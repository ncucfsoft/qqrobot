// FontInfSetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FontInfSetDlg.h"
//#include "afxdialogex.h"


// CFontInfSetDlg 对话框

IMPLEMENT_DYNAMIC(CFontInfSetDlg, CDialog)
extern	vector<COLORREF> randcolorvect;
CFontInfSetDlg::CFontInfSetDlg(CWnd* pParent /*=NULL*/)
	: CMyBGCDlg(CFontInfSetDlg::IDD, pParent)
{
	bNomultLanguage=true;
		wndIdentification=_T("IgnoreFoloderDlg");
		//m_clrBkgnd=RGB(128,170,150);
		
		m_clrBkgnd=RGB(220,210,200);
}

CFontInfSetDlg::~CFontInfSetDlg()
{
}

void CFontInfSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
		DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(CFontInfSetDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_EN_KILLFOCUS(IDC_EDIT6, &CFontInfSetDlg::OnEnKillfocusEdit6)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CFontInfSetDlg::OnCbnSelchangeCombo1)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CFontInfSetDlg::OnCbnKillfocusCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CFontInfSetDlg::OnBnClickedButton3)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON4, &CFontInfSetDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK2, &CFontInfSetDlg::OnBnClickedCheck2)
END_MESSAGE_MAP()
const int imgxsize=16;
const int imgysize=16;
void CFontInfSetDlg::Insert2List(COLORREF color1)
{
	CString hshowstr;
hshowstr.Format(_T("%06X"),(UINT)color1);
int itemcount=m_list1.GetItemCount();
		//m_list1.InsertItem(itemcount,fpath);
  
        CBitmap * pBmp = NULL;  
        pBmp = new CBitmap();  
CDC de; 
CDC *pDC=GetDC(); 
de.CreateCompatibleDC(pDC); 
        pBmp->CreateCompatibleBitmap(pDC,imgxsize,imgysize); 
		CBitmap *oldbitmap=de.SelectObject(pBmp); 
		CRect rect(0,0,imgxsize,imgysize);
			de.FillSolidRect(rect, color1);
			
		    m_imList.Add(pBmp,RGB(0,0,0));  
			de.SelectObject(oldbitmap); 
        delete pBmp;  
		ReleaseDC(pDC);
	
//HICON hIcon;  
//  
//        m_imList.Create(32,32,ILC_COLOR,2,20);  
//  
//        hIcon = AfxGetApp()->LoadIconW(IDI_ICON1);  
//        m_imList.Add(hIcon);  
//     hIcon = AfxGetApp()->LoadIconW(IDI_ICON1);  
//        m_imList.Add(hIcon);  
		int nRow=itemcount;  //记录行号   
LVITEM lvItem={0};  
  
//第一行数据   
lvItem.mask = LVIF_IMAGE|LVIF_TEXT|LVIF_STATE;  //文字、图片、状态   
lvItem.iItem = itemcount;       //行号(第一行)   
lvItem.iImage = m_imList.GetImageCount()-1;  //图片索引号(第一幅图片)   
lvItem.iSubItem = 0;    //子列号   
  
nRow = m_list1.InsertItem(&lvItem);     //第一列为图片   
m_list1.SetItemText(nRow,1,hshowstr);  //第二列为文字   
//m_list1.SetItemText(itemcount,1,hshowstr);

}
BOOL CFontInfSetDlg::OnInitDialog()
{
	CMyBGCDlg::OnInitDialog();

	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
		m_list1.InsertColumn(0,_T("颜色"),0,50);
				m_list1.InsertColumn(1,_T("颜色代码"),0,100);
				m_imList.Create(imgxsize,imgysize,ILC_MASK | ILC_COLOR24,0,20);  
			
		m_list1.SetImageList(&m_imList,LVSIL_SMALL); 

SetDlgItemInt(IDC_EDIT6,g_fontsize);
((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(g_boldflag);

int pos=((CComboBox*)GetDlgItem(IDC_COMBO1))->FindStringExact(-1,g_fontname);
if(pos==CB_ERR)
{
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetWindowText(g_fontname);
}
else
{
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(pos);

}
for(int i=0;i<randcolorvect.size();i++)
{
Insert2List(randcolorvect[i]);

}
return true;	
}
// CFontInfSetDlg 消息处理程序


void CFontInfSetDlg::OnEnKillfocusEdit6()
{
	g_fontsize=GetDlgItemInt(IDC_EDIT6);
	

	if(g_fontsize<9)
		g_fontsize=9;
}


void CFontInfSetDlg::OnCbnSelchangeCombo1()
{
		
//	int curpos=((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
//if(curpos>=0)
//{
//	CString rstring;
//	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(curpos,g_fontname);
//}

}


void CFontInfSetDlg::OnCbnKillfocusCombo1()
{
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(g_fontname);
	if(g_fontname.IsEmpty())
	 g_fontname=_T("微软雅黑");

}


void CFontInfSetDlg::OnBnClickedButton3()
{
	
	COLORREF c;//接收颜色
	CColorDialog dlg;//颜色对话框
	COLORREF g_rgbcolor=RGB(0,0,0);
	if(dlg.DoModal()==IDOK)
	{	
		int r,g,b;
		c=dlg.GetColor();//获得颜色，赋给c
		
		r=GetRValue(c);//获得R
		g=GetGValue(c);//G
		b=GetBValue(c);//B
		g_rgbcolor=RGB(r,g,b);
	Insert2List(g_rgbcolor);
	}

	
}


void CFontInfSetDlg::OnDestroy()
{

	int itemcount=m_list1.GetItemCount();
	CString qqstr,qqpasswordstr;
	CString strfmt;

	g_fontcolorstr=_T("");
		for(int i=0;i<itemcount;i++)
	{

	
		qqpasswordstr=m_list1.GetItemText(i,1);
		strfmt.Format(_T("%s"),qqpasswordstr);
		g_fontcolorstr+=strfmt;
		g_fontcolorstr+=_T(";");

	}

	CMyBGCDlg::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


BOOL CFontInfSetDlg::PreTranslateMessage(MSG* pMsg)
{
	LRESULT presult;
// TODO: 在此添加专用代码和/或调用基类

	if(pMsg->message==WM_KEYUP)
	{
		if(LOWORD(pMsg->wParam)==VK_DELETE)
		{
			CWnd *tempcwnd=GetFocus();
			if(tempcwnd==GetDlgItem(IDC_LIST1))
				OnBnClickedButton4();
			return true;
		}
	}
	presult=CDialog::PreTranslateMessage(pMsg);

return presult;
}
void CFontInfSetDlg::OnBnClickedButton4()
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
	
	for(int i=selectvect.size()-1;i>=0;i--)
	{
			m_list1.DeleteItem(selectvect[i]);
		

		
	}
}


void CFontInfSetDlg::OnBnClickedCheck2()
{
	g_boldflag=((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
}
