// QR2CodeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "晨风qq机器人.h"
#include "QR2CodeDlg.h"

#include "afxdialogex.h"



IMPLEMENT_DYNAMIC(CQR2CodeDlg, CDialog)




CQR2CodeDlg::CQR2CodeDlg(CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CQR2CodeDlg::IDD, pParent)
{
	fontsize=9;
	colorcode=0x00fc0606;//蓝色
m_rtvalue=NULL;
m_bstopdrawflag=false;
m_img_size=0;
m_validstate=true;
}

CQR2CodeDlg::~CQR2CodeDlg()
{
	
	if(m_rtvalue)
	{
	delete []m_rtvalue;
	m_rtvalue=NULL;
	}

}

void CQR2CodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
const int WM_TypeCapcha=WM_USER+1258;

BEGIN_MESSAGE_MAP(CQR2CodeDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
ON_WM_PAINT()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &CQR2CodeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CQR2CodeDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CQR2CodeDlg 消息处理程序

void CQR2CodeDlg::OnPaint()
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

		if(m_bstopdrawflag)
		{
		//CDC* pDC = this->GetDC();
		CPaintDC dc(this);
 TCHAR buffer[] = _T("二维码已失效，请点击刷新");
 dc.SetBkMode(TRANSPARENT);
 dc.Rectangle(m_myrect);
 dc.TextOut(m_myrect.left, m_myrect.top, buffer, sizeof(buffer));

 m_bstopdrawflag=false;
 	CMyBGCDlg::OnPaint();
		}
		else
		{
		CPaintDC dc(this);
		
	
		if(m_img_size)
 m_image.Draw(dc, m_myrect.left, m_myrect.top, m_image.GetWidth(), m_image.GetHeight(), 0, 0, m_image.GetWidth(), m_image.GetHeight());
			CMyBGCDlg::OnPaint();
		}
	}
}

extern float GetRandomTimeStr(CString &str);

void CQR2CodeDlg::LoadOneQRImage()
{
	CString urldownstr;
		CString realhostname=_T("ssl.ptlogin2.qq.com");
		CString processpath;
		CString randtimestr;
GetRandomTimeStr(randtimestr);
processpath.Format(_T("/ptqrshow?appid=501004106&e=0&l=M&s=5&d=72&v=4&t=%s"),randtimestr);
		//urldownstr.Format(_T("https://ssl.captcha.qq.com%s"),processpath);
		//::function::DownloadHttpFile(urldownstr,(byte*)m_rtvalue,m_img_size);
		//MySendWeb2(realhost,processpath,(byte*)m_rtvalue,NULL,m_img_size,NULL);
m_img_size=0;
		MySendWeb(realhostname,processpath,(byte*)m_rtvalue,0,m_img_size,true);
			if(!m_image.IsNull())
		m_image.Detach();
		m_bstopdrawflag=false;
		GetCImageFromByte(m_image,(byte*)m_rtvalue,m_img_size);

		SetWindowText(_T("webqq必须用手机扫描二维码才能登录，请用手机扫二维码进行登录"));
		if(m_img_size)
		{
			static BOOL onceflag=0;
			if(onceflag==0)
			{
				onceflag=1;
		m_myrect.SetRect(m_myrect.left,m_myrect.top,m_myrect.left+m_image.GetWidth(),m_myrect.top+m_image.GetHeight());

			}
			
			InvalidateRect(m_myrect);
			m_validstate=true;
		}
			

}
BOOL CQR2CodeDlg::OnInitDialog()
{
	this->ModifyStyleEx(0,WS_EX_APPWINDOW);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CMyBGCDlg::OnInitDialog();



		GetDlgItem(IDC_2code)->GetWindowRect(m_myrect);
		//GetDlgItem(IDC_yanzhengpic)->GetClientRect(myrect);
//ClientToScreen(myrect);
		ScreenToClient(m_myrect);
	//m_mypic.Create(NULL,WS_CHILD|WS_VISIBLE|SS_BITMAP|SS_CENTERIMAGE,myrect,this);
	//m_mypic.ShowWindow(true);

	SetIcon(m_hIcon, TRUE);
		m_img_size=0;
	m_rtvalue=new char[1024*1024];
LoadOneQRImage();
	
		SetTimer(1,1000,NULL);
	//CClientDC dc(this);

 //m_image.Draw(dc, myrect.left, myrect.top, m_image.GetWidth(), m_image.GetHeight(), 0, 0, m_image.GetWidth(), m_image.GetHeight());

 	 // int tempstyle=2;
	 // m_mypic.Draw(tempstyle,-1);
 return true;
}
int CQR2CodeDlg::TestLoginState()
{
	CString realhostname=_T("ssl.ptlogin2.qq.com");
		CString skeyvalue;
				
				
	CString processpath;
byte *imagebytebuf;
imagebytebuf=new byte[1024*512];	
UINT ddlen=0;

	processpath.Format(_T("/ptqrlogin?webqq_type=10&remember_uin=1&login2qq=1&aid=501004106&u1=http%%3A%%2F%%2Fw.qq.com%%2Fproxy.html%%3Flogin2qq%%3D1%%26webqq_type%%3D10&pttype=1&ptredirect=0&ptlang=2052&daid=164&from_ui=1&pttype=1&dumy=&fp=loginerroralert&action=0-0-2095&mibao_css=m_webqq&t=undefined&g=1&js_type=0&js_ver=10141&login_sig=&pt_randsalt=0"));
	//processpath.Format(_T("/login?u=%s&p=%s&verifycode=%s&webqq_type=10&remember_uin=1&login2qq=1&aid=1003903&u1=http%%3A%%2F%%2Fweb.qq.com%%2Floginproxy.html%%3Flogin2qq%%3D1%%26webqq_type%%3D10&h=1&pttype=1&ptredirect=0&ptlang=2052&daid=164&from_ui=1&dumy=&fp=loginerroralert&action=1-16-24797&mibao_css=m_webqq&t=1&g=1&js_type=0&js_ver=10037&login_sig=3w7ek7oQbOzdtCFW92wOacUgeAdjIs1WhLwIVjn-sz4PAGVrnuRdSPPLmf9hRnQl&pt_randsalt=0&pt_vcode_v1=0&pt_verifysession_v1=%s"),m_ownqqnumber,pstr,m_verifycode,fvsession);
	
	MySendWeb(realhostname,processpath,imagebytebuf,0,ddlen,true);
	CString str222;
::function::utf8_wchar((char*)imagebytebuf,str222);

m_jumpurl=str222;
if(str222.Find(_T("http://"))!=-1)
{
CString expressstr,rtmatchstr;
	
expressstr.Format(_T("(?<=,').+?(?=',)"));
	CStringvect getbackstr;
GetRegEX(str222,expressstr,getbackstr);//need consider of the actual keyname
if(getbackstr.size()>2)
{
	m_jumpurl=getbackstr[1];
}
}

if(0)
	MessageBox(str222,0,0);	
delete []imagebytebuf;

if(str222.Find(_T("http://"))!=-1)
	return 0;
else if(str222.Find(_T("二维码未失效"))!=-1)
	return 1;
else if(str222.Find(_T("二维码已失效"))!=-1)
	return 2;
else if(str222.Find(_T("二维码认证中"))!=-1)
	return 4;
else 
	return 3;

}

