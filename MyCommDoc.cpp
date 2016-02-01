// MyCommDoc.cpp : implementation of the CMyCommDoc class
//

#include "stdafx.h"
#include "MyComm.h"

#include "MyCommDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc

IMPLEMENT_DYNCREATE(CMyCommDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyCommDoc, CDocument)
	//{{AFX_MSG_MAP(CMyCommDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc construction/destruction

CMyCommDoc::CMyCommDoc()
{
	// TODO: add one-time construction code here
	m_ComAction = FALSE;

	m_intPort     = 1;
	m_intBaudRate = 9600;
	m_intDataBits = 8;
	m_cParity     ='N';
	m_intStopBits = 0;

	m_IsReceiveHex = TRUE;
	m_IsSendHex = TRUE;
	m_CommTimeout.ReadIntervalTimeout = 1;  //units ms
	m_CommTimeout.ReadTotalTimeoutMultiplier = 0;
	m_CommTimeout.ReadTotalTimeoutConstant = 0;
	m_CommTimeout.WriteTotalTimeoutMultiplier = 0;
	m_CommTimeout.WriteTotalTimeoutConstant = 0;

	m_TXCount = 0;
	m_RXCount = 0;
	int i;
	for(i=0;i<COMMANDCOUNT;i++)
	{
		m_Command[i].m_IsHex = FALSE;
		m_Command[i].m_isScript = FALSE;
	}
	
	m_historyIndex = 0;

}

CMyCommDoc::~CMyCommDoc()
{
}

BOOL CMyCommDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc serialization

void CMyCommDoc::Serialize(CArchive& ar)
{
	//
	// 2. 去掉快捷键 2008-1-14
	// 3. 增加是否是脚本功能,及16进制 2008-1-15
	// 4. 增加结果窗口的值 2008-1-18
	//
	//
	int ver; 
	int count;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		
		ver = 5;
		ar<<ver;  //version
		ar<<m_intPort;
		ar<<m_intBaudRate;
		ar<<m_intStopBits;
		ar<<m_intStopBits;
		ar<<m_cParity;
		ar<<m_intDataBits;
		
		//Timeout
		ar<<m_CommTimeout.ReadIntervalTimeout;
		ar<<m_CommTimeout.ReadTotalTimeoutMultiplier;
		ar<<m_CommTimeout.ReadTotalTimeoutConstant;
		ar<<m_CommTimeout.WriteTotalTimeoutMultiplier;
		ar<<m_CommTimeout.WriteTotalTimeoutConstant;
		
		count = COMMANDCOUNT;
		ar<<count;
		for(int i=0;i<count-1;i++)
		{
			ar<<m_Command[i].m_strName;
			//ar<<m_Command[i].m_ShutChar; ver=2 去掉
			ar<<m_Command[i].m_strCommand;
			ar<<m_Command[i].m_IsHex;  //ver=3
			ar<<m_Command[i].m_isScript; //ver=3
					
		};

		ar<<m_IsReceiveHex;
		ar<<m_IsSendHex;
		ar<<m_strProtocol;
		ar<< m_strReceiveValue; //ver=4 2008-1-18

				
	}
	else
	{
		// TODO: add loading code here
		ar>>ver;
		ar>>m_intPort;
		ar>>m_intBaudRate;
		ar>>m_intStopBits;
		ar>>m_intStopBits;
		ar>>m_cParity;
		ar>>m_intDataBits;

		//Timeout
		ar>>m_CommTimeout.ReadIntervalTimeout;
		ar>>m_CommTimeout.ReadTotalTimeoutMultiplier;
		ar>>m_CommTimeout.ReadTotalTimeoutConstant;
		ar>>m_CommTimeout.WriteTotalTimeoutMultiplier;
		ar>>m_CommTimeout.WriteTotalTimeoutConstant;

		ar>>count;
		for(int i=0;i<count-1;i++)
		{
			ar>>m_Command[i].m_strName;
			if (ver < 2) 
			{
				char myc;
				ar>>myc;
			}
			ar>>m_Command[i].m_strCommand;
			if (ver>2)
			{
				ar>>m_Command[i].m_IsHex;
				ar>>m_Command[i].m_isScript;
			}	
		};

		ar>>m_IsReceiveHex;
		ar>>m_IsSendHex;
		ar>>m_strProtocol;

		//ver=4
		if (ver>3)
		{
			ar>>m_strReceiveValue;
		}
		


	};
}

BOOL CMyCommDoc::OpenComm(CWnd * POwner)
{
	if (m_Comm.InitPort(POwner->m_hWnd,m_intPort,m_intBaudRate,m_cParity,
		m_intDataBits,m_intStopBits
		/*
		m_CommTimeout.ReadIntervalTimeout,
		m_CommTimeout.ReadTotalTimeoutConstant,
		m_CommTimeout.ReadTotalTimeoutMultiplier,
		m_CommTimeout.WriteTotalTimeoutMultiplier,
		m_CommTimeout.WriteTotalTimeoutConstant*/))
	{
		m_Comm.StartMonitoring();
		return TRUE;
	}
	else
		return FALSE;
}
void CMyCommDoc::CloseComm()
{
	m_Comm.ClosePort();
	m_Comm.StopMonitoring();
}

