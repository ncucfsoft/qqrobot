// AcceptRequestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PureAcceptRequestDlg.h"
//#include "afxdialogex.h"


extern CKeepMap<INT64,INT64,CPureAcceptRequestDlg*,CPureAcceptRequestDlg*> m_mapqqacdlg;
extern void LoadIgnoreQQlist(BOOL bLoad);
extern CCriticalSection lockqqacdlg;
extern CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_joinqq_qqword_map;//加群时填写的验证文字
extern CKeepMap<CString,LPCTSTR,INT64,INT64> g_joinqq_passqqnum_map;//加群时填写的数字
extern CCriticalSection lockgopuinres;
extern BOOL ExstractOneNum(LPCTSTR wstr,INT64 &qqnum);
CPureAcceptRequestDlg::CPureAcceptRequestDlg(INT64 qqgroupid,INT64 realgroupid,INT64 requestuin,INT64 qqaccount,INT64 timesignal,LPCTSTR nickname,LPCTSTR content,int bMale,qqgrouprule tempgrule,CWnd* pParent /*=NULL*/)
	{

	m_bMale=bMale;
	m_qqgroupid=qqgroupid;
	m_requestuin=requestuin;
	m_qqaccount=qqaccount;
	m_timesignal=timesignal;
	m_nickname=nickname;
	m_content=content;
	

	m_grule=tempgrule;
	m_realgroupnumber=realgroupid;
}

CPureAcceptRequestDlg::~CPureAcceptRequestDlg()
{
}



// CPureAcceptRequestDlg 消息处理程序



void CPureAcceptRequestDlg::OnDelSelf()
{


}

extern BOOL AgreeFriendRequest(INT64 qqaccount,INT64 timesignal);
extern BOOL AgreeGroupRequest(INT64 groupuin,INT64 requestuin,INT64 timesignal);
extern BOOL DenyGroupRequest(INT64 groupuin,INT64 requestuin,INT64 timesignal,LPCTSTR reason);
extern BOOL DenyFrendRequest(INT64 qqaccount,INT64 timesignal,LPCTSTR reason);

extern UINT SendWelcome(LPVOID lp);
int CPureAcceptRequestDlg::GetCheckedRadioButton(int radio1,int radio2)
{
return m_radiovalue;
}
void CPureAcceptRequestDlg::CheckRadioButton(int radio1,int radio2,int radio3)
{
	m_radiovalue=radio3;
}

void CPureAcceptRequestDlg::OnBnClickedOk()
{
	//CString str222;
	//str222.Format(_T("OnBnClickedOkbegin"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

	BOOL bDenyflag;
	BOOL bAlwaysDeny=false;
	if(GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2)==IDC_RADIO2)
	{
	bDenyflag=true;
	}
	else
	bDenyflag=false;

	int opvalue=-1;
	if(1)//g_slientmode)
	{
	if(m_realgroupnumber)
	{


opvalue=m_grule.g_group_request_method;
	}
	else
opvalue=g_friend_request_method;
	}
	
if(!g_totalsilent&&GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2)==IDC_RADIO1&&(opvalue==0||opvalue==2))
	opvalue=1;


CString denyreason;
CString welcomestr;
CString precardname;
CString femaleprecardname;
CString nnnnprecardname;
CString adminprecardname;
CString g_ranktitlestr;
INT64 ruleinitscore;
BOOL bTatalSlient;

