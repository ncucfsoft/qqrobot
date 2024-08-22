#pragma once
#include "MyBGCDlg.h"
#include "晨风qq机器人Dlg.h"
// COtherConfig 对话框

class COtherConfig : public CMyBGCDlg
{
	DECLARE_DYNAMIC(COtherConfig)

public:
	COtherConfig(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COtherConfig();
	virtual BOOL OnInitDialog();
		void OnDestroy();
// 对话框数据
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
};
