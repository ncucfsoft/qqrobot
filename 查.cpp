// 查.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "晨风qq机器人.h"
#include "time.h"
#include "sha1.h"

#include "MockHtmlDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
extern INT64 ConvertLocalTimeToInt(const SYSTEMTIME &t1);
extern CString g_grouprankpath;
//const INT64 basetime=1381924903;
CKeepMap<CString,LPCTSTR,CString,LPCTSTR> g_cityidmap;

set<CString> banwordset;
UINT proTimer(LPVOID lp);
BOOL LoadUserSetting(BOOL bLoad);
void InitCityMap();
int g_totalsilent=false;
extern BOOL bExitProcess;
extern BOOL g_bLocalSaveflag;
extern BOOL g_newplaymusicmode;
CString g_groupranksetpath;
//CString g_grouprankpath;
CString g_levelscorepath;

CString g_checkperiodpath;
CString g_addionalpath;
int g_checkperiod;
int g_extrascale=1;
CString g_extrareason;
extern BOOL g_forbidsaveanyrankfile;
 

void catcherror(LPCTSTR path,LPCTSTR error)
{
	CReadAUStdioFile igfile1;
	CString tempstr;
		if(igfile1.Open(path,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
		{
igfile1.WriteLineStr(error);
		igfile1.Close();
		
		}
}
BOOL ExpressResponse(const CString& trimusermsg,LPTSTR responsemsg)
{
	BOOL rtflag=true;
	static CString lastresponsestr;
		static DWORD lasttick=0;
		DWORD ticknow=GetTickCount();
		if(1)//ticknow-lasttick>1000*3*60)
		{
				lasttick=ticknow;
				CString expresscode,querynum;
				IsExpressQuery(trimusermsg,&expresscode,&querynum);
				CString timestr1;
	GetRandomTimeStr(timestr1);	
	CString str;
	UINT ddlen=1024*100;
	byte *bytebuf=new byte[ddlen];

	CString mtgoxfmt;
	CStringvect getcontextbackstr;
	CStringvect gettimebackstr;

	CString expressstr;
				//www.kuaidi100.com/query?type=zhongtong&postid=768118847794&id=1&valicode=&temp=0.3438792673638084
			CString	m_query_mtgox;//=_T("http://data.mtgox.com/api/1/BTCUSD/ticker");
			CString totalcookiesstr;
//			CString realhostname2=_T("cache.kuaidi100.com");
//			CString processpath2;
//			SYSTEMTIME st;
//GetLocalTime(&st);
//	CTime time1(st);
//	CString timestr3,timestr2;
//	timestr3.Format(_T("%lld%03d"),time1.GetTime(),st.wMilliseconds);
//
//		timestr2.Format(_T("%lld%03d"),time1.GetTime(),st.wMilliseconds);
//
//			processpath2.Format(_T("/querycookie.jsp?jsoncallback=jQuery171060452715337872_%s&_=%s"),timestr3,timestr2);
//			//CString additionhead=_T("Referer: http://www.kuaidi100.com/");
//			rtflag=MySendWeb(realhostname2,processpath2,bytebuf,(char*)NULL,ddlen,0,0);
		/*	if(0)
			{
				CString url;
				url.Format(_T("http://%s%s"),realhostname2,processpath2);
				::function::DownloadHttpFile(url,bytebuf,ddlen);
			}*/


		//CString tempstr;
		//tempstr.Format(_T("cstftoken=cdo99AAxDhjsrhw6RxRCW3xe432eAjC2VEq3v4FqhQo;"));
		//InternetSetCookieA( "http://www.kuaidi100.com", NULL, (CStringA)tempstr);

			

			m_query_mtgox.Format(_T("http://www.kuaidi100.com/autonumber/autoComNum?text=%s"),querynum);

CString realhostname;
CString processpath;
realhostname=_T("www.kuaidi100.com");

processpath.Format(_T("autonumber/autoComNum?text=%s"),querynum);

BOOL rtflag=false;
if(expresscode==_T("kuaidikuaidi"))
{
rtflag=MySendWeb(realhostname,processpath,bytebuf,(char*)NULL,ddlen);
CStringvect autocodevect;
expressstr.Format(_T("(?<=\"comCode\":\")\\w+?(?=\")"));
GetRegEX((char*)bytebuf,expressstr,autocodevect);//need consider of the actual keyname
	if(autocodevect.size()>0)
	{
	expresscode=autocodevect[0];
	}
//"comCode":"\\w+",
}
				if(ddlen)//if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
{
	 ddlen=1024*100;
			m_query_mtgox.Format(_T("http://www.kuaidi100.com/query?type=%s&postid=%s&id=1&valicode=&temp=%s"),expresscode,querynum,timestr1);
		///query?type=yuantong&postid=805577715222057702&temp=0.2508688445533593&phone= 
			//processpath.Format(_T("/query?type=%s&postid=%s&id=1&valicode=&temp=%s"),expresscode,querynum,timestr1);
processpath.Format(_T("/query?type=%s&postid=%s&temp=%s&phone="),expresscode,querynum,timestr1);
//
//CString safestr;
//safestr.Format(_T("http://%s%s"),realhostname,processpath);
//	CMockHtmlDlg *tempmsgdlg;
//		tempmsgdlg=new CMockHtmlDlg(safestr,NULL);
//	tempmsgdlg->Create(CMockHtmlDlg::IDD,NULL);
//	tempmsgdlg->ShowWindow(1);
//	Sleep(2000);
rtflag=MySendWeb(realhostname,processpath,bytebuf,(char*)NULL,ddlen);

//if(0)
	//::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen);

if(ddlen)//::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
{
	//str+=(char*)bytebuf;
	CString wstr;
	//context":"
	::function::utf8_wchar((char*)bytebuf,wstr);
	expressstr.Format(_T("(?<=\"context\":\").+?(?=\")"));
	GetRegEX(wstr,expressstr,getcontextbackstr);//need consider of the actual keyname
	expressstr.Format(_T("(?<=\"time\":\").+?(?=\")"));
	GetRegEX(wstr,expressstr,gettimebackstr);//need consider of the actual keyname

	if(gettimebackstr.size()>0&&getcontextbackstr.size()>0)
	{
		//getuinbackstr[4].Replace(_T("\\u00a0"),_T(""));
		int minsize=min(getcontextbackstr.size(),gettimebackstr.size());
		CString tempstr;
		mtgoxfmt=_T("");
		for(int i=0;i<minsize;i++)
		{
			tempstr.Format(_T("%s  %s\r\n"),gettimebackstr[i],getcontextbackstr[i]);
			mtgoxfmt+=tempstr;
		}
		if(mtgoxfmt.GetLength()>=2)
			mtgoxfmt=mtgoxfmt.Left(mtgoxfmt.GetLength()-2);

		//mtgoxfmt.Format(_T("mtgox行情:最高:%s 最低:%s 平均:%s"),getuinbackstr[0],getuinbackstr[1],getuinbackstr[2]);// 总交易量:%s,getuinbackstr[4]
	}
	else
	{
		mtgoxfmt=_T("未查到相关快递信息！");
		rtflag=true;
	}

}
	else
{
	mtgoxfmt=_T("当前快递查询服务器无法访问！");
	rtflag=true;
}
				}
else
{
	mtgoxfmt=_T("当前快递查询服务器无法访问！");
	rtflag=true;
}

lastresponsestr=mtgoxfmt;
		

	delete []bytebuf;
	

		
		}
			lastresponsestr+=_T("【换行】快递查询完毕");
		lstrcpy(responsemsg,lastresponsestr);
			return rtflag;
		
}
BOOL QQPlaySongResponse(const CString& trimusermsg,const CString &addtionalstr,LPTSTR responsemsg,LPCTSTR qqnum,LPCTSTR qqgroupnum)
{

	CString playsongstr;

	if(1)//g_newplaymusicmode)
		playsongstr=_T("newplaysong:");
	else
	playsongstr=_T("playsong:");

	CString askstr,answerstr;

	BOOL bShowSongListAnyway=false;
	if(addtionalstr.Find(_T("列出候选歌曲"))!=-1)
	{
	bShowSongListAnyway=true;
	
	}
	askstr=trimusermsg;
	answerstr=addtionalstr;
	answerstr.Replace(_T("列出候选歌曲"),_T(""));
	CStringA out_utfbuf;
	::function::wchrto_utf8(askstr,out_utfbuf);

	byte bufeee[20025];
	UINT insize=20024;
	strcpy((char*)bufeee,out_utfbuf);

	::function::urlencode((char*)bufeee);
	CStringA strfmtA;
	//strfmtA.Format("http://s.plcloud.music.qq.com/fcgi-bin/smartbox.fcg?o_utf8=1&utf8=1&key=%s&g_tk=%d&loginUin=0&hostUin=0&format=jsonp&inCharset=GB2312&outCharset=utf-8&notice=0",bufeee,m_myg_tk);
	
	strfmtA.Format("http://open.music.qq.com/fcgi-bin/fcg_weixin_music_search.fcg?perpage=30&jsonCallback=searchCallback&g_tk=%d&curpage=1&w=%s",m_myg_tk,bufeee);
	
	
	CString strfmtW=(CString)strfmtA;
	CString widestr;
	BOOL bPConly=false;
	BOOL bFindNothing=false;
	if(0)
		::function::DownloadHttpFile(strfmtW,bufeee,insize);
	bufeee[insize]=0;
	::function::utf8_wchar((char*)bufeee,widestr);
	CStringvect temp2vectid,temp2vectmid,temp2vectname,temp2vectsinger;

	CString expressstr;
CStringvect temp2vect;

//expressstr.Format(_T("(?<=song:\\[).*?(?=\\])"));
expressstr.Format(_T("(?<=\"curnum\" : )\\d+"));

GetRegEX(widestr,expressstr,temp2vect,false,true);//need consider of the actual keyname

BOOL bErrorflag=false;
if(temp2vect.size()==0||_ttoi(temp2vect[0])==0)
{
	strcpy((char*)bufeee,out_utfbuf);

	::function::urlencode((char*)bufeee);
	strfmtA.Format("http://s.plcloud.music.qq.com/fcgi-bin/smartbox.fcg?o_utf8=1&utf8=1&key=%s&g_tk=%d&loginUin=0&hostUin=0&format=jsonp&inCharset=GB2312&outCharset=utf-8&notice=0",bufeee,m_myg_tk);
	//strfmtA.Format("http://soso.music.qq.com/fcgi-bin/multiple_music_search.fcg?mid=1&p=1&catZhida=1&lossless=0&t=100&remoteplace=txt.yqqlist.all&utf8=1&w=%s",bufeee);
	
	CString strfmtW=(CString)strfmtA;
	CString widestr;
	::function::DownloadHttpFile(strfmtW,bufeee,insize);
	if(insize==0)
		bErrorflag=true;


	bufeee[insize]=0;
	::function::utf8_wchar((char*)bufeee,widestr);

	CString expressstr;
CStringvect temp2vect;

expressstr.Format(_T("(?<=song:\\[).*?(?=\\])"));

if(0)
	MessageBox(0,widestr,0,0);
GetRegEX(widestr,expressstr,temp2vect,0,true);//need consider of the actual keyname

	if(insize)
	{
		if(temp2vect.size()==0||temp2vect[0].IsEmpty())
	bFindNothing=true;
	}
if(bFindNothing&&(askstr.Find(_T("—"))!=-1||askstr.Find(_T("_"))!=-1||askstr.Find(_T("-"))!=-1))
{
//askstr.Find(_T("的"))!=-1||
	//askstr.Replace(_T("的"),_T(""));
	askstr.Replace(_T("—"),_T(""));
	askstr.Replace(_T("_"),_T(""));
	askstr.Replace(_T("-"),_T(""));
	::function::wchrto_utf8(askstr,out_utfbuf);

	strcpy((char*)bufeee,out_utfbuf);

	::function::urlencode((char*)bufeee);
	strfmtA.Format("http://s.plcloud.music.qq.com/fcgi-bin/smartbox.fcg?o_utf8=1&utf8=1&key=%s&g_tk=%d&loginUin=0&hostUin=0&format=jsonp&inCharset=GB2312&outCharset=utf-8&notice=0",bufeee,m_myg_tk);
	//strfmtA.Format("http://soso.music.qq.com/fcgi-bin/multiple_music_search.fcg?mid=1&p=1&catZhida=1&lossless=0&t=100&remoteplace=txt.yqqlist.all&utf8=1&w=%s",bufeee);
	
	strfmtW=(CString)strfmtA;
	insize=20024;
	::function::DownloadHttpFile(strfmtW,bufeee,insize);
	bufeee[insize]=0;
	::function::utf8_wchar((char*)bufeee,widestr);


expressstr.Format(_T("(?<=song:\\[).*?(?=\\])"));

GetRegEX(widestr,expressstr,temp2vect,0,true);//need consider of the actual keyname

if(temp2vect.size()==0||temp2vect[0].IsEmpty())
{

		lstrcpy(responsemsg,_T("未找到合适的歌曲，请试试换一个歌曲名或歌手名，记得歌手名和歌曲名之间用空格隔开！——也可能是腾讯音乐服务器忙，请稍后重试！"));
		

		return true;
}

}

if(temp2vect.size()>0&&!temp2vect[0].IsEmpty())
{
	bPConly=true;
	expressstr.Format(_T("(?<=id:)\\d+"));

GetRegEX(temp2vect[0],expressstr,temp2vectid,0,true);//need consider of the actual keyname

	
	expressstr.Format(_T("(?<=mid:\").*?(?=\",)"));

GetRegEX(temp2vect[0],expressstr,temp2vectmid,0,true);//need consider of the actual keyname

expressstr.Format(_T("(?<=\", name:\").*?(?=\", singer_name:)"));

GetRegEX(temp2vect[0],expressstr,temp2vectname,0,true);//need consider of the actual keyname

expressstr.Format(_T("(?<=singer_name:\").*?(?=\")"));

GetRegEX(temp2vect[0],expressstr,temp2vectsinger,0,true);//need consider of the actual keyname

}

}

if(bErrorflag||bFindNothing)
{
	strcpy((char*)bufeee,out_utfbuf);

	::function::urlencode((char*)bufeee);

	strfmtA.Format("http://open.music.qq.com/fcgi-bin/fcg_weixin_music_search.fcg?perpage=30&jsonCallback=searchCallback&g_tk=%d&curpage=1&w=%s",m_myg_tk,bufeee);
	
	
	strfmtW=(CString)strfmtA;

	bPConly=false;
	insize=20024;
		::function::DownloadHttpFile(strfmtW,bufeee,insize);
	bufeee[insize]=0;
	::function::utf8_wchar((char*)bufeee,widestr);

CStringvect temp2vect;

//expressstr.Format(_T("(?<=song:\\[).*?(?=\\])"));
expressstr.Format(_T("(?<=\"curnum\" : )\\d+"));

GetRegEX(widestr,expressstr,temp2vect,0,true);

if(temp2vect.size()==0||temp2vect[0].IsEmpty())
{

		lstrcpy(responsemsg,_T("未找到合适的歌曲，请试试换一个歌曲名或歌手名，记得歌手名和歌曲名之间用空格隔开！——也可能是腾讯音乐服务器忙，请稍后重试！"));
		

		return true;
}

}

if(bPConly==false)
{

	expressstr.Format(_T("(?<=\"id\" : )\\d+"));

GetRegEX(widestr,expressstr,temp2vectid,0,true);//need consider of the actual keyname

	
	expressstr.Format(_T("(?<=\"m4a\" : \").*?(?=\")"));

GetRegEX(widestr,expressstr,temp2vectmid,0,true);//need consider of the actual keyname

expressstr.Format(_T("(?<=\"songname\" : \").*?(?=\")"));

GetRegEX(widestr,expressstr,temp2vectname,0,true);//need consider of the actual keyname

expressstr.Format(_T("(?<=\"singername\" : \").*?(?=\")"));

GetRegEX(widestr,expressstr,temp2vectsinger,0,true);//need consider of the actual keyname

//if(temp2vectid.size()>0&&temp2vectid.size()==temp2vectname.size()&&temp2vectname.size()==temp2vectsinger.size())


}

if(temp2vectid.size()>0&&temp2vectmid.size()>0&&temp2vectname.size()>0&&temp2vectsinger.size()>0)
{

	int minsize=temp2vectid.size();
	minsize=min(minsize,temp2vectmid.size());
	minsize=min(minsize,temp2vectname.size());
	minsize=min(minsize,temp2vectsinger.size());

	CString playsongfmt;
	CString singername;
	CString songname;
	CString srcurlstr;


	CStringvect musicvectemp;
	
	
	::function::getmytoken(askstr,_T(" -—_"),musicvectemp);
	BOOL bFindonebest=false;
	BOOL bOnlyOneflag=false;
	bFindonebest=temp2vectname[0]==askstr||(musicvectemp.size()>1&&musicvectemp[0]==temp2vectsinger[0]&&musicvectemp[1]==temp2vectname[0]);
	bOnlyOneflag=temp2vectid.size()==1;
	
	if(((!g_smarttipsforsong||bFindonebest)&&!bShowSongListAnyway)||bOnlyOneflag)
	{
		singername=temp2vectsinger[0];
songname=temp2vectname[0];
	singername.Replace(_T("&"),_T("&amp;"));
	songname.Replace(_T("&"),_T("&amp;"));

	if(songname.IsEmpty())
		songname=_T("未知");
	if(singername.IsEmpty())
		singername=_T("佚名");
	srcurlstr=temp2vectmid[0];

	srcurlstr.Replace(_T("&"),_T("&amp;"));

		if(bPConly)
	{
		srcurlstr.Format(_T("http://ws.stream.qqmusic.qq.com/%s.m4a?fromtag=30"),temp2vectid[0]);
	playsongfmt.Format(_T("%s%s|%s|%s|%s|XXX花了$扣除10$积分点歌%s——点歌花费提示完毕！【非游戏不关闭】%s"),playsongstr,temp2vectid[0],srcurlstr,songname,singername,songname,answerstr);
	}
	else
playsongfmt.Format(_T("%s%s|%s|%s|%s|XXX花了$扣除10$积分点歌%s——点歌花费提示完毕！【非游戏不关闭】%s"),playsongstr,temp2vectid[0],srcurlstr,songname,singername,songname,answerstr);

	if(bOnlyOneflag)
	{
		
		CString playsongftmnoanser=playsongfmt;
		TrimRight(playsongftmnoanser,answerstr);
		g_playsongreplymap[askstr]=playsongftmnoanser;
		
	}

	}
	else
	{
	CString tempstr;
		CString tempstrtips;
		CString showtempstrtips;

	CString fmtstrtemp;
	CString showfmtstrtemp;

	CString singer_songname;
	CString orgsingername;
	CString orgsongname;

			for(int i=0;i<minsize;i++)
			{


						singername=temp2vectsinger[i];
songname=temp2vectname[i];	
	if(songname.IsEmpty())
		songname=_T("未知");
	if(singername.IsEmpty())
		singername=_T("佚名");
orgsingername=singername;
orgsongname=songname;
	songname.Replace(_T("&"),_T("&amp;"));
singername.Replace(_T("&"),_T("&amp;"));
	

	srcurlstr=temp2vectmid[i];

	srcurlstr.Replace(_T("&"),_T("&amp;"));

		if(bPConly)
	{
		srcurlstr.Format(_T("http://ws.stream.qqmusic.qq.com/%s.m4a?fromtag=30"),temp2vectid[i]);
	playsongfmt.Format(_T("%s%s|%s|%s|%s|XXX花了$扣除10$积分点歌%s——点歌花费提示完毕！【非游戏不关闭】%s"),playsongstr,temp2vectid[i],srcurlstr,songname,singername,songname,answerstr);
	}
	else
playsongfmt.Format(_T("%s%s|%s|%s|%s|XXX花了$扣除10$积分点歌%s——点歌花费提示完毕！【非游戏不关闭】%s"),playsongstr,temp2vectid[i],srcurlstr,songname,singername,songname,answerstr);

		singer_songname=orgsingername+_T(" ");
		singer_songname+=orgsongname;

		CString playsongftmnoanser=playsongfmt;
		TrimRight(playsongftmnoanser,answerstr);
		g_playsongreplymap[singer_songname]=playsongftmnoanser;
		
		if(i+1>9)
		{
		fmtstrtemp.Format(_T("%dface54 点歌%s"),i+1,singer_songname);
		showfmtstrtemp.Format(_T("%dface54 %s"),i+1,singer_songname);//没有点歌二字，看起来更简洁
		}
		else
		{
		fmtstrtemp.Format(_T("%d  face54 点歌%s"),i+1,singer_songname);
		showfmtstrtemp.Format(_T("%d  face54 %s"),i+1,singer_songname);//没有点歌二字，看起来更简洁
		
		}
	tempstrtips+=fmtstrtemp;
	tempstrtips+=_T("\r\n");
	showtempstrtips+=showfmtstrtemp;
	showtempstrtips+=_T("\r\n");

	if(showtempstrtips.GetLength()>400)
		break;
			}

			if(showtempstrtips.GetLength()>0)
			{
				locksongmapsource.Lock();
				if(g_querysongquickmap.GetCount()>100)
					g_querysongquickmap.RemoveAll();

				g_querysongquickmap[_ttoi64(qqnum)]=tempstrtips;
				locksongmapsource.Unlock();
			tempstr.Format(_T("XXX【换行】你要点的歌是不是【回复数字可快捷点歌】：\r\n%s点歌智能提示完毕！"),showtempstrtips);

			playsongfmt=tempstr;
		
			}
	}
		lstrcpy(responsemsg,playsongfmt);
	}
else
{
	lstrcpy(responsemsg,_T("查询歌曲返回的数据格式异常，请试试换一个歌曲名或歌手名，记得歌手名和歌曲名之间用空格隔开！"));
}



	
	

	//点歌你怎么舍得我难过【送给某某某】
	//XXX花了10积分点歌【送给某某某】
	return true;
}
BOOL QQvisitResponse(const CString& trimusermsg,LPTSTR responsemsg,LPCTSTR qqnum,LPCTSTR qqgroupnum,LPCTSTR otherqqnum)
{
	BOOL rtflag=true;
	CString	m_query_mtgox;
	CString actualqq=qqnum;
	if(lstrlen(otherqqnum))
		actualqq=otherqqnum;

	//m_query_mtgox.Format(_T("/cgi-bin/friendshow/cgi_get_visitor_simple?uin=%s&mask=2&g_tk=%d&page=1&fupdate=1"),actualqq,m_myg_tk);
	
	//	m_query_mtgox.Format(_T("http://g.qzone.qq.com/cgi-bin/friendshow/cgi_get_visitor_simple?uin=%s&mask=2&g_tk=%d&page=1&fupdate=1"),actualqq,m_myg_tk);
//http://g.cnc.qzone.qq.com/fcg-bin/cgi_emotion_list.fcg?uin=68663216&loginUin=3095087199&s=250195&num=3&g_tk=421960485		

	CString str;
	UINT ddlen=1024*500;
	byte *bytebuf=new byte[ddlen];

	CString mtgoxfmt;
	CStringvect todaycountstrvect;
	CStringvect totalcountstrvect;

	CString expressstr;

	CString realhostname;
CString processpath;
realhostname=_T("g.qzone.qq.com");

//processpath.Format(_T("/fcg-bin/cgi_emotion_list.fcg?uin=%s&loginUin=%lld&s=250195&num=3&g_tk=%d"),actualqq,g_interfaceuin,m_myg_tk);
processpath.Format(_T("/cgi-bin/friendshow/cgi_get_visitor_simple?uin=%s&mask=2&g_tk=%d&page=1&fupdate=1"),actualqq,m_myg_tk);
CStringA strfmt;
strfmt.Format("uin=%s&mask=2&g_tk=%d&page=1&fupdate=1",(CStringA)actualqq,m_myg_tk);
	strcpy((char*)bytebuf,strfmt);
	//CString dddrrrr;
	//	dddrrrr.Format(_T("MySendWeb前:%s"),actualqq);
	//MessageBox(0,dddrrrr,responsemsg,0);

CString additionalhead;
	//	additionalhead.Format(_T("Cookie: skey=%s;uin=o%lld;p_skey=%s\r\n"),g_skey,g_interfaceuin,g_qqsuperkey);
		ddlen=500*1024;//strlen(strfmt);
rtflag=MySendWeb(realhostname,processpath,bytebuf,(char*)NULL,ddlen,0,0);

//CStringA tempoutstr;
//::function::utf8_char((char*)bytebuf,tempoutstr);

//MessageBoxA(0,(char*)bytebuf,tempoutstr,0);
	if(ddlen)//if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
	{
	CString closenickname;
	INT64 realqqgroupnum=_ttoi64(qqgroupnum);
	INT64 realqqnum=_ttoi64(actualqq);

	GetNickNameFromGroupMap(realqqgroupnum,realqqnum,closenickname);
	
	//str+=(char*)bytebuf;
		CString wstr;
	//context":"
	//::function::utf8_wchar((char*)bytebuf,wstr);
	expressstr.Format(_T("(?<=\"todaycount\":)\\d+\\b"));//expressstr.Format(_T("(?<=\"todaycount\":)\\d+\\b"));
GetRegEX((char*)bytebuf,expressstr,todaycountstrvect);//need consider of the actual keyname
	expressstr.Format(_T("(?<=\"totalcount\":)\\d+\\b"));//expressstr.Format(_T("(?<=\"totalcount\":)\\d+\\b"));
GetRegEX((char*)bytebuf,expressstr,totalcountstrvect);//need consider of the actual keyname

if(todaycountstrvect.size()>0&&totalcountstrvect.size()>0)
{
	//【　　　　    熙ヽ　　　】QQ空间总浏览量：2735213|今日浏览量：1868
	mtgoxfmt.Format(_T("【%s】QQ空间总浏览量：%s|今日浏览量：%s"),closenickname,totalcountstrvect[0],todaycountstrvect[0]);// 总交易量:%s,getuinbackstr[4]
}
else
{
	if(lstrlen(otherqqnum))
	mtgoxfmt.Format(_T("无法访问【%s】QQ空间！"),closenickname);
	else
	{

mtgoxfmt.Format(_T("无法访问【%s】QQ空间！"),closenickname);
	}
	
	rtflag=true;
}

	}
else
{
	mtgoxfmt=_T("当前无法连接qq空间服务器！");
	rtflag=true;
}



	delete []bytebuf;
	

		

		
		lstrcpy(responsemsg,mtgoxfmt);
			return rtflag;
		
}
BOOL QueryPoemResponse(const CString& trimusermsg,LPTSTR responsemsg)
{
	BOOL rtflag=true;
	CString	m_query_mtgox;
	int type57=0;
	CString querypeom;
		IsHidePoemQuery(trimusermsg,&type57,&querypeom);
		CString formtquerypoem;
		CString tempff;
		for(int i=0;i<lstrlen(querypeom);i++)
		{
		tempff.Format(_T("%%u%X"),querypeom[i]);
		formtquerypoem+=tempff;
		}

		//%u5929%u4E0B%u65E0%u654C
			m_query_mtgox.Format(_T("http://cts.388g.com/fasong.php?w=%s&num=%d&type=1&yayuntype=1"),formtquerypoem,type57);
			CString str;
	UINT ddlen=1024*100;
	byte *bytebuf=new byte[ddlen];

	CString mtgoxfmt;
	
	CStringA expressstrA;
	CString expressstrW;
	CString expressstr;
	if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
{
	expressstrW=::function::CStrA2CStrW((char*)bytebuf);
	//expressstrA=bytebuf;
expressstrW.Replace(_T("'><font color=red><b>"),_T("'begin'"));
expressstrW.Replace(_T("<font color=red><b>"),_T(""));
expressstrW.Replace(_T("</b></font>"),_T(""));
expressstrW.Replace(_T("。<br/>"),_T("\r\n"));
expressstrW.Replace(_T("，<br/>"),_T("\r\n"));
expressstrW.Replace(_T("<br/>"),_T("\r\n"));
//expressstrA.Replace("。<br/>",RNDEFBUFA);
//expressstrA.Replace("，<br/>",RNDEFBUFA);
//expressstrA.Replace("<br/>",RNDEFBUFA);
expressstrW.Replace(_T("情****尚识返"),_T("情春色尚识返"));

	expressstr.Format(_T("(?<='begin').+?(?=</div>)"));
	CStringvect poemvect;
GetRegEX(expressstrW,expressstr,poemvect,0,true);
	//expressstrW=expressstrA;

	int randnum=0;
	if(poemvect.size())
	{
	
	randnum=rand()%poemvect.size();
	mtgoxfmt=poemvect[randnum];
	}
	else
	{
	mtgoxfmt.Format(_T("没找到合适的藏头诗可以匹配【%s】！"),querypeom);
	}
	//AfxMessageBox(expressstrW);
		rtflag=true;
	}
else
{
	mtgoxfmt=_T("当前无法连接藏头诗服务器！");
	rtflag=true;
}



	delete []bytebuf;
	

		
	mtgoxfmt+=_T("【换行】藏头诗查询完毕");
		
		lstrcpy(responsemsg,mtgoxfmt);
			return rtflag;
		
}

void GetGambleRobTimesFromFile(BOOL bLoad,INT64 realgroupnumber)
{
	CReadAUStdioFile file1(true);
	CString strfmt;
		strfmt.Format(_T("%I64d群成员赌博抢劫次数.txt"),realgroupnumber);
		CString filepath=g_grouprankpath+strfmt;
		CString tempstr;
		if(bLoad)
	{
	
			
			CQQGamblerobtimesKeepMap *g_speakrankmap=new CQQGamblerobtimesKeepMap();
			g_groupgrtimesmap[realgroupnumber]=g_speakrankmap;

		
			if(file1.Open(filepath,CFile::modeRead|CFile::shareDenyNone))
		{
		CStringvect vectemp;
		INT64 tempqqnumber;
		qqgroupgamblerobtimes temprank;
while(file1.ReadString(tempstr))
{
	::function::getmytoken(tempstr,'\t',vectemp);
if(vectemp.size()>=1)
{
	tempqqnumber=_ttoi64(vectemp[0]);

	if(vectemp.size()>=8)
		{
		temprank.activeday=_ttoi(vectemp[1]);
		temprank.gambletimes=_ttoi(vectemp[2]);
		temprank.wintimes=_ttoi(vectemp[3]);
		temprank.winscore=_ttoi64(vectemp[4]);
		temprank.robtimes=_ttoi(vectemp[5]);
		temprank.robwintimes=_ttoi(vectemp[6]);
		temprank.robwinscore=_ttoi64(vectemp[7]);
		

		}


	(*g_speakrankmap)[tempqqnumber]=temprank;
}

}

	file1.Close();
			}
	
			

	}
	else
	{
		
		
			if(file1.Open(filepath,CFile::modeCreate|CFile::modeWrite))
		{
		CString tempstr;
		INT64 tempqqnumber;
		
		
		CQQGamblerobtimesKeepMap* g_rankmap=g_groupgrtimesmap[realgroupnumber];
		for(UINT i=0;i<(*g_rankmap).m_mapstr.size();i++)
		{
			qqgroupgamblerobtimes& temprank=(*g_rankmap)[i];
		tempstr.Format(_T("%I64d\t%d\t%d\t%d\t%I64d\t%d\t%d\t%I64d"),(*g_rankmap).m_mapstr[i],temprank.activeday,temprank.gambletimes,temprank.wintimes,temprank.winscore,temprank.robtimes,temprank.robwintimes,temprank.robwinscore);
		file1.WriteLineStr(tempstr);
		}

	file1.Close();
			}

	
	}
}

void GetSpeakRankFromFile(BOOL bLoad,INT64 realgroupnumber)
{
	CReadAUStdioFile file1(true);
	CString strfmt;
		strfmt.Format(_T("%I64d发言次数.txt"),realgroupnumber);
		CString filepath=g_grouprankpath+strfmt;
		CString tempstr;
		if(bLoad)
	{
	
			
			CQQSpeakRankKeepMap *g_speakrankmap=new CQQSpeakRankKeepMap();
			g_groupspeakrankmap[realgroupnumber]=g_speakrankmap;

		
			if(file1.Open(filepath,CFile::modeRead|CFile::shareDenyNone))
		{
		CStringvect vectemp;
		INT64 tempqqnumber;
		qqgroupspeakrank temprank;
while(file1.ReadString(tempstr))
{
	::function::getmytoken(tempstr,'\t',vectemp);
if(vectemp.size()>=1)
{
	tempqqnumber=_ttoi64(vectemp[0]);
		if(vectemp.size()>2)
		{
		temprank.activeweek=_ttoi(vectemp[1]);
		temprank.speaktimes=_ttoi(vectemp[2]);
		}
			int nowweek=qqgroupspeakrank::getcurrentweek();
		if(nowweek!=temprank.activeweek)
		{
			temprank.speaktimes=0;
			temprank.activeweek=nowweek;
		}

	(*g_speakrankmap)[tempqqnumber]=temprank;
}

}

	file1.Close();
			}
	
			

	}
	else
	{
		
		
			if(file1.Open(filepath,CFile::modeCreate|CFile::modeWrite))
		{
		CString tempstr;
		INT64 tempqqnumber;
		
		
		CQQSpeakRankKeepMap* g_rankmap=g_groupspeakrankmap[realgroupnumber];
		for(UINT i=0;i<(*g_rankmap).m_mapstr.size();i++)
		{
			qqgroupspeakrank& temprank=(*g_rankmap)[i];
		tempstr.Format(_T("%I64d\t%d\t%d"),(*g_rankmap).m_mapstr[i],temprank.activeweek,temprank.speaktimes);
		file1.WriteLineStr(tempstr);
		}

	file1.Close();
			}

	
	}
}

void GetMedal4buf(BOOL bReadflag,CString& tempgoodsstr,CString* pmedalgoods)
{
	
	if(bReadflag)
	{
	CString curgoodsstr;
	int i=0;
for(i=0;i<tempgoodsstr.GetLength();i++)
{
	if((tempgoodsstr.GetAt(i)>'9'||tempgoodsstr.GetAt(i)<'0')&&tempgoodsstr.GetAt(i)!='-')
		break;
}
curgoodsstr=tempgoodsstr.Mid(i);

	curgoodsstr.Trim();
	CStringvect vectemp;
	::function::getmytoken(curgoodsstr,'|',vectemp);
	int minsize=min(vectemp.size(),goodsnum);
	
	for(int i=0;i<minsize;i++)
	{
	pmedalgoods[i]=vectemp[i];
	}

	}
	else
	{
		CString curgoodsstr;

		for(int i=0;i<goodsnum;i++)
		{
	curgoodsstr+=pmedalgoods[i];
	curgoodsstr+=_T("|");
		}
	
	int len=curgoodsstr.GetLength();
	if(len<100)
	{
		for(int i=0;i<100-len;i++)
		{
	curgoodsstr+=_T(" ");
		}
	}

	tempgoodsstr=curgoodsstr;

	}

}
void GetMedalNbuf(BOOL bReadflag,CString& tempgoodsstr,CString* pmedalgoods)
{
	
	if(bReadflag)
	{
	CString curgoodsstr;

curgoodsstr=tempgoodsstr;

	curgoodsstr.Trim();
	CStringvect vectemp;
	::function::getmytoken(curgoodsstr,'|',vectemp);
	int minsize=min(vectemp.size(),goodsnum);
	
	for(int i=0;i<minsize;i++)
	{
	if(i==1)
	{
		
		pmedalgoods[i]=vectemp[i];
				if(pmedalgoods[i].Find(_T("imgorurl"))!=-1)
					pmedalgoods[i].Replace(_T("imgorurl"),_T("|"));


	}
	else
		pmedalgoods[i]=vectemp[i];

	}

	}
	else
	{
		CString curgoodsstr;
		
		for(int i=0;i<goodsnum;i++)
		{
	//		if(pmedalgoods[i].IsEmpty())
	//curgoodsstr+=_T("无");
	//		else
			if(i==1)
			{
				CString temppmedalgoods=pmedalgoods[i];

				if(temppmedalgoods.Find(_T("|"))!=-1)
					temppmedalgoods.Replace(_T("|"),_T("imgorurl"));
				if(temppmedalgoods.Find(_T("\r\n"))!=-1)
					temppmedalgoods.Replace(_T("\r\n"),RNDEFBUF);

		curgoodsstr+=temppmedalgoods;	
			}
			else
	curgoodsstr+=pmedalgoods[i];

	curgoodsstr+=_T("|");
		}
	
	int len=curgoodsstr.GetLength();
	if(len<100)
	{
		for(int i=0;i<100-len;i++)
		{
	curgoodsstr+=_T(" ");
		}
	}

	tempgoodsstr=curgoodsstr;

	}

}

void GetRankFromFile(BOOL bLoad,INT64 realgroupnumber,int daynum)
{
	if(!bLoad)
	{
	if(g_forbidsaveanyrankfile)
		return;
	}
	CReadAUStdioFile file1(true);
	
	CString strfmt;
		strfmt.Format(_T("%I64d"),realgroupnumber);
		CString filepath=g_grouprankpath+strfmt;
		CString tempstr;
		
	
		CString lastfilepath=filepath+_T(".最后一次记录");
		CString lastdayfilepath=filepath+_T(".昨天的记录");
		CString lastnextfilepath=filepath+_T(".前天的记录");
		filepath+=_T(".txt");
		lastfilepath+=_T(".txt");
		lastnextfilepath+=_T(".txt");
		lastdayfilepath+=_T(".txt");
		SYSTEMTIME curSystemTime;
	GetLocalTime(&curSystemTime);
		int nowday=curSystemTime.wDay;
	int nowmonth=curSystemTime.wMonth;
	
	
		DWORD sizefold=::function::GetFileSizeFromPath(lastfilepath);
		DWORD sizefnew=::function::GetFileSizeFromPath(filepath);
	if(bLoad)
	{
	
			
			CQQRankKeepMap *g_rankmap=NULL;
			
			BOOL bWaitToclear=false;

			if(!g_grouprankmap.Lookup(realgroupnumber,g_rankmap))
			{
			g_rankmap=new CQQRankKeepMap();
			}
			else
			{
				bWaitToclear=true;
			
			}
			g_grouprankmap[realgroupnumber]=g_rankmap;

			if(!daynum)
			{
				//if(sizefold>3*sizefnew)
		if(!sizefnew&&sizefold)
		{
			static int tipsonce = false;
			if (!tipsonce)
			{
				tipsonce = true;
				AfxMessageBox(_T("积分文件意外丢失，请查清具体的原因，软件将自动启用最后一次记录的积分文件！"));
			}

			Sleep(2000);
			sizefnew = ::function::GetFileSizeFromPath(filepath);
			if (!sizefnew)
		::function::RemoveR_CopyFileW(lastfilepath,filepath,false);
		
		}
			}
				try
				{
					CString whichdayfilepath=filepath;
					if(daynum==1)
					{
						whichdayfilepath=lastdayfilepath;
					}
					else if(daynum==2)
					{
						whichdayfilepath=lastnextfilepath;
					}
					else if(daynum==3)
					{
						whichdayfilepath=lastfilepath;
					}
					if(file1.Open(whichdayfilepath,CFile::modeRead|CFile::shareDenyNone))
		{
			if(bWaitToclear)
			g_rankmap->RemoveAll();

		CStringvect vectemp;
		INT64 tempqqnumber;
		qqgrouprank temprank;
while(file1.ReadString(tempstr))
{
	::function::getmytoken(tempstr,'\t',vectemp);
	
	tempqqnumber=_ttoi64(vectemp[0]);
	if(!tempqqnumber)
		continue;
	if(tempqqnumber<1000)
		continue;
if(vectemp.size()==3)//兼容原来的积分和装备之间没有tab键的版本
{
	
		temprank.total_score=_ttoi64(vectemp[1]);
		GetMedal4buf(true,vectemp[1],temprank.medalgoods);
		
		temprank.timevectstr=vectemp[2];
		
	(*g_rankmap)[tempqqnumber]=temprank;
}
else if(vectemp.size()>=4)//
{
	
		temprank.total_score=_ttoi64(vectemp[1]);
		GetMedalNbuf(true,vectemp[2],temprank.medalgoods);
		
		temprank.timevectstr=vectemp[3];
		if(vectemp.size()>=5)
		temprank.enemyvectstr=vectemp[4];
		if(vectemp.size()>=6)
		temprank.ownerqq=_ttoi64(vectemp[5]);
	if(vectemp.size()>=7)
		temprank.bidprice=_ttoi64(vectemp[6]);
if(vectemp.size()>=8)
		temprank.vipendtime=_ttoi64(vectemp[7]);
if(vectemp.size()>=9)
		temprank.likenum=_ttoi64(vectemp[8]);
if(vectemp.size()>=11)
{
		temprank.leftlikenum=_ttoi64(vectemp[9]);
temprank.lefthatenum=_ttoi64(vectemp[10]);
}
if(vectemp.size()>=13)
{
temprank.jointime=_ttoi64(vectemp[11]);
temprank.totalspeaktimes=_ttoi64(vectemp[12]);
if(vectemp.size()>=14)
{
temprank.lastactivetime=_ttoi64(vectemp[13]);
temprank.last_lastacttivetime=temprank.lastactivetime;
}
if(vectemp.size()>=15)
{
temprank.blackhouse_endtime=_ttoi64(vectemp[14]);
}
if(vectemp.size()>=16)
{
temprank.qqscore=_ttoi(vectemp[15]);
}


}

	(*g_rankmap)[tempqqnumber]=temprank;
}


}

	file1.Close();
			}
				}
				catch(CFileException e)
				{
					static int tipsonce = false;
					if (!tipsonce)
					{
						tipsonce = true;
						str222.Format(_T("%I64d:读取文件错误%d"), realgroupnumber, e.m_cause);
						AfxMessageBox(str222);
						Write2MagnetLog(str222, &magnetfile, 4);
					
					}
				}
			

	}
	else
	{
			static int tipsonce = false;
	try
	{
	
	
		::function::RemoveRH(filepath);
			if(file1.Open(filepath,CFile::modeCreate|CFile::modeWrite))//|CFile::shareDenyNone
			{
		CString tempstr;
		INT64 tempqqnumber;
		
		
		CQQRankKeepMap* g_rankmap=g_grouprankmap[realgroupnumber];
		for(UINT i=0;i<(*g_rankmap).m_mapstr.size();i++)
		{
			qqgrouprank& temprank=(*g_rankmap)[i];
			//(%s|%s|%s|%s)
			CString tempgoodsstr;
			GetMedalNbuf(false,tempgoodsstr,temprank.medalgoods);
			//temprank.timevectstr=_T("999;");
		tempstr.Format(_T("%I64d\t%020I64d\t%s\t%s\t%s\t%I64d\t%I64d\t%I64d\t%I64d\t%I64d\t%I64d\t%I64d\t%I64d\t%I64d\t%I64d\t%d"),(*g_rankmap).m_mapstr[i],temprank.total_score,tempgoodsstr,temprank.timevectstr,temprank.enemyvectstr,temprank.ownerqq,temprank.bidprice,temprank.vipendtime,temprank.likenum,temprank.leftlikenum,temprank.lefthatenum,temprank.jointime,temprank.totalspeaktimes,temprank.lastactivetime,temprank.blackhouse_endtime,temprank.qqscore);
		file1.WriteLineStr(tempstr);
		}

	file1.Close();
			}
	}
		catch(CFileException e)
				{

			if (!tipsonce)
			{
				tipsonce = true;
				str222.Format(_T("%I64d:写入文件错误%d"), realgroupnumber, e.m_cause);
				AfxMessageBox(str222);
			}
		Write2MagnetLog(str222,&magnetfile,12);
				}

			 SYSTEMTIME lastwritest;
 ::function::GetMoudleVariousTime(lastwritest,2,lastdayfilepath);
	
			 SYSTEMTIME last2writest;
 ::function::GetMoudleVariousTime(last2writest,2,lastfilepath);
	
 INT64 nowtimevalue=ConvertLocalTimeToInt(curSystemTime);
  INT64 lasttimevalue=ConvertLocalTimeToInt(last2writest);
 if(!bExitProcess&&nowtimevalue-lasttimevalue>3600&&nowtimevalue-initsystemtime>3600)
 {
		BOOL bsave1=::function::RemoveR_CopyFileW(filepath,lastfilepath,false);
		if (!bsave1)
		{
			Sleep(1000);
			bsave1=::function::RemoveR_CopyFileW(filepath,lastfilepath,false);
			if (!bsave1)
			{
				if (!tipsonce)
				{
					tipsonce = true;
					str222.Format(_T("覆盖最后一次积分文件失败！"));
					//AfxMessageBox(str222);
				}
			}
		}
}	

	if(lastwritest.wDay!=nowday)
	{
	
		BOOL bsave1=::function::RemoveR_CopyFileW(lastdayfilepath, lastnextfilepath, false);
		if (!bsave1)
		{
			Sleep(1000);
			bsave1 = ::function::RemoveR_CopyFileW(lastdayfilepath, lastnextfilepath, false);
			if (!bsave1)
			{
				if (!tipsonce)
				{
					tipsonce = true;
					str222.Format(_T("覆盖前天积分文件失败！"));
					//AfxMessageBox(str222);
				}
			}
		}
		bsave1 = ::function::RemoveR_CopyFileW(filepath, lastdayfilepath, false);
		if (!bsave1)
		{
			Sleep(1000);
			bsave1 = ::function::RemoveR_CopyFileW(filepath, lastdayfilepath, false);
			if (!bsave1)
			{
				if (!tipsonce)
				{
					tipsonce = true;
					str222.Format(_T("覆盖昨天积分文件失败！"));
					//AfxMessageBox(str222);
				}
			}
		}
	}
	//DeleteFile(lastfilepath);

	}
}



INT64 GetnumFromTime(const SYSTEMTIME &t1)  
{
	INT64 ddd=ConvertLocalTimeToInt(t1);
	INT64 rtvalue=ddd-basetime;
	

	return rtvalue;
	//TCHAR buff[32]=_T("FF");
	//INT64 ddd=_tcstoi64(buff,0,16);
} 
DWORD GetNowTimeSimplenumFrom()  
{
	
	SYSTEMTIME curSystemTime;
			GetLocalTime(&curSystemTime);
	INT64 ddd=ConvertLocalTimeToInt(curSystemTime);
	DWORD rtvalue=ddd-basetime;
	return rtvalue;
	//TCHAR buff[32]=_T("FF");
	//INT64 ddd=_tcstoi64(buff,0,16);
} 

//
INT64 GetnumFromVect(LPCTSTR vectstr)  
{
	INT64 ddd=_tstoi64(vectstr);
	INT64 rtvalue=ddd;
	if(rtvalue>1300000000)
	rtvalue-=basetime;

		return rtvalue;
} 

INT64 GetWholenumFromVect(LPCTSTR vectstr)  
{
	INT64 ddd=_tstoi64(vectstr);
	INT64 rtvalue=ddd;
	if(rtvalue<1300000000)
	rtvalue+=basetime;

		return rtvalue;
} 
void LookQQRankNumLast(LPCTSTR wstr,INT64& qqnum)
{
  CStringvect temp2vect;
	CString expressstr;
		CString midnumstr=wstr;
	//Chinese2ArabianNum(midnumstr);

	expressstr.Format(_T("\\d{4,20}"));
GetRegEX(midnumstr,expressstr,temp2vect);//need consider of the actual keyname
if(temp2vect.size()==1)
{
	qqnum=_ttoi64(temp2vect[0]);
	
}
if(temp2vect.size()>=2)
{
	qqnum=_ttoi64(temp2vect[1]);
	
}


}

void LookQQRankNum(LPCTSTR wstr,INT64& qqnum)
{
  CStringvect temp2vect;
	CString expressstr;
		CString midnumstr=wstr;
	//Chinese2ArabianNum(midnumstr);

	expressstr.Format(_T("\\d{4,20}"));
GetRegEX(midnumstr,expressstr,temp2vect);//need consider of the actual keyname
if(temp2vect.size()==1)
{
	qqnum=_ttoi64(temp2vect[0]);
	
}
if(temp2vect.size()>=2)
{
	qqnum=_ttoi64(temp2vect[0]);
	
}


}
void AwardNum(LPCTSTR wstr,INT64& qqnum,INT64& score)
{
 // CStringvect temp2vect;
	//CString expressstr;
		CString midnumstr=wstr;
			int cpos=GetposLastChsNum(midnumstr);
	if(cpos!=-1)
	{
	int cpos1=cpos+1;
	int cpos2=cpos+2;
	if((cpos1<midnumstr.GetLength()&&midnumstr.GetAt(cpos1)>='0'&&midnumstr.GetAt(cpos1)<='9')||(cpos2<midnumstr.GetLength()&&midnumstr.GetAt(cpos1)=='-'&&midnumstr.GetAt(cpos2)>='0'&&midnumstr.GetAt(cpos2)<='9'))
	{
	midnumstr.Insert(cpos1,' ');
	}

	}
	Chinese2ArabianNum(midnumstr);
	int result=NoChineseRobNum(midnumstr,qqnum,score);

	if(Isggged)
	score=min(MAXSCORE,score);
	else
	score=min(2000,score);
	
	score=max(1,score);
//	expressstr.Format(_T("\\d+"));
//GetRegEX(midnumstr,expressstr,temp2vect);//need consider of the actual keyname
//if(temp2vect.size()>=2)
//{
//	qqnum=_ttoi64(temp2vect[0]);
//	score=_ttoi64(temp2vect[1]);
//	if(Isggged)
//	score=min(MAXSCORE,score);
//	else
//	score=min(2000,score);
//	
//	score=max(1,score);
//
//}

}

int NoChineseRobNum(LPCTSTR wstr,INT64& qqnum,INT64& score)
{
int result=0;

	int lenss=lstrlen(wstr);
	int i=0;
	//-888888888888888888888888888888888888888
	for(i=0;i<lenss;i++)
	{
	if(wstr[i]>='0'&&wstr[i]<='9')
	{
qqnum=_ttoi64(&wstr[i]);
if(qqnum==INT64_MAX)
{
qqnum=0;
score=0;
return 1;
}
if(i==1&&wstr[i-1]=='-')
{
qqnum=0-qqnum;
}
result=1;
break;
	}

	}


	if(result)
	{
	CString qqstr;

	//qqstr.Format(_T("%lld"),qqnum);
	int qqlen=0;
		for(int n=i;n<lenss;n++)
	{
	if(wstr[n]>='0'&&wstr[n]<='9')
	{
qqlen++;
	}
	else
		break;
		}

	qqstr=wstr+i+qqlen;//lstrlen(qqstr);
	lenss=lstrlen(qqstr);
	for(i=0;i<lenss;i++)
	{
	if(qqstr[i]>='0'&&qqstr[i]<='9')
	{
score=_ttoi64(qqstr.GetBuffer(0)+i);
if(i>0&&qqstr[i-1]=='-')
score=0-score;

result=2;
break;
	}
	}
	}
return result;
	//Chinese2ArabianNum(midnumstr);
	//打劫123456 45678
//int result=0;
//		
//  CStringvect temp2vect;
//	CString expressstr;
//	CString midnumstr=wstr;
//	expressstr.Format(_T("\\d+"));
//GetRegEX(midnumstr,expressstr,temp2vect);//need consider of the actual keyname
//if(temp2vect.size()>0)
//{
//	qqnum=_ttoi64(temp2vect[0]);
//	result=1;
//	if(temp2vect.size()>1)
//	{
//	score=_ttoi64(temp2vect[1]);
//	result=2;
//	}
//}
//return result;
}
int RobNum(LPCTSTR wstr,INT64& qqnum,INT64& score)
{
	int result=0;
	CString midnumstr=wstr;

	int cpos=GetposLastChsNum(midnumstr);
	if(cpos!=-1)
	{
	int cpos1=cpos+1;
	int cpos2=cpos+2;
	if((cpos1<midnumstr.GetLength()&&midnumstr.GetAt(cpos1)>='0'&&midnumstr.GetAt(cpos1)<='9')||(cpos2<midnumstr.GetLength()&&midnumstr.GetAt(cpos1)=='-'&&midnumstr.GetAt(cpos2)>='0'&&midnumstr.GetAt(cpos2)<='9'))
	{
	midnumstr.Insert(cpos1,' ');
	}

	}
Chinese2ArabianNum(midnumstr);//押二四300

	result=NoChineseRobNum(midnumstr,qqnum,score);

		if(qqnum==INT64_MAX)
			qqnum=0;
	if(score==INT64_MAX)
			score=0;

	
		if(qqnum==-9223372036854775807L)
			qqnum=0;
	if(score==-9223372036854775807L)
			score=0;


//
//  CStringvect temp2vect;
//	CString expressstr;
//	CString midnumstr=wstr;
//	Chinese2ArabianNum(midnumstr);
//
//	expressstr.Format(_T("\\d+"));
//GetRegEX(midnumstr,expressstr,temp2vect);//need consider of the actual keyname
//if(temp2vect.size()>0)
//{
//	qqnum=_ttoi64(temp2vect[0]);
//	result=1;
//	if(temp2vect.size()>1)
//	{
//	score=_ttoi64(temp2vect[1]);
//	result=2;
//	}
//}
return result;
}

BOOL ExstractOneNum(LPCTSTR wstr,INT64 &qqnum)//,BOOL bLast
{
	int result=0;
	int lenss=lstrlen(wstr);
	int i=0;
	for(i=0;i<lenss;i++)
	{
	if(wstr[i]>='0'&&wstr[i]<='9')
	{
qqnum=_ttoi64(&wstr[i]);
result=1;
break;
	}

	}

return result;
}


void GambleNum(LPCTSTR wstr,INT64& selfnum,int& scalenum)
{
  CStringvect temp3vect;
	CString expressstr;
	
	CString midnumstr=wstr;
	Chinese2ArabianNum(midnumstr);

	expressstr.Format(_T("\\d+"));
GetRegEX(midnumstr,expressstr,temp3vect);//need consider of the actual keyname
if(temp3vect.size()==4)
{
	selfnum=_ttoi64(temp3vect[3]);
	scalenum=_ttoi64(temp3vect[1]);
}
else if(temp3vect.size()==6)
{
	selfnum=_ttoi64(temp3vect[5]);
	scalenum=_ttoi64(temp3vect[4]);
}
else if(temp3vect.size()==5)
{
		scalenum=_ttoi64(temp3vect[4]);
}
else if(temp3vect.size()==3)
{
	selfnum=_ttoi64(temp3vect[2]);
	scalenum=_ttoi64(temp3vect[1]);
}
else if(temp3vect.size()==2)
{
	//selfnum=_ttoi64(temp3vect[2]);
	scalenum=_ttoi64(temp3vect[1]);
}
else if(temp3vect.size()==1)
{
	selfnum=_ttoi64(temp3vect[0]);
	
}



}
void RankNum(LPCTSTR wstr,int& numcount,BOOL& bFirst)
{

  CStringvect tempbackstr;
	CString expressstr;
	CString midnumstr=wstr;
	Chinese2ArabianNum(midnumstr);

	expressstr.Format(_T("\\d+"));
GetRegEX(midnumstr,expressstr,tempbackstr);//need consider of the actual keyname
if(tempbackstr.size())
{
	numcount=_ttoi(tempbackstr[0]);

}
if(StrStr(wstr,_T("后")))
{
bFirst=false;
}

}



BOOL SimsimiResponse(const CString& trimusermsg,LPTSTR responsemsg)
{
	if(1)//!g_smarttipsforsong)
	return 0;
	CString tempstr=_T("#")+trimusermsg;
	BOOL bSmart=IsSamrtKeyWord(tempstr);
	if(bSmart)
		return 0;

	CString realhostname;
CString processpath;
realhostname=_T("www.simsimi.com");

processpath.Format(_T("/talk.htm"));
	UINT ddlen=0;
	char *bufbyte=new char[1024*200];
		CStringA msgA;
		
	::function::wchrto_utf8(trimusermsg,msgA);
	int ddd=msgA.GetLength();
		strcpy(bufbyte,(CStringA)msgA);
		int ddd3=strlen(bufbyte);
	::function::urlencode(bufbyte);
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)bufbyte;
	

processpath.Format(_T("/func/req?msg=%s&lc=ch&ft=0.0"),tbufv);
	

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
//				strHeaders.Format(_T("Accept: */*\r\nReferer: http://%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"),realhostname);
				
				//strHeaders.Format(_T("Accept: */*\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\n"));
				strHeaders.Format(_T("Accept: */*\r\nX-Requested-With: XMLHttpRequest\r\nReferer: http://%s\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)\r\nCookie: sagree=true; selected_nc=zh; JSESSIONID=C035955D3B33F375A6D9896C820158F0; AWSELB=15E16D030EBAAAB8ACF4BD9BB7E0CA8FB501388662640BCEC6E9C54E70B150AA8514D30E844A0F6781F3C00BEC43069730243F418119D4A1660F073D105DD873991975B881\r\n"),_T("www.simsimi.com/talk.htm"));
				

				//strHeaders.Format(_T("Accept: application/json, text/javascript, */*; q=0.01\r\nX-Requested-With: XMLHttpRequest\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko)Chrome/27.0.1453.116 Safari/537.36\r\nContent-Type: application/json; charset=utf-8\r\nReferer: http://www.simsimi.com/talk.htm\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\nCookie: sagree=true; selected_nc=zh; JSESSIONID=C035955D3B33F375A6D9896C820158F0; AWSELB=15E16D030EBAAAB8ACF4BD9BB7E0CA8FB501388662640BCEC6E9C54E70B150AA8514D30E844A0F6781F3C00BEC43069730243F418119D4A1660F073D105DD873991975B881\r\nConnection: keep-alive\r\n"));
			
				//strcpy(pattachm,"replycampus=0&content=测试留言！&uin=35376062&ouin=13402429&g_tk=1662176677");
				//ddlen=strlen(pattachm);
				rgfilename=_T("login.html");
				rtflag=Send2web(pConnection,strHeaders,processpath,NULL,ddlen,(byte*)bufbyte,NULL,rgfilename,NULL,NULL,true);

		delete pConnection;

				delete p_session;
				
CString wstr;
	::function::utf8_wchar((char*)bufbyte,wstr);

delete []bufbyte;
CStringvect weather6vect;
	CString expressstr;
	
	expressstr.Format(_T("(?<=\"response\":\").+?(?=\")"));
GetRegEX(wstr,expressstr,weather6vect);//need consider of the actual keyname
if(weather6vect.size())
	wstr=weather6vect[0];
else
{
	wstr=_T("");
	rtflag=false;
}
//for(auto it=banwordset.begin();it!=banwordset.end();it++)
//		{
//		if(StrStrI(wstr,*it))
//		{
//			wstr=_T("");
//			rtflag=false;
//		break;
//		}
//
//		}
lstrcpy(responsemsg,wstr);
if(wstr.IsEmpty()||wstr.Find(_T("Please visit again tomorrow"))!=-1||wstr.Find(_T("only can speak"))!=-1||wstr.Find(_T("have no response"))!=-1)
	rtflag=false;

	}
	catch(...)
	{
	CString path=::function::complete_path(_T("MySendWeb_error.txt"));
		catcherror(path,processpath);
	}

				return rtflag;

}
int AjaxsnsResponse(const CString& trimusermsg,LPTSTR responsemsg,LPCTSTR qqnum=NULL,LPCTSTR groupnum=NULL,int iiiiflag=0,LPCTSTR fromwhichquery=NULL)//1=xiaoi,2=bFindOntuling
{
	int rtflag=1;
			CString lastresponsestr;
		
	CString	m_query_mtgox;

	CString expressstr;
	CStringvect getuinbackstr;

	if(trimusermsg.GetLength()>255)
	{
		lstrcpy(responsemsg,_T("你输入的字符数太多！！！！请输入#天气南昌、#笑话、#你想聊的话题（注意这是网络词库，很贱很暴力，勿跟机器人对骂。）、#18970900000、#翻译I love you、#歌词北京欢迎你、#计算3加2乘8、192.10.1.1！"));
		return false;
	}
		if(trimusermsg==_T("藏头诗"))
	{
		lstrcpy(responsemsg,_T("请输入“#藏头诗 天下无敌”之类的格式！"));
		return true;
	}
		
		CString finaltrimusermsg=trimusermsg;
if(_tcsncmp(finaltrimusermsg,_T("归属"),lstrlen(_T("归属")))==0)
{
	int ttnum=_ttoi64(finaltrimusermsg.GetBuffer(0)+lstrlen(_T("归属")));
	if(ttnum>1000000&&ttnum<10000000)//1387090
	{
	finaltrimusermsg+=_T("0000");
	}

}

	UINT ddlen=0;
	char *bufvalue=new char[1024*20];
	GlobalOmitwardword(finaltrimusermsg,1,false);
	CStringA msgA;
	::function::wchrto_utf8(finaltrimusermsg,msgA);
	int ddd=msgA.GetLength();
		strcpy(bufvalue,(CStringA)msgA);
		int ddd3=strlen(bufvalue);
	::function::urlencode(bufvalue);
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)bufvalue;

	CString appendqqnum;

	if(qqnum)
	appendqqnum.Format(_T("&cfrobotqqnum=%s"),qqnum);

		tbufv+=appendqqnum;

	if(groupnum)
	{
		INT64 realqqgroupnum=_ttoi64(groupnum);
	INT64 realqqnum=_ttoi64(qqnum);
	CString closenickname;
	GetNickNameFromGroupMap(realqqgroupnum,realqqnum,closenickname);
	
	CStringA msgA;
	::function::wchrto_utf8(closenickname,msgA);
	int ddd=msgA.GetLength();
		strcpy(bufvalue,(CStringA)msgA);
		int ddd3=strlen(bufvalue);
	::function::urlencode(bufvalue);
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)bufvalue;

			CString facerandfmt;

		RealGroupNumNickNamemap.Lookup(realqqgroupnum,facerandfmt);
		
			::function::wchrto_utf8(facerandfmt,msgA);
	ddd=msgA.GetLength();
		strcpy((char*)bufvalue,(CStringA)msgA);
		ddd3=strlen((char*)bufvalue);
	::function::urlencode((char*)bufvalue);
	
	CString groupnametbufv;//=trimusermsg;
	groupnametbufv=(CString)(CStringA)(char*)bufvalue;
		

	appendqqnum.Format(_T("&cfrobotgroupnum=%s&cfrobotnickname=%s&cfrobotgroupname=%s&cfrobotselfnum=%lld"),groupnum,tbufv,groupnametbufv,ccccflag2-oofffnum);
	
	}
	else
	{
	appendqqnum.Format(_T("&cfrobotselfnum=%lld&version=%s&checksign=%s"),ccccflag2-oofffnum,g_purenumberversion,g_ksidmd5);
	
	}
	tbufv.Replace(_T("cfrobotselfnum"),_T("cfrobotfakeselfnum"));

		tbufv+=appendqqnum;

	delete []bufvalue;
	byte *bytebuf=new byte[200*1024];

	static int ncount_getweb=0;
	if(Isggged&&g_cfxysourceweb.IsEmpty()&&ccccflag2>=g_interfaceuin&&ccccccc>25&&(ncount_getweb==0||ncount_getweb%20==10))
	{
	
		//str222.Format(_T("注册版获取网络词库地址:%s"),robotlink);
		//Write2MagnetLog(str222,&magnetfile,6);

	UINT ddlen=0;
	CStringvect vectemp;

		ddlen=::function::DownloadHttpTxtFile(robotlink,vectemp);
	/*	if(ddlen==0)
		{
		*pggged=0;
		ccccccc=0;

		}*/
		if(ddlen&&(*pggged))
		{

			if(vectemp.size()>0)
			g_cfxysourceweb=vectemp[0];
if(vectemp.size()>1)
			g_cfxysourceweb2=vectemp[1];

	//str222.Format(_T("获取网络词库地址:%s  %s"),g_cfxysourceweb,g_cfxysourceweb2);
		//Write2MagnetLog(str222,&magnetfile,6);

		}

	/*	else
		{
		*pggged=false;
		ccccflag2=0;
		ccccccc=0;
		}
*/
	}

	if(Isggged)
