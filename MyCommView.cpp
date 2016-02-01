// MyCommView.cpp : implementation of the CMyCommView class
//

#include "stdafx.h"
#include "MyComm.h"

#include "MyCommDoc.h"
#include "MyCommView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CMyCommView

IMPLEMENT_DYNCREATE(CMyCommView, CFormView)

BEGIN_MESSAGE_MAP(CMyCommView, CFormView)
	//{{AFX_MSG_MAP(CMyCommView)
	ON_BN_CLICKED(IDC_BTOPENCOMM, OnBtopencomm)
	ON_BN_CLICKED(IDC_BTADVANCED, OnBtadvanced)
	ON_BN_CLICKED(IDC_CHREVHEX, OnChrevhex)
	ON_BN_CLICKED(IDC_CHSENDHEX, OnChsendhex)
	ON_BN_CLICKED(IDC_BTSEND, OnBtSend)
	ON_BN_CLICKED(IDC_BTVIEWPROTOCOL, OnBtviewprotocol)
	ON_BN_CLICKED(IDC_BTCLEARRECEIVEDATA, OnBtclearreceivedata)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_CHAUTOSEND, OnChautosend)
	ON_WM_TIMER()
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommunication)
	ON_CBN_SELCHANGE(IDC_CBCOMMAND, OnSelchangeCbcommand)
	ON_BN_CLICKED(IDC_BTSAVERECDATA, OnBtsaverecdata)
	ON_BN_CLICKED(IDC_BTVIEWRECDATA, OnBtviewrecdata)
	ON_BN_CLICKED(IDC_BTSENDKEY, OnBtsendkey)
	ON_COMMAND(ID_SENDKEY_NONE, OnSendkeyNone)
	ON_COMMAND(ID_SENDKEY_ENTER, OnSendkeyEnter)
	ON_COMMAND(ID_SENDKEY_SHIFTENTER, OnSendkeyShiftenter)
	ON_BN_CLICKED(IDC_BTVISIBLEVALUE, OnBtvisiblevalue)
	ON_EN_UPDATE(IDC_EDRECDATAVALUE, OnUpdateEdrecdatavalue)
	ON_BN_CLICKED(IDC_BTCLEARRXTX, OnBtclearrxtx)
	ON_BN_CLICKED(IDC_BTSENDCLEAR, OnBtsendclear)
	ON_BN_CLICKED(IDC_BTSENDUP, OnBtsendup)
	ON_BN_CLICKED(IDC_BTSENDDOWN, OnBtsenddown)
	ON_BN_CLICKED(IDC_BTCALC, OnBtcalc)
	ON_BN_CLICKED(IDC_BTCHECKSUM, OnBtchecksum)
	ON_BN_CLICKED(IDC_BTCHECKDATA, OnBtcheckdata)
	ON_COMMAND(ID_CHECK_SUM, OnCheckSum)
	ON_COMMAND(ID_CHECK_CRC, OnCheckCrc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCommView construction/destruction

CMyCommView::CMyCommView()
	: ETSLayoutFormView(CMyCommView::IDD)   
{
	//{{AFX_DATA_INIT(CMyCommView)
	m_strSendData = _T("");
	m_AutoSendTime = 1000;
	m_ReceiveValue = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_hint.Create(this) ;
	m_IsViewReceiveData = TRUE;
	m_IsShowValueWindow = FALSE;
	m_CurrenthistoryIndex =0;
	m_CheckDataStyle = CDSSUM;
}

CMyCommView::~CMyCommView()
{
}

void CMyCommView::DoDataExchange(CDataExchange* pDX)
{
	ETSLayoutFormView::DoDataExchange(pDX);
	
	//{{AFX_DATA_MAP(CMyCommView)
	DDX_Control(pDX, IDC_BTCHECKSUM, m_CheckData);
	DDX_Control(pDX, IDC_BTOPENCOMM, m_ctrlOpenComm);
	DDX_Control(pDX, IDC_CHSCRIPT, m_ctrlSendScript);
	DDX_Control(pDX, IDC_EDRECDATA, m_ctrlReciveData);
	DDX_Control(pDX, IDC_CBCOMMAND, m_ctrlCommand);
	DDX_Control(pDX, IDC_CHAUTOSEND, m_ctrlAutoSend);
	DDX_Control(pDX, IDC_CBSTOPBITS, m_ctrlStopBits);
	DDX_Control(pDX, IDC_CBPARITY, m_ctrlParity);
	DDX_Control(pDX, IDC_CBDATABITS, m_ctrlDataBits);
	DDX_Control(pDX, IDC_CBCOM, m_ctrlCOM);
	DDX_Control(pDX, IDC_CBBANDRATE, m_ctrlBaudRate);
	DDX_Control(pDX, IDC_CHSENDHEX, m_ctrlSendHex);
	DDX_Control(pDX, IDC_CHREVHEX, m_ctrlReceiveHex);
	DDX_Text(pDX, IDC_EDSENDDATA, m_strSendData);
	DDX_Text(pDX, IDC_EDAUTOSENDTIME, m_AutoSendTime);
	DDX_Text(pDX, IDC_EDRECDATAVALUE, m_ReceiveValue);
	//}}AFX_DATA_MAP
}

BOOL CMyCommView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return ETSLayoutFormView::PreCreateWindow(cs);
	
}

