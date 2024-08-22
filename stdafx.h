
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif
//#define CuteMode
#ifndef WINVER				// 允许使用特定于 Windows XP 或更高版本的功能。
#define WINVER 0x0501		// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT		// 允许使用特定于 Windows XP 或更高版本的功能。
#define _WIN32_WINNT 0x0501	// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif	
#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类
#include <afxhtml.h>                    // MFC HTML 视图支持




#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持


#include <vector>
#include <set>
#include <map>
#include <list>
#include <shlwapi.h>
#include "algorithm"
using namespace std;
#include "zlib.h"
#include "function.h"
#include "KeepMap.h"
#include "加密解密库.h"
#include "MySortListCtrl.h"
#include "MyBGCDlg.h"
#include "FreeWareDlg.h"
#include "ReadAUStdioFile.h"
#include "RegMySoft.h"
#include <stdio.h>
//#include "MemDC.h"
//using namespace Gdiplus;
extern bool Global_bNotSimCh;
#include <afxinet.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <iomanip>
//#include <boost/filesystem/operations.hpp>
//#include <boost/filesystem/path.hpp>
//#include <boost/filesystem/fstream.hpp>
//#include <boost/bind.hpp>
#include <boost/regex.hpp>
//#pragma comment( lib,"libeay32.lib" )
//#pragma comment( lib,"ssleay32.lib" )

#include <afxdhtml.h>
#include "publichttp.h"

#ifdef _DEBUG           
#pragma comment( lib,"zlibD.lib")
#pragma comment( lib,"CommonFunLibD.lib")
#pragma comment( lib,"libprotobufD.lib")
#pragma comment( lib,"C:\\项目代码\\silk-arm-ios-master\\src\\SKP_Silk_FIX_Win32_debug.lib")
#else   
#pragma comment( lib,"zlib.lib")
#pragma comment( lib,"CommonFunLib.lib")
#pragma comment( lib,"libprotobuf.lib")
#pragma comment( lib,"C:\\项目代码\\silk-arm-ios-master\\src\\SKP_Silk_FIX_Win32_mt.lib")
#endif

//#define CHECKWRONG 1



#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

const INT64 MAXSCORE=8000000000000000;
extern const CString default_g_checkinformatstr;
extern const CString default_g_equipformatstr;
extern const CString default_g_gamroboformatstr;
extern const CString default_g_storeprice;
const int ID_ShowMainWindow=WM_USER+199;
const int  WM_SHOWTASK=WM_USER+200;
const int  ID_AutoRun=WM_USER+201;
const int WM_SHOWTASKLIST=WM_USER+243;
const int WM_SHOWHIDELIST=WM_USER+244;
const int WM_DownloadZip=WM_USER+245;
const int WM_SWITCHQQ=WM_USER+246;
const int WM_NEWMSG=WM_USER+248;
const int ID_MYOK=WM_USER+249;
const int WM_ANSWER=WM_USER+250;
const int WM_TIMENOTICE=WM_USER+251;
const int WM_PLUGRESPONSE=WM_USER+252;
const int WM_THREADDONE=WM_USER+253;
const int WM_GETALLGROUPOVER=WM_USER+254;
const int WM_RELOGIN=WM_USER+255;
const int WM_GETALLFRIENDOVER=WM_USER+256;
const int WM_RESTART=WM_USER+257;
const int WM_LoginNextQQ=WM_USER+258;
const int WM_NEWJOIN=WM_USER+259;
const int WM_NEWQUIT=WM_USER+260;
const int WM_NEWCHANGE=WM_USER+261;
const int WM_REFRESHLIST=WM_USER+262;
const int WM_ONLINE=WM_USER+263;
const int WM_SHOWALLFRIENDOVER=WM_USER+264;
const int WM_NEWUPDATEADMIN=WM_USER+265;
const int WM_ADD2DATA=WM_USER+266;
const int WM_ALREADYWELCOME=WM_USER+267;
const int WM_ReLoadPri=WM_USER+268;
const int WM_ReLoadDefGame=WM_USER+269;
const int WM_UPDATESTORE=WM_USER+270;
const int WM_ACROSSMSG=WM_USER+271;
const int WM_SLEEPPLUGRESPONSE=WM_USER+272;
const int WM_LoadDllPath=WM_USER+273;
const int WM_RELOADPLUG=WM_USER+274;
const int WM_GetBaiduVoiceToken=WM_USER+275;
const int WM_NEWWITHDRAW=WM_USER+276;
const int WM_EXTRESPONSE=WM_USER+277;
const int WM_CREATEQQDLG=WM_USER+278;
const int WM_UPDATERANKFILE=WM_USER+279;
const int WM_CLEARNOTINGROUP=WM_USER+280;
const int WM_UPDATEISADMININF=WM_USER+281;
const int WM_UPDATEISSHUTUPED= WM_USER + 282;

