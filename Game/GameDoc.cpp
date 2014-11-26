// GameDoc.cpp : CGameDoc Ŭ������ ����
//

#include "stdafx.h"
#include "Game.h"

#include "GameDoc.h"
// yoon // 14.11.15 // ����߰�
#include "DlgMode.h"
#include "DlgSockStat.h"
// yoon // 14.11.8 // ���̵����� �߰�
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
		//void*���� SOCKET���� ����ȯ�� �Ұ������� �޸�ī�Ǹ� �Ѵ�.
        SOCKET recvsocket;
        memcpy_s(&recvsocket, sizeof(SOCKET), pParam, sizeof(SOCKET));
		while(1) {
			recv(recvsocket, msg, sizeof(msg)*3, 0);
			//AfxMessageBox(_T("msg get"));
			if (msg[0]=='e' && msg[1]=='n' && msg[2] == 'd') {
				AfxMessageBox(_T("������ ������ �Ϸ��Ͽ����ϴ�. "));
				ExitProcess(0);
			}
		}
	}
	// yoon // end

	UINT CGameDoc::AcceptFunc(LPVOID pParam)
	{
		return 0;
	}

	// CGameDoc ����/�Ҹ�

	CGameDoc::CGameDoc()
	{
		// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
		m_bmCell = CSize(79, 81);

		// yoon // add code bgn ...

		DlgMode dlgMd;  // yoon // 14.11.15 // �¶��� ���￩�� ��ȭ����
		DlgSockStat dlgSoc;
		dlgMd.DoModal();
		char recvLV[10];

		// yoon // 14.11.15 // �������α׷����� ���� "stdafx.h"�� ����, ����
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
				// �Ʒ� �Լ����� holding�ϰ� �ִ´�. 
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
			DlgLevelOf dlgLV; // yoon // 14.11.8 // ���̵� ���� ��ȭ����
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
			m_nRow = 3;        // ������ �ʱ� �� �� ��
			m_nCol = 4;
			*/// yoon // 14.11.8 // original code

			m_bRandom = true;    // �����ϰ� �׸��� ID ���� 
			for(int n = 0; n < m_nRow; n++)
				for(int m = 0; m < m_nCol; m++)
					m_bShow[n][m] = false;

			//�ƹ� �׸��� ���õ��� ���� ������ �ν��ϱ� ���ؼ� �ʱⰪ�� 0���� �����Ѵ�. 
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
			m_nRow = 3;        // ������ �ʱ� �� �� ��
			m_nCol = 4;
			*/// yoon // 14.11.8 // original code

			m_bRandom = true;    // �����ϰ� �׸��� ID ���� 
			for(int n = 0; n < m_nRow; n++)
				for(int m = 0; m < m_nCol; m++)
					m_bShow[n][m] = false;

			//�ƹ� �׸��� ���õ��� ���� ������ �ν��ϱ� ���ؼ� �ʱⰪ�� 0���� �����Ѵ�. 
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

		// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
		// SDI ������ �� ������ �ٽ� ����մϴ�.

		return TRUE;
	}




	// CGameDoc serialization

	void CGameDoc::Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		}
		else
		{
			// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		}
	}


	// CGameDoc ����

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


	// CGameDoc ���
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
		// �ð��� Seed�� ��� �Ȱ��� ���� �߻��� ����
		srand((unsigned)time(NULL));

		// ��Ʈ�� ���� ���� / ������ �� �� / ó�� ���� ��Ʈ���� ���̵�
		// ������ ���̵� �� ���� ��ġ�ǵ��� �ϱ� ���� ������ �����Ѵ�. 
		BOOL  bInsert = TRUE;   
		//������ �Ѽ��� ���Ѵ�. 
		int    nGrating = m_nRow * m_nCol;

		// ������ ����ŭ ���鼭 ���� �߻�
		for(int n = 0; n < nGrating; n++)  //���� �� ��ŭ�� ����. 
		{
			// ���� ��Ʈ�� ���̵� ������ ���� ��Ʈ���� ����
			// �ϴ� �߻��� ������ �迭�� �����ϰ� ����. 
			m_nRnd[n] =  (rand() % (nGrating / 2)) + 1;

			//���� ������ ���ڼ������� ���Ѵ�. 
			for(int m = 0; m < n; m++){
				if(m_nRnd[n] == m_nRnd[m]){//���� ���������ִٸ� ������ ���ԺҰ��������� �˾ƺ���.
					if(bInsert == FALSE){ //bInsert�� FALSE�̸� �� ��° ������ ���̹Ƿ� 
						n--;  //�迭�� �̹� ����° ����� �������� ����ϱ� ���ؼ� ÷�ڸ� �����Ѵ�. 
						bInsert = TRUE; //�����̻��� ���� ������ ���� ����Ǿ� ���� ���� ���̹Ƿ� 
						break;  //���� �ݺ����� �����. ��������� bInsert���� TRUE�� ����
					}//if
					bInsert = FALSE;//���� ������ �������� �̹� �迭�� �����Ǿ� ������ �ѹ� ���� 
				}//�������̸� bInsert�� TRUE�̹Ƿ� �� ���� ������ ���� �迭�� ����� �Ŀ�
				//�������� ����Ǵ� �迭�� �� ��° ������ ���� ��Ÿ���� 
				//�� �̻� �迭�� ������� �ʵ��� �ϱ� ���ؼ� bInsert�� FALSE���� �����Ѵ�. 
			}//���� for
		}//�ٱ��� for
		//36���� �������� ����� ������ �迭 m_nRnd�� ���� �׸��� ��ġ�� ������ ���̸�
		//������ �׸��� ���߱� ���� ��Ÿ�� �׸��� ��ġ�� �ش� �׸��� ���̵� ���� 
		//  m_nBmpID�迭�� �ϴ��� �������� ��ġ�Ѵ�. 
		int    nCount = 0;

		for(int n = 0; n < m_nRow; n++)  {
			for(int m = 0; m < m_nCol; m++)    {
				m_nBmpID[n][m] = m_nRnd[nCount];
				nCount++;
			}
		}
	}


