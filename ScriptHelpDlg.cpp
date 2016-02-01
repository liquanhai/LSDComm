// ScriptHelpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "ScriptHelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptHelpDlg dialog


CScriptHelpDlg::CScriptHelpDlg(CWnd* pParent /*=NULL*/)
	: ETSLayoutDialog(CScriptHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScriptHelpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScriptHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	ETSLayoutDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptHelpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

	CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();

	CEdit * myedit = (CEdit *) GetDlgItem(IDC_EDIT1);
	myedit->SetWindowText(_T(myApp->m_ScriptHelp));

}


BEGIN_MESSAGE_MAP(CScriptHelpDlg, ETSLayoutDialog)
	//{{AFX_MSG_MAP(CScriptHelpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptHelpDlg message handlers

BOOL CScriptHelpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	CreateRoot(VERTICAL)
		<< item (IDC_EDIT1)
		<<	( pane(HORIZONTAL, ABSOLUTE_VERT )
		<< itemGrowing (HORIZONTAL) 
		<< item( IDOK, NORESIZE)
		<< item( IDCANCEL, NORESIZE )
		);
	
	UpdateLayout();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
