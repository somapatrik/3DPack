// MFCSink.cpp : implementation file
//

#include "stdafx.h"
#include "cut2dx.h"
#include "MFCSink.h"
#include "optimal2dx_i.c"
#include "cut2dxDlg.h"
#include "util.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern HWND dlgWnd;
extern UINT DoneNesting;

/////////////////////////////////////////////////////////////////////////////
// CMFCSink

IMPLEMENT_DYNCREATE(CMFCSink, CCmdTarget)

CMFCSink::CMFCSink()
{
	EnableAutomation();
}

CMFCSink::~CMFCSink()
{
}


void CMFCSink::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CMFCSink, CCmdTarget)
	//{{AFX_MSG_MAP(CMFCSink)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCSink, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMFCSink)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//DISP_FUNCTION(CMFCSink, "OnProgress", OnProgress, VT_ERROR, VTS_NONE)
	DISP_FUNCTION(CMFCSink, "OnFinish", OnFinish, VT_ERROR, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMFCSink to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {6EC3F7C6-401A-433A-A9C4-77CAE9AA05C7}
static const IID IID_IMFCSink =
{ 0x6ec3f7c6, 0x401a, 0x433a, { 0xa9, 0xc4, 0x77, 0xca, 0xe9, 0xaa, 0x5, 0xc7 } };

BEGIN_INTERFACE_MAP(CMFCSink, CCmdTarget)
	INTERFACE_PART(CMFCSink, DIID_IOptimization2DXEvents, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCSink message handlers
/*
SCODE CMFCSink::OnProgress() 


{
	MessageBox(NULL, "Progress", "Caption", MB_OK);

	return S_OK;
}
*/
//-----------------------------------------------------------------------------

SCODE CMFCSink::OnFinish() 

{
	SendMessage(dlgWnd,DoneNesting,(WPARAM)(0),(LPARAM)(0));


	//MessageBox(NULL, "Finish", "Caption", MB_OK);

	return S_OK;
}

//-----------------------------------------------------------------------------
