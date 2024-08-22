// AdminList.cpp : 实现文件
//

#include "stdafx.h"
#include "AdminList.h"
#include "MoreAdminList.h"

//#include "afxdialogex.h"


// CAdminList 对话框

IMPLEMENT_DYNAMIC(CAdminList, CDialog)

CAdminList::CAdminList(qqgrouprule& temprule,CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CAdminList::IDD, pParent),m_qqgrouprule(temprule)
{
	if(&m_qqgrouprule==&g_defaultqqgrouprule)
	m_defaultflag=true;
	else
	m_defaultflag=false;
	m_onceflag=false;
	bNomultLanguage=true;
}

CAdminList::~CAdminList()
{
}
LRESULT CAdminList::OnNcHitTest(CPoint point)
{
	  CRect rc;
           GetClientRect(&rc);
           ClientToScreen(&rc);
           return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);   //鼠标如果在客户区，将其当作标题栏
}

void CAdminList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdminList, CDialog)
	ON_WM_NCHITTEST()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_EN_KILLFOCUS(IDC_EDIT9, &CAdminList::OnEnKillfocusEdit9)
	ON_BN_CLICKED(IDOK, &CAdminList::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &CAdminList::OnBnClickedCheck1)
ON_BN_CLICKED(IDC_RADIO1, &CAdminList::OnBnClickedRadio1)
ON_BN_CLICKED(IDC_RADIO2, &CAdminList::OnBnClickedRadio2)
ON_BN_CLICKED(IDC_RADIO3, &CAdminList::OnBnClickedRadio3)
ON_BN_CLICKED(IDC_RADIO4, &CAdminList::OnBnClickedRadio4)
ON_EN_KILLFOCUS(IDC_EDIT8, &CAdminList::OnEnKillfocusEdit8)
ON_EN_KILLFOCUS(IDC_EDIT10, &CAdminList::OnEnKillfocusEdit10)
ON_EN_KILLFOCUS(IDC_EDIT13, &CAdminList::OnEnKillfocusEdit13)
ON_EN_KILLFOCUS(IDC_EDIT6, &CAdminList::OnEnKillfocusEdit6)
ON_EN_KILLFOCUS(IDC_EDIT7, &CAdminList::OnEnKillfocusEdit7)
ON_EN_KILLFOCUS(IDC_EDIT11, &CAdminList::OnEnKillfocusEdit11)
ON_EN_KILLFOCUS(IDC_EDIT14, &CAdminList::OnEnKillfocusEdit14)
ON_EN_KILLFOCUS(IDC_EDIT16, &CAdminList::OnEnKillfocusEdit16)

ON_EN_KILLFOCUS(IDC_EDIT1, &CAdminList::OnEnKillfocusEdit1)
ON_BN_CLICKED(IDC_CHECK3, &CAdminList::OnBnClickedCheck3)
ON_BN_CLICKED(IDC_CHECK6, &CAdminList::OnBnClickedCheck6)
ON_BN_CLICKED(IDC_CHECK11, &CAdminList::OnBnClickedCheck11)
ON_BN_CLICKED(IDC_CHECK2, &CAdminList::OnBnClickedCheck2)
ON_BN_CLICKED(IDC_CHECK4, &CAdminList::OnBnClickedCheck4)

