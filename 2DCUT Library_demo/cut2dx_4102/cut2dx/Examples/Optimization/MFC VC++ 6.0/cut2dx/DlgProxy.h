// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__16906AC5_68ED_49E0_9400_E6AF3D388DF0__INCLUDED_)
#define AFX_DLGPROXY_H__16906AC5_68ED_49E0_9400_E6AF3D388DF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCut2dxDlg;

/////////////////////////////////////////////////////////////////////////////
// CCut2dxDlgAutoProxy command target

class CCut2dxDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CCut2dxDlgAutoProxy)

	CCut2dxDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CCut2dxDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCut2dxDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCut2dxDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CCut2dxDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CCut2dxDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CCut2dxDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__16906AC5_68ED_49E0_9400_E6AF3D388DF0__INCLUDED_)
