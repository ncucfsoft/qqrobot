#pragma once
#include "晨风qq机器人Dlg.h"

// CMoreAdminList 对话框

class CMoreAdminList : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CMoreAdminList)

public:
	CMoreAdminList(qqgrouprule& temprule,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMoreAdminList();
	virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_DIALOG11 };
	BOOL m_defaultflag;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	
	qqgrouprule& m_qqgrouprule;

afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnEnKillfocusEdit3();
	afx_msg void OnEnKillfocusEdit4();
	afx_msg void OnEnKillfocusEdit5();
	afx_msg void OnEnKillfocusEdit6();
	afx_msg void OnEnKillfocusEdit7();
	int GetDlgItemInt(int nID);
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck22();
	afx_msg void OnEnKillfocusEdit26();
	afx_msg void OnEnKillfocusEdit9();
	afx_msg void OnEnKillfocusEdit10();
	afx_msg void OnEnKillfocusEdit13();
	afx_msg void OnEnKillfocusEdit11();
	afx_msg void OnEnKillfocusEdit32();
	afx_msg void OnEnKillfocusEdit30();
	afx_msg void OnEnKillfocusEdit31();
	afx_msg void OnEnKillfocusEdit33();
	afx_msg void OnEnKillfocusEdit34();
	afx_msg void OnEnKillfocusEdit35();
	afx_msg void OnEnKillfocusEdit36();
	afx_msg void OnEnKillfocusEdit37();
	afx_msg void OnEnKillfocusEdit38();
	afx_msg void OnEnKillfocusEdit39();
	afx_msg void OnEnKillfocusEdit40();
	afx_msg void OnBnClickedCheck23();
	afx_msg void OnBnClickedCheck24();
	afx_msg void OnBnClickedCheck30();
	afx_msg void OnEnKillfocusEdit45();
	afx_msg void OnEnKillfocusEdit51();
	afx_msg void OnBnClickedCheck31();
	afx_msg void OnBnClickedCheck32();
	afx_msg void OnEnKillfocusEdit52();
	afx_msg void OnBnClickedCheck33();
	afx_msg void OnEnKillfocusEdit53();
	afx_msg void OnEnKillfocusEdit55();
	afx_msg void OnEnKillfocusEdit56();
	afx_msg void OnEnKillfocusEdit57();
	afx_msg void OnEnKillfocusEdit58();
	afx_msg void OnEnKillfocusEdit48();
	afx_msg void OnEnKillfocusEdit54();
	afx_msg void OnEnKillfocusEdit59();
	afx_msg void OnBnClickedCheck34();
	afx_msg void OnBnClickedCheck35();
	afx_msg void OnEnKillfocusEdit60();
	afx_msg void OnEnKillfocusEdit61();
	afx_msg void OnCbnKillfocusCombo6();
	afx_msg void OnCbnKillfocusCombo7();
	afx_msg void OnEnKillfocusEdit62();
	afx_msg void OnEnKillfocusEdit63();
	afx_msg void OnEnKillfocusEdit64();
};
