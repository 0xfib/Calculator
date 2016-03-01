
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
	SelectedScreenNo(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, CSecondScreen);
	DDX_Control(pDX, IDC_EDIT2, CFirstScreen);

	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
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
	SelectedScreen()->GetWindowTextW(CurrentScreenText);
	SelectedScreen()->SetWindowTextW(CurrentScreenText + in);

	
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

BOOL CCalculatorDlg::PreTransalateMessage(MSG * msg)
{
	if (msg->message == WM_KEYDOWN && (msg->wParam >= '0' && msg->wParam <= '9'))
	{
		exit(0);
	}

	if (msg->message == WM_KEYDOWN && msg->wParam == 8) {
		
	}
	return CDialogEx::PreTranslateMessage(msg);
}

void CCalculatorDlg::OnBackSlash()
{

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
	int cmmdc = CMMDC(_wtoi(FirstScreenText), _wtoi(SecondScreenText));
}


void CCalculatorDlg::OnBnClickedMmc()
{
	
}
