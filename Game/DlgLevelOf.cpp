// yoon // 14.11.8 // ���̵� ���� ��ȭ����
// DlgLevelOf.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Game.h"
#include "DlgLevelOf.h"
#include "afxdialogex.h"


// DlgLevelOf ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(DlgLevelOf, CDialogEx)

DlgLevelOf::DlgLevelOf(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgLevelOf::IDD, pParent)
{

}

DlgLevelOf::~DlgLevelOf()
{
}

void DlgLevelOf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgLevelOf, CDialogEx)
	ON_BN_CLICKED(IDC_EASY, &DlgLevelOf::OnBnClickedEasy)
	ON_BN_CLICKED(IDC_HARD, &DlgLevelOf::OnBnClickedHard)
	ON_BN_CLICKED(IDC_VERYHARD, &DlgLevelOf::OnBnClickedVeryhard)
END_MESSAGE_MAP()


// DlgLevelOf �޽��� ó�����Դϴ�.



void DlgLevelOf::OnBnClickedEasy() // 2x3
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_lv = 2*3;
	CDialogEx::OnOK();
}


void DlgLevelOf::OnBnClickedHard() // 4x5
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_lv = 4*5;
	CDialogEx::OnOK();
}


void DlgLevelOf::OnBnClickedVeryhard() // 5x6
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_lv = 5*6;
	CDialogEx::OnOK();
}
