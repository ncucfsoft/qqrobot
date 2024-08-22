// CColorURLInput.cpp : 实现文件
//

#include "stdafx.h"
#include "晨风qq机器人.h"
#include "formatstruct.h"
#include "ColorURLInput.h"



IMPLEMENT_DYNAMIC(CColorURLInput, CDialog)


CColorURLInput::CColorURLInput(CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CColorURLInput::IDD, pParent)
{

}
CColorURLInput::CColorURLInput(LPCTSTR captchaurl,CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CColorURLInput::IDD, pParent)
{bNomultLanguage=true;
	
}
CColorURLInput::~CColorURLInput()
{
	
}

void CColorURLInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CColorURLInput, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CColorURLInput::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CColorURLInput::OnBnClickedCancel)
		ON_WM_CLOSE()
END_MESSAGE_MAP()


// CColorURLInput 消息处理程序
void CColorURLInput::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

	
	}
	else
	{
		CPaintDC dc(this);
		
	
	/*	CRect myrect;
		GetDlgItem(IDC_yanzhengpic)->GetWindowRect(myrect);
		ScreenToClient(myrect);
 m_image.Draw(dc, myrect.left, myrect.top, m_image.GetWidth(), m_image.GetHeight(), 0, 0, m_image.GetWidth(), m_image.GetHeight());
*/
			CMyBGCDlg::OnPaint();
	}
}
BOOL CColorURLInput::OnInitDialog()
{
	this->ModifyStyleEx(0,WS_EX_APPWINDOW);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CMyBGCDlg::OnInitDialog();


	

 return true;
}

void CColorURLInput::OnBnClickedOk()
{
	
	GetDlgItemText(IDC_EDIT2,m_smsstr);
	OnOK();
}


void CColorURLInput::OnBnClickedCancel()
{
	GetDlgItemText(IDC_EDIT2,m_smsstr);
	EndDialog(1000);
}


void CColorURLInput::OnClose()
{

	GetDlgItemText(IDC_EDIT2,m_smsstr);
		OnOK();
	CMyBGCDlg::OnClose();
}
