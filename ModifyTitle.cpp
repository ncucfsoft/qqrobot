// ModifyTitle.cpp : 实现文件
//

#include "stdafx.h"
#include "晨风qq机器人.h"
#include "ModifyTitle.h"
#include "IgnoreDlg.h"
//#include "afxdialogex.h"


// CModifyTitle 对话框
int g_lastprivilege=1;
IMPLEMENT_DYNAMIC(CModifyTitle, CDialog)
	
CModifyTitle::CModifyTitle(CKeepStrStrVectMap&replymap,CReadAUStdioFile&file1,CKeepStrStrVectMap&privilegereplymap,CReadAUStdioFile&privilegefile1,CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CModifyTitle::IDD, pParent)
	,m_autoreplyfile(file1),m_autoreplymap(replymap),m_privilegeautoreplyfile(privilegefile1),m_privilegeautoreplymap(privilegereplymap)
{
	m_parentwnd=(C晨风qq机器人Dlg*)pParent;
	bNomultLanguage=true;
	m_changed=false;
	lastfindpos=0;
	m_bPrivilege=g_lastprivilege;

	if(m_bPrivilege)
	{
		m_ppppautoreplyfile=&m_privilegeautoreplyfile;
m_ppppautoreplymap=&m_privilegeautoreplymap;
	}
	else
	{
m_ppppautoreplyfile=&m_autoreplyfile;
m_ppppautoreplymap=&m_autoreplymap;
	}
}

CModifyTitle::~CModifyTitle()
{
}

void CModifyTitle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}

void CModifyTitle::OnDestroy()
{


	if(m_changed)
	{
	
	int itemcount=m_list1.GetItemCount();
	CString qqstr,qqpasswordstr;
	CString strfmt;

	//if(file1.Open(m_path,CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone))
	
	(*m_ppppautoreplyfile).SetLength(0);
		for(int i=0;i<itemcount;i++)
	{

		qqstr=m_list1.GetItemText(i,0);
		qqpasswordstr=m_list1.GetItemText(i,1);
		strfmt.Format(_T("%s\t\t%s"),qqstr,qqpasswordstr);
		(*m_ppppautoreplyfile).WriteLineStr(strfmt);
	}
	(*m_ppppautoreplyfile).Flush();
	}
	GetKeepMapFromFile((*m_ppppautoreplymap),(*m_ppppautoreplyfile),true);

	CDialog::OnDestroy();
// TODO: 在此处添加消息处理程序代码
}
BEGIN_MESSAGE_MAP(CModifyTitle, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDOK, &CModifyTitle::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CModifyTitle::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CModifyTitle::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CModifyTitle::OnLvnItemchangedList1)
	ON_NOTIFY(NM_SETFOCUS, IDC_LIST1, &CModifyTitle::OnNMSetfocusList1)
ON_WM_CLOSE()
ON_BN_CLICKED(IDOK2, &CModifyTitle::OnBnClickedOk2)
ON_BN_CLICKED(IDC_CHECK1, &CModifyTitle::OnBnClickedCheck1)
ON_BN_CLICKED(IDC_BUTTON3, &CModifyTitle::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON5, &CModifyTitle::OnBnClickedButton5)
END_MESSAGE_MAP()


