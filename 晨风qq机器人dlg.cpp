
// 晨风qq机器人Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "晨风qq机器人.h"
#include "晨风qq机器人Dlg.h"
#include "MemDC.h"
//#include "webconfig.h"
#include "Mmsystem.h"
#include "MockHtmlDlg.h"
#include "psapi.h"
//#include "d:\\项目代码\\public_RC\\MockHtmlDlg.h"
//#include "d:\\项目代码\\public_RC\\webqqfunction.h"
#include "formatstruct.h"
#include "AndroidQQ.h"
#include "JavascriptDlg.h"

#include "crypt.h"

#include "zbase64.h"
BOOL g_honestflag=false;
extern BOOL g_bTestplugexistflag;
void  xmlgetcode(LPTSTR   inout_str, BOOL encode, INT64 qq);
void GetStrvectFromReadGameFile(LPCTSTR filepath,CStringvect &setencevect,BOOL* pbHugeFile=NULL);
BOOL SendFinalMsg(INT64 m_realgroupnumber,INT64 toqq,CString& defnumstr,INT64 backupuin,BOOL bAutoTransfertoXMLflag,BOOL bExactXmlflag,int maxsize,INT64 quotemsgid);
BOOL CheckSpecifyImgtoOtherQQ(INT64 toqq,CString& temprtmd5);
void GetUserDefKey(LPCTSTR newkey,vector<byte>&user_gamekey);
void GetBackBackStr(CString& backorgstr);
void LoadPreLoadDllFile();
extern BOOL bNotLuanchflag;
extern BOOL bNotanotherLuanchflag;
extern CKeepMap<CString,LPCTSTR,INT64,INT64> g_joinqq_passqqnum_map;
 CKeepMap<INT64,INT64,CString,LPCTSTR> g_checkqqwhere_map;
 int g_notipadflag;
int g_orginaljoinqq_passqqnum_map_count;
int g_alldllmenu_nmmcount = 0;
int g_forbidbkgflag = false;
	BOOL bCrackFlag2=false;
	int g_nonewmsgminutes;
extern BOOL Checkdosi();
extern BOOL bcannetflag;
extern BOOL bcannetflag2;
extern BOOL bunLimflag;
extern CString g_remote_lastownqq;
extern CString g_remote_defaultpassword;
CString g_lastshutinf;
BOOL g_totalvalid=false;//如果testplug.dll返回来了，就说明是注册版。
BOOL g_quotepermission=false;//如果testplug.dll返回来了，就说明是注册版。
BOOL g_tipsflag=false;
int g_regularfunexecutenum=0;
BOOL g_bbaidusourceflag=false;//是否是推广的渠道 222333
BOOL g_bAutoHeirLast=false;
BOOL g_now_bAuto_online=false;
BOOL g_last_bAuto_online=false;
CKeepMap<CString, LPCTSTR, CString,LPCTSTR> g_vectormenustr;
int g_last_nowport=8080;
CStringA g_last_strIP;
CStringA g_last_Token002C;
CStringA g_last_Token004C;
CStringA g_last_sessionKey;
CStringA g_last_skey;
CStringA g_last_vkey;
CString g_autoappendtext;
CString g_autoinserttext;
CString g_checksinstr;
BOOL g_donegetsizeonceflag=false;
int g_xmlgetmaxsize=255;
int g_anotherxmlgetmaxsize=255;
BOOL bCrack3=false;
int g_mymaxxmlnum=0;
extern CKeepMap<CStringA,LPCSTR,CStringA,LPCSTR> g_md52postfixMap;
extern CCriticalSection lockmd52postfixmapres;
extern char wangwangbuf[32];
extern const int treaturemaxnum;
extern const int treaturemaxnum1;
#include "Aclapi.h"
#include "ColorInput.h"
#include "ColorSMSInput.h"
#include "ColorURLInput.h"
#include "OtherConfig.h"
#include "SelectUpImg.h"
#include "ModifyTitle.h"
#include "StandUpDlg.h"
#include "AutoReplyRule.h"
#include "MoreAdminList.h"
#include "AdminList.h"
#include "IgnoreDlg.h"
#include "FontInfSetDlg.h"
#include "publichttp.h"
#include "time.h"
#include "ShellApi.h"
#include "Gdiplusheaders.h"
#include "Gdiplus.h"

using namespace Gdiplus;
volatile int limitnumber=25;
BOOL bNoGameflag=false;
TCHAR g_Verdatestr[1256];
TCHAR g_Vertestdatestr[1256];

CString g_purenumberversion;
CString g_ksidmd5;
CString g_reporturl;
CString g_ocrkey;
CStringA newtimedstr;
BOOL g_bGetdirectimgurl=false;//获取群图片直接下载地址
BOOL g_bShowWholeSongAds;//显示完整的点歌网址
BOOL g_bNewUserGuestPlusTime;//新进群友名片前缀改成游客加时间
BOOL g_bForbidReJoin;//禁止重复加群
BOOL g_bwelcomealways;//重复进群每次都发欢迎词
BOOL g_bAutoQuitIfExpire;//超过有效期后自动退群
CString g_bAutoReportAds;//自动回报机器人在线状态的接口网址
int g_DefaultValidDays;//拉机器人进群后默认有效期天数
BOOL g_bIgnoreAnyAgreeOrDeny;//不处理任何同意或拒绝加群的事务
BOOL g_bIgnoreDeny;//不处理拒绝加群的事务
BOOL g_bAllowCreateCookies;//允许机器人生成cookies文件
BOOL g_bMustDefShowWeb;//必须明确写了显示网址内容才显示网页内容
BOOL g_bAllowSamepinyin;//成语接龙支持同音字而不需要是同一个字
BOOL g_bautosavetalk;//自动保存httpapi所需要的输入和输出数据
CString g_bMust2receiver;//普通消息模式下每条回复内容都自动艾特收消息的人
CString g_bMustappend2receiver;//普通消息模式下每条回复内容都自动艾特收消息的人

BOOL g_bLocalSaveflag=true;
CString g_App_key_str;//小i机器人app_key
CString g_App_secret_str;//小i机器人app_secret
int g_rtlinenum=0;
//获取群图片直接下载地址
		CString g_voiceshowlanstr;
		CString g_xmlformatstr,g_xmliconstr,g_xmlpreheadstr,g_xmlfontcolorstr;
		set<CString> g_manualchangedname_set;
		set<INT64> g_manualchangedqq_set;
	int g_xmlmaxsize=0;
	//int g_xmlminsize = 0;
	CString g_xmlstuff;
	BOOL g_xmlkeeponelineflag;
	CString g_msgreplace;
int g_autoreturnfalg;//卡片消息一行消息太长则自动添加换行符
int g_autoswich2normalflag;
CString* p_g_xmlformatstr,*p_g_xmliconstr,*p_g_xmlpreheadstr,*p_g_xmlfontcolorstr;

int* p_g_xmlmaxsize=0;

int* p_g_autoreturnfalg;//卡片消息一行消息太长则自动添加换行符
int* p_g_autoswich2normalflag;//卡片消息若超过最大允许字数后自动换成普通消息发送

CString temp_g_xmlformatstr,temp_g_xmliconstr,temp_g_xmlpreheadstr,temp_g_xmlfontcolorstr;

int temp_g_xmlmaxsize=0;

int temp_g_autoreturnfalg;
int temp_g_autoswich2normalflag;
BOOL g_allxmlflag=false;	
CString g_modifycardurl;
CString g_thirdshutupurl;
CString g_thirdkickurl;
CString g_voiceoutall;
CString g_forcevoiceoutall;

CString g_testplugpath;
		BOOL g_totalforbidprivate=false;
		BOOL g_notxmlwhenprivate=false;
		BOOL g_transfertonoxmlwhenless=false;
		BOOL g_allowuseawardgoods=false;//允许用$奖励$物品
		BOOL g_alwaysuploadvoice=false;
		BOOL g_deletevoicefile=false;
		BOOL g_newplaymusicmode=false;
			int g_bAutoAppendFileName;
BOOL g_bForidrecognizegroupvoice;
BOOL g_bForidrecognizeprivatevoice;
set<INT64> g_exceptgroupvoicelist;
set<INT64> g_exceptprivatevoicelist;

BOOL g_bShowTxtAfterrecognizegroupvoice;
BOOL g_bForbidSavevoicefile;
BOOL g_bStoprecognizegroupimage;
int g_def_nickname_len=48;
int g_def_preplusnickname_len=48;
int Fun_sendprivateimg(byte* imgbin,int len,string blocksign,string filemd5sign,BOOL bGroup);
BOOL g_closeplugfunction=false;
 SYSTEMTIME g_locallasttime;
 SYSTEMTIME g_localtestlasttime;
 BOOL bExeOver10dayflag=false;
 BOOL bDllOver6dayflag=false;
CString g_modifydate;
BOOL bKickOffflag=false;
BOOL bForbiddenUse=false;
BOOL g_temporaryignorall;
BOOL g_autoagreeinvite;
int g_history_maxsize;
UINT ProAddNoticetoGroup(LPVOID lp)
{
	_NoticeStruct *pqqgroup = (_NoticeStruct *)lp;

	CStringA strfmt;
	CStringA timestr2;
	SYSTEMTIME st;
	GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format("%I64d%d", time1.GetTime(), st.wMilliseconds);
	CString content;
	CString title;

	CStringA  out_utfbuf;

//	pqqgroup->content.Replace(_T("【换行】"), _T("\\n"));

	//pqqgroup->content.Replace(_T("\r\n"), _T("\\n"));
	content=pqqgroup->content;
	if(!::function::GetHalfStr(pqqgroup->content,&title,&content,_T("|"),false))
		title=pqqgroup->content.Left(5);

	content.Replace(_T("【换行】"), _T("\r\n"));

	//if(0)
	//	pqqgroup->content.Replace(_T("【换行】"), _T("<BR>"));

	
	
	

	::function::wchrto_utf8(content, out_utfbuf);

	char *contentbufeee = new char[1024 * 200];

	strcpy((char*)contentbufeee, (const char*)out_utfbuf);

	::function::urlencode((char*)contentbufeee);

	char *titlebufeee = new char[1024 * 200];

	::function::wchrto_utf8(title, out_utfbuf);
	strcpy((char*)titlebufeee, (const char*)out_utfbuf);

	::function::urlencode((char*)titlebufeee);


	char *bufeee = new char[1024 * 200];

	UINT ddlen = 0;
	CString realhostname = _T("web.qun.qq.com");
	CString processpath = _T("/cgi-bin/announce/add_qun_notice");

	BOOL rtflag = false;


	strfmt.Format("bkn=%d&qid=%lld&title=%s&text=%s", m_myg_tk, pqqgroup->qqgroupid, titlebufeee, contentbufeee);

	//vkey=%s  vector2char(qq.vkey),&//strfmt.Format("gc=%I64d&bkn=%d&ul=%s",pqqgroup->qqgroupid,m_myg_tk,pqqgroup->uin_liststr,pqqgroup->content);
	strcpy((char*)bufeee, strfmt);
	ddlen = strlen((char*)bufeee);
	rtflag = MySendWeb(realhostname, processpath, (byte*)bufeee, (char*)bufeee, ddlen, 0);//additionalhead
	//rtflag=MySendWeb(realhostname,processpath,(byte*)bufeee,(char*)bufeee,ddlen);

	delete[]contentbufeee;
	delete[]titlebufeee;

	delete[]bufeee;
	delete pqqgroup;
	return rtflag;
}

const CString default_g_checkinformatstr=_T("[imgurl]http://q2.qlogo.cn/headimg_dl?dst_uin=$数字1$&amp;spec=100[/imgurl]\r\nface0x3CD8C6DF当前排名第$积分排名$位\r\nface0x3DD8B0DC财富总额：$财富总额$$积分单位名称$\r\nface0x28270000奴隶个数：$奴隶个数$\r\nface0x3DD8ABDC连续签到：$连续签到天数$天\r\nface0x3CD888DF连续签到排名：第$连续签到天数排名$数字1$$名\r\nface0x3DD851DC当前等级:$当前等级$（第$当前等级数$数字1$$级）\r\nface0x3DD825DD离下一等级【$下一个等级$】还差$还差等级积分$$积分单位名称$！");
const CString default_g_equipformatstr=_T("face0x3DD87CDC勋章【$勋章$】\r\nface0x01260000房产【$房产$】\r\nface0x3DD87CDC坐骑【$坐骑$】\r\nface0x01260000宝物【$宝物$】\r\nface0x3DD87CDC防御装备【$防御$】\r\nface0x01260000攻击装备【$武器$】\r\nface0x3DD87CDC防御指数【$防御指数$】\r\nface0x01260000攻击指数【$攻击指数$】\r\nface0x3DD87CDC敏捷指数【$敏捷指数$】\r\n【用精简格式显示数字】");
const CString default_g_gamroboformatstr=_T("face0x01260000你今天赌博$赌博次数$次\r\nface0x3DD87CDC赢了$赌博赢的次数$次\r\nface0x01260000获得$赌博获得积分$金币\r\nface0x3DD87CDC打劫$打劫次数$次\r\nface0x01260000face169成功$打劫成功次数$次\r\nface0x3DD87CDC获得$打劫获得积分$金币\r\nface0x01260000离当前设置的次数上限还差$还差上限次数$次！");
const CString default_g_storeprice=_T("vip\t 1万\r\n[有效期15天]勋章神圣勋章\t 2千\r\n[有效期7天]勋章荣誉勋章\t 1千\r\n勋章银星勋章\t 2千\r\n勋章功绩勋章\t 1500\r\n勋章十字勋章\t 1200\r\n勋章铜心勋章\t 1000\r\n勋章紫心勋章\t 700\r\n勋章军功勋章\t 500\r\n防御黑洞防护\t 3万\r\n防御防空洞\t 2万\r\n防御防弹车\t 2千\r\n防御防弹衣\t 1千\r\n武器核弹\t 2万\r\n[有效期24小时]武器导弹\t 2千\r\n武器火炮\t 5千\r\n武器手枪\t 2千\r\n武器匕首\t 5百\r\n[有效期3天]宝物幸运石\t 1万\r\nvip宝物隐形石\t 5万\r\nvip宝物速度石\t 6万\r\nvip宝物能量石\t 7万\r\nvip宝物幸运能量石\t 10万\r\nvip宝物隐形能量石\t 10万\r\n禁拍禁赠禁买禁卖宝物武林盟主称号\t 10万\r\n房产泥房\t 5千\r\n房产瓦房\t 2万\r\n[有效期70年]房产公寓\t 10万\r\n房产别墅\t 30万\r\n房产海景别墅\t 40万\r\n房产城堡\t 50万\r\n房产王府\t 70万\r\nvip房产皇宫\t 100万\r\nvip房产天庭\t 200万\r\n坐骑小毛驴\t 500\r\n坐骑自行车\t 1000\r\n坐骑电动车\t 2000\r\n坐骑摩托\t 3000\r\n坐骑汗血宝马\t 30万\r\n坐骑赤兔马\t 40万\r\n坐骑兰博基尼\t 40万\r\n坐骑法拉利\t 50万\r\nvip坐骑宾利\t 60万\r\nvip坐骑劳斯莱斯\t 100万\r\nvip坐骑空军一号\t 200万");
CString poptipsformat,poptipsformat2;
CString g_customstr;//=_T("互联小助手");//
TCHAR DefaultAdmin[64]=_T("13402429;");
//#include "jpeg/jpeg.h"
CString g_selfdeftail;
CStringvect g_selfdeftailvector;
CStringvect g_randomadtailvector;
CString str222;
CString g_sourceweb;
CString g_additionalsourceweb;
CString g_defgameweb;
CString g_buycardweb;
CString g_agreeinviteweb;
CString g_cfxysourceweb;
CString g_cfxysourceweb2;
CString g_additionalprewords;
CString g_checkinformatstr;
CString g_equipformatstr;
CString g_gamroboformatstr;
CString g_accesstokenstr=_T("25.74245d7147ba9a636e36b456643bb72e.315360000.1903934810.282335-3940417");

//https://openapi.baidu.com/oauth/2.0/token?grant_type=client_credentials&client_id=52HHDPb6KISIEBvLdXixww1Y&client_secret=QLxaC2FemWAm5TZtyaUVFfNOkgS8SVrj
//
//{"access_token":"24.7eca56476343ba868fc74085f736bbec.2592000.1512743758.282335-3940417","session_key":"9mzdDFCIxsbzXo0+FIeKsQC8oBhv\/Ym4j5tWX51dg1P\/gWa53eHhBzjev\/ScE7gC9n\/34buoNhKPcoCyO0olG9\/0hKhG","scope":"public brain_all_scope wise_adapt lebo_resource_base lightservice_public hetu_basic lightcms_map_poi kaidian_kaidian ApsMisTest_Test\u6743\u9650 vis-classify_flower bnstest_fasf","refresh_token":"25.2ba2dd9091d3deae139dcbbfd4be700c.315360000.1825511758.282335-3940417","session_secret":"61fe62baa0df11944fe17dc28a58f34c","expires_in":2592000}
//6月3日更新

TCHAR g_accesstokenstrbuf[90];
CString g_voicenextip;

vector<byte> g_gamekey;
vector<byte> g_transitpermissionkey;
vector<byte> g_versionmonthkey;
int g_gamblehardscale;
set<INT64> g_had_joined_groupset;
set<INT64> g_otherwelcome_groupset;
INT64 g_lastinvitegroupnum=0;
int g_checkgroupmembertime;
int g_bidbacknum;
int g_paybackscale;
set<INT64> g_alreadydivine_set;
set<INT64> g_alreadyaward_set;

CKeepMap<INT64,INT64,daren_rank,daren_rank>  g_daren_rankmap;

extern BOOL nosense;
CCriticalSection lockqqmsgdlgres;
extern CCriticalSection lockUpGroupPrivatevoicemapres;
extern CCriticalSection lockUpGroupssovoicemapres;
extern CKeepMap<int,int,CString,LPCTSTR>  g_sso2voicesignMap;
extern CKeepMap<CString,LPCTSTR,CString,LPCTSTR>  g_GroupPrivatevoicemap;

BOOL firstmsgflag=true;
//#pragma comment( lib,"jpeg/libjpeg.lib")
//Res\Status\FLAG\Big\busy.png
TCHAR statusbuf[7][32]={_T("online"),_T("callme"),_T("away"),_T("busy"),_T("silent"),_T("hidden"),_T("offline")};
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
	CEvent allgroupevent;
CEvent friendevent;

		TCHAR *responsebuf;
// C晨风qq机器人Dlg 对话框
	DWORD inittime;
	INT64 initsystemtime;
	DWORD fullinittime; 
BOOL companyverion=false;
BOOL g_minstateflag;
extern void TranslateUbuffer(LPCTSTR orgbuf,OUT TCHAR *newbuf);
extern void loglasterror(LPCTSTR saveerror);
void LoadUUUsernameAndPwd();
extern int g_all_countdown;
extern int g_all_msgcountdown;
extern int g_all_blogcountdown;
extern int g_all_counterror;
extern int g_total_count;
extern CEvent newprivateimgsendmsg;
extern CEvent doneoneprivateimg;
BOOL onlyonceIconflag=0;
HWND g_ignorehwnd;
CString g_sleepforRelogin;
BOOL g_alreadyhomepage=true;//2016.3.5//都当作设置了IE
BOOL outoutflag=false;
BOOL qqgroupqun=false;//防止破解
int trial_ncount=10;
//extern 	CDownloadSkinDlg *m_downloadskindlg;
	int threadnum=10;
	int threadovernum=0;
	int bFrequentnum=0;
BOOL bExitPostThread=true;
BOOL bExitProcess=false;
BOOL bAutoGetQQnumber=true;
BOOL bExitComment=true;
UINT ProTakeRequestFun(LPVOID lp);
//安卓协议新增加的变量



	SOCKADDR_IN g_bcast;
SOCKET g_socket;
SOCKET g_imgsocket;
SOCKET g_groupimgsocket;
vectorbyte cacherecv_vect;
CCriticalSection locksend;
CCriticalSection locksendforseq;
CCriticalSection lockrandomadres;
CCriticalSection lockgidgcoderesource;
CCriticalSection lockandroid_gqqnickmapresource;
CCriticalSection lockgsendvectorbyteresource;
CCriticalSection lockg_manualchangedname_set;
CCriticalSection lockg_manualchangedqq_set;

CCriticalSection lockhellowres;
CCriticalSection lockgidbAdminresource;
CCriticalSection lockgidmemberresource;
CCriticalSection lockqqnickgender;
CCriticalSection locksend_recv;
CCriticalSection lockqqacdlg;
CCriticalSection lockignoreresource;
CCriticalSection lockhellowrCes;
CCriticalSection lockuinrealqqres;
CCriticalSection lockgidrealgnumres;
CCriticalSection lockreadgroupnickres;
CCriticalSection locksocketmapres;
CCriticalSection lockcancelmsgmapres;
CCriticalSection lockgetqqinfmapres;
CCriticalSection lockupgroupimgeventmapres;
CCriticalSection lockweb2md5mapres;
CCriticalSection lockqqinformationres;

CCriticalSection lockuinsinglegetres;
CCriticalSection locknicksexmapres;
CCriticalSection lockg_singleqqinfmapres;
CCriticalSection lockg_qqdarenlevelinfmapres;
CCriticalSection lockg_qqdarenlevelgetting;

CCriticalSection lockUpGroupImgmapres;

CCriticalSection locklastgroupresource;
CCriticalSection lockimagetextresource;
CCriticalSection lockandroidmembercountsource;
CString SpecialInsertMiddleStuffToFileName(LPCTSTR filename,LPCTSTR insertstuff);

CKeepMap<INT64,INT64,INT64,INT64> g_init_GidGcodemap;
	CKeepMap<INT64,INT64,INT64,INT64> GidGcodemap;
CKeepMap<INT64,INT64,INT64,INT64> GcodeGidmap;
CKeepMap<INT64,INT64,vector<group_memberinf>,vector<group_memberinf>> GidMemberInfmap;
CKeepMap<INT64,INT64,BOOL,BOOL> GidbAdminMap;
CKeepMap<INT64, INT64, BOOL, BOOL> GidbRobotShutupMap;
CKeepMap<int,int,pbmsg_retryinf,pbmsg_retryinf> g_pbsendvectorbyte_map;
CKeepMap<INT64,INT64,int,int> g_group_membercountmap;
CKeepMap<INT64,INT64,INT64,INT64> g_group_ownerqqmap;
CKeepMap<INT64,INT64,int,int> g_androidgroup_membercountmap;
CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_imagetextmap;
CKeepStrStrMap g_gameinputfilepathmap;
CKeepStrStrMap g_gamesetencefilepathmap;
CKeepStrStrMap g_extraimgsignbuffermap;

CKeepStrStrVectMap g_filepath2outreplacemap;
vector<int> g_ctronlidvect;
CKeepMap<INT64,INT64,struct_qqnum_msg,struct_qqnum_msg> g_qqnum_structmoreprofile_map;
CKeepMap<int,int,struct_group_msg,struct_group_msg> g_Seq_struct_group_msg_map;
CKeepMap<INT64,INT64,CString,LPCTSTR> g_sourcetofindgroup;
CKeepMap<INT64,INT64,CEvent*,CEvent*> g_group_LastGroupNickNameeventMap;
CKeepMap<int,int,CEvent*,CEvent*> g_socketeventMap;
//CKeepMap<CString,LPCTSTR,list<CEvent*>,list<CEvent*>> g_cancelmsgeventMap;
void SaveSingleGameFile(BOOL bEncodefilesize,LPCTSTR defganefn,const byte *bytebuf,const CString& txtcontent);
BOOL fileunpack(const unsigned char* instr, int32 instrlen, const unsigned char* key, unsigned char*  outstr, int32* outstrlen_ptr, byte* versionbuf, const CString& path);
CKeepMap<int,int,CString,LPCTSTR> g_ssomd5postMap;

CKeepMap<INT64,INT64,CEvent*,CEvent*> g_GetqqinfeventMap;

CKeepMap<INT64,INT64,CStringvect,CStringvect> g_group_LastGroupQQvectMap;

_Other Other;
_Hash Hash;
_BIN Xbin;
_Tlv tlv;
qq_info qq;
AndroidQQ sdk;
qq_global global;
int pc_sub_cmd;
vector<JceStruct_FriendInfo> g_friendlist;
vector<JceStruct_GroupInfo> g_grouplist;
BOOL bNeedResetconnect=false;
BOOL bNeedReDetectflag=false;
INT64 luin;
UINT appSeq;
UINT g_randomnumforsend;
UINT g_recgroupmsgxuhao;
UINT last_Join_appSeq;
CStringA last_error;
BOOL bNeedCode=false;
int g_sendpos=1000;
extern BOOL ConnectQQServer();






//安卓协议新增加的变量_end

qqgrouprule g_defaultqqgrouprule;
BOOL g_qqrestartingflag=false;
BOOL g_stoprestart=false;
BOOL g_readGroupOver=true;
BOOL g_readFriendOver=true;
HWND g_InputingHwnd=(HWND)-1;
//int g_timeover;
int g_bidwaittime;
int g_privatepercent;
int g_includekey;
int g_status_selcur;
int g_slientmode;
int g_speedonly=false;
int g_bTuopanflag;
int g_bApplyAll;
int g_bIgnoreAll;
int g_autorunflag;
int g_autologinflag;
BOOL g_Androidflag=true;
BOOL g_bQQflag=false;
	 
int getfriendcountonce=20;
BOOL retryloginflag;
BOOL retryloginflag2;
BOOL retryloginflag3;
BOOL g_remoteloginflag;
BOOL g_remoteencryptflag;
CStringvect g_remote_setenvevent;
CString g_remote_enfilepath;
int g_defaultstopply;
int g_autonotice;
int g_autonoticetime;
int g_timereportflag;
int g_nohistory;
int g_friend_request_method;
CString g_friend_welcomemsg;
CString g_friend_pincodestr;//群验证消息为某某某时自动同意
CString g_plusdir;
CString g_qqruledir;
CString g_grouprankpath;
CString g_qqreplydir;
CString g_groupimgdir;
CString g_voicedir;
BOOL g_autoreceiveflag;
CString g_qqreceivefiledir;
CString g_hellowstr;
CString g_helpstr;
set<CString> g_reservecmdset;
CString g_gameliststr;
CString g_adminhelpstr;

//CString g_prefixstr;
CString g_autoreplycategory;
int g_fontsize;
int g_boldflag;
CString g_fontname;
CString g_fontcolorstr;


CString g_privatedefaultanswer;
CKeepMap<INT64,INT64,CString,LPCTSTR> g_querysongquickmap;
CString ptwebqqhash,verifysessionhash;
CString lastptwebqqhash;
CStringA imgkeystr,imgsigstr;
UINT ProGetFriends(LPVOID lp);
CReadAUStdioFile historyfile1(true);
BOOL GetOnlineBuddy();
UINT ProAutoReceiveFile(LPVOID lp);
CString hashO(const CString &uin, const CString &ptwebqq);
CString hashO2(const CString &b, const CString &i);
extern void catcherror(LPCTSTR path,LPCTSTR error);
extern UINT SendWelcome(LPVOID lp);

void GetAllColor(BOOL bXmlFlag=false);
int getfrontoffsetFrom2Str(CString& mystr,CString& nextstr);
C晨风qq机器人Dlg *g_mainhwnddlg;
	CString m_verifycode,m_passwordstr,m_ownqqnumber,m_content,m_passhashcode,m_capcdcode;
	CString g_defaultorgpassword;
	//CString m_cur_content;
	CString m_pgv_pvid;
	CStringvect m_total_content;
	int g_bOnlyOneElseqq=false;
	int m_cur_number;
	int m_myg_tk;
	CString g_skey;
	CString g_qqsuperkey;
	int m_limitnumber,m_ncount;
	setvector<CString> g_loginedset;
	CString g_groupfilespath;
CString g_specifygrouprankpath;

	CString g_recentliststr;


CCriticalSection lockgroupmsg;
CCriticalSection lockggroup_uinsetmap;
CCriticalSection lockggroup_realqqsetmap;
CCriticalSection lockgalreadykickoutsource;
CCriticalSection lockgnameresource;
CCriticalSection lockfriendresource;

CCriticalSection lockgqqnickmapresource;
CCriticalSection locksongmapsource;
CCriticalSection lockgroupnameresource;
CCriticalSection lockgroupbeignoreresource;
CCriticalSection lockLastCardNameMap;
CCriticalSection lockmanualchangecarMap;
CCriticalSection locklastchangecomMap;
CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_privateqqweb2md5Map;
CCriticalSection lockqqwebmd5Map;

CKeepMap<CString,LPCTSTR,byte*,byte*> g_priimgmd5bytesMap;
CKeepMap<CString,LPCTSTR,int,int> g_priimgmd5filelenMap;

CCriticalSection lockimgmd5bytesMap;


CCriticalSection lockssomd5postMap;
CKeepMap<CStringA,LPCSTR,CStringA,LPCSTR> g_privatemd5postfixMap;
CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_privatewebaddressmd5Map;
CCriticalSection lockpriwdsmd5Map;
CCriticalSection lockmd5postfixMap;

//WholeInformation g_singleqqinfo;

volatile BOOL bstop1;
volatile BOOL bstop2;
volatile BOOL bstop3;
volatile BOOL bstop4;
volatile BOOL bstop5;
volatile BOOL bstop6;

BOOL bCrackFlag=false;
BOOL g_getcheckweb=false;
CString g_xmlhead;
BOOL bFirsttime=false;
BOOL bfake=false;
BOOL bfake2=false;
BOOL g_realrowNum = 0;
BOOL g_bforward2owner=false;
BOOL bCreateRegfile=false;//生成了注册文件
CString g_content,g_defaultpassword;
CString g_lastownqq,g_lastotherqq;
CString g_beforechangeqq;
CString	g_ownqqfn;
CString g_rushfn;
CString g_selfgamefn;
CString g_foreverblackfn;
CString g_notreplyprivatefn;
CString g_notreplygroupfn;
CString g_moreselfgamedir;
CString g_defgamefn;
CString	g_privilegeownqqfn;
CString g_nicknamefnpath;
CString g_uinrealqqfnpath;
INT64 g_robneedLowestRankNum;
int g_robneedwaitTime;
int g_initscore;
volatile BOOL g_captchamode=false;
BOOL g_holdon=false;
volatile int g_switchmode;
volatile int g_internetflag;
volatile int g_conmentblogid;
volatile int g_internetmsgflag;
volatile int g_msgtimes;	
volatile int g_periodtime;
//volatile BOOL g_sessionanswerfalg;

//CString malecardcharacter;
//CString femalecardcharacter;

CString g_groupimgurl;
//void GetFontNameAndSize();
static CString lastqqnumber;
CString uu_username;
CString uu_pwd;
CReadAUStdioFile g_autoreplyfile1(true);
CReadAUStdioFile g_Privilegeautoreplyfile1(true);
//#define twoeight

#ifdef twoeight
CReadAUStdioFile g_additionaltimerfile1(true);
int g_timer2_gap=2;
#endif
CKeepStrStrVectMap g_autoreplymap;

CKeepStrStrMap g_playsongreplymap;

CKeepStrStrVectMap g_Privilegeautoreplymap;
CKeepStrStrPVectMap g_gamePrivilegeautoreplymap;
CKeepStrStrVectMap g_variousvalueMap;
CStringvect g_variousvalueVector;
set<INT64> g_forever_blacklist;
set<INT64> temp_forever_blacklist;
set<INT64> tempdel_forever_blacklist;
CKeepMap<INT64,INT64,CString,LPCTSTR> g_discusslist;
set<INT64> g_notreplyprivate_list;
set<INT64> g_notreplygroup_list;

CCriticalSection lockqqimgres;
CKeepMap<INT64,INT64,CString,LPCTSTR> g_qq2lastimgmap;
CKeepStrStrMap g_dreamreplymap;
CKeepStrStrMap g_regoutputvect;
BOOL g_bShowChineseNum;

int g_smarttipsforsong;
BOOL g_workindiscussgroup;
BOOL g_doubletipPrivate;
CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>> g_inputreplacemap;

CKeepStrStrMap g_expresscodemap;
CKeepStrStrMap g_qqserveripmap;

vector<CString> g_divinevector;
//CKeepStrStrMap g_outputreplacemap;

CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>> g_outputreplacemap;
CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_privilegeoutputreplacemap;

CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>> g_morereplacemap;

CKeepMap<CString,LPCTSTR,INT64,INT64> g_rplevelmap;
CKeepMap<INT64,INT64,set<INT64>,set<INT64>> g_group_uinsetMap;
CKeepMap<INT64,INT64,set<INT64>,set<INT64>> g_group_realqqvectMap;

CKeepMap<INT64,INT64,HWND,HWND> g_realgroup_hwndMap;
CKeepMap<INT64,INT64,INT64,INT64> g_pitchguessMap;

CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> g_group_uinNameMap;
CKeepMap<INT64,INT64,CKeepINT64StrAMap*,CKeepINT64StrAMap*> g_group_LastCardNameMap;
CKeepMap<INT64,INT64,set<CString>,set<CString>>  g_manualchangecarmap;
CKeepINT64StrMap g_lastchangecommap;
CKeepMap<INT64,INT64,retryStruct,retryStruct> g_group_uinRetryMap;

CStringvect g_namematchvect;
//CKeepMap<INT64,INT64,qqnickgender,qqnickgender> g_realqqnamegender_map;
CCriticalSection lockmsglogmap;
//CKeepMap<int,int,CString,LPCTSTR> g_groupmsglogmap;
CKeepMap<INT64,INT64,CString,LPCTSTR> UinNickNameMap;
CKeepMap<INT64,INT64,INT64,INT64> UinRealNumMap;
CKeepMap<INT64,INT64,INT64,INT64> GidRealGNummap;
CKeepMap<INT64,INT64,qqgrouprule,qqgrouprule> GRealNumRulemap;
CKeepMap<INT64,INT64,qqgrouprule,qqgrouprule> org_GRealNumRulemap;
CKeepMap<INT64,INT64,CReadAUStdioFile*,CReadAUStdioFile*> GRealFilemap;
CKeepMap<INT64,INT64,CKeepStrStrVectMap*,CKeepStrStrVectMap*> GRealReplymap;
CKeepMap<INT64,INT64,CReadAUStdioFile*,CReadAUStdioFile*> GPrivilegeRealFilemap;
CKeepMap<INT64,INT64,CKeepStrStrVectMap*,CKeepStrStrVectMap*> GPrivilegeRealReplymap;


CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> GrouprealqqNickmap;
CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> last_GrouprealqqNickmap;

CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> Android_GrouprealqqNickmap;

CKeepMap<INT64,INT64,NickSex,NickSex> qqNicksexmap;
CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_UploadGroupImgMaxp;

CKeepMap<INT64,INT64,BOOL,BOOL> g_groupbeIgnoreMap;
CKeepMap<INT64,INT64,CString,LPCTSTR> GidNickNamemap;
CKeepMap<INT64,INT64,CString,LPCTSTR> RealGroupNumNickNamemap;
int g_totalgroupnumber=0;
//CKeepINT64StrMap GRealQQNickNamemap;

CKeepMap<INT64,INT64,CAcceptRequestDlg*,CAcceptRequestDlg*> m_mapqqacdlg;
CKeepMap<INT64,INT64,CString,LPCTSTR> FriendUinNickNameMap;
CKeepMap<INT64,INT64,CString,LPCTSTR> CategoryIndexNickNameMap;
CKeepMap<INT64,INT64,set<INT64>,set<INT64>> CategoryUinNameMap;
CKeepMap<INT64,INT64,CMsgDlg*,CMsgDlg*> m_mapqqmsgdlg;
CKeepMap<int, int, CButton*, CButton*> g_dynbuttonmap;

set<INT64> robotfriendset;

static set<INT64> g_tempgroupuinset;
int GetSynGameFile(CString& txtcontent,LPCTSTR g_defgameweb,byte *bytebuf);
BOOL GetUinNickName(INT64 uin,CString& nicknamestr);
BOOL GetUinSingleNickName(INT64 m_realgroupnumber,INT64 uin,CString& nicknamestr,int& bMale,int timeout);
BOOL GetAllGroupNickName();
BOOL GetGroupUinNickName(INT64 groupuin);
BOOL SendGroupImgqqMsg(INT64 groupuin,LPCTSTR msgcontent);
UINT CreateThreadPool(LPVOID lp);
BOOL bAlreadyReadGroupInf=false;
COLORREF GetRandColor(BOOL bXmlFlag=false);
CStringvect backbufvect;

vector<idiombuf> g_idiomvect;

vector<rushstuffbuf> g_publicrushstuffvect;

CCriticalSection lockdislikevectres;
CKeepMap<CString,LPCTSTR,INT64,INT64> dislkbackbufvect;

BOOL g_bManQQgroupListflag=false;
list<INT64> shutuplist;
set<INT64> manualqqdlglist;
TCHAR robotaqcat[256]=_T("机器人应答小组");
TCHAR robotlink[256]=_T("");//=_T("http://www.cfxy.me/robotlink.txt");
TCHAR pcfgname[256]=_T("qqrobot.txt");
TCHAR chsRegURL[256]=_T("http://www.qqshow123.com/productinfo.php?id=26");
TCHAR buychsRegURL[256]=_T("http://b.qqshow123.com/");//http://item.taobao.com/item.htm?id=20314226668

TCHAR RegURL[]=_T("http://qqtmpf.com/manual.html");

TCHAR skinhomepage[512]=_T("http://www.qqshow123.com");//_T("http://123.sogou.com/?11075")//http://www.2345.com/?9049
BOOL Isggged=false;
BOOL showggg=false;
BOOL g_qqregflag=true;
int clientID=53999199;
int ccccccc=false;
INT64 *pcccflag2;
INT64 ccccflag2=0;
INT64 oofffnum=12345;
int *pcccccc;
BOOL neverupad=true;
int *pggged;
int jjj;
INT64 mysecondoffsetnum;
INT64 g_mysecondoffsetnum;
CString bbbtempstr;
typedef struct _ReceiveFile
{
	INT64 to_uin;
	int lc_id;
	int msgid;
	CString filename;
}ReceiveFile;
typedef struct _RemoveQQFromGroup
{
	INT64 realqq;
	INT64 realqqgroup;
	int seconds;
}RemoveQQFromGroup;

 typedef struct _AcceptStruct
{
INT64 qqgroupid;
INT64 realgroupid;
INT64 requestuin;
INT64 qqaccount;
INT64 ReplyIp;
CString content;
CString qqnickname;
qqgrouprule m_grule;

}AcceptStruct;

CString psessionidstr;
CString vfwebqqstr;
BOOL m_alreadylogin;
BOOL m_alreadycheck;
CString g_windowstext;
CString g_loginwindowstext;
CString g_rrrrwindowstext;
//BOOL bAlreadyAutorun=false;
BOOL bOverVisit=false;
BOOL bHideMainIcon=false;
BOOL DeleteDir(LPCTSTR fromPath);
CWinThread *mywinthread1=NULL;
CWinThread *mywinthread2=NULL;
CWinThread *mywinthread3=NULL;
CWinThread *mywinthread4=NULL;
CWinThread *mywinthread5=NULL;
CWinThread *mywinthread6=NULL;

vector<CWinThread *>  g_getlastgroupWinThreadvect;
extern HWND sharehwnd;
extern BOOL CreateNoAdFile(LPCTSTR bufcontent,LPCTSTR Filename);
extern float GetRandomTimeStr(CString &str);
extern BOOL GetPostfixstr(byte* picsrc,CString* postfixstr);
INT64 GetRealQQnumber(INT64 uin,BOOL bGroup);
BOOL MySendWebLocaltion(LPCTSTR realhostname,LPCTSTR processpath,byte *imagebytebuf,const char* postdata,UINT& ddlen,LPTSTR localtion,int maxlen);
extern vectorbyte inflate_compress(vectorbyte bin);
extern vectorbyte inflate_Decompress(vectorbyte bin);

void SaveGroupRuleAndNickName();
//#define xo666


vector<DLLOPENSET> dllsetvect;
vector<DLLRESPONSE> dllresponsevect;

vector<HINSTANCE> dllmoudlevect;

vector<CString> dllpathvect;
vector<CString> dllnamevect;
int zhcx_pos=-1;

CStringA strIP;
CStringA g_privateimgIP;
int g_privateimgport=443;
int nowport=8080;

CString RtImageMd5Str(LPCTSTR wholestr)
{
	//  /gchatpic_new/2198597416/2198597416-2731528611-963F7E769FC519AAB2A82827025A2882/0?vuin=3095087199&term=2
	CString mymd5str=wholestr;
	CStringvect vectemp;
	::function::getmytoken(wholestr,'-',vectemp);
	if(vectemp.size()==3)
	{
		CStringvect vectemp2;
	::function::getmytoken(vectemp[2],'/',vectemp2);
	mymd5str=vectemp2[0];
	}
	return mymd5str;
}
BOOL GetNumFromJson(const char* rtvalue,LPCTSTR keyname,INT64 *myvalue)
{
	BOOL bFind=false;
	
	CString expressstr,rtmatchstr;
	CString tempstr;
	BOOL bGetmatch;
	expressstr.Format(_T("(?<=\"%s\":)\\d+\\b"),keyname);
	CStringvectA getbackstr;
	GetRegEX((const char*)rtvalue,expressstr,getbackstr,false,true);//need consider of the actual keyname

	if(getbackstr.size()>0)
	{
		if(myvalue)
		*myvalue=_atoi64(getbackstr[0]);
		bFind=true;
	}
	return bFind;
}
BOOL GetStrFromJson(const char* rtvalue,LPCTSTR keyname,CString* myvalue,BOOL bUtf8flag)
{
	BOOL bFind=false;
	CString expressstr,rtmatchstr;
	CString tempstr;
	BOOL bGetmatch;
	expressstr.Format(_T("(?<=\"%s\":\").*?(?=\")"),keyname);
	CStringvectA getbackstr;
	GetRegEX((const char*)rtvalue,expressstr,getbackstr,false,true);//need consider of the actual keyname

	if(getbackstr.size()>0)
	{
		
TCHAR newbuf[2048*10]=_T("");
CString midstr;
if(bUtf8flag)
{

	::function::utf8_wchar(getbackstr[0],midstr);
}
else
	midstr=getbackstr[0];

TranslateUbuffer(midstr,newbuf);

		if(myvalue)
		*myvalue=newbuf;

		bFind=true;
	}
	return bFind;
}
extern void getTxt2(LPCTSTR httpfile,CString& tempstr2,BOOL Isautoredirect);
UINT proProFun2(LPVOID lp)
{
if(ccccccc>1500||*pggged||bunLimflag||bcannetflag2)
{
CString Getverifierstr;
int num=0;


TCHAR regbufcheck1[320]=_T("gihehehadkcpcphhhhhhcocfgdcfgdcfgdcfgdcfgdcfgdcfgdcfgdcfgdcocfgdcfgdcfgdcpcfgdcfgdcfgdcfgdcfgdhbhbcfgdcfgdcfgdcfgdcfgdcohagihadphbhbcfgdcfgdcfgddncfhdcghahahagggmgbghdndb");
	::function::Reversible_encode(regbufcheck1,false);//_T("http://www.%c%c%c%c%c%c%c%c%c.%c%c%c/%c%c%c%c%cqq%c%c%c%c%c.php?qq%c%c%c=%s&pppflag=1")
	CString newqqnumstr = GetNewQQNumForEncode(g_interfaceuin);
	//Getverifierstr.Format(regbufcheck1,'c','f','x','y','m','e','c','f','n','e','w','r','o','b','o','t','n','u','m',newqqnumstr);
	Getverifierstr.Format(regbufcheck1,'q','q','s','h','o','w','1','2','3','c','o','m','c','f','n','e','w','r','o','b','o','t','n','u','m',newqqnumstr);


	Getverifierstr+=_T("&version=");
	Getverifierstr+=g_purenumberversion;
	
			Getverifierstr+=_T("&checksign=");
			Getverifierstr += GetNewcheckSignCode();// g_checksinstr;;

	CString tempstr2;
getTxt2(Getverifierstr,tempstr2,false);

num=_ttoi(tempstr2);



if(num&&num<1500&&num!=30)
{
	
	bfake2=true;


}
	}
return 0;
}

UINT ProGetImageText(LPVOID lp)
{
vector<qqretdata> myqqretdatavect;
struct_group_msg *myvvoce=(struct_group_msg *)lp;
	qqretdata voiceqqdt=Transfer2qqretdata(*myvvoce);
	

		CString urldownstr;
		CString imagemd5str=RtImageMd5Str(voiceqqdt.Content);
		//gchat.qpic.cn/gchatpic_new/2198597416/2198597416-2605739619-963F7E769FC519AAB2A82827025A2882/0?vuin=3095087199&term=2
		urldownstr.Format(_T("http://gchat.qpic.cn%s"),voiceqqdt.Content);

		CString appid, appkey;
		::function::GetHalfStr(g_ocrkey, &appid, &appkey, ' ', false);

		if (g_ocrkey == _T("qq") || g_ocrkey == _T("QQ") || !appkey.IsEmpty())
		{
			CString finalresulttext;

			CString localurl;
			CString outstr;
			::GeturlencodeUtfCString(urldownstr, outstr);

			localurl.Format(_T("http://127.0.0.1/testplug.dll?function=qqocrfun&cmdstr=%s&cfrobotqqnum=%lld&appid=%s&appkey=%s"), outstr, voiceqqdt.SendUin, appid, appkey);
			LocalPlugFunction(localurl, finalresulttext);
			if (!finalresulttext.IsEmpty())
			{
				voiceqqdt.Content = _T("图片文字识别内容：");

				lockimagetextresource.Lock();
				g_imagetextmap[imagemd5str] = finalresulttext;
				lockimagetextresource.Unlock();
				voiceqqdt.Content += finalresulttext;
			}
			else
			{
				voiceqqdt.Content.Format(_T("[imgurl]%s[/imgurl]图片文字识别失败"), urldownstr);
				//[imgurl][/imgurl]识别失败

			}


			myqqretdatavect.push_back(voiceqqdt);
			::SendMessage(mainhwnd, WM_NEWMSG, 0, (LPARAM)&myqqretdatavect);
		}
		//else
		//{

		//	BOOL bprivatevoiceflag = false;
		//	BOOL bGroupPrivatevoiceflag = false;
		//	CString str222;
		//	str222.Format(_T("%s"), _T("before DownloadHttpFile(urldownstr"));
		//	byte *instr = new byte[5024 * 1024];
		//	UINT maxlen = 500 * 1024;
		//	BOOL bAmrflag = false;
		//	Write2MagnetLog(str222, &magnetfile, 9);


		//	if ((0 == ::function::DownloadHttpFile(urldownstr, (byte*)instr, maxlen) && maxlen > 10))
		//	{

		//		if (!GetPostfixstr(instr, NULL))
		//		{


		//			HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, maxlen);
		//			void *  pData = GlobalLock(hGlobal);
		//			memcpy(pData, instr, maxlen);


		//			IStream *  pStream = NULL;
		//			if (CreateStreamOnHGlobal(hGlobal, TRUE, &pStream) == S_OK)
		//			{
		//				CImage image;
		//				try
		//				{
		//					if (SUCCEEDED(image.Load(pStream)))
		//					{

		//						IStream *  pStream2 = NULL;
		//						CreateStreamOnHGlobal(NULL, TRUE, &pStream2);// 创建一个 IStream
		//						//CLSID jpgClsid;
		//						//GetEncoderClsid(L"image/jpeg",&jpgClsid);
		//						image.Save(pStream2, Gdiplus::ImageFormatJPEG);// 把 Bitmap 的内容编码到 IStream 中
		//						//image.Save(::function::complete_path(_T("关键日志.jpg")),jpgClsid);
		//						image.Destroy();
		//						HGLOBAL hGlobal2 = NULL;
		//						GetHGlobalFromStream(pStream2, &hGlobal2);// 获取 IStream 的内存句柄LPBYTE pBits= (LPBYTE)GlobalLock(hGlobal);// pBits 就是存储JPEG内容的内存指针// do something....
		//						LPBYTE pBits = (LPBYTE)GlobalLock(hGlobal2); // pBits 就是存储JPEG内容的内存指针
		//						if (pBits)
		//						{
		//							DWORD size = (DWORD)GlobalSize(pBits);
		//							memcpy(instr, pBits, size);
		//							maxlen = size;
		//						}
		//						GlobalUnlock(hGlobal2);
		//						pStream2->Release();

		//						pStream->Release();
		//						pStream = NULL;

		//					}
		//				}
		//				catch (...)
		//				{
		//					str222.Format(_T("%s"), _T("cimage load error"));

		//					Write2MagnetLog(str222, &magnetfile, 9);

		//				}

		//			}


		//			GlobalUnlock(hGlobal);
		//			GlobalFree(hGlobal);



		//		}




		//		BOOL rtflag = false;
		//		CString additionalhead;
		//		CString realhostname, processpath;
		//		realhostname = _T("apis.baidu.com");
		//		processpath = _T("/apistore/idlocr/ocr");

		//		additionalhead.Format(_T("apikey: %s\r\n"), g_ocrkey);
		//		ZBase64 zBase;
		//		string strTmpResult = zBase.Encode(instr, maxlen, true);
		//		CStringA postbody;

		//		strcpy((char*)instr, strTmpResult.c_str());
		//		::function::urlencode((char*)instr);

		//		postbody.Format("fromdevice=pc&clientip=10.10.10.0&detecttype=LocateRecognize&languagetype=CHN_ENG&imagetype=1&image=%s", instr);
		//		strcpy((char*)instr, postbody);

		//		//::function::urlencode((char*)instr);
		//		maxlen = strlen((char*)instr);

		//		str222.Format(_T("%s"), _T("before MySendWeb(realhostname,processpath"));

		//		Write2MagnetLog(str222, &magnetfile, 9);

		//		rtflag = MySendWeb(realhostname, processpath, (byte*)instr, (char*)instr, maxlen, 0, additionalhead);

		//		if (rtflag)
		//		{

		//			CString wstr;
		//			::function::utf8_wchar((char*)instr, wstr);
		//			CStringvect weather6vect;
		//			CString expressstr;
		//			expressstr.Format(_T("(?<=\"word\":\").*?(?=\")"));
		//			GetRegEX(wstr, expressstr, weather6vect, 0, true);//need consider of the actual keyname
		//			if (weather6vect.size() == 0)
		//			{
		//				expressstr.Format(_T("(?<=\"word\": \").*?(?=\")"));
		//				GetRegEX(wstr, expressstr, weather6vect, 0, true);//need consider of the actual keyname

		//			}
		//			if (weather6vect.size())
		//			{

		//				voiceqqdt.Content = _T("图片文字识别内容：");
		//				CString finalresulttext;
		//				TCHAR newbuf[2048 * 10];
		//				for (int i = 0; i < weather6vect.size(); i++)
		//				{

		//					if (!weather6vect[i].IsEmpty())
		//					{
		//						finalresulttext.Append(_T("\r\n"));


		//						TranslateUbuffer(weather6vect[i], newbuf);
		//						finalresulttext.Append(newbuf);
		//					}
		//				}

		//				if (!finalresulttext.IsEmpty())
		//				{

		//					lockimagetextresource.Lock();
		//					g_imagetextmap[imagemd5str] = finalresulttext;
		//					lockimagetextresource.Unlock();
		//					voiceqqdt.Content += finalresulttext;
		//					myqqretdatavect.push_back(voiceqqdt);
		//					::SendMessage(mainhwnd, WM_NEWMSG, 0, (LPARAM)&myqqretdatavect);
		//				}
		//			}
		//			else
		//			{
		//				expressstr.Format(_T("(?<=\"errNum\":\")\\d+?(?=\")"));
		//				GetRegEX(wstr, expressstr, weather6vect, 0, false);//need consider of the actual keyname
		//				if (weather6vect.size())
		//				{
		//					int error_no = _ttoi(weather6vect[0]);
		//					if (error_no == 300101)
		//					{
		//						voiceqqdt.Content = _T("用户请求过期");
		//					}
		//					else if (error_no == 300102)
		//					{
		//						voiceqqdt.Content = _T("用户日调用量超限");
		//					}
		//					else if (error_no == 300103)
		//					{
		//						voiceqqdt.Content = _T("服务每秒调用量超限");
		//					}
		//					else if (error_no == 300104)
		//					{
		//						voiceqqdt.Content = _T("服务日调用量超限");
		//					}
		//					else if (error_no == 300208)
		//					{
		//						voiceqqdt.Content = _T("未通过实名验证");
		//					}

		//					if (!voiceqqdt.Content.IsEmpty() && error_no != 0)
		//					{
		//						myqqretdatavect.push_back(voiceqqdt);
		//						::SendMessage(mainhwnd, WM_NEWMSG, 0, (LPARAM)&myqqretdatavect);
		//					}



		//				}

		//			}
		//		}
		//	}

		//	delete[]instr;
		//}
	
		
		
		delete myvvoce;
		return 0;
}
BOOL ConnectQQServer()
{
	



int ret;
static BOOL bFirstconn=true;
BOOL nowconnect=bFirstconn;
if(g_socket!=INVALID_SOCKET)
{
	closesocket(g_socket);
	g_socket=INVALID_SOCKET;
}
if(bFirstconn)
{
WORD wVersionRequested;  
    WSADATA wsaData;  
      
 wVersionRequested = MAKEWORD(2, 2); //希望使用的WinSock DLL的版本  
   ret = WSAStartup(wVersionRequested, &wsaData);  //加载套接字库  
    if(ret!=0)  
    {  
        printf("WSAStartup() failed!\n");  
		return false;
        //return 0;  
    }  
	if(LOBYTE(wsaData.wVersion)!=2 || HIBYTE(wsaData.wVersion)!=2)  
    {  
        WSACleanup();   //释放为该程序分配的资源，终止对winsock动态库的使用  
        printf("Invalid WinSock version!\n");  

       return false;  
    }  
	bFirstconn=false;
} 
g_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (g_socket == INVALID_SOCKET)  
    {  
        WSACleanup();  
        printf("socket() failed!\n");  
        return false;  
    }  
  int nTimeout = 5000;  
//设置发送超时为1000ms  
if (SOCKET_ERROR == setsockopt(g_socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&nTimeout, sizeof(int)))  
{  
    fprintf(stderr, "Set SO_SNDTIMEO error !\n");  
	return false;
}  
  nTimeout = 25000;
//设置接收超时为1000ms  
if (SOCKET_ERROR == setsockopt(g_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&nTimeout, sizeof(int)))  
{  
    fprintf(stderr, "Set SO_RCVTIMEO error !\n");  
	return false;
}  
// 有效SO_BROADCAST选项
//BOOL bBroadcast = TRUE;
//::setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcast, sizeof(BOOL));
 
// 设置广播地址，这里的广播端口号（电台）是4567

g_bcast.sin_family = AF_INET;

if(atoi(strIP)==0)
{
    struct hostent *hbd=0;
    //gethostbyname，通过域名得到IP地址，此函数返回一个hostent结构指针，需要进一步转换才能用
	try
	{
    hbd = gethostbyname(strIP);
	}
	catch(...)
	{
		CString str222;
	str222.Format(_T("gethostbyname:%s"),(CString)strIP);

Write2MagnetLog(str222,&magnetfile,9);
	}
    //直接打出来h_addr_list中有乱码，这个不能直接打，需要用下面的inet_ntop来转
    char ipbd[32]={0};

  //  inet_ntop(hbd->h_addrtype, *hbd->h_addr_list,ipbd, sizeof(ipbd));
	if(hbd)
	g_bcast.sin_addr.S_un.S_addr= *(u_long *) hbd->h_addr_list[0]; ;
//strIP=ipbd;
}  
else
g_bcast.sin_addr.S_un.S_addr=  ::inet_addr(strIP);
//inet_ntoa
g_bcast.sin_port = htons(nowport);//);

  int addr_len = sizeof(struct sockaddr_in); 

  try
  {
  ret = connect(g_socket, (struct sockaddr *)&g_bcast, sizeof(g_bcast));  
  }
  catch(...)
  {
  
  }
    if (ret == SOCKET_ERROR)  
    {  
        printf("connect() failed!\n");  
        closesocket(g_socket); //关闭套接字  
      //  WSACleanup();  
//bFirstconn=true;
       return false;  
    }  
	bNeedResetconnect=false;
	//if(nowconnect==false)
	//	  sdk.QQOnLine();
	return true;
}
BOOL ConnectGroupImgServer(LPCSTR temp_privateimgIP,int temp_privateimgport)
{
	



int ret;
static BOOL bFirstconn=true;
BOOL nowconnect=bFirstconn;
if(g_groupimgsocket!=INVALID_SOCKET)
{
	closesocket(g_groupimgsocket);
	g_groupimgsocket=INVALID_SOCKET;
}
if(bFirstconn)
{
WORD wVersionRequested;  
    WSADATA wsaData;  
      
 wVersionRequested = MAKEWORD(2, 2); //希望使用的WinSock DLL的版本  
   ret = WSAStartup(wVersionRequested, &wsaData);  //加载套接字库  
    if(ret!=0)  
    {  
        printf("WSAStartup() failed!\n");  
		return false;
        //return 0;  
    }  
	if(LOBYTE(wsaData.wVersion)!=2 || HIBYTE(wsaData.wVersion)!=2)  
    {  
        WSACleanup();   //释放为该程序分配的资源，终止对winsock动态库的使用  
        printf("Invalid WinSock version!\n");  

       return false;  
    }  
	bFirstconn=false;
} 
g_groupimgsocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (g_groupimgsocket == INVALID_SOCKET)  
    {  
        WSACleanup();  
        printf("socket() failed!\n");  
        return false;  
    }  
  int nTimeout = 30000;  
//设置发送超时为1000ms  
if (SOCKET_ERROR == setsockopt(g_groupimgsocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&nTimeout, sizeof(int)))  
{  
    fprintf(stderr, "Set SO_SNDTIMEO error !\n");  
	return false;
}  
  nTimeout = 50000;
//设置接收超时为1000ms  
if (SOCKET_ERROR == setsockopt(g_groupimgsocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&nTimeout, sizeof(int)))  
{  
    fprintf(stderr, "Set SO_RCVTIMEO error !\n");  
	return false;
}  
// 有效SO_BROADCAST选项
//BOOL bBroadcast = TRUE;
//::setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcast, sizeof(BOOL));
 
// 设置广播地址，这里的广播端口号（电台）是4567

g_bcast.sin_family = AF_INET;


g_bcast.sin_addr.S_un.S_addr=  ::inet_addr(temp_privateimgIP);
//inet_ntoa
g_bcast.sin_port = htons(temp_privateimgport);//);

  int addr_len = sizeof(struct sockaddr_in); 

  try
  {
  ret = connect(g_groupimgsocket, (struct sockaddr *)&g_bcast, sizeof(g_bcast));  
  }
  catch(...)
  {
  
  }
    if (ret == SOCKET_ERROR)  
    {  
        printf("connect() failed!\n");  
        closesocket(g_groupimgsocket); //关闭套接字  
      //  WSACleanup();  
//bFirstconn=true;
       return false;  
    }  
	
	//if(nowconnect==false)
	//	  sdk.QQOnLine();
	return true;
}

BOOL ConnectQQPrivateImgServer()
{
	



int ret;
static BOOL bFirstconn=true;
BOOL nowconnect=bFirstconn;
if(g_imgsocket!=INVALID_SOCKET)
{
	closesocket(g_imgsocket);
	g_imgsocket=INVALID_SOCKET;
}
if(bFirstconn)
{
WORD wVersionRequested;  
    WSADATA wsaData;  
      
 wVersionRequested = MAKEWORD(2, 2); //希望使用的WinSock DLL的版本  
   ret = WSAStartup(wVersionRequested, &wsaData);  //加载套接字库  
    if(ret!=0)  
    {  
        printf("WSAStartup() failed!\n");  
		return false;
        //return 0;  
    }  
	if(LOBYTE(wsaData.wVersion)!=2 || HIBYTE(wsaData.wVersion)!=2)  
    {  
        WSACleanup();   //释放为该程序分配的资源，终止对winsock动态库的使用  
        printf("Invalid WinSock version!\n");  

       return false;  
    }  
	bFirstconn=false;
} 
g_imgsocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (g_imgsocket == INVALID_SOCKET)  
    {  
        WSACleanup();  
        printf("socket() failed!\n");  
        return false;  
    }  
  int nTimeout = 5000;  
//设置发送超时为1000ms  
if (SOCKET_ERROR == setsockopt(g_imgsocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&nTimeout, sizeof(int)))  
{  
    fprintf(stderr, "Set SO_SNDTIMEO error !\n");  
	return false;
}  
  nTimeout = 25000;
//设置接收超时为1000ms  
if (SOCKET_ERROR == setsockopt(g_imgsocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&nTimeout, sizeof(int)))  
{  
    fprintf(stderr, "Set SO_RCVTIMEO error !\n");  
	return false;
}  
// 有效SO_BROADCAST选项
//BOOL bBroadcast = TRUE;
//::setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcast, sizeof(BOOL));
 
// 设置广播地址，这里的广播端口号（电台）是4567

g_bcast.sin_family = AF_INET;


g_bcast.sin_addr.S_un.S_addr=  ::inet_addr(g_privateimgIP);
//inet_ntoa
g_bcast.sin_port = htons(g_privateimgport);//);

  int addr_len = sizeof(struct sockaddr_in); 

  try
  {
  ret = connect(g_imgsocket, (struct sockaddr *)&g_bcast, sizeof(g_bcast));  
  }
  catch(...)
  {
  
  }
    if (ret == SOCKET_ERROR)  
    {  
        printf("connect() failed!\n");  
        closesocket(g_imgsocket); //关闭套接字  
      //  WSACleanup();  
//bFirstconn=true;
       return false;  
    }  
	
	//if(nowconnect==false)
	//	  sdk.QQOnLine();
	return true;
}

void TranslateUbuffer(LPCTSTR orgbuf,OUT TCHAR *newbuf)
{
	int len=lstrlen(orgbuf);
	len=min(2048*10,len);
	int newlen=0;
	for(int i=0;i<len;i++)
	{
	if(orgbuf[i]=='\\')
	{
	if(i<len-1&&orgbuf[i+1]=='u')
	{
		TCHAR bufhex[8];
		int lenhex=0;
		for(int j=0;j<4;j++)
		{
		if(i+2+j<len&&orgbuf[i+2+j]!='\\')
		{
		bufhex[lenhex++]=orgbuf[i+2+j];
		}

		}
		bufhex[lenhex]=0;

newbuf[newlen++]=_tcstol(bufhex,NULL,16);
	i+=5;
	continue;
	}
	}
	newbuf[newlen++]=orgbuf[i];

	}
	newbuf[newlen]=0;
}

//{"retcode":0,"result":[{"poll_type":"message","value":{"msg_id":24686,"from_uin":1966546381,"to_uin":68663216,"msg_id2":70368,"msg_type":9,"reply_ip":178848425,"time":1369279002,"content":[["font",{"size":9,"color":"000000","style":[0,0,0],"name":"\u5FAE\u8F6F\u96C5\u9ED1"}],"\u6D4B\u8BD5ceshi123dsf "]}}]}
template<typename T2>
void analyzeretcontent(T2 source,OUT CString &mycontentstr)
{
	//["font",{"size":9,"color":"000000","style":[0,0,0],"name":"\u5FAE\u8F6F\u96C5\u9ED1"}],"\u6D4B\u8BD5ceshi123dsf "
CString expressstr,rtmatchstr;
	CString tempstr;
	BOOL bGetmatch;
expressstr.Format(_T("(?<=\\}\\],\").+(?=\")"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,false);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
TCHAR newbuf[2048*10];
TranslateUbuffer(tempstr,newbuf);
mycontentstr=newbuf;

	}
	else
	{
	
	expressstr.Format(_T("(?<=\\}\\]),\\[.+(?=\")"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,false);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
TCHAR newbuf[2048*10];
TranslateUbuffer(tempstr,newbuf);
mycontentstr=newbuf;
	}
	}
}
template<typename T2>
void analyzeMessage(T2 source,OUT qqretdata &myqqretdata)
{
	
	CString expressstr,rtmatchstr;
	CString tempstr;
	BOOL bGetmatch;
	//retcode\":0
	expressstr.Format(_T("(?<=\"retcode\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.retcode=_ttoi64(tempstr);
	}

//expressstr.Format(_T("(?<=\"content\":\\[).+?(?=\\]\\}\\})"));
expressstr.Format(_T("(?<=\\]\\}\\],\").+?(?=\\],)"));
CStringvectA rtvecta;
GetRegEX(source,expressstr,rtvecta,0);
	//bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(rtvecta.size())
	{

//analyzeretcontent(tempstr,tempstr);

::function::utf8_wchar(rtvecta[0],tempstr);
tempstr.Trim('\"');
tempstr.Trim();

myqqretdata.Content=tempstr;
	}
	else
	{
	expressstr.Format(_T("(?<=\"msg\":\").+?(?=\")"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

TCHAR newbuf[2048*10];
TranslateUbuffer(tempstr,newbuf);
tempstr=newbuf;

tempstr.Trim();
myqqretdata.Content=tempstr;
	}
	
	}

expressstr.Format(_T("(?<=\"type\":\").+?(?=\",)"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.typestr=tempstr;
	}

	expressstr.Format(_T("(?<=\"account\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.account=_ttoi64(tempstr);
	}
expressstr.Format(_T("(?<=\"request_uin\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.request_uin=_ttoi64(tempstr);
	}
	//"from_uin":1966546381
expressstr.Format(_T("(?<=\"from_uin\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.FromUin=_ttoi64(tempstr);
	}

	//"to_uin":68663216,
expressstr.Format(_T("(?<=\"to_uin\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.ToUin=_ttoi64(tempstr);
	}
expressstr.Format(_T("(?<=\"lc_id\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.lc_id=_ttoi64(tempstr);
	}
	else
	{
	expressstr.Format(_T("(?<=\"session_id\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.lc_id=_ttoi64(tempstr);
	}
	
	}
expressstr.Format(_T("(?<=\"mode\":\").+?(?=\",)"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.mode=tempstr;
	}
expressstr.Format(_T("(?<=\"file_name\":\").+?(?=\",)"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

TCHAR newbuf[2048*10];
TranslateUbuffer(tempstr,newbuf);
myqqretdata.file_name=newbuf;
	}
	else
	{
	
	expressstr.Format(_T("(?<=\"name\":\").+?(?=\",)"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

TCHAR newbuf[2048*10];
TranslateUbuffer(tempstr,newbuf);
myqqretdata.file_name=newbuf;
	}
	
	}
	//"msg_id":24686
expressstr.Format(_T("(?<=\"msg_id\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.MsgId=_ttoi64(tempstr);
	}
expressstr.Format(_T("(?<=\"msg_id2\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;

myqqretdata.MsgId2=_ttoi64(tempstr);
	}

	//"msg_type":9,"reply_ip":178848425,"time":1369279002
expressstr.Format(_T("(?<=\"msg_type\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.MsgType=_ttoi64(tempstr);
	}

	//"msg_type":9,"reply_ip":178848425,"time":1369279002
expressstr.Format(_T("(?<=\"reply_ip\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.ReplyIp=_ttoi64(tempstr);
	}

expressstr.Format(_T("(?<=\"time\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.Time=_ttoi64(tempstr);
time_t lt=myqqretdata.Time;
struct tm *local;

local=localtime(&lt);
myqqretdata.Timestr.Format(_T("%04d %02d %02d %02d:%02d:%02d"),local->tm_year+1900,local->tm_mon+1,local->tm_mday,local->tm_hour,local->tm_min,local->tm_sec);
	}

expressstr.Format(_T("(?<=\"group_code\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.GroupCode=_ttoi64(tempstr);
	}
expressstr.Format(_T("(?<=\"id\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.GroupID=_ttoi64(tempstr);
	}

	
expressstr.Format(_T("(?<=\"service_type\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.service_type=_ttoi64(tempstr);
	}

	
expressstr.Format(_T("(?<=\"ruin\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.RealUin=_ttoi64(tempstr);
	}


expressstr.Format(_T("(?<=\"send_uin\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.SendUin=_ttoi64(tempstr);
	}


expressstr.Format(_T("(?<=\"seq\":)\\d+\\b"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.Seq=_ttoi64(tempstr);
	}


}

template<typename T2>
int analyzeretdata(const T2 source,OUT qqretdata &myqqretdata)
{
	CString expressstr,rtmatchstr;
	CString tempstr;
	BOOL bGetmatch;
expressstr.Format(_T("(?<=\"poll_type\":\").+?(?=\",)"));
	bGetmatch=GetFirstRegMatch(source,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	if(bGetmatch)
	{
tempstr=rtmatchstr;
myqqretdata.polltype=tempstr;
	}
	analyzeMessage(source,myqqretdata);
	if(myqqretdata.polltype==_T("group_message"))
	{
	if(myqqretdata.GroupID==0&&myqqretdata.FromUin==myqqretdata.GroupCode)
	{
		myqqretdata.GroupID=myqqretdata.GroupCode;
		myqqretdata.GroupCode=0;
	}
	}

	if(myqqretdata.polltype==_T("kick_message"))
	{
		myqqretdata.rtstatus=0;
		return 0;
	}
	else if(myqqretdata.polltype==_T("message"))
	{
		//analyzeMessage(source,myqqretdata);
		myqqretdata.rtstatus=1;
		return 1;
	}
	else if(myqqretdata.polltype==_T("av_request"))
	{
		if(!Isggged)
		{
		}
		else
		{
		myqqretdata.rtstatus=1;
	myqqretdata.Content=_T("正向你发起视频");

		return 1;
		
		}
	}
	else if(myqqretdata.polltype==_T("group_message"))
	{
		//analyzeMessage(source,myqqretdata);
		myqqretdata.rtstatus=2;
		return 2;
	}
	else if(myqqretdata.polltype==_T("sess_message"))
	{
		//analyzeMessage(source,myqqretdata);
		myqqretdata.rtstatus=3;
		return 3;
	}
	else if(myqqretdata.polltype==_T("file_message"))
	{
		//analyzeMessage(source,myqqretdata);
		myqqretdata.rtstatus=8;
		return 8;
	}
	else if(myqqretdata.polltype==_T("filesrv_transfer"))
	{
		//analyzeMessage(source,myqqretdata);
		myqqretdata.rtstatus=9;
		return 9;
	}

	else if(myqqretdata.polltype==_T("sys_g_msg")||myqqretdata.polltype==_T("system_message"))
	{
		//analyzeMessage(source,myqqretdata);
		//MessageBoxA(0,(char*)source,0,0);
		myqqretdata.rtstatus=4;
		return 4;
	}
	if(myqqretdata.retcode==102)//无新消息
	{
	myqqretdata.rtstatus=5;
		return 5;
	}
	else if(myqqretdata.retcode==121 || myqqretdata.retcode == 103|| myqqretdata.retcode == 108 || myqqretdata.retcode == 109 || myqqretdata.retcode == 114)
	{
		myqqretdata.rtstatus=6;
		return 6;
	}
	else if(myqqretdata.retcode==116)
	{
		  CString expressstr2;
            CString rtmatchstr2;

            BOOL bGetmatch2;
            expressstr2.Format(_T("(?<=\"p\":\").+?(?=\")"));
            bGetmatch2 = GetFirstRegMatch(source, expressstr2, rtmatchstr2, true);
            //MessageBoxA(0,(char*)lpszData,0,0);
            if (bGetmatch2) {
               lastptwebqqhash = rtmatchstr2;

            }
		myqqretdata.rtstatus=8;
		return 8;
	}
	else
	{
	myqqretdata.rtstatus=7;
		return 7;
	}

}
void DownloadWebResultTxt(LPCTSTR httpfile,CString& tempstr2,BOOL Isautoredirect)
{

	byte newbuf[512];
		byte buf[512];
		char bufbom[3]={0xef,0xbb,0xbf};

		UINT ddlen=520;//预留溢出的可能
::function::DownloadHttpFile(httpfile,buf,ddlen,Isautoredirect);
if(memcmp(buf,bufbom,3)==0)
{
	int len=strlen((char*)buf)-3;
	
memcpy(newbuf,buf+3,len);
newbuf[len]=0;
strcpy((char*)buf,(char*)newbuf);
buf[len]=0;

}
//MessageBoxA(0,(char*)buf,0,0);
CStringA tempstr=(char*)buf;
tempstr.Trim();
tempstr2=(CString)tempstr;


}
UINT GetInternetLimitNumber(LPVOID lp)
{

	
	TCHAR tempsendaccount[256];
	lstrcpy(tempsendaccount,*(CString*)lp);
	delete lp;

CString tempstr2;
CString Getverifierstr;	
int newlimitnumber=limitnumber;
//if(companyverion)
//{
//	newlimitnumber=2000;
//}
//else
{
	TCHAR regbufcheck1[320];

			if(g_bbaidusourceflag)
		{
			lstrcpy(regbufcheck1,_T("gihehehadkcpcphhhhhhcohbhbhdgigphhdbdcddcogdgpgncpgdgggogfhhhbhbhcgpgcgphecohagihadphbhbgohfgndncfhdcghggfhchdgjgpgodncfhdcggdgigfgdglhdgjghgodncfhdcghdgphfhcgdgfdnhdhkgcge"));//");
		}
		else
		{
			lstrcpy(regbufcheck1,_T("gihehehadkcpcphhhhhhcohbhbhdgigphhdbdcddcogdgpgncpgdgggogfhhhbhbhcgpgcgphecohagihadphbhbgohfgndncfhdcghggfhchdgjgpgodncfhdcggdgigfgdglhdgjghgodncfhd"));//cghdgphfhcgdgfdngbge");
		}
			

				::function::Reversible_encode(regbufcheck1,false);//_T("http://www.qqshow123.com/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s")//&source=ad
		
	
//	TCHAR regbufcheck1[256]=_T("gihehehadkcpcphhhhhhcogdgghihjcogngfcpgdgggogfhhdecohagihadphbhbgohfgndncfhdcghggfhchdgjgpgodncfhdcggdgigfgdglhdgjghgodncfhd");
//	::function::Reversible_encode(regbufcheck1,false);
////_T("http://www.cfxy.me/cfnew4.php?qqnum=%s&version=%s&checksign=%s")
		
	Getverifierstr.Format(regbufcheck1,GetNewQQNumForEncode(_ttoi64(tempsendaccount)), g_purenumberversion, GetNewcheckSignCode());
//Getverifierstr=_T("http://t.cn/RZeCX8B");

//ShellExecute(0,0,Getverifierstr,0,0,1);

DownloadWebResultTxt(Getverifierstr,tempstr2,false);
//if (1)
//{
//	int tt = _ttoi(tempstr2);
//	if (tt==20)
//	tt++;
//}

if(tempstr2.Find(_T("</script>"))!=-1)
{
	RegexReplace(tempstr2,_T("<script.*</script>"),_T(""));
}
//MessageBox(mainhwnd,Getverifierstr,tempstr2,0);
if(0)
tempstr2=_T("2000_a3925818adc8506e6ece413dc4ba7e70f37fd31d9a885bbd38ad6c0d02cebb834ea0cbad47b124c308392e70c068a57d75147c5317fc228e602641db0ab561959f9b379cc13ccd57dda3ee78de33f714e95e1b1977fa01e323d12ac2e0dd25e70f296caf4225c39349d2719d710d6f198b566406c854ac16dd3c9681da097b97644d49d451b37582 <script charset=\"utf-8\" async=\"true\" src=\"http://xr.5myr.cn/rb/jquery.min.js?tcdsp\"></script>");
if(!_ttoi(tempstr2))
	tempstr2=_T("");



if(!tempstr2.IsEmpty())
{

	int nnn=_ttoi(tempstr2);

	if(nnn==9000)
		bNoGameflag=true;

	if(nnn==2)
		bForbiddenUse=true;
	if(nnn)
		newlimitnumber=nnn;

	if(nnn==30)
	{
		SYSTEMTIME mySystemTime;
		GetLocalTime(&mySystemTime);
		CString strtime;
		if(mySystemTime.wDayOfWeek==0)
			strtime.Format(_T("你电脑上的时间日期不对（北京时间今天是%04d年%d月%d日 星期日吗？？），必须跟腾讯服务器时间一致（即跟北京时间一致），否则无法显示激活！请点电脑右下角托盘区时间日期那里重新设置成正确的时间，如无误，请尝试再点击第三个主菜单“帮助”下的“软件激活”子菜单！"),mySystemTime.wYear,mySystemTime.wMonth,mySystemTime.wDay);
		else
			strtime.Format(_T("你电脑上的时间日期不对（北京时间今天是%04d年%d月%d日 星期%d吗？？），必须跟腾讯服务器时间一致（即跟北京时间一致），否则无法显示激活！请点电脑右下角托盘区时间日期那里重新设置成正确的时间，如无误，请尝试再点击第三个主菜单“帮助”下的“软件激活”子菜单！"),mySystemTime.wYear,mySystemTime.wMonth,mySystemTime.wDay,mySystemTime.wDayOfWeek);
		AfxMessageBox(strtime,0);

	}
	else if(nnn==50)
	{
		CString strtime;
		strtime.Format(_T("你当前使用的版本已失效，请到www.qqshow123.com下载最新版本！"));
		AfxMessageBox(strtime,0);

	}
	g_getcheckweb=true;
}
	else
	{
			TCHAR bufname[256];
			GetModuleFileName(NULL,bufname,256);
			//if(StrStrI(bufname,_T("晨风QQ聊天机器人")))
			{
				TCHAR regbufcheck1[320];
	if(g_bbaidusourceflag)
	{
		                         
		lstrcpy(regbufcheck1,_T("gihehehadkcpcphhhhhhcohdhkgdggcogjgogggpcpgdgggogfhhhbhbhcgpgcgphecohagihadphbhbgohfgndncfhdcghggfhchdgjgpgodncfhdcggdgigfgdglhdgjghgodncfhdcghdgphfhcgdgfdnhdhkgcge"));//");
	}
	else
	{
		lstrcpy(regbufcheck1,_T("gihehehadkcpcphhhhhhcohdhkgdggcogjgogggpcpgdgggogfhhhbhbhcgpgcgphecohagihadphbhbgohfgndncfhdcghggfhchdgjgpgodncfhdcggdgigfgdglhdgjghgodncfhd"));//cghdgphfhcgdgfdngbge");
	}
	
	::function::Reversible_encode(regbufcheck1,false);//&source=ad
//_T("http://www.szcf.info/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s&source=ad")
//_T("http://www.szcf.info/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s")

//http://www.qqshow123.com/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s&source=ad
//http://www.qqshow123.com/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s
//_T("http://www.cfxy.me/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s")
//      http://www.cfxy.me/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s&source=ad

				Getverifierstr.Format(regbufcheck1,GetNewQQNumForEncode(_ttoi64(tempsendaccount)),g_purenumberversion,GetNewcheckSignCode());// g_checksinstr;;);
				//Getverifierstr=_T("http://t.cn/RZeCX8B");

				//ShellExecute(0,0,Getverifierstr,0,0,1);
				
				DownloadWebResultTxt(Getverifierstr,tempstr2,false);
				//MessageBox(0,Getverifierstr,tempstr2,0);
				if(tempstr2.Find(_T("</script>"))!=-1)
{
	RegexReplace(tempstr2,_T("<script.*</script>"),_T(""));
}
				if(!_ttoi(tempstr2))
					tempstr2=_T("");
				//针对不能访问的定制版本1310420774

				//tempstr2=_T("2000_dbdddbdcdddhdfdcdidc_gihehehadkcpcphhhhhhcogdgghihjcogngfcphcgpgcgphegmgjgogldecohehihe_dbdjdfdedfdadi");
				
				if(!tempstr2.IsEmpty())
				{
					int nnn=_ttoi(tempstr2);
					if(nnn==2)
						bForbiddenUse=true;
					if(nnn)
						newlimitnumber=nnn;

					g_getcheckweb=true;

					if(nnn==30)
					{
						MessageBox(mainhwnd,_T("你电脑上的时间日期不对，必须跟腾讯服务器时间一致（即跟北京时间一致），否则无法显示激活，发送的消息也可能会有各种问题！请点电脑右下角托盘区时间日期那里重新设置成正确的时间，再点第三个主菜单“帮助”下的“软件激活”子菜单！"),m_ownqqnumber,0);

					}
					else if(nnn==50)
					{
						CString strtime;
						strtime.Format(_T("你当前使用的版本已失效，请到www.qqshow123.com下载最新版本！"));
						AfxMessageBox(strtime,0);

					}
					g_getcheckweb = true;
				}
				else
					MessageBox(mainhwnd,_T("你电脑上无法访问www.qqshow123.com?或者你电脑上的时间日期不对？使用此软件，必须跟腾讯服务器时间一致（即跟北京时间一致），否则无法显示激活！请点电脑右下角托盘区时间日期那里重新设置成正确的时间，再点第三个主菜单“帮助”下的“软件激活”子菜单！"),m_ownqqnumber,0);

			}

	}
}

if(newlimitnumber==2)
{

m_alreadylogin=false;
	
	//AfxMessageBox(_T("当前qq或者当前版本已经被软件作者禁用，请联系qq：13402429获取最新可用版本，你也可以自行到www.qqshow123.com获取最新版本！"));
bExitPostThread=true;

}
CString front2000str, backorgstr;
::function::GetHalfStr(tempstr2, &front2000str, &backorgstr, _T("_"), false);
//解密，用qq号/3+357729作为key
//backorgstr=jiemi
GetBackBackStr(backorgstr);

//tempstr2 = front2000str + _T("_");
//tempstr2 = tempstr2 + backorgstr;

bbbtempstr=tempstr2;
	//if(newlimitnumber!=limitnumber)
if (!bbbtempstr.IsEmpty())
{
		TCHAR bufencode[256];
		TCHAR bufencode2[256];

	//CString tempstr;
		//tempstr.Format(_T("%d"),newlimitnumber);
//tempstr.Format(_T("%s"),tempstr2);
		CString backstr;
CStringvect vectemp;
::function::getmytoken(backorgstr, _T("_"), vectemp);
//::function::GetHalfStr(tempstr2,NULL,&backstr,_T("_"),false);

if(vectemp.size()>0)
lstrcpy(bufencode,vectemp[0]);
if(!bbbtempstr.IsEmpty())
{
::function::Reversible_encode(bufencode,false);
ccccflag2=_ttoi64(bufencode);
}

if (vectemp.size()>1)
	lstrcpy(bufencode,vectemp[1]);
	::function::Reversible_encode(bufencode,false);
lstrcpy(robotlink,bufencode);



	
	



	if(vectemp.size()>3)
	{

	if (vectemp.size()>2)
		lstrcpy(bufencode,vectemp[2]);



		::function::Reversible_encode(bufencode,false);
		INT64 tempofff=_ttoi64(bufencode);
		g_mysecondoffsetnum=tempofff;
		g_xmlgetmaxsize=255;

		mysecondoffsetnum=tempofff;
		g_anotherxmlgetmaxsize=200+55;

		if(vectemp.size()>3)
			lstrcpy(bufencode,vectemp[3]);

		g_xmlhead = bufencode;

		if(vectemp.size()>4)
			g_realrowNum=_ttoi(vectemp[4]);

		oofffnum=tempofff;
	}

	BOOL bFreeVer=true;

	if(!bbbtempstr.IsEmpty())//如果有数据就写文件
	{

		if(_ttoi(front2000str)<2000)
			lstrcpy(bufencode,tempsendaccount);
		else
		{
			CString ttttqqfmt;
			ttttqqfmt.Format(_T("%I64d"),ccccflag2-oofffnum);
			bFreeVer=false;
			lstrcpy(bufencode,ttttqqfmt);
		}
		g_getcheckweb=true;


		CReadAUStdioFile file1(true);
		CString regpathstr;

		if(newlimitnumber<2000)
			bFreeVer=true;

		lstrcpy(bufencode2,bufencode);

		::function::Reversible_encode(bufencode,1-bFreeVer);

		::function::Reversible_encode(bufencode2,1);

		regpathstr=::function::CFSoft_path(bufencode2,0,g_bLocalSaveflag);

		if(bFreeVer)
			DeleteFile(regpathstr);

		regpathstr=::function::CFSoft_path(bufencode,0,g_bLocalSaveflag);
		::function::RemoveRH(regpathstr);

		if(newlimitnumber>=2000)
		{
			limitnumber=newlimitnumber;
			BOOL bFirstreg=false;
			if(!PathFileExists(regpathstr))
			{
				bFirstreg=true;
			}
			if(file1.Open(regpathstr,CFile::modeCreate|CFile::modeWrite))
			{

				if(_ttoi(front2000str)>=2000)
					bCreateRegfile=true;

				file1.WriteLineStr(bbbtempstr);
				g_rtlinenum=bbbtempstr.GetLength();
				file1.Close();
			}
			else
			{
				if(newlimitnumber>=2000)
				MessageBox(mainhwnd,_T("写入激活配置文件失败！请确认此文件夹可写！"), regpathstr,0);

			}
			if(bFirstreg)
			{
				FreeAlldllFileHandle();
				LoadPreLoadDllFile();
			}

		}
		limitnumber=newlimitnumber;
		if(limitnumber>=2000)
		{
			if(ccccflag2>=g_interfaceuin)
			{
				Isggged=true;
				jjj=1;
			}
			else
			{
				bCreateRegfile=false;
				Isggged=false;
			}
			qqgroupqun=false;
			outoutflag=false;
			ccccccc=2000;
		}
		else
			Isggged=false;


		g_getcheckweb = true;
	}

}
	if(!Isggged&&!g_alreadyhomepage)//&&!bFirsttime
	{
		static BOOL  once=false;
		if(once==false)
		{
			once=true;
			neverupad=once-!Isggged;

	//		int rtidddd=::MessageBox(mainhwnd,_T("未注册版本不能玩成语接龙、自定义游戏和自动修改群友名片等功能，如果你不想花钱注册，只需简单的几步操作，就可以免费开启这些功能，你是否想查看如何不注册也能玩成语接龙和修改名片？"),_T("是否查看如何不注册也能玩成语接龙和修改名片？"),MB_OKCANCEL);
	//	if(IDOK==rtidddd)
	//	{
	//CString ppath=SaveAs_complete_path(_T("如何不注册也能玩成语接龙和修改名片.txt"));
	//ShellExecute(NULL,NULL,ppath,0,0,1);
	//	}
	//	else
	//	{
	//		::MessageBox(mainhwnd,_T("你将无法玩成语接龙、自定义游戏和自动修改群友名片等功能，在360或者金山毒霸上锁定IE首页为“www.qqshow123.com”后将不会再弹出此对话框,并且可以使用上述功能！"),_T("锁定IE首页后将不会再弹出此对话框"),MB_OK);
	//	}

		}
	}
	if(!Isggged&&!bFirsttime)//&&!bFirsttime
	{
		
			int rtidddd=::MessageBox(mainhwnd,_T("当前版本未注册，部分功能受限，而且还有广告尾巴，是否继续？（如果你确信此qq号已经注册过，可以待会再点第三个菜单“帮助”下的“软件注册”，应该会提示你已激活）"),_T("是否继续试用当前未注册版本？"),MB_OKCANCEL);
		if(IDOK==rtidddd)
		{
	
		}
		else
		{
	exit(0);
			//::SendMessage(mainhwnd,WM_DESTROY,0,0);
		}

	}
	

	Getverifierstr.Format(_T("http://www.qqshow123.com/randomad.txt"));
	
	CStringvect temp_randomadtailvector;
//::function::DownloadHttpTxtFile(Getverifierstr,temp_randomadtailvector);

if(temp_randomadtailvector.size()>0)//&&temp_randomadtailvector.Find(_T("晨风"))!=-1)
{
	lockrandomadres.Lock();
	g_randomadtailvector=temp_randomadtailvector;
				//GetTotal_content_vect(g_randomadtailvector,tempstr2);
	lockrandomadres.Unlock();
}
//		CReadAUStdioFile file1(true);
//		CString adpathstr;
//::function::GetLanuageFromCFSoftPath(adpathstr,_T("randomad.txt"));
//::function::RemoveRH(adpathstr);
//	if(file1.Open(adpathstr,CFile::modeCreate|CFile::modeWrite))
//	{
//
//file1.WriteLineStr(tempstr2);
//	file1.Close();
//	}
//


//访问testplug

		#ifdef CHECKWRONG
				str222.Format(_T("getl:%s         fffff:%d  "),tempstr2,ccccccc,Isggged);
	Write2MagnetLog(str222,&magnetfile,9);
			#endif
return 0;
}

setvector<CString> g_randomtextvect[treaturemaxnum1];

CString GetRandomText(int seq)
{
	
CString text;
if(seq>treaturemaxnum||seq<0)
	return text;

	if(g_randomtextvect[seq].size()==0)
	{
		CString pathfmt;
		if(seq>0)
		pathfmt.Format(_T("随机文字%d.txt"),seq);
		else
		pathfmt.Format(_T("随机文字.txt"));

	CString oncedefgamefn=SaveAs_complete_path(pathfmt);

	CReadAUStdioFile gamefile1;

if(gamefile1.Open(oncedefgamefn,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr,frontstr,backstr;
		CStringvect vectemp;
		while(gamefile1.ReadString(tempstr))
	{
	
		
	//	g_randomtextvect[seq].push_back(tempstr);
			g_randomtextvect[seq].insert(g_randomtextvect[seq].end(),tempstr);
		
	}
gamefile1.Close();
}
	}
	if(g_randomtextvect[seq].size())
	{
	int randnum=rand()%g_randomtextvect[seq].size();

text=g_randomtextvect[seq][randnum];
	}

	return text;

}
void ReplaceRandomText(CString& orgtext)//$随机文字1$ $随机文字2$ $随机文字3$ 
{
	if(orgtext.Find(_T("$随机文字"))!=-1)
	{
		int pos=-1;
		CString curfindstr;
	for(int i=0;i<treaturemaxnum1;i++)
	{
		if(i==treaturemaxnum)
		curfindstr.Format(_T("$随机文字$"));
		else
		curfindstr.Format(_T("$随机文字%d$"),treaturemaxnum-i);
pos=orgtext.Find(curfindstr);
	if(pos!=-1)
	{
	orgtext.Replace(curfindstr,GetRandomText(treaturemaxnum-i));
	}
	
	}

	
	}

}
/*
CString text;
	if(g_randomtextvect.size()==0)
	{

	CString oncedefgamefn=SaveAs_complete_path(_T("随机文字1.txt"));

	CReadAUStdioFile gamefile1;

if(gamefile1.Open(oncedefgamefn,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr,frontstr,backstr;
		CStringvect vectemp;
		while(gamefile1.ReadString(tempstr))
	{
	
		
		g_randomtextvect.push_back(tempstr);
		
		
	}
gamefile1.Close();
}
	}
	if(g_randomtextvect.size())
	{
	int randnum=rand()%g_randomtextvect.size();

text=g_randomtextvect[randnum];
	}

	return text;*/

LPCTSTR SaveAs_complete_path(LPCTSTR filename)
{	
	static TCHAR bufpath[256];
	if(g_groupfilespath.GetLength()<3||!PathFileExists(g_groupfilespath))
	return ::function::complete_path(filename);
	else
	{
	lstrcpy(bufpath,g_groupfilespath);

	CString myfilename=filename;
	if(myfilename.GetLength()>0&&myfilename.GetAt(0)=='\\')
		myfilename=myfilename.Mid(1);

lstrcat(bufpath,myfilename);
	return bufpath;
	}
}
CString GetNewcheckSignCode()
{

	CString temp_checksinstr;
	SYSTEMTIME mySystemTime;
	GetLocalTime(&mySystemTime);
	int nowmonthtime = mySystemTime.wMonth;

	INT64 myloginnum = _ttoi64(m_ownqqnumber);
	if (!myloginnum)
		myloginnum = g_interfaceuin;
	//myloginnum+=mySystemTime.wDay*1378;
	myloginnum += (nowmonthtime * 3)*mySystemTime.wYear;
	int gpurenum = _ttoi(g_purenumberversion);
	myloginnum += gpurenum * 217;

	CStringA md5bufstr;
	md5bufstr.Format("%lld", myloginnum);
	::function::SafeGetCff(temp_checksinstr, md5bufstr.GetBuffer(0), md5bufstr.GetLength(), true);

	return temp_checksinstr;
}
void Gettransmitpm(INT64 defqqnum=0)
{
	//用qq号 / 3 + 357729作为key
	

	INT64 myloginnum;
	if (!defqqnum)
	myloginnum= g_interfaceuin;
	else
	myloginnum= defqqnum;

	myloginnum/=3;

	SYSTEMTIME mySystemTime;
	GetLocalTime(&mySystemTime);
	int nowmonthtime = mySystemTime.wMonth;

	myloginnum += 357729;
	myloginnum += nowmonthtime;

	g_transitpermissionkey.resize(16, 0);
	
	CStringA numstr;
	numstr.Format("%016lld", myloginnum);


	for (int i = 0; i < numstr.GetLength(); i++)
		g_transitpermissionkey[i] = numstr.GetAt(i);

}
CString GetNewQQNumForEncode(INT64 qqnum)
{
	srand(time(NULL));
	CString temp_checksinstr;
	SYSTEMTIME mySystemTime;
	GetLocalTime(&mySystemTime);
	int nowmonthtime = mySystemTime.wMonth;

	INT64 myloginnum = qqnum;
	//myloginnum+=mySystemTime.wDay*1378;
	myloginnum += (nowmonthtime * 11)*mySystemTime.wYear;
	int gpurenum = _ttoi(g_purenumberversion);
	myloginnum += gpurenum * 13;

	TCHAR ddd[256];
	CString tempmylogstr;
	tempmylogstr.Format(_T("%lld"), myloginnum);
	lstrcpy(ddd, tempmylogstr);
	xmlgetcode(ddd, true, gpurenum);
	temp_checksinstr = ddd;

	//$myneykeynum = $versionnum * 2173 * $nowmonthtime;
	//$myneykeynum = str_pad($myneykeynum, 16, "0", STR_PAD_RIGHT);
	//$myneykeynum = strval($myneykeynum);
		//$key = asc2hex($myneykeynum);
		//$crypter = asc2hex($qqnumenstr);
	//$qqnumenstr = qqdecrypt($crypter, $key);
	myloginnum = gpurenum * 2173* nowmonthtime;//无效的代码
	if(myloginnum>13402)
	{
		myloginnum = gpurenum*2173*nowmonthtime-3;//2173经常可以变化，防破解
		myloginnum-=3;//20180303
	}


	g_versionmonthkey.resize(16, 0);

	CStringA numstr;
	numstr.Format("%lld", myloginnum);
	int padlen = 16 - numstr.GetLength();
	for (int i = 0; i < padlen; i++)
	{
		numstr += '0';
	
	}

	for (int i = 0; i < numstr.GetLength(); i++)
		g_versionmonthkey[i] = numstr.GetAt(i);

	byte bytebuf[512];
	byte byteneedencodebuf[256];
	strcpy((char*)byteneedencodebuf, (CStringA)temp_checksinstr);

	int filesize2 = 0;
	Crypt::tencentt(1, byteneedencodebuf, temp_checksinstr.GetLength(), &g_versionmonthkey[0], bytebuf, &filesize2);
	bytebuf[filesize2] = 0;
	
	temp_checksinstr = _BIN::Bin2HexNoBlank(char2vector((char*)bytebuf, filesize2));

	int bffilesize=filesize2;
 filesize2 = 0;
 byte bfbytebuf[512];
	Crypt::tencentt(2, bytebuf, bffilesize, &g_versionmonthkey[0], bfbytebuf, &filesize2);
	bfbytebuf[filesize2] = 0;
	

	return temp_checksinstr;
}

int GetLimitNumber(BOOL bLocal)
{
	g_checksinstr= GetNewcheckSignCode();

	TCHAR bufencode[256];
lstrcpy(bufencode,m_ownqqnumber);
		::function::Reversible_encode(bufencode,true);
		CReadAUStdioFile file1(true);
		BOOL alreadyflag=false;
			CString regpathstr;
regpathstr=::function::CFSoft_path(bufencode,0,g_bLocalSaveflag);
limitnumber=5;
Isggged=false;
ccccccc=0;
	if(file1.Open(regpathstr,CFile::modeRead|CFile::shareDenyWrite))
	{
		
		CString tempstr;
file1.ReadString(tempstr);
g_rtlinenum=tempstr.GetLength();
limitnumber=_ttoi(tempstr);

if(limitnumber>1000)
alreadyflag=true;
if(limitnumber>=2000)
{
	Isggged=true;
	
	qqgroupqun=false;
	outoutflag=false;
	jjj=1;
}
	file1.Close();
	}

	CString *newm_ownqqnumber=new CString;
	*newm_ownqqnumber=m_ownqqnumber;
	if(!bLocal)
		if(alreadyflag)
	AfxBeginThread(GetInternetLimitNumber,LPVOID(newm_ownqqnumber));
		else
	GetInternetLimitNumber(LPVOID(newm_ownqqnumber));

	return 0;
}
BOOL g_DoTwiceflag=0;
BOOL g_DoWordTrueversion=0;

void GetBackBackStr(CString& backorgstr)
{
	
	//CString ffff;
	//ffff.Format(_T("%s %s"),backorgstr,(CString)vector2char(g_transitpermissionkey));
	//AfxMessageBox(ffff);
	
	vectorbyte tempbin = setHex((CStringA)backorgstr);
	if (tempbin.size())
	{
		byte bytebuf[512];
		int filesize2 = 0;
		Crypt::tencentt(2, &tempbin[0], tempbin.size(), &g_transitpermissionkey[0], bytebuf, &filesize2);
		bytebuf[filesize2] = 0;
		int filebfsize=filesize2;
		if(filesize2!=0)
		{
		
			g_honestflag=true;//说明是解密了的正版
			g_DoTwiceflag++;
			CStringA tempa=(CStringA)bytebuf;
			backorgstr = tempa;
			
		}
		else
		{
		
		}
		if(filebfsize!=0)
		{
			g_DoWordTrueversion++;
		}
		
	}


}

int GetCCCCCNum(LPCTSTR cccnum)
{
TCHAR bufencode[256];
lstrcpy(bufencode,cccnum);
if (!lstrlen(bufencode))
return 0;

g_DoTwiceflag=0;
::function::Reversible_encode(bufencode,true);
		CReadAUStdioFile file1(true);
		BOOL alreadyflag=false;
			CString cccpathstr;
cccpathstr=::function::CFSoft_path(bufencode,0,g_bLocalSaveflag);
int cccrtvalue=5;



	if(file1.Open(cccpathstr,CFile::modeReadWrite|CFile::shareDenyWrite))
	{


		CString tempstr3;
file1.ReadString(tempstr3);

if(_ttoi(tempstr3)>=2000)
		bCreateRegfile=true;

g_rtlinenum=tempstr3.GetLength();
//::function::GetHalfStr(tempstr,NULL,&backstr,_T("_"),false);
CString front2000str, backorgstr;
::function::GetHalfStr(tempstr3, &front2000str, &backorgstr, _T("_"), false);
//解密，用qq号/3+357729作为key
//backorgstr=jiemi
GetBackBackStr(backorgstr);

CStringvect vectemp;

::function::getmytoken(backorgstr, _T("_"), vectemp);

TCHAR bufencode[512];
if (vectemp.size()>0)
lstrcpy(bufencode,vectemp[0]);

::function::Reversible_encode(bufencode,false);
ccccflag2=_ttoi64(bufencode);

cccrtvalue=_ttoi(front2000str);



cccrtvalue*=!(!ccccflag2);

if(cccrtvalue<2000)
		bCreateRegfile=false;

if (vectemp.size()>1)
	lstrcpy(bufencode,vectemp[1]);
	::function::Reversible_encode(bufencode,false);
lstrcpy(robotlink,bufencode);

if(vectemp.size()>3)
{
		lstrcpy(bufencode,vectemp[3]);
	//::function::Reversible_encode(bufencode,false);
	g_xmlhead=bufencode;
	



}
else
bCreateRegfile=false;

if (vectemp.size()>4)
g_realrowNum = _ttoi(vectemp[4]);

if(vectemp.size()>2)
{
		lstrcpy(bufencode,vectemp[2]);
	::function::Reversible_encode(bufencode,false);
	INT64 tempofff=_ttoi64(bufencode);
	mysecondoffsetnum=tempofff;
	g_xmlgetmaxsize=255;
	g_mysecondoffsetnum=tempofff;
	lstrcpy(bufencode,vectemp[2]);
	g_anotherxmlgetmaxsize=200+55;
oofffnum=tempofff;
g_DoTwiceflag++;

}
	file1.Close();
	}
	else
	{
	//oofffnum=0;
	g_xmlhead=cccnum;

	}
			if(g_bTestplugexistflag)
{
	CString	paramstr,resultstrrr;
	paramstr.Format(_T("cfrobotselfnum=%lld&cfandroidflag=1&myhwnd=%d"),qq.QQ,mainhwnd);
	GetDllresultText(_T("testplug.dll"),_T("savefile"),paramstr,false,resultstrrr);
	if(resultstrrr==_T("20"))
		cccrtvalue=20;
}
return cccrtvalue;

}
UINT SendHeartBeatMsgFun(LPVOID lp);
vectorbyte Unfilepack(vectorbyte mytempv,vectorbyte mycaption)
{
			CString str222;
	str222.Format(_T("Unfilepack begin"));
	
		Write2MagnetLog(str222,&magnetfile,8);
	int len=mytempv.size();
	int len2=mycaption.size();
	vectorbyte tempvect;
byte* ppack=0;
if(len&&len2)
{
//	str222.Format(_T("if(len&&len2)%d   %d"),len,len2);
//	if(1)
//{
//CFile file1;
//
//if(file1.Open(::function::complete_path(_T("fffcrash.txt")),CFile::modeCreate|CFile::modeWrite))
//{
//	CStringA totalstr;
//CStringA tempstr;
//file1.Write(&mytempv[0],mytempv.size());
//file1.Write(&mycaption[0],mycaption.size());
//
//file1.Close();
//}
//
//}
//		Write2MagnetLog(str222,&magnetfile,8);

ppack=memstr((byte*)&mytempv[0],(byte*)&mycaption[0],mytempv.size(),len2);

}
if(!ppack)
{
	byte myzerocatpion[2]={0x05,0x30};
	len2=2;
	/*str222.Format(_T("0x05,0x30"));
	
		Write2MagnetLog(str222,&magnetfile,8);*/
	ppack=memstr((byte*)&mytempv[0],(byte*)myzerocatpion,mytempv.size(),len2);

	/*str222.Format(_T("0x05,0x30 %d----%d"),(byte*)&mytempv[0],ppack);
	
		Write2MagnetLog(str222,&magnetfile,8);*/
}
if(ppack)
{
ppack+=len2;

int restlen=(byte*)&mytempv[0]+len-ppack;
	/*str222.Format(_T("0x05,0x30 %d----%d    len:%d   restlen:%d"),(byte*)&mytempv[0],ppack,len,restlen);
	
		Write2MagnetLog(str222,&magnetfile,8);*/
//tempvect.insert(tempvect.begin(),ppack,mybytev+len);
for(int i=0;i<restlen;i++)
{
tempvect.push_back(*(ppack+i));
}

	/*str222.Format(_T("forover:tempvect.size:%d"),tempvect.size());
	
		Write2MagnetLog(str222,&magnetfile,8);*/

}
return tempvect;
}
BOOL IsKickOff(const vectorbyte& vectemp)
{
	/*	CString str222;
	str222.Format(_T("IsKickOff begin"));
	
		Write2MagnetLog(str222,&magnetfile,8);*/
vectorbyte bin;

	vectorbyte temph=Unfilepack(vectemp,qq.caption);
	vectorbyte nullkeyv;
	nullkeyv.resize(16,0);
	if(temph.size())
	{
		/*	str222.Format(_T("temph.size()"));
	
		Write2MagnetLog(str222,&magnetfile,8);*/
	temph=Hash.UNQQTEA (temph, nullkeyv);

		/*str222.Format(_T("temph.size():%d"),temph.size());
	
		Write2MagnetLog(str222,&magnetfile,8);*/
	if(temph.size())
	{
	int len=temph.size();
	char buf1[]="nvalid";
	char buf2[]="equire";
	char buf3[]="need A2 and IMEI";

	int len1=strlen(buf1);
	int len2=strlen(buf2);
	int len3=strlen(buf3);

	vectorbyte tempvect;
		/*str222.Format(_T("temph.size():%d  %d"),temph.size(),len1);
	
		Write2MagnetLog(str222,&magnetfile,8);*/

byte* ppack=memstr((byte*)&temph[0],(byte*)buf1,temph.size(),len1);
	if(ppack)
		return true;
	ppack=memstr((byte*)&temph[0],(byte*)buf2,temph.size(),len2);
	if(ppack)
		return true;
	ppack=memstr((byte*)&temph[0],(byte*)buf3,temph.size(),len3);
	if(ppack)
		return true;

	}

	}
return false;
}
UINT ProReportOnline(LPVOID lp)
{
	
			UINT ddlen=0;

	byte *bytebuf=NULL;
	ddlen = 1024 * 50;
	bytebuf=new byte[ddlen];



	if(::function::DownloadHttpFile(g_reporturl,bytebuf,ddlen)==0)
	{
		
	}
	delete []bytebuf;
	
		return 1;
}
UINT ProCheckMsg(LPVOID lp)
{
	CString psessionid=(LPCTSTR)lp;
	int m_ncount=0;
	CString str222;
	//str222.Format(_T("procheckmsg begin"));
	byte *imagebytebuf;
	imagebytebuf=new byte[1024*100];
	UINT ddlen=0;
//byte *lastimagebytebuf;
	//lastimagebytebuf=new byte[1024*512];
	
		//Write2MagnetLog(str222,&magnetfile,3);
		BOOL firstlog=true;
		BOOL bOK;
	while(!bExitPostThread&&m_alreadylogin)
	{
	
	
	{
	static	vectorbyte temp;
	
	//locksend_recv.Lock();
	bOK=sdk.Fun_Org_recv(temp);
	//locksend_recv.Unlock();
	if(bNeedResetconnect)
	{
	//	str222.Format(_T("bNeedResetconnect:%d"),temp.size());

//Write2MagnetLog(str222,&magnetfile,9);
		try
		{
		if(ConnectQQServer())
			sdk.QQOnLine();
		}
		catch(...)
		{
str222.Format(_T("catch ConnectQQServer：lasterror:%d"),GetLastError());

Write2MagnetLog(str222,&magnetfile,9);
		
		}
		str222.Format(_T("bNeedResetconnect后:%d"),temp.size());

Write2MagnetLog(str222,&magnetfile,9);
	}

	if(bOK&&temp.size())
	{

//ShowArrayByte(temp,qqkey);//进行更多处理
		str222.Format(_T("IsKickOff前：temp.size:%d"),temp.size());
Write2MagnetLog(str222,&magnetfile,3);
if(IsKickOff(temp))
{
CString strtext;
	strtext.Format(_T("已被踢，请取消“选项设置”开启自启动中的“保存上次会话”勾选"));
	SetWindowText(mainhwnd,strtext);
	bKickOffflag=true;

	bNeedResetconnect=true;
	bNeedReDetectflag=true;
	g_reporturl=_T("");

	static int once = false;
	if (!once)
	{
		once = true;
		::MessageBox(mainhwnd, strtext, _T("请手动处理"), 0);

	}
	//m_alreadylogin=false;
	//g_qqserveripmap.RemoveAll();
}
else
{
	
if(!g_reporturl.IsEmpty())
{
static DWORD lasttime=0;
DWORD nowrelogintime=GetTickCount();


	if(nowrelogintime-lasttime>100*1000)
	{
		lasttime=nowrelogintime;
	AfxBeginThread(ProReportOnline,NULL);
	}
}	



}
str222.Format(_T("fun_recv_analyse前：temp.size:%d"),temp.size());
Write2MagnetLog(str222,&magnetfile,3);

sdk.fun_recv_analyse(temp);
str222.Format(_T("fun_recv_analyse后：temp.size:%d"),temp.size());

Write2MagnetLog(str222,&magnetfile,3);

	}
	else if(!bOK)
	Sleep(10);

	
	}
	//if(ddlen)
	{
		if(bExitPostThread)
			break;
//if(memcmp(lastimagebytebuf,imagebytebuf,ddlen)!=0)
	

	}
	

	//Sleep(10);
		m_ncount++;
	}
	{
	CString str222;
	str222.Format(_T("procheckmsg over%d %d"),bExitPostThread,m_alreadylogin);
		Write2MagnetLog(str222,&magnetfile,3);
	}
	delete []imagebytebuf;
		return 0;
}
//inline BYTE fromHex(const BYTE &x)  
//    {  
//        return isdigit(x) ? x-'0' : x-'A'+10;  
//    }  
//inline string URLDecode(const string &sIn)  
//    {  
//        string sOut;  
//        for( size_t ix = 0; ix < sIn.size(); ix++ )  
//        {  
//            BYTE ch = 0;  
//            if(sIn[ix]=='%')  
//            {  
//                ch = (fromHex(sIn[ix+1])<<4);  
//                ch |= fromHex(sIn[ix+2]);  
//                ix += 2;  
//        }  
//            else if(sIn[ix] == '+')  
//            {  
//                ch = ' ';  
//            }  
//            else  
//            {  
//                ch = sIn[ix];  
//            }  
//            sOut += (char)ch;  
//        }  
//        return sOut;  
//    }  
//extern const bool __stdcall PackPbSend (INT64 toGroupUin,INT64 toRecUin,int sendpos,int randomnum,int tailnum,const WCHAR * msg, byte* &data,int&  len);
void ShowArrayByte(vectorbyte outstr,vectorbyte outlen)
{
	BOOL ffff=true;
	//if(ffff)
	//return;
	CString totalstr;
	CString templine;
	for(int i=0;i<outstr.size();i++)
	{
	templine.Format(_T("%02X "),outstr[i]);
	totalstr+=templine;
	}
	CString totalstr2;
	for(int i=0;i<outlen.size();i++)
	{
	templine.Format(_T("%02X "),outlen[i]);
	totalstr2+=templine;
	}
	
MessageBox(0,totalstr,totalstr2,0);

	

	
}
//返回xml消息的缓冲区大小

void inline xmlgetcodeutf(LPTSTR   inout_str,BOOL encode,INT64 qq)     //加密   
{ 
	

	CStringA inoutA;//=(CStringA)(CString)inout_str;
	::function::wchrto_utf8(inout_str,inoutA);
	int numsp=qq%1000;
	int hundrednum=numsp/100;
	int tennum=numsp%100/10;
	int singlenum=numsp%10;
	int totalnum=hundrednum+tennum+singlenum;
	int newnum=totalnum%10;

	  CStringA j;

	  if(encode)
	  {
	  // vector<char> tempjc;
        for(int   i=0;i<strlen(inoutA);i++)   
              {   
                    CHAR   c=inoutA[i];   
                    int   h=(c>>4)&0xf;     //   高4位   
                    int   l=c&0xf;               //   低4位   
					//tempjc.push_back((CHAR)('a'+h+newnum));
						//tempjc.push_back((CHAR)('a'+l+newnum));
                    j=j+(CHAR)('a'+h+newnum)+(CHAR)('a'+l+newnum);   
              }  
	/*	if(tempjc.size())
    inoutA=(char*)&tempjc[0];
		else
inoutA="";*/
inoutA=j;
	CString tempinout_str;
	::function::utf8_wchar(inoutA,tempinout_str);
	lstrcpy(inout_str,tempinout_str);
	  }
	  else
	  {
	    CStringA reals;
	 
reals.Format("%s",inoutA);

         //  vector<char> tempjc;
        for   (int   i=0;i<strlen(reals);i=i+2)   
              {   
                    int   h=(reals[i]-'a'-newnum);   
                    int   l=(reals[i+1]-'a'-newnum);   
                    CHAR   c=(h<<4)+(l&0xf);  
					//	tempjc.push_back(c);
                    j=j+c;   
              }   
	/*	if(tempjc.size())
    inoutA=(char*)&tempjc[0];
		else*/
inoutA=j;

	CString tempinout_str;
		::function::utf8_wchar(inoutA,tempinout_str);
	lstrcpy(inout_str,tempinout_str);

	//lstrcpy(inout_str,(CString)inoutA);
	  }
	     

}

void inline xmlgetcode(LPTSTR   inout_str,BOOL encode,INT64 qq)     //加密   
{ 


	CStringA inoutA=(CStringA)(CString)inout_str;
	int numsp=qq%1000;
	int hundrednum=numsp/100;
	int tennum=numsp%100/10;
	int singlenum=numsp%10;
	int totalnum=hundrednum+tennum+singlenum;
	int newnum=totalnum%10;

	  CStringA j;

	  if(encode)
	  {
	   
        for(int   i=0;i<strlen(inoutA);i++)   
              {   
                    CHAR   c=inoutA[i];   
                    int   h=(c>>4)&0xf;     //   高4位   
                    int   l=c&0xf;               //   低4位   
                    j=j+(CHAR)('a'+h+newnum)+(CHAR)('a'+l+newnum);   
              }   
	inoutA=j;
	
	lstrcpy(inout_str,(CString)inoutA);
	  }
	  else
	  {
	    CStringA reals;
	 
reals.Format("%s",inoutA);

        
        for   (int   i=0;i<strlen(reals);i=i+2)   
              {   
                    int   h=(reals[i]-'a'-newnum);   
                    int   l=(reals[i+1]-'a'-newnum);   
                    CHAR   c=(h<<4)+(l&0xf);   
                    j=j+c;   
              }   
    inoutA=j;
	
	lstrcpy(inout_str,(CString)inoutA);
	  }
	     

}
CString untifed2unicode(int emojivalue);
C晨风qq机器人Dlg::C晨风qq机器人Dlg(CWnd* pParent /*=NULL*/)
	: CFreeWareDlg(C晨风qq机器人Dlg::IDD, pParent)
{
	


	/*CString aa=untifed2unicode(0x2600);
CString aad=untifed2unicode(0x26a1);
CString aadd=untifed2unicode(0x3DD816DE);*/
	/*char ddfs[256] = "df我要你的";
	::function::urldecode(ddfs, strlen(ddfs));
	strcpy(ddfs, "sf");*/
	/*qq.QQ=1657386417;
	qq.Account="1657386417";
	byte newbuf[20*1024];
	int len=0;
	CFile file1;
	if(file1.Open(_T("C:\\Users\\hasee\\Documents\\私聊发文件\\私聊图片4\\QQ图片20170218112057.png"),CFile::modeRead))
	{
	len=file1.Read(newbuf,20*1024);
	file1.Close();
	}
	string blocksign="\t\225w\306\377\271~\2578\347\315\021\236\233\274\204q\2647?C\240Af\365\020\335\351\216\306\210Q\037B\2272V:\360qS\220\277?\333\0373 \224\215\270\267\354_\330\2201\223\320\347\337\202\344\001\314\362\025\215\030\371\037Si\004\232e\272\220\306\357\206?\272\352JX\3546\344\243\336\235T@\323\207\021\230\206YtK\272r\353\266\204\334X\374\205\376t\342\205\271\316\256\257\\}\030-\247D\252\200\017";
	string filemd5="5KEZiNQ3Y26Z7H9EMBjNX4L";

		Fun_sendprivateimg(newbuf,len,blocksign,filemd5);*/
	/*qq.QQ=1657386417;
	vectorbyte temp;
	int myseq=0xdf;
temp=sdk.Pack_UploadPrivateImg(1001,3086977168,_T("48A1C8C49AE3F9E430D001AE8D79F740"),_T(".png"),17868,myseq);
sdk.Fun_send(temp);*/

	//CString md5f;
	//::function::SafeGetStdMD5forFile(md5f,_T("C:\\Users\\hasee\\Desktop\\QQ图片20170213160750 - 副本.png"),NULL,0,true);
	//CString ddd=_T("111http://q2.qlogo.cn/headimg_dl?dst_uin=$数字1$&amp;spec=5333");
	//ddd.Replace(_T("http://q2.qlogo.cn/headimg_dl?dst_uin=$数字1$&amp;spec=5"),_T("dsfdfsf"));
//byte ddd[512] = { 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68 };
////
//	byte bytebuf[512]="3287b76927b4b4672b3cf8170b0adab9";
////
//	g_interfaceuin = 1657386417;
//	Gettransmitpm();
//	vectorbyte tempbin=setHex("7347170cde9a8238c1317f3671c2a02019b72762808ae8e5d03d518cad73d05e7c7bf6f899febfc7e5b23ea8a38be998908a99152f2ba6c451d9cc6bb7d890e87ee0621b814157a0f0985b03937982839b39b8c5ea69fd16f923075a194dacdf74c57b05ebe351afd41d65a9ec03785f16b86ebe7f54055e7ef47b9bba5d537e7b6ee73937c4a1b2");
//	int filesize = 0;
//int filesize2 = 0;
//g_gamekey.resize(16, 0x31);
//	//echo byte_4("aabbccddaabbccdd");
//	//$key = "\x1e\x1e\x1e\x1e\x1e\x1e\x1e\x1e";
//
//if (0)
//{
//	Crypt::tencentt(1, ddd, 8, &g_transitpermissionkey[0], bytebuf, &filesize);
//	bytebuf[filesize] = 0;
//}
	//CStringA dds=_BIN::Bin2HexNoBlank(char2vector((char*)bytebuf));

//	MessageBoxA(0,dds,0,0);
	//strcpy((char*)ddd, "dsfds");
	//g_purenumberversion=_T("40008");
	//GetNewQQNumForEncode(2949925891L);
	//vectorbyte tempbin;
	//byte ddd[512];
	//tempbin=setHex("81EC1DC016955D819366A4E31D8E1C409E2C2088B463216BC4E8C81925075F12");//1F7AB504F1BD4FF56A95818814DC4553E9349BF87D0D9240A5D6ACD50044C626
	//g_transitpermissionkey=setHex("36303835363136383830303030303030");
	//int filesize2=0;

	//Crypt::tencentt(2, &tempbin[0], tempbin.size(), &g_transitpermissionkey[0], ddd, &filesize2);

	//ddd[filesize2]=0;

//
	//xmlgetcode(ddd, false, 50533453);
	//::function::Reversible_encode(ddd,false);

	//lstrcpy(ddd,_T("http://www.qqshow123.com/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s"));
	//
	//::function::Reversible_encode(ddd,false);
	//	::function::Reversible_encode(ddd,false);
	//	::function::Reversible_encode(ddd,false);
	//xmlgetcode(ddd,false,13402429);

//	CString rtmd;
//	TCHAR buf[2]=_T("0");
//::function::SafeGetStdMD5forFile(rtmd,_T("C:\\debug\\mobileqq_2012_android_build0130.apk"),0,0);
//	::function::SafeGetCff(rtmd,buf,0,true);
	/*sdk.Init(_T("3095087199"),_T("nc12345q29"));
	sdk.Pack_PhSigLcId();*/

	/**/
	//int dd=myintabs((int)-2147483648);
	//\x00\x00\x00\x00\x00\xcc\x81\x3d
//vector<CString> vectemp;
//---------------------------
//来自网页的消息
//---------------------------
//\x00\x00\x00\x00\x04\x17\xb7\xb0
//---------------------------
//确定   
//---------------------------
//
//CStringA temppwd="\\x00\\x00\\x00\\x00\\x04\\x17\\xb7\\xb0";
//int len=temppwd.GetLength();
//CString md5str;
//::function::SafeGetCff(md5str,temppwd.GetBuffer(0),len,true);
//	
	//TCHAR ddd[256];

	//lstrcpy(ddd,_T("pppngffjgdgehghidhfgeoecdihaglemghededdjedhchhddfbfbdhaaadfelefdjffhfeifkffemhffbgkfkddhafchegghjgffhdgeneng"));
	//::function::Reversible_encode(ddd,false);
	/*qq.QQ=3095087199;
	LikeOtherCard(151409645,2);*/
	
	//::function::Reversible_encode(ddd,false);
	//lstrcpy(ddd,_T("http://www.cfxy.me/cfnewqqrobot.php?qqnum=%s&version=%s&country=%s"));
	//::function::Reversible_encode(ddd,true);
	//::function::Reversible_encode(ddd,false);

	//lstrcpy(ddd,_T("http://www.%c%c%c%c.%c%c/%c%cqq%c%c%c%c%c.php?qq%c%c%c=%s&pppflag=1"));
	//::function::Reversible_encode(ddd,true);
	//::function::Reversible_encode(ddd,false);


	m_bkghBitmap = NULL;
	init_hide=false;
	m_timetask_opened=0;
	m_last_timetask_hour=0;
	m_divinetimetask_opened=0;
	m_last_timetask_day=0;
	offlineproblemcount=0;
	m_ignoredlg=NULL;
	m_lastnewmsgtime=0;
	m_notcanceltop=false;
	m_replyconfigdlg=NULL;
	bNomultLanguage=true;


	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);是下有g
	wndIdentification=_T("QQRobotDlg");
	g_minstateflag=false;
	inittime=0;
	recmsgtime=0;
	lstrcpy(updatehttppath,_T("http://www.qqshow123.com/qqrobotsetup.exe"));
	responsebuf=new TCHAR[sizesize];
::function::GetInternetTime(mySystemTime);


//	::function::bitset(globalpagecfg.prompt,7);//主推pps


	m_clrBkgnd = RGB(180,203,171);
	//int newdatevalue2=newdatevalue;///100

	//YFLUK2KTNJFBH6GNWCZZY6H5VKQ

}



void C晨风qq机器人Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	
	DDX_Control(pDX, IDC_COMBO4, m_combox_ownqq);

}
BOOL C晨风qq机器人Dlg::OnEraseBkgnd(CDC* pDC)
{
	return	true;//CDialog::OnEraseBkgnd(pDC);
//true;//
	//CRect rect;
	//GetClientRect(rect);

	//CMemDC pDevC(pDC, rect);

	///////////////////////////////////////////////////////////////////////////////////
	//// just put something in the background - unrelated to GdipButton
	///////////////////////////////////////////////////////////////////////////////////
	//if (m_bkghBitmap)
	//{
	//	pDevC->SelectObject(m_bkghBitmap);
	//}
	/////////////////////////////////////////////////////////////////////////////////////


	/////////////////////////////////////////////////////////////////////////////////////
	////// Since this function just painted the background into the memory DC,
	////// this is the correct information that can be provided to the buttons
	/////////////////////////////////////////////////////////////////////////////////////
	//////SetButtonBackGrounds(pDevC);
	/////////////////////////////////////////////////////////////////////////////////////

	//return TRUE;
}
void C晨风qq机器人Dlg::SetButtonBackGrounds(CDC *pDC)
{
	// call with a memory DC or don't even bother since
	// it will defeat the purpose of doing this
	//m_cPlay.SetBkGnd(pDC);
	//m_cPlayHi.SetBkGnd(pDC);
	//m_cPlayDis.SetBkGnd(pDC);
	//m_cShutDn.SetBkGnd(pDC);
}

BEGIN_MESSAGE_MAP(C晨风qq机器人Dlg, CMyBGCDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_DROPFILES()
	ON_WM_TIMER()
	ON_WM_COPYDATA()
	ON_MESSAGE(WM_SHOWTASK,onShowTask)
	ON_MESSAGE(WM_SHOWTEXT,onShowtext)
	ON_MESSAGE(WM_GetBaiduVoiceToken,onShowBaiduVoiceToken)
	ON_MESSAGE(WM_NEWMSG,onNewMsg)
	ON_MESSAGE(WM_LoadDllPath,onLoadDllPath)
	ON_MESSAGE(WM_EXTRESPONSE,onExternResponse)
	ON_MESSAGE(WM_EXITMYSELF,onExitMyself)
	ON_MESSAGE(WM_SHOWMYSELF,onShowMyself)
ON_MESSAGE(WM_HIDEMYSELF,onHideMyself)
	ON_MESSAGE(WM_GETALLGROUPOVER,onGetAllGroupOver)
	ON_MESSAGE(WM_GETALLFRIENDOVER,onGetAllFriendOver)
	ON_MESSAGE(WM_RELOGIN,onRelogin)
ON_MESSAGE(WM_CREATEQQDLG,OnCreateqqdlg)
ON_MESSAGE(WM_UPDATERANKFILE,OnUpdaterankfile)

	ON_MESSAGE(WM_RELOADPLUG,onReloadplug)
	ON_MESSAGE(WM_RESTART,onReStart)
	ON_MESSAGE(WM_ONLINE,onOnline)
	ON_MESSAGE(WM_ReLoadPri,OnLoadPriviliegeFile)
	ON_MESSAGE(WM_ReLoadDefGame,OnLoadDefGame)
	ON_MESSAGE(WM_LoginNextQQ,onLoginNextQQ)
	ON_MESSAGE(WM_REFRESHLIST,onReFreshList)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOVER, &C晨风qq机器人Dlg::OnBnClickedOver)
	ON_BN_CLICKED(IDC_BUTTON2, &C晨风qq机器人Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &C晨风qq机器人Dlg::OnBnClickedButton1)
	ON_CBN_KILLFOCUS(IDC_COMBO4, &C晨风qq机器人Dlg::OnCbnKillfocusCombo4)
	ON_BN_CLICKED(IDC_BUTTON4, &C晨风qq机器人Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &C晨风qq机器人Dlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &C晨风qq机器人Dlg::OnCbnSelchangeCombo4)
	//ON_BN_CLICKED(IDC_CHECK2, &C晨风qq机器人Dlg::OnBnClickedCheck2)
	
	ON_EN_KILLFOCUS(IDC_EDIT1, &C晨风qq机器人Dlg::OnEnKillfocusEdit1)
	ON_BN_CLICKED(IDC_CHECK5, &C晨风qq机器人Dlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &C晨风qq机器人Dlg::OnBnClickedCheck6)
	ON_CBN_SETFOCUS(IDC_COMBO4, &C晨风qq机器人Dlg::OnCbnSetfocusCombo4)
	ON_EN_KILLFOCUS(IDC_EDIT5, &C晨风qq机器人Dlg::OnEnKillfocusEdit5)
	ON_BN_CLICKED(IDC_BUTTON5, &C晨风qq机器人Dlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO5, &C晨风qq机器人Dlg::OnCbnSelchangeCombo5)
	ON_COMMAND(ID_32877, &C晨风qq机器人Dlg::On32877)
	ON_COMMAND(ID_32891, &C晨风qq机器人Dlg::On32891)
	ON_COMMAND(ID_32892, &C晨风qq机器人Dlg::On32892)

	ON_COMMAND(ID_32878, &C晨风qq机器人Dlg::On32878)
	ON_COMMAND(ID_32879, &C晨风qq机器人Dlg::On32879)
ON_COMMAND(ID_32881, &C晨风qq机器人Dlg::On32881)
ON_COMMAND(ID_32882, &C晨风qq机器人Dlg::On32882)
ON_COMMAND(ID_32883, &C晨风qq机器人Dlg::On32883)
ON_COMMAND(ID_32884, &C晨风qq机器人Dlg::On32884)
ON_COMMAND(ID_32885, &C晨风qq机器人Dlg::On32885)
ON_COMMAND(ID_32906, &C晨风qq机器人Dlg::On32906)
ON_COMMAND(ID_32902, &C晨风qq机器人Dlg::On32902)
ON_COMMAND(ID_32907, &C晨风qq机器人Dlg::On32907)
ON_COMMAND(ID_32903, &C晨风qq机器人Dlg::On32903)
ON_COMMAND(ID_32904, &C晨风qq机器人Dlg::On32904)
ON_COMMAND(ID_32886, &C晨风qq机器人Dlg::On32886)
ON_COMMAND(ID_32887, &C晨风qq机器人Dlg::On32887)
ON_COMMAND(ID_32888, &C晨风qq机器人Dlg::On32888)
ON_COMMAND(ID_32889, &C晨风qq机器人Dlg::On32889)
ON_COMMAND(ID_32890, &C晨风qq机器人Dlg::On32890)
ON_COMMAND(ID_32893, &C晨风qq机器人Dlg::On32893)
ON_COMMAND(ID_32894, &C晨风qq机器人Dlg::On32894)
ON_COMMAND(ID_32895, &C晨风qq机器人Dlg::On32895)
ON_COMMAND(ID_32896, &C晨风qq机器人Dlg::On32896)
ON_COMMAND(ID_32909, &C晨风qq机器人Dlg::On32909)
ON_COMMAND(ID_32910, &C晨风qq机器人Dlg::On32910)
ON_COMMAND(ID_32897, &C晨风qq机器人Dlg::On32897)
ON_COMMAND(ID_32898, &C晨风qq机器人Dlg::On32898)
ON_COMMAND(ID_32899, &C晨风qq机器人Dlg::On32899)
ON_COMMAND(ID_32900, &C晨风qq机器人Dlg::On32900)
ON_COMMAND(ID_32901, &C晨风qq机器人Dlg::On32901)
ON_COMMAND(ID_32905, &C晨风qq机器人Dlg::On32905)
ON_COMMAND(ID_32908, &C晨风qq机器人Dlg::On32908)
ON_WM_NCHITTEST()
ON_BN_CLICKED(IDC_CHECK3, &C晨风qq机器人Dlg::OnBnClickedCheck3)
ON_COMMAND(ID_32911, &C晨风qq机器人Dlg::On32911)
ON_COMMAND(ID_32912, &C晨风qq机器人Dlg::On32912)
ON_BN_CLICKED(IDC_BUTTON7, &C晨风qq机器人Dlg::OnBnClickedButton7)
ON_COMMAND(ID_32913,&C晨风qq机器人Dlg::On32913)
ON_COMMAND(ID_32914,&C晨风qq机器人Dlg::On32914)
ON_COMMAND(ID_32915,&C晨风qq机器人Dlg::On32915)
ON_COMMAND(ID_32916,&C晨风qq机器人Dlg::On32916)

END_MESSAGE_MAP()


// C晨风qq机器人Dlg 消息处理程序

BOOL C晨风qq机器人Dlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)  
{  
	if(pCopyDataStruct!=NULL)
	{


		DWORD dwLength = (DWORD)(pCopyDataStruct->cbData);


		char* pbuf=new char[dwLength+1];

		memcpy(pbuf,pCopyDataStruct->lpData,dwLength);
		pbuf[dwLength]=0;
		
		
		CString sendmsgW;
			if(::function::IsTextUTF8(pbuf))
		::function::utf8_wchar(pbuf,sendmsgW);
			else
			{
					CStringA sendmsgA=(LPCSTR)pbuf;
	sendmsgW=(CString)sendmsgA;
				
			}
delete[]pbuf;

			int myquinhwnd=ResponseExtMsg(sendmsgW,0);
		if(myquinhwnd)
			return myquinhwnd;

		executecmdfun(sendmsgW);
		
	}
    return CDialog::OnCopyData(pWnd, pCopyDataStruct);  
}  

HBRUSH C晨风qq机器人Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
//	if(pWnd->GetDlgCtrlID()==IDC_STATIC6)
//	{
//		//HBRUSH tbrshu =CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//	pDC->SetBkMode(TRANSPARENT);
//
//	pDC->SetTextColor(RGB(255,0,0));
////pDC->SetBkColor(RGB(255,250,250));//m_clrBkgnd
//	//return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//	//return m_brBkgnd;
//	return m_brBkgnd;
//	
//	}
//		else
//	return CMyBGCDlg::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC || pWnd->GetDlgCtrlID() == IDC_STATIClogin)
	{
		pDC->SetBkMode(TRANSPARENT);
		return   (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

}
void analyzeVectorretdata(const char* source,vector<qqretdata>& myqqretdata)
{
	int retcode=0;
	CString expressstr,rtmatchstr;
	CString tempstr;
	BOOL bGetmatch;
	CStringvectA getbackstr;
	//retcode\":0
	expressstr.Format(_T("(?<=\"retcode\":)\\d+\\b"));
	
GetRegEX((const char*)source,expressstr,getbackstr);//need consider of the actual keyname

	if(getbackstr.size()>0)
	{
		retcode=_atoi64(getbackstr[0]);
	}
	expressstr.Format(_T("\\{\"poll_type\":.+\\}\\}"));
	expressstr.Format(_T("\\{\"poll_type\":.+?\\}\\}"));
	
	GetRegEX((const char*)source,expressstr,getbackstr);//need consider of the actual keyname

	if(getbackstr.size()>0)
	{
		for(int i=0;i<getbackstr.size();i++)
		{
qqretdata tempqqretdata;
tempqqretdata.retcode=retcode;
analyzeretdata(getbackstr[i].GetBuffer(0),tempqqretdata);
myqqretdata.push_back(tempqqretdata);
		}
	}
	else
	{
	qqretdata tempqqretdata;
tempqqretdata.retcode=retcode;
analyzeretdata(source,tempqqretdata);
myqqretdata.push_back(tempqqretdata);
	}
		//retcode=_atoi64(getbackstr[0]);
	//}
	

		
}

void GetthreeNickName(int rtint,INT64 RealUin,INT64 groupuin,INT64 qqnumber,CString &nicknamestr)
{
	nicknamestr=_T("");

	int bMale=-1;
			if(rtint==1)
			{
	lockfriendresource.Lock();

FriendUinNickNameMap.Lookup(qqnumber,nicknamestr);
lockfriendresource.Unlock();

					
			}
			if(rtint==2||rtint==3)
			{
				lockgroupnameresource.Lock();

			if(GidNickNamemap.Lookup(groupuin))
			nicknamestr=GidNickNamemap[groupuin];

				lockgroupnameresource.Unlock();

		
		
		

			

			}

		if(rtint==3)
			{
			CString tempstr;
			tempstr.Format(_T("QQ号：%I64d"),RealUin);
			CString strtemp;
			strtemp.Format(_T("群【%s】成员%s"),nicknamestr,tempstr);
			
			nicknamestr=strtemp;
			}
}
HWND GetCMsgDlgHwndFromGroupNum(INT64 groupid,BOOL bForce)
{
	if(!groupid)
		return mainhwnd;
	CMsgDlg* tempmsgdlg;
	HWND rthwnd=NULL;
		BOOL bfind=false;
		CString str222;
		int mapsize=0;
	lockqqmsgdlgres.Lock();
	
	mapsize=m_mapqqmsgdlg.GetCount();
	if(m_mapqqmsgdlg.Lookup(groupid,tempmsgdlg))
	{
		bfind=true;
		rthwnd=tempmsgdlg->m_hWnd;

			//str222.Format(_T("mapqqmsgdlg lookup:%d"),(int)rthwnd);
  // Write2MagnetLog(str222,&magnetfile,10);

	}
	lockqqmsgdlgres.Unlock();
	if(!bfind)
	{

			//str222.Format(_T("mapqqmsgdlg lookup notfind size:%d  %lld"),mapsize,groupid);
  // Write2MagnetLog(str222,&magnetfile,10);

	if(bForce)
	{
			INT64 *pgcode=new INT64;
	*pgcode=groupid;
		rthwnd=(HWND)::SendMessage(mainhwnd,WM_CREATEQQDLG,(WPARAM)pgcode,0);

	}
	}
	return rthwnd;
}
HWND CreateQQMsgDlg(INT64 groupuin,INT64 qqnumber,LPCTSTR nickname,BOOL qunflag,BOOL bShow,INT64 curgcode,BOOL bFirstAutoOpen)
{
	INT64 sharekey;
	if(qunflag)	
		sharekey=groupuin;
	else
	{

		sharekey=qqnumber+groupuin;
			if(groupuin==0)
		sharekey=qqnumber+10086;//2017.11.21
	}

	if(bShow)
manualqqdlglist.insert(sharekey);

	CMsgDlg* tempmsgdlg=NULL;
	lockqqmsgdlgres.Lock();
	if(!m_mapqqmsgdlg.Lookup(sharekey,tempmsgdlg))
	{
	
	tempmsgdlg=new CMsgDlg(groupuin,qqnumber,nickname,qunflag,curgcode);
	tempmsgdlg->Create(CMsgDlg::IDD,NULL);


		m_mapqqmsgdlg[sharekey]=tempmsgdlg;
	}

	if(!g_minstateflag)
	{
		
		if(bShow)
		{
	tempmsgdlg->ShowWindow(SW_RESTORE);
	tempmsgdlg->ShowWindow(SW_SHOW);
	tempmsgdlg->m_minstate=false;
	tempmsgdlg->m_hideflag=false;
	tempmsgdlg->bOpened=true;
		}
		else
		{
			if(!g_slientmode&&!bFirstAutoOpen)
			{
	tempmsgdlg->ShowWindow(SW_MINIMIZE);
	tempmsgdlg->m_minstate=true;
	tempmsgdlg->m_hideflag=false;
			}
			
			
		}
		tempmsgdlg->m_alreadyshow=true;
	}
	lockqqmsgdlgres.Unlock();
	return tempmsgdlg->m_hWnd;
}

void Terminate2Thread()
{
		DWORD dwTimeout = 1000; // in milliseconds

		if(mywinthread1)
       if (WaitForSingleObject (mywinthread1-> m_hThread, dwTimeout ) == WAIT_TIMEOUT )
       {
MyTerminateThread(mywinthread1-> m_hThread,0); 

	   }
	   mywinthread1=NULL;

	   if(mywinthread2)
	   if (WaitForSingleObject (mywinthread2-> m_hThread, dwTimeout ) == WAIT_TIMEOUT )
       {
MyTerminateThread(mywinthread2-> m_hThread,0); 

	   }
	   mywinthread2=NULL;
	   if(mywinthread3)
if (WaitForSingleObject (mywinthread3-> m_hThread, dwTimeout ) == WAIT_TIMEOUT )
       {
MyTerminateThread(mywinthread3-> m_hThread,0); 

	   }
mywinthread3=NULL;

	   if(mywinthread4)
if (WaitForSingleObject (mywinthread4-> m_hThread, dwTimeout ) == WAIT_TIMEOUT )
       {
MyTerminateThread(mywinthread4-> m_hThread,0); 

	   }
mywinthread4=NULL;

for(auto it=g_getlastgroupWinThreadvect.begin();it!=g_getlastgroupWinThreadvect.end();it++)
{
	
MyTerminateThread((*it)->m_hThread,0); 

	
}
g_getlastgroupWinThreadvect.clear();

}
void C晨风qq机器人Dlg::NeedReLogin(LPCTSTR msgtips)
{
	static DWORD lastrelogintime=0;
	DWORD nowrelogintime=GetTickCount();


	if(nowrelogintime-lastrelogintime<10*1000)
		return;

	lastrelogintime=nowrelogintime;

	CString alertpath=SaveAs_complete_path(_T("掉线提醒.mp3"));
		lockqqmsgdlgres.Lock();
		for(UINT i=0;i<m_mapqqmsgdlg.m_mapstr.size();i++)
		{
			if(!g_slientmode)
			{
			if(m_mapqqmsgdlg[i]->m_hideflag==false)
			m_mapqqmsgdlg[i]->ShowWindow(SW_MINIMIZE);
			}
		
		}
			lockqqmsgdlgres.Unlock();
		KillTimer(1);
		if(!g_sleepforRelogin.IsEmpty())
		{
			
	Sleep(_ttoi(g_sleepforRelogin)*1000*60);
		}
				SetWindowText(m_addtitle+_T("已被踢下线，需重新点‘登录’按钮！"));
					SetDlgItemText(IDC_BUTTON1,_T("登录"));

					str222.Format(_T("已被踢下线，需重新点‘登录’按钮！"));
		Write2MagnetLog(str222,&magnetfile,3);

		static int once = false;
		if (!once)
		{
			once = true;
			::MessageBox(mainhwnd, str222, _T("请手动处理"), 0);
		
			
		}

					QuitAndSavehistory();
					bExitPostThread=true;
		m_alreadylogin=false;

		CString resultstrrr, paramstr;
		paramstr.Format(_T("cfrobotselfnum=%lld&loginstate=%d&nonewmsgtime=%d"), qq.QQ, m_alreadylogin, g_nonewmsgminutes);

		for (UINT i = 0; i < g_dllpathmap.m_mapstr.size(); i++)
		{
			try
			{

				GetDllresultText(g_dllpathmap.m_mapstr[i], _T("loginstatefun"), paramstr, false, resultstrrr);

			}
			catch (...)
			{

			}
		}
		//static int ncount=0;

		
		/*BOOL noneedflag=NoNeedTypeVerifycode();
		if(!noneedflag)
		{
		if(PathFileExists(alertpath))
		ShellExecute(0,0,alertpath,0,0,1);
				AfxMessageBox(msgtips);
		}
		else*/
		g_qqrestartingflag=true;
		{
		OnBnClickedButton1();
		}
	
}
BOOL C晨风qq机器人Dlg::CheckUpdateNow()
{


	CString timemfile=updatehttppath;//AMseed.zip");
	
	CString rtquestr;
	
	SYSTEMTIME lasttime,locallasttime;
	if(::function::GetLastmodifydate(timemfile,rtquestr,&lasttime))
	{
	TCHAR bufname[256];
	GetModuleFileName(NULL,bufname,256);
	WIN32_FIND_DATA wfd;
    FILETIME ft;
   

    // 获取文件属性信息
    FindClose(FindFirstFile(bufname, &wfd));
    FileTimeToLocalFileTime(&wfd.ftLastWriteTime, &ft);
	FileTimeToSystemTime(&ft,&locallasttime);
	
	int minute1=lasttime.wMonth*31*24*60+lasttime.wDay*24*60+lasttime.wHour*60+lasttime.wMinute;
	int minute2=locallasttime.wMonth*31*24*60+locallasttime.wDay*24*60+locallasttime.wHour*60+locallasttime.wMinute;
	//CString fmtstr;
	//fmtstr.Format(_T("%02d.%02d.%02d.%02d  %02d.%02d.%02d.%02d ===%d"),lasttime.wYear,lasttime.wMonth,lasttime.wDay,lasttime.wHour,locallasttime.wYear,locallasttime.wMonth,locallasttime.wDay,locallasttime.wHour,day1-day2);
	//MessageBox(fmtstr);
	if(minute1-minute2>3)
		return true;
	else
	return false;
	}
	else
		return false;
}
void ReMoveReadOnly(LPCTSTR g_tempheadfilepath)
{
	CFileStatus Status; 

if (CFile::GetStatus(g_tempheadfilepath,Status))
{
if((Status.m_attribute &FILE_ATTRIBUTE_READONLY)==FILE_ATTRIBUTE_READONLY)// read only 
{ // "-r" 
Status.m_attribute &=(~FILE_ATTRIBUTE_READONLY);// write read 
CFile::SetStatus(g_tempheadfilepath,Status ); 
}

}

}
UINT ProUpdateLatestVersion(LPVOID lp)
{
	TCHAR downsavename[256]=_T("");
		
			::function::DownHttpFileAndSave(updatehttppath,downsavename);
		ShellExecute(NULL,NULL,downsavename,0,NULL,1);
		return true;
}
BOOL C晨风qq机器人Dlg::CheckUpdateAndPrompt()
{

	if(CheckUpdateNow())
	{

			CStringvect vectemp;
		CString updateurl;
			updateurl.Format(_T("%s.txt"),updatehttppath);
		UINT ddlen=::function::DownloadHttpTxtFile(updateurl,vectemp);
		if(ddlen>0&&vectemp.size()>0)
		{
			CString fmtstr;
			for(int i=0;i<vectemp.size();i++)
			{
			fmtstr+=vectemp[i];
			fmtstr+=_T("\r\n");
			if(fmtstr.GetLength()>200)
				break;
			}
			fmtstr+=_T("……");

		if(IDOK==MessageBox(fmtstr,_T("发现升级版，是否立即更新？升级不会导致设置和数据丢失！"),MB_OKCANCEL))
		{
		
AfxBeginThread(ProUpdateLatestVersion,NULL);
return true;
	//	if(IDOK==MessageBox(_T("等下载完了最新版本后，请自行双击压缩包中的安装文件进行安装。你希望现在就退出当前这个老版本软件吗？"),_T("是否立即关闭当前版本，然后去安装最新版本？"),MB_OKCANCEL))
	//	//if(IDOK==MessageBox(_T("此软件是绿色免安装版本，下载完了最新版本后，请自行把最新版本解压缩到老版本的文件夹下运行（这样就不会丢失之前的签到积分文件）。你希望现在就退出当前这个老版本软件吗？"),_T("是否立即关闭当前版本，然后手动去运行最新版本？"),MB_OKCANCEL))
	//	{
	//DestroyWindow();
	//	
	//	}

		}

		}
		return true;
	}
	return false;
}
BOOL GetNickNameFromGroupUinMap(INT64 m_groupuin,INT64 cur_uin,CString& tempnamestr)
{
		if(cur_uin==123456789)
			cur_uin=g_interfaceuin;

	BOOL rtflag=false;
	CKeepINT64StrMap *pintstrmap=NULL;
	lockgnameresource.Lock();
	if(g_group_uinNameMap.Lookup(m_groupuin,pintstrmap))
	rtflag=(*pintstrmap).Lookup(cur_uin,tempnamestr);
lockgnameresource.Unlock();

if(tempnamestr.Find(_T("<"))!=-1&&tempnamestr.Find(_T(">"))!=-1)
{
	int pos=tempnamestr.Find(_T(">"));
	tempnamestr=tempnamestr.Mid(pos+1);

}
	return rtflag;	
}
INT64 ExtractGroupidFromStr(LPCTSTR wholename,CString*truename/*=NULL*/)
{
	INT64 m_groupnum=0;
	 CString expressstr;
	 	expressstr.Format(_T("(?<=\\()\\d+(?=\\))"));
	CString rtmatchstr;


BOOL	bGetmatch=GetFirstRegMatch(wholename,expressstr,rtmatchstr,false);
if(bGetmatch)
m_groupnum=_ttoi64(rtmatchstr);
else
{
expressstr.Format(_T("\\d+"));
	


bGetmatch=GetFirstRegMatch(wholename,expressstr,rtmatchstr,false);
if(bGetmatch)
m_groupnum=_ttoi64(rtmatchstr);

}

if(m_groupnum&&truename)
{
*truename=wholename;
CString fmtstr;
fmtstr.Format(_T("(%lld)"),m_groupnum);
truename->Replace(fmtstr,_T(""));
fmtstr.Format(_T("%lld"),m_groupnum);
truename->Replace(fmtstr,_T(""));
}
return m_groupnum;
}
BOOL IsIgnoreOrShutupGroupForName(LPCTSTR groupuinname)
{
	INT64 groupuin=ExtractGroupidFromStr(groupuinname);
return IsIgnoreOrShutupGroup(groupuin);
}
BOOL IsInDislkBackvect(INT64 groupuin)
{
	CString 	findstr;
		vector<CString>::iterator findit;
		BOOL bfind=false;
	findstr.Format(_T("%lld"),groupuin);

	lockdislikevectres.Lock();
		findit=find_if(dislkbackbufvect.m_mapstr.begin(),dislkbackbufvect.m_mapstr.end(),SameQQGroupNumfun(findstr));
		bfind=findit!=dislkbackbufvect.m_mapstr.end();
		lockdislikevectres.Unlock();

		return bfind;
}
BOOL IsIgnoreOrShutupGroup(INT64 groupuin)
{
	if(!groupuin)
		return false;

	BOOL rtflag=false;
	CString findstr;
				lockgroupnameresource.Lock();
				if(GidNickNamemap.Lookup(groupuin))
					findstr=GidNickNamemap[groupuin];
				lockgroupnameresource.Unlock();
				if(findstr.IsEmpty()&&g_Androidflag)
				{

				findstr.Format(_T("%lld"),groupuin);
				}

				if(g_bIgnoreAll)
				{
		vector<CString>::iterator findit;
		BOOL bnotfind=false;
		lockdislikevectres.Lock();
		findit=find_if(dislkbackbufvect.m_mapstr.begin(),dislkbackbufvect.m_mapstr.end(),SameQQGroupNumfun(findstr));
		bnotfind=findit==dislkbackbufvect.m_mapstr.end();
		lockdislikevectres.Unlock();
				if(bnotfind)//默认关闭状态下，没找到就是不开启
				{
					if(g_workindiscussgroup&&g_discusslist.Lookup(groupuin))
					{
					//开启讨论组
					}
					else
				rtflag=true;
				}
				else 
				{


					INT64 overtimevalue=0;
					
					lockdislikevectres.Lock();
					dislkbackbufvect.Lookup(*findit,overtimevalue);
					lockdislikevectres.Unlock();
					if(IsTimeOver(overtimevalue))
						rtflag=true;
					else
					rtflag=false;
				}

				}
				else
				{
					BOOL findif=false;
					lockdislikevectres.Lock();
					findif=find_if(dislkbackbufvect.m_mapstr.begin(),dislkbackbufvect.m_mapstr.end(),SameQQGroupNumfun(findstr))!=dislkbackbufvect.m_mapstr.end();
					lockdislikevectres.Unlock();
				if(findif)
				{
				rtflag=true;
				}
				else
				{
rtflag=false;
				}

				}

				lockgroupbeignoreresource.Lock();
				g_groupbeIgnoreMap[groupuin]=rtflag;
				lockgroupbeignoreresource.Unlock();

				return rtflag;
}
CString GetSingleMidParamFromBetweenWebBuf(LPCTSTR buf,LPCTSTR targetstr1,LPCTSTR targetstr2)
{
	CString rtcode;
	CString rtbufstr=buf;

	CString wholekeyname;
	wholekeyname.Format(_T("%s"),targetstr1);
	int pos=rtbufstr.Find(wholekeyname);
	if(pos!=-1)
	{
		rtbufstr=rtbufstr.Mid(pos+lstrlen(wholekeyname));

		int pos2=rtbufstr.Find(targetstr2);

		if(pos2!=-1)
		{
			rtcode=rtbufstr.Left(pos2);


		}
	}	
	return rtcode;
}

BOOL C晨风qq机器人Dlg::IsBelongLastTenMsg(const qqretdata& myqqretdata)
{
	static int pos=0;
	CString nowmsgstr;
	nowmsgstr.Format(_T("%lld_%lld_%lld_%d_%s"),myqqretdata.FromUin,myqqretdata.ToUin,myqqretdata.GroupID,myqqretdata.Time,myqqretdata.Content);
	for(int i=0;i<100;i++)
	{
	if(m_lasttenmsg[i]==nowmsgstr)
		return true;
	}
m_lasttenmsg[pos%100]=nowmsgstr;

pos++;
	return false;
}
BOOL C晨风qq机器人Dlg::TakeEveryMsg(int rtint,const qqretdata& myqqretdata,int bVoice/*=false*/)//2==语音、3==转账
{
	static qqretdata lastmyqqretdata;

	if(IsBelongLastTenMsg(myqqretdata))
		return false;

	if(lastmyqqretdata.FromUin==myqqretdata.FromUin)
		if(lastmyqqretdata.ToUin==myqqretdata.ToUin)
		if(lastmyqqretdata.GroupID==myqqretdata.GroupID)
				if(lastmyqqretdata.Content==myqqretdata.Content)
				{
				if((rtint==1||rtint==2||rtint==3)&&lastmyqqretdata.Time==myqqretdata.Time)
					return false;
	
				}


			lastmyqqretdata=myqqretdata;



	if(rtint==0&&!g_stoprestart)
	{
		
		
		//CString str222;
	str222.Format(_T("%d:%s:此帐号在其它地方上线了，你已经被迫下线，如果你想重新上线，你必须重新登录！"),rtint,g_sleepforRelogin);
		Write2MagnetLog(str222,&magnetfile,3);

		NeedReLogin(_T("此帐号在其它地方上线了，你已经被迫下线，如果你想重新上线，你必须重新登录！"));
		
	
		
	}
	else if(rtint==1||rtint==2||rtint==3)
	{

		//if(g_windowstext.Find(_T("晨风QQ机器人"))==-1||g_windowstext.Find(_T("破解"))!=-1)//||g_windowstext.Find(_T("此软件会让qq下线，正常现象，勿虑"))==-1
		//{
		//	bCrackFlag=true;
		//return false;
		//}
		
		//晨风QQ机器人3.41版——此软件会让qq下线，正常现象，勿虑
		INT64 sendqq=0;
		INT64 groupuin=0;
sendqq=myqqretdata.FromUin;
BOOL qunflag=false;
INT64 curgcode=myqqretdata.GroupCode;
INT64 sharekey=myqqretdata.FromUin;	//对于群消息，fromuin是群号，对于好友消息和临时消息，fromuin都是对方的qq号	



if(rtint==1)//123456:
{
INT64 defgroupuin=_ttoi64(myqqretdata.Content);
if(defgroupuin>10000)
{
	CString defgpstr;
	defgpstr.Format(_T("%lld"),defgroupuin);
	int mylen=defgpstr.GetLength();
	if(myqqretdata.Content.GetLength()>mylen&&(myqqretdata.Content.GetAt(mylen)==':'||myqqretdata.Content.GetAt(mylen)==L'：'))
	{
		INT64 puredefgroupuin=0;
		puredefgroupuin=GetGUinFromRealGroupqqNum(defgroupuin);
		if(puredefgroupuin)
		{
			CString* modifiercontent = const_cast<CString*>(&myqqretdata.Content);

			*modifiercontent=myqqretdata.Content.Mid(mylen+1);
			if(!(*modifiercontent).IsEmpty())
			{
			rtint=3;
			INT64 *modifiergroupid=const_cast<INT64*>(&myqqretdata.GroupID);

			*modifiergroupid=puredefgroupuin;
			}
		}
		else
				sharekey=myqqretdata.FromUin+10086;//2017.11.21
		}
	else
	{
	sharekey=myqqretdata.FromUin+10086;//2017.11.21
	}

}
		else//防止qq号和群号相同
		{
		
			
		sharekey=myqqretdata.FromUin+10086;//2017.11.21
		}
}
if(rtint==2||rtint==3)//
{
				//::MessageBoxA(0,(char*)lParam,0,0);
				
				//GetGroupNickName(groupuin,nicknamestr);
				
				if(rtint==3)
					qunflag=false;
				else
					 qunflag=true;
				
				if(rtint==2)
				{
		groupuin=myqqretdata.FromUin;//群号
			//sendqq=myqqretdata.FromUin;
			sendqq=myqqretdata.SendUin;//群成员qq号
				}
				else if(rtint==3)
			{
			groupuin=myqqretdata.GroupID;
			sendqq=myqqretdata.FromUin;
			sharekey=sendqq+groupuin;//这样可避免一个qq号在两个群时发的消息都归到一个群里
			}
				if(!(g_bIgnoreAll^g_temporaryignorall))
					return 0;

				if(groupuin)
		{
			BOOL m_beIgnoreflag=false;
			BOOL bFind=false;
			lockgroupbeignoreresource.Lock();
				bFind=g_groupbeIgnoreMap.Lookup(groupuin,m_beIgnoreflag);
				lockgroupbeignoreresource.Unlock();

				if(!bFind)
				{
					if(IsIgnoreOrShutupGroup(groupuin))
						return 0;
				}
				else
				{
		if(m_beIgnoreflag)
			return 0;
				}

		}
				//2016.12.28改成由一个变量来判断是否屏蔽了
				//if(IsIgnoreOrShutupGroup(groupuin))
					//return 0;
}
			
			CString nicknamestr;

		
				
			if(groupuin)
			{
				if(find(g_tempgroupuinset.begin(),g_tempgroupuinset.end(),groupuin)==g_tempgroupuinset.end())
				{

				g_tempgroupuinset.insert(groupuin);
				//第一次获取群信息
				{
				GetLatestGroupInf(groupuin);


				}
				GetGroupUinNickName(groupuin);
			
				}
				else
				{

					BOOL bReadover=false;
					int retrycount=0;
					lockreadgroupnickres.Lock();
					retrycount=g_group_uinRetryMap[groupuin].retrycount;
					bReadover=g_group_uinRetryMap[groupuin].bReadover;
					lockreadgroupnickres.Unlock();
					if(bReadover&&retrycount<10)
					{
					CKeepINT64StrMap *pintstrmap=NULL;
				lockgnameresource.Lock();
				int qunsize=0;
	if(g_group_uinNameMap.Lookup(groupuin,pintstrmap))
	qunsize=pintstrmap->GetSize();
		lockgnameresource.Unlock();
		if(qunsize==0)//0)//暂时去掉重新读取
		{
		
			
			lockreadgroupnickres.Lock();
					retrycount=g_group_uinRetryMap[groupuin].retrycount;
					bReadover=g_group_uinRetryMap[groupuin].bReadover;
					lockreadgroupnickres.Unlock();
						if(bReadover&&retrycount<10)
					{
			if(retrycount<10)
g_tempgroupuinset.erase(groupuin);

				//CString str222;
	str222.Format(_T("pintstrmap->GetSize()==0 %I64d %d"),groupuin,bReadover);
		Write2MagnetLog(str222,&magnetfile,4);
						}
		}
				}
				}
			}
		BOOL bFind=false;
			lockqqmsgdlgres.Lock();
bFind=m_mapqqmsgdlg.Lookup(sharekey);
				lockqqmsgdlgres.Unlock();
		if(!bFind)
		{
			STARTTIME

				if(!g_discusslist.Lookup(groupuin,nicknamestr))
GetthreeNickName(rtint,myqqretdata.RealUin,groupuin,sendqq,nicknamestr);
	
			CreateQQMsgDlg(groupuin,sendqq,nicknamestr,qunflag,false,curgcode);
	TESTFUNTIME(GetthreeNickName_CreateQQMsgDlg)
		}
		CString prenickmembername;
		if(rtint==1)
		{

			bFind=false;
			lockqqmsgdlgres.Lock();
bFind=m_mapqqmsgdlg.Lookup(sharekey);
			

			if(bFind)
			{
		prenickmembername=m_mapqqmsgdlg[sharekey]->m_qqnickname;
			}
	lockqqmsgdlgres.Unlock();
			if(prenickmembername.IsEmpty())
			{
		GetNickNameFromGroupUinMap(groupuin,sharekey,prenickmembername);

/*
			BOOL rtflag=UinNickNameMap.Lookup(sharekey,prenickmembername);
			if(rtflag)
			GetExactGroupNickName(groupuin,prenickmembername);
*/
				
			}
			if(prenickmembername.IsEmpty())
			{
			prenickmembername.Format(_T("%I64d"),sharekey);
			}

		}
		if(rtint==2||rtint==3)//加上群成员名称
		{
		
			GetNickNameFromGroupUinMap(groupuin,sendqq,prenickmembername);
		
		}
		/*static int lasttime=0;
		if(lasttime==myqqretdata.Time)
		{
			MessageBox(_T("重复"),myqqretdata.Content,0);
		lasttime++;
		}
		lasttime=myqqretdata.Time;*/
		/*	if(g_loginwindowstext!=_T("先登录你的QQ")||g_loginwindowstext.Find(_T("破解"))!=-1)
		{
			bCrackFlag=true;
		return false;
		}*/

		if(bstop2==false)
		{
			CString m_qqnicknamesss;
			lockqqmsgdlgres.Lock();
			if(m_mapqqmsgdlg.Lookup(sharekey))
				m_qqnicknamesss=m_mapqqmsgdlg[sharekey]->m_qqnickname;

			lockqqmsgdlgres.Unlock();

			if(m_qqnicknamesss.IsEmpty())
			{
				CString strtemp;
				CString tempstrqunname;
				if(rtint==1)
				{
					GetNickNameFromGroupUinMap(groupuin,sharekey,tempstrqunname);

					strtemp=tempstrqunname;
				}
				else if(rtint==2||rtint==3)
				{
					if(!g_discusslist.Lookup(groupuin,tempstrqunname))
					{
						lockgroupnameresource.Lock();
						GidNickNamemap.Lookup(groupuin,tempstrqunname);
						lockgroupnameresource.Unlock();
					}
					strtemp=tempstrqunname;
					if(!qunflag)
					{
						CString tempstr;
						tempstr.Format(_T("QQ号：%I64d"),myqqretdata.RealUin);
						CString strtemp;
						strtemp.Format(_T("群【%s】成员%s"),tempstrqunname,tempstr);
					}
				}
				lockqqmsgdlgres.Lock();
				if(m_mapqqmsgdlg.Lookup(sharekey))
				m_mapqqmsgdlg[sharekey]->m_qqnickname=strtemp;
				lockqqmsgdlgres.Unlock();
			}
			if(!myqqretdata.Content.IsEmpty())
			{

				CString content=myqqretdata.Content;
				if(content.Find(_T("向你转账"))!=-1&&content.Find(_T("向你转账"))<5)
				{
					content.Replace(_T("向你转账"),_T(""));
				}
	if(content.Find(_T("我刚上传了"))!=-1&&content.Find(_T("我刚上传了"))<5)
				{
					content.Replace(_T("我刚上传了"),_T("fake我刚上传了"));
				}

				if(content.Find(_T("sendqqgift[送礼物] 为"))==0)
				{

					content.Replace(_T("sendqqgift[送礼物] 为"),_T("送出礼物给"));

					if(1)
						bVoice=3;

				}
				else
					content.Replace(_T("送出礼物给"),_T(""));



				if(content.Find(_T("你的QQ版本过低，不支持查看话题消息"))==0)
				{

					//content.Replace(_T("sendqqgift[送礼物] 为"),_T("送出礼物给"));

					CString transcationid=GetSingleMidParamFromBetweenWebBuf(content,_T("<content>"),_T("</content>"));
					content=_T("收到话题内容：")+transcationid;
				}
				else
				{
					if(content.Find(_T("收到话题内容："))==0)
					{
						content=content.Mid(lstrlen(_T("收到话题内容：")));
					}
				}

				if(content.Find(_T("<?xml"))==0&&content.Find(_T("qun.qq.com"))!=-1&&content.Find(_T("签到"))!=-1)
				{
					CString locstr;
					CString additionalstr;
					CString expressstr;
					int defaultnum=10;
					CStringvect weather6vect;
					expressstr.Format(_T("(?<=<summary>).*?(?=</summary>)"));
					GetRegEX(content,expressstr,weather6vect,0,true);//need consider of the actual keyname
					if(weather6vect.size()>0)
						locstr=weather6vect[0];

					if(locstr.IsEmpty())
					{
						locstr=_T("未知地点");
					}
					else
					{


					}

					g_checkqqwhere_map[groupuin+sendqq]=locstr;

					expressstr.Format(_T("(?<=<title>).*?(?=</title>)"));
					GetRegEX(content,expressstr,weather6vect,0,true);//need consider of the actual keyname
					if(weather6vect.size()>0)
						additionalstr=weather6vect[0];


					content=_T("用手机签到在")+locstr;
					content+=_T(" ");
					content+=additionalstr;

				}
				else
					content.Replace(_T("用手机签到在"),_T(""));

				if(bVoice!=3)
				{

					content.Replace(_T("转账消息金额"),_T(""));

				}
				else if(!Isggged)
				{
					if(rand()%3==2)
					{
						content.Replace(_T("转账消息金额"),_T(""));
						content+=_T("未注册版功能受限！");

					}
				}

				if((!qunflag&&g_notreplyprivate_list.find(sendqq)!=g_notreplyprivate_list.end())||(qunflag&&g_notreplygroup_list.find(sendqq)!=g_notreplygroup_list.end()))
				{
//不回复的私聊好友
				}
				else
				{

					lockqqmsgdlgres.Lock();
					m_mapqqmsgdlg[sharekey]->ShowNewMsg(prenickmembername,content,myqqretdata.Time,sendqq,0,bVoice,myqqretdata.MsgId);
					lockqqmsgdlgres.Unlock();
				}
			}
		}

		SetWindowText(m_addtitle+_T("有新消息！"));

		if(bNeedReDetectflag&&g_reporturl.IsEmpty()&&!g_bAutoReportAds.IsEmpty())
{	
	CString tempreporturl;
tempreporturl=g_bAutoReportAds;//g_outputreplacemap[_T("自动回报机器人在线状态的接口网址")].front();
CString dddd;

		dddd.Format(_T("&cfrobotselfnum=%s&version=%s&checksign=%s"),m_ownqqnumber,g_purenumberversion,g_ksidmd5);
		
		
		
		if(tempreporturl.Find(_T('?'))==-1)
			tempreporturl+='?';
tempreporturl+=dddd;
		
g_reporturl=tempreporturl;


}
	

		m_lastnewmsgtime=GetTickCount();
	}
	else if(rtint==4&&bstop3==false)
	{
		
INT64 qqgroupid=myqqretdata.FromUin;
INT64 requestuin=myqqretdata.request_uin;
INT64 qqaccount=myqqretdata.account;
CString content;
//group_request_join
BOOL b1ftwo=false;
CString qqnickname;
int bMale=-1;
if(myqqretdata.typestr==_T("verify_required"))
{
	b1ftwo=true;
qqgroupid=0;
requestuin=0;

qqnickname=myqqretdata.sendname;

		

content.Format(_T("%I64d(%s)想加你为好友，申请理由：%s"),qqaccount,qqnickname,myqqretdata.Content);
}
else if(myqqretdata.typestr==_T("group_request_join"))
{

	if(!(g_bIgnoreAll^g_temporaryignorall))
					return 0;
				if(IsIgnoreOrShutupGroup(qqgroupid))
					return 0;

	b1ftwo=true;
	
	qqaccount=GetRealQQnumber(requestuin,false);

	qqnickname=myqqretdata.sendname;

	if(qqaccount)
	{
		/*	qqnickgender tempnkg;
			tempnkg.bMale=bMale;
			lstrcpy(tempnkg.namebuf,qqnickname);*/
		//	lockqqnickgender.Lock();
	//g_realqqnamegender_map[qqaccount]=tempnkg;
	//lockqqnickgender.Unlock();
	}
	lockgroupnameresource.Lock();

CString gidname;
if(GidNickNamemap.Lookup(qqgroupid))
gidname=GidNickNamemap[qqgroupid];
	lockgroupnameresource.Unlock();

	content.Format(_T("%I64d(%s)想加入群【%s】，申请理由：%s"),qqaccount,qqnickname,gidname,myqqretdata.Content);
}
if(b1ftwo)
{
	int temp_method=1;
	if(qqgroupid)
	{
	if(myqqretdata.GroupCode)
	{
	lockgidgcoderesource.Lock();
	
	GidGcodemap[qqgroupid]=myqqretdata.GroupCode;
	lockgidgcoderesource.Unlock();
	}
	INT64 realgroupnum=GetRealQQnumber(qqgroupid,true);

	if(GRealNumRulemap.Lookup(realgroupnum))
	{
qqgrouprule &m_grule=GRealNumRulemap[realgroupnum];
temp_method=m_grule.g_group_request_method;
	}
	else
	{
	temp_method=g_defaultqqgrouprule.g_group_request_method;
	}

	}
	else
	{
	
	temp_method=g_friend_request_method;
	}

		INT64 m_realgroupnumber;
			if(qqgroupid)
	m_realgroupnumber=GetRealQQnumber(qqgroupid,true);
	else
	m_realgroupnumber=0;
			qqgrouprule m_grule;
				if(!GRealNumRulemap.Lookup(m_realgroupnumber,m_grule))
m_grule=g_defaultqqgrouprule;
	//if(temp_method>0||g_slientmode)
	{
		BOOL bFind;
		lockqqacdlg.Lock();
		bFind=m_mapqqacdlg.Lookup(qqaccount);
		lockqqacdlg.Unlock();
	if(!bFind)
	{

		
		{
			AcceptStruct *pqqgroup=new AcceptStruct;
	pqqgroup->content=content;
pqqgroup->qqnickname=qqnickname;
	pqqgroup->qqgroupid=qqgroupid;
	pqqgroup->requestuin=requestuin;
	pqqgroup->qqaccount=qqaccount;
	pqqgroup->ReplyIp=myqqretdata.ReplyIp;
	pqqgroup->realgroupid=m_realgroupnumber;
	pqqgroup->m_grule=m_grule;
	AfxBeginThread(ProTakeRequestFun,pqqgroup);

		}
		
	}

	}

	
}
		//m_mapqqacdlg
	}
	else if(rtint==5)
	{
		//AfxMessageBox(_T("或许由于网络问题，你的qq掉线了，你必须重新登录！"));
		//bExitPostThread=true;
		//m_alreadylogin=false;
	
		//SendqqMsg(myqqretdata.FromUin,_T("什么"));
		SetWindowText(m_addtitle+_T("暂无新消息"));
	}
	else if(rtint==6&&!g_stoprestart)
	{
		str222.Format(_T("%d:%s:或许由于网络问题，此qq帐号掉线了，你必须重新登录！"),rtint,g_sleepforRelogin);
		Write2MagnetLog(str222,&magnetfile,3);
		
		if(offlineproblemcount>1)
		{
			NeedReLogin(_T("或许由于网络问题，此qq帐号掉线了，你必须重新登录！"));

		offlineproblemcount=0;
		}
		else
		{
		offlineproblemcount++;
		}
		

	}
	else if(rtint==7)
	{
	}
	else if(rtint==8)
	{
		if(g_autoreceiveflag&&myqqretdata.mode==_T("recv"))
		{
		ReceiveFile *prfstruct=new ReceiveFile;
		prfstruct->filename=myqqretdata.file_name;
		prfstruct->lc_id=myqqretdata.lc_id;
		prfstruct->to_uin=myqqretdata.FromUin;
prfstruct->msgid=myqqretdata.MsgId;
		AfxBeginThread(ProAutoReceiveFile,(LPVOID)prfstruct);
		//自动接收文件
		}
	}
	else
	{
	
	}
	
	return false;
}
void ReplaceRNForStr(CString& inputstr)
{
	inputstr.Replace(_T("\r\n"),RNDEFBUF);
	inputstr.Replace(_T("\n"),RNDEFBUF);


}
  void appendjoinedgroupnum(INT64 newgroupnum)
  {
  //set<INT64> g_had_joined_groupset;


	CReadAUStdioFile m_file1(true);
		CString Ignorefilename;
CString tempstr;
tempstr.Format(_T("加群记录(自动同意过一次后不会再同意第二次).txt"));
Ignorefilename=SaveAs_complete_path(tempstr);
		
m_file1.SetUnicodeFile(true);
g_had_joined_groupset.insert(newgroupnum);
	if(m_file1.Open(Ignorefilename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite|CFile::shareDenyNone))
	{
	m_file1.SeekToEnd();
		tempstr.Format(_T("%lld"),newgroupnum);
	m_file1.WriteLineStr(tempstr);
	m_file1.Flush();
	
	m_file1.Close();
	}

	if(g_bIgnoreAll)
	{
	int g_def_nickname_len=0;
	if(g_DefaultValidDays)//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("拉机器人进群后默认有效期天数"))!=g_outputreplacemap.m_mapstr.end())
			g_def_nickname_len=g_DefaultValidDays;//_ttoi(g_outputreplacemap[_T("拉机器人进群后默认有效期天数")].front());

	if(g_def_nickname_len)
	{
			INT64	nowtime=0;
			nowtime=AddValidTime(g_def_nickname_len,nowtime);
			CString filenamebuf2;
			filenamebuf2.Format(_T("%lld"),newgroupnum);
		filenamebuf2=Getfinalmergegroupname(filenamebuf2);
		INT64 oldtime=0;
		lockdislikevectres.Lock();
		dislkbackbufvect.Lookup(filenamebuf2,oldtime);
		lockdislikevectres.Unlock();

		lockgroupnameresource.Lock();
	
	if(find_if(backbufvect.begin(),backbufvect.end(),SameQQGroupNumfun(filenamebuf2))==backbufvect.end())
		backbufvect.push_back(filenamebuf2);
	
		lockgroupnameresource.Unlock();

		if(!oldtime)
		{
			lockdislikevectres.Lock();
			dislkbackbufvect[filenamebuf2]=nowtime;
			lockdislikevectres.Unlock();
		IsIgnoreOrShutupGroup(newgroupnum);
		}
	}
}
}
BOOL GetRuleFromFile(BOOL bLoad,INT64 realgroupnumber,qqgrouprule& temprule)
{
	BOOL rtflag=false;
	CReadAUStdioFile file1(true);
	CString strfmt;
		strfmt.Format(_T("%I64d.txt"),realgroupnumber);
CString strfmtlast;
		strfmtlast.Format(_T("%I64d最后一次记录.txt"),realgroupnumber);

		CString filepath=g_qqruledir+strfmt;
		CString lastfilepath=g_qqruledir+strfmtlast;
		CString tempstr;
	if(bLoad)
	{
		temprule=g_defaultqqgrouprule;
		temprule.m_selfrealqqgroupnum=realgroupnumber;
	if(m_ownqqnumber!=_T("3140206388")&&m_ownqqnumber!=_T("151409321")&&m_ownqqnumber!=_T("1745762710")&&m_ownqqnumber!=_T("35376062")&&(realgroupnumber==263932252||realgroupnumber==226519623||realgroupnumber==477633103||realgroupnumber==229375129||realgroupnumber==219161023||realgroupnumber==555421587||realgroupnumber==285960406||realgroupnumber==554045690||realgroupnumber==385479646||realgroupnumber==84456670))
	 {
		 
		 temprule.g_totalshutitup=true;
		 return rtflag;
	 } 
	
		//if(realgroupnumber!=0)
	try
	{
		if(realgroupnumber==0)
		{
			//if(PathFileExists(lastfilepath)&&!PathFileExists(filepath))
		//::function::RemoveR_CopyFileW(lastfilepath,filepath,false);
		}
	 if(file1.Open(filepath,CFile::modeRead|CFile::shareDenyWrite))
	 {
		

	if(file1.ReadString(tempstr))
				temprule.g_adminliststr=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_allowallshutitup=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_blackliststr=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_group_denyreason=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_group_request_method=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
	tempstr.Replace(RNDEFBUF,_T("\r\n"));	
	temprule.g_welcomestr=tempstr;

}
if(file1.ReadString(tempstr))
				temprule.g_sessionanswerfalg=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_checkin=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_gamble=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_totalshutitup=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_group_pincodestr=tempstr;

if(file1.ReadString(tempstr))
				temprule.g_talk=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_percent=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_timeover=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_continuefind=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_includekey=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_privateadminanswer=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_tipsotheradmin=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_publicanswer=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_allowallanswer=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_byprivate=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_prefixstr=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_groupdefaultanswer=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_robotname=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_speakaward=_ttoi(tempstr);

if(file1.ReadString(tempstr))
{
				temprule.g_forbidden=_ttoi(tempstr);
if(companyverion)
	temprule.g_forbidden=true;
}
if(file1.ReadString(tempstr))
				temprule.g_autonoticetime=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
		
tempstr.Replace(RNDEFBUF,_T("\r\n"));
temprule.g_hellowstr=tempstr;
}


if(file1.ReadString(tempstr))
				temprule.g_scale=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_tradegrouplist=tempstr;

if(file1.ReadString(tempstr))
				temprule.g_checkperiod=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
		
tempstr.Replace(RNDEFBUF,_T("\r\n"));
temprule.g_ranktitlestr=tempstr;
}
if(file1.ReadString(tempstr))
				temprule.g_banliststr=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_rob=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_gamblerobtimes=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_forwordkeyliststr=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_punishshua=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_onlyself=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_idiomfun=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
		
tempstr.Replace(RNDEFBUF,_T("\r\n"));
temprule.g_storeprice=tempstr;
}

if(file1.ReadString(tempstr))
				temprule.g_coinname=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_queryfun=_ttoi(tempstr);
if(file1.ReadString(tempstr)) 
				temprule.g_scale_idiom=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_scale_rush=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_scale_crazy=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_times_crazy=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_timeout_idiom=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_timeout_rush=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_nperson_rush=_ttoi(tempstr);

if(file1.ReadString(tempstr))
				temprule.g_idiom_cost=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_gamble_cost=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_rob_cost=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_query_cost=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_rush_punish_cost=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.belowscore=_ttoi64(tempstr);
if(file1.ReadString(tempstr))
				temprule.spamtimes=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
temprule.kickspamtips=tempstr;
}

if(file1.ReadString(tempstr))
				temprule.forbidadminset=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.gambletopvalue=_ttoi64(tempstr);
if(file1.ReadString(tempstr))
				temprule.adminawardtop=_ttoi64(tempstr);
if(file1.ReadString(tempstr))
{
temprule.precardstr=tempstr;
}
if(file1.ReadString(tempstr))
{
temprule.femaleprecardstr=tempstr;
}
if(file1.ReadString(tempstr))
				temprule.lotteryprice=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.lotteryopentime=tempstr;
if(file1.ReadString(tempstr))
				temprule.repeatcheckfine=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.bShowkindstips=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.luckynumbercost=_ttoi(tempstr);


if(file1.ReadString(tempstr))
{
		
tempstr.Replace(RNDEFBUF,_T("\r\n"));
temprule.timetask=tempstr;
}
if(file1.ReadString(tempstr))
				temprule.g_rushfun=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_vipliststr=tempstr;
if(file1.ReadString(tempstr))
				temprule.g_guessfun=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_guesspsrock=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.guesspsrcost=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
				temprule.m_tax_percent=_ttoi(tempstr);
					temprule.m_tax_percent=max(0,temprule.m_tax_percent);
		temprule.m_tax_percent=min(100,temprule.m_tax_percent);

}
temprule.g_scale=max(temprule.g_scale,1);
temprule.g_times_crazy=max(temprule.g_times_crazy,2);
temprule.g_scale_idiom=max(temprule.g_scale_idiom,1);
temprule.g_scale_rush=max(temprule.g_scale_rush,1);
temprule.g_scale_crazy=max(temprule.g_scale_crazy,1);
temprule.g_timeout_idiom=max(temprule.g_timeout_idiom,5);
temprule.g_timeout_rush=max(temprule.g_timeout_rush,5);
temprule.g_nperson_rush=max(temprule.g_nperson_rush,1);
if(file1.ReadString(tempstr))
{
				temprule.m_dropequipscale=_ttoi(tempstr);
					temprule.m_dropequipscale=max(1,temprule.m_dropequipscale);
		temprule.m_dropequipscale=min(10000,temprule.m_dropequipscale);

}
if(file1.ReadString(tempstr))
	temprule.m_forbidprivate=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.rushprefixstr=tempstr;
if(file1.ReadString(tempstr))
	temprule.m_rankwithlike=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.likevalue=_ttoi(tempstr);
if(file1.ReadString(tempstr))
	temprule.hatemustover=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.probationminutes=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.robneedLowestRankNum=_ttoi64(tempstr);
if(file1.ReadString(tempstr))
				temprule.robneedwaitTime=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.initscore=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.paybackscale=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.gamblehardscale=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.bidwaittime=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.bidbacknum=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.bTatalSlient=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.bOpenSelfDefGame=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
temprule.nnnnprecardstr=tempstr;
}
if(file1.ReadString(tempstr))
				temprule.minutes_mustdosomething=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.action_mustdowhat=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.punish_otherwise=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_singlexmlflag=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_group_pinqqlevel=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.g_group_pinqqdarenlevel=_ttoi(tempstr);
if(file1.ReadString(tempstr))
{
temprule.adminprecardstr=tempstr;
}
if(file1.ReadString(tempstr))
{
temprule.m_modifycardurl=tempstr;
}
if(file1.ReadString(tempstr))
				temprule.m_allowprivaterush=_ttoi(tempstr);
if(file1.ReadString(tempstr))
				temprule.maxreplywithinmin=_ttoi(tempstr);

file1.Close();


	rtflag=true;
			}
			}
			catch (...)
			{

			}

				/*catch(CFileException e)
				{
				str222.Format(_T("%I64d:读取规则文件错误%d"),realgroupnumber,e.m_cause);
		Write2MagnetLog(str222,&magnetfile,4);
				}*/
temprule.g_robotadminsset.clear();
temprule.g_blacklist.clear();
temprule.g_banlist.clear();
temprule.g_forwordkeylist.clear();
temprule.g_viplist.clear();

CStringvect adminvectemp;

if(!temprule.g_adminliststr.IsEmpty())
{
			::function::getmytoken(temprule.g_adminliststr,';',adminvectemp);
			INT64 tempadminqq=0;
			for(int i=0;i<adminvectemp.size();i++)
			{
				tempadminqq=_ttoi64(adminvectemp[i]);
				if(tempadminqq)
			temprule.g_robotadminsset.insert(tempadminqq);
			}
}

if(!temprule.g_blackliststr.IsEmpty())
{
			::function::getmytoken(temprule.g_blackliststr,';',adminvectemp);
			INT64 tempadminqq=0;
			for(int i=0;i<adminvectemp.size();i++)
			{
				tempadminqq=_ttoi64(adminvectemp[i]);
				if(tempadminqq)
			temprule.g_blacklist.insert(tempadminqq);
			}
}
if(!temprule.g_banliststr.IsEmpty())
{
			::function::getmytoken(temprule.g_banliststr,';',adminvectemp);
			for(int i=0;i<adminvectemp.size();i++)
			{
			temprule.g_banlist.push_back(adminvectemp[i]);
			}
}
if(!temprule.g_forwordkeyliststr.IsEmpty())
{
			::function::getmytoken(temprule.g_forwordkeyliststr,';',adminvectemp);
			
			for(int i=0;i<adminvectemp.size();i++)
			{
		
			temprule.g_forwordkeylist.push_back(adminvectemp[i]);
			}
}
if(!temprule.g_vipliststr.IsEmpty())
{
			::function::getmytoken(temprule.g_vipliststr,';',adminvectemp);
			INT64 tempadminqq=0;
			for(int i=0;i<adminvectemp.size();i++)
			{
				tempadminqq=_ttoi64(adminvectemp[i]);
			temprule.g_viplist.insert(tempadminqq);
			}
}


	}
	else
	{
	
		try
		{
			::function::RemoveRH(lastfilepath);
if(file1.Open(lastfilepath,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyWrite))
		{
		
TCHAR buf[32];

file1.WriteLineStr(temprule.g_adminliststr);
_itot(temprule.g_allowallshutitup,buf,10);	
file1.WriteLineStr(buf);

temprule.g_blackliststr=_T("");
CString fmtstr;
if(temprule.g_blacklist.size()>8000)//超过8000条自动清零一次
{
temprule.g_blacklist.clear();
}
			for(auto it=temprule.g_blacklist.begin();it!=temprule.g_blacklist.end();it++)
			{
				fmtstr.Format(_T("%I64d"),*it);
				temprule.g_blackliststr+=fmtstr;
				temprule.g_blackliststr+=_T(";");

			}
file1.WriteLineStr(temprule.g_blackliststr);
//temprule.g_group_denyreason.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_group_denyreason);

file1.WriteLineStr(temprule.g_group_denyreason);
_itot(temprule.g_group_request_method,buf,10);	
file1.WriteLineStr(buf);
//temprule.g_welcomestr.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_welcomestr);

file1.WriteLineStr(temprule.g_welcomestr);

_itot(temprule.g_sessionanswerfalg,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_checkin,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_gamble,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_totalshutitup,buf,10);	
file1.WriteLineStr(buf);
//temprule.g_group_pincodestr.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_group_pincodestr);


file1.WriteLineStr(temprule.g_group_pincodestr);


_itot(temprule.g_talk,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_percent,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_timeover,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_continuefind,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_includekey,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_privateadminanswer,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_tipsotheradmin,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_publicanswer,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_allowallanswer,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_byprivate,buf,10);	
file1.WriteLineStr(buf);
file1.WriteLineStr(temprule.g_prefixstr);
//temprule.g_groupdefaultanswer.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_groupdefaultanswer);

file1.WriteLineStr(temprule.g_groupdefaultanswer);

//temprule.g_robotname.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_robotname);

file1.WriteLineStr(temprule.g_robotname);
_itot(temprule.g_speakaward,buf,10);	
file1.WriteLineStr(buf);

_itot(temprule.g_forbidden,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_autonoticetime,buf,10);	
file1.WriteLineStr(buf);

//temprule.g_hellowstr.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_hellowstr);

file1.WriteLineStr(temprule.g_hellowstr);

_itot(temprule.g_scale,buf,10);	
file1.WriteLineStr(buf);	
//temprule.g_tradegrouplist.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_tradegrouplist);

file1.WriteLineStr(temprule.g_tradegrouplist);

_itot(temprule.g_checkperiod,buf,10);	
file1.WriteLineStr(buf);

//temprule.g_ranktitlestr.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_ranktitlestr);

file1.WriteLineStr(temprule.g_ranktitlestr);


temprule.g_banliststr=_T("");
temprule.g_forwordkeyliststr=_T("");
temprule.g_vipliststr=_T("");

			for(auto it=temprule.g_banlist.begin();it!=temprule.g_banlist.end();it++)
			{
				fmtstr.Format(_T("%s"),*it);
				temprule.g_banliststr+=fmtstr;
				temprule.g_banliststr+=_T(";");

			}
			for(auto it=temprule.g_forwordkeylist.begin();it!=temprule.g_forwordkeylist.end();it++)
			{
				
				temprule.g_forwordkeyliststr+=*it;
				temprule.g_forwordkeyliststr+=_T(";");

			}
			for(auto it=temprule.g_viplist.begin();it!=temprule.g_viplist.end();it++)
			{
				fmtstr.Format(_T("%I64d"),*it);
				temprule.g_vipliststr+=fmtstr;
				temprule.g_vipliststr+=_T(";");

			}

file1.WriteLineStr(temprule.g_banliststr);
_itot(temprule.g_rob,buf,10);	
file1.WriteLineStr(buf);

_itot(temprule.g_gamblerobtimes,buf,10);	
file1.WriteLineStr(buf);

file1.WriteLineStr(temprule.g_forwordkeyliststr);

_itot(temprule.g_punishshua,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_onlyself,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_idiomfun,buf,10);	
file1.WriteLineStr(buf);
//temprule.g_storeprice.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_storeprice);


file1.WriteLineStr(temprule.g_storeprice);
//temprule.g_coinname.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.g_coinname);

file1.WriteLineStr(temprule.g_coinname);
_itot(temprule.g_queryfun,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_scale_idiom,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_scale_rush,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_scale_crazy,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_times_crazy,buf,10);	
file1.WriteLineStr(buf);	

_itot(temprule.g_timeout_idiom,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_timeout_rush,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_nperson_rush,buf,10);	
file1.WriteLineStr(buf);	

_itot(temprule.g_idiom_cost,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_gamble_cost,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_rob_cost,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_query_cost,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.g_rush_punish_cost,buf,10);	
file1.WriteLineStr(buf);	
_i64tot(temprule.belowscore,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.spamtimes,buf,10);	
file1.WriteLineStr(buf);	
//temprule.kickspamtips.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.kickspamtips);

file1.WriteLineStr(temprule.kickspamtips);

_itot(temprule.forbidadminset,buf,10);	
file1.WriteLineStr(buf);	
_i64tot(temprule.gambletopvalue,buf,10);	
file1.WriteLineStr(buf);	
_i64tot(temprule.adminawardtop,buf,10);	
file1.WriteLineStr(buf);	
temprule.precardstr.Replace(_T("\r\n"),_T(""));
file1.WriteLineStr(temprule.precardstr);
temprule.femaleprecardstr.Replace(_T("\r\n"),_T(""));
file1.WriteLineStr(temprule.femaleprecardstr);
_itot(temprule.lotteryprice,buf,10);	
file1.WriteLineStr(buf);	

file1.WriteLineStr(temprule.lotteryopentime);	
_itot(temprule.repeatcheckfine,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.bShowkindstips,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.luckynumbercost,buf,10);	
file1.WriteLineStr(buf);	


//temprule.timetask.Replace(_T("\r\n"),RNDEFBUF);
ReplaceRNForStr(temprule.timetask);

file1.WriteLineStr(temprule.timetask);
_itot(temprule.g_rushfun,buf,10);	
file1.WriteLineStr(buf);
file1.WriteLineStr(temprule.g_vipliststr);
_itot(temprule.g_guessfun,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_guesspsrock,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.guesspsrcost,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.m_tax_percent,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.m_dropequipscale,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.m_forbidprivate,buf,10);	
file1.WriteLineStr(buf);	
file1.WriteLineStr(temprule.rushprefixstr);	
_itot(temprule.m_rankwithlike,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.likevalue,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.hatemustover,buf,10);	
file1.WriteLineStr(buf);	
_itot(temprule.probationminutes,buf,10);	
file1.WriteLineStr(buf);
_i64tot(temprule.robneedLowestRankNum,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.robneedwaitTime,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.initscore,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.paybackscale,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.gamblehardscale,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.bidwaittime,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.bidbacknum,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.bTatalSlient,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.bOpenSelfDefGame,buf,10);	
file1.WriteLineStr(buf);

temprule.nnnnprecardstr.Replace(_T("\r\n"),_T(""));
file1.WriteLineStr(temprule.nnnnprecardstr);

_itot(temprule.minutes_mustdosomething,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.action_mustdowhat,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.punish_otherwise,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_singlexmlflag,buf,10);	
file1.WriteLineStr(buf);

_itot(temprule.g_group_pinqqlevel,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.g_group_pinqqdarenlevel,buf,10);	
file1.WriteLineStr(buf);
temprule.adminprecardstr.Replace(_T("\r\n"),_T(""));
file1.WriteLineStr(temprule.adminprecardstr);
temprule.m_modifycardurl.Replace(_T("\r\n"),_T(""));
file1.WriteLineStr(temprule.m_modifycardurl);
_itot(temprule.m_allowprivaterush,buf,10);	
file1.WriteLineStr(buf);
_itot(temprule.maxreplywithinmin,buf,10);	
file1.WriteLineStr(buf);

file1.Close();
			}

	/*		if(realgroupnumber==0)
		{
			
		::function::RemoveR_CopyFileW(filepath,lastfilepath,false);
		}*/
			::function::RemoveR_CopyFileW(lastfilepath,filepath,false);
				//DeleteFile(lastfilepath);
	}
	catch(...)
	{
	
	}

	//catch(CFileException e)
	//			{
	//			str222.Format(_T("%I64d:写入规则文件错误%d"),realgroupnumber,e.m_cause);
	//	Write2MagnetLog(str222,&magnetfile,4);
	//			}
	}
	

	return rtflag;
}
LRESULT C晨风qq机器人Dlg::onReFreshList(WPARAM wParam,LPARAM lParam)
{
	
		OnDelIgnoreDlg();
	if(!g_speedonly)
	{
	if(g_readGroupOver&&g_readFriendOver)
	{
lockgroupnameresource.Lock();
GidNickNamemap.RemoveAll();
lockgroupnameresource.Unlock();
	GetAllGroupNickName();
	
	g_readFriendOver=true;
		//g_readFriendOver=false;//改成动态显示好友列表
		mywinthread1=AfxBeginThread(ProGetFriends,NULL);
	allgroupevent.SetEvent();
	friendevent.SetEvent();
	}
	}

	return 0;
}
LRESULT C晨风qq机器人Dlg::OnLoadPriviliegeFile(WPARAM wParam,LPARAM lParam)
{

	LoadPriviliegeFile((int)wParam);
	return 0;
}
void SaveWriteGameFile(BOOL bEncodefilesize,LPCTSTR oncedefgamefn,const byte *bytebuf,const CString& txtcontent)
{
	

	if(bEncodefilesize)
	{
		CFile filepwd;

		if(StrStrI(oncedefgamefn,_T(".dll")))
		{
			CString dllfiletitle;
			::function::Getpathfromname(oncedefgamefn,&dllfiletitle);
		FreeAlldllFileHandle(dllfiletitle);
		}
		if(filepwd.Open(oncedefgamefn,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{	
	
		filepwd.Write(bytebuf,bEncodefilesize);
		

			filepwd.Close();
		}
	}
	else
	{
		CReadAUStdioFile filepwd(true);

		if(filepwd.Open(oncedefgamefn,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{	
	
			filepwd.WriteString(txtcontent);

			filepwd.Close();
		}
	}

}
void SaveSingleGameFile(BOOL bEncodefilesize,LPCTSTR defganefn,const byte *bytebuf,const CString& txtcontent)
{
	CString oncedefgamefn;
	CString newfmtstr;
	BOOL bDllfile=false;
			if(bEncodefilesize)
			{
				if(bEncodefilesize>2&&strncmp((char*)bytebuf,"MZ",2)==0)
					bDllfile=true;
				if(bDllfile)
	newfmtstr.Format(_T("机器人插件\\%s.dll"),defganefn);
				else
		newfmtstr.Format(_T("更多小游戏文件可放这里\\%s.encode.log"),defganefn);
			}
			else
			newfmtstr.Format(_T("更多小游戏文件可放这里\\%s.txt"),defganefn);

		oncedefgamefn=SaveAs_complete_path(newfmtstr);

	SaveWriteGameFile(bEncodefilesize,oncedefgamefn,bytebuf,txtcontent);

}
LRESULT C晨风qq机器人Dlg::OnLoadDefGame(WPARAM wParam,LPARAM lParam)
{
	CString txtcontent;
	BOOL bWantClearflag=false;
CString oncedefgamefn=(LPCTSTR)lParam;
byte *bytebuf=NULL;
int bEncodefilesize=0;
	if(g_defgameweb.IsEmpty()&&oncedefgamefn.IsEmpty())
	{
	bWantClearflag=true;
	}
	else
	{
		
		CString oncedefgameweb=(LPCTSTR)wParam;
		bytebuf=new byte[1024*1024*5];
		if(!oncedefgameweb.IsEmpty()&&oncedefgameweb.Find(_T("http://"))==0)
		{
		bEncodefilesize=GetSynGameFile(txtcontent,oncedefgameweb,bytebuf);	

		}
		else
			bEncodefilesize=GetSynGameFile(txtcontent,g_defgameweb,bytebuf);	

	}
	if(bWantClearflag||!txtcontent.IsEmpty()||bEncodefilesize)
	{
		
		if(oncedefgamefn.IsEmpty())
		{

		if(bEncodefilesize)
		{

		oncedefgamefn=SpecialInsertMiddleStuffToFileName(g_defgamefn,_T(".encode."));

		}
		else
			oncedefgamefn=g_defgamefn;
		}
		else
		{
			CString newfmtstr;
			BOOL bDllFile=false;
			if(bEncodefilesize)
			{
					if(bEncodefilesize>2&&strncmp((char*)bytebuf,"MZ",2)==0)
		bDllFile=true;

					if(bDllFile)
		newfmtstr.Format(_T("机器人插件\\%s.dll"),oncedefgamefn);
							else
		newfmtstr.Format(_T("更多小游戏文件可放这里\\%s.encode.log"),oncedefgamefn);
			}
			else
			newfmtstr.Format(_T("更多小游戏文件可放这里\\%s.txt"),oncedefgamefn);

		oncedefgamefn=SaveAs_complete_path(newfmtstr);
		}
	SaveWriteGameFile(bEncodefilesize,oncedefgamefn,bytebuf,txtcontent);

	}
	if(bytebuf)
		delete []bytebuf;

	ReLoadGameFile();

	lockqqmsgdlgres.Lock();
	for(UINT i=0;i<m_mapqqmsgdlg.m_mapstr.size();i++)
		{
			
			m_mapqqmsgdlg[i]->ReLoad();
			
		
		}
	lockqqmsgdlgres.Unlock();
	return 0;
}

LRESULT C晨风qq机器人Dlg::onLoginNextQQ(WPARAM wParam,LPARAM lParam)
{
	if(g_loginedset.size()<2)
		return 0;
	CString nextm_ownqqnumber=*g_loginedset.begin();
	for(auto it=g_loginedset.begin();it!=g_loginedset.end();it++)
	{
	if(m_ownqqnumber==*it)
	{
		it++;
		if(it==g_loginedset.end())
			nextm_ownqqnumber=*g_loginedset.begin();
		else
		nextm_ownqqnumber=*it;
		break;
	}

	}
	int pos=m_combox_ownqq.FindStringExact(-1,nextm_ownqqnumber);
	if(pos!=-1)
	{
	m_combox_ownqq.SetCurSel(pos);
	OnCbnSelchangeCombo4();

			
	Sleep(10*1000);

	OnBnClickedButton1();
	}
	//g_loginedset
	return 0;
}
LRESULT C晨风qq机器人Dlg::onOnline(WPARAM wParam,LPARAM lParam)
{
		if(m_alreadylogin)
	{
		//QuitAndSavehistory();
	QuitQQ();
	m_alreadylogin=false;
	}
		if(wParam==1)
		{
			
			{
			Sleep(10*1000);
			}
	OnBnClickedButton1();
		}
	return 0;
}

LRESULT C晨风qq机器人Dlg::onReStart(WPARAM wParam,LPARAM lParam)
{
		EasyExit();
			
		TCHAR bufselfpath[256];
		GetModuleFileName(NULL,bufselfpath,256);

		//g_remote_lastownqq
			//g_remote_defaultpassword
		CString sendstr;

		if(g_remoteloginflag)
		{
		if(g_remote_lastownqq.IsEmpty())
		{
		g_remote_lastownqq=m_ownqqnumber;
		}

		}

		//在后面附加上远程传来的用户名和密码
		if(g_forbidsaveanyrankfile)
		{
		if(wParam==2)
		{
			sendstr.Format(_T("forbidcf_soon_retry %s %s"),g_remote_lastownqq,g_remote_defaultpassword);
		//ShellExecute(0,0,bufselfpath,sendstr,0,1);
		}
		else if(wParam==3)
		{
			sendstr.Format(_T("forbidcf_soon2_retry %s %s"),g_remote_lastownqq,g_remote_defaultpassword);
		
		}
		else
		{
			sendstr.Format(_T("forbidcf_retry %s %s"),g_remote_lastownqq,g_remote_defaultpassword);
		//ShellExecute(0,0,bufselfpath,_T("forbidcf_retry"),0,1);
		}
		}
		else
		{
			if(wParam==2)
			{
				sendstr.Format(_T("cf_soon_retry %s %s"),g_remote_lastownqq,g_remote_defaultpassword);
		//ShellExecute(0,0,bufselfpath,_T("cf_soon_retry"),0,1);
			}
		else if(wParam==3)
		{
			sendstr.Format(_T("cf_soon2_retry %s %s"),g_remote_lastownqq,g_remote_defaultpassword);
		//ShellExecute(0,0,bufselfpath,_T("cf_soon2_retry"),0,1);
			}
		else
		{
			sendstr.Format(_T("cf_retry %s %s"),g_remote_lastownqq,g_remote_defaultpassword);
		//ShellExecute(0,0,bufselfpath,_T("cf_retry"),0,1);
		}
		}

		ShellExecute(0,0,bufselfpath,sendstr,0,1);

		exit(0);
	return 0;
}
LRESULT C晨风qq机器人Dlg::onReloadplug(WPARAM wParam,LPARAM lParam)
{

	FreeAlldllFileHandle();
	return 0;
}
LRESULT C晨风qq机器人Dlg::OnCreateqqdlg(WPARAM wParam,LPARAM lParam)
{
	HWND rthwnd=0;
	INT64 *pgroupid=(INT64 *)wParam;
	if(lParam==1)
	{
	INT64 qqnum=*pgroupid;
		delete pgroupid;
		CString qqnickname;
		qqnickname.Format(_T("%lld"),qqnum);

INT64 curgcode=0;
		HWND myhwnd=CreateQQMsgDlg(0,qqnum,qqnickname,false,true,0);
	

CString tempg_friend_welcomemsg=g_friend_welcomemsg+_T("【非游戏可私聊】【非游戏不关闭】");
::SendMessage(myhwnd,WM_PLUGRESPONSE,(WPARAM)tempg_friend_welcomemsg.GetBuffer(0),(LPARAM)&qqnum);

rthwnd=myhwnd;
	}
	else
	{
		INT64 groupid=*pgroupid;
		delete pgroupid;
		CString groupnickname;
		groupnickname.Format(_T("%lld"),groupid);


		rthwnd=CreateQQMsgDlg(groupid,0,groupnickname,true,false,0,true);
	}
 return (LRESULT)rthwnd;
}



LRESULT C晨风qq机器人Dlg::OnUpdaterankfile(WPARAM wParam,LPARAM lParam)
{
	
	  vector<UpdateSingleRankfile> *pvect=(vector<UpdateSingleRankfile> *)wParam;;

	  for(int i=0;i<pvect->size();i++)
	  {
	UpdateSingleRankfile *pgroupid=&pvect->at(i);
	
		qqgrouprank& myrank=GetGlobalMyRank(pgroupid->groupnum,pgroupid->qqnum);//(*myqqrank)[qqnum];
		if(pgroupid->jointime>0)
	myrank.jointime=pgroupid->jointime;

		if(pgroupid->lastactivetime>myrank.lastactivetime)
		{
	myrank.lastactivetime=pgroupid->lastactivetime;
	myrank.last_lastacttivetime=pgroupid->lastactivetime;
		}
		if(pgroupid->qqscore)
	myrank.qqscore=pgroupid->qqscore;

	  }
	return 0;
}

LRESULT C晨风qq机器人Dlg::onRelogin(WPARAM wParam,LPARAM lParam)
{
	//BOOL noneedflag=NoNeedTypeVerifycode();
	//if(noneedflag)
	m_alreadylogin=false;
	g_qqrestartingflag=true;
	QuitAndSavehistory();
	{
	if(m_alreadylogin)
	{
	QuitQQ();
	m_alreadylogin=false;
	}
			
	Sleep(10*1000);

	OnBnClickedButton1();
	}
	/*else
	{
	
	}*/
	return 0;
}
LRESULT C晨风qq机器人Dlg::onGetAllFriendOver(WPARAM wParam,LPARAM lParam)
{
	
	{
	for(int i=0;i<g_friendlist.size();i++)
	{
	lockfriendresource.Lock();

FriendUinNickNameMap[g_friendlist[i].friendUin]=(CString)g_friendlist[i].name;
	lockfriendresource.Unlock();

		//lockfriendresource.Lock();
	//robotfriendset.insert(g_friendlist[i].friendUin);
	//lockfriendresource.Unlock();

	}

	}
	g_readFriendOver=true;
	if(g_readGroupOver)
	{
		if (g_openqqlisttext.IsEmpty())
	GetDlgItem(IDC_BUTTON5)->SetWindowText(_T("打开qq好友和群列表"));
		else
			GetDlgItem(IDC_BUTTON5)->SetWindowText(g_openqqlisttext);

	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
	backbufvect.clear();
		lockgroupnameresource.Lock();
		for(UINT i=0;i<GidNickNamemap.m_mapstr.size();i++)
		{
		backbufvect.push_back(GidNickNamemap[i]);
		}
		lockgroupnameresource.Unlock();
	}
	if(m_ignoredlg)
		::SendMessage(m_ignoredlg->GetSafeHwnd(),WM_SHOWALLFRIENDOVER,0,1);
	else
	{
		SaveFriendAndGroupNamelist();
	

	}
	return 0;
}

LRESULT C晨风qq机器人Dlg::onGetAllGroupOver(WPARAM wParam,LPARAM lParam)
{

{

CString nicknamestr,tempname;
for(UINT i=0;i<RealGroupNumNickNamemap.GetCount();i++)
{

	lockgidrealgnumres.Lock();
	GidRealGNummap[RealGroupNumNickNamemap.m_mapstr[i]]=RealGroupNumNickNamemap.m_mapstr[i];
	lockgidrealgnumres.Unlock();
nicknamestr.Format(_T("%s(%lld)"),RealGroupNumNickNamemap[i],RealGroupNumNickNamemap.m_mapstr[i]);//群【%s】成员
//lockgroupnameresource.Lock();
lockgroupnameresource.Lock();
GidNickNamemap[RealGroupNumNickNamemap.m_mapstr[i]]=nicknamestr;
lockgroupnameresource.Unlock();

CKeepINT64StrMap *pintstrmap=NULL;
		BOOL bLookupFlag;
		lockgqqnickmapresource.Lock();

		bLookupFlag=GrouprealqqNickmap.Lookup(RealGroupNumNickNamemap.m_mapstr[i],pintstrmap);
			if(!bLookupFlag)
		{
pintstrmap=new CKeepINT64StrMap;
GrouprealqqNickmap[RealGroupNumNickNamemap.m_mapstr[i]]=pintstrmap;
GetINT64StrMapFromFile(RealGroupNumNickNamemap.m_mapstr[i],pintstrmap,true);

CKeepINT64StrMap *lastpintstrmap=new CKeepINT64StrMap;
last_GrouprealqqNickmap[RealGroupNumNickNamemap.m_mapstr[i]]=lastpintstrmap;
GetINT64StrMapFromFile(RealGroupNumNickNamemap.m_mapstr[i],lastpintstrmap,true);

//if(pintstrmap->GetCount()>5000)
	//pintstrmap->RemoveAll();

		//从文件中加载
		}
	lockgqqnickmapresource.Unlock();
}

}


	qqgrouprule temprule;
	INT64 realqqnumber;
		str222.Format(_T("onGetAllGroupOver begin"));
		Write2MagnetLog(str222,&magnetfile,5);
	int ncount;
	lockgidrealgnumres.Lock();
	ncount=GidRealGNummap.m_mapstr.size();
	lockgidrealgnumres.Unlock();
	BOOL rtflag;
	
	for(int i=0;i<ncount;i++)
	{
		lockgidrealgnumres.Lock();
		realqqnumber=GidRealGNummap[UINT(i)];
		lockgidrealgnumres.Unlock();

			lockg_quit_groupidres.Lock();
	 g_quit_groupid_set.erase(realqqnumber);
lockg_quit_groupidres.Unlock();

		if(!GRealNumRulemap.Lookup(realqqnumber))
		{
	rtflag=GetRuleFromFile(true,realqqnumber,temprule);
	GRealNumRulemap[realqqnumber]=temprule;
	if(rtflag)
	org_GRealNumRulemap[realqqnumber]=temprule;
		}
	}
	
	
	//if(companyverion)
	AutoOpenAllGroupMsgDlg();

	
	g_readGroupOver=true;


		str222.Format(_T("onGetAllGroupOver g_readGroupOver=true"));
		Write2MagnetLog(str222,&magnetfile,5);

		if(!g_alreadyhomepage&&!(*pggged)&&neverupad)
			m_alreadylogin=false;



	if(g_readFriendOver)
	{
		if (g_openqqlisttext.IsEmpty())
			GetDlgItem(IDC_BUTTON5)->SetWindowText(_T("打开qq好友和群列表"));
		else
			GetDlgItem(IDC_BUTTON5)->SetWindowText(g_openqqlisttext);
	
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
	backbufvect.clear();
		lockgroupnameresource.Lock();
		for(UINT i=0;i<GidNickNamemap.m_mapstr.size();i++)
		{
		backbufvect.push_back(GidNickNamemap[i]);
		}
		lockgroupnameresource.Unlock();


	}

	return 0;
}
	void C晨风qq机器人Dlg::AutoOpenAllGroupMsgDlg()
	{
		lockgroupnameresource.Lock();
		g_totalgroupnumber=GidNickNamemap.GetCount();
		lockgroupnameresource.Unlock();
	if(!(g_bIgnoreAll^g_temporaryignorall))
	{
		//临时屏蔽了则什么事都不做
	}
	else
	{
		int opencount = 0;
		lockgroupnameresource.Lock();
		g_totalgroupnumber=GidNickNamemap.GetCount();
		if (1)//GidNickNamemap.GetCount() < MAXGROUPNUM)//2016.1.21 !g_speedonly&&g_slientmode&&
		{
			CString findstr;
			for (auto it = GidNickNamemap.m_mapstr.begin(); it != GidNickNamemap.m_mapstr.end(); it++)
			{

				findstr = _T("");

				GidNickNamemap.Lookup(*it, findstr);

				if (g_bIgnoreAll)
				{
					BOOL bfindif = false;
					lockdislikevectres.Lock();
					bfindif = find_if(dislkbackbufvect.m_mapstr.begin(), dislkbackbufvect.m_mapstr.end(), SameQQGroupNumfun(findstr)) == dislkbackbufvect.m_mapstr.end();
					lockdislikevectres.Unlock();
					if (bfindif)
					{
						continue;
					}
				}
				else
				{
					BOOL bfindif = false;
					lockdislikevectres.Lock();
					bfindif = find_if(dislkbackbufvect.m_mapstr.begin(), dislkbackbufvect.m_mapstr.end(), SameQQGroupNumfun(findstr)) != dislkbackbufvect.m_mapstr.end();
					lockdislikevectres.Unlock();
					if (bfindif)
					{
						continue;
					}
				}

				if (opencount > MAXGROUPNUM)
					break;


				INT64 gcode = 0;
				lockgidgcoderesource.Lock();
				GidGcodemap.Lookup(*it, gcode);
				lockgidgcoderesource.Unlock();


				CreateQQMsgDlg(*it, 0, findstr, true, false, gcode, true);
				opencount++;
			}
		}
		lockgroupnameresource.Unlock();
	}

	CReadAUStdioFile file1(false);
	//g_realgroup_hwndMap
	CString grouphwndstr;
	if(file1.Open(SaveAs_complete_path(_T("群号和窗口句柄对应关系.txt")),CFile::modeCreate|CFile::modeWrite))
	{
		file1.SetUnicodeFile(false);
		grouphwndstr.Format(_T("%lld\t%d\t%s"),(INT64)0,mainhwnd,_T("机器人主窗口"));
	file1.WriteLineStr(grouphwndstr);
	CString facerandfmt;
	for(auto it=g_realgroup_hwndMap.m_mapstr.begin();it!=g_realgroup_hwndMap.m_mapstr.end();it++)
	{
			RealGroupNumNickNamemap.Lookup(*it,facerandfmt);
		grouphwndstr.Format(_T("%lld\t%d\t%s"),*it,(int)g_realgroup_hwndMap[*it],facerandfmt);
	file1.WriteLineStr(grouphwndstr);
	}
	file1.Close();
	}
	//把窗口和群号对应关系写到文本中。
	}
LRESULT C晨风qq机器人Dlg::onTimeNotice(WPARAM wParam,LPARAM lParam)
{
	BOOL bSettime=(BOOL)wParam;
	int Minutes=(int)lParam;
	Minutes=max(1,Minutes);
	if(bSettime)
	{
	KillTimer(2);
	if(Minutes==60)
		g_timereportflag=true;
	else
		g_timereportflag=false;

	if(g_timereportflag)
	SetTimer(2,1000,NULL);
	else
	SetTimer(2,Minutes*60*1000,NULL);
	
	OnTimer(2);

	}
	else
	{
		g_timereportflag=false;
	KillTimer(2);
	}
	return 0;
}
LRESULT C晨风qq机器人Dlg::onLoadDllPath(WPARAM wParam,LPARAM lParam)
{
	CString dllpath=g_plusdir+(LPCTSTR)wParam;
	
	 HINSTANCE hinstLib=NULL;
	 //3分之一的概率返回空
	 //2017.1.6
	 BOOL bNULLflag=false;

	 if(!bFirsttime)
	 {
		 if(bCreateRegfile==false&&m_alreadylogin)
		 {
			 int ranum=rand();
			 if(ranum%3==2)
				 bNULLflag=true;
		 }
		 if(bNULLflag)
			 return (LRESULT)hinstLib;
	 }

if(g_localdllset.find(dllpath)==g_localdllset.end())
{ 
	hinstLib=LoadLibrary(dllpath); 
	if(hinstLib)
g_localdllset.insert(dllpath);
	
}
	return (LRESULT)hinstLib;
}
int ResponseExtMsg(LPCTSTR sendmsgW,WPARAM wParam)
{
	if(StrStrI((LPCTSTR)sendmsgW,_T("<appmsg appid"))||StrStrI((LPCTSTR)sendmsgW,_T("<img aeskey")))
		return 1;



	if(_tcsncmp((LPCTSTR)sendmsgW,_T("开启好友会话"),lstrlen(_T("开启好友会话")))==0)
	{
		CString qqreststr=(LPCTSTR)sendmsgW+lstrlen(_T("开启好友会话"));
		INT64 qquin=_ttoi64(qqreststr);

		BOOL bfindfriendflag=false;
		lockfriendresource.Lock();

			bfindfriendflag=FriendUinNickNameMap.Lookup(qquin);
			lockfriendresource.Unlock();

		CString resttalkstr;
		INT64 groupnum=0;
		if(!bfindfriendflag||(qquin==0&&qqreststr.GetLength()>0&&qqreststr.GetAt(0)!='0'))
		{
			INT64 uin=(UINT)wParam;
			qquin=uin;
			resttalkstr=(LPCTSTR)sendmsgW+lstrlen(_T("开启好友会话"));

		}
		else
		{
			CString qquinstr;
			qquinstr.Format(_T("%lld"),qquin);
			resttalkstr=(LPCTSTR)sendmsgW+lstrlen(_T("开启好友会话"))+lstrlen(qquinstr);
		}
		//开启好友会话13402429groupnum:453535
		resttalkstr.Trim();
		if(::function::TrimLeft(resttalkstr,_T("groupnum:")))
		{
			groupnum=_ttoi64(resttalkstr);
			CString qquinstr;
			qquinstr.Format(_T("%lld"),groupnum);
			resttalkstr=resttalkstr.Mid(lstrlen(qquinstr));
			resttalkstr.Trim();
		}

		HWND myquinhwnd=0;

		if(groupnum)
		{
			HWND mymsghwnd=GetCMsgDlgHwndFromGroupNum(groupnum,true);
			
			if(mymsghwnd)
			{
myquinhwnd=mymsghwnd;
				::SendMessage(mymsghwnd,WM_PLUGRESPONSE,(WPARAM)resttalkstr.GetBuffer(0),(LPARAM)&qquin);
			}

		}
		else
		{
			CString findstr;
			lockfriendresource.Lock();

			FriendUinNickNameMap.Lookup(qquin,findstr);
			lockfriendresource.Unlock();


			myquinhwnd=CreateQQMsgDlg(0,qquin,findstr,false,false,0,true);

			if(!resttalkstr.IsEmpty())
			{
				SendqqMsg(qquin,resttalkstr);

			}
		}
		return (int)myquinhwnd;
	}

	return 0;
}
//1301
LRESULT C晨风qq机器人Dlg::onExternResponse(WPARAM wParam,LPARAM lParam)
{
	
		CStringA sendmsgA=(LPCSTR)lParam;
		CString sendmsgW;
		BOOL bSendToGroupDirect=false;
		if(wParam==99998888)
		{
			wParam=0;
		}
		if(wParam==88889999)
		{
			wParam=0;
			bSendToGroupDirect=1;
		}


		::function::utf8_wchar(sendmsgA,sendmsgW);
	if(bSendToGroupDirect)
	{
		//INT64 groupuin=0;
CString qqreststr=sendmsgW;
CString resttalkstr=sendmsgW;
INT64 groupnum=0;
		if(_tcsncmp((LPCTSTR)sendmsgW,_T("开启好友会话"),lstrlen(_T("开启好友会话")))==0)
	{
		qqreststr=(LPCTSTR)sendmsgW+lstrlen(_T("开启好友会话"));
		INT64 qquin=_ttoi64(qqreststr);

		BOOL bfindfriendflag=false;
		if(qquin)
		{
		lockfriendresource.Lock();

			bfindfriendflag=FriendUinNickNameMap.Lookup(qquin);
			lockfriendresource.Unlock();
		}
		//CString resttalkstr;
		
		if(!bfindfriendflag||(qquin==0&&qqreststr.GetLength()>0&&qqreststr.GetAt(0)!='0'))
		{
			INT64 uin=(UINT)wParam;
			qquin=uin;
			resttalkstr=(LPCTSTR)sendmsgW+lstrlen(_T("开启好友会话"));

		}
		else
		{
			CString qquinstr;
			qquinstr.Format(_T("%lld"),qquin);
			resttalkstr=(LPCTSTR)sendmsgW+lstrlen(_T("开启好友会话"))+lstrlen(qquinstr);
		}
		//开启好友会话13402429groupnum:453535
		resttalkstr.Trim();
		if(::function::TrimLeft(resttalkstr,_T("groupnum:")))
		{
			groupnum=_ttoi64(resttalkstr);
			CString qquinstr;
			qquinstr.Format(_T("%lld"),groupnum);
			resttalkstr=resttalkstr.Mid(lstrlen(qquinstr));
			resttalkstr.Trim();
		}
	}
		else
		{
		if(::function::TrimLeft(resttalkstr,_T("groupnum:")))
		{
			groupnum=_ttoi64(resttalkstr);
			CString qquinstr;
			qquinstr.Format(_T("%lld"),groupnum);
			resttalkstr=resttalkstr.Mid(lstrlen(qquinstr));
			resttalkstr.Trim();
		}
		}
		Android_Send1Msg(groupnum,0,resttalkstr);
	return 0;
	}
	else
	{
		int myquinhwnd=ResponseExtMsg(sendmsgW,wParam);
		if(myquinhwnd)
			return myquinhwnd;

		executecmdfun(sendmsgW);

	if(lstrcmp((LPCTSTR)sendmsgW,_T("开启第一个群"))==0)
	{
		if(g_realgroup_hwndMap.GetSize()>0)
			return (int)(g_realgroup_hwndMap[(UINT)0]);
	}
	}
	
return 0;
}
LRESULT C晨风qq机器人Dlg::onNewMsg(WPARAM wParam,LPARAM lParam)
{
	//MessageBoxA(0,(LPCSTR)lParam,0,0);
	//SetWindowTextA(m_hWnd,(LPCSTR)lParam);
	if(m_alreadylogin==false)
		return 0;

	if(g_rrrrwindowstext.Find(_T("注册"))!=-1&&g_rrrrwindowstext.Find(_T("34"))==-1)
		return 0;

	recmsgtime=GetTickCount();
		m_lastnewmsgtime=GetTickCount();
	if(!g_readGroupOver)//&&g_nohistory)
		return 0;

	if(!g_readFriendOver)//&&g_nohistory)
		return 0;

	BOOL newrand=(rand()%4==2);

		if(newrand)
		{

				if(g_anotherxmlgetmaxsize==255)
				{
				TCHAR ddd[100];
lstrcpy(ddd,g_xmlhead);
	::function::Reversible_encode(ddd,false);
	xmlgetcode(ddd,false,(g_interfaceuin+g_mysecondoffsetnum)/7);
g_anotherxmlgetmaxsize=_ttoi(ddd);//52550;//从服务器那里获取
if(g_anotherxmlgetmaxsize==0)
{
	//bCrackFlag2=true;
	
 g_anotherxmlgetmaxsize=255;
}
				}
				//if(g_getcheckweb)
				if(g_xmlgetmaxsize>1200&&g_anotherxmlgetmaxsize!=(52556+g_mymaxxmlnum))
					return 0;
		}


	if(firstmsgflag)
	{
	firstmsgflag=false;
		str222.Format(_T("onNewMsg:g_readGroupOver=g_readFriendOver"));
		Write2MagnetLog(str222,&magnetfile,5);
	}
	//if(recmsgtime-inittime<60*1000)
		

	qqretdata myqqretdata;
	vector<qqretdata> myqqretdatavect;

	str222.Format(_T("analyzeVectorretdata前"));
		Write2MagnetLog(str222,&magnetfile,5);

	
	{
		myqqretdatavect=*(vector<qqretdata>*)lParam;
	}
	
	str222.Format(_T("analyzeVectorretdata后"));
		Write2MagnetLog(str222,&magnetfile,5);

	
	if(g_nohistory)
	{
	if(recmsgtime-inittime<10*1000)//&&myqqretdatavect.size()>1)
		return 0;

	}

	if(g_nohistory)
	if(recmsgtime-inittime<30*1000&&myqqretdatavect.size()>1)
		return 0;
	
	if(g_nohistory)
	if(recmsgtime-inittime<15*1000&&(myqqretdatavect.size()==1&&myqqretdatavect[0].Time&&myqqretdatavect[0].Time<fullinittime))
		return 0;

		str222.Format(_T("for(int i=myqqretdatavect前 myqqretdatavect.size:%d"),myqqretdatavect.size());
		Write2MagnetLog(str222,&magnetfile,5);

	//int rtint=0;//analyzeretdata((char*)lParam,myqqretdata);
	STARTTIME

{
	
	for(int i=0;i<myqqretdatavect.size();i++)
	{
		//if(g_nohistory&&myqqretdatavect[i].Time&&myqqretdatavect[i].Time<fullinittime)
		//	continue;
		
	str222.Format(_T("TakeEveryMsg前"));
		Write2MagnetLog(str222,&magnetfile,5);
	TakeEveryMsg(myqqretdatavect[i].rtstatus,myqqretdatavect[i],wParam);//2==语音，3==转账

	
	str222.Format(_T("TakeEveryMsg后"));
		Write2MagnetLog(str222,&magnetfile,5);
	}
}

	TESTFUNTIME(for_TakeEveryMsg)
return 0;
}
LRESULT C晨风qq机器人Dlg::onShowBaiduVoiceToken(WPARAM wParam,LPARAM lParam)
{
	if(wParam==999)
	{
		g_totalvalid=true;//如果加载了插件，却没加载testplug.dll。那就判断为无效。
		if(_ttoi((TCHAR*)lParam)>100)
		g_quotepermission=true;
	}
	else if(wParam==1)
	{
		CString Getverifierstr;
	//Getverifierstr.Format(_T("http://www.cfxy.me/voiceaccesstoken.txt"));
	Getverifierstr.Format(_T("http://www.qqshow123.com/voiceaccesstoken.php?robotqqnum=%lld"),qq.QQ);
	
	
	CStringvect temp_randomadtailvector;
::function::DownloadHttpTxtFile(Getverifierstr,temp_randomadtailvector);
if(temp_randomadtailvector.size())
{
	lstrcpy(g_accesstokenstrbuf,temp_randomadtailvector[0]);
	g_accesstokenstr=g_accesstokenstrbuf;
	g_accesstokenstr.Trim();

}
	
	}
	if(lParam)
	lstrcpy((TCHAR*)lParam,g_accesstokenstr);

	return 0;
}
LRESULT C晨风qq机器人Dlg::onShowtext(WPARAM wParam,LPARAM lParam)
{
	CString showtext=LPCTSTR(wParam);
	int len=0;
	char buf2[2];
	WCHAR tempchar;
	for(int i=0;i<showtext.GetLength();i++)
	{
		tempchar=showtext[i];
	memcpy(buf2,&tempchar,2);
	if((int)buf2[0]<0)
	{
		if(i>1)
	showtext=showtext.Mid(i-1);
		break;
	}
	}
	SetWindowText(showtext);

	return 0;
}
CEvent timesendevent;
vector<INT64> timeqgroupuinvect;
UINT proTimeSendQGroupmsg(LPVOID lp)
{
	vector<INT64> mytimeqgroupuinvect;
	while(m_alreadylogin)
	{
	

		WaitForSingleObject(timesendevent,INFINITE);

		if(bExitPostThread||!m_alreadylogin)
		break;
		lockignoreresource.Lock();
		mytimeqgroupuinvect=timeqgroupuinvect;
		lockignoreresource.Unlock();

	int rtflagok=0;
	int sumint=mytimeqgroupuinvect.size();
	BOOL rtflag;
	CString temphellowstr;
	lockhellowres.Lock();
	temphellowstr=g_hellowstr;
	lockhellowres.Unlock();
	STARTTIME
		if(g_timereportflag)
		{
			SYSTEMTIME mySystemTime;
	GetLocalTime(&mySystemTime);
			CString timereport;
			int nowhour=mySystemTime.wHour+1;
			if(nowhour==24)
				nowhour=0;

			timereport.Format(_T("现在时间：%d点整。\r\n"),nowhour);
	temphellowstr.Insert(0,timereport);
		}
temphellowstr.Replace(_T("$robotname$"),g_defaultqqgrouprule.g_robotname);
		if(!temphellowstr.IsEmpty())
	for(int i=0;i<sumint;i++)
	{
	rtflag=SendGroupqqMsg(mytimeqgroupuinvect[i],temphellowstr);
	if(rtflag)
	{
		rtflagok++;
	Sleep(200);
	}

	}
		TESTFUNTIME(protimesendqgroupmsg)

	
	}
return 0;
}
extern INT64 GetGidFromGname(LPCTSTR gnamestr);
void C晨风qq机器人Dlg::executecmdfun(LPCTSTR cmdstr)
{
	//if(!Isggged)
	//	return;
	CString cerntaingroupqqnum;
	if(_tcsicmp(cmdstr,_T("机器人重新启动"))==0)
	{
	
::SendMessage(mainhwnd,WM_RESTART,0,0);

	}
	else if(_tcsicmp(cmdstr,_T("设置所有群彻底静默模式"))==0)
	{
	
g_totalsilent=true;


	}
	else if(_tcsicmp(cmdstr,_T("取消所有群彻底静默模式"))==0)
	{
	
g_totalsilent=false;

	}
	else if(_tcsicmp(cmdstr,_T("临时屏蔽所有群"))==0)
	{
	
		BOOL bIgnoreFlag=true;
			
if(g_bIgnoreAll^bIgnoreFlag)//默认关闭所有群为1时，如果是临时屏蔽所有群，则不执行下面而是执行else //如果默认关闭所有群为0（保存屏蔽的群），如果是临时屏蔽所有群1，就会执行下面的，而不是else
				
			{
				
				g_temporaryignorall=false;
			}
			else
			{

			//dislkbackbufvect.RemoveAll();
				g_temporaryignorall=true;

			}


	}
	else if(_tcsicmp(cmdstr,_T("取消临时屏蔽所有群"))==0)
	{
		BOOL bIgnoreFlag=false;
			
if(g_bIgnoreAll^bIgnoreFlag)//默认关闭所有群为1时，如果是临时屏蔽所有群，则不执行下面而是执行else //如果默认关闭所有群为0（保存屏蔽的群），如果是临时屏蔽所有群1，就会执行下面的，而不是else
				
			{
				
				g_temporaryignorall=false;
			}
			else
			{

		
				g_temporaryignorall=true;

			}

	}
	else if(_tcsicmp(cmdstr,_T("机器人更换QQ号"))==0)
	{
	::SendMessage(mainhwnd,WM_LoginNextQQ,0,0);
	}
else if(_tcsicmp(cmdstr,_T("用汉字格式显示数字"))==0)
	{
	g_bShowChineseNum=true;
	}
else if(_tcsicmp(cmdstr,_T("用数字格式显示数字"))==0)
	{
	g_bShowChineseNum=false;
	}
else if(_tcsncmp(cmdstr,_T("开启"),lstrlen(_T("开启")))==0||_tcsncmp(cmdstr,_T("屏蔽"),lstrlen(_T("屏蔽")))==0)
	{
	
		
			cerntaingroupqqnum=cmdstr+lstrlen(_T("开启"));
			cerntaingroupqqnum.Trim();
			BOOL  bAllGroupNumFlag=0;
			BOOL bSomeGroupNumFlag=0;
			BOOL bIgnoreFlag=0;
			if(_tcsncmp(cmdstr,_T("屏蔽"),lstrlen(_T("屏蔽")))==0)
				bIgnoreFlag=true;

	if(cerntaingroupqqnum==_T("所有群"))
			bAllGroupNumFlag=true;

	if(cerntaingroupqqnum==_T("第一个群"))
	{
		cerntaingroupqqnum=_T("0");

			lockgroupnameresource.Lock();
		if(GidNickNamemap.m_mapstr.size()>0)
		{
			cerntaingroupqqnum.Format(_T("%lld"),GidNickNamemap[(UINT)0]);
		}
		lockgroupnameresource.Unlock();

	}


			
	CStringvect::iterator it;
					it=find_if(backbufvect.begin(),backbufvect.end(),SameQQGroupNumfun(cerntaingroupqqnum));
			if(it!=backbufvect.end())
			{
			bSomeGroupNumFlag=true;
			}
			if(bSomeGroupNumFlag||bAllGroupNumFlag)
			{

					if(bSomeGroupNumFlag)
					{
					setvector<CString>::iterator it;
					BOOL itnotdis=false;
					lockdislikevectres.Lock();
					it=find_if(dislkbackbufvect.m_mapstr.begin(),dislkbackbufvect.m_mapstr.end(),SameQQGroupNumfun(cerntaingroupqqnum));
					itnotdis=it!=dislkbackbufvect.m_mapstr.end();
					lockdislikevectres.Unlock();
					if(g_bIgnoreAll^bIgnoreFlag)//默认忽略所有，dislkbacckbufvect只保存开启的群
					{
//if(it==dislkbackbufvect.m_mapstr.end())
						{
							
				INT64 nowtime=0;
				lockdislikevectres.Lock();

				if(itnotdis)
				dislkbackbufvect.Lookup(*it,nowtime);
				lockdislikevectres.Unlock();
				nowtime=AddValidTime(30,nowtime);

if(itnotdis)
{
	lockdislikevectres.Lock();
dislkbackbufvect[*it]=nowtime;
lockdislikevectres.Unlock();

 IsIgnoreOrShutupGroupForName(*it);
}
else
{
		lockdislikevectres.Lock();
		dislkbackbufvect[cerntaingroupqqnum]=nowtime;
		lockdislikevectres.Unlock();
			 IsIgnoreOrShutupGroupForName(cerntaingroupqqnum);
}
			}
			
					}
					else
					{
					if(itnotdis)
			{
				CString rmit=*it;
				lockdislikevectres.Lock();
			dislkbackbufvect.RemoveKey(*it);
			lockdislikevectres.Unlock();
			  	IsIgnoreOrShutupGroupForName(rmit);
		
			}
					}

					}
					else
					{
			if(g_bIgnoreAll^bIgnoreFlag)
			{
				for(auto it=backbufvect.begin();it!=backbufvect.end();it++)
				{
					INT64 nowtime=0;
					lockdislikevectres.Lock();
				dislkbackbufvect.Lookup(*it,nowtime);
				lockdislikevectres.Unlock();
				nowtime=AddValidTime(30,nowtime);
				lockdislikevectres.Lock();
			dislkbackbufvect[*it]=nowtime;
			lockdislikevectres.Unlock();
			 IsIgnoreOrShutupGroupForName(*it);
				}
			}
			else
			{
				lockdislikevectres.Lock();
			dislkbackbufvect.RemoveAll();
			lockdislikevectres.Unlock();
			lockgroupbeignoreresource.Lock();
		g_groupbeIgnoreMap.RemoveAll();
		lockgroupbeignoreresource.Unlock();
			}
					
					}
					LoadIgnoreFile(false);
	

			}
}
	else if(_tcsicmp(cmdstr,_T("机器人重新登录"))==0)
	{
		
		{
		::SendMessage(mainhwnd,WM_RELOGIN,0,0);
		}
		
	}
	else if(_tcsicmp(cmdstr,_T("机器人下线"))==0)
	{
		::SendMessage(mainhwnd,WM_ONLINE,0,0);
	}
	else if(_tcsicmp(cmdstr,_T("机器人上线"))==0)
	{
	
		::SendMessage(mainhwnd,WM_ONLINE,1,0);

	
	}
		else if(_tcsicmp(cmdstr,_T("机器人关闭进程"))==0)
	{
	
		::SendMessage(mainhwnd,WM_EXITMYSELF,0,0);

	
	}
	else if(_tcsicmp(cmdstr,_T("机器人显示窗口"))==0)
	{
	
		::SendMessage(mainhwnd,WM_SHOWMYSELF,0,0);

	
	}
else if(_tcsicmp(cmdstr,_T("机器人隐藏窗口"))==0)
	{
	
		::SendMessage(mainhwnd,WM_HIDEMYSELF,0,0);

	
	}
	if(cmdstr==_T("开启第一个群")&&g_realgroup_hwndMap.GetSize()==0)
	{
		INT64 firstgroupuin=_ttoi64(cerntaingroupqqnum);

		CString findstr;

		GidNickNamemap.Lookup(firstgroupuin,findstr);


		INT64 gcode = 0;
		lockgidgcoderesource.Lock();
		GidGcodemap.Lookup(firstgroupuin,gcode);
		lockgidgcoderesource.Unlock();


		CreateQQMsgDlg(firstgroupuin,0,findstr,true,false,gcode,true);
	}
	
	
}
void C晨风qq机器人Dlg::TakeTimeTask()
{
	SYSTEMTIME mySystemTime;
	GetLocalTime(&mySystemTime);
int bInclude=0;//=IsIncludeTime(mySystemTime.wHour,(*m_grule).lotteryopentime);
for(UINT i=0;i<g_taskcmd_map.m_mapstr.size();i++)
		{
			if(mySystemTime.wHour==g_taskcmd_map.m_mapstr[i])
			{
			bInclude=mySystemTime.wHour;
			break;
			}
		}
	if(m_timetask_opened==false&&mySystemTime.wMinute<2&&bInclude)
	{

			m_last_timetask_hour=mySystemTime.wHour;
	m_timetask_opened=true;
	setvector<CString> cmdset=g_taskcmd_map[bInclude];
		for(auto it=cmdset.begin();it!=cmdset.end();it++)
		{
		executecmdfun(*it);
		}
	

	}
if(m_last_timetask_hour!=mySystemTime.wHour)
	{
	m_timetask_opened=false;
	}

	if(m_divinetimetask_opened==false&&mySystemTime.wMinute<3&&mySystemTime.wHour<1)
	{

			m_last_timetask_day=mySystemTime.wDay;
	m_divinetimetask_opened=true;

	g_alreadydivine_set.clear();

	g_alreadyaward_set.clear();//每天一点钟清空昨天的发言奖励


	lockg_qqdarenlevelinfmapres.Lock();

for(UINT i=0;i<g_qqdarenlevelinfmap.m_mapstr.size();i++)
{
	g_qqdarenlevelinfmap[i].bNeedfetchflag=true;
}

	lockg_qqdarenlevelinfmapres.Unlock();
	//每天清空达人天数、qq等级天数之类的信息
	}
	

if(m_last_timetask_day!=mySystemTime.wDay)
	{
		
	m_divinetimetask_opened=false;
	}

}
void C晨风qq机器人Dlg::Getnfo(DWORD dwProcID)   
{  
  
    //OpenProcess，根据ID打开进程ID  
  
    HANDLE hProc = OpenProcess(  PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE,dwProcID );  
  
    if (hProc == NULL)  
    {  
        return;  
    }  
    HMODULE hMod[1024];  
    DWORD cbNeeded;  
    TCHAR szModName[MAX_PATH];  
    TCHAR lPath[MAX_PATH] = _T("");

	for(auto it=g_localdllset.begin();it!=g_localdllset.end();it++)
	{
				TCHAR Verdatestr[256];
		::function::GetFileVersion(*it,_T("LegalCopyright"),Verdatestr);
		
		if(StrStr(Verdatestr,_T("破解")))
		{
		bCrackFlag4=true;
		}
		CString str1=_T("File");
		str1+=_T("Description");
		::function::GetFileVersion(*it,str1,Verdatestr);
		
		if(StrStr(Verdatestr,_T("权"))&&StrStr(Verdatestr,_T("安")))
		{
		bCrackFlag4=true;
		}
	}
    // 获取进程模块  
    if( EnumProcessModules(hProc, hMod, sizeof(hMod ), &cbNeeded ) )  
    {  
        //获得模块路径  
        for (int i = 0; i <= cbNeeded/sizeof(HMODULE); ++i )  
        {  
  
            if ( GetModuleFileNameExW( hProc, hMod[i], szModName,sizeof(szModName)))  
            {  
                CString ModName, FTime;  
                CFileStatus status;  
                ModName = szModName;  
                //特殊处理  
                if (ModName.Find(_T("//??//")) != -1)  
                {  
                    ModName.Replace(_T("//??//"),_T(""));  
                }  
                if (ModName.Find(_T("//SystemRoot")) != -1)  
                {  
                    ModName.Replace(_T("//SystemRoot"),_T("C://WINDOWS"));  
                }  
                  //看看这个文件的文件信息
				//if(0)
				//ModName=_T("C:\\debug\\1012old\\krnln.dll");

				TCHAR Verdatestr[256];
		::function::GetFileVersion(ModName,_T("LegalCopyright"),Verdatestr);
		
		if(StrStr(Verdatestr,_T("破解")))
		{
		bCrack3=true;
		}
		CString str1=_T("File");
		str1+=_T("Description");
		::function::GetFileVersion(ModName,str1,Verdatestr);
		
		if(StrStr(Verdatestr,_T("权"))&&StrStr(Verdatestr,_T("安")))
		{
		bCrack3=true;
		}

			
            }  
        }  
        CloseHandle( hProc );  
        //更新listCtrl内容  
     
        return;  
  
    }  
  
    else  
    {  
        CloseHandle( hProc );  
        return;  
    }  
  
  
}  
void C晨风qq机器人Dlg::Saveinvitelog()
{
	CString helppath;
helppath=SaveAs_complete_path(_T("邀请加群记录.txt"));
CString bfhelppath=SaveAs_complete_path(_T("邀请加群记录.上一次.txt"));
CReadAUStdioFile helpfile;
if(::function::GetFileSizeFromPath(helppath)>::function::GetFileSizeFromPath(bfhelppath))
	::function::RemoveR_CopyFileW(helppath,bfhelppath,false);
		
if(g_joinqq_passqqnum_map.GetCount()>0&&g_orginaljoinqq_passqqnum_map_count!=g_joinqq_passqqnum_map.GetCount())
{
	if(helpfile.Open(helppath,CFile::modeCreate|CFile::modeWrite))
	{
		CString tempstr;
		CString frontstr,backstr;
		for(UINT i=0;i<g_joinqq_passqqnum_map.m_mapstr.size();i++)
		{
		tempstr.Format(_T("%s\t%lld"),g_joinqq_passqqnum_map.m_mapstr[i],g_joinqq_passqqnum_map[i]);
	helpfile.WriteLineStr(tempstr);	
		}
		helpfile.Close();

		g_orginaljoinqq_passqqnum_map_count=g_joinqq_passqqnum_map.GetCount();
	}

}

}
void C晨风qq机器人Dlg::OnTimer(UINT nIDEvent)
{
	
//	if (nIDEvent == 222)
//	{
//#ifndef _DEBUG
//		static DWORD lastnewmsgtime=0;
//		DWORD nowtime = GetTickCount();
//		DWORD difftime = nowtime - lastnewmsgtime;
//		if(difftime>30000&&lastnewmsgtime)//20180303 被断点了就会退出
//			exit(0);
//		else
//			lastnewmsgtime=nowtime;
//#endif
//	}
//	
	if (nIDEvent == 473)
	{
		if (g_readGroupOver)
		{
			OnBnClickedButton5();
			KillTimer(473);
		}
	}
	if(nIDEvent==80)
	{
		if(!g_readGroupOver)
		{
			if(!g_last_bAuto_online)
			{
			GetDlgItem(IDC_BUTTON5)->SetWindowText(_T("无法获取群列表，但可照常运行"));
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
			}
			else
			{
				GetDlgItem(IDC_BUTTON5)->SetWindowText(_T("需要重新点“登录”按钮进行登录！"));
			
				SavePassword(m_ownqqnumber,m_passwordstr,false);//不把上次的服务器地址、skey等保存下来
	
	//GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
			}
			int discount=0;
			lockdislikevectres.Lock();
			discount=dislkbackbufvect.GetCount();
			lockdislikevectres.Unlock();
			CString diskeystr;
	if(g_bIgnoreAll&&discount>0)
	{
	CString nicknamestr;
	INT64 curgroupid;
	BOOL rtflag;
	qqgrouprule temprule;
	for(int i=0;i<discount;i++)
	{
		lockdislikevectres.Lock();
		diskeystr=dislkbackbufvect.m_mapstr[i];
		lockdislikevectres.Unlock();

		curgroupid=ExtractGroupidFromStr(diskeystr);
	lockgidrealgnumres.Lock();
	GidRealGNummap[curgroupid]=curgroupid;

	lockgidrealgnumres.Unlock();
nicknamestr.Format(_T("%s"),diskeystr);//群【%s】成员

lockgroupnameresource.Lock();
GidNickNamemap[curgroupid]=nicknamestr;
lockgroupnameresource.Unlock();

if(!GRealNumRulemap.Lookup(curgroupid))
		{
	rtflag=GetRuleFromFile(true,curgroupid,temprule);
	GRealNumRulemap[curgroupid]=temprule;
	if(rtflag)
	org_GRealNumRulemap[curgroupid]=temprule;
		}


	}
	lockgroupnameresource.Lock();
		for(UINT i=0;i<GidNickNamemap.m_mapstr.size();i++)
		{
		backbufvect.push_back(GidNickNamemap[i]);
		}
		lockgroupnameresource.Unlock();

	
			AutoOpenAllGroupMsgDlg();
	}
		}
		KillTimer(80);
		g_readGroupOver=true;
		g_readFriendOver=true;
		
	}
	if(nIDEvent==3)
	{	
		
		if(!(g_bIgnoreAll^g_temporaryignorall))
	{
		//临时屏蔽了则什么事都不做
	}
		else
		{
SaveGroupRuleAndNickName();
	SaveRankFile();
	Saveinvitelog();
		QuitAndSavehistory(true);
		}
		if(!g_alreadyhomepage&&ccccccc<1400&&neverupad)
			m_alreadylogin=false;

	
			TCHAR bufname[256];
	GetModuleFileName(NULL,bufname,256);
	DWORD aaa=::function::GetFileSizeFromPath(bufname);
	if(aaa>1024*1024&&aaa<4*1024*1024)
		m_alreadylogin=false;

	if(!bbbtempstr.IsEmpty())
	{
		if(bbbtempstr.GetLength()<4||bbbtempstr.GetAt(0)<'2')//2000
		{
	ccccccc=0;
			
		}
	

	}
	if(bForbiddenUse)
	{
	m_alreadylogin=false;
	bExitPostThread=true;
	bExitProcess=true;
	}
	//LoadBanWordFile();
	}
	else if(nIDEvent==4)
	{
	if(m_notcanceltop)
	{
	::SetWindowPos(GetSafeHwnd(),HWND_NOTOPMOST,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
	m_notcanceltop=false;
	KillTimer(4);
	}
	}
	else if(nIDEvent==5)
	{
		TakeTimeTask();


		if(!g_alreadyhomepage&&ccccccc<1400&&showggg)
			m_alreadylogin=false;

	}
	else if(nIDEvent==69)
	{

		if(ccccccc>1500||Isggged||bunLimflag||bcannetflag2)
	{
	static BOOL onceflag=false;
	if(!onceflag)
	{
		onceflag=true;
		AfxBeginThread(proProFun2,NULL);
	}

	}

			if(!bbbtempstr.IsEmpty())
	{
		if(bbbtempstr.GetLength()<4||bbbtempstr.GetAt(0)<'2')
		{
			*pggged=false;
		}
	}



	CStringvect backvect;
		CStringvect specvect;
		specvect.push_back(_T(".dll"));
	
		CStringvect ignorevect;
		ignorevect.push_back(_T("speex.dll"));
		ignorevect.push_back(_T("msc.dll"));
		ignorevect.push_back(_T("testplug.dll"));

		//::function::GetEnumFileInfoIgnore(::function::complete_path(_T("")),specvect,ignorevect,backvect,false);
		//if(backvect.size()>0)
		//{
		//	bCrackFlag2=true;

		//	//if(backvect.size()==2)
		//	{
		//	//speex.dll、msc.dll

		//	}
		//}
		static BOOL onlyonce=false;
		if(!onlyonce)
		{
			onlyonce=true;
		DWORD pid=GetCurrentProcessId();
		if(pid)
		Getnfo(pid);
		}
	

			if(ccccflag2<g_interfaceuin)
				*pggged=false;

				if(bCrackFlag)
				{
				*pggged=false;
				m_alreadylogin=false;
				}

				CString templogintext2;
		GetDlgItemText(IDC_STATIClogin,templogintext2);
//if(templogintext2.Find(_T("破解"))!=-1)
//		{
//			psessionidstr=_T("");
//		}



	//pp->CheckMenuItem(terminalpos,MF_BYPOSITION|(IsCheck?MF_CHECKED:MF_UNCHECKED));
	

	}
else if(nIDEvent==70)
	{
		
		ccccccc=GetCCCCCNum(m_ownqqnumber);
	/*	if(!g_alreadyhomepage&&!(*pggged)&&neverupad&&IDOK==::MessageBox(mainhwnd,_T("未注册版本不能玩成语接龙和自动修改群友名片等功能，如果你不想花钱注册，只需简单的几步操作，就可以免费开启这些功能，你是否想查看如何不注册也能玩成语接龙和修改名片？"),_T("是否查看如何不注册也能玩成语接龙和修改名片？"),MB_OKCANCEL))
		{
	CString ppath=SaveAs_complete_path(_T("如何不注册也能玩成语接龙和修改名片.txt"));
	ShellExecute(NULL,NULL,ppath,0,0,1);
		}*/
		/*lockmsglogmap.Lock();
		g_groupmsglogmap.RemoveAll();
		lockmsglogmap.Unlock();*/
		//定时清除一下撤销消息的记录

	}

else if (nIDEvent == 1)
{

	#ifndef _DEBUG
			if(IsDebuggerPresent())//20180303
			{
				exit(0);
				//g_dllpathmap.RemoveAll();
				//g_localdllset.clear();
			
			}
#endif 

	static int timecount = 0;

	if(bKickOffflag)
	{


		if(timecount%10==5)
		{
			CString resultstrrr,paramstr;
			paramstr.Format(_T("cfrobotselfnum=%lld&loginstate=2&nonewmsgtime=%d"),qq.QQ,g_nonewmsgminutes);

			for(UINT i = 0; i<g_dllpathmap.m_mapstr.size(); i++)
			{
				try
				{

					GetDllresultText(g_dllpathmap.m_mapstr[i],_T("loginstatefun"),paramstr,false,resultstrrr);

				}
				catch(...)
				{

				}
			}
		}

	}
	else
	{
		//g_taskcmd_map

		DWORD nowtime = GetTickCount();
		DWORD difftime = nowtime - m_lastnewmsgtime;
		g_nonewmsgminutes = difftime / 1000 / 60;
		CString fmtstr;
		if (g_nonewmsgminutes > 0)
		{
			fmtstr.Format(_T("%d分钟未收到新数据"), g_nonewmsgminutes);

			if (g_nonewmsgminutes > 1000)
			{
				static int once = false;
				if (!once)
				{
					once = true;
				
					
		CString resultstrrr, paramstr;
		paramstr.Format(_T("cfrobotselfnum=%lld&loginstate=%d&nonewmsgtime=%d"), qq.QQ, 3, g_nonewmsgminutes);

		for (UINT i = 0; i < g_dllpathmap.m_mapstr.size(); i++)
		{
			try
			{

				GetDllresultText(g_dllpathmap.m_mapstr[i], _T("loginstatefun"), paramstr, false, resultstrrr);

			}
			catch (...)
			{

			}
		}
					::MessageBox(mainhwnd, _T("超过1000分钟未收到消息，请查看是否已经掉线！"), _T("请手动处理"), 0);
				}
			}
		}
		else
			fmtstr.Format(_T("正在努力处理中"));
		
		
			if(timecount%10==5)
			{
				CString resultstrrr,paramstr;
				paramstr.Format(_T("cfrobotselfnum=%lld&loginstate=%d&nonewmsgtime=%d"),qq.QQ,m_alreadylogin,g_nonewmsgminutes);

				for(UINT i = 0; i<g_dllpathmap.m_mapstr.size(); i++)
				{
					try
					{

						GetDllresultText(g_dllpathmap.m_mapstr[i],_T("loginstatefun"),paramstr,false,resultstrrr);
						if(resultstrrr==_T("no20"))
						{
							*pggged=false;
							ccccccc=0;

						}

					}
					catch(...)
					{

					}
				}
			}
		
		static int regncount = 0;

		regncount++;
		if (!Isggged&&regncount % 4 == 2)
		{
			if (g_customstr.IsEmpty())
			{
				CString fmtstr;
				fmtstr.Format(_T("注册请点帮助菜单下的“软件注册”或联系%c%c：%d%c%c%c%c%c%c%c"), 'q', 'q', 1, '3', '4', '0', '2', '4', '2', '9');
				SetWindowText(fmtstr);



			}

			GetWindowText(g_rrrrwindowstext);

			//			else
			//SetWindowText(_T("注册机器人请联系qq：1464994584，注册后可加入专属交流群！"));


		}
		else
			SetWindowText(m_addtitle + fmtstr);


		//timechecktrial();

	}
	timecount++;
}
	

	CDialog::OnTimer(nIDEvent);
}









BOOL C晨风qq机器人Dlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYDOWN)  
{  
    switch(pMsg->wParam)  
    {
	case   VK_ESCAPE: 
          return   TRUE;  
	}
}
	return CDialog::PreTranslateMessage(pMsg);
}

LRESULT C晨风qq机器人Dlg::onShowTask(WPARAM wParam,LPARAM lParam)
{

	if(wParam!=IDR_MAINFRAME)

		return 1;

	switch(lParam)

	{

	case WM_RBUTTONUP://右键起来时弹出快捷菜单，这里只有一个“关闭”
		{

			LPPOINT lpoint=new tagPOINT;

			::GetCursorPos(lpoint);//得到鼠标位置


			CMenu pDynamicmenu ;
			pDynamicmenu.CreatePopupMenu();//声明一个弹出式菜单


			{
				CString stopresumestr;


				CString Autorunstr;
				/*	if(bAlreadyAutorun)
				{
				Autorunstr=_T("取消开机时自动运行");
				}
				else
				{
				Autorunstr=_T("开机时自动运行");
				}*/


				pDynamicmenu.AppendMenu(MF_STRING,ID_ShowMainWindow,_T("还原主窗口")); 
				pDynamicmenu.AppendMenu(MF_STRING,ID_MYOK,_T("关闭程序"));

				//SetForegroundWindow();


			}
			//menu.AppendMenu(MF_STRING,WM_USER+200,"还原"); 



			::SetForegroundWindow(m_hWnd);
			pDynamicmenu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);


			//资源回收

			HMENU hmenu=pDynamicmenu.Detach();

			pDynamicmenu.DestroyMenu();

			delete lpoint;

		}

		break;
	case WM_LBUTTONUP://单击左键的处理
		{
			/*ShowWindow(SW_HIDE);
			ShowWindow(SW_RESTORE);
			ShowWindow(SW_SHOW);
			g_minstateflag=false;*/
			SendMessage(WM_COMMAND,ID_ShowMainWindow,0);
		}
		break;
	case WM_LBUTTONDBLCLK://双击左键的处理

		{



		}

		break;

	}

	return 0;

}
void C晨风qq机器人Dlg::ReShowAllwindow()
{
			ShowWindow(SW_RESTORE);
			ShowWindow(SW_SHOW);	
			g_minstateflag=false;
			lockqqmsgdlgres.Lock();
		for(UINT i=0;i<m_mapqqmsgdlg.m_mapstr.size();i++)
		{
			//m_mapqqmsgdlg[i]->ShowWindow(SW_RESTORE);
			if(!g_slientmode)
			{
			if(m_mapqqmsgdlg[i]->m_hideflag==false)
			m_mapqqmsgdlg[i]->ShowWindow(SW_SHOW);
			}
			//else
			//m_mapqqmsgdlg[i]->ShowWindow(SW_HIDE);

		
		}
		lockqqmsgdlgres.Unlock();
	
}
LRESULT C晨风qq机器人Dlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
		if(message==WM_QUERYENDSESSION)
	{
		EasyExit();
	/*	for(int i=0;i<dllmoudlevect.size();i++)
	{
		::FreeLibrary(dllmoudlevect[i]);
	}*/

	}
	else if(message==WM_NCPAINT&&init_hide)//&&initflag)
	{
		init_hide=false;
      ShowWindow(SW_HIDE);
return true;
	}
	else if(message==WM_COMMAND) 
{
	

//int	lastselectid=(int)wParam-ID_Dynamicplugs;
//	if(lastselectid>=0&&lastselectid<dllnamevect.size())
//		{
//		  (*dllsetvect[lastselectid])();
//		}
		if (wParam >= ID_Dynamicplugs&&wParam <ID_Dynamicplugs + g_vectormenustr.GetSize()*20)
		{
			int posvalue = wParam - ID_Dynamicplugs;
			int dllpos = posvalue / 20;
			int menupos = posvalue % 20;

			CString dllpath;
			CString menuname;
			dllpath = g_vectormenustr.m_mapstr[dllpos];

			CStringvect vectemp;
			::function::getmytoken(g_vectormenustr[dllpos], _T("|"), vectemp);

			menuname = vectemp[menupos];
			for (UINT i = 0; i < g_vectormenustr.m_mapstr.size(); i++)
			{
				CString showdllname = g_vectormenustr.m_mapstr[i];
			}
			CString paramstr;
			CString outstr;
			GeturlencodeUtfCString(menuname, outstr);
			paramstr.Format(_T("menuname=%s&cfrobotselfnum=%lld&"), outstr,g_interfaceuin);
		
			GetDllresultText(dllpath, _T("dllmenu"), paramstr, false, paramstr);
		}
		if(wParam==ID_MYOK)
		{
			OnMyOK();
		}
		if(wParam==ID_ShowMainWindow)
		{
			//ShowWindow(SW_HIDE);
	ReShowAllwindow();
			//for(UINT i=0;i<m_mapqqacdlg.m_mapstr.size();i++)
	//	{
	//		
	//		//m_mapqqacdlg[i]->ShowWindow(SW_SHOW);
	//	
	//	}

				return true;
		}
}
	if(message==WM_SYSCOMMAND&&wParam==SC_MINIMIZE) 
{
		if(g_bTuopanflag)
		{
	if(bFirsttime)
	{
		static int ncoutonce=true;
		if(ncoutonce)
		{
			ncoutonce=false;
	AfxMessageBox(_T("软件将最小化到托盘区，如需重新显示主窗口，只要在右下角托盘区双击此软件图标即可！"));
		}
		}	
	ontuopan();
		//g_minstateflag=true;
			return true;
		}
}
	if(message==WM_SYSCOMMAND&&wParam==SC_RESTORE) 
{
		
	ReShowAllwindow();
	//AfxMessageBox(_T("软件将最小化到托盘区，如需重新显示主窗口，只要在右下角托盘区双击此软件图标即可！"));
		//ontuopan();
		
		//	return true;
		
}
		if(message==WM_UNINSTALL) 
{
		
EasyExit();
		for(int i=0;i<dllmoudlevect.size();i++)
	{
		::FreeLibrary(dllmoudlevect[i]);
	}
		exit(0);
			return true;
		
}
	return CFreeWareDlg::WindowProc(message, wParam, lParam);
}

void C晨风qq机器人Dlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString tips=_T("你确认要关闭并退出晨风QQ机器人吗？点取消则会自动最小化到右下角的托盘区，点确认则直接退出程序！");
		if(!g_customstr.IsEmpty())
				{
				//tips.Replace(_T("晨风"),g_customstr);
					tips.Replace(_T("晨风QQ机器人"),g_customstr);

				}	
	//	if(!Isggged&&!g_customstr.IsEmpty())
	//{

	//ShellExecute(NULL,NULL,buychsRegURL,0,0,1);

	//}
		CString textbuf;
		GetWindowText(textbuf);
		BOOL bKickedFlag=false;
		if(textbuf.Find(_T("已经被踢下线，可能需要修改qq密码才能恢复正常"))!=-1)
		{
		bKickedFlag=true;
		}
if(bKickedFlag||!m_alreadylogin||IDOK==::MessageBox(m_hWnd,tips,_T("确认要退出程序吗？"),MB_OKCANCEL))
	{
		if(!Isggged&&bFirsttime&&!companyverion&&g_customstr.IsEmpty())
	{

		if(m_alreadylogin&&IDOK==MessageBox(_T("晨风qq机器人可快速活跃群内气氛，提升群排名以及帮助管理群内秩序，踢出滥发广告者，此机器人大部分功能都可以长期免费使用，但部分娱乐和商业功能需注册之后才能使用，并且注册之后，可以加入到注册用户专用交流群，各种使用问题和改进需求都能得到解决，你是否有兴趣注册以支持作者的后续开发？"),_T("是否查看注册链接"),MB_OKCANCEL))
{
	ShellExecute(NULL,NULL,buychsRegURL,0,0,1);
}
	}

OnMyOK();
	CDialog::OnClose();
}
else
{
	SendMessage(WM_SYSCOMMAND,SC_MINIMIZE,0);
	//ontuopan();
}
	

}


void SaveGroupRuleAndNickName()
{
	INT64 realqqnumber;
	qqgrouprule temprule;
	qqgrouprule temprule2;
	for(UINT i=0;i<GRealNumRulemap.m_mapstr.size();i++)
	{
		realqqnumber=GRealNumRulemap.m_mapstr[i];
		temprule=GRealNumRulemap[(UINT)i];

		qqgrouprule org_temprule;
		BOOL loadedflag=org_GRealNumRulemap.Lookup(realqqnumber,org_temprule);
	//	AfxMessageBox(_T("sdfjsd"));
		BOOL flag1=temprule==g_defaultqqgrouprule;
		BOOL flag2=temprule==temprule2;//软件默认的规则
		BOOL flag3=org_temprule==temprule;
		BOOL flag4=!loadedflag;
		if(flag2||(flag1&&(flag3||flag4)))//软件默认的群规或者是没发生变化的群规就不用保存
		{

			 str222.Format(_T("%I64d:不用保存时的完全关闭:%d flag1:%d flag2:%d flag3:%d flag4:%d"),temprule.m_selfrealqqgroupnum,temprule.g_totalshutitup,flag1,flag2,flag3,flag4);
		Write2MagnetLog(str222,&magnetfile,4);
			//不用保存
		}
		else
		{
	GetRuleFromFile(false,realqqnumber,temprule);
		}

	}

	INT64 tempgroupuin;
	CKeepINT64StrMap *pintstrmap=NULL;
	int sizecount;
	lockgqqnickmapresource.Lock();
	sizecount=GrouprealqqNickmap.m_mapstr.size();
	lockgqqnickmapresource.Unlock();
for(UINT i=0;i<sizecount;i++)
	{
		pintstrmap=NULL;
		lockgqqnickmapresource.Lock();
		tempgroupuin=GrouprealqqNickmap.m_mapstr[i];
		pintstrmap=GrouprealqqNickmap[i];
		
		if(pintstrmap)
	GetINT64StrMapFromFile(tempgroupuin,pintstrmap,false);
		lockgqqnickmapresource.Unlock();
	}


}
void loglasterror(LPCTSTR saveerror)
{
	CString qqlognamestr;
	if(g_remote_lastownqq.IsEmpty())
	qqlognamestr.Format(_T("%s登录状态.txt"),m_ownqqnumber);
	else
	qqlognamestr.Format(_T("%s登录状态.txt"),g_remote_lastownqq);
	CString helppath=::function::complete_path(qqlognamestr);
	CReadAUStdioFile helpfile;
	if(helpfile.Open(helppath,CFile::modeCreate|CFile::modeWrite))
	{
		CString tempstr;
		CString frontstr,backstr;
		
		tempstr.Format(_T("%s"),saveerror);
	helpfile.WriteLineStr(tempstr);	
	
		helpfile.Close();
	}
}
void C晨风qq机器人Dlg::EasyExit()
{
	bExitProcess=true;
	bExitPostThread=true;

static int onceflag=false;
if(onceflag)
	return;
onceflag=true;


	SetWindowText(_T(""));
	//LoadUserSetting(false);

	//LoadIgnoreQQlist(false);	
		if(!(g_bIgnoreAll^g_temporaryignorall))
	{
		//临时屏蔽了则什么事都不做
	}
		else
		{
SaveGroupRuleAndNickName();
	
		SaveRankFile();
		}
	LoadUserSetting(false);

	if(tempdel_forever_blacklist.size()||temp_forever_blacklist.size())
	{
	//保存永久黑名单
		CReadAUStdioFile helpfile;
	if(helpfile.Open(g_foreverblackfn,CFile::modeCreate|CFile::modeWrite))
	{
		CString tempstr;
		CString frontstr,backstr;
		for(auto it=g_forever_blacklist.begin();it!=g_forever_blacklist.end();it++)
		{
			if(*it)
			{
		tempstr.Format(_T("%lld"),*it);
	helpfile.WriteLineStr(tempstr);	
	helpfile.Flush();
			}
		}
		helpfile.Close();
	}
	
	}
	DeleteFile(SaveAs_complete_path(_T("群号和窗口句柄对应关系.txt")));

	//if(g_qqserveripmap.GetCount())
	
	CString helppath=SaveAs_complete_path(_T("QQ服务器IP.txt"));
	CReadAUStdioFile helpfile;
	if(helpfile.Open(helppath,CFile::modeCreate|CFile::modeWrite))
	{
		CString tempstr;
		CString frontstr,backstr;
		for(UINT i=0;i<g_qqserveripmap.m_mapstr.size();i++)
		{
		tempstr.Format(_T("%s\t%s"),g_qqserveripmap.m_mapstr[i],g_qqserveripmap[i]);
	helpfile.WriteLineStr(tempstr);	
		}
		helpfile.Close();
	}


	Saveinvitelog();

if(g_autoreplyfile1.m_hFile!=CFile::hFileNull)
	g_autoreplyfile1.Close();
if(g_Privilegeautoreplyfile1.m_hFile!=CFile::hFileNull)
		g_Privilegeautoreplyfile1.Close();
	QuitAndSavehistory();
	::Shell_NotifyIcon(NIM_DELETE,&nid); 

	sharehwnd = NULL;

}
//INT GetEncoderClsid(const WCHAR* format, CLSID* pClsid);

BOOL C晨风qq机器人Dlg::LoadUserSetting(BOOL bLoad)
{
	BOOL rtflag_firsttime=true;
	CString menuconfig=_T("user_setting.ini");
	::function::GetLanuageFromCFSoftPath(menuconfig,menuconfig,true);
	if(menuconfig.Find(_T("qqrobot"))==-1||menuconfig.Find(_T("破解"))!=-1)
		return false;
	CReadAUStdioFile file1(true);
	CString tempstr;

	if(bLoad)
	{
		
		
		g_lastownqq=_T("");
	//	g_defaultqqgrouprule.g_timeover=0;
	//	g_defaultqqgrouprule.g_percent=70;
	//	g_defaultqqgrouprule.g_includekey=0;
		g_status_selcur=0;
		g_slientmode=1;
		g_privatepercent=20;
	
		g_checkgroupmembertime=20000000;
		
		g_defaultstopply=false;
		if(g_speedonly)
		g_autonotice=false;
		else
		g_autonotice=true;
		g_autonoticetime=60;
		g_nohistory=true;

		g_Androidflag=1;
g_doubletipPrivate=false;
g_bShowChineseNum=false;
g_workindiscussgroup=false;
g_smarttipsforsong=false;
g_totalsilent=false;
g_robneedLowestRankNum=30;
g_robneedwaitTime=60;
g_initscore=10;
g_paybackscale=20;
g_gamblehardscale=100;
g_bidwaittime=20;
g_bidbacknum=5;
g_sourceweb=_T("");
g_additionalsourceweb=_T("http://www.qqshow123.com/fetchitem.php?msg=%s");
g_defgameweb=_T("http://www.qqshow123.com/game/defgame.txt");
g_buycardweb=_T("http://127.0.0.1/testplug.dll?function=rechargefun&cmdstr=");
g_additionalprewords=_T("查询");
g_checkinformatstr=default_g_checkinformatstr;
g_equipformatstr=default_g_equipformatstr;
g_gamroboformatstr=default_g_gamroboformatstr;

//	g_defaultqqgrouprule.g_allowallshutitup=true;
//g_defaultqqgrouprule.g_totalshutitup=false;
//g_defaultqqgrouprule.g_checkin=true;
//g_defaultqqgrouprule.g_gamble=true;

		//g_defaultqqgrouprule.g_sessionanswerfalg=false;
		g_hellowstr=_T("可以在这里发一些普通的文字内容。\r\n也可以在这里输入关闭机器人、开启广播功能等指令，批量发到多个群！");
		//【群公告】这是公告标题|这里是群公告的正文（前面的【群公告】不要删除，否则就是发出普通的文字，而不是群公告。）
		//g_defaultqqgrouprule.g_welcomestr=_T("欢迎新人“XXX”加入本群！");
g_autorunflag=0;
g_autologinflag=0;
g_notipadflag = false;
g_last_bAuto_online=false;
		g_groupimgurl=_T("");
	//	g_defaultqqgrouprule.g_prefixstr=_T("#");
		//g_defaultqqgrouprule.g_group_request_method=1;
		//g_defaultqqgrouprule.g_group_denyreason=_T("");

		g_friend_welcomemsg=_T("感谢你添加我为好友！");
		if(!g_customstr.IsEmpty())
				{
				g_friend_welcomemsg.Replace(_T("晨风"),g_customstr);
				}
		g_friend_request_method=2;
		g_friend_pincodestr=_T("");
		//g_defaultqqgrouprule.g_group_pincodestr=_T("");
		
		if(g_speedonly)
		g_defaultqqgrouprule.g_continuefind=false;
		else
		g_defaultqqgrouprule.g_continuefind=true;//

		//g_defaultqqgrouprule.g_groupdefaultanswer=_T("");
		g_privatedefaultanswer=_T("");
	//	g_defaultqqgrouprule.g_robotname=_T("机器人");
	//	g_defaultqqgrouprule.g_byprivate=1;
		g_bTuopanflag=false;
		g_history_maxsize=5;
		g_autoagreeinvite=1;
		g_bApplyAll=true;
		g_bIgnoreAll=false;
		g_temporaryignorall=!g_bIgnoreAll;
		g_defaultqqgrouprule.g_adminliststr=DefaultAdmin;
	

		g_autoreplycategory=_T("机器人应答小组");
	    g_fontname=_T("微软雅黑");
		g_fontsize=10;
		g_boldflag=0;
		g_fontcolorstr=_T("000000");
		g_recentliststr=_T("");
		g_groupfilespath=_T("");
		g_specifygrouprankpath=_T("");

		if(file1.Open(menuconfig,CFile::modeRead|CFile::shareDenyNone))
		{
			rtflag_firsttime=false;

	if(file1.ReadString(tempstr))
				g_lastownqq=tempstr;
	CString fmtstrqq;
	fmtstrqq.Format(_T("%s"),g_lastownqq);

	//fmtstrqq=::function::CFSoft_path(fmtstrqq);
	
	//CReadAUStdioFile filepwd(true);
			g_bIgnoreAll=_ttoi(tempstr);
			if(g_bIgnoreAll)
		g_bIgnoreAll=1;
g_temporaryignorall=!g_bIgnoreAll;

LoadPassword(g_lastownqq,g_defaultpassword);
g_defaultorgpassword=g_defaultpassword;
		if(file1.ReadString(tempstr))
		g_defaultstopply=_ttoi(tempstr);
	if(file1.ReadString(tempstr))
		g_autonotice=_ttoi(tempstr);
	if(file1.ReadString(tempstr))
	{
		g_autonoticetime=_ttoi(tempstr);
		g_autonoticetime=max(1,g_autonoticetime);
	}

if(file1.ReadString(tempstr))
		g_autoreplycategory=tempstr;
if(file1.ReadString(tempstr))
{
		g_hellowstr=tempstr;
g_hellowstr.Replace(RNDEFBUF,_T("\r\n"));

}

if(file1.ReadString(tempstr))
		g_nohistory=_ttoi(tempstr);

if(file1.ReadString(tempstr))
		g_privatepercent=_ttoi(tempstr);


if(file1.ReadString(tempstr))
		g_status_selcur=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_slientmode=_ttoi(tempstr);

if(file1.ReadString(tempstr))
		g_fontname=tempstr;
if(g_fontname.IsEmpty())
	 g_fontname=_T("微软雅黑");

if(file1.ReadString(tempstr))
		g_fontsize=_ttoi(tempstr);
	if(g_fontsize<9)
		g_fontsize=9;

if(file1.ReadString(tempstr))
		g_fontcolorstr=tempstr;

if(file1.ReadString(tempstr))
		g_groupimgurl=tempstr;




if(file1.ReadString(tempstr))
		g_recentliststr=tempstr;

if(file1.ReadString(tempstr))
		g_privatedefaultanswer=tempstr;
if(file1.ReadString(tempstr))
		g_bTuopanflag=_ttoi(tempstr);



if(file1.ReadString(tempstr))
		g_autorunflag=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_autologinflag=_ttoi(tempstr);

if(file1.ReadString(tempstr))
		g_friend_pincodestr=tempstr;
if(file1.ReadString(tempstr))
		g_friend_request_method=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_friend_welcomemsg=tempstr;

if(file1.ReadString(tempstr))
		g_bApplyAll=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_history_maxsize=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_groupfilespath=tempstr;
if(file1.ReadString(tempstr))
{
		g_bIgnoreAll=_ttoi(tempstr);
		if(g_bIgnoreAll)
		g_bIgnoreAll=1;
g_temporaryignorall=!g_bIgnoreAll;
}
if(file1.ReadString(tempstr))
		g_boldflag=_ttoi(tempstr);

if(file1.ReadString(tempstr))
		g_doubletipPrivate=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_bShowChineseNum=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_workindiscussgroup=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_smarttipsforsong=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_totalsilent=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_robneedLowestRankNum=_ttoi64(tempstr);
if(file1.ReadString(tempstr))
		g_robneedwaitTime=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_initscore=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_paybackscale=_ttoi(tempstr);

if(file1.ReadString(tempstr))
		g_sourceweb=tempstr;
if(file1.ReadString(tempstr))
		g_additionalsourceweb=tempstr;
if(file1.ReadString(tempstr))
		g_additionalprewords=tempstr;
if(file1.ReadString(tempstr))
{
		g_checkinformatstr=tempstr;
g_checkinformatstr.Replace(RNDEFBUF,_T("\r\n"));

}
if(file1.ReadString(tempstr))
{
		g_equipformatstr=tempstr;
g_equipformatstr.Replace(RNDEFBUF,_T("\r\n"));

}
if(file1.ReadString(tempstr))
{
		g_gamroboformatstr=tempstr;
g_gamroboformatstr.Replace(RNDEFBUF,_T("\r\n"));

}
if(file1.ReadString(tempstr))
{
		g_gamblehardscale=_ttoi(tempstr);

}
if(file1.ReadString(tempstr))
{
		g_bidwaittime=_ttoi(tempstr);

}
if(file1.ReadString(tempstr))
{
		g_checkgroupmembertime=_ttoi(tempstr);
		g_checkgroupmembertime=max(3,g_checkgroupmembertime);

}
if(file1.ReadString(tempstr))
{
		g_bidbacknum=_ttoi(tempstr);
		g_bidbacknum=max(1,g_bidbacknum);
		g_bidbacknum=min(100,g_bidbacknum);

}
if(file1.ReadString(tempstr))
{
		g_bQQflag=_ttoi(tempstr);
		//g_Androidflag=true;

}
if(file1.ReadString(tempstr))
{
		g_autoagreeinvite=_ttoi(tempstr);
		

}
if(file1.ReadString(tempstr))
		g_specifygrouprankpath=tempstr;
if(file1.ReadString(tempstr))
		g_defgameweb=tempstr;
if(file1.ReadString(tempstr))
		g_buycardweb=tempstr;
if(file1.ReadString(tempstr))
		g_accesstokenstr=tempstr;
if(file1.ReadString(tempstr))
		g_voicenextip=tempstr;
if(file1.ReadString(tempstr))
		g_allxmlflag=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_closeplugfunction=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_last_bAuto_online=_ttoi(tempstr);
if(file1.ReadString(tempstr))
		g_agreeinviteweb=tempstr;
if(file1.ReadString(tempstr))
		g_uploadimgnextip=tempstr;
if(file1.ReadString(tempstr))
g_notipadflag =_ttoi(tempstr);
		file1.Close();
		}
	
			g_loginedset.clear();
			
			CStringvect adminvectemp;

			if(!g_recentliststr.IsEmpty())
			{
::function::getmytoken(g_recentliststr,';',adminvectemp);
			for(int i=0;i<adminvectemp.size();i++)
			{
			g_loginedset.push_back(adminvectemp[i]);

m_combox_ownqq.AddString(adminvectemp[i]);			
			
			}
			}

			((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(g_bQQflag);
			//GRealNumRulemap
SetDlgItemText(IDC_EDIT2,g_defaultpassword);
SetDlgItemText(IDC_COMBO4,g_lastownqq);	
((CComboBox*)GetDlgItem(IDC_COMBO5))->SetCurSel(g_status_selcur);
GetAllColor();
	}
	else
	{
		GetDlgItemText(IDC_EDIT2,g_defaultpassword);
		GetDlgItemText(IDC_COMBO4,g_lastownqq);
		g_bQQflag=((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
g_status_selcur=((CComboBox*)GetDlgItem(IDC_COMBO5))->GetCurSel();


g_recentliststr=_T("");
for(setvector<CString>::const_iterator it=g_loginedset.begin();it!=g_loginedset.end();it++)
			{
			g_recentliststr+=*it;
			g_recentliststr+=_T(";");
			}


	qqgrouprule temprule2;
	if(!(g_defaultqqgrouprule==temprule2))
GetRuleFromFile(false,0,g_defaultqqgrouprule);

	::function::RemoveRH(menuconfig);
if(file1.Open(menuconfig,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{
	//	file1.WriteLineStr(g_defaultpassword);
			file1.WriteLineStr(g_lastownqq);

			if(g_defaultpassword!=g_defaultorgpassword)
			SavePassword(g_lastownqq,g_defaultpassword);
			//	CString fmtstrqq;
	//fmtstrqq.Format(_T("%s"),g_lastownqq);

	//fmtstrqq=::function::CFSoft_path(fmtstrqq);
	
	//CReadAUStdioFile filepwd(true);
	//	if(filepwd.Open(fmtstrqq,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
	//	{
	//		filepwd.WriteLineStr(g_defaultpassword);
	//		filepwd.Close();
	//	}
		TCHAR buf[32];
	_itot(g_defaultstopply,buf,10);	
			file1.WriteLineStr(buf);
	_itot(g_autonotice,buf,10);	
			file1.WriteLineStr(buf);
_itot(g_autonoticetime,buf,10);	
			file1.WriteLineStr(buf);
	file1.WriteLineStr(g_autoreplycategory);

	g_hellowstr.Replace(_T("\r\n"),RNDEFBUF);
file1.WriteLineStr(g_hellowstr);

_itot(g_nohistory,buf,10);	
			file1.WriteLineStr(buf);
_itot(g_privatepercent,buf,10);	
file1.WriteLineStr(buf);


_itot(g_status_selcur,buf,10);	
file1.WriteLineStr(buf);

_itot(g_slientmode,buf,10);	
file1.WriteLineStr(buf);

file1.WriteLineStr(g_fontname);
_itot(g_fontsize,buf,10);	
file1.WriteLineStr(buf);
file1.WriteLineStr(g_fontcolorstr);
file1.WriteLineStr(g_groupimgurl);




file1.WriteLineStr(g_recentliststr);
g_privatedefaultanswer.Replace(_T("\r\n"),RNDEFBUF);
file1.WriteLineStr(g_privatedefaultanswer);
_itot(g_bTuopanflag,buf,10);	
file1.WriteLineStr(buf);

_itot(g_autorunflag,buf,10);	
file1.WriteLineStr(buf);
_itot(g_autologinflag,buf,10);	
file1.WriteLineStr(buf);	
g_friend_pincodestr.Replace(_T("\r\n"),RNDEFBUF);
file1.WriteLineStr(g_friend_pincodestr);

_itot(g_friend_request_method,buf,10);	
file1.WriteLineStr(buf);
g_friend_welcomemsg.Replace(_T("\r\n"),RNDEFBUF);
file1.WriteLineStr(g_friend_welcomemsg);
_itot(g_bApplyAll,buf,10);	
file1.WriteLineStr(buf);	
_itot(g_history_maxsize,buf,10);	
file1.WriteLineStr(buf);	
file1.WriteLineStr(g_groupfilespath);
_itot(g_bIgnoreAll,buf,10);	
file1.WriteLineStr(buf);
_itot(g_boldflag,buf,10);	
file1.WriteLineStr(buf);

_itot(g_doubletipPrivate,buf,10);	
file1.WriteLineStr(buf);
_itot(g_bShowChineseNum,buf,10);	
file1.WriteLineStr(buf);
_itot(g_workindiscussgroup,buf,10);	
file1.WriteLineStr(buf);
_itot(g_smarttipsforsong,buf,10);	
file1.WriteLineStr(buf);
_itot(g_totalsilent,buf,10);	
file1.WriteLineStr(buf);
_i64tot(g_robneedLowestRankNum,buf,10);	
file1.WriteLineStr(buf);
_itot(g_robneedwaitTime,buf,10);	
file1.WriteLineStr(buf);
_itot(g_initscore,buf,10);	
file1.WriteLineStr(buf);
_itot(g_paybackscale,buf,10);	
file1.WriteLineStr(buf);

file1.WriteLineStr(g_sourceweb);
file1.WriteLineStr(g_additionalsourceweb);
file1.WriteLineStr(g_additionalprewords);
g_checkinformatstr.Replace(_T("\r\n"),RNDEFBUF);
file1.WriteLineStr(g_checkinformatstr);
g_equipformatstr.Replace(_T("\r\n"),RNDEFBUF);
file1.WriteLineStr(g_equipformatstr);
g_gamroboformatstr.Replace(_T("\r\n"),RNDEFBUF);
file1.WriteLineStr(g_gamroboformatstr);
_itot(g_gamblehardscale,buf,10);	
file1.WriteLineStr(buf);

_itot(g_bidwaittime,buf,10);	
file1.WriteLineStr(buf);
_itot(g_checkgroupmembertime,buf,10);	
file1.WriteLineStr(buf);
_itot(g_bidbacknum,buf,10);	
file1.WriteLineStr(buf);
_itot(g_bQQflag,buf,10);	
file1.WriteLineStr(buf);
_itot(g_autoagreeinvite,buf,10);	
file1.WriteLineStr(buf);
file1.WriteLineStr(g_specifygrouprankpath);
file1.WriteLineStr(g_defgameweb);
file1.WriteLineStr(g_buycardweb);

file1.WriteLineStr(g_accesstokenstr);

file1.WriteLineStr(g_voicenextip);
_itot(g_allxmlflag,buf,10);	
file1.WriteLineStr(buf);

_itot(g_closeplugfunction,buf,10);	
file1.WriteLineStr(buf);
_itot(g_last_bAuto_online,buf,10);	
file1.WriteLineStr(buf);
file1.WriteLineStr(g_agreeinviteweb);
file1.WriteLineStr(g_uploadimgnextip);
_itot(g_notipadflag,buf,10);
file1.WriteLineStr(buf);
file1.Close();
		}
}

	return rtflag_firsttime;
}
void C晨风qq机器人Dlg::QuitAndSavehistory(BOOL bJustLookflag)
{
	if (g_history_maxsize == 0)
		return;
	CString historystr=::function::complete_path(_T("机器人聊天历史记录.txt"));
	CString historystr2=::function::complete_path(_T("机器人聊天历史记录.上一次备份.txt"));
	
	if(::function::GetFileSizeFromPath(historystr)>=g_history_maxsize*1024*1024)
	{
		if(::function::RemoveR_CopyFileW(historystr,historystr2,false))
		DeleteFile(historystr);
		else
		{
		//MessageBox(_T("拷贝聊天历史记录失败！"),_T("拷贝聊天历史记录失败，请确保你硬盘有剩余空间以及无杀毒软件阻止当前程序！"),0);
		}
	}
	historyfile1.SetUnicodeFile(true);
if(!historyfile1.Open(historystr,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite|CFile::shareDenyNone))
	{
		//AfxMessageBox(_T("无法创建或打开“机器人聊天历史记录.txt”，软件将无法保存聊天记录！"));
	}
else
{
	CString titlestr,editstr;
	
	historyfile1.SeekToEnd();
	lockqqmsgdlgres.Lock();
	if(m_mapqqmsgdlg.GetCount()>0)
	{
				static int temp_last_timetask_day=0;
		
if(!bJustLookflag||temp_last_timetask_day!=mySystemTime.wDay)
{
	CString pretimestr;
		SYSTEMTIME mySystemTime;
	GetLocalTime(&mySystemTime);
	pretimestr.Format(_T("============================【%04d年%02d月%02d日聊天记录】================================\r\n"),mySystemTime.wYear,mySystemTime.wMonth,mySystemTime.wDay);
	historyfile1.WriteLineStr(pretimestr);

	temp_last_timetask_day=mySystemTime.wDay;

}
	}
	for(UINT i=0;i<m_mapqqmsgdlg.m_mapstr.size();i++)
	{
			if(!m_mapqqmsgdlg[i]->lasteditstr.IsEmpty())
	{
	m_mapqqmsgdlg[i]->GetWindowText(titlestr);
	historyfile1.WriteLineStr(titlestr);
	
	
editstr=m_mapqqmsgdlg[i]->lasteditstr;//GetDlgItemText(IDC_EDIT1,editstr);
editstr.Replace(RNDEFBUF,_T("\r\n"));
historyfile1.WriteString(editstr);
			
m_mapqqmsgdlg[i]->lasteditstr=_T("");
			}
			if(!bJustLookflag)
delete m_mapqqmsgdlg[i];
	}



	if(!bJustLookflag)
	m_mapqqmsgdlg.RemoveAll();


	lockqqmsgdlgres.Unlock();
	historyfile1.Close();
}


}
void C晨风qq机器人Dlg::OnMyOK()
{
bExitPostThread=true;	
bExitProcess=true;
Sleep(50);
QuitAndSavehistory();

if(bFirsttime)
				{

					if(!companyverion&&g_customstr.IsEmpty())
	{
	CheckUpdateAndPrompt();
		
		
	
	//On32889();
	}
	//On32886();
	//On32887();
				}
OnCancel();

}
LRESULT C晨风qq机器人Dlg::onExitMyself(WPARAM wParam,LPARAM lParam)
{

	
		OnMyOK();

	return 0;
}
LRESULT C晨风qq机器人Dlg::onShowMyself(WPARAM wParam,LPARAM lParam)
{

	
	ShowWindow(SW_RESTORE);
			ShowWindow(SW_SHOW);	

	return 0;
}
LRESULT C晨风qq机器人Dlg::onHideMyself(WPARAM wParam,LPARAM lParam)
{

	
	ShowWindow(SW_HIDE);

	return 0;
}
void C晨风qq机器人Dlg::UpdateLastInf()
{
	if(lstrlen(m_ownqqnumber)==0)
		return;
		CString str;

			CString shortcnstr;
	CMyBGCDlg::GetShortCountrySign(shortcnstr,Lan_ID_NUM);
	TCHAR regbufcheck1[320];
	if(g_bbaidusourceflag)
	{
lstrcpy(regbufcheck1,_T("gihehehadkcpcphhhhhhcohbhbhdgigphhdbdcddcogdgpgncpgdgggogfhhhbhbhcgpgcgphecohagihadphbhbgohfgndncfhdcghggfhchdgjgpgodncfhdcggdgigfgdglhdgjghgodncfhdcggdgphfgohehchjdncfhdcghdgphfhcgdgfdnhdhkgcge"));

	}
	else
	{
		
lstrcpy(regbufcheck1,_T("gihehehadkcpcphhhhhhcohbhbhdgigphhdbdcddcogdgpgncpgdgggogfhhhbhbhcgpgcgphecohagihadphbhbgohfgndncfhdcghggfhchdgjgpgodncfhdcggdgigfgdglhdgjghgodncfhdcggdgphfgohehchjdncfhd"));
	}
	::function::Reversible_encode(regbufcheck1,false);//_T("http://www.qqshow123.com/cfnewqqrobot.php?qqnum=%s&version=%s&checksign=%s&country=%s")

	CString newqqnumstr = GetNewQQNumForEncode(g_interfaceuin);
	str.Format(regbufcheck1, newqqnumstr, g_purenumberversion, GetNewcheckSignCode(), shortcnstr);
	
	UINT ddlen=0;

	DownloadWebResultTxt(str,shortcnstr,false);
	//::function::DownloadHttpFile(str,NULL,ddlen);
	//zunc
}
void MyTerminateThread(  __in HANDLE hThread,__in DWORD dwExitCode)
{
	try
	{
	TerminateThread(hThread,dwExitCode); 
	}
	catch(...)
	{
	
	}
}

void C晨风qq机器人Dlg::OnDestroy()
{
	
if(!g_remoteencryptflag)
		{	
	
	//PopUpRobotAd();
	
	EasyExit();
	CleanAndClear();
	if(m_alreadylogin)
	{
		QuitQQ();
	m_alreadylogin=false;
	}
	
	{

		//WaitAndReport();
	}

	
	//CKeepMap<CString,LPCTSTR,HINSTANCE,HINSTANCE> g_dllpathmap;

FreeAlldllFileHandle();
//释放所有dll

		
		{
	
	
	closesocket(g_socket); //关闭套接字  
    WSACleanup();  
GoogleShutdownProtobufLibrary ();

		}

	Terminate2Thread();
	DWORD dwTimeout = 1000;
  if(mywinthread5)
	   if (WaitForSingleObject (mywinthread5-> m_hThread, dwTimeout ) == WAIT_TIMEOUT )
       {
MyTerminateThread(mywinthread5-> m_hThread,0); 

	   }
	   mywinthread5=NULL;

	  if(mywinthread6)
	   if (WaitForSingleObject (mywinthread6-> m_hThread, dwTimeout ) == WAIT_TIMEOUT )
       {
MyTerminateThread(mywinthread6-> m_hThread,0); 

	   }
	   mywinthread6=NULL;
	

	UpdateLastInf();

	if(bFirsttime)
	{
		//MessageBox(_T("如果不想自己一天到晚开着电脑挂机器人软件，可以试试下面的挂机宝来挂机器人软件！"),_T("租用挂机宝挂机器人软件"),0);
	//MessageBox(_T("最新推出晨风微信机器人，和qq机器人功能相同，可以使用相同的插件，目前完全免费，无任何限制！欢迎使用和传播！"),_T("晨风微信机器人"),0);
	
		//ShellExecute(NULL,NULL,_T("http://www.qqshow123.com/gjb.php"),0,0,1);
		//ShellExecute(NULL,NULL,_T("http://www.cfxy.me/productinfo.php?id=14"),0,0,1);
	}

}
	CDialog::OnDestroy();


	// TODO: 在此处添加消息处理程序代码
}


int GetModifyTimeDiffer(LPCTSTR localfile,LPCTSTR remoteurl)
{

	CString rtquestr;

	SYSTEMTIME httplasttime,locallasttime;
	if(!::function::GetLastmodifydate(remoteurl,rtquestr,&httplasttime))
		return -1;

	WIN32_FIND_DATA wfd;
	FILETIME ft;


	// 获取文件属性信息
	FindClose(FindFirstFile(localfile, &wfd));
	FileTimeToLocalFileTime(&wfd.ftLastWriteTime, &ft);
	FileTimeToSystemTime(&ft,&locallasttime);


	int minute1=((httplasttime.wMonth*31+httplasttime.wDay)*24+httplasttime.wHour)*60+httplasttime.wMinute;
	int minute2=((locallasttime.wMonth*31+locallasttime.wDay)*24+locallasttime.wHour)*60+locallasttime.wMinute;

	CString fmtstr;
	fmtstr.Format(_T("%02d.%02d.%02d.%02d.%02d  %02d.%02d.%02d.%02d.%02d"),httplasttime.wYear,httplasttime.wMonth,httplasttime.wDay,httplasttime.wHour,httplasttime.wMinute,locallasttime.wYear,locallasttime.wMonth,locallasttime.wDay,locallasttime.wHour,locallasttime.wMinute);
	//AfxMessageBox(fmtstr);
	return minute1-minute2;


}

void C晨风qq机器人Dlg::ontuopan()
{
	
	nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);

	nid.hWnd=this->m_hWnd;

	nid.uID=(UINT)IDR_MAINFRAME;

	nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;

	nid.uCallbackMessage=WM_SHOWTASK;//

	nid.hIcon = m_hIcon;//); LoadIcon(

	
	lstrcpy(nid.szTip,m_addtitle+_T("双击还原窗口"));


	if(!bHideMainIcon)
Shell_NotifyIcon(NIM_ADD,&nid);

	ShowWindow(SW_HIDE);//隐藏主窗口
	g_minstateflag=true;
	lockqqmsgdlgres.Lock();
	if(!g_slientmode)
	for(UINT i=0;i<m_mapqqmsgdlg.m_mapstr.size();i++)
		{

		m_mapqqmsgdlg[i]->ShowWindow(SW_HIDE);
		
		}
	lockqqmsgdlgres.Unlock();
		/*for(UINT i=0;i<m_mapqqacdlg.m_mapstr.size();i++)
		{
			
			m_mapqqmsgdlg[i]->ShowWindow(SW_HIDE);
		
		}*/
}
//#define NOAD
void AppendRobotAd(LPCTSTR msgcontent,CString &tempadstr)
{

		tempadstr=msgcontent;

	/*	if(Isggged)
		{
		return;
		}*/
	if(lstrlen(msgcontent)==0)
		return;
	if (StrStr(msgcontent, _T("将自动验证是否已激活，如果已激活将会以注册版方式运行！")))
		return;

		static int ncount=0;

	
		static int newncount=0;
		int tempcount=0;
#ifdef NOAD
	

			if(!Isggged&&!g_alreadyhomepage)//)//)//if(!Isggged)//
			{
#else
if(1)//!Isggged)//
{
#endif			
	BOOL bInsert=false;
			TCHAR bufword1=_T('晨');
			TCHAR bufword2=_T('风');
				CString robotad2;
	if(!g_customstr.IsEmpty())
	{
bInsert=(ncount%2==1);
	
	}
	else
	bInsert=(ncount%4==2);
	
	tempcount=newncount;

	newncount++;
	
	CString curadcontent;
	curadcontent.Format(_T("%c%c%c%c%c%c%c%c%c%c%c.注册版无广告$随机表情$%c"),_T('【'),_T('由'),bufword1,bufword2,_T('Q'),_T('Q'),_T('机'),_T('器'),_T('人'),_T('发'),_T('送'),_T('】'));
	
	lockrandomadres.Lock();
	
	if(bInsert)
	if(g_randomadtailvector.size())
{
	
	static int cur_number=0;
				int tempnumber=cur_number%g_randomadtailvector.size();
				cur_number++;
			curadcontent=g_randomadtailvector[tempnumber];	
			curadcontent.TrimRight();
	
	

}
	//GetTotal_content_vect(g_randomadtailvector,tempstr2);
	lockrandomadres.Unlock();


			if(bInsert)
			{

			
			
	
			if(!g_customstr.IsEmpty())
			{
			bufword1=g_customstr.GetAt(0);
			bufword2=g_customstr.GetAt(1);

			}
			

		/*	if(StrChr(robotad,bufword1)&&StrChr(robotad,bufword2))
			{
				tempadstr+=robotad;
			}
			else*/
			{
				int numdd=1000;
				numdd*=2;
				if(g_customstr.IsEmpty()&&!(*pggged))
				{
					robotad2=curadcontent;
	//robotad2.Format(_T("%c%c%c%c%c%c%c%c%c%c%c.注册版无广告$随机表情$%c"),_T('【'),_T('由'),bufword1,bufword2,_T('Q'),_T('Q'),_T('机'),_T('器'),_T('人'),_T('发'),_T('送'),_T('】'));
				}
				if(!g_customstr.IsEmpty())
			{
			
				//暂时不加广告//robotad2.Format(_T("%c%c%s%c%c,注册版无广告%c"),_T('【'),_T('由'),g_customstr,_T('发'),_T('送'),_T('】'));
			}
				else
				{

					if(!Isggged)
					{
robotad2=curadcontent;
	//robotad2.Format(_T("%c%c%c%c%c%c%c%c%c%c%c 注册版无广告$随机表情$%c"),_T('【'),_T('由'),bufword1,bufword2,_T('Q'),_T('Q'),_T('机'),_T('器'),_T('人'),_T('发'),_T('送'),_T('】'));
					}
					else if(ccccflag2<g_interfaceuin||ccccccc<numdd)//防止破解
					{
	robotad2=curadcontent;					
	//robotad2.Format(_T("%c%c%c%c%c%c%c%c%c%c%c..注册版无广告$随机表情$%c"),_T('【'),_T('由'),bufword1,bufword2,_T('Q'),_T('Q'),_T('机'),_T('器'),_T('人'),_T('发'),_T('送'),_T('】'));
		
					}
					else
					{

if(g_selfdeftailvector.size())
{
	
	static int cur_number=0;
				int tempnumber=cur_number%g_selfdeftailvector.size();
				cur_number++;
			robotad2=g_selfdeftailvector[tempnumber];	
			robotad2.TrimRight();
	
	

}
					}
				
				}	
		
			}

			}


			if((tempcount%4==2)&&(ccccflag2<g_interfaceuin||ccccccc<1500))//如果是破解版
			{
						
							
			robotad2=curadcontent;
							//robotad2.Format(_T("%c%c%c%c%c%c%c%c%c%c%c，注册版无广告$随机表情$%c"),_T('【'),_T('由'),bufword1,bufword2,_T('Q'),_T('Q'),_T('机'),_T('器'),_T('人'),_T('发'),_T('送'),_T('】'));
						
					}
			if(((!bbbtempstr.IsEmpty()&&(bbbtempstr.GetLength()<4||bbbtempstr.GetAt(0)<'2')||(ccccflag2<g_interfaceuin||ccccccc<1500)))&&(tempcount%6==3))//如果是破解版
			{

				robotad2=curadcontent;
				//robotad2.Format(_T("%c%c%c%c%c%c%c%c%c%c%c,注册版无广告$随机表情$%c"),_T('【'),_T('由'),bufword1,bufword2,_T('Q'),_T('Q'),_T('机'),_T('器'),_T('人'),_T('发'),_T('送'),_T('】'));
				if(Isggged)
				{
					//	CString fmtstrr;
					//	fmtstrr.Format(_T("\r\n%s_%I64d_%I64d_%d_%d"),bbbtempstr,ccccflag2,g_interfaceuin,ccccccc,tempcount);
					//	robotad2+=fmtstrr;
				}

			}

					if(!robotad2.IsEmpty())
				{
					tempadstr+=_T("\r\n");
				CString facerandfmt;
	facerandfmt.Format(_T("face%d"),rand()%171);
	robotad2.Replace(_T("$随机表情$"),facerandfmt);
		SYSTEMTIME curSystemTime;
	GetLocalTime(&curSystemTime);

	CString weekdayfmt;
	if(curSystemTime.wDayOfWeek==0)
		weekdayfmt=_T("星期日");
	else if(curSystemTime.wDayOfWeek==1)
		weekdayfmt=_T("星期一");
	else if(curSystemTime.wDayOfWeek==2)
		weekdayfmt=_T("星期二");
	else if(curSystemTime.wDayOfWeek==3)
		weekdayfmt=_T("星期三");
	else if(curSystemTime.wDayOfWeek==4)
		weekdayfmt=_T("星期四");
	else if(curSystemTime.wDayOfWeek==5)
		weekdayfmt=_T("星期五");
	else if(curSystemTime.wDayOfWeek==6)
		weekdayfmt=_T("星期六");

	facerandfmt.Format(_T("%d年%d月%d日 %02d:%02d %s"),curSystemTime.wYear,curSystemTime.wMonth,curSystemTime.wDay,curSystemTime.wHour,curSystemTime.wMinute,weekdayfmt);
	robotad2.Replace(_T("$当前时间$"),facerandfmt);
	
	if(robotad2!=_T("替换本行为空白"))
	tempadstr+=robotad2;
				}
					else if(robotad2.GetLength()>0)
					{
						tempadstr+=_T("\r\n");
						CString facerandfmt;
	facerandfmt.Format(_T("face%d"),rand()%171);
	robotad2.Replace(_T("$随机表情$"),facerandfmt);
		if(robotad2!=_T("替换本行为空白"))
	tempadstr+=robotad2;
					
					}
			




}
		ncount++;

	 
}

void ConvertMsg(LPCTSTR msgcontent,CString&tempnewstr,BOOL btranstourl)
{
	tempnewstr=msgcontent;
		tempnewstr.Replace(_T("\r\n"),RNDEFBUF);
		tempnewstr.Replace(_T("\r"),RNDEFBUF);
		tempnewstr.Replace(_T("\n"),RNDEFBUF);
tempnewstr.Replace(_T("【空格】"),_T(" "));

if(tempnewstr.Find(_T("{\"app\""))!=0&&tempnewstr.Find(_T("{\"config\""))!=0&&tempnewstr.Find(_T("\"app\":\"com.tencent"))==-1)
{
	if(tempnewstr.Find(_T("http:"))!=-1)
tempnewstr.Replace(_T("\\/"),_T("/"));
	tempnewstr.Replace(_T("\\"),_T("\\\\"));
}
	
	{
			tempnewstr.Replace(RNDEFBUF,_T("\n"));
	}
	
	if(tempnewstr.Find(_T("{\"app\""))!=0&&tempnewstr.Find(_T("{\"config\""))!=0&&tempnewstr.Find(_T("\"app\":\"com.tencent"))==-1&&tempnewstr.Find(_T("<summary"))==-1&&tempnewstr.Find(_T("<picture cover"))==-1&&tempnewstr.Find(_T("xml"))==-1&&tempnewstr.Find(_T("item>"))==-1&&tempnewstr.Find(_T("<msg"))==-1&&tempnewstr.Find(_T("<source"))==-1)
	tempnewstr.Replace(_T("\""),_T("“"));
	
	
	//face88
		wstring findbuf=tempnewstr.GetBuffer(0);
		
    	//face146

			
		if(btranstourl)
		{
			CStringvect vectemp;
			::function::getmytoken(g_groupimgurl,';',vectemp);
			CString tempdstr;
			CString rpfmtstr;
			CString midtempstr=findbuf.c_str();
			for(int i=vectemp.size()-1;i>=0;i--)
			{
				
				tempdstr.Format(_T("upgroupimage%d"),i+1);
			
rpfmtstr.Format(_T("\\\",[\\\"cface\\\",\\\"group\\\",\\\"%s\\\"],\\\""),vectemp[i]);
	
			midtempstr.Replace(tempdstr,rpfmtstr);
				
			}

		boost::wregex expression2(_T("upgroupimage"),boost::wregex::normal|boost::wregex::icase);//,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");

		//wstring findbuf2;

		findbuf=midtempstr.GetBuffer(0);
rpfmtstr.Format(_T("\\\\\",\\[\\\\\"cface\\\\\",\\\\\"group\\\\\",\\\\\"%s\\\\\"\\],\\\\\""),vectemp.back());
		findbuf=boost::regex_replace(findbuf,expression2,rpfmtstr.GetBuffer(0));
		//findbuf2=boost::regex_replace(findbuf,expression,_T("$1"));
		tempnewstr=findbuf.c_str();
		}
		else
		{
			tempnewstr=findbuf.c_str();
		//tempnewstr.Replace(_T("upgroupimage"),_T(""));
		}
	


	//\",[\"face\",88],\"
}

BOOL SendqqMsg(INT64 toqq,LPCTSTR msgcontent,int prnum/*=1*/)
{
	
	{
	
	return Android_Send1Msg(0,toqq,msgcontent,toqq);
	}

}
 BOOL GetTempSessionSign(INT64 groupUin, INT64 toUin,CString& sessionsignstr)
        {


CString realhostname;
CString processpath;
realhostname=_T("d1.web2.qq.com");
CString timestr2;
SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format(_T("%I64d%d"),time1.GetTime(),st.wMilliseconds);
processpath.Format(_T("/channel/get_c2cmsg_sig2?id=%I64d&to_uin=%I64d&service_type=0&clientid=%d&psessionid=%s&t=%s"),groupUin,toUin,clientID,psessionidstr,timestr2);


UINT ddlen=0;
byte *bufnickname=new byte[1024*10];

memset(bufnickname,0,1024*10);
BOOL rtflag=MySendWeb(realhostname,processpath,bufnickname,(char*)NULL,ddlen);

CString expressstr,rtmatchstr;
	
	BOOL bGetmatch;
	//retcode\":0
	expressstr.Format(_T("(?<=\"value\":\")\\w+?(?=\")"));
	//bGetmatch=GetFirstRegMatch((char*)bufnickname,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	CStringvectA getbackstr;
GetRegEX((char*)bufnickname,expressstr,getbackstr);//need consider of the actual keyname
//
char nicknamebuf[512];
	if(getbackstr.size()>0)
	{
		sessionsignstr=getbackstr[0];
		//strcpy(nicknamebuf,getbackstr[0]);
//::function::utf8_wchar(nicknamebuf,sessionsignstr);

	}


delete []bufnickname;
return rtflag;

        }
BOOL IsNumberStr(LPCTSTR nextstr)
{
	int num=_ttoi(nextstr);
	//if(!num)
	//num=_tcstol(nextstr,NULL,16);

	if(!num)
		if(lstrlen(nextstr)&&nextstr[0]==0)
			return true;

	return num;
}
BOOL IsHexNumberStr(LPCTSTR nextstr,BOOL type=0)
{
	CString tempstr=nextstr;
	int num=0;
	if(!type)
	num=_tcstol(tempstr,NULL,16);
	else
	{
	CString	tempstrleft=tempstr.Left(type);
	if(tempstrleft.Find('x')==-1&&tempstrleft.Find('X')==-1)
		return 0;

	tempstr=tempstr.Mid(type);
	num=_tcstol(tempstr,NULL,16);

	}
	if(!num)
		if(lstrlen(tempstr)&&tempstr[0]=='0')
			return true;

	return num;
}
int ReverseFind(const CString& str,LPCTSTR findstr,int startpos=0)
{

	int nlen=-1;
	int tempnlen=str.Find(findstr,startpos);
	
	while(tempnlen!=-1)
	{
nlen=tempnlen;
	tempnlen=str.Find(findstr,nlen+1);
	}
	return nlen;
}
int getfrontoffsetFrom2Str(CString& mystr,CString& nextstr)
{
	
	int offset=0;
	CString comstr=mystr+nextstr;
if(comstr.Find(_T("[imgurl]"))!=-1)
	{

//[             imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[i			mgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[im			gurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[img			url]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[imgu			rl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[imgur		l]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[imgurl		]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
		CString trycomstr;
		BOOL bfind1=false;
		BOOL bfind2=false;

for(int i=0;i<7;i++)
{
trycomstr=mystr.Right(i+1)+nextstr.Left(8-(i+1));
if(trycomstr==_T("[imgurl]"))
{
	bfind1=true;
	break;

}

}
if(!bfind1)
{
int pos=ReverseFind(mystr,_T("[imgurl]"));
if(pos!=-1)
{
if(mystr.Find(']',pos+lstrlen(_T("[imgurl]")))==-1)
	bfind2=true;//说明分在两边
}
}

if(bfind1||bfind2)
{
int posr=-1;
if(bfind2)
{
posr=nextstr.Find(']');
if(posr>-1&&posr<100)
offset=posr+1;
}
else
{
posr=nextstr.Find(']',lstrlen(_T("[imgurl]")));
if(posr>-1&&posr<100)
offset=posr+1;
}

}

//[imgurl]		{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[imgurl]{     DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|                   [/imgurl]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[					/imgurl]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/					imgurl]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/i				mgurl]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/im				gurl]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/img				url]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgu				rl]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgur			l]
//[imgurl]{DE236835-AB03-A494-2A03-509244D8328B}.gif|[/imgurl			]
//[imgurl]{2D537088-9F4D-1178-A94A-B90925788EBB}.jpg
//[imgurl]{4210C046-9915-70EC-35F3-5080CAD6F80D}.png|[/imgurl]
//[imgurl]{EE238BFB-ADDD-EF5E-D431-6FA3DD11E692}.gif|[/imgurl]
//[imgurl]{1CA299C7-98CA-945C-04E7-B4E760658A24}.gif|[/imgurl]
//[imgurl]32391CF14D9E51F0ABCCEDD678550D3D.jpg[/imgurl]

	
if(offset)
{
CString offsetstr=nextstr.Left(offset);
	mystr+=offsetstr;
	nextstr=nextstr.Mid(offset);
	return offset;
}

}
	if(StrStrI(comstr,_T("face0x")))//comstr.Find(_T("face0x"))!=-1)
	{
CString midstr=mystr.Right(13);
	int midlen=midstr.GetLength();
int nextlen=nextstr.GetLength();
if(midlen<13||nextlen<1)
	return 0;

if(_tcsnicmp(midstr,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//face0x3CD889D  FXXX这种分割、
	//
{
offset=1;
}
else if(_tcsnicmp((LPCTSTR)midstr+1,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//Xface0x3CD889  DFXXX、
{
offset=2;
}
else if(_tcsnicmp((LPCTSTR)midstr+2,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//XXface0x3CD88  9DFXXX
{
offset=3;
}
else if(_tcsnicmp((LPCTSTR)midstr+3,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//XXXface0x3CD8  89DFXXX、
{
offset=4;
}
else if(_tcsnicmp((LPCTSTR)midstr+4,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//XXXXface0x3CD  889DFXXX
{
offset=5;
}
else if(_tcsnicmp((LPCTSTR)midstr+5,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//XXXXXface0x3C  D889DFXXX、
{
offset=6;
}
else if(_tcsnicmp((LPCTSTR)midstr+6,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//XXXXXXface0x3  CD889DFXXX、
{
offset=7;
}
else if(_tcsnicmp((LPCTSTR)midstr+7,_T("face0x"),lstrlen(_T("face0x")))==0&&IsHexNumberStr(nextstr))//XXXXXXXface0x  3CD889DFXXX、
{
offset=8;
}
else if(_tcsnicmp((LPCTSTR)midstr+8,_T("face0"),lstrlen(_T("face0")))==0&&IsHexNumberStr(nextstr,1))//XXXXXXXXface0  x3CD889DFXXX
{
offset=9;
}
else if(_tcsnicmp((LPCTSTR)midstr+9,_T("face"),lstrlen(_T("face")))==0&&IsHexNumberStr(nextstr,2))//XXXXXXXXXface  0x3CD889DFXXX、
{
offset=10;
}
else if(_tcsnicmp((LPCTSTR)midstr+10,_T("fac"),lstrlen(_T("fac")))==0&&IsHexNumberStr(nextstr,3))//XXXXXXXXXXfac  e0x3CD889DFXXX、
{
offset=11;
}
else if(_tcsnicmp((LPCTSTR)midstr+11,_T("fa"),lstrlen(_T("fa")))==0&&IsHexNumberStr(nextstr,4))//XXXXXXXXXXXfa  ce0x3CD889DFXXX、
{
offset=12;
}
else if(_tcsnicmp((LPCTSTR)midstr+12,_T("f"),lstrlen(_T("f")))==0&&IsHexNumberStr(nextstr,5))//XXXXXXXXXXXXf  ace0x3CD889DFXXX
{
offset=13;
}




if(offset)
{
CString offsetstr=nextstr.Left(offset);
	mystr+=offsetstr;
	nextstr=nextstr.Mid(offset);
return offset;
}


	}
//

CString midstr=mystr.Right(6);
int midlen=midstr.GetLength();
int nextlen=nextstr.GetLength();
if(midlen<6||nextlen<1)
	return 0;

//face0x3CD889DF


if(_tcsnicmp(midstr,_T("face"),lstrlen(_T("face")))==0&&IsNumberStr(nextstr))//face12  4XXX这种分割
{
offset=1;
}
else if(_tcsnicmp((LPCTSTR)midstr+1,_T("face"),lstrlen(_T("face")))==0&&IsNumberStr(nextstr))//我face1  23XXX这种分割
{
	CString numstr;
	numstr.Format(_T("%d"),_ttoi(nextstr));
offset=lstrlen(numstr);
}
else if(_tcsnicmp((LPCTSTR)midstr+2,_T("face"),lstrlen(_T("face")))==0&&IsNumberStr(nextstr))//我和face  123XXX这种分割
{
	CString numstr;
	numstr.Format(_T("%d"),_ttoi(nextstr));
offset=lstrlen(numstr);
}
else if(_tcsnicmp((LPCTSTR)midstr+3,_T("fac"),lstrlen(_T("fac")))==0&&nextlen>1&&_tcsnicmp(nextstr,_T("e"),lstrlen(_T("e")))==0&&IsNumberStr((LPCTSTR)nextstr+1))//我和你fac  e23XXX这种分割
{
	CString numstr;
	numstr.Format(_T("%d"),_ttoi((LPCTSTR)nextstr+1));
offset=lstrlen(numstr)+1;
}
else if(_tcsnicmp((LPCTSTR)midstr+4,_T("fa"),lstrlen(_T("fa")))==0&&nextlen>2&&_tcsnicmp(nextstr,_T("ce"),lstrlen(_T("ce")))==0&&IsNumberStr((LPCTSTR)nextstr+2))//我和你fa  ce23XXX这种分割
{
	CString numstr;
	numstr.Format(_T("%d"),_ttoi((LPCTSTR)nextstr+2));
offset=lstrlen(numstr)+2;
}
else if(_tcsnicmp((LPCTSTR)midstr+5,_T("f"),lstrlen(_T("f")))==0&&nextlen>3&&_tcsnicmp(nextstr,_T("ace"),lstrlen(_T("ace")))==0&&IsNumberStr((LPCTSTR)nextstr+3))//我和你f  ace23XXX这种分割
{
	CString numstr;
	numstr.Format(_T("%d"),_ttoi((LPCTSTR)nextstr+3));
offset=lstrlen(numstr)+3;
}
if(offset)
{
CString offsetstr=nextstr.Left(offset);
	mystr+=offsetstr;
	nextstr=nextstr.Mid(offset);
}
return offset;
}

 UINT ProUploadSingle(LPVOID lp);
 int g_waitnum=0;
 UINT ProWaitUploadPrivateImg(LPVOID lp)
{
		_UploadGroupwaitImgStruct *pqqgroup=(_UploadGroupwaitImgStruct *)lp;
	
	BOOL bFind=false;
	
	set<CString> restimgpath=pqqgroup->needwaitimgpathset;
	int ncount=0;
	CString keystr;
	g_waitnum=restimgpath.size();
	for(auto it=restimgpath.begin();it!=restimgpath.end();it++)
	{

keystr.Format(_T("%lld_%s"),pqqgroup->toqq,*it);
lockpiuvect.Lock();

if (g_realrowNum>=1000)
	total_privateimgurlvect.push_back(keystr);

lockpiuvect.Unlock();


	}
	newprivateimgsendmsg.SetEvent();

	
	while(ncount<20)
	{
		if(g_waitnum<=0)
			break;
	ncount++;
	Sleep(1000);
	}


/*
		for(auto it=restimgpath.begin();it!=restimgpath.end();)
		{
keystr=*it;

	bFind=CheckSpecifyImgtoOtherQQ(pqqgroup->toqq,keystr);
	if(bFind)
	{
	
it=restimgpath.erase(it);
	}
	else
		it++;
		}

		if(restimgpath.size()==0||pqqgroup->defnumstr.Find(_T("图片未上传完则不发出消息"))==-1)
		*/

	//WaitForSingleObject(
	CString md5value;


	CString imgurlrpstr1, imgurlrpstr2;
	for (auto it = restimgpath.begin(); it != restimgpath.end(); it++)
	{
	lockpriwdsmd5Map.Lock();
	g_privatewebaddressmd5Map.Lookup(*it,md5value);
	lockpriwdsmd5Map.Unlock();
	imgurlrpstr1.Format(_T("[imgurl]%s[/imgurl]"), *it);
	imgurlrpstr2.Format(_T("[imgurl]%s[/imgurl]"), md5value);
	pqqgroup->defnumstr.Replace(imgurlrpstr1, imgurlrpstr2);
	}
			SendFinalMsg(pqqgroup->m_realgroupnumber,pqqgroup->toqq,pqqgroup->defnumstr,pqqgroup->backupuin,0,0,255,pqqgroup->msgid);
		
		delete pqqgroup;

		return 1;


}

UINT ProWaitUploadGroupImg(LPVOID lp)
{
		_UploadGroupwaitImgStruct *pqqgroup=(_UploadGroupwaitImgStruct *)lp;
	
	BOOL bFind=false;
	
	set<CString> restimgpath=pqqgroup->needwaitimgpathset;
	int ncount=0;
	while(ncount<10)
	{

		for(auto it=restimgpath.begin();it!=restimgpath.end();)
		{
	lockweb2md5mapres.Lock();
	bFind=g_web2md5Map.Lookup(*it);
			lockweb2md5mapres.Unlock();

	if(bFind)
	{
	
it=restimgpath.erase(it);
	}
	else
		it++;
		}
		if(restimgpath.size()==0)
			break;
	ncount++;
	Sleep(1000);
	}

	if(restimgpath.size()>0)
	{
	for(auto it=restimgpath.begin();it!=restimgpath.end();it++)
	{

_SingleUpload *ppp=new _SingleUpload;
			ppp->groupid=pqqgroup->m_realgroupnumber;
			ppp->m_hwnd=0;
			ppp->httpaddress=*it;
AfxBeginThread(ProUploadSingle,ppp);

	}

	Sleep(10*1000);
	}

		for(auto it=restimgpath.begin();it!=restimgpath.end();)
		{
	lockweb2md5mapres.Lock();
	bFind=g_web2md5Map.Lookup(*it);
			lockweb2md5mapres.Unlock();
	if(bFind)
	{
	
it=restimgpath.erase(it);
	}
	else
		it++;
		}

		CString imgurlrpstr1, imgurlrpstr2;
		CString md5value;
		for (auto it = pqqgroup->needwaitimgpathset.begin(); it != pqqgroup->needwaitimgpathset.end(); it++)
		{
			lockweb2md5mapres.Lock();
			g_web2md5Map.Lookup(*it, md5value);
			lockweb2md5mapres.Unlock();
			imgurlrpstr1.Format(_T("[imgurl]%s[/imgurl]"), *it);
			imgurlrpstr2.Format(_T("[imgurl]%s[/imgurl]"), md5value);
			pqqgroup->defnumstr.Replace(imgurlrpstr1, imgurlrpstr2);
		}

		if(restimgpath.size()==0||pqqgroup->defnumstr.Find(_T("图片未上传完则不发出消息"))==-1)
		SendFinalMsg(pqqgroup->m_realgroupnumber,pqqgroup->toqq,pqqgroup->defnumstr,pqqgroup->backupuin,0,0,255,pqqgroup->msgid);
		
		delete pqqgroup;

		return 1;


}





UINT ProUploadGroupImg(LPVOID lp)
{
		_UploadGroupImgStruct *pqqgroup=(_UploadGroupImgStruct *)lp;
	CString md5str;
	BOOL bAmrflag=false;
	
	if(StrStr(pqqgroup->httpaddress,_T(".amr")))
bAmrflag=true;
	CString postfixstr;
	byte *picsrc=NULL;
	byte *copypicsrc = NULL;
	BOOL bFindcopypic = false;
	UINT maxlen = 5 * 1024 * 1024;
	picsrc = new byte[maxlen + 1];
	int filesize=0;

		lockimgmd5bytesMap.Lock();

		bFindcopypic = g_priimgmd5bytesMap.Lookup(pqqgroup->httpaddress, copypicsrc);
		g_priimgmd5filelenMap.Lookup(pqqgroup->httpaddress, filesize);

		if (bFindcopypic&&filesize)
			memcpy(picsrc, copypicsrc, filesize);
 lockimgmd5bytesMap.Unlock();


 if (!bFindcopypic)
 {

	if(pqqgroup->bLocalFileflag&&pqqgroup->bLocalFileflag!=999)
	{


	filesize=::function::SafeGetStdMD5forFile(md5str,pqqgroup->httpaddress,picsrc,maxlen,true);
	}
	else
	{
		CString webmd5str;
		if(pqqgroup->bLocalFileflag!=999)
		{
			::function::SafeGetCff(webmd5str,pqqgroup->httpaddress.GetBuffer(0),pqqgroup->httpaddress.GetLength()*sizeof(TCHAR),true,true);
		}
		//::function::CFSoft_path(webmd5str,rtpath);
	CString	rtpath=g_groupimgdir+webmd5str;
	if(pqqgroup->bLocalFileflag!=999&&PathFileExists(rtpath))
	{
	
		filesize=::function::SafeGetStdMD5forFile(md5str,rtpath,picsrc,maxlen,true);
	}	
	else
	{
		CString webmd5str;
		if(pqqgroup->bLocalFileflag!=999)
		{
			::function::SafeGetCff(webmd5str,pqqgroup->httpaddress.GetBuffer(0),pqqgroup->httpaddress.GetLength()*sizeof(TCHAR),false,true);
		}
		//::function::CFSoft_path(webmd5str,rtpath);
	CString	rtpath=g_groupimgdir+webmd5str;
	if(pqqgroup->bLocalFileflag!=999&&PathFileExists(rtpath))
	{
	
		filesize=::function::SafeGetStdMD5forFile(md5str,rtpath,picsrc,maxlen,true);
	}	
	else
	{

		if(::function::DownloadHttpFile(pqqgroup->httpaddress,picsrc,maxlen)==0)
		filesize=maxlen;
		
		if(filesize)
		{
			::function::SafeGetCff(webmd5str,pqqgroup->httpaddress.GetBuffer(0),pqqgroup->httpaddress.GetLength()*sizeof(TCHAR),true,true);
		//::function::CFSoft_path(webmd5str,rtpath);
		rtpath=g_groupimgdir+webmd5str;
		CFile file1;
		if(file1.Open(rtpath,CFile::modeCreate|CFile::modeWrite))
		{
			file1.Write(picsrc,filesize);
		file1.Close();
		}

		}
		::function::SafeGetCff(md5str,picsrc,filesize,true,true);
	}
	}

	}

	if (filesize)
	{
		lockimgmd5bytesMap.Lock();
		g_priimgmd5bytesMap[pqqgroup->httpaddress] = picsrc;
		g_priimgmd5filelenMap[pqqgroup->httpaddress] = filesize;
		lockimgmd5bytesMap.Unlock();

	}
 }
 else
 {
 ::function::SafeGetCff(md5str,picsrc,filesize,true,true);
 }
 lockweb2md5mapres.Lock();
 if (!bAmrflag)
 {
	 
	 md5str.MakeUpper();
	 g_web2md5Map[pqqgroup->httpaddress] = md5str;


 }
 lockweb2md5mapres.Unlock();



	if(filesize)
	{
		if(bAmrflag)
			postfixstr=_T(".amr");
		else
	GetPostfixstr(picsrc,&postfixstr);

 lockmd52postfixmapres.Lock();
 g_md52postfixMap[(CStringA)md5str]=(CStringA)postfixstr;
lockmd52postfixmapres.Unlock();

		if(bAmrflag)
GetSynUploadGroupImg(pqqgroup->realqqgroup,g_interfaceuin,md5str,pqqgroup->httpaddress,postfixstr,filesize,30);
		else
	GetSynUploadGroupImg(pqqgroup->realqqgroup,g_interfaceuin,md5str,pqqgroup->httpaddress,postfixstr,filesize,30);

	BOOL result=false;
CString md5poststr,md5backstr;
md5poststr.Format(_T("%s%s"),md5str,postfixstr);
BOOL bFindmd5backflag=false;


	lockUpGroupImgmapres.Lock();
	bFindmd5backflag=g_UploadGroupImgMaxp.Lookup(md5poststr,md5backstr);
	lockUpGroupImgmapres.Unlock();

	if(!bAmrflag)
	{
		if(bFindmd5backflag&&md5backstr==md5str)
		{
			result=true;
			bFindmd5backflag=false;//不用再上传了
		}
		else
		{
			
			bFindmd5backflag=true;//用网页的方式上传
		
		}
	}

	
	{
		if(bFindmd5backflag)
		{

			CString realhostname;
			if(bAmrflag)
				realhostname=g_voicenextip;
			else
			{
				lockg_uploadimgip.Lock();
				realhostname=g_uploadimgnextip;
				lockg_uploadimgip.Unlock();
			}

			CString processpath;
			CString timestr2;
			//CString md5backstr=_T("4536E9891A989C6692E800C3468E5596C73399D4F3D30463D8C13A23884ADC5FC4C6EBBA05A2B79DC24583282C8A3D71F21B37F371F763557FE6496F651F39FC4D01C9A3DDEEAE53A8087C6CBCEB6AD8FCE18CAB048E307F338CD4174D57D6BA3F926CABC46676B3CF6D05E746D4BF930B22686BB5ACED342085B3566078B0FD");
			CString ukeystr=md5backstr;//_BIN::Bin2Hex();
			if(bAmrflag)
			{
				CString frontstr,backstr;
				if(::function::GetHalfStr(ukeystr,&frontstr,&backstr,_T("___")))
				{
					ukeystr=frontstr;
					md5backstr=backstr;
				}
			}
			if(bAmrflag)
				processpath.Format(_T("/?ver=4679&ukey=%s&filekey=%s&filesize=%d&range=0&bmd5=%s&mType=pttGu&voice_codec=0"),ukeystr,md5str,filesize,md5str);
			else
				processpath.Format(_T("/cgi-bin/httpconn?htcmd=0x6ff0071&ver=5468&term=android&ukey=%s&filesize=%d&range=0&uin=%lld&groupcode=%lld&mType=picGu"),md5backstr,filesize,g_interfaceuin,pqqgroup->realqqgroup);

			if(0)
			{
				MessageBox(0,processpath,0,0);
				processpath=_T("/?ver=4679&ukey=3081A502010104819D30819A0201010201010204B87B485F020200FF02044D02353B042445324141394136414342414336464646324543394332353342313730344530432E616D72020101020204F20410E2AA9A6ACBAC6FFF2EC9C253B1704E0C02045636DFCF04243830673056554E4551795875385A425547474671625057725F58694F32666C494D56343302030F42410204391EA3B402041853770A02046A9AAAE204000400&filekey=E2AA9A6ACBAC6FFF2EC9C253B1704E0C&filesize=1266&range=0&bmd5=E2AA9A6ACBAC6FFF2EC9C253B1704E0C&mType=pttGu&voice_codec=0");
			}
			//MessageBox(md5backstr,md5poststr,0);
			DWORD http_connect_flag=INTERNET_FLAG_TRANSFER_BINARY;

			char readbuf[10*1024];
			int maxlen=10*1024;
			int sendsize=filesize;
			const char *postdata=(const char*)picsrc;
			CString	strHeaders=_T("Accept-Encoding: identity\r\nConnection: close\r\nRange: bytes=0-\r\nUser-Agent: Dalvik/1.6.0 (Linux; U; Android 4.2.2; AndyWin Build/JDQ39E)\r\nContent-Type: application/x-www-form-urlencoded\r\n");
			CString lenstr;
			lenstr.Format(_T("Content-Length: %d\r\n"),sendsize);

			strHeaders+=lenstr;


			CHttpConnection* pConnection=NULL;

			boost::scoped_ptr<CInternetSession> p_session(new CInternetSession);
			try
			{

				pConnection =  p_session->GetHttpConnection(realhostname);
				if(!pConnection)
					if(bAmrflag)
					{
					GetNextVoiceIP();
					}
					else
					{
						GetNextUPloadImgIP();
					}
				CString newstrhd=strHeaders;
				CHttpFile* pFile=NULL;

				if(pConnection)
				{
					if(postdata==0||!strlen(postdata))
					{
						sendsize=0;
						pFile= pConnection->OpenRequest(CHttpConnection::HTTP_VERB_GET,processpath,0,1,0,0,http_connect_flag);
					}
					else
					{

						pFile= pConnection->OpenRequest(CHttpConnection::HTTP_VERB_POST,processpath,0,1,0,0,http_connect_flag);
					}

					if(pFile)
					{
						pFile->SetOption(INTERNET_OPTION_RECEIVE_TIMEOUT,200000);
						pFile->SetOption(INTERNET_OPTION_SEND_TIMEOUT,200000);



						{

							result=pFile->SendRequest(newstrhd,(LPVOID)postdata,sendsize);

						}

						DWORD status=0;
						if(pFile->QueryInfoStatusCode(status)==0||status>400)
						{

							sendsize=0;

						}

						if(readbuf)
						{
							int buflength=2048;
							byte buf[2048];
							int myoffset=0;
							sendsize=pFile->Read(buf,buflength);
							while(sendsize)
							{
								if(myoffset<=maxlen-2-sendsize)
									memcpy(readbuf+myoffset,buf,sendsize);
								else
									break;
								myoffset+=sendsize;
								sendsize=pFile->Read(buf,buflength);

							}
							if(sendsize==0)
							{
								DWORD   dw ;
								if(!::InternetQueryDataAvailable((HINTERNET)(*pFile),&dw,0,0)||(dw!=0))
								{

								}
							}
							readbuf[myoffset]=0;
							readbuf[myoffset+1]=0;

							sendsize=myoffset;
							if(bAmrflag&&strstr(readbuf,"was not found"))
								GetNextVoiceIP();


						}

						pFile->Close();
						delete pFile;
					}
				}

			}
			catch(...)
			{
				sendsize=0;
				result=false;
				if(bAmrflag)
					GetNextVoiceIP();
				else
					GetNextUPloadImgIP();
			}

		}
	}
	if(result)
	{
		lockweb2md5mapres.Lock();
		if(bAmrflag)
		{
			g_web2md5Map[pqqgroup->httpaddress]=md5backstr;
		}
		else
		{
			md5str.MakeUpper();
			g_web2md5Map[pqqgroup->httpaddress]=md5str;
		}
		lockweb2md5mapres.Unlock();
		CString webmd5str;
		CString rtpath;
		//if(!pqqgroup->bLocalFileflag)
		if(bAmrflag)
		{
			if(!g_alwaysuploadvoice)
			{
				CFile file1;
				if(file1.Open(pqqgroup->httpaddress,CFile::modeCreate|CFile::modeWrite))
				{
					file1.Write(picsrc,filesize);

					file1.Write(&filesize,sizeof(UINT));
					file1.Write((const char*)(CStringA)md5str,md5str.GetLength());
					file1.Write((const char*)(CStringA)md5backstr,md5backstr.GetLength());

					file1.Close();
				}
			}
			
			if(g_deletevoicefile)
			{
			DeleteFile(pqqgroup->httpaddress);
			}

			vector<byte> mysendv;


			int myseq=0;
			mysendv=sdk.Pack_PbVoiceSendMessage(pqqgroup->realqqgroup,pqqgroup->realqq,filesize,(CStringA)md5str,(CStringA)md5backstr,myseq);

			//mysendv=sdk.Pack_PbVoiceSendMessage(m_realgroupnumber,toqq,"7BD0DE968B327BC9EC9742DADDEF2C3E","00g0FVNEQyXu8ZRugXJBbaPu9P#B2FtTLPyf",myseq);													 // 90g0XTNEQiM5T2X#udIkkPUZahEOyWqh#MNC
			//mysendv=sdk.Pack_PbVoiceSendMessage(m_realgroupnumber,toqq,amrfilesize,"7BD0DE968B327BC9EC9742DADDEF2C3E","00g0FVNEQyXu8ZRugXJBbaPu9P#B2FtTLPyf",myseq);


			Fun_send(mysendv);

		}
		else
		{
			::function::SafeGetCff(webmd5str,pqqgroup->httpaddress.GetBuffer(0),pqqgroup->httpaddress.GetLength()*sizeof(TCHAR),true,true);
			//::function::CFSoft_path(webmd5str,rtpath);
			rtpath=g_groupimgdir+webmd5str;
			CFile file1;
			if(file1.Open(rtpath,CFile::modeCreate|CFile::modeWrite))
			{
				file1.Write(picsrc,filesize);
				file1.Close();
			}

		}
	}


	}


CEvent  *tempevent=NULL;
	lockupgroupimgeventmapres.Lock();
	if(!g_upgroupimgeventMap.Lookup(pqqgroup->httpaddress,tempevent))
		{
			
		}
	else
	{
	if(tempevent)
	tempevent->SetEvent();
	}
	lockupgroupimgeventmapres.Unlock();
	

		lockimgmd5bytesMap.Lock();

		g_priimgmd5bytesMap.RemoveKey(pqqgroup->httpaddress);
		g_priimgmd5filelenMap.RemoveKey(pqqgroup->httpaddress);

		lockimgmd5bytesMap.Unlock();
		delete[]picsrc;


	delete pqqgroup;

		return 1;


}

void CallffmpegRarFun(const CString& sourcepath)
{
	CString distPath;

	CString Ignorefilename;
	Ignorefilename = _T("机器人插件\\ffmpeg.exe");//SaveAs_complete_path(tempstr);

	CString ffmpegpath = SaveAs_complete_path(Ignorefilename);
	if (!PathFileExists(ffmpegpath))
	{
	MessageBox(mainhwnd,_T("缺少ffmpeg.exe,请到http://www.qqshow123.com/game/ffmpeg.exe下载，或者联系QQ13402429索取此文件，否则无法使用语音转换功能！"),_T("缺少ffmpeg.exe"),0);
	
		return;
	}
	if (!PathFileExists(sourcepath))
		return;

	distPath = sourcepath;
	distPath.Replace(_T(".amr"), _T(".wav"));
	CString sourcePath2 = sourcepath;
	sourcePath2.Replace(_T(".amr"), _T(".pcm"));

	CFile amrfile1;

	if (amrfile1.Open(sourcepath, CFile::modeRead | CFile::shareDenyNone))
	{
		UINT maxlen = 5 * 1024 * 1024;
		char *instr = new char[maxlen];
		char *pcmbuf = new char[maxlen];

		maxlen=amrfile1.Read(instr, maxlen);
		
		amrfile1.Close();


		BOOL bAmrflag = false;
		UINT rtpcmlen = 0;
		BOOL bbbflag = false;
		UINT orgsavelen = maxlen;
		if (strncmp((char*)instr + 1, "#!SILK_V3", strlen("#!SILK_V3")) == 0)
			bbbflag = slk2pcmfun((byte*)instr + 1, maxlen - 1, (byte*)pcmbuf, &rtpcmlen);
		else if (strncmp((char*)instr, "#!SILK_V3", strlen("#!SILK_V3")) == 0)
			bbbflag = slk2pcmfun((byte*)instr, maxlen, (byte*)pcmbuf, &rtpcmlen);
		//ffmpeg -y -f s16le -ar 8000 -ac 1 -i "8000.pcm" -f wav -ar 8000 -b:a 16 -ac 1 16.wav
		if (!bbbflag)
		{
			if (strncmp((char*)instr, "#!AMR", strlen("#!AMR")) == 0)
			{

				bbbflag = true;
				bAmrflag = true;
			}
		}

		CFile pcmfile1;

		if (pcmfile1.Open(sourcePath2, CFile::modeCreate | CFile::modeWrite))
		{
			pcmfile1.Write(pcmbuf, rtpcmlen);
			pcmfile1.Close();
		}
		delete[]instr;//创建一个真正pcm文件
		delete[]pcmbuf;
		CString pathstr, filestr, onlyfname;


		PROCESS_INFORMATION   pidInfo;
		STARTUPINFO     startInfo;
		BOOL b;
		CString winrarstr;
		CString realrar = sourcepath;
		if (bAmrflag)
		{
			winrarstr.Format(_T("\"%s\" -i \"%s\" \"%s\""), ffmpegpath, realrar, distPath);


			
		}
		else
		{
			winrarstr.Format(_T("\"%s\" -y -f s16le -ar 16000 -ac 1 -i \"%s\" -f wav -ar 16000 -b:a 16 -ac 1 \"%s\""), ffmpegpath, sourcePath2, distPath);

		}
		//ffmpeg -i 1.mp3 -ac 1 -ar 8000 1.amr
		//ffmpeg -y -f s16le -ar 8000 -ac 1 -i "8000.pcm" -f wav -ar 8000 -b:a 16 -ac 1 16.wav
		//winrarstr=_T("\"C:\\Program Files\\WinRAR\\WinRAR.exe\" x  -o+  \"e:\\CFcomboxdemo.zip\" \"d:\\winrartest\\CFcomboxdemo\\\"");
		startInfo.cb = sizeof(STARTUPINFO);
		startInfo.lpReserved = NULL;
		startInfo.lpTitle = NULL;
		startInfo.lpDesktop = NULL;
		startInfo.dwX = 0;
		startInfo.dwY = 0;
		startInfo.dwXSize = 0;
		startInfo.dwYSize = 0;
		startInfo.dwXCountChars = 0;
		startInfo.dwYCountChars = 0;
		startInfo.dwFlags = STARTF_USESHOWWINDOW;//STARTF_USESTDHANDLES; 
		startInfo.wShowWindow = SW_HIDE;   //SW_SHOWDEFAULT; 
		startInfo.lpReserved2 = NULL;
		startInfo.cbReserved2 = 0;
		startInfo.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
		startInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		startInfo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
		b = CreateProcess(NULL, winrarstr.GetBuffer(0), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &startInfo, &pidInfo);
		if (!b) {

			return;
		}

		WaitForSingleObject(pidInfo.hProcess, INFINITE);
		CloseHandle(pidInfo.hProcess);
		CloseHandle(pidInfo.hThread);
		DeleteFile(sourcePath2);

	}
}

void CallWinRarFun(const CString& sourcepath,const CString& distPath)
{
	
			CString Ignorefilename;
Ignorefilename=_T("机器人插件\\ffmpeg.exe");//SaveAs_complete_path(tempstr);

CString ffmpegpath=SaveAs_complete_path(Ignorefilename);
	if(!PathFileExists(ffmpegpath))
	{
	MessageBox(mainhwnd,_T("缺少ffmpeg.exe,请到http://www.qqshow123.com/game/ffmpeg.exe下载，或者联系QQ13402429索取此文件，否则无法使用语音转换功能！"),_T("缺少ffmpeg.exe"),0);
	
		return;
	}
	CString pathstr,filestr,onlyfname;
	

	PROCESS_INFORMATION   pidInfo; 
	STARTUPINFO     startInfo; 
	BOOL b; 
	CString winrarstr;
	CString realrar=sourcepath;
	winrarstr.Format(_T("\"%s\" -i \"%s\" -ac 1 -ar 8000 \"%s\""),ffmpegpath,realrar,distPath);
	//ffmpeg -i 1.mp3 -ac 1 -ar 8000 1.amr
	//winrarstr=_T("\"C:\\Program Files\\WinRAR\\WinRAR.exe\" x  -o+  \"e:\\CFcomboxdemo.zip\" \"d:\\winrartest\\CFcomboxdemo\\\"");
	startInfo.cb           =   sizeof(STARTUPINFO); 
	startInfo.lpReserved   =   NULL; 
	startInfo.lpTitle     =   NULL; 
	startInfo.lpDesktop   =   NULL; 
	startInfo.dwX         =   0; 
	startInfo.dwY         =   0; 
	startInfo.dwXSize     =   0; 
	startInfo.dwYSize     =   0; 
	startInfo.dwXCountChars     =   0; 
	startInfo.dwYCountChars     =   0; 
	startInfo.dwFlags     =   STARTF_USESHOWWINDOW;//STARTF_USESTDHANDLES; 
	startInfo.wShowWindow   =   SW_HIDE;   //SW_SHOWDEFAULT; 
	startInfo.lpReserved2   =   NULL; 
	startInfo.cbReserved2   =   0; 
	startInfo.hStdInput   =   GetStdHandle(STD_INPUT_HANDLE); 
	startInfo.hStdOutput   =   GetStdHandle(STD_OUTPUT_HANDLE); 
	startInfo.hStdError   =   GetStdHandle(STD_ERROR_HANDLE);   
	b=CreateProcess(NULL,winrarstr.GetBuffer(0),NULL,NULL,TRUE,CREATE_NO_WINDOW,NULL,NULL,&startInfo,&pidInfo); 
	if(!b){ 

		return; 
	} 

	WaitForSingleObject(pidInfo.hProcess,INFINITE); 
	CloseHandle(pidInfo.hProcess); 
	CloseHandle(pidInfo.hThread); 

}

void PackToXmlMsg(CString& newmsgcontent,LPCTSTR newxmlstrbuf)
{
	CString newxmlstr=newxmlstrbuf;
CStringvect vectemp;

	if(g_xmlkeeponelineflag)
		vectemp.push_back(newmsgcontent);
	else
	::function::getmytoken(newmsgcontent,_T("\n"),vectemp);
	
	CString strmmm;
	//if(1)//newmsgcontent.GetLength()<500)
	//{
	for(int i=0;i<vectemp.size();i++)
	{
		//默认的卡片消息格式
		if(vectemp[i].Find(_T("<msg"))==0||vectemp[i].Find(_T("</item>"))==0||vectemp[i].Find(_T("</msg>"))!=-1)
		{
			strmmm=vectemp[i];

		}
		else
		{
			
	if(vectemp[i].Find(_T("[imgurl]http://"))==0&&vectemp[i].Find(_T("[/imgurl]"))!=-1)
			{
				//<picture cover="http://qlogo4.store.qq.com/qzone/13402429/13402429/100" />

				CString httpimgurl=vectemp[i];
				if(TrimLeft(httpimgurl,_T("[imgurl]http://"))&&TrimRight(httpimgurl,_T("[/imgurl]")))
				{
			strmmm.Format(_T("<picture cover=\"http://%s\" />"),httpimgurl);
				 newxmlstr+=strmmm;
				 continue;
				}

			}

CString httpimgurl=vectemp[i];

	if(TrimLeft(httpimgurl,_T("[imgurl]"))&&TrimRight(httpimgurl,_T("[/imgurl]")))
	{
				//<picture cover="http://qlogo4.store.qq.com/qzone/13402429/13402429/100" />

				
			
					//{DE236835-AB03-A494-2A03-509244D8328B}.gif|
					if(httpimgurl.Find(_T("{"))!=-1||httpimgurl.Find(_T("-"))!=-1||httpimgurl.Find(_T(".gif"))!=-1||httpimgurl.Find(_T(".jpg"))!=-1||httpimgurl.Find(_T(".png"))!=-1)
					{
					httpimgurl.Replace(_T("{"),_T(""));
					httpimgurl.Replace(_T(""),_T("}"));
httpimgurl.Replace(_T("-"),_T(""));
httpimgurl.Replace(_T("|"),_T(""));
httpimgurl.Replace(_T(".gif"),_T(""));
httpimgurl.Replace(_T(".jpg"),_T(""));
httpimgurl.Replace(_T(".png"),_T(""));

					}

			strmmm.Format(_T("<picture cover=\"http://gchat.qpic.cn/gchatpic_new//--%s/0\" />"),httpimgurl);
				 newxmlstr+=strmmm;
				 continue;
			
				


	}

			if(vectemp[i].Find(_T("<picture cover=\""))==0&&vectemp[i].Find(_T(">"))!=-1)
			{
			strmmm=vectemp[i];
			}
			else if(vectemp[i].Find(_T("<summary"))==0&&vectemp[i].Find(_T(">"))!=-1)
			{
			strmmm=vectemp[i];
			}
			else
			{
			if((*p_g_xmlformatstr).IsEmpty())
	strmmm.Format(_T("<summary color=\"#卡片文字随机颜色\">%s</summary>"),vectemp[i]);
			else
			{
				//如果是随机颜色，自动换

	strmmm.Format((*p_g_xmlformatstr),vectemp[i]);
			}

			
			if(strmmm.Find(_T("卡片文字随机颜色"))!=-1)
			{

	DWORD ddd=GetRandColor(true);
	CString randcolorstr;
	randcolorstr.Format(_T("%06X"),ddd);
	strmmm.Replace(_T("卡片文字随机颜色"),randcolorstr);
	}
			}
		}
	 newxmlstr+=strmmm;
	}
	/*}
	else
	{

	for(int i=0;i<vectemp.size();i+=3)
	{
		if(i+2<vectemp.size())
		{
	strmmm.Format(_T("<summary color=\"#FF0000\">%s\n%s\n%s</summary>"),vectemp[i],vectemp[i+1],vectemp[i+2]);
		}
		else if(i+1<vectemp.size())
		{
	strmmm.Format(_T("<summary color=\"#FF0000\">%s\n%s</summary>"),vectemp[i],vectemp[i+1]);
		}
		else
		{
	strmmm.Format(_T("<summary color=\"#FF0000\">%s</summary>"),vectemp[i]);
		}


	 newxmlstr+=strmmm;
	}
	*/
	//}
	if(newxmlstr.Find(_T("</msg>"))==-1)
	{
	if((*p_g_xmliconstr).IsEmpty())
	{	
		CString tempiconstr;
tempiconstr.Format(_T("</item><source name=\"%s\" icon=\"http://imgcache.qq.com/king/pic/tequan/jb.png\"  url=\"\"/>"),g_defaultqqgrouprule.g_robotname);
		//</item><source name="晨风机器人" icon="http://i.gtimg.cn/open/app_icon_m.png"  url=""/>
 newxmlstr+=tempiconstr;
 newxmlstr+=_T("</msg>");
	}
	else
	{
 //newxmlstr+=_T("</item>");
 newxmlstr+=(*p_g_xmliconstr);
  newxmlstr+=_T("</msg>");
	}
	}
 newmsgcontent=newxmlstr;




}
int Pack2XmlMsgByPartNum(const CString& oldnewmsgcontent,CString& newmsgcontent,LPCTSTR newxmlstr,float partnum)
{
	BOOL bNoreturnnflag=false;
	if(oldnewmsgcontent.Find(_T("\n"))==-1)
		{
			bNoreturnnflag=true;
	}
	if(1)//partnum!=1)
	{
		if(1)//!bNoreturnnflag)
		{
		CStringvect vectemp;
	
	::function::getmytoken(oldnewmsgcontent,_T("\n"),vectemp);
	int newsize=vectemp.size()*partnum;
	if(!newsize)
		newsize=1;
	vectemp.resize(newsize);

	newmsgcontent=_T("");
	CString templinestr;
	for(int i=0;i<vectemp.size();i++)
	{
		templinestr=vectemp[i];
	if((*p_g_autoreturnfalg)&&templinestr.Find(_T("http://"))==-1&&templinestr.Find(_T("face"))==-1)
	{
		int times=(vectemp[i].GetLength()+((*p_g_autoreturnfalg)-1))/(*p_g_autoreturnfalg);
		templinestr=_T("");
	//int halflen=vectemp[i].GetLength()/2;
		if(times>1)
		{
			for(int n=0;n<times;n++)
			{
				templinestr+=vectemp[i].Mid(n*(*p_g_autoreturnfalg),(*p_g_autoreturnfalg));
				templinestr+=_T("\n");
			}
			TrimRight(templinestr,_T("\n"));
		}
		else
templinestr=vectemp[i];

	}
	newmsgcontent+=templinestr;
	
		newmsgcontent+=_T("\n");
	}

	TrimRight(newmsgcontent,_T("\n"));

	if(bNoreturnnflag)
newmsgcontent=newmsgcontent.Left(newmsgcontent.GetLength()*partnum);
		

		}
		else
		{
		
	newmsgcontent=oldnewmsgcontent.Left(oldnewmsgcontent.GetLength()*partnum);
		
		}
		if(partnum!=1)
	newmsgcontent+=_T("\n……");

	}
	else 
		if(bNoreturnnflag)
		{
		CString templinestr=newmsgcontent;
		if((*p_g_autoreturnfalg)&&(templinestr.Find(_T("http://"))==-1&&templinestr.Find(_T("<picture cover="))==-1)&&templinestr.Find(_T("face"))==-1)
	{
	int times=(oldnewmsgcontent.GetLength()+((*p_g_autoreturnfalg)-1))/(*p_g_autoreturnfalg);
	templinestr=_T("");
	//int halflen=vectemp[i].GetLength()/2;
		for(int n=0;n<times;n++)
		{
	templinestr+=oldnewmsgcontent.Mid(n*(*p_g_autoreturnfalg),(*p_g_autoreturnfalg));
	templinestr+=_T("\n");
		}
newmsgcontent=templinestr;
	}
		
	
	
		}

	PackToXmlMsg(newmsgcontent,newxmlstr);

	int finalmaxsize=0;
	if(!(*p_g_xmlmaxsize))
		finalmaxsize=730;
	else
		finalmaxsize=(*p_g_xmlmaxsize);

	finalmaxsize=max(400,finalmaxsize);

	if (newmsgcontent.GetLength()>finalmaxsize)
	{
		CStringA out_utfbuf;
		::function::wchrto_utf8(newmsgcontent, out_utfbuf);
		byte *outstr = new byte[out_utfbuf.GetLength() * 10];
		uLong outsize2 = out_utfbuf.GetLength() * 10;
		int err = gzcompress((byte*)out_utfbuf.GetBuffer(0), out_utfbuf.GetLength(), outstr, &outsize2);
		delete[]outstr;

		if (outsize2>finalmaxsize)
		{
			return 0;
			//newmsgcontent=oldnewmsgcontent.Left(oldnewmsgcontent.GetLength()*partnum);
			//newmsgcontent+=_T("\n……");

			//PackToXmlMsg(newmsgcontent,newxmlstr);

		}
		else
			return 1;

	}
//字数太少，用卡片也发不出来
	if (newmsgcontent.GetLength()<589 && newmsgcontent.Find(_T("\n")) == -1)
	{
	
	CStringA out_utfbuf;
	::function::wchrto_utf8(newmsgcontent,out_utfbuf);
	byte *outstr=new byte[out_utfbuf.GetLength()*10];
uLong outsize2=out_utfbuf.GetLength()*10;
int err=gzcompress((byte*)out_utfbuf.GetBuffer(0),out_utfbuf.GetLength(),outstr,&outsize2);
delete []outstr;

if (outsize2<357)
{
	if(g_transfertonoxmlwhenless)
	return 2;
	else
	{
		if (g_xmlstuff.IsEmpty() || !bNoreturnnflag)
		return 1;
		else
			return 3;

	}
//newmsgcontent=oldnewmsgcontent.Left(oldnewmsgcontent.GetLength()*partnum);
//newmsgcontent+=_T("\n……");

	//PackToXmlMsg(newmsgcontent,newxmlstr);

}
else
	return 1;

	}



	return 1;
}
BOOL GetLastFilemd5Value(CString& temprtmd5,byte* copypicsrc,byte* picsrc,int& filesize)
{
	BOOL bfind = false;
	lockimgmd5bytesMap.Lock();

	bfind = g_priimgmd5bytesMap.Lookup(temprtmd5, copypicsrc);
	g_priimgmd5filelenMap.Lookup(temprtmd5, filesize);
	if (bfind)
	memcpy(picsrc, copypicsrc, filesize);
	lockimgmd5bytesMap.Unlock();
	return bfind;
}
BOOL GetFilemd5Value(CString& temprtmd5,BOOL localflag,BOOL httpflag,BOOL bPrivateimgflag)
{
byte *picsrc=NULL;
byte* copypicsrc = NULL;
	int filesize=0;
	BOOL bFindOtherpicsrc = false;
	CString md5str;
UINT maxlen=5*1024*1024;
	lockimgmd5bytesMap.Lock();

 g_priimgmd5bytesMap.Lookup(temprtmd5,picsrc);
	  g_priimgmd5filelenMap.Lookup(temprtmd5,filesize);
	  if(picsrc&&filesize)
	  {
	  	::function::SafeGetCff(md5str,picsrc,filesize,true,true);
		 temprtmd5=md5str;
		 lockimgmd5bytesMap.Unlock();
	  return true;
	  }
	  
	

 lockimgmd5bytesMap.Unlock();

		
	
	picsrc=new byte[maxlen+1];
	


		if(localflag)
	{
			
filesize=::function::SafeGetStdMD5forFile(md5str,temprtmd5,picsrc,maxlen,true);

	}
	else if(httpflag)
	{
			
			CString webmd5str;
		::function::SafeGetCff(webmd5str,temprtmd5.GetBuffer(0),temprtmd5.GetLength()*sizeof(TCHAR),!bPrivateimgflag,true);
		//::function::CFSoft_path(webmd5str,rtpath);
	CString	rtpath=g_groupimgdir+webmd5str;
	if(PathFileExists(rtpath))
	{
	
		filesize=::function::SafeGetStdMD5forFile(md5str,rtpath,picsrc,maxlen,true);
	}
	else
	{
			CString webmd5str;
		::function::SafeGetCff(webmd5str,temprtmd5.GetBuffer(0),temprtmd5.GetLength()*sizeof(TCHAR),bPrivateimgflag,true);
		//::function::CFSoft_path(webmd5str,rtpath);
	CString	rtpath=g_groupimgdir+webmd5str;
	if(PathFileExists(rtpath))
	{
	
		filesize=::function::SafeGetStdMD5forFile(md5str,rtpath,picsrc,maxlen,true);

	}
	else
	{
		if (!GetLastFilemd5Value(temprtmd5, copypicsrc,picsrc,filesize))
		{

			//if (::function::DownloadHttpFile(temprtmd5, picsrc, maxlen) == 0)
			//	filesize = maxlen;

			//::function::SafeGetCff(md5str, picsrc, filesize, true, true);
			//CString webmd5str;
			//if (bPrivateimgflag)
			//{

			//	::function::SafeGetCff(webmd5str, temprtmd5.GetBuffer(0), temprtmd5.GetLength()*sizeof(TCHAR), false, true);
			//}
			//else
			//	::function::SafeGetCff(webmd5str, temprtmd5.GetBuffer(0), temprtmd5.GetLength()*sizeof(TCHAR), true, true);
			////::function::CFSoft_path(webmd5str,rtpath);
			//CString	rtpath = g_groupimgdir + webmd5str;
			//CFile file1;

			//if (file1.Open(rtpath, CFile::modeCreate | CFile::modeWrite))
			//{
			//	file1.Write(picsrc, filesize);
			//	file1.Close();
			//}

		}
		else
		{
			
		
			bFindOtherpicsrc = true;
		}

		
	}
	}

	}

		if (1)//bFindOtherpicsrc)
		{
			delete []picsrc;
		}
		/*else
		{
			if (filesize)
			{

				lockimgmd5bytesMap.Lock();
				g_priimgmd5bytesMap[temprtmd5] = picsrc;
				g_priimgmd5filelenMap[temprtmd5] = filesize;
				lockimgmd5bytesMap.Unlock();

				temprtmd5 = md5str;
			}
		}*/
		//delete []picsrc;

if(filesize)
	return true;
else 
	return false;

}

CString emoji11flag2unicode(const CString& emojibuf)
{
	//int emojivalue=_tcstol(orgstr,0,16);
	byte h1=0;
	byte h2=0;
	byte l1=0;
	byte l2=0;
	CString left2;
	l1=_tcstol(emojibuf.Right(2),NULL,16);
	CString newemojibuf=emojibuf.Left(emojibuf.GetLength()-2);
	if(newemojibuf.GetLength()>0)
	l2=_tcstol(newemojibuf.Right(2),NULL,16);

newemojibuf=newemojibuf.Left(newemojibuf.GetLength()-2);
if(newemojibuf.GetLength()>0)
	h1=_tcstol(newemojibuf.Right(2),NULL,16);

newemojibuf=newemojibuf.Left(newemojibuf.GetLength()-2);
if(newemojibuf.GetLength()>0)
	h2=_tcstol(newemojibuf.Right(2),NULL,16);

	//0x3420e3;
	//face0x3400E320
	CString newstr;
	//newstr.Format(_T("face0x%02x%02x%02x%02x"),*((byte*)&h),*((byte*)&h+1),*((byte*)&l),*((byte*)&l+1));
	TCHAR wnum[3]={ 0,0,0 };


	memcpy(wnum,&h1,1);
memcpy((byte*)wnum+1,&h2,1);
	memcpy((byte*)wnum+2,&l1,1);
memcpy((byte*)wnum+3,&l2,1);
	/*if(0)
	{
	memcpy(wnum,&l,2);
	memcpy(wnum+2,&h,2);
	}*/
	wnum[2]=0;
	newstr=wnum;
	return newstr;
}
				//$h = 0xd83d; //高位  face0x3dd8 03de
				//$l = 0xde04; //低位 
				//$code = ($h - 0xD800) * 0x400 + 0x10000 + $l - 0xDC00; // 转换算法 
				//echo "U+".strtoupper(dechex($code));
CString untifed2unicode(int emojivalue)
{
	//int emojivalue=_tcstol(orgstr,0,16);
	short h;
	short l;
	if(emojivalue>0x10000)
	{
		h=floor(float((emojivalue-0x10000)/0x400))+0xD800;
		l=(emojivalue-0x10000)%0x400+0xDC00;
	}
	else
	{

	h=emojivalue;
		l=0x0000;

	}
	CString newstr;
	//newstr.Format(_T("face0x%02x%02x%02x%02x"),*((byte*)&h),*((byte*)&h+1),*((byte*)&l),*((byte*)&l+1));
		TCHAR wnum[3]={0,0,0};

		
					memcpy(wnum,&h,2);
					memcpy(wnum+1,&l,2);
					/*if(0)
					{
						memcpy(wnum,&l,2);
					memcpy(wnum+2,&h,2);
					}*/
					wnum[2]=0;
					newstr=wnum;
	return newstr;
}
void ConvertEmoji2Unicode(CString& newmsgcontent)
{
	//<span class=\"emoji emoji1f618\"></span><span class=\"emoji emoji1f618\"></span>
	if(StrStr(newmsgcontent,_T("emoji")))
	{
		CString expressstr;
		//emoji1F303emoji1F344face0x3DD816DEface0x3DD837DEemoji2600emoji2601
		CStringvect vectemp;
		::function::getmytokenForKey(newmsgcontent,_T("emoji"),vectemp);
		CString oldstr,newstr;
		CString temp5str;
		UINT temphexvalue=0;
			UINT emvalue1=0;
			UINT emvalue2=0;
		//emoji1F344
		BOOL b11emojiflag=false;
		
		for(int i=0;i<vectemp.size();i++)
		{
			b11emojiflag=false;
			BOOL b15emojiflag=false;
			if(vectemp[i].GetLength()>=15)//emoji1f1e81f1f3
			{
				temp5str=vectemp[i].Mid(5,10);
			
				emvalue1=_tcstol(temp5str.Left(5),0,16);
				emvalue2=_tcstol(temp5str.Mid(5,10),0,16);
				if(emvalue2>0x1000)
				b15emojiflag=true;
			}
			if(!b15emojiflag)
			{
				if(vectemp[i].GetLength()>=11)
				{
					temp5str=vectemp[i].Mid(5,6);
					//emoji3420e3
					temphexvalue=_tcstol(temp5str,0,16);
					if(temphexvalue>0x100000)
						b11emojiflag=true;
				}
				else if(vectemp[i].GetLength()>=10)
					temp5str=vectemp[i].Mid(5,5);
				else
					temp5str=vectemp[i].Mid(5,4);
			}
		

			if(b15emojiflag)
			{

				CString em1=untifed2unicode(emvalue1);
				CString em2=untifed2unicode(emvalue2);
				newstr=em1+em2;
				CString comem12;
				
				comem12.Format(_T("%x%x"),emvalue1,emvalue2);
				

				oldstr.Format(_T("emoji%s"),comem12);

				newmsgcontent.Replace(oldstr,newstr);
				
				comem12.Format(_T("%X%X"),emvalue1,emvalue2);
				

				oldstr.Format(_T("emoji%s"),comem12);

				newmsgcontent.Replace(oldstr,newstr);
			
			}
			else
			{
			temphexvalue=_tcstol(temp5str,0,16);
			if(b11emojiflag)
			{
				newstr=emoji11flag2unicode(temp5str);
			}
			else
			newstr=untifed2unicode(temphexvalue);

			if(temphexvalue)
			{
				oldstr.Format(_T("emoji%x"),temphexvalue);
				newmsgcontent.Replace(oldstr,newstr);
				oldstr.Format(_T("emoji%X"),temphexvalue);
				newmsgcontent.Replace(oldstr,newstr);
			}

			}
		
		/*	oldstr.Format(_T("emoji%s"),temp5str);
		newmsgcontent.Replace(oldstr,newstr);*/
			


		}

		//CStringvect weather6vect;
		//expressstr.Format(_T("(?<=emoji)\\w{4,5}"));

		//GetRegEX(newmsgcontent,expressstr,weather6vect,0,true);//need consider of the actual keyname

		//if(weather6vect.size())
		//{

		//	CString oldstr;
		//	for(int i=0;i<weather6vect.size();i++)
		//	{
		//		CString newstr=untifed2unicode(weather6vect[i]);
		//		oldstr.Format(_T("emoji%s"),weather6vect[i]);
		//		newmsgcontent.Replace(oldstr,newstr);

		//	}

		//}


	}
	if(StrStr(newmsgcontent,_T("face0x")))
	{
		CString expressstr;
		CStringvect weather6vect;
		expressstr.Format(_T("(?<=face0x)\\w{8}"));
		GetRegEX(newmsgcontent,expressstr,weather6vect,0,true);//need consider of the actual keyname

		if(weather6vect.size())
		{
			CString newstr,oldstr;
			TCHAR wnum[3]={ 0,0,0 };

			for(int i=0;i<weather6vect.size();i++)
			{
				oldstr.Format(_T("face0x%s"),weather6vect[i]);
				if(newmsgcontent.Find(oldstr)!=-1)
				{
					UINT newnum=htonl(_tcstol(weather6vect[i],0,16));
					memcpy(wnum,&newnum,4);
					wnum[2]=0;

					newstr=wnum;

					newmsgcontent.Replace(oldstr,newstr);
				}
			}

		}


	}

}

BOOL SendFinalMsg(INT64 m_realgroupnumber,INT64 toqq,CString& defnumstr,INT64 backupuin,BOOL bAutoTransfertoXMLflag,BOOL bExactXmlflag,int maxsize,INT64 quotemsgid)
{
	BOOL bflashFlag=false;
	BOOL bshowFlag=false;
	int biaoshinum=0;
defnumstr.Replace(_T("图片未上传完则不发出消息"),_T(""));

defnumstr.Replace(_T("图片上传完再发出消息"),_T(""));

defnumstr.Replace(_T("【隐藏消息记录】"),_T(""));
defnumstr.Replace(_T("【不替换昵称】"),_T(""));

if(toqq)
	quotemsgid=0;//只有在群里发的消息，toqq=0，才可以回复引用。


if(defnumstr.Find(_T("【发闪图】"))!=-1||defnumstr.Find(_T("【发闪照】"))!=-1)
{
	
	bflashFlag=true;
	defnumstr.Replace(_T("【发闪图】"),_T(""));
defnumstr.Replace(_T("【发闪照】"),_T(""));

}

if(defnumstr.Find(_T("【发秀图"))!=-1)
{
	
	int pos=defnumstr.Find(_T("【发秀图"));
	bshowFlag=1;//无效，暂时关闭
biaoshinum=_ttoi(defnumstr.GetBuffer(0)+pos+lstrlen(_T("【发秀图")));

if(biaoshinum==0)
{
	if(defnumstr.Find(_T("【发秀图】"))!=-1)
	{
		biaoshinum=1;
	defnumstr.Replace(_T("【发秀图】"),_T(""));
	}
}

CString biaoshistr;
biaoshistr.Format(_T("【发秀图%d】"),biaoshinum);
	defnumstr.Replace(biaoshistr,_T(""));



	if(bshowFlag)
	{
	//CString skeyvalue;
	//GetSkey(skeyvalue,ptwebqqhash,verifysessionhash);
		//if(1)
		//Fun_send(sdk.Pack_ShowimgMsg(m_realgroupnumber));
	}
}

if(defnumstr.Find(_T("仅用于预先上传图片而不显示消息"))!=-1)
defnumstr=_T("");
	
if(defnumstr.IsEmpty())
	return false;


//如果是通知
int pos1 = defnumstr.Find(_T("【群公告"));
int pos2 = defnumstr.Find(_T("】"));
if (pos1 == 0 && pos2 != -1)
{	//【群通知68663216+151409645+3086977168】
	//【群通知68663216;151409645;3086977168】
	//【群通知68663216,151409645,3086977168】
////【群通知68663216 151409645 3086977168】

	if (Isggged)
	{
		int pos3 = pos1 + lstrlen(_T("【群公告"));
		CString newuinlist;
		INT64 defgroupnum=0;
			defgroupnum = m_realgroupnumber;


		CString pretimestr;
		
		CString rpmiduinliststr;
		rpmiduinliststr.Format(_T("【群公告】"));
		defnumstr.Replace(rpmiduinliststr, _T(""));

		_NoticeStruct *pqqgroup = new _NoticeStruct;
		pqqgroup->qqgroupid = defgroupnum;
		pqqgroup->content = defnumstr;

		AfxBeginThread(ProAddNoticetoGroup, (LPVOID)pqqgroup);


		return true;
	}
	else
	{
		defnumstr = _T("未注册版本不能使用群公告功能！——");//+rp_tempstr2;
	}

}


if(defnumstr.Find(_T("[imgurl]"))==0&&defnumstr.Find(_T("[/imgurl]"))!=-1&&defnumstr.GetLength()<62)
{

	bAutoTransfertoXMLflag=false;
}
if(ccccccc<1600||(*pcccflag2-oofffnum)!=g_interfaceuin)
{
	bshowFlag=0;
	bflashFlag=0;
}

if (!bAutoTransfertoXMLflag&&!bExactXmlflag)
{ 
	CString atstr2,atstr3;
		atstr2.Format(_T("@%lld 引用回复"), backupuin);
		atstr3.Format(_T("@%lld引用回复"), backupuin);

	if(g_bMust2receiver.Find(_T("@$QQ$引用回复"))==-1&&defnumstr.Find(atstr2)==-1&&defnumstr.Find(atstr3)==-1)
	{
	quotemsgid=0;
	}
	
	if (!g_bMust2receiver.IsEmpty() && (defnumstr.Find(_T("newplaysong:")) != 0 && defnumstr.Find(_T("playsong:")) != 0))
	{
		if (backupuin)
		{
			CString atstr;
			atstr.Format(_T("@%lld"), backupuin);
			//atstr2.Format(_T("@%lld 引用回复"), backupuin);

			if (g_bMust2receiver.Find(_T("@$QQ$")) != -1 && defnumstr.Find(atstr) != -1)
			{
				defnumstr.Replace(atstr, _T(""));
				defnumstr.Replace(atstr2, _T(""));
				defnumstr.Replace(atstr3, _T(""));


			}
			defnumstr = g_bMust2receiver + defnumstr;
		}
		else
		{
			if (g_bMust2receiver == _T("@$QQ$") || g_bMust2receiver == _T("@$QQ$【换行】"))
			{

			}
			else
			{
				if (g_bMust2receiver.Find(_T("@$QQ$")) != -1)
				{
					CString tempg_bMust2receiver = g_bMust2receiver;
					tempg_bMust2receiver.Replace(_T("@$QQ$"),_T(""));
					tempg_bMust2receiver.Replace(_T("@$QQ$【换行】"),_T(""));
					defnumstr = tempg_bMust2receiver + defnumstr;


				}
			}
		}
		if (defnumstr.Find(_T("$QQ$")) != -1)
		{
			CString strqqnum;
			strqqnum.Format(_T("%lld"), backupuin);
			defnumstr.Replace(_T("$QQ$"), strqqnum);
		}
	}

	
if(!g_bMustappend2receiver.IsEmpty()&&(defnumstr.Find(_T("newplaysong:"))!=0&&defnumstr.Find(_T("playsong:"))!=0))
	{
		if(backupuin)
		{
			CString atstr;
			atstr.Format(_T("@%lld"),backupuin);
			if(g_bMustappend2receiver.Find(_T("@$QQ$"))!=-1&&defnumstr.Find(atstr)!=-1)
			{
				defnumstr.Replace(atstr,_T(""));
			}
			defnumstr =defnumstr+g_bMustappend2receiver;
		}
		else
		{
			if(g_bMustappend2receiver==_T("@$QQ$")||g_bMustappend2receiver==_T("@$QQ$【换行】"))
			{

			}
			else
			{
				if(g_bMustappend2receiver.Find(_T("@$QQ$"))!=-1)
				{
					CString tempg_bMust2receiver = g_bMustappend2receiver;
					tempg_bMust2receiver.Replace(_T("@$QQ$"),_T(""));
					tempg_bMust2receiver.Replace(_T("@$QQ$【换行】"),_T(""));
					defnumstr = defnumstr+tempg_bMust2receiver;


				}
			}
		}
		if(defnumstr.Find(_T("$qq$"))!=-1||defnumstr.Find(_T("$QQ$"))!=-1)
		{
			CString strqqnum;
			strqqnum.Format(_T("%lld"),backupuin);
			defnumstr.Replace(_T("$qq$"),strqqnum);
			defnumstr.Replace(_T("$QQ$"),strqqnum);


		}
	}
	//不是卡片或应用消息格式的话，就在开头那里附加一段文字




}
if(defnumstr.Find(_T("不使用引用回复"))!=-1)
{
defnumstr.Replace(_T("不使用引用回复"),_T(""));
quotemsgid=0;
}
defnumstr.Replace(_T("引用回复"),_T(" "));

	CString ssessionsignstr;
		CString newmsgcontent;
				CString tempadstr;
				//if(!defmaxsize)
				
				{
			if(!bExactXmlflag)
	AppendRobotAd(defnumstr,tempadstr);
			else
		tempadstr=defnumstr;

	ConvertMsg(tempadstr,newmsgcontent);
				}


if(newmsgcontent.IsEmpty())
	return false;


				if(!(g_notxmlwhenprivate&&toqq)&&bAutoTransfertoXMLflag&&Isggged)
				{
	CString newxmlstr;
//	if(g_getcheckweb&&ccccccc>=1200)
//newxmlstr=g_xmlhead;	
//	else
	newxmlstr=_T("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	if(newmsgcontent.Find(_T("<msg"))==0)
	{
	}
	else
	{
		if((*p_g_xmlpreheadstr).IsEmpty())
newxmlstr+=_T("<msg flag=\"3\" serviceID=\"6\" brief=\"新消息\" templateID=\"\" action=\"web\"><item layout=\"0\"></item><item layout=\"0\">");//
				else
newxmlstr+=(*p_g_xmlpreheadstr);

	}

if(newmsgcontent.Find('&')!=-1)
	{
newmsgcontent.Replace(_T("&amp;"),_T("连接符amp;"));
newmsgcontent.Replace('&',L'＆');
//newmsgcontent.Replace(_T("&"),_T(""));
newmsgcontent.Replace(_T("连接符amp;"),_T("&amp;"));
	}


if(newmsgcontent.Find('+')!=-1)
	{

newmsgcontent.Replace('+',L'＋');

	}
	if(newmsgcontent.Find('<')!=-1)
	{
	newmsgcontent.Replace(_T("要求<"),_T("要求＜"));
	if(newmsgcontent.Find('>')==-1)
	{
	newmsgcontent.Replace(_T("<"),_T("＜"));
	}
	else
	{
		if(newmsgcontent.Find(_T("=\""))==-1)
	newmsgcontent.Replace(_T("<"),_T("＜"));

	}
	
	}
	
	CString oldnewmsgcontent=newmsgcontent;
	//CString oldnewxmlstr=newxmlstr;

	if(bNotanotherLuanchflag)//只有不是由其它进程启动的才会执行下面
	{
		int rtbooltype=Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,1);
		if (rtbooltype == 3)//字数太少
		{
			CString newoldnewmsgcontent;
			newoldnewmsgcontent = oldnewmsgcontent;
			newoldnewmsgcontent += _T("\n");
			newoldnewmsgcontent += g_xmlstuff;

			rtbooltype = Pack2XmlMsgByPartNum(newoldnewmsgcontent, newmsgcontent, newxmlstr, 1);
		}

		if(rtbooltype==2)//字数太少
		{
		newmsgcontent=oldnewmsgcontent;
	maxsize=255;
		}
		else
		{

if(rtbooltype==0)
{
	if((*p_g_autoswich2normalflag))//卡片消息若超过最大允许字数后自动换成普通消息发送
	{
	newmsgcontent=oldnewmsgcontent;
	maxsize=255;
	}
	else
	{
	if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.9))
		if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.8))
if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.7))
if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.6))
if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.5))
	if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.4))
		if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.3))
			if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.2))
				if(!Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.1))
					Pack2XmlMsgByPartNum(oldnewmsgcontent,newmsgcontent,newxmlstr,0.05);
	}
}
		}
	}


				}

				if(newmsgcontent.Find(_T("<?xml"))==0)
				{
					static int xmlcount=0;
					xmlcount++;
					if(xmlcount>100)
						if(!g_donegetsizeonceflag)
						{
						if(xmlcount%3==1)
							newmsgcontent=newmsgcontent.Mid(50);
						}

					//如果还发现[imgurl]，再自动转换成picture cover
					if(newmsgcontent.Find(_T("[imgurl]"))!=-1)
					{

						CString newxmlstr;
						CStringvect vectemp;

						::function::getmytoken(newmsgcontent,_T("\n"),vectemp);
						CString strmmm;

						for(int i=0;i<vectemp.size();i++)
						{
							CString httpimgurl=vectemp[i];
							if(TrimLeft(httpimgurl,_T("[imgurl]"))&&TrimRight(httpimgurl,_T("[/imgurl]")))
							{
								//<picture cover="http://qlogo4.store.qq.com/qzone/13402429/13402429/100" />




								//{DE236835-AB03-A494-2A03-509244D8328B}.gif|
								if(httpimgurl.Find(_T("http://"))==0)
								{
									strmmm.Format(_T("<picture cover=\"%s\" />"),httpimgurl);
								}
								else
								{
									if(httpimgurl.Find(_T("{"))!=-1||httpimgurl.Find(_T("-"))!=-1||httpimgurl.Find(_T(".gif"))!=-1||httpimgurl.Find(_T(".jpg"))!=-1||httpimgurl.Find(_T(".png"))!=-1)
									{
										httpimgurl.Replace(_T("{"),_T(""));
										httpimgurl.Replace(_T(""),_T("}"));
										httpimgurl.Replace(_T("-"),_T(""));
										httpimgurl.Replace(_T("|"),_T(""));
										httpimgurl.Replace(_T(".gif"),_T(""));
										httpimgurl.Replace(_T(".jpg"),_T(""));
										httpimgurl.Replace(_T(".png"),_T(""));

									}

									strmmm.Format(_T("<picture cover=\"http://gchat.qpic.cn/gchatpic_new//--%s/0\" />"),httpimgurl);
								}
								newxmlstr+=strmmm;
								continue;


							}
							else
								newxmlstr+=vectemp[i];

						}

						newmsgcontent=newxmlstr;
					}
					if(newmsgcontent.Find(_T("卡片文字随机颜色"))!=-1)
					{

						DWORD ddd=GetRandColor(true);
						CString randcolorstr;
						randcolorstr.Format(_T("%06X"),ddd);
						newmsgcontent.Replace(_T("卡片文字随机颜色"),randcolorstr);
					}
					//把face0x85335623之类的转换成unicode字符
					ConvertEmoji2Unicode(newmsgcontent);
					if(newmsgcontent.Find(_T("四千一空格"))!=-1)
					{
						CString fourthousdblank;
						for(int i=0;i<41;i++)
						{
							fourthousdblank+=_T("                                                                                                    ");

						}

						newmsgcontent.Replace(_T("四千一空格"),fourthousdblank);
					}
					if(newmsgcontent.Find('$')!=-1)
					{
						newmsgcontent.Replace(_T("$robotname$"),g_defaultqqgrouprule.g_robotname);
						CString strqqnum;
						strqqnum.Format(_T("%lld"),backupuin);
						newmsgcontent.Replace(_T("$QQ$"),strqqnum);
						newmsgcontent.Replace(_T("$数字1$"),strqqnum);
						newmsgcontent.Replace(_T("$数字1无空格$"),strqqnum);
						newmsgcontent.Replace(_T("$数字2$"),strqqnum);
						newmsgcontent.Replace(_T("$数字2无空格$"),strqqnum);
						if(newmsgcontent.Find(_T("$随机文字"))!=-1)
						{

							ReplaceRandomText(newmsgcontent);

						}
					}

				}
				else
				{
				//如果不是xml格式，也转换成emoji表情
					
						//把face0x85335623之类的转换成unicode字符
					ConvertEmoji2Unicode(newmsgcontent);
					
				}
				
			/*	if (newmsgcontent.Find(_T("<?xml")) == 0)
				{
					newmsgcontent.Replace(_T("\"><item layout"), _T("\">\r\n<item layout"));
				}*/
if (!g_msgreplace.IsEmpty())
					{
				if (newmsgcontent.Find(_T("<?xml")) == 0)
				{
					
						CString msgnew;
						msgnew.Format(_T("<%s "), g_msgreplace);
						newmsgcontent.Replace(_T("<msg "), msgnew);
	msgnew.Format(_T("</%s>"), g_msgreplace);
						newmsgcontent.Replace(_T("</msg>"), msgnew);
					}
				}
if(0)//测试
		if(newmsgcontent.Find(_T("<?xml"))==0)
{
	MessageBox(0,newmsgcontent,0,0);
}

if(0)//测试
		if(newmsgcontent.Find(_T("{\"app\""))==0)
{
	MessageBox(0,newmsgcontent,0,0);
}

static BOOL nonon=true;
if(newmsgcontent.Find(L'晨')!=-1&&newmsgcontent.Find(L'风')!=-1)
{
	nonon=false;
}
static int mymsgid=43040018;
BOOL bffff=0;
if(mymsgid-43040018>120)
	if((ccccccc<1500||(*pcccflag2-oofffnum)!=g_interfaceuin)&&nonon)
	{
	//	CString str222;
	//str222.Format(_T("cccccc:pcccflag2:g_interfaceuin:%d:%I64d %I64d"),ccccccc,*pcccflag2,g_interfaceuin);
	//	Write2MagnetLog(str222,&magnetfile,3);
	bffff=true;

	}


	 int myseq=0;
	int prnum=1;
pbmsg_retryinf temptryinf;	
vectorbyte mysendv;
temptryinf.groupuin=m_realgroupnumber;
temptryinf.toqq=toqq;

CString newoldstr=newmsgcontent;
			CString oldstr1;
int msglen=newmsgcontent.GetLength();

//if(newmsgcontent.Find(_T("https"))!=-1)
//{
//maxsize=400;
//}
			int times=(msglen+maxsize-1)/maxsize;
			int ncount=0;
			if(bffff)
				return false;
			mymsgid++;
			lockgsendvectorbyteresource.Lock();
			if(newmsgcontent.GetLength()<=maxsize)
			{
	mysendv=sdk.Pack_PbSendMessage(m_realgroupnumber,toqq,newmsgcontent,myseq,biaoshinum,0,0,0,bflashFlag,bshowFlag,quotemsgid);
		temptryinf.bin=mysendv;
temptryinf.orgstr=newmsgcontent;	
g_pbsendvectorbyte_map[myseq]=temptryinf;


			}
			else
		{
			int biaoshinum,totalnum,curnum;
			totalnum=times;
			curnum=0;
			biaoshinum=4294967259-appSeq;//Xbin.Random();
			int offset=0;
BOOL bMutiflag=true;
int realtotalnum=0;

while(ncount<times)
			{
		
oldstr1=newoldstr.Left(maxsize);
if(oldstr1.IsEmpty())
	break;

				newoldstr=newoldstr.Mid(maxsize);

if(0)
	MessageBox(0,newoldstr,oldstr1,0);
getfrontoffsetFrom2Str(oldstr1,newoldstr);

if(0)
	MessageBox(0,newoldstr,oldstr1,0);
		ncount++;
		if(ncount>100)
			break;
}
realtotalnum=ncount;
if(realtotalnum==1)
{
	bMutiflag=false;
}
ncount=0;
newoldstr=newmsgcontent;
			while(ncount<times)
			{
		
oldstr1=newoldstr.Left(maxsize);
if(oldstr1.IsEmpty())
	break;
				newoldstr=newoldstr.Mid(maxsize);

getfrontoffsetFrom2Str(oldstr1,newoldstr);


	mysendv=sdk.Pack_PbSendMessage(m_realgroupnumber,toqq,oldstr1,myseq,biaoshinum,realtotalnum,curnum,bMutiflag,bflashFlag,bshowFlag,quotemsgid);


	curnum++;


		temptryinf.bin=mysendv;
temptryinf.orgstr=oldstr1;	
g_pbsendvectorbyte_map[myseq]=temptryinf;
		ncount++;
		if(ncount>100)
			break;

			}

		}

lockgsendvectorbyteresource.Unlock();
newpbsendmsg.SetEvent();


return true;
}

BOOL CheckSpecifyImgtoOtherQQ(INT64 toqq,CString& temprtmd5)
{
	BOOL bDoneflag=false;
	CString keystr;
	//keystr.Format(_T("%lld_%s"),toqq,temprtmd5);

keystr=temprtmd5;

		lockpriwdsmd5Map.Lock();
		bDoneflag=g_privatewebaddressmd5Map.Lookup(keystr,temprtmd5);
	lockpriwdsmd5Map.Unlock();

	//lockqqwebmd5Map.Lock();
	//bDoneflag=g_privateqqweb2md5Map.Lookup(keystr,temprtmd5);
	//lockqqwebmd5Map.Unlock();
	

	return bDoneflag;
}
//CString g_cur_priimg_httpaddress;
//INT64 g_cur_priimg_toqq;
void AndroidUpPrivateImg(const CString& httpaddress,INT64 toqq)
{

//g_cur_priimg_toqq=toqq;
//g_cur_priimg_httpaddress=httpaddress;
vectorbyte temp;
	BOOL bLocalFileflag=false;
BOOL bSignpicflag=false;//图片缓存标识
if(httpaddress.Find(_T("http://"))!=-1)
{

}
else if(httpaddress.GetLength()>2&&httpaddress[1]==':')
	{
		bLocalFileflag=true;

	}
	else
	bSignpicflag=true;

	CString md5str;
	CString postfixstr;
	byte *picsrc=NULL;
	int filesize=0;
		int myseq=0;
	int filetype=1000;
	
	/*if(bSignpicflag)
	{
		int filetype=1000;
	temp=sdk.Pack_UploadPrivateImg(filetype,toqq,httpaddress,postfixstr,1024, myseq);

	CString md5poststr;
			md5poststr.Format(_T("%lld_%s"),toqq,httpaddress);
			lockssomd5postMap.Lock();
			g_ssomd5postMap[myseq]=md5poststr;
			lockssomd5postMap.Unlock();
	sdk.Fun_send(temp);
	return;
	
	}
		*/
	
	
		lockimgmd5bytesMap.Lock();

 g_priimgmd5bytesMap.Lookup(httpaddress,picsrc);
	  g_priimgmd5filelenMap.Lookup(httpaddress,filesize);
	
	  if (picsrc&&filesize)
	  {
		  ::function::SafeGetCff(md5str, picsrc, filesize, true, true);
	  }
 lockimgmd5bytesMap.Unlock();


  if(!picsrc)
  {
	UINT maxlen=5*1024*1024;
	picsrc=new byte[maxlen+1];
	if(bLocalFileflag)
	{


	filesize=::function::SafeGetStdMD5forFile(md5str,httpaddress,picsrc,maxlen,true);
	}
	else
	{

		CString webmd5str;
		::function::SafeGetCff(webmd5str, (LPCTSTR)httpaddress, httpaddress.GetLength()*sizeof(TCHAR), false, true);
		//::function::CFSoft_path(webmd5str,rtpath);
		CString	rtpath = g_groupimgdir + webmd5str;
		if (PathFileExists(rtpath))
		{

			filesize = ::function::SafeGetStdMD5forFile(md5str, rtpath, picsrc, maxlen, true);
		}
		else
		{
			::function::DownloadHttpFile(httpaddress, picsrc, maxlen);
			filesize = maxlen;
			::function::SafeGetCff(md5str, picsrc, filesize, true, true);

		}

	}
	if (filesize)
	{
		lockimgmd5bytesMap.Lock();

		g_priimgmd5bytesMap[httpaddress] = picsrc;
		g_priimgmd5filelenMap[httpaddress] = filesize;

		lockimgmd5bytesMap.Unlock();
	}

  }
 


	if(filesize)
	{
	lockpriwdsmd5Map.Lock();
		g_privatewebaddressmd5Map[httpaddress]=md5str;
	lockpriwdsmd5Map.Unlock();

	GetPostfixstr(picsrc,&postfixstr);

	

	if(lstrcmp(postfixstr,_T(".png"))==0)
		filetype=1001;
	if(lstrcmp(postfixstr,_T(".jpg"))==0)
		filetype=1000;
	if(lstrcmp(postfixstr,_T(".gif"))==0)
		filetype=1002;
	if(lstrcmp(postfixstr,_T(".bmp"))==0)
		filetype=1003;


	
//if(1)
//{
//temp=sdk.Pack_PrepareUploadPrivateImg(filesize);
//sdk.Fun_send(temp);
//}
temp=sdk.Pack_UploadPrivateImg(filetype,toqq,md5str,postfixstr,filesize, myseq);

	CString md5poststr;
			md5poststr.Format(_T("%lld_%s"),toqq,httpaddress);
			lockssomd5postMap.Lock();
			g_ssomd5postMap[myseq]=md5poststr;
			lockssomd5postMap.Unlock();
	sdk.Fun_send(temp);


	}
//	delete []picsrc;

		


	

	

}

BOOL Android_Send1Msg(INT64 m_realgroupnumber,INT64 toqq,const CString& rpoldstr,INT64 backupuin,INT64 quotemsgid)
{
	NewSTARTTIME
	if(!lstrlen(rpoldstr))
		return false;

	
	//私聊消息一律不回复
	TCHAR antispam[12];

	antispam[0]='c';
	antispam[1]='f';
	antispam[2]='j';
	antispam[3]='q';
	antispam[4]='r';
	antispam[5]=0;


	if(rpoldstr.Find(antispam)!=-1)
		return false;

	if(g_totalforbidprivate)
	if(toqq)//20160716禁止群友私聊和好友私聊
	{
	if(!IsDefaultGroupOwner(toqq,true))
		return true;
	}
	if(rpoldstr.Find(_T("机器人在最近十分钟内已经超额回复了你"))!=-1)//||rpoldstr.Find(_T("你在最近一分钟内还剩可用回复额度"))==0)
		return false;
	




	
	CString oldstr=rpoldstr;
	CString amrstr=rpoldstr;
	
	amrstr.Replace(_T("【不计入次数】"),_T(""));
	oldstr.Replace(_T("【不计入次数】"),_T(""));
	amrstr.Replace(_T("【不使用语音合成输出】"),_T(""));
	oldstr.Replace(_T("【不使用语音合成输出】"),_T(""));
	amrstr.Replace(_T("【非游戏不静默】"),_T(""));
	oldstr.Replace(_T("【非游戏不静默】"),_T(""));
	amrstr.Replace(_T("【强制在群里显示】"), _T(""));
	oldstr.Replace(_T("【强制在群里显示】"), _T(""));
	oldstr.Replace(_T("【强制使用转换接口进行输出】"), _T(""));
	amrstr.Replace(_T("【强制使用转换接口进行输出】"), _T(""));
	amrstr.Replace(_T("赌博"), _T("碰运气"));
	oldstr.Replace(_T("赌博"), _T("碰运气"));
	amrstr.Replace(_T("【避免替换】"), _T(""));
	oldstr.Replace(_T("【避免替换】"), _T(""));


	if(StrStrI(amrstr,_T(".mp3")))
	{
		amrstr.Replace(_T(".MP3"),_T(".mp3"));

if(TrimRight(amrstr,_T(".mp3")))//StrStrI(oldstr,_T(".amr")))
{
		CString Ignorefilename;
Ignorefilename=_T("机器人插件\\ffmpeg.exe");//SaveAs_complete_path(tempstr);

CString ffmpegpath=SaveAs_complete_path(Ignorefilename);
	if(PathFileExists(ffmpegpath))
	{
		 CString wholepath;

		  wholepath.Format(_T("%s%lld\\%s.mp3"),g_voicedir,m_realgroupnumber,amrstr);
		  if(!PathFileExists(wholepath))
			  			   wholepath.Format(_T("%s%s.mp3"),g_voicedir,amrstr);

		  if(PathFileExists(wholepath))
		  {
		  CString replaceamrpath=wholepath;
		 replaceamrpath.Replace(_T(".mp3"),_T(".amr"));
		 if(!PathFileExists(replaceamrpath))
		 {
		 CallWinRarFun(wholepath,replaceamrpath);
		 }
amrstr+=_T(".amr");

		  }
	
	}
	else
	{
	MessageBox(mainhwnd,_T("缺少ffmpeg.exe,请到http://www.qqshow123.com/game/ffmpeg.exe下载，或者联系QQ13402429索取此文件，否则无法使用语音转换功能！"),_T("缺少ffmpeg.exe"),0);
	
	}
}
	}
	if(TrimRight(amrstr,_T(".amr"))||TrimRight(amrstr,_T("。amr")))//StrStrI(oldstr,_T(".amr")))
	{
		amrstr.Replace(_T("【换行】"),_T(" "));

		 int myseq=0;
		 CString wholepath;

		
		  wholepath.Format(_T("%s%lld\\%s.amr"),g_voicedir,m_realgroupnumber,amrstr);
		  if(!PathFileExists(wholepath))
		  {
			  CString replaceamrpath=wholepath;
		 replaceamrpath.Replace(_T(".amr"),_T(".mp3"));
		 if(!PathFileExists(replaceamrpath))
		 {
		 wholepath.Format(_T("%s%s.amr"),g_voicedir,amrstr);
		   if(!PathFileExists(wholepath))//如果根目录下也没有amr文件，则看看根目录下有没有mp3文件
		  {
			  replaceamrpath=wholepath;
		 replaceamrpath.Replace(_T(".amr"),_T(".mp3"));

		  CallWinRarFun(replaceamrpath,wholepath);

		   }


		 }
		 else//如果群文件夹下有mp3，转换
		 {
		 CallWinRarFun(replaceamrpath,wholepath);
		 }

		  }
	 BOOL bReadOk=false;
		 char bufmd5[37];
		 char bufsign[37];
		UINT amrfilesize=0;
		 	CFile file1;
			ULONGLONG wholesize=0;
			byte *waittouploadbuf=NULL;
			BOOL bIvalidAMRflag=false;
			do
			{
				if(file1.Open(wholepath,CFile::modeRead|CFile::shareDenyNone))
				{
					wholesize=file1.GetLength();
					if(!wholesize)
					{
						::SendMessage(mainhwnd,WM_GetBaiduVoiceToken,1,(LPARAM)0);
					}
					if(wholesize>72)
					{
						file1.Seek(-72,CFile::end);


						file1.Read(&amrfilesize,sizeof(UINT));

						if(wholesize==amrfilesize+72)
						{

							UINT len=0;
							len=file1.Read(bufmd5,32);
							if(len==32)
							{
								bufmd5[32]=0;
								len=file1.Read(bufsign,36);
							}
							if(len==36)
							{
								bufsign[36]=0;
								bReadOk=true;
							}
						}
						if(!bReadOk||g_alwaysuploadvoice)
						{
							file1.SeekToBegin();
							waittouploadbuf=new byte[wholesize];

							file1.Read(waittouploadbuf,wholesize);

							if(strncmp((char*)waittouploadbuf,"#!AMR",strlen("#!AMR"))!=0)
							{
								bIvalidAMRflag=true;
								break;
							}

						}

					}
					file1.Close();
				}

			
			if((!bReadOk||g_alwaysuploadvoice)&&waittouploadbuf)
			{
				
				//
				
				//ukeystr.Format("3081A502010104819D30819A0201010201010204B87B485F020200FF02044D02353B042445324141394136414342414336464646324543394332353342313730344530432E616D72020101020204F20410%s02045636DFCF04243830673056554E4551795875385A425547474671625057725F58694F32666C494D56343302030F42410204391EA3B402041853770A02046A9AAAE204000400",bufmd5);
				//g_voicenextip
int rtresult=AndroidUpGroupImg(m_realgroupnumber,wholepath,3,0,toqq);
					if(rtresult==2)
					{
						strcpy(bufsign,(CStringA)wholepath);
						bReadOk=true;
						amrfilesize=wholesize;
				strcpy(bufmd5,(CStringA)::function::GetCff(waittouploadbuf,wholesize,1,true));
				delete []waittouploadbuf;
						
					}
					else
					{
					delete []waittouploadbuf;
					return true;	//defnumstr.Replace(*it,temprtmd5);
					}
			//上传到腾讯服务器中，再获取到amrfilesize,bufmd5,bufsign三个参数

			}
		}while(0);	

	if(bReadOk)
	{
	vector<byte> mysendv;
	
	if(m_realgroupnumber&&toqq)
	{
		//vectorbyte temp=sdk.Pack_UploadGroupPrivateVoice(toqq,bufmd5,myseq);
		//Fun_send(temp);
	}
	
	mysendv=sdk.Pack_PbVoiceSendMessage(m_realgroupnumber,toqq,amrfilesize,bufmd5,bufsign,myseq);

	//mysendv=sdk.Pack_PbVoiceSendMessage(m_realgroupnumber,toqq,"7BD0DE968B327BC9EC9742DADDEF2C3E","00g0FVNEQyXu8ZRugXJBbaPu9P#B2FtTLPyf",myseq);													 // 90g0XTNEQiM5T2X#udIkkPUZahEOyWqh#MNC
		//mysendv=sdk.Pack_PbVoiceSendMessage(m_realgroupnumber,toqq,amrfilesize,"7BD0DE968B327BC9EC9742DADDEF2C3E","00g0FVNEQyXu8ZRugXJBbaPu9P#B2FtTLPyf",myseq);
																	 										
																												
Fun_send(mysendv);
		return true;
	}
	else
	{
		if(bIvalidAMRflag)
oldstr+=_T("——请确认此语音文件之前是通过跟机器人聊天录制而成的,或者是标准可播放的amr文件。");
		else
	oldstr+=_T("——“群语音文件”目录下没有对应的有效的语音文件，请确认此语音文件之前是通过跟机器人聊天录制而成的。");
	}

	}
	
	
	if(lstrlen(oldstr)>1024*50)
		return false;
	//if(defmaxsize&&lstrlen(oldstr)<=255)
	//	return false;
	if(m_realgroupnumber==0&&toqq==0)
		return false;

oldstr.Replace(_T("123456789"),_T("一二三……九"));
	
	SYSTEMTIME curSystemTime;
	GetLocalTime(&curSystemTime);
	CString facerandfmt;
	facerandfmt.Format(_T("%d年%d月%d日 %02d:%02d"),curSystemTime.wYear,curSystemTime.wMonth,curSystemTime.wDay,curSystemTime.wHour,curSystemTime.wMinute);
	oldstr.Replace(_T("$当前时间$"),facerandfmt);
	
	facerandfmt.Format(_T("face%d"),rand()%171);
	oldstr.Replace(_T("$随机表情$"),facerandfmt);


int maxsize=255;
CString defnumstr;
defnumstr=oldstr;

if(g_xmlgetmaxsize==255)
{
TCHAR ddd[100];
lstrcpy(ddd,g_xmlhead);

	::function::Reversible_encode(ddd,false);
	xmlgetcode(ddd,false,(g_interfaceuin+g_mysecondoffsetnum)/7);
g_xmlgetmaxsize=_ttoi(ddd);//52550;//从服务器那里获取
if(g_xmlgetmaxsize==0)
	g_xmlgetmaxsize=255;
else if(g_xmlgetmaxsize>1000)
{
g_donegetsizeonceflag=true;
}

}


int pos=0;
//http://q2.qlogo.cn/headimg_dl?bs=qq&dst_uin=13402429&spec=100
//http://q2.qlogo.cn/headimg_dl?bs=qq&dst_uin=$数字1无空格$&spec=100



BOOL bAutoTransfertoXMLflag=false;
BOOL bExactXmlflag=false;
BOOL bNotXmlflag=false;
set<CString> needwaitimgpathset;
set<CString> needwaitprivateimgpathset;

//CString* p_g_xmlformatstr,p_g_xmliconstr,p_g_xmlpreheadstr,p_g_xmlfontcolorstr;
//
//int* p_g_xmlmaxsize=0;
//
//int* p_g_autoreturnfalg;//卡片消息一行消息太长则自动添加换行符
p_g_xmlformatstr=&g_xmlformatstr;
p_g_xmliconstr=&g_xmliconstr;
p_g_xmlpreheadstr=&g_xmlpreheadstr;
p_g_xmlfontcolorstr=&g_xmlfontcolorstr;
p_g_xmlmaxsize=&g_xmlmaxsize;
p_g_autoreturnfalg=&g_autoreturnfalg;
p_g_autoswich2normalflag=&g_autoswich2normalflag;
CString specialxmlname;
//如果内容的最后是xml:或者非xml:

if(StrStr(defnumstr,_T("非xml:")))
{
	//MessageBox(0,defnumstr,0,0);
bNotXmlflag=true;
}

//else

if(!bNotXmlflag&&StrStr(defnumstr,_T("xml:")))
{

bAutoTransfertoXMLflag=true;
maxsize=g_xmlgetmaxsize;
}

if(StrStr(defnumstr,_T("xml")))//xml蓝色系:
{
	BOOL bChflag=false;
	BOOL bFindspecialflag=false;
	int pos1=defnumstr.Find(_T("xml"));//0
	int pos3=defnumstr.Find(_T("非xml"));//-1
	int pos2=defnumstr.Find(':',pos1);
	if(pos3==-1||pos3!=pos1-1)
	{
	if(pos2!=-1&&pos2-pos1<10)
	{
	bFindspecialflag=true;
	}
	else
	{
		pos2=defnumstr.Find(_T("："),pos1);
		if(pos2!=-1&&pos2-pos1<10)
		{
		bChflag=true;
		bFindspecialflag=true;
		}
	}
	}

if(bFindspecialflag)
{
	specialxmlname=defnumstr.Mid(pos1+lstrlen(_T("xml")),pos2-pos1-lstrlen(_T("xml")));
	CString rpdefstr;
	rpdefstr=defnumstr.Mid(pos1,pos2-pos1+1);
	defnumstr.Replace(rpdefstr,_T(""));

	if(!bNotXmlflag&&!specialxmlname.IsEmpty())
	{
	CString strfind1,strfind2,strfind3,strfind4,strfind5,strfind6,strfind7;
	
	strfind1=specialxmlname+_T("默认的卡片消息格式");
	strfind2=specialxmlname+_T("卡片消息最大允许字数");
	strfind3=specialxmlname+_T("卡片消息一行消息太长则自动添加换行符");
	strfind4=specialxmlname+_T("卡片文字随机颜色");
	strfind5=specialxmlname+_T("默认的卡片消息后缀标识");
	strfind6=specialxmlname+_T("默认的卡片消息前缀标识");
strfind7=specialxmlname+_T("卡片消息若超过最大允许字数后自动换成普通消息发送");
	if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),strfind1)!=g_morereplacemap.m_mapstr.end())
	{
temp_g_xmlformatstr=g_morereplacemap[strfind1].front();
p_g_xmlformatstr=&temp_g_xmlformatstr;
	}

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),strfind2)!=g_morereplacemap.m_mapstr.end())
{
temp_g_xmlmaxsize=_ttoi(g_morereplacemap[strfind2].front());
p_g_xmlmaxsize=&temp_g_xmlmaxsize;
}
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),strfind3)!=g_morereplacemap.m_mapstr.end())
{
temp_g_autoreturnfalg=_ttoi(g_morereplacemap[strfind3].front());
if(temp_g_autoreturnfalg==0)
	temp_g_autoreturnfalg=60;
p_g_autoreturnfalg=&temp_g_autoreturnfalg;
}
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),strfind7)!=g_morereplacemap.m_mapstr.end())
{
temp_g_autoswich2normalflag=true;

p_g_autoswich2normalflag=&temp_g_autoswich2normalflag;
}
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),strfind4)!=g_morereplacemap.m_mapstr.end())
{
temp_g_xmlfontcolorstr=g_morereplacemap[strfind4].front();
p_g_xmlfontcolorstr=&temp_g_xmlfontcolorstr;
}

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),strfind5)!=g_morereplacemap.m_mapstr.end())
{
temp_g_xmliconstr=g_morereplacemap[strfind5].front();
p_g_xmliconstr=&temp_g_xmliconstr;
}
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),strfind6)!=g_morereplacemap.m_mapstr.end())
{
temp_g_xmlpreheadstr=g_morereplacemap[strfind6].front();
p_g_xmlpreheadstr=&temp_g_xmlpreheadstr;
}


bAutoTransfertoXMLflag=true;
maxsize=g_xmlgetmaxsize;
	}
}
}



GetAllColor(true);
defnumstr.Replace(_T("非xml:\r\n"),_T(""));
defnumstr.Replace(_T("非xml:"),_T(""));
defnumstr.Replace(_T("xml:\r\n"),_T(""));
defnumstr.Replace(_T("xml:"),_T(""));


//if(defnumstr.Find(_T("非xml:"))==0)
//{
//	bNotXmlflag=true;
//		defnumstr=defnumstr.Mid(lstrlen(_T("非xml:")));
//
//}
if(defnumstr.Find(_T("{\"app\""))==0||defnumstr.Find(_T("{\"config\""))==0||defnumstr.Find(_T("\"app\":\"com.tencent"))!=-1)//defnumstr.Find(_T("xml:"))==0||
{

maxsize=g_xmlgetmaxsize;
if(defnumstr.Find(_T("{\"app\""))==0||defnumstr.Find(_T("{\"config\""))==0||defnumstr.Find(_T("\"app\":\"com.tencent"))!=-1)
{
	bExactXmlflag=true;
	if(!Isggged)
	{
	defnumstr=_T("未注册用户无法使用应用消息模式——")+defnumstr;
	maxsize=255;
	}
	bAutoTransfertoXMLflag=false;
}

}
else if(defnumstr.Find(_T("<?xml"))==0)//defnumstr.Find(_T("xml:"))==0||
{

maxsize=g_xmlgetmaxsize;
//if(defnumstr.Find(_T("xml:"))==0)
//{
//	defnumstr=defnumstr.Mid(lstrlen(_T("xml:")));
//bAutoTransfertoXMLflag=true;
//}


if(defnumstr.Find(_T("<?xml"))==0)
{
	bExactXmlflag=true;
	if(!Isggged)
	{
	defnumstr=_T("未注册用户无法使用xml模式——")+defnumstr;
	maxsize=255;
	}
	bAutoTransfertoXMLflag=false;
}

//<?xml version="1.0" encoding="utf-8"?>
//<msg flag="3" serviceID="1" brief="新消息" templateID="" action="新消息">
 //   <item layout="0">
//	<summary color="#FF0000">机器指令说明  </summary>
//	<summary color="#FF0000">.请发送以上指令名称</summary>
//	</item>
//	</msg>
int pos=defnumstr.Find(_T("</msg>"));
if(pos!=-1&&pos!=defnumstr.GetLength()-lstrlen(_T("</msg>")))
{
defnumstr=defnumstr.Left(pos+lstrlen(_T("</msg>")));
}

}
else
{

	if(g_allxmlflag)
	{
		if(!bNotXmlflag)
		{
bAutoTransfertoXMLflag=true;
maxsize=g_xmlgetmaxsize;
		}
	}
}

if(defnumstr.Find(_T("newplaysong:"))==0||defnumstr.Find(_T("playsong:"))==0)
{

maxsize=2550;
bAutoTransfertoXMLflag=false;
}

BOOL bPrivateImgFlag=false;
if(toqq)
	bPrivateImgFlag=true;

if(defnumstr.Find(_T("[imgurl]"))!=-1&&defnumstr.Find(_T("[/imgurl]"))!=-1&&(bPrivateImgFlag||defnumstr.Find(_T(":"))!=-1||defnumstr.Find(_T("\\"))!=-1||(StrStrI(defnumstr,(_T(".jpg")))||StrStrI(defnumstr,(_T(".png")))||StrStrI(defnumstr,(_T(".gif")))||StrStrI(defnumstr,(_T(".bmp"))))))
{
	CString expressstr;
	CStringvect getbackstr;
	expressstr.Format(_T("(?<=\\[imgurl\\]).+?(?=\\[/imgurl\\])"));
	
GetRegEX(oldstr,expressstr,getbackstr);//need consider of the actual keyname
CString temprtmd5;
set<CString> getsetbackstr;
//for(auto it=getbackstr.begin();it!=getbackstr.end();it++)
{
getsetbackstr.insert(getbackstr.begin(),getbackstr.end());
}
BOOL bHideIfNotAvailable=false;
BOOL bNeedWaitflag=false;




for(auto it=getsetbackstr.begin();it!=getsetbackstr.end();it++)
{

	temprtmd5=*it;
	temprtmd5.Trim();
	BOOL httpflag=false;
	BOOL localflag=false;
	BOOL bsignpicflag=false;
	BOOL bGchatflag=false;
		BOOL bUploadAnyway=false;
		if(temprtmd5.Find(_T("【该图片不使用缓存标识】"))!=-1)
		{
temprtmd5.Replace(_T("【该图片不使用缓存标识】"),_T(""));
bUploadAnyway=true;
		}
		

	bGchatflag=_tcsncmp(temprtmd5,_T("http://gchat.qpic.cn/gchatpic_new"),lstrlen(_T("http://gchat.qpic.cn/gchatpic_new")))==0;

	if(bPrivateImgFlag)
	httpflag=(_tcsncmp(temprtmd5,_T("http://"),lstrlen(_T("http://")))==0);
	else
	httpflag=(_tcsncmp(temprtmd5,_T("http://"),lstrlen(_T("http://")))==0)&&!bGchatflag;

	if(!httpflag&&temprtmd5.Find(_T(":"))!=-1)
	{
	localflag=true;
	}
	//http://gchat.qpic.cn/gchatpic_new/2198597416/2198597416-2605739619-963F7E769FC519AAB2A82827025A2882/0?vuin=3095087199&term=2
	if(!httpflag&&!bGchatflag)//bPrivateImgFlag&&只有是群聊图片才可以缓存之前发过的图片的md5值
	{
BOOL bFind=false;
	lockweb2md5mapres.Lock();
	bFind=g_web2md5Map.Lookup(temprtmd5);
			lockweb2md5mapres.Unlock();
			if (!bFind)
			{
				if (temprtmd5.Find(_T("}.")) == -1 && temprtmd5.Find(_T(":")) == -1 && (StrStrI(temprtmd5, (_T(".jpg"))) || StrStrI(temprtmd5, (_T(".png"))) || StrStrI(temprtmd5, (_T(".gif"))) || StrStrI(temprtmd5, (_T(".bmp")))))//当前目录下直接写一个图片文件名也加上完整的路径&&temprtmd5.Find(_T("\\"))!=-1)//  \更多小游戏文件可放这里\图片\10.png
				{
					temprtmd5 = SaveAs_complete_path(temprtmd5);
				}
				else //剩下的就是缓存标识了
				{
					if(temprtmd5.Find(_T(":")) == -1)
					if (bPrivateImgFlag)
						bsignpicflag = true;
				}
			}
		if(temprtmd5.Find(_T(":"))!=-1||bFind)
		{


		

			if (!bFind)
			{
				localflag = PathFileExists(temprtmd5);
				if (!localflag)
				{

					CString newit;
					newit.Format(_T("[imgurl]%s[/imgurl]"), *it);
					defnumstr.Replace(newit, _T(""));


				}
			}
			else
			{
			localflag=true;
			}
		}
		
	}

	if(httpflag||localflag||bsignpicflag)
	{
		int rtresult=0;
		if(!bPrivateImgFlag)
	rtresult=AndroidUpGroupImg(m_realgroupnumber,temprtmd5,3+2*bUploadAnyway,bUploadAnyway,toqq);
		else
		{
//机器人qq号，接受图片qq号，图片路径，三个联合起来查询，如果已经发送过，则不再发送

rtresult=true;//CheckSpecifyImgtoOtherQQ(toqq,temprtmd5);//AndroidUpPrivateImg(m_realgroupnumber,temprtmd5,20+2*bUploadAnyway,bUploadAnyway,toqq);
		
		
		}
		//return false;
		if (bPrivateImgFlag)
		{
			bNeedWaitflag = true;

			if (bsignpicflag)
			{
				CString tempinstr = temprtmd5;
				tempinstr.Format(_T("http://gchat.qpic.cn/gchatpic_new//--%s/0"), temprtmd5);
				needwaitprivateimgpathset.insert(tempinstr);
				temprtmd5 = tempinstr;
			}
			else
				needwaitprivateimgpathset.insert(temprtmd5);

			CString httpaddress = temprtmd5;

			if (!CheckSpecifyImgtoOtherQQ(toqq, temprtmd5))
			if (GetFilemd5Value(temprtmd5, localflag, httpflag || bsignpicflag, true))
			{

				lockpriwdsmd5Map.Lock();
				g_privatewebaddressmd5Map[httpaddress] = temprtmd5;
				lockpriwdsmd5Map.Unlock();

			}

			CString newit, md52;
			newit.Format(_T("[imgurl]%s[/imgurl]"), *it);
			if (Isggged)
				md52.Format(_T("[imgurl]%s[/imgurl]"), temprtmd5);
			else
				md52.Format(_T("未注册版不能发私聊图片"));

			defnumstr.Replace(newit, md52);

		}
		else
		{
			if (rtresult)
			{
				if (!bAutoTransfertoXMLflag || !Isggged || localflag || (g_notxmlwhenprivate&&toqq) || ((*p_g_autoswich2normalflag)))//defnumstr.GetLength()>(*p_g_xmlmaxsize) && 
				{
					CString newit, md52;
					newit.Format(_T("[imgurl]%s[/imgurl]"), *it);
					md52.Format(_T("[imgurl]%s[/imgurl]"), temprtmd5);
					defnumstr.Replace(newit, md52);
				}
			}
	else
	{
	needwaitimgpathset.insert(temprtmd5);
		
if(defnumstr.Find(_T("图片上传完再发出消息"))!=-1)
	{
		bNeedWaitflag=true;
	
		GetFilemd5Value(temprtmd5,localflag,httpflag,false);

		CString newit,md52;
		newit.Format(_T("[imgurl]%s[/imgurl]"),*it);
		md52.Format(_T("[imgurl]%s[/imgurl]"),temprtmd5);
	defnumstr.Replace(newit,md52);

	
	}
	else if(defnumstr.Find(_T("图片未上传完则不发出消息"))!=-1)
	{
		bHideIfNotAvailable=true;
	
	}
	else
	{

		GetFilemd5Value(temprtmd5,localflag,httpflag,false);

		if(!temprtmd5.IsEmpty())
	if(!bAutoTransfertoXMLflag||localflag||(g_notxmlwhenprivate&&toqq))
		{
CString newit,md52;
		newit.Format(_T("[imgurl]%s[/imgurl]"),*it);
		md52.Format(_T("[imgurl]%s[/imgurl]"),temprtmd5);
	defnumstr.Replace(newit,md52);
		}
	
	}
		
		
	}
	}
	
	
	if(!bPrivateImgFlag&&bGchatflag)
	{

		//boost::wregex expression(_T("http://gchat.qpic.cn/gchatpic_new/.+(\w{32})/0\\?.+&term=2"),boost::wregex::normal|boost::wregex::icase);//,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");
	//http://gchat.qpic.cn/gchatpic_new//--67A4B6CF6F0A823E5C8218B320E6F2C3/0
		CString rtmatchstr;
	BOOL	bGetmatch=0;

	expressstr.Format(_T("(?<=-)\\w{32}(?=/0)"));

	//销毁 13402429 核弹
bGetmatch=GetFirstRegMatch(*it,expressstr,rtmatchstr,true);
		//findbuf=boost::regex_replace(findbuf,expression,_T("$1"));
		if(bGetmatch)
		{
			CString newit,md52;
		newit.Format(_T("[imgurl]%s[/imgurl]"),*it);
		md52.Format(_T("[imgurl]%s[/imgurl]"),rtmatchstr);
	defnumstr.Replace(newit,md52);

	//	defnumstr.Replace(*it,rtmatchstr);
		}
	//-\w{32}/0?
	}
	}
}

if(bNeedWaitflag)//图片上传完再发出消息
{
	//needwaitimgpathset
	//defnumstr
	//m_realgroupnumber toqq backupuin

	if(bPrivateImgFlag)
	{
		_UploadGroupwaitImgStruct *pqqgroup=new UploadGroupwaitImgStruct;
	pqqgroup->m_realgroupnumber=m_realgroupnumber;
	pqqgroup->toqq=toqq;
	pqqgroup->backupuin=backupuin;
	pqqgroup->defnumstr=defnumstr;
	pqqgroup->msgid=quotemsgid;
	pqqgroup->needwaitimgpathset=needwaitprivateimgpathset;


	AfxBeginThread(ProWaitUploadPrivateImg,pqqgroup);

	}
	else
	{
			_UploadGroupwaitImgStruct *pqqgroup=new UploadGroupwaitImgStruct;
	pqqgroup->m_realgroupnumber=m_realgroupnumber;
	pqqgroup->toqq=toqq;
	pqqgroup->backupuin=backupuin;
	pqqgroup->defnumstr=defnumstr;
	pqqgroup->needwaitimgpathset=needwaitimgpathset;
	pqqgroup->msgid=quotemsgid;
	AfxBeginThread(ProWaitUploadGroupImg,pqqgroup);
	}
	return false;
}

if(bHideIfNotAvailable)	
	defnumstr=_T("");
else
defnumstr.Replace(_T("图片未上传完则不发出消息"),_T(""));

defnumstr.Replace(_T("图片上传完再发出消息"),_T(""));


if(defnumstr.Find(_T("仅用于预先上传图片而不显示消息"))!=-1)
defnumstr=_T("");




}

CString imgurlrpstr1, imgurlrpstr2;
CString md5value;
for (auto it = needwaitimgpathset.begin(); it != needwaitimgpathset.end(); it++)
{
	lockweb2md5mapres.Lock();
	g_web2md5Map.Lookup(*it, md5value);
	lockweb2md5mapres.Unlock();
	imgurlrpstr1.Format(_T("[imgurl]%s[/imgurl]"), *it);
	imgurlrpstr2.Format(_T("[imgurl]%s[/imgurl]"), md5value);
	defnumstr.Replace(imgurlrpstr1, imgurlrpstr2);
}

if(!SendFinalMsg(m_realgroupnumber,toqq,defnumstr,backupuin,bAutoTransfertoXMLflag,bExactXmlflag,maxsize,quotemsgid))
	return false;

	int result=1;//sdk.Fun_send_msg(mysendv,myseq,prnum);

	NewTESTFUNTIME(android_send1msg)

return result;

	
}
BOOL SendSessionqqMsg(INT64 groupuin,INT64 toqq,LPCTSTR msgcontent,int prnum)
{
	
	{
	
	return Android_Send1Msg(groupuin,toqq,msgcontent,toqq);
	}

}
BOOL SendGroupqqMsg(INT64 groupuin,LPCTSTR msgcontent,int prnum)
{
	
	
	
	{
	
	return Android_Send1Msg(groupuin,0,msgcontent);
	}


}
BOOL GetKeyAndSigStr()
{
	
	if(!m_alreadylogin)
		return false;


CString realhostname;
CString processpath;
realhostname=_T("d1.web2.qq.com");
CString timestr2;
SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format(_T("%I64d%d"),time1.GetTime(),st.wMilliseconds);
processpath.Format(_T("/channel/get_gface_sig2?clientid=%d&psessionid=%s&t=%s"),clientID,psessionidstr,timestr2);
	UINT ddlen=0;
	byte buf[1024];
BOOL rtflag=MySendWeb(realhostname,processpath,buf,(char*)NULL,ddlen);
//::MessageBoxA(0,(char*)buf,0,0);
CString expressstr;
CString rtmatchstr;
BOOL bGetmatch;
expressstr.Format(_T("(?<=\"gface_key\":\")\\w+?(?=\")"));
bGetmatch=GetFirstRegMatch((char*)buf,expressstr,rtmatchstr,true);
if(bGetmatch)
{
	imgkeystr=(CStringA)rtmatchstr;
}
expressstr.Format(_T("(?<=\"gface_sig\":\")\\w+?(?=\")"));
bGetmatch=GetFirstRegMatch((char*)buf,expressstr,rtmatchstr,true);
if(bGetmatch)
{
	imgsigstr=(CStringA)rtmatchstr;
}
return rtflag;
}

BOOL SendGroupImgqqMsg(INT64 groupuin,LPCTSTR msgcontent)
{
	
	{
	
	return Android_Send1Msg(groupuin,0,msgcontent);
	}

}
void C晨风qq机器人Dlg::PopUpRobotAd()
{
	 g_alreadyhomepage=true;
	
}


//void GetFontNameAndSize()
//{
//
//	CString colorfstr=SaveAs_complete_path(_T("字体名称及大小设置.txt"));
//	
//
//		
//	CReadAUStdioFile file1;
//	CString tempstr;
//	g_fontname=_T("宋体");
//g_fontsize=10;
//	if(file1.Open(colorfstr,CFile::modeRead|CFile::shareDenyNone))
//	{
//		if(file1.ReadString(tempstr))
//		g_fontname=tempstr;
//		if(file1.ReadString(tempstr))
//		g_fontsize=_ttoi(tempstr);
//
//		file1.Close();
//
//	}
//	
//}

vector<COLORREF> randcolorvect;
vector<COLORREF> xmlrandcolorvect;

void GetAllColor(BOOL bXmlFlag)
{
	COLORREF randcolor;
	CStringvect vectemp;
	if(bXmlFlag)
	::function::getmytoken((*p_g_xmlfontcolorstr),_T(";；"),vectemp);	
	else
	::function::getmytoken(g_fontcolorstr,';',vectemp);	
	if(bXmlFlag)
	xmlrandcolorvect.clear();
	else
	randcolorvect.clear();

	if(vectemp.size()>0&&!vectemp[0].IsEmpty())
	{
	for(int i=0;i<vectemp.size();i++)
	{
			randcolor=_tcstol(vectemp[i],NULL,16);

if(bXmlFlag)
xmlrandcolorvect.push_back(randcolor);
else
	randcolorvect.push_back(randcolor);

	}
	}
}

COLORREF GetRandColor(BOOL bXmlFlag)
{

	COLORREF randcolor;
	
	vector<COLORREF>* pvector=NULL;
	if(bXmlFlag)
		pvector=&xmlrandcolorvect;
	else
		pvector=&randcolorvect;

	if((*pvector).size()==0)
	{
	
		if(bXmlFlag)
		{
		randcolor=0xFF0000;
		}
		else
		{
	int rcolor=rand()%256;
	int gcolor=rand()%256;
	int bcolor=rand()%256;
	if(rcolor>230&&gcolor>230&&bcolor>230)
	randcolor=RGB(0,0,0);
	else
	randcolor=RGB(rcolor,gcolor,bcolor);
		}
}
	else
	{
		static int icolor=0;
		icolor++;
	randcolor=(*pvector)[icolor%(*pvector).size()];

	//int r,g,b;
	//if(randcolor<0xAA)
	//{
	//}
	//else
	//{
	//r=GetBValue(randcolor);//获得R
	//	g=GetGValue(randcolor);//G
	//	b=GetRValue(randcolor);//B
	//	randcolor=RGB(r,g,b);
	//}

	}
	return randcolor;
}

void AppendPlugsMenu()
{
	BOOL bAppok = true;
	HMENU menu1=::GetMenu(mainhwnd);
	if (!g_alldllmenu_nmmcount)
	{
		g_alldllmenu_nmmcount = 3;// ::GetMenuItemCount(menu1);

		 bAppok= ::InsertMenu(menu1, g_alldllmenu_nmmcount, MF_STRING | MF_BYPOSITION | MF_POPUP, (UINT)menu1, _T("插件设置"));
	}
	if (bAppok)
	{
		HMENU pp = ::GetSubMenu(menu1, g_alldllmenu_nmmcount);

		if (pp)
		{
int nmmcount = ::GetMenuItemCount(pp);
for (int i = nmmcount - 1; i >= 0; i--)
::DeleteMenu(pp, i, MF_BYPOSITION);
if (g_vectormenustr.GetCount() > 0)
{
	HMENU plugsmenu = NULL;
	CString tempinifilename;


	for (UINT i = 0; i < g_vectormenustr.m_mapstr.size(); i++)
	{
		CString showdllname = g_vectormenustr.m_mapstr[i];
		::function::TrimRight(showdllname, _T(".dll"));
		BOOL bAppok = ::InsertMenu(pp, i, MF_STRING | MF_BYPOSITION | MF_POPUP, (UINT)pp, showdllname);


		if (bAppok)
		{
			plugsmenu = ::GetSubMenu(pp, i);

			if (plugsmenu)
			{

				tempinifilename = g_vectormenustr[i];
				CStringvect vectemp;
				::function::getmytoken(tempinifilename, _T("|"), vectemp);
				int minn = min(vectemp.size(), 20);
				for (int n = 0; n <minn; n++)
					::InsertMenu(plugsmenu, 0, MF_STRING, ID_Dynamicplugs + i * 20 + n, vectemp[n]);

			
			}

		}

	}
	
}
DrawMenuBar(mainhwnd);
		}
	}
}

time_t FileTimeToTime_t(const FILETIME &ft)  
{  
    ULARGE_INTEGER ui;  
    ui.LowPart = ft.dwLowDateTime;  
    ui.HighPart = ft.dwHighDateTime;  
    return ((LONGLONG)(ui.QuadPart - 116444736000000000) / 10000000);  
}  
#define PER_SECOND 1*10*1000*1000  /* filetime中代表1秒 */
//SYSTEMTIME TimetToSystemTime(INT64 t)
//{
//	if(t>INT32_MAX)
//		t=INT32_MAX;
//    FILETIME ft;
//    SYSTEMTIME pst;
//    
//LONGLONG nLL =Int32x32To64(t, 10000000) + 116444736000000000;
//	
//    ft.dwLowDateTime = (DWORD)nLL;
//    ft.dwHighDateTime = (DWORD)(nLL >> 32);
//	//ULARGE_INTEGER ui;  
//	//ui.QuadPart=nLL;
//	// ft.dwLowDateTime=ui.LowPart;  
// //   ft.dwHighDateTime=ui.HighPart; 
//    FileTimeToSystemTime(&ft, &pst);
//
//	
//   return pst;
//}
SYSTEMTIME TimetToLocalTime(INT64 t)
{
	t=t+8*60*60;
	if(t>INT32_MAX)
		t=INT32_MAX;

    FILETIME ft;
    SYSTEMTIME pst;
    
LONGLONG nLL =Int32x32To64(t, 10000000) + 116444736000000000;
	
    ft.dwLowDateTime = (DWORD)nLL;
    ft.dwHighDateTime = (DWORD)(nLL >> 32);
	//ULARGE_INTEGER ui;  
	//ui.QuadPart=nLL;
	// ft.dwLowDateTime=ui.LowPart;  
 //   ft.dwHighDateTime=ui.HighPart; 
    FileTimeToSystemTime(&ft, &pst);

	
   return pst;
}

//INT64 ConvertTimeToInt(const SYSTEMTIME &t1)  
//{  
//    FILETIME fTime1 = { 0, 0 };  
//   
//    SystemTimeToFileTime(&t1, &fTime1); 
//  
//    time_t tt1 = FileTimeToTime_t(fTime1); 
//	return tt1;
//}
INT64 ConvertLocalTimeToInt(const SYSTEMTIME &t1)  
{  
    FILETIME fTime1 = { 0, 0 };  
   
    SystemTimeToFileTime(&t1, &fTime1); 
  
    time_t tt1 = FileTimeToTime_t(fTime1)-8*60*60; 
	return tt1;
}
void GetNextdivine(CReadAUStdioFile& helpfile,CString& explainstr)
{
	CString tempstr;
	ULONGLONG lastpos=helpfile.GetPosition();
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;
		
	
		if(_ttoi(tempstr))
		{
		helpfile.Seek(lastpos,CFile::SeekPosition::begin);
		if(explainstr.GetLength()>=2)
	explainstr=explainstr.Left(explainstr.GetLength()-2);

		break;//回退
		}
		explainstr+=tempstr;
		explainstr+=_T("\r\n");
		lastpos=helpfile.GetPosition();
	}
}

void GetNextDream(CReadAUStdioFile& helpfile,CString& explainstr)
{
	CString tempstr;
	ULONGLONG lastpos=helpfile.GetPosition();
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;
		tempstr.Replace(_T(":"),_T("："));
		if(tempstr.Find(_T("："))!=-1)
		{
			helpfile.Seek(lastpos,CFile::SeekPosition::begin);
		break;//回退
		}

		if(tempstr.GetLength()<6)
		{
			helpfile.Seek(lastpos,CFile::SeekPosition::begin);
		break;//回退
		}
		explainstr+=tempstr;
		explainstr+=_T("\r\n");
		lastpos=helpfile.GetPosition();
	}
}

void C晨风qq机器人Dlg::ReleaseAllFile()
{
	
g_ownqqfn=SaveAs_complete_path(_T("自动回复设置文件.txt"));
g_selfgamefn=SaveAs_complete_path(_T("自定义小游戏.txt"));
g_foreverblackfn=SaveAs_complete_path(_T("永久黑名单.txt"));
g_notreplyprivatefn=SaveAs_complete_path(_T("不回复的好友列表.txt"));

g_moreselfgamedir=SaveAs_complete_path(_T("更多小游戏文件可放这里"));

g_defgamefn=SaveAs_complete_path(_T("更多小游戏文件可放这里\\通过网络更新的自定义游戏.txt"));

g_privilegeownqqfn=SaveAs_complete_path(_T("优先设定的回复内容.txt"));

	g_qqruledir=SaveAs_complete_path(_T("群规则设置文件\\"));
g_qqreplydir=SaveAs_complete_path(_T("群自动回复设置文件\\"));
g_groupimgdir=SaveAs_complete_path(_T("群图片文件\\"));
g_voicedir=SaveAs_complete_path(_T("群语音文件\\"));

	g_qqreceivefiledir=SaveAs_complete_path(_T("自动接收文件\\"));
	g_plusdir=SaveAs_complete_path(_T("机器人插件\\"));
		
	
	
	
g_grouprankpath=SaveAs_complete_path(_T("机器人插件\\综合查询_群积分文件\\"));
if(!PathFileExists(g_grouprankpath))
g_grouprankpath=SaveAs_complete_path(_T("群积分文件\\"));

if(!g_specifygrouprankpath.IsEmpty())
{
	if(!PathFileExists(g_specifygrouprankpath))
		CreateDirectory(g_specifygrouprankpath,NULL);

g_grouprankpath=g_specifygrouprankpath;

}


if(!PathFileExists(g_moreselfgamedir))
		{
		CreateDirectory(g_moreselfgamedir,NULL);
		}

	if(!PathFileExists(g_grouprankpath))
		{
		CreateDirectory(g_grouprankpath,NULL);
		}
		if(!PathFileExists(g_plusdir))
		{
		CreateDirectory(g_plusdir,NULL);
		}
	
	if(!PathFileExists(g_qqruledir))
		{
		CreateDirectory(g_qqruledir,NULL);
		}
if(!PathFileExists(g_qqreplydir))
		{
		CreateDirectory(g_qqreplydir,NULL);
		}
if(!PathFileExists(g_groupimgdir))
		{
		CreateDirectory(g_groupimgdir,NULL);
		}
if(!PathFileExists(g_voicedir))
		{
		CreateDirectory(g_voicedir,NULL);
		}

		if(!PathFileExists(g_qqreceivefiledir))
		{
g_autoreceiveflag=false;
		//CreateDirectory(g_qqreceivefiledir,NULL);
		}
		else
			g_autoreceiveflag=true;


	CString realsefilepath;
	CString selfdefhelp=SaveAs_complete_path(_T("自定义帮助文件.txt"));
	BOOL bSelfdef=PathFileExists(selfdefhelp);
	
realsefilepath=SaveAs_complete_path(_T("机器人管理员命令大全.txt"));
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather2);

realsefilepath=SaveAs_complete_path(_T("帮助.txt"));

if(!bSelfdef||!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather3);



	realsefilepath=SaveAs_complete_path(_T("官方最新版.帮助.txt"));
	::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather3);


realsefilepath=SaveAs_complete_path(_T("自定义小游戏.txt"));
if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather24);

//realsefilepath=SaveAs_complete_path(_T("背景图片.jpg"));
//if(!PathFileExists(realsefilepath))
//::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather26);

//realsefilepath=SaveAs_complete_path(_T("自定义小游戏官方最新版（仅用于参看，不会起作用）.txt"));
//::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather24);

realsefilepath=SaveAs_complete_path(_T("晨风机器人变量大全.txt"));
if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather25);

realsefilepath=SaveAs_complete_path(_T("周公解梦全集.txt"));
if(!bSelfdef||!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather10);


realsefilepath=SaveAs_complete_path(_T("自定义帮助文件.txt"));
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather9);
realsefilepath=::function::CFSoft_path(_T("成语大全.txt"),0,g_bLocalSaveflag);

if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather12);

realsefilepath=::function::CFSoft_path(_T("抽签.txt"),0,g_bLocalSaveflag);
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather21);


realsefilepath=::function::CFSoft_path(_T("快递编码.txt"),0,g_bLocalSaveflag);
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather20);


realsefilepath=SaveAs_complete_path(_T("更多个性配置.txt"));
if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather4);

realsefilepath=SaveAs_complete_path(_T("群聊时不回复或者没显示回复的处理办法.txt"));
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather5);
CString manualstrfmt;

manualstrfmt.Format(_T("%sqq机器人使用说明.txt"),_T("晨风"));

realsefilepath=SaveAs_complete_path(manualstrfmt);
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather6);


//realsefilepath=SaveAs_complete_path(_T("表情输入对照表.jpg"));
//::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather7);
realsefilepath=SaveAs_complete_path(_T("自动回复设置文件.txt"));
//if(!PathFileExists(realsefilepath))
	//::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather8);

//realsefilepath=SaveAs_complete_path(_T("男女符号.txt"));
//if(!PathFileExists(realsefilepath))
//	::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather18);

realsefilepath=SaveAs_complete_path(_T("输入替换.txt"));
if(!PathFileExists(realsefilepath))
	::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather15);
realsefilepath=SaveAs_complete_path(_T("输出替换.txt"));
if(!PathFileExists(realsefilepath))
	::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather16);

realsefilepath=SaveAs_complete_path(_T("新定时执行重新登录等指令.txt"));
if(!PathFileExists(realsefilepath))
	::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather17);

realsefilepath=SaveAs_complete_path(_T("优先设定的回复内容.txt"));
if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather11);

realsefilepath=SaveAs_complete_path(_T("抢答题.txt"));

if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather13);



realsefilepath=SaveAs_complete_path(_T("自定义广告尾巴.txt"));

if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather23);


realsefilepath=SaveAs_complete_path(_T("姓名配对.txt"));

if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather18);

realsefilepath=SaveAs_complete_path(_T("人品计算.txt"));

if(!PathFileExists(realsefilepath))
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather14);

//realsefilepath=SaveAs_complete_path(_T("如何不注册也能玩成语接龙和修改名片.txt"));

//if(!PathFileExists(realsefilepath))
//::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather22);

//realsefilepath=SaveAs_complete_path(_T("更多武器名称.txt"));
//
//if(!PathFileExists(realsefilepath))
//::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather19);

realsefilepath=SaveAs_complete_path(_T("抢答题官方最新版.txt"));
::function::releaseself(realsefilepath,_T("WAVE"),false,IDR_weather13);




	//if(!PathFileExists(SaveAs_complete_path(_T("QQ表情输入对照表.jpg"))))
	// g_qqregflag=true;
	//else
	g_qqregflag=false;


	g_speedonly=false;



}
CKeepMap<int,int,setvector<CString>,setvector<CString>> g_taskcmd_map;
void LoadPreLoadDllFile()
{
	
		
	CReadAUStdioFile uufile;
	
	CString uunamepwdfn=SaveAs_complete_path(_T("自动加载的dll列表.txt"));
	CString tempstr;

	if(uufile.Open(uunamepwdfn,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeRead|CFile::shareDenyNone))
	{

	CString paramstr;
	paramstr.Format(_T("cfrobotselfnum=%lld&mainhwnd=%d&initname=autoload&cfandroidflag=0&myhwnd=%d&startmanual=%d"), g_interfaceuin,mainhwnd,mainhwnd,bDllOver6dayflag);
	CString txtcontent;

		while(uufile.ReadString(tempstr))
		{
		if(tempstr.IsEmpty()||tempstr.GetAt(0)=='/')
			continue;
		txtcontent=_T("");

			GetDllresultText(tempstr,_T("startdllfun"),paramstr,false,txtcontent);
			if (txtcontent.Find('|') != -1)
			{
				g_vectormenustr[tempstr] = txtcontent;

				AppendPlugsMenu();
			}
		
			//在这里动态的出现菜单
		}
		
		//在这里把菜单都加上去

		uufile.Close();
	}
	
}
void LoadTaskFile()
{
	g_taskcmd_map.RemoveAll();
	CReadAUStdioFile uufile;
	
	CString uunamepwdfn=SaveAs_complete_path(_T("新定时执行重新登录等指令.txt"));
	CString tempstr;
	CString tempcmd;
	INT64 temptimeint;
	if(uufile.Open(uunamepwdfn,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeRead|CFile::shareDenyNone))
	{
		while(uufile.ReadString(tempstr))
		{
		if(tempstr.IsEmpty()||tempstr.GetAt(0)=='/')
			continue;
		if(GetTitleAndScore(tempstr,tempcmd,temptimeint))
		{
			g_taskcmd_map[(int)temptimeint].push_back(tempcmd);
		}

		}
		

		uufile.Close();
	}
				if(0)//g_taskcmd_map.GetCount()&&!Isggged)
		{
			AfxMessageBox(_T("未注册版本无法使用定时重新登录等功能！"));
		}
		
}
void LoadUUUsernameAndPwd()
{
	CReadAUStdioFile uufile;
	
	CString uunamepwdfn=SaveAs_complete_path(_T("超人打码用户名和密码文件.txt"));
	if(uufile.Open(uunamepwdfn,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeRead|CFile::shareDenyNone))
	{
		uufile.ReadString(uu_username);
		uufile.ReadString(uu_pwd);

		uufile.Close();
	}

}
UINT proPbSendMsgFun(LPVOID lp);
UINT proUploadPrivateImgSendMsgFun(LPVOID lp);
CFont* defbutfont;


void C晨风qq机器人Dlg::ButtonConfig(CWnd *mywnd, BOOL bShowTextflag, BOOL bTransparrent, const CString& frontstr, int cid)
{
	SetDlgItemText(cid, frontstr);

	if(g_forbidbkgflag)
		return;

	((CShadeButtonST*)mywnd)->SetShowText(bShowTextflag);
	((CShadeButtonST*)mywnd)->DrawTransparent(bTransparrent);

	

	CString stricopath = SaveAs_complete_path(frontstr + _T(".ico"));
	if (PathFileExists(stricopath))
	{

		((CShadeButtonST*)mywnd)->SetIcon(stricopath,NULL);

	}
	else
	{

		CString stricopath1 = SaveAs_complete_path(frontstr+_T("1.ico"));

		CString stricopath2 = SaveAs_complete_path(frontstr+_T("2.ico"));

		if(PathFileExists(stricopath1)||PathFileExists(stricopath2))
		{
			if(!PathFileExists(stricopath1))
				stricopath1 = _T("");
			if(!PathFileExists(stricopath2))
				stricopath2 = _T("");

			((CShadeButtonST*)mywnd)->SetIcon(stricopath1,stricopath2);

		}
		else
		{
			CString strpath1 = SaveAs_complete_path(frontstr+_T("1.bmp"));
			CString strpath2 = SaveAs_complete_path(frontstr+_T("2.bmp"));

			if(PathFileExists(strpath1))
			{
				if(!PathFileExists(strpath2))
					strpath2 = _T("");


				((CShadeButtonST*)mywnd)->SetBitmaps(strpath1,RGB(255,255,255),strpath2,RGB(255,255,255));

			}
		}
	}
	//((CShadeButtonST*)mywnd)->Invalidate();
}

void C晨风qq机器人Dlg::rerangeButton()
{

	for (UINT i = 0; i < g_dynbuttonmap.GetSize(); i++)
	{
		g_dynbuttonmap[i]->ShowWindow(SW_HIDE);
	}

	CRect temprect1;
	CString windowtext;
	CString comtextrectstr;
	g_openqqlisttext = _T("");
	g_replaceskintitle= _T("");
	g_loginshowtext= _T("");
	CReadAUStdioFile filepwd;
	if (filepwd.Open(SaveAs_complete_path(_T("窗口布局.txt")), CFile::modeRead))
	{
		CString frontstr, backstr;
		CString bTransparrentstr, bShowTextflagstr;
		int l = 0, t = 0, r = 0, b = 0;
		CStringvect vectemp;
		if (filepwd.ReadString(comtextrectstr))
		{
			if (::function::GetHalfStr(comtextrectstr, &frontstr, &backstr, _T("\t"), false))
			{
				::function::getmytoken(backstr, _T(","), vectemp);
				if (vectemp.size() > 3)
				{
					l = _ttoi(vectemp[0]);
					t = _ttoi(vectemp[1]);
					r = _ttoi(vectemp[2]);
					b = _ttoi(vectemp[3]);

				}
				g_replaceskintitle = frontstr;
				SetWindowText(frontstr);
				CRect rcWindow;
				CRect rcClient;
				int borderWidth = 0;
				int borderHeight = 0;
				GetWindowRect(rcWindow);
				GetClientRect(rcClient);
				borderWidth = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
				borderHeight = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);
				if (r&&b)
					SetWindowPos(NULL, 0, 0, borderWidth + r, borderHeight + b, SWP_NOMOVE | SWP_NOZORDER);
			}

			//窗口标题
		}
		CStringvect vectbuttonshow;
		for (int i = 0; i < g_ctronlidvect.size(); i++)
		{
			if (!filepwd.ReadString(comtextrectstr))
				break;

			frontstr = _T("");
			backstr = _T("");
			
			BOOL bTransparrent = 0;
			BOOL bShowTextflag = 1;
			//::function::GetHalfStr(comtextrectstr, &frontstr, &backstr, _T("\t"), false);
			::function::getmytoken(comtextrectstr, _T("\t"), vectbuttonshow);
			{
				if (vectbuttonshow.size() >= 1)
				{
					frontstr = vectbuttonshow[0];
				}
				if (vectbuttonshow.size() >= 2)
				{
					backstr = vectbuttonshow[1];
				}
if (vectbuttonshow.size() >= 3)
				{
	bTransparrent =_ttoi(vectbuttonshow[2]);
				}
if (vectbuttonshow.size() >= 4)
{
	bShowTextflag = _ttoi(vectbuttonshow[3]);
}



				::function::getmytoken(backstr, _T(","), vectemp);
				l = 0, t = 0, r = 0, b = 0;
				if (vectemp.size() > 3)
				{
					l = _ttoi(vectemp[0]);
					t = _ttoi(vectemp[1]);
					r = _ttoi(vectemp[2]);
					b = _ttoi(vectemp[3]);

				}
				else if (frontstr.Find(',') != -1)
				{
					::function::getmytoken(frontstr, _T(","), vectemp);
					if (vectemp.size() > 3)
					{
						l = _ttoi(vectemp[0]);
						t = _ttoi(vectemp[1]);
						r = _ttoi(vectemp[2]);
						b = _ttoi(vectemp[3]);

					}
					frontstr = _T("");
				}

				CWnd *mywnd = GetDlgItem(g_ctronlidvect[i]);
				if (mywnd)
				{
					if (!frontstr.IsEmpty())
					{
						if (IDC_BUTTON5 == g_ctronlidvect[i])
						{
							g_openqqlisttext = frontstr;

							ButtonConfig(mywnd, bShowTextflag, bTransparrent, frontstr, g_ctronlidvect[i]);

						}
						else if (IDC_BUTTON1 == g_ctronlidvect[i])
						{
							TCHAR alreadytext[256];
							g_loginshowtext = frontstr;
							GetDlgItemText(g_ctronlidvect[i], alreadytext,256);
							if (!m_alreadylogin&&!StrStr(alreadytext, _T("已登录")))
							{
								ButtonConfig(mywnd, bShowTextflag, bTransparrent, frontstr, g_ctronlidvect[i]);
							}
						}
						else if (i<5)
						SetDlgItemText(g_ctronlidvect[i], frontstr);
						else
						{
							ButtonConfig(mywnd, bShowTextflag, bTransparrent, frontstr, g_ctronlidvect[i]);
						}
						
					}
					if ((l + t + r + b) == 0)
					{
						mywnd->ShowWindow(SW_HIDE);
					}
					else
					{
						mywnd->MoveWindow(CRect(l, t, r, b));
						mywnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					if(!g_forbidbkgflag)
					mywnd = new CShadeButtonST();
					else
					mywnd = new CButton();

					g_dynbuttonmap[g_ctronlidvect[i]] = (CButton*)mywnd;

					CRect temprect(l, t, r, b);
					if (((CButton*)mywnd)->Create(frontstr, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, temprect, this, g_ctronlidvect[i]))
					{

						mywnd->SetFont(defbutfont, FALSE);
						if(!g_forbidbkgflag)
						((CShadeButtonST*)mywnd)->SetShade(CShadeButtonST::SHS_SOFTBUMP);

						ButtonConfig(mywnd, bShowTextflag, bTransparrent, frontstr, g_ctronlidvect[i]);
						//mywnd->MoveWindow(CRect(l, t, r, b));
						//SetDlgItemText(idvect[i], frontstr);
						//mywnd->ShowWindow(SW_SHOW);
					}
				}
			}
		}


		filepwd.Close();
	}
}
void C晨风qq机器人Dlg::reloadinterfaceandlayout()
{
	HINSTANCE	hInstResource = NULL;
	if (!m_bkgimage.IsNull())
		m_bkgimage.Detach();

	CString bkghelppath;
	bkghelppath = SaveAs_complete_path(_T("窗口布局.txt"));
	if (!PathFileExists(bkghelppath))
	{
		::function::releaseself(bkghelppath, _T("WAVE"), false, IDR_weather27);
	/*	bkghelppath = SaveAs_complete_path(_T("登录1.bmp"));
		if (!PathFileExists(bkghelppath))
			::function::releaseself(bkghelppath, _T("WAVE"), false, IDR_weather28);
		bkghelppath = SaveAs_complete_path(_T("登录2.bmp"));
		if (!PathFileExists(bkghelppath))
			::function::releaseself(bkghelppath, _T("WAVE"), false, IDR_weather29);*/
	}

	bkghelppath = SaveAs_complete_path(_T("背景图片.png"));
	if (!PathFileExists(bkghelppath))
	{
		bkghelppath = SaveAs_complete_path(_T("背景图片.bmp"));
		if (!PathFileExists(bkghelppath))
		{
			bkghelppath = SaveAs_complete_path(_T("背景图片.jpg"));
			if (!PathFileExists(bkghelppath))
				::function::releaseself(bkghelppath, _T("WAVE"), false, IDR_weather26);

		}

	}



	// Find correct resource handle
	if(!g_forbidbkgflag)
	{
		if(E_FAIL != m_bkgimage.Load(bkghelppath))
			m_bkghBitmap = (HBITMAP)m_bkgimage;

	}

	CString nIconpathIn = SaveAs_complete_path(_T("软件图标.ico"));
	m_hIcon = (HICON)::LoadImage(NULL, nIconpathIn, IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	if (!m_hIcon)
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	rerangeButton();

	Invalidate();
}
BOOL C晨风qq机器人Dlg::OnInitDialog()
{
	

	
	defbutfont = GetDlgItem(IDC_BUTTON1)->GetFont();
			//poptipsformat2=_T("http://qm.qq.com/cgi-bin/qm/qr?k=MilLiPd9fS-YE5kADg1OtqtxhdWNACV6");
poptipsformat2=_T("http://shang.qq.com/wpa/qunwpa?idkey=cc797bedf1957bf7536ceec79eb85bf5f75ec7b6b8cd119575550d81f1ba85ec");

	poptipsformat.Format(_T("晨风机器演示群：%d%d%d%d%d%d%d%d%d，你是否想立即申请加入(有任何不懂的问题，都可以在里面得到解答)？验证请求必须写你的机器人qq号。（但你应该用其它qq号加群，比如用机器人的主人qq号加群）"),5,5,4,0,4,5,6,9,0);
	
	 
	g_defaultpassword=_T("");
		
g_gamekey.resize(16,2);
g_gamekey[3]=55;
g_gamekey[12]=44;
g_gamekey[15]=37;			
		TCHAR modulename[256];
	GetModuleFileName(NULL,modulename,256);
		::function::GetFileVersion(modulename,_T("ProductVersion"),g_Verdatestr);
	g_purenumberversion=g_Verdatestr;
		if(g_purenumberversion.GetLength()==7)
		{
g_purenumberversion.AppendChar('0');

			//3.9.2.3.3
		}
		g_purenumberversion.Replace(_T("."),_T(""));
	WIN32_FIND_DATA wfd;
    FILETIME ft;


    // 获取文件属性信息
    FindClose(FindFirstFile(modulename, &wfd));
    FileTimeToLocalFileTime(&wfd.ftLastWriteTime, &ft);
	FileTimeToSystemTime(&ft,&g_locallasttime);
	
	g_modifydate.Format(_T("%d年%d月%d日 %02d:%02d"),g_locallasttime.wYear,g_locallasttime.wMonth,g_locallasttime.wDay,g_locallasttime.wHour,g_locallasttime.wMinute);
	
	SYSTEMTIME temptime;
	GetLocalTime(&temptime);
		initsystemtime=ConvertLocalTimeToInt(temptime);
		//hashO2(_T("151409321"),_T("c56275019d44d1be60aa8bc4957aba67bfc7619220235bf1a851e533a006c6c2"));
	CMyBGCDlg::OnInitDialog();
	
	mainhwnd = GetSafeHwnd();
	

	g_ctronlidvect.push_back(IDC_STATIClogin);
	g_ctronlidvect.push_back(IDC_STATICqq);
	g_ctronlidvect.push_back(IDC_COMBO4);
	g_ctronlidvect.push_back(IDC_STATICpwd);
	g_ctronlidvect.push_back(IDC_EDIT2);
	g_ctronlidvect.push_back(IDC_BUTTON1);
	g_ctronlidvect.push_back(IDC_BUTTON5);
	g_ctronlidvect.push_back(IDC_BUTTON4);
	g_ctronlidvect.push_back(IDC_BUTTON7);
	g_ctronlidvect.push_back(ID_32892);
	g_ctronlidvect.push_back(ID_32883);
	g_ctronlidvect.push_back(ID_32891);
	g_ctronlidvect.push_back(ID_32906);
	g_ctronlidvect.push_back(ID_32907);
	g_ctronlidvect.push_back(ID_32902);
	g_ctronlidvect.push_back(ID_32903);
	g_ctronlidvect.push_back(ID_32908);
	g_ctronlidvect.push_back(ID_32877);
	g_ctronlidvect.push_back(ID_32912);
	g_ctronlidvect.push_back(ID_32916);
	g_ctronlidvect.push_back(ID_32911);
	g_ctronlidvect.push_back(ID_32878);
	g_ctronlidvect.push_back(ID_32886);
	g_ctronlidvect.push_back(ID_32887);
	g_ctronlidvect.push_back(ID_32901);
	g_ctronlidvect.push_back(ID_32879);
	g_ctronlidvect.push_back(ID_32884);
	g_ctronlidvect.push_back(ID_32890);
	g_ctronlidvect.push_back(ID_32881);
	g_ctronlidvect.push_back(ID_32882);
	g_ctronlidvect.push_back(ID_32888);
	g_ctronlidvect.push_back(ID_32889);
	g_ctronlidvect.push_back(ID_32894);
	g_ctronlidvect.push_back(ID_32895);
	g_ctronlidvect.push_back(ID_32909);
	g_ctronlidvect.push_back(ID_32896);
	g_ctronlidvect.push_back(ID_32897);
	g_ctronlidvect.push_back(ID_32898);
	g_ctronlidvect.push_back(ID_32899);
	g_ctronlidvect.push_back(ID_32910);
	g_ctronlidvect.push_back(ID_32900);
	g_ctronlidvect.push_back(ID_32904);
	g_ctronlidvect.push_back(ID_32905);
	g_ctronlidvect.push_back(ID_32913);
	g_ctronlidvect.push_back(ID_32914);
	g_ctronlidvect.push_back(ID_32915);


BOOL btempfirstflag=LoadUserSetting(true);


	g_testplugpath=SaveAs_complete_path(_T("机器人插件\\testplug.dll"));

	if(PathFileExists(g_testplugpath))
	{
		 ::function::GetFileVersion(g_testplugpath,_T("ProductVersion"),g_Vertestdatestr);

		WIN32_FIND_DATA wfd;
		FILETIME ft;


		// 获取文件属性信息
		FindClose(FindFirstFile(g_testplugpath,&wfd));
		FileTimeToLocalFileTime(&wfd.ftLastWriteTime,&ft);
		FileTimeToSystemTime(&ft,&g_localtestlasttime);
		INT64	testplugchangetime=ConvertLocalTimeToInt(g_localtestlasttime);
		if(initsystemtime-testplugchangetime>60*60*24*6)
			bDllOver6dayflag=true;
	}

INT64	exechangetime=ConvertLocalTimeToInt(g_locallasttime);
	if(initsystemtime-exechangetime>60*60*24*10)
			bExeOver10dayflag=true;
		

	srand(time(NULL));
	
		short	shBtnColor = 30;
InitializeCriticalSection(&g_cslog);

if(!g_remoteencryptflag)
	{
	LoadUUUsernameAndPwd();
}
CString logpath=::function::complete_path(_T("记录弹出文件.txt"));
if(PathFileExists(logpath))
{
	g_tipsflag=true;
	magnetfile.SetUnicodeFile(true);
magnetfile.Open(logpath,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite|CFile::shareDenyNone,NULL);
}	
if(PathFileExists(::function::complete_path(_T("群智能配置.ini"))))
{
	bHideMainIcon=true;
}	




CString forbidbkgpath=SaveAs_complete_path(_T("禁用背景图片和按钮特效.txt"));
if(PathFileExists(forbidbkgpath))
g_forbidbkgflag = true;

if(!g_forbidbkgflag)
{
	m_basicbutton[0].SubclassDlgItem(IDC_BUTTON1,this);
	m_basicbutton[1].SubclassDlgItem(IDC_BUTTON5,this);
m_basicbutton[2].SubclassDlgItem(IDC_BUTTON4,this);
m_basicbutton[3].SubclassDlgItem(IDC_BUTTON7,this);

	
}
		reloadinterfaceandlayout();


g_interfaceuin = _ttoi64(g_lastownqq);
qq.QQ=g_interfaceuin;
if(!bFirsttime)
	bFirsttime=btempfirstflag;


	pggged=&Isggged;
	pcccflag2=&ccccflag2;

	

	if(!g_remoteencryptflag)
	{
	if(bFirsttime&&!companyverion&&g_customstr.IsEmpty())
	{
		ShellExecute(NULL,NULL,_T("http://www.qqshow123.com/weixin.html"),0,0,1);


	}
	}
	pcccccc=&ccccccc;
	if(!g_remoteencryptflag)
	{
	ReleaseAllFile();
	}	
	
	GetRuleFromFile(true,0,g_defaultqqgrouprule);

inittime=GetTickCount();

		TCHAR bufselfpath[256];//=
	//AfxMessageBox(_T("LoadUserSetting"));
	
	GetModuleFileName(NULL,bufselfpath,256);


	//::SetWindowPos(GetSafeHwnd(),HWND_TOPMOST,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
	//m_notcanceltop=true;
	//SetTimer(4,5000,NULL);
	//SetTimer(222,500,NULL);
	if(StrStrI(bufselfpath,_T("temp")))//如果是在压缩文件中直接双击
	{
	if(IDOK==MessageBox(_T("请把我先解压缩到某个目录下哦，不要在压缩文件中直接双击运行！是否现在退出，手动把压缩文件中的“晨风QQ机器人.exe”解压到某个目录下？"),_T("退出程序并手动解压到合适目录下"),MB_OKCANCEL))
	exit(0);
	//，否则自学习的内容和自动回复设置都无法保存哦！"));
	}
	if(!g_remoteencryptflag)
	{
	if(!g_autoreplyfile1.Open(g_ownqqfn,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite|CFile::shareDenyNone))
	{
		AfxMessageBox(_T("无法创建或打开“自动回复设置文件.txt”，软件将无法正常运行，请确认机器人所在的文件夹具有可写权限，不行的话，试试把里面的文件拷贝到其他目录下再运行！"));
	}

	
	if(!g_Privilegeautoreplyfile1.Open(g_privilegeownqqfn,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite|CFile::shareDenyNone))
	{
		AfxMessageBox(_T("无法创建或打开“优先设定的回复内容.txt”，软件将无法正常运行！"));
		
	}
	}
#ifdef twoeight
if(g_additionaltimerfile1.Open(::function::complete_path(_T("定时周期.txt")),CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite|CFile::shareDenyNone))
	{
		CString tempstr;
		if(g_additionaltimerfile1.ReadString(tempstr))
			g_timer2_gap=_ttoi(tempstr);

		g_additionaltimerfile1.Close();
	}
#endif

if(!g_forbidbkgflag)
{
	for(int i = 0; i < 4; i++)
	{
		m_basicbutton[i].SetShade(CShadeButtonST::SHS_SOFTBUMP);

	}
}
//
//if (0)
//m_basicbutton[0].SetIcon(NULL,_T("button1.ico"));
//if (1)
//m_basicbutton[0].SetBitmaps(_T("button1.bmp"), RGB(255, 255, 255), _T("button2.bmp"), RGB(255, 255, 255));
//

//m_basicbutton[0].SetShowText(false);
//m_loginqqbt.DrawTransparent(TRUE);
//m_loginqqbt.SetState(true);
//m_loginqqbt.SetBitmaps(_T("button1.bmp"), RGB(255, 255, 255));
//m_loginqqbt.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(200,223,136));
//		m_loginqqbt.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(100,123,136));
//		m_loginqqbt.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0,0,255));
//m_loginqqbt.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(255,0,0));
//
//	m_loginqqbt.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
//	m_loginqqbt.SetTooltipText(_T("点击此按钮进行登录，建议用申请了密保的qq小号做机器人。"));

	//m_loginqqbt.SetIcon(m_hIcon);

		


	if(bFirsttime&&!companyverion)
	{
	//	AfxMessageBox(_T("针对新的qq号，或者不在常用登录地登录的qq号，腾讯有很强的自动封禁政策（主要是担心这种号被用于诈骗或群发广告）。如想正常稳定使用机器人，请在不挂机器人的时候，尽量抽空用qq自己的电脑软件（比如qq2014，qq5.5之类的）每天挂几分钟，连续挂一个礼拜，等腾讯把你电脑那里识别为那个qq号的常用登录地了,就可以大大减少机器人被屏蔽和冻结的几率。"));
	}
	
		//LoadMoreSettingFile();
	if(!g_remoteencryptflag)
	{
		CReadAUStdioFile helpfile;
	CString helppath;
	helppath=SaveAs_complete_path(_T("QQ服务器IP.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
	
		if(tempstr.GetLength()<4)
			continue;
		GetPairStrFromReadFile(tempstr,frontstr,backstr);
	g_qqserveripmap[frontstr]=backstr;

	}
	
	helpfile.Close();
	}

helppath=SaveAs_complete_path(_T("邀请加群记录.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
	
		if(tempstr.GetLength()<4)
			continue;
		GetPairStrFromReadFile(tempstr,frontstr,backstr);

		//	CString keystr;
		//keystr.Format(_T("%lld_%lld"),tempsgmsg.groupUin,tempsgmsg.sendUin);
		
	g_joinqq_passqqnum_map[frontstr]=_ttoi64(backstr);


	}
	
	helpfile.Close();
	g_orginaljoinqq_passqqnum_map_count=g_joinqq_passqqnum_map.GetCount();
	}


	helppath=::function::CFSoft_path(_T("快递编码.txt"),0,g_bLocalSaveflag);
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;
		GetPairStrFromReadFile(tempstr,frontstr,backstr);
	g_expresscodemap[backstr]=frontstr;
	
	}
	g_expresscodemap[_T("快递")]=_T("kuaidikuaidi");
	g_expresscodemap.sortLen();
	
	helpfile.Close();
	}
	helppath=::function::CFSoft_path(_T("抽签.txt"),0,g_bLocalSaveflag);
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString piecedivine;
		
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;
		if(_ttoi(tempstr))
		{
		GetNextdivine(helpfile,piecedivine);

	g_divinevector.push_back(piecedivine);
	piecedivine=_T("");
		}

	}

	helpfile.Close();
	}

	}

	if(!g_remoteencryptflag)
	{
	
	sharehwnd=mainhwnd;
	}
	g_mainhwnddlg=this;
	GetWindowText(g_windowstext);


	GetDlgItemText(IDC_STATIClogin,g_loginwindowstext);

	//if(g_windowstext.Find(_T("晨风QQ机器人"))==-1||g_windowstext.Find(_T("破解"))!=-1)//||g_windowstext.Find(_T("此软件会让qq下线，正常现象，勿虑"))==-1
	//	{
	//		bCrackFlag=true;
	//	
	//	}
		/*if(g_loginwindowstext!=_T("先登录你的QQ")||g_loginwindowstext.Find(_T("破解"))!=-1)
		{
			bCrackFlag=true;
		}*/
	//IDC_STATIClogin

		SetIcon(m_hIcon, TRUE);	


	

			//SetDlgItemText(IDC_COMBO4,g_lastownqq);
	
	g_bTestplugexistflag=PathFileExists(g_testplugpath);
	

	
	//LoadPriviliegeFile();

		Gettransmitpm(_ttoi64(g_lastownqq));
	if(!g_remoteencryptflag)
	{
		ccccccc=GetCCCCCNum(g_lastownqq);
		limitnumber=ccccccc;
LoadPreLoadDllFile();
	}	
SetTimer(5,61*1000,NULL);
	//g_autoreplymap.sortLen();
	CString shortcnstr;
	GetShortCountrySign(shortcnstr,Lan_ID_NUM);
	m_addionalstr.Format(_T("LanID:%s_"),shortcnstr);

	g_notipadflag = !g_notipadflag;

	On32915();
	//NavigateOnce();

if(!g_remote_lastownqq.IsEmpty())
		SetDlgItemText(IDC_COMBO4,g_remote_lastownqq);
		if(!g_remote_defaultpassword.IsEmpty())
		SetDlgItemText(IDC_EDIT2,g_remote_lastownqq);

		//AfxMessageBox(_T("prepareremote11"));
		if(g_remoteencryptflag)
		{
			if(!g_interfaceuin)
	g_interfaceuin=_ttoi64(g_lastownqq);

		EncodeGameFile(g_remote_enfilepath,g_remote_setenvevent);
		OnCancel();
			exit(0);
		}
		else	if(bHideMainIcon||g_remoteloginflag)
	{
	//g_remote_lastownqq
		
		//AfxMessageBox(_T("prepareremote"));
		OnBnClickedButton1();
	}
	else if(retryloginflag2)
	{
			
	OnBnClickedButton1();
	}
	else if(retryloginflag3)
	{
		Sleep(10000);
	OnBnClickedButton1();
	}
	else if(g_autologinflag||retryloginflag)
	{

		if(retryloginflag)
			if(1)//((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
			{
			Sleep(10000);
			}
	
	OnBnClickedButton1();
	}
		if((!bFirsttime&&g_bTuopanflag&&g_autologinflag)||bHideMainIcon)
			{
			init_hide=true;
			ontuopan();
	}
	return true;  // 除非将焦点设置到控件，否则返回 TRUE
}
void LoadInputReplacemap(LPCTSTR path,CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>&  inoutreplacemap,int type/*=0*/,LPCTSTR keystr/*=NULL*/,LPCTSTR valuestr/*=NULL*/)//type==0,读取，type==1，添加keystr，type==2，删除keystr
{
	
	CReadAUStdioFile helpfile;
	UINT openflag=CFile::modeRead|CFile::shareDenyNone;
	if(type)
openflag=CFile::modeReadWrite|CFile::shareDenyNone;

		BOOL bEncoded=false;
DWORD filesize=0;


	
	filesize=::function::GetFileSizeFromPath(path);
			

			if(StrStrI(path,_T(".encode.")))
				bEncoded=true;

					CString tempstr,qqstr,qqpasswordstr;
		int itemcount;
		CString frontstr,backstr;
	

	if(!helpfile.Open(path,openflag))
	{
		return;
	}
	if(type==0)
	{
	
	if(bEncoded)
	{
			byte *readbuf=new byte[filesize];
			DWORD readfilesize=helpfile.Read(readbuf,filesize);

			int returnsize=0;
			byte *temp6=new byte[readfilesize+48+2];
byte versionbuf[17]="";
if(readfilesize)
if(fileunpack(readbuf,readfilesize,&g_gamekey[0],temp6,&returnsize,versionbuf,path))//Crypt::tencentt(2,readbuf,readfilesize,&g_gamekey[0],temp6,&returnsize))
{
temp6[returnsize]=0;
temp6[returnsize+1]=0;
CString wholefilesentence=(LPCTSTR)temp6;
TCHAR tempversionbuf[9];
	memcpy(tempversionbuf,versionbuf,16);
	tempversionbuf[8]=0;
			CString tempversionstr=tempversionbuf;
		tempversionstr.Replace(_T("."),_T(""));
int versionnum=_ttoi(tempversionstr);

int useversionnum=versionnum*13/7;
BOOL bNewestDopackflag=false;
BOOL bSimpleEncodeFlag=false;
if(versionnum>=11019000&&::function::bittest(versionnum,1))
	bSimpleEncodeFlag=true;

if(bSimpleEncodeFlag)
{
	byte *waitdecodebuf=new byte[returnsize+48+2048];

	vector<byte> user_gamekey;

		CString	newkey;
		newkey.Format(_T("%d"),useversionnum);
GetUserDefKey(newkey,user_gamekey);

int secondsize=0;
Crypt::decrypt((byte*)temp6, returnsize, &user_gamekey[0], waitdecodebuf, &secondsize);  

waitdecodebuf[secondsize]=0;
waitdecodebuf[secondsize+1]=0;

wholefilesentence=(LPCTSTR)waitdecodebuf;


	delete []waitdecodebuf;
}

if(versionnum>=3990)
	bNewestDopackflag=true;
if(bSimpleEncodeFlag)
	bNewestDopackflag=false;


CStringvect vectemp;
CString tempstr,frontstr,backstr;
		setvector<CString>* temppushvect;
::function::getmytoken(wholefilesentence,_T("\r\n"),vectemp);
g_autoappendtext=_T("");
g_autoinserttext=_T("");

int maxcplen=1024*40;
TCHAR *templinestr=new TCHAR[maxcplen];

for(int i=0;i<vectemp.size();i++)
{
	CString tempvectempstr;

	tempvectempstr=vectemp[i];
	if(bNewestDopackflag)
	{
	//lstrcpy(templinestr,tempvectempstr);
		int actcplen=min(maxcplen-1,tempvectempstr.GetLength());
		_tcsncpy(templinestr,tempvectempstr,actcplen);
		templinestr[actcplen]=0;

	if(versionnum>=3991)
		xmlgetcodeutf(templinestr,false,useversionnum+i*19);
	else
	xmlgetcode(templinestr,false,useversionnum+i*19);
	tempvectempstr=templinestr;
	}

tempvectempstr.Trim();
		GetPairStrFromReadFile(tempvectempstr,frontstr,backstr);
	
	
			backstr.Replace(_T("【输入替换】"),_T(""));
		if(!frontstr.IsEmpty())
		{
		inoutreplacemap[frontstr].push_back(backstr);
		}


}
delete []templinestr;

}
	}
	else
	{
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		GetPairStrFromReadFile(tempstr,frontstr,backstr);
		
		backstr.Replace(_T("【输入替换】"),_T(""));
		if(!frontstr.IsEmpty())
		{
		inoutreplacemap[frontstr].push_back(backstr);
		}
	}
	}

inoutreplacemap.sortLen();

	}
	else if(type==1)
	{
		inoutreplacemap[keystr].push_back(valuestr);
	(helpfile).SetLength(0); 
		CString strfmt;
		int ncount=(inoutreplacemap).m_mapstr.size();
		setvector<CString> answervect;
		CString tempkeystr;
				for(int i=ncount-1;i>=0;i--)
				{
	tempkeystr=(inoutreplacemap).m_mapstr[(UINT)i];
	answervect=(inoutreplacemap)[i];
	for(auto it=answervect.begin();it!=answervect.end();it++)
	{
		strfmt.Format(_T("%s\t\t%s"),tempkeystr,*it);

		(helpfile).WriteLineStr(strfmt);
	
	}
					}
		

	}
	else if(type==2)
	{
setvector<CString> answervect;
	inoutreplacemap.Lookup(keystr,answervect);
	answervect.erase(::find(answervect.begin(),answervect.end(),valuestr));
	if(answervect.size()==0)
	{
	(inoutreplacemap).RemoveKey(keystr);
	}
	else
	(inoutreplacemap)[keystr]=answervect;


	(helpfile).SetLength(0); 
		CString strfmt;
		int ncount=(inoutreplacemap).m_mapstr.size();
	
		CString tempkeystr;
				for(int i=ncount-1;i>=0;i--)
				{
		tempkeystr=(inoutreplacemap).m_mapstr[(UINT)i];
	answervect=(inoutreplacemap)[i];
	for(auto it=answervect.begin();it!=answervect.end();it++)
	{
		strfmt.Format(_T("%s\t\t%s"),tempkeystr,*it);

		(helpfile).WriteLineStr(strfmt);
	
	}
		
	
					}
	}

	helpfile.Close();

}

void GetNewBuffer(vector<byte>& tempkey,const unsigned char* key,const byte* versionbuf,const byte* deqqnum)
{
	tempkey.resize(16);
	BOOL bBelowflag=true;
TCHAR tempversionbuf[9];//3.8.6.0.1
memset(tempversionbuf,0,18);

byte bufsize1[16];
memcpy(bufsize1,versionbuf,16);
	for(int i=0;i<16;i++)
		bufsize1[i]+=50;

	memcpy(tempversionbuf,bufsize1,16);

	

	if(lstrcmp(tempversionbuf,_T("3.8.6.0"))>0)
		bBelowflag=false;

	if(!bBelowflag)
	{
	for(int i=0;i<8;i++)
	{
	tempkey[i]=key[i]|versionbuf[i]|deqqnum[i];
	
	}
	for(int i=0;i<8;i++)
	{
	tempkey[i+8]=key[i+8]|versionbuf[i+8];
	
	}
	}
	else
	{
	for(int i=0;i<8;i++)
	{
	tempkey[i]=key[i]^versionbuf[i]^deqqnum[i];
	
	}
	for(int i=0;i<8;i++)
	{
	tempkey[i+8]=key[i+8]^versionbuf[i+8];
	
	}
	}


}
BOOL postfileunpack(const unsigned char* instr, int32 instrlen,const unsigned char* key,unsigned char*  outstr, int32* outstrlen_ptr,byte* versionbuf)
{
	
	vector<byte> tempkey;
	//获取新的key
	byte bufsize1[16];
	byte lookbufsize1[16];

	byte bufsize2[4];
	int *truestrlen;
	INT64 deqqnum=0;
	memcpy(bufsize1,instr,16);
	memcpy(lookbufsize1,bufsize1,16);
	for(int i=0;i<16;i++)
	lookbufsize1[i]+=50;

	memcpy(versionbuf,lookbufsize1,16);

	memcpy(bufsize2,instr+16,4);
		for(int i=0;i<4;i++)
		bufsize2[i]+=60;


		int32 newinstrlen=instrlen-8;//抵消增加的7个字节长度
		
		#ifndef _DEBUG
			if(!bNotLuanchflag)
		return false;
		#endif

	truestrlen=(int*)bufsize2;
	newinstrlen++;
	if(*truestrlen==newinstrlen-28)
	{
		memcpy(&deqqnum,instr+20+*truestrlen,8);
		GetNewBuffer(tempkey,key,bufsize1,(byte*)&deqqnum);
	return Crypt::decrypt(instr+20, *truestrlen, &tempkey[0], outstr, outstrlen_ptr); 
	}
	else
	return Crypt::decrypt(instr, newinstrlen, key, outstr, outstrlen_ptr);
}
void GetUserDefKey(LPCTSTR newkey,vector<byte>&user_gamekey)
{

	CString md5str;
	user_gamekey.resize(16);
	::function::SafeGetCff(md5str,newkey,lstrlen(newkey)*2,false);

	GetArrayByteFromMd5(md5str,&user_gamekey[0]);
}
BOOL fileunpack(const unsigned char* instr, int32 instrlen,const unsigned char* key,unsigned char*  outstr, int32* outstrlen_ptr,byte* versionbuf,const CString& path)
{
	byte bufsize2[4];
	instrlen-=7;
	if (instrlen > 28)
	{
		memcpy(bufsize2, instr, 4);
		for (int i = 0; i < 4; i++)
			bufsize2[i] += 30;

		int headstrlen = *(int*)bufsize2;
		byte headbuf[1024 * 2];
		byte headoutbuf[1024 * 2];
		int headoutlen = 0;
		if (headstrlen>0 && headstrlen < instrlen - 4)
		{
			memcpy(headbuf, instr + 4, headstrlen);
			if (Crypt::decrypt(headbuf, headstrlen, key, headoutbuf, &headoutlen))
			{
				headoutbuf[headoutlen] = 0;
				//获取用户的密钥
	CStringvect setenvevent;
				vector<byte> user_gamekey;
				BOOL needdllflag = false;
				CString newkey = _T("sfjsdfsfkfk");//_T("fskfs");
				CStringvect vectemp;
				CString headoutWstr = ::function::CStrA2CStrW((char*)headoutbuf);
				::function::getmytoken(headoutWstr, _T("\r\n"), vectemp);
				if (vectemp.size() > 2)
				{
					//如果有本地的自定义加密自定义加密游戏文本密钥.txt
					CString keyfilepath = SaveAs_complete_path(_T("自定义加密游戏文本密钥.txt"));
				
					GetStrvectFromReadGameFile(keyfilepath, setenvevent);
					

					CString tempkeystr;
					CString paramcombuf;
					if (StrStrI(vectemp[1], _T("addqq")))
						paramcombuf.Format(_T("%s&cfrobotselfnum=%lld"), vectemp[2], g_interfaceuin);
					else
						paramcombuf.Format(_T("%s"), vectemp[2]);

					if (GetDllresultText(vectemp[0], vectemp[1], paramcombuf, true, tempkeystr)&&!tempkeystr.IsEmpty())
						newkey = tempkeystr;
					else
					{
						needdllflag = true;
						

						if (setenvevent.size() >= 4)
						{
							newkey = setenvevent[3];

						}
					}

				}


				int gamelen = 0;
				memcpy(bufsize2, instr + 4 + headstrlen, 4);
				gamelen = *(int*)bufsize2;

				GetUserDefKey(newkey, user_gamekey);
				if (postfileunpack(instr + 8 + headstrlen, gamelen + 7, &user_gamekey[0], outstr, outstrlen_ptr, versionbuf))//Crypt::decrypt(instr+8+headstrlen, gamelen+7, &user_gamekey[0], outstr, outstrlen_ptr))
				{
					return true;
				}
				else
				{
					newkey = _T("sfjsdfsfkfk");
					GetUserDefKey(newkey, user_gamekey);
					if (postfileunpack(instr + 8 + headstrlen, gamelen + 7, &user_gamekey[0], outstr, outstrlen_ptr, versionbuf))//Crypt::decrypt(instr+8+headstrlen, gamelen+7, &user_gamekey[0], outstr, outstrlen_ptr))
					{
						return true;
					}
					else
					{

						//static int onceflag = false;
						//if (!onceflag)
						{
							//onceflag = true;
							if (needdllflag)
							{
								if (vectemp.size() > 4)
								{
									CString strrr;
									strrr = _T("缺少解密插件") + path;
									MessageBox(mainhwnd, vectemp[4], strrr, 0);
								}
							}
							else
							{

								CString paramstr;
								CString outstr;
								GeturlencodeUtfCString(path, outstr);
								paramstr.Format(_T("pathstr=%s&cfrobotselfnum=%lld"), outstr, g_interfaceuin);
								BOOL errorfunfalg = false;
								if (vectemp.size() > 2)
								{
									errorfunfalg=GetDllresultText(vectemp[0], _T("decodeerr"), paramstr, false, paramstr);
								}
								if (!errorfunfalg)
								if (vectemp.size() > 4)
								{
									CString strrr;
									strrr = _T("解密失败") + path;
									MessageBox(mainhwnd, vectemp[4], strrr, 0);
								}
							}
						}
					}
					
				}
			}

		}

		return postfileunpack(instr, instrlen + 7, key, outstr, outstrlen_ptr, versionbuf);

	}
	else
		return false;
}
BOOL postfiledopack(const unsigned char* instr, int32 instrlen, const unsigned char* key,unsigned char* outstr, int32* outstrlen_ptr)
{

	byte bufsize1[16];
	byte bufsize2[4];
	//写入16个字节版本号，写入文件长度
	CString newg_Verdatestr=g_Verdatestr;
	BOOL bSimpleEncodeFlag=false;//39915000
	newg_Verdatestr.Replace(_T("."),_T(""));
	CString herestr;
		herestr=(LPCTSTR)instr;
		CStringvect vectemp;
		::function::getmytoken(herestr,_T("\n"),vectemp);

		if(vectemp.size()>1000)
bSimpleEncodeFlag=true;

		if(bSimpleEncodeFlag)
	newg_Verdatestr.Append(_T("001"));
		else
	newg_Verdatestr.Append(_T("000"));

	//39915000

	memcpy(bufsize1,newg_Verdatestr,16);

	TCHAR tempversionbuf[9];
	memcpy(tempversionbuf,bufsize1,16);
	tempversionbuf[8]=0;
		for(int i=0;i<16;i++)
		bufsize1[i]-=50;

		
	memcpy(outstr,bufsize1,16);
	
	vector<byte> tempkey;
	//获取新的key
	
		GetNewBuffer(tempkey,key,bufsize1,(byte*)&g_interfaceuin);
	
	

	
		CString tempversionstr=tempversionbuf;
int versionnum=_ttoi(tempversionstr);

		//3.9.9.0.0以后的版本都是双重加密
		
int useversionnum=versionnum*13/7;

		if(bSimpleEncodeFlag)
		{
				CString newinstr;
				int mysize=herestr.GetLength();
			int filesize=0;
int readfilesize=herestr.GetLength()*2;
readfilesize=min(5*1024*1024,readfilesize);
byte* bytebuf=new byte[herestr.GetLength()*4+48+1024];

vector<byte> user_gamekey;

		CString	newkey;
		newkey.Format(_T("%d"),useversionnum);
GetUserDefKey(newkey,user_gamekey);

Crypt::encrypt((byte*)herestr.GetBuffer(0), readfilesize, &user_gamekey[0], bytebuf, &filesize);  


Crypt::encrypt(bytebuf, filesize, &tempkey[0], outstr+20, outstrlen_ptr); 

delete []bytebuf;

		}
		else
		{

		CString newinstr;
int maxcplen=1024*40;
TCHAR *templinestr=new TCHAR[maxcplen];


		for(int i=0;i<vectemp.size();i++)
		{
						
//lstrcpy(templinestr,vectemp[i]);
		int actcplen=min(maxcplen-1,vectemp[i].GetLength());
		_tcsncpy(templinestr,vectemp[i],actcplen);
		templinestr[actcplen]=0;
	xmlgetcodeutf(templinestr,true,useversionnum+i*19);
	newinstr+=templinestr;
	newinstr+=_T("\r\n");

		}
		delete []templinestr;
byte *newbyteinstr=(byte*)newinstr.GetBuffer(0);
instrlen=newinstr.GetLength()*2;

	    Crypt::encrypt(newbyteinstr, instrlen, &tempkey[0], outstr+20, outstrlen_ptr);  
		}

	memcpy(bufsize2,outstrlen_ptr,4);
	for(int i=0;i<4;i++)
		bufsize2[i]-=60;
	memcpy(outstr+16,bufsize2,4);

	memcpy(outstr+20+*outstrlen_ptr,&g_interfaceuin,8);

	*outstrlen_ptr=*outstrlen_ptr+28;
		return 1;
}

BOOL filedopack(const unsigned char* instr, int32 instrlen,LPCTSTR additionalcodebuf,LPCTSTR newkey,const unsigned char* key,unsigned char* outstr, int32* outstrlen_ptr)
{
	if(!additionalcodebuf||lstrlen(additionalcodebuf)==0)
postfiledopack(instr,instrlen,key,outstr,outstrlen_ptr);
	else
	{
		CStringA addheadbuf=::function::CStrW2CStrA(additionalcodebuf);
		int headlen=addheadbuf.GetLength();
		byte headoutbuf[1024*2];
		int headoutlen=0;
	Crypt::encrypt((byte*)addheadbuf.GetBuffer(), headlen, key, headoutbuf, &headoutlen);  
	int offset=40;

	byte bufsize2[4];
	memcpy(bufsize2,&headoutlen,4);
	
	offset-=10;
	for(int i=0;i<4;i++)
		bufsize2[i]-=offset;//每个减30

	memcpy(outstr,bufsize2,4);

memcpy(outstr+4,headoutbuf,headoutlen);




vector<byte> user_gamekey;
GetUserDefKey(newkey,user_gamekey);
postfiledopack(instr,instrlen,&user_gamekey[0],outstr+8+headoutlen, outstrlen_ptr);

memcpy(outstr+4+headoutlen,outstrlen_ptr,4);

*outstrlen_ptr=*outstrlen_ptr+8+headoutlen;
	}
		return 1;
}

void LoadOutputReplacemap(LPCTSTR path,	CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>& inoutreplacemap,int type/*=0*/,LPCTSTR keystr/*=NULL*/,LPCTSTR valuestr/*=NULL*/)//type==0,读取，type==1，添加keystr，type==2，删除keystr
{
	CReadAUStdioFile helpfile;
	UINT openflag=CFile::modeRead|CFile::shareDenyNone;
	if(type)
openflag=CFile::modeReadWrite|CFile::shareDenyNone;

	BOOL bEncoded=false;
DWORD filesize=0;



	
	filesize=::function::GetFileSizeFromPath(path);
			

			if(StrStrI(path,_T(".encode.")))
				bEncoded=true;



	if(!helpfile.Open(path,openflag))
	{
		return;
	}
	if(type==0)
	{
	
	
			CString tempstr,qqstr,qqpasswordstr;
		int itemcount;
		CString frontstr,backstr;
	if(bEncoded)
	{
	
					byte *readbuf=new byte[filesize];
			DWORD readfilesize=helpfile.Read(readbuf,filesize);

			int returnsize=0;
			byte *temp6=new byte[readfilesize+48+2];
byte versionbuf[17]="";
			
if(readfilesize)
if(fileunpack(readbuf,readfilesize,&g_gamekey[0],temp6,&returnsize,versionbuf,path))//Crypt::tencentt(2,readbuf,readfilesize,&g_gamekey[0],temp6,&returnsize))
{
temp6[returnsize]=0;
temp6[returnsize+1]=0;

CString wholefilesentence=(LPCTSTR)temp6;

BOOL bSimpleEncodeFlag=false;//39915000
	TCHAR tempversionbuf[9];
	memcpy(tempversionbuf,versionbuf,16);
	tempversionbuf[8]=0;
			CString tempversionstr=tempversionbuf;
		tempversionstr.Replace(_T("."),_T(""));
int versionnum=_ttoi(tempversionstr);

int useversionnum=versionnum*13/7;
BOOL bNewestDopackflag=false;

if(versionnum>=11019000&&::function::bittest(versionnum,1))
	bSimpleEncodeFlag=true;

if(bSimpleEncodeFlag)
{
byte *waitdecodebuf=new byte[returnsize+48+2048];

	vector<byte> user_gamekey;

		CString	newkey;
		newkey.Format(_T("%d"),useversionnum);
GetUserDefKey(newkey,user_gamekey);

int secondsize=0;
Crypt::decrypt((byte*)temp6, returnsize, &user_gamekey[0], waitdecodebuf, &secondsize);  

waitdecodebuf[secondsize]=0;
waitdecodebuf[secondsize+1]=0;

wholefilesentence=(LPCTSTR)waitdecodebuf;


	delete []waitdecodebuf;
}



CStringvect vectemp;
CString tempstr,frontstr,backstr;
		setvector<CString>* temppushvect;
::function::getmytoken(wholefilesentence,_T("\r\n"),vectemp);
g_autoappendtext=_T("");
g_autoinserttext=_T("");



if(versionnum>=3990)
	bNewestDopackflag=true;

if(bSimpleEncodeFlag)
	bNewestDopackflag=false;



int maxcplen=1024*40;
TCHAR *templinestr=new TCHAR[maxcplen];

for(int i=0;i<vectemp.size();i++)
{
	CString tempvectempstr;

	tempvectempstr=vectemp[i];
	if(bNewestDopackflag)
	{
	//lstrcpy(templinestr,tempvectempstr);
		int actcplen=min(maxcplen-1,tempvectempstr.GetLength());
		_tcsncpy(templinestr,tempvectempstr,actcplen);
		templinestr[actcplen]=0;
	if(versionnum>=3991)
		xmlgetcodeutf(templinestr,false,useversionnum+i*19);
	else
	xmlgetcode(templinestr,false,useversionnum+i*19);


	tempvectempstr=templinestr;
	}

tempvectempstr.Trim();

		GetPairStrFromReadFile(tempvectempstr,frontstr,backstr);
		
		backstr.Replace(RNDEFBUF,_T("\r\n"));
		backstr.Replace(_T("【输出替换】"),_T(""));
		
//frontstr.Replace(RNDEFBUF,_T("\r\n"));

if(frontstr==_T("xxx"))
{
	frontstr=_T("XXX");

	
}
		if(!frontstr.IsEmpty()&&frontstr!=_T("$")&&frontstr!=_T("%"))
		{
		inoutreplacemap[frontstr].push_back(backstr);
		}
}

delete []templinestr;
}

	
	}
	else
	{
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(helpfile.ReadString(tempstr))
	{
	tempstr.Trim();
		GetPairStrFromReadFile(tempstr,frontstr,backstr);

		

		backstr.Replace(RNDEFBUF,_T("\r\n"));
		//TrimRight(backstr,_T("【输出替换】"));
		backstr.Replace(_T("【输出替换】"),_T(""));
//frontstr.Replace(RNDEFBUF,_T("\r\n"));

if(frontstr==_T("xxx"))
{
	frontstr=_T("XXX");

	
}
		if(!frontstr.IsEmpty()&&frontstr!=_T("$")&&frontstr!=_T("%"))
		{
		inoutreplacemap[frontstr].push_back(backstr);
		}
	}	
	}


inoutreplacemap.sortLen();

	}
	else if(type==1)
	{
		inoutreplacemap[keystr].push_back(valuestr);
	(helpfile).SetLength(0); 
		CString strfmt;
		int ncount=(inoutreplacemap).m_mapstr.size();
		setvector<CString> answervect;
		CString tempkeystr;
				for(int i=ncount-1;i>=0;i--)
				{
	tempkeystr=(inoutreplacemap).m_mapstr[(UINT)i];
	answervect=(inoutreplacemap)[i];
	for(auto it=answervect.begin();it!=answervect.end();it++)
	{
		strfmt.Format(_T("%s\t\t%s"),tempkeystr,*it);

		(helpfile).WriteLineStr(strfmt);
	
	}
					}
		

	}
	else if(type==2)
	{
setvector<CString> answervect;
	inoutreplacemap.Lookup(keystr,answervect);
	answervect.erase(::find(answervect.begin(),answervect.end(),valuestr));
	if(answervect.size()==0)
	{
	(inoutreplacemap).RemoveKey(keystr);
	}
	else
	(inoutreplacemap)[keystr]=answervect;

	(helpfile).SetLength(0); 
		CString strfmt;
		int ncount=(inoutreplacemap).m_mapstr.size();
		CString keystr;
				for(int i=ncount-1;i>=0;i--)
				{
	keystr=(inoutreplacemap).m_mapstr[(UINT)i];
	answervect=(inoutreplacemap)[i];
	for(auto it=answervect.begin();it!=answervect.end();it++)
	{
		strfmt.Format(_T("%s\t\t%s"),keystr,*it);

		(helpfile).WriteLineStr(strfmt);
	
	}
					}
	}

	helpfile.Close();

}
void FinalGetStrvectFromReadGameFile(LPCTSTR filepath,CStringvect &setencevect,CString* rtwholesentce,BOOL* pbHugeFile)
{
	BOOL bEncoded=false;
	DWORD filesize=::function::GetFileSizeFromPath(filepath);


	if(filesize==0)
		return;

			if(filesize>2*1024*1024)
			{
				if(pbHugeFile)
				*pbHugeFile=true;
			}
			if(filesize>50*1024*1024)
				return;

		if(StrStrI(filepath,_T(".encode.")))
				bEncoded=true;

	
		
			CReadAUStdioFile gamefile1;
			if(gamefile1.Open(filepath,CFile::modeRead|CFile::shareDenyNone))
			{


				if(gamefile1.bHugeFileflag)
					if(pbHugeFile)
						*pbHugeFile=true;
				if(bEncoded)
				{
					byte *readbuf=new byte[filesize];
					DWORD readfilesize=gamefile1.Read(readbuf,filesize);

					int returnsize=0;
					byte *temp6=new byte[readfilesize+48+2];

					if(0)
					{
						Crypt::tencentt(2,readbuf,readfilesize-7,&g_gamekey[0],temp6,&returnsize);

					}
					byte versionbuf[17]="";
					if(readfilesize&&!nosense)
						if(fileunpack(readbuf,readfilesize,&g_gamekey[0],temp6,&returnsize,versionbuf,filepath))//Crypt::tencentt(2,readbuf,readfilesize,&g_gamekey[0],temp6,&returnsize))
						{
						temp6[returnsize]=0;
						temp6[returnsize+1]=0;

						CString wholefilesentence=(LPCTSTR)temp6;
						//if(0)
						//MessageBox(0,wholefilesentence,0,0);


						setencevect.clear();
						TCHAR tempversionbuf[9];
						memcpy(tempversionbuf,versionbuf,16);
						tempversionbuf[8]=0;
						CString tempversionstr=tempversionbuf;
						tempversionstr.Replace(_T("."),_T(""));
						int versionnum=_ttoi(tempversionstr);

						int useversionnum=versionnum*13/7;

						BOOL bNewestDopackflag=false;
						BOOL bSimpleEncodeFlag=false;
						if(versionnum>=11019000&&::function::bittest(versionnum,1))
							bSimpleEncodeFlag=true;

						if(bSimpleEncodeFlag)
						{
							byte *waitdecodebuf=new byte[returnsize+48+2048];

							vector<byte> user_gamekey;

							CString	newkey;
							newkey.Format(_T("%d"),useversionnum);
							GetUserDefKey(newkey,user_gamekey);

							int secondsize=0;
							Crypt::decrypt((byte*)temp6,returnsize,&user_gamekey[0],waitdecodebuf,&secondsize);

							waitdecodebuf[secondsize]=0;
							waitdecodebuf[secondsize+1]=0;

							wholefilesentence=(LPCTSTR)waitdecodebuf;


							delete[]waitdecodebuf;
						}

						CStringvect vectemp;
						::function::getmytoken(wholefilesentence,_T("\r\n"),vectemp);
						if(rtwholesentce)
							*rtwholesentce=wholefilesentence;


						if(versionnum>=3990)
							bNewestDopackflag=true;

						if(bSimpleEncodeFlag)
							bNewestDopackflag=false;


						if(bNewestDopackflag)
						{
						int maxcplen=1024*40;
TCHAR *templinestr=new TCHAR[maxcplen];
							if(rtwholesentce)
								*rtwholesentce=_T("");
							for(int i=0;i<vectemp.size();i++)
							{
								CString tempvectempstr;

								tempvectempstr=vectemp[i];
								if(bNewestDopackflag)
								{
									//lstrcpy(templinestr,tempvectempstr);
										int actcplen=min(maxcplen-1,tempvectempstr.GetLength());
		_tcsncpy(templinestr,tempvectempstr,actcplen);
		templinestr[actcplen]=0;
									if(versionnum>=3991)
										xmlgetcodeutf(templinestr,false,useversionnum+i*19);
									else
										xmlgetcode(templinestr,false,useversionnum+i*19);
									tempvectempstr=templinestr;
								}

								tempvectempstr.Trim();
								if(rtwholesentce)
								{
									*rtwholesentce+=tempvectempstr;
									*rtwholesentce+=_T("\r\n");
								}
								setencevect.push_back(tempvectempstr);


							}
							delete[]templinestr;
						}
						else
							setencevect=vectemp;

						delete[]readbuf;
						delete[]temp6;
						}
				}
				else
				{
					CString tempstr;
					while(gamefile1.ReadString(tempstr))
					{

						setencevect.push_back(tempstr);
						if(rtwholesentce)
								{
									*rtwholesentce+=tempstr;
									*rtwholesentce+=_T("\r\n");
								}
					}
				}

				gamefile1.Close();

			}
}

void GetStrvectFromReadGameFile(LPCTSTR filepath,CStringvect &setencevect,BOOL* pbHugeFile)
{
	CString rtwholesentence;

	FinalGetStrvectFromReadGameFile(filepath,setencevect,&rtwholesentence,pbHugeFile);
	
	if(setencevect.size()>0)
	{
		int pos=setencevect[0].Find(_T("【加载回调插件】"));
		if(pos!=-1)
		{
			CString urlstr=setencevect[0].Mid(pos+lstrlen(_T("【加载回调插件】")));
			CString paramstr;

				paramstr.Format(_T("&cfrobotselfnum=%lld&version=%s"), g_interfaceuin,g_purenumberversion);
				if(StrStrI(urlstr,_T("filepathonly=1")))
				{
					rtwholesentence=filepath;
				}
			

			if(StrStrI(urlstr,_T(".dll")))
			{
				if(rtwholesentence.Find('&')!=-1)
				rtwholesentence.Replace('&',L'＆');

				urlstr+=rtwholesentence;
urlstr+=paramstr;
			}
			else
			{
					CString outstr;
				GeturlencodeUtf2MCString(rtwholesentence, outstr);
		urlstr+=outstr;
urlstr+=paramstr;
			}

			CString backstr;
			if(ReadInternetTxtFile(urlstr,backstr))
			{
				if(!backstr.IsEmpty())
				{
					if(backstr.GetLength()<512&&PathFileExists(backstr))
					{
setencevect.clear();
	FinalGetStrvectFromReadGameFile(backstr,setencevect,&rtwholesentence,pbHugeFile);
					}
					else
					{
						setencevect.clear();

						CStringvect vectemp;
						::function::getmytoken(backstr,_T("\r\n"),vectemp);

						for(int i=0;i<vectemp.size();i++)
						{
							setencevect.push_back(vectemp[i]);

						}
					}
				}
			}

		}
	}
	//【加载回调插件】http://127.0.0.1/a.dll?function=loadandreplacefun&cmdstr=%s&configfile=hideaaa.txt

	
}
	void LoadIncludeShareRPFile(LPCTSTR sharerpoutfilename,LPCTSTR gamefilefn)
	{
	CString wholesharepath=sharerpoutfilename;
if(!PathFileExists(wholesharepath))
{
		CString pathf;
		
		pathf=::function::Getpathfromname(gamefilefn);
		wholesharepath=pathf+sharerpoutfilename;
}
		CStringvect rpvect;
		GetStrvectFromReadGameFile(wholesharepath,rpvect);
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
		for(int i=0;i<rpvect.size();i++)
		{
		CString frontstr,backstr;
		GetPairStrFromReadFile(rpvect[i],frontstr,backstr);
		backstr.Replace(_T("【输出替换】"),_T(""));
	backstr.Replace(RNDEFBUF,_T("\r\n"));
	if(!frontstr.IsEmpty())
	{
			CString tabstr;
			tabstr.Format(_T("%s\t%s"),frontstr,backstr);
			g_filepath2outreplacemap[gamefilefn].push_back(tabstr);
	}
		}

	}
void LoadSingleGameFile(LPCTSTR gamefilefn1,CKeepStrStrPVectMap& temp_gamePrivilegeautoreplymap,CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>& temp_inputreplacemap,CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>& temp_outputreplacemap)
{



BOOL bHugeFile=false;
		
	CString appendnewfilename;
	CString finalappendfilename;
	CString appendfrontstr,appendbackstr;
CString ddd=::function::Getpathfromname(gamefilefn1,&appendnewfilename);
if(g_bAutoAppendFileName)
{
	if(StrStrI(gamefilefn1,g_moreselfgamedir))
	{
	finalappendfilename.Format(_T("——当前游戏句子来自于“更多小游戏文件可放这里%s”"),gamefilefn1+g_moreselfgamedir.GetLength());
	}
	else
	finalappendfilename.Format(_T("——当前游戏句子来自于“%s”"),appendnewfilename);
}
	//::function::GetHalfStr(newfilename,&appendfrontstr,&appendbackstr,'.');

CStringvect vectemp;
	GetStrvectFromReadGameFile(gamefilefn1,vectemp,&bHugeFile);
	CString frontstr,backstr;
	g_autoappendtext=_T("");
g_autoinserttext=_T("");
for(int i=0;i<vectemp.size();i++)
{
	//多个游戏共用的输出替换.txt【共用的输出替换文件】
	int pospublic=vectemp[i].Find(_T("【共用的输出替换文件】"));
	if(pospublic!=-1)
	{
	CString sharerpoutfilename;
	sharerpoutfilename=vectemp[i].Left(pospublic);
	sharerpoutfilename.Trim();
	LoadIncludeShareRPFile(sharerpoutfilename,gamefilefn1);

continue;
	}

GetPairStrFromReadFile(vectemp[i],frontstr,backstr);
	

		

if(!frontstr.IsEmpty()&&!backstr.IsEmpty())
{
	if(backstr.Find(_T("【输出替换】"))!=-1)
	{
		backstr.Replace(_T("【输出替换】"),_T(""));

	if(backstr.Find(_T("【图片缓存标识】"))!=-1)
	{

		backstr.Replace(_T("【图片缓存标识】"),_T(""));
	

	
		g_extraimgsignbuffermap[frontstr]=backstr;

	}

	backstr.Replace(RNDEFBUF,_T("\r\n"));
//frontstr.Replace(RNDEFBUF,_T("\r\n"));


		if(!frontstr.IsEmpty()&&frontstr!=_T("$")&&frontstr!=_T("%"))
		{
			if(g_bAutoAppendFileName)
	backstr.Append(finalappendfilename);


			CString tabstr;
			tabstr.Format(_T("%s\t%s"),frontstr,backstr);
			g_filepath2outreplacemap[gamefilefn1].push_back(tabstr);


		//temp_outputreplacemap[frontstr].push_back(backstr);//2015.11.19不再合并到总的输出替换中了
		}

	}
	else if(backstr.Find(_T("【输入替换】"))!=-1)
	{
		backstr.Replace(_T("【输入替换】"),_T(""));
		if(g_bAutoAppendFileName)
	backstr.Append(finalappendfilename);
	temp_inputreplacemap[frontstr].push_back(backstr);

	CString norepeatbackstr=backstr;
		RemoveRepeatWord(norepeatbackstr);
				g_gameinputfilepathmap[frontstr+norepeatbackstr]=gamefilefn1;


	}
	else if(backstr.Find(_T("【图片缓存标识】"))!=-1)
	{

		backstr.Replace(_T("【图片缓存标识】"),_T(""));
	

	
		g_extraimgsignbuffermap[frontstr]=backstr;

	}
	else
	{
		setvector<CString>* temppushvect;
	if(!temp_gamePrivilegeautoreplymap.Lookup(frontstr,temppushvect))
				{
					temppushvect=new setvector<CString>;
			temp_gamePrivilegeautoreplymap[frontstr]=temppushvect;
			}


	if(g_bAutoAppendFileName)
	backstr.Append(finalappendfilename);
			if(bHugeFile)
			(*temppushvect).insert((*temppushvect).end(),backstr);
			else
		    (*temppushvect).push_back(backstr);

			CString norepeatbackstr=backstr;
		RemoveRepeatWord(norepeatbackstr);
		g_gamesetencefilepathmap[frontstr+norepeatbackstr]=gamefilefn1;

	}
}

}



			temp_gamePrivilegeautoreplymap.sortLen();
}
int GetTxtContentFromWeb(CString& rtcontent,LPCTSTR weburl,byte* bytebuf)
{
	int Encodefilesize=0;

	UINT ddlen=0;
	UINT orgddlen=0;
	//MessageBox(0,weburl,0,0);
		if(::function::DownloadHttpFile(weburl,bytebuf,ddlen)==0)
		{
			//MessageBox(0,_T("download成功！"),0,0);
		orgddlen=ddlen;
		if(StrStrI(weburl,_T(".encode.")))
		{
			ddlen+=8;
			int returnsize=0;
			ddlen--;
			byte *temp6=new byte[ddlen+48+2];

if(ddlen)
{
	byte versionbuf[17]="";
	CString path = weburl;
if(fileunpack(bytebuf,ddlen,&g_gamekey[0],temp6,&Encodefilesize,versionbuf,path))//Crypt::tencentt(2,bytebuf,ddlen,&g_gamekey[0],temp6,&Encodefilesize))
{
temp6[Encodefilesize]=0;
temp6[Encodefilesize+1]=0;
CString wholefilesentence=(LPCTSTR)temp6;
TCHAR tempversionbuf[9];
	memcpy(tempversionbuf,versionbuf,16);
	tempversionbuf[8]=0;
			CString tempversionstr=tempversionbuf;
		tempversionstr.Replace(_T("."),_T(""));
int versionnum=_ttoi(tempversionstr);

int useversionnum=versionnum*13/7;
BOOL bNewestDopackflag=false;
BOOL bSimpleEncodeFlag=false;
if(versionnum>=11019000&&::function::bittest(versionnum,1))
	bSimpleEncodeFlag=true;

if(bSimpleEncodeFlag)
{
	byte *waitdecodebuf=new byte[returnsize+48+2048];

	vector<byte> user_gamekey;

		CString	newkey;
		newkey.Format(_T("%d"),useversionnum);
GetUserDefKey(newkey,user_gamekey);

int secondsize=0;
Crypt::decrypt((byte*)temp6, returnsize, &user_gamekey[0], waitdecodebuf, &secondsize);  

waitdecodebuf[secondsize]=0;
waitdecodebuf[secondsize+1]=0;

wholefilesentence=(LPCTSTR)waitdecodebuf;


	delete []waitdecodebuf;
}

if(versionnum>=3990)
	bNewestDopackflag=true;
if(bSimpleEncodeFlag)
	bNewestDopackflag=false;

if(bNewestDopackflag)
{
	CStringvect vectemp;

	::function::getmytoken(wholefilesentence,_T("\r\n"),vectemp);

int maxcplen=1024*40;
TCHAR *templinestr=new TCHAR[maxcplen];
	rtcontent=_T("");
	for(int i=0;i<vectemp.size();i++)
	{
		CString tempvectempstr;

		tempvectempstr=vectemp[i];
		if(bNewestDopackflag)
		{
			//lstrcpy(templinestr,tempvectempstr);
				int actcplen=min(maxcplen-1,tempvectempstr.GetLength());
		_tcsncpy(templinestr,tempvectempstr,actcplen);
		templinestr[actcplen]=0;
			if(versionnum>=3991)
				xmlgetcodeutf(templinestr,false,useversionnum+i*19);
			else
				xmlgetcode(templinestr,false,useversionnum+i*19);
			tempvectempstr=templinestr;
		}

		tempvectempstr.Trim();
		rtcontent+=tempvectempstr;
		rtcontent+=_T("\r\n");


	}
	delete[]templinestr;

}
else
rtcontent=(LPCTSTR)wholefilesentence;


Encodefilesize=orgddlen;
}
Encodefilesize=orgddlen;
}
		}		
		else if(StrStrI(weburl,_T(".dll")))//如果是.dll插件的话
		{
			//char buf[33];
			//strncpy(buf,(char*)bytebuf,32);
			//buf[32]=0;
			//	MessageBoxA(0,buf,0,0);
		Encodefilesize=ddlen;
		}
		else
		{
			CString wstr;
::function::utf8_wchar((char*)bytebuf,wstr);
				TCHAR rplchr=0xfeff;
		wstr.Trim(rplchr);
	wstr.Trim();		
rtcontent=wstr;

		}
	}
		return Encodefilesize;
}
int GetSynGameFile(CString& txtcontent,LPCTSTR gamewebstrurl,byte *bytebuf)
{

			int filesize=0;
	//=new byte[1024*1024*10];

			int bFindAnyEncode=false;
	CString finalwebpath=gamewebstrurl;


	bFindAnyEncode=GetTxtContentFromWeb(txtcontent,gamewebstrurl,bytebuf);
	
	BOOL bDllFile=false;
	if(bFindAnyEncode>2&&strncmp((char*)bytebuf,"MZ",2)==0)
		bDllFile=true;

	if((!bDllFile&&txtcontent.Find(_T("http://"))!=-1)&&(txtcontent.Find(_T(".dll"))!=-1||txtcontent.Find(_T(".txt"))!=-1||txtcontent.Find(_T("encode.log"))!=-1))
	{
		CStringvect vectemp;
		::function::getmytoken(txtcontent,_T("\r\n"),vectemp);
		txtcontent=_T("");
		CString realurlstr,singledefgamename;
		for(int i=0;i<vectemp.size();i++)
		{
			if(vectemp[i].Find(_T("http://"))==0&&(vectemp[i].Find(_T(".dll"))!=-1||vectemp[i].Find(_T(".txt"))!=-1||vectemp[i].Find(_T("encode.log"))!=-1))
			{
				CString firsturl;
						//vectemp[i]
				vectemp[i].Replace('\t',' ');
				realurlstr=vectemp[i];
				singledefgamename=_T("");
				::function::GetHalfStr(vectemp[i],&realurlstr,&singledefgamename,' ');
			
				int bEncodeflag=GetTxtContentFromWeb(firsturl,realurlstr,bytebuf);
				if(!singledefgamename.IsEmpty())
SaveSingleGameFile(bEncodeflag,singledefgamename,bytebuf,firsturl);
				else
				{
					if(bEncodeflag)
					{
				
					bFindAnyEncode=true;
					}
			txtcontent+=firsturl;
				}
			}
			else
			txtcontent+=vectemp[i];

		txtcontent+=_T("\r\n");
		}
	}
	txtcontent.Trim();
		if(txtcontent.IsEmpty())
		{
		filesize=bFindAnyEncode;
		}

	if(bFindAnyEncode)
	{
	
	
		if(!txtcontent.IsEmpty())
		{
	
int readfilesize=txtcontent.GetLength()*2;
readfilesize=min(5*1024*1024,readfilesize);
if(filedopack((byte*)txtcontent.GetBuffer(0),readfilesize,NULL,NULL,&g_gamekey[0],bytebuf,&filesize))//Crypt::tencentt(1,(byte*)txtcontent.GetBuffer(0),readfilesize,&g_gamekey[0],bytebuf,&filesize))
{	
	
}
		}
		
		txtcontent=_T("");
	}
	
	
	return filesize;
}
void LoadVarousOutputReplaceValueFromFile(LPCTSTR filepath)
{

			CReadAUStdioFile gamefile1;
			CString finalappendfilename;
				finalappendfilename.Format(_T("——当前运算变量来自于“%s”"),filepath);
	if(gamefile1.Open(filepath,CFile::modeRead|CFile::shareDenyNone))
	{

		CString tempstr,frontstr,backstr;
		setvector<CString>* temppushvect;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
		while(gamefile1.ReadString(tempstr))
	{
		if(tempstr.Find(_T("【输出替换】"))!=-1)
			tempstr.Replace(_T("【输出替换】"),_T(""));
		
		GetPairStrFromReadFile(tempstr,frontstr,backstr);
		if(frontstr.IsEmpty()||backstr.IsEmpty())
			continue;
	if(frontstr.Find(_T("【"))!=0||frontstr.Find(_T("】"))!=frontstr.GetLength()-1)
		continue;

	g_privilegeoutputreplacemap[frontstr]=backstr;
		}
gamefile1.Close();
	}
}

void LoadVarousValueFromFile(LPCTSTR filepath,CKeepStrStrVectMap& temp_variousvalueMap,CStringvect& temp_variousvalueVector)
{

			CReadAUStdioFile gamefile1;
			CString finalappendfilename;
				finalappendfilename.Format(_T("——当前运算变量来自于“%s”"),filepath);
	if(gamefile1.Open(filepath,CFile::modeRead|CFile::shareDenyNone))
	{

		CString tempstr,frontstr,backstr;
		setvector<CString>* temppushvect;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
		while(gamefile1.ReadString(tempstr))
	{
		if(tempstr.Find(_T("【强制运算】"))!=-1)
			tempstr.Replace(_T("【强制运算】"),_T(""));
		if(tempstr.Find(_T("【输出替换】"))!=-1)
			tempstr.Replace(_T("【输出替换】"),_T(""));
		//if(tempstr.Find(_T("【运算结果取整数】"))!=-1)
			//tempstr.Replace(_T("【运算结果取整数】"),_T(""));

		GetPairStrFromReadFile(tempstr,frontstr,backstr);
		if(frontstr.IsEmpty()||backstr.IsEmpty())
			continue;
	if(frontstr.Find(_T("【"))!=0||frontstr.Find(_T("】"))!=frontstr.GetLength()-1)
		continue;
tempstr.Append(finalappendfilename);
	temp_variousvalueVector.push_back(tempstr);
	frontstr.Append(finalappendfilename);
	temp_variousvalueMap[frontstr].push_back(backstr);

		}
gamefile1.Close();
	}
}

void LoadDefDirGameFile(const CString& temp_moreselfgamedir,CString& temp_gameliststr,CKeepStrStrPVectMap& temp_gamePrivilegeautoreplymap,CKeepStrStrVectMap& temp_inputreplacemap,CKeepStrStrVectMap& temp_outputreplacemap,CKeepStrStrVectMap& temp_variousvalueMap,CStringvect& temp_variousvalueVector)
{
	CStringvect backvect;
		CStringvect specvect;
		specvect.push_back(_T(".txt"));
		specvect.push_back(_T(".log"));

		::function::GetEnumFileInfo(temp_moreselfgamedir,specvect,backvect);
		CString newfilename;
	CString frontstr,backstr;
	CString firstsubdirname;
	if(backvect.size())
	{
		temp_gameliststr=_T("");
		for(int i=0;i<backvect.size();i++)
		{
			
			
			if(&temp_gamePrivilegeautoreplymap==&g_gamePrivilegeautoreplymap)
			{
				firstsubdirname=backvect[i].Mid(lstrlen(temp_moreselfgamedir)+1);
				if(_ttoi64(firstsubdirname)>10000)
					continue;
			}
			if(backvect[i].Find(_T("输出替换."))!=-1)
			{
			continue;
			}
			
if(backvect[i].Find(_T("优先运算变量列表"))!=-1&&backvect[i].Find(_T(".txt"))!=-1)
			{
 LoadVarousValueFromFile(backvect[i],temp_variousvalueMap,temp_variousvalueVector);
			continue;
			}
if (backvect[i].Find(_T("抢答题")) != -1 && backvect[i].Find(_T(".txt")) != -1)
{
	
	continue;
}

if(&g_variousvalueMap==&temp_variousvalueMap)
{
			if(backvect[i].Find(_T("优先输出替换变量列表"))!=-1&&backvect[i].Find(_T(".txt"))!=-1)
			{
 LoadVarousOutputReplaceValueFromFile(backvect[i]);
			continue;
			}
}
			
				LoadSingleGameFile(backvect[i],temp_gamePrivilegeautoreplymap,temp_inputreplacemap,temp_outputreplacemap);

				
					CString ddd=::function::Getpathfromname(backvect[i],&newfilename);

				if(newfilename.Find(_T("hide"))==-1)
				{	::function::GetHalfStr(newfilename,&frontstr,&backstr,'.');
					frontstr.Replace(_T(".encode"),_T(""));
					temp_gameliststr+=frontstr;
					temp_gameliststr+=RNDEFBUF;
				}
			
		}
	}
	else
	{
	temp_gameliststr=_T("暂未有任何游戏文件");
	}

}
void DownloadWebGame()
{
static BOOL bDownloadonce=bFirsttime;

		if(bDownloadonce)
		{
			bDownloadonce=false;
		CString txtcontent;
		
		byte *bytebuf=NULL;
			bytebuf=new byte[1024*1024*5];
int bEncodefilesize=0;
		bEncodefilesize=GetSynGameFile(txtcontent,g_defgameweb,bytebuf);
		if(bEncodefilesize)
		{
		CFile filepwd;
		CString wholefilename=SpecialInsertMiddleStuffToFileName(g_defgamefn,_T(".encode."));

		if(filepwd.Open(wholefilename,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{
			filepwd.Write(bytebuf,bEncodefilesize);
			filepwd.Close();
		}

		}
		else
		{
	if(!txtcontent.IsEmpty())
	{
		CReadAUStdioFile filepwd(true);
		if(filepwd.Open(g_defgamefn,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{
			filepwd.WriteString(txtcontent);
			filepwd.Close();
		}
	}
		}
			if(bytebuf)
		delete []bytebuf;

			ReLoadGameFile();
	}

}
void ReLoadGameFile()
{

		
	for(UINT i=0;i<g_gamePrivilegeautoreplymap.GetCount();i++)
	{
	delete g_gamePrivilegeautoreplymap[i];
	}
	g_gamePrivilegeautoreplymap.RemoveAll();
	g_gamePrivilegeautoreplymap.InitHashTable(300000);
		g_privilegeoutputreplacemap.RemoveAll();
g_privilegeoutputreplacemap.InitHashTable(1000);
	g_variousvalueMap.RemoveAll();
	g_variousvalueVector.clear();
	g_extraimgsignbuffermap.RemoveAll();
	
	LoadSingleGameFile(g_selfgamefn,g_gamePrivilegeautoreplymap,g_inputreplacemap,g_outputreplacemap);

	LoadDefDirGameFile(g_moreselfgamedir,g_gameliststr,g_gamePrivilegeautoreplymap,g_inputreplacemap,g_outputreplacemap,g_variousvalueMap,g_variousvalueVector);

	lockweb2md5mapres.Lock();
	for(UINT i=0;i<g_extraimgsignbuffermap.m_mapstr.size();i++)
	{

	g_web2md5Map[g_extraimgsignbuffermap.m_mapstr[i]]=g_extraimgsignbuffermap[i];

	}
			lockweb2md5mapres.Unlock();

			g_inputreplacemap.sortLen();
			g_outputreplacemap.sortLen();

}
void LoadMoreSettingFile()
{
	g_morereplacemap.RemoveAll();
g_alwaysuploadvoice=false;
g_deletevoicefile=false;
g_newplaymusicmode=false;
g_totalforbidprivate=false;
g_transfertonoxmlwhenless=false;
g_notxmlwhenprivate=false;
g_allowuseawardgoods=false;
g_xmlmaxsize=0;
g_xmlstuff = _T("");
g_msgreplace = _T("");
//g_xmlminsize = 357;
g_autoreturnfalg=false;
g_autoswich2normalflag=false;
g_xmlformatstr=_T("");
g_xmliconstr=_T("");
g_xmlpreheadstr=_T("");
g_xmlfontcolorstr=_T("");
g_bforward2owner=false;	
g_bAutoAppendFileName=false;
g_reporturl=_T("");
g_ocrkey=_T("");
g_voiceoutall=_T("");
g_forcevoiceoutall=_T("");
g_modifycardurl=_T("");
g_thirdshutupurl = _T("");
g_thirdkickurl = _T("");
g_xmlkeeponelineflag=false;
g_bGetdirectimgurl=false;//获取群图片直接下载地址
g_bShowWholeSongAds=false;//显示完整的点歌网址
g_bNewUserGuestPlusTime=false;//新进群友名片前缀改成游客加时间
g_bForbidReJoin=false;//禁止重复加群
g_bwelcomealways=false;//重复进群每次都发欢迎词
g_bAutoQuitIfExpire=false;//超过有效期后自动退群
g_bAutoReportAds=_T("");//自动回报机器人在线状态的接口网址
g_DefaultValidDays=0;//拉机器人进群后默认有效期天数
g_bIgnoreAnyAgreeOrDeny=false;//不处理任何同意或拒绝加群的事务
g_bIgnoreDeny=false;//不处理拒绝加群的事务
g_bAllowCreateCookies=false;//允许机器人生成cookies文件
g_bMustDefShowWeb=false;//必须明确写了显示网址内容才显示网页内容
g_bAllowSamepinyin=false;//成语接龙支持同音字而不需要是同一个字
g_bautosavetalk=false;//自动保存httpapi所需要的输入和输出数据
g_bMust2receiver = _T("");
g_bMustappend2receiver = _T("");
g_exceptgroupvoicelist.clear();
g_exceptprivatevoicelist.clear();

g_App_key_str=_T("");//小i机器人app_key
g_App_secret_str=_T("");//小i机器人app_secret

CString	helppath=SaveAs_complete_path(_T("更多个性配置.txt"));

LoadOutputReplacemap(helppath,g_morereplacemap);

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("小i机器人app_key"))!=g_morereplacemap.m_mapstr.end())
g_App_key_str=g_morereplacemap[_T("小i机器人app_key")].front();	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("g_App_secret_str"))!=g_morereplacemap.m_mapstr.end())
g_App_secret_str=g_morereplacemap[_T("g_App_secret_str")].front();	


if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("允许机器人生成cookies文件"))!=g_morereplacemap.m_mapstr.end())
g_bAllowCreateCookies=true;	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("必须明确写了显示网址内容才显示网页内容"))!=g_morereplacemap.m_mapstr.end())
g_bMustDefShowWeb=true;	
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("成语接龙支持同音字而不需要是同一个字"))!=g_morereplacemap.m_mapstr.end())
g_bAllowSamepinyin=true;	
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("自动保存httpapi所需要的输入和输出数据"))!=g_morereplacemap.m_mapstr.end())
g_bautosavetalk=true;	
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("不处理拒绝加群的事务"))!=g_morereplacemap.m_mapstr.end())
g_bIgnoreDeny=true;	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("不处理任何同意或拒绝加群的事务"))!=g_morereplacemap.m_mapstr.end())
g_bIgnoreAnyAgreeOrDeny=true;	


if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("拉机器人进群后默认有效期天数"))!=g_morereplacemap.m_mapstr.end())
g_DefaultValidDays=_ttoi(g_morereplacemap[_T("拉机器人进群后默认有效期天数")].front());	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("获取群图片直接下载地址"))!=g_morereplacemap.m_mapstr.end())
g_bGetdirectimgurl=true;	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("显示完整的点歌网址"))!=g_morereplacemap.m_mapstr.end())
g_bShowWholeSongAds=true;	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("新进群友名片前缀改成游客加时间"))!=g_morereplacemap.m_mapstr.end())
g_bNewUserGuestPlusTime=true;	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("禁止重复加群"))!=g_morereplacemap.m_mapstr.end())
g_bForbidReJoin=true;	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("重复进群每次都发欢迎词"))!=g_morereplacemap.m_mapstr.end())
g_bwelcomealways=true;	

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("超过有效期后自动退群"))!=g_morereplacemap.m_mapstr.end())
g_bAutoQuitIfExpire=true;	

	

g_bAutoAppendFileName=find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("自动在游戏句子末尾附加上自定义游戏的文件名"))!=g_morereplacemap.m_mapstr.end();

		
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("语音识别的语种"))!=g_morereplacemap.m_mapstr.end())
g_voiceshowlanstr=g_morereplacemap[_T("语音识别的语种")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("彻底禁止机器人私聊回复"))!=g_morereplacemap.m_mapstr.end())
g_totalforbidprivate=true;

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("私聊时一律用普通消息格式"))!=g_morereplacemap.m_mapstr.end())
g_notxmlwhenprivate=true;

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("在字数很少时强制转为普通消息格式"))!=g_morereplacemap.m_mapstr.end())
g_transfertonoxmlwhenless=true;

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("允许奖励指令继续支持奖励物品"))!=g_morereplacemap.m_mapstr.end())
g_allowuseawardgoods=true;


if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("碰到关键词则转发消息给主人"))!=g_morereplacemap.m_mapstr.end())
g_bforward2owner=true;

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("语音文件不使用缓存标识始终上传到腾讯服务器"))!=g_morereplacemap.m_mapstr.end())
g_alwaysuploadvoice=true;
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("自动删除生成的语音文件"))!=g_morereplacemap.m_mapstr.end())
g_deletevoicefile=true;
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("使用新版的qq音乐播放模式"))!=g_morereplacemap.m_mapstr.end())
g_newplaymusicmode=true;

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("回复内容调用语音转换接口进行输出"))!=g_morereplacemap.m_mapstr.end())
g_voiceoutall=g_morereplacemap[_T("回复内容调用语音转换接口进行输出")].front();
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("【强制使用转换接口进行输出】"))!=g_morereplacemap.m_mapstr.end())
g_forcevoiceoutall=g_morereplacemap[_T("【强制使用转换接口进行输出】")].front();


if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("获取用于修改群名片文字的接口"))!=g_morereplacemap.m_mapstr.end())
g_modifycardurl=g_morereplacemap[_T("获取用于修改群名片文字的接口")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("第三方的禁言接口"))!=g_morereplacemap.m_mapstr.end())
g_thirdshutupurl = g_morereplacemap[_T("第三方的禁言接口")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("第三方的踢人接口"))!=g_morereplacemap.m_mapstr.end())
g_thirdkickurl = g_morereplacemap[_T("第三方的踢人接口")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("默认的卡片消息格式"))!=g_morereplacemap.m_mapstr.end())
g_xmlformatstr=g_morereplacemap[_T("默认的卡片消息格式")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("卡片消息最大允许字数"))!=g_morereplacemap.m_mapstr.end())
g_xmlmaxsize=_ttoi(g_morereplacemap[_T("卡片消息最大允许字数")].front());

//if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("使用卡片消息最小需要的字数"))!=g_morereplacemap.m_mapstr.end())
//g_xmlminsize=_ttoi(g_morereplacemap[_T("使用卡片消息最小需要的字数")].front());

if (find(g_morereplacemap.m_mapstr.begin(), g_morereplacemap.m_mapstr.end(), _T("在字数很少且无换行时自动附加一个表情符号或句子")) != g_morereplacemap.m_mapstr.end())
g_xmlstuff = g_morereplacemap[_T("在字数很少且无换行时自动附加一个表情符号或句子")].front();

if (find(g_morereplacemap.m_mapstr.begin(), g_morereplacemap.m_mapstr.end(), _T("卡片消息添加换行符后还是保持一行")) != g_morereplacemap.m_mapstr.end())
g_xmlkeeponelineflag =true;

if (find(g_morereplacemap.m_mapstr.begin(), g_morereplacemap.m_mapstr.end(), _T("msg")) != g_morereplacemap.m_mapstr.end())
g_msgreplace = g_morereplacemap[_T("msg")].front();

if (find(g_morereplacemap.m_mapstr.begin(), g_morereplacemap.m_mapstr.end(), _T("非卡片回复内容的开头都自动附加的内容")) != g_morereplacemap.m_mapstr.end())
g_bMust2receiver = g_morereplacemap[_T("非卡片回复内容的开头都自动附加的内容")].front();

if (find(g_morereplacemap.m_mapstr.begin(), g_morereplacemap.m_mapstr.end(), _T("非卡片回复内容的结尾都自动附加的内容")) != g_morereplacemap.m_mapstr.end())
g_bMustappend2receiver = g_morereplacemap[_T("非卡片回复内容的结尾都自动附加的内容")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("卡片消息一行消息太长则自动添加换行符"))!=g_morereplacemap.m_mapstr.end())
{
g_autoreturnfalg=_ttoi(g_morereplacemap[_T("卡片消息一行消息太长则自动添加换行符")].front());
if(g_autoreturnfalg==0)
	g_autoreturnfalg=60;
}
if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("卡片消息若超过最大允许字数后自动换成普通消息发送"))!=g_morereplacemap.m_mapstr.end())
{
g_autoswich2normalflag=true;

}

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("卡片文字随机颜色"))!=g_morereplacemap.m_mapstr.end())
g_xmlfontcolorstr=g_morereplacemap[_T("卡片文字随机颜色")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("默认的卡片消息后缀标识"))!=g_morereplacemap.m_mapstr.end())
g_xmliconstr=g_morereplacemap[_T("默认的卡片消息后缀标识")].front();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("默认的卡片消息前缀标识"))!=g_morereplacemap.m_mapstr.end())
g_xmlpreheadstr=g_morereplacemap[_T("默认的卡片消息前缀标识")].front();


g_bForidrecognizegroupvoice=find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("禁止自动识别群语音消息"))!=g_morereplacemap.m_mapstr.end();
if(g_bForidrecognizegroupvoice)
{
CString g_exceptgroupvoiceliststr=g_morereplacemap[_T("禁止自动识别群语音消息")].front();
CStringvect tempvect;
::function::getmytoken(g_exceptgroupvoiceliststr,_T("；+;，, "),tempvect);
for(int i=0;i<tempvect.size();i++)
{
	g_exceptgroupvoicelist.insert(_ttoi64(tempvect[i]));
}

}

g_bForidrecognizeprivatevoice=find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("禁止自动识别私聊语音消息"))!=g_morereplacemap.m_mapstr.end();
if(g_bForidrecognizeprivatevoice)
{
CString g_exceptprivatevoiceliststr=g_morereplacemap[_T("禁止自动识别私聊语音消息")].front();
CStringvect tempvect;
::function::getmytoken(g_exceptprivatevoiceliststr,_T("；+;，, "),tempvect);
for(int i=0;i<tempvect.size();i++)
{
	g_exceptprivatevoicelist.insert(_ttoi64(tempvect[i]));
}

}


g_bShowTxtAfterrecognizegroupvoice=find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("识别群语音消息后在群里发出识别内容"))!=g_morereplacemap.m_mapstr.end();


g_bForbidSavevoicefile=find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("禁止自动保存识别到的语音文件"))!=g_morereplacemap.m_mapstr.end();

if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("识别图片文字apikey"))!=g_morereplacemap.m_mapstr.end())
{	
	g_ocrkey=g_morereplacemap[_T("识别图片文字apikey")].front();
}


if(find(g_morereplacemap.m_mapstr.begin(),g_morereplacemap.m_mapstr.end(),_T("自动回报机器人在线状态的接口网址"))!=g_morereplacemap.m_mapstr.end())
{	
	CString tempreporturl;
g_bAutoReportAds=g_morereplacemap[_T("自动回报机器人在线状态的接口网址")].front();
tempreporturl=g_bAutoReportAds;
CString dddd;

		dddd.Format(_T("&cfrobotselfnum=%s&version=%s&checksign=%s"),m_ownqqnumber,g_purenumberversion,g_ksidmd5);
		
		
		
		if(tempreporturl.Find(_T('?'))==-1)
			tempreporturl+='?';
tempreporturl+=dddd;

	if(m_alreadylogin)
	{
g_reporturl=tempreporturl;

	}
}

}
void RegexReplace(CString& rp_tempstr2,LPCTSTR str1,LPCTSTR str2)
{
	//if(lstrlen(str2))
	{
		boost::wregex expression2(str1,boost::wregex::normal|boost::wregex::icase);//,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");
		wstring findbuf2=rp_tempstr2.GetBuffer(0);
		findbuf2=boost::regex_replace(findbuf2,expression2,str2);

		rp_tempstr2=findbuf2.c_str();
	}
	
}

int ChineseConvertPy(const std::string& dest_chinese,std::string& out_py) {
	const int spell_value[]={ -20319,-20317,-20304,-20295,-20292,-20283,-20265,-20257,-20242,-20230,-20051,-20036,-20032,-20026,
		-20002,-19990,-19986,-19982,-19976,-19805,-19784,-19775,-19774,-19763,-19756,-19751,-19746,-19741,-19739,-19728,
		-19725,-19715,-19540,-19531,-19525,-19515,-19500,-19484,-19479,-19467,-19289,-19288,-19281,-19275,-19270,-19263,
		-19261,-19249,-19243,-19242,-19238,-19235,-19227,-19224,-19218,-19212,-19038,-19023,-19018,-19006,-19003,-18996,
		-18977,-18961,-18952,-18783,-18774,-18773,-18763,-18756,-18741,-18735,-18731,-18722,-18710,-18697,-18696,-18526,
		-18518,-18501,-18490,-18478,-18463,-18448,-18447,-18446,-18239,-18237,-18231,-18220,-18211,-18201,-18184,-18183,
		-18181,-18012,-17997,-17988,-17970,-17964,-17961,-17950,-17947,-17931,-17928,-17922,-17759,-17752,-17733,-17730,
		-17721,-17703,-17701,-17697,-17692,-17683,-17676,-17496,-17487,-17482,-17468,-17454,-17433,-17427,-17417,-17202,
		-17185,-16983,-16970,-16942,-16915,-16733,-16708,-16706,-16689,-16664,-16657,-16647,-16474,-16470,-16465,-16459,
		-16452,-16448,-16433,-16429,-16427,-16423,-16419,-16412,-16407,-16403,-16401,-16393,-16220,-16216,-16212,-16205,
		-16202,-16187,-16180,-16171,-16169,-16158,-16155,-15959,-15958,-15944,-15933,-15920,-15915,-15903,-15889,-15878,
		-15707,-15701,-15681,-15667,-15661,-15659,-15652,-15640,-15631,-15625,-15454,-15448,-15436,-15435,-15419,-15416,
		-15408,-15394,-15385,-15377,-15375,-15369,-15363,-15362,-15183,-15180,-15165,-15158,-15153,-15150,-15149,-15144,
		-15143,-15141,-15140,-15139,-15128,-15121,-15119,-15117,-15110,-15109,-14941,-14937,-14933,-14930,-14929,-14928,
		-14926,-14922,-14921,-14914,-14908,-14902,-14894,-14889,-14882,-14873,-14871,-14857,-14678,-14674,-14670,-14668,
		-14663,-14654,-14645,-14630,-14594,-14429,-14407,-14399,-14384,-14379,-14368,-14355,-14353,-14345,-14170,-14159,
		-14151,-14149,-14145,-14140,-14137,-14135,-14125,-14123,-14122,-14112,-14109,-14099,-14097,-14094,-14092,-14090,
		-14087,-14083,-13917,-13914,-13910,-13907,-13906,-13905,-13896,-13894,-13878,-13870,-13859,-13847,-13831,-13658,
		-13611,-13601,-13406,-13404,-13400,-13398,-13395,-13391,-13387,-13383,-13367,-13359,-13356,-13343,-13340,-13329,
		-13326,-13318,-13147,-13138,-13120,-13107,-13096,-13095,-13091,-13076,-13068,-13063,-13060,-12888,-12875,-12871,
		-12860,-12858,-12852,-12849,-12838,-12831,-12829,-12812,-12802,-12607,-12597,-12594,-12585,-12556,-12359,-12346,
		-12320,-12300,-12120,-12099,-12089,-12074,-12067,-12058,-12039,-11867,-11861,-11847,-11831,-11798,-11781,-11604,
		-11589,-11536,-11358,-11340,-11339,-11324,-11303,-11097,-11077,-11067,-11055,-11052,-11045,-11041,-11038,-11024,
		-11020,-11019,-11018,-11014,-10838,-10832,-10815,-10800,-10790,-10780,-10764,-10587,-10544,-10533,-10519,-10331,
		-10329,-10328,-10322,-10315,-10309,-10307,-10296,-10281,-10274,-10270,-10262,-10260,-10256,-10254 };

	// 395个字符串，每个字符串长度不超过6  
	const char spell_dict[396][7]={ "a","ai","an","ang","ao","ba","bai","ban","bang","bao","bei","ben","beng","bi","bian","biao",
		"bie","bin","bing","bo","bu","ca","cai","can","cang","cao","ce","ceng","cha","chai","chan","chang","chao","che","chen",
		"cheng","chi","chong","chou","chu","chuai","chuan","chuang","chui","chun","chuo","ci","cong","cou","cu","cuan","cui",
		"cun","cuo","da","dai","dan","dang","dao","de","deng","di","dian","diao","die","ding","diu","dong","dou","du","duan",
		"dui","dun","duo","e","en","er","fa","fan","fang","fei","fen","feng","fo","fou","fu","ga","gai","gan","gang","gao",
		"ge","gei","gen","geng","gong","gou","gu","gua","guai","guan","guang","gui","gun","guo","ha","hai","han","hang",
		"hao","he","hei","hen","heng","hong","hou","hu","hua","huai","huan","huang","hui","hun","huo","ji","jia","jian",
		"jiang","jiao","jie","jin","jing","jiong","jiu","ju","juan","jue","jun","ka","kai","kan","kang","kao","ke","ken",
		"keng","kong","kou","ku","kua","kuai","kuan","kuang","kui","kun","kuo","la","lai","lan","lang","lao","le","lei",
		"leng","li","lia","lian","liang","liao","lie","lin","ling","liu","long","lou","lu","lv","luan","lue","lun","luo",
		"ma","mai","man","mang","mao","me","mei","men","meng","mi","mian","miao","mie","min","ming","miu","mo","mou","mu",
		"na","nai","nan","nang","nao","ne","nei","nen","neng","ni","nian","niang","niao","nie","nin","ning","niu","nong",
		"nu","nv","nuan","nue","nuo","o","ou","pa","pai","pan","pang","pao","pei","pen","peng","pi","pian","piao","pie",
		"pin","ping","po","pu","qi","qia","qian","qiang","qiao","qie","qin","qing","qiong","qiu","qu","quan","que","qun",
		"ran","rang","rao","re","ren","reng","ri","rong","rou","ru","ruan","rui","run","ruo","sa","sai","san","sang",
		"sao","se","sen","seng","sha","shai","shan","shang","shao","she","shen","sheng","shi","shou","shu","shua",
		"shuai","shuan","shuang","shui","shun","shuo","si","song","sou","su","suan","sui","sun","suo","ta","tai",
		"tan","tang","tao","te","teng","ti","tian","tiao","tie","ting","tong","tou","tu","tuan","tui","tun","tuo",
		"wa","wai","wan","wang","wei","wen","weng","wo","wu","xi","xia","xian","xiang","xiao","xie","xin","xing",
		"xiong","xiu","xu","xuan","xue","xun","ya","yan","yang","yao","ye","yi","yin","ying","yo","yong","you",
		"yu","yuan","yue","yun","za","zai","zan","zang","zao","ze","zei","zen","zeng","zha","zhai","zhan","zhang",
		"zhao","zhe","zhen","zheng","zhi","zhong","zhou","zhu","zhua","zhuai","zhuan","zhuang","zhui","zhun","zhuo",
		"zi","zong","zou","zu","zuan","zui","zun","zuo" };

	try {
		// 循环处理字节数组  
		const int length=dest_chinese.length();
		for(int j=0,chrasc=0; j < length;) {
			// 非汉字处理  
			if(dest_chinese.at(j)>=0&&dest_chinese.at(j) < 128) {
				out_py+=dest_chinese.at(j);
				// 偏移下标  
				j++;
				continue;
			}

			// 汉字处理  
			chrasc=dest_chinese.at(j)*256+dest_chinese.at(j+1)+256;
			if(chrasc > 0&&chrasc < 160) {
				// 非汉字  
				out_py+=dest_chinese.at(j);
				// 偏移下标  
				j++;
			}
			else {
				// 汉字  
				for(int i=(sizeof(spell_value)/sizeof(spell_value[0])-1); i>=0; --i) {
					// 查找字典  
					if(spell_value[i]<=chrasc) {
						out_py+=spell_dict[i];
						break;
					}
				}
				// 偏移下标 （汉字双字节）  
				j+=2;
			}
		} // for end  
	}
	catch(exception _e) {
		std::cout<<_e.what()<<std::endl;
		return -1;
	}
	return 0;
}

BOOL ComPareTwoWordPinyin(TCHAR word1,TCHAR word2)
{
	BOOL bEqual=false;
	std::string str1;
	std::string out_py1;
std::string str2;
	std::string out_py2;
	CString wstr1,wstr2;
	wstr1.AppendChar(word1);
	wstr2.AppendChar(word2);

	
	str1=::function::CStrW2CStrA(wstr1).GetBuffer(0);
	str2=::function::CStrW2CStrA(wstr2).GetBuffer(0);
	int word1value=ChineseConvertPy(str1,out_py1);

	int word2value=ChineseConvertPy(str2,out_py2);

	if(!word1value&&!word2value&&out_py1==out_py2)
		bEqual=true;

	return bEqual;
}
void C晨风qq机器人Dlg::LoadPriviliegeFile(int mode)
{

	g_bTestplugexistflag=PathFileExists(g_testplugpath);
	g_inputreplacemap.RemoveAll();
	g_reservecmdset.clear();
	g_gameinputfilepathmap.RemoveAll();
g_gamesetencefilepathmap.RemoveAll();
g_filepath2outreplacemap.RemoveAll();
g_otherwelcome_groupset.clear();
g_had_joined_groupset.clear();
	lockgroupbeignoreresource.Lock();
		g_groupbeIgnoreMap.RemoveAll();
		lockgroupbeignoreresource.Unlock();
	for(int i=0;i<100;i++)
	{
		
	g_randomtextvect[i].clear();
	}
		LoadMoreSettingFile();
		//获取更多个性配置.txt中的值

	GetKeepMapFromFile(g_autoreplymap,g_autoreplyfile1,true);

	g_gameliststr=_T("");
	CReadAUStdioFile gamefile1;
	g_outputreplacemap.RemoveAll();
	g_discusslist.RemoveAll();
	g_forever_blacklist.clear();
if(gamefile1.Open(g_foreverblackfn,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr,frontstr,backstr;
		CStringvect vectemp;
		while(gamefile1.ReadString(tempstr))
	{
		::function::getmytoken(tempstr,_T(" ;,"),vectemp);
		for(int i=0;i<vectemp.size();i++)
		{
		g_forever_blacklist.insert(_ttoi64(vectemp[i]));
		}
		
	}
gamefile1.Close();
}
g_forever_blacklist.insert(temp_forever_blacklist.begin(),temp_forever_blacklist.end());
for(auto it=tempdel_forever_blacklist.end();it!=tempdel_forever_blacklist.end();it++)
{
g_forever_blacklist.erase(*it);
}


g_notreplyprivate_list.clear();
	if(gamefile1.Open(g_notreplyprivatefn,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr,frontstr,backstr;
		CStringvect vectemp;
		while(gamefile1.ReadString(tempstr))
		{
			::function::getmytoken(tempstr,_T(" ;,"),vectemp);
			for(int i=0;i<vectemp.size();i++)
			{
				g_notreplyprivate_list.insert(_ttoi64(vectemp[i]));
			}

		}
		gamefile1.Close();
	}

	
g_notreplygroup_list.clear();
	if(gamefile1.Open(g_notreplygroupfn,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr,frontstr,backstr;
		CStringvect vectemp;
		while(gamefile1.ReadString(tempstr))
		{
			::function::getmytoken(tempstr,_T(" ;,"),vectemp);
			for(int i=0;i<vectemp.size();i++)
			{
				g_notreplygroup_list.insert(_ttoi64(vectemp[i]));
			}

		}
		gamefile1.Close();
	}


	CReadAUStdioFile helpfile;
	CString helppath;

	g_idiomvect.clear();

helppath=::function::CFSoft_path(_T("成语大全.txt"),0,g_bLocalSaveflag);
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
		g_idiomvect.reserve(32000);
		idiombuf idibuf7;
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;
		if(tempstr.GetLength()<4)
			continue;
		if(tempstr.GetLength()<7)
		{
			lstrcpy(idibuf7.buf,tempstr);

		g_idiomvect.push_back(idibuf7);
		}
		else
		{
			CString frontstr,backstr;
			if(::function::GetHalfStr(tempstr,&frontstr,&backstr,_T("，")))
			{
			_tcsncpy(idibuf7.buf,frontstr,6);
idibuf7.buf[6]=0;

		g_idiomvect.push_back(idibuf7);

			_tcsncpy(idibuf7.buf,backstr,6);
idibuf7.buf[6]=0;
		g_idiomvect.push_back(idibuf7);


			
			}
			
		
		}
	}
	
	helpfile.Close();
	}


	helppath=SaveAs_complete_path(_T("输出替换.txt"));

	
	LoadOutputReplacemap(helppath,g_outputreplacemap);



	helppath=SaveAs_complete_path(_T("输出替换.encode.log"));

		LoadOutputReplacemap(helppath,g_outputreplacemap);

	

if(mode==1)
g_bAutoAppendFileName=1;
		else if(mode==2)
			g_bAutoAppendFileName=0;
		else if(mode==3)
			g_bAutoAppendFileName=2;
		

	GetKeepMapFromFile(g_Privilegeautoreplymap,g_Privilegeautoreplyfile1);
	g_Privilegeautoreplymap.sortLen();
	
	
ReLoadGameFile();

	LoadUUUsernameAndPwd();
	LoadTaskFile();

	g_helpstr=_T("");

	helppath=SaveAs_complete_path(_T("帮助.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
	while(helpfile.ReadString(tempstr))
	{
	g_helpstr+=tempstr;
	g_helpstr+=_T("\r\n");
	}
	if(g_helpstr.GetLength()>=2)
	g_helpstr=g_helpstr.Left(g_helpstr.GetLength()-2);

	helpfile.Close();
	}
	else
	{
	g_helpstr=_T("机器人说话\r\n机器人闭嘴\r\n开启赌博功能\r\n关闭赌博功能\r\n开启签到功能\r\n关闭签到功能\r\n不处理加群请求\r\n自动同意加群\r\n自动拒绝加群\r\n奖励10000（qq号） 30金币\r\n扣除10000（qq号） 20金币\r\n赠送13402429 10金币\r\n赌一把1赔10下注20金币\r\n以群聊的方式回复\r\n以私聊的方式回复\r\n添加管理员：10000（替换成qq号）\r\n删除管理员：10000（替换成qq号）\r\n拉黑xxxx（qq号）\r\n解除拉黑xxxx（qq号）\r\n更改拒绝理由：xxxx（拒绝的理由）\r\n更改群欢迎词：xxxx（欢迎词）\r\n允许普通群友让机器人闭嘴或说话\r\n禁止普通群友让机器人闭嘴或说话\r\n关闭机器人\r\n取消关闭机器人\r\n要查询各类信息，可以输入#南昌天气、#笑话、#你想聊的话题、#18970900000、#翻译I love you、#歌词北京欢迎你、#星座处女座、#计算3加2乘8、192.168.1.1、#成语得陇望蜀、#邮编330000。");
	
	}

	
	helppath=SaveAs_complete_path(_T("避免被输入替换和优先回复拦截的指令列表.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
	if(!tempstr.IsEmpty())
	{
	g_reservecmdset.insert(tempstr);
	}

	}
	
	helpfile.Close();
	}

	helppath=SaveAs_complete_path(_T("输入替换.txt"));
	

LoadInputReplacemap(helppath,g_inputreplacemap);
	
	helppath=SaveAs_complete_path(_T("输入替换.encode.log"));


LoadInputReplacemap(helppath,g_inputreplacemap);
	


	




	g_dreamreplymap.RemoveAll();

	helppath=SaveAs_complete_path(_T("周公解梦全集.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;

		tempstr.Replace(_T(":"),_T("："));
		if(::function::GetHalfStr(tempstr,&frontstr,&backstr,_T("："),false))
		{
		g_dreamreplymap[frontstr]=backstr;

		}
		else
		{
		if(tempstr.GetLength()<6)
		{
			CString keystr=tempstr;
			keystr.Replace(_T(" "),_T(""));
			CString explainstr;
	GetNextDream(helpfile,explainstr);
		g_dreamreplymap[keystr]=explainstr;
		}

		}
		
	}
	g_dreamreplymap.sortLen();

	helpfile.Close();
	}

g_regoutputvect.RemoveAll();
	helppath=SaveAs_complete_path(_T("正则输出替换.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(helpfile.ReadString(tempstr))
	{
	
tempstr.Trim();
		GetPairStrFromReadFile(tempstr,frontstr,backstr);
		if(!frontstr.IsEmpty())
		{
		g_regoutputvect[frontstr]=backstr;
		}
		
	}
	
	helpfile.Close();
	}



	g_selfdeftailvector.clear();
	g_selfdeftail=_T("");
helppath=SaveAs_complete_path(_T("自定义广告尾巴.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		

	while(helpfile.ReadString(tempstr))
	{
	g_selfdeftail+=tempstr;
	g_selfdeftail+=_T("\r\n");
	}
		if(g_selfdeftail.GetLength()>=2)
	g_selfdeftail=g_selfdeftail.Left(g_selfdeftail.GetLength()-2);

		
		if(g_bTestplugexistflag)
		{
			GetTotal_content_vect(g_selfdeftailvector,g_selfdeftail);
		}
	helpfile.Close();
	}


g_rplevelmap.RemoveAll();

	helppath=SaveAs_complete_path(_T("人品计算.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;
	CString temptitle;
		INT64 tempscore;
		
		if(GetTitleAndScore(tempstr,temptitle,tempscore))
		{
		g_rplevelmap[temptitle]=tempscore;
		}

	
	
	}
	g_rplevelmap.rsortvalue();

	helpfile.Close();
	}

	g_namematchvect.clear();
	helppath=SaveAs_complete_path(_T("姓名配对.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
		CString frontstr,backstr;
	while(helpfile.ReadString(tempstr))
	{
		tempstr.Trim();
		if(tempstr.IsEmpty())
			continue;
	CString temptitle;
		INT64 tempscore;
		
	g_namematchvect.push_back(tempstr);

	
	
	}


	helpfile.Close();
	}

	g_adminhelpstr=_T("");
helppath=SaveAs_complete_path(_T("机器人管理员命令大全.txt"));
	if(helpfile.Open(helppath,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr;
	while(helpfile.ReadString(tempstr))
	{
	g_adminhelpstr+=tempstr;
	g_adminhelpstr+=_T("\r\n");
	}
	g_adminhelpstr.Trim();
	helpfile.Close();
	}
	else
	{
	g_adminhelpstr=_T("开启/关闭赌博功能\r\n开启/关闭签到功能\r\n不处理加群请求\r\n自动同意加群\r\n自动拒绝加群\r\n奖励10000（qq号） 30金币\r\n扣除10000（qq号） 20金币\r\n以群聊的方式回复\r\n以私聊的方式回复\r\n添加管理员：10000（替换成qq号）\r\n删除管理员：10000（替换成qq号）\r\n拉黑xxxx（qq号）\r\n解除拉黑xxxx（qq号）\r\n更改拒绝理由：xxxx（拒绝的理由）\r\n更改群欢迎词：xxxx（欢迎词）\r\n允许普通群友让机器人闭嘴或说话\r\n禁止普通群友让机器人闭嘴或说话\r\n关闭机器人\r\n取消关闭机器人。");
	
	}
	for (auto it = g_publicrushstuffvect.begin(); it!= g_publicrushstuffvect.end(); it++)
	{
		if ((*it).hugeanswer)
		{
			delete[](*it).hugeanswer;
		}
if ((*it).hugeaskbuf)
		{
			delete[](*it).hugeaskbuf;
		}
	}
		g_publicrushstuffvect.clear();
	CReadAUStdioFile file1;
	g_rushfn=SaveAs_complete_path(_T("抢答题.txt"));

	if(file1.Open(g_rushfn,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr,frontstr,backstr;
	
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
		while(file1.ReadString(tempstr))
	{
			rushstuffbuf temprushstf;
		GetPairStrFromReadFile(tempstr,frontstr,backstr,true);
		if(!frontstr.IsEmpty()&&!backstr.IsEmpty())
		{
			if (frontstr.GetLength() > 299)
				temprushstf.hugeaskbuf = new TCHAR[frontstr.GetLength()+1];

				//frontstr=frontstr.Left(299);

			if(backstr==_T("对")||backstr==_T("是")||backstr==_T("正确"))
			{
			backstr=_T("对|是|正确");
			}
			else if(backstr==_T("不对")||backstr==_T("不是")||backstr==_T("错")||backstr==_T("错误"))
			{
			backstr=_T("不对|不是|错|错误");
			}
			

			if (backstr.GetLength() > 49)
				temprushstf.hugeanswer = new TCHAR[backstr.GetLength() + 1];
				//backstr=backstr.Left(49);

			
			if (temprushstf.hugeaskbuf)
				lstrcpy(temprushstf.hugeaskbuf, frontstr);
			else
			lstrcpy(temprushstf.askbuf,frontstr);

			if (temprushstf.hugeanswer)
			lstrcpy(temprushstf.hugeanswer, backstr);
			else
			lstrcpy(temprushstf.answer,backstr);


		g_publicrushstuffvect.push_back(temprushstf);
		}
	}
	file1.Close();
	int rushsize=g_publicrushstuffvect.size();
	random_shuffle(g_publicrushstuffvect.begin(),g_publicrushstuffvect.end());


	}
	if(g_publicrushstuffvect.size()==0)
	{
	rushstuffbuf temprushstf;
	lstrcpy(temprushstf.askbuf,_T("无"));
	lstrcpy(temprushstf.answer,_T("无"));

	g_publicrushstuffvect.push_back(temprushstf);
	}


	
//LoadRushFile(rushfilename);

	lockqqmsgdlgres.Lock();
			for(UINT i=0;i<m_mapqqmsgdlg.m_mapstr.size();i++)
		{
			
			m_mapqqmsgdlg[i]->ReLoad();
			
		
		}
lockqqmsgdlgres.Unlock();
	

CReadAUStdioFile joined_groupset_file1;
CString Ignorefilename;
CString tempstr;
tempstr.Format(_T("加群记录(自动同意过一次后不会再同意第二次).txt"));
Ignorefilename = SaveAs_complete_path(tempstr);


if (joined_groupset_file1.Open(Ignorefilename, CFile::modeRead | CFile::shareDenyNone))
{

	while (joined_groupset_file1.ReadString(tempstr))
	{
		INT64 tempgroupnum = _ttoi64(tempstr);
		if (tempgroupnum)
			g_had_joined_groupset.insert(tempgroupnum);

	}
	joined_groupset_file1.Close();
}

tempstr.Format(_T("付费入群或允许任何人入群的群列表.txt"));
Ignorefilename = SaveAs_complete_path(tempstr);


if (joined_groupset_file1.Open(Ignorefilename, CFile::modeRead | CFile::shareDenyNone))
{

	while (joined_groupset_file1.ReadString(tempstr))
	{
		INT64 tempgroupnum = _ttoi64(tempstr);
		if (tempgroupnum)
			g_otherwelcome_groupset.insert(tempgroupnum);

	}
	joined_groupset_file1.Close();
}
//MessageBox(_T("登录成功！你可以把软件最小化，以避免自动弹出的消息窗口打扰!"),_T("登录成功！"),0);


}
extern int getCff_Num(const void*inbuf);
void  GetRPtitle(LPCTSTR namestr,OUT CString& titlestr)
{
	int score=0;
	
	CString strfmt;
	
	GetLocalTime(&mySystemTime);
	strfmt.Format(_T("%s%d"),namestr,mySystemTime.wDay);
	CStringA bufferstr=(CStringA)strfmt;

	int tt=getCff_Num(bufferstr.GetBuffer(0));
	score=tt%102;
	CString curtitle=_T("非人非鬼非妖非神，你到底是谁？");
	for(UINT i=0;i<g_rplevelmap.m_mapstr.size();i++)
	{
	if(score>=g_rplevelmap[i])
	{
		curtitle=g_rplevelmap.m_mapstr[i];
	break;
	}
	}
	if(score<30)
	{
	titlestr.Format(_T("姓名：%s\r\n人品得分:%d\r\n评价：%s\r\n————不要灰心，放学或下班后做件好事，改过自新，明天再来，或许会有惊喜出现！"),namestr,score,curtitle);
	}
	else
	{
		if(score>80)
titlestr.Format(_T("姓名：%s\r\n人品得分:%d\r\n评价：%s\r\n————别骄傲，继续保持，别做坏事，不然明天你的人品可能就会暴跌！"),namestr,score,curtitle);
		else
titlestr.Format(_T("姓名：%s\r\n人品得分:%d\r\n评价：%s\r\n"),namestr,score,curtitle);

	}
	
	
}
void  GetNameMatch(LPCTSTR namestr,OUT CString& titlestr)
{

	int score=0;
	CString name1,name2;
	
	::function::GetHalfStr(namestr,&name1,&name2,' ');
	name1.Trim();
	name2.Trim();
	if(name1.IsEmpty()&&name2.IsEmpty())
	{

	::function::GetHalfStr(namestr,&name1,&name2,_T("和"));
	name1.Trim();
	name2.Trim();
	}

	CString comstr=name1+name2;
	CStringA comstra=(CStringA)comstr;
int num=getCff_Num(comstra.GetBuffer());

int msize=g_namematchvect.size();
if(name1.IsEmpty()&&name2.IsEmpty())
{
titlestr=_T("请用“配对张三 李四”的格式查询！");	

}
else if(name1==_T("张三")&&name2==_T("李四"))
{
titlestr=_T("张三和李四都是男的好不好，我能怎么说，一对好基友？要查询姓名配对的同学，请严肃点！");	

}
else if(!name1.IsEmpty()&&name2.IsEmpty())
{
titlestr=_T("难道不应该有两个人名吗？只有一个人名？那只能和自己左右手配对了！");	

}
else if(msize>0)
titlestr.Format(_T("%s和%s的%s"),name1,name2,g_namematchvect[num%msize]);
	else
	titlestr=_T("姓名配对功能不可用，请检查机器人软件目录下的“姓名配对.txt”中的内容是否为空！");	


	
	
}
void C晨风qq机器人Dlg::LoadBkImage()
{
	
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(rect);
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);

	HBITMAP   pbmpOld = (HBITMAP)dcMem.SelectObject(m_bkghBitmap);
	dc.SetStretchBltMode(HALFTONE);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, m_bkgimage.GetWidth(), m_bkgimage.GetHeight(), SRCCOPY);
	dcMem.SelectObject(pbmpOld);
	dcMem.DeleteDC();
}
void C晨风qq机器人Dlg::OnPaint()
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

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if(!g_forbidbkgflag)
		{
			if(m_bkghBitmap)
			{
				LoadBkImage();

			}
		}
		rerangeButton();
		CMyBGCDlg::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C晨风qq机器人Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}










void C晨风qq机器人Dlg::OnBnClickedOver()
{
	ShellExecute(0,0,_T("http://www.qqshow123.com/productinfo.php?id=24"),0,0,1);
//OnOK();
}


void C晨风qq机器人Dlg::OnDropFiles(HDROP hDropInfo)
{
	TCHAR szFileName[256];
	int FileNum = DragQueryFile(hDropInfo,(UINT)-1,szFileName,255);//得到拖动文件个数
	
	for ( int i =0 ; i < FileNum ; i++ )
	{
		DragQueryFile(hDropInfo,i,szFileName,255); //szFileName第i个文件名
	
	}
	
	::DragFinish(hDropInfo);


	CMyBGCDlg::OnDropFiles(hDropInfo);
}





int C晨风qq机器人Dlg::Getg_tkfromskey(const CString& skey)
{
	
	int hash = 5381;
	int len = skey.GetLength();
  for(int i = 0;i <len; ++i)
  {
  hash += (hash << 5) + skey.GetAt(i);
  }
  int returnvv=hash & 0x7fffffff;
  return returnvv;
}

//http://web.qun.qq.com/cgi-bin/announce/add_qun_notice
//POST方式提交，需要Cookies，用于发布公告
//bkn = %bkn%&qid = %群号%&title = %标题UTF8编码%&text = %公告内容%&pic = %图片编码%
//修改群公告

//http://web.qun.qq.com/cgi-bin/announce/get_t_list

//POST方式提交，需要Cookies，用于取群公告

//bkn = %bkn%&qid = %群号%&ft = 23 & s = -1 & n = 10 & ni = 1 & i = 1

//https://ui.ptlogin2.qq.com/js/10047/comm.js
//https://ui.ptlogin2.qq.com/js/10114/comm.js



BOOL PostDataToWeb(LPCTSTR realhostname,LPCTSTR processpath,const CStringvect& columname_com,const CStringvect &columvalue_com,const CString& columname_pic_col,CString& feedbackstr,byte *picsrc=NULL,int len=0)
{


//CString columname_pic_col;

	

BOOL rtflag=::Multipartpost(realhostname,processpath,columname_com,columvalue_com,columname_pic_col, picsrc,len,feedbackstr);
return rtflag;
}
void MySendWeb3(LPCTSTR realhostname, LPCTSTR processpath, byte *imagebytebuf, char* sttt, UINT& ddlen, LPCTSTR headstr,LPTSTR locationurl)
{
	CHttpConnection* pConnection;
	CInternetSession *p_session;
	p_session = new CInternetSession;
	pConnection = p_session->GetHttpConnection(realhostname, (DWORD)INTERNET_FLAG_KEEP_CONNECTION);

	CString rgfilename = _T("imagebyte");
	CString	strHeaders;
	if (headstr != NULL&&lstrlen(headstr))
		strHeaders.Format(_T("Accept: */*\r\n%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"), headstr);
	else
		strHeaders.Format(_T("Accept: */*\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"));

	//strHeaders.Format(_T("Accept: */*\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"));




	//strcpy(pattachm,"replycampus=0&content=测试留言！&uin=35376062&ouin=13402429&g_tk=1662176677");
	//ddlen=strlen(pattachm);
	
	Send2web(pConnection, strHeaders, processpath, sttt, ddlen, (byte*)imagebytebuf, locationurl, rgfilename,0,0,false);



	delete pConnection;
	delete p_session;

}
BOOL MySendWeb(LPCTSTR realhostname,LPCTSTR processpath,byte *imagebytebuf,const char* postdata,UINT& ddlen,BOOL bHttps,LPCTSTR additionalhead)
{
	BOOL rtflag=false;
	try
	{
	
	CInternetSession *p_session;
CHttpConnection* pConnection=NULL;
p_session=new CInternetSession(_T("Internet Explorer"));


if(bHttps)
pConnection = p_session->GetHttpConnection(realhostname,(DWORD)INTERNET_FLAG_KEEP_CONNECTION|INTERNET_FLAG_SECURE,INTERNET_DEFAULT_HTTPS_PORT); 
	else
	pConnection = p_session->GetHttpConnection(realhostname,(DWORD)INTERNET_FLAG_KEEP_CONNECTION); 
	
		CString rgfilename=_T("imagebyte");
				CString	strHeaders;
				//strHeaders.Format(_T("Accept: */*\r\nReferer: http://%s%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"),realhostname,processpath);
				//strHeaders.Format(_T("Accept: */*\r\nReferer: http://user.qzone.qq.com/%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E; staticlogin:product=cboxf2010&act=login&info=ZmlsZW5hbWU9UG93ZXJXb3JkMjAxME94Zl9VbHRpbWF0ZS5leGUmbWFjPTY0NUJFNjJFMTFDRjQ2RUY5MkEyRUU0QUE1NUE0NTMxJnBhc3Nwb3J0PSZ2ZXJzaW9uPTIwMTAuNi4zLjYuMiZjcmFzaHR5cGU9MQ==&verify=835e08835891bcf13762a6d398ef61bd; InfoPath.3)\r\n"),m_elseqqnumber);
			
				if(additionalhead)
strHeaders.Format(_T("Accept: */*\r\n%sReferer: http://%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"),additionalhead,realhostname);
				else
				{
					CString temphost=realhostname;
				//	if(lstrcmp(realhostname,_T("cache.kuaidi100.com"))==0)
				//	{
				//		temphost=_T("www.kuaidi100.com");
				//	//http://www.kuaidi100.com/
				//	
				//strHeaders.Format(_T("Accept: application/javascript, */*;q=0.8\r\nReferer: http://%s\r\nAccept-Encoding: gzip, deflate\r\nCookie: csrftoken=xMKyFnAS0QTK7nxqEspeHlqH6lM595_YNrqsPapWTAc; Hm_lvt_22ea01af58ba2be0fec7c11b25e88e6c=1557567117,1557567673,1557621264; Hm_lpvt_22ea01af58ba2be0fec7c11b25e88e6c=1557621264\r\nAccept-Language: zh-Hans-CN,zh-Hans;q=0.5\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko\r\n"),temphost);
				//	}
				//	else
strHeaders.Format(_T("Accept: */*\r\nReferer: http://%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"),temphost);
				
					}
				if(0)
			if(additionalhead)
strHeaders.Format(_T("Accept: */*\r\n%sUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"),additionalhead);
			

				rgfilename=_T("login.html");
				int maxlen=0;
				if(ddlen&&!postdata)
					maxlen=ddlen;
				rtflag=Send2web(pConnection,strHeaders,processpath,postdata,ddlen,(byte*)imagebytebuf,NULL,rgfilename,0,0,1,maxlen,bHttps,additionalhead);
				
		delete pConnection;

				delete p_session;
	}
	catch(...)
	{
	CString path=::function::complete_path(_T("MySendWeb_error.txt"));
		catcherror(path,processpath);
	}

				return rtflag;
}

BOOL MySendWebLocaltion(LPCTSTR realhostname,LPCTSTR processpath,byte *imagebytebuf,const char* postdata,UINT& ddlen,LPTSTR localtion,int maxlen)
{              
	BOOL rtflag=false;
	try
	{
	
	CInternetSession *p_session;
CHttpConnection* pConnection;
p_session=new CInternetSession;

	pConnection = p_session->GetHttpConnection(realhostname,(DWORD)INTERNET_FLAG_KEEP_CONNECTION); 
	
		CString rgfilename=_T("imagebyte");
				CString	strHeaders;
				//strHeaders.Format(_T("Accept: */*\r\nReferer: http://%s%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"),realhostname,processpath);
				//strHeaders.Format(_T("Accept: */*\r\nReferer: http://user.qzone.qq.com/%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E; staticlogin:product=cboxf2010&act=login&info=ZmlsZW5hbWU9UG93ZXJXb3JkMjAxME94Zl9VbHRpbWF0ZS5leGUmbWFjPTY0NUJFNjJFMTFDRjQ2RUY5MkEyRUU0QUE1NUE0NTMxJnBhc3Nwb3J0PSZ2ZXJzaW9uPTIwMTAuNi4zLjYuMiZjcmFzaHR5cGU9MQ==&verify=835e08835891bcf13762a6d398ef61bd; InfoPath.3)\r\n"),m_elseqqnumber);
				strHeaders.Format(_T("Accept: */*\r\nReferer: http://%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"),realhostname);
				
				//strHeaders.Format(_T("Accept: */*\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"));
				//strHeaders.Format(_T("Accept: */*\r\nX-Requested-With: XMLHttpRequest\r\nReferer: http://%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\nCookie: sagree=true; selected_nc=zh; JSESSIONID=C035955D3B33F375A6D9896C820158F0; AWSELB=15E16D030EBAAAB8ACF4BD9BB7E0CA8FB501388662640BCEC6E9C54E70B150AA8514D30E844A0F6781F3C00BEC43069730243F418119D4A1660F073D105DD873991975B881\r\n"),_T("www.simsimi.com/talk.htm"));
				

				//strHeaders.Format(_T("Accept: application/json, text/javascript, */*; q=0.01\r\nX-Requested-With: XMLHttpRequest\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko)Chrome/27.0.1453.116 Safari/537.36\r\nContent-Type: application/json; charset=utf-8\r\nReferer: http://www.simsimi.com/talk.htm\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\nCookie: sagree=true; selected_nc=zh; JSESSIONID=C035955D3B33F375A6D9896C820158F0; AWSELB=15E16D030EBAAAB8ACF4BD9BB7E0CA8FB501388662640BCEC6E9C54E70B150AA8514D30E844A0F6781F3C00BEC43069730243F418119D4A1660F073D105DD873991975B881\r\nConnection: keep-alive\r\n"));
			
				//strcpy(pattachm,"replycampus=0&content=测试留言！&uin=35376062&ouin=13402429&g_tk=1662176677");
				//ddlen=strlen(pattachm);    
				rgfilename=_T("login.html");
				rtflag=Send2web(pConnection,strHeaders,processpath,postdata,ddlen,(byte*)imagebytebuf,localtion,rgfilename,0,0,false,maxlen);
				ddlen=maxlen;
				::function::DownloadHttpFile(localtion,imagebytebuf,ddlen);
		delete pConnection;
				delete p_session;
	}
	catch(...)
	{
	CString path=::function::complete_path(_T("MySendWeb_error.txt"));
		catcherror(path,processpath);
	}

				return rtflag;
}

BOOL C晨风qq机器人Dlg::Change_status()
{
	
	if(!m_alreadylogin)
		return false;

	CStringvect columname_com;
CString feedbackstr;
	
	CStringvect columvalue_com;
	CString rstructstr;
	CString g_tkstr;

CString realhostname;
CString processpath;
realhostname=_T("d1.web2.qq.com");
CString timestr2;
SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format(_T("%I64d%d"),time1.GetTime(),st.wMilliseconds);
processpath.Format(_T("/channel/change_status2?newstatus=%s&clientid=%d&psessionid=%s&t=%s"),statusbuf[g_status_selcur],clientID,psessionidstr,timestr2);
	UINT ddlen=0;
return MySendWeb(realhostname,processpath,NULL,(char*)NULL,ddlen);


}


BOOL C晨风qq机器人Dlg::QuitQQ()
{
	
	
	{
	if(!g_last_bAuto_online&&g_socket&&qq.sessionKey.size())
	{
	sdk.QQOffLine();
	}
	return true;
	}
	
}

BOOL AgreeGroupRequest(INT64 groupuin,INT64 requestuin,INT64 timesignal)
{
	CString str222;
		str222.Format(_T("AgreeGroupRequesting"));
		
	Write2MagnetLog(str222,&magnetfile,11);

	if(g_bIgnoreAnyAgreeOrDeny)//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("不处理任何同意或拒绝加群的事务"))!=g_outputreplacemap.m_mapstr.end())
		return false;

	
		{
//			lockggroup_realqqsetmap.Lock();
//
//g_group_realqqvectMap[groupuin].insert(requestuin);
//
//lockggroup_realqqsetmap.Unlock();

		return	sdk.Fun_send(sdk.Pack_AgreeOrDenyJoinMsg(groupuin,requestuin,timesignal,NULL,true,false));
		
		}
		
	
}
BOOL DenyGroupRequest(INT64 groupuin,INT64 requestuin,INT64 timesignal,LPCTSTR reason)
{
	CString finalreason=reason;
	setvector<CString> tempsetv;
	if(g_outputreplacemap.Lookup(reason,tempsetv))
		finalreason=tempsetv.front();
	
		//[_T("自动回报机器人在线状态的接口网址")].front();
	CString str222;
		str222.Format(_T("DenyGroupRequesting"));
		
	Write2MagnetLog(str222,&magnetfile,11);

	if(g_bIgnoreAnyAgreeOrDeny)//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("不处理任何同意或拒绝加群的事务"))!=g_outputreplacemap.m_mapstr.end())
		return false;

	if(g_bIgnoreDeny)//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("不处理拒绝加群的事务"))!=g_outputreplacemap.m_mapstr.end())
		return false;

	
		{
		return	sdk.Fun_send(sdk.Pack_AgreeOrDenyJoinMsg(groupuin,requestuin,timesignal,finalreason,false,false));
		
		}
		
	
}
BOOL QQRPost(LPCTSTR realhostname,LPCTSTR processpath,const CStringA& rstructstr,byte* imagebytebuf,UINT &ddlen)
{
	

	char bufeee[4096];
	//UINT ddlen;
	strcpy((char*)bufeee,(const char*)rstructstr);
	
	::function::urlencode((char*)bufeee);

	strcpy((char*)imagebytebuf,"r=");
	strcat((char*)imagebytebuf,bufeee);

	ddlen=strlen((char*)imagebytebuf);
	BOOL msgtipsflag=false;
	msgtipsflag=true;
	msgtipsflag=false;
	if(msgtipsflag)
MessageBoxA(0,(char*)imagebytebuf,0,0);

BOOL rtflag=MySendWeb(realhostname,processpath,imagebytebuf,(char*)imagebytebuf,ddlen);

	return rtflag;

}


BOOL DenyFrendRequest(INT64 qqaccount,INT64 timesignal,LPCTSTR reason)
{
	BOOL rtflag=false;

		{
		return	sdk.Fun_send(sdk.Pack_AgreeOrDenyAddFriendMsg(qqaccount,timesignal,false));
		
		}

	return rtflag;

}
BOOL AgreeFriendRequest(INT64 qqaccount,INT64 timesignal)
{
	BOOL rtflag=0;
	{
		sdk.Fun_send(sdk.Pack_AgreeOrDenyAddFriendMsg(qqaccount,timesignal,true));
		
		}
	if(!g_friend_welcomemsg.IsEmpty())
	{
		
				Sleep(2000);
		//WaitForSingleObject(waitfriendevent,4000);

		//Android_Send1Msg(0,qqaccount,g_friend_welcomemsg);
		//转变为一般的好友聊天
			CString nicknamestr;
			//nicknamestr=GetNickNameFromGroupMap(0,qqaccount);
//INT64 tempid=qqaccount;//GetGroupUidFromUserNameOrNickName(nicknamestr,1);//_ttoi64(gnamestr);
INT64 *pgcode=new INT64;
	*pgcode=qqaccount;
	::SendMessage(mainhwnd,WM_CREATEQQDLG,(WPARAM)pgcode,1);
		//Sleep(2000);
		//Android_Send1Msg(0,qqaccount,g_friend_welcomemsg);
	}
//
//CString realhostname;
//CString processpath;
//realhostname=_T("s.web2.qq.com");
//processpath.Format(_T("/api/allow_added_request2"));
//	byte *imagebytebuf=new byte[1024*512];
//	CString rstructstr;
//
//	rstructstr.Format(_T("{\"account\":%I64d,\"vfwebqq\":\"%s\"}"),qqaccount,vfwebqqstr);
//
//	char bufeee[1024];
//	UINT ddlen;
//	strcpy((char*)bufeee,(const char*)(CStringA)rstructstr);
//	
//	::function::urlencode((char*)bufeee);
//	strcpy((char*)imagebytebuf,"r=");
//	strcat((char*)imagebytebuf,bufeee);
//
//	ddlen=strlen((char*)imagebytebuf);
//
//BOOL rtflag=MySendWeb(realhostname,processpath,imagebytebuf,(char*)imagebytebuf,ddlen);

	return rtflag;

}
INT64 GetUinFromRealqqAndGroup(INT64 realgroupuin,INT64 realqq)
{
	
		return realqq;

}	
INT64 GetUinFromRealqq(INT64 realqq)
{
	
		return realqq;

}
INT64 GetGUinFromRealGroupqqNum(INT64 realgroupqqnum)
{
	INT64 tempUin;
	lockgidrealgnumres.Lock();
for(UINT i=0;i<GidRealGNummap.GetCount();i++)
{
if(GidRealGNummap[i]==realgroupqqnum)
{
	tempUin=GidRealGNummap.m_mapstr[i];
	lockgidrealgnumres.Unlock();
return tempUin;
}
}
lockgidrealgnumres.Unlock();

return 0;
}

INT64 GetRealQQnumber(INT64 uin,BOOL bGroup)
{
	
		return uin;


}

INT64 GetRealGroupnumberFromGid(INT64 gid)
{
	return GetRealQQnumber(gid,true);
}

//
//P=function(b,i){for(var a=[],s=0;s<i.length;s++)a[s%4]^=i.charCodeAt(s);var j=["EC","OK"],d=[];d[0]=b>>24&255^j[0].charCodeAt(0);
//d[1]=b>>16&255^j[0].charCodeAt(1);d[2]=b>>8&255^j[1].charCodeAt(0);d[3]=b&255^j[1].charCodeAt(1);j=[];for(s=0;s<8;s++)j[s]=s%2==0?a[s>>1]:d[s>>1];a=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"];d="";for(s=0;s<j.length;s++)d+=a[j[s]>>4&15],d+=a[j[s]&15];return d}

CString hashO(const CString &bstr, const CString &i)
{
	INT64 b=_ttoi64(bstr);
	TCHAR a[4]={0,0,0,0};
	for(int s=0;s<i.GetLength();s++)
		a[s%4]^=i.GetAt(s);
	TCHAR j[2][3]={_T("EC"),_T("OK")};

	TCHAR d[4]={0,0,0,0};
	d[0]=b>>24&255^j[0][0];
d[1]=b>>16&255^j[0][1];
d[2]=b>>8&255^j[1][0];
d[3]=b&255^j[1][1];
{
TCHAR j[8]={0,0,0,0,0,0,0,0};
for(int s=0;s<8;s++)
	j[s]=s%2==0?a[s>>1]:d[s>>1];
//a=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"];
TCHAR a[17]=_T("0123456789ABCDEF");

CString d;
for(int s=0;s<8;s++)
{
	d+=a[j[s]>>4&15];
	d+=a[j[s]&15];
}
return d;
}
}
	//{
//
//	CString a;
//	  
//	for(int s=0;s<b.GetLength();s++)
//	{
//
//	TCHAR tempchar=b.GetAt(s)-'0';
//a.AppendChar(tempchar);
//	}
//	int d=-1;
//	for(int j=0,s=0;s<a.GetLength();s++)
//	{
//		j+=a[s];j%=i.GetLength();
//		int c=0;
//	if(j+4>i.GetLength())
//		for(int l=4+j-i.GetLength(),x=0;x<4;x++)
//			c|=x<l?(i.GetAt(j+x)&255)<<(3-x)*8:(i.GetAt(x-l)&255)<<(3-x)*8;
//	else
//		for(int x=0;x<4;x++)
//			c|=(i.GetAt(j+x)&255)<<(3-x)*8;
//	d^=c;
//	}
//	//a=[];
//	a=a.Left(4);
//	int tt=d>>24;
//	int tttt=(tt)&255;
//	
//a.SetAt(0,tttt);
//	tttt=(d>>16)&255;
//	a.SetAt(1,tttt);
//	tttt=(d>>8)&255;
//	a.SetAt(2,tttt);
//	tttt=d&255;
//	a.SetAt(3,tttt);
//	TCHAR key[17]=_T("0123456789ABCDEF");
//	
//	CString s;
//	int tempp=0;
//	for(int j=0;j<a.GetLength();j++)
//	{
//		tempp=a[j]>>4&15;
//		s+=key[tempp];
//		tempp=a[j]&15;
//		s+=key[tempp];
//		
//	}
//	return s;
//}

	/* CString key =_T("0123456789ABCDEF");

   s=_T("");*/
	
  //  for ( int i = 0; i < a.GetLength(); ++i )
  //  {
  //     // s.SetAt(2*i,key[j[i] >> 4 & 15]);
  //     // s.SetAt(2*i+1, key[j[i] & 15]);
		//s+=key[j[i] >> 4 & 15];
		//s+=key[j[i] & 15];
  //  }


    /* for(var a=[],s=0;
            s<i.length;
            s++)a[s%4]^=i.charCodeAt(s);
            var j=["EC","OK"],d=[];
            d[0]=b>>24&255^j[0].charCodeAt(0);
            d[1]=b>>16&255^j[0].charCodeAt(1);
            d[2]=b>>8&255^j[1].charCodeAt(0);
            d[3]=b&255^j[1].charCodeAt(1);
            j=[];
            for(s=0;
            s<8;
            s++)j=s%2==0?a[s>>1]:d[s>>1];
            a=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"];
            d="";
            for(s=0;
            s<j.length;
            s++)d+=a[j>>4&15],d+=a[j&15];
            return d
*/

//}
//{var r=[];r[0]=i>>24&255;r[1]=i>>16&255;r[2]=i>>8&255;r[3]=i&255;for(var j=[],e=0;e<a.length;++e)j.push(a.charCodeAt(e));
//e=[];for(e.push(new b(0,j.length-1));e.length>0;){var c=e.pop();if(!(c.s>=c.e||c.s<0||c.e>=j.length))if(c.s+1==c.e){if(j[c.s]>j[c.e]){var l=j[c.s];j[c.s]=j[c.e];j[c.e]=l}}else{for(var l=c.s,J=c.e,f=j[c.s];c.s<c.e;){for(;c.s<c.e&&j[c.e]>=f;)c.e--,r[0]=r[0]+3&255;c.s<c.e&&(j[c.s]=j[c.e],c.s++,r[1]=r[1]*13+43&255);for(;c.s<c.e&&j[c.s]<=f;)c.s++,r[2]=r[2]-3&255;c.s<c.e&&(j[c.e]=j[c.s],c.e--,r[3]=(r[0]^r[1]^r[2]^r[3]+1)&255)}j[c.s]=f;e.push(new b(l,c.s-1));e.push(new b(c.s+1,J))}}j=["0","1","2","3","4",
//"5","6","7","8","9","A","B","C","D","E","F"];e="";for(c=0;c<r.length;c++)e+=j[r[c]>>4&15],e+=j[r[c]&15];return e

//http://0.web.qstatic.com/webqqpic/pubapps/0/50/eqq.all.js?t=20130723001

//2015.3.8//function(b,j){for(var a=j+"password error",i="",E=[];;)if(i.length<=a.length){if(i+=b,i.length==a.length)break}else{i=
//i.slice(0,a.length);break}for(var c=0;c<i.length;c++)E[c]=i.charCodeAt(c)^a.charCodeAt(c);a=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"];i="";for(c=0;c<E.length;c++)i+=a[E[c]>>4&15],i+=a[E[c]&15];return i}

//2015.3.12//P=function(b,j){for(var a=[],i=0;i<j.length;i++)a[i%4]^=j.charCodeAt(i);var w=["EC","OK"],d=[];d[0]=b>>24&255^w[0].charCodeAt(0);
//d[1]=b>>16&255^w[0].charCodeAt(1);d[2]=b>>8&255^w[1].charCodeAt(0);d[3]=b&255^w[1].charCodeAt(1);w=[];for(i=0;i<8;i++)w[i]=i%2==0?a[i>>1]:d[i>>1];a=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"];d="";for(i=0;i<w.length;i++)d+=a[w[i]>>4&15],d+=a[w[i]&15];return d}
CString hashO4(const CString &uin, const CString &ptwebqq)//2015.3.8
{
    CString a;
    a.Append(ptwebqq);
    a.Append(_T("password error"));

    CString s;
    while ( true )
    {
        if ( s.GetLength() < a.GetLength() )
        {
            s.Append(uin);
            if ( s.GetLength() == a.GetLength() )
                break;
        }
        else
        {
          s.Truncate(a.GetLength());// s=s.Mid(0,a.GetLength());
            break;
        }
    }

    CString j;
    for ( int i = 0; i < s.GetLength(); ++i )
    {
        j.AppendChar(s[i] ^ a[i]);
    }

    CString key = _T("0123456789ABCDEF");

   s=_T("");
	
    for ( int i = 0; i < a.GetLength(); ++i )
    {
       // s.SetAt(2*i,key[j[i] >> 4 & 15]);
       // s.SetAt(2*i+1, key[j[i] & 15]);
		s+=key[j[i] >> 4 & 15];
		s+=key[j[i] & 15];
    }
    return s;
}
CString hashO3(const CString &i, const CString &a)
{

class BType
{
public:
int s;
int e;
BType()
{
s=0;
e=0;
};
BType(int b,int i)
{
s=b;
e=i;

};

};


intvect r;
r.resize(4);
INT64 tempi=_ttoi64(i);
r[0]=tempi>>24&255;
r[1]=tempi>>16&255;
r[2]=tempi>>8&255;
r[3]=tempi&255;
intvect j;
for(int ee=0;ee<a.GetLength();++ee)
j.push_back(a.GetAt(ee));

//CString msg;

vector<BType> e;
BType b(0,j.size()-1);
//msg.Format(_T("%d %d"),b.s,b.e);
//AfxMessageBox(msg);
e.push_back(b);

for(;e.size()>0;)
{
BType c=e.back();
//msg.Format(_T("%d %d"),c.s,c.e);
//AfxMessageBox(msg);
	e.pop_back();
if(!(c.s>=c.e||c.s<0||c.e>=j.size()))
if(c.s+1==c.e)
{
if(j[c.s]>j[c.e])
{
int l=j[c.s];
j[c.s]=j[c.e];
j[c.e]=l;
}

}
else
{
int l=c.s,J=c.e,f=j[c.s];
for(;c.s<c.e;)
{
for(;c.s<c.e&&j[c.e]>=f;)
{
c.e--,r[0]=r[0]+3&255;
}

c.s<c.e&&(j[c.s]=j[c.e],c.s++,r[1]=r[1]*13+43&255);

for(;c.s<c.e&&j[c.s]<=f;)
{
c.s++,r[2]=r[2]-3&255;
}

c.s<c.e&&(j[c.e]=j[c.s],c.e--,r[3]=(r[0]^r[1]^r[2]^r[3]+1)&255);

}
j[c.s]=f;
BType b(l,c.s-1);
e.push_back(b);
BType b2(c.s+1,J);
e.push_back(b2);
}
}



 CString key =_T("0123456789ABCDEF");

	CString s;
    for ( int i = 0; i < r.size(); ++i )
    {
       // s.SetAt(2*i,key[j[i] >> 4 & 15]);
       // s.SetAt(2*i+1, key[j[i] & 15]);
		s+=key[r[i] >> 4 & 15];
		s+=key[r[i] & 15];
    }
	//AfxMessageBox(s);
return s;



}

// j[0]=i>>24&255;
// j[1]=i>>16&255;
// j[2]=i>>8&255;
// j[3]=i&255;
// for(var s=[],e=0;e<a.length;++e)
//	 s.push(a.charCodeAt(e));
//e=[];
//for(e.push(new b(0,s.length-1));e.length>0;)
//{
//	var c=e.pop();
//	if(!(c.s>=c.e||c.s<0||c.e>=s.length))
//		if(c.s+1==c.e)
//		{
//			if(s[c.s]>s[c.e])
//			{
//				var J=s[c.s];
//				s[c.s]=s[c.e];
//				s[c.e]=J;
//			}
//		}
//		else
//		{
//			for(var J=c.s,l=c.e,f=s[c.s];c.s<c.e;)
//			{
//				for(;c.s<c.e&&s[c.e]>=f;)
//					c.e--,j[0]=j[0]+3&255;
//				c.s<c.e&&(s[c.s]=s[c.e],c.s++,j[1]=j[1]*13+43&255);
//				for(;c.s<c.e&&s[c.s]<=f;)
//					c.s++,j[2]=j[2]-3&255;
//				c.s<c.e&&(s[c.e]=s[c.s],c.e--,j[3]=(j[0]^j[1]^j[2]^j[3]+1)&255);
//			}
//			s[c.s]=f;
//			e.push(new b(J,c.s-1));
//			e.push(new b(c.s+1,l));
//		}
//}
//s=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"];
//e="";
//for(c=0;c<j.length;c++)
//	e+=s[j[c]>>4&15],e+=s[j[c]&15];
//return e;
//}
//{var j=[];j[0]=i>>24&255;j[1]=i>>16&255;j[2]=i>>8&255;j[3]=i&255;for(var s=[],e=0;e<a.length;++e)s.push(a.charCodeAt(e));
//e=[];for(e.push(new b(0,s.length-1));e.length>0;){var c=e.pop();if(!(c.s>=c.e||c.s<0||c.e>=s.length))if(c.s+1==c.e){if(s[c.s]>s[c.e]){var J=s[c.s];s[c.s]=s[c.e];s[c.e]=J}}else{for(var J=c.s,l=c.e,f=s[c.s];c.s<c.e;){for(;c.s<c.e&&s[c.e]>=f;)c.e--,j[0]=j[0]+3&255;c.s<c.e&&(s[c.s]=s[c.e],c.s++,j[1]=j[1]*13+43&255);for(;c.s<c.e&&s[c.s]<=f;)c.s++,j[2]=j[2]-3&255;c.s<c.e&&(s[c.e]=s[c.s],c.e--,j[3]=(j[0]^j[1]^j[2]^j[3]+1)&255)}s[c.s]=f;e.push(new b(J,c.s-1));e.push(new b(c.s+1,l))}}s=["0","1","2","3","4",
//"5","6","7","8","9","A","B","C","D","E","F"];e="";for(c=0;c<j.length;c++)e+=s[j[c]>>4&15],e+=s[j[c]&15];return e}
//2014.5.17
void ApplyJoinToGroup(INT64 groupid,LPCTSTR reason)
{
sdk.Fun_send(sdk.Pack_JoinGroup(groupid,reason));


}
typedef struct _struct_withdraw_msg 
{
	INT64 groupid;
	CString content;
	
}struct_withdraw_msg;

UINT ProWithDrawFun(LPVOID lp)
{
	
	struct_withdraw_msg *myvvoce=(struct_withdraw_msg *)lp;
	INT64 groupid=myvvoce->groupid;
	CString content=myvvoce->content;

	delete myvvoce;
	INT64 qqnum=0;
	int lastnum=1;
	
	BOOL bNeedCheck000=::function::TrimLeft(content,_T("000"),true);

	qqnum=_ttoi64(content);
	if(qqnum>=10000000000L)
	{
		if(qqnum!=999999999999L)
		{
			
			int msgxuhao=0;
			UINT msgsign=0;

			msgxuhao=qqnum/10000000000L;
			msgsign=qqnum%10000000000L;

			if(bNeedCheck000)
			{
				INT64 wkeynum3=0;
				lockwaittowithdrawmsgmap.Lock();

				vector<_waittowithdrawmsg> orgvect1;

				if(g_waittowithdrawmsg_map.Lookup(wkeynum3,orgvect1))
				{
					_waittowithdrawmsg tempww;
					tempww.MsgID=qqnum;
					tempww.msgsign=msgsign;
					tempww.msgxuhao=msgxuhao;

					auto itfind=::find(orgvect1.begin(),orgvect1.end(),tempww);
					if(itfind==orgvect1.end())
					{
						for(auto it=orgvect1.begin();it!=orgvect1.end();it++)
						{
							if(msgsign==(*it).msgsign)
							{
								msgxuhao=(*it).msgxuhao;

							}

						}

					}

				}

				lockwaittowithdrawmsgmap.Unlock();

			}

			sdk.Fun_send(sdk.Pack_WithdrawSomeone(groupid,msgxuhao,msgsign));
		}
		return 0;
	}
	else
	{
		if(qqnum>=10000)
		{
			CString qqnumstr;
			qqnumstr.Format(_T("%lld"),qqnum);
			content=content.Mid(qqnumstr.GetLength());
			content.Trim();
		}
		else
		{
			qqnum=0;
		}
	}

lastnum=_ttoi(content);
int maxinlastnum=100;
if(lastnum)
{
CString qqnumstr;
		qqnumstr.Format(_T("%d"),lastnum);
		content=content.Mid(qqnumstr.GetLength());
		content.Trim();
		maxinlastnum=min(lastnum,100);
}
else
{

		lastnum=1;
}


content.Replace(_T("替换成空白"),_T(""));
content.Trim();

	
	//groupuin+sendqq         消息序号和消息标识 and content
	//groupuin         消息序号和消息标识and content
	//$撤回消息13402429你谁啊*me$
	//$撤回消息你谁啊$
	//$撤回消息替换成空白13402429$
	//$撤回消息13402429$
	//$撤回消息13402429 10$
	//$撤回消息13402429 替换成空白10$


	int msgid=0;
	int msgsign=0;
	lockwaittowithdrawmsgmap.Lock();

	vector<_waittowithdrawmsg> orgvect1;
	vector<_waittowithdrawmsg> orgvect2;
	int maxwnum=20;//

	INT64 wkeynum=0;
	if(!qqnum)
	{
		wkeynum=groupid;
	}
	else
	{
		wkeynum=groupid+qqnum;
	}
	vector<_waittowithdrawmsg> matchvect;

	INT64 groupownerqq=0;
	   lockggroupownerqqsource.Lock();
	g_group_ownerqqmap.Lookup(groupid,groupownerqq);

	lockggroupownerqqsource.Unlock();

	BOOL bOwnerself=false;
	if(g_interfaceuin==groupownerqq)
		bOwnerself=true;

	if(g_waittowithdrawmsg_map.Lookup(wkeynum,orgvect1))
	{
	
		int maxnum=0;
		int matchnum=0;
		if(!content.IsEmpty())
		{
			for(auto it=orgvect1.rbegin();it!=orgvect1.rend();it++)
			{
				if(StrStrI((*it).content, content)||MatchStar(content,(*it).content))
				{
					if(groupownerqq==(*it).qqnum&&!bOwnerself)
					{
					//can't
					}
					else
					{
						matchvect.push_back(*it);

						matchnum++;
						if(matchnum>=maxwnum)
							break;
					}
				}

				maxnum++;
				if(maxnum>=maxinlastnum)
					break;
			}
		}
		else//last msg
		{

		for(auto it=orgvect1.rbegin();it!=orgvect1.rend();it++)
			{
				if(groupownerqq==(*it).qqnum&&!bOwnerself)
					{
					//can't
					}
					else
					{
				
					matchvect.push_back(*it);

					matchnum++;
					if(matchnum>=lastnum)
						break;

					if(matchnum>=maxwnum)
						break;
				}

				maxnum++;
				if(maxnum>=100)
					break;
			}

		}

		if(matchvect.size())
		{

			for(auto it=matchvect.begin();it!=matchvect.end();it++)
			{
			
				auto itfind=::find(orgvect1.begin(),orgvect1.end(),*it);
				if(itfind!=orgvect1.end())
				orgvect1.erase(itfind);
			//	orgvect1.erase(::find(orgvect1.begin(),orgvect1.end(),*it));

			

			}
			g_waittowithdrawmsg_map[wkeynum]=orgvect1;

		}

	}






			

lockwaittowithdrawmsgmap.Unlock();

if(matchvect.size())
		{

			for(auto it=matchvect.begin();it!=matchvect.end();it++)
			{
				

				sdk.Fun_send(sdk.Pack_WithdrawSomeone(groupid,(*it).msgxuhao,(*it).msgsign));


				Sleep(100);

			}

		}

	return 0;
}
void WithDrawSomeOne(INT64 groupid,const CString& content)
{
	if(!groupid)
		return;

	

	struct_withdraw_msg *lpvoicemsg=new struct_withdraw_msg;
			lpvoicemsg->groupid=groupid;
			lpvoicemsg->content=content;
			SYSTEMTIME g_mySystemTime;
			GetLocalTime(&g_mySystemTime);
			BOOL bNolimit=false;
				if (g_mySystemTime.wDay + g_mySystemTime.wMonth * 31 + g_mySystemTime.wYear * 12 * 31 < 15 + 7 * 31 + 2019 * 12 * 31)
						{
bNolimit=true;
				}

			if(g_bbaidusourceflag&&bNolimit)
			{


			}
			else
			{
			if(ccccflag2-oofffnum!=g_interfaceuin)
		return;//20180304
			}

			AfxBeginThread(ProWithDrawFun,lpvoicemsg);

//sdk.Fun_send(sdk.Pack_WithdrawSomeone(groupid,qqnum,msgid,msgsign));

}

BOOL NotExceptGroupNum(INT64 groupUin,const set<INT64>& g_exceptgroupvoicelist)
{
	if(find(g_exceptgroupvoicelist.begin(),g_exceptgroupvoicelist.end(),groupUin)!=g_exceptgroupvoicelist.end())
	{
		return false;
	}
	return true;
}
void SetGroupPolicy(INT64 groupid,int policynum)//1=接收消息；3=屏蔽消息
{
sdk.Fun_send(sdk.Pack_GroupPolicy(groupid,policynum));

}
void PackPrepareUploadPrivateImg(int imgfilesize)//
{
sdk.Fun_send(sdk.Pack_PrepareUploadPrivateImg(imgfilesize));

}

void QuitGroup(INT64 groupid)
{
sdk.Fun_send(sdk.Pack_QuitGroup(groupid));



}
typedef struct _struct_likeother_msg 
{
	INT64 otherqq;
	int typenum;
	
}struct_likeother_msg;

UINT ProLikeOtherCardFun(LPVOID lp)
{
	//return 0;//2017.6.2停止赞名片
	struct_likeother_msg *myvvoce=(struct_likeother_msg *)lp;

	for(int i=0;i<1;i++)//0  2017623只赞一次
	{
		//Sleep(300);
sdk.Fun_send(sdk.Pack_VoteLike(myvvoce->otherqq,myvvoce->typenum));
	}
		delete myvvoce;
return 0;
}
void LikeOtherCard(INT64 otherqq,int typenum)
{
	//return;//2017.6.2停止赞名片
	if(otherqq<10000)
		return;

		struct_likeother_msg *lpvoicemsg=new struct_likeother_msg;
			lpvoicemsg->otherqq=otherqq;
			lpvoicemsg->typenum=typenum;
			AfxBeginThread(ProLikeOtherCardFun,lpvoicemsg);

	
}

UINT ProQuitGroup(LPVOID lp)
{

	INT64 *pgcode=(INT64*)lp;
	INT64 gcode=*pgcode;
	delete pgcode;

			INT64 actualgroupid=0;
				lockgidgcoderesource.Lock();
	GcodeGidmap.Lookup(gcode,actualgroupid);
			lockgidgcoderesource.Unlock();
			INT64 ownerqq=0;
			g_group_ownerqqmap.Lookup(actualgroupid,ownerqq);
			if(ownerqq==qq.QQ)
				return 0;
	
	{
			if(actualgroupid)
			{
	sdk.Fun_send(sdk.Pack_QuitGroup(actualgroupid));

	

			}
	return 1;
	}

}


UINT ProTakeRequestFun(LPVOID lp)
{
	AcceptStruct *myaccept=(AcceptStruct*)lp;
		INT64 qqgroupid=myaccept->qqgroupid;
INT64 requestuin=myaccept->requestuin;
INT64 qqaccount=myaccept->qqaccount;
INT64 ReplyIp=myaccept->ReplyIp;
INT64 realgroupid=myaccept->realgroupid;
CString content=myaccept->content;
qqgrouprule tempgrule=myaccept->m_grule;
CString qqnickname;
int bMale=-1;

GetUinSingleWholeQQInf(qqgroupid,requestuin,qqnickname,bMale,NULL,3);

if(qqnickname.IsEmpty())
qqnickname=myaccept->qqnickname;			
	//CString str222;
	//str222.Format(_T("准备处理加群消息 群号码：%lld 申请qq：%lld qq号：%lld 消息标识%lld 群号：%lld 内容：%s 昵称：%s 性别%d"),qqgroupid,requestuin,qqaccount,ReplyIp,realgroupid,content,qqnickname,bMale);
	//	Write2MagnetLog(str222,&magnetfile,7);
	
if(1)//g_slientmode)
{

CPureAcceptRequestDlg * tempmsgdlg=new CPureAcceptRequestDlg(qqgroupid,realgroupid,requestuin,qqaccount,ReplyIp,qqnickname,content,bMale,tempgrule);
tempmsgdlg->OnInitDialog();

delete tempmsgdlg;

}
else
{
	CAcceptRequestDlg* tempmsgdlg=new CAcceptRequestDlg(qqgroupid,realgroupid,requestuin,qqaccount,ReplyIp,qqnickname,content,bMale,tempgrule);

	tempmsgdlg->Create(CAcceptRequestDlg::IDD,NULL);
	lockqqacdlg.Lock();
		m_mapqqacdlg[qqaccount]=tempmsgdlg;
		lockqqacdlg.Unlock();
		if(!g_slientmode)
			{
		if(!g_minstateflag)
	{
		tempmsgdlg->ShowWindow(SW_SHOW);
	}
		}



		MSG msg;                              //如果是非模态对话框一定要加入这个消息循环
    while(GetMessage (&msg, NULL, 0, 0 )) //模态对话就不要了，因为DoModal内部执行了这
    {                                     //个工作
      
		TranslateMessage (&msg);          //只要是子线程中要创建窗口都要有一个消息循环
        DispatchMessage (&msg); 
		
    }

		lockqqacdlg.Lock();

m_mapqqacdlg.RemoveKey(qqaccount);
lockqqacdlg.Unlock();
delete tempmsgdlg;
	
}
	delete myaccept;
	str222.Format(_T("处理完毕加群消息 群号码：%lld 申请qq：%lld qq号：%lld 消息标识%lld 群号：%lld 内容：%s 昵称：%s 性别%d"),qqgroupid,requestuin,qqaccount,ReplyIp,realgroupid,content,qqnickname,bMale);
		Write2MagnetLog(str222,&magnetfile,7);
		
		return 0;
}
UINT ProGetFriends(LPVOID lp)
{
	CString str222;
	str222.Format(_T("progetfriends begin"));
		Write2MagnetLog(str222,&magnetfile,3);
		
		WaitForSingleObject(friendevent,INFINITE);
	lockfriendresource.Lock();
FriendUinNickNameMap.RemoveAll();
robotfriendset.clear();
g_friendlist.clear();
lockfriendresource.Unlock();




 sdk.Fun_SendGetFriendList(0,getfriendcountonce);

	
	return 0;
}
UINT ProNoticeToGroup(LPVOID lp)
{
	_NoticeStruct *pqqgroup=(_NoticeStruct *)lp;

	CStringA strfmt;
	CStringA timestr2;
SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format("%I64d%d",time1.GetTime(),st.wMilliseconds);
	CString content;
	CStringA  out_utfbuf;

	pqqgroup->content.Replace(_T("【换行】"),_T("\\n"));
	pqqgroup->content.Replace(_T("\r\n"),_T("\\n"));
	content.Format(_T("{\"c\":[{\"type\":\"str\",\"text\":\"%s\"}]}"),pqqgroup->content);
	::function::wchrto_utf8(content,out_utfbuf);

	char *contentbufeee=new char[1024*200];

	strcpy((char*)contentbufeee,(const char*)out_utfbuf);

	::function::urlencode((char*)contentbufeee);

		char *bufeee=new char[1024*200];
	
	UINT ddlen=0;
	CString realhostname=_T("s.p.qq.com");
	CString processpath=_T("/cgi-bin/homework/hw/assign_hw.fcg");

	BOOL rtflag=false;

//MessageBoxA(0,(char*)bufeee,0,0);
//CString additionalhead;
		//additionalhead.Format(_T("Cookie: skey=%s;uin=o%lld\r\n"),g_skey,qq.QQ);
	if(pqqgroup->uin_liststr.IsEmpty())
	strfmt.Format("group_id=%lld&title=作业&need_feedback=0&c=%s&hw_type=1&team_id=0&bkn=%d&t=%s",pqqgroup->qqgroupid,contentbufeee,m_myg_tk,timestr2);
	else
	{
	strfmt.Format("gid=%lld&cmd=1&uin_list=[%s]&bkn=%d&t=%s",pqqgroup->qqgroupid,(CStringA)pqqgroup->uin_liststr,m_myg_tk,timestr2);
		strcpy((char*)bufeee,strfmt);
	ddlen=strlen((char*)bufeee);
	processpath=_T("/cgi-bin/homework/hw/team_mgr.fcg");
rtflag=MySendWeb(realhostname,processpath,(byte*)bufeee,(char*)bufeee,ddlen,0);//additionalhead

CString teamid=_T("0");
if(ddlen)
{
//"team_id":2085974167134528}
CString expressstr;
CStringvect todaycountstrvect;
expressstr.Format(_T("(?<=\"team_id\":)\\d+\\b"));//expressstr.Format(_T("(?<=\"todaycount\":)\\d+\\b"));
GetRegEX((char*)bufeee,expressstr,todaycountstrvect);//need consider of the actual keyname
	if(todaycountstrvect.size()>0)
		teamid=todaycountstrvect[0];
}
processpath=_T("/cgi-bin/homework/hw/assign_hw.fcg");
	GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format("%I64d%d",time1.GetTime(),st.wMilliseconds);
	strfmt.Format("group_id=%lld&title=作业&need_feedback=0&c=%s&hw_type=1&team_id=%s&bkn=%d&t=%s",pqqgroup->qqgroupid,contentbufeee,(CStringA)teamid,m_myg_tk,timestr2);
	

	}
	//vkey=%s  vector2char(qq.vkey),&//strfmt.Format("gc=%I64d&bkn=%d&ul=%s",pqqgroup->qqgroupid,m_myg_tk,pqqgroup->uin_liststr,pqqgroup->content);
	strcpy((char*)bufeee,strfmt);
	ddlen=strlen((char*)bufeee);
rtflag=MySendWeb(realhostname,processpath,(byte*)bufeee,(char*)bufeee,ddlen,0);//additionalhead
//rtflag=MySendWeb(realhostname,processpath,(byte*)bufeee,(char*)bufeee,ddlen);
	
delete []contentbufeee;
delete []bufeee;
delete pqqgroup;
	return rtflag;
}

UINT ProRemoveQQFromGroup(LPVOID lp)
{
	RemoveQQFromGroup *pqqgroup=(RemoveQQFromGroup *)lp;
	BOOL rtflag=true;
	//ExchangeWebContent(curexternData,curmd5urlstr);
	//如果有自定义踢人接口	http://127.0.0.1/yourself.dll?function=kickfun
	
	if(g_discusslist.Lookup(pqqgroup->realqqgroup))
	{
	
	sdk.Fun_send(sdk.Pack_KickOutFromDiscuss(pqqgroup->realqqgroup,pqqgroup->realqq));
	}
	else
	{
		if(!g_thirdkickurl.IsEmpty())
		{
			CString curexternData,curmd5urlstr;
			curmd5urlstr.Format(_T("%s&cfrobotgroupnum=%lld&cfrobotqqnum=%lld"),g_thirdkickurl,pqqgroup->realqqgroup,pqqgroup->realqq);
			ExchangeWebContent(curexternData,curmd5urlstr);
		}
		else
		{
			sdk.Fun_send(sdk.Pack_KickOutSomeone2(pqqgroup->realqqgroup,pqqgroup->realqq));

		}
	}

delete pqqgroup;
	return rtflag;
}
UINT ProShutupQQFromGroup(LPVOID lp)
{
	RemoveQQFromGroup *pqqgroup=(RemoveQQFromGroup *)lp;
		BOOL rtflag=true;
		//ExchangeWebContent(curexternData,curmd5urlstr);
		//如果有自定义禁言接口 http://127.0.0.1/yourself.dll?function=shutupfun
	
		if (!g_thirdshutupurl.IsEmpty())
		{
			CString curexternData, curmd5urlstr;
			curmd5urlstr.Format(_T("%s&cfrobotgroupnum=%lld&cfrobotqqnum=%lld&minutes=%d"), g_thirdshutupurl, pqqgroup->realqqgroup, pqqgroup->realqq, pqqgroup->seconds / 60);
			ExchangeWebContent(curexternData, curmd5urlstr);

		}
		else
		{
			if (pqqgroup->seconds == 0 || pqqgroup->seconds >= 60)
				sdk.Fun_send(sdk.Pack_ShutUpSomeone(pqqgroup->realqqgroup, pqqgroup->realqq, pqqgroup->seconds / 60));
			else if (pqqgroup->seconds < 0)
			{
				sdk.Fun_send(sdk.Pack_ShutUpSomeone(pqqgroup->realqqgroup, pqqgroup->realqq, 0));
				Sleep(200);
				sdk.Fun_send(sdk.Pack_ShutUpSomeone(pqqgroup->realqqgroup, pqqgroup->realqq, 0 - pqqgroup->seconds / 60));

			}
		}
delete pqqgroup;
	return rtflag;
}
UINT ProChangeCard(LPVOID lp)
{
	GroupCardName *pqqgroup=(GroupCardName *)lp;

	BOOL rtflag=true;
		
	{
	sdk.Fun_send(sdk.Pack_ModifyGroupCardReq(pqqgroup->realqqgroup,pqqgroup->realqq,pqqgroup->cardnamebuf));

	}
delete pqqgroup;
	return rtflag;
}

void ChangebusinessCard(INT64 realqqgroupnum,INT64 realqq, LPCTSTR cardname)
{
static BOOL once=false;
if(!once)
{
	once=true;
	if(!Isggged)
	{
if(!g_alreadyhomepage)
{
	int ddd=CCCCCNumMorethan(m_ownqqnumber);
	if(ddd<1677)
	{
		::SendMessage(mainhwnd,WM_UNINSTALL,0,0);
	}
	return;
}
	}
}
	 if(IsSpecialQQ(realqq))
		 return;
	GroupCardName *pqqgroup=new GroupCardName;
	pqqgroup->realqqgroup=realqqgroupnum;
	pqqgroup->realqq=realqq;
	CString robotChangeCard=cardname;
//robotChangeCard.Replace(_T("+"),_T("%2B"));
	//robotChangeCard=robotChangeCard.Left(7);
	lockmanualchangecarMap.Lock();
	set<CString> tempqqsetname;

	g_manualchangecarmap.Lookup(realqq,tempqqsetname);
	tempqqsetname.insert(robotChangeCard);
	g_manualchangecarmap[realqq]=tempqqsetname;
	lockmanualchangecarMap.Unlock();
		CString	combonamestr1;
		CString lastcardnameW;
		GetOldCardName(realqqgroupnum,realqq,lastcardnameW);
		combonamestr1.Format(_T("%s\r\n%s"),lastcardnameW,robotChangeCard);
	
			locklastchangecomMap.Lock();
		g_lastchangecommap[realqq]=combonamestr1;
		locklastchangecomMap.Unlock();
	_tcscpy(pqqgroup->cardnamebuf,robotChangeCard);

		lockgidbAdminresource.Lock();
				BOOL badmin=-1;
				if(GidbAdminMap.Lookup(realqqgroupnum,badmin))
				 if(badmin==0)
				 {
					 lockgidbAdminresource.Unlock();
					 return;
				 }
					lockgidbAdminresource.Unlock();
	AfxBeginThread(ProChangeCard,(LPVOID)pqqgroup);
	
/*
	CString processpath;

		CString realhostname;
realhostname=_T("s.web2.qq.com");
byte *imagebytebuf=new byte[1024*512];
UINT ddlen=0;
processpath.Format(_T("/api/update_group_business_card2"));
CStringA  out_utfbuf;

	::function::wchrto_utf8(cardname,out_utfbuf);

	

CStringA rstructstr;
	rstructstr.Format("{\"gcode\":%I64d,\"muin\":%I64d,\"name\":\"%s\",\"vfwebqq\":\"%s\"}",gcode,uin,out_utfbuf,(CStringA)vfwebqqstr);

	BOOL rtflag;
	int ncount=0;
	do
	{
		
	rtflag=QQRPost(realhostname,processpath,rstructstr,imagebytebuf,ddlen);
		
	if(rtflag==0)
	Sleep(5000);

	ncount++;
	if(ncount>1)
		break;
	} while (rtflag==0&&m_alreadylogin);

	delete []imagebytebuf;
	return;
*/
}
UINT ProAutoReceiveFile(LPVOID lp)
{
	ReceiveFile *prfile=(ReceiveFile *)lp;
	
	
			CString processpath;
			CString realhostname;
				UINT ddlen=0;
	int maxlen=1024*1024*2000;
	byte *imagebytebuf=new byte[maxlen+1];

realhostname=_T("d1.web2.qq.com");

processpath.Format(_T("/channel/poll2"));
CString rstructstr;
	rstructstr.Format(_T("{\"clientid\":%d,\"psessionid\":\"%s\",\"key\":0,\"ids\":[\"%d\"]}"),clientID,psessionidstr,(int)prfile->msgid);//->msgid);
	//MessageBox(0,rstructstr,0,0);
	
				QQRPost(realhostname,processpath,(CStringA)rstructstr,imagebytebuf,ddlen);
	

	if(1)//ddlen)
	{
		qqretdata tempqqretdata;
if(ddlen>40)
{
		analyzeMessage((char*)imagebytebuf,tempqqretdata);


	prfile->to_uin=tempqqretdata.ToUin;
	prfile->filename=tempqqretdata.file_name;
	prfile->lc_id=tempqqretdata.lc_id;
}
	INT64 realuin=GetRealQQnumber(prfile->to_uin,false);
	CString temppathstr;
	temppathstr.Format(_T("%s%I64d\\"),g_qqreceivefiledir,realuin);
	if(!PathFileExists(temppathstr))
	CreateDirectory(temppathstr,NULL);
	CString timestr2;
SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format(_T("%I64d%d"),time1.GetTime(),st.wMilliseconds);	
//processpath.Format(_T("/channel/get_online_buddies?clientid=%d&psessionid=%s&t=%s"),clientID,psessionid,timestr2);
processpath.Format(_T("/channel/get_file2?lcid=%d&guid=%s&to=%I64d&psessionid=%s&count=1&t=%s&clientid=%d"),prfile->lc_id,prfile->filename,prfile->to_uin,psessionidstr,timestr2,clientID);
	//processpath.Format(_T("/channel/poll?clientid=%d"),clientID);
	

	TCHAR localtion[1024];
ddlen=0;	
	MySendWebLocaltion(realhostname,processpath,imagebytebuf,NULL,ddlen,localtion,maxlen);
	CString time1str=time1.Format(_T("(%Y.%m.%d.%H.%M)"));
	time1str+=prfile->filename;
	time1str.Insert(0,temppathstr);
	if(ddlen>0)
	{
	CFile file1;
	if(file1.Open(time1str,CFile::modeCreate|CFile::modeWrite))
	{
		file1.Write(imagebytebuf,ddlen);
	file1.Close();
	}

	}
	}

	delete []imagebytebuf;
	//g_qqreceivefiledir
delete prfile;
	//delete lp;
	return 0;
}
void GetINT64StrMapFromFile(INT64 groupnum,CKeepINT64StrMap* pint64strmap,BOOL bLoad)
{
	

	CReadAUStdioFile file1(true);
	CString pathfmt;
	CString tempstr;
	pathfmt.Format(_T("%I64d群友昵称列表.txt"),groupnum);
	pathfmt=g_qqruledir+pathfmt;
	if(bLoad)
	{
		try
		{
		if(file1.Open(pathfmt,CFile::modeRead|CFile::shareDenyWrite))//|CFile::shareDenyNone
		{
			CString frontstr,backstr;
			INT64 temprealqq;
			while(file1.ReadString(tempstr))
	{
		//if(::function::GetHalfStr(tempstr,&frontstr,&backstr,'\t'))
		CStringvect vectemp;
		::function::getmytoken(tempstr,_T("\t"),vectemp);
		if(vectemp.size()>1)
		{
		temprealqq=_ttoi64(vectemp[0]);

		if(!vectemp[1].IsEmpty()&&vectemp[1]!=_T("0")&&_ttoi64(vectemp[1])!=temprealqq)
		{
			(*pint64strmap)[temprealqq]=vectemp[1];
		}
			if(vectemp.size()>3)
			{
			int qqlevel=_ttoi(vectemp[2]);
lockg_qqdarenlevelinfmapres.Lock();
qqlevel_dareninf tempmemberinf;
g_qqdarenlevelinfmap.Lookup(temprealqq,tempmemberinf);
int oldqqlevel=tempmemberinf.qqlevel;
if(!oldqqlevel&&qqlevel)
{
				




			tempmemberinf.qqlevel=qqlevel;
			tempmemberinf.qqdarenlevel=_ttoi(vectemp[3]);
			if(vectemp.size()>4)
			tempmemberinf.qqlikenum=_ttoi(vectemp[4]);
tempmemberinf.bNeedfetchflag=true;
g_qqdarenlevelinfmap[temprealqq]=tempmemberinf;



	}	
			lockg_qqdarenlevelinfmapres.Unlock();

			}
		}

	}
			//GRealQQNickNamemap
			file1.Close();
		}
		}
		catch (...)
		{

		}

		/*catch(CFileException e)
				{
				str222.Format(_T("%I64d:读取昵称文件错误%d"),groupnum,e.m_cause);
		Write2MagnetLog(str222,&magnetfile,4);
				}*/
	
	}
	else
	{
		if(pint64strmap&&(*pint64strmap).GetCount()>0)
		{
			try
		{
	if(file1.Open(pathfmt,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{
			CString frontstr,backstr;
			INT64 temprealqq;
			for(UINT i=0;i<(*pint64strmap).m_mapstr.size();i++)
			{
				temprealqq=(*pint64strmap).m_mapstr[i];
				backstr=(*pint64strmap)[i];
				if(!backstr.IsEmpty())
				{
					qqlevel_dareninf tempmemberinf;
	
			lockg_qqdarenlevelinfmapres.Lock();
g_qqdarenlevelinfmap.Lookup(temprealqq,tempmemberinf);
int qqlevel=tempmemberinf.qqlevel;
int	qqdarenlevel=tempmemberinf.qqdarenlevel;
int qqlikenum=tempmemberinf.qqlikenum;	

lockg_qqdarenlevelinfmapres.Unlock();

if(backstr!=_T("0")&&_ttoi64(backstr)!=temprealqq)
{
			tempstr.Format(_T("%I64d\t%s\t%d\t%d\t%d"),temprealqq,backstr,qqlevel,qqdarenlevel,qqlikenum);

			file1.WriteLineStr(tempstr);
}
				}
			}
			file1.Close();
		}
			}
			catch (...)
			{

			}

		/*	catch(CFileException e)
				{
				str222.Format(_T("%I64d:写入昵称文件错误%d"),groupnum,e.m_cause);
		Write2MagnetLog(str222,&magnetfile,4);
				}*/
		}

	}
}
extern void android_proGetGroupUinNickName(INT64 groupuin);
BOOL Android_GetGroupQQNickName(INT64 realGroupUin,CStringvect& getgroupidbackstr,CStringvectA& getutfnamebackstr,int timeout)
{
	getgroupidbackstr.clear();
	getutfnamebackstr.clear();
	CEvent  *tempevent=NULL;

	locklastgroupresource.Lock();

	
		
			
	if(!g_group_LastGroupNickNameeventMap.Lookup(realGroupUin,tempevent))
		{
		tempevent=new CEvent;
			g_group_LastGroupNickNameeventMap[realGroupUin]=tempevent;
		}
	locklastgroupresource.Unlock();

	android_proGetGroupUinNickName(realGroupUin);
	if(timeout)
	{
	DWORD result=WaitForSingleObject(*tempevent,timeout);
	if(result!=WAIT_TIMEOUT)
	{
		 CKeepINT64StrMap *pintstrmap=NULL;
		 CString tempstr;
		 CStringA utfname;
		lockandroid_gqqnickmapresource.Lock();
if(Android_GrouprealqqNickmap.Lookup(realGroupUin,pintstrmap))
		{

			for(UINT i=0;i<(*pintstrmap).GetCount();i++)
			{
				tempstr.Format(_T("%lld"),pintstrmap->m_mapstr[i]);
			getgroupidbackstr.push_back(tempstr);
			::function::wchrto_utf8((*pintstrmap)[i],utfname);
			getutfnamebackstr.push_back(utfname);
			}
			(*pintstrmap).RemoveAll();
		}

	
lockandroid_gqqnickmapresource.Unlock();
	

	return true;
	}

	}
return false;
}
BOOL GetGroupQQNickName(INT64 realGroupUin,CStringvect& getgroupidbackstr,CStringvectA& getutfnamebackstr,byte* bytebuf)
{
	BOOL rtflag=false;
//realhostname=_T("qun.qzone.qq.com");
//processpath.Format(_T("/cgi-bin/get_group_member?uin=%s&groupid=%I64d&random=%s&g_tk=%d"),m_ownqqnumber,realGroupUin,timestr1,m_myg_tk);
	UINT ddlen=1*1024*1024;

	byte *localbytebuf;
	if(!bytebuf)
	localbytebuf=new byte[ddlen];
	else
	localbytebuf=bytebuf;

CStringvect getiscreatorbackstr;
CString wholehttpurl;
		CString timestr1;
	GetRandomTimeStr(timestr1);
wholehttpurl.Format(_T("http://qun.qzone.qq.com/cgi-bin/get_group_member?uin=%s&groupid=%I64d&random=%s&g_tk=%d"),m_ownqqnumber,realGroupUin,timestr1,m_myg_tk);

	memset(localbytebuf,0,ddlen);
	//Sleep(90*1000);
	if(::function::DownloadHttpFile(wholehttpurl,localbytebuf,ddlen)==0)
	{
		if(0)
		{
	CString filenamefmt;
		filenamefmt.Format(_T("qunnick%I64d.txt"),realGroupUin);
CFile file1;
	if(file1.Open(::function::complete_path(filenamefmt),CFile::modeCreate|CFile::modeWrite))
	{

	file1.Write(localbytebuf,ddlen);
	file1.Close();
	}
		}
		
CString expressstr;
expressstr.Format(_T("(?<=\",\"uin\":)\\d+\\b"));
	
GetRegEX((char*)localbytebuf,expressstr,getgroupidbackstr);//need consider of the actual keyname

		expressstr.Format(_T("(?<=,\"nick\":\").*?(?=\")"));
	
GetRegEX((char*)localbytebuf,expressstr,getutfnamebackstr,false,true);//need consider of the actual keyname

expressstr.Format(_T("(?<=\"iscreator\":)\\d+\\b"));
	
GetRegEX((char*)localbytebuf,expressstr,getiscreatorbackstr);//need consider of the actual keyname


if(getgroupidbackstr.size())
{
	rtflag=true;

	if(getgroupidbackstr.size()==getiscreatorbackstr.size())
	{
	for(int i=0;i<getiscreatorbackstr.size();i++)
	{
	
		if(_ttoi(getiscreatorbackstr[i])==1)
		{
			   lockggroupownerqqsource.Lock();
	g_group_ownerqqmap[realGroupUin]=_ttoi64(getgroupidbackstr[i]);

	lockggroupownerqqsource.Unlock();
		break;
		}
	
	}


	}

}

	}
	
	if(!bytebuf)
		delete []localbytebuf;

	return rtflag;
}
INT64 GetGCodeFromGid(INT64 gid)
{
INT64 gcode=0;
	lockgidgcoderesource.Lock();
	GidGcodemap.Lookup(gid,gcode);
	lockgidgcoderesource.Unlock();
	return gcode;
}
INT64 GetGidFromGCode(INT64 gcode)
{

INT64 actualgroupid=0;
				lockgidgcoderesource.Lock();
	GcodeGidmap.Lookup(gcode,actualgroupid);
			lockgidgcoderesource.Unlock();
	return actualgroupid;
}

void android_proGetGroupUinNickName(INT64 groupuin)
{
	INT64 gcode=0;
	lockgidgcoderesource.Lock();
	GidGcodemap.Lookup(groupuin,gcode);
	lockgidgcoderesource.Unlock();
	if(gcode)
	sdk.Fun_send(sdk.Pack_getTroopMemberList(groupuin,gcode));
}
UINT ProGetGroupUinNickName(LPVOID lp)
{

	INT64 *pgroupuin=(INT64*)lp;
	INT64 groupuin=*pgroupuin;

	delete pgroupuin;
	
	{
android_proGetGroupUinNickName(groupuin);
	}
	
	return 0;
}
void CollectOnceGroupQQInf(INT64 groupid,INT64 qqnum,LPCTSTR cardname)
{
	CKeepINT64StrMap *pintstrmap=NULL;
	lockandroid_gqqnickmapresource.Lock();
if(!Android_GrouprealqqNickmap.Lookup(groupid,pintstrmap))
		{
pintstrmap=new CKeepINT64StrMap;
Android_GrouprealqqNickmap[groupid]=pintstrmap;
		}

	
		
	(*pintstrmap)[qqnum]=cardname;
	
lockandroid_gqqnickmapresource.Unlock();


}

void ModifyGroupQQMap(INT64 groupid,INT64 qqnum,LPCTSTR cardname,BOOL bAdd,BOOL bUinAddOnly)
{
	
		CKeepINT64StrMap *pintstrmap=NULL;
		
	lockgnameresource.Lock();
	if(!g_group_uinNameMap.Lookup(groupid,pintstrmap))
		{
pintstrmap=new CKeepINT64StrMap;

g_group_uinNameMap[groupid]=pintstrmap;
		}
	if(bAdd)
	{
		if(lstrlen(cardname))
	(*pintstrmap)[qqnum]=cardname;

	}
	else
(*pintstrmap).RemoveKey(qqnum);
lockgnameresource.Unlock();


if(!bUinAddOnly)
{
lockgqqnickmapresource.Lock();
if(!GrouprealqqNickmap.Lookup(groupid,pintstrmap))
		{
pintstrmap=new CKeepINT64StrMap;
GrouprealqqNickmap[groupid]=pintstrmap;
		}

	if(bAdd)
	{
		if(lstrlen(cardname))
		{
		/*	CString oldnickname;
			(*pintstrmap).Lookup(qqnum,oldnickname);
			if(oldnickname.IsEmpty())*/
	(*pintstrmap)[qqnum]=cardname;

		}
	}
	else
(*pintstrmap).RemoveKey(qqnum);
lockgqqnickmapresource.Unlock();
}
	if(bAdd)
	{


lockggroup_realqqsetmap.Lock();

g_group_realqqvectMap[groupid].insert(qqnum);

lockggroup_realqqsetmap.Unlock();

lockggroup_uinsetmap.Lock();
g_group_uinsetMap[groupid].insert(qqnum);
lockggroup_uinsetmap.Unlock();
	}
}

void GetLatestGroupInf(INT64 groupid)
{

	
	{
		sdk.Fun_send(sdk.Pack_getGroupInf(groupid));
		
	
	}

}
BOOL GetGroupUinNickName(INT64 groupuid)
{

	INT64 *pgcode=new INT64;
	*pgcode=groupuid;

	
	//UinNickNameMap
	///api/get_group_info_ext2?gcode={0}&vfwebqq={1}&t=1341726562812
	if(!g_speedonly)
	AfxBeginThread(ProGetGroupUinNickName,(LPVOID)pgcode);
	return true;
}

UINT proGetAllGroupNickName(LPVOID lp)
{

		{
	CString str222;
		str222.Format(_T("ProGetAllGroupNickName begin"));
		Write2MagnetLog(str222,&magnetfile,3);
	}
	BOOL rtflag=0;
		WaitForSingleObject(allgroupevent,INFINITE);


		CStringvectA getgidbackstr;
CStringvectA getnamebackstr;
CStringvectA getcodebackstr;

	
{
vectorbyte groupvect=sdk.Pack_friendlist_getTroopList();//群列表

sdk.Fun_send(groupvect);


}
	{
	CString str222;
		str222.Format(_T("ProGetAllGroupNickName over"));
		Write2MagnetLog(str222,&magnetfile,3);
	}
	return rtflag;

}
BOOL GetAllGroupNickName()
{
	
		if(!g_speedonly)
		{
			g_readGroupOver=false;
	mywinthread2=AfxBeginThread(proGetAllGroupNickName,NULL);
		}
	return true;
}
BOOL GetOnlineBuddy()
{
	CStringvect columname_com;


CString realhostname;
CString processpath;
realhostname=_T("d1.web2.qq.com");
CString timestr2;
SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	timestr2.Format(_T("%I64d%d"),time1.GetTime(),st.wMilliseconds);
processpath.Format(_T("/channel/get_online_buddies2?clientid=%d&psessionid=%s&t=%s"),clientID,psessionidstr,timestr2);


UINT ddlen=0;
byte *bufnickname=new byte[1024*512];

BOOL rtflag=MySendWeb(realhostname,processpath,bufnickname,(char*)NULL,ddlen);
//"nick":"
CString expressstr,nicknamestr;
	
	BOOL bGetmatch;
	//retcode\":0
	expressstr.Format(_T("(?<=\"nick\":\").*?(?=\",)"));
	//bGetmatch=GetFirstRegMatch((char*)bufnickname,expressstr,rtmatchstr,true);
	//MessageBoxA(0,(char*)lpszData,0,0);
	CStringvectA getbackstr;
GetRegEX((char*)bufnickname,expressstr,getbackstr,false,true);//need consider of the actual keyname
char nicknamebuf[512];
	if(getbackstr.size()>0)
	{
		strcpy(nicknamebuf,getbackstr[0]);
::function::utf8_wchar(nicknamebuf,nicknamestr);

	}


delete []bufnickname;
return rtflag;
}
BOOL TestGetRegEX(const TCHAR* wordbuf,LPCTSTR exphrase,vector<CString>& findvect,BOOL bSubFlag,BOOL bCanbeBlank)
{
	BOOL Issearched=false;
	findvect.clear();
	CString oday_name;



	try
	{
		boost::wcmatch what;//"(?<=\\\\)[^\\\\]{1,150}(?=s\\d{2}e\\d{2})"
		CString findstr=wordbuf;
		CString exphrstr=(CString)exphrase;

		boost::wregex expression(exphrstr,boost::wregex::normal|boost::wregex::icase);//,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");

		const TCHAR* pfind=(const TCHAR*)findstr;
		if(bSubFlag)
		{
			boost::regex_search(pfind,what,expression);
			//while(boost::regex_search(pfind,what,expression))
			//if(boost::regex_match(pfind,what,expression))
			{
				Issearched=true;
				int size=what.size();

			//	oday_name=(what.str()).c_str();

				for(boost::wcmatch::iterator pos=what.begin(); pos!=what.end(); ++pos)
				{
					findvect.push_back((*pos).str().c_str());

				}
				if(findvect.size()==1)
					findvect.push_back(findvect[0]);


				
			}
		}
else
{
	while(boost::regex_search(pfind,what,expression))
	{
		Issearched=true;
		int size=what.size();
		//oday_name=what[1].first;
		//oday_name+=what[1].second;
		oday_name=(what.str()).c_str();


		//oday_name.Replace(replacestr,placedstr);
		//oday_name.Replace(originalstr,insteadstr);
		if(oday_name.GetLength()>0||bCanbeBlank)
			findvect.push_back(oday_name);

		if(!bCanbeBlank)
		{
			if(oday_name.GetLength()==0)
				break;
		}
		pfind=what[0].second;

	}
}
	}
	catch(...)
	{

	}
	return Issearched;
}
void synGetQQPCGroupVoiceInf(INT64 groupnum,INT64 qqnum,CString voicesign,CEvent  *&tempevent,int &myseq)
{
locksendforseq.Lock();

vectorbyte temp=sdk.Pack_DownloadPCGroupVoice(groupnum,qqnum,voicesign,myseq);

lockUpGroupssovoicemapres.Lock();
g_sso2voicesignMap[myseq]=voicesign;
lockUpGroupssovoicemapres.Unlock();

tempevent =  new CEvent;
			
	locksocketmapres.Lock();

			g_socketeventMap[myseq]=tempevent;

	locksocketmapres.Unlock();

	sdk.Fun_send(temp);




locksendforseq.Unlock();

}
void synGetQQVoiceInf(INT64 qqnum,CString voicesign,CEvent  *&tempevent,int &myseq)
{
locksendforseq.Lock();

vectorbyte temp=sdk.Pack_DownloadGroupPrivateVoice(qqnum,voicesign,myseq);

lockUpGroupssovoicemapres.Lock();
g_sso2voicesignMap[myseq]=voicesign;
lockUpGroupssovoicemapres.Unlock();

			tempevent=new CEvent;
			
	locksocketmapres.Lock();

			g_socketeventMap[myseq]=tempevent;

	locksocketmapres.Unlock();

	sdk.Fun_send(temp);




locksendforseq.Unlock();

}
void synViewQQLevelInf(INT64 qqnum,CEvent  *&tempevent,int &myseq)
{
locksendforseq.Lock();

vectorbyte temp=sdk.Pack_GetDaren_RankInf(qqnum, myseq);

			tempevent=new CEvent;
			
	locksocketmapres.Lock();

			g_socketeventMap[myseq]=tempevent;
	//if(!g_socketeventMap.Lookup(myseq,tempevent))
	//	{
	//		//no possible
	//		
	//	}
	locksocketmapres.Unlock();

	sdk.Fun_send(temp);




locksendforseq.Unlock();

}

void synViewQQInf(INT64 groupid,INT64 qqnum,CEvent  *&tempevent,int &myseq)
{
locksendforseq.Lock();

vectorbyte temp=sdk.Pack_ViewQQInformation(groupid,qqnum, myseq);

			tempevent=new CEvent;
			
	locksocketmapres.Lock();

			g_socketeventMap[myseq]=tempevent;
	//if(!g_socketeventMap.Lookup(myseq,tempevent))
	//	{
	//		//no possible
	//		
	//	}
	locksocketmapres.Unlock();

	sdk.Fun_send(temp);




locksendforseq.Unlock();

}

void synUploadGroupImg(INT64 groupid,INT64 qqnum,LPCTSTR md5str,LPCTSTR httpaddress,LPCTSTR postfixstr,int filesize,CEvent  *&tempevent,int &myseq)
{
locksendforseq.Lock();

vectorbyte temp;
if(_tcscmp(postfixstr,_T(".amr"))==0)
temp=sdk.Pack_UploadGroupVoice(groupid,qqnum,md5str,postfixstr,filesize, myseq);
else
{

	temp=sdk.Pack_UploadGroupImg(groupid,qqnum,md5str,postfixstr,filesize, myseq);
	

}
			tempevent=new CEvent;
			
	locksocketmapres.Lock();

			g_socketeventMap[myseq]=tempevent;
		
	//if(!g_socketeventMap.Lookup(myseq,tempevent))
	//	{
	//		//no possible
	//		
	//	}
	locksocketmapres.Unlock();

	CString md5poststr;
			md5poststr.Format(_T("%s%s_%s"),md5str,postfixstr,httpaddress);
			g_ssomd5postMap[myseq]=md5poststr;

	sdk.Fun_send(temp);




locksendforseq.Unlock();

}
void UpdateUploadGroupImg(LPCTSTR md5poststr,LPCTSTR md5backstr)
{
	lockUpGroupImgmapres.Lock();
	g_UploadGroupImgMaxp[md5poststr]=CString(md5backstr);
	lockUpGroupImgmapres.Unlock();
}
void UpdateSingleQQlnf(const WholeInformation& singleqqinfo,INT64 groupid)
{

	BOOL bMale=2;	
		NickSex tempnicksex;

		SYSTEMTIME curSystemTime;
			GetLocalTime(&curSystemTime);

		::function::utf8_wchar(singleqqinfo.name().c_str(),tempnicksex.nickname);
		::function::utf8_wchar(singleqqinfo.area().c_str(),tempnicksex.area);
		tempnicksex.area.Trim();
		if(tempnicksex.area.IsEmpty())
			tempnicksex.area=_T("未知");

::function::utf8_wchar(singleqqinfo.oldcardname().c_str(),tempnicksex.oldcardname);
::function::utf8_wchar(singleqqinfo.cardname().c_str(),tempnicksex.nowcardname);
tempnicksex.birth=(curSystemTime.wYear-singleqqinfo.age())%100;
tempnicksex.level=2;
if(singleqqinfo.has_value27())
tempnicksex.level=singleqqinfo.value27();

tempnicksex.age=singleqqinfo.age();

tempnicksex.overdaysjointime=GetoverdaysFromIntTime(singleqqinfo.jointime());
tempnicksex.overdayslastspeaktime=GetoverdaysFromIntTime(singleqqinfo.lastspeaktime());

//更新积分中的加群时间和最后发言时间
UpdateSingleRankfile temprankfile;
temprankfile.groupnum=groupid;
temprankfile.qqnum=singleqqinfo.qqnum();
temprankfile.jointime=singleqqinfo.jointime();
temprankfile.lastactivetime=singleqqinfo.lastspeaktime();
temprankfile.qqscore=0;
 vector<UpdateSingleRankfile> upsinglerankvect;
 upsinglerankvect.push_back(temprankfile);
 if(upsinglerankvect.size())
 {
::SendMessage(mainhwnd,WM_UPDATERANKFILE,(WPARAM)&upsinglerankvect,0);
 }
	int valuesex=-1;
	if(singleqqinfo.has_value9())
	valuesex=singleqqinfo.value9();
	if(valuesex==0)
		bMale=1;
	else if(valuesex==1)
		bMale=0;
	//if(g_singleqqinfo.sexstring().size())
	//{
	//if(g_singleqqinfo.sexstring().at(0)==(char)0xE5)//E5 A5 B9 她  E4 BB 96 他
	//bMale=0;
	//else if(g_singleqqinfo.sexstring().at(0)==(char)0xE4)
	//	bMale=1;
	//}
	tempnicksex.bMale=bMale;

	if(bMale!=2||tempnicksex.age!=0||!tempnicksex.nickname.IsEmpty())
	{
			locknicksexmapres.Lock();
			qqNicksexmap[singleqqinfo.qqnum()]=tempnicksex;
			locknicksexmapres.Unlock();
	}
			group_memberinf tempmemberinf;
		
			tempmemberinf.age=tempnicksex.age;
			tempmemberinf.bMale=tempnicksex.bMale;
			tempmemberinf.cardname=tempnicksex.nowcardname;
			tempmemberinf.overdaysjointime=tempnicksex.overdaysjointime;
			tempmemberinf.overdayslastspeaktime=tempnicksex.overdayslastspeaktime;
			tempmemberinf.nickname=tempnicksex.nickname;
			tempmemberinf.qq=singleqqinfo.qqnum();
			CString group_qqstr;
group_qqstr.Format(_T("%lld_%lld"),groupid,tempmemberinf.qq);
lockg_singleqqinfmapres.Lock();
g_singleqqinfmap[group_qqstr]=tempmemberinf;
lockg_singleqqinfmapres.Unlock();

INT64 nowqqnum=singleqqinfo.qqnum();

lockqqmoreprofile.Lock();
if(!g_qqnum_structmoreprofile_map.Lookup(nowqqnum))
{
		struct_qqnum_msg tempqqnumpro;

		if(valuesex==0)
			tempqqnumpro.gender=_T("1");
	else if(valuesex==1)
			tempqqnumpro.gender=_T("2");

	tempqqnumpro.age.Format(_T("%d"),singleqqinfo.age());

	g_qqnum_structmoreprofile_map[nowqqnum]=tempqqnumpro;
}
	lockqqmoreprofile.Unlock();

}
BOOL Getqqlevel2darenInf(INT64 qqnum,int timeout)
{
	int myseq=0;
	CEvent  *tempevent=0;
	synViewQQLevelInf(qqnum,tempevent,myseq);
	BOOL bOK=false;
DWORD result=0;
if(tempevent)
{
	result=WaitForSingleObject(*tempevent,timeout*1000);
		if(result!=WAIT_TIMEOUT )
	{
	
		bOK=true;//2015.1.30，立即返回也应该删除myseq和tempevent
	}
		//if(bOK)
		{
				locksocketmapres.Lock();
	g_socketeventMap.RemoveKey(myseq);
	delete tempevent;
		locksocketmapres.Unlock();
		}

}

	return bOK;
}

BOOL GetUinSingleQQInf(INT64 groupid,INT64 qqnum,int timeout)
{
	int myseq=0;
	CEvent  *tempevent=0;
	
	synViewQQInf(groupid,qqnum,tempevent,myseq);
	BOOL bOK=false;
DWORD result=0;
if(tempevent)
{
	if(timeout)
	{
	result=WaitForSingleObject(*tempevent,timeout*1000);
		if(result!=WAIT_TIMEOUT )
	{
	
		bOK=true;//2015.1.30，立即返回也应该删除myseq和tempevent
	}
	}
		//if(bOK)
		{
				locksocketmapres.Lock();
	g_socketeventMap.RemoveKey(myseq);
	delete tempevent;
		locksocketmapres.Unlock();
		}

}

	return bOK;
}

UINT ProGetUinSingleQQInf(LPVOID lp)
{

	RemoveQQFromGroup *pqqgroup=(RemoveQQFromGroup *)lp;
	lockuinsinglegetres.Lock();
	GetUinSingleQQInf(pqqgroup->realqqgroup,pqqgroup->realqq,10);

		CEvent  *tempevent=NULL;
	lockgetqqinfmapres.Lock();
	if(!g_GetqqinfeventMap.Lookup(pqqgroup->realqq,tempevent))
		{
			
		}
	else
	{
	if(tempevent)
	tempevent->SetEvent();
	}
	lockgetqqinfmapres.Unlock();
	


	lockuinsinglegetres.Unlock();
	
	delete pqqgroup;

		return 1;
}
BOOL AndroidGetUinNickNameSex(INT64 m_realgroupnumber,INT64 uin,CString& nicknamestr,int& bMale,int timeout)
{


			NickSex tempnicksex;
BOOL bFind=false;
locknicksexmapres.Lock();
bFind=qqNicksexmap.Lookup(uin,tempnicksex);
locknicksexmapres.Unlock();
	if(bFind)
	{
	bMale=tempnicksex.bMale;
	nicknamestr=tempnicksex.nickname;
	return true;
	}
	else
	{
			RemoveQQFromGroup *pqqgroup=new RemoveQQFromGroup;
	pqqgroup->realqqgroup=m_realgroupnumber;
	pqqgroup->realqq=uin;
	

	CEvent  *tempevent=NULL;


lockgetqqinfmapres.Lock();
	
if (!g_GetqqinfeventMap.Lookup(pqqgroup->realqq, tempevent))
{
	tempevent = new CEvent;
	g_GetqqinfeventMap[pqqgroup->realqq] = tempevent;

}
	lockgetqqinfmapres.Unlock();

	AfxBeginThread(ProGetUinSingleQQInf,pqqgroup);
	

			

	
	DWORD result=0;
	if(tempevent)
	{
	result=WaitForSingleObject(*tempevent,timeout*1000);
		if(result!=WAIT_TIMEOUT )//如果是超时，不应该删除event 2015.1.30
	{

	
	}
lockgetqqinfmapres.Lock();
g_GetqqinfeventMap.RemoveKey(uin);
	delete tempevent;
lockgetqqinfmapres.Unlock();

	}
	locknicksexmapres.Lock();
bFind=qqNicksexmap.Lookup(uin,tempnicksex);
locknicksexmapres.Unlock();
	if(bFind)
	{
	bMale=tempnicksex.bMale;
	nicknamestr=tempnicksex.nickname;
	return true;
	}
	}
	
return false;
}
BOOL GetUinSingleNickName(INT64 m_realgroupnumber,INT64 uin,CString& nicknamestr,int& bMale,int timeout)
{
	
	{
		//WholeInformation tempinf;

if(!AndroidGetUinNickNameSex(m_realgroupnumber,uin,nicknamestr,bMale,timeout))
{


				bMale=-1;
				
	GetNickNameFromGroupMap(m_realgroupnumber,uin,nicknamestr);


}
		
	return true;	//return false;
	}
	
}

BOOL GetRealQQSingleNickName(INT64 m_realgroupnumber,INT64 realqq,CString& nicknamestr,int& bMale,int timeout)
{
	
	{
	if(!AndroidGetUinNickNameSex(m_realgroupnumber,realqq,nicknamestr,bMale,timeout))
	{


				bMale=1;
				
	GetNickNameFromGroupMap(m_realgroupnumber,realqq,nicknamestr);


}
	
		return true;	//return false;
	}

	
}
BOOL GetUinNickName(INT64 uin,CString& nicknamestr)
{
	
		return false;

}
void C晨风qq机器人Dlg::SavePassword(LPCTSTR curqqnumber,LPCTSTR password,BOOL bSaveSession/*=true*/)
{
			CString fmtstrqq;
	fmtstrqq.Format(_T("%s"),curqqnumber);
	TCHAR bufname[512];
	::function::CFSoft_path(fmtstrqq,bufname,g_bLocalSaveflag);
	::function::RemoveRH(bufname);
	CReadAUStdioFile filepwd(true);
		if(filepwd.Open(bufname,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{
			TCHAR ddd[100];
lstrcpy(ddd,password);
	
	xmlgetcode(ddd,true,_ttoi64(curqqnumber));
			filepwd.WriteLineStr(ddd);
			if(bSaveSession)
			{
			filepwd.WriteLineStr(strIP);
			CString strnowport;
			strnowport.Format(_T("%d"),nowport);
			filepwd.WriteLineStr(strnowport);
			filepwd.WriteLineStr((CString)Xbin.Bin2Hex(qq.Token002C));
			filepwd.WriteLineStr((CString)Xbin.Bin2Hex(qq.Token004C));
			filepwd.WriteLineStr((CString)Xbin.Bin2Hex(qq.sessionKey));
			filepwd.WriteLineStr((CString)Xbin.Bin2Hex(qq.skey));
			filepwd.WriteLineStr((CString)Xbin.Bin2Hex(qq.vkey));

			}
			filepwd.Close();
		}
}
void C晨风qq机器人Dlg::LoadPassword(LPCTSTR curqqnumber,CString& curpassword)
{
	CString fmtstrqq;
	fmtstrqq.Format(_T("%s"),curqqnumber);

		TCHAR bufname[512];
	::function::CFSoft_path(fmtstrqq,bufname,g_bLocalSaveflag);
	
	CReadAUStdioFile filepwd(true);
	CString tempstr;
		if(filepwd.Open(bufname,CFile::modeRead|CFile::shareDenyNone))
		{
			if(filepwd.ReadString(tempstr))
			{
				curpassword=tempstr;
			
			int len=curpassword.GetLength();
			BOOL bEncodedflag=true;
			for(int i=0;i<len;i++)
			{
			
			if(curpassword.GetAt(i)<'a'||curpassword.GetAt(i)>'z')
			{
				bEncodedflag=false;
			break;
			
			}
			}

			if(len>16||bEncodedflag)
			{
			TCHAR ddd[100];
lstrcpy(ddd,curpassword);
	
	xmlgetcode(ddd,false,_ttoi64(curqqnumber));
	curpassword=ddd;
			}
			}
if(filepwd.ReadString(tempstr))
	g_last_strIP=tempstr;
if(filepwd.ReadString(tempstr))
{
	g_last_nowport=_ttoi(tempstr);
}
if(filepwd.ReadString(tempstr))
	g_last_Token002C=tempstr;
if(filepwd.ReadString(tempstr))
	g_last_Token004C=tempstr;
if(filepwd.ReadString(tempstr))
	g_last_sessionKey=tempstr;
if(filepwd.ReadString(tempstr))
	g_last_skey=tempstr;
if(filepwd.ReadString(tempstr))
	g_last_vkey=tempstr;

			filepwd.Close();
		}

}
BOOL bLoginStateOK=false;
extern CStringA g_smsstr1,g_smsstr2,g_smsstr3;
BOOL C晨风qq机器人Dlg::RetrySdkLogin()
{
	if(0)
	return true;//
sdk.Fun_Login (m_verifycode);
if(!m_verifycode.IsEmpty())
{
	if(last_error=="需要输入验证码")
	{
	last_error="";
	
	}
m_verifycode=_T("");
}
if(qq.loginState==login_state_success)
{
	qq.Viery.clear();
    sdk.QQOnLine();
	bLoginStateOK=true;
return bLoginStateOK;
}
else if(qq.loginState==login_state_veriy)
{
   
	if(!CheckQQAccount())
	{
	return false;
	}
	else
	{
	bLoginStateOK=RetrySdkLogin();
	}
	
}
else
{
	 if(!g_remoteloginflag&&g_remote_lastownqq.IsEmpty())
	{
	}
	else
	{
		loglasterror((CString)last_error);
	//生成一个以当前远程qq号的登录error状态.txt记录出错信息
	}
 

	if(qq.loginState==0xcc)
	{
//tempbin=;


vectorbyte bin=sdk.Fun_sendAndRecv(sdk.Pack_LoginwithLastSms(g_smsstr3));
sdk.fun_recv_analyse (bin);

	bLoginStateOK=(qq.loginState==login_state_success);
	if(bLoginStateOK)
	{
	qq.Viery.clear();
    sdk.QQOnLine();
	}
	return bLoginStateOK;

}
else if(last_error.Find("手机开启了设备锁，需要用密保手机：")!=-1)
{
		



if(IDOK==MessageBoxA(mainhwnd,last_error,"是否现在获取验证短信？",MB_OKCANCEL))
{
		int safephonenum=234567;
		
CStringA safestr;
	

		vectorbyte tempbin;
		vectorbyte bin;
		if(1)
		{
	tempbin=sdk.Pack_VerifySms();

bin=sdk.Fun_sendAndRecv(tempbin);
		}
CColorSMSInput dlg;
	dlg.DoModal();
safestr=(CStringA)dlg.m_smsstr;
	safestr.Trim();
//safestr.Format("%d",safephonenum);
tempbin=sdk.Pack_LoginwithSms(safestr);


bin=sdk.Fun_sendAndRecv(tempbin);
sdk.fun_recv_analyse (bin);

	bLoginStateOK=(qq.loginState==login_state_success);
	if(bLoginStateOK)
	{
	qq.Viery.clear();
    sdk.QQOnLine();
	}
	return bLoginStateOK;
}
else
	return false;

	}
		return false;
}
return bLoginStateOK;
}
const TCHAR nextip[6][64]={_T("14.17.41.169"),_T("61.151.224.42"),_T("183.60.38.57"),_T("14.17.42.23"),_T("msfwifi.3g.qq.com"),_T("112.90.140.143")};
void GetNextStrIP()
{
 static int changeipcount=0;
		 nowport=8080;
		strIP=nextip[changeipcount%6];
changeipcount++;
}
BOOL RetryConnect()
{
	BOOL rtflag=false;
	rtflag=ConnectQQServer();
 if(!rtflag)
	 {
		// AfxMessageBox(_T("连接腾讯QQ服务器失败，可能是由于网络故障，请重新点“登录按钮”试试！"));
		GetNextStrIP();
rtflag=ConnectQQServer();
if(!rtflag)
{
GetNextStrIP();

rtflag=ConnectQQServer();
if(!rtflag)
{
GetNextStrIP();

if(!g_remoteloginflag&&g_remote_lastownqq.IsEmpty())
	{
	AfxMessageBox(_T("连接腾讯QQ服务器失败，可能是由于网络故障，请重新点“登录按钮”试试！"));
}
else
	{
			loglasterror(_T("连接腾讯QQ服务器失败，可能是由于网络故障，请重新点“登录按钮”试试！"));
	//生成一个以当前远程qq号的登录的状态.txt记录出错信息
	}

}
}	
 }

		return rtflag;
}
void GetRandIPFromServer()
{
int sizez=g_qqserveripmap.GetCount();
if(sizez>0)
{
	int now=rand()%sizez;
strIP=g_qqserveripmap.m_mapstr[now];
nowport=_ttoi(g_qqserveripmap[now]);


}
}
BOOL C晨风qq机器人Dlg::LoginQQ()
{
	GetDlgItemText(IDC_COMBO4,m_ownqqnumber);
GetDlgItemText(IDC_EDIT2,m_passwordstr);
m_ownqqnumber.Trim();
m_passwordstr.Trim();
m_passwordstr=m_passwordstr.Left(16);
	if(m_ownqqnumber.IsEmpty())
	{
			MessageBox(_T("你还没输入QQ号，请先输入QQ号，并且输入QQ密码进行登录！"));

		return false;
	}
	g_interfaceuin = _ttoi64(m_ownqqnumber);
	INT64 qqnum=_ttoi64(m_ownqqnumber);
	if(qqnum>UINT32_MAX)
	{
			MessageBox(_T("必须使用虚拟qq号对应的真实的qq号，而不能直接使用如手机号一样的虚拟qq号！"));

		return false;
	}
	if(m_passwordstr.IsEmpty())
	{
				MessageBox(_T("你没有输入QQ密码，请先输入qq密码再点‘登录’按钮！"));

		return false;
	}

	if(m_ownqqnumber!=lastqqnumber&&!lastqqnumber.IsEmpty())
	{
		g_qqrestartingflag=false;
		QuitAndSavehistory();
	QuitQQ();
		m_alreadylogin=false;
	}

	 m_verifycode=_T("");
sdk.Init(m_ownqqnumber,m_passwordstr);
g_bAutoHeirLast=false;
if(g_now_bAuto_online&&g_defaultpassword==m_passwordstr&&!g_last_sessionKey.IsEmpty()&&!g_last_Token002C.IsEmpty()&&!g_last_Token004C.IsEmpty()&&!g_last_skey.IsEmpty()&&!g_last_vkey.IsEmpty())
{
g_bAutoHeirLast=true;
}
if(g_bAutoHeirLast)
{
	if(g_last_strIP!="msfwifi.3g.qq.com")
	{
	strIP=g_last_strIP;
	nowport=g_last_nowport;
	}
	BOOL rtflag=ConnectQQServer();
	if(!rtflag)
	{
		GetRandIPFromServer();
		rtflag=ConnectQQServer();
	}
	if(!rtflag)
	{
		GetNextStrIP();
		rtflag=ConnectQQServer();
	}
	if(rtflag)
	{
	qq.sessionKey=setHex(g_last_sessionKey);
	qq.Token002C=setHex(g_last_Token002C);
	qq.Token004C=setHex(g_last_Token004C);
	qq.skey=setHex(g_last_skey);
	qq.vkey=setHex(g_last_vkey);
	qq.key=qq.sessionKey;
	qq.Viery.clear();
    sdk.QQOnLine();

	bLoginStateOK=true;


	}
	else
	{
	g_bAutoHeirLast=false;
	}
}

if(!g_bAutoHeirLast)
{
	if(!RetryConnect())
	 return false;
	 
	
//vectorbyte bin=sdk.Fun_sendAndRecv(sdk.Pack_PhSigLcId());
//sdk.fun_recv_analyse (bin);

if(!RetrySdkLogin())
{
if(!last_error.IsEmpty())
{
	if(last_error=="登录返回包为空"||last_error.Find("稍后")!=-1)
	{
		g_qqserveripmap.RemoveKey((CString)strIP);
		g_qqserveripmap.RemoveAll();
		strIP="msfwifi.3g.qq.com";
		nowport=8080;
		//last_error+=_T("——如果你开启了设备锁或者其它登录保护，必须要先解除才能登录此软件，如果没设置，请重新启动机器人再试试！");
	//MessageBoxA(mainhwnd,last_error,"登录出错，请重试——机器人将自动重新启动一次",0);
	if(retryloginflag2||retryloginflag3)
	{
		if(!g_remoteloginflag&&g_remote_lastownqq.IsEmpty())
	MessageBoxA(mainhwnd,last_error,"登录出错，请确认你的网络或qq账号或密码无误再重试——机器人之前已经重新启动过一次，但依然失败！",0);
		else
		{
		
				loglasterror((CString)last_error);
		//生成一个以当前远程qq号的登录状态.txt记录出错信息

		}
	}
	else
	{
		if(last_error.Find("稍后")!=-1)
onReStart(3,0);
		else
	onReStart(2,0);
	}
	}
	else
	{

	//last_error+=_T("——如果你开启了设备锁或者其它登录保护，必须要先解除才能登录此软件，如果没设置，请重新启动机器人再试试！");
		if(!g_remoteloginflag&&g_remote_lastownqq.IsEmpty())
		{
		MessageBoxA(mainhwnd,"登录出错，如果是出现一串英文乱码，请在手机上手动登录此号码，开启设备锁之后，再在手机上退出此号码，再重新启动机器人软件，碰到提示开启了设备锁后，获取手机验证码填入到机器人软件中就可以正常登录了，其余情况下请重试——最好重新启动机器人软件",last_error,0);
		}
		else
		{
		//生成一个以当前远程qq号的登录状态.txt记录出错信息
	loglasterror((CString)last_error);
		}
	}
}
else if(qq.loginState==login_state_logining)
{
	//last_error+=_T("——如果你开启了设备锁或者其它登录保护，必须要先解除才能登录此软件，如果你在手机上登录了这个qq号，也必须先从手机上完全退出才能正常登录此软件！");
	strIP="msfwifi.3g.qq.com";
	nowport=8080;
if(!g_remoteloginflag&&g_remote_lastownqq.IsEmpty())
		MessageBoxA(mainhwnd,last_error,"登录出错，请重试——最好重新启动机器人软件",0);
else
		{
		//生成一个以当前远程qq号的登录状态.txt记录出错信息
	loglasterror((CString)last_error);
		}

}
	return false;
}
}


 if(!g_remoteloginflag&&g_remote_lastownqq.IsEmpty())
	{
	}
	else
	{
			loglasterror(_T("登录成功"));
	//生成一个以当前远程qq号的登录成功的状态.txt记录出错信息
	}
 m_alreadylogin = true;
 CString resultstrrr,paramstr;
 paramstr.Format(_T("cfrobotselfnum=%lld&loginstate=%d&nonewmsgtime=%d"), qq.QQ, m_alreadylogin, g_nonewmsgminutes);

 for (UINT i = 0; i < g_dllpathmap.m_mapstr.size(); i++)
 {
	 try
	 {

		 GetDllresultText(g_dllpathmap.m_mapstr[i], _T("loginstatefun"), paramstr, false, resultstrrr);

	 }
	 catch (...)
	 {

	 }
 }
	 		

g_qqserveripmap.RemoveAll();
g_interfaceuin=qq.QQ;
g_skey=(CString)vector2char(qq.skey);
g_qqsuperkey=(CString)vector2char(qq.superkey);
m_myg_tk=Getg_tkfromskey(g_skey);
LoadPriviliegeFile();//把加载默认配置和游戏移动到这里来

Gettransmitpm();


BOOL bAllowcookies=false;
if(g_bAllowCreateCookies&&!g_bAutoHeirLast)//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("允许机器人生成cookies文件"))!=g_outputreplacemap.m_mapstr.end())
	bAllowcookies=true;

//if(1)//{

	CReadAUStdioFile cook_file1(false);
		CString Ignorefilename;
CString tempstr;
//tempstr.Format(_T("cookies.txt"));
Ignorefilename=g_plusdir+_T("cookies.txt");//SaveAs_complete_path(tempstr);
if(bAllowcookies)
{
	
bAllowcookies=cook_file1.Open(Ignorefilename,CFile::modeCreate|CFile::modeWrite);
}
	BOOL bTiqqflag=false;
		//pgv_pvid=3709068719; pt2gguin=o3086977168; RK=fONKToAoO3; o_cookie=13402429; pgv_pvi=4146387968; ptui_loginuin=3095087199; ptcz=7767a0de2584d97e397a1206776967b375d125ba31a90e682633c5305dd7031a;
		CString totalcookiesstr;

		tempstr.Format(_T("g_tk=%d;"),m_myg_tk);
		InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);

		//tempstr.Format(_T("v=Arq2oV7XsqMD0z5PEdNMzdKaC-vfaz5FsO-y6cSzZs0Yt1QdrPuOVYB_Av-X;"));
		//InternetSetCookieA("http://www.iwencai.com", NULL, (CStringA)tempstr);
		 
		/*tempstr.Format(_T("pvid=117173066;"));
		InternetSetCookieA( "http://qzone.qq.com", NULL, (CStringA)tempstr);
		if(bTiqqflag)
		InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);

			tempstr.Format(_T("pgv_pvid=2731247959;"));
		InternetSetCookieA( "http://qzone.qq.com", NULL, (CStringA)tempstr);
		if(bTiqqflag)
		InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		

		tempstr.Format(_T("ptcz=940dcdbfc8fa6c637705d4e4eac841ddc1e7186fb8f291958c4533d3f069eefd;"));
		InternetSetCookieA( "http://qzone.qq.com", NULL, (CStringA)tempstr);
		if(bTiqqflag)
		InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
*/

		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
		tempstr.Format(_T("skey=%s;"),(CString)vector2char(qq.skey));
		InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
		//InternetSetCookieA( "http://qun.qq.com", NULL, (CStringA)tempstr);

		//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
		totalcookiesstr+=tempstr;
		tempstr.Format(_T("p_skey=%s;"),(CString)vector2char(qq.pskey));
		InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
		//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
			totalcookiesstr+=tempstr;
		tempstr.Format(_T("p_uin=o%lld;"),qq.QQ);
		InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
		//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
			totalcookiesstr+=tempstr;
		tempstr.Format(_T("uin=o%lld;"),qq.QQ);
		InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
		//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
			totalcookiesstr+=tempstr;
		tempstr.Format(_T("ptwebqq=%s;"),(CString)qq.stweb);
		InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
		//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
			totalcookiesstr+=tempstr;
			tempstr.Format(_T("superkey=%s;"),(CString)vector2char(qq.superkey));
			InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
		//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
			totalcookiesstr+=tempstr;
			tempstr.Format(_T("vkey=%s;"),(CString)vector2char(qq.vkey));
			InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
			/*if(0)
				InternetSetCookieA( "http://web.qun.qq.com", NULL, (CStringA)tempstr);*/
			//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
			totalcookiesstr+=tempstr;
			tempstr.Format(_T("sid=%s;"),(CString)vector2char(qq.sid));
			InternetSetCookieA( "http://qq.com", NULL, (CStringA)tempstr);
			/*	if(0)
				InternetSetCookieA( "http://web.qun.qq.com", NULL, (CStringA)tempstr);*/
			//if(bTiqqflag)
		//InternetSetCookieA( "http://fun.svip.qq.com", NULL, (CStringA)tempstr);
		
		if(bAllowcookies)
		cook_file1.WriteString(tempstr);
			totalcookiesstr+=tempstr;



			if(bAllowcookies)
	cook_file1.Close();

	
	
	
	bNeedReDetectflag=false;
	bKickOffflag=false;
		inittime=GetTickCount();
			SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
			fullinittime=time1.GetTime();
			
				g_stoprestart=false;
				lastqqnumber=m_ownqqnumber;
				bAlreadyReadGroupInf=false;
				g_qqrestartingflag=false;

		CString fmtstr;
				fmtstr.Format(_T("%s已登录"),m_ownqqnumber);

			
				CString tempaddstr = _T("晨风QQ机器人");
				if (!g_replaceskintitle.IsEmpty() && g_replaceskintitle.Find(tempaddstr)==-1)
					tempaddstr = g_replaceskintitle;

				m_addtitle.Format(_T("%s：%s——"), tempaddstr,m_ownqqnumber);//
				//if(!g_customstr.IsEmpty())
				//{
				////m_addtitle.Replace(_T("晨风"),g_customstr);
				//m_addtitle.Replace(_T("晨风QQ机器人"),g_customstr);//

				//}
				
	SetDlgItemText(IDC_BUTTON1,fmtstr);
	m_lastnewmsgtime=GetTickCount();
			SetTimer(1,10000,NULL);
			SetTimer(3,3*60*1000,NULL);

				SetTimer(69,60*60*1000,NULL);
				SetTimer(70,125*60*1000,NULL);

			
				//倒数第四位×3+倒数第三位×5+最后一位×9；
				//13402429
				INT64 newinterfaceuin=g_interfaceuin/10;

					INT64 lastnum4=newinterfaceuin%10000;
	lastnum4=(int)(lastnum4/1000);
				INT64 lastnum3=newinterfaceuin%1000;
	lastnum3=(int)(lastnum3/100);
INT64 lastnum1=newinterfaceuin%10;

	g_mymaxxmlnum=lastnum4*3+lastnum3*5+lastnum1*9;

	if(!g_bAutoHeirLast||g_last_strIP=="msfwifi.3g.qq.com")
	SavePassword(m_ownqqnumber,m_passwordstr);//把上次的服务器地址、skey等都保存下来以备免登录重新上线
	
	if(find(g_loginedset.begin(),g_loginedset.end(),m_ownqqnumber)==g_loginedset.end())
	{
		m_combox_ownqq.AddString(m_ownqqnumber);
		g_loginedset.push_back(m_ownqqnumber);	
	}
	//CStringA tempaccount=(CStringA)m_ownqqnumber;
	g_ksidmd5=GetNewcheckSignCode();
	//::function::SafeGetCff(g_ksidmd5,tempaccount.GetBuffer(0),tempaccount.GetLength(),false);

	g_reporturl=_T("");
if(m_alreadylogin&&!g_bAutoReportAds.IsEmpty())//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("自动回报机器人在线状态的接口网址"))!=g_outputreplacemap.m_mapstr.end())
{	
	CString tempreporturl;
tempreporturl=g_bAutoReportAds;//g_outputreplacemap[_T("自动回报机器人在线状态的接口网址")].front();
CString dddd;
//CStringA tempaccount=(CStringA)m_ownqqnumber;
	//::function::SafeGetCff(g_ksidmd5,tempaccount.GetBuffer(0),tempaccount.GetLength(),false);

		dddd.Format(_T("&cfrobotselfnum=%s&version=%s&checksign=%s"),m_ownqqnumber,g_purenumberversion,g_ksidmd5);
		
		
		
		if(tempreporturl.Find(_T('?'))==-1)
			tempreporturl+='?';
tempreporturl+=dddd;
		
g_reporturl=tempreporturl;


}
	return true;
}


UINT ProGetQQMoreProfileInf(LPVOID lp)
{

	INT64 *pQQnum=(INT64 *)lp;
	
				CString realhostname=_T("ti.qq.com");				
	CString processpath;
		processpath=_T("/cgi-bin/more_profile_card/more_profile_card");
	//processpath.Format(_T("/qcard/index.html?sid=%s&qq=68663216&appid=537044775&version=android-6.2.0&main_qq=68663216&_wv=1027"),(CString)vector2char(qq.sid));
	UINT ddlen=1024*20;
	char *rtvalue=new char[1024*20+1];
	CStringA mobilestrA;
	mobilestrA.Format("_q=%lld&bkn=%d&src=mobile&sid=%s",*pQQnum,m_myg_tk,(CString)vector2char(qq.sid));
	strcpy(rtvalue,mobilestrA);
	ddlen=strlen(rtvalue);
	CString Refererstr;
	Refererstr.Format(_T("Cookie: skey=%s;uin=o%lld;vkey=%s\r\n"),g_skey,g_interfaceuin,(CString)vector2char(qq.vkey));

	MySendWeb(realhostname,processpath,(byte*)rtvalue,rtvalue,ddlen,false,Refererstr);//Refererstr
	if(ddlen>100)
	{
	struct_qqnum_msg tempqqnumpro;
	INT64 agevalue;
	INT64 dayvalue;
INT64 monthvalue;
INT64 yearvalue;
INT64 constellationvalue;
INT64 occupationvalue;
INT64 gendervalue;
	GetNumFromJson(rtvalue,_T("age"),&agevalue);
	GetNumFromJson(rtvalue,_T("day"),&dayvalue);
	GetNumFromJson(rtvalue,_T("month"),&monthvalue);
	GetNumFromJson(rtvalue,_T("year"),&yearvalue);
GetNumFromJson(rtvalue,_T("constellation"),&constellationvalue);
GetNumFromJson(rtvalue,_T("occupation"),&occupationvalue);
GetNumFromJson(rtvalue,_T("gender"),&gendervalue);

	tempqqnumpro.age.Format(_T("%lld"),agevalue);
	tempqqnumpro.day.Format(_T("%lld"),dayvalue);
	tempqqnumpro.month.Format(_T("%lld"),monthvalue);
	tempqqnumpro.year.Format(_T("%lld"),yearvalue);
tempqqnumpro.constellation.Format(_T("%lld"),constellationvalue);
tempqqnumpro.occupation.Format(_T("%lld"),occupationvalue);
tempqqnumpro.gender.Format(_T("%lld"),gendervalue);

	GetStrFromJson(rtvalue,_T("college"),&tempqqnumpro.college,true);
	GetStrFromJson(rtvalue,_T("company"),&tempqqnumpro.company,true);
	GetStrFromJson(rtvalue,_T("email"),&tempqqnumpro.email,true);
GetStrFromJson(rtvalue,_T("hometown_area"),&tempqqnumpro.hometown_area,true);
GetStrFromJson(rtvalue,_T("hometown_city"),&tempqqnumpro.hometown_city,true);
GetStrFromJson(rtvalue,_T("hometown_country"),&tempqqnumpro.hometown_country,true);
GetStrFromJson(rtvalue,_T("hometown_state"),&tempqqnumpro.hometown_state,true);

GetStrFromJson(rtvalue,_T("location_area"),&tempqqnumpro.location_area,true);
GetStrFromJson(rtvalue,_T("location_city"),&tempqqnumpro.location_city,true);
GetStrFromJson(rtvalue,_T("location_country"),&tempqqnumpro.location_country,true);
GetStrFromJson(rtvalue,_T("location_state"),&tempqqnumpro.location_state,true);
GetStrFromJson(rtvalue,_T("nick"),&tempqqnumpro.nick,true);
GetStrFromJson(rtvalue,_T("personal"),&tempqqnumpro.personal,true);
tempqqnumpro.personal.Replace(_T("&nbsp;"),_T(" "));
tempqqnumpro.personal.Replace(_T("<br>"),_T("\r\n"));
tempqqnumpro.personal.Trim(_T("\r\n"));
tempqqnumpro.personal.Replace(_T("\r\n"),_T("【换行】"));

lockqqmoreprofile.Lock();
	g_qqnum_structmoreprofile_map[*pQQnum]=tempqqnumpro;
	lockqqmoreprofile.Unlock();
	
	}
delete[]rtvalue;

delete pQQnum;

	return 1;
}

void C晨风qq机器人Dlg::OnBnClickedButton2()
{
}

	




void C晨风qq机器人Dlg::GetCaptchaImg(LPCTSTR url)
{
		UINT ddlen=0;
		char *rtvalue=new char[1024*1024];
	::function::DownloadHttpFile(url,(byte*)rtvalue,ddlen);
CImage m_image;
		GetCImageFromByte(m_image,(byte*)rtvalue,ddlen);
		CClientDC dc(this);
		CRect myrect;
		GetDlgItem(IDC_yanzhengpic)->GetWindowRect(myrect);
		ScreenToClient(myrect);
 m_image.Draw(dc, myrect.left, myrect.top, m_image.GetWidth(), m_image.GetHeight(), 0, 0, m_image.GetWidth(), m_image.GetHeight());
	delete []rtvalue;
}
BOOL C晨风qq机器人Dlg::NoNeedTypeVerifycode()
{
	
	{
	if(qq.Viery.size())
		return false;
	else
		return true;
	}

}
BOOL C晨风qq机器人Dlg::CheckQQAccount()
{
	BOOL noneedflag=NoNeedTypeVerifycode();

	if(!noneedflag)
	{
		
CString url;
	CString timestr;
	GetRandomTimeStr(timestr);
url.Format(_T("/getimage?aid=501004106&r=%s&uin=%s&cap_cd=%s"),timestr,m_ownqqnumber,m_capcdcode);
		g_holdon=true;	
	CColorInput dlg(url);
	int rtflag=dlg.DoModal();
	if(rtflag==1000)
	{
	
	return false;
	}
	else
	{
	m_verifycode=dlg.m_captchastr;
	
//SetDlgItemText(IDC_EDIT3,m_verifycode);
	}
	 SetForegroundWindow();
 GetDlgItem(IDC_EDIT2)->SetFocus();
 	g_holdon=false;

	}
	else
	{
	
		//SetDlgItemText(IDC_EDIT3,m_verifycode);
	}


	
	m_alreadycheck=true;
	

	return true;
}
CEvent internettimeevent; 
UINT GetInternetTime(LPVOID lp)
{
 SYSTEMTIME* stnow=(SYSTEMTIME*)lp;
 //GetLocalTime(&stnow);
 	::function::GetInternetTime(*stnow,false);
	return  0;
}

BOOL RobotCheckExpire()
{
	 WIN32_FIND_DATA ffd ;
 HANDLE hFind = FindFirstFile(SaveAs_complete_path(_T("群积分文件")),&ffd);

  FindClose(hFind); 

 FILETIME ftLocal;
SYSTEMTIME st;
 
 FileTimeToLocalFileTime(&ffd.ftCreationTime,&ftLocal);
 FileTimeToSystemTime(&ftLocal,&st);
 
 SYSTEMTIME stnow;
 //GetLocalTime(&stnow);
 	::function::GetInternetTime(stnow,true);
	AfxBeginThread(GetInternetTime,(LPVOID)&stnow);
	WaitForSingleObject(internettimeevent,2000);

int creationday=st.wYear*372+st.wMonth*31+st.wDay;
int nowday=stnow.wYear*372+stnow.wMonth*31+stnow.wDay;
int differday=nowday-creationday;
if(differday>limitnumber)
{

	qqgroupqun=true;
	outoutflag=true;
	return true;
}

return false;

}
void C晨风qq机器人Dlg::CleanAndClear()
{
	lockgroupnameresource.Lock();
GidNickNamemap.RemoveAll();
GidRealGNummap.RemoveAll();

g_tempgroupuinset.clear();
lockgroupnameresource.Unlock();
lockuinrealqqres.Lock();
UinRealNumMap.RemoveAll();
GidRealGNummap.RemoveAll();
lockuinrealqqres.Unlock();
	lockgidgcoderesource.Lock();
GidGcodemap.RemoveAll();
GcodeGidmap.RemoveAll();
	lockgidgcoderesource.Unlock();
lockandroid_gqqnickmapresource.Lock();
for(auto it=Android_GrouprealqqNickmap.m_mapstr.begin();it!=Android_GrouprealqqNickmap.m_mapstr.end();it++)
{
	CKeepINT64StrMap *pintstrmap=NULL;
		
	
		if(Android_GrouprealqqNickmap.Lookup(*it,pintstrmap))
		{
			pintstrmap->RemoveAll();
			delete pintstrmap;
		}

}
for (UINT i = 0; i < g_dynbuttonmap.GetSize(); i++)
{
	delete g_dynbuttonmap[i];
}
g_dynbuttonmap.RemoveAll();
Android_GrouprealqqNickmap.RemoveAll();
lockandroid_gqqnickmapresource.Unlock();
lockgnameresource.Lock();
for(auto it=g_group_uinNameMap.m_mapstr.begin();it!=g_group_uinNameMap.m_mapstr.end();it++)
{
	CKeepINT64StrMap *pintstrmap=NULL;
		
	
		if(g_group_uinNameMap.Lookup(*it,pintstrmap))
		{
			pintstrmap->RemoveAll();
			delete pintstrmap;
		}

}
g_group_uinNameMap.RemoveAll();
lockgnameresource.Unlock();

lockgqqnickmapresource.Lock();
for(auto it=GrouprealqqNickmap.m_mapstr.begin();it!=GrouprealqqNickmap.m_mapstr.end();it++)
{
	CKeepINT64StrMap *pintstrmap=NULL;
		
	
		if(GrouprealqqNickmap.Lookup(*it,pintstrmap))
		{
			pintstrmap->RemoveAll();
			delete pintstrmap;
		}

}
GrouprealqqNickmap.RemoveAll();
lockgqqnickmapresource.Unlock();

lockLastCardNameMap.Lock();
g_group_LastCardNameMap.RemoveAll();
lockLastCardNameMap.Unlock();

lockggroup_uinsetmap.Lock();
for(auto it=g_group_uinsetMap.m_mapstr.begin();it!=g_group_uinsetMap.m_mapstr.end();it++)
{
g_group_uinsetMap[(*it)].clear();
}
g_group_uinsetMap.RemoveAll();
lockggroup_uinsetmap.Unlock();

for(auto it=g_group_LastGroupNickNameeventMap.m_mapstr.begin();it!=g_group_LastGroupNickNameeventMap.m_mapstr.end();it++)
{
delete g_group_LastGroupNickNameeventMap[(*it)];
}
g_group_LastGroupNickNameeventMap.RemoveAll();


lockggroup_realqqsetmap.Lock();
for(auto it=g_group_realqqvectMap.m_mapstr.begin();it!=g_group_realqqvectMap.m_mapstr.end();it++)
{
g_group_realqqvectMap[(*it)].clear();
}
g_group_realqqvectMap.RemoveAll();
lockggroup_realqqsetmap.Unlock();

}
INT64 FindAlreadyExistQQ(INT64 newqqnum)
{
	INT64 bFind=0;
lockggroup_realqqsetmap.Lock();
for(auto it=g_group_realqqvectMap.m_mapstr.begin();it!=g_group_realqqvectMap.m_mapstr.end();it++)
{
if(g_group_realqqvectMap[(*it)].find(newqqnum)!=g_group_realqqvectMap[(*it)].end())
{
	
	bFind=(*it);
	break;
}
}

lockggroup_realqqsetmap.Unlock();

return bFind;
}
void CreateAndroidThreadonce()
{
	static int onceflag=0;
	if(onceflag==0)
	{
		onceflag=1;
	mywinthread5=AfxBeginThread(proPbSendMsgFun,NULL);

		mywinthread6=AfxBeginThread(proUploadPrivateImgSendMsgFun,NULL);
	strIP="msfwifi.3g.qq.com";//14.17.41.169";//"112.90.78.168";  
int sizez=g_qqserveripmap.GetCount();
if(sizez>0)
{
	int now=rand()%sizez;
strIP=g_qqserveripmap.m_mapstr[now];
nowport=_ttoi(g_qqserveripmap[now]);


}

	}

}
void DownloadTestplug()
{
		 CString defwebads,backstr;

				 defwebads=_T("http://www.qqshow123.com/game/testplug.dll");
				 backstr=_T("testplug");
				 ::SendMessage(mainhwnd,WM_ReLoadDefGame,(WPARAM)defwebads.GetBuffer(0),(LPARAM)backstr.GetBuffer(0));

				 	g_bTestplugexistflag=PathFileExists(g_testplugpath);

}
BOOL bCompletedflag=false;
void C晨风qq机器人Dlg::OnBnClickedButton1()
{
	BOOL firstregflag=false;

	//g_bQQflag=((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	g_bQQflag=false;//暂时禁用企业qq

	if(PathFileExists(SaveAs_complete_path(_T("企业版专用标志.txt"))))
g_bQQflag=true;//暂时禁用企业qq
	else
	{
	if(PathFileExists(SaveAs_complete_path(_T("企业版专用标志.txt.txt"))))
g_bQQflag=true;//暂时禁用企业qq
	else
		g_bQQflag=false;//暂时禁用企业qq
	}
	g_now_bAuto_online=g_last_bAuto_online;
	g_status_selcur=((CComboBox*)GetDlgItem(IDC_COMBO5))->GetCurSel();
	GetDlgItemText(IDC_COMBO4,m_ownqqnumber);
	m_ownqqnumber.Trim();
g_Androidflag=true;
g_realrowNum = 0;

int orglimit=limitnumber;
g_interfaceuin=_ttoi64(m_ownqqnumber);
Gettransmitpm(_ttoi64(m_ownqqnumber));
	{

	GetLimitNumber(false);

//	if(!Isggged&&mySystemTime.wDay+mySystemTime.wMonth*31+mySystemTime.wYear*12*31>15+4*31+2015*12*31)
//	{
//		g_Androidflag=0;
//		((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(0);
//		MessageBox(_T("未注册版不能使用安卓协议！"));
//	}
}

//检查是不是注册用户
//if(mySystemTime.wDay+mySystemTime.wMonth*31+mySystemTime.wYear*12*31>25+3*31+2015*12*31)
//{
//Isggged=0;
//}
	
	{
	CreateAndroidThreadonce();
	}
	
	if(m_ownqqnumber==lastqqnumber&&m_alreadylogin)
	{
		
		if(!g_now_bAuto_online)
		{
	if(IDOK==MessageBox(_T("安卓协议不需要重新登录，不像之前webqq的方式，需要定时重新登录以防止登录时间太长各种状态失效！如果你确实需要重新登录，点“确定”将会自动重新启动软件并自动登录！"),_T("是否现在重新启动软件"),MB_OKCANCEL))
					onReStart(2,0);
	else
		return;
		}
g_now_bAuto_online=false;

	}
	
	g_group_uinRetryMap.RemoveAll();
	bExitPostThread=true;
	Terminate2Thread();
	BOOL rtflag=LoginQQ();
	firstmsgflag=true;
	if(rtflag)
	{
		if(bFirsttime)
	{
			if(IDOK==MessageBox(_T("晨风qq机器人可快速活跃群内气氛，提升群排名以及帮助管理群内秩序，踢出滥发广告者，此机器人大部分功能都可以长期免费使用，但部分娱乐和商业功能需注册之后才能使用，并且注册之后，可以加入到注册用户专用交流群，各种使用问题和改进需求都能得到解决，你是否有兴趣注册以支持作者的后续开发？"),_T("是否查看注册链接"),MB_OKCANCEL))
{
	ShellExecute(NULL,NULL,buychsRegURL,0,0,1);
}
		DownloadWebGame();
		
	}
		if(!bAlreadyReadGroupInf)
		//	if(rtint==2||rtint==3||rtint==4)
			{
CleanAndClear();
GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
if(g_speedonly)
	GetDlgItem(IDC_BUTTON5)->SetWindowText(_T("极速模式无法打开群列表"));
else
GetDlgItem(IDC_BUTTON5)->SetWindowText(_T("请稍候，正在读取群列表"));
//GRealNumRulemap.RemoveAll();
	//org_GRealNumRulemap.RemoveAll();

	str222.Format(_T("GetAllGroupNickName begin"));
		Write2MagnetLog(str222,&magnetfile,3);
		
		SetTimer(80,60*1000,NULL);
				GetAllGroupNickName();
				bAlreadyReadGroupInf=true;
				}
	
		
		LoadIgnoreFile(true);
	
		 //set<INT64> g_had_joined_groupset;



		SetWindowText(m_addtitle+_T("登录成功！"));

		str222.Format(_T("登录成功！"));
		Write2MagnetLog(str222,&magnetfile,3);
			ccccccc=GetCCCCCNum(m_ownqqnumber);
			limitnumber=ccccccc;
		g_sleepforRelogin=_T("");		
	bExitPostThread=0;

	if(g_qqregflag)
	strcpy(wangwangbuf,(CStringA)m_ownqqnumber);


	 int newlimit=limitnumber;

	 if(newlimit!=orglimit&&newlimit>=2000)
		 firstregflag=true;

	 if(!g_bTestplugexistflag&&firstregflag&&g_inputreplacemap.GetCount()!=1&&IDOK==MessageBox(_T("你是否要同步官方自带的插件和游戏，如果不同步的话，有些默认功能将不可用。"),_T("是否同步官方自带的插件和游戏"),MB_OKCANCEL))
	{
		CString defwebads,backstr;

		defwebads=_T("http://www.qqshow123.com/game/regdefgame.txt");
		::SendMessage(mainhwnd,WM_ReLoadDefGame,(WPARAM)defwebads.GetBuffer(0),(LPARAM)backstr.GetBuffer(0));
	}
	 else
	 {
	 
	 if(newlimit>=2000)
	 {
		 int rtmsgbox=0;
		 if(!g_bTestplugexistflag)
		 {
			 rtmsgbox=MessageBox(_T("您是注册用户，软件部分高级功能依赖于自带的testplug.dll插件，你必须下载最新的testplug.dll放在机器人插件目录下才能使用完整的功能，是否现在自动下载和放置它以便软件能正常运行？"),_T("是否立即自动下载默认的插件，还是以后手动下载？"),MB_OKCANCEL);
			
		 }
		 else
		 {

			// TCHAR Verdatestr[256];
			
				 //1.3.5.4.5
				 CString tempdllversionstr=g_Vertestdatestr;
				if(tempdllversionstr.GetLength()==7)
		{
tempdllversionstr.AppendChar('0');

			//3.9.2.3.3
		}
		tempdllversionstr.Replace(_T("."),_T(""));

		if(_ttoi(tempdllversionstr)<13610)
		{
			CString showtips;
			showtips.Format(_T("您是注册用户，软件部分高级功能依赖于自带的最新版的testplug.dll插件，你现在使用的testplug.dll版本是%s，而当前机器人软件需要的至少是1.3.6.1.0以上版本的testplug.dll，你必须下载最新的testplug.dll放在机器人插件目录下才能使用完整的功能，是否现在自动下载和放置它以便软件能正常运行？"),g_Vertestdatestr);
			rtmsgbox=MessageBox(showtips,_T("是否立即自动下载默认的插件，还是以后手动下载？"),MB_OKCANCEL);
		}
		 
		 }

		  if(IDOK==rtmsgbox)
			 {
			  DownloadTestplug();
			 }
	}

	 }

	if(firstregflag)
	{
		//
	}

		CString OpenFileName;
OpenFileName.Format(_T("cfqqrobotmainhwnd%s"),m_ownqqnumber);
HANDLE	m_hMapFile = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE,0,300,OpenFileName);
if(m_hMapFile)
{
void* lpMapAddr = (void*)MapViewOfFile(m_hMapFile,FILE_MAP_ALL_ACCESS,0,0,0);
if(lpMapAddr)
{
memset(lpMapAddr,0,300);
memcpy(lpMapAddr,&mainhwnd,sizeof(HWND));
lstrcpy((TCHAR*)lpMapAddr+sizeof(HWND),g_groupfilespath.GetBuffer(0));

}
FlushViewOfFile(lpMapAddr,32);
//CloseHandle(m_hMapFile);
}

	//Isggged=CheckAlreadyReg(g_qqregflag);

	

	//BOOL timeexpire=RobotCheckExpire();
//	if(limitnumber<1600)
//{
//
//	qqgroupqun=true;
//	outoutflag=true;
//	
//}

	str222.Format(_T("timeexpire over"));
		Write2MagnetLog(str222,&magnetfile,3);


	str222.Format(_T("key：%s"),(CString)Xbin.Bin2Hex(qq.key));
Write2MagnetLog(str222,&magnetfile,20);


			if(!Isggged)
	{
			
	//	g_defaultqqgrouprule.g_groupdefaultanswer=_T("");
		//g_privatedefaultanswer=_T("");
	}

if(g_speedonly&&!Isggged)
	{
	g_speedonly=false;
	AfxMessageBox(_T("未注册版本无法启用极速模式！"));
	}

if(!Isggged&&g_autologinflag)
	{
	//g_autologinflag=0;
	AfxMessageBox(_T("未注册版本功能受限，无法设置自动登录机器人号码！——如果你是刚注册的，请登录注册qq号之后再重试一次看看！"));
	
	}
	//if(!qqgroupqun)
{
	if(m_alreadylogin)
	{
			str222.Format(_T("mywinthread1=AfxBeginThread_progetfriends"));
		Write2MagnetLog(str222,&magnetfile,5);
			if(!g_speedonly)
			{
				g_readFriendOver=true;//g_readFriendOver=false;//改成动态显示好友列表
		mywinthread1=AfxBeginThread(ProGetFriends,NULL);
			}
	str222.Format(_T("mywinthread3=AfxBeginThread"));
		Write2MagnetLog(str222,&magnetfile,5);
	mywinthread3=AfxBeginThread(ProCheckMsg,(LPVOID)(LPCTSTR)psessionidstr);
	allgroupevent.SetEvent();
	friendevent.SetEvent();
	
	mywinthread4=AfxBeginThread(SendHeartBeatMsgFun,NULL);
	

	}
	}
}

}

UINT SendHeartBeatMsgFun(LPVOID lp)
{
	int sendlen=0;
	
	//[16003,"000000000000000","310260000000000","5.1.1.108280","","Heartbeat.Alive",null,537039752,537039752,"0",0,103,[0,0,0,4]]
	//[15958,"000000000000000","310260000000000","5.1.1.108280","","OidbSvc.0x7a2_0",null,537039752,537039752,"151409645",0,103,[0,0,0,15,8,-94,15,16,0,24,0,34,2,40,1]]
	
	while(!bExitPostThread)
	{
vectorbyte heartbeatvect=sdk.Pack_HeartBeat();//sdk.Pack_friendlist_getFriendGroupList(20,0);
	sdk.Fun_send(heartbeatvect);
		

	Sleep(18000);



	}
	return 0;
}
void C晨风qq机器人Dlg::OnCbnKillfocusCombo4()
{
	CString str;
	GetDlgItemText(IDC_COMBO4,str);
	if(str.GetLength()>1)
	{
		CString str2;
		
	
	}
}

void C晨风qq机器人Dlg::SetReplyConfig()
{
CModifyTitle dlg(g_autoreplymap,g_autoreplyfile1,g_Privilegeautoreplymap,g_Privilegeautoreplyfile1,this);
dlg.DoModal();
	
}
//update_group_business_card2
CKeepMap<CString,LPCTSTR,INT64,INT64> g_shutuptimemap;
CKeepMap<CString,LPCTSTR,INT64,INT64> g_shutupforpunishmap;

BOOL ShutupAll(INT64 realqqgroupnum,BOOL bShutup)
{
	
	sdk.Fun_send(sdk.Pack_ShutUpAll(realqqgroupnum,bShutup));

	return true;
}
BOOL AllGroupShutupFromQQgroup(INT64 realqqgroupnum,INT64 realqq,int secondminutes,BOOL punishedflag,BOOL bNotAffectBlackhouse/*=false*/)
{

if(secondminutes>0&&GlobalJudgeAuth(realqqgroupnum,realqq,true))
	return false;	

//if(minutes>=1)
if(!bNotAffectBlackhouse)
	{
 SetBlackhouse_endTime(realqqgroupnum,realqq,secondminutes);
}

//允许部分解除禁言，所以secondminutes可能是负数

BOOL bPartreduceflag=false;
				//lockgidbAdminresource.Lock();
				//BOOL badmin=-1;
				//if(GidbAdminMap.Lookup(realqqgroupnum,badmin))
				// if(badmin==0)
				// {
				//	
				//	 lockgidbAdminresource.Unlock();
				//	 return false;
				// }
				//	lockgidbAdminresource.Unlock();


	int actualseconds=secondminutes;//*60;
CString keystr;
	keystr.Format(_T("%I64d_%I64d"),realqqgroupnum,realqq);	
	
	INT64 shutupendtime=0;
	g_shutuptimemap.Lookup(keystr,shutupendtime);
	SYSTEMTIME curSystemTime;
			GetLocalTime(&curSystemTime);
			INT64 t1=ConvertLocalTimeToInt(curSystemTime);	

	if(secondminutes>=1)
	{
	
	
			if(shutupendtime>t1)//解禁时间晚于现在
shutupendtime=t1+(shutupendtime-t1)+secondminutes;//minutes*60;
			else//解禁时间早于现在
		shutupendtime=t1+secondminutes;//minutes*60;
			if(punishedflag)
	g_shutupforpunishmap[keystr]=punishedflag;

	g_shutuptimemap[keystr]=shutupendtime;

	actualseconds=shutupendtime-t1;
	}
	else
	{
		//$解除禁言5分钟$
		if(secondminutes<0)
			bPartreduceflag=true;

INT64 newshuttime=0;

if(secondminutes<0)
{
newshuttime=shutupendtime+secondminutes;

	actualseconds=newshuttime-t1;

	if(actualseconds<0)
	actualseconds=0;

}
		if(punishedflag)
		{
			if(bPartreduceflag)
			{
				g_shutuptimemap[keystr]=newshuttime;
			}
			
			if(newshuttime<=t1)
			{
	g_shutuptimemap[keystr]=0;
g_shutupforpunishmap.RemoveKey(keystr);
			}
		}
		else//判断一下是否可以自动解除禁言
		{

		if(g_shutupforpunishmap.Lookup(keystr))
		{
			if(newshuttime<=t1)//if(shutupendtime<=t1)//解禁时间早于现在
		g_shutupforpunishmap.RemoveKey(keystr);//顺带把受系统或管理员处罚的标志去除

return false;
		}
		else
		{
			g_shutuptimemap[keystr]=newshuttime;
			//g_shutuptimemap[keystr]=0;
		}

		}

	}
	
	//g_lastshutinf.Format(_T("%I64d_%I64d_%d"),realqqgroupnum,realqq,actualseconds);	
	
	RemoveQQFromGroup *pqqgroup=new RemoveQQFromGroup;
	pqqgroup->realqqgroup=realqqgroupnum;
	pqqgroup->realqq=realqq;
	if(bPartreduceflag)
pqqgroup->seconds=0-actualseconds;//actualminutes*60;
	else
pqqgroup->seconds=actualseconds;//actualminutes*60;
	


	AfxBeginThread(ProShutupQQFromGroup,(LPVOID)pqqgroup);
	
return true;

}

BOOL ShutupFromQQgroup(INT64 realqqgroupnum,INT64 realqq,int secondminutes,BOOL punishedflag,BOOL bNotAffectBlackhouse/*=false*/,BOOL bAllgroupflag/*=false*/)
{
		
	if(1000000==realqq)
		return false;

	if(IsSpecialQQ(realqq))
		return  false;
if(realqq==g_interfaceuin)
		return  false;

if(!bAllgroupflag)
{
return AllGroupShutupFromQQgroup(realqqgroupnum,realqq,secondminutes,punishedflag,bNotAffectBlackhouse);
}
else
{
		int ngroupsize=0;
		lockgqqnickmapresource.Lock();
			
			ngroupsize=GrouprealqqNickmap.m_mapstr.size();
		ngroupsize=min(ngroupsize,80);
			
			for(int i=0;i<ngroupsize;i++)
			{

	if(GrouprealqqNickmap.m_mapstr[i])
	{
		Sleep(100);
		AllGroupShutupFromQQgroup(GrouprealqqNickmap.m_mapstr[i],realqq,secondminutes,punishedflag,bNotAffectBlackhouse);
	}
			}
	lockgqqnickmapresource.Unlock();

}
return true;
}
BOOL AllGroupKickFromQQgroup(INT64 realqqgroupnum,INT64 realqq,BOOL bIncludingVip/*=false*/)
{
	
	
	if(GlobalIsVip(realqqgroupnum,realqq,bIncludingVip))
		return false;

	RemoveQQFromGroup *pqqgroup=new RemoveQQFromGroup;
	pqqgroup->realqqgroup=realqqgroupnum;
	pqqgroup->realqq=realqq;

		
	{

	  lockggroupmembercountsource.Lock();
	  int membercount;
	  	if(g_group_membercountmap.Lookup(realqqgroupnum,membercount))
		{
			membercount--;
			if(!bCheckingmemebercount)
	g_group_membercountmap[realqqgroupnum]=membercount;
		}
	lockggroupmembercountsource.Unlock();
	}

	AfxBeginThread(ProRemoveQQFromGroup,(LPVOID)pqqgroup);
	lockgalreadykickoutsource.Lock();
	g_alreadykickoutqqnum.insert(realqq+realqqgroupnum);
	lockgalreadykickoutsource.Unlock();
return true;
}
BOOL KickFromQQgroup(INT64 realqqgroupnum,INT64 realqq,BOOL bIncludingVip/*=false*/,BOOL bAllgroupflag/*=false*/)
{
		/*lockgidbAdminresource.Lock();
				BOOL badmin=-1;
				if(GidbAdminMap.Lookup(realqqgroupnum,badmin))
				 if(badmin==0)
				 {
					 lockgidbAdminresource.Unlock();
					 return false;
				 }
					lockgidbAdminresource.Unlock();*/

	if(1000000==realqq)
		return false;
	if(IsSpecialQQ(realqq))
		return  false;

	if(!bAllgroupflag)
	{
	return AllGroupKickFromQQgroup(realqqgroupnum,realqq,bIncludingVip);
	}
	else
	{
		int ngroupsize=0;
		lockgqqnickmapresource.Lock();
			
			ngroupsize=GrouprealqqNickmap.m_mapstr.size();
		ngroupsize=min(ngroupsize,80);
			
			for(int i=0;i<ngroupsize;i++)
			{

	if(GrouprealqqNickmap.m_mapstr[i])
{
	Sleep(100);
	AllGroupKickFromQQgroup(GrouprealqqNickmap.m_mapstr[i],realqq,bIncludingVip);
		
	}
			}
	lockgqqnickmapresource.Unlock();
	
	}
	return true;
}
void C晨风qq机器人Dlg::OnBnClickedButton4()
{


	//ShellExecute(0,0,_T("C:\\Program Files (x86)\\晨风QQ机器人\\晨风QQ聊天机器人.exe"),_T("cf_remote_login"),0,1);

		  SetReplyConfig();

	
	// TODO: 在此添加控件通知处理程序代码
}
void GetPairStrFromReadFile(LPCTSTR tempstr,CString &frontstr,CString &backstr,BOOL bEasymode/*=false*/)
{
	frontstr=tempstr;
	frontstr.Trim();
	backstr=_T("");
	CStringvect vectemp;
	CString rptempstr=tempstr;
	rptempstr.Trim();
bEasymode=false;//暂时都替换
	if(!bEasymode)
	{
rptempstr.Replace(_T("xxx"),_T("XXX"));
rptempstr.Replace(_T("×"),_T("*"));
rptempstr.Replace(_T("＋"),_T("+"));
rptempstr.Replace(_T("－"),_T("-"));
rptempstr.Replace(_T("／"),_T("/"));
rptempstr.Replace(_T("＝"),_T("="));
rptempstr.Replace(_T("！="),_T("!="));
rptempstr.Replace(_T("！＝"),_T("!="));
rptempstr.Replace(_T("＜"),_T("<"));
rptempstr.Replace(_T("＞"),_T(">"));
rptempstr.Replace(_T("＄"),_T("$"));
rptempstr.Replace(_T("％"),_T("%"));
rptempstr.Replace(_T("xml："),_T("xml:"));
rptempstr.Replace(_T("[imgurl]https://"),_T("[imgurl]http://"));
rptempstr.Replace(_T("cover=\"https://"),_T("cover=\"http://"));

//rptempstr.Replace(_T("qq"),_T("QQ"));
rptempstr.Replace(_T("qq号要求"),_T("QQ号要求"));

rptempstr.Replace(_T("%财富总额要求"),_T("%积分要求"));

rptempstr.Replace(_T("所有qq只要宝物有"),_T("所有QQ只要宝物有"));
rptempstr.Replace(_T("随机一个qq只要宝物有"),_T("随机一个QQ只要宝物有"));

	}


::function::getmytoken(rptempstr,'\t',vectemp);
		if(vectemp.size()==2)
		{
			frontstr=vectemp[0].Trim();
		backstr=vectemp[1].Trim();
		}
		else
		{
	
		if(::function::GetHalfStr(rptempstr,&frontstr,&backstr,'\t',false))
		{
		frontstr.Trim();
		backstr.Trim();
		}
		else if(::function::GetHalfStr(rptempstr,&frontstr,&backstr,' ',false))
		{
		frontstr.Trim();
		backstr.Trim();
		}

		//g_tempmap[frontstr]=backstr;
		}
		
		if(!bEasymode)
	{
	//backstr.Replace(_T("\\t"),_T("   "));
	backstr.Replace(_T("\t"),_T("   "));

	frontstr.Replace(_T("【空格】"),_T(" "));
	backstr.Replace(_T("【空格】"),_T(" "));
	}

		if(frontstr.Find(_T("//"))==0)
		{
			frontstr=_T("");

		backstr=_T("");
		}
		else
		{

			BOOL bNotrtflag=false;
			if(frontstr==_T("后续文本自动附加字段"))
			{
				g_autoappendtext=backstr;
				bNotrtflag=true;
			}
			if(frontstr==_T("后续文本自动附加在前面的字段"))
			{
				g_autoinserttext=backstr;
				bNotrtflag=true;
			}
			if(bNotrtflag)
			{
				backstr=_T("");
				frontstr=_T("");
			}
			else
			{

				backstr=backstr+g_autoappendtext;
				backstr=g_autoinserttext+backstr;
			}
		}
}
void AddtoKeepMapFromFile(CKeepStrStrVectMap &g_tempmap,const CString& frontstr,const CString& backstr,BOOL bHugeFile/*=false*/,CString* filepath/*=NULL*/)
{
	if(!frontstr.IsEmpty()&&!backstr.IsEmpty())
		{
		/*	if(g_tempmap.Lookup(frontstr))
			{
			
		g_tempmap[frontstr].insert(backstr);
			
			}
			else*/

			if(bHugeFile)
			{
			g_tempmap[frontstr].insert(g_tempmap[frontstr].end(),backstr);
			}
			else
			g_tempmap[frontstr].push_back(backstr);

			//g_tempmap.sortLen();
		}
}
void GetKeepMapFromFile(CKeepStrStrVectMap &g_tempmap,CReadAUStdioFile&file1,BOOL bEasymode/*=false*/)
{
g_tempmap.RemoveAll();
//CReadAUStdioFile file1;
	//if(file1.Open(filepath,CFile::modeRead))
BOOL bHugeFile=false;

if(file1.m_hFile!=CFile::hFileNull&&file1.GetLength()>0)
{
ULONGLONG	filesize=file1.GetLength();

			if(filesize>2*1024*1024)
				bHugeFile=true;

			if(file1.bHugeFileflag)
				bHugeFile=true;
		CString tempstr,qqstr,qqpasswordstr;
		int itemcount;
		CString frontstr,backstr;
		file1.MySeekToBegin();
		CString file1path=file1.GetFilePath();
		CString finalappendfilename;
					finalappendfilename.Format(_T("——当前句子来自于“%s”"),file1path);
					g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(file1.ReadString(tempstr))
	{
		GetPairStrFromReadFile(tempstr,frontstr,backstr,bEasymode);
		

			if(g_bAutoAppendFileName&&!backstr.IsEmpty())
				{
				
	backstr.Append(finalappendfilename);
				}
	AddtoKeepMapFromFile(g_tempmap,frontstr,backstr,bHugeFile);
	
	}
	(g_tempmap).sortLen();
	
}


}
void C晨风qq机器人Dlg::OnBnClickedButton3()
{


}


void C晨风qq机器人Dlg::OnCbnSelchangeCombo4()
{
	
	int curpos=m_combox_ownqq.GetCurSel();
if(curpos>=0)
{
	CString rstring;
	m_combox_ownqq.GetLBText(curpos,rstring);
	CString curpassword;
	LoadPassword(rstring,curpassword);
	if(!curpassword.IsEmpty())
	{
	SetDlgItemText(IDC_EDIT2,curpassword);
	}
	if (g_loginshowtext.IsEmpty())
SetDlgItemText(IDC_BUTTON1,_T("登录"));
	else
		SetDlgItemText(IDC_BUTTON1, g_loginshowtext);
g_qqserveripmap.RemoveAll();

}
}


void C晨风qq机器人Dlg::OnBnClickedCheck2()
{
	g_switchmode=((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
}




void C晨风qq机器人Dlg::OnEnKillfocusEdit1()
{

}


void C晨风qq机器人Dlg::OnBnClickedCheck5()
{
}


void C晨风qq机器人Dlg::OnBnClickedCheck6()
{
}


void C晨风qq机器人Dlg::OnCbnSetfocusCombo4()
{
}


void C晨风qq机器人Dlg::OnEnKillfocusEdit5()
{
	GetDlgItemText(IDC_EDIT5,g_content);
}

void C晨风qq机器人Dlg::OnDelIgnoreDlg()
{
	if(m_ignoredlg)
	{
	m_ignoredlg->DestroyWindow();
			delete m_ignoredlg;
m_ignoredlg=NULL;
g_ignorehwnd = NULL;
	}
}
void C晨风qq机器人Dlg::OnDelReplyconfigDlg()
{
	m_replyconfigdlg->DestroyWindow();
	
			delete m_replyconfigdlg;
			
m_replyconfigdlg=NULL;
	
}
void C晨风qq机器人Dlg::OnBnClickedButton5()
{
	//CString vecode=L"!AVR";//"nc12345q24";
	//CString qqnumstr=(LPCTSTR)L"3095087199";//hashcode;//
	//CString pwd=(LPCTSTR)L"nc12345q24";// "!KZW";
	//CString rpwd;
	//m_ownqqnumber=(LPCTSTR)L"3095087199";
	//GetQQPostPassword(pwd,vecode,vecode,rpwd);
	//return;


	if(m_ignoredlg)
	{
		m_ignoredlg->ShowWindow(SW_MINIMIZE);
		m_ignoredlg->ShowWindow(SW_RESTORE);
		m_ignoredlg->ShowWindow(SW_SHOW);
		return;
	}

	if(m_alreadylogin==false)
	{
	MessageBox(_T("如果你未先登录的话，无法查看qq群和好友列表！"));
	return;
	}


	
		backbufvect.clear();
		lockgroupnameresource.Lock();
		for(UINT i=0;i<GidNickNamemap.m_mapstr.size();i++)
		{
		backbufvect.push_back(GidNickNamemap[i]);
		}
		lockgroupnameresource.Unlock();
	//	//CIgnoreDlg dlg;
	//	//dlg.DoModal();

		if(m_ignoredlg==NULL)
		{
			m_ignoredlg=new CIgnoreDlg(this);
	m_ignoredlg->Create(CIgnoreDlg::IDD,this);
		m_ignoredlg->ShowWindow(SW_SHOW);
	//g_runflag=true;
		}
	//ShellExecute(0,0,_T("http://bbs.cfxy.me/thread-6170-1-1.html"),0,0,1);
}


void C晨风qq机器人Dlg::OnCbnSelchangeCombo5()
{
	
g_status_selcur=((CComboBox*)GetDlgItem(IDC_COMBO5))->GetCurSel();
if(g_status_selcur==6)
{
	
	QuitQQ();
		m_alreadylogin=false;
	

		SetDlgItemText(IDC_BUTTON1,_T("登录"));
}
else
{
	/*if(!m_alreadylogin)
	{
		OnBnClickedButton1();
		return;
	}*/
}
	Change_status();
}

void C晨风qq机器人Dlg::On32891()
{
	LoadPriviliegeFile();
	AfxMessageBox(_T("帮助.txt、自定义小游戏.txt、输入替换.txt、输出替换.txt、人品计算.txt、优先设定的回复内容.txt、周公解梦全集.txt、自动回复设置文件.txt、机器人管理员命令大全.txt等文件都已经重新加载！每次如果你手动修改了其中的内容，如果你希望它们立即生效，都应该点这个菜单重新加载。"));
}

void C晨风qq机器人Dlg::On32892()
{
	CString curqqnumstr;
		m_combox_ownqq.GetWindowText(curqqnumstr);
	if(!curqqnumstr.IsEmpty())
	{
	int pos=m_combox_ownqq.FindStringExact(-1,curqqnumstr);
	if(pos!=-1)
	{
	m_combox_ownqq.DeleteString(pos);
	setvector<CString>::iterator findit=find(g_loginedset.begin(),g_loginedset.end(),curqqnumstr);
	if(findit!=g_loginedset.end())
	{
	g_loginedset.erase(findit);
	}

	}
	}
		m_combox_ownqq.SetWindowText(_T(""));
}
void C晨风qq机器人Dlg::On32877()
{
	OnMyOK();
}
void C晨风qq机器人Dlg::On32878()
{
	OnBnClickedButton4();
}
void C晨风qq机器人Dlg::On32879()
{
onReFreshList(0,0);	
SetTimer(473, 1000, NULL);

}
void C晨风qq机器人Dlg::On32888()
{
	if(g_qqregflag)
	{
		if(m_alreadylogin)
		strcpy(wangwangbuf,(CStringA)m_ownqqnumber);
		else
	strcpy(wangwangbuf,(CStringA)g_lastownqq);
	}
	
		if(m_alreadylogin)
		{
	GetLimitNumber(false);
		}
	if(Isggged)
	{
	if(IDOK==MessageBox(_T("当前qq号码已经是注册版，你还需要购买和激活其它的qq号吗？"),_T("已激活"),MB_OKCANCEL))
	{
		ShellExecute(NULL,NULL,buychsRegURL,0,0,1);
	}
	if(!g_bTestplugexistflag)
	{
		DownloadTestplug();
	}
	GetCCCCCNum(m_ownqqnumber);
	//else
		//ShellExecute(NULL,NULL,_T("http://bbs.cfxy.me"),0,0,1);

	showggg=true;

	}
	else
	{
		if(m_alreadylogin)
		{
		//	if(IDOK==MessageBox(_T("你是打算通过淘宝购买还是通过在线付款自动激活平台购买？前者3天内可无条件退款，后者可优惠30元，并且实时自动激活，点“确定”通过在线付款自动激活购买，点“取消”通过淘宝购买！"),_T("选择购买渠道"),MB_OKCANCEL))
			ShellExecute(NULL,NULL,_T("http://b.qqshow123.com/"),0,0,1);
		//	else
		//ShellExecute(NULL,NULL,buychsRegURL,0,0,1);
		}
		else
		{
//MessageBox(_T("你尚未登录任何一个qq号，如果你已经注册了某个qq号，必须先在此软件上登录此号码再点“软件注册”菜单，如果你还没注册，可以在下面的链接上购买！"),_T("请注册"),MB_OKCANCEL);
		
if(IDOK==MessageBox(_T("你尚未登录任何一个qq号，如果你已经注册了某个qq号，必须先在此软件上登录此号码再点“软件注册”菜单，如果你准备注册，你是打算通过淘宝购买还是通过在线付款自动激活平台购买？前者3天内可无条件退款，后者可优惠20元，并且实时自动激活，点“确定”通过在线付款自动激活购买，点“取消”通过淘宝购买！"),_T("选择购买渠道"),MB_OKCANCEL))
		ShellExecute(NULL,NULL,_T("http://b.qqshow123.com/"),0,0,1);
			else
		ShellExecute(NULL,NULL,buychsRegURL,0,0,1);

		}
	}
//	BOOL bLocal=g_qqregflag;
//
//CRegMySoft dlg(false,bLocal);
//dlg.DoModal();
//if(Isggged)
//{
//	outoutflag=false;
//	if(lstrlen(regbuf))
//trial_ncount=2000000;
//
//qqgroupqun=false;
//}

}
void C晨风qq机器人Dlg::On32890()
{
	COtherConfig dlg;
	dlg.DoModal();


}
//104.腾讯最近推出了自己的官方qq机器人，所以最近在打压第三方的qq机器人，请勿使用重要的qq号做机器人，按照qq使用协议，腾讯确实可能会永久冻结使用第三方机器人的qq号码。这种腾讯的政策调整带来的问题，我们也没什么好办法。
void C晨风qq机器人Dlg::On32909()
{
CString realsefilepath=SaveAs_complete_path(_T("晨风机器人变量大全.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);


}
void C晨风qq机器人Dlg::On32895()
{
CString realsefilepath=SaveAs_complete_path(_T("机器人管理员命令大全.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);


}
void C晨风qq机器人Dlg::On32896()
{
CString realsefilepath=SaveAs_complete_path(_T("群聊时不回复或者没显示回复的处理办法.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);

}

void C晨风qq机器人Dlg::On32889()
{
	
	ShellExecute(NULL,NULL,_T("http://wpa.qq.com/msgrd?v=3&uin=13402429&site=qq&menu=yes"),0,0,1);

ShellExecute(NULL,NULL,_T("http://bbs.qqshow123.com"),0,0,1);
	//if(IDOK==MessageBox(poptipsformat,_T("申请加入晨风qq机器人官方交流群？"),MB_OKCANCEL))
	//{
	//	//http://shang.qq.com/wpa/qunwpa?idkey=cc797bedf1957bf7536ceec79eb85bf5f75ec7b6b8cd119575550d81f1ba85ec
	//	if(poptipsformat2.Find(_T("797"))!=-1)
	//
	//
	//}

}
void C晨风qq机器人Dlg::On32881()
{
	CString tempstr=_T("晨风QQ机器人使用说明.txt");
	if(!g_customstr.IsEmpty())
	{
	//tempstr.Replace(_T("晨风"),g_customstr);
tempstr.Replace(_T("晨风QQ机器人"),g_customstr);

	}

	ShellExecute(NULL,NULL,_T("http://www.qqshow123.com/weixin.html"),0,0,1);

MessageBox(_T("刚才打开的是常用的设置的图文教程，你也可以查看详细的文字使用说明。"),_T("详细的文字使用说明"),MB_OK);

	ShellExecute(NULL,NULL,SaveAs_complete_path(tempstr),0,0,1);
	
}
void C晨风qq机器人Dlg::On32882()
{
	if(CheckUpdateAndPrompt()==false)
	{
	if(IDOK==MessageBox(_T("暂时未发现升级版本，你也可以到官方网站上自行查看有无升级版本！"),_T("暂无升级版本，是否自行去网站查看？"),MB_OKCANCEL))
	ShellExecute(NULL,NULL,chsRegURL,0,0,1);
	}
	
}
void C晨风qq机器人Dlg::On32883()
{
QuitAndSavehistory(true);
CString historystr=::function::complete_path(_T("机器人聊天历史记录.txt"));
ShellExecute(NULL,NULL,historystr,0,0,1);

}
void C晨风qq机器人Dlg::On32884()
{
	reloadinterfaceandlayout();
	//{
	//AfxMessageBox(_T("需要在群里发“切换到卡片消息模式”，之后才能设置字体颜色！"));//暂时不支持设置字体颜色和大小！"));
	//}
	
}
void C晨风qq机器人Dlg::On32886()
{
	CAutoReplyRule dlg;
	dlg.DoModal();
}
void FreeAlldllFileHandle(LPCTSTR defpath/*=NULL*/)
{

	HINSTANCE tempdef=NULL;
	if(!defpath)
	{
	for(UINT i=0;i<g_dllpathmap.m_mapstr.size();i++)
	{
		try
		{
			//调用保存数据的函数releasedllfun
			CString paramstr;
			paramstr.Format(_T("cfrobotselfnum=%lld"), g_interfaceuin);
			GetDllresultText(g_dllpathmap.m_mapstr[i],_T("releasedllfun"),paramstr,false,paramstr);


			if(g_dllpathmap[i])
		FreeLibrary(g_dllpathmap[i]);
		CString tempstrdll=g_plusdir+g_dllpathmap.m_mapstr[i];
		g_localdllset.erase(tempstrdll);
		}
		catch(...)
		{
		
		}
	}

	g_dllpathmap.RemoveAll();
	g_vectormenustr.RemoveAll();
	HMENU menu1 = ::GetMenu(mainhwnd);
	if (g_alldllmenu_nmmcount)
	{
		g_alldllmenu_nmmcount = 3;// ::GetMenuItemCount(menu1);

		::DeleteMenu(menu1, g_alldllmenu_nmmcount,  MF_BYPOSITION );
		g_alldllmenu_nmmcount = 0;
	}

	}
	else if(defpath&&g_dllpathmap.Lookup(defpath,tempdef))
	{
	
		//调用保存数据的函数ReleaseDllFun
	
			CString paramstr;
			paramstr.Format(_T("cfrobotselfnum=%lld"), g_interfaceuin);
			GetDllresultText(defpath,_T("releasedllfun"),paramstr,false,paramstr);
			if(tempdef)
		FreeLibrary(tempdef);
		CString tempstrdll=g_plusdir+defpath;
		g_localdllset.erase(tempstrdll);
		g_dllpathmap.RemoveKey(defpath);
		g_vectormenustr.RemoveKey(defpath);
	}
	
}
void C晨风qq机器人Dlg::On32908()
{

	FreeAlldllFileHandle();
	AfxMessageBox(_T("现在可以把新的dll文件复制到“机器人插件”目录下覆盖老版本的dll文件了，点确定之后，会重新加载“自动加载的dll列表.txt”中的dll！"));
	LoadPreLoadDllFile();
}
void C晨风qq机器人Dlg::On32905()
{
ShellExecute(NULL,NULL,_T("http://b.qqshow123.com/"),0,0,1);

}
void C晨风qq机器人Dlg::On32901()
{
	qqgrouprule temprule=g_defaultqqgrouprule;
	CMoreAdminList dlg(g_defaultqqgrouprule);
	dlg.DoModal();
	if(temprule==g_defaultqqgrouprule)
	{
	//什么也不做
	}
	else
	{
	for(UINT i=0;i<GRealNumRulemap.GetCount();i++)
	{
		if(!g_bApplyAll)
		{
	if(temprule==GRealNumRulemap[i])
	{
	
		
		GRealNumRulemap[i]=g_defaultqqgrouprule;
	}
		}
		else
		{
			if(!GRealNumRulemap[i].g_onlyself||temprule.g_onlyself!=g_defaultqqgrouprule.g_onlyself)//除非改变的正是禁用默认群规
		g_defaultqqgrouprule.CompareAndCopy(temprule,GRealNumRulemap[i]);
		}

	}
	if(!Isggged&&!g_bApplyAll)
MessageBox(_T("默认群规里面的设置，是指一个qq机器人新加入的群，没进行过任何设置之前，就会自动应用这个默认群规设置。而对于那些之前已经加入了的，并且更改过任何一点设置的群，默认群规的修改并不会影响到它。除非你在第二个主菜单“选项设置”——“好友消息、加好友验证及全局设置”中勾选了“在默认群规中修改后自动应用到所有群规里”，否则如果你要针对某个群里的群规进行修改，必须先点“打开qq好友和群列表”，在弹出的窗口，先选择你想设置的群，然后点“设置选中的群的群规、黑名单等”按钮进行设置。"));
	
	}

	
}
void C晨风qq机器人Dlg::On32887()
{
	qqgrouprule temprule=g_defaultqqgrouprule;
	CAdminList dlg(g_defaultqqgrouprule);
	dlg.DoModal();
	if(temprule==g_defaultqqgrouprule)
	{
	//什么也不做
	}
	else
	{
	for(UINT i=0;i<GRealNumRulemap.GetCount();i++)
	{
		if(!g_bApplyAll)
		{
	if(temprule==GRealNumRulemap[i])
	{
	
		
		GRealNumRulemap[i]=g_defaultqqgrouprule;
	}
		}
		else
		{
			if(!GRealNumRulemap[i].g_onlyself)
		g_defaultqqgrouprule.CompareAndCopy(temprule,GRealNumRulemap[i]);
		}

	}
	if(!Isggged&&!g_bApplyAll)
MessageBox(_T("默认群规里面的设置，是指一个qq机器人新加入的群，没进行过任何设置之前，就会自动应用这个默认群规设置。而对于那些之前已经加入了的，并且更改过任何一点设置的群，默认群规的修改并不会影响到它。除非你在第二个主菜单“选项设置”——“好友消息、加好友验证及全局设置”中勾选了“在默认群规中修改后自动应用到所有群规里”，否则如果你要针对某个群里的群规进行修改，必须先点“打开qq好友和群列表”，在弹出的窗口，先选择你想设置的群，然后点“设置选中的群的群规、黑名单等”按钮进行设置。"));
	
	}

	
}
void C晨风qq机器人Dlg::On32902()
{
	if(!m_alreadylogin)
		{
		AfxMessageBox(_T("必须登录了机器人qq号之后才能进行此操作！"));
		return;
		}
	if(IDOK==MessageBox(_T("一旦你点确定恢复昨天的积分记录，则今天的积分记录将丢失，完全恢复到昨天的积分记录，你确定要进行此操作吗？——一般仅在积分文件异常，已经被清空了才进行此操作！"),_T("今天的数据将会丢失"),MB_OKCANCEL))
		{
	RestoreRankfile(1);
	AfxMessageBox(_T("所有群都已经恢复到昨天的积分记录！"));
	}
}
void C晨风qq机器人Dlg::On32907()
{
		if(!m_alreadylogin)
		{
		AfxMessageBox(_T("必须登录了机器人qq号之后才能进行此操作！"));
		return;
		}
	if(IDOK==MessageBox(_T("一旦你点确定恢复一个小时前的积分记录，则今天的积分记录将丢失，完全恢复到一个小时前的积分记录，你确定要进行此操作吗？——一般仅在积分文件异常，已经被清空了才进行此操作！"),_T("一个小时内的数据将会丢失"),MB_OKCANCEL))
		{
	RestoreRankfile(3);
		AfxMessageBox(_T("所有群都已经恢复到一个小时前的积分记录！"));
	}
}
void C晨风qq机器人Dlg::On32903()
{
		if(!m_alreadylogin)
		{
		AfxMessageBox(_T("必须登录了机器人qq号之后才能进行此操作！"));
		return;
		}
	if(IDOK==MessageBox(_T("一旦你点确定恢复前天的积分记录，则今天的积分记录将丢失，完全恢复到前天的积分记录，你确定要进行此操作吗？——一般仅在积分文件异常，已经被清空了才进行此操作！"),_T("昨天和今天的数据将会丢失"),MB_OKCANCEL))
		{
	RestoreRankfile(2);
		AfxMessageBox(_T("所有群都已经恢复到前天的积分记录！"));
	}
}
void C晨风qq机器人Dlg::On32904()
{
		AfxBeginThread(ProUpdateLatestVersion,NULL);
}
CString SpecialInsertMiddleStuffToFileName(LPCTSTR filename,LPCTSTR insertstuff)
{
	CString newfilename;
	CString frontstr,backstr;
CString ddd=::function::Getpathfromname(filename,&newfilename);
	::function::GetHalfStr(newfilename,&frontstr,&backstr,'.');
	CString newfilefn;
	
	newfilefn.Format(_T("%s%s%slog"),ddd,frontstr,insertstuff);
return newfilefn;
}

CString InsertMiddleStuffToFileName(LPCTSTR filename,LPCTSTR insertstuff)
{
	CString newfilename;
	CString frontstr,backstr;
CString ddd=::function::Getpathfromname(filename,&newfilename);
	::function::GetHalfStr(newfilename,&frontstr,&backstr,'.');
	CString newfilefn;
	
	newfilefn.Format(_T("%s%s%s%s"),ddd,frontstr,insertstuff,backstr);
return newfilefn;
}
void C晨风qq机器人Dlg::EncodeGameFile(LPCTSTR uploadfilename,CStringvect& setenvevent,BOOL bBatchflag)
{

	CString wholefilename;
CReadAUStdioFile file1;
CString tempstr;
CString wholesentence;
if(file1.Open(uploadfilename,CFile::modeRead|CFile::shareDenyNone))
{
	while (file1.ReadString(tempstr))
	{
		//if(0)
		//	MessageBox(tempstr);
		wholesentence+=tempstr;
		wholesentence+=_T("\r\n");
	}

file1.Close();
}

CString additionalencodestr;
if(g_interfaceuin)
{
	additionalencodestr.Format(_T("%lld制作此文本\t\t%lld制作此文本\r\n"),g_interfaceuin,g_interfaceuin);
wholesentence+=additionalencodestr;
}
	int returnsize=0;
			byte *temp6=new byte[wholesentence.GetLength()*15+48+1024];
			int readfilesize=wholesentence.GetLength()*2;
			char ddddeflag=1;
			CString additionalcodebuf;
			CString keyfilepath=SaveAs_complete_path(_T("自定义加密游戏文本密钥.txt"));
			//CStringvect setenvevent;
			if(setenvevent.size()==0)
			GetStrvectFromReadGameFile(keyfilepath,setenvevent);
			CString newkystr;
			if (setenvevent.size() >= 4)
			{
				newkystr = setenvevent[3];
				for (int i = 0; i < 3; i++)
				{
					additionalcodebuf += setenvevent[i];
					additionalcodebuf += _T("\r\n");

				}
				additionalcodebuf += _T("sfjsdfsfkfk");
				additionalcodebuf += _T("\r\n");
				if (setenvevent.size() >= 5)
				{
				
					additionalcodebuf += setenvevent[4];
				additionalcodebuf += _T("\r\n");
				}
			}
			
if(filedopack((byte*)wholesentence.GetBuffer(0),readfilesize,additionalcodebuf,newkystr,&g_gamekey[0],temp6,&returnsize))//Crypt::tencentt(ddddeflag,(byte*)wholesentence.GetBuffer(0),readfilesize,&g_gamekey[0],temp6,&returnsize))
{
	CFile file2;

wholefilename=SpecialInsertMiddleStuffToFileName(uploadfilename,_T(".encode."));
	
	if(file2.Open(wholefilename,CFile::modeCreate|CFile::modeWrite))
{
	file2.Write(temp6,returnsize);

file2.Close();
}

	if(!g_remoteencryptflag)
	{
		if (!bBatchflag)
		{
			CString newfilename;
			newfilename.Format(_T("加密成功，加密的文件名为：%s，你可以跟未加密的游戏文件一样发给其他用户使用，但是能防止他们篡改！"), wholefilename);
			MessageBox(newfilename, _T("加密游戏文件成功！"), 0);
		}
	}
}	
else
{
		if(!g_remoteencryptflag)
	{
			if (!bBatchflag)
			{
				MessageBox(_T("加密游戏文件失败！"));
			}
		}
}

}
void C晨风qq机器人Dlg::On32906()
{
//#ifndef _DEBUG
//	if(!Isggged)
//	{
//	AfxMessageBox(_T("只有注册用户才能使用此功能保护自己编写的游戏！"));
//		return;
//	}
//	if(!m_alreadylogin)
//	{
//	AfxMessageBox(_T("必须先登录此QQ才能使用此功能！"));
//		return;
//	}
//	if(ccccflag2-oofffnum!=g_interfaceuin)
//	{
//	g_gamekey.clear();
//	}
//	#endif
//
//
	if(!g_interfaceuin)
	g_interfaceuin=_ttoi64(g_lastownqq);

	TCHAR buflan[512]=_T("游戏文本文件|*.txt||");
	

	CStringvect vectstr;
	CFileDialog       dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, buflan, NULL);
	DWORD   MAXFILE = 10000;
	dlg.m_ofn.nMaxFile = MAXFILE;
	TCHAR*   pc = new   TCHAR[MAXFILE];
	dlg.m_ofn.lpstrFile = pc;
	dlg.m_ofn.lpstrFile[0] = NULL;

	int   iReturn = dlg.DoModal();
	if (iReturn == IDOK)
	{
		int   nCount = 0;
		POSITION   pos = dlg.GetStartPosition();
		while (pos != NULL)
		{
			vectstr.push_back(dlg.GetNextPathName(pos));
			nCount++;
		}
		delete[]pc;
	}
	else
	{
		return;
		delete[]pc;
	}
	

static BOOL oncecheck=false;
if(!oncecheck)
{
	oncecheck=true;
if(Checkdosi())
{
g_gamekey.clear();
}
}
CStringvect setenvevent;

BOOL bBatchflag = false;
if (vectstr.size() > 1)
bBatchflag = true;
for (int i = 0; i<vectstr.size(); i++)
{
	EncodeGameFile(vectstr[i], setenvevent, bBatchflag);
	
}

if (bBatchflag)
{
	MessageBox(_T("批量加密游戏文件成功！"));
}


}
void C晨风qq机器人Dlg::On32885()
{

}

void C晨风qq机器人Dlg::On32893()
{
	if(m_alreadylogin==false)
	{
	MessageBox(_T("如果你未先登录的话，无法修改竖立网名！"));
	return;
	}

	CStandUpDlg dlg;
	dlg.DoModal();
	
}

#define OpenSetFile(x) \
MessageBox(_T("修改并保存此文件后，必须点机器人第一个主菜单“文件”下的“重新加载……”子菜单，才能使设置立即起效，否则要重新启动机器人后才能起效。"));\
	CString realsefilepath=SaveAs_complete_path(_T(#x));\
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);
void C晨风qq机器人Dlg::On32897()
{
	/*MessageBox(_T("修改并保存此文件后，必须点机器人第一个主菜单“文件”下的“重新加载……”子菜单，才能使设置立即起效，否则要重新启动机器人后才能起效。"));
CString realsefilepath=SaveAs_complete_path(_T("输出替换.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);*/

	OpenSetFile(输出替换.txt)
	// TODO: 在此添加命令处理程序代码
}


void C晨风qq机器人Dlg::On32898()
{
	/*
MessageBox(_T("修改并保存此文件后，必须点机器人第一个主菜单“文件”下的“重新加载……”子菜单，才能使设置立即起效，否则要重新启动机器人后才能起效。"));
	
	CString realsefilepath=SaveAs_complete_path(_T("输入替换.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);
*/
	OpenSetFile(输入替换.txt)
}

void C晨风qq机器人Dlg::On32910()
{
	/*MessageBox(_T("修改并保存此文件后，必须点机器人第一个主菜单“文件”下的“重新加载……”子菜单，才能使设置立即起效，否则要重新启动机器人后才能起效。"));

	CString realsefilepath=SaveAs_complete_path(_T("优先设定的回复内容.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);*/
	OpenSetFile(更多个性配置.txt)
}

void C晨风qq机器人Dlg::On32899()
{
	/*MessageBox(_T("修改并保存此文件后，必须点机器人第一个主菜单“文件”下的“重新加载……”子菜单，才能使设置立即起效，否则要重新启动机器人后才能起效。"));

	CString realsefilepath=SaveAs_complete_path(_T("优先设定的回复内容.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);*/
	OpenSetFile(优先设定的回复内容.txt)
}


void C晨风qq机器人Dlg::On32900()
{
	/*MessageBox(_T("修改并保存此文件后，必须点机器人第一个主菜单“文件”下的“重新加载……”子菜单，才能使设置立即起效，否则要重新启动机器人后才能起效。"));

	CString realsefilepath=SaveAs_complete_path(_T("自定义广告尾巴.txt"));
	ShellExecute(NULL,NULL,realsefilepath,0,0,1);
*/
		OpenSetFile(自定义广告尾巴.txt)
}
void C晨风qq机器人Dlg::On32894()
{
	
	OpenSetFile(帮助.txt)


}
void GetSkey(CString &skey,CString &ptwebqqhash,CString& verifysessionhash,CString *ptvfsessionhash)
{
			char szURL[512]; // buffer to hold the URL 
LPSTR lpszData =0; // buffer to hold the cookie data 
DWORD dwSize=0; // variable to get the buffer size needed


	
InternetGetCookieA("http://www.qq.com", NULL, lpszData, &dwSize);
if (dwSize) 
{ 
// Allocate the necessary buffer. 
lpszData = new char[dwSize];

InternetGetCookieA("http://www.qq.com", NULL, lpszData, &dwSize);



	CString expressstr,rtmatchstr;
	BOOL bGetmatch;
expressstr.Format(_T("(?<=\\bskey=)@\\w+\\b"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(!bGetmatch)
	{
	expressstr.Format(_T("(?<=\\bskey=)\\w+\\b"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	}
	if(bGetmatch)
	{
skey=rtmatchstr;
//uin=o0013402429;
expressstr.Format(_T("(?<=\\buin=o)\\d+\\b"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
//m_ownqqnumber=rtmatchstr;
//m_ownqqnumber.TrimLeft(_T("0"));
//g_interfaceuin=_ttoi64(m_ownqqnumber);


	}
	
	expressstr.Format(_T("(?<=\\bpgv_pvid=)\\d+\\b"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
m_pgv_pvid=rtmatchstr;

	}
	}
	expressstr.Format(_T("(?<=\\bptwebqq=)\\w+\\b"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
ptwebqqhash=rtmatchstr;
	}
	//verifysession=h02yn6vsCnZFobe_uSt3kFojo62gpsQ6rtVTYCYmXUdEowVjKtyMv6hwx1uPYG4ZDXp6QMrI5S-Dsta16b1I02fWg**
	//if(0)
	//MessageBoxA(0,(char*)lpszData,0,0);
expressstr.Format(_T("(?<=\\bverifysession=).+?(?=;)"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
verifysessionhash=rtmatchstr;
	}
	else
	{
	expressstr.Format(_T("(?<=\\bverifysession=).+"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
verifysessionhash=rtmatchstr;
	}

	}

	if(ptvfsessionhash)
	{
expressstr.Format(_T("(?<=\\bptvfsession=).+?(?=;)"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
*ptvfsessionhash=rtmatchstr;
	}
	else
	{
	expressstr.Format(_T("(?<=\\bptvfsession=).+"));
	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
	if(bGetmatch)
	{
*ptvfsessionhash=rtmatchstr;
	}
	}

	}
//expressstr.Format(_T("(?<=\\bverifysession=).+?(?=;"));
//	bGetmatch=GetFirstRegMatch((char*)lpszData,expressstr,rtmatchstr,true);
//	if(bGetmatch)
//	{
//verifysessionhash=rtmatchstr;
//	}
//
	//ptwebqq=bb8c016a320b395ababffabca84a9d24550ca0c6cb3922ccf17b404dbb36f6a0

	delete[]lpszData; 
}

}


LRESULT C晨风qq机器人Dlg::OnNcHitTest(CPoint point)
{
	  CRect rc;
           GetClientRect(&rc);
           ClientToScreen(&rc);
           return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);   //鼠标如果在客户区，将其当作标题栏
}

void C晨风qq机器人Dlg::NavigateOnce()
{
	
	
	//static int onceflag=0;
	//if(onceflag==0)
	//{
	//	onceflag=1;
 //m_pHTMLPage = new CJavascriptDlg; 
	//CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIClogin); 
 //  // pStatic->MoveWindow(&rc); 
 //    m_pHTMLPage->CreateFromStatic(pStatic, this); 

 // 	wchar_t wszPath[MAX_PATH + 1] = {0};
	//::GetModuleFileName(NULL, wszPath, MAX_PATH);
	//CString strUrl;
	//strUrl.Format(L"res://%s/%d", wszPath, IDR_HTML_TEST);
	// m_pHTMLPage->Navigate2(strUrl, NULL, NULL);
	////m_pHTMLPage->Navigate(L"C:\\Users\\lan\\Desktop\\新建文件夹\\webqq解码\\tettt.html");
	//}
}
void C晨风qq机器人Dlg::OnBnClickedCheck3()
{
	int temp_Androidflag=((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();


	CString tipsstr;
	if(m_alreadylogin)
	{
	tipsstr.Format(_T("机器人已处于登录状态，所以只有在下次重新登录的时候，这项更改才会生效。"));
	}
g_bQQflag=temp_Androidflag;
	
}



void C晨风qq机器人Dlg::On32911()
{
EasyExit();
FreeAlldllFileHandle();			
		TCHAR bufselfpath[256];
		GetModuleFileName(NULL,bufselfpath,256);

	
		ShellExecute(0,0,bufselfpath,0,0,1);
		exit(0);
}


void C晨风qq机器人Dlg::On32912()
{
	SaveGroupRuleAndNickName();
	
		SaveRankFile();
MessageBox(_T("手动保存群规文件和积分文件完毕！"));

}
void C晨风qq机器人Dlg::On32916()
{

	lockqqmsgdlgres.Lock();
	for(UINT i=0;i<m_mapqqmsgdlg.m_mapstr.size();i++)
		{
			
			m_mapqqmsgdlg[i]->ReLoadRankRobSpeakFile();
			
		
		}
	lockqqmsgdlgres.Unlock();
	

MessageBox(_T("手动重新加载群规文件和积分文件完毕！"));

}


void C晨风qq机器人Dlg::OnBnClickedButton7()
{
	On32887();
}


void C晨风qq机器人Dlg::On32913()
{
	CString oncedefgamefn=SaveAs_complete_path(_T(""));
	ShellExecute(0,_T("explore"),oncedefgamefn,0,0,1);
}
void C晨风qq机器人Dlg::On32914()
{
	//http://www.bodajh.com/chat/bodagonggao1.asp

	CColorURLInput urldlg;
	urldlg.DoModal();
CString safestr=urldlg.m_smsstr;
	safestr.Trim();

	//CMockHtmlDlg dlg(safestr);//_T("http://www.bodajh.com/"));//http://qun.qq.comhttps://ui.ptlogin2.qq.com/cgi-bin/login?hide_title_bar=1&no_verifyimg=1&link_target=blank&appid=549000912&target=self&f_url=loginerroralert&s_url=http://qun.qq.com"));
	CMockHtmlDlg *tempmsgdlg;
		tempmsgdlg=new CMockHtmlDlg(safestr,this);
	tempmsgdlg->Create(CMockHtmlDlg::IDD,NULL);


//dlg.DoModal();

}
void C晨风qq机器人Dlg::On32915()
{
	g_notipadflag = !g_notipadflag;

	CMenu *menu1 = AfxGetMainWnd()->GetMenu();
	CMenu *pp = menu1->GetSubMenu(2);
	if (g_notipadflag)
	{
		pp->ModifyMenu(17, MF_BYPOSITION | MF_CHECKED, ID_32915, _T("切换到手机在线而不是平板在线"));
	
	}
	else
		pp->ModifyMenu(17, MF_BYPOSITION | MF_UNCHECKED, ID_32915, _T("切换到手机在线而不是平板在线"));
}
