// NetServDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetServ.h"
#include "NetServDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetServDlg dialog

CNetServDlg::CNetServDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetServDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetServDlg)
	m_szPort = 123;
	m_szMaxListen = 3;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetServDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetServDlg)
	DDX_Control(pDX, IDC_LstClients, m_clients);
	DDX_Text(pDX, IDC_Port, m_szPort);
	DDX_Text(pDX, IDC_MaxListen, m_szMaxListen);
	DDV_MinMaxInt(pDX, m_szMaxListen, 1, 1000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetServDlg, CDialog)
	//{{AFX_MSG_MAP(CNetServDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Listen, OnListen)
	ON_BN_CLICKED(IDC_StopListen, OnStopListen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetServDlg message handlers

BOOL CNetServDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNetServDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNetServDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetServDlg::OnListen() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (m_szPort <=0)
	{
		AfxMessageBox("Invalid port for listen!");
		return;
	}


	if (m_srvrSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_srvrSocket.Create(m_szPort, SOCK_STREAM, FD_ACCEPT);

		if (!bFlag)
		{
			CString s;
			s.Format("Socket error with %d", m_srvrSocket.GetLastError());
			AfxMessageBox(s);
			PostQuitMessage(0);
			return;
		}
	}
	if(!m_srvrSocket.Listen(this->m_szMaxListen))
	{
		int nErrorCode = m_srvrSocket.GetLastError();

		if (nErrorCode != WSAEWOULDBLOCK)
		{
			CString s;
			s.Format("Listen error %d", nErrorCode);
			AfxMessageBox(s);
			m_srvrSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
}

void CNetServDlg::OnStopListen() 
{
	// TODO: Add your control notification handler code here
	if (m_srvrSocket.m_hSocket != INVALID_SOCKET)
	{
		m_srvrSocket.Close();
	}
}
