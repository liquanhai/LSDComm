// SendFileByXModem.cpp : implementation file
//

#include "stdafx.h"
#include "MyComm.h"
#include "SendFileByXModem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendFileByXModem dialog


CSendFileByXModem::CSendFileByXModem(CWnd* pParent /*=NULL*/)
	: CDialog(CSendFileByXModem::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendFileByXModem)
	m_SendFileName = _T("");
	m_ModemType = -1;
	//}}AFX_DATA_INIT
}


void CSendFileByXModem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendFileByXModem)
	DDX_Text(pDX, IDC_EDFILENAME, m_SendFileName);
	DDX_Radio(pDX, IDC_RD_XMODEM, m_ModemType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendFileByXModem, CDialog)
	//{{AFX_MSG_MAP(CSendFileByXModem)
	ON_BN_CLICKED(IDC_BTSELECTFILE, OnBtselectfile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendFileByXModem message handlers

void CSendFileByXModem::OnBtselectfile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, NULL, "",                       
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_NOCHANGEDIR, 
		"All FIle (*.*)|*.*|Txt (*.txt)|*.txt");
    if (dlg.DoModal() == IDOK)
    {
		m_SendFileName = dlg.GetPathName();
		UpdateData(FALSE);
	}	
}
