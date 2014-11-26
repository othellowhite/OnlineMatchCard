#pragma once


// DlgSockStat 대화 상자입니다.

class DlgSockStat : public CDialog
{
	DECLARE_DYNAMIC(DlgSockStat)

public:
	DlgSockStat(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DlgSockStat();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SOCKSTAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	char m_isServer;
	afx_msg void OnBnClickedButton();
	CString m_btnStr;
	afx_msg void OnEnChangePort();
	afx_msg void OnIpnFieldchangedIpaddr(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_ipaddrStr;
	CString m_port;
};
