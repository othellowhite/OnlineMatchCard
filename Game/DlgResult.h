#pragma once


// DlgResult ��ȭ �����Դϴ�.

class DlgResult : public CDialogEx
{
	DECLARE_DYNAMIC(DlgResult)

public:
	DlgResult(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DlgResult();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_score;
	afx_msg void OnEnChangeEdit();
	void SetScore(int score);
};
