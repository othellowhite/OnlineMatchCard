// yoon // 14.11.8 // ������ ��ȭ����
// DlgScoreBoard.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgScoreBoard.h"
#include "afxdialogex.h"


// DlgScoreBoard ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(DlgScoreBoard, CDialogEx)

DlgScoreBoard::DlgScoreBoard(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgScoreBoard::IDD, pParent)
{
}

DlgScoreBoard::~DlgScoreBoard()
{
}

void DlgScoreBoard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_SCORELIST, m_scoreStr);
	DDX_Control(pDX, IDC_SCORELIST, m_scoreCtr);
}


BEGIN_MESSAGE_MAP(DlgScoreBoard, CDialogEx)
	ON_LBN_SELCHANGE(IDC_SCORELIST, &DlgScoreBoard::OnLbnSelchangeScorelist)
END_MESSAGE_MAP()


// DlgScoreBoard �޽��� ó�����Դϴ�.


void DlgScoreBoard::OnLbnSelchangeScorelist()
{
	int score;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL DlgScoreBoard::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	int rank = 1, i;
	for (i = 0; i < 30; i++){
		m_scoreStr.Format(_T("���� : %3d,  �̸� : %5s,  ���� :  %d"), rank++, _T("yoon"), (1800-(i*30)));
		m_scoreCtr.AddString(m_scoreStr);
	}

	return TRUE;
}