const int WM_EXITMYSELF = WM_USER + 283;
const int WM_NEXTRUSH= WM_USER + 284;
const int WM_SHOWMYSELF = WM_USER + 286;
const int WM_HIDEMYSELF = WM_USER + 287;
//const int WM_UNINSTALL=WM_USER+247;
const int WM_STOPMSG=WM_USER+1000;
 const int ID_Dynamicplugs=WM_USER+2000;
 const  int CARDLEN=14;
 
extern  BOOL Android_Send1Msg(INT64 m_realgroupnumber,INT64 uin,const CString& oldstr,INT64 backupuin=0,INT64 quotemsgid=0);
extern int getfriendcountonce;
typedef struct _privateimginf
{
	int filesize;
	int width;
	int height;
	int filetype;
	string blocksign;
	CStringA despstr;
	CStringA imgIP;
	int port;
}privateimginf;

typedef struct _daren_rank
{
	int darendays;
	int ranknum;
	_daren_rank()
	{
	ranknum=0;
	darendays=false;
	}
}daren_rank;

typedef struct _UpdateSingleRankfile
{
INT64 groupnum;
INT64 qqnum;
INT64 jointime;
INT64 lastactivetime;
int qqscore;
_UpdateSingleRankfile()
{
	groupnum=0;
	qqnum=0;
	jointime=0;
	lastactivetime=0;
	qqscore=0;
}

}UpdateSingleRankfile;

typedef struct _waittowithdrawmsg
{
INT64 groupnum;
INT64 qqnum;
INT64 MsgID;
UINT msgsign;
int msgxuhao;
int msgtime;
CString content;
_waittowithdrawmsg()
{
	groupnum=0;
	qqnum=0;
	msgsign=0;
	msgxuhao=0;
	MsgID=0;
	msgtime=0;
}
bool operator==(const _waittowithdrawmsg other1)
       {
            return (other1.MsgID==MsgID);
       };

}waittowithdrawmsg;

