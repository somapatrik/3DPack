// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "cut2dx.h"
#include "DlgProxy.h"
#include "cut2dxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCut2dxDlgAutoProxy

IMPLEMENT_DYNCREATE(CCut2dxDlgAutoProxy, CCmdTarget)

CCut2dxDlgAutoProxy::CCut2dxDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CCut2dxDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CCut2dxDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CCut2dxDlgAutoProxy::~CCut2dxDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CCut2dxDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CCut2dxDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CCut2dxDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCut2dxDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CCut2dxDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ICut2dx to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {4888E327-D690-46AB-9596-86914851F032}
static const IID IID_ICut2dx =
{ 0x4888e327, 0xd690, 0x46ab, { 0x95, 0x96, 0x86, 0x91, 0x48, 0x51, 0xf0, 0x32 } };

BEGIN_INTERFACE_MAP(CCut2dxDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CCut2dxDlgAutoProxy, IID_ICut2dx, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {783D1866-E302-4F76-A631-8834BEB39F26}
IMPLEMENT_OLECREATE2(CCut2dxDlgAutoProxy, "Cut2dx.Application", 0x783d1866, 0xe302, 0x4f76, 0xa6, 0x31, 0x88, 0x34, 0xbe, 0xb3, 0x9f, 0x26)

/////////////////////////////////////////////////////////////////////////////
// CCut2dxDlgAutoProxy message handlers
