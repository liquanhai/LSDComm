// MyComm.h : main header file for the MYCOMM application
//

#if !defined(AFX_MYCOMM_H__2773D06E_03EF_40DD_A120_69FCB7ED9933__INCLUDED_)
#define AFX_MYCOMM_H__2773D06E_03EF_40DD_A120_69FCB7ED9933__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

enum SendKeyStyle {SKNONE=0,SKENTER,SKSHIFTENTER};
enum StatusBarStyle{SBSINFO=0,SBSTX,SBSRX,SBSCOMM,SBSSENDKEY};
enum CheckDataStyle{CDSSUM=0,CDSCRC};
enum Language { LACHINA = 0, LACHINAS ,LAENGLISH};


/////////////////////////////////////////////////////////////////////////////
// CMyCommApp:
// See MyComm.cpp for the implementation of this class
//

class CMyCommApp : public CWinApp
{
public:
	CMyCommApp();
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCommApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyCommApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	SendKeyStyle       m_SendkeyType;  
	CString            m_ScriptHelp;
	CString            m_AppDir;
	CString            m_AppVersion;
	CString            m_downfileexefilename;
public:
	void DoSetStautsBarText(UINT index,CString Value);



};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMM_H__2773D06E_03EF_40DD_A120_69FCB7ED9933__INCLUDED_)
