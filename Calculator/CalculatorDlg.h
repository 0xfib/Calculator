
// CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Rational.h"


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int SelectedScreenNo;
	bool FirstScreenNewStart;
	bool SecondScreenNewStart;
	Rational MemRational;
	Rational CurrentRational;
	CEdit CSecondScreen;
	CEdit CFirstScreen;
	CEdit CHistoryScreen;
	CEdit COPERATOR;
	CEdit* SelectedScreen();
	BOOL PreTranslateMessage(MSG* msg);
	void InsertScreen(CString in);
	void SetOperator(CString opr);
	int CMMDC(int a, int b);
	int CMMMC(int a, int b);
	void OnBackSlash();
	void Debug();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedDc();
	afx_msg void OnBnClickedMmc();
	afx_msg void OnEnSetfocusEdit3();
	afx_msg void OnEnSetfocusEdit2();
	afx_msg void OnBnClickedP();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedButtonMulti();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedE();
	afx_msg void OnBnClickedShift();
	afx_msg void OnBnClickedX();
	afx_msg void OnBnClickedPM();
	afx_msg void OnBnClickedCe();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedMc();
	afx_msg void OnBnClickedMp();
	afx_msg void OnBnClickedMr();
	afx_msg void OnBnClickedMm();
};
