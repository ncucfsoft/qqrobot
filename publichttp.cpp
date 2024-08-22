#include "stdafx.h"
#include "publichttp.h"
CReadAUStdioFile magnetfile(true);



 int g_countdone,g_all_countdown,g_all_counterror;
 int g_all_msgcountdown;
 int g_all_blogcountdown;
 int g_total_count;
 void GB2GBK(char *szBuf)
{
if(!strcmp(szBuf,""))
return;
int nStrLen = strlen(szBuf);
WORD wLCID = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
int nReturn = LCMapStringA(wLCID, LCMAP_TRADITIONAL_CHINESE, szBuf, nStrLen, NULL, 0);
if(!nReturn)
return;
char *pcBuf = new char[nReturn + 1];
__try
{
wLCID = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
LCMapStringA(wLCID, LCMAP_TRADITIONAL_CHINESE, szBuf, nReturn, pcBuf, nReturn + 1);
memcpy(szBuf, pcBuf, nReturn);
}
__finally
{
delete[] pcBuf;
}
}
 void BIG52GBK(char*szBuf)
{
if(!strcmp(szBuf,""))
return;
int nStrLen=strlen(szBuf);
wchar_t*pws=new wchar_t[nStrLen+1];

int nReturn=MultiByteToWideChar(950,0,szBuf,nStrLen,pws,nStrLen+1);
BOOL bValue=false;
nReturn=WideCharToMultiByte(936,0,pws,nReturn,szBuf,nStrLen+1,"?",&bValue);
szBuf[nReturn]=0;


delete[]pws;

}
void   Gb2Big(char*   sGb) 
{ 
//return;
	//GB2GBK(sGb);
int nStrLen = strlen(sGb);
TCHAR *pws = new TCHAR[nStrLen + 1];
MultiByteToWideChar(936, 0, sGb, nStrLen, pws, nStrLen + 1);
BOOL bValue = false;
WideCharToMultiByte(950, 0, pws, nStrLen, sGb, nStrLen + 1, "?", &bValue);
sGb[nStrLen] = 0;
delete[] pws;
}   
void GetSetBoard_order(const char *readbuf,CString& board_order)
{
	CStringvect getbackstr;
	CString expressstr;
	expressstr.Format(_T("((?<=\\bf=)\\d+\\b)|((?<=\\bfid=)\\d+\\b)"));
	
	//forumdisplay.php?2-
	///forum/\d-
		///forum-\d-
	GetRegEX((const char*)readbuf,expressstr,getbackstr,false);
	if(getbackstr.size()==0)
	{
expressstr.Format(_T("(?<=forum[\/-])\\d+(?=-)"));//((?<=\\bf=)\\d+\\b)|((?<=\\bfid=)\\d+\\b)"));
GetRegEX((const char*)readbuf,expressstr,getbackstr,false);	
	
	}
	if(getbackstr.size()==0)
	{
expressstr.Format(_T("(?<=forumdisplay.php\\?)\\d+(?=-)"));//((?<=\\bf=)\\d+\\b)|((?<=\\bfid=)\\d+\\b)"));
GetRegEX((const char*)readbuf,expressstr,getbackstr,false);	
	
	}

	
	set<CString,NatStrLess<CString>> myset;
	for(int i=0;i<getbackstr.size();i++)
	{
	myset.insert(getbackstr[i]);
	}
	board_order=_T("");
	for(set<CString,NatStrLess<CString>>::iterator it=myset.begin();it!=myset.end();it++)
	{
	board_order+=*it;
	board_order+=',';
	}
	board_order.TrimRight(',');
}
void Write2MagnetLog(LPCTSTR str,CReadAUStdioFile* file1,int IsDebug)
{	
	if(IsDebug<13)//IsDebug!=3&&IsDebug!=4)
		return;
	
	


	EnterCriticalSection(&g_cslog);

if(file1->m_hFile==CFile::hFileNull)
{
	LeaveCriticalSection(&g_cslog);
	return;
}	
	file1->SeekToEnd();
	CString timestr;
	int leftnum=g_total_count-g_all_countdown-g_all_counterror;
/*	if(IsDebug==1)
	{
timestr.Format(_T(" 已刷%d，失败%d，还剩%d个就完成所有任务！"),g_all_countdown,g_all_counterror,leftnum);
	}
	else if(IsDebug==2)
	{
timestr.Format(_T(" 已成功刷留言：%d 人气%d,失败%d,还剩%d个"),g_all_msgcountdown,g_all_countdown,g_all_counterror,leftnum);
	}
	else */
	//if(IsDebug==3)
	{
		SYSTEMTIME mySystemTime;
	GetLocalTime(&mySystemTime);
	

timestr.Format(_T(" %02d:%02d:%02d "),mySystemTime.wHour,mySystemTime.wMinute,mySystemTime.wSecond);

	}

timestr=str+timestr;

	file1->WriteLineStr(timestr);

	file1->Flush();
	//
	LeaveCriticalSection(&g_cslog);
if(0)//mainhwnd)
		::SendMessage(mainhwnd,WM_SHOWTEXT, (WPARAM)timestr.GetBuffer(0), (LPARAM)0);  
}