void CMyCommView::OnInitialUpdate()
{
	ModifyStyleEx(0,  WS_EX_STATICEDGE);
    ModifyStyleEx(WS_EX_CLIENTEDGE,0 );
	
	ETSLayoutFormView::OnInitialUpdate();
	
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	if (GetDocument()->m_ComAction)
	{
		GetDocument()->CloseComm();
	}
	
	m_EditLogger.SetEditCtrl( m_ctrlReciveData.m_hWnd );

	m_ctrlReceiveHex.SetCheck(GetDocument()->m_IsReceiveHex);
	m_ctrlSendHex.SetCheck(GetDocument()->m_IsSendHex);
	CString mystr;
	m_ctrlCOM.SetCurSel(GetDocument()->m_intPort-1);
	mystr.Format("%d",GetDocument()->m_intBaudRate); 
	m_ctrlBaudRate.SetCurSel(m_ctrlBaudRate.FindString(0,mystr));
	mystr.Format("%d",GetDocument()->m_intDataBits);
	m_ctrlDataBits.SetCurSel(m_ctrlDataBits.FindString(0,mystr));

	switch(GetDocument()->m_cParity)
	{
		case 'N':
			m_ctrlParity.SetCurSel(0);
			break;
		case 'O':
			m_ctrlParity.SetCurSel(1);
			break;
		case 'E':
			m_ctrlParity.SetCurSel(2);
			break;
		case 'M':
			m_ctrlParity.SetCurSel(3);
			break;
		case 'S':
			m_ctrlParity.SetCurSel(4);
			break;

	}
	m_ctrlStopBits.SetCurSel(GetDocument()->m_intStopBits); 

	// send botton
	BOOL myAction = FALSE;
	GetDlgItem(IDC_BTSEND)->EnableWindow(myAction);
	
	// com param
	GetDlgItem(IDC_CBCOM)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBBANDRATE)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBDATABITS)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBPARITY)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBSTOPBITS)->EnableWindow(!myAction);
	GetDlgItem(IDC_BTADVANCED)->EnableWindow(!myAction);
	
	
	//layout
	DoUpdateLayout();

	//hint
	EnableToolTips(TRUE);
	m_hint.Activate(TRUE);
	m_hint.AddTool(GetDlgItem(IDC_CBCOMMAND),_T("选择要发送的指令，并点发送。"));
	m_hint.AddTool(GetDlgItem(IDC_BTSENDKEY),_T("设置发送的快捷键。"));
	m_hint.AddTool(GetDlgItem(IDC_BTCLEARRXTX),_T("清空计数RX,TX"));
	m_hint.AddTool(GetDlgItem(IDC_BTSENDCLEAR),_T("清空发送内容。"));
	m_hint.AddTool(GetDlgItem(IDC_BTSENDUP),_T("发送指令的上一条内容。"));
	m_hint.AddTool(GetDlgItem(IDC_BTSENDDOWN),_T("发送指令的下一条内容。"));
	m_hint.AddTool(GetDlgItem(IDC_BTCALC),_T("计算器"));
	m_hint.AddTool(GetDlgItem(IDC_BTCHECKSUM),_T("接收窗口选择的内容进行数据校验。"));
	m_hint.AddTool(GetDlgItem(IDC_BTCHECKDATA),_T("更多的校检方法。"));
		
	m_hint.SetTipTextColor(RGB(0,0,0));  
	m_hint.SetDelayTime(100);     
	
	//command combox
	CString myCommandStr;
	m_ctrlCommand.ResetContent();
	for(int i=0 ;i<COMMANDCOUNT ;i++)
	{
		if (!GetDocument()->m_Command[i].m_strName.IsEmpty())
		{
			myCommandStr.Format("%d %s",i+1,GetDocument()->m_Command[i].m_strName);
			m_ctrlCommand.AddString(myCommandStr);
		}
	}
	
	//send key
	CMyCommApp * myApp = (CMyCommApp * )AfxGetApp();
	switch(myApp->m_SendkeyType)
	{
	case SKENTER:
		{
			CButton * mybt = (CButton *) GetDlgItem(IDC_BTSEND);
			mybt->SetWindowText("发送 E");
			break;
		}	
	case SKSHIFTENTER:
		{
			CButton * mybt = (CButton *) GetDlgItem(IDC_BTSEND);
			mybt->SetWindowText("发送 S");
			break;
		}
	default:
		break;
	}

	//icon
	CButton *Button= (CButton *) GetDlgItem(IDC_BTCLEARRXTX);;
    Button-> SetIcon(DoGetButtonIcon(IDI_ICONCLEAR));
	Button= (CButton *) GetDlgItem(IDC_BTCALC);
    Button-> SetIcon(DoGetButtonIcon(IDI_ICONCALC));
	
	

	//value
	m_ReceiveValue = GetDocument()->m_strReceiveValue;
	m_CheckDataStyle = CDSSUM;
	m_CheckData.SetWindowText(_T("累加和"));
	

	UpdateData(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CMyCommView diagnostics

#ifdef _DEBUG
void CMyCommView::AssertValid() const
{
	ETSLayoutFormView::AssertValid();
}

void CMyCommView::Dump(CDumpContext& dc) const
{
	ETSLayoutFormView::Dump(dc);
}

CMyCommDoc* CMyCommView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCommDoc)));
	return (CMyCommDoc*)m_pDocument;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCommView message handlers