ncount_getweb++;

	if(0)//g_getcheckweb&&(g_cfxysourceweb.IsEmpty()))//)//读取不到就算是未注册版//&&!StrStr(robotlink,_T("www.cfxy.me"))
	{
		Isggged=false;
		ccccccc=1;
		ccccccc--;
	}

BOOL errorflag=1;	
if(Isggged&&!g_cfxysourceweb.IsEmpty()&&ccccflag2>=g_interfaceuin&&ccccccc>25&&g_cfxysourceweb.Find(_T("http://"))!=-1)
{
	if(g_cfxysourceweb.Find(_T("%s"))!=-1)
	m_query_mtgox.Format(g_cfxysourceweb,tbufv);
	else
	m_query_mtgox.Format(_T("%s%s"),g_cfxysourceweb,tbufv);
	ddlen=200*1024;

	if(iiiiflag==0)
	errorflag=::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen);

}

if(errorflag)
{
	if(g_customstr.IsEmpty())
	{
		m_query_mtgox=_T("");
	//m_query_mtgox.Format(_T("http://api.ajaxsns.com/api.php?key=free&appid=0&msg=%s"),tbufv);
	}
//	else
//m_query_mtgox.Format(_T("http://www.xshuju.com/mydict/index.php?key=free&appid=0&msg=%s"),tbufv);
	if(iiiiflag==1)
	{
	CString app_key;
	CString app_secre;
	CString realapp_secret;

	if(!g_App_key_str.IsEmpty())//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("小i机器人app_key"))!=g_outputreplacemap.m_mapstr.end())
{	
	
app_key=g_App_key_str;//g_outputreplacemap[_T("小i机器人app_key")].front();
	}
	else
	app_key=_T("3tQliwzJh3rr");

	if(!g_App_secret_str.IsEmpty())//find(g_outputreplacemap.m_mapstr.begin(),g_outputreplacemap.m_mapstr.end(),_T("小i机器人app_secret"))!=g_outputreplacemap.m_mapstr.end())
{	
	
realapp_secret=g_App_secret_str;//g_outputreplacemap[_T("小i机器人app_secret")].front();
	}
	else
	{
app_secre=_T("fhrbkt3xCjokwc5Qimv");
realapp_secret=app_secre+'n';
	}

CString realm = _T("xiaoi.com");
CString method = _T("POST");
CString uri = _T("/ask.do");

	CSHA1 sha1;
	std::basic_string<TCHAR> strReport1;
	std::basic_string<TCHAR> strReport2;
	std::basic_string<TCHAR> strsignature;
CString nonce;
	TCHAR chars[] = _T("abcdefghijklmnopqrstuvwxyz0123456789");  
	srand(time(NULL));
for ( int i = 0; i < 40;i++) 
{

	nonce.AppendChar(chars[rand()%36]); 
}
//nonce=_T("de5d4c23fa5e733df529a848ca261b03c528");
	CString strsha1;
strsha1.Format(_T("%s:%s:%s"),app_key,realm,realapp_secret);
	
	CStringA pszAnsi=(CStringA)strsha1;
	sha1.Update((UINT_8*)pszAnsi.GetBuffer(), strlen(pszAnsi));
	sha1.Final();
	sha1.ReportHashStl(strReport1, CSHA1::REPORT_HEX_SHORT);
		sha1.Reset();

		strsha1.Format(_T("%s:%s"),method,uri);
pszAnsi=(CStringA)strsha1;
sha1.Update((UINT_8*)pszAnsi.GetBuffer(), strlen(pszAnsi));
	sha1.Final();
	sha1.ReportHashStl(strReport2, CSHA1::REPORT_HEX_SHORT);
		sha1.Reset();

		std::transform(strReport1.begin(), strReport1.end(), strReport1.begin(), ::towlower);
		std::transform(strReport2.begin(), strReport2.end(), strReport2.begin(), ::towlower);
		
strsha1.Format(_T("%s:%s:%s"),strReport1.c_str(),nonce,strReport2.c_str());
pszAnsi=(CStringA)strsha1;
sha1.Update((UINT_8*)pszAnsi.GetBuffer(), strlen(pszAnsi));
	sha1.Final();
	sha1.ReportHashStl(strsignature, CSHA1::REPORT_HEX_SHORT);
		sha1.Reset();

std::transform(strsignature.begin(), strsignature.end(), strsignature.begin(), ::towlower);
	
CString strfmt;
	strfmt.Format(_T("platform=custom&userId=%s&type=0&question=%s"),qqnum,tbufv);
	//strfmt.Format(_T("question=nihao&platform=custom&userId=%s&type=0"),qqnum);

	//char bufeee[5024];//&app_key=%s&nonce=%s&signature=%s  app_key,nonce,strsignature.c_str(),
	//UINT ddlen;
	strcpy((char*)bytebuf,(CStringA)strfmt);
	CString realhostname=_T("nlp.xiaoi.com");
	CString processpath=_T("/ask.do");
	UINT ddlen=strlen((char*)bytebuf);
//MessageBoxA(0,(char*)bufeee,0,0);
	CString additionalhead;

	additionalhead.Format(_T("X-Auth:app_key=\"%s\",nonce=\"%s\",signature=\"%s\"\r\n"),app_key,nonce,strsignature.c_str());
rtflag=MySendWeb(realhostname,processpath,(byte*)bytebuf,(char*)bytebuf,ddlen,0,additionalhead);
if(rtflag)
	errorflag=0;
	}
	else if(iiiiflag==2)
	{
		m_query_mtgox.Format(_T("http://www.tuling123.com/openapi/api?key=5bfc5345cb0807ab03b82153cc41093%d&info=%s"),9,tbufv);
	ddlen=200*1024;
	if(!m_query_mtgox.IsEmpty())
	errorflag=::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen);
	
	}
	//ddlen=200*1024;
	//if(!m_query_mtgox.IsEmpty())
	//errorflag=::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen);
}
BOOL bContentexist=false;
if(!errorflag)
{
CStringvect weather6vect;
	CString wstr;
	::function::utf8_wchar((char*)bytebuf,wstr);

	
	expressstr.Format(_T("(?<=\"content\":\").*?(?=\")"));
GetRegEX(wstr,expressstr,weather6vect,0,true);//need consider of the actual keyname
if(weather6vect.size()&&!weather6vect[0].IsEmpty())
bContentexist=true;
}

