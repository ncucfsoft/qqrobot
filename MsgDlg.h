#pragma once
#include "晨风qq机器人.h"
#include "afxwin.h"
#include "afxcmn.h"

// CMsgDlg 对话框
#include "晨风qq机器人Dlg.h"
// CModifyTitle 对话框
class C晨风qq机器人Dlg;
extern C晨风qq机器人Dlg *g_mainhwnddlg;
const int treaturemaxnum=900;
const int treaturemaxnum1=901;
const int echeonummax = 30;
typedef   struct _onetimetask
{
	CString taskcmd;
int hour;
int minute;
int second;
int bAlreadydone;
int periodtime;//间隔10秒、间隔5分钟、间隔3小时、间隔2天
_onetimetask()
{
	hour=-1;
	minute=-1;
	second=-1;

	periodtime=0;
	bAlreadydone=0;
}
bool operator==(const _onetimetask& otherone) const
		{
			if(taskcmd==otherone.taskcmd&&hour==otherone.hour&&minute==otherone.minute&&second==otherone.second)
				return true;
			else  
				return false;
		}
}onetimetask;
class SameRushAnswser
{
 
private:
	CString m_str;
public:
 SameRushAnswser(const CString& wholename)
 {
	
	 m_str=wholename;
 };

bool operator()(const CString &everysinglestr)const
 {
 


        return (_tcsicmp(everysinglestr,m_str)==0);
 

       
 

}
 

 

};
typedef struct _RestoreSendmsg
	{
	
	INT64 finalqqnum;
	int sleeptime;
	CString privatemsg;
	}RestoreSendmsg;
 typedef struct _AutoSpeakStruct
{	CString sendmsg;
	INT64 uin;
}AutoSpeakStruct;
class CMsgDlg : public CMyBGCDlg
{
	DECLARE_DYNAMIC(CMsgDlg)

public:
	BOOL IsGuessNumTest(LPCTSTR itstr,int *myguessnum);
	CMsgDlg(INT64 groupuin,INT64 qqnumber,LPCTSTR nickname,BOOL qunflag=true,INT64 curgcode=0,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMsgDlg();
	void ReLoad();
	BOOL CMsgDlg::FindPriVarious(CString& rp_tempstr2, CString* filepath=NULL);
	BOOL CheckOneCondition(const CString& singlevaluestr,INT64 backupuin);
	void ReplaceAGoodsNameByseq(INT64 otherqqnum,const CString &tempawardstr,int seqnum,INT64 INtimeovervalue);
	INT64 AddGoods(CString& needtrimstr,LPCTSTR addstr,LPCTSTR seps,INT64 timeovervalue,BOOL& bFindSame,BOOL bAppendToTreature=NULL);
	void ShowNewMsg(LPCTSTR prembname,LPCTSTR inputnewmsg,int msgtime,INT64 cur_uin,int timetaskflag=0,BOOL bVoice=false,INT64 msgid=0);
	void thisAwardOrPunish(BOOL bAward,INT64 cur_uin,INT64 cur_realqqnum,INT64 score,LPCTSTR reason,BOOL bQuiet=false);
	void CountSpeak(INT64 cur_uin,LPCTSTR m_lastnewmsg,BOOL bNotTalk);
	BOOL IsPlayIdiom(LPCTSTR m_lastnewmsg);
	BOOL IsAwardAll(const CString& trimusermsg,INT64* auctionscore,BOOL*  bLikeFlag,BOOL* bVipOnly,int* spbanknum=NULL);
BOOL AwardAllFunHandle(const CString& checkintempstr,INT64 cur_uin);
void AwardAllOrVipOnly(CString* fmtstr,INT64 auctionscore,BOOL bLikeFlag,int bVipOnlyFlag);
	BOOL KickFunction(const CString& checkintempstr,INT64 cur_uin);
	void Pop1Msg(LPCTSTR m_lastnewmsg,CString &tempstr,INT64 uin,BOOL *bShowExactly);
	BOOL TestAdminCmd(LPCTSTR templastnewmsg,CString &tempstr,INT64 uin,BOOL *bShowExactly);
	int CheckReCharge(LPCTSTR cardname,INT64 uin,INT64 realgroupnumber,LPCTSTR cmdstr);
	void QueryReCharge(CString& querystr);
	void SetDefGroupOwner(INT64 groupnum,INT64 qqnum);
	BOOL repairResponse(LPCTSTR responsebuf,INT64 cur_uin);
	void ReLoadRankRobSpeakFile();
	BOOL BuySellGiveMedal(LPCTSTR medalname,LPTSTR responsemsg,BOOL bBuy,INT64 qqgroupnum,INT64 selfqq,INT64 otherqq=0,INT64 def_timeover=0);
	BOOL BuyvipByManual(LPCTSTR medalname,LPTSTR responsemsg,INT64 qqgroupnum,INT64 selfqq);
	BOOL IncludingPrivilegeWord(LPCTSTR nowword,CString* keyword=NULL);
	int JudgeAuth(INT64 uin,BOOL bTrueqq=true,BOOL bStrictToken=false);
	
	BOOL RandAbandonQQSlave(INT64 oldqqnum,INT64 newqqnum,CString&slavename,int range);
	BOOL RandAbandonQQSet(INT64 qqgroupnum,INT64 qqnum,CString&equipname,int range);
BOOL ClearSomeQQSet(LPTSTR responsemsg,INT64 qqgroupnum,INT64 qqnum,LPCTSTR setname,BOOL checkOnly=false);
	INT64 GetNowScore(INT64 qqgroupnum,INT64 queryRealQQnum);
	BOOL AwardOrPunish(const CString& trimusermsg,LPTSTR responsemsg,INT64 qqgroupnum,LPCTSTR reasonstr=NULL,BOOL limitflag=false,INT64 adminqqnum=NULL);
	BOOL ClearAllScore(LPTSTR responsemsg,INT64 qqgroupnum,INT64 qqnum,BOOL bForce=false);
	BOOL IsOwner(INT64 ownerqqnum,INT64 slaveqqnum);
	BOOL IsAuctionLikeNum(const CString& trimusermsg,INT64* AuctionLikeNum,INT64* auctionscore);
	BOOL IsBlackHouseAll(const CString& trimusermsg,BOOL* bVipOnly);
	void GetlotteryLogFromFile(BOOL bLoad,INT64 realgroupnumber);
	void GetGameTimeLogFromFile(BOOL bLoad,INT64 realgroupnumber);
	void GetGameTimesLogFromFile(BOOL bLoad,INT64 realgroupnumber);
	void GetSendMsgTimesLogFromFile(BOOL bLoad,INT64 realgroupnumber);
	BOOL AuctionLikeNumFunHandle(const CString& checkintempstr,INT64 cur_uin);
int BlackHouseAllFunHandle(const CString& checkintempstr,INT64 cur_uin);
void FindReplaceAnwser(CString& answerstr,const setvector<CString>& answerset,INT64 uin,BOOL inputflag=false);
void ReplaceRandomText(CString& rn_newmsg,INT64 backupuin);
void ReplaceSequentText(CString& rn_newmsg,INT64 backupuin);
CString GetRandomText(int seq,INT64 backupuin,int posnum=-1);
	void AutoUpdatecardName(INT64 cur_uin,INT64 otherqqnum);
	BOOL CMsgDlg::AllowSendAd(INT64 uin);
	int CountSlaveNum(INT64 myselfqqnum);
	void SendGameMsg(int sleeptime,INT64 finalqqnum,LPCTSTR privatemsg);
	int GetOverSpeakdays(INT64 otherqqnum);
	BOOL GetCheckLocalTime(SYSTEMTIME* curSystemTime);
	void GetSpecifyTime(LPCTSTR timestr);//设置当前签到时间
	BOOL IsChangeCardWordTest(LPCTSTR itstr,INT64 *qqnum,CString* rtnamebuf=NULL);
	void ReplaceVariousValueAll(CString& rp_tempstr2,INT64 backupuin,const CKeepStrStrVectMap& temp_variousvaluemap,const CStringvect& temp_variousvalueVector,LPCTSTR filepath);
	void ReplaceSingleVariousValueAll(INT64 backupuin,const CKeepStrStrVectMap& temp_variousvaluemap,const CStringvect& temp_variousvalueVector,CKeepMap<CString,LPCTSTR,double,double>& temp_keyvalueMap,LPCTSTR filepath);
	INT64  m_lastbid_qqnum;
	INT64 m_lastsell_qqnum;
	INT64  m_lastbid_price;
	INT64  m_lastsalve_qqnum;
	int m_currentsld;
	int shunxunowpos[treaturemaxnum1];

	int shunxuseqnowpos[treaturemaxnum1];
	INT64 m_lastbid_time;
	INT64  m_bid_init_price;
	BOOL m_bid_alreadystart;
	BOOL bStarTimeJudging;
	CKeepMap<CString,LPCTSTR,BOOL,BOOL> g_sixtwotempkeydonemap;
	int m_sixtwocount;
	int m_sixtwolasthour;
	int m_sixtwolastminute;
int m_sixtwolastsecond;

	INT64 specifychecktime;//设置当前签到时间
	set<INT64> m_raincheck_qqset;
	INT64 m_bid_likenum;//拍卖的赞个数
	CString m_bid_treaturename;//拍卖的宝物名称
	CString m_intreplacestopstr,m_intreplacerestorestr;
CString m_gameliststr;
	CKeepStrStrPVectMap m_gamePrivilegeautoreplymap;
	CKeepStrStrVectMap  m_inputreplacemap;
	CKeepStrStrVectMap m_outputreplacemap;
	CKeepMap<CString,LPCTSTR,setvector<INT64>,setvector<INT64>> m_groupgamemembermap;
	CKeepMap<CString,LPCTSTR,list<CEvent*>,list<CEvent*>> g_cancelmsgeventMap;
	CKeepMap<CString,LPCTSTR,list<INT64>,list<INT64>> g_cancelmsgrestoreMap;
CKeepMap<INT64,INT64,CString,LPCTSTR> g_cancelmsgnumberMap;
CKeepMap<INT64,INT64,BOOL,BOOL> m_isvoiceMap;

CKeepStrStrVectMap m_variousvalueMap;
CStringvect m_variousvalueVector;
//BOOL m_bAllowPrivateRushflag;
	vector<RestoreSendmsg> m_restoresendmsgvect;
	list<AutoSpeakStruct> m_autospeaklist;
BOOL onceloadgamemsgflag;
	BOOL m_showbadword;
	BOOL m_allowvipbadword;
	BOOL m_notrelatewithsignflag;
	BOOL m_bstardotstarflag;
	CString m_bid_slavename;
	CString m_bid_ownername;
	BOOL m_fivenoanswerflag;
	INT64 last_uin;
	int m_last_lottery_hour;
	BOOL m_lottery_opened;
	INT64 m_last_pitchguess_qqnum;
	int m_last_guessingnum;
	INT64 m_last_guessingprice;
	int m_guessingtimes;
	int m_guess_count;
	set<INT64> m_alreadypickQQ_set;
	CKeepMap<INT64,INT64,int,int> g_spamtimesMap;
	CKeepMap<INT64,INT64,int,int> m_wantPrivateMap;
CKeepMap<INT64,INT64,int,int> m_wantMuteExecuteMap;

CKeepMap<INT64,INT64,INT64,INT64> m_adminAwardMap;
//CKeepMap<INT64,INT64,int,int> m_likecountMap;
//CKeepMap<INT64,INT64,int,int> m_hatecountMap;
CKeepMap<CString,LPCTSTR,INT64,INT64> m_virtualnameMap;
INT64 GetCountOfLikeOnce(INT64 qqnum1);
void ReplaceVirtualname2QQnum(CString& wholestr);
BOOL IsDuelSomeone(const CString& trimusermsg,INT64 *globalqqnum,INT64* auctionscore,BOOL* bDuel);
INT64 GetLeftLikeNum(INT64 qqnum1,BOOL bLike);
BOOL IsLikeSomeone(const CString& trimusermsg,INT64 *globalqqnum,INT64* auctionscore,BOOL* bLike);
BOOL LikeSomeoneFunHandle(const CString& checkintempstr,INT64 cur_uin);
BOOL DuelSomeoneFunHandle(const CString& checkintempstr,INT64 cur_uin);
BOOL ThreePrivilegeWord(LPCTSTR nowword,CString* keyword/*=NULL*/,int typenum);
void NoticeQQOwner(LPCTSTR noticemsg,BOOL bForwordkey=false,BOOL bTimeOut=false);
void AmuseFunWordTest(LPCTSTR itstr,INT64 *realgroupnum,BOOL *rankingflag,BOOL *awardorpunishflag,BOOL *checkinflag,BOOL *gambleflag,BOOL *giveflag,BOOL *queryflag,BOOL *robflag);
BOOL IsShutupSomeone(const CString& trimusermsg,INT64 *globalqqgroupnum,INT64 *globalqqnum,INT64* auctionscore,BOOL* bShutup,CString* preasonstr,BOOL *bNotAffectBlackHouse=NULL);
BOOL IsAuctionSlave(const CString& trimusermsg,CString* qqnumber,INT64* auctionscore);
BOOL ShutSomeoneFunHandle(const CString& checkintempstr,INT64 cur_uin);
BOOL IsDestroyWordTest(LPCTSTR itstr,CString* weaponname);
	int m_restbag_count;
	int m_lastluckybag_num;
	CString m_lastpitchName;
	CKeepMap<INT64,INT64,int,int> m_lotterymap;
	CString last_counttext;
	CString last_lotterychampion;
	int m_cur_number;//=g_all_blogcountdown%m_total_content.size();
	CStringvect m_total_content;
	int m_shuapincount;
	int m_solouincount;
	BOOL m_FirstBroadcasted;
	BOOL bOpened;
	BOOL m_totalshutitup;
	BOOL m_talk;
	BOOL m_checkin;
	BOOL m_gamble;
	BOOL m_rob;
set<INT64> temprobotfriendset;



	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	INT64 m_qqnumber;
	INT64 m_groupuin;
	INT64 m_gcode;
	INT64 m_realgroupnumber;
	BOOL m_qunflag;
	BOOL m_forbidprivate_once;
	INT64 m_number2value;
	INT64 m_number1value;
	INT64 sharekeynumber;
	qqgrouprule *m_grule;
	set<INT64>  m_alreadywelcomeqqnum;
	int tempcount;
	CString badword;
	CString m_replacecontent;
	void random2num(CString& str,INT64 uin);
	CKeepMap<INT64,INT64,CString,LPCTSTR> m_queryquickmap;
	CKeepMap<INT64,INT64,CString,LPCTSTR> m_disposablemap;
CKeepMap<INT64,INT64,CString,LPCTSTR> m_insomegamemap;
CKeepMap<CString, LPCTSTR, CString, LPCTSTR> m_lastrandomtxtmap;
	CKeepMap<CString,LPCTSTR,CString,LPCTSTR> m_newmsgmap;
	CKeepMap<INT64,INT64,CString,LPCTSTR> m_newmsguinmap;
	CKeepMap<INT64,INT64,CKeepMap<CString,LPCTSTR,double,double>*,CKeepMap<CString,LPCTSTR,double,double>*> m_uin_var_map;
	BOOL GetPureNameAndTimeAndValue(LPCTSTR trimgoodsname,INT64 qqnum,INT64 *resttime,INT64 *numvalue,CString* wordvalue=NULL);
	BOOL GetPureNameFromValue(LPCTSTR trimgoodsvalue,INT64 qqnum,CString* goodsname);

	void ReplaceShowNumValueTime(CString& rp_tempstr2,INT64 backupuin);
	void ReplaceShowTreasureFromValue(CString& rp_tempstr2,INT64 backupuin);
	BOOL ReplaceTrimMidonce(CString& needtrimstr,int xuhao,IN OUT CString& replacestr,LPCTSTR seps,LPCTSTR randomxuhaostr=NULL);
	//CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>* m_autoreplymap;
	//BOOL IsExistQQ(INT64 qq1);
	void JudgeAutoQuit();
	BOOL FindAnwser(CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>* curreplymap,LPCTSTR templastnewmsg,CString& tempstr,INT64 uin);
	INT64 NeedLikeNum(int curpos);
	void FindGameAnwser(CString& answerstr,const setvector<CString>& answerset,INT64 uin,BOOL bGetOneAnyway=false,BOOL bReplace=false,BOOL inputflag=false);
	void Send1MsgForPlaySong(CString& sendmsg,INT64 uin);
	INT64 GetRandomRealQQ();
	void ReplaceEchoAndNumber(CString& rp_tempstr2,INT64 backupuin);
	//CReadAUStdioFile* m_autoreplyfile;
CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>* m_pautoreplymap;
CReadAUStdioFile* m_pautoreplyfile;

CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>* m_pPrivilegeautoreplymap;
CReadAUStdioFile* m_pPrivilegeautoreplyfile;

DWORD m_lastidiomtime;
BOOL m_bIdioming;
TCHAR m_lastidiomword;
CString m_lastidiomwords;
int idiommode;
int m_tempidiommode;

int m_idiomtimes;
setvector<CString> usedidiomset;
BOOL m_rush_6flag;
int nrestsecond;
CKeepMap<INT64,INT64,CString,LPCTSTR> m_rush_6qqmap;
BOOL m_sleepingforrush;
int	m_rushtimeout;
DWORD	m_lastrushtime;
BOOL	m_bRushing;
int   m_msgcount;
int	m_rush_count;
INT64	last_rush_uin;
int	m_rushtimes;
int samecount;
set<INT64> closerushgame_uinset;
set<INT64> openrushgame_uinset;

CString lastsamenewmsg;//最近5次都是相同的消息，则不回答
	CString m_replyfn;
	
	CString m_lastnewmsg;
	CString m_selectnewmsg;
	INT64 m_selectnewuin;
	DECLARE_MESSAGE_MAP()
public:
	CString m_qqnickname;
	BOOL m_hideflag;
	BOOL m_bDiscussFlag;
		CString m_ssessionsignstr;
		BOOL m_alreadyshow;
		BOOL m_minstate;
		int lastday;
		INT64 last_idiom_uin;
		int m_idiom_count;
	int checkinpos;
	CString lastranktitlestr;
	BOOL m_beIgnoreflag;
	CString laststorestr;
	CString lasttimetaskstr;
	BOOL m_closebroastflag;
	BOOL m_open_bid_market;
	BOOL m_open_baidu_find;
	BOOL m_forbidden_continually_playgame;
	BOOL m_forbidden_negative_playgame;
	BOOL m_forbidrob1000;
	BOOL m_bKickincludingvip;
	int m_open_quit_tips;
	int m_open_forbidword_flag;
	int m_open_input_hook;
	int m_open_withdraw;
	BOOL m_open_notice_owner;
	BOOL m_open_smarttips;
	BOOL m_open_novip_give;
	CKeepMap<CString,LPCTSTR,INT64,INT64> g_levelnamemap;
	CKeepMap<CString,LPCTSTR,INT64,INT64> g_levelnameLikeNummap;
	CKeepMap<CString,LPCTSTR,int,int> m_defposmap;
	CKeepMap<CString,LPCTSTR,INT64,INT64> g_storepricemap;
CKeepMap<CString,LPCTSTR,INT64,INT64> g_timeover_goodsnamemap;
CKeepMap<INT64,INT64,DWORD,DWORD> m_timefor_noactionpunish_map;
CKeepMap<INT64,INT64,DWORD,DWORD> m_timefor_noactionpunish2_map;
LRESULT onUpdateStore(WPARAM wParam,LPARAM lParam);
void ClearExpireGoods(INT64 globalqqgroup,qqgrouprank & myrank1);
	CKeepMap<CString,LPCTSTR,onetimetask,onetimetask> timetaskmap;
	void TakeTimeTask();
	void CheckExpireForNotice();
	void RevealRush6Result();
	void ReplaceDefine(CString& tempstr2,INT64 uin,BOOL inputflag=false);
	void ReplaceNumber1AndNumber2(CString& rp_tempstr2,INT64 backupuin);
	void ReplaceQQNumber(CString& rp_tempstr2,INT64 backupuin);
	void executecmdfun(LPCTSTR cmdstr);
	int  Rush_right_wrong_neutralize(LPCTSTR last_rushanswerstr,LPCTSTR checkintempstr);
	BOOL IsSameAsDefaultOwner(qqgrouprule* targetqqgrouprule=NULL);
	INT64 AddNotTreatureGoods(qqgrouprank &otherrank,const CString &tempawardstr,INT64 timeovervalue,int ppos);
	void ExecuteReplaceDefine(CString&rptempstr2,const qqgrouprank &myrank,INT64 otherqqnum,BOOL bNumFortune=false,LPCTSTR wholerptempstr2=NULL);
	int GetOverJoindays(INT64 otherqqnum);
		BOOL m_timetask_opened;
	BOOL m_last_timetask_day;
	INT64 m_lastrobqqnum;
	vector<_NoticeWithDrawStruct> m_summarynotice_vector;
	//DWORD m_lastrobtime;
CKeepMap<INT64,INT64,DWORD,DWORD> m_qqmap_lastrobtime;
CKeepMap<INT64,INT64,DWORD,DWORD> m_qqmap_lastgametime;
CKeepMap<INT64,INT64,DWORD,DWORD> m_qqmap_todaygametimes;
CKeepMap<INT64,INT64,int,int> m_map_todayspeaktimes;
CKeepMap<INT64,INT64,vector<INT64>,vector<INT64>> m_map_lastminreplytimes;

CKeepMap<INT64, INT64, CString, LPCTSTR> m_lastoldcardmap;

BOOL m_needfirsthello;
BOOL m_allxmlflag; 
	DWORD m_luckytipstime;
	void UpdateTimeTaskInf(BOOL readonly=true,BOOL newdayflag=false);
	void UpdateStoreInf();
	void UpdateLevelInf();
	void SetGoodsAllOrVipOnly(CString* fmtstr,LPCTSTR tempawardstr,int bVipOnlyFlag,int ppos);
	void CountDefense(INT64 &weekspeaktimes,const CString& defensename);
	void Countweapon(double &otherspeaktimes,const CString& weaponname);
	int TestGoods(LPCTSTR medalname);
	BOOL GlobalGiveFunHandle(const CString& checkintempstr,INT64 cur_uin);
BOOL GlobalMoveFunHandle(const CString& checkintempstr,INT64 cur_uin);
BOOL GuesspsrockHandle(const CString& checkintempstr,INT64 cur_uin);
	BOOL CheckEnemyFunHandle(const CString& checkintempstr,INT64 cur_uin);
	void  Gettitle(INT64 score,INT64 likenum,OUT CString& titlestr,int *npos=NULL,INT64 *nextgap=NULL,INT64 *nextgaplike=NULL,CString* nexttitle=NULL);
	double  GetMedalPK(INT64 qq1,INT64 qq2);
	double GetTotalCountPower(INT64 qqnum,BOOL bFirst,int typenum,INT64 othergroupnum=0);
	BOOL IsSameOwner(INT64 otherqqnum,INT64 slaveqqnum);
	BOOL IsCouple(INT64 spouseqqnum1,INT64 spouseqqnum2);
	INT64 ReturnCoupleNum(INT64 ownerqqnum);
	BOOL ClearAllNotInGroupScore(LPTSTR responsemsg,INT64 qqgroupnum);
		void Update2CheckInData(INT64 cur_uin,INT64 qqnum);
	void EnumSlaves(INT64 ownerqqnum,set<INT64>& myslaves,BOOL bIncludevirtual=true,BOOL bIncludeCouple=false);
	BOOL FreeMySelfFunHandle(const CString& checkintempstr,INT64 cur_uin);
	double GetTaxRestValue();
	BOOL AuctionSlaveFunHandle(const CString& checkintempstr,INT64 cur_uin);
	BOOL AuctionTreatureFunHandle(const CString& checkintempstr,INT64 cur_uin);
	BOOL IsAuctionTreature(const CString& trimusermsg,CString*treaturename,INT64* auctionscore);
	BOOL FreeSlaveFunHandle(const CString& checkintempstr,INT64 cur_uin);
BOOL BidForSlaveFunHandle(const CString& checkintempstr,INT64 cur_uin);
	BOOL CheckSlaveFunHandle(const CString& checkintempstr,INT64 cur_uin);
	BOOL ListVirtualSlaveFunHandle(const CString& checkintempstr,INT64 cur_uin);
BOOL GetbackMoneyFunHandle(const CString& checkintempstr,INT64 cur_uin);

	double  GetRobTimesPK(INT64 qq1,INT64 qq2);
	double GetGoodsPKValue(INT64 qq1,int mtype);
	qqgrouprank & GetMyRank(INT64 qq1,BOOL noClearExpire=false);
	//qqgrouprank & GetGlobalMyRank(INT64 globalqqgroup,INT64 qq1);
	double GetRestEnergyPKValue(INT64 qq1);
double GetRobotPKValue(INT64 qq1);
	int GetTrueGambleRobtimes(INT64 qq1);
		BOOL CheckInFun(const CString& trimusermsg,LPTSTR responsemsg,INT64 qqgroupnum,INT64 qqnum,INT64 cur_uin);
		BOOL GetRankInf(const CString& trimusermsg,LPTSTR responsemsg,INT64 qqgroupnum);
		//void GetLastNQQnum(INT64 qqgroupnum,int numcount,set<INT64>& lastqqset);
LRESULT onAnserMsg(WPARAM wParam,LPARAM lParam);
LRESULT onAdd2Data(WPARAM wParam,LPARAM lParam);
void AcrossSend1Msg(INT64 targetgroupnum,INT64 targetqqnum,LPCTSTR msg);
LRESULT onResponse(WPARAM wParam,LPARAM lParam);
LRESULT onClearNotInGroup(WPARAM wParam,LPARAM lParam);
LRESULT onSleepResponse(WPARAM wParam,LPARAM lParam);
LRESULT onAcrossMsg(WPARAM wParam,LPARAM lParam);
LRESULT onNewJoin(WPARAM wParam,LPARAM lParam);
LRESULT onNewQuit(WPARAM wParam,LPARAM lParam);
LRESULT onNewUpdateAdmin(WPARAM wParam,LPARAM lParam);
LRESULT onNewWithDrawMsg(WPARAM wParam,LPARAM lParam);
LRESULT onAlreadyWelcome(WPARAM wParam,LPARAM lParam);
LRESULT onNewChange(WPARAM wParam,LPARAM lParam);
//void ReplaceVariousProfile(CString& tempstr,INT64 newjoinqq);
void GetGenderAndJoinTime(INT64 m_realgroupnumber,INT64 qqnum,CString* genderstr,CString* agestr,int *overdaysjointime,int timeout);
void WelcomeNewJoin(INT64 newjoinqq,LPCTSTR nickname);
void ReplaceRankingList(CString& rp_tempstr2,INT64 backupuin,BOOL b1000flag=NULL);
void ReplaceVirtualRankingList(CString& rp_tempstr2,CQQRankKeepMap *myqqrank,INT64 herem_realgroupnumber,INT64 backupuin,BOOL bLikeflag,BOOL b1000flag=NULL);
void ReplaceChineseEcho(CString&rp_tempstr2,INT64 backupuin);
void ReplaceNickName(CString& rp_tempstr2,INT64 backupuin);
void ReplaceMsgID(CString& rp_tempstr2,INT64 backupuin);
void ReplaceCheckInWhere(CString& rp_tempstr2,INT64 backupuin);
void ReplaceRealQQName(CString& rp_tempstr2,INT64 backupuin);
void ReplaceShowInvalidTime(CString& rp_tempstr2,INT64 backupuin);
void ReplaceShowBlackTime(CString& rp_tempstr2,INT64 backupuin);
void ReplaceShowQQWhichHaveGoodsName(CString& rp_tempstr2);
void ReplaceShowTreaturePrice(CString& rp_tempstr2,INT64 backupuin);
BOOL IsOverGroup(INT64 groupnum);
void Getqqwhichhavegoodsliststr(CString& qqwhichhavegoodsliststr,LPCTSTR goodsname,int* rtnumber=NULL,int Virtualnum=0);
void ReplaceShowTreaturePos(CString& rp_tempstr2,INT64 backupuin);
void ReplaceShowTreatureName(CString& rp_tempstr2,INT64 backupuin);
void ReplaceNumTime(CString& rp_tempstr2,INT64 backupuin,int typevalue=0);
void QueitChangeCard(INT64 newqqnum,const CString& defcardname);
void ExecuteReplaceTreatureN(CString&rptempstr2,const qqgrouprank &myrank,INT64 otherqqnum,int n);
void GiveDefCardNameToVirtualQQ(CString& tempstr,const CString& defcardname,INT64 changeqqnum);
LRESULT onThreadDone(WPARAM wParam,LPARAM lParam);
LRESULT onNextRush(WPARAM wParam,LPARAM lParam);
int GetReplyPercent(LPCTSTR usermsg,LPCTSTR standreply);
	afx_msg void OnClose();
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	void ShowOwnWindow();
	void Updatetemprobotfriendset(set<INT64>&temprobotfriendset);
	void ChangeCardFun(CString& tempstr,const CString& defcardname,INT64 changeqqnum,INT64 cur_uin,BOOL shutuped);
	void ChangeCardFunForHuman(CString& tempstr,const CString& defcardname,INT64 changeqqnum,INT64 cur_uin,BOOL shutuped);
	BOOL IsVip(INT64 realqqnum,BOOL bKickIncludingVip);
	BOOL IsVipGood(LPCTSTR goodname);
	BOOL TestGoodsName(LPCTSTR checkintempstr,INT64 cur_uin);
	void NeedConvert2Chinese(CString&rp_tempstr2,BOOL bAlwaysChinese=false);
	void ForceNeedConvert2Chinese(CString&rp_tempstr2,BOOL bAlwaysChinese/*=false*/);
void RegReplaceFinalStr(CString&rp_tempstr2);
BOOL ReplaceUrlEncode(CString& rp_tempstr2,INT64 backupuin);
void GetUrlEncodeBuf(CString& rplacecorestr,INT64 backupuin);
LRESULT onExternResponse(WPARAM wParam,LPARAM lParam);
BOOL CMsgDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	void ImplyKindofDefine(CString &rp_tempstr2,INT64 backupuin,BOOL inputflag=false);
	void SetAllOrVipOnly(CString* fmtstr,INT64 auctionscore,BOOL bLikeFlag,int bVipOnlyFlag);
	void GiveAllOrVipOnly(CString* fmtstr,const CString& tempawardstr,BOOL bGiveflag,int bVipOnlyFlag,INT64 def_timeover_value=0,BOOL bAddToTreature=false,BOOL bAppendToTreature=false);
	void Omitwardword(CString& nickname,BOOL strictflag=true,BOOL bReplaceTrim=true,INT64 backupuin=0,BOOL bNotwithdrawimg=true);
	void ReplaceCurrentLinetoBlankOrChinese(CString& rp_tempstr2);
	BOOL Send1Msg(const CString& tempstr2,INT64 uin_bAutoAnswer,BOOL bAlwaysPrivate=false,int sleeptime=0,BOOL bFalsesend=0,BOOL bShowExactly=false);
	//BOOL  Android_Send1Msg(INT64 m_realgroupnumber,INT64 uin,BOOL qunflag,const CString& oldstr);
	BOOL AnalyseInternalWord(CString& rp_tempstr2,INT64 uin,BOOL bValid,BOOL bNocondition=false);
	BOOL IsFulfilAllCondition(CString& rp_tempstr3,INT64 otherqqnum,BOOL bNoword=false,BOOL bTimeUpdate=false,BOOL bNodefineflag=false,BOOL inputflag=false);
	void GetGenderFromMap(INT64 finalqqnum,CString& facerandfmt,CString& agestrfmt);
	//void GetqqlevelFromMap(INT64 finalqqnum,int& qqlevel,int& qqdarenlevel);
	void GetVipRestTime(INT64 globalrealqqgroup,INT64 globalrealqqnum,CString& vipendtime);
	BOOL OpenSomeQQGroup(LPCTSTR templastnewmsg,CString &tempstr,INT64 uin);
	INT64 SystemAwardOrDrop(INT64 otherqqnum,const CString &tempawardstr,BOOL bAwardflag,INT64 INtimeovervalue=0,CString *rp_tempstr3=NULL,BOOL bAddToTreature=false,BOOL bAppendToTreature=false);
	void SystemAwardOrDropGame(INT64 otherqqnum,const CString &tempawardstr,BOOL bAwardflag,INT64 INtimeovervalue=0);
	int IsOverFullForSystemAward(INT64 otherqqnum);
	BOOL PromptSend1Msg  (const CString& tempstr2,INT64 uin,BOOL DefaultPrivate=false,BOOL bFalsesend=0);
	BOOL Send1MsgToAllQAcategory(const CString& tempstr2,LPCTSTR fromstr,INT64 uin);
	BOOL Send1MsgToAllQAcategoryForDone(const CString& tempstr2,int number,LPCTSTR answername,INT64 anuin);
	void Insert2List(LPCTSTR timestr,LPCTSTR namestr,const CString& xcmsgstr,INT64 cur_uin,LPCTSTR orgmsgstr=NULL);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	BOOL OnInitDialog();
	BOOL NeedToContinueReplaceOutAll(const CString& rp_tempstr2,set<CString>& alreadyreplaceset,CString* rtfindstr);
	void ReplaceOutAll(CString& rp_tempstr2,INT64 backupuin,BOOL &bGameflag,set<CString>& alreadyreplaceset,CKeepMap<CString,LPCTSTR,setvector<CString>,setvector<CString>>* outputreplacemap);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void CheckTimefor_noactionpunish();
	void AppendRobotAd(LPCTSTR msgcontent,CString &tempadstr);
	void LoadSelfTailvector(LPCTSTR tailpath);
	void MathReplaceByForce(CString& rp_tempstr2,INT64 backupuin,BOOL bAnyWayForce=false);
	BOOL m_firstcmdflag;
	BOOL GlobalSend1Msg(INT64 realgroupnum,HWND inhwnd,const CString& tempstr2);
	void TimeSend(BOOL bFirstbroadcasting=NULL);
	LRESULT CMsgDlg::onTimeNotice(WPARAM wParam,LPARAM lParam);
	void GetGoodsType(CString& wholegoodsname);
	void ReplaceAllRandword(CString& rp_tempstr2,INT64 backupuin);
	static vector<CString> m_questionvect;
	static vector<INT64> m_questionuinvect;
void ReplaceAllDefineStr(CString& rp_tempstr2,INT64 backupuin,BOOL inputflag=false);
	static CKeepMap<int,int,HWND,HWND> CMsgDlg::m_numbertoHwndMap;
	static void GlobalAdd2Data(LPCTSTR templastmsg,LPCTSTR tempstr2,BOOL bPrivilege=false);
void Add2Data(LPCTSTR templastmsg,LPCTSTR tempstr2,BOOL bPrivilege=false);
void OverWrite2Data(BOOL bPrivilegeflag=false);
void Remove1QQFromqqwhichhavegoodsliststr(LPCTSTR goodsname,INT64 qqnum);
void Insert1QQFromqqwhichhavegoodsliststr(LPCTSTR goodsname,INT64 qqnum);
void Get1Randomqqwhichhavegoodsstr(CString& qqwhichhavegoodsliststr,LPCTSTR goodsname);
void EraseQQFromqqwhichhavegoodsliststr(CString& qqwhichhavegoodsliststr,LPCTSTR goodsname);
BOOL IsHaveSomeGoodsName(INT64 qqnum,LPCTSTR goodsname);
BOOL g_timereportflag;
CString lastsendtext;
INT64 lastsenduin;
INT64 lastAnalysesenduin;
CString Last_lastAnalyseText;
int m_notrevertime;
int m_lastnumtime;
int m_timetaskuinpos;
set<int> m_hour61intvect;
			set<int> m_minute61intvect;
			set<int> m_second61intvect;
CStringvect m_randomadtailvector;
CKeepMap<INT64,INT64,CString,LPCTSTR> Now_lastOrgAnswerText_map;//尚未把随机数字等符号转化为具体的值
CKeepMap<INT64,INT64,CString,LPCTSTR> Now_lastAnalyseText_map;
CString Now_lastgamesetencePath;
CKeepMap<INT64,INT64,CString,LPCTSTR> Now_lastAskText_map;
CKeepMap<INT64,INT64,INT64,INT64> Now_lastMsgID_map;

CKeepMap<INT64,INT64,CString,LPCTSTR> Now_lastwholeAskText_map;
CKeepMap<INT64,INT64,int,int> m_qq_slavenum_map;
CKeepMap<CString,LPCTSTR,CString,LPCTSTR> m_goodqqliststrText_map;

//CString Now_lastAnalyseText;
//CString Now_lastAskText;

CString Last_PromptText;
INT64 Last_Promptuin;
INT64 m_herotitle_qq;
	int m_counter;
	int lastselect;
	BOOL m_alreadysetpos;
	CString m_guesspsr_lastname;
	CString m_guesspsr_lastpredictname;

	int m_guesspsr_lastwinflag;
	
	/*setvector<CString> g_medalnamelist;
	setvector<CString> g_diamondnamelist;
	setvector<CString> g_defensenamelist;
	setvector<CString> g_weaponnamelist;
	setvector<CString> g_housenamelist;
	setvector<CString> g_horsenamelist;*/
	setvector<CString> g_goodsnamelist[goodsnum];
	setvector<CString> g_vipgoodsnamelist;
setvector<CString> g_forbid_auctiongoodsnamelist;
setvector<CString> g_forbid_givegoodsnamelist;
setvector<CString> g_forbid_buygoodsnamelist;
setvector<CString> g_forbid_showgoodsnamelist;
setvector<CString> g_forbid_sellgoodsnamelist;
int InputHooker(CString& newmsg,INT64 cur_uin,INT64 msgid);
BOOL TrimMidonce(CString& needtrimstr,CString& cutstr,LPCTSTR seps);
void IsFulfilGoodsCondition(INT64 otherqqnum,int i,const setvector<INT64>& tempmembersetv,BOOL bTimeUpdate,BOOL bNoword,CString& rp_tempstr3,CString &notokstr,BOOL &bBreakI,CStringvect&askvectemp,BOOL &defineflag,BOOL &bNodefineflag,BOOL &bNodefineI,BOOL &onefailflag,INT64 &finalqqnum);
BOOL IsFulfilOneGood(int j,LPCTSTR valuestr,INT64 finalqqnum,const setvector<INT64>& tempmembersetv);
	//BOOL m_bStartcounting;
	BOOL m_bStopautoreply;
	BOOL m_baddtodata;
	BOOL m_bNewMsg;
	BOOL m_bNewAskflag;
	CString m_last_askneedanswerstr;
	CString lasteditstr;
	vector<rushstuffbuf> m_rushstuffvect;
	vector<rushstuffbuf> *p_g_rushstuffvect;
	int once50;
	int m_idiomtimeout;
	afx_msg void OnBnClickedOk();
	void LoadRushFile(LPCTSTR rushfilename);
BOOL IsKeyWord(const CString& checkintempstr);
BOOL ClearAllGroupScore(LPTSTR responsemsg,INT64 qqgroupnum);
BOOL FindIsLocalQuestion(LPCTSTR templastnewmsg);
int IsCardWithOtherStyle(LPCTSTR checkintempstr);
void BatchSendMsg();
BOOL GetNameAfterLevel(const CString& nowcardname,CString& defname,CString& levelname);
void GetLevelTitle(INT64 qqnum,CString& titlestr);
void BatchChangeCardName(INT64 cur_uin);
void Add2Blacklist(INT64 qqgroupnum,INT64 otherqqnum,BOOL bAdd=true,BOOL bAllgroupflag=false);
BOOL IsOwnerOfAnyGroup(INT64 myrealqq,INT64 *whichgroupnum);
void AddVip(INT64 globalrealqqgroup,INT64 globalrealqqnum,int globalvipflag,CString& fmtpstr,INT64 viphours,BOOL bGame=false,BOOL bAllgroupflag=false);
void AddtoBlackHouseList(INT64 globalrealqqgroup,INT64 globalrealqqnum,int globalvipflag,CString& fmtpstr,INT64 viphours,BOOL bGame=false,BOOL bAllgroupflag=false);
void SetVipTime(INT64 globalrealqqgroup,INT64 globalrealqqnum,INT64 viphours,BOOL bGame=false);
void GetVipTime(INT64 globalrealqqgroup,INT64 globalrealqqnum,CString& vipendtime);
void GetBlackhouse_endTime(INT64 globalrealqqgroup,INT64 globalrealqqnum,CString& vipendtime);
BOOL IsInBlackList(INT64 realqqnum);
BOOL IsInKickoutList(INT64 realqqnum);
BOOL ClearAllVirtualQQScore(LPTSTR responsemsg,INT64 qqgroupnum,int defvirtualnum=0,INT64 defqqrelevant=0);
void AwardOne(INT64 globalrealqqgroup,INT64 globalrealqqnum,INT64 globalscore,CString& fmtpstr);
afx_msg void OnBnClickedCancel();
		int m_rushwrongtims;
CEdit m_Edit1;
afx_msg void OnBnClickedButton1();
afx_msg void OnBnClickedCheck1();
afx_msg void OnBnClickedCheck2();
CListCtrl m_list1;
afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
afx_msg void OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult);
afx_msg void OnEnSetfocusEdit2();
afx_msg void OnEnKillfocusEdit2();
afx_msg void OnEnChangeEdit2();
afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
afx_msg void OnSetFocus(CWnd* pOldWnd);
afx_msg void OnEnSetfocusEdit1();
afx_msg void OnBnClickedButton2();
afx_msg void OnBnClickedButton3();
afx_msg void OnBnClickedButton12();
afx_msg void OnDestroy();
};
