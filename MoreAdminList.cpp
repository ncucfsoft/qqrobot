// AdminList.cpp : 实现文件
//

#include "stdafx.h"
#include "MoreAdminList.h"
//#include "afxdialogex.h"


// CMoreAdminList 对话框

IMPLEMENT_DYNAMIC(CMoreAdminList, CDialog)

CMoreAdminList::CMoreAdminList(qqgrouprule& temprule,CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CMoreAdminList::IDD, pParent),m_qqgrouprule(temprule)
{
	if(&m_qqgrouprule==&g_defaultqqgrouprule)
	m_defaultflag=true;
	else
	m_defaultflag=false;
	bNomultLanguage=true;
}

CMoreAdminList::~CMoreAdminList()
{
}

void CMoreAdminList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
LRESULT CMoreAdminList::OnNcHitTest(CPoint point)
{
	  CRect rc;
           GetClientRect(&rc);
           ClientToScreen(&rc);
           return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);   //鼠标如果在客户区，将其当作标题栏
}

BEGIN_MESSAGE_MAP(CMoreAdminList, CDialog)
	ON_WM_NCHITTEST()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_CHECK1, &CMoreAdminList::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMoreAdminList::OnBnClickedCheck2)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CMoreAdminList::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, &CMoreAdminList::OnEnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT3, &CMoreAdminList::OnEnKillfocusEdit3)
	ON_EN_KILLFOCUS(IDC_EDIT4, &CMoreAdminList::OnEnKillfocusEdit4)
	ON_EN_KILLFOCUS(IDC_EDIT5, &CMoreAdminList::OnEnKillfocusEdit5)
	ON_EN_KILLFOCUS(IDC_EDIT6, &CMoreAdminList::OnEnKillfocusEdit6)
	ON_EN_KILLFOCUS(IDC_EDIT7, &CMoreAdminList::OnEnKillfocusEdit7)

	ON_BN_CLICKED(IDC_CHECK8, &CMoreAdminList::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK22, &CMoreAdminList::OnBnClickedCheck22)
	ON_EN_KILLFOCUS(IDC_EDIT26, &CMoreAdminList::OnEnKillfocusEdit26)
	ON_EN_KILLFOCUS(IDC_EDIT9, &CMoreAdminList::OnEnKillfocusEdit9)
	ON_EN_KILLFOCUS(IDC_EDIT10, &CMoreAdminList::OnEnKillfocusEdit10)
	ON_EN_KILLFOCUS(IDC_EDIT13, &CMoreAdminList::OnEnKillfocusEdit13)
	ON_EN_KILLFOCUS(IDC_EDIT11, &CMoreAdminList::OnEnKillfocusEdit11)
	ON_EN_KILLFOCUS(IDC_EDIT32, &CMoreAdminList::OnEnKillfocusEdit32)
	ON_EN_KILLFOCUS(IDC_EDIT30, &CMoreAdminList::OnEnKillfocusEdit30)
	ON_EN_KILLFOCUS(IDC_EDIT31, &CMoreAdminList::OnEnKillfocusEdit31)
	ON_EN_KILLFOCUS(IDC_EDIT33, &CMoreAdminList::OnEnKillfocusEdit33)
	ON_EN_KILLFOCUS(IDC_EDIT34, &CMoreAdminList::OnEnKillfocusEdit34)
	ON_EN_KILLFOCUS(IDC_EDIT35, &CMoreAdminList::OnEnKillfocusEdit35)
	ON_EN_KILLFOCUS(IDC_EDIT36, &CMoreAdminList::OnEnKillfocusEdit36)
	ON_EN_KILLFOCUS(IDC_EDIT37, &CMoreAdminList::OnEnKillfocusEdit37)
	ON_EN_KILLFOCUS(IDC_EDIT38, &CMoreAdminList::OnEnKillfocusEdit38)
	ON_EN_KILLFOCUS(IDC_EDIT39, &CMoreAdminList::OnEnKillfocusEdit39)
	ON_EN_KILLFOCUS(IDC_EDIT40, &CMoreAdminList::OnEnKillfocusEdit40)
	ON_BN_CLICKED(IDC_CHECK23, &CMoreAdminList::OnBnClickedCheck23)
	ON_BN_CLICKED(IDC_CHECK24, &CMoreAdminList::OnBnClickedCheck24)
	ON_BN_CLICKED(IDC_CHECK30, &CMoreAdminList::OnBnClickedCheck30)
	ON_EN_KILLFOCUS(IDC_EDIT45, &CMoreAdminList::OnEnKillfocusEdit45)
	ON_EN_KILLFOCUS(IDC_EDIT51, &CMoreAdminList::OnEnKillfocusEdit51)
	ON_BN_CLICKED(IDC_CHECK31, &CMoreAdminList::OnBnClickedCheck31)
	ON_BN_CLICKED(IDC_CHECK32, &CMoreAdminList::OnBnClickedCheck32)
	ON_EN_KILLFOCUS(IDC_EDIT52, &CMoreAdminList::OnEnKillfocusEdit52)
	ON_BN_CLICKED(IDC_CHECK33, &CMoreAdminList::OnBnClickedCheck33)
	ON_EN_KILLFOCUS(IDC_EDIT53, &CMoreAdminList::OnEnKillfocusEdit53)
	ON_EN_KILLFOCUS(IDC_EDIT55, &CMoreAdminList::OnEnKillfocusEdit55)
	ON_EN_KILLFOCUS(IDC_EDIT56, &CMoreAdminList::OnEnKillfocusEdit56)
	ON_EN_KILLFOCUS(IDC_EDIT57, &CMoreAdminList::OnEnKillfocusEdit57)
	ON_EN_KILLFOCUS(IDC_EDIT58, &CMoreAdminList::OnEnKillfocusEdit58)
	ON_EN_KILLFOCUS(IDC_EDIT48, &CMoreAdminList::OnEnKillfocusEdit48)
	ON_EN_KILLFOCUS(IDC_EDIT54, &CMoreAdminList::OnEnKillfocusEdit54)
	ON_EN_KILLFOCUS(IDC_EDIT59, &CMoreAdminList::OnEnKillfocusEdit59)
	ON_BN_CLICKED(IDC_CHECK34, &CMoreAdminList::OnBnClickedCheck34)
	ON_BN_CLICKED(IDC_CHECK35, &CMoreAdminList::OnBnClickedCheck35)
	ON_EN_KILLFOCUS(IDC_EDIT60, &CMoreAdminList::OnEnKillfocusEdit60)
	ON_EN_KILLFOCUS(IDC_EDIT61, &CMoreAdminList::OnEnKillfocusEdit61)
	ON_CBN_KILLFOCUS(IDC_COMBO6, &CMoreAdminList::OnCbnKillfocusCombo6)
	ON_CBN_KILLFOCUS(IDC_COMBO7, &CMoreAdminList::OnCbnKillfocusCombo7)
	ON_EN_KILLFOCUS(IDC_EDIT62, &CMoreAdminList::OnEnKillfocusEdit62)
	ON_EN_KILLFOCUS(IDC_EDIT63, &CMoreAdminList::OnEnKillfocusEdit63)
	ON_EN_KILLFOCUS(IDC_EDIT64, &CMoreAdminList::OnEnKillfocusEdit64)
