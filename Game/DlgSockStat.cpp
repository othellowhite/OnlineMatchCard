// DlgSockStat.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgSockStat.h"
#include "afxdialogex.h"


// DlgSockStat ��ȭ �����Դϴ�.

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


// DlgSockStat �޽��� ó�����Դϴ�.


void DlgSockStat::OnBnClickedRadio1() // Server
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_isServer = true;

	CWnd* PfieldIpAddr = GetDlgItem( IDC_IPADDR );
	PfieldIpAddr->EnableWindow( FALSE ); 

	m_btnStr = _T("Listen");
	UpdateData(false);
}


void DlgSockStat::OnBnClickedRadio2() // Client
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_isServer = false;

	CWnd* PfieldIpAddr = GetDlgItem( IDC_IPADDR );
	PfieldIpAddr->EnableWindow( TRUE ); 

	m_btnStr = _T("Connect");
	UpdateData(false);

}


void DlgSockStat::OnBnClickedButton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItemText(IDC_IPADDR, m_ipaddrStr);
	GetDlgItemText(IDC_PORT, m_port);
	
	CDialog::OnOK();
}



void DlgSockStat::OnEnChangePort()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.


	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

