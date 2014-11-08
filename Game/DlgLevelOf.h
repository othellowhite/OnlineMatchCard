#pragma once

// yoon // 14.11.8 // 난이도 설정 대화상자
// DlgLevelOf 대화 상자입니다.

class DlgLevelOf : public CDialogEx
{
	DECLARE_DYNAMIC(DlgLevelOf)

public:
	DlgLevelOf(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DlgLevelOf();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LEVOF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedEasy();
	afx_msg void OnBnClickedHard();
	afx_msg void OnBnClickedVeryhard();
	int m_lv;
};
