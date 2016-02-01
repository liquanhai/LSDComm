#if !defined(AFX_SENDFILEBYXMODEM_H__D0265162_1EE4_40C3_A9AB_D0E9D005437F__INCLUDED_)
#define AFX_SENDFILEBYXMODEM_H__D0265162_1EE4_40C3_A9AB_D0E9D005437F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendFileByXModem.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendFileByXModem dialog

class CSendFileByXModem : public CDialog
{
// Construction
public:
	CSendFileByXModem(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSendFileByXModem)
	enum { IDD = IDD_DLGSENDFILE };
	CString	m_SendFileName;
	int		m_ModemType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendFileByXModem)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendFileByXModem)
	afx_msg void OnBtselectfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDFILEBYXMODEM_H__D0265162_1EE4_40C3_A9AB_D0E9D005437F__INCLUDED_)
