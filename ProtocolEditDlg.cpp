// ProtocolEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "ProtocolEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProtocolEditDlg dialog


CProtocolEditDlg::CProtocolEditDlg(CWnd* pParent /*=NULL*/)
	: ETSLayoutDialog(CProtocolEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProtocolEditDlg)
	m_Edit = _T("");
	//}}AFX_DATA_INIT
}


void CProtocolEditDlg::DoDataExchange(CDataExchange* pDX)
{
	ETSLayoutDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProtocolEditDlg)
	DDX_Text(pDX, IDC_EDIT, m_Edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProtocolEditDlg, ETSLayoutDialog)
	//{{AFX_MSG_MAP(CProtocolEditDlg)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProtocolEditDlg message handlers

BOOL CProtocolEditDlg::OnInitDialog() 
{
	ETSLayoutDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CreateRoot(VERTICAL)
		<< item (IDC_EDIT)
/*		
		<< 	( pane(HORIZONTAL, ABSOLUTE_VERT )
		<< item( IDC_NEW_ITEM, GREEDY )
		<< item( IDC_ADD_ITEM, NORESIZE )
		)
		
		<< item ( IDC_ITEM_LIST_STATIC, NORESIZE )
		<< item ( IDC_ITEM_LIST, GREEDY )
*/		
		<<	( pane(HORIZONTAL, ABSOLUTE_VERT )
			<< itemGrowing (HORIZONTAL) 
			<< item( IDOK, NORESIZE)
			<< item( IDCANCEL, NORESIZE )
		);
	
	UpdateLayout();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProtocolEditDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	ETSLayoutDialog::OnClose();
}
