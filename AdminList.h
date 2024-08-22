#pragma once
#include "晨风qq机器人Dlg.h"

// CAdminList 对话框

class CAdminList : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CAdminList)

public:
	CAdminList(qqgrouprule& temprule,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdminList();
	virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_DIALOG9 };
	BOOL m_defaultflag;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_onceflag;
	afx_msg void OnEnKillfocusEdit9();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnEnKillfocusEdit10();
afx_msg void OnEnKillfocusEdit6();
afx_msg void OnEnKillfocusEdit7();
afx_msg void OnEnKillfocusEdit11();
afx_msg void OnEnKillfocusEdit14();
afx_msg void OnEnKillfocusEdit16();

afx_msg void OnEnKillfocusEdit13();

afx_msg LRESULT OnNcHitTest(CPoint point);

		afx_msg void OnEnKillfocusEdit8();
	afx_msg void OnEnKillfocusEdit1();
	qqgrouprule& m_qqgrouprule;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck4();

	
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck16();
	afx_msg void OnBnClickedCheck17();
	afx_msg void OnEnKillfocusEdit18();
	afx_msg void OnEnKillfocusEdit17();
	afx_msg void OnEnKillfocusEdit19();
	afx_msg void OnEnKillfocusEdit20();
	afx_msg void OnEnKillfocusEdit21();
	afx_msg void OnEnKillfocusEdit22();
	afx_msg void OnEnKillfocusEdit23();
	afx_msg void OnBnClickedCheck19();
	afx_msg void OnBnClickedCheck18();
	afx_msg void OnEnKillfocusEdit24();
	afx_msg void OnEnKillfocusEdit25();
	afx_msg void OnBnClickedCheck20();
	afx_msg void OnBnClickedCheck21();
	afx_msg void OnEnChangeEdit22();
	afx_msg void OnEnKillfocusEdit28();
	afx_msg void OnEnKillfocusEdit29();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnKillfocusEdit41();
	afx_msg void OnEnKillfocusEdit42();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnKillfocusEdit49();
	afx_msg void OnEnKillfocusEdit50();
	afx_msg void OnEnKillfocusEdit32();
	afx_msg void OnEnKillfocusEdit33();
};
