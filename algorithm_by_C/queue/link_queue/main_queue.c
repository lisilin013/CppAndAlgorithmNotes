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
	int i,elem,enqueue_len,dequeue_len;
	stLinkQueue q;
	InitQueue(&q);

	enqueue_len = 10;
	dequeue_len = 10;
	//enqueue
	for (i = 0; i < enqueue_len; ++i)
	{
		if(EnQueue(&q, i))		
			printf("EnQueue elem: %d\n", i);
		else
			printf("EnQueue failed!\n");
	}

	printf("Queue len: %d\n", GetLength(&q));


	//dequeue
	for (i = 0; i < dequeue_len; ++i)
	{
		if(DeQueue(&q, &elem))
			printf("DeQueue elem: %d\n", elem);
		else
			printf("DeQueue failed!\n");
	}

	printf("Queue len: %d\n", GetLength(&q));
	

	//destroy
	DestoryQueue(&q);
	printf("DestoryQueue...\n");
	return 0;
}