void CMyCommView::OnBtopencomm() 
{
	// TODO: Add your control notification handler code here
	if (GetDocument()->m_ComAction) 
	{
		GetDocument()->CloseComm();

		m_ctrlOpenComm.SetWindowText(_T(" 打开串口"));
		GetDocument()->m_ComAction = FALSE;
		CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
		myApp->DoSetStautsBarText(SBSCOMM,_T("串口:×"));
	}
	else{
		
		CString mystr;
		char myc;		

		if (m_ctrlCOM.GetCurSel()<0) 
		{
			AfxMessageBox(_T("请选择串口"));
			return ;
		}	
		GetDocument()->m_intPort = m_ctrlCOM.GetCurSel()+1;
		m_ctrlBaudRate.GetWindowText(mystr);
		if (!DoIsNumeric(mystr)) 
		{	
			AfxMessageBox(_T("请选择波特率"));
			return;
		}	
		GetDocument()->m_intBaudRate = atoi(mystr);
		m_ctrlDataBits.GetWindowText(mystr);
		if (!DoIsNumeric(mystr)) 
		{
			AfxMessageBox(_T("请选择数据位"));
			return;
		}	
		GetDocument()->m_intDataBits = atoi(mystr);
		
		myc = 'N';
		int i=m_ctrlParity.GetCurSel();
		switch(i)
		{
		case 0:
			myc='N';
			break;
		case 1:
			myc='O';
			break;
		case 2:
			myc='E';
			break;
		case 3:
			myc='M';
			break;
		case 4:
			myc='S';
			break;
		}
		GetDocument()->m_cParity=myc;
		
		if (m_ctrlStopBits.GetCurSel()<0) 
		{
			AfxMessageBox(_T("请选择停止位"));
			return;
		}	
		GetDocument()->m_intStopBits = m_ctrlStopBits.GetCurSel();  //index 表示
		
		if (GetDocument()->OpenComm(this))
		{	
			CBitmap myBitmap;
			myBitmap.LoadBitmap(IDB_BITMAPOPENCOM);
			m_ctrlOpenComm.SetBitmap(myBitmap);
			m_ctrlOpenComm.SetWindowText(_T("关闭串口"));
			GetDocument()->m_ComAction = TRUE;
			CEdit * myedit = (CEdit *)GetDlgItem(IDC_EDSENDDATA);
			myedit->SetFocus();
			CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
			myApp->DoSetStautsBarText(SBSCOMM,_T("串口:√"));
		}
		else
			AfxMessageBox(_T("串口被占用！"));
	}

	// send botton
	BOOL myAction = GetDocument()->m_ComAction;
	GetDlgItem(IDC_BTSEND)->EnableWindow(myAction);
	
	// com param
	GetDlgItem(IDC_CBCOM)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBBANDRATE)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBDATABITS)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBPARITY)->EnableWindow(!myAction);
	GetDlgItem(IDC_CBSTOPBITS)->EnableWindow(!myAction);
	GetDlgItem(IDC_BTADVANCED)->EnableWindow(!myAction);
	
}

int CMyCommView::DoStr2Hex(CString str,char* data)
{
	int t,t1;
	int rlen=0,len=str.GetLength();
	for (int i=0;i<len;)
	{
		char l,h=str[i];
		if(h==' ')
		{
			i++;
			continue;
		}
		i++;
		if(i>=len) break;
		l=str[i];
		t=DoHexChar(h);
		t1=DoHexChar(l);
		if((t==16)||(t1==16))
			break;
		else 
			t=t*16+t1;
		i++;
		data[rlen]=(char)t;
		rlen++;
	}
	return rlen;
}

char CMyCommView::DoHexChar(char c)
{
	if((c>='0')&&(c<='9'))
		return c-0x30;
	else if((c>='A')&&(c<='F'))
		return c-'A'+10;
	else if((c>='a')&&(c<='f'))
		return c-'a'+10;
	else
		return 0x10;
}

void CMyCommView::OnBtadvanced() 
{
	// TODO: Add your control notification handler code here
	CCommAdvancedDlg dlg;
	
	dlg.m_dwoReadInter       = GetDocument()->m_CommTimeout.ReadIntervalTimeout;
	dlg.m_dwoReadTotalMult   = GetDocument()->m_CommTimeout.ReadTotalTimeoutMultiplier;
	dlg.m_dwoReadTotalConst  = GetDocument()->m_CommTimeout.ReadTotalTimeoutConstant;
	dlg.m_dwoWriteTotalMult  = GetDocument()->m_CommTimeout.WriteTotalTimeoutMultiplier;
	dlg.m_dwoWriteTotalConst = GetDocument()->m_CommTimeout.WriteTotalTimeoutConstant;
	if (dlg.DoModal()==IDOK)
	{
		
		GetDocument()->m_CommTimeout.ReadIntervalTimeout = 	WORD(dlg.m_dwoReadInter);
		GetDocument()->m_CommTimeout.ReadTotalTimeoutMultiplier = WORD(dlg.m_dwoReadTotalMult);
		GetDocument()->m_CommTimeout.ReadTotalTimeoutConstant = WORD(dlg.m_dwoReadTotalConst);
		GetDocument()->m_CommTimeout.WriteTotalTimeoutMultiplier = WORD(dlg.m_dwoWriteTotalMult);
		GetDocument()->m_CommTimeout.WriteTotalTimeoutConstant = WORD(dlg.m_dwoWriteTotalConst);
	}

}

