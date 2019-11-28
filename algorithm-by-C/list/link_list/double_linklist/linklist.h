/*
 ************************************************************************
 *File Name: linklist.h
 *Author   : 
 *Date     : 2017年04月07日 星期五 18时44分43秒
 *Brief    : 
 ************************************************************************
 */
#ifndef _LINKLIST_H
#define _LINKLIST_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "TYPES.h"



typedef int ElementType;


typedef struct stNode 
{
	ElementType data;
	struct stNode *next;
	struct stNode *prior;	
}stNode;

typedef struct stNode* pstLinkList;



BOOL InitList(pstLinkList* pstll, int n);
BOOL IsListEmpty(pstLinkList pstll);

BOOL GetptrList(pstLinkList pstll, int index, pstLinkList* pll);
BOOL GetElem(pstLinkList pstll, int index, ElementType * elem);
BOOL GetIndex(pstLinkList pstll, ElementType elem, int* index);
void GetLength(pstLinkList pstll, int* len);

BOOL InsertElem(pstLinkList pstll, int index, ElementType elem);
BOOL PushElem(pstLinkList pstll, ElementType elem);

BOOL DeletElem(pstLinkList pstll, int index);
BOOL PopElem(pstLinkList pstll);
void ClearList(pstLinkList pstll);

void PrintList(pstLinkList pstll);



#ifdef __cplusplus
}
#endif

#endif