if(errorflag||!bContentexist)
{
//if(Isggged&&!g_cfxysourceweb2.IsEmpty()&&ccccflag2>=g_interfaceuin&&ccccccc>25&&g_cfxysourceweb2.Find(_T("http://"))!=-1)
//{
//	if(g_cfxysourceweb2.Find(_T("%s"))!=-1)
//	m_query_mtgox.Format(g_cfxysourceweb2,tbufv);
//	else
//	m_query_mtgox.Format(_T("%s%s"),g_cfxysourceweb2,tbufv);
//	ddlen=200*1024;
//	errorflag=::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen);
//
//}
//	
	//2015.10.20去掉再次查询
}
//{"result":0,"content":""}

if(!errorflag)
	{
	//str+=(char*)bytebuf;
	
	CStringvect weather6vect;
	CString wstr;
	::function::utf8_wchar((char*)bytebuf,wstr);
	wstr.Trim();
	
		

		GetWebReturnContent(wstr,weather6vect);


		if(weather6vect.size()>0)
		{
			lastresponsestr=weather6vect[0];

			lastresponsestr.Replace(_T("&quot;"),_T("“"));
			lastresponsestr.Replace(_T("&nbsp;"),_T(" "));
			lastresponsestr.Replace(_T("&lt;p&gt;"), _T(" "));
			lastresponsestr.Replace(_T("&lt;/p&gt;"), _T(" "));
			lastresponsestr.Replace(_T("{br}"),_T("\r\n"));
			lastresponsestr.Replace(_T("</br>"),_T("\r\n"));
			lastresponsestr.Replace(_T("<br>"),_T("\r\n"));
			lastresponsestr.Replace(_T("<br />"),_T("\r\n"));
			lastresponsestr.Replace(_T("\t"),_T("   "));
			lastresponsestr.Replace(_T("提示：按分类看笑话请发送“笑话分类”"),_T(""));
			lastresponsestr.Replace(_T("加减乘除符号为 + - * /，获取详细说明请发送：计算"),_T(""));
			lastresponsestr.Replace(_T("菲菲"),_T("机器人"));
			lastresponsestr.Replace(_T("签你妹出去遛"),_T("要签到请在群里发“签到”二字，别私聊"));
			lastresponsestr.Replace(_T("mzxing.com"),_T("qqshow123.com"));
			lastresponsestr.Replace(_T("u3j.net/mzxing"),_T("www.qqshow123.com"));
			lastresponsestr.Replace(_T("梅州行"),_T("晨风软件"));
			lastresponsestr.Replace(_T("梅州"),_T("晨风"));
			lastresponsestr.Replace(_T("小i机器人"),_T("晨风机器人"));
			lastresponsestr.Replace(_T("小I机器人"),_T("晨风机器人"));
			lastresponsestr.Replace(_T("图灵机器人"),_T("晨风机器人"));

			lastresponsestr.Replace(_T("face:"),_T("face"));
			lastresponsestr.Replace(_T("face:"),_T("face"));

			
			if(_tcscmp(trimusermsg,lastresponsestr)==0)
			{
			
				lastresponsestr+=_T("——问题和答复完全一致");
			}
			else
			if(_tcsncmp(trimusermsg,lastresponsestr,25)==0)
			{
			
				lastresponsestr+=_T("——问题和答复基本一致");
			}


			if(fromwhichquery&&lstrlen(fromwhichquery))
			{

				lastresponsestr+=fromwhichquery;
			}
			else
			{
				if(iiiiflag==2)
					lastresponsestr+=_T("——来自图灵词库");
				else if(iiiiflag==1)
					lastresponsestr+=_T("——来自小i词库");
					else if(iiiiflag==0)
					lastresponsestr+=_T("——来自网络词库");

			}

			if(lastresponsestr==_T("你说的什么哦？换种说法行不")||lastresponsestr==_T("宝贝，你说的话好深奥啊，有点像哥德巴赫猜想，暂时无解！"))
			{
				lastresponsestr=_T("");
				rtflag=0;
			}
			else
				rtflag=2;

		}
else
{
lastresponsestr=_T("");
rtflag=0;
}
	
}
else
{
lastresponsestr=_T("");
rtflag=false;
}
	if(rtflag==false)
	{
	//http://www.simsimi.com/talk.htm?lc=ch
	}
	/*	for(auto it=banwordset.begin();it!=banwordset.end();it++)
		{
		if(StrStrI(lastresponsestr,*it))
		{
			lastresponsestr=_T("");
			rtflag=false;
		break;
		}

		}
*/
	delete []bytebuf;
	
	

		
		lstrcpy(responsemsg,lastresponsestr);
			return rtflag;
			
}
BOOL IsforeAdditionalQuery(const CString& trimusermsg,CString* querystr)
{
	CString newstr=trimusermsg;
	newstr.TrimLeft(_T("#"));
	int nlen=lstrlen(g_additionalprewords);
	if(nlen&&_tcsncmp(newstr,g_additionalprewords,nlen)==0)
	{
	
	if(querystr)
		*querystr=newstr.Mid(nlen);
	return true;
	}

	return false;
}
BOOL IsforecastWeather(const CString& trimusermsg,CString* cityname)
{
	CString newstr=trimusermsg;
	newstr.TrimLeft(_T("#"));

	CString expressstr;
	CStringvect getuinbackstr;
	CString citystr;
		expressstr.Format(_T(".+(?=天气$)"));
GetRegEX(newstr,expressstr,getuinbackstr);//need consider of the actual keyname
if(getuinbackstr.size())
{
citystr=getuinbackstr[0];
		citystr.Trim();
}
if(citystr.IsEmpty())
{
if(_tcsnicmp(newstr,_T("天气"),lstrlen(_T("天气")))==0)
	{
		
		citystr=trimusermsg.Mid(lstrlen(_T("天气")));
		citystr.Trim();
}
}
if(g_cityidmap.GetCount()==0)
	{
	InitCityMap();

	}
BOOL findcityflag=false;
for(auto it=g_cityidmap.m_mapstr.begin();it!=g_cityidmap.m_mapstr.end();it++)
{
if(*it==citystr)
{
findcityflag=true;
break;
}
}
if(findcityflag)
{
if(cityname)
{

GlobalOmitwardword(citystr,1,false);
	*cityname=citystr;
}
return true;
}
else
	return false;
}
BOOL IsQQvisit(const CString& trimusermsg,CString* qqnumber)
{
	CString newstr=trimusermsg;
	newstr.TrimLeft(_T("#"));
	int nlen=lstrlen(_T("人气"));
	if(_tcscmp(newstr,_T("人气"))==0)
	{
		if(qqnumber)
{
	*qqnumber=_T("");

}
		return true;
	}
	if(_tcsncmp(newstr,_T("人气"),nlen)==0)
	{
		CString qqnumstr=newstr.Mid(nlen);
		if(_ttoi64(qqnumstr))
		{
if(qqnumber)
{
	*qqnumber=qqnumstr;

}
return true;
		}

	}
	return false;
}

