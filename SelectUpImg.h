#pragma once
#include "MyBGCDlg.h"
#include "晨风qq机器人Dlg.h"

// CSelectUpImg 对话框

class CSelectUpImg : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CSelectUpImg)

public:
	CSelectUpImg(LPCTSTR uploadimgpath,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectUpImg();
	int m_imgxuhao;
	CString m_uploadimgpath;
// 对话框数据
	enum { IDD = IDD_DIALOG13 };
virtual BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
};
