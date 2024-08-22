#pragma once
#include "PictureEx.h"

// CQR2CodeDlg 对话框

class CQR2CodeDlg : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CQR2CodeDlg)

public:
	CQR2CodeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CQR2CodeDlg();
DWORD colorcode;
CString m_jumpurl;
int fontsize;
char *m_rtvalue;
UINT m_img_size;
CPictureEx m_mypic;
// 对话框数据
	enum { IDD = IDD_DIALOG14 };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_validstate;
	CRect m_myrect;
	CImage m_image;
	BOOL m_bstopdrawflag;
	HICON m_hIcon;
	int CQR2CodeDlg::TestLoginState();
	void CQR2CodeDlg::LoadOneQRImage();
	afx_msg void OnBnClickedOk();
	void OnPaint();
		afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