typedef struct struct_qqnum_msg 
{
	//"age":116,"birthday":"day":25,"month":1,"year":1900,"college":"社会大学","company":"","constellation":1,"email":"ncucf@hotmail.com","gender":1,"hometown_area":"","hometown_city":"",
	//"hometown_country":"","hometown_state":"","location_area":"","location_city":"南昌","location_country":"中国","location_state":"江西","nick":"&nbsp;晨风","occupation":0,"personal":"用经济学思想武装自己的生活观"] 
struct_qqnum_msg()
	{

	}
CString age;
CString day;
CString month;
CString year;
CString college;
CString company;
CString constellation;
CString email;
CString gender;
CString hometown_area;
CString hometown_city;
CString hometown_country;
CString hometown_state;
CString location_area;
CString location_city;
CString location_country;
CString location_state;
CString nick;
CString occupation;
CString personal;
}; 
 typedef struct _NoticeWithDrawStruct
{

CString content;//撤回的时候是撤回的内容，签到则是签到的地点，还有上传文件则是文件名
CString posstr;//今天第3个
INT64 qqgroupid;
INT64 opqqnum;
INT64 qqnum;
int sign;//禁言是【3073】、撤回是[4352]、签到是【4096】或【16】、上传文件是【1000】（自己设置的）
int shuttime;
int withdrawtime;
int msgid;
int time;
_NoticeWithDrawStruct()
{
qqgroupid=0;
opqqnum=0;
qqnum=0;
sign=0;//禁言是【3073】、撤回是[4352]、签到是【4096】、上传文件是【1000】（自己设置的）
shuttime=0;
withdrawtime=0;
msgid=0;
time=0;

}
 bool operator==(const _NoticeWithDrawStruct& other1)
       {
            return (other1.content==content &&other1.qqgroupid==qqgroupid && other1.opqqnum==opqqnum && other1.qqnum==qqnum && other1.sign==sign && other1.shuttime==shuttime&& other1.withdrawtime==withdrawtime&& other1.msgid==msgid&& other1.time==time);
       };
}NoticeWithDrawStruct;
typedef struct _NickSex
 {
	CString nickname;
	BOOL bMale;
CString area;
CString oldcardname;
CString nowcardname;
int overdaysjointime;
int overdayslastspeaktime;
int birth;
int age;
int level;
_NickSex()
{
overdaysjointime=0;
overdayslastspeaktime=0;
birth=0;
age=0;
level=0;
bMale=-1;
}
 }NickSex;
 typedef struct group_memberinf 
{
INT64 qq;
int age;
int bMale;
CString nickname;
CString cardname;
INT64 shutupendtime;
INT64 jointime;
INT64 lastactivetime;
int overdaysjointime;
int overdayslastspeaktime;
int qqscore;
group_memberinf()
{
overdaysjointime=0;
overdayslastspeaktime=0;
lastactivetime=0;
jointime=0;
shutupendtime = 0;
bMale=-1;
age=0;
qq=0;
qqscore=0;
}

};
 typedef struct qqlevel_dareninf 
{
int qqlevel;
int qqdarenlevel;
int qqlikenum;
BOOL bNeedfetchflag;
qqlevel_dareninf()
{
qqlevel=0;
qqdarenlevel=0;
qqlikenum=0;
bNeedfetchflag=true;
}

};
  typedef struct _SingleUpload
{
	
	INT64 groupid;
	CString httpaddress;
	HWND m_hwnd;
}SingleUpload;
 typedef struct _UploadGroupImgStruct
{
	INT64 realqq;
	INT64 realqqgroup;
	BOOL bLocalFileflag;
	CString httpaddress;
	
}UploadGroupImgStruct;

 typedef struct _UploadGroupwaitImgStruct
{
	INT64 toqq;
	INT64 backupuin;
	INT64 msgid;
	INT64 m_realgroupnumber;
	CString defnumstr;
	set<CString> needwaitimgpathset;
}UploadGroupwaitImgStruct;


 typedef struct _GroupCardName
{
	INT64 realqq;
	INT64 realqqgroup;
	TCHAR cardnamebuf[256];
}GroupCardName;
 typedef struct _qqretdata
{
	CString polltype;
	  CString Content;
	  CString typestr;//group_request_join;
	  CString file_name;
	  CString mode;
	  CString sendname;
	  int retcode;
        INT64 FromUin;
		INT64 ToUin;
       INT64 GroupCode;
	   INT64 request_uin;
      INT64 ReplyIp;
        INT64 MsgId;
        INT64 MsgId2;
		int lc_id; 
		int InfoSeq;
        int MsgType;
        
		int rtstatus;
		INT64 GroupID;
		INT64 RealUin;
       int service_type;
	   INT64 account;
       INT64 SendUin;
       int Seq;
        int Time;
		CString Timestr;
 _qqretdata()
  {
	  lc_id=0;
	  request_uin=0;
	  GroupID=0;
	  RealUin=0;
	  request_uin=0;
account=0;
rtstatus=99;
  retcode=0;
  FromUin=0;
  ToUin=0;
  GroupCode=0;
  InfoSeq=0;
  MsgId=0;
  MsgId2=0;
  MsgType=0;
  ReplyIp=0;
  SendUin=0;
  Seq=0;
  Time=0;
  }
}qqretdata;
  typedef CKeepMap<CString,LPCTSTR,CString,LPCTSTR> CKeepStrStrMap;
extern CKeepStrStrMap g_qqserveripmap;
extern CKeepMap<INT64,INT64,CString,LPCTSTR> g_sourcetofindgroup;
extern INT64 GetGCodeFromGid(INT64 gid);
extern INT64 GetGidFromGCode(INT64 gcode);
extern BOOL GetUinSingleWholeQQInf(INT64 groupid, INT64 uin, CString& nickname, int& bMale, NickSex* rttempnicksex, int timeout, BOOL bAnyway = false);
#define CMemDC XCMemDC