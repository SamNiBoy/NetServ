; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewSocket
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetServ.h"

ClassCount=4
Class1=CNetServApp
Class2=CNetServDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CNewSocket
Class4=CServerSocket
Resource2=IDD_NETSERV_DIALOG

[CLS:CNetServApp]
Type=0
HeaderFile=NetServ.h
ImplementationFile=NetServ.cpp
Filter=N

[CLS:CNetServDlg]
Type=0
HeaderFile=NetServDlg.h
ImplementationFile=NetServDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_Listen



[DLG:IDD_NETSERV_DIALOG]
Type=1
Class=CNetServDlg
ControlCount=8
Control1=IDC_Listen,button,1342242816
Control2=IDC_Port,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_StopListen,button,1342242816
Control5=IDC_MaxListen,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_LstClients,listbox,1352728835
Control8=IDC_STATIC,static,1342308352

[CLS:CNewSocket]
Type=0
HeaderFile=NewSocket.h
ImplementationFile=NewSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CNewSocket

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CServerSocket
VirtualFilter=q

