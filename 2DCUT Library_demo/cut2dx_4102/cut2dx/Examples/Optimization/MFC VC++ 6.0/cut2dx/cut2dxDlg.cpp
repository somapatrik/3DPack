// cut2dxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cut2dx.h"
#include "cut2dxDlg.h"
#include "DlgProxy.h"
#include "optimal2dx_i.c"
#include "util.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

cut *cuts;
part *parts;
waste *wastes; 

long num_cuts;
long num_parts;
long num_wastes;

long Length;
long Width;

extern UINT DoneNesting;
HWND dlgWnd = NULL;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCut2dxDlg dialog

IMPLEMENT_DYNAMIC(CCut2dxDlg, CDialog);

CCut2dxDlg::CCut2dxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCut2dxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCut2dxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;

	cuts = NULL;
	wastes = NULL;
	parts = NULL;
	num_parts = 0;
	num_cuts = 0;
	num_wastes = 0;

}

CCut2dxDlg::~CCut2dxDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CCut2dxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCut2dxDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCut2dxDlg, CDialog)
	//{{AFX_MSG_MAP(CCut2dxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDSTART, OnStart)
	ON_WM_DESTROY()
	ON_REGISTERED_MESSAGE(DoneNesting,OnDoneNesting)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCut2dxDlg message handlers

BOOL CCut2dxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCut2dxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCut2dxDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialog::OnPaint();
		CPaintDC dc(this); // device context for painting
	
		// TODO: Add your message handler code here
 
		dc.Rectangle(0, 0, Length, Width);
		
		for (int i = 0; i < num_cuts; i++){
			dc.MoveTo(cuts[i].tx, cuts[i].ty);
			dc.LineTo(cuts[i].bx, cuts[i].by);
		}

		for (i = 0; i < num_parts; i++){
			char size[20];
			char val[5];
			itoa(abs(parts[i].bx - parts[i].tx), val, 10);
			strcpy(size, val);
			strcat(size, "x");
			itoa(abs(parts[i].by - parts[i].ty), val, 10);
			strcat(size, val);

			CString txt(size);
				
			dc.TextOut((parts[i].bx + parts[i].tx) / 2, (parts[i].by + parts[i].ty) / 2, txt);
			
		}
		
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCut2dxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CCut2dxDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CCut2dxDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CCut2dxDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CCut2dxDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CCut2dxDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	
	dlgWnd = this->m_hWnd;

	HRESULT hr;
	CLSID clsid;
	LPUNKNOWN lpUnk;

	CDialog::OnInitDialog();

	// Create the AnyShapeCut2DX object

	hr = CLSIDFromProgID(OLESTR("optimal2dx.Optimization2DX"),&clsid);    

	Optimization2DX1.CreateInstance(clsid,NULL);

	// Create the event sink object

	m_pEventSink = new CMFCSink;

	// Get the IUnknown ptr of the sink object

	lpUnk = m_pEventSink->GetIDispatch(FALSE);

	// Connect the event sink to the event source

	if (AfxConnectionAdvise(Optimization2DX1,DIID_IOptimization2DXEvents,lpUnk,FALSE,&m_dwCookie) == TRUE)  {
//		MessageBox("AfxConnectionAdvise", "Caption", MB_OK);
	}


	Optimization2DX1->NumberOfDemandPieces = 14;
 
    Optimization2DX1->SetDemandPiece(0,  60,  40,  1, 0, 0);
	Optimization2DX1->SetDemandPiece(1,  60,  40,  1, 1, 0);
	Optimization2DX1->SetDemandPiece(2,  48,  40,  1, 2, 0);
	Optimization2DX1->SetDemandPiece(3,  60,  53,  1, 3, 0);
	Optimization2DX1->SetDemandPiece(4,  45,  45,  1, 4, 0);
	Optimization2DX1->SetDemandPiece(5,  50,  80,  1, 5, 0);
	Optimization2DX1->SetDemandPiece(6,  45,  75,  1, 6, 0);
	Optimization2DX1->SetDemandPiece(7,  100, 100, 1, 7, 0);
	Optimization2DX1->SetDemandPiece(8,  100, 100, 1, 8, 0);
	Optimization2DX1->SetDemandPiece(9,  90,  90,  1, 9, 0);
	Optimization2DX1->SetDemandPiece(10, 90,  90,  1, 10, 0);
	Optimization2DX1->SetDemandPiece(11, 90,  90,  1, 11, 0);
	Optimization2DX1->SetDemandPiece(12, 110, 110, 1, 12, 0);
	Optimization2DX1->SetDemandPiece(13, 110, 110, 1, 13, 0);


	Optimization2DX1->NumberOfRepositoryPieces = 1;
 
    Optimization2DX1->SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0);


	Optimization2DX1->BladeWidth = 0;
	Optimization2DX1->OptimizationLevel = 50;
	Optimization2DX1->RandomSeed = 0;
	Optimization2DX1->MaximalCutLength = 300;
	
	Optimization2DX1->StartGuillotine();


}

void CCut2dxDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	
	// TODO: Add your message handler code here
	LPUNKNOWN m_pUnk=m_pEventSink->GetIDispatch(FALSE);

	AfxConnectionUnadvise(Optimization2DX1,DIID_IOptimization2DXEvents,m_pUnk,FALSE,m_dwCookie);
	if(m_pEventSink!=NULL)
	{
		delete m_pEventSink; /*the sink destructor must be public or compiler will complain*/
		m_pEventSink=NULL;
		Optimization2DX1=NULL;
	}
	
	if (cuts != NULL)
		delete[] cuts;

	if (parts != NULL)
		delete[] parts;

}

LRESULT CCut2dxDlg::OnDoneNesting(WPARAM,LPARAM) 

{
	long SheetIndex = 0;
	long rep_index, rep_id;
	long dem_index, dem_id;

	Optimization2DX1->GetUtilizedRepositoryPiece(SheetIndex, &rep_index, &rep_id);

	long tt, tl, tb, tr, priority, num_holes;

	Optimization2DX1->GetRepositoryPiece(rep_index, &Length, &Width, &tt, &tl, &tb, &tr, &rep_id, &priority, &num_holes);

	Optimization2DX1->NumberOfCuttings (SheetIndex, &num_cuts, &rep_index, &rep_id);

	if (cuts != NULL)
		delete[] cuts;

	if (num_cuts > 0){
		cuts = new cut[num_cuts];
		for (int i = 0; i < num_cuts; i++)
			Optimization2DX1->GetCut(SheetIndex, i, &cuts[i].tx, &cuts[i].ty, &cuts[i].bx, &cuts[i].by, &cuts[i].thick, &rep_index, &rep_id);
		
	}

	Optimization2DX1->NumberOfUtilizedDemandPieces(SheetIndex, &num_parts, &rep_index, &rep_id);

	if (parts != NULL)
		delete[] parts;

	if (num_parts > 0){
		parts = new part[num_parts];
		for (int i = 0; i < num_parts; i++)
			Optimization2DX1->GetUtilizedDemandPiece(SheetIndex, i, &parts[i].tx, &parts[i].ty, &parts[i].bx, &parts[i].by, &parts[i].rotated, &rep_index, &dem_index, &rep_id, &dem_id);
	}
	
	Optimization2DX1->NumberOfWastePieces(SheetIndex, &num_wastes, &rep_index, &rep_id);
this->Invalidate(true);
	return true;
}
