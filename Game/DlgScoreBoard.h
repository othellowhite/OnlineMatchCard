#pragma once

// yoon // 14.11.8 // 점수판 대화상자
// DlgScoreBoard 대화 상자입니다.

class DlgScoreBoard : public CDialogEx
{
	DECLARE_DYNAMIC(DlgScoreBoard)

public:
	DlgScoreBoard(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DlgScoreBoard();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SCOREBOARD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeScorelist();
};
