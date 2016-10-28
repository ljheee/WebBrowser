
// WebBrowserView.h : CWebBrowserView 类的接口
//

#pragma once


class CWebBrowserView : public CHtmlView
{
protected: // 仅从序列化创建
	CWebBrowserView();
	DECLARE_DYNCREATE(CWebBrowserView)

// 特性
public:
	CWebBrowserDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CWebBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnDocumentComplete(LPCTSTR lpszURL);
};

#ifndef _DEBUG  // WebBrowserView.cpp 中的调试版本
inline CWebBrowserDoc* CWebBrowserView::GetDocument() const
   { return reinterpret_cast<CWebBrowserDoc*>(m_pDocument); }
#endif

