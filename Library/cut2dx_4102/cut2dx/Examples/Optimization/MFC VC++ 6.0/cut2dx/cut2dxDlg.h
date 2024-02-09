// cut2dxDlg.h : header file
//

#if !defined(AFX_CUT2DXDLG_H__4BA03561_DCD5_48ED_8C1A_14AE1C7EEE4D__INCLUDED_)
#define AFX_CUT2DXDLG_H__4BA03561_DCD5_48ED_8C1A_14AE1C7EEE4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "mfcsink.h"

class CCut2dxDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CCut2dxDlg dialog

class CCut2dxDlg : public CDialog
{
	DECLARE_DYNAMIC(CCut2dxDlg);
	friend class CCut2dxDlgAutoProxy;

// Construction
public:
	CCut2dxDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CCut2dxDlg();

	IOptimization2DXPtr Optimization2DX1;
	
	CMFCSink *m_pEventSink;
	DWORD m_dwCookie;

// Dialog Data
	//{{AFX_DATA(CCut2dxDlg)
	enum { IDD = IDD_CUT2DX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCut2dxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

	

protected:
	CCut2dxDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CCut2dxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnStart();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	afx_msg LRESULT OnDoneNesting(WPARAM,LPARAM);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUT2DXDLG_H__4BA03561_DCD5_48ED_8C1A_14AE1C7EEE4D__INCLUDED_)