int DownloadHttpFile(LPCTSTR strUrl,byte* myreadbuf,UINT &ddlen)
{
	
	boost::scoped_ptr<CInternetSession> p_session(new CInternetSession);
	ddlen=0;

	try
	{

		DWORD   dwFlags   =   INTERNET_FLAG_TRANSFER_BINARY|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_RELOAD|INTERNET_FLAG_NO_CACHE_WRITE;   
		CHttpFile   *pHttpFile   =   (CHttpFile*)p_session->OpenURL(strUrl,   1,   dwFlags);   

		DWORD   dwHttpStatus   =   0;   
		if(pHttpFile   ==   NULL)   return   -1L;   
		if(!pHttpFile->QueryInfoStatusCode(dwHttpStatus))   return   -1L;   
		if(dwHttpStatus   <   200   ||   dwHttpStatus   >=   300)   return   -1L;   


		int buflength=1024;//*100
		byte readbuf[1024];//*100
		UINT sendsize=0;
		DWORD offset=0;

		while(1)
		{
			sendsize=pHttpFile->Read(readbuf,buflength);
			if(sendsize==0)
				break;
			memcpy(myreadbuf+offset,readbuf,sendsize);
			offset+=sendsize;
		}


		ddlen=offset;
		myreadbuf[ddlen]=0;
		pHttpFile->Close();
		delete pHttpFile;       

	}
	catch(...)
	{
		ddlen=0;
		myreadbuf[ddlen]=0;
		int dd=GetLastError();
		return dd;	
	}

	return 0L;
}


