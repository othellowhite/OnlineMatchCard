// DlgMode.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgMode.h"
#include "afxdialogex.h"


// DlgMode 대화 상자입니다.

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


// DlgMode 메시지 처리기입니다.


void DlgMode::OnBnClickedButton1() // yoon // single
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_isOnline = false;
	CDialogEx::OnOK();
}


void DlgMode::OnBnClickedButton2() // yoon // online
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_isOnline = true;
	CDialogEx::OnOK();
}
