// MyCommView.h : interface of the CMyCommView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_)
#define AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CommAdvancedDlg.h"
#include "ETSLayout.h"
#include "EditLog.h"
#include "MyEditEx.h"


class CMyCommView : public ETSLayoutFormView
{
protected: // create from serialization only
	CMyCommView();
	DECLARE_DYNCREATE(CMyCommView)
public:
	//{{AFX_DATA(CMyCommView)
	enum { IDD = IDD_MYCOMM_FORM };
	CButton	m_CheckData;
	CButton	m_ctrlOpenComm;
	CButton	m_ctrlSendScript;
	CMyEditEx	m_ctrlReciveData;
	CComboBox	m_ctrlCommand;
	CButton	m_ctrlAutoSend;
	CComboBox	m_ctrlStopBits;
	CComboBox	m_ctrlParity;
	CComboBox	m_ctrlDataBits;
	CComboBox	m_ctrlCOM;
	CComboBox	m_ctrlBaudRate;
	CButton	m_ctrlSendHex;
	CButton	m_ctrlReceiveHex;
	CString	m_strSendData;
	int		m_AutoSendTime;
	CString	m_ReceiveValue;
	//}}AFX_DATA

	BOOL m_IsViewReceiveData; 
	CheckDataStyle m_CheckDataStyle;

// Attributes
public:
	CMyCommDoc* GetDocument();
	CEditLog  m_EditLogger; 
	BOOL m_IsShowValueWindow; 

// Operations
public:
	void ShowMsg(CString strMsg);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCommView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCommView();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CToolTipCtrl m_hint;
	int m_CurrenthistoryIndex;   

	int DoStr2Hex(CString str,char* data);
	char DoHexChar(char c);
	BOOL DoIsNumeric(const CString &strText);
	void DoRunScript(const CString str);
	void DoUpdateLayout();
	HICON DoGetButtonIcon(UINT nID);
	CString DoGetReciveSelected();
	unsigned short DoCreateCRC(unsigned char *CommData, unsigned int uLen );
// Generated message map functions

protected:
	
	//{{AFX_MSG(CMyCommView)
	afx_msg void OnBtopencomm();
	afx_msg void OnBtadvanced();
	afx_msg void OnChrevhex();
	afx_msg void OnChsendhex();
	afx_msg void OnBtSend();
	afx_msg void OnBtviewprotocol();
	afx_msg void OnBtclearreceivedata();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnChautosend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LONG OnCommunication(WPARAM ch, LPARAM port);
	afx_msg void OnSelchangeCbcommand();
	afx_msg void OnBtsaverecdata();
	afx_msg void OnBtviewrecdata();
	afx_msg void OnBtsendkey();
	afx_msg void OnSendkeyNone();
	afx_msg void OnSendkeyEnter();
	afx_msg void OnSendkeyShiftenter();
	afx_msg void OnBtvisiblevalue();
	afx_msg void OnUpdateEdrecdatavalue();
	afx_msg void OnBtclearrxtx();
	afx_msg void OnBtsendclear();
	afx_msg void OnBtsendup();
	afx_msg void OnBtsenddown();
	afx_msg void OnBtcalc();
	afx_msg void OnBtchecksum();
	afx_msg void OnBtcheckdata();
	afx_msg void OnCheckSum();
	afx_msg void OnCheckCrc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyCommView.cpp
inline CMyCommDoc* CMyCommView::GetDocument()
   { return (CMyCommDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMMVIEW_H__DD229253_5846_46A3_82FC_CFF51F4C1FA5__INCLUDED_)
