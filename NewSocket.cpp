// NewSocket.cpp : implementation file
//

#include "stdafx.h"
#include "NetServ.h"
#include "NewSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewSocket

CNewSocket::CNewSocket()
{
	memset(m_szBuffer,0, sizeof(m_szBuffer));
	m_nLength = 0;
}

CNewSocket::~CNewSocket()
{
	if(this->m_hSocket != INVALID_SOCKET)
		Close();
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CNewSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CNewSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CNewSocket member functions

void CNewSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer));
	AsyncSelect(FD_WRITE);
	CAsyncSocket::OnReceive(nErrorCode);
}

void CNewSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	char buff[4096];
	memset(buff, 0, sizeof(buff));
	strcpy(buff, "From Server:");
	strcat(buff, m_szBuffer);
	strcpy(m_szBuffer, buff);

	Send(m_szBuffer, m_nLength+12, 0);
	AsyncSelect(FD_READ);
	CAsyncSocket::OnSend(nErrorCode);
}

void CNewSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CString a;
	unsigned int p;

	this->GetPeerName(a, p);

	

	CString s;
	s.Format("Looks Client %s, %d disconnected!", a, p);

	AfxMessageBox(s);
	CAsyncSocket::OnClose(nErrorCode);
}
