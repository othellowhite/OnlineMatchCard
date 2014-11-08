// yoon // 14.11.8 // 점수판 대화상자
// DlgScoreBoard.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgScoreBoard.h"
#include "afxdialogex.h"


// DlgScoreBoard 대화 상자입니다.

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


// DlgScoreBoard 메시지 처리기입니다.


void DlgScoreBoard::OnLbnSelchangeScorelist()
{
	int score;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