// CModifyTitle 消息处理程序
BOOL CModifyTitle::PreTranslateMessage(MSG* pMsg)
{
	LRESULT presult;
// TODO: 在此添加专用代码和/或调用基类

	if(pMsg->message==WM_KEYUP)
	{
		if(LOWORD(pMsg->wParam)==VK_DELETE)
		{
			CWnd *tempcwnd=GetFocus();
			if(tempcwnd==GetDlgItem(IDC_LIST1))
				DeleteItem();
			return true;
		}
	}
	if(pMsg->message==WM_KEYDOWN)
	{
	if(pMsg->wParam==VK_RETURN&&GetKeyState(VK_CONTROL)<0)
	{
		OnBnClickedOk();
		return true;
	}
	if(pMsg->hwnd==GetDlgItem(IDC_EDIT2)->GetSafeHwnd())
	{
		BOOL b= GetKeyState(VK_CONTROL)&0x80;
        if(b&&(pMsg->wParam=='a'||pMsg->wParam=='A'))
        {
            ((CEdit*)GetDlgItem(IDC_EDIT2))->SetSel(0,-1);
            return TRUE;
        }
		
	}
	}
	presult=CDialog::PreTranslateMessage(pMsg);

return presult;
}
void CModifyTitle::DeleteItem()
{
	intvect selectvect;
	for(int i=0;i<m_list1.GetItemCount();i++)
	{
		int   nState   =   m_list1.GetItemState(i,LVIS_SELECTED);   
		if(nState   !=0)   
		{   
			selectvect.push_back(i);
				
		}  

	}
	CString frontstr,backstr;
	setvector<CString> tempset;
	for(int i=selectvect.size()-1;i>=0;i--)
	{
frontstr=m_list1.GetItemText(selectvect[i],0);
backstr=m_list1.GetItemText(selectvect[i],1);

if((*m_ppppautoreplymap).Lookup(frontstr,tempset))
{
	setvector<CString>::iterator findit;
	if((findit=find(tempset.begin(),tempset.end(),backstr))!=tempset.end())
	{

	tempset.erase(findit);
	}
	if(tempset.size()==0)
	{
(*m_ppppautoreplymap).RemoveKey(frontstr);
	}
}
		m_list1.DeleteItem(selectvect[i]);
		

		
	}

	m_changed=true;
}
void CModifyTitle::AddQQPair(LPCTSTR qqstr,LPCTSTR pwdstr)
{
	CString qqpasswordstr=pwdstr;
	//CString tempencode=pwdstr;
//	ReversibleEncode(tempencode,qqpasswordstr,true);
	int itemcount=m_list1.GetItemCount();

		m_list1.InsertItem(itemcount,qqstr);
		m_list1.SetItemText(itemcount,1,qqpasswordstr);

		AddtoKeepMapFromFile((*m_ppppautoreplymap),qqstr,qqpasswordstr);
	(*m_ppppautoreplymap).sortLen();
		m_changed=true;
}
void CModifyTitle::OnBnClickedOk()
{
	CString qqstr,qqpasswordstr;

	GetDlgItemText(IDC_EDIT1,qqstr);
	
	GetDlgItemText(IDC_EDIT2,qqpasswordstr);
	qqstr.Trim();
	qqstr.Replace(_T("｜"), _T("|"));
	qqpasswordstr.Trim();
	TCHAR buf[256*1024];
	lstrcpy(buf,qqpasswordstr);
	//qqpasswordstr.Replace(_T("\\"),_T("\\\\"));
	qqpasswordstr.Replace(_T("\r\n"),RNDEFBUF);
	qqpasswordstr.Replace(_T("\n"),RNDEFBUF);

	qqpasswordstr.Replace(_T("\t"),_T("   "));
	qqpasswordstr.Replace(_T("xml："),_T("xml:"));
	

	BOOL bExistReply=false;

	int itemcount=m_list1.GetItemCount();
	CString tempqqstr,tempqqstr2;
		for(int i=0;i<itemcount;i++)
	{

		tempqqstr=m_list1.GetItemText(i,0);
		tempqqstr2=m_list1.GetItemText(i,1);
	if(tempqqstr==qqstr&&tempqqstr2==qqpasswordstr)//)//
	{
	
	m_list1.SetItemText(i,1,qqpasswordstr);
		bExistReply=true;
		break;
	}

	}



if(!bExistReply)
{
	AddQQPair(qqstr,qqpasswordstr);
	m_list1.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
}
		SetDlgItemText(IDC_EDIT1,_T(""));
		GetDlgItem(IDC_EDIT1)->SetFocus();

}
void CModifyTitle::LoadAllItem()
{
	m_list1.DeleteAllItems();
	//CReadAUStdioFile file1;
//	if(file1.Open(,CFile::modeRead|CFile::shareDenyNone))
	{
		CString tempstr,qqstr,qqpasswordstr;
		int itemcount;
		
		CString frontstr,backstr;
		(*m_ppppautoreplyfile).MySeekToBegin();
		str222.Format(_T("文件长度：%I64d"),(*m_ppppautoreplyfile).GetLength());
		//Write2MagnetLog(str222,&magnetfile,4);
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while((*m_ppppautoreplyfile).ReadString(tempstr))
	{
		//str222.Format(_T("第一行内容：%s"),tempstr);
		//Write2MagnetLog(str222,&magnetfile,4);

		GetPairStrFromReadFile(tempstr,frontstr,backstr);
		if(!frontstr.IsEmpty()&&!backstr.IsEmpty())
		{
		itemcount=m_list1.GetItemCount();
		m_list1.InsertItem(itemcount,frontstr);
		m_list1.SetItemText(itemcount,1,backstr);
		}

	}


	}
	int itemcount=m_list1.GetItemCount();
	lastfindpos=itemcount;

}
BOOL CModifyTitle::OnInitDialog()
{
	CMyBGCDlg::OnInitDialog();
	
	CStringvect m_ziduan;
	m_ziduan.push_back(_T("特征字符或词句"));
	m_ziduan.push_back(_T("自动回复的内容"));
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(m_bPrivilege);
	int lenauto;
	intvect m_ziduanlen;
	m_ziduanlen.resize(m_ziduan.size());
	m_ziduanlen[0]=150;
	m_ziduanlen[1]=800;
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
		if(m_list1.GetSafeHwnd())
			for(int i=0;i<m_ziduan.size();i++)
			{
	lenauto=max(1,m_ziduan[i].GetLength()/4.0)*70;

				
					m_list1.InsertColumn(i,m_ziduan[i],0,max(m_ziduanlen[i],lenauto));
			

			}

			LoadAllItem();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void CModifyTitle::OnBnClickedButton1()
{
	DeleteItem();
}

void CModifyTitle::OnDropFiles(HDROP hDropInfo)
{
	TCHAR szFileName[256];
	int FileNum = DragQueryFile(hDropInfo,(UINT)-1,szFileName,255);//得到拖动文件个数
	
	for ( int i =0 ; i < 1 ; i++ )
	{
		DragQueryFile(hDropInfo,i,szFileName,255); //szFileName第i个文件名
		ImportAFile(szFileName);
	}
	
	::DragFinish(hDropInfo);


	CMyBGCDlg::OnDropFiles(hDropInfo);
}
void CModifyTitle::xls_ImportAFile(LPCTSTR importfilename)
{
	CReadAUStdioFile file1(true);
	CString tempstr;
	if(file1.Open(importfilename,CFile::modeRead|CFile::shareDenyNone))
	{
		CStringvect vectemp;
		
		CString frontstr,backstr;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
TCHAR level922word[4]={0x9,0x9,0x22,0};
	while(file1.ReadString(tempstr))
	{
		
			GetPairStrFromReadFile(tempstr,frontstr,backstr);
	
		if(::function::TrimLeft(backstr,_T("\""))&&!::function::TrimRight(backstr,_T("\"")))
		{
			

			while(file1.ReadString(tempstr))
			{
				if(::function::TrimRight(tempstr,_T("\"")))
				{
					backstr+=_T("【换行】");
				backstr+=tempstr;
				break;
				}
				else
				{
				backstr+=_T("【换行】");
				backstr+=tempstr;
				}
		
			}
		}
			if(!frontstr.IsEmpty()&&!backstr.IsEmpty())
		AddQQPair(frontstr,backstr);
		
	}
	file1.Close();
	}

}

void CModifyTitle::org_ImportAFile(LPCTSTR importfilename)
{
	CReadAUStdioFile file1(true);
	CString tempstr;
	if(file1.Open(importfilename,CFile::modeRead|CFile::shareDenyNone))
	{
		CStringvect vectemp;
		
		CString frontstr,backstr;
		g_autoappendtext=_T("");
g_autoinserttext=_T("");
	while(file1.ReadString(tempstr))
	{
		
			GetPairStrFromReadFile(tempstr,frontstr,backstr);
			if(!frontstr.IsEmpty()&&!backstr.IsEmpty())
		AddQQPair(frontstr,backstr);
		
	}
	file1.Close();
	}

}

void CModifyTitle::ImportAFile(LPCTSTR importfilename)
{
	BOOL kuqflag=false;
	int emptycount=0;
	CReadAUStdioFile file1(true);
	CString tempstr;
	BOOL bxlsexportflag=false;
	if(file1.Open(importfilename,CFile::modeRead|CFile::shareDenyNone))
	{
		CStringvect vectemp;
		
		CString frontstr,backstr;
		TCHAR level922word[4]={0x9,0x9,0x22,0};
		int level922count=0;
	while(file1.ReadString(tempstr))
	{
		if(tempstr.Find(level922word)!=-1)
		{
		level922count++;
		}
		if(level922count>10)
			bxlsexportflag=true;

		if(tempstr.IsEmpty())
			emptycount++;
		else if(tempstr.Find('\t')==-1&&tempstr.Find(' ')==-1)
		{
		emptycount++;
		}
		else
		{
			emptycount--;
		}

	}
	file1.Close();
	}

	if(emptycount<5)
	{
		if(bxlsexportflag)
		{
		xls_ImportAFile(importfilename);
		}
		else
	org_ImportAFile(importfilename);
	}
	else
	{
	kuqflag=true;

	if(file1.Open(importfilename,CFile::modeRead))
	{
		CStringvect vectemp;
		BOOL bread1,bread2;
		CString frontstr,backstr;
	while(1)
	{
		bread1=file1.ReadString(frontstr);
		bread2=file1.ReadString(backstr);
			if(bread1&&bread2)
			{	
				if(!frontstr.IsEmpty()&&!backstr.IsEmpty())
				{

//backstr.Replace(_T("[bq"),_T("[face"));
backstr.Replace(_T("[cqname]"),_T("$robotname$"));
backstr.Replace(_T("[name]"),_T("XXX"));
frontstr.Replace(_T("[cqname]"),g_defaultqqgrouprule.g_robotname);

boost::wregex expression(_T("(\\[bq)(\\d+)]"),boost::wregex::normal|boost::wregex::icase);//,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");
		wstring findbuf=backstr.GetBuffer(0);
	
		findbuf=boost::regex_replace(findbuf,expression,_T("face$2"));
		//findbuf2=boost::regex_replace(findbuf,expression,_T("$1"));
boost::wregex expression2(_T("(\\[\"face\",)(\\d+\\])"),boost::wregex::normal|boost::wregex::icase);//,boost::wregex::icase|boost::wregex::perls01e09");//s[0-9][0-9]e[0-9][0-9]");
		wstring findbuf2=frontstr.GetBuffer(0);
		findbuf2=boost::regex_replace(findbuf2,expression2,_T(",$1$2,\""));

//[bq98]         [face98]
//["face",87]       ,["face",83],"

		backstr=findbuf.c_str();
		frontstr=findbuf2.c_str();

		AddQQPair(frontstr,backstr);
				}
				ULONGLONG posnow=file1.GetPosition();
			file1.ReadString(backstr);
			if(!backstr.IsEmpty())
				file1.Seek(posnow,file1.begin);
			}
			else
				break;
	
		
	}
	file1.Close();
	}

	}

	m_list1.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
}
void CModifyTitle::OnBnClickedButton2()
{
	TCHAR buflan[256]=_T("包含自动回复的文本文件|*.txt;*.log||");
	CFileDialog  filedlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,buflan);
	if(filedlg.DoModal()!=IDOK)
	{
		return;
	}

	CString importfilename=filedlg.GetPathName();
	
	ImportAFile(importfilename);
	


}


