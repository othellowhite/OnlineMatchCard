// DlgResult.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgResult.h"
#include "afxdialogex.h"


// DlgResult 대화 상자입니다.

IMPLEMENT_DYNAMIC(DlgResult, CDialogEx)

DlgResult::DlgResult(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgResult::IDD, pParent)
{
}

DlgResult::~DlgResult()
{
}

void DlgResult::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Text(pDX, IDC_SCORE, m_score);
}


BEGIN_MESSAGE_MAP(DlgResult, CDialogEx)
END_MESSAGE_MAP()


// DlgResult 메시지 처리기입니다.


void DlgResult::SetScore(int score)
{
	m_score = score;
}