BOOL IsFreeSlave(const CString& trimusermsg,CString* qqnumber)
{
	CString newstr=trimusermsg;
	newstr.TrimLeft(_T("#"));
	TCHAR   keyword[32]=_T("解放");
	int nlen=lstrlen(keyword);
	if(_tcsncmp(newstr,keyword,nlen)==0)
	{
		CString qqnumstr=newstr.Mid(nlen);
		if(_ttoi64(qqnumstr))
		{
if(qqnumber)
{
	*qqnumber=qqnumstr;

}
return true;
		}

	}
	return false;
}
BOOL IsBidForSlave(const CString& trimusermsg,INT64* bidscore)
{
	CString newstr=trimusermsg;
	newstr.TrimLeft(_T("#"));

		CString midnumstr=newstr;
	Chinese2ArabianNum(midnumstr);

	TCHAR   keyword[32]=_T("出价");
	int nlen=lstrlen(keyword);
	if(_tcsncmp(midnumstr,keyword,nlen)==0)
	{
		CString qqnumstr=midnumstr.Mid(nlen);
		INT64 ttmpscore=_ttoi64(qqnumstr);
		if(ttmpscore)
		{
if(bidscore)
{
 ttmpscore=max(ttmpscore,100);
 //if(Isggged)
 ttmpscore=min(MAXSCORE,ttmpscore);
 //else
 //ttmpscore=min(2000,ttmpscore);

	*bidscore=ttmpscore;

}
return true;
		}

	}
	return false;
}

