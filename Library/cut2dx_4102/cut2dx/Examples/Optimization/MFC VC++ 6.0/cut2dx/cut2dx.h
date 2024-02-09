// cut2dx.h : main header file for the CUT2DX application
//

#if !defined(AFX_CUT2DX_H__A6139EE8_DCC2_4661_91B7_254B1B59304E__INCLUDED_)
#define AFX_CUT2DX_H__A6139EE8_DCC2_4661_91B7_254B1B59304E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCut2dxApp:
// See cut2dx.cpp for the implementation of this class
//

class CCut2dxApp : public CWinApp
{
public:
	CCut2dxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCut2dxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCut2dxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUT2DX_H__A6139EE8_DCC2_4661_91B7_254B1B59304E__INCLUDED_)
