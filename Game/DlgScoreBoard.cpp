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
