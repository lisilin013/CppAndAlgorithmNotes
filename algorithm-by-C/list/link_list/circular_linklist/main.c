/*
 ************************************************************************
 *File Name: main.c
 *Author   : 
 *Date     : 2017年04月07日 星期五 17时35分19秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "linklist.h"

int test();

int main(int argc, char const *argv[])
{
	test();


	return 0;
}


int test()
{
	pstLinkList pstll, pll;

	ElementType elem;
	int index,len;

	if(!InitList(&pstll, 2))
	{
		printf("Init failed!\n");
		ClearList(pstll);
		
		return 0;
	}

	if(IsListEmpty(pstll))
	{
		printf("this link list is empty!\n");
		ClearList(pstll);

		return 0;
	}

	printf("link list elements are:\n");
	printf("======\n");
	PrintList(pstll);
	printf("\n\n\n");

	GetLength(pstll, &len);
	printf("link list length: %d\n", len);

	if(GetIndex(pstll, 3, &index))
		printf("elem 3 at the index: %d\n",index);
	else
		printf("elem 3 is not existing in the link list\n");

	if(GetElem(pstll, 4, &elem))
		printf("elem at the index 4: %d\n", elem);
	else
		printf("index is not elligal!\n");
	printf("\n\n\n");


	printf("insert elem 90 at index 3: \n");
	if(InsertElem(pstll, 3, 90))
	{
		printf("now, link list's elem are: \n");
		PrintList(pstll);
	}
	else 
		printf("insert index is not elligal!\n");
	printf("\n\n\n");


	printf("push elem 88 at the end of the link list: \n");
	if(PushElem(pstll, 88))
	{
		printf("now, link list's elem are: \n");
		PrintList(pstll);
	}
	else
		printf("push failed!\n");
	printf("\n\n\n");


	printf("delet the elem at the index 1: \n");
	if(DeletElem(pstll, 1))
	{
		printf("now, link list's elem are: \n");
		PrintList(pstll);
	}
	else
		printf("delet index are elligal!\n");
	printf("\n\n\n");



	printf("pop elem at the the end of the link list\n");
	if(PopElem(pstll))
	{
		printf("now, link list's elem are: \n");
		PrintList(pstll);		
	}
	else
		printf("pop failed!\n");
	printf("\n\n\n");


	printf("clear the list...\n");
	ClearList(pstll);
	printf("link list datastructure exercise is the end...\n");
	printf("see u ^_^ !\n");
	printf("\n\n\n");
	
}