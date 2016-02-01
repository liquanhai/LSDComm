#if !defined(AFX_PROTOCOLEDITDLG_H__3EE225FC_BDEC_4093_A4CA_CF5D0EA64548__INCLUDED_)
#define AFX_PROTOCOLEDITDLG_H__3EE225FC_BDEC_4093_A4CA_CF5D0EA64548__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProtocolEditDlg.h : header file
//
#include "ETSLayout.h"

/////////////////////////////////////////////////////////////////////////////
// CProtocolEditDlg dialog

class CProtocolEditDlg : public ETSLayoutDialog
{
// Construction
	DECLARE_LAYOUT();
public:
	CProtocolEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProtocolEditDlg)
	enum { IDD = IDD_DLGPROTOCOL };
	CString	m_Edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProtocolEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProtocolEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROTOCOLEDITDLG_H__3EE225FC_BDEC_4093_A4CA_CF5D0EA64548__INCLUDED_)
