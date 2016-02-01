// UpgradeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "UpgradeDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUpgradeDlg dialog


CUpgradeDlg::CUpgradeDlg(CWnd* pParent /*=NULL*/)
	: ETSLayoutDialog(CUpgradeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpgradeDlg)
	m_strData = _T("");
	//}}AFX_DATA_INIT
}


void CUpgradeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpgradeDlg)
	DDX_Text(pDX, IDC_EDDATE, m_strData);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUpgradeDlg, CDialog)
	//{{AFX_MSG_MAP(CUpgradeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpgradeDlg message handlers

void CUpgradeDlg::OnOK() 
{
	// TODO: Add extra validation here
	if (!m_IsUpgrade) {
		CDialog::OnOK();
		return;
	};
	
	char s[256],s2[256];
	_tcscpy(s,m_StrLocalfile.GetBuffer(m_StrLocalfile.GetLength())) ;
	_tcscpy(s2,m_strdownfile.GetBuffer(m_strdownfile.GetLength())) ;
	CMainFrame * myMain = (CMainFrame *)AfxGetMainWnd();
	if(!myMain->DonwLoadFile(s2,s))
	{
		AfxMessageBox(_T("ÎÞ·¨Éý¼¶¡£"));
		return;
	}
	else{
		CDialog::OnOK();
	}
	
}

BOOL CUpgradeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		CreateRoot(VERTICAL)
		<< item(IDC_STATIC1,NORESIZE)
		<< item (IDC_EDDATE)
		<<	( pane(HORIZONTAL, ABSOLUTE_VERT )
			<< itemGrowing (HORIZONTAL) 
			<< item( IDOK, NORESIZE)
			<< item( IDCANCEL, NORESIZE )
		);
	UpdateLayout();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
