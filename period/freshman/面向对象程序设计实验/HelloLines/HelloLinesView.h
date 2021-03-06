
// HelloLinesView.h: CHelloLinesView 类的接口
//

#pragma once


class CHelloLinesView : public CView
{
protected: // 仅从序列化创建
	CHelloLinesView();
	DECLARE_DYNCREATE(CHelloLinesView)

// 特性
public:
	CHelloLinesDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CHelloLinesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	int m_Draw;
	HCURSOR m_Hcursor;
	CPoint m_pOld;
	CPoint m_pOrigin;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // HelloLinesView.cpp 中的调试版本
inline CHelloLinesDoc* CHelloLinesView::GetDocument() const
   { return reinterpret_cast<CHelloLinesDoc*>(m_pDocument); }
#endif

