// DlgResult.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgResult.h"
#include "afxdialogex.h"


// DlgResult ��ȭ �����Դϴ�.

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


// DlgResult �޽��� ó�����Դϴ�.


void DlgResult::SetScore(int score)
{
	m_score = score;
}
