#pragma once
#include "晨风qq机器人Dlg.h"

// CAutoReplyRule 对话框

class CAutoReplyRule : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CAutoReplyRule)

public:
	CAutoReplyRule(CWnd* pParent = NULL);   // 标准构造函数

	virtual ~CAutoReplyRule();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnEnKillfocusEdit7();
	void OnEnKillfocusEdit14();
	void OnEnKillfocusEdit15();
	afx_msg void OnEnKillfocusEdit5();
	void OnBnClickedRadio1();
	void OnBnClickedRadio2();
	void OnBnClickedRadio3();
	afx_msg void OnBnClickedCheck8();
	virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	

	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnEnKillfocusEdit10();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnEnKillfocusEdit11();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnEnKillfocusEdit35();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck25();
	afx_msg void OnBnClickedCheck26();
	afx_msg void OnBnClickedCheck27();
	afx_msg void OnBnClickedCheck28();
	afx_msg void OnEnKillfocusEdit16();
	afx_msg void OnEnKillfocusEdit39();
	afx_msg void OnEnKillfocusEdit40();
	afx_msg void OnEnKillfocusEdit43();
	afx_msg void OnEnKillfocusEdit18();
	afx_msg void OnEnKillfocusEdit44();
	afx_msg void OnEnKillfocusEdit45();
	afx_msg void OnEnKillfocusEdit20();
	afx_msg void OnEnKillfocusEdit21();
	afx_msg void OnEnKillfocusEdit22();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnEnKillfocusEdit32();
	afx_msg void OnBnClickedCheck29();
	afx_msg void OnEnKillfocusEdit46();
	afx_msg void OnEnKillfocusEdit47();
	afx_msg void OnEnKillfocusEdit48();
	afx_msg void OnBnClickedCheck36();
	afx_msg void OnBnClickedCheck37();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnEnKillfocusEdit54();
	afx_msg void OnBnClickedCheck38();
	afx_msg void OnEnKillfocusEdit26();
};