void CMyCommView::OnChrevhex() 
{
	// TODO: Add your control notification handler code here
	if (m_ctrlReceiveHex.GetCheck())
		GetDocument()->m_IsReceiveHex = TRUE;
	else
		GetDocument()->m_IsReceiveHex = FALSE;	
}

void CMyCommView::OnChsendhex() 
{
	// TODO: Add your control notification handler code here
	if (m_ctrlSendHex.GetCheck())
		GetDocument()->m_IsSendHex = TRUE;
	else
		GetDocument()->m_IsSendHex = FALSE;			
}

void CMyCommView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
}


BOOL CMyCommView::DoIsNumeric(const CString &strText)
{
	BOOL  bRet=TRUE;  
	int   nLen=strText.GetLength();  
	if(strText.IsEmpty())  
	{  
		bRet =  FALSE;
	} 
	
	for(int i=0;i<nLen;i++)  
	{  
		bRet=(_istdigit(strText.GetAt(i)) != 0);  
		if(!bRet)  
			break;  
	}  
	return   bRet;  
}

void CMyCommView::OnBtSend() 
{
	// TODO: Add your control notification handler code here
	if (!GetDocument()->m_ComAction) 
	{
		return;
	}
	UpdateData(TRUE);
	
	int i;

	
	if(m_ctrlSendScript.GetCheck())
	{
		CString mycommand;
		CString myscript;
		char myc;
		mycommand.Empty();
		myscript = this->m_strSendData;
		for(i=0;i<myscript.GetLength();i++)
		{
			myc = myscript[i];
			if (myc==';')
			{
				DoRunScript(mycommand);
				mycommand.Empty();
			}	
			else{
				if ((myc != '\n') && (myc != '\r')) {mycommand += myc;}
			}
			
		}
			 
	}
	else if(m_ctrlSendHex.GetCheck())
	{
		char data[512];
		int len=DoStr2Hex(m_strSendData,data);
		GetDocument()->m_Comm.WriteToPort(data,len);
		GetDocument()->m_RXCount+=(long)((m_strSendData.GetLength()+1)/3);
		CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
		CString str;
		str.Format("TX:%d",GetDocument()->m_RXCount);
		myApp->DoSetStautsBarText(SBSTX,str);
	}
	else 
	{
		GetDocument()->m_Comm.WriteToPort((LPCTSTR)m_strSendData);	//发送数据
		GetDocument()->m_RXCount+=m_strSendData.GetLength();
		CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
		CString str;
		str.Format("TX:%d",GetDocument()->m_RXCount);
		myApp->DoSetStautsBarText(SBSTX,str);
	}
	
	CommCommand myCommand;
	myCommand.m_IsHex = m_ctrlSendHex.GetCheck();
	myCommand.m_isScript = m_ctrlSendScript.GetCheck();
	myCommand.m_strCommand = m_strSendData;
	m_CurrenthistoryIndex = GetDocument()->AddHistory(myCommand);
}

void CMyCommView::OnBtviewprotocol() 
{
	// TODO: Add your control notification handler code here
	if (!GetDocument()->m_strProtocol.IsEmpty())
		m_EditLogger.AddText( "\n\r" + GetDocument()->m_strProtocol );
	else
		m_EditLogger.AddText(_T("\n\r无串口通信协议内容\n\r"));
		
	UpdateData(FALSE);
	
}

void CMyCommView::OnBtclearreceivedata() 
{
	// TODO: Add your control notification handler code here
	HWND hEdit = m_ctrlReciveData.m_hWnd;
	
	BOOL bReadOnly = ::GetWindowLong( hEdit, GWL_STYLE ) & ES_READONLY;
	if( bReadOnly )
		::SendMessage( hEdit, EM_SETREADONLY, FALSE, 0 );
	::SendMessage( hEdit, EM_SETSEL, 0, -1 );
	::SendMessage( hEdit, WM_CLEAR, 0, 0 );
	if( bReadOnly )
		::SendMessage( hEdit, EM_SETREADONLY, TRUE, 0 );
}


void CMyCommView::OnSize(UINT nType, int cx, int cy) 
{
	ETSLayoutFormView::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
}


