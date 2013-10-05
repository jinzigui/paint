
// 优化的画线Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "优化的画线.h"
#include "优化的画线Dlg.h"
#include "afxdialogex.h"
#include"math.h"
#include"Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C优化的画线Dlg 对话框



C优化的画线Dlg::C优化的画线Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C优化的画线Dlg::IDD, pParent)
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

void C优化的画线Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C优化的画线Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON2, &C优化的画线Dlg::mink)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Menu, &C优化的画线Dlg::OnMenu)
	ON_COMMAND(ID_32777, &C优化的画线Dlg::OnMink)
	ON_COMMAND(ID_32778, &C优化的画线Dlg::OnExit)
	ON_COMMAND(ID_32773, &C优化的画线Dlg::OnRectangle)
	ON_COMMAND(ID_32772, &C优化的画线Dlg::OnLine)
	ON_COMMAND(ID_32774, &C优化的画线Dlg::OnArrow)
	ON_COMMAND(ID_32779, &C优化的画线Dlg::OnDrawLine)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32775, &C优化的画线Dlg::OnOval)
	ON_COMMAND(ID_32776, &C优化的画线Dlg::OnRound)
	ON_COMMAND(ID_32776, &C优化的画线Dlg::OnRound)
	ON_COMMAND(ID_32780, &C优化的画线Dlg::OnClear)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// C优化的画线Dlg 消息处理程序

BOOL C优化的画线Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowLong (this->m_hWnd,GWL_EXSTYLE,GetWindowLong(this->m_hWnd ,GWL_EXSTYLE )^0x80000);
	HINSTANCE hInst = LoadLibrary(_T("User32.DLL"));
	if(hInst)
	{
		typedef BOOL (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD);  
		MYFUNC fun = NULL; //取得SetLayeredWindowAttributes函数指针
		fun=(MYFUNC)GetProcAddress(hInst, "SetLayeredWindowAttributes");
		if(fun)
		{  
			fun(this->m_hWnd,0,95,3.5);   //修改该参数就可以改变窗口透明程度
		}
		FreeLibrary(hInst);
	}
	 SetWindowLong(m_hWnd, GWL_STYLE, GetWindowLong(m_hWnd, GWL_STYLE) & (~(WS_CAPTION | WS_BORDER)));     //移除了对话框的边框
	 this->ShowWindow(SW_SHOWMAXIMIZED);   //对话框最大化  
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C优化的画线Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C优化的画线Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C优化的画线Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C优化的画线Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_startPoint =point;
	mpoint =point;
	m_Draw=true;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void C优化的画线Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC=GetDC();
    //设置画笔，颜色，并且选择到设备里面；
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


void C优化的画线Dlg::mink()
{
	

	ShowWindow(SW_MINIMIZE );
	// TODO: 在此添加控件通知处理程序代码
}



void C优化的画线Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//右键弹出快捷键
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu *pContextMenu=menu.GetSubMenu(0);
	CPoint mpoint ;
	GetCursorPos (&mpoint);
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,mpoint.x,mpoint.y,AfxGetMainWnd());

	CDialogEx::OnRButtonDown(nFlags, mpoint);
}


void C优化的画线Dlg::OnMenu()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg;
	dlg.m_cc.Flags |=CC_RGBINIT;
	dlg.m_cc.rgbResult=m_color;
	if(IDOK==dlg.DoModal ())
	{
		m_color =dlg.m_cc.rgbResult;
	}
}



void C优化的画线Dlg::OnMink()
{
	// TODO: 在此添加命令处理程序代码
	ShowWindow(SW_MINIMIZE );
}


void C优化的画线Dlg::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	OnExit ();
}


void C优化的画线Dlg::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	type=2;
}


void C优化的画线Dlg::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	type=1;
}


void C优化的画线Dlg::OnArrow()   //箭头
{
	// TODO: 在此添加命令处理程序代码
	type =3;
}


void C优化的画线Dlg::DrawArrow(CPoint p1, CPoint p2, double theta, double length)
{
	theta=3.1415926*theta/180;//转换为弧度
	double Px,Py,P1x,P1y,P2x,P2y;
	//以P2为原点得到向量P2P1（P）
	Px=p1.x-p2.x;
	Py=p1.y-p2.y;
	//向量P旋转theta角得到向量P1
	P1x=Px*cos(theta)-Py*sin(theta);
	P1y=Px*sin(theta)+Py*cos(theta);
	//向量P旋转-theta角得到向量P2
	P2x=Px*cos(-theta)-Py*sin(-theta);
	P2y=Px*sin(-theta)+Py*cos(-theta);
	//伸缩向量至制定长度
	double x1,x2;
	x1=sqrt(P1x*P1x+P1y*P1y);
	P1x=P1x*length/x1;
	P1y=P1y*length/x1;
	x2=sqrt(P2x*P2x+P2y*P2y);
	P2x=P2x*length/x2;
	P2y=P2y*length/x2;
	//平移变量到直线的末端
	P1x=P1x+p2.x;
	P1y=P1y+p2.y;
	P2x=P2x+p2.x;
	P2y=P2y+p2.y;
	CClientDC dc(this);//获取客户窗口DC
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


void C优化的画线Dlg::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	type=4;
}


void C优化的画线Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(type==4)
	{
		CDC* pDC=GetDC();
    //设置画笔，颜色，并且选择到设备里面；
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


void C优化的画线Dlg::OnOval()   //椭圆
{
	// TODO: 在此添加命令处理程序代码
	type=5;
}

//void C优化的画线Dlg::CirPot(int cx, int cy, int x, int y, CDC* pDC)
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


//void C优化的画线Dlg::DrawRound(CPoint m_startPoint, CPoint m_endPoint, CDC* pDC)
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


void C优化的画线Dlg::OnRound()
{
	// TODO: 在此添加命令处理程序代码
	type=6;
}


void C优化的画线Dlg::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
}


void C优化的画线Dlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC=NULL;
	CBrush *pBrush=CBrush ::FromHandle((HBRUSH )GetStockObject (NULL_BRUSH ));  //调用白色背景画刷会把文字给刷掉
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