ON_BN_CLICKED(IDC_BUTTON1, &CAdminList::OnBnClickedButton1)
ON_BN_CLICKED(IDC_CHECK9, &CAdminList::OnBnClickedCheck9)
ON_BN_CLICKED(IDC_CHECK7, &CAdminList::OnBnClickedCheck7)
ON_BN_CLICKED(IDC_CHECK14, &CAdminList::OnBnClickedCheck14)
ON_BN_CLICKED(IDC_CHECK15, &CAdminList::OnBnClickedCheck15)
ON_BN_CLICKED(IDC_CHECK13, &CAdminList::OnBnClickedCheck13)
ON_BN_CLICKED(IDC_CHECK12, &CAdminList::OnBnClickedCheck12)
ON_BN_CLICKED(IDC_CHECK16, &CAdminList::OnBnClickedCheck16)
ON_BN_CLICKED(IDC_CHECK17, &CAdminList::OnBnClickedCheck17)
ON_EN_KILLFOCUS(IDC_EDIT18, &CAdminList::OnEnKillfocusEdit18)
ON_EN_KILLFOCUS(IDC_EDIT17, &CAdminList::OnEnKillfocusEdit17)
ON_EN_KILLFOCUS(IDC_EDIT19, &CAdminList::OnEnKillfocusEdit19)
ON_EN_KILLFOCUS(IDC_EDIT20, &CAdminList::OnEnKillfocusEdit20)
ON_EN_KILLFOCUS(IDC_EDIT21, &CAdminList::OnEnKillfocusEdit21)
ON_EN_KILLFOCUS(IDC_EDIT22, &CAdminList::OnEnKillfocusEdit22)
ON_EN_KILLFOCUS(IDC_EDIT23, &CAdminList::OnEnKillfocusEdit23)
ON_BN_CLICKED(IDC_CHECK19, &CAdminList::OnBnClickedCheck19)
ON_BN_CLICKED(IDC_CHECK18, &CAdminList::OnBnClickedCheck18)
ON_EN_KILLFOCUS(IDC_EDIT24, &CAdminList::OnEnKillfocusEdit24)
ON_EN_KILLFOCUS(IDC_EDIT25, &CAdminList::OnEnKillfocusEdit25)
ON_BN_CLICKED(IDC_CHECK20, &CAdminList::OnBnClickedCheck20)
ON_BN_CLICKED(IDC_CHECK21, &CAdminList::OnBnClickedCheck21)
ON_EN_KILLFOCUS(IDC_EDIT28, &CAdminList::OnEnKillfocusEdit28)
ON_EN_KILLFOCUS(IDC_EDIT29, &CAdminList::OnEnKillfocusEdit29)
ON_BN_CLICKED(IDC_BUTTON2, &CAdminList::OnBnClickedButton2)
ON_EN_KILLFOCUS(IDC_EDIT41, &CAdminList::OnEnKillfocusEdit41)
ON_EN_KILLFOCUS(IDC_EDIT42, &CAdminList::OnEnKillfocusEdit42)
ON_BN_CLICKED(IDC_BUTTON3, &CAdminList::OnBnClickedButton3)
ON_EN_KILLFOCUS(IDC_EDIT49, &CAdminList::OnEnKillfocusEdit49)
ON_EN_KILLFOCUS(IDC_EDIT50, &CAdminList::OnEnKillfocusEdit50)
ON_EN_KILLFOCUS(IDC_EDIT32, &CAdminList::OnEnKillfocusEdit32)
ON_EN_KILLFOCUS(IDC_EDIT33, &CAdminList::OnEnKillfocusEdit33)
END_MESSAGE_MAP()