int CMyCommDoc::AddHistory(CommCommand Command)
{
	if (m_historyIndex>=COMMANDCOUNT)  //=20
	{	
		CommCommand myCommand;
		for (int i=1;i<COMMANDCOUNT;i++)
		{
			m_HistoryCommand[i-1].m_IsHex = m_HistoryCommand[i].m_IsHex;
			m_HistoryCommand[i-1].m_isScript = m_HistoryCommand[i].m_isScript;
			m_HistoryCommand[i-1].m_strCommand = m_HistoryCommand[i].m_strCommand;
			m_HistoryCommand[i-1].m_strName = m_HistoryCommand[i].m_strName;
		}
		// end
		m_HistoryCommand[m_historyIndex-1].m_IsHex = Command.m_IsHex;
		m_HistoryCommand[m_historyIndex-1].m_isScript = Command.m_isScript;
		m_HistoryCommand[m_historyIndex-1].m_strCommand = Command.m_strCommand;
		m_HistoryCommand[m_historyIndex-1].m_strName = Command.m_strName;
	}
	else{
		m_HistoryCommand[m_historyIndex].m_IsHex = Command.m_IsHex;
		m_HistoryCommand[m_historyIndex].m_isScript = Command.m_isScript;
		m_HistoryCommand[m_historyIndex].m_strCommand = Command.m_strCommand;
		m_HistoryCommand[m_historyIndex].m_strName = Command.m_strName;
		m_historyIndex++;
	}	
	return m_historyIndex;
	
}

int CMyCommDoc::GetHistoryIndex()
{
	return m_historyIndex;
}

// bool SendData(LPCTSTR lpszData, const int nLength)    - 串口发送函数
// int RecvData(LPTSTR lpszData, const int nSize)    - 串口接收函数
BOOL CMyCommDoc::SendByXmodem(LPCTSTR lpszData, const int nLength, const int nRetryTimes)
{
	char szPacket[XMODEM_BLOCK_HEAD_SIZE + XMODEM_BLOCK_NO_SIZE + 
		  XMODEM_BLOCK_BODY_SIZE + XMODEM_BLOCK_CHK_SIZE];
    char szRecvBuff[128];
    char cPartNo = 0;
    char cChkSum = 0;
    int nRetry   = 0;
    int nTemp1, nTemp2;
	
    // Notify Destination of Data Transfer
    sprintf(szPacket, "%c", XMODEM_STA);
    m_Comm.SendData(szPacket, 1);
	Sleep(100);
    if (m_Comm.RecvData(szRecvBuff, sizeof(szRecvBuff)) && szRecvBuff[0] == XMODEM_NAK)
    {
		// Send Data
		for (nTemp1 = 0; nTemp1 < nLength; nTemp1 += XMODEM_BLOCK_BODY_SIZE)
		{

			//1.Make One Packet 
			memset(szPacket, NULL, sizeof(szPacket));
			if (cPartNo == 0xFF)
				cPartNo = 0;
			else
				cPartNo++;
			cChkSum = 0;
			szPacket[0] = XMODEM_SOH;
			szPacket[1] = cPartNo;
			szPacket[2] = 0xFF - cPartNo;
			for (nTemp2 = 0; nTemp2 < XMODEM_BLOCK_BODY_SIZE; nTemp2++)
			{
				if ((nTemp1 + nTemp2) < nLength)
					szPacket[XMODEM_BLOCK_HEAD_SIZE + XMODEM_BLOCK_NO_SIZE + nTemp2] = *(lpszData + nTemp1 + nTemp2);
				else
					szPacket[XMODEM_BLOCK_HEAD_SIZE + XMODEM_BLOCK_NO_SIZE + nTemp2] = XMODEM_EOF;
				cChkSum += szPacket[XMODEM_BLOCK_HEAD_SIZE + XMODEM_BLOCK_NO_SIZE + nTemp2];
			}
			szPacket[sizeof(szPacket) - 1] = cChkSum;

			//2.Send Packet
			m_Comm.SendData(szPacket, sizeof(szPacket));
			while (true)
			{
				Sleep(10);
				if (m_Comm.RecvData(szRecvBuff, sizeof(szRecvBuff)))
				{
					// Affirmative Answer
					if (szRecvBuff[0] == XMODEM_ACK)
						break;
					// Negative Answer
					else
						if (szRecvBuff[0] == XMODEM_NAK)
						{
							m_Comm.SendData(szPacket, sizeof(szPacket));
							nRetry++;
						}
				}
				if (nRetry >= nRetryTimes)
				{
					// Cancel Transfer
					sprintf(szPacket, "%c%c%c%c%c", XMODEM_CAN, XMODEM_CAN, XMODEM_CAN, XMODEM_CAN, XMODEM_CAN);
					m_Comm.SendData(szPacket, 5);
					return false;
				}
			}
		} // end form
	} //end if
	
    // Transfer Done
    sprintf(szPacket, "%c%c%c%c%c", XMODEM_EOT, XMODEM_EOT, XMODEM_EOT, XMODEM_EOT, XMODEM_EOT);
    m_Comm.SendData(szPacket, 5);
    return true;	
}
/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc diagnostics

#ifdef _DEBUG
void CMyCommDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyCommDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCommDoc commands





















