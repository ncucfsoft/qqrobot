#pragma once
#include "MyBGCDlg.h"
#include "MySortListCtrl.h"
#include "ReadAUStdioFile.h"
#include "晨风qq机器人Dlg.h"
#include "afxcmn.h"
#include "afxwin.h"
class C晨风qq机器人Dlg;
class CIgnoreDlg : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CIgnoreDlg)

public:
	CIgnoreDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CIgnoreDlg();
	LRESULT onFriendOver(WPARAM wParam,LPARAM lParam);
	LRESULT onUpdateIsAdminInf(WPARAM wParam,LPARAM lParam);
	LRESULT onUpdateIsShutuped(WPARAM wParam, LPARAM lParam);
	void UpdateList();
	void Insert2List(LPCTSTR fpath,LPCTSTR hshow);
void ModifyList(LPCTSTR fpath,LPCTSTR hshow);

	void DisLikeOrLikeFile(LPCTSTR filenamebuf,BOOL bDisLike);
	
	void OnDestroy();
	void OnDropFiles(HDROP hDropInfo);
	CMySortListCtrl m_list1;
	C晨风qq机器人Dlg *m_parentwnd;
	int m_lastrow;
	int m_lastsubcolumn;
	int lastfindpos;
// 对话框数据
	enum { IDD = IDD_AVOIDPIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL OnInitDialog();
	void SaveEditValue();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	void OpenGroupMsgDlg(int item);
	void OpenFriendMsgDlg(int item);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton7();
	void NormalSomeItem(int item);
	afx_msg void OnBnClickedButton10();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButton1();
	void GetSelectIntvect(const CMySortListCtrl& m_list,intvect& selectvect);
	afx_msg void OnBnClickedButton2();
	CMySortListCtrl m_list2;
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	CEdit m_SubItemEdit;
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton22();
};
