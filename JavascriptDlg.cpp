// JavascriptDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "晨风qq机器人.h"
#include "JavascriptDlg.h"


// CJavascriptDlg

IMPLEMENT_DYNCREATE(CJavascriptDlg, CHtmlView)

CJavascriptDlg::CJavascriptDlg()
{

}

CJavascriptDlg::~CJavascriptDlg()
{
}
BOOL CJavascriptDlg::CreateFromStatic(CStatic* pStaticWnd, CWnd* pParent) 
{ 
    ASSERT(NULL!=pStaticWnd && NULL!=pStaticWnd->GetSafeHwnd()); 
    ASSERT(NULL!=pParent && NULL!=pParent->GetSafeHwnd()); 
 
    CRect rc; 
    pStaticWnd->GetClientRect(&rc); 
 pStaticWnd->ClientToScreen(rc);
 pParent->ScreenToClient(rc);

    int nID = pStaticWnd->GetDlgCtrlID(); 
    LPCTSTR lpClassName = AfxRegisterWndClass(NULL); 
    return Create(lpClassName, _T(""), WS_CHILD, rc, pParent, nID, NULL);// WS_VISIBLE
} 
int CJavascriptDlg::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) 
{ 
    // TODO: Add your message handler code here and/or call default 
 
    return CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message); 
 
//Do not call it. 
    // return CHtmlView::OnMouseActivate(pDesktopWnd, nHitTest, message); 
} 
void CJavascriptDlg::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CJavascriptDlg, CHtmlView)
END_MESSAGE_MAP()


// CJavascriptDlg 诊断

#ifdef _DEBUG
void CJavascriptDlg::AssertValid() const
{
	CHtmlView::AssertValid();
}

#ifndef _WIN32_WCE
void CJavascriptDlg::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif
#endif //_DEBUG


// CJavascriptDlg 消息处理程序

extern BOOL bCompletedflag;
void CJavascriptDlg::OnNavigateComplete2(LPCTSTR strURL)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	CHtmlView::OnNavigateComplete2(strURL);
	bCompletedflag=true;
}
