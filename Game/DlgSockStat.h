#pragma once


// DlgSockStat ��ȭ �����Դϴ�.

class DlgSockStat : public CDialog
{
	DECLARE_DYNAMIC(DlgSockStat)

public:
	DlgSockStat(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DlgSockStat();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SOCKSTAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