BOOL CMyCommView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_hint.RelayEvent(pMsg);
	if ( GetFocus()!=NULL && GetFocus()->GetDlgCtrlID() == IDC_EDSENDDATA)
	{
		CMyCommApp * myApp = (CMyCommApp * )AfxGetApp();
		// enter
		if( myApp->m_SendkeyType == SKENTER && pMsg->wParam==VK_RETURN && pMsg->message==WM_KEYDOWN)  
		{  
			OnBtSend();
			return   true; 			
		}   
		//shift + enter
		else if ( myApp->m_SendkeyType == SKSHIFTENTER && pMsg->wParam == VK_RETURN &&
			 GetKeyState(VK_SHIFT) && pMsg->message==WM_KEYDOWN)
		{
			OnBtSend();
			return true;
		}
	}
	
	return CFormView::PreTranslateMessage(pMsg);
}


void CMyCommView::OnChautosend() 
{
	// TODO: Add your control notification handler code here
	if (! GetDocument()->m_ComAction) return;
	UpdateData(TRUE);
	if (m_ctrlAutoSend.GetCheck())
		SetTimer(1,m_AutoSendTime,NULL);
	else
		KillTimer(1);
}

void CMyCommView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
		case 1:
			OnBtSend();
			break;
	}
	CFormView::OnTimer(nIDEvent);
}

LONG CMyCommView::OnCommunication(WPARAM ch, LPARAM port)
{
	
	if (m_IsViewReceiveData)
	{
		if (m_ctrlReceiveHex.GetCheck())
		{
			CString str;
			str.Format("%02X ",ch);
			m_EditLogger.AddText(str);
			
		}
		else{
			CString str;
			str.Format("%c",ch);
			m_EditLogger.AddText(str);
			
		}
		UpdateData(FALSE);
	}
	GetDocument()->m_RXCount++;
	CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
	CString str;
	str.Format("RX:%d",GetDocument()->m_RXCount);
	myApp->DoSetStautsBarText(SBSRX,str);
	m_ctrlReciveData.LineScroll(m_ctrlReciveData.GetLineCount());
	
	return 0;
}


void CMyCommView::OnSelchangeCbcommand() 
{
	// TODO: Add your control notification handler code here
	int myindex;
	myindex = m_ctrlCommand.GetCurSel();
	if (myindex>=0 && myindex < COMMANDCOUNT)
	{
		m_strSendData = GetDocument()->m_Command[myindex].m_strCommand;
		m_ctrlSendHex.SetCheck(GetDocument()->m_Command[myindex].m_IsHex);
		m_ctrlSendScript.SetCheck(GetDocument()->m_Command[myindex].m_isScript);	
		UpdateData(FALSE);
	}
}

void CMyCommView::OnBtsaverecdata() 
{
	// TODO: Add your control notification handler code here
    CFileDialog dlg(FALSE, NULL, ".txt",                       
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_NOCHANGEDIR, 
		"Txt (*.txt)|*.txt|All FIle (*.*)|*.*");
    if (dlg.DoModal() == IDOK)
    {
		CString strCmdLine = dlg.GetPathName();
		CString   str;  
		GetDlgItemText(IDC_EDRECDATA,   str);  
		FILE   *fp;  
		fp   =   fopen(strCmdLine,   "ab+");  
		if (fp )
		{  
			fwrite((LPCTSTR)str,   1,   str.GetLength(),   fp);  
			fclose(fp);  
		}
    }	
}

void CMyCommView::OnBtviewrecdata() 
{
	// TODO: Add your control notification handler code here
	m_IsViewReceiveData = !m_IsViewReceiveData;
	if (m_IsViewReceiveData)
	{
		CButton * myb = (CButton *) GetDlgItem(IDC_BTVIEWRECDATA);
		myb->SetWindowText(_T("停止显示"));
		m_EditLogger.AddText(_T("\r\n继续显示\r\n"));
	}
	else
	{
		CButton * myb = (CButton *) GetDlgItem(IDC_BTVIEWRECDATA);
		myb->SetWindowText(_T("继续显示"));
		m_EditLogger.AddText(_T("\r\n停止显示"));
	}
}

BOOL CMyCommView::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	return ETSLayoutFormView::DestroyWindow();
}

