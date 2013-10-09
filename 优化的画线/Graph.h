#pragma once
#include"atltypes.h"
class CGraph
{
public:
	CGraph(void);
	~CGraph(void);
	UINT type;   //存储选择图像类型
	CPoint m_stPoint;  //起点
	CPoint m_toPoint;    //中转点
	CPoint m_ptEnd;    //终点
	UINT nFlage;
	CGraph(UINT type,UINT nFlage, CPoint m_stPoint, CPoint m_toPoint,CPoint m_ptEnd);
};

