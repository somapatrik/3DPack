#if !defined(AFX_MFCSINK_H__F1C21F55_4E0D_42BC_9240_F8CF2A74503D__INCLUDED_)
#define AFX_MFCSINK_H__F1C21F55_4E0D_42BC_9240_F8CF2A74503D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MFCSink.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CMFCSink command target

class CMFCSink : public CCmdTarget
{
	DECLARE_DYNCREATE(CMFCSink)

	CMFCSink();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSink)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL
virtual ~CMFCSink();

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CMFCSink)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CMFCSink)
		// NOTE - the ClassWizard will add and remove member functions here.
	//afx_msg SCODE OnProgress();
	afx_msg SCODE OnFinish();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSINK_H__F1C21F55_4E0D_42BC_9240_F8CF2A74503D__INCLUDED_)
