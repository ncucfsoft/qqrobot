
// 晨风qq机器人.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once
//机器人创始人通过跟机器人私聊屏蔽和开启哪些群，每个群有效日期截至时间。
//


#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif
class CMsgDlg;
#include "resource.h"		// 主符号
//#include "d:\\项目代码\\public_RC\\fourcom_IDC.h"
const TCHAR cneng_share_title[2][256]={_T("晨风qq机器人——支持QQ2011、2012版本"),_T("QQ Skin tool--for QQ2011 or later")};
const TCHAR cneng_registryKeyName[2][256]={_T("晨风qq机器人"),_T("QQ Skin tool")};
const TCHAR cneng_shortcutname[2][256]={_T("晨风qq机器人"),_T("QQ Skin tool")};
const TCHAR cneng_Ignore_avoided[2][256]={_T("已屏蔽"),_T("已开启")};
const TCHAR cneng_Ignore_normal[2][256]={_T("正常接收"),_T("默认关闭")};
const TCHAR cneng_Ignore_overtime[2][256]={_T("过期屏蔽"),_T("过期关闭")};
const INT64 basetime=1381924903;
extern set<INT64> g_forever_blacklist;
extern set<INT64> temp_forever_blacklist;
extern set<INT64> tempdel_forever_blacklist;
extern BOOL bDllOver6dayflag;
extern BOOL bExeOver10dayflag;
extern BOOL g_tipsflag;
extern int g_def_nickname_len;
extern int g_def_preplusnickname_len;
extern BOOL bCheckingmemebercount;
extern 	BOOL g_transfertonoxmlwhenless;
extern CCriticalSection lockqqimgres;
extern CKeepMap<INT64,INT64,CString,LPCTSTR> g_qq2lastimgmap;
extern int ResponseExtMsg(LPCTSTR sendmsgW,WPARAM wParam);
extern UINT ProNoticeToGroup(LPVOID lp);
extern BOOL IsDefaultGroupOwner(INT64 uin,BOOL bTrueqq);
extern CKeepMap<CString,LPCTSTR,INT64,INT64> g_shutuptimemap;
extern BOOL g_realrowNum;
extern CString g_xmlhead;
extern CKeepMap<INT64,INT64,CString,LPCTSTR> g_discusslist;
extern void MySendWeb3(LPCTSTR realhostname, LPCTSTR processpath, byte *imagebytebuf, char* sttt, UINT& ddlen, LPCTSTR headstr, LPTSTR locationurl);
extern void SaveFriendAndGroupNamelist();

extern void LoadPreLoadDllFile();
extern void FreeAlldllFileHandle(LPCTSTR defpath=NULL);
 typedef struct _idiombuf
 {
	 TCHAR buf[7];
 
 }idiombuf;

 typedef struct _rushstuffbuf
 {
	 TCHAR askbuf[300];
	 TCHAR answer[50];

 TCHAR *hugeaskbuf;
 TCHAR *hugeanswer;
	 _rushstuffbuf()
 {
	 hugeaskbuf = NULL;
	 hugeanswer = NULL;
 }
 }rushstuffbuf;
  typedef struct _NoticeStruct
{
INT64 qqgroupid;
CString content;
CString uin_liststr;
//68663216,151409645,3086977168

}NoticeStruct;
  extern int g_bAutoAppendFileName;
  extern CCriticalSection lockqqmsgdlgres;
 extern int jjj;//另一个注册备份
 extern BOOL g_DoWordTrueversion;
 typedef vector<byte> vectorbyte;
typedef const vector<byte> const_vectorbyte;
 typedef CKeepMap<INT64,INT64,CString,LPCTSTR> CKeepINT64StrMap;
typedef CKeepMap<INT64,INT64,CStringA,LPCSTR> CKeepINT64StrAMap;

 typedef CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>> CKeepStrStrVectMap;
 typedef CKeepMap<CString,LPCTSTR,setvector<CString>*,setvector<CString>*> CKeepStrStrPVectMap;
 extern void ReLoadGameFile();
 extern int myintabs(int f);
 extern INT64 myabs(int f);
 extern void DownloadWebResultTxt(LPCTSTR httpfile,CString& tempstr2,BOOL Isautoredirect=true);
 extern BOOL ReadInternetTxtFile(LPCTSTR webpath,CString& txtcontent,BOOL bShishicaiflag=false,BOOL bGB3212flag=false);
 extern void GeturlencodeUtf2MCString(LPCTSTR urlecho,CString& outstr);
 extern CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> GrouprealqqNickmap;
extern CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> last_GrouprealqqNickmap;
extern BOOL TestGetRegEX(const TCHAR* wordbuf,LPCTSTR exphrase,vector<CString>& findvect,BOOL bSubFlag,BOOL bCanbeBlank);
 extern CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> Android_GrouprealqqNickmap;
 extern CKeepMap<INT64,INT64,CReadAUStdioFile*,CReadAUStdioFile*> GRealFilemap;
extern CKeepMap<INT64,INT64,CKeepStrStrVectMap*,CKeepStrStrVectMap*> GRealReplymap;
extern CKeepMap<INT64,INT64,CReadAUStdioFile*,CReadAUStdioFile*> GPrivilegeRealFilemap;
extern CKeepMap<INT64,INT64,CKeepStrStrVectMap*,CKeepStrStrVectMap*> GPrivilegeRealReplymap;
extern CKeepMap<CString,LPCTSTR,INT64,INT64> g_rplevelmap;
extern CKeepMap<INT64,INT64,set<INT64>,set<INT64>> g_group_uinsetMap;
extern CKeepMap<INT64,INT64,CEvent*,CEvent*> g_group_LastGroupNickNameeventMap;
extern CKeepMap<INT64,INT64,CStringvect,CStringvect> g_group_LastGroupQQvectMap;
extern CKeepStrStrMap g_gameinputfilepathmap;
extern CKeepStrStrMap g_gamesetencefilepathmap;
void GeturlencodeUtfCString(LPCTSTR urlecho, CString& outstr);
extern CString GetNewcheckSignCode();
extern CString GetNewQQNumForEncode(INT64 qqnum);
extern CKeepStrStrVectMap g_filepath2outreplacemap;
extern TCHAR g_Verdatestr[1256];
extern TCHAR g_Vertestdatestr[1256];
extern int g_xmlgetmaxsize;
extern int g_anotherxmlgetmaxsize;
extern CString emoji11flag2unicode(const CString& emojibuf);
extern int g_mymaxxmlnum;
extern CString g_purenumberversion;
extern CString g_checksinstr;
extern CString g_modifydate;
extern CString g_moreselfgamedir;
extern CString bbbtempstr;
extern SYSTEMTIME g_locallasttime;
extern SYSTEMTIME g_localtestlasttime;

