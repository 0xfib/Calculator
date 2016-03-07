
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent),
	SelectedScreenNo(1),
	FirstScreenNewStart(true),
	SecondScreenNewStart(true)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, CSecondScreen);
	DDX_Control(pDX, IDC_EDIT2, CFirstScreen);

	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	DDX_Control(pDX, IDC_EDIT_HISTORY, CHistoryScreen);
	DDX_Control(pDX, IDC_EDIT_OPERATOR, COPERATOR);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BUTTON0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_RADIO1, &CCalculatorDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CCalculatorDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(BUTTON_DC, &CCalculatorDlg::OnBnClickedDc)
	ON_BN_CLICKED(BUTTON_MMC, &CCalculatorDlg::OnBnClickedMmc)
	ON_EN_SETFOCUS(IDC_EDIT3, &CCalculatorDlg::OnEnSetfocusEdit3)
	ON_EN_SETFOCUS(IDC_EDIT2, &CCalculatorDlg::OnEnSetfocusEdit2)
	ON_BN_CLICKED(BUTTON_P, &CCalculatorDlg::OnBnClickedP)
	ON_BN_CLICKED(BUTTON_MINUS, &CCalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_BUTTON_Multi, &CCalculatorDlg::OnBnClickedButtonMulti)
	ON_BN_CLICKED(BUTTON_DIV, &CCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(BUTTON_E, &CCalculatorDlg::OnBnClickedE)
	ON_BN_CLICKED(BUTTON_SHIFT, &CCalculatorDlg::OnBnClickedShift)
	ON_BN_CLICKED(BUTTON_X, &CCalculatorDlg::OnBnClickedX)
	ON_BN_CLICKED(BUTTON_P_M, &CCalculatorDlg::OnBnClickedPM)
	ON_BN_CLICKED(BUTTON_CE, &CCalculatorDlg::OnBnClickedCe)
	ON_BN_CLICKED(BUTTON_C, &CCalculatorDlg::OnBnClickedC)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// Init Screens
	CFirstScreen.SetWindowTextW(CString("0"));
	CSecondScreen.SetWindowTextW(CString("1"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::InsertScreen(CString in)
{
	CString CurrentScreenText;
	if (SelectedScreenNo == 1 && FirstScreenNewStart) {
		SelectedScreen()->SetWindowTextW(in);
		FirstScreenNewStart = FALSE;
	}
	else if (SelectedScreenNo == 2 && SecondScreenNewStart) {
		SelectedScreen()->SetWindowTextW(in);
		SecondScreenNewStart = FALSE;
	}
	else {
		SelectedScreen()->GetWindowTextW(CurrentScreenText);
		SelectedScreen()->SetWindowTextW(CurrentScreenText + in);
	}
}

void CCalculatorDlg::SetOperator(CString opr)
{
	COPERATOR.SetWindowTextW(opr);
	CString FirstScreenText;
	CFirstScreen.GetWindowTextW(FirstScreenText);
	CString SecondScreenText;
	CSecondScreen.GetWindowTextW(SecondScreenText);
	int t = _wtoi(FirstScreenText);
	int b = _wtoi(SecondScreenText);

	CString toString;

	CString CurrentHistoryScreenText;
	CHistoryScreen.GetWindowTextW(CurrentHistoryScreenText);

	if (opr == '=') {
		CHistoryScreen.SetWindowTextW(CurrentHistoryScreenText + Rational(t, b).toString() + _T(" "));
		CurrentRational = CurrentRational + Rational(t, b);
		toString.Format(TEXT("%d"), CurrentRational.getNumarator());
		CFirstScreen.SetWindowTextW(toString);
		toString.Format(TEXT("%d"), CurrentRational.getNumitor());
		CSecondScreen.SetWindowTextW(toString);
	}
	else {
		CurrentRational = Rational(t, b);
	}
	
	CHistoryScreen.GetWindowTextW(CurrentHistoryScreenText);
	if (opr == '=') 
		CHistoryScreen.SetWindowTextW(CurrentHistoryScreenText + opr + _T(" ") + CurrentRational.toString());
	else
		CHistoryScreen.SetWindowTextW(CurrentHistoryScreenText + CurrentRational.toString() + opr + _T(" "));

	FirstScreenNewStart = TRUE;
	SecondScreenNewStart = TRUE;
}

int CCalculatorDlg::CMMDC(int a, int b)
{
	int r;
	r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int CCalculatorDlg::CMMMC(int a, int b)
{
	return(a*b / CMMDC(a, b));;
}


CEdit* CCalculatorDlg::SelectedScreen()
{
	if (SelectedScreenNo == 1) {
		return &CFirstScreen;
	}
	else {
		return &CSecondScreen;
	}
}


BOOL CCalculatorDlg::PreTranslateMessage(MSG * pMsg)
{
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam >= VK_NUMPAD0 && pMsg->wParam <= VK_NUMPAD9) {

		}
		else if(pMsg->wParam >= 48 && pMsg->wParam <= 57) {
			CString in((wchar_t)pMsg->wParam);
			InsertScreen(in);
			return true;
		}
		else if (pMsg->wParam == 32) {}
		else if (pMsg->wParam == VK_BACK) OnBackSlash();
		else if (pMsg->wParam == VK_SHIFT) Debug();
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CCalculatorDlg::OnBackSlash()
{
	CString currentScreenText;
	SelectedScreen()->GetWindowTextW(currentScreenText);
	currentScreenText.Delete(currentScreenText.GetLength());
	if (currentScreenText.GetLength() == 1) {
		if (SelectedScreenNo == 1){
			SelectedScreen()->SetWindowTextW(CString(_T("0")));
			FirstScreenNewStart = TRUE;
		} else {
			SelectedScreen()->SetWindowTextW(CString(_T("1")));
			SecondScreenNewStart = TRUE;
		}
	}
	else if (!currentScreenText.IsEmpty()) {
		currentScreenText.Delete(currentScreenText.GetLength() - 1);
		SelectedScreen()->SetWindowTextW(currentScreenText);
	}
}

void CCalculatorDlg::Debug()
{
	Rational tr = Rational(0, 1);
	CString string = _T("test");
	AfxMessageBox(tr.toString());
}

void CCalculatorDlg::OnBnClickedButton0()
{
	InsertScreen(CString("0"));
}


void CCalculatorDlg::OnBnClickedButton1()
{
	InsertScreen(CString("1"));
}


void CCalculatorDlg::OnBnClickedButton2()
{
	InsertScreen(CString("2"));
}


void CCalculatorDlg::OnBnClickedButton3()
{
	InsertScreen(CString("3"));
}


void CCalculatorDlg::OnBnClickedButton4()
{
	InsertScreen(CString("4"));
}


void CCalculatorDlg::OnBnClickedButton5()
{
	InsertScreen(CString("5"));
}


void CCalculatorDlg::OnBnClickedButton6()
{
	InsertScreen(CString("6"));
}


void CCalculatorDlg::OnBnClickedButton7()
{
	InsertScreen(CString("7"));
}


void CCalculatorDlg::OnBnClickedButton8()
{
	InsertScreen(CString("8"));
}


void CCalculatorDlg::OnBnClickedButton9()
{
	InsertScreen(CString("9"));
}


void CCalculatorDlg::OnBnClickedRadio1()
{
	SelectedScreenNo = 1;
}


void CCalculatorDlg::OnBnClickedRadio2()
{
	SelectedScreenNo = 2;
}


void CCalculatorDlg::OnBnClickedDc()
{
	CString FirstScreenText;
	CFirstScreen.GetWindowTextW(FirstScreenText);
	CString SecondScreenText;
	CSecondScreen.GetWindowTextW(SecondScreenText);
	int re = CMMDC(_wtoi(FirstScreenText), _wtoi(SecondScreenText));

	CString CurrentScreenText = _T("");
	CString reString;
	reString.Format(TEXT("%d"), re);
	CHistoryScreen.SetWindowTextW(CurrentScreenText + reString);
}


void CCalculatorDlg::OnBnClickedMmc()
{
	CString FirstScreenText;
	CFirstScreen.GetWindowTextW(FirstScreenText);
	CString SecondScreenText;
	CSecondScreen.GetWindowTextW(SecondScreenText);
	int re = CMMMC(_wtoi(FirstScreenText), _wtoi(SecondScreenText));

	CString CurrentScreenText=_T("");
	CString reString;
	reString.Format(TEXT("%d"), re);
	CHistoryScreen.SetWindowTextW(CurrentScreenText + reString);
}

void CCalculatorDlg::OnEnSetfocusEdit3()
{
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO2);
	SelectedScreenNo = 2;
}


void CCalculatorDlg::OnEnSetfocusEdit2()
{
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	SelectedScreenNo = 1;
}


void CCalculatorDlg::OnBnClickedP()
{
	SetOperator(CString(_T("+")));
}


void CCalculatorDlg::OnBnClickedMinus()
{
	SetOperator(CString(_T("-")));
}


void CCalculatorDlg::OnBnClickedButtonMulti()
{
	SetOperator(CString(_T("*")));
}


void CCalculatorDlg::OnBnClickedDiv()
{
	SetOperator(CString(_T("/")));
}


void CCalculatorDlg::OnBnClickedE()
{
	SetOperator(CString(_T("=")));
}


void CCalculatorDlg::OnBnClickedShift()
{
	OnBackSlash();
}


void CCalculatorDlg::OnBnClickedX()
{
	CString FirstScreenText;
	CString SecondScreenText;

	CFirstScreen.GetWindowTextW(FirstScreenText);
	CSecondScreen.GetWindowTextW(SecondScreenText);
	CFirstScreen.SetWindowTextW(SecondScreenText);
	if (FirstScreenText == "0") FirstScreenText = _T("1");
	CSecondScreen.SetWindowTextW(FirstScreenText);
}


void CCalculatorDlg::OnBnClickedPM()
{
	CString currentScreenText;
	SelectedScreen()->GetWindowTextW(currentScreenText);
	int conv = _wtoi(currentScreenText);
	CString reString;
	reString.Format(TEXT("%d"), -conv);
	SelectedScreen()->SetWindowTextW(reString);
}


void CCalculatorDlg::OnBnClickedCe()
{
	CString clearScreen;
	clearScreen = _T("0");
	CFirstScreen.SetWindowTextW(clearScreen);
	clearScreen = _T("1");
	CSecondScreen.SetWindowTextW(clearScreen);
	FirstScreenNewStart = TRUE;
	SecondScreenNewStart = TRUE;
}


void CCalculatorDlg::OnBnClickedC()
{
	CString clearScreen;
	clearScreen = _T("0");
	CFirstScreen.SetWindowTextW(clearScreen);
	clearScreen = _T("1");
	CSecondScreen.SetWindowTextW(clearScreen);
	clearScreen = _T("");
	CHistoryScreen.SetWindowTextW(clearScreen);
	COPERATOR.SetWindowTextW(clearScreen);
	FirstScreenNewStart = TRUE;
	SecondScreenNewStart = TRUE;

}