CString contentbackstr;
		::function::GetHalfStr(m_content,NULL,&contentbackstr,_T("申请理由："),false);
		contentbackstr.TrimRight(_T("\\\\r"));

	if(find(g_forever_blacklist.begin(),g_forever_blacklist.end(),m_qqaccount)!=g_forever_blacklist.end())
	{
	
	bAlwaysDeny=true;
	denyreason=_T("你已经进入永久黑名单，无法加入");
	}	

	if(m_realgroupnumber&&m_qqaccount)
	{

		CString admininvitestr;
		CString keystr;
		keystr.Format(_T("%lld_%lld"),m_realgroupnumber,m_qqaccount);
		INT64 realinviteuin=0;
		ExstractOneNum(contentbackstr,realinviteuin);
		lockgopuinres.Lock();
		g_joinqq_qqword_map[keystr]=contentbackstr;

		if(realinviteuin>10000)
		{
			if(realinviteuin>10000||!g_joinqq_passqqnum_map.Lookup(keystr))
				g_joinqq_passqqnum_map[keystr]=realinviteuin;
		}
		lockgopuinres.Unlock();

		if(g_bNewUserGuestPlusTime)
		{
			SYSTEMTIME mySystemTime;
			GetLocalTime(&mySystemTime);
			CString timestr;
			timestr.Format(_T("游客%d.%d"),mySystemTime.wMonth,mySystemTime.wDay);
			precardname=timestr;
			femaleprecardname=timestr;
			nnnnprecardname=timestr;
			adminprecardname=timestr;
		}
		else
		{

			precardname=m_grule.precardstr;
			femaleprecardname=m_grule.femaleprecardstr;
			nnnnprecardname=m_grule.nnnnprecardstr;
			adminprecardname=m_grule.adminprecardstr;

		}
		g_ranktitlestr=m_grule.g_ranktitlestr;
		denyreason=m_grule.g_group_denyreason;
		ruleinitscore=m_grule.initscore;
		bTatalSlient=m_grule.bTatalSlient;
		if(!m_grule.g_welcomestr.IsEmpty()&&m_grule.lastwelcomestr.IsEmpty())
		{
			InsertExternalData(m_grule.g_welcomestr,m_grule.lastwelcomestr);
		}
		welcomestr=m_grule.lastwelcomestr;

		//InsertExternalData(welcomestr,welcomestr);
		if(m_grule.g_group_denyreason==_T("禁止重复加群")||g_bForbidReJoin)
		{
			INT64 alreadygroup=FindAlreadyExistQQ(m_qqaccount);
			if(alreadygroup&&alreadygroup!=m_realgroupnumber)
			{
				bAlwaysDeny=true;
				CString alreadygroupstr;
				alreadygroupstr.Format(_T("你已经在%lld群中，禁止重复加群"),alreadygroup);;
				denyreason=alreadygroupstr;
			}
		}


		if(find(m_grule.g_blacklist.begin(),m_grule.g_blacklist.end(),m_qqaccount)!=m_grule.g_blacklist.end())
		{

			bAlwaysDeny=true;
			denyreason=_T("你已经进入群黑名单，无法加入");
		}
		if(!m_grule.g_onlyself)
		{
			if(find(g_defaultqqgrouprule.g_blacklist.begin(),g_defaultqqgrouprule.g_blacklist.end(),m_qqaccount)!=g_defaultqqgrouprule.g_blacklist.end())
			{

				bAlwaysDeny=true;
				denyreason=_T("你已经进入总群黑名单，无法加入");
			}


		}
	}
if(m_realgroupnumber==0)
{

	denyreason=g_friend_welcomemsg;
	welcomestr=g_defaultqqgrouprule.g_welcomestr;
	if(find(g_defaultqqgrouprule.g_blacklist.begin(),g_defaultqqgrouprule.g_blacklist.end(),m_qqaccount)!=g_defaultqqgrouprule.g_blacklist.end())
	{
		bAlwaysDeny=true;
		denyreason=_T("你已经进入黑名单，无法加为好友");
	}


}

	//str222.Format(_T("balwaysdenybegin"));
		
	//Write2MagnetLog(str222,&magnetfile,11);
