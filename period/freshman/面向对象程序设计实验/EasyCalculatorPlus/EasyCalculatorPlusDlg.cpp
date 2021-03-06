
// EasyCalculatorPlusDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "EasyCalculatorPlus.h"
#include "EasyCalculatorPlusDlg.h"
#include "ExpCalculator.hpp"
#include "afxdialogex.h"

#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEasyCalculatorPlusDlg 对话框



CEasyCalculatorPlusDlg::CEasyCalculatorPlusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EASYCALCULATORPLUS_DIALOG, pParent)
	, expression(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEasyCalculatorPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_EXP, CEdit_Exp);
	//  DDX_Text(pDX, IDC_EDIT_EXP, Edit_cstr);
	//  DDX_Text(pDX, IDC_EDIT_EXP, expression);
	DDX_Text(pDX, IDC_EDIT_EXP, expression);
}

BEGIN_MESSAGE_MAP(CEasyCalculatorPlusDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CEasyCalculatorPlusDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_CAL, &CEasyCalculatorPlusDlg::OnBnClickedButtonCal)
END_MESSAGE_MAP()


// CEasyCalculatorPlusDlg 消息处理程序

BOOL CEasyCalculatorPlusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CEdit_Exp.SetWindowText(TEXT("请在此处键入您的表达式，支持四则运算和小括号嵌套 : )"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEasyCalculatorPlusDlg::OnPaint()
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
HCURSOR CEasyCalculatorPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CEasyCalculatorPlusDlg::OnBnClickedButtonExit()
{
	CDialogEx::OnOK();
}


void CEasyCalculatorPlusDlg::OnBnClickedButtonCal()
{
	static Calculator cp;

	UpdateData(TRUE);
	if (cp.resolve(wstring(expression.GetBuffer()))) {
		expression = to_wstring(cp.calculate()).c_str();
	}
	else expression = CString("不能理解您的输入…");
	UpdateData(FALSE);
}