BOOL IsQuerySlaves(const CString& trimusermsg,CString* qqnumber,int *myslavenum)
{
	CString newstr=trimusermsg;
	newstr.TrimLeft(_T("#"));

	int nlen=lstrlen(_T("奴隶列表"));
	if(_tcscmp(newstr,_T("奴隶列表"))==0)
	{
		if(qqnumber)
{
	*qqnumber=_T("");

}

		return true;
	}
	if(_tcsncmp(newstr,_T("奴隶列表"),nlen)==0)
	{
		CString qqnumstr=newstr.Mid(nlen);
		INT64 tempqqnum=_ttoi64(qqnumstr);
		if(tempqqnum)
		{
if(tempqqnum>=1000)
{
	if(qqnumber)
	*qqnumber=qqnumstr;

	 CStringvect temp2vect;
	CString expressstr;
		CString midnumstr=qqnumstr;
	Chinese2ArabianNum(midnumstr);

	expressstr.Format(_T("\\d+"));
GetRegEX(midnumstr,expressstr,temp2vect);//need consider of the actual keyname
if(temp2vect.size()>=2)
{
if(myslavenum)
{
	*myslavenum=_ttoi64(temp2vect[1]);
	*myslavenum=max(5,*myslavenum);

}

}
}
else
{
if(myslavenum)
{
	*myslavenum=tempqqnum;
	*myslavenum=max(5,*myslavenum);

}
}

return true;
		}

	}
	return false;
}