extern set<INT64> g_otherwelcome_groupset;
extern set<CString> g_reservecmdset;
extern BOOL MatchStar(LPCTSTR keystar,LPCTSTR wholestr,CString* rtregstr=NULL);
extern BOOL IsRegxReply(LPCTSTR standreply, BOOL bIncludingbracket = false);
extern BOOL g_bStoprecognizegroupimage;
extern CStringvect g_selfdeftailvector;
extern set<INT64> g_had_joined_groupset;
extern INT64 g_lastinvitegroupnum;
extern CKeepMap<CString, LPCTSTR, CString, LPCTSTR> g_vectormenustr;
extern INT64 FindAlreadyExistQQ(INT64 newqqnum);
extern UINT ProQuitGroup(LPVOID lp);
extern void ReplaceRandomText(CString& orgtext);
extern INT64 GetRealGroupnumberFromGid(INT64 gid);
extern BOOL QuerySingleItem(LPCTSTR qqnumstr,CString& rtitemstr);
extern void LoadIgnoreFile(BOOL bLoad);
extern void LoadDefDirGameFile(const CString& g_moreselfgamedir,CString& temp_gameliststr,CKeepStrStrPVectMap& temp_gamePrivilegeautoreplymap,CKeepStrStrVectMap& temp_inputreplacemap,CKeepStrStrVectMap& temp_outputreplacemap,CKeepStrStrVectMap& temp_variousvalueMap,CStringvect& temp_variousvalueVector);
extern CString Getfinalmergegroupname(LPCTSTR groupname);
extern void AddValidDaysforSomeGroup(LPCTSTR groupname,int days,CString& lastvalidtime);
extern void GetValidTime(INT64 nowtime,CString& nowtimestr);
extern int NoChineseRobNum(LPCTSTR wstr,INT64& qqnum,INT64& score);
extern void GetWebReturnContent(CString& wstr,CStringvect& weather6vect);
extern BOOL InsertExternalData(LPCTSTR orgtext,CString& actualhellowstr);
extern CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> g_group_uinNameMap;
extern CKeepMap<INT64,INT64,CKeepINT64StrAMap*,CKeepINT64StrAMap*> g_group_LastCardNameMap;
extern set<INT64>  g_alreadywelcomeqqnum;
extern set<INT64>  g_alreadykickoutqqnum;
extern BOOL g_temporaryignorall;
extern BOOL g_autoagreeinvite;
extern CCriticalSection lockdislikevectres;
//extern void LoadRushFile(LPCTSTR rushfilename);
extern void GetPerfectnamecard(const CString& prefixstr,CString& curcardname,BOOL bxxx);
extern BOOL IsExistQQ(INT64 m_realgroupnumber,INT64 qq1,BOOL bNotBank=false);
extern BOOL IsNumberChar(LPCTSTR numchar,BOOL bSigned=false,BOOL bATflag=false,BOOL bIncludingfloat=false);
extern BOOL slk2pcmfun(byte*slkbuf, int slklen, OUT byte *pcmbuf, OUT UINT* pcmlen);
extern void CallffmpegRarFun(const CString& sourcepath);
extern BOOL IsTimeOver(INT64 nowtime);
extern BOOL ConvertAndCompareTime(LPCTSTR timestr,INT64& nowtime);
extern BOOL IsGuesspsrockFun(LPCTSTR itstr,CString *outpsr,INT64 *score);
extern BOOL IsIgnoreOrShutupGroup(INT64 groupuin);
extern BOOL IsIgnoreOrShutupGroupForName(LPCTSTR groupuinname);
extern void MakeSureExistQQ(INT64 m_realgroupnumber,INT64 qq1,INT64 initscore);
extern BOOL GetTitleAndScore(const CString& comstr,CString&title,INT64 &score);
extern BOOL GetGroupQQNickName(INT64 realGroupUin,CStringvect& getgroupidbackstr,CStringvectA& getutfnamebackstr,byte* bytebuf=NULL);
extern BOOL Android_GetGroupQQNickName(INT64 realGroupUin,CStringvect& getgroupidbackstr,CStringvectA& getutfnamebackstr,int timeout);
//extern BOOL GetUinSingleWholeQQInf(INT64 groupid, INT64 uin, CString& nickname, int& bMale, NickSex* rttempnicksex, int timeout,BOOL bAnyway=false);
extern void GetqqlevelFromMap(INT64 finalqqnum,int& qqlevel,int& qqdarenlevel,int& qqlikenum,int timeout,BOOL retryflag);
extern BOOL GetLastFilemd5Value(CString& temprtmd5, byte* copypicsrc, byte* picsrc, int& filesize);
extern CKeepMap<INT64,INT64,BOOL,BOOL> GidbAdminMap;
extern CCriticalSection lockgidbAdminresource;
extern CKeepMap<INT64,INT64,CString,LPCTSTR> g_querysongquickmap;
//extern CKeepMap<int,int,pbmsg_retryinf,pbmsg_retryinf> g_pbsendvectorbyte_map;
extern CCriticalSection lockgsendvectorbyteresource;
extern CKeepMap<CString,LPCTSTR,HINSTANCE,HINSTANCE> g_dllpathmap;
extern BOOL LocalPlugFunction(LPCTSTR webpath,CString& txtcontent);
extern int BaiduKnowResponse(const CString& trimusermsg,LPTSTR responsemsg);
extern void MyTerminateThread(  __in HANDLE hThread,__in DWORD dwExitCode);
extern BOOL OpenSingleReplyFile(INT64 realgroupqqnum);
extern void  GetRPtitle(LPCTSTR namestr,OUT CString& titlestr);
extern void  GetNameMatch(LPCTSTR namestr,OUT CString& titlestr);
extern void GetRandAnswer(CString& answerstr,const setvector<CString>& answerset,int defpos=-1);
extern BOOL IsSamrtKeyWord(const CString& checkintempstr);
extern BOOL IsExpressQuery(const CString& checkintempstr,CString* expresscode,CString *querynum);
extern BOOL QueryPoemResponse(const CString& trimusermsg,LPTSTR responsemsg);
extern BOOL IsHidePoemQuery(const CString& checkintempstr,int* type57,CString *querystr);
extern BOOL IsShareSong(const CString& checkintempstr,CString *querystr,CString *addtionalstr);
extern void GlobalOmitwardword(CString& nickname,BOOL strictflag=true,BOOL bReplaceTrim=true,BOOL bOnlyawardorpunish=false,BOOL bNotwithdrawimg=true);
extern BOOL IsBaikeQuery(const CString& checkintempstr,CString* querycode);
extern BOOL IsBaiduKnowQuery(const CString& checkintempstr,CString* querycode);
extern BOOL IsforecastWeather(const CString& trimusermsg,CString* cityname);
extern BOOL IsQQvisit(const CString& trimusermsg,CString* qqnumber);
extern BOOL IsQuerySlaves(const CString& trimusermsg,CString* qqnumber,int* num);
extern BOOL IsFreeSlave(const CString& trimusermsg,CString* qqnumber);
//extern INT64 ConvertTimeToInt(const SYSTEMTIME &t1);
extern INT64 ConvertLocalTimeToInt(const SYSTEMTIME &t1);
extern SYSTEMTIME TimetToLocalTime(INT64 t);
extern int GlobalJudgeAuth(INT64 groupnumber,INT64 uin,BOOL bTrueqq=true);
extern int CCCCCNumMorethan(LPCTSTR cccnum);
extern DWORD GetNowTimeSimplenumFrom();
extern HWND GetCMsgDlgHwndFromGroupNum(INT64 groupid,BOOL bForce=false);
//extern BOOL IsAuctionSlave(const CString& trimusermsg,CString* qqnumber,INT64* auctionscore);
extern BOOL IsBidForSlave(const CString& trimusermsg,INT64* bidscore);
extern BOOL IsforeAdditionalQuery(const CString& trimusermsg,CString* querystr);
extern int GetLimitNumber(BOOL bLocal);
//extern void GetNickNameFromGroupMap(INT64 m_realgroupnumber,INT64 rprealqq,CString& nickname,INT64 uin/*=NULL*/);
extern CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_cityidmap;
extern vector<CWinThread *>  g_getlastgroupWinThreadvect;
extern vector<rushstuffbuf> g_rushstuffvect;
extern CReadAUStdioFile g_autoreplyfile1;
extern CReadAUStdioFile g_Privilegeautoreplyfile1;
extern CKeepStrStrVectMap g_autoreplymap;
extern int g_history_maxsize;
extern CString g_windowstext;
const int goodsnum=6;
extern int g_initscore;
extern int m_myg_tk;
extern int ccccccc;
extern BOOL g_DoTwiceflag;
extern UINT appSeq;
extern UINT g_randomnumforsend;
extern UINT g_recgroupmsgxuhao;
extern CKeepMap<INT64,INT64,CString,LPCTSTR> g_checkqqwhere_map;
extern INT64 ccccflag2;
extern INT64 oofffnum;
extern INT64 g_interfaceuin;
extern TCHAR robotlink[256];
extern INT64 mysecondoffsetnum;
extern BOOL g_getcheckweb;
extern CKeepStrStrMap g_expresscodemap;
extern vector<CString> g_divinevector;
extern set<INT64> g_alreadydivine_set;
extern set<INT64> g_alreadyaward_set;
extern void halfChinese(INT64 dignum,CString& rthalfstr);
extern int GetposLastChsNum(const CString& ChsStr);
extern void Chinese2ArabianNum(CString& ChsStr);
extern void FullNum2HalfNum(CString& ChsStr);
extern void WithDrawSomeOne(INT64 groupid,const CString& content);
extern UINT ProGetQQMoreProfileInf(LPVOID lp);
extern BOOL GetTitleAndScoreAndLikeNum(const CString& comstr,CString&title,INT64 &score,INT64 &likenum);
extern BOOL TrimLeft(CString& wholetrimstr,LPCTSTR trim);
extern BOOL TrimRight(CString& wholetrimstr,LPCTSTR trim);
extern void ArabianNum2Chinese(INT64 dignum,CString& ChsStr,LPCTSTR wholerptempstr2=NULL);
extern BOOL  IsSpecialQQ(INT64 qqnum,BOOL bIncludeBank=true);
extern CString g_groupfilespath;
extern CString g_specifygrouprankpath;
extern CString g_ksidmd5;
extern CString uu_username;
extern CString uu_pwd;
extern 	DWORD inittime;
extern INT64 initsystemtime;
extern setvector<CString> g_weaponnamelist;
extern CString g_sourceweb;
extern CString g_additionalsourceweb;
extern CString g_defgameweb;
extern CString g_buycardweb;
extern CString g_agreeinviteweb;
extern CString g_defgamefn;
extern CString g_additionalprewords;
extern CString g_checkinformatstr;
extern CString g_equipformatstr;
extern CString g_gamroboformatstr;
extern BOOL bCrackFlag4;
extern set<CString> g_localdllset;
extern int g_checkgroupmembertime;
extern void RegexReplace(CString& rp_tempstr2,LPCTSTR str1,LPCTSTR str2);
extern CString g_cfxysourceweb;
extern CString g_cfxysourceweb2;
extern CString g_groupimgurl;
extern CCriticalSection lockgnameresource;
extern CCriticalSection lockgalreadykickoutsource;
extern CCriticalSection lockggroup_uinsetmap;
extern CCriticalSection lockreadgroupnickres;
extern CCriticalSection lockwelcomeqqnumres;
extern CStringvect g_namematchvect;
extern TCHAR *responsebuf;
extern BOOL g_allowuseawardgoods;
extern CString g_customstr;
const int sizesize=500*1024;
const int MAXGROUPNUM=80;
extern setvector<CString> g_loginedset;
extern CKeepStrStrVectMap g_Privilegeautoreplymap;
extern CKeepMap<int,int,CEvent*,CEvent*> g_socketeventMap;
extern CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_UploadGroupImgMaxp;
extern CKeepStrStrMap g_playsongreplymap;
extern CKeepStrStrPVectMap g_gamePrivilegeautoreplymap;
extern CKeepStrStrVectMap g_variousvalueMap;
extern CStringvect g_variousvalueVector;
extern set<INT64> g_forever_blacklist;
extern INT64 StrToHash(LPCTSTR str);
extern void AwardOrPunishDirect(INT64 realqqgroupnum,INT64 realqqnum,INT64 score);	
extern void GetPairStrFromReadFile(LPCTSTR tempstr,CString &frontstr,CString &backstr,BOOL bEasymode=false);
extern 	CString g_autoappendtext;
extern	CString g_autoinserttext;
extern void GetExactGroupNickName(INT64 m_groupuin,CString& nickname);
extern BOOL KickFromQQgroup(INT64 realqqgroupnum,INT64 realqq,BOOL bIncludingVip=false,BOOL bAllgroupflag=false);
extern BOOL ShutupFromQQgroup(INT64 realqqgroupnum,INT64 realqq,int secondminutes,BOOL punishedflag=true,BOOL bNotAffectBlackhouse=false,BOOL bAllgroupflag=false);
extern BOOL ShutupAll(INT64 realqqgroupnum,BOOL bShutup);
extern BOOL GetUinSingleNickName(INT64 m_realgroupnumber,INT64 uin,CString& nicknamestr,int& bMale,int timeout);
extern void GetNickNameFromGroupMap(INT64 m_realgroupnumber,INT64 rprealqq,INT64 uin,CString& nickname);
extern void Regex_Replace2Blank(CString& wholegoodsname,LPCTSTR expressstr,LPCTSTR notblankstr);
extern CKeepMap<int,int,setvector<CString>,setvector<CString>> g_taskcmd_map;
//extern CStringvect g_idiomvect;
extern BOOL g_slientmode;
extern CKeepMap<CString,LPCTSTR,INT64,INT64> g_shutupforpunishmap;
extern vector<idiombuf> g_idiomvect;
extern CKeepStrStrMap g_dreamreplymap;
extern CKeepStrStrMap g_regoutputvect;
extern CKeepMap<INT64,INT64,INT64,INT64> UinRealNumMap;
extern INT64 GetGUinFromRealGroupqqNum(INT64 realgroupqqnum);
extern CKeepMap<INT64,INT64,CMsgDlg*,CMsgDlg*> m_mapqqmsgdlg;
extern CKeepMap<INT64,INT64,vector<_waittowithdrawmsg>,vector<_waittowithdrawmsg>> g_waittowithdrawmsg_map;
extern  CCriticalSection lockwaittowithdrawmsgmap;
extern void LoadInputReplacemap(LPCTSTR path,CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>& inoutreplacemap,int type=0,LPCTSTR keystr=NULL,LPCTSTR valuestr=NULL);//type==0,读取，type==1，添加keystr，type==2，删除keystr
extern void LoadOutputReplacemap(LPCTSTR path,	CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>& inoutreplacemap,int type=0,LPCTSTR keystr=NULL,LPCTSTR valuestr=NULL);//type==0,读取，type==1，添加keystr，type==2，删除keystr
extern BOOL g_allxmlflag;
extern BOOL g_honestflag;
extern BOOL g_closeplugfunction;
extern set<INT64> g_quit_groupid_set;
extern CCriticalSection lockg_quit_groupidres;
void AppendPlugsMenu();
extern int  ResponseFun(LPCTSTR usermsg,LPTSTR responsemsg,LPCTSTR qqnum=NULL,LPCTSTR groupnum=NULL,BOOL bBaiduFind=true);
extern void SaveRankFile();
extern void LoadBanWordFile();
extern void GetTotal_content_vect(CStringvect &m_total_content,LPCTSTR contentstr);
extern void ChangebusinessCard(INT64 realqqgroupnum,INT64 realqq, LPCTSTR cardname);
extern void GetNickNameFromGroupMap(INT64 m_realgroupnumber,INT64 rprealqq,CString& nickname,INT64 uin=NULL);
extern 	INT64 FinnalGetUinFromRealqqAndGroup(INT64 m_realgroupnumber,INT64 realqqnum);
extern BOOL GetGroupUinNickName(INT64 groupuin);
extern void GetLatestGroupInf(INT64 groupid);
extern BOOL MySendWeb(LPCTSTR realhostname,LPCTSTR processpath,byte *imagebytebuf,const char* sttt,UINT& ddlen,BOOL bHttps=false,LPCTSTR additionalhead=NULL);
extern float GetRandomTimeStr(CString &str);
extern void GetSkey(CString &skey,CString &ptwebqqhash,CString &verifysessionhash,CString *ptvfsessionhash=NULL);
extern BOOL QQRPost(LPCTSTR realhostname,LPCTSTR processpath,const CStringA& rstructstr,byte* imagebytebuf,UINT &ddlen);
extern BOOL GetNickNameFromGroupUinMap(INT64 m_groupuin,INT64 cur_uin,CString& tempnamestr);
extern void ConvertVariousValue(INT64 m_realgroupnumber,CString& rtfmtstr,INT64 backupuin);
extern void GetOldCardName(INT64 m_groupuin,INT64 cur_uin,CString& oldcardname);
extern BOOL LocalPlugFunction(LPCTSTR webpath,CString& txtcontent);
extern INT64 GetRealGroupnumberFromGid(INT64 gid);
extern CKeepMap<INT64,INT64,CString,LPCTSTR> RealGroupNumNickNamemap;
extern BOOL bNoGameflag;
extern CString g_grouprankpath;
extern CString g_plusdir;
extern CString g_sleepforRelogin;
extern CString str222;
extern BOOL g_bShowChineseNum;
extern BOOL g_workindiscussgroup;
extern BOOL g_doubletipPrivate;
extern CString g_skey;
extern CString g_qqsuperkey;