if(bAlwaysDeny)
{
	if(m_requestuin)
	{
		
	DenyGroupRequest(m_qqgroupid,m_requestuin,m_timesignal,denyreason);
	}
else
{
	DenyFrendRequest(m_qqaccount,m_timesignal,denyreason);
}	

}
else if(opvalue)
{
		CString codecontent;
		CString denyreasonstr;
		if(m_realgroupnumber)
		{
	
	denyreasonstr=m_grule.g_group_denyreason;
					codecontent=m_grule.g_group_pincodestr;
		}
		else
		{

	denyreasonstr=g_friend_welcomemsg;
	//2016.12.18,加好友拒绝理由都是空

	denyreasonstr=_T("");
		codecontent=g_friend_pincodestr;
		}
			BOOL bSameQQ=false;
		BOOL regqqnumflag=false;
		BOOL bDirectlyAgree=false;
		BOOL bneedmanualAgree=false;
		BOOL bDirectDeny=false;
		CString rtdenyreason;
		//http://www.cfxy.me/qqnum?
		//http://buy.cfxy.me/recharge.php?cardseq=
		//自动补足robotqqnum、opqqnum、version、
		BOOL bRechargeflag=false;
		BOOL bLocaldllplugflag=false;
		if(codecontent.Find(_T("recharge"))!=-1)
				{
		bRechargeflag=true;
		}
		if(codecontent.Find(_T(".dll?function="))!=-1)
				{
		bLocaldllplugflag=true;
		}

		if (bRechargeflag || bLocaldllplugflag)
		{

			//这里解析一些变量
			CString frontstr,backstr;
			if (::function::GetHalfStr(codecontent, &frontstr, &backstr, '$', false))
			{
				CString newquerystr;
				newquerystr.Format(_T("交互查询$%s"), backstr);
				char *getbackbuf = new char[512];
				strcpy(getbackbuf, (CStringA)newquerystr);
				HWND inhwnd = 0;
				inhwnd = GetCMsgDlgHwndFromGroupNum(m_realgroupnumber, false);
				SendMessageA((HWND)inhwnd, WM_EXTRESPONSE, (WPARAM)0, (LPARAM)getbackbuf);//WM_EXTRESPONSE
				codecontent = frontstr + (CString)getbackbuf;
				delete getbackbuf;
			}
		}

		INT64 *pQQnum=new INT64;
*pQQnum=m_requestuin;
//AfxBeginThread(ProGetQQMoreProfileInf,pQQnum);

		//str222.Format(_T("progetqqmoreprofileinfbegin"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

ProGetQQMoreProfileInf(pQQnum);

//str222.Format(_T("progetqqmoreprofileinfafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);
//NickSex rttempnicksex;
if(m_bMale==-1)
{
			CString qqnickname;
	



BOOL bGetGenderok=false;
if(opvalue==3)
bGetGenderok=GetUinSingleWholeQQInf(m_qqgroupid,m_requestuin,qqnickname,m_bMale,NULL,50);
else
bGetGenderok=GetUinSingleWholeQQInf(m_qqgroupid,m_requestuin,qqnickname,m_bMale,NULL,10);

if(!bGetGenderok)
{
	Sleep(1000);
bGetGenderok=GetUinSingleWholeQQInf(m_qqgroupid,m_requestuin,qqnickname,m_bMale,NULL,5);
}

//str222.Format(_T("GetUinSingleWholeQQInfafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

	}

struct_qqnum_msg tempqqnumpro;
lockqqmoreprofile.Lock();
	g_qqnum_structmoreprofile_map.Lookup(m_requestuin,tempqqnumpro);
	lockqqmoreprofile.Unlock();
	CString localtionstr;
		
		localtionstr.Format(_T("%s %s %s"),tempqqnumpro.location_state,tempqqnumpro.location_city,tempqqnumpro.location_area);
		localtionstr.Trim();

		CString agestr;

		agestr.Format(_T("%s"),tempqqnumpro.age);
		agestr.Trim();
		CString personalstr;
		personalstr.Format(_T("%s"),tempqqnumpro.personal);
		
		if(m_bMale!=1&&m_bMale!=0)
		{

			if(tempqqnumpro.gender==_T("1"))
		m_bMale=1;
	else if(tempqqnumpro.gender==_T("2"))
		m_bMale=0;

		}

	//	if(agestr.IsEmpty())
		//	agestr.Format(_T("%d"),rttempnicksex.age);

//看看要不要读取qq等级和qq达人信息
int requireminqqlevel=0;
int requireminqqdarenlevel=0;
requireminqqlevel=m_grule.g_group_pinqqlevel;
requireminqqdarenlevel=m_grule.g_group_pinqqdarenlevel;
	int qqlevel=0;
	int qqdarenlevel=0;
	int qqlikenum=0;
if(requireminqqlevel||requireminqqdarenlevel||bRechargeflag)
{
//查询qq等级和qq达人信息
		
	
//str222.Format(_T("GetqqlevelFromMapbefore"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

GetqqlevelFromMap(m_requestuin,qqlevel,qqdarenlevel,qqlikenum,5,false);

if(qqlevel==0&&qqdarenlevel==0)
{
GetqqlevelFromMap(m_requestuin,qqlevel,qqdarenlevel,qqlikenum,5,true);

}

//str222.Format(_T("GetqqlevelFromMapafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

}

if(IsDefaultGroupOwner(m_qqaccount,true))
{
	regqqnumflag=true;

bDirectlyAgree=true;
	
}
	if(!bDenyflag)
	{
	
		//
	
		if(_tcsicmp(codecontent,_T("注册qq"))==0||StrStrI(codecontent,_T("http://")))
		{
		//g_additionalsourceweb
		CString Getverifierstr;
		CString tempstr2;

		contentbackstr.TrimLeft(_T("已注册"));
		contentbackstr.TrimLeft(_T("注册"));
		contentbackstr.TrimLeft(_T("QQ"));
		contentbackstr.TrimLeft(_T("qq"));
		INT64 qqregnum=0;
		if(!bRechargeflag)
		qqregnum=_ttoi64(contentbackstr);
	
		if(qqregnum==0&&!bRechargeflag)
		{
		CString expressstr;
CStringvect temp2vect;

expressstr.Format(_T("\\d{5,20}"));
GetRegEX(contentbackstr,expressstr,temp2vect);//need consider of the actual keyname
if(temp2vect.size()>0)
	qqregnum=_ttoi64(temp2vect[0]);

		}
	/*	if(m_realgroupnumber==229375129)
		if(qqregnum==m_qqaccount)
			bSameQQ=true;*/

		if(qqregnum>10000)
		{
			if(_tcsicmp(codecontent,_T("注册qq"))==0)
			{
				CString newqqnumstr = GetNewQQNumForEncode(qqregnum);
		if(m_realgroupnumber!=229375129&&m_realgroupnumber!=263932252&&m_realgroupnumber!=226519623&&m_realgroupnumber!=477633103&&m_realgroupnumber!=285960406&&m_realgroupnumber!=555421587)
			Getverifierstr.Format(_T("http://www.qqshow123.com/cfnewqqrobot.php?qqnum=%s&pppflag=1"),newqqnumstr);
		else
			Getverifierstr.Format(_T("http://www.qqshow123.com/cfnewqqrobot.php?qqnum=%s&joincheck=%lld"),newqqnumstr,m_qqaccount);

		//qq号跟（当前月份×年份）相加

		Getverifierstr += _T("&version=");
		Getverifierstr += g_purenumberversion;

		Getverifierstr += _T("&checksign=");
		Getverifierstr += GetNewcheckSignCode();// g_checksinstr;g_checksinstr;

			}
			else
			{
				//http://www.cfxy.me/broadcast3.txt.php?word=
				
			Getverifierstr.Format(_T("%s%lld"),codecontent,qqregnum);
	
			}
		}
		else
		{
			if (_tcsicmp(codecontent, _T("注册qq")) == 0)
			{
				//CString newqqnumstr = GetNewQQNumForEncode(qqregnum);
				//Getverifierstr.Format(_T("http://www.cfxy.me/cfnewqqrobot.php?qqnum=%s&pppflag=1"), newqqnumstr);

				//Getverifierstr += _T("&version=");
				//Getverifierstr += g_purenumberversion;

				//Getverifierstr += _T("&checksign=");
				//Getverifierstr += GetNewcheckSignCode();// g_checksinstr;
				//上面的代码导致任意人都可以进注册群了
			}
		else
		{
			if(bRechargeflag)
				{
						CStringA msgA;


	::function::wchrto_utf8(contentbackstr,msgA);
	char bufvalue[2048*10];
	int ddd=msgA.GetLength();
	
		strcpy(bufvalue,(CStringA)msgA);
		int ddd3=strlen(bufvalue);
	::function::urlencode(bufvalue);
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)bufvalue;

	CString sendnickname;


	::function::wchrto_utf8(m_nickname,msgA);
	
	ddd=msgA.GetLength();
	
		strcpy(bufvalue,(CStringA)msgA);
		
	::function::urlencode(bufvalue);
	
	sendnickname=(CString)(CStringA)bufvalue;

	CString sendlocationstr;
CString sendpersonalstr;


	::function::wchrto_utf8(localtionstr,msgA);
	
	ddd=msgA.GetLength();
	
		strcpy(bufvalue,(CStringA)msgA);
		
	::function::urlencode(bufvalue);
	
	
sendlocationstr=(CString)(CStringA)bufvalue;

::function::wchrto_utf8(personalstr,msgA);
	
	ddd=msgA.GetLength();
	
		strcpy(bufvalue,(CStringA)msgA);
		
	::function::urlencode(bufvalue);
	
	
sendpersonalstr=(CString)(CStringA)bufvalue;


	HWND inhwnd=0;
	if(m_realgroupnumber)
		inhwnd=GetCMsgDlgHwndFromGroupNum(m_realgroupnumber,false);
	else
		inhwnd=mainhwnd;
	str222.Format(_T("GetCMsgDlgHwndFromGroupNumafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

				Getverifierstr.Format(_T("%s%s&cfrobotselfnum=%s&cfrobotqqnum=%lld&cfrobotgroupnum=%lld&cfqqlevel=%d&cfqqdarenlevel=%d&cfqqlikenum=%d&cfgender=%d&cfrobotnickname=%s&cfrobotloc=%s&cfrobotage=%s&cfrobotpersonal=%s&myhwnd=%d&version=%s&checksign=%s"),codecontent,tbufv,m_ownqqnumber,m_qqaccount,m_realgroupnumber,qqlevel,qqdarenlevel,qqlikenum,m_bMale,sendnickname,sendlocationstr,agestr,sendpersonalstr,inhwnd,g_purenumberversion,g_ksidmd5);
			
			}
				else
	Getverifierstr.Format(_T("%s%s"),codecontent,contentbackstr);
		
		}
		}
			str222.Format(_T("LocalPlugFunctionbefore"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

	if(bLocaldllplugflag)
		LocalPlugFunction(Getverifierstr,tempstr2);
	else
DownloadWebResultTxt(Getverifierstr,tempstr2);

		str222.Format(_T("LocalPlugFunctionafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

	int rtvalueint=_ttoi(tempstr2);
if(rtvalueint>=2000)
{
	regqqnumflag=true;

bDirectlyAgree=true;
	
}
else if(rtvalueint>=20&&m_realgroupnumber!=229375129&&m_realgroupnumber!=263932252&&m_realgroupnumber!=226519623&&m_realgroupnumber!=477633103&&m_realgroupnumber!=285960406&&m_realgroupnumber!=555421587)
	regqqnumflag=true;
else
{
	if (rtvalueint == 2)
	{
		bDenyflag = true;
		bDirectDeny = true;
	}
	else if (rtvalueint > 2)
	{
		bneedmanualAgree = true;
	}
	else if (rtvalueint == 0)
	{
		if (tempstr2.GetLength() > 1)
		{
			bDenyflag = true;
			rtdenyreason = tempstr2;
		}
	}
	if (StrStrI(contentbackstr, _T("注册qq")))
	{
		contentbackstr = _T("");
	}

	if (StrStrI(contentbackstr, codecontent))
	{
		contentbackstr = _T("");
	}


}


		}
	
		BOOL bMatchRegxflag = false;

		if (IsRegxReply(codecontent))
		{
			if (StrStrI(contentbackstr, codecontent))
contentbackstr= _T("");

			bMatchRegxflag = MatchStar(codecontent, contentbackstr);
		}
		if (!codecontent.IsEmpty() && !StrStrI(contentbackstr, codecontent) && (!bMatchRegxflag) && (!regqqnumflag))
		{
		

		if(denyreasonstr.IsEmpty())//||denyreasonstr==_T("禁止重复加群")
		{

			//if(!m_realgroupnumber)//加好友，如果不符合就要手动批准
		bneedmanualAgree=true;
			
			//denyreason=_T("验证消息不正确，请重新查找正确的验证消息再来申请！");//改成不处理，交给群管手动处理
		}
		else
		{
		//如果是网址返回比2大，比20小的数字，那么还是不处理，由其他管理员手动处理
if(bneedmanualAgree)
{

}
		else
		{
			
			bDenyflag=true;
		
		if(denyreasonstr==_T("自动给出拒绝理由"))
			{
		
				if(bDirectDeny)
				{
				denyreason=_T("你已经被拉进黑名单！");
				}
				else
			denyreason=_T("验证消息不正确，请重新查找正确的验证消息再来申请！");
			}
			else
			denyreason=denyreasonstr;


}
		}

		}
		

		if(!bDirectlyAgree)
		{
		if(m_bMale!=0&&opvalue==3)
		{
	
			if(!denyreasonstr.IsEmpty()&&m_bMale==1)
			{
		bDenyflag=true;
		if(denyreasonstr==_T("自动给出拒绝理由"))
			{
			
			denyreason=_T("只有女性才可加入此群");
		}
		else
			denyreason=denyreasonstr;
		//denyreason=denyreasonstr;
			}
		

		}
		
		if(m_realgroupnumber&&(qqlevel<requireminqqlevel||qqdarenlevel<requireminqqdarenlevel))
		{
		
		if(!denyreasonstr.IsEmpty())
		{
			bDenyflag=true;
			if(denyreasonstr==_T("自动给出拒绝理由"))
			{

				bDenyflag = true;

				if(qqlevel==0&&qqdarenlevel==0)
				{
					denyreason.Format(_T("未识别出QQ等级等信息，请稍后重试加群！"));
				}
				else
				{
					if(qqlevel<requireminqqlevel&&qqdarenlevel<requireminqqdarenlevel)
						denyreason.Format(_T("QQ等级要大于%d，达人天数要大于%d"),requireminqqlevel,requireminqqdarenlevel);
					else if(qqlevel<requireminqqlevel)
						denyreason.Format(_T("QQ等级要大于%d"),requireminqqlevel);
					else if(qqdarenlevel<requireminqqdarenlevel)
						denyreason.Format(_T("QQ达人天数要大于%d"),requireminqqdarenlevel);
				}

			}
		else
		{
			
			denyreason=denyreasonstr;
			
		}
		}
		else		
		bneedmanualAgree=true;


		}
		}

		if(!rtdenyreason.IsEmpty())
		{
		denyreason=rtdenyreason;
		}
		
		if(!bDenyflag&&!bneedmanualAgree)
		{
	if(m_realgroupnumber)
	{

		//str222.Format(_T("BOOL rtflag=AgreeGroupRequestbefore"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

	BOOL rtflag=AgreeGroupRequest(m_qqgroupid,m_requestuin,m_timesignal);
		CString tempstr=welcomestr;
		tempstr.Trim();
		//str222.Format(_T("BOOL rtflag=AgreeGroupRequestafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);
		static INT64 lastqqacount=0;
		if(rtflag)//&&lastqqacount!=m_qqaccount)
		{
		lastqqacount=m_qqaccount;
		BOOL alreadywelcomeflag=false;
		//if(!g_Androidflag)
		{
		Sleep(1500);
//lockwelcomeqqnumres.Lock();
//if(g_alreadywelcomeqqnum.find(m_qqaccount)!=g_alreadywelcomeqqnum.end())
//	alreadywelcomeflag=true;
//if(!alreadywelcomeflag)
//g_alreadywelcomeqqnum.insert(m_qqaccount);
//lockwelcomeqqnumres.Unlock();

HWND mymsghwnd=GetCMsgDlgHwndFromGroupNum(m_qqgroupid);

//str222.Format(_T("HWND mymsghwnd=GetCMsgDlgafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);

	if(m_qqaccount)
	{
		CString cardname;
	GetNickNameFromGroupMap(m_realgroupnumber,m_qqaccount,cardname);
		::SendMessage(mymsghwnd,WM_NEWJOIN,(WPARAM)cardname.GetBuffer(0),(LPARAM)&m_qqaccount);
	}
	//		alreadywelcomeflag=::SendMessage(mymsghwnd,WM_ALREADYWELCOME,(WPARAM)1,(LPARAM)&m_qqaccount);
	
//if(1)//!alreadywelcomeflag)
//{
//GetGlobalMyRank(m_realgroupnumber,m_qqaccount);
//SetProbationTime(m_realgroupnumber,m_qqaccount);
//
//
//}

	
	
	}
		}
	}
	else
	{
	AgreeFriendRequest(m_qqaccount,m_timesignal);
	
	}
		}
	}

	if(bDenyflag)
	{
if(m_requestuin)
	{
		
		//str222.Format(_T("lastDenyGroupRebefore"));
		
	//Write2MagnetLog(str222,&magnetfile,11);
	DenyGroupRequest(m_qqgroupid,m_requestuin,m_timesignal,denyreason);

	//str222.Format(_T("lastDenyGroupReafter"));
		
	//Write2MagnetLog(str222,&magnetfile,11);
}
else
{
	
	DenyFrendRequest(m_qqaccount,m_timesignal,denyreason);
}	
	//拒绝
	}
}

	//g_welcomestr
	
	//str222.Format(_T("okdone"));
		
	//Write2MagnetLog(str222,&magnetfile,11);
	//OnDelSelf();
}

BOOL CPureAcceptRequestDlg::OnInitDialog()
{
	
	if(m_realgroupnumber)
{
	qqgrouprule m_grule;
	if(!GRealNumRulemap.Lookup(m_realgroupnumber,m_grule))
m_grule=g_defaultqqgrouprule;

	if(m_grule.g_group_request_method>0)
	{
		if(m_grule.g_group_request_method==2)

CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO2);
		else
CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	}
}
	else
	{
		if(g_friend_request_method>0)
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1+(g_friend_request_method-1));
	}
	//if(g_slientmode)
	{
	
	OnBnClickedOk();
	}
	

return true;
}
