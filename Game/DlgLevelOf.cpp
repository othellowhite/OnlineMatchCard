// yoon // 14.11.8 // 난이도 설정 대화상자
// DlgLevelOf.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgLevelOf.h"
#include "afxdialogex.h"


// DlgLevelOf 대화 상자입니다.

IMPLEMENT_DYNAMIC(DlgLevelOf, CDialogEx)

DlgLevelOf::DlgLevelOf(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgLevelOf::IDD, pParent)
{

}

DlgLevelOf::~DlgLevelOf()
{
}

void DlgLevelOf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgLevelOf, CDialogEx)
	ON_BN_CLICKED(IDC_EASY, &DlgLevelOf::OnBnClickedEasy)
	ON_BN_CLICKED(IDC_HARD, &DlgLevelOf::OnBnClickedHard)
	ON_BN_CLICKED(IDC_VERYHARD, &DlgLevelOf::OnBnClickedVeryhard)
END_MESSAGE_MAP()


// DlgLevelOf 메시지 처리기입니다.



void DlgLevelOf::OnBnClickedEasy() // 2x3
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_lv = 2*3;
	CDialogEx::OnOK();
}


void DlgLevelOf::OnBnClickedHard() // 4x5
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_lv = 4*5;
	CDialogEx::OnOK();
}


void DlgLevelOf::OnBnClickedVeryhard() // 5x6
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_lv = 5*6;
	CDialogEx::OnOK();
}
