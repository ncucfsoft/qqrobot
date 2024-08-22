#pragma once



typedef struct 
{
	CString 	reg_previous1,reg_previous2,reg_first,reg_second,reg_third,reg_freshimage,reg_freshimagebody,reg_fourth;
CString reg_secondbody,reg_fourthbody;
CString boardid_order;
CString updateprev,updatesignature,upsignaturebody;
CString updateinfprev,updateinf,upinfbody;

CString login_visit,login_post,login_loginbody;
CString post_board,post_post,postbody;

CString reply_show,reply_post,replybody;


CString board_order;
CString friend_sort,friend_add;

CString pm_checkmsg,pm_sendnew,pm_reply,pm_lastmsgbody;

CString columname_com,columname_pic_col,columname_streamtype;


	//BOOL IsForumType,IsViewResult,NeedReadNfo,forcinglogin,IsNotPtweb,IsShowMagnetAds;


}OneLuaConfig;


#define GETLUASTR(var) \
	lua_getfield (m_pL, LUA_GLOBALSINDEX,#var);\
	pleftb= lua_tolstring(m_pL, -1,NULL);\
	temp1config.var=(CStringA)pleftb;\
	lua_pop(m_pL, 1);

#define GETLUAINT(var) \
	lua_getfield (m_pL, LUA_GLOBALSINDEX,#var);\
	temp1config.var= lua_tointeger(m_pL, -1);\
	lua_pop(m_pL, 1);

#define GETGLOBALLUASTR(var) \
	lua_getfield (m_pL, LUA_GLOBALSINDEX,#var);\
	pleftb= lua_tolstring(m_pL, -1,NULL);\
	var=(CStringA)pleftb;\
	lua_pop(m_pL, 1);

#define GETGLOBALLUAINT(var) \
	lua_getfield (m_pL, LUA_GLOBALSINDEX,#var);\
	var= lua_tointeger(m_pL, -1);\
	lua_pop(m_pL, 1);


enum enum_web_type
{
    vbulletin=1,
phpbb=2,
ipb=3,
discuz=4,
hotelchatter=10,
opencube=11,
phpbbcom=12,
yookoscom=13,

};
typedef struct 
{
CString web_host;
enum_web_type web_type;
CString username;
CString password;
CString fid__topicid;
}ListLine;
typedef vector<ListLine> ListLineVect;
void GetOneLuafileset(enum_web_type web_type,int additionalref,OneLuaConfig& temp1config);

extern BOOL Send2web(CHttpConnection* pConnection,const CString& strHeaders,LPCTSTR processpath,const char* sttt,unsigned int& sendsize,byte* readbuf,LPTSTR locationurl,OUT CString& logfilename,const char* proxy_strUsername=NULL,const char*  proxy_strPassword=NULL,BOOL Isautoredirect=true,int maxlen=209715200,BOOL bHttps=false,LPCTSTR additionalhead=NULL);


extern CReadAUStdioFile magnetfile;
extern void Write2MagnetLog(LPCTSTR str,CReadAUStdioFile* file1=&magnetfile,BOOL IsDebug=false);
extern int DownloadHttpFile(LPCTSTR strUrl,byte* myreadbuf,UINT &ddlen);
extern BOOL Postabody(CHttpConnection* &pConnection,char *pattachm,const char *readbuf,LPTSTR locationbuf,LPCTSTR bodyinf,LPCTSTR processf,const CKeepMap<CString,LPCTSTR,CString,LPCTSTR> &map_hidevalue,CString& rtlogfilename,const char* proxy_strUsername=NULL,const char*  proxy_strPassword=NULL,BOOL Isautoredirect=true);
extern void Fillvalue(byte* readbuf,CString& reg_secondbody2,const CKeepMap<CString,LPCTSTR,CString,LPCTSTR> &map_hidevalue,BOOL encode=true);
extern BOOL openself();
extern BOOL GetCImageFromByte(CImage& m_image,const byte *  pMemData,  long  len);
extern void UpdatalatestVersion(LPCTSTR filename);
extern void GetKeynameFrombody(LPCTSTR reg_secondbody2,CStringvect &getbackstr);
extern void Transfer2Html(CString& contentnew);
extern void StartMonitorProcess(const TCHAR* modulename,TCHAR* MonszTitle,TCHAR* parentprocessname,HWND& mon_hwnd);
extern const int myfilelength2;//15174656;//
extern int oopp;
extern int alreadytriggered;
extern int cntopen;
extern CString ttttt1,ttttt2;
//extern HWND mainwnd;
extern int g_countdone;
extern int g_all_countdown;
extern CRITICAL_SECTION g_csevent,g_cswnd,g_csdatabase,g_cslog;
const int WM_SHOWTEXT=WM_USER+240;
const int WM_FRESHLIST=WM_USER+250;
const CString boundarystrany1=_T("---------------------------7dd3492b3e03e6");
								  
const CString Content_Typeformat=_T("Content-Type: multipart/form-data; boundary=");
const int WM_SHOWDLG=WM_USER+220;
extern void chrto_utf8(LPCSTR cbuf,std::string& tranlatedbuf);
void   Gb2Big(char*   sGb);
extern BOOL Multipartpost(CHttpConnection* &pConnection,const CString& processpath,const CStringvect& columname_com,CKeepMap<CString,LPCTSTR,CString,LPCTSTR>& map_hidevalue,const byte* readbuf,LPCTSTR columname_bin_col=NULL,const byte* binbuf=NULL,UINT len=0,LPCSTR proxy_strUsername=NULL,LPCSTR proxy_strPassword=NULL);

extern BOOL Multipartpost(const CString& realhostname,const CString& processpath,const CStringvect& columname_com,const CStringvect& columvalue_com,const CString& columname_pic_col,const byte* picsrc,int len,CString& feedbackstr);
extern void AddBinaryData(char* pattachm,LPCTSTR uploadpath,int &getfilelen);
extern void AddBinaryData(char* pattachm,const byte* bytesrc,IN OUT int &getfilelen);
extern UINT profunPost(LPVOID lp);
extern void GetSetBoard_order(const char *readbuf,CString& board_order);
extern  void BIG52GBK(char*szBuf);
extern UINT profunReply(LPVOID lp);
extern UINT profunProfile(LPVOID lp);
extern UINT profunRegister(LPVOID lp);
extern UINT pro_Createthread(LPVOID lp);
extern UINT pro_CreatethreadforPost(LPVOID lp);
extern UINT pro_CreatethreadforUpdateProfile(LPVOID lp);
extern UINT pro_CreatethreadforReply(LPVOID lp);
extern void GetListFromFile(LPCTSTR filepath,CStringvect& rtvect);
extern BOOL CombinePic(const vector<vector<byte>>& picsvect,vector<byte>& newpic,int type/*=3*/);
extern BOOL RTbackConfirmcode(byte* buf,int len,CString& confirmcode,int& decaptchid);
//template<typename T2,typename T3>
//BOOL GetRegEX(const char* wordbuf,T2 exphrase,vector< T3>& findvect,BOOL replacevalue=true)
//{
//	BOOL Issearched=false;
//	findvect.clear();
//	T3 oday_name;
//
//
//	T3 originalstr=(T3)"&amp;";
//	T3 insteadstr=(T3)"&";
//
//	try
//	{
//		boost::cmatch what;//"(?<=\\\\)[^\\\\]{1,150}(?=s\\d{2}e\\d{2})"
//		CStringA findstr=wordbuf;
//		CStringA exphrstr=(CStringA)exphrase;
//
//		boost::regex expression(exphrstr,boost::wregex::normal|boost::wregex::icase);//no_mod_s multiple line,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");
//
//		const CHAR* pfind=(const CHAR* )findstr;
//
//		while (boost::regex_search(pfind,what,expression))
//		{ 
//Issearched=true;
//			int size  = what.size();
//			oday_name=what[1].first;
//			oday_name+=what[1].second;
//			oday_name=(what.str()).c_str();
//		
//			if(replacevalue)
//			{
//		vector< T3> subgetbackstr;
//			T2 subexpressstr=(T2)"(?<=VALUE=[\"']).*";
//if(GetRegEX(oday_name,subexpressstr,subgetbackstr))
//{
//	subgetbackstr.resize(1);
//oday_name=subgetbackstr[0];
//
//
//}
//			}
//			oday_name.Replace(originalstr,insteadstr);
//			if(oday_name.GetLength()>0)
//				findvect.push_back(oday_name);
//
//				if(oday_name.GetLength()==0)
//			break;
//			pfind=what[0].second; 
//		}
//	}
//	catch(...)
//	{
//
//	}
//	return Issearched;
//}
//template<typename T2,typename T3>
//BOOL GetRegEX(const TCHAR* wordbuf,T2 exphrase,vector< T3>& findvect,BOOL replacevalue=true)
//{
//	BOOL Issearched=false;
//	findvect.clear();
//	T3 oday_name;
//	
//	T3 originalstr=(T3)"&amp;";
//	T3 insteadstr=(T3)"&";
//	
//	try
//	{
//		boost::wcmatch what;//"(?<=\\\\)[^\\\\]{1,150}(?=s\\d{2}e\\d{2})"
//		CString findstr=wordbuf;
//		CString exphrstr=(CString)exphrase;
//
//		boost::wregex expression(exphrstr,boost::wregex::normal|boost::wregex::icase);//,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");
//
//		const TCHAR* pfind=(const TCHAR* )findstr;
//
//		while (boost::regex_search(pfind,what,expression))
//		{ 
//Issearched=true;
//			int size  = what.size();
//			oday_name=what[1].first;
//			oday_name+=what[1].second;
//			oday_name=(what.str()).c_str();
//		
//			if(replacevalue)
//			{
//		vector< T3> subgetbackstr;
//			T2 subexpressstr=(T2)"(?<=VALUE=[\"']).*";
//
//if(GetRegEX(oday_name,subexpressstr,subgetbackstr))
//{
//	subgetbackstr.resize(1);
//oday_name=subgetbackstr[0];
//
//
//}
//			}
//			//oday_name.Replace(replacestr,placedstr);
//	oday_name.Replace(originalstr,insteadstr);
//			if(oday_name.GetLength()>0)
//				findvect.push_back(oday_name);
//
//			if(oday_name.GetLength()==0)
//			break;
//			pfind=what[0].second; 
//
//		}
//	}
//	catch(...)
//	{
//
//	}
//	return Issearched;
//}
template <typename T1>
void GetValueFromBuf(const char* readbuf,LPCTSTR keyname,vector<T1>& getbackstr)
{
if(lstrlen(keyname)==0)
return;
	CString expressstr;
	CString tempvstr=keyname;
	tempvstr.Replace(_T("["),_T("\\["));
	tempvstr.Replace(_T("]"),_T("\\]"));
	tempvstr.Replace(_T("?"),_T("\\?"));

	TCHAR bufexp[256]=_T("((?<=name=[\'\"]%s[\'\"] )[^>]*?value=[\"'].*?(?=[\"']))|((?<=\\b%s=).*?(?=[&'\"]))|((?<=<(%s)>).*?(?=</%s>))|(?<='%s']\\s{3}=\\s['\"]).*?(?=['\"])|(?<=%s : [\"']).*?(?=[\"'],)");//|((?<=\\b%s=).*?(?=\"))|((?<=\\b%s=).*?(?=&))|((?<=\\b%s=).*?(?=\'))|(?<=<(%s)>).*?(?=<\/%s>)");
	expressstr.Format(bufexp,tempvstr,tempvstr,tempvstr,tempvstr,tempvstr,tempvstr);//,tempvstr,tempvstr,tempvstr,tempvstr,tempvstr);

	GetRegEX((const char*)readbuf,expressstr,getbackstr);
	//if(getbackstr.size()==0)
	//{
	//TCHAR bufexp[256]=_T("((?<=\\b%s=).*?(?=[&'\"]))");//|((?<=\\b%s=).*?(?=\"))|((?<=\\b%s=).*?(?=&))|((?<=\\b%s=).*?(?=\'))|(?<=<(%s)>).*?(?=<\/%s>)");
	//expressstr.Format(bufexp,tempvstr);//,tempvstr,tempvstr,tempvstr,tempvstr,tempvstr);

	//GetRegEX((const char*)readbuf,expressstr,getbackstr);
	//
	//
	//}
}
#define ENUMLIST \
CString web_host,web_typestr,ename,general_password;\
	ListLineVect* pstrvect=new ListLineVect;\
ListLine templistline;\
CString seperatebuf;\
for(int cursel=0;cursel<m_list1.GetItemCount();cursel++)\
{\
int   nState   =   m_list1.GetItemState(cursel,LVIS_SELECTED);\
if(nState!=0)\
{\
templistline.web_host =m_list1.GetItemText(cursel,0);\
templistline.web_type=map_webinf[templistline.web_host];\
templistline.username=m_list1.GetItemText(cursel,1);\
templistline.password=m_list1.GetItemText(cursel,2);\
templistline.fid__topicid=m_list1.GetItemText(cursel,5);\
pstrvect->push_back(templistline);\
}\
}\
	if(pstrvect->size()==0)\
{\
	AfxMessageBox(_T("You didn't Select any Item."));\
	return;\
}
