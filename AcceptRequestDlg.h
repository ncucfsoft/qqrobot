#pragma once
#include "晨风qq机器人.h"
typedef struct _welcomestruct
{
	CString nickname;
	CString welcomestr;
	CString precardname;
	CString femaleprecardname;
	CString titlestr;
	INT64 pro_m_qqgroupid;
	INT64 cur_uin;
	INT64 otherqqnum;
	BOOL bMale;
	BOOL bTatalSlient;
}welcomestruct;
// CAcceptRequestDlg 对话框
class C晨风qq机器人Dlg;
class CAcceptRequestDlg : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CAcceptRequestDlg)

public:
	CAcceptRequestDlg(INT64 qqgroupid,INT64 realgroupid,INT64 requestuin,INT64 qqaccount,INT64 timesignal,LPCTSTR nickname,LPCTSTR content,int bMale,qqgrouprule tempgrule,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAcceptRequestDlg();
	INT64 m_realgroupnumber;
	INT64 m_qqgroupid;
	INT64 m_requestuin;
	INT64 m_qqaccount;
	int m_bMale;
	INT64 m_timesignal;
	CString m_nickname;
	CString m_content;
	qqgrouprule m_grule;
// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNcDestroy();
	afx_msg void OnDestroy();
	void OnDelSelf();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
	int ncount;
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBnClickedCancel();
};