//extern CString malecardcharacter;
//extern CString femalecardcharacter;

extern CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>> g_inputreplacemap;
extern CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>> g_outputreplacemap;
extern CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_privilegeoutputreplacemap;
extern BOOL companyverion;
extern CCriticalSection lockqqnickgender;
extern CCriticalSection lockLastCardNameMap;
extern CCriticalSection lockmanualchangecarMap;
extern CCriticalSection locklastchangecomMap;
extern CKeepMap<INT64,INT64,set<CString>,set<CString>> g_manualchangecarmap;
extern CKeepINT64StrMap g_lastchangecommap;;
extern CCriticalSection lockandroidmembercountsource;
extern CKeepMap<INT64,INT64,int,int> g_androidgroup_membercountmap;
extern CCriticalSection lockuinrealqqres;
extern CCriticalSection lockupgroupimgeventmapres;
extern CCriticalSection locksocketmapres;
extern CCriticalSection lockcancelmsgmapres;
extern CCriticalSection lockweb2md5mapres;
extern CCriticalSection lockg_singleqqinfmapres;
extern CCriticalSection lockg_qqdarenlevelinfmapres;
extern CCriticalSection lockg_qqdarenlevelgetting;

extern CString g_groupimgdir;
extern CString g_voicedir;
extern CString g_voicenextip;
extern BOOL g_bLocalSaveflag;
extern CString g_uploadimgnextip;
extern CCriticalSection lockg_uploadimgip;
extern void GetNextUPloadImgIP();
extern void GetNextVoiceIP();
extern CEvent newprivateimgsendmsg;
extern vector<CString> total_privateimgurlvect;
extern CCriticalSection lockpiuvect;
extern BOOL GetFilemd5Value(CString& temprtmd5,BOOL localflag,BOOL httpflag,BOOL bPrivateimgflag);
extern UINT ProWaitUploadPrivateImg(LPVOID lp);
extern BOOL GetRealQQSingleNickName(INT64 m_realgroupnumber,INT64 realqq,CString& nicknamestr,int& bMale,int timeout);
extern BOOL SetBlackhouse_endTime(INT64 globalrealqqgroup,INT64 globalrealqqnum,INT64 minutes);
extern BOOL AndroidUpGroupImg(INT64 m_realgroupnumber,CString& httpaddress,int timeout,BOOL bUploadAnyway,INT64 toqq);
extern BOOL GetSynUploadGroupImg(INT64 groupid,INT64 qqnum,LPCTSTR md5str,LPCTSTR httpaddress,LPCTSTR postfixstr,int filesize,int timeout);
extern CKeepMap<CString,LPCTSTR,CEvent*,CEvent*> g_upgroupimgeventMap;
extern CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_web2md5Map;
extern CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_privateweb2md5Map;
extern CString GetUploadImgMd5(const CString& httpaddress,int *filesize);
extern CKeepMap<CStringA,LPCSTR,privateimginf,privateimginf> g_md5imginfMap;
extern BOOL g_bforward2owner;
extern BOOL g_bGetdirectimgurl;
extern BOOL g_bShowWholeSongAds;//显示完整的点歌网址
extern BOOL g_bNewUserGuestPlusTime;//新进群友名片前缀改成游客加时间
extern BOOL g_bForbidReJoin;//禁止重复加群
extern BOOL g_bwelcomealways;//重复进群每次都发欢迎词

extern BOOL g_bAutoQuitIfExpire;//超过有效期后自动退群
extern CString g_bAutoReportAds;//自动回报机器人在线状态的接口网址
extern int g_DefaultValidDays;//拉机器人进群后默认有效期天数
extern BOOL g_bIgnoreAnyAgreeOrDeny;//不处理任何同意或拒绝加群的事务
extern BOOL g_bIgnoreDeny;//不处理拒绝加群的事务
extern BOOL g_bAllowCreateCookies;//允许机器人生成cookies文件
extern BOOL g_bMustDefShowWeb;//必须明确写了显示网址内容才显示网页内容
extern CString g_bMust2receiver;//必须明确写了显示网址内容才显示网页内容
extern CString g_bMustappend2receiver;//必须明确写了显示网址内容才显示网页内容

extern CString g_App_key_str;//小i机器人app_key
extern CString g_App_secret_str;//小i机器人app_secret
extern BOOL g_bAllowSamepinyin;//成语接龙支持同音字而不需要是同一个字
extern BOOL g_bautosavetalk;//自动保存httpapi所需要的输入和输出数据
extern void ExchangeWebContent(CString& externData, const CString& md5urlstr);
extern BOOL ComPareTwoWordPinyin(TCHAR word1,TCHAR word2);
typedef struct _qqnickgender
{
	TCHAR namebuf[256];
	int bMale;
}qqnickgender;
//extern CKeepMap<INT64,INT64,qqnickgender,qqnickgender> g_realqqnamegender_map;

