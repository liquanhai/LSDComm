#if !defined(AFX_UPGRADEDLG_H__97A51039_332C_40FD_8FD7_F9B4D880E080__INCLUDED_)
#define AFX_UPGRADEDLG_H__97A51039_332C_40FD_8FD7_F9B4D880E080__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UpgradeDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CUpgradeDlg dialog

#include "ETSLayout.h"

class CUpgradeDlg : public ETSLayoutDialog
{
// Construction
   DECLARE_LAYOUT();
public:
	CUpgradeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUpgradeDlg)
	enum { IDD = IDD_DLGUPGRADE };
	CString	m_strData;
	//}}AFX_DATA

	CString m_StrLocalfile;
	CString m_strdownfile;
	BOOL m_IsUpgrade;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpgradeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUpgradeDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPGRADEDLG_H__97A51039_332C_40FD_8FD7_F9B4D880E080__INCLUDED_)
