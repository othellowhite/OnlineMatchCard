// DlgSockStat.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgSockStat.h"
#include "afxdialogex.h"


// DlgSockStat 대화 상자입니다.

IMPLEMENT_DYNAMIC(DlgSockStat, CDialog)

DlgSockStat::DlgSockStat(CWnd* pParent /*=NULL*/)
	: CDialog(DlgSockStat::IDD, pParent)
{

}

DlgSockStat::~DlgSockStat()
{
}

void DlgSockStat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
	DDX_Text(pDX, IDC_BUTTON, m_btnStr);
}


BEGIN_MESSAGE_MAP(DlgSockStat, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &DlgSockStat::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DlgSockStat::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON, &DlgSockStat::OnBnClickedButton)
	ON_EN_CHANGE(IDC_PORT, &DlgSockStat::OnEnChangePort)
END_MESSAGE_MAP()


// DlgSockStat 메시지 처리기입니다.


void DlgSockStat::OnBnClickedRadio1() // Server
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_isServer = true;

	CWnd* PfieldIpAddr = GetDlgItem( IDC_IPADDR );
	PfieldIpAddr->EnableWindow( FALSE ); 

	m_btnStr = _T("Listen");
	UpdateData(false);
}


void DlgSockStat::OnBnClickedRadio2() // Client
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_isServer = false;

	CWnd* PfieldIpAddr = GetDlgItem( IDC_IPADDR );
	PfieldIpAddr->EnableWindow( TRUE ); 

	m_btnStr = _T("Connect");
	UpdateData(false);

}


void DlgSockStat::OnBnClickedButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_IPADDR, m_ipaddrStr);
	GetDlgItemText(IDC_PORT, m_port);
	
	CDialog::OnOK();
}



void DlgSockStat::OnEnChangePort()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.


	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

