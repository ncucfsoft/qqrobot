#pragma once
#include "afxcmn.h"
#include "晨风qq机器人Dlg.h"

// CModifyTitle 对话框
class C晨风qq机器人Dlg;
class CModifyTitle : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CModifyTitle)

public:
	CModifyTitle(CKeepStrStrVectMap&replymap,CReadAUStdioFile&file1,CKeepStrStrVectMap&privilegereplymap,CReadAUStdioFile&privilegefile1,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModifyTitle();
CString newqqtitle;
CString m_path;
BOOL m_changed;
int lastfindpos;
CReadAUStdioFile& m_autoreplyfile;
CKeepStrStrVectMap& m_autoreplymap;

CReadAUStdioFile& m_privilegeautoreplyfile;
CKeepStrStrVectMap& m_privilegeautoreplymap;

CReadAUStdioFile* m_ppppautoreplyfile;
CKeepStrStrVectMap* m_ppppautoreplymap;

	C晨风qq机器人Dlg *m_parentwnd;
	void OnDelSelf();
// 对话框数据
	enum { IDD = IDD_DIALOG2 };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void DeleteItem();
	void LoadAllItem();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOk();
	CListCtrl m_list1;
	void org_ImportAFile(LPCTSTR importfilename);
void xls_ImportAFile(LPCTSTR importfilename);

	void ImportAFile(LPCTSTR importfilename);
	void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void AddQQPair(LPCTSTR qqstr,LPCTSTR pwdstr);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL CModifyTitle::PreTranslateMessage(MSG* pMsg);

	afx_msg void OnNMSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult);

	BOOL m_bPrivilege;
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
};