typedef struct _qqgrouprank
{
INT64 total_score;
INT64 ownerqq;
INT64 bidprice;
INT64 vipendtime;
INT64 blackhouse_endtime;
INT64 likenum;//每签到一次后就可以赞或贬3次，1级要0个赞，2级要10个赞、3级要30个赞，4级要40个赞、10级要100个赞，10级之后，每升一级，需要多100赞。即11级需要200赞，12级300、19级1000赞，20级1100赞。等级10的人赞一次值10个赞，赞一次可从对方身上得到对应次数签到的奖励
INT64 leftlikenum;
INT64 lefthatenum;
INT64 jointime;
INT64 totalspeaktimes;
INT64 lastactivetime;
int qqscore;
INT64 last_lastacttivetime;//不用保存到文件中
//提高等级在打劫中的权重

//增加群友之间赞或贬的功能，机器人主人每次最多可赞或贬群友1万次，管理员每次签到后有20次机会，普通群友每次签到过后有3次机会赞或贬他人，(vip次数翻倍)，总赞数低于-20的群友会被禁言10分钟。
//10级的群友赞一次值10个赞（贬一次，则扣对方10个赞）
CString timevectstr;
CString enemyvectstr;

CString medalgoods[goodsnum];//0是勋章；1是幸运石；2是防御；3是武器 4是房产 5是坐骑

bool operator < (const _qqgrouprank &m)const 
	{
		return total_score < m.total_score;
	}
bool operator > (const _qqgrouprank &m)const 
	{
		return total_score > m.total_score;
	}
void  setInitScore(INT64 tempinitscore)
{
total_score=tempinitscore;//g_initscore;

}
void resetdata()
{
	for(int i=0;i<goodsnum;i++)
	{
medalgoods[i]=_T("无");
	}
timevectstr=_T("0;");
enemyvectstr=_T(";");


}
_qqgrouprank()
{
	ownerqq=0;
	bidprice=100;
	vipendtime=0;
	blackhouse_endtime=0;
	likenum=0;
	leftlikenum=0;
	lefthatenum=0;
totalspeaktimes=0;
total_score=g_initscore;//g_initscore;
qqscore=0;
SYSTEMTIME curSystemTime;
			GetLocalTime(&curSystemTime);
			INT64 t1=ConvertLocalTimeToInt(curSystemTime);	
jointime=t1;
lastactivetime=0;
last_lastacttivetime=0;

resetdata();

}
}qqgrouprank;

typedef struct _qqgroupgamblerobtimes
{
int activeday;
int gambletimes;
int wintimes;
INT64 winscore;
int robtimes;
int robwintimes;
INT64 robwinscore;


void reset()
{
gambletimes=0;
robtimes=0;
wintimes=0;

winscore=0;
robwintimes=0;
robwinscore=0;
}
_qqgroupgamblerobtimes()
{
	activeday=0;
	reset();
}

}qqgroupgamblerobtimes;
typedef struct _qqgroupspeakrank
{
	int activeweek;
int speaktimes;

static int getcurrentweek()
{
	
	SYSTEMTIME st;
GetLocalTime(&st);
	CTime time1(st);
	int nowtime=time1.GetTime();
CTime time2(st.wYear,1,1,0,0,0);
	int dayweek=st.wDayOfWeek;
	if(dayweek==0)
		dayweek=7;
	int startWeek = time2.GetDayOfWeek();
	if(startWeek == 0)
	startWeek = 7;
	int time1v=time1.GetTime();
	int time2v=time2.GetTime();
	
	int sccc=(time1v-time2v)/(24*60*60);

int weekNum = (sccc+startWeek-dayweek)/7 + 1;


	
	return weekNum;

}
bool operator < (const _qqgroupspeakrank &m)const 
	{
		
		return speaktimes< m.speaktimes;
	}

bool operator > (const _qqgroupspeakrank &m)const 
	{
		return speaktimes > m.speaktimes;
	}

_qqgroupspeakrank()
{
	activeweek=0;
speaktimes=0;
}
}qqgroupspeakrank;

// CKeepMap<INT64,INT64,qqgrouprank,qqgrouprank> g_rankmap;
 typedef  CKeepMap<INT64,INT64,qqgrouprank,qqgrouprank> CQQRankKeepMap;

 typedef  CKeepMap<INT64,INT64,qqgroupspeakrank,qqgroupspeakrank> CQQSpeakRankKeepMap;

typedef  CKeepMap<INT64,INT64,qqgroupgamblerobtimes,qqgroupgamblerobtimes> CQQGamblerobtimesKeepMap;

  extern CKeepMap<INT64,INT64,CQQRankKeepMap*,CQQRankKeepMap*> g_grouprankmap;

   extern CKeepMap<INT64,INT64,CQQGamblerobtimesKeepMap*,CQQGamblerobtimesKeepMap*> g_groupgrtimesmap;
 extern BOOL GlobalIsInBlackList(INT64 realqqgroupnum,INT64 realqqnum);
 extern BOOL GlobalIsVip(INT64 realqqgroupnum,INT64 realqqnum,BOOL bIncludingVip);
extern qqgrouprank & GetGlobalMyRank(INT64 globalqqgroup,INT64 qq1,BOOL noClearExpire=false);
extern void SetProbationTime(INT64 globalqqgroup,INT64 qq1);

 extern CKeepMap<INT64,INT64,CQQSpeakRankKeepMap*,CQQSpeakRankKeepMap*> g_groupspeakrankmap;
 extern CKeepMap<INT64,INT64,set<INT64>,set<INT64>> g_group_realqqvectMap;
 extern CKeepMap<INT64,INT64,HWND,HWND> g_realgroup_hwndMap;
 extern CKeepMap<INT64,INT64,INT64,INT64> g_pitchguessMap;
 extern CCriticalSection lockggroup_realqqsetmap;
 extern CKeepMap<INT64,INT64,int,int> g_group_membercountmap;
extern CKeepMap<INT64,INT64,INT64,INT64> g_group_ownerqqmap;
extern BOOL g_forbidsaveanyrankfile;
 extern void RestoreRankfile(int daynum);
 extern void GetRankFromFile(BOOL bLoad,INT64 realgroupnumber,int daynum=0);
extern void GetSpeakRankFromFile(BOOL bLoad,INT64 realgroupnumber);
extern void GetGambleRobTimesFromFile(BOOL bLoad,INT64 realgroupnumber);
extern INT64 GetnumFromVect(LPCTSTR vectstr);
extern INT64 GetWholenumFromVect(LPCTSTR vectstr);
//extern SYSTEMTIME TimetToSystemTime(INT64 t);
extern INT64 GetnumFromTime(const SYSTEMTIME &t1);
typedef struct _retryStruct
{
	int retrycount;
	BOOL bReadover;
	_retryStruct()
	{
	retrycount=0;
	bReadover=false;
	}
}retryStruct;

