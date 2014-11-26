// DlgMode.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgMode.h"
#include "afxdialogex.h"


// DlgMode ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(DlgMode, CDialogEx)

DlgMode::DlgMode(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgMode::IDD, pParent)
	, m_isOnline(0)
{

}

DlgMode::~DlgMode()
{
}

void DlgMode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgMode, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgMode::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgMode::OnBnClickedButton2)
END_MESSAGE_MAP()


// DlgMode �޽��� ó�����Դϴ�.


void DlgMode::OnBnClickedButton1() // yoon // single
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_isOnline = false;
	CDialogEx::OnOK();
}


void DlgMode::OnBnClickedButton2() // yoon // online
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_isOnline = true;
	CDialogEx::OnOK();
}
