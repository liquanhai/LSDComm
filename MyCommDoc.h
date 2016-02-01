// MyCommDoc.h : interface of the CMyCommDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCOMMDOC_H__82C943F9_55E4_4E3A_9F44_4F7FB6E5A707__INCLUDED_)
#define AFX_MYCOMMDOC_H__82C943F9_55E4_4E3A_9F44_4F7FB6E5A707__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SerialPort.h"

//XModem
#define XMODEM_NUL            0x00
#define XMODEM_SOH            0x01
#define XMODEM_STX            0x02
#define XMODEM_EOT            0x04
#define XMODEM_ACK            0x06
#define XMODEM_NAK            0x15
#define XMODEM_CAN            0x18
#define XMODEM_EOF            0x1A
#define XMODEM_STA            0xAA

#define XMODEM_BLOCK_HEAD_SIZE      1
#define XMODEM_BLOCK_NO_SIZE        2
#define XMODEM_BLOCK_BODY_SIZE      128
#define XMODEM_BLOCK_CHK_SIZE       1


const COMMANDCOUNT = 20; 

struct CommCommand {
	CString m_strName;
	CString m_strCommand;
	BOOL  m_IsHex;  //is Hex
	BOOL  m_isScript; 
} ;

struct CommTimeout{
	WORD ReadIntervalTimeout;
	WORD ReadTotalTimeoutMultiplier;
	WORD ReadTotalTimeoutConstant;
	WORD WriteTotalTimeoutMultiplier;
	WORD WriteTotalTimeoutConstant;
};

class CMyCommDoc : public CDocument
{
protected: // create from serialization only
	CMyCommDoc();
	DECLARE_DYNCREATE(CMyCommDoc)

// Attributes
protected:
	int m_historyIndex;   
	
public:
	CSerialPort m_Comm;
	BOOL m_ComAction;
	int m_intPort;  
	int m_intBaudRate;
	int m_intDataBits  ;  
	char m_cParity   ;    // 0 ,1,2 
	int m_intStopBits;    // 0=1 1=1.5 2=2
	CommTimeout m_CommTimeout;
	CommCommand m_Command[COMMANDCOUNT];

	BOOL m_IsReceiveHex;
	BOOL m_IsSendHex;

	CString m_strReceiveData;
	CString m_strSendData;
	CString m_strProtocol;
	LONG  m_TXCount;
	LONG  m_RXCount;
	CString m_strReceiveValue;  //结果窗口值

	

	CommCommand m_HistoryCommand[COMMANDCOUNT];

// Operations
public:
	BOOL OpenComm(CWnd * POwner);
	void CloseComm();

	int AddHistory(CommCommand Command);
	int GetHistoryIndex();

	BOOL SendByXmodem(LPCTSTR lpszData, const int nLength, const int nRetryTimes);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCommDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCommDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyCommDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMMDOC_H__82C943F9_55E4_4E3A_9F44_4F7FB6E5A707__INCLUDED_)





