extern CKeepMap<INT64,INT64,retryStruct,retryStruct> g_group_uinRetryMap;
typedef struct _qqgrouprule
{

int g_allowallshutitup;
int g_group_request_method;

int g_checkin;
int g_gamble;
int g_rob;
int g_totalshutitup;
int g_idiomfun;
int g_rushfun;
int g_guessfun;
int g_guesspsrock;
INT64 m_selfrealqqgroupnum;
BOOL g_sessionanswerfalg;
int g_talk;
int g_percent;
int g_timeover;
int g_continuefind;
int g_includekey;
int g_autonoticetime;
int g_forbidden;
int g_onlyself;
int	g_scale;
int g_scale_idiom;
int	g_scale_rush;
int	g_scale_crazy;
int	g_times_crazy;

int	g_timeout_rush;
int	g_timeout_idiom;
int	g_nperson_rush;
int g_idiom_cost;
int g_gamble_cost;
int g_rob_cost;
int g_query_cost;
int g_rush_punish_cost;
int g_singlexmlflag;
INT64 belowscore;
int spamtimes;
CString kickspamtips;
int bShowkindstips;
int bTatalSlient;
int bOpenSelfDefGame;
int g_checkperiod;
int g_gamblerobtimes;

int g_privateadminanswer;
int g_tipsotheradmin;
int g_publicanswer;
int g_allowallanswer;
int g_byprivate;
int g_speakaward;
int g_punishshua;
int g_queryfun;
int m_tax_percent;
int m_dropequipscale;
int m_allowprivaterush;
BOOL m_stopfunction;
int forbidadminset;
INT64 gambletopvalue;
INT64 adminawardtop;
int lotteryprice;
int repeatcheckfine;
int luckynumbercost;
int guesspsrcost;
int likevalue;
int probationminutes;
int maxreplywithinmin;
int minutes_mustdosomething;
int action_mustdowhat;
int punish_otherwise;

INT64 robneedLowestRankNum;
int robneedwaitTime;
int initscore;
int paybackscale;
int gamblehardscale;
int bidwaittime;
int bidbacknum;

int hatemustover;
int m_forbidprivate;
int m_rankwithlike;

CString rushprefixstr;

CString lotteryopentime;
CString precardstr;
CString femaleprecardstr;
CString nnnnprecardstr;
CString adminprecardstr;
CString m_modifycardurl;
CString g_ranktitlestr;
CString g_storeprice;
CString timetask;
CString g_coinname;
CString g_hellowstr;
CString g_prefixstr;
CString g_groupdefaultanswer;
CString g_robotname;
CString g_group_denyreason;
CString g_blackliststr;
CString g_banliststr;
CString g_forwordkeyliststr;
CString g_vipliststr;
CString g_tradegrouplist;
CString g_welcomestr;
CString lastwelcomestr;
CString g_group_pincodestr;//群验证消息为某某某时自动同意
int g_group_pinqqlevel;//加群的qq等级大于等于多少时自动同意
int g_group_pinqqdarenlevel;//加群的qq达人等级大于等于多少时自动同意

CString g_adminliststr;
set<INT64> g_robotadminsset;
set<INT64> g_blacklist;
setvector<CString> g_banlist;
setvector<CString> g_forwordkeylist;
set<INT64> g_viplist;
set<INT64> g_tradelist;


#define COPYGROUP(x) this->x=copyrule.x;
_qqgrouprule& operator = (const _qqgrouprule& copyrule)
{
	
		COPYGROUP(g_adminliststr)
		COPYGROUP(g_allowallshutitup)
		COPYGROUP(g_blackliststr)
		COPYGROUP(g_banliststr)
		COPYGROUP(g_forwordkeyliststr)
		COPYGROUP(g_vipliststr)
		COPYGROUP(g_robotadminsset)
		COPYGROUP(g_blacklist)
		COPYGROUP(g_banlist)
		COPYGROUP(g_forwordkeylist)
		COPYGROUP(g_viplist)
		COPYGROUP(g_tradelist)
		COPYGROUP(g_group_denyreason)
		COPYGROUP(g_group_request_method)
		COPYGROUP(g_welcomestr)
		COPYGROUP(lastwelcomestr)
		COPYGROUP(g_checkin)
		COPYGROUP(g_gamble)
		COPYGROUP(g_idiomfun)
		COPYGROUP(g_rushfun)
		COPYGROUP(g_guessfun)
		COPYGROUP(g_guesspsrock)
		COPYGROUP(m_forbidprivate)
COPYGROUP(m_rankwithlike)
		COPYGROUP(g_rob)
		COPYGROUP(g_sessionanswerfalg)
		COPYGROUP(g_totalshutitup)
		COPYGROUP(g_group_pincodestr)
		COPYGROUP(g_talk)
		COPYGROUP(g_percent)
		COPYGROUP(g_timeover)
		COPYGROUP(g_continuefind)
		COPYGROUP(g_includekey)
		COPYGROUP(g_privateadminanswer)
		COPYGROUP(g_tipsotheradmin)
		COPYGROUP(g_publicanswer)
		COPYGROUP(g_allowallanswer)
		COPYGROUP(g_prefixstr)
		COPYGROUP(g_groupdefaultanswer)
		COPYGROUP(g_robotname)
		COPYGROUP(g_byprivate)
		COPYGROUP(g_speakaward)
		COPYGROUP(g_punishshua)
		if(copyrule.m_selfrealqqgroupnum)
		COPYGROUP(m_selfrealqqgroupnum)
		COPYGROUP(g_forbidden)
		COPYGROUP(g_onlyself)
		COPYGROUP(g_autonoticetime)
		COPYGROUP(g_hellowstr)
		COPYGROUP(g_scale)
		COPYGROUP(m_tax_percent)
COPYGROUP(m_dropequipscale)

		COPYGROUP(g_scale_idiom)
		COPYGROUP(g_scale_rush)
		COPYGROUP(g_scale_crazy)
		COPYGROUP(g_times_crazy)
COPYGROUP(g_group_pinqqlevel)
COPYGROUP(g_group_pinqqdarenlevel)
COPYGROUP(g_timeout_rush)
COPYGROUP(g_timeout_idiom)
COPYGROUP(g_nperson_rush)
COPYGROUP(g_idiom_cost)
COPYGROUP(g_gamble_cost)
COPYGROUP(g_rob_cost)
COPYGROUP(g_query_cost)
COPYGROUP(g_rush_punish_cost)
COPYGROUP(g_singlexmlflag)
COPYGROUP(belowscore)
COPYGROUP(spamtimes)
COPYGROUP(bShowkindstips)
COPYGROUP(bTatalSlient)
COPYGROUP(bOpenSelfDefGame)
COPYGROUP(kickspamtips)
COPYGROUP(forbidadminset)
COPYGROUP(gambletopvalue)
COPYGROUP(adminawardtop)
COPYGROUP(precardstr)
COPYGROUP(femaleprecardstr)
COPYGROUP(nnnnprecardstr)
COPYGROUP(adminprecardstr)
COPYGROUP(m_modifycardurl)
COPYGROUP(lotteryprice)
COPYGROUP(repeatcheckfine)
COPYGROUP(luckynumbercost)
COPYGROUP(guesspsrcost)
COPYGROUP(likevalue)
COPYGROUP(probationminutes)
COPYGROUP(maxreplywithinmin)
COPYGROUP(minutes_mustdosomething)
COPYGROUP(action_mustdowhat)
COPYGROUP(punish_otherwise)

COPYGROUP(robneedLowestRankNum)
COPYGROUP(robneedwaitTime)
COPYGROUP(initscore)
COPYGROUP(paybackscale)
COPYGROUP(gamblehardscale)
COPYGROUP(bidwaittime)
COPYGROUP(bidbacknum)

COPYGROUP(hatemustover)
COPYGROUP(lotteryopentime)
COPYGROUP(rushprefixstr)
		COPYGROUP(g_tradegrouplist)
		COPYGROUP(g_coinname)
		COPYGROUP(g_queryfun)
		COPYGROUP(m_allowprivaterush)
		COPYGROUP(g_checkperiod)
		COPYGROUP(g_gamblerobtimes)
		COPYGROUP(g_ranktitlestr)	
		COPYGROUP(g_storeprice)	
COPYGROUP(timetask)	
	return *this;
}
_qqgrouprule(const _qqgrouprule& copyrule)
{
	*this=copyrule;
}
_qqgrouprule()
{
	g_prefixstr=_T("#");
g_adminliststr=_T("13402429;");
g_talk=1;
g_forbidden=0;
g_onlyself=0;
g_autonoticetime=0;
g_hellowstr=_T("我是$robotname$，face0x3DD81CDE 欢迎大家找我聊天（输入#你想聊的话题）或者签到，也可输入冒险游戏、修炼打怪、#笑话、抽奖、成语接龙、扔红包、南昌天气、百科感冒、#星座水瓶座、百度南极有多冷、顺丰快递431185755652等查询各类信息。\r\n想获知更多机器人指令和功能，请发送help或帮助。\r\n=======================\r\n可以轮流发送不同的广播内容,欢迎大家找我聊天（输入#你想聊的话题）或者签到，也可输入#星座水瓶座、#笑话、扔红包10个、#成语接龙、#南昌天气、#百科感冒、#顺丰快递431185755652等查询各类信息，欲知更多，请发送：帮助");
g_scale=1;
m_tax_percent=10;
m_dropequipscale=100;
g_scale_idiom=1;
g_scale_rush=1;
g_scale_crazy=1;
g_times_crazy=7;
g_group_pinqqlevel=0;
g_group_pinqqdarenlevel=0;
g_nperson_rush=10;
g_idiom_cost=1;
g_gamble_cost=2;
g_rob_cost=5;
g_query_cost=1;
g_rush_punish_cost=0;
g_singlexmlflag=0;
belowscore=99999999999;
spamtimes=5;
bShowkindstips=1;
bTatalSlient=0;
bOpenSelfDefGame=1;
kickspamtips=_T("XXX赢得了一张免费机票，大家欢送他起飞～");
forbidadminset=1;
gambletopvalue=1000;
adminawardtop=1000;
precardstr=_T("♂");
femaleprecardstr=_T("♀");
nnnnprecardstr=_T("⊙-");
lotteryprice=10;
repeatcheckfine=1;
luckynumbercost=10;
guesspsrcost=10;
likevalue=20;
probationminutes=0;
maxreplywithinmin=1000;
minutes_mustdosomething=5;
action_mustdowhat=0;
punish_otherwise=2;
robneedLowestRankNum=30;
robneedwaitTime=60;
initscore=0;
paybackscale=20;
gamblehardscale=100;
bidwaittime=20;
bidbacknum=5;

hatemustover=0;
lotteryopentime=_T("12|20");
rushprefixstr=_T("");
g_timeout_idiom=45;
g_timeout_rush=60;
g_tradegrouplist=_T("");
g_coinname=_T("金币");
g_queryfun=1;
g_group_denyreason=_T("自动给出拒绝理由");
g_groupdefaultanswer=_T("");//$回声$？
g_checkperiod=8;
g_gamblerobtimes=20;
g_ranktitlestr=_T("乞丐\t-5\t0\r\n贫民\t0\t10\r\n富农\t30\t20\r\n侍从\t50\t30\r\n军士\t100\t40\r\n骑士\t300\t50\r\n领主\t500\t80\r\n勋爵\t2000\t100\r\n男爵\t5000\t200\r\n子爵\t6000\t300\r\n伯爵\t7000\t400\r\n侯爵\t8000\t500\r\n公爵\t9000\t600\r\n王爷\t10000\t700\r\n国王\t15000\t800\r\n教皇\t30000\t900\r\n上帝\t100000\t2000");
g_storeprice=default_g_storeprice;
timetask=_T("");//设置初始运行时间【定时任务游戏】\t62点\r\n一分钟后领取每周第一天的礼包\t星期一16点10分\r\n扔红包100个\t星期一16点11分\r\n开启签到功能\t 0

//不能随意更改顺序
g_banliststr=_T("yunpan.cn;彩钻;混网全部技术;肏;贱鸡;鸡巴;互赞;教程地址;卖刷钻;");//q[\\s:：]*\\d{5,12};yunpan.cn;宽带徒弟;宽带钻;彩钻;收徒;混网全部技术;约炮;肏;贱鸡;鸡巴;
//兼职;小号信誉;接单;爆款;代练金币;代练;刷流量;出售充值软件;帮开淘宝店铺;需要联系我;出售qb;出售Q币;网赚;秒单;互赞刷赞;客服QQ;联系客服;欢迎来到酷Q的世界~如果您是我的主人的话，请发送[帮助]了解设置酷Q的方法哦;刷全部人物坐骑刷枪;信誉;经营;腾讯老板;需要请;工作室;无限刷;免费领取;日工资;押金;咨询Q;这女;代刷;小窗口;加Q;日赚;裸聊;联系QQ;联系电话;大家玩下去;把我踢了;歌舞;激情;日结算;招聘;垃圾刷手;店铺托管;装修服务;扣扣裙;空间业务;天天飞车金币;宽带钻;需要M我;刷销量;软件下载;出售6.7位Yy号刷天天酷跑金币;出租高成长Yy号;赚点零用;招商;分销;刷单;北京商城;淘宝客;成人用品;本公司;速度加;代销;草你妈;傻逼;傻比;傻逼机器人;请加QQ;破机器;快来;速办;酷Q;快小窗口;约炮;少妇Q;免费聊骚;咨询热线;免费开私服;QQ:;联系Q;这女的太开放了;诚招代理;批发;诚邀加盟;详情请加Q;兼职人员;小时工;注册速办;转发;发给qq;加qq;操你妈的机器人;办卡;指路;指路天使;qqlite;qqpuls;联系我;窃听器;代办发票;代开;发票;香烟无需押金;无需抵押;百元无需押金;招聘兼职日赚;验证后付;抵押贷款;股票刷信誉;迷情药;迷情yao;代刷QB;招聘网络兼职;工资日付;信誉刷钻;垃圾机器人;出售枪支;仿真假钞;高息贷款;催情药;各种证件;加入;交流股票票;股票輑;验证1000人专业刷钻;轻松赚网络兼职;网上赚保证日赚;刷枪;急招;免费币;淘宝兼职;刷QQ飞车;走私香煙;本煙行;批發;聯系;包郵;裸聊qq;加盟费;无抵押;无担保;刷QQ钻;月赚;在线就能赚代刷会员;网上兼职;秒进;赚QB;诚信代刷;公司兼职;日结工资;每天在线时间;六肖;薪水日结;股票加诚;专业刷Q币;上网赚;代办;加群：;高档香烟;股票进验加裙;信誉保年薪;一笔一结;专业刷信誉;加入我们;股票交流无抵押免担;信用贷款;崔情药水;迷奸水;激情招;进群写;互刷流量;高仿烟;最火兼职;千人群招人;垃圾群内不回;网站电话;大量网址链接;邀请您访问;火爆招募;你还寂寞吗;你还寂寞么;点击一下;专业生产;质量可靠;价格优惠;有效证件;专业办理;看完不资金账户;第三代网店;假一赔十;低价批发;七天不满意无条件;出售大量肉鸡;全国货到付款;期待您加入;把这个消息;培训网站;我要退考后付款;考前发放;出售答案;专业代考;限时秒杀;厂价直销;请问您吗;点进去看一下;来时写上;公司地址;无需资金;注册全套公司;代理记帐;进群学习交流;护肤交流帮忙点一下;不转死全家;诚招;代理加盟;在家自主创业;大批量订购;质量保请一定诚信交易;全网最低价;帮忙转发一下;不转对不起自己;腾讯周年;腾讯生日;转发一下;注册即请私密;学历提高;承接;业务;招聘在线待遇丰厚;网店培训;公司代理发货;中国平安贷款;工会招收;招聘信息;美女主持;待遇从优;梦龙水宫;咨询电话;后场JI团队;宫斗;马化腾亲戚;想开淘宝网店吗;培训淘宝新手;代理发货;专业培训;正品保工商代理;执照年检;看看我刚刚建立的;有意向;皇冠信誉;有量详谈;老牌代理;全自动冲值提款;特权总代;年信誉;有意详谈;资金包赔;游戏代练;推荐给大家;无毒免费;今天是腾讯;QQ连升;超级代理;有量者咨询;欢迎前来咨询;消息连发;低价供货;招收分站;桑拿会所;预约电话;欢迎加我;火暴新区;火热招;做魅力女人;不咨询后悔一辈子;常年首区;官方网站;报名电话;一手资源;火爆测试;请转发;直播间;只加女性;激情聊天;特价促销;YY频道;只赚信誉;新店开张;不看后悔;返利网;群内不设回复;此信息及长期有效;火爆网页游戏;全场包邮;一个月不买日货;抵制;是中国人的就量大从优;年龄不限;肌肤测试;皮肤测试;仅此一天;群内不回复;是中国人;群不回;质量100%保七天退换货;爱国的就转发;加微信;期待您的加入;本店经营;是中国人就转发;专业交友;点这个网址;感兴趣的加我;绝无病毒;全国包邮;欢迎各位的到来;高薪招聘;开服;货到付款;有意者来电;服务电话;上门服务;我也是被逼的;见者不发全家;代收货款;特价全部现货;晚上开放;找炮友;未成年人远离;代理教程;诚信互赞;有赞有回;快速办理;群多不回复;排位代练;活动期间;赶快来加入吧;有意者窗口;把我踢出去;不转对不起自己的良心;帮忙转一下;优质货源;分钟到帐;火热报名;加盟代理;证书办理;提升学历;需要小窗;相互收藏;谁群多;转一下;云赚;想开网店;演出服装;专业定制;群发机;手续齐全;收徒;加QQ;加妹妹QQ;夜话紫禁城;夜激情;坐台;针孔摄像机;男女公关;手机监控;短信群发;代购有偿;上门看货;不成功不收费;全國貨到付款;经济周火爆收人;真人视频;无返利;薪酬厚待;有意致电;不网聊;绝对真实;最高返利;保密发货;赌术教学;价格实惠;咨询;群以屏蔽;本人收购;开张;视频服务;激情视频;详情;业务代理;赶快加入吧;视频聊天;可竭诚上门;合作以上内容使用自动发豪迪QQ群发器;捡到经验;请进;日结;价格从优;自动冲;提款;招收代理;刷钻;
//g_forwordkeyliststr=_T("注册;购买;付费;怎么注册;怎么购买;vip怎么");

g_percent=50;
g_timeover=0;
g_continuefind=1;
g_includekey=0;
g_speakaward=0;
g_punishshua=0;
g_privateadminanswer=0;
g_tipsotheradmin=0;
g_publicanswer=1;
g_allowallanswer=0;
m_selfrealqqgroupnum=0;
g_totalshutitup=false;
g_allowallshutitup=false;
g_group_request_method=1;//0:不处理 1:自动 2：拒绝 3：女性自动进群
g_byprivate=1;
g_checkin=1;
g_gamble=1;
g_idiomfun=1;
g_rushfun=1;
g_guessfun=1;
g_guesspsrock=1;
m_forbidprivate=0;//2015.12.29 0
m_rankwithlike=1;
m_stopfunction=0;
m_allowprivaterush=0;
g_rob=1;
g_sessionanswerfalg=0;
g_welcomestr=_T("☆欢☆ 【网名】face0x3DD84FDC （$性别$）@$QQ$\r\n☆迎☆ 【群名】face0x3CD87ADF $群名称$\r\n☆新☆ 【群号】face0x3CD83ADF $群号码$\r\n☆人☆ 【注意】face0x3DD814DD进群请勿发广告,刷屏,漫骂,共享木马等！\r\n$奖励20009898$邀请者$ 1隐藏$你来自$加群来源$\r\n$操作者$$操作行为$你加入本群！\r\n你是当前群第$群成员数量$个成员！$修改名片$QQ$$\r\n=======================");//\r\n欢迎您加入【$群名称$】！\r\n你是当前群第$群成员数量$个成员！\r\n请遵守群规，有问题找群主！
g_robotname=_T("机器人");





}
#define COMPARECOPY(X) \
v1=this->X==p2.X;\
		if(!v1)\
{\
			copyto.X=this->X;\
}
void CompareAndCopy(const _qqgrouprule &p2,_qqgrouprule &copyto)
    {
		BOOL v1;
		COMPARECOPY(g_adminliststr)
		COMPARECOPY(g_allowallshutitup)
		COMPARECOPY(g_blackliststr)
		COMPARECOPY(g_group_denyreason)
		COMPARECOPY(g_group_request_method)
COMPARECOPY(g_welcomestr)
COMPARECOPY(lastwelcomestr)
COMPARECOPY(g_checkin)
COMPARECOPY(g_gamble)
COMPARECOPY(g_sessionanswerfalg)
COMPARECOPY(g_totalshutitup)
COMPARECOPY(g_group_pincodestr)
COMPARECOPY(g_idiomfun)
COMPARECOPY(g_rushfun)
COMPARECOPY(g_guessfun)
COMPARECOPY(g_guesspsrock)
COMPARECOPY(m_forbidprivate)
COMPARECOPY(m_rankwithlike)

COMPARECOPY(g_talk)
COMPARECOPY(g_percent)
COMPARECOPY(g_timeover)
COMPARECOPY(g_continuefind)
COMPARECOPY(g_includekey)
COMPARECOPY(g_privateadminanswer)
COMPARECOPY(g_tipsotheradmin)
COMPARECOPY(g_publicanswer)
COMPARECOPY(g_allowallanswer)
COMPARECOPY(g_prefixstr)
COMPARECOPY(g_groupdefaultanswer)
	COMPARECOPY(g_robotname)
	COMPARECOPY(g_byprivate)
	COMPARECOPY(g_speakaward)
	COMPARECOPY(g_punishshua)
	COMPARECOPY(g_forbidden)
COMPARECOPY(g_autonoticetime)
COMPARECOPY(g_hellowstr)
COMPARECOPY(g_scale)
COMPARECOPY(m_tax_percent)
COMPARECOPY(m_dropequipscale)
COMPARECOPY(g_scale_idiom)
COMPARECOPY(g_scale_rush)
COMPARECOPY(g_scale_crazy)
COMPARECOPY(g_times_crazy)
COMPARECOPY(g_group_pinqqlevel)
COMPARECOPY(g_group_pinqqdarenlevel)
COMPARECOPY(g_timeout_rush)
COMPARECOPY(g_timeout_idiom)
COMPARECOPY(g_nperson_rush)
COMPARECOPY(g_idiom_cost)
COMPARECOPY(g_gamble_cost)
COMPARECOPY(g_rob_cost)
COMPARECOPY(g_query_cost)
COMPARECOPY(g_rush_punish_cost)
COMPARECOPY(g_singlexmlflag)
COMPARECOPY(belowscore)
COMPARECOPY(spamtimes)
COMPARECOPY(bShowkindstips)
COMPARECOPY(bTatalSlient)
COMPARECOPY(bOpenSelfDefGame)
COMPARECOPY(kickspamtips)
COMPARECOPY(forbidadminset)
COMPARECOPY(gambletopvalue)
COMPARECOPY(adminawardtop)
COMPARECOPY(precardstr)
COMPARECOPY(femaleprecardstr)
COMPARECOPY(nnnnprecardstr)
COMPARECOPY(adminprecardstr)
COMPARECOPY(m_modifycardurl)
COMPARECOPY(lotteryprice)
COMPARECOPY(repeatcheckfine)
COMPARECOPY(luckynumbercost)
COMPARECOPY(guesspsrcost)
COMPARECOPY(likevalue)
COMPARECOPY(probationminutes)
COMPARECOPY(maxreplywithinmin)
COMPARECOPY(minutes_mustdosomething)
COMPARECOPY(action_mustdowhat)
COMPARECOPY(punish_otherwise)
COMPARECOPY(robneedLowestRankNum)
COMPARECOPY(robneedwaitTime)
COMPARECOPY(initscore)
COMPARECOPY(paybackscale)
COMPARECOPY(gamblehardscale)
COMPARECOPY(bidwaittime)
COMPARECOPY(bidbacknum)
COMPARECOPY(hatemustover)
COMPARECOPY(lotteryopentime)
COMPARECOPY(rushprefixstr)
COMPARECOPY(g_tradegrouplist)
COMPARECOPY(g_checkperiod)
COMPARECOPY(g_ranktitlestr)
COMPARECOPY(g_banliststr)
COMPARECOPY(g_rob)
COMPARECOPY(g_gamblerobtimes)
COMPARECOPY(g_forwordkeyliststr)
COMPARECOPY(g_vipliststr)
COMPARECOPY(g_onlyself)
COMPARECOPY(g_storeprice)
COMPARECOPY(timetask)
COMPARECOPY(g_coinname)
COMPARECOPY(g_queryfun)
COMPARECOPY(m_allowprivaterush)
COMPARECOPY(g_robotadminsset)
COMPARECOPY(g_blacklist)
COMPARECOPY(g_banlist)
COMPARECOPY(g_forwordkeylist)
COMPARECOPY(g_viplist)
COMPARECOPY(g_tradelist)


    };
#define COMPARECOUNT(x) totalcount+=this->x==p2.x;


 bool operator==(const _qqgrouprule &p2)
    {
		int totalcount=0;
		
		COMPARECOUNT(g_adminliststr)
		COMPARECOUNT(g_allowallshutitup)
		COMPARECOUNT(g_blackliststr)
		COMPARECOUNT(g_group_denyreason)
		COMPARECOUNT(g_group_request_method)
		COMPARECOUNT(g_welcomestr)
		COMPARECOUNT(g_checkin)
		COMPARECOUNT(g_gamble)
		COMPARECOUNT(g_sessionanswerfalg)
		COMPARECOUNT(g_totalshutitup)
		COMPARECOUNT(g_group_pincodestr)
		COMPARECOUNT(g_idiomfun)
		COMPARECOUNT(g_rushfun)
		COMPARECOUNT(g_guessfun)
		COMPARECOUNT(g_guesspsrock)
		COMPARECOUNT(m_forbidprivate)
		COMPARECOUNT(m_rankwithlike)
		COMPARECOUNT(g_talk)
		COMPARECOUNT(g_percent)
		COMPARECOUNT(g_timeover)
		COMPARECOUNT(g_continuefind)
		COMPARECOUNT(g_includekey)
		COMPARECOUNT(g_privateadminanswer)
		COMPARECOUNT(g_tipsotheradmin)
		COMPARECOUNT(g_publicanswer)
		COMPARECOUNT(g_allowallanswer)
		COMPARECOUNT(g_prefixstr)
		COMPARECOUNT(g_groupdefaultanswer)
		COMPARECOUNT(g_robotname)
		COMPARECOUNT(g_byprivate)
		COMPARECOUNT(g_speakaward)
		COMPARECOUNT(g_punishshua)		
		COMPARECOUNT(g_forbidden)
		COMPARECOUNT(g_autonoticetime)
		COMPARECOUNT(g_hellowstr)
		COMPARECOUNT(g_scale)
		COMPARECOUNT(m_tax_percent)
		COMPARECOUNT(m_dropequipscale)
		COMPARECOUNT(g_scale_idiom)
		COMPARECOUNT(g_scale_rush)
		COMPARECOUNT(g_scale_crazy)
		COMPARECOUNT(g_times_crazy)
COMPARECOUNT(g_group_pinqqlevel)
COMPARECOUNT(g_group_pinqqdarenlevel)
COMPARECOUNT(g_timeout_rush)
COMPARECOUNT(g_timeout_idiom)
COMPARECOUNT(g_nperson_rush)
COMPARECOUNT(g_idiom_cost)
COMPARECOUNT(g_gamble_cost)
COMPARECOUNT(g_rob_cost)
COMPARECOUNT(g_query_cost)
COMPARECOUNT(g_rush_punish_cost)
COMPARECOUNT(g_singlexmlflag)
COMPARECOUNT(belowscore)
COMPARECOUNT(spamtimes)
COMPARECOUNT(bShowkindstips)
COMPARECOUNT(bTatalSlient)
COMPARECOUNT(bOpenSelfDefGame)
	COMPARECOUNT(kickspamtips)
COMPARECOUNT(forbidadminset)
COMPARECOUNT(gambletopvalue)
COMPARECOUNT(adminawardtop)
COMPARECOUNT(precardstr)
	COMPARECOUNT(femaleprecardstr)
	COMPARECOUNT(nnnnprecardstr)
COMPARECOUNT(adminprecardstr)
COMPARECOUNT(m_modifycardurl)
COMPARECOUNT(lotteryprice)
COMPARECOUNT(repeatcheckfine)
COMPARECOUNT(luckynumbercost)
COMPARECOUNT(guesspsrcost)
COMPARECOUNT(likevalue)
COMPARECOUNT(probationminutes)
COMPARECOUNT(maxreplywithinmin)
COMPARECOUNT(minutes_mustdosomething)
COMPARECOUNT(action_mustdowhat)
COMPARECOUNT(punish_otherwise)
COMPARECOUNT(robneedLowestRankNum)
COMPARECOUNT(robneedwaitTime)
COMPARECOUNT(initscore)
COMPARECOUNT(paybackscale)
COMPARECOUNT(gamblehardscale)
COMPARECOUNT(bidwaittime)
COMPARECOUNT(bidbacknum)
COMPARECOUNT(hatemustover)
	COMPARECOUNT(lotteryopentime)
COMPARECOUNT(rushprefixstr)
	COMPARECOUNT(g_tradegrouplist)
		COMPARECOUNT(g_checkperiod)
		COMPARECOUNT(g_ranktitlestr)
		COMPARECOUNT(g_banliststr)
		COMPARECOUNT(g_rob)
		COMPARECOUNT(g_gamblerobtimes)
		COMPARECOUNT(g_forwordkeyliststr)
		COMPARECOUNT(g_vipliststr)
		COMPARECOUNT(g_onlyself)
		COMPARECOUNT(g_storeprice)
		COMPARECOUNT(timetask)
		COMPARECOUNT(g_coinname)
		COMPARECOUNT(g_queryfun)
		COMPARECOUNT(m_allowprivaterush)
	    return totalcount==101; 
    };
}qqgrouprule;

