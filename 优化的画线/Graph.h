#pragma once
#include"atltypes.h"
class CGraph
{
public:
	CGraph(void);
	~CGraph(void);
	UINT type;   //�洢ѡ��ͼ������
	CPoint m_stPoint;  //���
	CPoint m_toPoint;    //��ת��
	CPoint m_ptEnd;    //�յ�
	UINT nFlage;
	CGraph(UINT type,UINT nFlage, CPoint m_stPoint, CPoint m_toPoint,CPoint m_ptEnd);
};

