
// HelloLinesView.cpp: CHelloLinesView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HelloLines.h"
#endif

#include "HelloLinesDoc.h"
#include "HelloLinesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloLinesView

IMPLEMENT_DYNCREATE(CHelloLinesView, CView)

BEGIN_MESSAGE_MAP(CHelloLinesView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHelloLinesView 构造/析构

CHelloLinesView::CHelloLinesView()
{
	// TODO: 在此处添加构造代码

	m_Draw = 0;
	m_Hcursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
}

CHelloLinesView::~CHelloLinesView()
{
}

BOOL CHelloLinesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHelloLinesView 绘图

void CHelloLinesView::OnDraw(CDC* pDC)
{
	CHelloLinesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int index = pDoc->GetTotalLine();
	while (index--) {
		pDoc->GetLine(index)->DrawLine(pDC);
	}
}


// CHelloLinesView 诊断

#ifdef _DEBUG
void CHelloLinesView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloLinesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloLinesDoc* CHelloLinesView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloLinesDoc)));
	return (CHelloLinesDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloLinesView 消息处理程序


void CHelloLinesView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pOld = point;
	m_pOrigin = point;
	SetCapture();
	m_Draw = 1;
	RECT rect; GetClientRect(&rect);
	ClientToScreen(&rect);
	ClipCursor(&rect);

	CView::OnLButtonDown(nFlags, point);
}


void CHelloLinesView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_Draw) {
		m_Draw = 0;
		ReleaseCapture();
		ClipCursor(nullptr);

		CHelloLinesDoc *pDoc = GetDocument();
		pDoc->AddLine(m_pOrigin.x, m_pOrigin.y, point.x, point.y);
	}

	CView::OnLButtonUp(nFlags, point);
}


void CHelloLinesView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCursor(m_Hcursor);
	if (m_Draw) {
		CClientDC dc(this);
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_pOrigin);
		dc.LineTo(m_pOld);
		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);
		m_pOld = point;
	}

	CView::OnMouseMove(nFlags, point);
}
