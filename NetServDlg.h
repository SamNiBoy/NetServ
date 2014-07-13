// NetServDlg.h : header file
//

#if !defined(AFX_NETSERVDLG_H__26B1E98A_D6CF_4031_93A7_B62A9147F051__INCLUDED_)
#define AFX_NETSERVDLG_H__26B1E98A_D6CF_4031_93A7_B62A9147F051__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"ServerSocket.h"
/////////////////////////////////////////////////////////////////////////////
// CNetServDlg dialog

class CNetServDlg : public CDialog
{
// Construction
public:
	CServerSocket m_srvrSocket;
public:
	CNetServDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetServDlg)
	enum { IDD = IDD_NETSERV_DIALOG };
	CListBox	m_clients;
	int		m_szPort;
	int		m_szMaxListen;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetServDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetServDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnListen();
	afx_msg void OnStopListen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETSERVDLG_H__26B1E98A_D6CF_4031_93A7_B62A9147F051__INCLUDED_)
