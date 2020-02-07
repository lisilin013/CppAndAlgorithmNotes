/*
 ************************************************************************
 *File Name: static_linklist.c
 *Author   : 
 *Date     : 2017年04月09日 星期日 00时57分52秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "TYPES.h"

#define MAX_SIZE 1024

typedef int ElementType;

typedef struct 
{
	ElementType data;
	int cur;	
}StaticLinkList[MAX_SIZE];//new defination way



/*
* cur=0          store the unused beginning cur
* cur=MAX_SIZE-1 store first node
*/

BOOL InitList(StaticLinkList space)
{
	int i;

	for (i = 0; i < MAX_SIZE-1; ++i)
	{
		/* code */
		space[i].cur = i+1;
	}

	space[MAX_SIZE-1].cur = 0;

	return TRUE;
}

BOOL IsListEmpty(StaticLinkList sll)
{

}

BOOL IsListFull(StaticLinkList sll)
{


}

int MallocSLL(StaticLinkList space)
{
	int unused_cur_begin;

	unused_cur_begin = space[0].cur;

	if(unused_cur_begin)
		space[0].cur = space[unused_cur_begin].cur;//cur0 point to next

	return unused_cur_begin;//return the malloced cur
}

int FreeSLL(StaticLinkList space, int i)
{
	space[i].cur = space[0].cur;
	space[0].cur = i;
}


int GetLength(StaticLinkList sll)
{
	int len,k;

	len = 0;
	k = sll[MAX_SIZE-1].cur;
	while(k)
	{
		k = sll[k].cur;
		len++;
	}

	return len;
}

BOOL GetIndex()
{

}

BOOL GetElem()
{

}



BOOL InsertElem(StaticLinkList sll, int index, ElementType elem)
{
	int unused_cur, pre_i, k;

	if(index<1 || index>GetLength(sll)+1)
		return FALSE;

	unused_cur = MallocSLL(sll);

	k = MAX_SIZE-1;
	if(unused_cur)
	{
		for(pre_i=0;pre_i<=index-1;pre_i++)
		k = sll[k].cur;
		
		sll[unused_cur].data = elem;
		sll[unused_cur].cur = sll[k].cur;	

		sll[k].cur = unused_cur;

		return TRUE;
	}	

	return FALSE;
}


BOOL DeletElem(StaticLinkList sll, int index)
{
	int pre_i,k,j;

	if(index<1 || index>GetLength(sll))
		return FALSE;

	k = MAX_SIZE-1;
	for(pre_i=0; pre_i<=index-1; pre_i++)
		k = sll[k].cur;

	j = sll[k].cur;

	sll[k].cur = sll[j].cur;
	FreeSLL(sll,j);

	return TRUE;
}





int main()
{
	int len;
	StaticLinkList sll;

	InitList(sll);

	InsertElem(sll,1,4);

	len = GetLength(sll);

	printf("%d\n", len);


    return 0;
}