template<typename T2>
BOOL GetFirstRegMatch(T2 reg_secondbody2,LPCTSTR expressstr,CString &matchstr,BOOL bFirst/*=true*/)
{
	CStringvect getbackstr;
GetRegEX(reg_secondbody2,expressstr,getbackstr);//need consider of the actual keyname

	if(getbackstr.size()>0)
	{
		if(bFirst)
	matchstr=getbackstr.front();
		else
matchstr=getbackstr.back();

		return true;
	}
	else
		return false;

}
extern CKeepMap<INT64,INT64,struct_qqnum_msg,struct_qqnum_msg> g_qqnum_structmoreprofile_map;
extern BOOL GetDllresultText(const CString& dllpath,const CString& functionname,LPCTSTR paramstr,BOOL bKeyflag,CString& txtcontent);
extern CCriticalSection lockqqmoreprofile;
extern CCriticalSection lockgroupbeignoreresource;

extern CString m_ownqqnumber;
extern BOOL Isggged;
extern int *pggged;
extern BOOL g_minstateflag;
extern BOOL bFirsttime;
//extern int g_percent;
extern int g_autorunflag;
extern int g_autologinflag;
extern int g_notipadflag;

extern BOOL g_last_bAuto_online;

extern BOOL g_Androidflag;
extern int g_privatepercent;
//extern int g_includekey;
extern int g_status_selcur;
extern int g_slientmode;
extern int g_speedonly;
extern int g_friend_request_method;
extern CString g_friend_welcomemsg;
extern CString g_friend_pincodestr;//群验证消息为某某某时自动同意