int BaiduKnowResponse(const CString& trimusermsg,LPTSTR responsemsg)
{
int rtflag=1;

		

	
	CString	m_query_mtgox;

	CString expressstr;
	CStringvect getuinbackstr;
	
	UINT ddlen=1024*200;
	byte *bytebuf=new byte[ddlen];
	CStringA msgA=(CStringA)trimusermsg;
	::function::wchrto_utf8(trimusermsg,msgA);

	int ddd=msgA.GetLength();
		strcpy((char*)bytebuf,(CStringA)msgA);
		int ddd3=strlen((char*)bytebuf);
	::function::urlencode((char*)bytebuf);
	
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)(char*)bytebuf;

	
//	if(0)
//		m_query_mtgox.Format(_T("http://zhidao.baidu.com/search?lm=0&rn=10&pn=0&fr=search&ie=gbk&word=%s"),tbufv);

m_query_mtgox.Format(_T("https://zhidao.baidu.com/search?lm=0&rn=10&pn=0&fr=search&ie=utf-8&word=%s"),tbufv);


	//m_query_mtgox.Format(_T("http://m.weather.com.cn/data/%s.html"),cityid);
	//meta name="Description" content="基因工程（genetic engineering）又称基因拼接技术和DNA重组技术，是以分子遗传学为理论基础，以分子生物学和微生物学的现代方法为手段，将不同来源的基因按预先设计的蓝图，在体外构建杂种DNA分子，然后导入活细胞，以改变生物原有的遗传特性、获得新品种、生产新产品。基因工程技术为基因的结构..." /><
	if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
	{
		
//	CFile file1;
//	CString pathname;
//
//
//pathname.Format(_T("baiduknow(%s).txt"),trimusermsg);
//	if(file1.Open(::function::complete_path(pathname),CFile::modeCreate|CFile::modeWrite))
//	{
//
//	file1.Write(bytebuf,ddlen);
//	file1.Close();
//	}

		//str+=(char*)bytebuf;
	CStringvect temp6vect;
	CStringvect weather6vect;
	CStringA Astr;
	CString newwstr;
	//if(strstr((char*)bytebuf,"charset=gbk"))
	//{
	//	Astr=(char*)bytebuf;
	//}
	//else
	//::function::utf8_char((char*)bytebuf,Astr);

	CString Wstr;
	//::function::utf8_wchar((char*)bytebuf,Wstr);
	Wstr=::function::CStrA2CStrW((char*)bytebuf);
	//MessageBoxA(mainhwnd,Astr,0,0);
	
	//MessageBox(mainhwnd,Wstr,0,0);

	//MessageBox(mainhwnd,(LPCTSTR)(char*)bytebuf,0,0);

	if(StrStr(Wstr.GetBuffer(0),_T("推荐答案")))
	{
		expressstr.Format(_T("(?<=推荐答案<i class=\"i-right-arrow\"></i></span>).+?(?=<a href=)"));


		rtflag=2;
	}
	else if(!StrStr(Wstr.GetBuffer(0),_T("zhidao.baidu.com/business"))&&StrStr(Wstr.GetBuffer(0),_T("div class=\"desc\"")))
	{
		expressstr.Format(_T("(?<=<div class=\"desc\">).+?(?=</p>)"));

		rtflag=2;
	
	}
	else if(StrStr(Wstr.GetBuffer(0),_T("con-short")))
	{
		expressstr.Format(_T("(?<=<div class=\"con-short\">).+?(?=<(a href=)|(</div>))"));

		rtflag=2;
	
	}
	else
expressstr.Format(_T("(?<=答：</i>).+?(?=</dd>)"));


	GetRegEX(Wstr.GetBuffer(0),expressstr,temp6vect);//need consider of the actual keyname

	if(temp6vect.size()>0)
{
	newwstr=temp6vect[0];
	newwstr.Replace(_T("<br>"),_T("\r\n"));
	newwstr.Replace(_T("<br />"),_T("\r\n"));
	newwstr.Replace(_T("</em>"),_T(""));
	newwstr.Replace(_T("<em>"),_T(""));
	newwstr.Replace(_T("<p>"),_T(""));
	newwstr.Replace(_T("</p>"),_T(""));

newwstr.Trim();
}
	delete []bytebuf;
	
		
		if(newwstr.IsEmpty())
			return false;
		else
		{
			
newwstr+=_T("——来自百度知道");

		lstrcpy(responsemsg,newwstr);
			return rtflag;
	
		}
	}
	else
	{
	lstrcpy(responsemsg,_T("百度知道服务器暂时不可用，请稍候再试！"));
			return 1;
	}
	return rtflag;
}

BOOL BaikeResponse(const CString& trimusermsg,LPTSTR responsemsg)
{
BOOL rtflag=true;

		

	
	CString	m_query_mtgox;

	CString expressstr;
	CStringvect getuinbackstr;
	
	UINT ddlen=1024*200;
	byte *bytebuf=new byte[ddlen];
	CStringA msgA;
	::function::wchrto_utf8(trimusermsg,msgA);
	int ddd=msgA.GetLength();
		strcpy((char*)bytebuf,(CStringA)msgA);
		int ddd3=strlen((char*)bytebuf);
	::function::urlencode((char*)bytebuf);
	
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)(char*)bytebuf;

	m_query_mtgox.Format(_T("https://baike.baidu.com/search/word?word=%s&pic=1&sug=1&enc=utf8&oq=%s"),tbufv,tbufv);
	//m_query_mtgox.Format(_T("http://m.weather.com.cn/data/%s.html"),cityid);
	//meta name="Description" content="基因工程（genetic engineering）又称基因拼接技术和DNA重组技术，是以分子遗传学为理论基础，以分子生物学和微生物学的现代方法为手段，将不同来源的基因按预先设计的蓝图，在体外构建杂种DNA分子，然后导入活细胞，以改变生物原有的遗传特性、获得新品种、生产新产品。基因工程技术为基因的结构..." /><
	if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
	{
	//str+=(char*)bytebuf;
	CStringvect temp6vect;
	CStringvect weather6vect;
	CString wstr;
	::function::utf8_wchar((char*)bytebuf,wstr);

		expressstr.Format(_T("(?<=meta name=\"Description\" content=\").+?(?=\")"));
GetRegEX(wstr,expressstr,temp6vect);//need consider of the actual keyname

CString newwstr;
if(temp6vect.size()>0)
{
	newwstr=temp6vect[0];
}

	delete []bytebuf;
	
		
		if(newwstr.IsEmpty())
			return false;
		else
		{
			newwstr+=_T("——来自百度百科");
		lstrcpy(responsemsg,newwstr);
			return true;
	
		}
	}
	else
	{
	lstrcpy(responsemsg,_T("百度百科服务器暂时不可用，请稍候再试！"));
			return true;
	}
	return rtflag;
}