BOOL Send2web(CHttpConnection* pConnection,const CString& strHeaders,LPCTSTR processpath,const char* postdata,unsigned int& sendsize,byte* readbuf,LPTSTR locationurl,OUT CString& logfilename,const char* proxy_strUsername,const char*  proxy_strPassword,BOOL Isautoredirect/*=true*/,int maxlen/*=209715200//200*1024*1024*/,BOOL bHttps/*=false*/,LPCTSTR additionalhead/*=NULL*/)
{
	
	CString magnetlogstr;
	CString newstrhd;
	BOOL Isneedlog=false;
magnetlogstr=processpath;
Write2MagnetLog(magnetlogstr);//,&magnetfile,9
if(maxlen==0)
	maxlen=200*1024*1024;
if(lstrlen(processpath)==0)
return true;
if(pConnection==NULL)
{
		magnetlogstr.Format(_T("pConnection==NULL"));
	Write2MagnetLog(magnetlogstr);
	logfilename=magnetlogstr;
return false;
}
newstrhd=strHeaders;

try
{  

	DWORD http_connect_flag;
	if(bHttps)
http_connect_flag=INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_BINARY|INTERNET_FLAG_KEEP_CONNECTION|INTERNET_FLAG_SECURE|INTERNET_FLAG_IGNORE_CERT_CN_INVALID|INTERNET_FLAG_IGNORE_CERT_DATE_INVALID;
		else
	http_connect_flag=INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_TRANSFER_BINARY|INTERNET_FLAG_KEEP_CONNECTION;
	if(!Isautoredirect)
	http_connect_flag|=INTERNET_FLAG_NO_AUTO_REDIRECT;

	if(strHeaders.Find(_T("Cookie:"))!=-1)
		http_connect_flag|=INTERNET_FLAG_NO_COOKIES;
	//
	CHttpFile* pFile=NULL;
	if(newstrhd.Find(_T("Referer: http://"))==-1)
	{
		newstrhd+=_T("Referer: http://");
newstrhd+=pConnection->GetServerName();
	newstrhd+=_T("\r\n");
	}
	
	if(postdata==0||!strlen(postdata))
	{
sendsize=0;
		pFile= pConnection->OpenRequest(CHttpConnection::HTTP_VERB_GET,processpath,0,1,0,0,http_connect_flag); 
	}
	else
	{
	
		pFile= pConnection->OpenRequest(CHttpConnection::HTTP_VERB_POST,processpath,0,1,0,0,http_connect_flag); 

if(newstrhd.Find(_T("Content-Type:"))==-1)//multipart/form-data; boundary=
{
//if(additionalhead)
//	newstrhd+=_T("Content-Type: application/x-www-form-urlencoded;charset=UTF-8\r\n");
//else
newstrhd+=_T("Content-Type: application/x-www-form-urlencoded\r\n");

}

	}

	if(!pFile)
		{
				    
				return false;	
			}
	//if(additionalhead)
	//pFile->AddRequestHeaders(additionalhead);

	pFile->SetOption(INTERNET_OPTION_RECEIVE_TIMEOUT, 200000);
pFile->SetOption(INTERNET_OPTION_SEND_TIMEOUT, 200000);

	if(proxy_strUsername&&strlen(proxy_strUsername))
pFile-> SetOption(INTERNET_OPTION_PROXY_USERNAME,(LPVOID)proxy_strUsername,strlen(proxy_strUsername)+1); 
	if(proxy_strPassword&&strlen(proxy_strPassword))
pFile-> SetOption(INTERNET_OPTION_PROXY_PASSWORD,(LPVOID)proxy_strPassword,strlen(proxy_strPassword)+1); 
BOOL result=0;
	
if(!pFile)
		{
				    
				return false;	
		}

	{
//magnetlogstr.Format(_T("sendsize:%d file address:%d"),sendsize,pFile);
		
//	MessageBox(0,magnetlogstr,0,0);
	if(pFile)
		 result=pFile->SendRequest(newstrhd, (LPVOID)postdata, sendsize); 
		//MessageBoxA(0,postdata,0,0);
	}

	DWORD status;
	if(pFile)
	{
		//magnetlogstr.Format(_T("QueryInfoStatusCode之前"));
		
	//MessageBox(0,magnetlogstr,0,0);
	if(pFile-> QueryInfoStatusCode(status)==0||status> 400) 
	{ 	
		pFile->Close();
		magnetlogstr.Format(_T("%s submit data fail:%d"),pConnection->GetServerName(),status);
		Write2MagnetLog(magnetlogstr);//,&magnetfile,9
		logfilename=magnetlogstr;
		sendsize=0;
		//	magnetlogstr.Format(_T("delete pFile之前"));
		
	//MessageBox(0,magnetlogstr,0,0);
		delete pFile;  
			//magnetlogstr.Format(_T("delete pFile之后"));
		
	//MessageBox(0,magnetlogstr,0,0);
		return false;
	}

	}
	magnetlogstr.Format(_T("%s http response:%d"),pConnection->GetServerName(),status);
	Write2MagnetLog(magnetlogstr);//,&magnetfile,9
	if(locationurl)
	{
		DWORD lolen=1024;
		if(pFile)
		if(pFile->QueryInfo(HTTP_QUERY_LOCATION,locationurl,&lolen))
		{
			locationurl[lolen]=0;

			//	magnetlogstr.Format(_T("locationurl之后"));
		
	//MessageBox(0,magnetlogstr,0,0);
		}
	}
	if(readbuf)
	{
		int buflength=2048;
		byte buf[2048];
		int myoffset=0;

		if(pFile)
		sendsize=pFile->Read(buf,buflength);

		//magnetlogstr.Format(_T("pFile->Read size:%d maxlen:%d"),sendsize,maxlen);
		//	MessageBox(0,magnetlogstr,0,0);
		while (sendsize)
		{
			if(myoffset<=maxlen-2-sendsize)
			memcpy(readbuf+myoffset,buf,sendsize);
			else
				break;
			myoffset+=sendsize;
			if(pFile)
			sendsize=pFile->Read(buf,buflength);
			
			
		//magnetlogstr.Format(_T("pFile->Read size:%d maxlen:%d myoffset:%d"),sendsize,maxlen,myoffset);
		//	MessageBox(0,magnetlogstr,0,0);

		}
		if (sendsize == 0)
		{
			DWORD   dw ;
			if(pFile)
			if (!::InternetQueryDataAvailable ((HINTERNET)(*pFile), &dw, 0, 0) || (dw != 0))
			{
				pFile->Close();
				magnetlogstr=_T("cann't get the whole file!");
				Write2MagnetLog(magnetlogstr);//,&magnetfile,9
				logfilename=magnetlogstr;
				delete pFile;       
				return false;	
			}
		}
		readbuf[myoffset]=0;
		readbuf[myoffset+1]=0;

		sendsize=myoffset;

		if(Isneedlog&&sendsize)
		{
			CFile file1;
			TCHAR safecompletename[256];
::function::Safecomplete_path(safecompletename,_T("log"));

			CreateDirectory(safecompletename,NULL);
			CString filen;
			static int ncount=0;
			ncount++;
			CString tempmid=processpath;
			if(tempmid.GetLength()>5)
				tempmid=tempmid.Left(5);
			if(logfilename)
				filen.Format(_T("log\\%s_%s_%s.htm"),pConnection->GetServerName(),tempmid,logfilename);
			else
				filen.Format(_T("log\\%s_%s_rtdata.htm"),pConnection->GetServerName(),tempmid);
			filen.Replace(_T("/"),_T("."));

::function::Safecomplete_path(safecompletename,filen);
			CString wholelogpath=safecompletename;
			if(file1.Open(wholelogpath,CFile::modeCreate|CFile::modeWrite))
			{
				file1.Write(readbuf,sendsize);
				file1.Close();
			}
		
			logfilename=wholelogpath;
		}

	}
	if(pFile)
	{
	pFile->Close();
	delete pFile;    
	}

}
catch(...)
{
	int dd=GetLastError();
	//pConnection->Close();
	magnetlogstr.Format(_T("%s %s  lasterror:%d"),pConnection->GetServerName(),_T("catch fail"),dd);
	Write2MagnetLog(magnetlogstr);//,&magnetfile,9
logfilename=magnetlogstr;
	//delete pConnection;
sendsize=0;
	return false;
}

return true;
}

