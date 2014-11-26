// GameDoc.cpp : CGameDoc 클래스의 구현
//

#include "stdafx.h"
#include "Game.h"

#include "GameDoc.h"
// yoon // 14.11.15 // 모드추가
#include "DlgMode.h"
#include "DlgSockStat.h"
// yoon // 14.11.8 // 난이도설정 추가
#include "DlgLevelOf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGameDoc

IMPLEMENT_DYNCREATE(CGameDoc, CDocument)

	BEGIN_MESSAGE_MAP(CGameDoc, CDocument)
	END_MESSAGE_MAP()

	// yoon // bgn
	UINT ThreadFunc( void* pParam )
	{
		char msg[10]; 
		//void*에서 SOCKET으로 형변환이 불가함으로 메모리카피를 한다.
        SOCKET recvsocket;
        memcpy_s(&recvsocket, sizeof(SOCKET), pParam, sizeof(SOCKET));
		while(1) {
			recv(recvsocket, msg, sizeof(msg)*3, 0);
			//AfxMessageBox(_T("msg get"));
			if (msg[0]=='e' && msg[1]=='n' && msg[2] == 'd') {
				AfxMessageBox(_T("상대방이 게임을 완료하였습니다. "));
				ExitProcess(0);
			}
		}
	}
	// yoon // end

	UINT CGameDoc::AcceptFunc(LPVOID pParam)
	{
		return 0;
	}

	// CGameDoc 생성/소멸

	CGameDoc::CGameDoc()
	{
		// TODO: 여기에 일회성 생성 코드를 추가합니다.
		m_bmCell = CSize(79, 81);

		// yoon // add code bgn ...

		DlgMode dlgMd;  // yoon // 14.11.15 // 온라인 경쟁여부 대화상자
		DlgSockStat dlgSoc;
		dlgMd.DoModal();
		char recvLV[10];

		// yoon // 14.11.15 // 소켓프로그래밍을 위해 "stdafx.h"를 수정, 참고
		isServ = 'n';
		if (dlgMd.m_isOnline==true) {
			
			isServ='s';
			dlgSoc.DoModal();

			if (dlgSoc.m_isServer == true) {  // yoon // 14.11.17 // server

				// yoon // 14.11.17 // create Socket
				if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0){
					AfxMessageBox(_T(" WSAStartup Error "));
				}

				hServSock = socket(PF_INET, SOCK_STREAM, 0);
				if (hServSock
					== INVALID_SOCKET) {
						AfxMessageBox(_T(" Socket Error "));
				}

				// yoon // 14.11.17 // bind
				memset(&servAddr, 0, sizeof(servAddr));
				servAddr.sin_family = AF_INET;
				servAddr.sin_port = htons(_ttoi(dlgSoc.m_port));
				if(bind(hServSock, (sockaddr*)&servAddr, sizeof(servAddr))
					== SOCKET_ERROR) AfxMessageBox(_T(" Bind Error "));

				// yoon // 14.11.17 // listen
				if(listen(hServSock, 5)
					==SOCKET_ERROR) AfxMessageBox(_T(" Listen Error "));

				// yoon // 14.11.25 // accept
				szClntAddr=sizeof(clntAddr);
				// 아래 함수에서 holding하고 있는다. 
				hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
				if(hClntSock==INVALID_SOCKET) AfxMessageBox(_T(" Accept Error "));

				AfxBeginThread(ThreadFunc,&hClntSock);

			}

			else { // yoon // 14.11.17 // client
				isServ='c';
				if(WSAStartup(MAKEWORD(2, 2), &wsaData) !=0)
					AfxMessageBox(_T(" WSAStartup Error "));

				hClntSock=socket(PF_INET, SOCK_STREAM, 0);
				if(hClntSock==INVALID_SOCKET)AfxMessageBox(_T(" Socket Error "));

				memset(&servAddr, 0, sizeof(servAddr));
				servAddr.sin_family=AF_INET;
				AfxMessageBox(dlgSoc.m_ipaddrStr);
				char *ipaddr = "127.0.0.1";
				//char *ipaddr = "192.168.0.105";
				//WideCharToMultiByte(CP_ACP, WC_DEFAULTCHAR,
				//	(LPCTSTR)dlgSoc.m_ipaddrStr, -1, ipaddr, dlgSoc.m_ipaddrStr.GetLength(), NULL, NULL);
				servAddr.sin_addr.s_addr=inet_addr(ipaddr);
				servAddr.sin_port=htons(_ttoi(dlgSoc.m_port));

				if(connect(hClntSock, (SOCKADDR*)&servAddr, sizeof(servAddr))==SOCKET_ERROR)
					AfxMessageBox(_T(" Connect Error "));

				recv(hClntSock, recvLV, sizeof(int), 0);
				AfxBeginThread(ThreadFunc,&hClntSock);
			}


		}
		if (dlgSoc.m_isServer == true || dlgMd.m_isOnline==false) { // yoon // single & server mode
			DlgLevelOf dlgLV; // yoon // 14.11.8 // 난이도 설정 대화상자
			dlgLV.DoModal();
			
			send( (hClntSock), (char*)&dlgLV.m_lv, sizeof(dlgLV.m_lv), NULL);

			switch (dlgLV.m_lv)
			{
			case 6 :
				m_nRow = 2; m_nCol = 3; break;
			case 20 :
				m_nRow = 4; m_nCol = 5; break;
			case 30 :
				m_nRow = 5; m_nCol = 6; break;
			}
			// yoon // add code ... end
			/*
			m_nRow = 3;        // 격자의 초기 행 열 값
			m_nCol = 4;
			*/// yoon // 14.11.8 // original code

			m_bRandom = true;    // 랜덤하게 그림의 ID 변경 
			for(int n = 0; n < m_nRow; n++)
				for(int m = 0; m < m_nCol; m++)
					m_bShow[n][m] = false;

			//아무 그림도 선택되지 않은 것으로 인식하기 위해서 초기값을 0으로 설정한다. 
			m_nBmpFirstID = m_nBmpSecondID = 0;
			m_bMouse = false;
		}

		else {// for client

			switch (recvLV[0])
			{
			case 6 :
				m_nRow = 2; m_nCol = 3; break;
			case 20 :
				m_nRow = 4; m_nCol = 5; break;
			case 30 :
				m_nRow = 5; m_nCol = 6; break;
			}
			// yoon // add code ... end
			/*
			m_nRow = 3;        // 격자의 초기 행 열 값
			m_nCol = 4;
			*/// yoon // 14.11.8 // original code

			m_bRandom = true;    // 랜덤하게 그림의 ID 변경 
			for(int n = 0; n < m_nRow; n++)
				for(int m = 0; m < m_nCol; m++)
					m_bShow[n][m] = false;

			//아무 그림도 선택되지 않은 것으로 인식하기 위해서 초기값을 0으로 설정한다. 
			m_nBmpFirstID = m_nBmpSecondID = 0;
			m_bMouse = false;
		}

	}

	CGameDoc::~CGameDoc()
	{
	}

	BOOL CGameDoc::OnNewDocument()
	{
		if (!CDocument::OnNewDocument())
			return FALSE;

		// TODO: 여기에 재초기화 코드를 추가합니다.
		// SDI 문서는 이 문서를 다시 사용합니다.

		return TRUE;
	}




	// CGameDoc serialization

	void CGameDoc::Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			// TODO: 여기에 저장 코드를 추가합니다.
		}
		else
		{
			// TODO: 여기에 로딩 코드를 추가합니다.
		}
	}


	// CGameDoc 진단