BOOL CAdminList::OnInitDialog()
{
	CMyBGCDlg::OnInitDialog();

	//
	//GidNickNamemap[falsegroupUin]=nicknamestr;
	//GidRealGNummap
	INT64 falsegroupuin=GetGUinFromRealGroupqqNum(m_qqgrouprule.m_selfrealqqgroupnum);
	if(falsegroupuin)
	{
	CString nicknamestr;
	GidNickNamemap.Lookup(falsegroupuin,nicknamestr);
nicknamestr+=_T("——群管理员qq号名单、加群处理、群黑名单设置——群管理员可在群聊天中发送指令更改这些设置");
	SetWindowText(nicknamestr);
	}
	else
SetWindowText(_T("群管理员qq号名单、加群处理、群黑名单设置——群管理员可在群聊天中发送指令更改这些设置——关闭窗口才能使设置生效"));
	CEdit *tempedit=(CEdit*)GetDlgItem(IDC_EDIT1);
tempedit->SetLimitText(-1);
tempedit=(CEdit*)GetDlgItem(IDC_EDIT23);
tempedit->SetLimitText(-1);
tempedit=(CEdit*)GetDlgItem(IDC_EDIT25);
tempedit->SetLimitText(-1);
tempedit=(CEdit*)GetDlgItem(IDC_EDIT42);
tempedit->SetLimitText(-1);

	SetDlgItemText(IDC_EDIT9,m_qqgrouprule.g_adminliststr);
SetDlgItemText(IDC_EDIT13,m_qqgrouprule.g_group_pincodestr);
SetDlgItemInt(IDC_EDIT32,m_qqgrouprule.g_group_pinqqlevel);
SetDlgItemInt(IDC_EDIT33,m_qqgrouprule.g_group_pinqqdarenlevel);

SetDlgItemText(IDC_EDIT10,m_qqgrouprule.g_group_denyreason);
SetDlgItemText(IDC_EDIT1,m_qqgrouprule.g_blackliststr);
SetDlgItemText(IDC_EDIT23,m_qqgrouprule.g_banliststr);
SetDlgItemText(IDC_EDIT25,m_qqgrouprule.g_forwordkeyliststr);
SetDlgItemText(IDC_EDIT42,m_qqgrouprule.g_vipliststr);
SetDlgItemText(IDC_EDIT20,m_qqgrouprule.g_tradegrouplist);
	SetDlgItemText(IDC_EDIT7,m_qqgrouprule.g_prefixstr);
	SetDlgItemInt(IDC_EDIT16,m_qqgrouprule.g_timeover);
SetDlgItemText(IDC_EDIT14,m_qqgrouprule.g_robotname);
SetDlgItemInt(IDC_EDIT6,m_qqgrouprule.g_percent);


	SetDlgItemText(IDC_EDIT17,m_qqgrouprule.g_hellowstr);
	SetDlgItemInt(IDC_EDIT18,m_qqgrouprule.g_autonoticetime);
SetDlgItemText(IDC_EDIT29,m_qqgrouprule.g_coinname);
SetDlgItemInt(IDC_EDIT19,m_qqgrouprule.g_scale);
SetDlgItemInt(IDC_EDIT49,m_qqgrouprule.m_tax_percent);
SetDlgItemInt(IDC_EDIT50,m_qqgrouprule.m_dropequipscale);



CString lastranktitlestr=m_qqgrouprule.g_ranktitlestr;
		lastranktitlestr.Trim();
		lastranktitlestr.Replace(_T("\\t"),_T("\t"));	
		m_qqgrouprule.g_ranktitlestr=lastranktitlestr;
		
SetDlgItemText(IDC_EDIT22,m_qqgrouprule.g_ranktitlestr);

lastranktitlestr=m_qqgrouprule.g_storeprice;
		lastranktitlestr.Trim();
		lastranktitlestr.Replace(_T("\\t"),_T("\t"));	
		m_qqgrouprule.g_storeprice=lastranktitlestr;
		
SetDlgItemText(IDC_EDIT28,m_qqgrouprule.g_storeprice);

CString lasttimetaskstr=m_qqgrouprule.timetask;
		lasttimetaskstr.Trim();
		lasttimetaskstr.Replace(_T("\\t"),_T("\t"));	
		m_qqgrouprule.timetask=lasttimetaskstr;
		
SetDlgItemText(IDC_EDIT41,m_qqgrouprule.timetask);


SetDlgItemInt(IDC_EDIT21,m_qqgrouprule.g_checkperiod);
SetDlgItemInt(IDC_EDIT24,m_qqgrouprule.g_gamblerobtimes);


((CButton*)GetDlgItem(IDC_CHECK9))->SetCheck(m_qqgrouprule.g_continuefind);
SetDlgItemText(IDC_EDIT14,m_qqgrouprule.g_robotname);
SetDlgItemInt(IDC_EDIT16,m_qqgrouprule.g_timeover);
SetDlgItemInt(IDC_EDIT6,m_qqgrouprule.g_percent);
SetDlgItemText(IDC_EDIT11,m_qqgrouprule.g_groupdefaultanswer);


	SetDlgItemText(IDC_EDIT8,m_qqgrouprule.g_welcomestr);
((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(m_qqgrouprule.g_sessionanswerfalg);

CheckRadioButton(IDC_RADIO1,IDC_RADIO4,IDC_RADIO1+m_qqgrouprule.g_group_request_method);

	CEdit * pEdt = (CEdit*)GetDlgItem(IDC_EDIT10);//   
 pEdt->SetLimitText(36); 
	
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(m_qqgrouprule.g_allowallshutitup);

	

	((CButton*)GetDlgItem(IDC_CHECK6))->SetCheck(m_qqgrouprule.g_totalshutitup);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(m_qqgrouprule.g_checkin);
	((CButton*)GetDlgItem(IDC_CHECK11))->SetCheck(m_qqgrouprule.g_gamble);
((CButton*)GetDlgItem(IDC_CHECK19))->SetCheck(m_qqgrouprule.g_rob);

	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(m_qqgrouprule.g_talk);
((CButton*)GetDlgItem(IDC_CHECK18))->SetCheck(m_qqgrouprule.g_forbidden);
((CButton*)GetDlgItem(IDC_CHECK21))->SetCheck(m_qqgrouprule.g_onlyself);
	((CButton*)GetDlgItem(IDC_CHECK14))->SetCheck(m_qqgrouprule.g_privateadminanswer);
	((CButton*)GetDlgItem(IDC_CHECK15))->SetCheck(m_qqgrouprule.g_tipsotheradmin);
((CButton*)GetDlgItem(IDC_CHECK13))->SetCheck(m_qqgrouprule.g_publicanswer);
((CButton*)GetDlgItem(IDC_CHECK12))->SetCheck(m_qqgrouprule.g_allowallanswer);
((CButton*)GetDlgItem(IDC_CHECK16))->SetCheck(m_qqgrouprule.g_byprivate);
((CButton*)GetDlgItem(IDC_CHECK7))->SetCheck(m_qqgrouprule.g_includekey);
((CButton*)GetDlgItem(IDC_CHECK17))->SetCheck(m_qqgrouprule.g_speakaward);

((CButton*)GetDlgItem(IDC_CHECK20))->SetCheck(m_qqgrouprule.g_punishshua);

return true;
}
// CAdminList 消息处理程序
void CAdminList::OnEnKillfocusEdit8()
{
	CString oldstr=m_qqgrouprule.g_welcomestr;
	GetDlgItemText(IDC_EDIT8,m_qqgrouprule.g_welcomestr);
	if(oldstr!=m_qqgrouprule.g_welcomestr)
	InsertExternalData(m_qqgrouprule.g_welcomestr,m_qqgrouprule.lastwelcomestr);
	// TODO: 在此添加控件通知处理程序代码
}

void CAdminList::OnBnClickedRadio1()
{
m_qqgrouprule.g_group_request_method=0;
	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnBnClickedRadio2()
{
	m_qqgrouprule.g_group_request_method=1;
	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnBnClickedRadio3()
{
	m_qqgrouprule.g_group_request_method=2;
	// TODO: 在此添加控件通知处理程序代码
}
void CAdminList::OnBnClickedRadio4()
{
	m_qqgrouprule.g_group_request_method=3;
	// TODO: 在此添加控件通知处理程序代码
}

void CAdminList::OnEnKillfocusEdit13()
{

	GetDlgItemText(IDC_EDIT13,m_qqgrouprule.g_group_pincodestr);

	m_qqgrouprule.g_group_pincodestr.Replace(_T("http：//"), _T("http://"));
	m_qqgrouprule.g_group_pincodestr.Trim();
	// TODO: 在此添加控件通知处理程序代码
}

void CAdminList::OnEnKillfocusEdit10()
{
	GetDlgItemText(IDC_EDIT10,m_qqgrouprule.g_group_denyreason);
	m_qqgrouprule.g_group_denyreason.Trim();
	// TODO: 在此添加控件通知处理程序代码
}
void CAdminList::OnEnKillfocusEdit6()
{
	m_qqgrouprule.g_percent=GetDlgItemInt(IDC_EDIT6);
	// TODO: 在此添加控件通知处理程序代码
}

void CAdminList::OnEnKillfocusEdit7()
{
	
	/*if(!Isggged)
	{
	AfxMessageBox(_T("未注册版本版本功能受限，只能以空白为触发前缀。"));
	return;
	}
*/
	GetDlgItemText(IDC_EDIT7,m_qqgrouprule.g_prefixstr);
	m_qqgrouprule.g_prefixstr.Replace(_T(":"),_T("："));
	m_qqgrouprule.g_prefixstr.Replace(_T(","),_T("，"));
	m_qqgrouprule.g_prefixstr.Trim();
	// TODO: 在此添加控件通知处理程序代码
}
void CAdminList::OnEnKillfocusEdit11()
{

	if(qqgroupqun)
	{
//	AfxMessageBox(_T("未注册版本版本功能受限，只能以空白为默认回复。"));
//	return;
	}



	GetDlgItemText(IDC_EDIT11,m_qqgrouprule.g_groupdefaultanswer);
	// TODO: 在此添加控件通知处理程序代码
}
void CAdminList::OnEnKillfocusEdit16()
{
	m_qqgrouprule.g_timeover=GetDlgItemInt(IDC_EDIT16);
	// TODO: 在此添加控件通知处理程序代码
}

void CAdminList::OnEnKillfocusEdit14()
{
	GetDlgItemText(IDC_EDIT14,m_qqgrouprule.g_robotname);
	// TODO: 在此添加控件通知处理程序代码
}

void CAdminList::OnEnKillfocusEdit9()
{
//	if(!m_defaultflag&&qqgroupqun)
//	{
//		
//		if(m_onceflag==false)
//		{
//			m_onceflag=true;
//AfxMessageBox(_T("未注册版本功能受限，无法单独设置每个群的机器人管理员，你可以在默认群规里（软件主界面上点第二个菜单‘选项设置’-‘默认群规设置、群管名单’）添加你想设置的管理员qq！"));
//		}
//	SetDlgItemText(IDC_EDIT9,g_defaultqqgrouprule.g_adminliststr);
//	
//	return;
//	}
//
	GetDlgItemText(IDC_EDIT9,m_qqgrouprule.g_adminliststr);
	
	m_qqgrouprule.g_adminliststr.Replace(_T("；"),_T(";"));
m_qqgrouprule.g_adminliststr.Replace(_T("丨"),_T("|"));

if(!m_ownqqnumber.IsEmpty()&&m_qqgrouprule.g_adminliststr.Find(m_ownqqnumber)!=-1)
{
	MessageBox(_T("这里应该设置一个不同于机器人qq号的qq号，比如你自己常用的别的qq号，之后就可以用那个qq号在群里发指令来控制机器人qq!"),_T("这里应该设置一个不同于机器人qq号的qq号"),0);
	m_qqgrouprule.g_adminliststr.Replace(m_ownqqnumber,_T(""));
}
	int len=m_qqgrouprule.g_adminliststr.GetLength();
	if(len>0&&m_qqgrouprule.g_adminliststr.GetAt(len-1)!=';')
m_qqgrouprule.g_adminliststr+=_T(";");
	
	CStringvect adminvectemp;
			::function::getmytoken(m_qqgrouprule.g_adminliststr,';',adminvectemp);
			m_qqgrouprule.g_robotadminsset.clear();
			for(int i=0;i<adminvectemp.size();i++)
			{
				if(_ttoi64(adminvectemp[i]))
			m_qqgrouprule.g_robotadminsset.insert(_ttoi64(adminvectemp[i]));
			}

	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnBnClickedOk()
{
	OnOK();
	

}


void CAdminList::OnBnClickedCheck1()
{
	
	m_qqgrouprule.g_allowallshutitup=((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
}


void CAdminList::OnEnKillfocusEdit1()
{
	GetDlgItemText(IDC_EDIT1,m_qqgrouprule.g_blackliststr);
	m_qqgrouprule.g_blackliststr.Replace(_T("；"),_T(";"));
	int len=m_qqgrouprule.g_blackliststr.GetLength();
	if(len>0&&m_qqgrouprule.g_blackliststr.GetAt(len-1)!=';')
m_qqgrouprule.g_blackliststr+=_T(";");

	CStringvect vectemp;
	m_qqgrouprule.g_blacklist.clear();
	if(!m_qqgrouprule.g_blackliststr.IsEmpty())
	{
	::function::getmytoken(m_qqgrouprule.g_blackliststr,';',vectemp);
	for(int i=0;i<vectemp.size();i++)
	{
		if(_ttoi64(vectemp[i]))
	m_qqgrouprule.g_blacklist.insert(_ttoi64(vectemp[i]));
	}
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnBnClickedCheck3()
{
	m_qqgrouprule.g_sessionanswerfalg=((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnBnClickedCheck6()
{
	m_qqgrouprule.g_totalshutitup=((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck();
	
	// TODO: 在此添加控件通知处理程序代码
}




void CAdminList::OnBnClickedCheck11()
{
	m_qqgrouprule.g_gamble=((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck();
	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnBnClickedCheck2()
{
	m_qqgrouprule.g_checkin=((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	// TODO: 在此添加控件通知处理程序代码
}
void CAdminList::OnBnClickedCheck4()
{
	m_qqgrouprule.g_talk=((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
	// TODO: 在此添加控件通知处理程序代码
}





void CAdminList::OnBnClickedButton1()
{	
	
	CReadAUStdioFile* m_autoreplyfile;
CKeepStrStrVectMap* m_autoreplymap;
	CReadAUStdioFile* m_privilegeautoreplyfile;
CKeepStrStrVectMap* m_privilegeautoreplymap;

	INT64 m_realgroupnumber=m_qqgrouprule.m_selfrealqqgroupnum;
	if(m_realgroupnumber)
	{
	OpenSingleReplyFile(m_realgroupnumber);

		m_autoreplyfile=GRealFilemap[m_realgroupnumber];
		
	m_autoreplymap=GRealReplymap[m_realgroupnumber];

		m_privilegeautoreplyfile=GPrivilegeRealFilemap[m_realgroupnumber];
		
	m_privilegeautoreplymap=GPrivilegeRealReplymap[m_realgroupnumber];
	}
	else
	{
	m_autoreplyfile=&g_autoreplyfile1;
	m_autoreplymap=&g_autoreplymap;
m_privilegeautoreplyfile=&g_Privilegeautoreplyfile1;
	m_privilegeautoreplymap=&g_Privilegeautoreplymap;


	}


	CModifyTitle dlg(*m_autoreplymap,*m_autoreplyfile,*m_privilegeautoreplymap,*m_privilegeautoreplyfile,this);
dlg.DoModal();
	//CReadAUStdioFile* m_autoreplyfile;
	//GRealFilemap.Lookup(m_qqgrouprule.m_selfrealqqgroupnum)
	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnBnClickedCheck9()
{
	m_qqgrouprule.g_continuefind=((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck();
}


void CAdminList::OnBnClickedCheck7()
{

	m_qqgrouprule.g_includekey=((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck();

	if(m_qqgrouprule.g_includekey)
	{
		if(IDOK==MessageBox(_T("除非你机器人主要就是为了回答特定的问题，否则强烈建议不要勾选此项，很容易导致各个自定义小游戏产生冲突，自动回复和优先回复都可以用“*你好*”，“你好*”，甚至正则表达式来替换这个只要包含关键词就回复的功能，正常情况下，不需要勾选此项。"),_T("是否确认包含关键词即回复"),MB_OKCANCEL))
		{
		
		}
		else
		{
		m_qqgrouprule.g_includekey=false;
		((CButton*)GetDlgItem(IDC_CHECK7))->SetCheck(0);
		}
	}
}


void CAdminList::OnBnClickedCheck14()
{
	m_qqgrouprule.g_privateadminanswer=((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();
}


void CAdminList::OnBnClickedCheck15()
{
		m_qqgrouprule.g_tipsotheradmin=((CButton*)GetDlgItem(IDC_CHECK15))->GetCheck();

}


void CAdminList::OnBnClickedCheck13()
{
		m_qqgrouprule.g_publicanswer=((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck();

}


void CAdminList::OnBnClickedCheck12()
{
		m_qqgrouprule.g_allowallanswer=((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck();

}


void CAdminList::OnBnClickedCheck16()
{
	m_qqgrouprule.g_byprivate=((CButton*)GetDlgItem(IDC_CHECK16))->GetCheck();
}


void CAdminList::OnBnClickedCheck17()
{
	m_qqgrouprule.g_speakaward=((CButton*)GetDlgItem(IDC_CHECK17))->GetCheck();

}


void CAdminList::OnEnKillfocusEdit18()
{
	int lastautotime=m_qqgrouprule.g_autonoticetime;
	m_qqgrouprule.g_autonoticetime=GetDlgItemInt(IDC_EDIT18);
	if(lastautotime==m_qqgrouprule.g_autonoticetime)
		return;
	INT64 guin=GetGUinFromRealGroupqqNum(m_qqgrouprule.m_selfrealqqgroupnum);
	CMsgDlg* tempmsgdlg;
	BOOL bfind=false;
	lockqqmsgdlgres.Lock();
	bfind=m_mapqqmsgdlg.Lookup(guin,tempmsgdlg);
	
	if(bfind)
	{
	
	if(m_qqgrouprule.g_autonoticetime)
	{

	tempmsgdlg->SendMessage(WM_TIMENOTICE,(WPARAM)1,(LPARAM)(m_qqgrouprule).g_autonoticetime);

	}
	else
	{
	tempmsgdlg->SendMessage(WM_TIMENOTICE,(WPARAM)0,(LPARAM)(m_qqgrouprule).g_autonoticetime);

	}


	}
lockqqmsgdlgres.Unlock();
}


void CAdminList::OnEnKillfocusEdit17()
{
	GetDlgItemText(IDC_EDIT17,m_qqgrouprule.g_hellowstr);
	
	
}


void CAdminList::OnEnKillfocusEdit19()
{
		m_qqgrouprule.g_scale=GetDlgItemInt(IDC_EDIT19);
		if(Isggged)
m_qqgrouprule.g_scale=min(MAXSCORE,m_qqgrouprule.g_scale);
	else
	{
		AfxMessageBox(_T("未注册版受限制，最高数值不能超过20"));

m_qqgrouprule.g_scale=min(20,m_qqgrouprule.g_scale);
	}
}


void CAdminList::OnEnKillfocusEdit20()
{
GetDlgItemText(IDC_EDIT20,m_qqgrouprule.g_tradegrouplist);
	
	m_qqgrouprule.g_tradegrouplist.Replace(_T("；"),_T(";"));
		int len=m_qqgrouprule.g_tradegrouplist.GetLength();
	if(len>0&&m_qqgrouprule.g_tradegrouplist.GetAt(len-1)!=';')
m_qqgrouprule.g_tradegrouplist+=_T(";");

	CStringvect vectemp;
	m_qqgrouprule.g_tradelist.clear();
	if(!m_qqgrouprule.g_tradegrouplist.IsEmpty())
	{
	::function::getmytoken(m_qqgrouprule.g_tradegrouplist,';',vectemp);
	for(int i=0;i<vectemp.size();i++)
	{
	m_qqgrouprule.g_tradelist.insert(_ttoi64(vectemp[i]));
	}
	}

}


void CAdminList::OnEnKillfocusEdit21()
{
		m_qqgrouprule.g_checkperiod=GetDlgItemInt(IDC_EDIT21);
	
}


void CAdminList::OnEnKillfocusEdit22()
{
GetDlgItemText(IDC_EDIT22,m_qqgrouprule.g_ranktitlestr);
	
}


void CAdminList::OnEnKillfocusEdit23()
{
GetDlgItemText(IDC_EDIT23,m_qqgrouprule.g_banliststr);
	m_qqgrouprule.g_banliststr.Replace(_T("；"),_T(";"));
	m_qqgrouprule.g_banliststr.Replace(_T("|"),_T(";"));

	int len=m_qqgrouprule.g_banliststr.GetLength();
	if(len>0&&m_qqgrouprule.g_banliststr.GetAt(len-1)!=';')
m_qqgrouprule.g_banliststr+=_T(";");

	CStringvect vectemp;
	m_qqgrouprule.g_banlist.clear();
	if(!m_qqgrouprule.g_banliststr.IsEmpty())
	{
	::function::getmytoken(m_qqgrouprule.g_banliststr,';',vectemp);
	
	for(int i=0;i<vectemp.size();i++)
	{
		if(vectemp[i]!=_T(" "))
		m_qqgrouprule.g_banlist.push_back(vectemp[i]);
	}
	}
	
}


void CAdminList::OnBnClickedCheck19()
{
		m_qqgrouprule.g_rob=((CButton*)GetDlgItem(IDC_CHECK19))->GetCheck();
}


void CAdminList::OnBnClickedCheck18()
{
	m_qqgrouprule.g_forbidden=((CButton*)GetDlgItem(IDC_CHECK18))->GetCheck();
}


void CAdminList::OnEnKillfocusEdit24()
{
	m_qqgrouprule.g_gamblerobtimes=GetDlgItemInt(IDC_EDIT24);

			if(Isggged)
m_qqgrouprule.g_gamblerobtimes=min(MAXSCORE,m_qqgrouprule.g_gamblerobtimes);
	else
	{
		if(m_qqgrouprule.g_gamblerobtimes>50)
		AfxMessageBox(_T("未注册版受限制，最高数值不能超过50"));

m_qqgrouprule.g_gamblerobtimes=min(50,m_qqgrouprule.g_gamblerobtimes);
	}

	// TODO: 在此添加控件通知处理程序代码
}


void CAdminList::OnEnKillfocusEdit25()
{
	
	GetDlgItemText(IDC_EDIT25,m_qqgrouprule.g_forwordkeyliststr);
	m_qqgrouprule.g_forwordkeyliststr.Replace(_T("；"),_T(";"));
		int len=m_qqgrouprule.g_forwordkeyliststr.GetLength();
	if(len>0&&m_qqgrouprule.g_forwordkeyliststr.GetAt(len-1)!=';')
m_qqgrouprule.g_forwordkeyliststr+=_T(";");

	CStringvect vectemp;
	m_qqgrouprule.g_forwordkeylist.clear();

	if(!m_qqgrouprule.g_forwordkeyliststr.IsEmpty())
	{
	::function::getmytoken(m_qqgrouprule.g_forwordkeyliststr,';',vectemp);
	for(int i=0;i<vectemp.size();i++)
	{
		
	m_qqgrouprule.g_forwordkeylist.push_back(vectemp[i]);
	}
	}
}


void CAdminList::OnBnClickedCheck20()
{	
	m_qqgrouprule.g_punishshua=((CButton*)GetDlgItem(IDC_CHECK20))->GetCheck();

	
}


void CAdminList::OnBnClickedCheck21()
{
	m_qqgrouprule.g_onlyself=((CButton*)GetDlgItem(IDC_CHECK21))->GetCheck();// TODO: 在此添加控件通知处理程序代码
}





void CAdminList::OnEnKillfocusEdit28()
{

GetDlgItemText(IDC_EDIT28,m_qqgrouprule.g_storeprice);


	INT64 guin=GetGUinFromRealGroupqqNum(m_qqgrouprule.m_selfrealqqgroupnum);
	CMsgDlg* tempmsgdlg;
	lockqqmsgdlgres.Lock();
	if(m_mapqqmsgdlg.Lookup(guin,tempmsgdlg))
	{
	
	if(m_qqgrouprule.g_autonoticetime)
	{

	tempmsgdlg->SendMessage(WM_UPDATESTORE,0,0);

	}
	else
	{
	tempmsgdlg->SendMessage(WM_UPDATESTORE,0,0);

	}
	}
	lockqqmsgdlgres.Unlock();

}


void CAdminList::OnEnKillfocusEdit29()
{
	GetDlgItemText(IDC_EDIT29,m_qqgrouprule.g_coinname);
}


void CAdminList::OnBnClickedButton2()
{
	CMoreAdminList dlg(m_qqgrouprule);
	dlg.DoModal();
	
}


void CAdminList::OnEnKillfocusEdit41()
{

	if(!Isggged)
	{
	//AfxMessageBox(_T("请注意，未注册版本不能执行定时任务！"));
	
	}
GetDlgItemText(IDC_EDIT41,m_qqgrouprule.timetask);


}




void CAdminList::OnEnKillfocusEdit42()
{
		GetDlgItemText(IDC_EDIT42,m_qqgrouprule.g_vipliststr);
	m_qqgrouprule.g_vipliststr.Replace(_T("；"),_T(";"));
		int len=m_qqgrouprule.g_vipliststr.GetLength();
	if(len>0&&m_qqgrouprule.g_vipliststr.GetAt(len-1)!=';')
m_qqgrouprule.g_vipliststr+=_T(";");

	CStringvect vectemp;
	m_qqgrouprule.g_viplist.clear();
	if(!m_qqgrouprule.g_vipliststr.IsEmpty())
	{
	::function::getmytoken(m_qqgrouprule.g_vipliststr,';',vectemp);
	for(int i=0;i<vectemp.size();i++)
	{
		if(_ttoi64(vectemp[i]))
	m_qqgrouprule.g_viplist.insert(_ttoi64(vectemp[i]));
	}
	}

}


void CAdminList::OnBnClickedButton3()
{

	m_qqgrouprule.g_storeprice=default_g_storeprice;
SetDlgItemText(IDC_EDIT28,m_qqgrouprule.g_storeprice);

}


void CAdminList::OnEnKillfocusEdit49()
{
		
m_qqgrouprule.m_tax_percent=GetDlgItemInt(IDC_EDIT49);

}


void CAdminList::OnEnKillfocusEdit50()
{
	m_qqgrouprule.m_dropequipscale=GetDlgItemInt(IDC_EDIT50);
	if(m_qqgrouprule.m_dropequipscale<0||m_qqgrouprule.m_dropequipscale>10000)
	{
	AfxMessageBox(_T("掉装备和叛逃概率系数有效值在0和10000之间！"));
	}
	
			m_qqgrouprule.m_dropequipscale=max(0,m_qqgrouprule.m_dropequipscale);
	m_qqgrouprule.m_dropequipscale=min(10000,m_qqgrouprule.m_dropequipscale);
	SetDlgItemInt(IDC_EDIT50,m_qqgrouprule.m_dropequipscale);

}


void CAdminList::OnEnKillfocusEdit32()
{
	m_qqgrouprule.g_group_pinqqlevel=GetDlgItemInt(IDC_EDIT32);
}


void CAdminList::OnEnKillfocusEdit33()
{
	m_qqgrouprule.g_group_pinqqdarenlevel=GetDlgItemInt(IDC_EDIT33);
}
