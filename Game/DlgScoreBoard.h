#pragma once

// yoon // 14.11.8 // ������ ��ȭ����
// DlgScoreBoard ��ȭ �����Դϴ�.

class DlgScoreBoard : public CDialogEx
{
	DECLARE_DYNAMIC(DlgScoreBoard)

public:
	DlgScoreBoard(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DlgScoreBoard();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SCOREBOARD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeScorelist();
};
