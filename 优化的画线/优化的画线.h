
// �Ż��Ļ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Ż��Ļ���App:
// �йش����ʵ�֣������ �Ż��Ļ���.cpp
//

class C�Ż��Ļ���App : public CWinApp
{
public:
	C�Ż��Ļ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Ż��Ļ���App theApp;