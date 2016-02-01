#if !defined(AFX_COMMADVANCEDDLG_H__AA839B69_391E_4650_8A5A_69183A95C6DA__INCLUDED_)
#define AFX_COMMADVANCEDDLG_H__AA839B69_391E_4650_8A5A_69183A95C6DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CommAdvancedDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommAdvancedDlg dialog

class CCommAdvancedDlg : public CDialog
{
// Construction
public:
	CCommAdvancedDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCommAdvancedDlg)
	enum { IDD = IDD_DLGADVANCED };
	DWORD	m_dwoReadInter;
	DWORD	m_dwoReadTotalMult;
	DWORD	m_dwoReadTotalConst;
	DWORD	m_dwoWriteTotalMult;
	DWORD	m_dwoWriteTotalConst;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommAdvancedDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommAdvancedDlg)
	afx_msg void OnBtdefault();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMADVANCEDDLG_H__AA839B69_391E_4650_8A5A_69183A95C6DA__INCLUDED_)
