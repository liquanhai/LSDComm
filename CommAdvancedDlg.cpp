// CommAdvancedDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "CommAdvancedDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommAdvancedDlg dialog


CCommAdvancedDlg::CCommAdvancedDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommAdvancedDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommAdvancedDlg)
	m_dwoReadInter = 0;
	m_dwoReadTotalMult = 0;
	m_dwoReadTotalConst = 0;
	m_dwoWriteTotalMult = 0;
	m_dwoWriteTotalConst = 0;
	//}}AFX_DATA_INIT
}


void CCommAdvancedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommAdvancedDlg)
	DDX_Text(pDX, IDC_EDREADINTER, m_dwoReadInter);
	DDX_Text(pDX, IDC_EDREADTOTALMUL, m_dwoReadTotalMult);
	DDX_Text(pDX, IDC_EDREATOTALCONST, m_dwoReadTotalConst);
	DDX_Text(pDX, IDC_EDWRITETOTALCONST, m_dwoWriteTotalMult);
	DDX_Text(pDX, IDC_EDWRITETOTALMUL, m_dwoWriteTotalConst);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommAdvancedDlg, CDialog)
	//{{AFX_MSG_MAP(CCommAdvancedDlg)
	ON_BN_CLICKED(IDC_BTDEFAULT, OnBtdefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommAdvancedDlg message handlers

void CCommAdvancedDlg::OnBtdefault() 
{
	// TODO: Add your control notification handler code here
	m_dwoReadInter = 1;
	m_dwoReadTotalMult = 0;
	m_dwoReadTotalConst = 0;
	m_dwoWriteTotalMult = 0;
	m_dwoWriteTotalConst =0;
	UpdateData(FALSE);
}
