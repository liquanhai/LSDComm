// MyComm.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyComm.h"

#include "MainFrm.h"
#include "MyCommDoc.h"
#include "MyCommView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCommApp

BEGIN_MESSAGE_MAP(CMyCommApp, CWinApp)
	//{{AFX_MSG_MAP(CMyCommApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
		
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCommApp construction

CMyCommApp::CMyCommApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_SendkeyType = SKNONE;
	
	CString mystr;
	char   re[3]   =   {VK_RETURN,   0x0a};
	mystr += "//"; mystr += re;
	mystr += "//2008-1-15 author:mrlong" ;mystr += re; 
	mystr += "//不区分大小写";mystr += re; 
	mystr += "//"; mystr += re;
	mystr +=re;
	mystr += "语法格式: 命令=参数1,参数2,参数3,..参数n ;"; mystr +=re;
	mystr += "          注意每个语句必须用;号结束。"; mystr+=re;
	mystr += "注释符# ，必须是第一个字符与独占一行。例如 #我的说明了"; mystr +=re;
	mystr +=re;
	
	
	mystr += "1. send 发送命令 "; mystr += re;
	mystr += " 例如: 1.1 send=%1; 其中%1表示指令1"; mystr +=re;
	mystr += "       1.2 Send=68 01 01 68 41 00 41 16;"; mystr +=re;
	
	mystr +=re;
	mystr += "2. sleep 停留时间(单位毫秒) "; mystr +=re;
	mystr += " 例如: 2.1 sleep=300;"; mystr +=re;
	
	mystr +=re;
	mystr += "3. out 发送字符到接收窗口"; mystr +=re;
	mystr += " 例如: 3.1 out=我的字符;"; mystr +=re;
	
	mystr +=re;
	mystr += "4. date 将时间发送到窗口"; mystr +=re;
	mystr += " 例如: 4.1 date=%Y-%m-%d %H:%M:%S 参数表示格式"; mystr +=re; 
	mystr += "   %Y=2008 ; %y=08, %m 与 %M 不同，注意这个参数的大小写。"; mystr += re;
	mystr += "       4.2 date; 无参数默认是格式为%Y-%m-%d %H:%M:%S。"; mystr +=re;
	
	mystr +=re;
	mystr += "5. clear 清空接收窗口数据"; mystr +=re;
	mystr += " 例如 clear;"; mystr +=re;
	
	mystr +=re;
	mystr += "6. help 在接收区显示脚本帮助"; mystr += re;
	mystr += " 例如 help;"; mystr += re;

	m_ScriptHelp = mystr;
	
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyCommApp object

CMyCommApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyCommApp initialization

BOOL CMyCommApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings(10);  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	//App dir
	GetModuleFileName(NULL,m_AppDir.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	m_AppDir.ReleaseBuffer ();
	int nPos = 0;
	nPos = m_AppDir.ReverseFind('\\');
	CString str = m_AppDir.Right(m_AppDir.GetLength()-nPos-1);    // 不含路径的升级文件名
	m_AppDir = m_AppDir.Left (nPos);
	//=============================================================================
	//1.3 2008-2-16 
	//  增加发送文件功能。
	//
	//
	//
	m_AppVersion = "1.3"; 
	
	//=============================================================================
	m_downfileexefilename = "";
	

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMyCommDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CMyCommView));
	AddDocTemplate(pDocTemplate);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	//App Params
	m_SendkeyType = SendKeyStyle(GetProfileInt("Other","SendKeyType",0));

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();



	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMyCommApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMyCommApp message handlers


int CMyCommApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	WriteProfileInt("Other","SendKeyType",m_SendkeyType);
	return CWinApp::ExitInstance();
}

void CMyCommApp::DoSetStautsBarText(UINT index,CString Value)
{
	CMainFrame * myMain = (CMainFrame *)m_pMainWnd;
	myMain->m_wndStatusBar.SetPaneText(index,Value);

}



BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
	CStatic * mystatic = (CStatic *)GetDlgItem(IDC_STATIC_VERSION);
	mystatic->SetWindowText(myApp->m_AppVersion);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