extern CString	g_ownqqfn;

extern CReadAUStdioFile historyfile1;
	const TCHAR RNDEFBUF[15]=_T("【换行】");
	const char RNDEFBUFA[15]="【换行】";

	extern INT64 FinalGetRealQQFromUin(INT64 m_realgroupnumber,INT64 cur_uin,BOOL strictflag);
	extern INT64 GetRealQQFromUin(INT64 m_realgroupnumber,INT64 cur_uin);
extern void AddtoKeepMapFromFile(CKeepStrStrVectMap &g_tempmap,const CString& frontstr,const CString& backstr,BOOL bHugeFile=false,CString* filepath=NULL);
extern int g_defaultstopply;
extern int g_autonotice;
extern int g_autonoticetime;
extern CString g_hellowstr;
extern CString g_helpstr;
extern CString g_gameliststr;
extern CString g_adminhelpstr;
extern qqgrouprule g_defaultqqgrouprule;
extern qqgrouprule& GetGlobalGrule(INT64 globalqqgroup);
extern int zhcx_pos;
extern set<INT64> manualqqdlglist;
extern CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> GrouprealqqNickmap;
extern CKeepMap<INT64,INT64,CKeepINT64StrMap*,CKeepINT64StrMap*> last_GrouprealqqNickmap;
extern void ModifyGroupQQMap(INT64 groupid,INT64 qqnum,LPCTSTR cardname,BOOL bAdd,BOOL bUinAddOnly);
extern void GetINT64StrMapFromFile(INT64 groupnum,CKeepINT64StrMap* pint64strmap,BOOL bLoad);
extern void SaveGroupUinNickName(INT64 realgroupnum,INT64 realqq,INT64 cur_uin);
extern void GetKeepMapFromFile(CKeepStrStrVectMap &g_tempmap,CReadAUStdioFile& autoreplyfile,BOOL bEasymode=false);
extern CString g_qqruledir;
extern CString g_qqreplydir;
extern int g_fontsize;
extern int g_boldflag;
extern CString g_fontname;
extern CString g_fontcolorstr;
//extern CString g_prefixstr;
extern CString g_autoreplycategory;
extern CString vfwebqqstr,ptwebqqhash,verifysessionhash;
extern BOOL m_alreadylogin;
extern BOOL g_nohistory;
//extern int g_continuefind;
//extern CString g_groupdefaultanswer;
extern CString g_privatedefaultanswer;
//extern CString g_robotname;
extern int g_bTuopanflag;
extern int g_bApplyAll;
extern int g_bIgnoreAll;
extern int g_totalsilent;
extern int g_smarttipsforsong;
extern HWND g_ignorehwnd;
extern CKeepMap<INT64, INT64, BOOL, BOOL> GidbRobotShutupMap;

