
// 晨风qq机器人.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "晨风qq机器人.h"
#include "晨风qq机器人Dlg.h"
#include <tlhelp32.h>
#include <Psapi.h>

#include "sha1.h"
#pragma comment (lib,"Psapi.lib")
int cntopen;
CString ttttt1;
CString ttttt2;

const int myfilelength2=1340242900;//15174656;//
CRITICAL_SECTION g_csevent,g_cswnd,g_csdatabase,g_cslog;
#pragma data_seg(".QQSKINTOOL") 
HWND sharehwnd=0;
#pragma data_seg () 
#pragma comment(linker,"/SECTION:.QQSKINTOOL,RWS") 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C晨风qq机器人App
//CDownloadSkinDlg *m_downloadskindlg=NULL;
extern BOOL retryloginflag;
extern BOOL retryloginflag2;
extern BOOL retryloginflag3;
extern BOOL g_remoteloginflag;
extern BOOL g_remoteencryptflag;
extern CStringvect g_remote_setenvevent;
extern CString g_remote_enfilepath;
extern BOOL bFirsttime;
int screen_xsize;
	int screen_ysize;
CString g_remote_lastownqq;
CString g_remote_defaultpassword;

BEGIN_MESSAGE_MAP(C晨风qq机器人App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// C晨风qq机器人App 构造

C晨风qq机器人App::C晨风qq机器人App()
{
	// 支持重新启动管理器
	//um_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 C晨风qq机器人App 对象

C晨风qq机器人App theApp;


// C晨风qq机器人App 初始化
void PrintProcessNameAndID( DWORD processID,CString& rtszModName )
{

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID );

	// Get the process name.
	TCHAR szModName[512]=_T("");
	if (NULL != hProcess )
	{
		HMODULE hMod;
		DWORD cbNeeded;
		


		// Get the full path to the module's file.

		int lll=GetModuleFileNameEx( hProcess, NULL, szModName,  sizeof(szModName));
		if(lll!=0)
		rtszModName=szModName;


	}
	


	CloseHandle( hProcess );
}


DWORD GetPPid(CString& processpath)
{    
HANDLE         hProcessSnap = NULL; 
PROCESSENTRY32 pe32      = {0}; 
 
    //  Take a snapshot of all processes in the system. 

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 

    if (hProcessSnap == (HANDLE)-1) 
        return (FALSE); 
 
    //  Fill in the size of the structure before using it. 

    pe32.dwSize = sizeof(PROCESSENTRY32); 
 
    //  Walk the snapshot of the processes, and for each process, 
    //  display information. 

    if (Process32First(hProcessSnap, &pe32)) 
    {
        while(pe32.th32ProcessID!=GetCurrentProcessId())
              Process32Next(hProcessSnap, &pe32);
    }
	CloseHandle(hProcessSnap);

	//processpath=pe32.szExeFile;
	DWORD pid=pe32.th32ParentProcessID;

	PrintProcessNameAndID(pid,processpath);
    return pid;
}
BOOL bNotLuanchflag=false;
BOOL bNotanotherLuanchflag=false;
void atest(int a)
{
int b=a;

}
void btest(int& a)
{
int b=a;

}

const TCHAR setupbuf[128]=_T("qqrobotsetup");
BOOL C晨风qq机器人App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	//_CrtSetBreakAlloc(320489);
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	
	//::function::RemoveR_CopyFileW(_T("d:\\gggg.txt"),_T("d:\\445s.txt"),false);
	CWinApp::InitInstance();
	Global_bNotSimCh=!!::function::GetOSLangID();
	AfxEnableControlContainer();

	CString processpath;



	
//		CString app_key=_T("3tQliwzJh3rr");
//CString app_secre=_T("fhrbkt3xCjokwc5Qimv");
//CString realapp_secret=app_secre+'n';
//CString realm = _T("xiaoi.com");
//CString method = _T("POST");
//CString uri = _T("/ask.do");
//
//	CSHA1 sha1;
//	std::basic_string<TCHAR> strReport1;
//	std::basic_string<TCHAR> strReport2;
//	std::basic_string<TCHAR> strsignature;
//CString nonce=_T("f98er24s8ur3zpzxh0da1yoje8760xlsls7e9th4");
//
//	CString strsha1;
//strsha1.Format(_T("%s:%s:%s"),app_key,realm,realapp_secret);
//	
//	CStringA pszAnsi=(CStringA)strsha1;
//	sha1.Update((UINT_8*)pszAnsi.GetBuffer(), strlen(pszAnsi));
//	sha1.Final();
//	sha1.ReportHashStl(strReport1, CSHA1::REPORT_HEX_SHORT);
//		sha1.Reset();


	//_asm
	//{
	//	int 3;
	//}
	CString logpath;

		logpath=::function::complete_path(_T("保存加密后的密码文件到系统文件夹.txt"));
if(PathFileExists(logpath))
{
	g_bLocalSaveflag=false;
} 

	logpath=::function::complete_path(_T("保存加密后的密码等文件到当前文件夹.txt"));
if(PathFileExists(logpath))
{
	g_bLocalSaveflag=true;
}

	//GetPPid(processpath);
	TCHAR windowsbuf[256];
	GetWindowsDirectory(windowsbuf,256);
	CString expstr;
	expstr.AppendChar('\\');
	expstr.AppendChar('e');
	expstr.AppendChar('x');
	expstr.AppendChar('p');
	expstr.AppendChar('l');
	expstr.AppendChar('o');
	expstr.AppendChar('r');
	expstr.AppendChar('e');
	expstr.AppendChar('r');
	expstr.AppendChar('.');
	expstr.AppendChar('e');
	expstr.AppendChar('x');
	expstr.AppendChar('e');

	lstrcat(windowsbuf,expstr);

	TCHAR bufselfpath[512];
		GetModuleFileName(NULL,bufselfpath,512);


	//if(processpath.IsEmpty()||StrStrI(processpath,_T("晨风机器人"))||StrStrI(processpath,_T("晨风QQ机器人"))||StrStrI(processpath,setupbuf)||_tcsicmp(windowsbuf,processpath)==0||_tcsicmp(bufselfpath,processpath)==0)
	{
	bNotLuanchflag=true;

	bNotanotherLuanchflag=1;
	}
#ifdef _DEBUG
bNotLuanchflag=true;
bNotanotherLuanchflag=1;
#endif


	//if(bNotLuanchflag)
	//MessageBox(0,processpath,_T("正常启动"),0);
	//else
	//MessageBox(0,processpath,_T("不正常启动"),0);
	//
	/*TCHAR buf[128]=_T("gihehehadkcpcphhhhhhcogdgghihjcogngfcpgjgfdcdddedfgmgjgoglcohehihe");
	::function::Reversible_encode(buf,false);
	*/

//	CString filenamefmt;
//		filenamefmt.Format(_T("qunnick219161023.txt"));
//CFile file1;
//int ddlen=1024*1024;
//char *localbytebuf=new char[ddlen];
//memset(localbytebuf,0,ddlen);
//	if(file1.Open(::function::complete_path(filenamefmt),CFile::modeRead))
//	{
//
//	ddlen=file1.Read(localbytebuf,ddlen);
//	file1.Close();
//	}
//
//	CStringvect	getgroupidbackstr;
//	CStringvectA getutfnamebackstr;
//CString expressstr;
//expressstr.Format(_T("(?<=\",\"uin\":)\\d+\\b"));
//	
////GetRegEX((char*)localbytebuf,expressstr,getgroupidbackstr);//need consider of the actual keyname
//
//		expressstr.Format(_T("(?<=,\"nick\":\").*?(?=\")"));
//	
//GetRegEX((char*)localbytebuf,expressstr,getutfnamebackstr,false,true);//need consider of the actual keyname
//return false;
	/*TCHAR bufmsg[256]={0x60A8,0x7684,0x8D26,0x53F7,0x5728,0x53E6,0x4E00,0x5730,0x70B9,0x767B,0x5F55,0xFF0C,0x60A8,0x5DF2,0x88AB};
	
	AfxMessageBox(bufmsg);*/
	//HWND hwnd1=::FindWindow(_T("ATL:65165368"),NULL);
	//int rtvalue=0x3ff00000;//00 00 f0 3f;
	//byte aa[4]={0x00,0x00,0xf0,0x3f};
	//int rttttt=*(int*)aa;
//
	//CString strrr=_T("藏头诗 猋毳");
//CString strrr=_T("藏头诗天下无敌 ");
//	TCHAR *bufff=new TCHAR[1024];
//	QueryPoemResponse(strrr,bufff);
//	delete []bufff;
//	return false;
	//INT64 newcur_uin=0x34934543354543;
	//::function::int64bitset(newcur_uin,64);
	//INT64 bit_value=pow((double)2,(double)(64-1));
	//	INT64 bit_value2=~bit_value;

	//newcur_uin=newcur_uin&bit_value2;
//	CString strrr=_T("南京多粗");//_T("南极有多大");//_T("南极有多冷");
//	TCHAR *bufff=new TCHAR[1024];
//	BaiduKnowResponse(strrr,bufff);
//	delete []bufff;
//return false;
//CString ChsStr=_T("赌博一赔十下注一百二十五来个60或者十七万三千新1亿");
////
////	//Chinese2ArabianNum(ChsStr);
////
//INT64 aa=102000;
////aa=_ttoi(_T("20 000"));
////	//aa=-123407890;
//halfChinese(aa,ChsStr);
//	
//	Chinese2ArabianNum(ChsStr);
	//string tempsex;

	//if(tempsex.at(4)==(char)0xE5)
	//tempsex="dfsd";
	AfxOleInit();
	LPTSTR strCmdLine = GetCommandLine();
	BOOL uninstallflag=false;
	LPTSTR puninstall=StrStrI(strCmdLine,_T("/uninstall"));
LPTSTR pretryflag=StrStrI(strCmdLine,_T("cf_retry"));
LPTSTR pretryflag2=StrStrI(strCmdLine,_T("cf_soon_retry"));
LPTSTR pretryflag3=StrStrI(strCmdLine,_T("cf_soon2_retry"));

LPTSTR pretryflag4=StrStrI(strCmdLine,_T("cf_remote_login"));
LPTSTR pretryflag5=StrStrI(strCmdLine,_T("cf_remote_encrypt"));

if(StrStrI(strCmdLine,_T("forbidcf")))
{
g_forbidsaveanyrankfile=true;
}

//g_remote_lastownqq=vectemp[3];
	//		g_remote_defaultpassword=vectemp[4];


//AfxMessageBox(strCmdLine);
if(pretryflag5)
{
//AfxMessageBox(strCmdLine);
	g_remoteencryptflag=true;
	CStringvect vectemp;
	//	_asm
	//{
	//	int 3;
	//}
	if(StrStr(pretryflag5,_T("\"")))//cf_remote_encrypt "c:\\de bug\\1.txt" a.dll getkeyaddqq chuanru 123456
	{


	::function::getmytoken(pretryflag5,_T("\""),vectemp);
	if(vectemp.size()>=2)
	{
	g_remote_enfilepath=vectemp[1];

	if(vectemp.size()>=3)
	{
	CStringvect vectemp2;
		::function::getmytoken(vectemp[2],_T(" "),vectemp2);
	if(vectemp2.size()>3)
		{
		g_remote_setenvevent.push_back(vectemp2[0]);
		g_remote_setenvevent.push_back(vectemp2[1]);
		g_remote_setenvevent.push_back(vectemp2[2]);
		g_remote_setenvevent.push_back(vectemp2[3]);

		}
	if (vectemp2.size() > 4)
	{
		g_remote_setenvevent.push_back(vectemp2[4]);
	}

	}

	}

	}
	else
	{
		::function::getmytoken(pretryflag5,_T(" "),vectemp);
	
		if(vectemp.size()>1)
		{
		g_remote_enfilepath=vectemp[1];

		if(vectemp.size()>5)
		{
		g_remote_setenvevent.push_back(vectemp[2]);
		g_remote_setenvevent.push_back(vectemp[3]);
		g_remote_setenvevent.push_back(vectemp[4]);
		g_remote_setenvevent.push_back(vectemp[5]);

		}
		if (vectemp.size() > 6)
		{
	g_remote_setenvevent.push_back(vectemp[6]);
		}
		}
	}
		

}
else if(pretryflag4)
{
	//AfxMessageBox(_T("remote"));
		g_remoteloginflag=true;
}
else if(pretryflag)
	{
		retryloginflag=true;

		
	}
	else if(pretryflag2)
	{
		retryloginflag2=true;

	}
	else if(pretryflag3)
	{
		retryloginflag3=true;

	}
	if(pretryflag4||pretryflag||pretryflag2||pretryflag3)
	{
	CStringvect vectemp;
	if(pretryflag)
		::function::getmytoken(pretryflag,_T(" "),vectemp);
	else if(pretryflag4)
		::function::getmytoken(pretryflag4,_T(" "),vectemp);
	else if(pretryflag2)
		::function::getmytoken(pretryflag2,_T(" "),vectemp);
	else if(pretryflag3)
		::function::getmytoken(pretryflag3,_T(" "),vectemp);

		if(vectemp.size()>=2)
		{
			g_remote_lastownqq=vectemp[1];
		}
		if(vectemp.size()>=3)
		{
			g_remote_defaultpassword=vectemp[2];
		}

	}

	if(!g_remote_lastownqq.IsEmpty()&&_ttoi64(g_remote_lastownqq)<10000)
		{
g_remote_lastownqq=_T("");
g_remote_defaultpassword=_T("");
g_remoteloginflag=false;
		}

	//AfxMessageBox(strCmdLine);
	if(puninstall)
	{
	uninstallflag=true;	
	}


	
if(!uninstallflag)
if(!bNotLuanchflag)
{
//MessageBox(0,processpath,windowsbuf,0);

}
	
	AfxEnableControlContainer();
	
	

	//mainhwnd=::FindWindow(_T("#32770"),cneng_share_title[Global_bNotSimCh]);

	
	/*CString fmtstr;
	fmtstr.Format(_T("0x%x"),mainhwnd);
	AfxMessageBox(fmtstr);*/
	if(uninstallflag)
	{
	if(sharehwnd)
{  
	
	::SendMessage(sharehwnd,WM_UNINSTALL,0,0);
Sleep(1000);
		return false;
}




	

	return false;
	
	}
	else if(sharehwnd)
{  
	if(!g_remoteencryptflag&&!g_remoteloginflag)
	{
	//::ShowWindow(sharehwnd,SW_FORCEMINIMIZE);
::ShowWindow(sharehwnd,SW_MINIMIZE);
::ShowWindow(sharehwnd,SW_RESTORE);
::ShowWindow(sharehwnd,SW_NORMAL);
		return false;
	}
}
 

	//http://baidu.lecai.com/lottery/draw/list/202时时彩
	//http://trend.baidu.lecai.com/jxssc/baseTrend.action
//CString resrdbpathhere=SaveAs_complete_path(_T("res.rdb"));
//if(!PathFileExists(resrdbpathhere))
	//::function::releaseself(resrdbpath,_T("WAVE"),false,IDR_resrdb);
	
	//BOOL dfsdf=::SendMessage((HWND)0x145534,WM_PLUGRESPONSE,0,(LPARAM)0);


//CString defrdbpathhere=SaveAs_complete_path(_T("default.rdb"));
//#ifndef _DEBUG
	if(::function::IsRunUAC()&&!::function::IsRunAsAdministrator())
		{	TCHAR bufselfpath[256];
		GetModuleFileName(NULL,bufselfpath,256);
			TCHAR bufsys[256];
			GetSystemDirectory(bufsys,256);

			if(_tcsncicmp(bufsys,bufselfpath,3)==0)
			{
				CString menuconfig=_T("user_setting.ini");
	::function::GetLanuageFromCFSoftPath(menuconfig,menuconfig,true);

	bFirsttime=!PathFileExists(menuconfig);

	CReadAUStdioFile file1(true);
				if(!file1.Open(menuconfig,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite|CFile::shareDenyNone))
	{
	

			::function::ShellexecuteAsAdmin(bufselfpath,true);
			return false;
		}
				else
				{
				file1.Close();
				}
			}
			
			
	}
//#endif
	

//screen_xsize=::GetSystemMetrics(SM_CXSCREEN);
//screen_ysize=::GetSystemMetrics(SM_CYSCREEN);
	SetRegistryKey(cneng_registryKeyName[Global_bNotSimCh]);
	

	C晨风qq机器人Dlg dlg;
	//dlg.IDD = IDD_Main;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。

	//LoadPwdFile(false);
	// ClosePwdFile();
	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

