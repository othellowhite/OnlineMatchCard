#pragma once

// yoon // 14.11.8 // ���̵� ���� ��ȭ����
// DlgLevelOf ��ȭ �����Դϴ�.

class DlgLevelOf : public CDialogEx
{
	DECLARE_DYNAMIC(DlgLevelOf)

public:
	DlgLevelOf(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DlgLevelOf();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LEVOF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedEasy();
	afx_msg void OnBnClickedHard();
	afx_msg void OnBnClickedVeryhard();
	int m_lv;
};