extern	CStringvect backbufvect;
extern	CKeepMap<CString,LPCTSTR,INT64,INT64>  dislkbackbufvect;
extern BOOL g_bManQQgroupListflag;
extern CKeepMap<INT64,INT64,CString,LPCTSTR> GidNickNamemap;
extern int g_totalgroupnumber;
extern CKeepMap<INT64,INT64,BOOL,BOOL> g_groupbeIgnoreMap;
extern CKeepMap<INT64,INT64,INT64,INT64> GidRealGNummap;
extern CKeepMap<INT64,INT64,CString,LPCTSTR> FriendUinNickNameMap;
extern CKeepMap<INT64,INT64,qqgrouprule,qqgrouprule> GRealNumRulemap;
extern BOOL SendqqMsg(INT64 toqq,LPCTSTR msgcontent,int prnum=1);
extern BOOL SendSessionqqMsg(INT64 groupuin,INT64 toqq,LPCTSTR msgcontent,int prnum=1);
extern BOOL SendGroupqqMsg(INT64 groupuin,LPCTSTR msgcontent,int prnum=1);
extern INT64 GetRealQQnumber(INT64 uin,BOOL bGroup);
extern CKeepMap<INT64,INT64,INT64,INT64> GidGcodemap;
extern CKeepMap<INT64,INT64,INT64,INT64> g_init_GidGcodemap;
extern set<INT64> robotfriendset;
extern LPCTSTR SaveAs_complete_path(LPCTSTR filename);
extern BOOL GetRuleFromFile(BOOL bLoad,INT64 realgroupnumber,qqgrouprule& temprule);
extern HWND CreateQQMsgDlg(INT64 groupuin,INT64 qqnumber,LPCTSTR nickname,BOOL qunflag,BOOL bShow,INT64 curgcode,BOOL bFirstAutoOpen=false);
extern void GetthreeNickName(int rtint,INT64 RealUin,INT64 groupuin,INT64 qqnumber,CString &nicknamestr);
extern BOOL IsSameGroupQQNum(LPCTSTR str1,LPCTSTR str2);
extern INT64 AddValidTime(INT64 daystime,INT64 oldtime);
extern void ConvertMsg(LPCTSTR msgcontent,CString&tempnewstr,BOOL btranstourl=false);
extern void AppendRobotAd(LPCTSTR msgcontent,CString &tempadstr);
extern void ApplyJoinToGroup(INT64 groupid,LPCTSTR reason);
extern void SetGroupPolicy(INT64 groupid,int policynum);
extern void PackPrepareUploadPrivateImg(int imgfilesize);

extern BOOL  IsBankSpecialQQ(INT64 qqnum,int defnum=2000,INT64 defgroupnum=0);
extern void QuitGroup(INT64 groupid);
extern void LikeOtherCard(INT64 otherqq,int typenum);
extern CEvent newpbsendmsg;
extern BOOL g_bForidrecognizegroupvoice;
extern BOOL g_bForidrecognizeprivatevoice;
extern BOOL g_bForbidSavevoicefile;
// C晨风qq机器人App:
// 有关此类的实现，请参阅 晨风qq机器人.cpp
//
extern volatile BOOL bstop1;
extern volatile BOOL bstop2;
extern volatile BOOL bstop3;
extern volatile BOOL bstop4;
extern volatile BOOL bstop5;
extern volatile BOOL bstop6;
extern BOOL g_alreadyhomepage;
extern CStringA timedstr;
extern int g_timeover;
extern BOOL qqgroupqun;
//#define STARTTIME DWORD time1=GetTickCount();
//#define TESTFUNTIME(funname) DWORD time2=GetTickCount();\
//timedstr.Format("%s:时间差：%d",#funname,time2-time1);\
//	Write2MagnetLog((CString)timedstr,&magnetfile,true);
#define STARTTIME

#define TESTFUNTIME(funname)


#define NewSTARTTIME

#define NewTESTFUNTIME(funname)


//extern CStringA newtimedstr;
//#define NewSTARTTIME DWORD newtime1=GetTickCount();
//#define NewTESTFUNTIME(funname) DWORD newtime2=GetTickCount();\
//newtimedstr.Format("%s:时间差：%d",#funname,newtime2-newtime1);\
//	Write2MagnetLog((CString)newtimedstr,&magnetfile,30);

//ATLTRACE("starttime");
//ATLTRACE("%s",#funname);
const TCHAR robotad[32]=_T("【由晨风QQ机器人发送】");
extern int screen_xsize;
extern int screen_ysize;
typedef void (_cdecl * DLLOPENSET)();
typedef BOOL (_cdecl * DLLRESPONSE)(LPCTSTR usermsg,LPTSTR responsemsg);

class CMyCriticalSection:public CCriticalSection
{
	public:
			CMyCriticalSection()
			{
			};
	/*BOOL Unlock()
	{
		return true;
	};
	BOOL Lock()
	{
		return true;
	};*/

};
extern INT64 ExtractGroupidFromStr(LPCTSTR wholename,CString*truename=NULL);
class SameQQGroupNumfun
{
 
private:
	INT64 m_groupnum;
public:
 SameQQGroupNumfun(const CString& wholename)
 {
	 m_groupnum=0;
	m_groupnum=ExtractGroupidFromStr(wholename);

 };

bool operator()(const CString &everysinglestr)const
 {
 

	// (229375129)
	 CString expressstr;
	 	expressstr.Format(_T("(?<=\\()\\d+(?=\\))"));
	CString rtmatchstr;
	INT64 groupnum1=0;
groupnum1=ExtractGroupidFromStr(everysinglestr);
CString findstr;
findstr.Format(_T("%s——%I64d-%I64d"),everysinglestr,groupnum1,m_groupnum);
	
		Write2MagnetLog(findstr,&magnetfile,3);

        return (groupnum1==m_groupnum)&&groupnum1;
 

       
 

}
 

 

};
extern int GetoverdaysFromIntTime(INT64 time);
extern CCriticalSection locksongmapsource;
extern CCriticalSection lockhellowres;
extern CCriticalSection lockfriendresource;
extern CCriticalSection lockgroupnameresource;
extern CCriticalSection lockgidgcoderesource;
extern CCriticalSection lockgqqnickmapresource;
extern CCriticalSection lockggroupmembercountsource;
extern CCriticalSection lockggroupownerqqsource;
extern CCriticalSection lockandroid_gqqnickmapresource;
extern   CKeepMap<CString,LPCTSTR,group_memberinf,group_memberinf> g_singleqqinfmap;
extern CKeepMap<INT64,INT64,qqlevel_dareninf,qqlevel_dareninf> g_qqdarenlevelinfmap;
class C晨风qq机器人App : public CWinApp
{
public:
	C晨风qq机器人App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C晨风qq机器人App theApp;
