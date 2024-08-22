#pragma once
#include "MyBGCDlg.h"
#include "晨风qq机器人Dlg.h"


// CStandUpDlg 对话框

class CStandUpDlg : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CStandUpDlg)

public:
	CStandUpDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStandUpDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL CStandUpDlg::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