BOOL WeatherResponse(const CString& trimusermsg,LPTSTR responsemsg)
{
BOOL rtflag=true;
	if(g_cityidmap.GetCount()==0)
	{
	InitCityMap();
	}
	if(g_cityidmap.GetCount()==0)
	{
		
		lstrcpy(responsemsg,_T("无法读取各城市代号！"));
		return false;
	}
	CString lastresponsestr;
		
		
			CString cityid;
		static CString lastcitystr;
		static CString lastcityweatherstr;
		
	if(trimusermsg.IsEmpty())
	{
		lstrcpy(responsemsg,_T("请输入#天气 城市名 的格式来查询！"));
		return true;
	}
	if(lastcitystr==trimusermsg)
		{
		if(!lastcityweatherstr.IsEmpty())
		{
			
		lstrcpy(responsemsg,lastcityweatherstr);
			return true;
		}

		}


		if(!g_cityidmap.Lookup(trimusermsg,cityid))
	{
		CString ftmerror;
		ftmerror.Format(_T("城市名称不正确或不是中国的城市，无法查询天气！目前数据库中有%d条城市记录！"),g_cityidmap.GetCount());
		lstrcpy(responsemsg,ftmerror);
		return true;
	}
	
		

		lastcitystr=trimusermsg;


	
	CString	m_query_mtgox;

	CString expressstr;
	CStringvect getuinbackstr;
	
	UINT ddlen=1024*200;
	byte *bytebuf=new byte[ddlen];
	m_query_mtgox.Format(_T("http://www.weather.com.cn/weather/%s.shtml"),cityid);
	//m_query_mtgox.Format(_T("http://m.weather.com.cn/data/%s.html"),cityid);
	
	if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
	{
	//str+=(char*)bytebuf;
	CStringvect temperature6vect;
	CStringvect weather6vect;
	CStringvect temp6vect;
CStringvect temp6vect1,temp6vect2,tempweathvect;

	CString wstr,newtempstr;

	::function::utf8_wchar((char*)bytebuf,wstr);

	expressstr.Format(_T("(?<=）<\\/h1>).+?(?=<\\/li>)"));
GetRegEX(wstr,expressstr,temp6vect);//need consider of the actual keyname

for(int i=0;i<temp6vect.size();i++)
{
expressstr.Format(_T("(?<=tem\">\\n<span>).*?(?=<\\/span>)"));//expressstr.Format(_T("(?<=tem tem1\">\\n<span>).*?(?=<\\/span>)"));
GetRegEX(temp6vect[i],expressstr,temp6vect2,0,true);//need consider of the actual keyname

if(!temp6vect2.size())
{

expressstr.Format(_T("(?<=tem\">\\n<i>).*?(?=<\\/i>)"));//expressstr.Format(_T("(?<=tem tem2\">\\n<span>).*?(?=<\\/span>)"));
GetRegEX(temp6vect[i],expressstr,temp6vect1,0,true);//need consider of the actual keyname
temp6vect2.push_back(_T(""));
}
else
{
expressstr.Format(_T("(?<=<\\/span>\\/<i>).*?(?=<\\/i>)"));//expressstr.Format(_T("(?<=tem tem2\">\\n<span>).*?(?=<\\/span>)"));
GetRegEX(temp6vect[i],expressstr,temp6vect1,0,true);//need consider of the actual keyname
if(!temp6vect1.size())
{
expressstr.Format(_T("(?<=<\\/span>\\/\\n<i>).*?(?=<\\/i>)"));//expressstr.Format(_T("(?<=tem tem2\">\\n<span>).*?(?=<\\/span>)"));
GetRegEX(temp6vect[i],expressstr,temp6vect1,0,true);//need consider of the actual keyname

}
}
//expressstr.Format(_T("(?<=>)\\w+?(?=<\\/p>)"));
//GetRegEX(temp6vect[i],expressstr,tempweathvect);//need consider of the actual keyname
expressstr.Format(_T("(?<=class=\"wea\">).+?(?=<\\/p>)"));
GetRegEX(temp6vect[i],expressstr,tempweathvect);//need consider of the actual keyname
if(!tempweathvect.size())
{
expressstr.Format(_T("(?<=class=\"wea\" title=\").+?(?=\">)"));
GetRegEX(temp6vect[i],expressstr,tempweathvect);//need consider of the actual keyname

}
if(temp6vect2.size()&&temp6vect1.size()&&tempweathvect.size())
{
	if(temp6vect2[0].IsEmpty())
newtempstr.Format(_T("%s"),temp6vect1[0]);
	else if(temp6vect1[0].IsEmpty())
	newtempstr.Format(_T("%s"),temp6vect2[0]);
	else
newtempstr.Format(_T("%s~%s"),temp6vect1[0],temp6vect2[0]);
	temperature6vect.push_back(newtempstr);

	weather6vect.push_back(tempweathvect[0]);
}
}







if(temperature6vect.size()>2&&weather6vect.size()>2)
{
	//getuinbackstr[4]=getuinbackstr[4].Left();
	lastresponsestr.Format(_T("未来三天%s天气\r\n今天：%s %s \r\n明天：%s %s \r\n后天：%s %s "),trimusermsg,weather6vect[0],temperature6vect[0],weather6vect[1],temperature6vect[1],weather6vect[2],temperature6vect[2]);//,getuinbackstr[4] 总交易量:%s
	lastcityweatherstr=lastresponsestr;
}
else if(temperature6vect.size()>1&&weather6vect.size()>1)
{
	//getuinbackstr[4]=getuinbackstr[4].Left();
	lastresponsestr.Format(_T("未来两天%s天气\r\n今天：%s %s \r\n明天：%s %s "),trimusermsg,weather6vect[0],temperature6vect[0],weather6vect[1],temperature6vect[1]);//,getuinbackstr[4] 总交易量:%s
	lastcityweatherstr=lastresponsestr;
}
else if(temperature6vect.size()>0&&weather6vect.size()>0)
{
	//getuinbackstr[4]=getuinbackstr[4].Left();
	lastresponsestr.Format(_T("%s天气：%s %s "),trimusermsg,weather6vect[0],temperature6vect[0]);//,getuinbackstr[4] 总交易量:%s
	lastcityweatherstr=lastresponsestr;
}
else
{
lastresponsestr=_T("可能由于天气数据查询的服务器问题，返回的数据错误，无法查询！");
lastcityweatherstr=_T("");

CString tempcitystr=trimusermsg+_T("天气");
rtflag=AjaxsnsResponse(tempcitystr,responsemsg,NULL);
if(rtflag)
{
lastresponsestr=responsemsg;
}
rtflag=true;
	
}
	}
	else
{
	lastcityweatherstr=_T("");
lastresponsestr=_T("提供天气数据查询的服务器无法访问！");
CString tempcitystr=trimusermsg+_T("天气");
//rtflag=AjaxsnsResponse(tempcitystr,responsemsg,NULL);
//if(rtflag)
//{
//lastresponsestr=responsemsg;
//}
rtflag=true;
}
	delete []bytebuf;
	
		
			lastresponsestr+=_T("【换行】天气查询完毕");

		lstrcpy(responsemsg,lastresponsestr);
			return rtflag;
	
//	
//
//	CString	m_query_mtgox;
//
//	CString expressstr;
//	CStringvect getuinbackstr;
//	
//	UINT ddlen=0;
//	byte *bytebuf=new byte[1024*50];
//	m_query_mtgox.Format(_T("http://m.weather.com.cn/data/%s.html"),cityid);
//
//	if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
//	{
//	//str+=(char*)bytebuf;
//	CStringvect temp6vect;
//	CStringvect weather6vect;
//	CString wstr;
//	::function::utf8_wchar((char*)bytebuf,wstr);
//
//	expressstr.Format(_T("(?<=\"temp\\d\":\").+?(?=\")"));
//GetRegEX(wstr,expressstr,temp6vect);//need consider of the actual keyname
//
//	expressstr.Format(_T("(?<=\"weather\\d\":\").+?(?=\")"));
//GetRegEX(wstr,expressstr,weather6vect);//need consider of the actual keyname
//
//
//
//if(temp6vect.size()>2&&weather6vect.size()>2)
//{
//	//getuinbackstr[4]=getuinbackstr[4].Left();
//	lastresponsestr.Format(_T("未来三天%s天气\r\n今天：%s %s \r\n明天：%s %s \r\n后天：%s %s "),trimusermsg,weather6vect[0],temp6vect[0],weather6vect[1],temp6vect[1],weather6vect[2],temp6vect[2]);//,getuinbackstr[4] 总交易量:%s
//}
//else
//{
//lastresponsestr=_T("可能由于天气数据查询的服务器问题，返回的数据错误，无法查询！");
//
//	rtflag=true;
//}
//	}
//	else
//{
//lastresponsestr=_T("提供天气数据查询的服务器无法访问！");
//CString tempcitystr=trimusermsg+_T("天气");
//rtflag=AjaxsnsResponse(tempcitystr,responsemsg,NULL);
//if(rtflag)
//lastresponsestr=responsemsg;
//
//rtflag=true;
//}
//	delete []bytebuf;
//	
//		
//		
//		lstrcpy(responsemsg,lastresponsestr);
//			return rtflag;
//		

}
BOOL OwnSourceResponse(const CString& trimusermsg,LPTSTR responsemsg,LPCTSTR qqnum,LPCTSTR groupnum,const CString& sourceweburl)
{
BOOL rtflag=false;
	

	CString	m_query_mtgox;

	CString expressstr;
	CStringvect getuinbackstr;
UINT ddlen=1024*200;
	byte *bytebuf=new byte[ddlen];
	CString finaltrimusermsg=trimusermsg;
	GlobalOmitwardword(finaltrimusermsg,1,false);
	CStringA msgA;
	::function::wchrto_utf8(finaltrimusermsg,msgA);
	int ddd=msgA.GetLength();
		strcpy((char*)bytebuf,(CStringA)msgA);
		int ddd3=strlen((char*)bytebuf);
	::function::urlencode((char*)bytebuf);
	
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)(char*)bytebuf;

	CString appendqqnum22;
	CString appendqqnum;
	if(qqnum)
	{
		if(StrStr(sourceweburl,_T("?")))
	appendqqnum.Format(_T("&cfrobotqqnum=%s"),qqnum);
		else
	appendqqnum.Format(_T("?cfrobotqqnum=%s"),qqnum);
	}
		appendqqnum22+=appendqqnum;

	if(groupnum)
	{
	
	INT64 realqqgroupnum=_ttoi64(groupnum);
	INT64 realqqnum=_ttoi64(qqnum);
	CString closenickname;
	GetNickNameFromGroupMap(realqqgroupnum,realqqnum,closenickname);
	CStringA msgA;
	::function::wchrto_utf8(closenickname,msgA);
	int ddd=msgA.GetLength();
		strcpy((char*)bytebuf,(CStringA)msgA);
		int ddd3=strlen((char*)bytebuf);
	::function::urlencode((char*)bytebuf);
	
	CString tbufv;//=trimusermsg;
	tbufv=(CString)(CStringA)(char*)bytebuf;

		CString facerandfmt;

			RealGroupNumNickNamemap.Lookup(realqqgroupnum,facerandfmt);
		
			::function::wchrto_utf8(facerandfmt,msgA);
	ddd=msgA.GetLength();
		strcpy((char*)bytebuf,(CStringA)msgA);
		ddd3=strlen((char*)bytebuf);
	::function::urlencode((char*)bytebuf);
	
	CString groupnametbufv;//=trimusermsg;
	groupnametbufv=(CString)(CStringA)(char*)bytebuf;

	appendqqnum.Format(_T("&cfrobotgroupnum=%s&cfrobotnickname=%s&cfrobotgroupname=%s&cfrobotselfnum=%lld&version=%s&checksign=%s"),groupnum,tbufv,groupnametbufv,ccccflag2-oofffnum,g_purenumberversion,g_ksidmd5);
	
	}
	else
	{
	appendqqnum.Format(_T("&cfrobotselfnum=%lld&version=%s&checksign=%s"),ccccflag2-oofffnum,g_purenumberversion,g_ksidmd5);
	
	}

	appendqqnum22.Replace(_T("cfrobotselfnum"),_T("cfrobotfakeselfnum"));

		appendqqnum22+=appendqqnum;




	//api.ajaxsns.com/api.php?key=free&appid=0&msg=笑话
		BOOL copymode=false;
		if(StrStrI(sourceweburl,_T("php?key=free&appid=0&msg=")))
		{
		copymode=true;
		}
		if(StrStrI(sourceweburl,_T("index"))&&(StrStrI(sourceweburl,_T("qqshow123.com"))||StrStrI(sourceweburl,_T("szcf.info"))||StrStrI(sourceweburl,_T("cfxy.me"))))
		{
		copymode=true;
		}

	if(sourceweburl.Find(_T("%s"))!=-1)
	m_query_mtgox.Format(sourceweburl,tbufv);
	else
	m_query_mtgox.Format(_T("%s%s"),sourceweburl,tbufv);

	m_query_mtgox+=appendqqnum22;

	CString txtcontent;
	if(LocalPlugFunction(m_query_mtgox,txtcontent))
	{
		if(!txtcontent.IsEmpty())
		{
	lstrcpy(responsemsg,txtcontent);
	rtflag=true;
		}
		else
		{
			rtflag=false;
		}
	}
	else
	{
	if(::function::DownloadHttpFile(m_query_mtgox,bytebuf,ddlen)==0)
	{
		if(0)
			AfxMessageBox(m_query_mtgox);
	//str+=(char*)bytebuf;
	CStringvect temp6vect;
	CStringvect weather6vect;
	CString wstr;
	//if(::function::IsTextUTF8((char*)bytebuf))
	if(!copymode)
		{
			::function::utf8_wchar((char*)bytebuf,wstr);
	}
	//else
	//	wstr=(CString)(LPCSTR)bytebuf;

		wstr.Replace(_T("&nbsp;"),_T(" "));	

		wstr.Replace(_T("&lt;p&gt;"), _T(" "));
		wstr.Replace(_T("&lt;/p&gt;"), _T(" "));

		wstr.Replace(_T("{br}"),_T("\r\n"));
		wstr.Replace(_T("</br>"),_T("\r\n"));
		wstr.Replace(_T("<br>"),_T("\r\n"));
		wstr.Replace(_T("<br />"),_T("\r\n"));
		wstr.Replace(_T("\t"),_T("   "));
	wstr.Trim();	

	GetWebReturnContent(wstr,weather6vect);

	
	if(wstr.GetLength()==0)
rtflag=false;
	else
	{
		

		if(_tcscmp(trimusermsg,wstr)==0)
			{
			
				wstr+=_T("——问题和答复完全一致");
			}
			else
			if(_tcsncmp(trimusermsg,wstr,25)==0)
			{
			
				wstr+=_T("——问题和答复基本一致");
			}


		if(sourceweburl.Find(_T("tuling123.com"))!=-1)
wstr+=_T("——来自图灵词库");
		else if(sourceweburl.Find(_T("xiaoi.com"))!=-1)
wstr+=_T("——来自小i词库");
		else 
wstr+=_T("——来自网络词库");

		

		rtflag=true;
		if(!copymode)
lstrcpy(responsemsg,wstr);
	}
	if(wstr.GetLength()>1000000)
		MessageBox(0,responsemsg,0,0);

	}
	}
	delete []bytebuf;
	
		
				return rtflag;
		

}

