// OtherConfig.cpp : 实现文件
//

#include "stdafx.h"
#include "OtherConfig.h"
//#include "afxdialogex.h"


// COtherConfig 对话框

IMPLEMENT_DYNAMIC(COtherConfig, CDialog)

COtherConfig::COtherConfig(CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(COtherConfig::IDD, pParent)
{

		bNomultLanguage=true;
		wndIdentification=_T("OtherConfigDlg");
		m_clrBkgnd=RGB(180,172,160);
}

COtherConfig::~COtherConfig()
{
}
void COtherConfig::OnDestroy()
{
	

	CDialog::OnDestroy();


	// TODO: 在此处添加消息处理程序代码
}
void COtherConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
BOOL COtherConfig::OnInitDialog()
{
	CMyBGCDlg::OnInitDialog();
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(g_autorunflag);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(g_autologinflag);
((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(g_last_bAuto_online);
	return true;
}

BEGIN_MESSAGE_MAP(COtherConfig, CDialog)
	ON_WM_CTLCOLOR()
		ON_WM_ERASEBKGND()
		ON_WM_DESTROY()
		ON_BN_CLICKED(IDOK, &COtherConfig::OnBnClickedOk)
		ON_BN_CLICKED(IDC_CHECK2, &COtherConfig::OnBnClickedCheck2)
		ON_BN_CLICKED(IDC_CHECK1, &COtherConfig::OnBnClickedCheck1)
END_MESSAGE_MAP()


// COtherConfig 消息处理程序


void COtherConfig::OnBnClickedOk()
{
	
	g_autorunflag=((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	g_autologinflag=((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	g_last_bAuto_online=((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck();
	if(!Isggged&&g_autologinflag)
	{
	//g_autologinflag=0;
	AfxMessageBox(_T("未注册版本功能受限，将无法启用自动登录机器人号码！——如果你是刚注册的，请登录注册qq号之后再重试一次看看！"));
	
	}
	CString	autorunkeyname=_T("Auto_CFRobot_");
	
	TCHAR bufpath[256];
GetModuleFileName(NULL,bufpath,256);
CString stmd5;
	::function::SafeGetCff(stmd5,bufpath,2*lstrlen(bufpath),true);
autorunkeyname+=stmd5;
		::function::AutorunwithSystemOrNot(g_autorunflag,autorunkeyname,NULL);
		OnOK();
}


void COtherConfig::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void COtherConfig::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
}
