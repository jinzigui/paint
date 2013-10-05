
// �Ż��Ļ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�Ż��Ļ���.h"
#include "�Ż��Ļ���Dlg.h"
#include "afxdialogex.h"
#include"math.h"
#include"Graph.h"

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
	, m_startPoint(0)
	, m_Draw(FALSE)
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
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON2, &C�Ż��Ļ���Dlg::mink)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Menu, &C�Ż��Ļ���Dlg::OnMenu)
	ON_COMMAND(ID_32777, &C�Ż��Ļ���Dlg::OnMink)
	ON_COMMAND(ID_32778, &C�Ż��Ļ���Dlg::OnExit)
	ON_COMMAND(ID_32773, &C�Ż��Ļ���Dlg::OnRectangle)
	ON_COMMAND(ID_32772, &C�Ż��Ļ���Dlg::OnLine)
	ON_COMMAND(ID_32774, &C�Ż��Ļ���Dlg::OnArrow)
	ON_COMMAND(ID_32779, &C�Ż��Ļ���Dlg::OnDrawLine)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32775, &C�Ż��Ļ���Dlg::OnOval)
	ON_COMMAND(ID_32776, &C�Ż��Ļ���Dlg::OnRound)
	ON_COMMAND(ID_32776, &C�Ż��Ļ���Dlg::OnRound)
	ON_COMMAND(ID_32780, &C�Ż��Ļ���Dlg::OnClear)
	ON_WM_DRAWITEM()
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
			fun(this->m_hWnd,0,95,3.5);   //�޸ĸò����Ϳ��Ըı䴰��͸���̶�
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
	m_startPoint =point;
	mpoint =point;
	m_Draw=true;
	CDialogEx::OnLButtonDown(nFlags, point);
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
	 switch(type)
	 {
	 case 1:
		 pDC->MoveTo (m_startPoint  );
		 pDC->LineTo (point );
		 break;
	 case 2:
		 pDC->Rectangle (CRect(m_startPoint ,mpoint ));
		 pDC->Rectangle (CRect(m_startPoint ,point));
		 mpoint=point;
		 break;
	 case 3:
		 DrawArrow (m_startPoint ,point,25,25);
		 break;
	 case 4:
		 OnMouseMove( nFlags, point);
		 break;
	 case 5:
		 pDC->Ellipse(CRect(m_startPoint,point));
		 break;
	 case 6:
		 pDC->Ellipse(m_startPoint.x-50,m_startPoint.y-50,mpoint.x+50,mpoint.y+50);
		 break;
	 }
	 m_Draw=false;
	CDialogEx::OnLButtonUp(nFlags, point);

}


void C�Ż��Ļ���Dlg::mink()
{
	

	ShowWindow(SW_MINIMIZE );
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void C�Ż��Ļ���Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�Ҽ�������ݼ�
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu *pContextMenu=menu.GetSubMenu(0);
	CPoint mpoint ;
	GetCursorPos (&mpoint);
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,mpoint.x,mpoint.y,AfxGetMainWnd());

	CDialogEx::OnRButtonDown(nFlags, mpoint);
}


void C�Ż��Ļ���Dlg::OnMenu()
{
	// TODO: �ڴ���������������
	CColorDialog dlg;
	dlg.m_cc.Flags |=CC_RGBINIT;
	dlg.m_cc.rgbResult=m_color;
	if(IDOK==dlg.DoModal ())
	{
		m_color =dlg.m_cc.rgbResult;
	}
}



void C�Ż��Ļ���Dlg::OnMink()
{
	// TODO: �ڴ���������������
	ShowWindow(SW_MINIMIZE );
}


void C�Ż��Ļ���Dlg::OnExit()
{
	// TODO: �ڴ���������������
	OnExit ();
}


void C�Ż��Ļ���Dlg::OnRectangle()
{
	// TODO: �ڴ���������������
	type=2;
}


void C�Ż��Ļ���Dlg::OnLine()
{
	// TODO: �ڴ���������������
	type=1;
}


void C�Ż��Ļ���Dlg::OnArrow()   //��ͷ
{
	// TODO: �ڴ���������������
	type =3;
}


void C�Ż��Ļ���Dlg::DrawArrow(CPoint p1, CPoint p2, double theta, double length)
{
	theta=3.1415926*theta/180;//ת��Ϊ����
	double Px,Py,P1x,P1y,P2x,P2y;
	//��P2Ϊԭ��õ�����P2P1��P��
	Px=p1.x-p2.x;
	Py=p1.y-p2.y;
	//����P��תtheta�ǵõ�����P1
	P1x=Px*cos(theta)-Py*sin(theta);
	P1y=Px*sin(theta)+Py*cos(theta);
	//����P��ת-theta�ǵõ�����P2
	P2x=Px*cos(-theta)-Py*sin(-theta);
	P2y=Px*sin(-theta)+Py*cos(-theta);
	//�����������ƶ�����
	double x1,x2;
	x1=sqrt(P1x*P1x+P1y*P1y);
	P1x=P1x*length/x1;
	P1y=P1y*length/x1;
	x2=sqrt(P2x*P2x+P2y*P2y);
	P2x=P2x*length/x2;
	P2y=P2y*length/x2;
	//ƽ�Ʊ�����ֱ�ߵ�ĩ��
	P1x=P1x+p2.x;
	P1y=P1y+p2.y;
	P2x=P2x+p2.x;
	P2y=P2y+p2.y;
	CClientDC dc(this);//��ȡ�ͻ�����DC
	CPen pen,pen1,*oldpen;
	//CPen pen(lineStyle , lineWidth,m_color );
	pen.CreatePen(lineStyle , lineWidth,m_color );;
	pen1.CreatePen(lineStyle , lineWidth,m_color );;
	oldpen=dc.SelectObject(&pen);
	dc.MoveTo(p1.x,p1.y);
	dc.LineTo(p2.x,p2.y);
	dc.SelectObject(&pen1);
	dc.MoveTo(p2.x,p2.y);
	dc.LineTo(P1x,P1y);
	dc.MoveTo(p2.x,p2.y);
	dc.LineTo(P2x,P2y);
	dc.SelectObject(oldpen);
}


