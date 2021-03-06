
// CoolCalculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "CoolCalculator.h"
#include "CoolCalculatorDlg.h"
#include "afxdialogex.h"
#include "ExpCalculator.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCoolCalculatorDlg 对话框



CCoolCalculatorDlg::CCoolCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COOLCALCULATOR_DIALOG, pParent)
	, exp_str(_T(""))
	, ans_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCoolCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_EXP, edit_exp);
	DDX_Control(pDX, IDC_EDIT_ANS, edit_ans);
	DDX_Text(pDX, IDC_EDIT_EXP, exp_str);
	DDX_Text(pDX, IDC_EDIT_ANS, ans_str);
}

BEGIN_MESSAGE_MAP(CCoolCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCoolCalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_AC, &CCoolCalculatorDlg::OnBnClickedButtonAc)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CCoolCalculatorDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCoolCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCoolCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUTIPLE, &CCoolCalculatorDlg::OnBnClickedButtonMutiple)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCoolCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_LEFT_BRACKET, &CCoolCalculatorDlg::OnBnClickedLeftBracket)
	ON_BN_CLICKED(IDC_RIGHT_BRACKET, &CCoolCalculatorDlg::OnBnClickedRightBracket)
	ON_BN_CLICKED(IDC_NUM1, &CCoolCalculatorDlg::OnClickedNum1)
	ON_BN_CLICKED(IDC_NUM2, &CCoolCalculatorDlg::OnClickedNum2)
	ON_BN_CLICKED(IDC_NUM3, &CCoolCalculatorDlg::OnClickedNum3)
	ON_BN_CLICKED(IDC_NUM4, &CCoolCalculatorDlg::OnClickedNum4)
	ON_BN_CLICKED(IDC_NUM5, &CCoolCalculatorDlg::OnClickedNum5)
	ON_BN_CLICKED(IDC_NUM6, &CCoolCalculatorDlg::OnClickedNum6)
	ON_BN_CLICKED(IDC_NUM7, &CCoolCalculatorDlg::OnClickedNum7)
	ON_BN_CLICKED(IDC_NUM8, &CCoolCalculatorDlg::OnClickedNum8)
	ON_BN_CLICKED(IDC_NUM9, &CCoolCalculatorDlg::OnClickedNum9)
	ON_BN_CLICKED(IDCANCEL, &CCoolCalculatorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_NUM0, &CCoolCalculatorDlg::OnBnClickedNum0)
END_MESSAGE_MAP()


// CCoolCalculatorDlg 消息处理程序

BOOL CCoolCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	edit_exp.SetWindowText(TEXT("请在此键入欲计算的表达式"));
	edit_ans.SetWindowText(TEXT("计算结果将在此处显示"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCoolCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCoolCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCoolCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCoolCalculatorDlg::OnBnClickedOk()
{
	static Calculator cp;

	UpdateData(TRUE);
	if (cp.resolve(wstring(exp_str.GetBuffer()))) {
		ans_str = to_wstring(cp.calculate()).c_str();
	}
	else ans_str = CString("不能理解您的输入…");
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedButtonAc()
{
	edit_ans.SetWindowText(TEXT(""));
	edit_exp.SetWindowText(TEXT(""));
}


void CCoolCalculatorDlg::OnBnClickedButtonDel()
{
	UpdateData(TRUE);
	if (!exp_str.IsEmpty())
		exp_str.Delete(exp_str.GetLength()-1);
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedButtonPlus()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('+'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedButtonMinus()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('-'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedButtonMutiple()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('*'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedButtonDivide()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('/'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedLeftBracket()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('('));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedRightBracket()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR(')'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum1()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('1'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum2()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('2'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum3()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('3'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum4()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('4'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum5()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('5'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum6()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('6'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum7()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('7'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum8()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('8'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnClickedNum9()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('9'));
	UpdateData(FALSE);
}


void CCoolCalculatorDlg::OnBnClickedNum0()
{
	UpdateData(TRUE);
	exp_str.AppendChar(CHAR('0'));
	UpdateData(FALSE);
}

void CCoolCalculatorDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}