void CMyCommView::DoRunScript(const CString str)
{
	CString Commandstr;
	CString Paramsstr,SendStr;
	char data[512];
	int myindex;
	int commandindex;

	if (str.GetLength()==0){return;}
	if (str[0]=='#'){return;}  //注释行不处理。
	myindex = str.Find('=',0);
	if (myindex == -1) 
	{
		//有可能是无参数的命令
		Commandstr = str;
		Commandstr.MakeUpper();
		if ((Commandstr=="CLEAR") || (Commandstr=="DATE") || (Commandstr=="HELP"))	
		{
			Paramsstr.Empty();
		} 
		else
		{
			CString ErrorStr;
			ErrorStr.Format("\n\r语法出错1 %s\n\r",str);
			m_EditLogger.AddText(_T(ErrorStr));
			return;
		}
		
	}	
	else{
		Commandstr = str.Left(myindex);
		Paramsstr  = str.Right(str.GetLength()-myindex-1);
		Commandstr.MakeUpper();
	}	
	

	if (Commandstr=="SEND")
	{
		//内容可能有#1的情况
		if ((Paramsstr.GetLength()>0) && (Paramsstr[0]=='%'))
		{
			commandindex = atoi(Paramsstr.Right(Paramsstr.GetLength()-1))-1;
			if (GetDocument()->m_Command[commandindex].m_isScript)
			{
				CString ErrorStr;
				ErrorStr.Format("\n\r语法出错，脚本不能做SEND的参数。 %s\n\r",str);
				m_EditLogger.AddText(_T(ErrorStr));
				return;	
			}
			SendStr=GetDocument()->m_Command[commandindex].m_strCommand;	
		}	
		else{
			SendStr = Paramsstr;
		}
		
		if(m_ctrlSendHex.GetCheck())
		{
			int len=DoStr2Hex(SendStr,data);
			GetDocument()->m_Comm.WriteToPort(data,len);
			GetDocument()->m_RXCount+=(long)((SendStr.GetLength()+1)/3);
			CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
			CString str;
			str.Format("TX:%d",GetDocument()->m_RXCount);
			myApp->DoSetStautsBarText(SBSTX,str);
		}
		else{
			GetDocument()->m_Comm.WriteToPort((LPCTSTR)SendStr);	//发送数据
			GetDocument()->m_RXCount+=SendStr.GetLength();
			CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
			CString str;
			str.Format("TX:%d",GetDocument()->m_RXCount);
			myApp->DoSetStautsBarText(SBSTX,str);
		}
	}
	else if (Commandstr=="SLEEP")
	{
		Sleep(atoi(Paramsstr));
	}
	else if (Commandstr=="OUT")
	{
		//char   re[3]   =   {VK_RETURN,   0x0a};
		SendStr = Paramsstr;
		//SendStr.Replace("\n\r","abc");
		m_EditLogger.AddText(_T(SendStr));
	}
	else if (Commandstr =="DATE")
	{
		CTime time=CTime::GetCurrentTime(); 
		CString s;
		if (Paramsstr.IsEmpty())
			s = time.Format("%Y-%m-%d %H:%M:%S");
		else	
			s = time.Format(Paramsstr);
		m_EditLogger.AddText(s);
	}	
	else if (Commandstr == "CLEAR")
	{
		OnBtclearreceivedata();
	}
	else if (Commandstr == "HELP")
	{
		CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
		m_EditLogger.AddText(myApp->m_ScriptHelp);
	}
	else{
		CString ErrorStr;
		ErrorStr.Format("\n\r语法出错2 %s\n\r",str);
		m_EditLogger.AddText(_T(ErrorStr));
	}
		
}

void CMyCommView::OnBtsendkey() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	CPoint point;
	CButton * mybt = (CButton *)GetDlgItem(IDC_BTSENDKEY);
	mybt->GetWindowRect(rect);
    point.x = rect.right;
    point.y = rect.bottom;

	CMenu menu;
	VERIFY( menu.LoadMenu( IDR_MENU_SNEDKEY ) );
	CMenu* popup = menu.GetSubMenu(0);
	ASSERT( popup != NULL );
            popup->TrackPopupMenu(TPM_RIGHTALIGN| TPM_RIGHTBUTTON, point.x, point.y, this ); 
}

void CMyCommView::OnSendkeyNone() 
{
	// TODO: Add your command handler code here
	CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
	myApp->m_SendkeyType = SKNONE;
	CButton * mybt = (CButton *) GetDlgItem(IDC_BTSEND);
	mybt->SetWindowText(_T("发送"));
	myApp->DoSetStautsBarText(SBSSENDKEY,"无");
}

void CMyCommView::OnSendkeyEnter() 
{
	// TODO: Add your command handler code here
	CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
	myApp->m_SendkeyType = SKENTER;
	CButton * mybt = (CButton *) GetDlgItem(IDC_BTSEND);
	mybt->SetWindowText(_T("发送 E"));
	myApp->DoSetStautsBarText(SBSSENDKEY,"E");
}

void CMyCommView::OnSendkeyShiftenter() 
{
	// TODO: Add your command handler code here
	CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
	myApp->m_SendkeyType = SKSHIFTENTER;
	CButton * mybt = (CButton *) GetDlgItem(IDC_BTSEND);
	mybt->SetWindowText(_T("发送 S"));
	myApp->DoSetStautsBarText(SBSSENDKEY,"S");
}

void CMyCommView::OnBtvisiblevalue() 
{
	// TODO: Add your control notification handler code here
	CEdit * myedit = (CEdit *)GetDlgItem(IDC_EDRECDATAVALUE);
	CButton * mybt = (CButton *)GetDlgItem(IDC_BTVISIBLEVALUE);
	m_IsShowValueWindow = !m_IsShowValueWindow;
	if (m_IsShowValueWindow)
	{	
		mybt->SetWindowText(_T("关闭结果窗"));
		myedit->ShowWindow(SW_SHOW); //SW_HIDE
	
	}
    else{ 
		mybt->SetWindowText(_T("显示结果窗"));
		myedit->ShowWindow(SW_HIDE);
	}
	DoUpdateLayout();
	
}

