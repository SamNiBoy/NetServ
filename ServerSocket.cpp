// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "NetServ.h"
#include "ServerSocket.h"
#include "NetServDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CNewSocket *pSocket = new CNewSocket();


	if (Accept(*pSocket))
	{
		pSocket->AsyncSelect(FD_READ);
		m_pSocket = pSocket;
		CString addr;
		unsigned int port;
		pSocket->GetPeerName(addr, port);

		CNetServApp *pApp = (CNetServApp*) AfxGetApp();
		CNetServDlg *pDlg = (CNetServDlg*) pApp->m_pMainWnd;

		CString s;
		s.Format("Addr:%s, Port:%d", addr, port);
		pDlg->m_clients.InsertString(0, s);
		
		//s.Format("Accept connection from %s", psa->sa_data);
		//AfxMessageBox(s);
	}
	else
		delete pSocket;
	//CAsyncSocket::OnAccept(nErrorCode);
}
