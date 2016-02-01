; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyComm.h"
LastPage=0

ClassCount=13
Class1=CMyCommApp
Class2=CMyCommDoc
Class3=CMyCommView
Class4=CMainFrame

ResourceCount=12
<<<<<<< .mine
Resource1=IDD_MYCOMM_FORM
Resource2=IDD_DLGCOMMAND
=======
Resource1=IDD_MYCOMM_FORM
Resource2=IDD_DLGCOMMAND
>>>>>>> .r13
Class5=CAboutDlg
Resource3=IDD_DLGADVANCED
Class6=CCommandDlg
<<<<<<< .mine
Resource4=IDR_MENU_SNEDKEY
=======
Resource4=IDR_MENU_SNEDKEY
>>>>>>> .r13
Class7=CCommAdvancedDlg
<<<<<<< .mine
Resource5=IDR_MAINFRAME
=======
Resource5=IDR_MAINFRAME
>>>>>>> .r13
Class8=CProtocolEditDlg
Class9=CMyEditEx
Class10=CScriptHelpDlg
Class11=CUpgradeDlg
Resource6=IDD_DLGPROTOCOL
Resource7=IDD_DLGSCRIPTHELP
Resource8=IDD_DLGSENDFILE
Resource9=IDD_PROPPAGE_SMALL (English (U.S.))
Resource10=IDD_DLGUPGRADE
Resource11=IDR_MENU_CHECK
Class12=CSendFileByXModem
Class13=CRemoteApplyDlg
Resource12=IDD_ABOUTBOX

[CLS:CMyCommApp]
Type=0
HeaderFile=MyComm.h
ImplementationFile=MyComm.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CMyCommApp

[CLS:CMyCommDoc]
Type=0
HeaderFile=MyCommDoc.h
ImplementationFile=MyCommDoc.cpp
Filter=N
LastObject=CMyCommDoc

[CLS:CMyCommView]
Type=0
HeaderFile=MyCommView.h
ImplementationFile=MyCommView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_BTCHECKSUM


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_APP_HOME




[CLS:CAboutDlg]
Type=0
HeaderFile=MyComm.cpp
ImplementationFile=MyComm.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=10
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC_VERSION,static,1342308352
Control10=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_VIEW_STATUS_BAR
Command8=ID_EDIT_COMMAND
Command9=ID_EDIT_PROTOCOL
Command10=ID_SEND_FILE
Command11=ID_HELP_SCRIPT
Command12=ID_APP_UPGRADE
Command13=ID_APP_HOME
Command14=ID_APP_SNEDMAIL
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_MYCOMM_FORM]
Type=1
Class=CMyCommView
ControlCount=38
Control1=IDC_STATIC1,button,1342177287
Control2=IDC_STATIC2,button,1342177543
Control3=IDC_EDRECDATA,edit,1352732932
Control4=IDC_EDSENDDATA,edit,1352732804
Control5=IDC_BTSEND,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_CBCOM,combobox,1344340034
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CBBANDRATE,combobox,1344339970
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CBDATABITS,combobox,1344339970
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CBPARITY,combobox,1344339971
Control15=IDC_CBSTOPBITS,combobox,1344339971
Control16=IDC_BTOPENCOMM,button,1342242816
Control17=IDC_BTADVANCED,button,1342242816
Control18=IDC_CHREVHEX,button,1342242819
Control19=IDC_BTVIEWPROTOCOL,button,1342242816
Control20=IDC_BTCLEARRECEIVEDATA,button,1342242816
Control21=IDC_CHSENDHEX,button,1342242819
Control22=IDC_STATIC_SEND,static,1342312448
Control23=IDC_EDAUTOSENDTIME,edit,1350639744
Control24=IDC_CHAUTOSEND,button,1342242819
Control25=IDC_CBCOMMAND,combobox,1344339971
Control26=IDC_BTSAVERECDATA,button,1342242816
Control27=IDC_BTVIEWRECDATA,button,1342242816
Control28=IDC_CHSCRIPT,button,1342242819
Control29=IDC_BTSENDKEY,button,1342242816
Control30=IDC_EDRECDATAVALUE,edit,1085345924
Control31=IDC_BTVISIBLEVALUE,button,1342242816
Control32=IDC_BTCLEARRXTX,button,1342242880
Control33=IDC_BTSENDUP,button,1342242816
Control34=IDC_BTSENDDOWN,button,1342242816
Control35=IDC_BTSENDCLEAR,button,1342242816
Control36=IDC_BTCALC,button,1342246720
Control37=IDC_BTCHECKSUM,button,1342242816
Control38=IDC_BTCHECKDATA,button,1342242816

