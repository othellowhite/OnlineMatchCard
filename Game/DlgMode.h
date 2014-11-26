#pragma once


// DlgMode 대화 상자입니다.

class DlgMode : public CDialogEx
{
	DECLARE_DYNAMIC(DlgMode)

public:
	DlgMode(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DlgMode();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	char m_isOnline;
};