void CMyCommView::DoUpdateLayout()
{

	CPane newRecPane = pane( HORIZONTAL, GREEDY );
	if (m_IsShowValueWindow)
	{
		newRecPane
			<< (pane(VERTICAL)
					<<item(IDC_EDRECDATAVALUE,ABSOLUTE_VERT,0,0,0,0)
					<<item(IDC_EDRECDATA,GREEDY,0,0,0,0)
				);
			//<< item(IDC_SLIDEREDIT,ABSOLUTE_HORZ,0,0,0,0);

	}
	else{
		newRecPane<<item(IDC_EDRECDATA,GREEDY,0,0,0,0);
	}

		
	CreateRoot(VERTICAL); //layout
	m_RootPane	//create 
		<< 	( pane(HORIZONTAL)
		<<( pane(VERTICAL,ABSOLUTE_VERT)
				<< item( IDC_STATIC1, NORESIZE )
				<< item(IDC_BTOPENCOMM,NORESIZE)
				<< item( IDC_STATIC2, NORESIZE ))
			<< newRecPane
		)
	 
	 //	<< item ( IDC_ITEM_LIST_STATIC, NORESIZE )
	 //	<< item ( IDC_ITEM_LIST, GREEDY )
	 
	 <<	( pane(HORIZONTAL, ABSOLUTE_VERT )
	 //<< (paneCtrl(IDC_STATIC3,VERTICAL,GREEDY, nDefaultBorder, 10, 10)
	 << (pane(VERTICAL,GREEDY)
		//<< item( IDC_STATIC3, NORESIZE)
		//<< itemGrowing(VERTICAL)
		<< item (IDC_STATIC_SEND,NORESIZE)
		<< (pane(HORIZONTAL,GREEDY)
			<< item( IDC_CHSENDHEX,NORESIZE)
			<< item( IDC_CHSCRIPT,NORESIZE)
			)
		<< (pane(HORIZONTAL,GREEDY,2,0,0)
					<< item(IDC_CHAUTOSEND,NORESIZE)
					<< item(IDC_EDAUTOSENDTIME,NORESIZE)
					
				)
		<< (pane(HORIZONTAL)
			<< item(IDC_BTSENDUP,NORESIZE)    //上
			<< item(IDC_BTSENDCLEAR,NORESIZE) //clear
			<< item(IDC_BTSENDDOWN,NORESIZE)  //下	

		   )
					
		)
		<< ( pane(VERTICAL,ABSOLUTE_VERT)
					   //send
					   << item( IDC_EDSENDDATA,ABSOLUTE_VERT,0,0,0,0)
						
					   //option
						<<(pane(HORIZONTAL, ABSOLUTE_VERT)
							<<(pane(HORIZONTAL, ABSOLUTE_VERT,0)
								<< item(IDC_BTSEND, NORESIZE)   // send button ALIGN_RIGHT	
								<< item(IDC_BTSENDKEY,NORESIZE)
								)
							<< item(IDC_CBCOMMAND,NORESIZE)
							<< itemGrowing (HORIZONTAL)    // bank row 
							<<(pane(HORIZONTAL, ABSOLUTE_VERT,0)
							    << item(IDC_BTCALC,NORESIZE)
								<< item(IDC_BTCLEARRXTX,NORESIZE)
								
							  )
							)
					));

	UpdateLayout();
	
}

void CMyCommView::OnUpdateEdrecdatavalue() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	GetDocument()->m_strReceiveValue = m_ReceiveValue;
}



void CMyCommView::OnBtclearrxtx() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->m_RXCount = 0;
	GetDocument()->m_TXCount = 0;
	CMyCommApp * myApp = (CMyCommApp *)AfxGetApp();
	myApp->DoSetStautsBarText(SBSRX,"RX:");
	myApp->DoSetStautsBarText(SBSTX,"TX:");
	
}

void CMyCommView::OnBtsendclear() 
{
	// TODO: Add your control notification handler code here
	m_strSendData.Empty();
	UpdateData(FALSE);
	CEdit * myedit = (CEdit *)GetDlgItem(IDC_EDSENDDATA);
	myedit->SetFocus();
}


void CMyCommView::OnBtsendup() 
{
	// TODO: Add your control notification handler code here
	if (m_CurrenthistoryIndex<=0) return;
	if (m_CurrenthistoryIndex>=COMMANDCOUNT) return;
	m_CurrenthistoryIndex--;
	
	CommCommand myCommand = GetDocument()->m_HistoryCommand[m_CurrenthistoryIndex];
	m_ctrlSendScript.SetCheck(myCommand.m_isScript);
	m_ctrlSendHex.SetCheck(myCommand.m_IsHex);
	m_strSendData = myCommand.m_strCommand;
	UpdateData(FALSE);
}

void CMyCommView::OnBtsenddown() 
{
	// TODO: Add your control notification handler code here
	if (m_CurrenthistoryIndex<0) return;
	if (m_CurrenthistoryIndex>=COMMANDCOUNT) return;
	m_CurrenthistoryIndex++;

	int myindex = GetDocument()->GetHistoryIndex();
	if (m_CurrenthistoryIndex>=myindex) return;
	
	
	CommCommand myCommand = GetDocument()->m_HistoryCommand[m_CurrenthistoryIndex];
	m_ctrlSendScript.SetCheck(myCommand.m_isScript);
	m_ctrlSendHex.SetCheck(myCommand.m_IsHex);
	m_strSendData = myCommand.m_strCommand;
	UpdateData(FALSE);
	
}