#ifdef _DEBUG
	void CGameDoc::AssertValid() const
	{
		CDocument::AssertValid();
	}

	void CGameDoc::Dump(CDumpContext& dc) const
	{
		CDocument::Dump(dc);
	}
#endif //_DEBUG


	// CGameDoc 명령
#include "GameView.h"
#include "MainFrm.h"

	void CGameDoc::ResizeWindow(void)
	{
		CMainFrame*    pMain = (CMainFrame*)AfxGetMainWnd();

		CREATESTRUCT  st;
		CREATESTRUCT&  rst = st;

		pMain->PreCreateWindow(rst);

		rst.lpszName = _T("Game");
		rst.cx = (m_nRow + 1) * m_bmCell.cx + 180;
		rst.cy = (m_nCol + 1) * m_bmCell.cy + 100;

		CRect    rect;
		pMain->GetClientRect(rect);
		pMain->MoveWindow(rect.left, rect.top, rst.cx, rst.cy);
	}

	void CGameDoc::OnRandom(void)
	{
		// 시간을 Seed로 잡아 똑같은 난수 발생을 방지
		srand((unsigned)time(NULL));

		// 비트맵 삽입 여부 / 격자의 총 수 / 처음 넣을 비트맵의 아이디
		// 동일한 아이디를 두 번씩 배치되도록 하기 위한 변수를 설정한다. 
		BOOL  bInsert = TRUE;   
		//격자의 총수를 구한다. 
		int    nGrating = m_nRow * m_nCol;

		// 격자의 수만큼 돌면서 난수 발생
		for(int n = 0; n < nGrating; n++)  //격자 수 만큼만 돈다. 
		{
			// 시작 비트맵 아이디에 난수를 더해 비트맵을 변경
			// 일단 발생한 난수를 배열에 저장하고 본다. 
			m_nRnd[n] =  (rand() % (nGrating / 2)) + 1;

			//현재 진행한 격자수까지만 비교한다. 
			for(int m = 0; m < n; m++){
				if(m_nRnd[n] == m_nRnd[m]){//만일 같은값이있다면 변수에 삽입불가능한지를 알아본다.
					if(bInsert == FALSE){ //bInsert가 FALSE이면 세 번째 동일한 값이므로 
						n--;  //배열에 이미 세번째 저장된 랜덤값을 취소하기 위해서 첨자를 감소한다. 
						bInsert = TRUE; //세번이상은 절대 동일한 값이 저장되어 있지 않을 것이므로 
						break;  //안쪽 반복문을 벗어난다. 벗어나기전에 bInsert값을 TRUE로 설정
					}//if
					bInsert = FALSE;//새로 생성된 랜덤값이 이미 배열에 설정되어 있지만 한번 만난 
				}//랜덤값이면 bInsert가 TRUE이므로 두 번쨰 동일한 값은 배열에 저장된 후에
				//다음부터 진행되는 배열에 세 번째 동일한 값이 나타나면 
				//더 이상 배열에 저장되지 않도록 하기 위해서 bInsert에 FALSE값을 저장한다. 
			}//안쪽 for
		}//바깥쪽 for
		//36개의 랜덤값이 저장된 일차원 배열 m_nRnd에 의해 그림의 위치가 결정될 것이면
		//동일한 그림을 맞추기 위해 나타날 그림의 위치에 해당 그림의 아이디 값을 
		//  m_nBmpID배열에 일대일 대응으로 배치한다. 
		int    nCount = 0;

		for(int n = 0; n < m_nRow; n++)  {
			for(int m = 0; m < m_nCol; m++)    {
				m_nBmpID[n][m] = m_nRnd[nCount];
				nCount++;
			}
		}
	}


