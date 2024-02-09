; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCut2dxApp
LastTemplate=CCmdTarget
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "cut2dx.h"
ODLFile=cut2dx.odl

ClassCount=5
Class1=CCut2dxApp
Class2=CCut2dxDlg
Class3=CAboutDlg
Class4=CCut2dxDlgAutoProxy

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CUT2DX_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Class5=CMFCSink
Resource5=IDD_CUT2DX_DIALOG (English (U.S.))

[CLS:CCut2dxApp]
Type=0
HeaderFile=cut2dx.h
ImplementationFile=cut2dx.cpp
Filter=N
LastObject=CCut2dxApp

[CLS:CCut2dxDlg]
Type=0
HeaderFile=cut2dxDlg.h
ImplementationFile=cut2dxDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCut2dxDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=cut2dxDlg.h
ImplementationFile=cut2dxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[CLS:CCut2dxDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_CUT2DX_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CCut2dxDlg

[DLG:IDD_CUT2DX_DIALOG (English (U.S.))]
Type=1
Class=CCut2dxDlg
ControlCount=1
Control1=IDSTART,button,1342242817

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CMFCSink]
Type=0
HeaderFile=MFCSink.h
ImplementationFile=MFCSink.cpp
BaseClass=CCmdTarget
Filter=N
LastObject=CMFCSink