void CModifyTitle::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	

	int istat=pNMLV->iItem;
	int lastrclick_row=istat;

	CString pString;
	//int ncount=m_list1.GetHeaderCtrl()->GetItemCount();
	//for(int i=0;i<ncount;i++)
	{
		pString=m_list1.GetItemText(istat,0);
	
		
			SetDlgItemText(IDC_EDIT1,pString);
			
		pString=m_list1.GetItemText(istat,1);
	
	pString.Replace(RNDEFBUF,_T("\r\n"));
//	pString.Replace(_T("\\\\"),_T("\\"));

			SetDlgItemText(IDC_EDIT2,pString);

	}



	*pResult = 0;
}



void CModifyTitle::OnNMSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}











void CModifyTitle::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		//m_parentwnd->OnDelReplyconfigDlg();
		
	CMyBGCDlg::OnClose();
}







void CModifyTitle::OnBnClickedOk2()
{
	
		int itemcount=m_list1.GetItemCount();
	CString qqstr,qqpasswordstr;
	CString strfmt;
	CString findstr;
	GetDlgItemText(IDC_EDIT3,findstr);

		if(lastfindpos>itemcount)
			lastfindpos=itemcount;
		
int i=0;
	for(i=lastfindpos-1;i>=0;i--)
	{
		
		qqstr=m_list1.GetItemText(i,0);
		qqpasswordstr=m_list1.GetItemText(i,1);
	if(StrStrI(qqstr,findstr)||StrStrI(qqpasswordstr,findstr))
	{

		if(lastfindpos<itemcount)
m_list1.SetItemState(lastfindpos,0,-1);
	
	m_list1.SetItemState(i,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	lastfindpos=i;
	m_list1.EnsureVisible(i,false);
m_list1.SetFocus();
	break;
	}

	}
	if(i==-1)
		lastfindpos=itemcount;
}


void CModifyTitle::OnBnClickedCheck1()
{
	m_bPrivilege=((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	g_lastprivilege=m_bPrivilege;
	if(m_bPrivilege)
	{
		m_ppppautoreplyfile=&m_privilegeautoreplyfile;
m_ppppautoreplymap=&m_privilegeautoreplymap;
	}
	else
	{
m_ppppautoreplyfile=&m_autoreplyfile;
m_ppppautoreplymap=&m_autoreplymap;
	}
	LoadAllItem();
}


void CModifyTitle::OnBnClickedButton3()
{


	TCHAR buflan[512] = _T("图片文件|*.png;*.bmp;*.jpg;*.jpeg;*.gif||");
	CFileDialog  filedlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, buflan);
	if (filedlg.DoModal() != IDOK)
	{
		return;
	}
	CString uploadfilename;
	uploadfilename = filedlg.GetPathName();
	CString tempstr;
	tempstr.Format(_T("[imgurl]%s[/imgurl]"),uploadfilename);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		int nLength= pEdit->GetWindowTextLength();;// = pEdit->GetSel();
//
	pEdit->SetSel(nLength, nLength);
	//l追加文本
	pEdit->ReplaceSel(tempstr);
	//IDC_EDIT2

}


void CModifyTitle::OnBnClickedButton5()
{
		intvect selectvect;
	for(int i=0;i<m_list1.GetItemCount();i++)
	{
		int   nState   =   m_list1.GetItemState(i,LVIS_SELECTED);   
		if(nState   !=0)   
		{   
			selectvect.push_back(i);
				
		}  

	}

	if(selectvect.size()>1)
	{
		MessageBox(_T("修改时，不能选中多条记录，只能单选某一条记录，请重试！"),_T("请单选某一条记录用于修改"),0);
	for(int i=0;i<selectvect.size();i++)
	{
		m_list1.SetItemState(selectvect[i],0,-1);
	}
	return;
	}
	CString qqstr,qqpasswordstr;
	GetDlgItemText(IDC_EDIT1,qqstr);
	
	GetDlgItemText(IDC_EDIT2,qqpasswordstr);
	qqstr.Trim();
	qqstr.Replace(_T("｜"), _T("|"));
	qqpasswordstr.Trim();
	//qqpasswordstr.Replace(_T("\\"),_T("\\\\"));
	qqpasswordstr.Replace(_T("\r\n"),RNDEFBUF);
	qqpasswordstr.Replace(_T("\n"),RNDEFBUF);

	qqpasswordstr.Replace(_T("\t"),_T("   "));
	qqpasswordstr.Replace(_T("xml："),_T("xml:"));
	
	
	CString frontstr,backstr;
	setvector<CString> tempset;

		frontstr=m_list1.GetItemText(selectvect.back(),0);
backstr=m_list1.GetItemText(selectvect.back(),1);

if((*m_ppppautoreplymap).Lookup(frontstr,tempset))
{
	setvector<CString>::iterator findit;
	if((findit=find(tempset.begin(),tempset.end(),backstr))!=tempset.end())
	{

	tempset.erase(findit);
	}
	if(tempset.size()==0)
	{
(*m_ppppautoreplymap).RemoveKey(frontstr);
	}
}

	AddtoKeepMapFromFile((*m_ppppautoreplymap),qqstr,qqpasswordstr);
	(*m_ppppautoreplymap).sortLen();
		m_changed=true;

		m_list1.SetItemText(selectvect.back(),0,qqstr);
		m_list1.SetItemText(selectvect.back(),1,qqpasswordstr);

		SetDlgItemText(IDC_EDIT1,_T(""));
		GetDlgItem(IDC_EDIT1)->SetFocus();
}