void CMyCommView::OnBtcalc() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(this->m_hWnd,"open","calc.exe","",NULL,SW_SHOW ); 
}

HICON CMyCommView::DoGetButtonIcon(UINT nID)
{
	return (HICON)LoadImage(AfxGetResourceHandle(), 
		MAKEINTRESOURCE(nID), 
		IMAGE_ICON,16,16,0);
}

CString CMyCommView::DoGetReciveSelected()
{
	int a,b;
	m_ctrlReciveData.GetSel(a,b);
	CString myv;
	m_ctrlReciveData.GetWindowText(myv);
	if (b-a >0) myv = myv.Mid(a,b-a);
	return myv;
}


byte DoCheckSum(unsigned char *buffer,   int   size)
{
	byte myv = 0x00;
	for(int i=0;i<size;i++)
		myv += *buffer++;
	return myv;
}


#define CRC16_GEN_POL 0x8005
#define MKSHORT(a,b) ((unsigned short) (a) | ((unsigned short)(b) << 8))
unsigned short CMyCommView::DoCreateCRC(unsigned char *CommData, unsigned int uLen )
{
	unsigned short uCrc16;
	unsigned char abData[2];
	uCrc16 = 0;
	abData[0] = 0;
	while (uLen-- )
	{
		abData[1] = abData[0];
		abData[0] = *CommData++;
		if(uCrc16 & 0x8000)
		{
			uCrc16 = (uCrc16 & 0x7fff) << 1;
			uCrc16 ^= CRC16_GEN_POL;
		}
		else
		{
			uCrc16 <<= 1;
		}
		uCrc16 ^= MKSHORT (abData[0] , abData[1]);
	}
	return(uCrc16);
}


void CMyCommView::OnBtchecksum() 
{
	// TODO: Add your control notification handler code here
	switch(m_CheckDataStyle) {
		case CDSSUM:
			OnCheckSum();	
			break;
		case CDSCRC:
			OnCheckCrc();
			break;
		default:
			return;
	};
}

void CMyCommView::OnBtcheckdata() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	CPoint point;
	CButton * mybt = (CButton *)GetDlgItem(IDC_BTCHECKDATA);
	mybt->GetWindowRect(rect);
    point.x = rect.right;
    point.y = rect.bottom;
	
	CMenu menu;
	VERIFY( menu.LoadMenu( IDR_MENU_CHECK ) );
	CMenu* popup = menu.GetSubMenu(0);
	ASSERT( popup != NULL );
	popup->TrackPopupMenu(TPM_RIGHTALIGN| TPM_RIGHTBUTTON, point.x, point.y, this ); 
}

void CMyCommView::OnCheckSum() 
{
	// TODO: Add your command handler code here
	m_CheckDataStyle = CDSSUM;
	m_CheckData.SetWindowText(_T("累加和"));
	CString mystr = DoGetReciveSelected();
	mystr.TrimLeft(); mystr.TrimRight();
	if (mystr == "") return;
	
	
	char data[512];
	int len=DoStr2Hex(mystr,data);
	unsigned char *ptemp=(unsigned char*)((LPCTSTR)data);
	byte a = DoCheckSum(ptemp,len);
		
	CString myvalue;
	myvalue.Format("%x",a);
	myvalue.MakeUpper();
	if (m_ReceiveValue=="") 
		m_ReceiveValue = myvalue;
	else 
		m_ReceiveValue += "\r\n" + myvalue;
	
	UpdateData(FALSE);
	if(!m_IsShowValueWindow) OnBtvisiblevalue();
	CEdit *myEdit = (CEdit *)GetDlgItem(IDC_EDRECDATAVALUE);
	myEdit->LineScroll(myEdit->GetLineCount());

}

void CMyCommView::OnCheckCrc() 
{
	// TODO: Add your command handler code here
	m_CheckDataStyle = CDSCRC;
	m_CheckData.SetWindowText(_T("CRC"));
	CString mystr = DoGetReciveSelected();
	mystr.TrimLeft(); mystr.TrimRight();
	if (mystr == "") return;

	char data[512];
	int len=DoStr2Hex(mystr,data);
	unsigned char *ptemp=(unsigned char*)((LPCTSTR)data);
	unsigned short cc=DoCreateCRC(ptemp,len);
	
			
	unsigned short hightbit=cc/256;
	unsigned short lowbit = cc-hightbit*256;
	
	CString strHighBit;
	strHighBit.Format("%02x",hightbit);
	
	CString strLowBit;
	strLowBit.Format("%02x",lowbit);
	
	if (m_ReceiveValue=="") 
		m_ReceiveValue = strLowBit + ' ' + strHighBit;
	else 
		m_ReceiveValue += "\r\n" + strLowBit + ' ' + strHighBit;
	
	UpdateData(FALSE);
	if(!m_IsShowValueWindow) OnBtvisiblevalue();
	CEdit *myEdit = (CEdit *)GetDlgItem(IDC_EDRECDATAVALUE);
	myEdit->LineScroll(myEdit->GetLineCount());
}

void CMyCommView::ShowMsg(CString strMsg)
{
	this->m_EditLogger.AddText(strMsg);
}