[DLG:IDD_DLGCOMMAND]
Type=1
Class=CCommandDlg
ControlCount=106
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDNAME_1,edit,1350631552
Control4=IDC_EDCOMMAND_1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDNAME_2,edit,1350631552
Control7=IDC_EDCOMMAND_2,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDNAME_3,edit,1350631552
Control10=IDC_EDCOMMAND_3,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDNAME_4,edit,1350631552
Control13=IDC_EDCOMMAND_4,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDNAME_5,edit,1350631552
Control16=IDC_EDCOMMAND_5,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDNAME_6,edit,1350631552
Control19=IDC_EDCOMMAND_6,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_EDNAME_7,edit,1350631552
Control22=IDC_EDCOMMAND_7,edit,1350631552
Control23=IDC_STATIC,static,1342308352
Control24=IDC_EDNAME_8,edit,1350631552
Control25=IDC_EDCOMMAND_8,edit,1350631552
Control26=IDC_STATIC,static,1342308352
Control27=IDC_EDNAME_9,edit,1350631552
Control28=IDC_EDCOMMAND_9,edit,1350631552
Control29=IDC_STATIC,static,1342308352
Control30=IDC_EDNAME_10,edit,1350631552
Control31=IDC_EDCOMMAND_10,edit,1350631552
Control32=IDC_STATIC,static,1342308352
Control33=IDC_EDNAME_11,edit,1350631552
Control34=IDC_EDCOMMAND_11,edit,1350631552
Control35=IDC_STATIC,static,1342308352
Control36=IDC_EDNAME_12,edit,1350631552
Control37=IDC_EDCOMMAND_12,edit,1350631552
Control38=IDC_STATIC,static,1342308352
Control39=IDC_EDNAME_13,edit,1350631552
Control40=IDC_EDCOMMAND_13,edit,1350631552
Control41=IDC_STATIC,static,1342308352
Control42=IDC_EDNAME_14,edit,1350631552
Control43=IDC_EDCOMMAND_14,edit,1350631552
Control44=IDC_STATIC,static,1342308352
Control45=IDC_EDNAME_15,edit,1350631552
Control46=IDC_EDCOMMAND_15,edit,1350631552
Control47=IDC_STATIC,static,1342308352
Control48=IDC_EDNAME_16,edit,1350631552
Control49=IDC_EDCOMMAND_16,edit,1350631552
Control50=IDC_STATIC,static,1342308352
Control51=IDC_EDNAME_17,edit,1350631552
Control52=IDC_EDCOMMAND_17,edit,1350631552
Control53=IDC_STATIC,static,1342308352
Control54=IDC_EDNAME_18,edit,1350631552
Control55=IDC_EDCOMMAND_18,edit,1350631552
Control56=IDC_STATIC,static,1342308352
Control57=IDC_EDNAME_19,edit,1350631552
Control58=IDC_EDCOMMAND_19,edit,1350631552
Control59=IDC_STATIC,static,1342308352
Control60=IDC_EDNAME_20,edit,1350631552
Control61=IDC_EDCOMMAND_20,edit,1350631552
Control62=IDC_STATIC,static,1342308352
Control63=IDC_CHHEX_1,button,1342242819
Control64=IDC_CHHEX_2,button,1342242819
Control65=IDC_CHHEX_3,button,1342242819
Control66=IDC_CHHEX_4,button,1342242819
Control67=IDC_CHHEX_5,button,1342242819
Control68=IDC_CHHEX_6,button,1342242819
Control69=IDC_CHHEX_7,button,1342242819
Control70=IDC_CHHEX_8,button,1342242819
Control71=IDC_CHHEX_9,button,1342242819
Control72=IDC_CHHEX_10,button,1342242819
Control73=IDC_CHHEX_11,button,1342242819
Control74=IDC_CHHEX_12,button,1342242819
Control75=IDC_CHHEX_13,button,1342242819
Control76=IDC_CHHEX_14,button,1342242819
Control77=IDC_CHHEX_15,button,1342242819
Control78=IDC_CHHEX_16,button,1342242819
Control79=IDC_CHHEX_17,button,1342242819
Control80=IDC_CHHEX_18,button,1342242819
Control81=IDC_CHHEX_19,button,1342242819
Control82=IDC_CHHEX_20,button,1342242819
Control83=IDC_STATIC,static,1342308352
Control84=IDC_STATIC,static,1342308352
Control85=IDC_CHSCRIPT_1,button,1342242819
Control86=IDC_CHSCRIPT_2,button,1342242819
Control87=IDC_CHSCRIPT_3,button,1342242819
Control88=IDC_CHSCRIPT_4,button,1342242819
Control89=IDC_CHSCRIPT_5,button,1342242819
Control90=IDC_CHSCRIPT_6,button,1342242819
Control91=IDC_CHSCRIPT_7,button,1342242819
Control92=IDC_CHSCRIPT_8,button,1342242819
Control93=IDC_CHSCRIPT_9,button,1342242819
Control94=IDC_CHSCRIPT_10,button,1342242819
Control95=IDC_CHSCRIPT_11,button,1342242819
Control96=IDC_CHSCRIPT_12,button,1342242819
Control97=IDC_CHSCRIPT_13,button,1342242819
Control98=IDC_CHSCRIPT_14,button,1342242819
Control99=IDC_CHSCRIPT_15,button,1342242819
Control100=IDC_CHSCRIPT_16,button,1342242819
Control101=IDC_CHSCRIPT_17,button,1342242819
Control102=IDC_CHSCRIPT_18,button,1342242819
Control103=IDC_CHSCRIPT_19,button,1342242819
Control104=IDC_CHSCRIPT_20,button,1342242819
Control105=IDC_STATIC,static,1342308352
Control106=IDC_BTSCRIPTHELP,button,1342242816

