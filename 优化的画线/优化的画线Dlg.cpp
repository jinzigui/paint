
// �Ż��Ļ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�Ż��Ļ���.h"
#include "�Ż��Ļ���Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�Ż��Ļ���Dlg �Ի���



C�Ż��Ļ���Dlg::C�Ż��Ļ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�Ż��Ļ���Dlg::IDD, pParent)
	, type(0)
	, draw(FALSE)
	, mpoint(0)
	, lineStyle(3)
	, lineWidth(3)	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�Ż��Ļ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�Ż��Ļ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &C�Ż��Ļ���Dlg::��test)
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON2, &C�Ż��Ļ���Dlg::mink)
	ON_BN_CLICKED(IDC_BUTTON3, &C�Ż��Ļ���Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// C�Ż��Ļ���Dlg ��Ϣ�������

BOOL C�Ż��Ļ���Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetWindowLong (this->m_hWnd,GWL_EXSTYLE,GetWindowLong(this->m_hWnd ,GWL_EXSTYLE )^0x80000);
	HINSTANCE hInst = LoadLibrary(_T("User32.DLL"));
	if(hInst)
	{
		typedef BOOL (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD);  
		MYFUNC fun = NULL; //ȡ��SetLayeredWindowAttributes����ָ��
		fun=(MYFUNC)GetProcAddress(hInst, "SetLayeredWindowAttributes");
		if(fun)
		{  
			fun(this->m_hWnd,0,150,2);   //�޸ĸò����Ϳ��Ըı䴰��͸���̶�
		}
		FreeLibrary(hInst);
	}
	 SetWindowLong(m_hWnd, GWL_STYLE, GetWindowLong(m_hWnd, GWL_STYLE) & (~(WS_CAPTION | WS_BORDER)));     //�Ƴ��˶Ի���ı߿�
	 this->ShowWindow(SW_SHOWMAXIMIZED);   //�Ի������  
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�Ż��Ļ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�Ż��Ļ���Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�Ż��Ļ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�Ż��Ļ���Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	mpoint=point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void C�Ż��Ļ���Dlg::��test()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	type=1;
}


void C�Ż��Ļ���Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC* pDC=GetDC();
    //���û��ʣ���ɫ������ѡ���豸���棻
     CPen pen(lineStyle , lineWidth,m_color );
	 CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH ));
	 pDC->SelectObject (&pen);
	 pDC->SelectObject (&pBrush );
	 pDC->MoveTo (mpoint );
	  pDC->LineTo (point);
	CDialogEx::OnLButtonUp(nFlags, point);

}


void C�Ż��Ļ���Dlg::mink()
{
	

	ShowWindow(SW_MINIMIZE );
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}




//void C�Ż��Ļ���Dlg::OnBnClickedButton1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CColorDialog dlg;
//	dlg.DoModal ();
//}


void C�Ż��Ļ���Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CColorDialog dlg;
	dlg.m_cc.Flags |=CC_RGBINIT;
	dlg.m_cc.rgbResult=m_color;
	if(IDOK==dlg.DoModal ())
	{
		m_color =dlg.m_cc.rgbResult;
	}
	dlg.DoModal ();
}
