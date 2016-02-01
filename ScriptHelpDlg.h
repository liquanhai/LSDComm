#if !defined(AFX_SCRIPTHELPDLG_H__80A39D23_4D0F_45DC_B5EC_C4E248659317__INCLUDED_)
#define AFX_SCRIPTHELPDLG_H__80A39D23_4D0F_45DC_B5EC_C4E248659317__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScriptHelpDlg.h : header file
//

#include "ETSLayout.h"

/////////////////////////////////////////////////////////////////////////////
// CScriptHelpDlg dialog

class CScriptHelpDlg : public ETSLayoutDialog
{
// Construction
	DECLARE_LAYOUT();
public:
	CScriptHelpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScriptHelpDlg)
	enum { IDD = IDD_DLGSCRIPTHELP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptHelpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScriptHelpDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTHELPDLG_H__80A39D23_4D0F_45DC_B5EC_C4E248659317__INCLUDED_)
