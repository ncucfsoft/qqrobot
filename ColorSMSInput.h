#pragma once

// CColorSMSInput 对话框

class CColorSMSInput : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CColorSMSInput)

public:
CColorSMSInput(LPCTSTR captchaurl,CWnd* pParent = NULL); 
	CColorSMSInput(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CColorSMSInput();

	enum { IDD = IDD_DIALOG15 };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_smsstr;
	HICON m_hIcon;
	afx_msg void OnBnClickedOk();
	void OnPaint();
	
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
};
