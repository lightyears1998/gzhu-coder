
// HelloLinesDoc.h: CHelloLinesDoc 类的接口
//


#pragma once

class CMyLine : public CObject
{
protected:
	int m_StartX, m_StartY;
	int m_EndX, m_EndY;

public:
	CMyLine(int StartX, int StartY, int EndX, int EndY);
	void DrawLine(CDC *pDC);
};


class CHelloLinesDoc : public CDocument
{
protected: // 仅从序列化创建
	CObArray m_ObArray;
	
	CHelloLinesDoc();
	DECLARE_DYNCREATE(CHelloLinesDoc)

// 特性
public:

// 操作
public:
	void AddLine(int StartX, int StartY, int EndX, int EndY);
	CMyLine * GetLine(int index);
	int GetTotalLine();
	virtual void DeleteContents();

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CHelloLinesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
