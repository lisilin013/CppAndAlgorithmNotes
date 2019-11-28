/*
 ************************************************************************
 *File Name: linklist.c
 *Author   : 
 *Date     : 2017年04月07日 星期五 18时44分34秒
 *Brief    : HITCRT C Program Style
 ************************************************************************
 */
#include "linklist.h"

static BOOL CreatNode(pstLinkList* p) /* double ** */
{
	*p = (pstLinkList)malloc(sizeof(stNode));

	if(!(*p))
		return FALSE;

	(*p)->next = NULL;
	(*p)->data = 666;

	return TRUE;
}


/*
* creat head point to first node
*/
BOOL InitList(pstLinkList* pstll, int n) /* double ** */
{
	int i;
	pstLinkList pstnode,p;
 
 	CreatNode(pstll);//creat head pointer

 	p = *pstll;
	for(i=0; i<n; i++)
	{
		CreatNode(&pstnode);
		
		pstnode->data = i;
		pstnode->next = p->next;

		p->next = pstnode;
	}

	return TRUE;
}


BOOL IsListEmpty(pstLinkList pstll)
{
	return !pstll->next;
}



/*
* if index=0 ,return the head pointer
* pll <----> index =0~len
*/
BOOL GetptrList(pstLinkList pstll, int index, pstLinkList* pll)
{
	int count;
	pstLinkList p;

	p = pstll;//head pointer
	count = 0;
	while(p && index>=0)
	{
		if(index == count)
		{
			*pll = p;

			return TRUE;
		}
		else
		{
			p = p->next;
			count++;
		}
	}
	
	*pll = NULL;
	return FALSE;
}

/*
* index>=1 && index <= GetLength(L)
*/
BOOL GetElem(pstLinkList pstll, int index, ElementType * elem)
{
	pstLinkList p;

	if(GetptrList(pstll, index, &p) && index>=1)// index<= len
	{
		*elem = p->data;
		return TRUE;
	}

	return FALSE;
}


BOOL GetIndex(pstLinkList pstll, ElementType elem, int* index)
{
	int count;
	pstLinkList p;

	count = 1;
	p = pstll->next;//first node

	while(p)
	{
		if(p->data == elem)
		{
			*index = count;
			return TRUE;
		}
		else
		{
			p = p->next;
			count++;
		}
	}

	return FALSE;
}



/*
* node counts
*/
void GetLength(pstLinkList pstll, int* len)
{
	int count;
	pstLinkList p;

	p = pstll->next;//first node
	count = 0;

	while(p)
	{
		count++;
		p = p->next;
	}

	*len = count;
}

/*
* insert node at index
*/
BOOL InsertElem(pstLinkList pstll, int index, ElementType elem)
{
	pstLinkList p,pNode;

	/*index>=1 && index <= len+1*/
	if(GetptrList(pstll, index-1, &p))
	{
		CreatNode(&pNode);
		pNode->data = elem;
		pNode->next = p->next;

		p->next = pNode;
		return TRUE;
	}

	return FALSE;	
}

BOOL PushElem(pstLinkList pstll, ElementType elem)
{
	int len;

	GetLength(pstll, &len);
	return InsertElem(pstll,len+1,elem);
}

BOOL DeletElem(pstLinkList pstll, int index)
{
	pstLinkList p,pDelNode;

	if(GetptrList(pstll, index-1, &p))
	{
		pDelNode = p->next;
		
		if(!pDelNode)//in case p is the end 
			return FALSE;

		p->next = pDelNode->next;
		free(pDelNode);
		printf("free ok!\n");
		return TRUE;
	}
	return FALSE;
}

BOOL PopElem(pstLinkList pstll)
{
	int len;

	GetLength(pstll, &len);
	return DeletElem(pstll,len);
}


void ClearList(pstLinkList pstll)
{
	pstLinkList p;

	p = pstll->next;//first node
	while(pstll)
	{
		free(pstll);
		pstll = p;

		if(p)  //in case core dumped
			p = p->next;
	}
}




// BOOL CopyList(pstLinkList from, pstLinkList to);
// BOOL AppendList(pstLinkList pstlla, pstLinkList pstll);
// BOOL AddList(pstLinkList pstlla, pstLinkList lb, pstLinkList pstll);


void PrintList(pstLinkList pstll)
{
	pstLinkList p;

	p = pstll->next;//first node

	while(p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}


