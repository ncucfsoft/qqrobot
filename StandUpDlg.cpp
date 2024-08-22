// StandUpDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StandUpDlg.h"
//#include "afxdialogex.h"


// CStandUpDlg 对话框

IMPLEMENT_DYNAMIC(CStandUpDlg, CDialog)

CStandUpDlg::CStandUpDlg(CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CStandUpDlg::IDD, pParent)
{
	bNomultLanguage=true;
		wndIdentification=_T("StandUpDlg");
		//m_clrBkgnd=RGB(128,170,150);
		
		m_clrBkgnd=RGB(220,210,200);
}

CStandUpDlg::~CStandUpDlg()
{
}

void CStandUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStandUpDlg, CDialog)
ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDOK, &CStandUpDlg::OnBnClickedOk)
END_MESSAGE_MAP()
TCHAR ziduan[15][32]={_T("nick"),_T("gender"),_T("shengxiao"),_T("constel"),_T("blood"),_T("birthyear"),_T("birthmonth"),_T("birthday"),_T("phone"),_T("mobile"),_T("email"),_T("occupation"),_T("college"),_T("homepage"),_T("personal")};
char ziduanvalue[15][2048];
BOOL GetUinDetail(INT64 uin,CString& orgnickname)
{
	CStringvect columname_com;

	
	CStringvect columvalue_com;
	CString rstructstr;
	CString g_tkstr;

CString realhostname;
CString processpath;
realhostname=_T("s.web2.qq.com");
CString timestr2;
SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format(_T("%I64d%d"),time1.GetTime(),st.wMilliseconds);
processpath.Format(_T("/api/get_friend_info2?tuin=%I64d&verifysession=&code=&vfwebqq=%s&t=%s"),uin,vfwebqqstr,timestr2);


UINT ddlen=0;
byte *bufnickname=new byte[1024*10];
memset(bufnickname,0,1024*10);
BOOL rtflag=MySendWeb(realhostname,processpath,bufnickname,(char*)NULL,ddlen);
//"nick":"
CString expressstr,rtmatchstr;
	
	BOOL bGetmatch;
	//retcode\":0
CString nicknamestr;
	for(int i=0;i<15;i++)
	{
	if(i==5)
	{
	expressstr.Format(_T("(?<=\"year\":).*?(?=,)"));
	}
	else if(i==6)
	{
	expressstr.Format(_T("(?<=\"month\":).*?(?=,)"));
	
	}
	else if(i==7)
	{
		expressstr.Format(_T("(?<=\"day\":).*?(?=\\})"));
	
	}
	else if(i==2||i==3||i==4)
expressstr.Format(_T("(?<=\"%s\":).*?(?=,)"),ziduan[i]);
	else if(i==9)
expressstr.Format(_T("(?<=\"%s\":\").*?(?=\"\\})"),ziduan[i]);
	else
		expressstr.Format(_T("(?<=\"%s\":\").*?(?=\",)"),ziduan[i]);

	CStringvectA getbackstr;
GetRegEX((char*)bufnickname,expressstr,getbackstr,false,true);//need consider of the actual keyname
char nicknamebuf[2048];

	if(getbackstr.size()>0)
	{
		strcpy(nicknamebuf,getbackstr[0]);
::function::utf8_wchar(nicknamebuf,nicknamestr);
if(i==0)
	orgnickname=nicknamestr;
else
strcpy(ziduanvalue[i],(CStringA)nicknamestr);
	}

	}

delete []bufnickname;
return rtflag;
}
TCHAR sep[2];
BOOL CStandUpDlg::OnInitDialog()
{
	CMyBGCDlg::OnInitDialog();
	INT64 cur_loginqquin;
	cur_loginqquin=_ttoi64(m_ownqqnumber);
	CString nicknamestr;
	GetUinDetail(cur_loginqquin,nicknamestr);
	
	sep[0]=0x2028;
	sep[1]=0;
	
	//CStringvect vectemp;
	//::function::getmytoken(nicknamestr,sep,vectemp);
	
	CString newnickname=nicknamestr;
	if(newnickname.Find(sep)!=-1)
	{
	newnickname.Replace(sep,_T("\r\n"));
	}
	else
	{
		newnickname=_T("");
	for(int i=0;i<nicknamestr.GetLength();i++)
	{
	newnickname+=nicknamestr.GetAt(i);
	newnickname+=_T("\r\n");
	}
	if(newnickname.GetLength()>2)
	newnickname=newnickname.Left(newnickname.GetLength()-2);


	}
	SetDlgItemText(IDC_EDIT22,newnickname);
	
return true;
}
// CStandUpDlg 消息处理程序


void CStandUpDlg::OnBnClickedOk()
{
		CString newnickname;
	GetDlgItemText(IDC_EDIT22,newnickname);
	newnickname.Replace(_T("\r\n"),sep);
	

	CString processpath;

		CString realhostname;
realhostname=_T("s.web2.qq.com");
byte *imagebytebuf=new byte[1024*512];
UINT ddlen=0;
processpath.Format(_T("/api/modify_my_details2"));
	//processpath.Format(_T("/channel/poll?clientid=%d"),clientID);
CStringA rstructstr;
CStringA nickname;
	::function::wchrto_utf8(newnickname,nickname);
	strcpy(ziduanvalue[0],nickname);
	newnickname=(CString)ziduanvalue[14];
	::function::wchrto_utf8(newnickname,nickname);
	strcpy(ziduanvalue[14],nickname);
	rstructstr.Format("{");
	//rstructstr.Format("{\"nick\":\"%s\",\"birthyear\":\"1910\",\"birthmonth\":\"1\",\"birthday\":\"1\",\"gender\":\"male\",\"shengxiao\":\"10\",\"constel\":\"12\",\"blood\":\"3\",\"phone\":\"-\",\"mobile\":\"-\",\"email\":\"68663216@qq.com\",\"occupation\":\"\",\"college\":\"\",\"homepage\":\"\",\"personal\":\"none\",\"vfwebqq\":\"%s\"}",nickname,(CStringA)vfwebqqstr);
	//rstructstr.Format("{\"nick\":\"%s\",\"vfwebqq\":\"%s\"}",nickname,(CStringA)vfwebqqstr);
	CStringA tempstra;
	for(int i=0;i<15;i++)
	{
	tempstra.Format("\"%s\":\"%s\",",(CStringA)ziduan[i],ziduanvalue[i]);
	rstructstr+=tempstra;

	}
	rstructstr+="\"vfwebqq\":\"";
	rstructstr+=(CStringA)vfwebqqstr;
		rstructstr+="\"}";
	BOOL rtflag;
	int ncount=0;
		
	rtflag=QQRPost(realhostname,processpath,rstructstr,imagebytebuf,ddlen);
		

	if(!StrStrIA((char*)imagebytebuf,"\"retcode\":0"))
		rtflag=false;

		CString str222;
		if(!rtflag)
::function::utf8_wchar((char*)imagebytebuf,str222);
		else
			str222=_T("修改竖立网名成功！");
		if(rtflag)
	MessageBox(str222,_T("成功"),0);
		else
	MessageBox(str222,_T("修改竖立网名失败！"),0);
	
	//{"retcode":0}
	delete []imagebytebuf;
	OnOK();
}
