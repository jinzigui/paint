#include "stdafx.h"
#include "Graph.h"


CGraph::CGraph(void)
{
}


CGraph::~CGraph(void)
{
}

CGraph::CGraph(UINT type,UINT nFlage,CPoint m_stPoint,CPoint m_toPoint,CPoint m_ptEnd)
{
	this->type =type;
	this->nFlage=nFlage;
	this->m_stPoint  =m_stPoint;
	this->m_toPoint =m_toPoint;
	this->m_ptEnd=m_ptEnd;
}