int  ResponseFun(LPCTSTR usermsg,LPTSTR responsemsg,LPCTSTR qqnum,LPCTSTR groupnum,BOOL bBaiduFind)
		{
			//MessageBox(0,usermsg,responsemsg,0);

	CString lastresponsestr;
	int rtflag=1;
			//CString cityid;
			CString trimusermsg=usermsg;
			trimusermsg.Trim();
			trimusermsg.Replace(_T("\\"),_T(""));
			lstrcpy(responsemsg,_T(""));
	
	if(trimusermsg.IsEmpty())
	{
		lstrcpy(responsemsg,_T("要查询各类信息请输入#南昌天气（把南昌换成你想查询的城市名称）、#笑话、#你想聊的话题（注意这是网络词库，很贱很暴力，勿跟机器人对骂。）、#18970900000、#翻译I love you、#歌词北京欢迎你、#计算3加2乘8、192.10.1.1！"));
		return true;
	}
if(_tcsncmp(trimusermsg,_T("百度百度"),lstrlen(_T("百度百度")))==0)
	{
		lstrcpy(responsemsg,_T("找碴是吧？"));
		return true;
	}

	//天气 南昌

	CString expressstr;
	CStringvect getuinbackstr;
	CString citystr;
	CString otherqqnumberstr;
	CString baikequerystr;
	CString baiduknowquerystr;
	CString querysongstr;
	CString songaddtionalstr;
	IsforecastWeather(trimusermsg,&citystr);
	BOOL bPlaySongFlag=IsShareSong(trimusermsg,&querysongstr,&songaddtionalstr);
	BOOL expressflag=IsExpressQuery(trimusermsg,NULL,NULL);
	BOOL bQueryPoemflag=IsHidePoemQuery(trimusermsg,NULL,NULL);
	BOOL baikeflag=IsBaikeQuery(trimusermsg,&baikequerystr);
BOOL baiduknowflag=IsBaiduKnowQuery(trimusermsg,&baiduknowquerystr);

	BOOL bFindOnBaidu=0;
if(g_sourceweb==_T("http://www.baidu.com"))
	bFindOnBaidu=true;

	BOOL bFindOnxiaoi=0;
if(g_sourceweb.Find(_T("xiaoi.com"))!=-1)
	bFindOnxiaoi=true;

	BOOL bFindOntuling=0;
if(g_sourceweb==_T("http://www.tuling123.com"))
	bFindOntuling=true;

	BOOL bqqvisitflag=IsQQvisit(trimusermsg,&otherqqnumberstr);
	//CString dddrrrr;
	//dddrrrr.Format(_T("bqqvisitflag:%d"),bqqvisitflag);
	//MessageBox(0,dddrrrr,responsemsg,0);

	CString querystr;
	BOOL bAddionalQueryflag=IsforeAdditionalQuery(trimusermsg,&querystr);
	if(bPlaySongFlag)
	{
	rtflag=false;
		try
		{

	rtflag=QQPlaySongResponse(querysongstr,songaddtionalstr,responsemsg,qqnum,groupnum);
	//点歌怎么舍得我难过【送给某某某】
	//XXX花了10积分点歌【送给某某某】
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("PlaySong_error.txt"));
		catcherror(path,trimusermsg);
		}
//if(rtflag)
	return 3;


	}

	if(bqqvisitflag)
{
		rtflag=false;
		try
		{
		//	dddrrrr.Format(_T("QQvisitResponse前:%d"),bqqvisitflag);
	//MessageBox(0,dddrrrr,responsemsg,0);

	rtflag=QQvisitResponse(trimusermsg,responsemsg,qqnum,groupnum,otherqqnumberstr);
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("additionalsource_error.txt"));
		catcherror(path,trimusermsg);
		}
//if(rtflag)
	return rtflag;

}
if(bQueryPoemflag)
{
		rtflag=false;
		try
		{
	rtflag=QueryPoemResponse(trimusermsg,responsemsg);
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("Poem_error.txt"));
		catcherror(path,trimusermsg);
		}
//if(rtflag)
	return rtflag;

}

if(!g_additionalsourceweb.IsEmpty()&&Isggged&&bAddionalQueryflag)
{
		rtflag=false;
		try
		{
	rtflag=OwnSourceResponse(querystr,responsemsg,qqnum,groupnum,g_additionalsourceweb);
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("additionalsource_error.txt"));
		catcherror(path,trimusermsg);
		}
//if(rtflag)
	return 3;

}
if(!baikequerystr.IsEmpty())
	{
		
		try
		{
	rtflag=BaikeResponse(baikequerystr,responsemsg);
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("baike_error.txt"));
		catcherror(path,trimusermsg);
		}
	if(!rtflag)
	{
		CString nofindstr;
		//nofindstr.Format(_T("百度百科上未找到【%s】词条，请确认后重试！"),baikequerystr);
nofindstr.Format(_T("XXX，百度百科上未找到此词条，请确认后重试！"));
lstrcpy(responsemsg,nofindstr);
	return true;
	}
	else
		return rtflag;

	}
if(!baiduknowquerystr.IsEmpty())
	{
		
		try
		{
	rtflag=BaiduKnowResponse(baiduknowquerystr,responsemsg);
	if(lstrlen(responsemsg))
				lstrcat(responsemsg,_T("【避免替换】"));
	if(lstrlen(responsemsg)>20000000)
		MessageBox(0,responsemsg,0,0);
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("baiduknow_error.txt"));
		catcherror(path,trimusermsg);
		}
	if(!rtflag)
	{
		CString nofindstr;
		//nofindstr.Format(_T("百度知道上未找到【%s】词条，请确认后重试！"),baiduknowquerystr);
nofindstr.Format(_T("XXX，百度知道上未找到此词条，请确认后重试！"));

lstrcpy(responsemsg,nofindstr);
	return true;
	}
	else
		return rtflag;

	}



if(!citystr.IsEmpty())
	{
		
		try
		{
	rtflag=WeatherResponse(citystr,responsemsg);
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("weather_error.txt"));
		catcherror(path,trimusermsg);
		}
	}
	//btc
	else if(expressflag)
	{
		
			try
		{
	rtflag=ExpressResponse(trimusermsg,responsemsg);
	}
		catch(...)
		{
			CString path=::function::complete_path(_T("Express_error.txt"));
		catcherror(path,trimusermsg);
		}

}

if(rtflag&&lstrlen(responsemsg))
	return rtflag;

if(!bFindOnBaidu&&!bFindOnxiaoi&&!bFindOntuling)
if(!g_sourceweb.IsEmpty()&&Isggged)
{
		rtflag=false;
		try
		{
	rtflag=OwnSourceResponse(trimusermsg,responsemsg,qqnum,groupnum,g_sourceweb);
		}
		catch(...)
		{
			CString path=::function::complete_path(_T("source_error.txt"));
		catcherror(path,trimusermsg);
		}
if(rtflag)
	return 3;
}
	

	{	
		
	if(1)//始终
	{
		try
		{
			CString fromwhichquery;
			BOOL nobaikflag=false;
			BOOL tempfirstflag=0;
			if(_tcsnicmp(trimusermsg,_T("星座"),lstrlen(_T("星座")))==0)
			{
				nobaikflag=true;
				tempfirstflag=0;
				fromwhichquery=_T("【换行】星座查询完毕");
			}
			else if(_tcsnicmp(trimusermsg,_T("歌词"),lstrlen(_T("歌词")))==0)
			{
				nobaikflag=true;
				tempfirstflag=0;
					fromwhichquery=_T("【换行】歌词查询完毕");
			}
			else if(_tcsnicmp(trimusermsg,_T("笑话"),lstrlen(_T("笑话")))==0)
			{
			nobaikflag=true;
				tempfirstflag=0;
					fromwhichquery=_T("【换行】笑话查询完毕");
			}
			else if(_tcsnicmp(trimusermsg,_T("计算"),lstrlen(_T("计算")))==0)
			{
			nobaikflag=true;
				tempfirstflag=0;
					fromwhichquery=_T("【换行】计算查询完毕");
			}
			else if(_tcsnicmp(trimusermsg,_T("翻译"),lstrlen(_T("翻译")))==0)
			{
				nobaikflag=true;
				tempfirstflag=0;
					fromwhichquery=_T("【换行】翻译查询完毕");
			}
			else if(_tcsnicmp(trimusermsg,_T("1"),lstrlen(_T("1")))==0)
			{nobaikflag=true;
				tempfirstflag=0;

			}
			else if(_tcsnicmp(trimusermsg,_T("2"),lstrlen(_T("2")))==0)
			{
			nobaikflag=true;
				tempfirstflag=0;
			}

//			if(!nobaikflag)
//			{
//			//先检查是否是百度百科词条，如果是，直接返回
//rtflag=BaikeResponse(trimusermsg,responsemsg);
//if(rtflag)
//	return rtflag;
//
//			}

			if(!bFindOnBaidu||nobaikflag)
			{
			if(tempfirstflag==1)
			{

rtflag=SimsimiResponse(trimusermsg,responsemsg);
static BOOL firstonce=true;
if(firstonce)
{
	firstonce=false;
if(!rtflag)
	rtflag=SimsimiResponse(trimusermsg,responsemsg);

}
		
	if(!rtflag)
	{
		int iiiiflag=0;
		if(bFindOnxiaoi)
			iiiiflag=1;
		else if(bFindOntuling)
			iiiiflag=2;

	rtflag=AjaxsnsResponse(trimusermsg,responsemsg,qqnum,0,iiiiflag,fromwhichquery);
	}
			}
			else
			{
				{
					int iiiiflag=0;
		if(bFindOnxiaoi)
			iiiiflag=1;
		else if(bFindOntuling)
			iiiiflag=2;
			rtflag=AjaxsnsResponse(trimusermsg,responsemsg,qqnum,0,iiiiflag,fromwhichquery);

				}
	if(!rtflag)
	rtflag=SimsimiResponse(trimusermsg,responsemsg);

			}

			}
			
			if(bFindOnBaidu||bBaiduFind)
			{
			if(lstrlen(responsemsg)==0)//||bFindOnBaidu
			{
			rtflag=BaiduKnowResponse(trimusermsg,responsemsg);
			if(lstrlen(responsemsg))
				lstrcat(responsemsg,_T("【避免替换】"));
	//if(rtflag!=2)
	//	rtflag=0;

			}
			}

		}
		catch(...)
		{
			CString path=::function::complete_path(_T("sns_error.txt"));
		catcherror(path,trimusermsg);
		}
		
	
	}

	}
		//if(ticknow-lasttick>1000*1*60)
	// 此处为普通函数体
	return rtflag;
}


// 唯一的一个 C查App 对象



void InitCityMap()
{

CString filepath=::function::CFSoft_path(_T("天气.txt"),0,g_bLocalSaveflag);
	//::function::releaseself(filepath,_T("WAVE"),false,IDR_weather);
::function::releaseself(filepath,_T("WAVE"),false,IDR_weather1);
	
	CReadAUStdioFile igfile1;
	CString tempstr;
		if(igfile1.Open(filepath,CFile::modeRead|CFile::shareDenyNone))
		{
			CStringvect vectemp;
	while(igfile1.ReadString(tempstr))
	{
		::function::getmytoken(tempstr,',',vectemp);
		if(vectemp.size()>1)
		{
	g_cityidmap[vectemp[1]]=vectemp[0];
		}
	}
	igfile1.Close();
		}
	

}
void RestoreRankfile(int daynum)//daynum==1,则是昨天，daynum==2，则是前天,daynum==3，则是上一次积分记录。
{

INT64 qqgroupnum;
	for(UINT i=0;i<RealGroupNumNickNamemap.GetCount();i++)
{


		qqgroupnum=RealGroupNumNickNamemap.m_mapstr[i];
		

	GetRankFromFile(true,qqgroupnum,daynum);
	
	}

	GetRankFromFile(true,0,daynum);
	
}

void SaveRankFile()
{
	
//	static BOOL justonce=false;
//if(g_getcheckweb)
//{
//	if(!justonce)
//	{
//		justonce=true;
//	jjj=*pggged;
//	}
//}

INT64 qqgroupnum;
	for(UINT i=0;i<g_grouprankmap.m_mapstr.size();i++)
	{
		qqgroupnum=g_grouprankmap.m_mapstr[i];
		

	GetRankFromFile(false,qqgroupnum);
	

	//delete g_grouprankmap[i];
	}
	for(UINT i=0;i<g_groupspeakrankmap.m_mapstr.size();i++)
	{
		qqgroupnum=g_groupspeakrankmap.m_mapstr[i];


	GetSpeakRankFromFile(false,qqgroupnum);
	//delete g_grouprankmap[i];
	}
	for(UINT i=0;i<g_groupgrtimesmap.m_mapstr.size();i++)
	{
		qqgroupnum=g_groupgrtimesmap.m_mapstr[i];


	GetGambleRobTimesFromFile(false,qqgroupnum);
	//delete g_grouprankmap[i];
	}
	
}

