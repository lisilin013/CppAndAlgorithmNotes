/*
 ************************************************************************
 *File Name: main_queue.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 01时59分50秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "queue.h"


int main(int argc, char const *argv[])
{
	int i,elem;
	stQueue q;
	InitQueue(&q);

	for (i = 0; i < 5; ++i)
	{
		if(EnQueue(&q, i))		
			printf("enqueue elem: %d\n", i);
		else
			printf("EnQueue failed!\n");
	}

	if(EnQueue(&q, 9))
		printf("enqueue failed!\n");

	printf("queue len: %d\n", GetLength(&q));

	for (i = 0; i < 5; ++i)
	{
		if(DeQueue(&q, &elem))
			printf("dequeue elem: %d\n", elem);
		else
			printf("DeQueue failed!\n");
	}

	printf("queue len: %d\n", GetLength(&q));
	
	if(!DeQueue(&q, &elem))
		printf("dequeue failed!\n");

	return 0;
}