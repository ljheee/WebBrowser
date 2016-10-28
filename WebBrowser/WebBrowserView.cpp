
// WebBrowserView.cpp : CWebBrowserView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "WebBrowser.h"
#endif

#include "WebBrowserDoc.h"
#include "WebBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWebBrowserView

IMPLEMENT_DYNCREATE(CWebBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CWebBrowserView, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWebBrowserView 构造/析构

CWebBrowserView::CWebBrowserView()
{
	// TODO:  在此处添加构造代码

}

CWebBrowserView::~CWebBrowserView()
{
}

BOOL CWebBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

int flag = 0;
void CWebBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.baidu.com/"),NULL,NULL);
	flag = 1;
}


// CWebBrowserView 打印


void CWebBrowserView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}


void CWebBrowserView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWebBrowserView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWebBrowserView 诊断

#ifdef _DEBUG
void CWebBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CWebBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CWebBrowserDoc* CWebBrowserView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWebBrowserDoc)));
	return (CWebBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CWebBrowserView 消息处理程序


void CWebBrowserView::OnDocumentComplete(LPCTSTR lpszURL)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (flag == 1)  return;

	CWinApp* pApp = AfxGetApp();
	POSITION curTemplatePos = pApp->GetFirstDocTemplatePosition();
	if (curTemplatePos != NULL){
		CDocTemplate* curTemplate = pApp->GetNextDocTemplate(curTemplatePos);
		curTemplate->OpenDocumentFile(NULL);
		
	}
	
	
//	Navigate2(lpszURL, NULL, NULL);


	CHtmlView::OnDocumentComplete(lpszURL);
}
