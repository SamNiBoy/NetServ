// NetServ.h : main header file for the NETSERV application
//

#if !defined(AFX_NETSERV_H__9DD16662_DE2E_4847_950E_77705085B7A5__INCLUDED_)
#define AFX_NETSERV_H__9DD16662_DE2E_4847_950E_77705085B7A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetServApp:
// See NetServ.cpp for the implementation of this class
//

class CNetServApp : public CWinApp
{
public:
	CNetServApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetServApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetServApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETSERV_H__9DD16662_DE2E_4847_950E_77705085B7A5__INCLUDED_)
