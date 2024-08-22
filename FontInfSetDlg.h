#pragma once
#include "MyBGCDlg.h"
#include "晨风qq机器人Dlg.h"
// CFontInfSetDlg 对话框

class CFontInfSetDlg : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CFontInfSetDlg)

public:
	CFontInfSetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFontInfSetDlg();
CMySortListCtrl m_list1;
CImageList m_imList;
// 对话框数据
	enum { IDD = IDD_DIALOG7 };
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
virtual BOOL OnInitDialog();
void Insert2List(COLORREF color1);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnKillfocusEdit6();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnKillfocusCombo1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton4();
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedCheck2();
};
