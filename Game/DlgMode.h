#pragma once


// DlgMode ��ȭ �����Դϴ�.

class DlgMode : public CDialogEx
{
	DECLARE_DYNAMIC(DlgMode)

public:
	DlgMode(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DlgMode();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	char m_isOnline;
};