void GetListFromFile(LPCTSTR filepath,CStringvect& rtvect)
{
	rtvect.clear();
	CReadAUStdioFile file1;
	CString email;
	if(file1.Open(filepath,CFile::modeRead|CFile::shareDenyWrite))
	{
		
		while(file1.ReadString(email))
		{
			email.Trim();
			if(StrStrI(filepath,_T("proxy_list.ini")))
			{
	email.Replace(_T("\t"),_T(""));
	email.Replace(_T(" "),_T(""));
			}

			if(email.GetLength())
				rtvect.push_back(email);
		}

		file1.Close();
	}

}
BOOL openself()
{
#ifdef _DEBUG
	cntopen=true;
	return true;
#endif
	CString msg;

	int filelen=myfilelength2;
	CFile file1;
	TCHAR buf[256]=_T("");
	GetModuleFileName(NULL,buf,256);
	byte *buffer=new byte[filelen];

	if(file1.Open(buf,CFile::modeRead|CFile::shareDenyWrite))
	{

		file1.Read(buffer,filelen);

CString rtmd5str;
::function::SafeGetCff(rtmd5str,buffer,filelen);

		ttttt2=rtmd5str;
		int len=file1.Read(buffer,32*sizeof(TCHAR));
		buffer[len]=0;
		buffer[len+1]=0;

		ttttt1=(CString)(LPCWSTR)buffer;



		file1.Close();
		if(ttttt1==ttttt2)
			return true;
		else 
			return false;
	}
	else
		cntopen=true;
	return true;
}
//BOOL GetLastmodifieddate(CInternetSession& p_session,LPCTSTR strUrl,DWORD querindex,CString& rtquerystr,byte* myreadbuf,DWORD &ddlen)
//{
//	//HTTP_QUERY_LAST_MODIFIED
//	ddlen=0;
//	BOOL rtflag=0;
//	try
//	{
//
//		DWORD   dwFlags   =   INTERNET_FLAG_TRANSFER_BINARY|INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_RELOAD;   
//		CHttpFile   *pHttpFile   =   (CHttpFile*)p_session.OpenURL(strUrl,   1,   dwFlags);   
//
//		DWORD   dwHttpStatus   =   0;   
//		if(pHttpFile   ==   NULL)   return   false;   
//		//if(!pHttpFile->QueryInfoStatusCode(dwHttpStatus))   return   false;   
//		//if(dwHttpStatus   <   200   ||   dwHttpStatus   >=   300)   return   -1L;  
//		char buftime[128];
//		DWORD getlen=128;
//		if(querindex==HTTP_QUERY_LAST_MODIFIED)
//		{
//
//			SYSTEMTIME m_time;
//
//			rtflag=pHttpFile->QueryInfo(HTTP_QUERY_LAST_MODIFIED,&m_time);
//			if(rtflag)
//			{
//				rtquerystr.Format(_T("%02d-%02d-%02d %02d:%02d:%02d"), m_time.wYear,m_time.wMonth,m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
//
//			}
//		}
//		else
//		{
//			rtflag=pHttpFile->QueryInfo(HTTP_QUERY_FLAG_REQUEST_HEADERS,buftime,&getlen,&querindex);
//			if(rtflag)
//			{
//				buftime[getlen]=0;
//				rtquerystr=buftime;
//
//			}
//		}
//
//		if(myreadbuf)
//		{
//			int buflength=1024;//*100
//			byte readbuf[1024];//*100
//			UINT sendsize=0;
//			DWORD offset=0;
//
//			while(1)
//			{
//				sendsize=pHttpFile->Read(readbuf,buflength);
//				if(sendsize==0)
//					break;
//				memcpy(myreadbuf+offset,readbuf,sendsize);
//				offset+=sendsize;
//			}
//
//
//			ddlen=offset;
//			myreadbuf[ddlen]=0;
//			pHttpFile->Close();
//			delete pHttpFile;       
//		}
//	}
//	catch(...)
//	{
//
//		int dd=GetLastError();
//		ddlen=dd;
//		return false;	
//	}
//
//	return rtflag;
//}
//


void GetHideValueFromHtml(byte* readbuf,LPCTSTR findhidevalue1,CKeepMap<CString,LPCTSTR,CString,LPCTSTR> &map_hidevalue)
{
	CStringvect vectemp;
	::function::getmytoken(findhidevalue1,',',vectemp);
	CStringvect getbackstr;
	CString expressstr;
	TCHAR bufvalue[64*1000];
	//"(?<=\\\\)[^\\\\]{1,150}(?=s\\d{2}e\\d{2})"
	CString tempvstr;
	for(int i=0;i<vectemp.size();i++)
	{
if(1)//map_hidevalue[vectemp[i]]==_T(""))
{
		GetValueFromBuf((const char*)readbuf,vectemp[i],getbackstr);	
		if(getbackstr.size()>0)
		{
			lstrcpy(bufvalue,getbackstr[0]);
			if(lstrlen(bufvalue))
				map_hidevalue[vectemp[i]]=bufvalue;
		}
}
}
}