[CLS:CCommandDlg]
Type=0
HeaderFile=CommandDlg.h
ImplementationFile=CommandDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BTSCRIPTHELP
VirtualFilter=dWC

[DLG:IDD_DLGADVANCED]
Type=1
Class=CCommAdvancedDlg
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDREADINTER,edit,1350639744
Control8=IDC_EDREADTOTALMUL,edit,1350639744
Control9=IDC_EDREATOTALCONST,edit,1350639744
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDWRITETOTALMUL,edit,1350639744
Control17=IDC_EDWRITETOTALCONST,edit,1350639744
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_BTDEFAULT,button,1342242816

[CLS:CCommAdvancedDlg]
Type=0
HeaderFile=CommAdvancedDlg.h
ImplementationFile=CommAdvancedDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDREADINTER
VirtualFilter=dWC

[DLG:IDD_DLGPROTOCOL]
Type=1
Class=CProtocolEditDlg
ControlCount=3
Control1=IDOK,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT,edit,1353781380

[CLS:CProtocolEditDlg]
Type=0
HeaderFile=ProtocolEditDlg.h
ImplementationFile=ProtocolEditDlg.cpp
BaseClass=ETSLayoutDialog
Filter=D
VirtualFilter=dWC
LastObject=CProtocolEditDlg

[CLS:CMyEditEx]
Type=0
HeaderFile=MyEditEx.h
ImplementationFile=MyEditEx.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=ID_CHECK_SUM

[DLG:IDD_DLGSCRIPTHELP]
Type=1
Class=CScriptHelpDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1353783428

[CLS:CScriptHelpDlg]
Type=0
HeaderFile=ScriptHelpDlg.h
ImplementationFile=ScriptHelpDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScriptHelpDlg

[MNU:IDR_MENU_SNEDKEY]
Type=1
Class=CMyCommView
Command1=ID_SENDKEY_NONE
Command2=ID_SENDKEY_ENTER
Command3=ID_SENDKEY_SHIFTENTER
CommandCount=3

[DLG:IDD_PROPPAGE_SMALL (English (U.S.))]
Type=1
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DLGUPGRADE]
Type=1
Class=CUpgradeDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC1,static,1342308352
Control4=IDC_EDDATE,edit,1353779332

[CLS:CUpgradeDlg]
Type=0
HeaderFile=UpgradeDlg.h
ImplementationFile=UpgradeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CUpgradeDlg
VirtualFilter=dWC

[MNU:IDR_MENU_CHECK]
Type=1
Class=CMyCommView
Command1=ID_CHECK_SUM
Command2=ID_CHECK_CRC
CommandCount=2

[DLG:IDD_DLGSENDFILE]
Type=1
Class=CSendFileByXModem
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDFILENAME,edit,1350631552
Control7=IDC_BTSELECTFILE,button,1342242816
Control8=IDC_RD_XMODEM,button,1342308361
Control9=IDC_RD_YMODEM,button,1342177289
Control10=IDC_RD_ZMODEM,button,1342177289
Control11=IDC_RD_1KXMODEM,button,1342177289

[CLS:CSendFileByXModem]
Type=0
HeaderFile=SendFileByXModem.h
ImplementationFile=SendFileByXModem.cpp
BaseClass=CDialog
Filter=D
LastObject=CSendFileByXModem
VirtualFilter=dWC

[CLS:CRemoteApplyDlg]
Type=0
HeaderFile=RemoteApplyDlg.h
ImplementationFile=RemoteApplyDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIP
VirtualFilter=dWC

