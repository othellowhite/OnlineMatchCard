#pragma once


// DlgResult 대화 상자입니다.

class DlgResult : public CDialogEx
{
	DECLARE_DYNAMIC(DlgResult)

public:
	DlgResult(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DlgResult();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_score;
	afx_msg void OnEnChangeEdit();
	void SetScore(int score);
};