void UpdatalatestVersion(LPCTSTR filename)
{
	
}
void GetKeynameFrombody(LPCTSTR reg_secondbody2,CStringvect &getbackstr)
{
	if(_tcsrchr(reg_secondbody2,',')&&!_tcsrchr(reg_secondbody2,'&'))
	{
		::function::getmytoken(reg_secondbody2,',',getbackstr);
	}
	else
	{
	CString expressstr;
	expressstr.Format(_T("((?<=&)[^& ]+?(?==%%s))|([^& ]+?(?==%%s))"));
	GetRegEX(reg_secondbody2,expressstr,getbackstr);//need consider of actual keyname
	}
}
void ReplacehideValue(byte* readbuf,const CString& oldstr,CString& rtstr,const CKeepMap<CString,LPCTSTR,CString,LPCTSTR> &map_hidevalue,BOOL needencode)
{
	try
	{
		boost::wcmatch what;//"(?<=\\\\)[^\\\\]{1,150}(?=s\\d{2}e\\d{2})"
		CString findstr=oldstr;//(CStringA)wordbuf;
		CString exphrstr=_T("\\S+?(?==%)");
		CString keyname;
		boost::wregex expression(exphrstr,boost::wregex::icase);//s01e09");//s[0-9][0-9]e[0-9][0-9]");
		wstring pfind;
		pfind=findstr.GetBuffer(0);	
		const TCHAR* pfind2=findstr;
		if(boost::regex_search(pfind2,what,expression))
		{ 
			

			keyname=(what.str()).c_str();
			if(keyname!=_T("f")&&keyname!=_T("recaptcha_response_field")&&keyname.Find(_T("username"))==-1&&keyname.Find(_T("password"))==-1)
			GetHideValueFromHtml((byte*)readbuf,keyname,const_cast<CKeepMap<CString,LPCTSTR,CString,LPCTSTR>&>(map_hidevalue));

		}

		CString fmt_replace;
		char bufvalue[1024*64];

		CStringA reg_secondbody2;
			//::function::IsTextUTF8((const char*)readbuf,strlen((const char*)readbuf));
	if((StrStrIA((const char*)readbuf,"charset=big5")!=0))
			{
				char *pbuf=new char[1024*200];
				strcpy(pbuf,(CStringA)map_hidevalue[keyname]);
		
				Gb2Big(pbuf);
reg_secondbody2=pbuf;
delete []pbuf;
		
	}
		else if((StrStrIA((const char*)readbuf,"charset=gb")==0))
		{
	::function::wchrto_utf8(map_hidevalue[keyname],reg_secondbody2);
	}
		else
		reg_secondbody2=(CStringA)map_hidevalue[keyname];

//		const int ISO_8859_1 = 28591;
//
//int CharCount =WideCharToMultiByte(437,0,map_hidevalue[keyname],-1,NULL,0,0,0);
//
//WideCharToMultiByte(437,0,(LPCWSTR)map_hidevalue[keyname],-1,bufvalue,CharCount,0,0);
		//strcpy(bufvalue,(CStringA)map_hidevalue[keyname]);

	strcpy(bufvalue,reg_secondbody2);

		if(needencode)
		{

			::function::urlencode(bufvalue);
		}
		CString tbufv=(CString)(CStringA)bufvalue;
		if(keyname==_T("image?c"))
			needencode=false;
		if(needencode)
		{
			char keynamebuf[512];
			CStringA keynameaa=(CStringA)keyname;
			strcpy(keynamebuf,keynameaa);
				::function::urlencode(keynamebuf);

			rtstr.Format(_T("%s=%s"),(CString)keynamebuf,tbufv);
		}
		else
		{
		fmt_replace.Format(_T("$1--00--%s"),tbufv);
		TCHAR buffmt[1024];
		lstrcpy(buffmt,fmt_replace);
		exphrstr=_T("(\\S+?=)(%s)");//(CStringA)exphrase;
		expression.assign(exphrstr,boost::wregex::icase);
		//boost::wregex expression2(exphrstr,boost::wregex::icase);//s01e09");//s[0-9][0-9]e[0-9][0-9]");

		//const wchar_t* pfind=(const wchar_t* )findstr;

		pfind=boost::regex_replace(pfind,expression,buffmt);

		//if(keyname.GetLength()>0&&map_hidevalue[keyname].GetLength()>0)
		{
			rtstr=pfind.c_str();
			rtstr.Replace(_T("--00--"),_T(""));
		}
		}
	}
	catch(...)
	{

	}

	//securitytoken=%s
}
BOOL GetCImageFromByte(CImage& m_image,const byte *  pMemData,  long  len)
{
	BOOL IsOk=false;
	 HGLOBAL hGlobal  =  GlobalAlloc(GMEM_MOVEABLE, len);
   void *  pData  =  GlobalLock(hGlobal);
  memcpy(pData, pMemData, len);
    GlobalUnlock(hGlobal);

  IStream *  pStream  =  NULL;
   if  (CreateStreamOnHGlobal(hGlobal, TRUE,  & pStream)  ==  S_OK)
   {
  HRESULT hr =m_image.Load(pStream);
    if (SUCCEEDED(hr))
    {
    IsOk=true;

   } 
   pStream -> Release();     
  } 
  GlobalFree(hGlobal);
return IsOk;
}
BOOL Multipartpost(CHttpConnection* &pConnection,const CString& processpath,const CStringvect& columname_com,CKeepMap<CString,LPCTSTR,CString,LPCTSTR>& map_hidevalue,const byte* readbuf,LPCTSTR columname_bin_col,const byte* binbuf,UINT len,LPCSTR proxy_strUsername,LPCSTR proxy_strPassword)
{
	
	UINT offsetpattachm,offsetstore1,offsetstore2;//=strlen(pattachm);
	TCHAR locationbuf[1256]=_T("");
	CString rtlogfilename;
	CStringA	boundarystrany2,convstr;
	CString	strHeaders=_T("Accept: */*\r\n");
	boost::scoped_array<char> pattachm(new char[3*1024*1024]);
		//CString columname_streamtype=_T("application/octet-stream");
	CString columname_streamtype=_T("image/jpeg");

		CString profile_pic=_T("c:\\test.jpg");
	CString magnetlogstr;

	strHeaders+=Content_Typeformat;
	strHeaders+=boundarystrany1;
	strHeaders+=_T("\r\n");
	boundarystrany2="--"+(CStringA)boundarystrany1;

	CStringvect getbackstr,valuevect;

	


	int countcol=0;
	CStringvect reginfvect;
	








	for(int i=0;i<columname_com.size();i++)
	{
		GetValueFromBuf((const char*)readbuf,columname_com[i],getbackstr);
		if(getbackstr.size()>0&&getbackstr[0].GetLength()>0)
		map_hidevalue[columname_com[i]]=getbackstr[0];
		

	
	}
	strcpy(pattachm.get(),"");
	for(int i=0;i<columname_com.size();i++)
	{


		convstr.Format("%s\r\nContent-Disposition: form-data; name=\"%s\"\r\n\r\n%s\r\n",boundarystrany2,(CStringA)columname_com[i],(CStringA)map_hidevalue[columname_com[i]]);

		strcat(pattachm.get(),convstr);

	}


	
	if(columname_bin_col&&lstrlen(columname_bin_col))
	{
		convstr.Format("%s\r\nContent-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\nContent-Type: %s\r\n\r\n",boundarystrany2,(CStringA)columname_bin_col,(CStringA)profile_pic,(CStringA)columname_streamtype);

		strcat(pattachm.get(),convstr);

		offsetpattachm=strlen(pattachm.get());


		pattachm[offsetpattachm]=0;
		string utfstr;

		::function::chrto_utf8(pattachm.get(),utfstr);

		offsetpattachm=utfstr.size();
		memcpy(pattachm.get(),utfstr.c_str(),offsetpattachm);
		pattachm[offsetpattachm]=0;


		int getfilelen;
		AddBinaryData(pattachm.get()+offsetpattachm,profile_pic,getfilelen);
		offsetpattachm+=getfilelen;
		convstr.Format("%s",boundarystrany2);
		getfilelen=convstr.GetLength();
		memcpy(pattachm.get()+offsetpattachm,convstr.GetBuffer(0),getfilelen);
		offsetpattachm+=getfilelen;
	}
	else
	{
		offsetpattachm=strlen(pattachm.get());


		pattachm[offsetpattachm]=0;
		string utfstr;

		::function::chrto_utf8(pattachm.get(),utfstr);

		offsetpattachm=utfstr.size();
		memcpy(pattachm.get(),utfstr.c_str(),offsetpattachm);
		pattachm[offsetpattachm]=0;

	}
	rtlogfilename=_T("multipartpost");
	if(!Send2web(pConnection,strHeaders,processpath,pattachm.get(),offsetpattachm,(byte*)readbuf,locationbuf,rtlogfilename,proxy_strUsername,proxy_strPassword))
	{


		magnetlogstr=_T("upload attachment fail!");
		Write2MagnetLog(magnetlogstr);

		return false;
	}

	return true;
}

