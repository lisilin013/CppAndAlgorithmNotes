/*
 ************************************************************************
 *File Name: linklist.c 
 *Author   : 
 *Date     : 2017年04月07日 星期五 18时44分34秒
 *Brief    : single dirction circular linked list
 ************************************************************************
 */
#include "linklist.h"

BOOL CreatNode(pstLinkList* p) /* double ** */
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

 	p->next = p;//diff1:head node pointer point to itself
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
	return pstll->next==pstll;//diff2: empty list's head node point to itself
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
	while(p->next!=pstll && index>=0)//diff3: the key difference
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
	
	if(index==count)//incase index is the last elem's index
	{
		*pll = p;
		return TRUE;
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

	while(p!=pstll)//diff4: the key difference
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

	while(p!=pstll)//diff5: the key difference
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
		
		if(pDelNode==pstll)//diff6: in case the index is head node index 
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


// diff: 
void ClearList(pstLinkList pstll)
{
	pstLinkList p,pDelNode;

	pDelNode = pstll->next;//first node
	while(pDelNode!=pstll)
	{
		p = pDelNode->next;//tmp node
		free(pDelNode);
		pstll->next = p;
		pDelNode = p;
	}
	free(pDelNode);//free head node
}




// BOOL CopyList(pstLinkList from, pstLinkList to);
// BOOL AppendList(pstLinkList pstlla, pstLinkList pstll);
// BOOL AddList(pstLinkList pstlla, pstLinkList lb, pstLinkList pstll);


void PrintList(pstLinkList pstll)
{
	pstLinkList p;

	p = pstll->next;//first node

	while(p!=pstll)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}


