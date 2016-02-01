// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__1AD07C2D_D534_4B2A_A63C_FACE7390D292__INCLUDED_)
#define AFX_MAINFRM_H__1AD07C2D_D534_4B2A_A63C_FACE7390D292__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CommandDlg.h"
#include "MyCommDoc.h"
#include "ProtocolEditDlg.h"
#include "SendFileByXModem.h"


class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	Language m_language;
	CStatusBar  m_wndStatusBar;
	BOOL  m_IsNewVertxt;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void ActivateFrame(int nCmdShow = -1);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
	BOOL DonwLoadFile(PSTR pURL, LPSTR SaveAsFilePath);
	void ShowMessage(CString strMsg);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	
	BOOL m_firstShow;

	//thread
	HANDLE hThread;
	DWORD ThreadID;


// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnEditCommand();
	afx_msg void OnEditProtocol();
	afx_msg void OnHelpScript();
	afx_msg void OnAppSnedmail();
	afx_msg void OnAppUpgrade();
	afx_msg void OnAppHome();
	afx_msg void OnSendFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__1AD07C2D_D534_4B2A_A63C_FACE7390D292__INCLUDED_)