BOOL Multipartpost(const CString& realhostname,const CString& processpath,const CStringvect& columname_com,const CStringvect& columvalue_com,const CString& columname_pic_col,const byte* picsrc,int len,CString& feedbackstr)
{
	CString magnetlogstr;
	//-------------b358fdj4ha19fdk
	//http://antigate.com/in.php
	boost::scoped_ptr<CInternetSession> p_session(new CInternetSession);
	CHttpConnection* pConnection=NULL;
		boost::scoped_array<char> pattachm(new char[3*1024*1024]);
		boost::scoped_array<char> readbuf(new char[3*1024*1024]);
		
	try
	{

		pConnection =  p_session->GetHttpConnection(realhostname); 

	}
	catch(...)
	{

		magnetlogstr.Format(_T("cann't open %s!"),realhostname);
		Write2MagnetLog(magnetlogstr);

		return false;
	}
	UINT offsetpattachm,offsetstore1,offsetstore2;//=strlen(pattachm);
	TCHAR locationbuf[1256]=_T("");
	CString rtlogfilename;
	CStringA	boundarystrany2,convstr;
	CString	strHeaders=_T("Accept: */*\r\n");

	//const_cast<CString &>(realhostname)=_T("api.deathbycaptcha.com");
	CString columname_streamtype=_T("image/jpeg");
		strHeaders+=_T("Content-Type: multipart/form-data; boundary=");
		strHeaders+=boundarystrany1;
strHeaders+=_T("\r\n");
		boundarystrany2="--"+(CStringA)boundarystrany1;

		CString	profile_pic;
		WORD headbyte=0;
		if(picsrc)
		memcpy((void*)&headbyte,picsrc,2);

		switch(headbyte)
		{
		case 0x4D42:
		profile_pic=_T("captcha.bmp");
				break;
	case 0x4947:
		profile_pic=_T("captcha.gif");
				break;
	case 0xD8FF:
		profile_pic=_T("captcha.jpg");
				break;
	case 0x5089:
		profile_pic=_T("captcha.png");
				break;

			default:
profile_pic=_T("captcha.jpg");
				break;

		};
//profile_pic=_T("image100*100");
			//CString processpath=_T("/in.php");
CStringvect getbackstr;
int countcol=0;
CStringvect reginfvect;
strcpy(pattachm.get(),"");
for(int i=0;i<columname_com.size();i++)
				{
					convstr.Format("%s\r\nContent-Disposition: form-data; name=\"%s\"\r\n\r\n%s\r\n",boundarystrany2,(CStringA)columname_com[i],(CStringA)columvalue_com[i]);
					strcat(pattachm.get(),convstr);
				}


			
		
			if(columname_pic_col.GetLength())
			{
			convstr.Format("%s\r\nContent-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\nContent-Type: %s\r\n\r\n",boundarystrany2,(CStringA)columname_pic_col,(CStringA)profile_pic,(CStringA)columname_streamtype);

			strcat(pattachm.get(),convstr);

			offsetpattachm=strlen(pattachm.get());


			pattachm.get()[offsetpattachm]=0;
			//string utfstr;

			//::function::chrto_utf8(pattachm.get(),utfstr);


			//offsetpattachm=utfstr.size();
			//memcpy(pattachm.get(),utfstr.c_str(),offsetpattachm);
			//pattachm.get()[offsetpattachm]=0;


int getfilelen=len;
			AddBinaryData(pattachm.get()+offsetpattachm,picsrc,getfilelen);
			offsetpattachm+=getfilelen;
			convstr.Format("%s--\r\n",boundarystrany2);
			getfilelen=convstr.GetLength();
			memcpy(pattachm.get()+offsetpattachm,convstr.GetBuffer(0),getfilelen);
			offsetpattachm+=getfilelen;
			
			}
			else
			{
			offsetpattachm=strlen(pattachm.get());


			pattachm.get()[offsetpattachm]=0;
		/*	string utfstr;

			::function::chrto_utf8(pattachm.get(),utfstr);

			offsetpattachm=utfstr.size();
			memcpy(pattachm.get(),utfstr.c_str(),offsetpattachm);
			pattachm.get()[offsetpattachm]=0;*/

			}
			
			rtlogfilename=_T("multipartpost");
		

			if(!Send2web(pConnection,strHeaders,processpath,pattachm.get(),offsetpattachm,(byte*)readbuf.get(),locationbuf,rtlogfilename,NULL,NULL))
			{
				magnetlogstr=_T("get feedbackstr fail!");
				Write2MagnetLog(magnetlogstr);
				
			return false;
			}

			feedbackstr=readbuf.get();
			if(pConnection)
			{
			pConnection->Close();
			delete pConnection;
			}
return false;
}
void Fillvalue(byte* readbuf,CString& reg_secondbody2,const CKeepMap<CString,LPCTSTR,CString,LPCTSTR> &map_hidevalue,BOOL encode)
{
	CString expressstr;
	CStringvect getbackstr;
	BOOL body_flag=(reg_secondbody2.Find('/')==-1);

	expressstr.Format(_T("((?<=&)[^& ]+?=%%s.*?)|([^& ]+?=%%s.*?)"));
	GetRegEX(reg_secondbody2,expressstr,getbackstr);//need consider of the actual keyname
	CString desreplacestr;
	CString smtkeyname,actkeyname;
	char bufvalue[1024*128];
	for(int i=0;i<getbackstr.size();i++)
	{
		if(!::function::FenliCtdx(getbackstr[i],smtkeyname,actkeyname,_T("#")))
						actkeyname=_T("");
		else
		{
		smtkeyname+=_T("=%s");
actkeyname.Replace(_T("=%s"),_T(""));
		}

BOOL allowencode=(smtkeyname.Find(_T("recaptcha_challenge_field"))==-1);
if(smtkeyname.Find(_T("securitytoken"))!=-1)
allowencode=0;
		ReplacehideValue(readbuf,smtkeyname,desreplacestr,map_hidevalue,body_flag&&allowencode);
		strcpy(bufvalue,(CStringA)desreplacestr);
		//if(encode&&!StrStrIA(bufvalue,"recaptcha/api")&&!StrStrIA(bufvalue,"image?c="))
		desreplacestr=bufvalue;
		if(desreplacestr.GetLength()==(smtkeyname.GetLength()-2))
		{

			CString expressstr;
			CStringvect getbackstr;
			GetValueFromBuf((const char*)readbuf,actkeyname,getbackstr);	
			if(getbackstr.size()>0)
			{
				desreplacestr+=getbackstr[0];
			}
			else
			{

			desreplacestr+=map_hidevalue[actkeyname];
			}

		}
		strcpy(bufvalue,(CStringA)desreplacestr);
		//if(encode)
			//::function::urlencode(bufvalue);

		desreplacestr=bufvalue;


		reg_secondbody2.Replace(getbackstr[i],desreplacestr);
	}

}
void AddBinaryData(char* pattachm,const byte* bytesrc,IN OUT int &getfilelen)
{
	
	if(bytesrc&&getfilelen)
	{
		memcpy(pattachm,bytesrc,getfilelen);
		char bufrt[]="\r\n";
		memcpy(pattachm+getfilelen,bufrt,strlen(bufrt));
		getfilelen+=strlen(bufrt);
		
	}
	else
	{
		char bufrt[]="\r\n";
		getfilelen=0;
		memcpy(pattachm+getfilelen,bufrt,strlen(bufrt));
		getfilelen+=strlen(bufrt);

	}
}
void AddBinaryData(char* pattachm,LPCTSTR uploadpath,int &getfilelen)
{
	getfilelen=0;
	if(PathFileExists(uploadpath))
	{
		CFile file1;
		byte* filebuf=new byte[2*1024*1024];
		if(file1.Open(uploadpath,CFile::modeRead|CFile::shareDenyWrite,NULL))
		{
			getfilelen=file1.Read(filebuf,2*1024*1024);
			filebuf[getfilelen]=0;
			file1.Close();
		}
		memcpy(pattachm,filebuf,getfilelen);
		char bufrt[]="\r\n";
		memcpy(pattachm+getfilelen,bufrt,strlen(bufrt));
		getfilelen+=strlen(bufrt);
		delete []filebuf;
	}
	else
	{
		char bufrt[]="\r\n";
		getfilelen=0;
		memcpy(pattachm+getfilelen,bufrt,strlen(bufrt));
		getfilelen+=strlen(bufrt);

	}
}
void Transfer2Html(CString& contentnew)
{
CStringvect vectemp;
							::function::getmytoken(contentnew,_T("\r\n"),vectemp);
							contentnew=_T("");
							for(int i=0;i<vectemp.size();i++)
							{
								contentnew+=_T("<P>");
								contentnew+=vectemp[i];
								contentnew+=_T("</P>");
								contentnew+=_T("\r\n");


							}
}
BOOL Postabody(CHttpConnection* &pConnection,char *pattachm,const char *readbuf,LPTSTR locationbuf,LPCTSTR bodyinf,LPCTSTR processf,const CKeepMap<CString,LPCTSTR,CString,LPCTSTR> &map_hidevalue,CString& rtlogfilename,const char* proxy_strUsername,const char*  proxy_strPassword,BOOL Isautoredirect/*=true*/)
{
CString magnetlogstr;

	CStringA reg_secondbody2;
	CString cstrbodyinf=bodyinf;
	CString cstrprof=processf;

	if(cstrprof.GetLength()==0)
		return true;
	BOOL IsbodydataFlag=(cstrprof==cstrbodyinf);

	UINT offsetpattachm;
CStringvect multkeyvect;
BOOL multpost=false;

	if(bodyinf)
	if(_tcsrchr(bodyinf,',')&&!_tcsrchr(bodyinf,'&'))
	{
		::function::getmytoken(bodyinf,',',multkeyvect);
		multpost=true;
	}

	if(!IsbodydataFlag)
	{
		if(bodyinf&&!multpost)
			Fillvalue((byte*)readbuf,cstrbodyinf,map_hidevalue);

		Fillvalue((byte*)readbuf,cstrprof,map_hidevalue);

		//::function::IsTextUTF8(readbuf,strlen(readbuf))
	/*	if((strstr(readbuf,"charset=gbk")==0)&&(strstr(readbuf,"charset=gb3212")==0))
		::function::wchrto_utf8(cstrbodyinf,reg_secondbody2);
		else
	*/	
		reg_secondbody2=(CStringA)cstrbodyinf;
		//rtlogfilename=_T("register2");
		strcpy(pattachm,reg_secondbody2);
		offsetpattachm=strlen(reg_secondbody2);
	}
	else
	{
		offsetpattachm=0;
		Fillvalue((byte*)readbuf,cstrprof,map_hidevalue,false);

	}
	int encodingtype=0;//default utf-8
		if(StrStrIA((const char*)readbuf,"charset=gb3212")||StrStrIA((const char*)readbuf,"charset=gbk"))
	{
		encodingtype=1;
	}
	else if(StrStrIA((const char*)readbuf,"charset=big5"))
	{
		encodingtype=2;
	}

	
	CString	strHeaders=_T("Accept: */*\r\n");
if(multpost)
{
CString columname_streamtype=_T("application/octet-stream");
		strHeaders+=_T("Content-Type: multipart/form-data; boundary=");
		strHeaders+=boundarystrany1;
strHeaders+=_T("\r\n");
CStringA boundarystrany2="--"+(CStringA)boundarystrany1;
CStringA convstr;
strcpy(pattachm,"");
for(int i=0;i<multkeyvect.size();i++)
				{
					convstr.Format("%s\r\nContent-Disposition: form-data; name=\"%s\"\r\n\r\n%s\r\n",boundarystrany2,(CStringA)multkeyvect[i],(CStringA)map_hidevalue[multkeyvect[i]]);
					strcat(pattachm,convstr);
				}

offsetpattachm=strlen(pattachm);
			if(encodingtype==0)
			{
			pattachm[offsetpattachm]=0;
			string utfstr;

			::function::chrto_utf8(pattachm,utfstr);

			offsetpattachm=utfstr.size();
			memcpy(pattachm,utfstr.c_str(),offsetpattachm);
			pattachm[offsetpattachm]=0;

			}
			else if(encodingtype==2)
			{
					pattachm[offsetpattachm]=0;
			string utfstr;

			Gb2Big(pattachm);

			
			offsetpattachm=strlen(pattachm);
			
				

			
			}

	
}
	
			
			

	
			rtlogfilename=_T("postmultipartpost");
			if(!Send2web(pConnection,strHeaders,cstrprof,pattachm,offsetpattachm,(byte*)readbuf,locationbuf,rtlogfilename,proxy_strUsername,proxy_strPassword,Isautoredirect))
			{
				magnetlogstr=_T("post multiorsingle fail!");
				Write2MagnetLog(magnetlogstr);
				
			return false;
			}

	return true;
}