void CQR2CodeDlg::OnTimer(UINT nIDEvent)
{
	if(nIDEvent==1)
	{
	int rtstate=TestLoginState();

	if(rtstate==0)
	{
	OnOK();
	}
	else if(rtstate==2)
	{
		if(m_validstate)
		{
		m_bstopdrawflag=true;
		m_validstate=false;
		if(!m_image.IsNull())
		m_image.Detach();

		InvalidateRect(m_myrect);

		SetWindowText(_T("二维码已失效，请点击刷新"));
		}
	//m_image.Load();
	}
else if(rtstate==4)
	{
		
		SetWindowText(_T("二维码已扫描，请在手机上点“确认登录”"));
		
	//m_image.Load();
	}

	
	}
	
	
	CDialog::OnTimer(nIDEvent);
}

void CQR2CodeDlg::OnBnClickedOk()
{
	
	
	OnOK();
}


void CQR2CodeDlg::OnBnClickedCancel()
{
	
	EndDialog(1000);
}


void CQR2CodeDlg::OnClose()
{
		int rtstate=TestLoginState();
		if(rtstate==0)
		EndDialog(IDOK);
		else
		EndDialog(1000);
		//OnOK();
	CMyBGCDlg::OnClose();
}


BOOL CQR2CodeDlg::PreTranslateMessage(MSG* pMsg)
{
	if((pMsg->message ==WM_MOUSEMOVE))
{
HCURSOR hcur;
POINT pt=pMsg->pt;
ScreenToClient(&pt);


//CWnd *pwnd=ChildWindowFromPoint(pt);
//int nid=pwnd->GetDlgCtrlID();
if(m_myrect.PtInRect(pt))
{

hcur=AfxGetApp()->LoadStandardCursor(IDC_HAND);
::SetCursor(hcur);

}
else
{
hcur=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
::SetCursor(hcur);
}
	}
	else if((pMsg->message ==WM_LBUTTONDOWN))
{
HCURSOR hcur;
POINT pt=pMsg->pt;
ScreenToClient(&pt);


//CWnd *pwnd=ChildWindowFromPoint(pt);
//int nid=pwnd->GetDlgCtrlID();
if(m_myrect.PtInRect(pt))
{

LoadOneQRImage();
	

}
else
{

}
	}

	return CMyBGCDlg::PreTranslateMessage(pMsg);
}
