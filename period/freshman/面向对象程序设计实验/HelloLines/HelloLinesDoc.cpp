
// HelloLinesDoc.cpp: CHelloLinesDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HelloLines.h"
#endif

#include "HelloLinesDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHelloLinesDoc

IMPLEMENT_DYNCREATE(CHelloLinesDoc, CDocument)

BEGIN_MESSAGE_MAP(CHelloLinesDoc, CDocument)
END_MESSAGE_MAP()


// CHelloLinesDoc 构造/析构

CHelloLinesDoc::CHelloLinesDoc()
{
	// TODO: 在此添加一次性构造代码

}

CHelloLinesDoc::~CHelloLinesDoc()
{
}

void CHelloLinesDoc::AddLine(int StartX, int StartY, int EndX, int EndY)
{
	CMyLine * pMyLine = new CMyLine(StartX, StartY, EndX, EndY);
	m_ObArray.Add(pMyLine);
}

CMyLine * CHelloLinesDoc::GetLine(int index)
{
	if (index < 0 || index > m_ObArray.GetUpperBound())
		return nullptr;
	return (CMyLine*)m_ObArray.GetAt(index);
}

int CHelloLinesDoc::GetTotalLine()
{
	return int(m_ObArray.GetSize());
}

void CHelloLinesDoc::DeleteContents()
{
	int index = int(m_ObArray.GetSize());
	while (index--)
		delete m_ObArray.GetAt(index);
	m_ObArray.RemoveAll();
}

BOOL CHelloLinesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CHelloLinesDoc 序列化

void CHelloLinesDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CHelloLinesDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CHelloLinesDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CHelloLinesDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHelloLinesDoc 诊断

#ifdef _DEBUG
void CHelloLinesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHelloLinesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHelloLinesDoc 命令

CMyLine::CMyLine(int StartX, int StartY, int EndX, int EndY)
{
	m_StartX = StartX, m_StartY = StartY;
	m_EndX = EndX, m_EndY = EndY;
}

void CMyLine::DrawLine(CDC * pDC)
{
	pDC->MoveTo(m_StartX, m_StartY);
	pDC->LineTo(m_EndX, m_EndY);
}


