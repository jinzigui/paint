
// �Ż��Ļ���Dlg.h : ͷ�ļ�
//

#pragma once
#include "atltypes.h"
#include "afxcoll.h"


// C�Ż��Ļ���Dlg �Ի���
class C�Ż��Ļ���Dlg : public CDialogEx
{
// ����
public:
	C�Ż��Ļ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	UINT type;
	BOOL draw;
	CPoint mpoint;
	int lineStyle;
	UINT lineWidth;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void mink();
//	afx_msg void OnColor();
	COLORREF m_color;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMenu();
	afx_msg void OnMink();
//	afx_msg void OnExit();
	afx_msg void OnRectangle();
	
	afx_msg void OnLine();
	afx_msg void OnArrow();
	void DrawArrow(CPoint p1, CPoint p2, double theta, double length);
	afx_msg void OnDrawLine();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	BOOL m_Draw;
	afx_msg void OnOval();
//	afx_msg void OnRound();
//	void CirPot(int cx, int cy, int x, int y, CDC* pDC);
//	void DrawRound(CPoint m_startPoint, CPoint m_endPoint, CDC* pDC);
	afx_msg void OnRound();
	afx_msg void OnClear();
//	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
public:
	CPtrArray m_ptrArray;
public:
	afx_msg void OnOpen();
//	afx_msg void OnClose();
	afx_msg void OnClose();
	CPoint m_ptOrigin;
private:
	CPoint m_startPoint;              //�����Ū���Һþ�
public:
	afx_msg LRESULT OnNcHitTest(CPoint point);
	BOOL m_rect;
};