END_MESSAGE_MAP()
void CMoreAdminList::OnBnClickedCheck1()
{
	
	m_qqgrouprule.g_queryfun=((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
}

void CMoreAdminList::OnBnClickedCheck2()
{
	
	m_qqgrouprule.g_idiomfun=((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
}

void CMoreAdminList::OnEnKillfocusEdit1()
{
	m_qqgrouprule.g_scale_idiom=GetDlgItemInt(IDC_EDIT1);

	if(Isggged)
m_qqgrouprule.g_scale_idiom=min(MAXSCORE,m_qqgrouprule.g_scale_idiom);
	else
		{
			AfxMessageBox(_T("未注册版受限制，最高数值不能超过20"));
m_qqgrouprule.g_scale_idiom=min(20,m_qqgrouprule.g_scale_idiom);
	}
	// TODO: 在此添加控件通知处理程序代码
}
void CMoreAdminList::OnEnKillfocusEdit2()
{
	

	m_qqgrouprule.g_scale_rush=GetDlgItemInt(IDC_EDIT2);
	
	
	if(Isggged)
m_qqgrouprule.g_scale_rush=min(MAXSCORE,m_qqgrouprule.g_scale_rush);
	else
	{
		AfxMessageBox(_T("未注册版受限制，最高数值不能超过20"));
m_qqgrouprule.g_scale_rush=min(20,m_qqgrouprule.g_scale_rush);
	}
	// TODO: 在此添加控件通知处理程序代码
}
void CMoreAdminList::OnEnKillfocusEdit3()
{
	m_qqgrouprule.g_scale_crazy=GetDlgItemInt(IDC_EDIT3);
	// TODO: 在此添加控件通知处理程序代码
}
void CMoreAdminList::OnEnKillfocusEdit4()
{
	m_qqgrouprule.g_times_crazy=GetDlgItemInt(IDC_EDIT4);
	// TODO: 在此添加控件通知处理程序代码
}
void CMoreAdminList::OnEnKillfocusEdit5()
{
	m_qqgrouprule.g_nperson_rush=GetDlgItemInt(IDC_EDIT5);
	// TODO: 在此添加控件通知处理程序代码
}
void CMoreAdminList::OnEnKillfocusEdit6()
{
	m_qqgrouprule.g_timeout_idiom=GetDlgItemInt(IDC_EDIT6);
	
	// TODO: 在此添加控件通知处理程序代码
}
void CMoreAdminList::OnEnKillfocusEdit7()
{
	m_qqgrouprule.g_timeout_rush=GetDlgItemInt(IDC_EDIT7);
	
	if(!Isggged&&m_qqgrouprule.g_timeout_rush%10==6)
	{
		AfxMessageBox(_T("未注册版不能设置为尾数为6的模式。"));
m_qqgrouprule.g_timeout_rush=m_qqgrouprule.g_timeout_rush-1;
	}
	// TODO: 在此添加控件通知处理程序代码
}



BOOL CMoreAdminList::OnInitDialog()
{
	CMyBGCDlg::OnInitDialog();

	
	INT64 falsegroupuin=GetGUinFromRealGroupqqNum(m_qqgrouprule.m_selfrealqqgroupnum);
	if(falsegroupuin)
	{
	CString nicknamestr;
	GidNickNamemap.Lookup(falsegroupuin,nicknamestr);
nicknamestr+=_T("——更多群规设置——群名片、赌博、打劫、彩票等各项娱乐积分消耗设置");
	SetWindowText(nicknamestr);
	}
		else
SetWindowText(_T("更多群规设置——群名片、赌博、打劫、彩票等各项娱乐积分消耗设置——关闭窗口才能使设置生效"));

SetDlgItemInt(IDC_EDIT1,m_qqgrouprule.g_scale_idiom);
SetDlgItemInt(IDC_EDIT2,m_qqgrouprule.g_scale_rush);
SetDlgItemInt(IDC_EDIT3,m_qqgrouprule.g_scale_crazy);
SetDlgItemInt(IDC_EDIT4,m_qqgrouprule.g_times_crazy);
SetDlgItemInt(IDC_EDIT5,m_qqgrouprule.g_nperson_rush);
SetDlgItemInt(IDC_EDIT26,m_qqgrouprule.g_idiom_cost);
SetDlgItemInt(IDC_EDIT9,m_qqgrouprule.g_gamble_cost);
SetDlgItemInt(IDC_EDIT10,m_qqgrouprule.g_rob_cost);
SetDlgItemInt(IDC_EDIT11,m_qqgrouprule.g_rush_punish_cost);


TCHAR belowstr[32];
_i64tot(m_qqgrouprule.belowscore,belowstr,10);
	SetDlgItemText(IDC_EDIT32,belowstr);

	
//SetDlgItemInt(IDC_EDIT32,m_qqgrouprule.belowscore);
SetDlgItemInt(IDC_EDIT30,m_qqgrouprule.spamtimes);
SetDlgItemText(IDC_EDIT31,m_qqgrouprule.kickspamtips);


CString tempfmtstr;
tempfmtstr.Format(_T("%I64d"),m_qqgrouprule.robneedLowestRankNum);
SetDlgItemText(IDC_EDIT55,tempfmtstr);
SetDlgItemInt(IDC_EDIT56,m_qqgrouprule.robneedwaitTime);
SetDlgItemInt(IDC_EDIT57,m_qqgrouprule.initscore);
SetDlgItemInt(IDC_EDIT58,m_qqgrouprule.paybackscale);
SetDlgItemInt(IDC_EDIT48,m_qqgrouprule.gamblehardscale);
SetDlgItemInt(IDC_EDIT54,m_qqgrouprule.bidwaittime);
SetDlgItemInt(IDC_EDIT59,m_qqgrouprule.bidbacknum);


tempfmtstr.Format(_T("%I64d"),m_qqgrouprule.gambletopvalue);
SetDlgItemText(IDC_EDIT33,tempfmtstr);
SetDlgItemInt(IDC_EDIT34,m_qqgrouprule.adminawardtop);
SetDlgItemText(IDC_EDIT35,m_qqgrouprule.precardstr);
SetDlgItemText(IDC_EDIT36,m_qqgrouprule.femaleprecardstr);
SetDlgItemText(IDC_EDIT60,m_qqgrouprule.nnnnprecardstr);
SetDlgItemText(IDC_EDIT62,m_qqgrouprule.adminprecardstr);
SetDlgItemText(IDC_EDIT63,m_qqgrouprule.m_modifycardurl);
SetDlgItemInt(IDC_EDIT37,m_qqgrouprule.lotteryprice);
SetDlgItemInt(IDC_EDIT39,m_qqgrouprule.repeatcheckfine);
SetDlgItemInt(IDC_EDIT40,m_qqgrouprule.luckynumbercost);
SetDlgItemInt(IDC_EDIT45,m_qqgrouprule.guesspsrcost);
SetDlgItemInt(IDC_EDIT52,m_qqgrouprule.likevalue);
SetDlgItemInt(IDC_EDIT53,m_qqgrouprule.probationminutes);

SetDlgItemInt(IDC_EDIT64,m_qqgrouprule.maxreplywithinmin);
SetDlgItemInt(IDC_EDIT61,m_qqgrouprule.minutes_mustdosomething);
((CComboBox*)GetDlgItem(IDC_COMBO6))->SetCurSel(m_qqgrouprule.action_mustdowhat);
((CComboBox*)GetDlgItem(IDC_COMBO7))->SetCurSel(m_qqgrouprule.punish_otherwise);

SetDlgItemText(IDC_EDIT38,m_qqgrouprule.lotteryopentime);
SetDlgItemText(IDC_EDIT51,m_qqgrouprule.rushprefixstr);
SetDlgItemInt(IDC_EDIT13,m_qqgrouprule.g_query_cost);
SetDlgItemInt(IDC_EDIT6,m_qqgrouprule.g_timeout_idiom);
SetDlgItemInt(IDC_EDIT7,m_qqgrouprule.g_timeout_rush);

((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(m_qqgrouprule.g_queryfun);
((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(m_qqgrouprule.g_idiomfun);
((CButton*)GetDlgItem(IDC_CHECK23))->SetCheck(m_qqgrouprule.g_rushfun);
((CButton*)GetDlgItem(IDC_CHECK24))->SetCheck(m_qqgrouprule.g_guessfun);
((CButton*)GetDlgItem(IDC_CHECK30))->SetCheck(m_qqgrouprule.g_guesspsrock);
((CButton*)GetDlgItem(IDC_CHECK31))->SetCheck(m_qqgrouprule.m_forbidprivate);
((CButton*)GetDlgItem(IDC_CHECK32))->SetCheck(m_qqgrouprule.m_rankwithlike);
((CButton*)GetDlgItem(IDC_CHECK33))->SetCheck(m_qqgrouprule.hatemustover);
((CButton*)GetDlgItem(IDC_CHECK8))->SetCheck(m_qqgrouprule.forbidadminset);
((CButton*)GetDlgItem(IDC_CHECK22))->SetCheck(m_qqgrouprule.bShowkindstips);
((CButton*)GetDlgItem(IDC_CHECK34))->SetCheck(m_qqgrouprule.bTatalSlient);
((CButton*)GetDlgItem(IDC_CHECK35))->SetCheck(m_qqgrouprule.bOpenSelfDefGame);


return true;
}
// CMoreAdminList 消息处理程序

void CMoreAdminList::OnBnClickedCheck8()
{

m_qqgrouprule.forbidadminset=((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck();
}


void CMoreAdminList::OnBnClickedCheck22()
{
	m_qqgrouprule.bShowkindstips=((CButton*)GetDlgItem(IDC_CHECK22))->GetCheck();
}


void CMoreAdminList::OnEnKillfocusEdit26()
{
	m_qqgrouprule.g_idiom_cost=GetDlgItemInt(IDC_EDIT26);
}


void CMoreAdminList::OnEnKillfocusEdit9()
{
	m_qqgrouprule.g_gamble_cost=GetDlgItemInt(IDC_EDIT9);

}


void CMoreAdminList::OnEnKillfocusEdit10()
{
m_qqgrouprule.g_rob_cost=GetDlgItemInt(IDC_EDIT10);
}


void CMoreAdminList::OnEnKillfocusEdit13()
{
m_qqgrouprule.g_query_cost=GetDlgItemInt(IDC_EDIT13);
}


void CMoreAdminList::OnEnKillfocusEdit11()
{
m_qqgrouprule.g_rush_punish_cost=GetDlgItemInt(IDC_EDIT11);
	// TODO: 在此添加控件通知处理程序代码
}


void CMoreAdminList::OnEnKillfocusEdit32()
{
	CString str;
	GetDlgItemText(IDC_EDIT32,str);
	m_qqgrouprule.belowscore=_ttoi64(str);
	
//GetDlgItemInt(IDC_EDIT32);
}


void CMoreAdminList::OnEnKillfocusEdit30()
{
m_qqgrouprule.spamtimes=GetDlgItemInt(IDC_EDIT30);
}

int CMoreAdminList::GetDlgItemInt(int nID)
{
	CString str;
	GetDlgItemText(nID,str);
	INT64 dd=_ttoi64(str);
	if(dd>21*10000*10000)
	return 	21*10000*10000;
	else
		return (int)dd;
}
void CMoreAdminList::OnEnKillfocusEdit31()
{
GetDlgItemText(IDC_EDIT31,m_qqgrouprule.kickspamtips);
}


void CMoreAdminList::OnEnKillfocusEdit33()
{
	CString str;
	GetDlgItemText(IDC_EDIT33,str);
	m_qqgrouprule.gambletopvalue=_ttoi64(str);
}


void CMoreAdminList::OnEnKillfocusEdit34()
{
	CString str;
	GetDlgItemText(IDC_EDIT34,str);
	m_qqgrouprule.adminawardtop=_ttoi64(str);
		if(!Isggged)
		{
		AfxMessageBox(_T("未注册版受限制，最高数值不能超过2000"));

//m_qqgrouprule.adminawardtop=min(2000,m_qqgrouprule.adminawardtop);
	}
		m_qqgrouprule.adminawardtop=min(MAXSCORE,m_qqgrouprule.adminawardtop);

}


void CMoreAdminList::OnEnKillfocusEdit35()
{
	GetDlgItemText(IDC_EDIT35,m_qqgrouprule.precardstr);
}


void CMoreAdminList::OnEnKillfocusEdit36()
{
	GetDlgItemText(IDC_EDIT36,m_qqgrouprule.femaleprecardstr);
}


void CMoreAdminList::OnEnKillfocusEdit37()
{
	m_qqgrouprule.lotteryprice=GetDlgItemInt(IDC_EDIT37);
}


void CMoreAdminList::OnEnKillfocusEdit38()
{
	GetDlgItemText(IDC_EDIT38,m_qqgrouprule.lotteryopentime);
	m_qqgrouprule.lotteryopentime.Trim();
}


void CMoreAdminList::OnEnKillfocusEdit39()
{
m_qqgrouprule.repeatcheckfine=GetDlgItemInt(IDC_EDIT39);
}


void CMoreAdminList::OnEnKillfocusEdit40()
{
	m_qqgrouprule.luckynumbercost=GetDlgItemInt(IDC_EDIT40);
}


void CMoreAdminList::OnBnClickedCheck23()
{
	m_qqgrouprule.g_rushfun=((CButton*)GetDlgItem(IDC_CHECK23))->GetCheck();
}


void CMoreAdminList::OnBnClickedCheck24()
{
		m_qqgrouprule.g_guessfun=((CButton*)GetDlgItem(IDC_CHECK24))->GetCheck();

}


void CMoreAdminList::OnBnClickedCheck30()
{
	m_qqgrouprule.g_guesspsrock=((CButton*)GetDlgItem(IDC_CHECK30))->GetCheck();

}


void CMoreAdminList::OnEnKillfocusEdit45()
{
	m_qqgrouprule.guesspsrcost=GetDlgItemInt(IDC_EDIT45);
}


void CMoreAdminList::OnEnKillfocusEdit51()
{
	GetDlgItemText(IDC_EDIT51,m_qqgrouprule.rushprefixstr);
}


void CMoreAdminList::OnBnClickedCheck31()
{
	m_qqgrouprule.m_forbidprivate=((CButton*)GetDlgItem(IDC_CHECK31))->GetCheck();
}


void CMoreAdminList::OnBnClickedCheck32()
{
	m_qqgrouprule.m_rankwithlike=((CButton*)GetDlgItem(IDC_CHECK32))->GetCheck();
}


void CMoreAdminList::OnEnKillfocusEdit52()
{
	m_qqgrouprule.likevalue=GetDlgItemInt(IDC_EDIT52);
	
}


void CMoreAdminList::OnBnClickedCheck33()
{
	m_qqgrouprule.hatemustover=((CButton*)GetDlgItem(IDC_CHECK33))->GetCheck();
	
}


void CMoreAdminList::OnEnKillfocusEdit53()
{
	m_qqgrouprule.probationminutes=GetDlgItemInt(IDC_EDIT53);

//m_qqgrouprule.probationminutes=min(9999,m_qqgrouprule.probationminutes);

}


void CMoreAdminList::OnEnKillfocusEdit55()
{
	CString tempstr;
	GetDlgItemText(IDC_EDIT55,tempstr);
m_qqgrouprule.robneedLowestRankNum=_ttoi64(tempstr);
}


void CMoreAdminList::OnEnKillfocusEdit56()
{
	CString tempstr;
	GetDlgItemText(IDC_EDIT56,tempstr);
m_qqgrouprule.robneedwaitTime=_ttoi64(tempstr);
}


void CMoreAdminList::OnEnKillfocusEdit57()
{
	CString tempstr;
	GetDlgItemText(IDC_EDIT57,tempstr);
m_qqgrouprule.initscore=_ttoi64(tempstr);

	if(Isggged)
m_qqgrouprule.initscore=min(MAXSCORE,m_qqgrouprule.initscore);
	else
	{
		AfxMessageBox(_T("未注册版受限制，最高数值不能超过20"));

m_qqgrouprule.initscore=min(20,m_qqgrouprule.initscore);
	}
}


void CMoreAdminList::OnEnKillfocusEdit58()
{
	CString tempstr;
	GetDlgItemText(IDC_EDIT58,tempstr);
m_qqgrouprule.paybackscale=_ttoi64(tempstr);
}


void CMoreAdminList::OnEnKillfocusEdit48()
{
m_qqgrouprule.gamblehardscale=GetDlgItemInt(IDC_EDIT48);
	if(m_qqgrouprule.gamblehardscale<20||m_qqgrouprule.gamblehardscale>1000)
	{
	AfxMessageBox(_T("赌博难度系数有效值在20和1000之间！"));
	}
	
			m_qqgrouprule.gamblehardscale=max(20,m_qqgrouprule.gamblehardscale);
	m_qqgrouprule.gamblehardscale=min(1000,m_qqgrouprule.gamblehardscale);
	SetDlgItemInt(IDC_EDIT48,m_qqgrouprule.gamblehardscale);
}


void CMoreAdminList::OnEnKillfocusEdit54()
{
m_qqgrouprule.bidwaittime=GetDlgItemInt(IDC_EDIT54);
	if(m_qqgrouprule.bidwaittime<5||m_qqgrouprule.bidwaittime>100)
	{
	AfxMessageBox(_T("连续拍卖喊价的等待时间必须在5和100之间！"));
	}
	
			m_qqgrouprule.bidwaittime=max(1,m_qqgrouprule.bidwaittime);
	m_qqgrouprule.bidwaittime=min(10000,m_qqgrouprule.bidwaittime);
	SetDlgItemInt(IDC_EDIT54,m_qqgrouprule.bidwaittime);
	
}


void CMoreAdminList::OnEnKillfocusEdit59()
{
	m_qqgrouprule.bidbacknum=GetDlgItemInt(IDC_EDIT59);
	if(m_qqgrouprule.bidbacknum<1||m_qqgrouprule.bidbacknum>100)
	{
	AfxMessageBox(_T("赎回自己的赔偿倍数有效值在1到100之间！"));
	}
	
			m_qqgrouprule.bidbacknum=max(1,m_qqgrouprule.bidbacknum);
			m_qqgrouprule.bidbacknum=min(100,m_qqgrouprule.bidbacknum);

	SetDlgItemInt(IDC_EDIT59,m_qqgrouprule.bidbacknum);

}


void CMoreAdminList::OnBnClickedCheck34()
{
		m_qqgrouprule.bTatalSlient=((CButton*)GetDlgItem(IDC_CHECK34))->GetCheck();

		if(m_qqgrouprule.bTatalSlient&&!Isggged)
	{
	AfxMessageBox(_T("如果你是未注册版本，此功能将受限，将无法启用彻底静默模式。"));
	}
}


void CMoreAdminList::OnBnClickedCheck35()
{
		m_qqgrouprule.bOpenSelfDefGame=((CButton*)GetDlgItem(IDC_CHECK35))->GetCheck();// TODO: 在此添加控件通知处理程序代码
}


void CMoreAdminList::OnEnKillfocusEdit60()
{
		GetDlgItemText(IDC_EDIT60,m_qqgrouprule.nnnnprecardstr);
}


void CMoreAdminList::OnEnKillfocusEdit61()
{
		m_qqgrouprule.minutes_mustdosomething=GetDlgItemInt(IDC_EDIT61);
}


void CMoreAdminList::OnCbnKillfocusCombo6()
{
m_qqgrouprule.action_mustdowhat=((CComboBox*)GetDlgItem(IDC_COMBO6))->GetCurSel();
	
}


void CMoreAdminList::OnCbnKillfocusCombo7()
{

m_qqgrouprule.punish_otherwise=((CComboBox*)GetDlgItem(IDC_COMBO7))->GetCurSel();
}


void CMoreAdminList::OnEnKillfocusEdit62()
{
		GetDlgItemText(IDC_EDIT62,m_qqgrouprule.adminprecardstr);
}


void CMoreAdminList::OnEnKillfocusEdit63()
{
	GetDlgItemText(IDC_EDIT63,m_qqgrouprule.m_modifycardurl);
}


void CMoreAdminList::OnEnKillfocusEdit64()
{
	m_qqgrouprule.maxreplywithinmin=GetDlgItemInt(IDC_EDIT64);

	if(!m_qqgrouprule.maxreplywithinmin)
		m_qqgrouprule.maxreplywithinmin=200;
}
