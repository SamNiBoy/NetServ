#if !defined(AFX_NEWSOCKET_H__5499459B_6BDF_4DF0_8FE0_623986A4C572__INCLUDED_)
#define AFX_NEWSOCKET_H__5499459B_6BDF_4DF0_8FE0_623986A4C572__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CNewSocket command target

class CNewSocket : public CAsyncSocket
{
// Attributes
public:

	char m_szBuffer[4096];
	int m_nLength;
// Operations
public:
	CNewSocket();
	virtual ~CNewSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CNewSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSOCKET_H__5499459B_6BDF_4DF0_8FE0_623986A4C572__INCLUDED_)
