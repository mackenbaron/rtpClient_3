
// RTP_3Camera_Client.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRTP_3Camera_ClientApp:
// �йش����ʵ�֣������ RTP_3Camera_Client.cpp
//

class CRTP_3Camera_ClientApp : public CWinApp
{
public:
	CRTP_3Camera_ClientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRTP_3Camera_ClientApp theApp;