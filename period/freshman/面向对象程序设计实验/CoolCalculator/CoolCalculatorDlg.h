
// CoolCalculatorDlg.h: 头文件
//

#pragma once


// CCoolCalculatorDlg 对话框
class CCoolCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCoolCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COOLCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit edit_exp;
	CEdit edit_ans;
	afx_msg void OnBnClickedButtonAc();
	afx_msg void OnBnClickedButtonDel();
	CString exp_str;
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMutiple();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedLeftBracket();
	afx_msg void OnBnClickedRightBracket();
	afx_msg void OnClickedNum1();
	afx_msg void OnClickedNum2();
	afx_msg void OnClickedNum3();
	afx_msg void OnClickedNum4();
	afx_msg void OnClickedNum5();
	afx_msg void OnClickedNum6();
	afx_msg void OnClickedNum7();
	afx_msg void OnClickedNum8();
	afx_msg void OnClickedNum9();
	afx_msg void OnBnClickedCancel();
	CString ans_str;
	afx_msg void OnBnClickedNum0();
};