void C�Ż��Ļ���Dlg::OnDrawLine()
{
	// TODO: �ڴ���������������
	type=4;
}


void C�Ż��Ļ���Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(type==4)
	{
		CDC* pDC=GetDC();
    //���û��ʣ���ɫ������ѡ���豸���棻
     CPen pen(lineStyle , lineWidth,m_color );
	 CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH ));
	 pDC->SelectObject (&pen);
	 if(m_Draw )
	 {
	pDC->MoveTo (m_startPoint );
	pDC->LineTo(point);
	m_startPoint=point;
	 }
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void C�Ż��Ļ���Dlg::OnOval()   //��Բ
{
	// TODO: �ڴ���������������
	type=5;
}

//void C�Ż��Ļ���Dlg::CirPot(int cx, int cy, int x, int y, CDC* pDC)
//{
//	pDC->SetPixelV((cx+x),(cy+y),m_color);
//
//	pDC->SetPixelV((cx+y),(cy+x),m_color);
//
//	pDC->SetPixelV((cx+y),(cy-x),m_color);
//
//	pDC->SetPixelV((cx+x),(cy-y),m_color);
//
//	pDC->SetPixelV((cx-x),(cy-y),m_color);
//
//	pDC->SetPixelV((cx-y),(cy-x),m_color);
//
//	pDC->SetPixelV((cx-y),(cy+x),m_color);
//
//	pDC->SetPixelV((cx-x),(cy+y),m_color);
//
//}


//void C�Ż��Ļ���Dlg::DrawRound(CPoint m_startPoint, CPoint m_endPoint, CDC* pDC)
//{
//	int t1=abs(m_endPoint.x-m_startPoint.x)*abs(m_endPoint.x-m_startPoint.x);
//
//	int t2=abs(m_endPoint.y-m_startPoint.y)*abs(m_endPoint.y-m_startPoint.y);
//
//	double r=sqrt(double(t1+t2))/2;
//
//	int cx=(m_startPoint.x+m_endPoint.x)/2;
//
//	int cy=(m_startPoint.y+m_endPoint.y)/2;
//
//	int x,y;
//
//	float d;
//
//	x=0;
//
//	y=r;
//
//	d=1-r;
//
//	CirPot(cx,cy,x,y,pDC);
//
//	while(x<y)
//
//	{
//
//		if(d<0)
//
//		{
//
//			d+=2*x+3;
//
//			x++;
//
//		}
//
//		else
//
//		{
//
//			d+=2*(x-y)+5;
//
//			x++;
//
//			y--;
//
//		}
//
//		CirPot(cx,cy,x,y,pDC);
//
//	}
//}


void C�Ż��Ļ���Dlg::OnRound()
{
	// TODO: �ڴ���������������
	type=6;
}


void C�Ż��Ļ���Dlg::OnClear()
{
	// TODO: �ڴ���������������
	Invalidate();
}


void C�Ż��Ļ���Dlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC* pDC=NULL;
	CBrush *pBrush=CBrush ::FromHandle((HBRUSH )GetStockObject (NULL_BRUSH ));  //���ð�ɫ������ˢ������ָ�ˢ��
	pDC->SelectObject (pBrush );
	for(int i=0;i<m_ptrArray.GetSize();i++)
	{
		switch(((CGraph*)m_ptrArray.GetAt(i))->m_nDrawType)
		{
		case 1:
			pDC->MoveTo(((CGraph*)m_ptrArray.GetAt (i))->m_ptOrigin );
			pDC->LineTo (((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd);
			break;
		case 2:
			pDC->Rectangle(CRect(((CGraph*)m_ptrArray.GetAt (i))->m_ptOrigin ,((CGraph *)m_ptrArray.GetAt(i))->m_ptEnd) );
			break;
		case 3:
			DrawArrow (((CGraph *)m_ptrArray.GetAt(i))->m_ptOrigin,((CGraph *)m_ptrArray.GetAt(i))->m_ptEnd,25,25);
			break;
		case 4:
			OnMouseMove(NULL(((CGraph*)m_ptrArray.GetAt (i))->m_ptOrigin ,((CGraph *)m_ptrArray.GetAt(i))->m_ptEnd),NULL );
			break;
		case 5:
			pDC->Ellipse (CRect(((CGraph*)m_ptrArray.GetAt (i))->m_ptOrigin ,((CGraph *)m_ptrArray.GetAt(i))->m_ptEnd) );
			break;
		//case 6:

		}
	}
	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
