#if !defined(AFX_COMMANDDLG_H__BE6FBC09_ECC3_4E55_92E6_9CD8E05D1A9D__INCLUDED_)
#define AFX_COMMANDDLG_H__BE6FBC09_ECC3_4E55_92E6_9CD8E05D1A9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CommandDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommandDlg dialog

class CCommandDlg : public CDialog
{
// Construction
public:
	CCommandDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCommandDlg)
	enum { IDD = IDD_DLGCOMMAND };
	CString	m_strCommand_1;
	CString	m_strName_1;
	CString	m_strName_10;
	CString	m_strName_11;
	CString	m_strName_12;
	CString	m_strName_13;
	CString	m_strName_14;
	CString	m_strName_15;
	CString	m_strName_16;
	CString	m_strName_17;
	CString	m_strName_18;
	CString	m_strName_19;
	CString	m_strName_2;
	CString	m_strName_20;
	CString	m_strName_3;
	CString	m_strName_4;
	CString	m_strName_5;
	CString	m_strName_6;
	CString	m_strName_7;
	CString	m_strName_8;
	CString	m_strName_9;
	CString	m_strCommand_10;
	CString	m_strCommand_11;
	CString	m_strCommand_12;
	CString	m_strCommand_13;
	CString	m_strCommand_14;
	CString	m_strCommand_15;
	CString	m_strCommand_16;
	CString	m_strCommand_17;
	CString	m_strCommand_18;
	CString	m_strCommand_19;
	CString	m_strCommand_2;
	CString	m_strCommand_20;
	CString	m_strCommand_3;
	CString	m_strCommand_4;
	CString	m_strCommand_5;
	CString	m_strCommand_6;
	CString	m_strCommand_7;
	CString	m_strCommand_8;
	CString	m_strCommand_9;
	BOOL	m_IsHex_1;
	BOOL	m_IsHex_10;
	BOOL	m_IsHex_11;
	BOOL	m_IsHex_12;
	BOOL	m_IsHex_13;
	BOOL	m_IsHex_14;
	BOOL	m_IsHex_15;
	BOOL	m_IsHex_16;
	BOOL	m_IsHex_17;
	BOOL	m_IsHex_18;
	BOOL	m_IsHex_19;
	BOOL	m_IsHex_2;
	BOOL	m_IsHex_20;
	BOOL	m_IsHex_3;
	BOOL	m_IsHex_4;
	BOOL	m_IsHex_5;
	BOOL	m_IsHex_6;
	BOOL	m_IsHex_7;
	BOOL	m_IsHex_8;
	BOOL	m_IsHex_9;
	BOOL	m_IsScript_1;
	BOOL	m_IsScript_10;
	BOOL	m_IsScript_11;
	BOOL	m_IsScript_12;
	BOOL	m_IsScript_13;
	BOOL	m_IsScript_14;
	BOOL	m_IsScript_15;
	BOOL	m_IsScript_16;
	BOOL	m_IsScript_17;
	BOOL	m_IsScript_18;
	BOOL	m_IsScript_19;
	BOOL	m_IsScript_2;
	BOOL	m_IsScript_20;
	BOOL	m_IsScript_3;
	BOOL	m_IsScript_4;
	BOOL	m_IsScript_5;
	BOOL	m_IsScript_6;
	BOOL	m_IsScript_7;
	BOOL	m_IsScript_8;
	BOOL	m_IsScript_9;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommandDlg)
	afx_msg void OnBtscripthelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDDLG_H__BE6FBC09_ECC3_4E55_92E6_9CD8E05D1A9D__INCLUDED_)
