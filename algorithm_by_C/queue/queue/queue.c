/*
 ************************************************************************
 *File Name: queue.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 01时59分59秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "queue.h"


BOOL InitQueue(stQueue* q)
{
	q->front = 0;
	q->rear = 0;

	return TRUE;
}

int GetLength(stQueue* q)
{
	return (q->rear-q->front+QUEUE_SIZE)%QUEUE_SIZE;
}

BOOL IsQueueFull(stQueue* q)
{
	return (q->rear+1)%QUEUE_SIZE == q->front;
}

BOOL IsQueueEmpty(stQueue* q)
{
	return q->rear==q->front;
}

BOOL EnQueue(stQueue* q, ElementType elem)
{
	if(IsQueueFull(q))
		return FALSE;

	q->data[q->rear] = elem;
	q->rear = (q->rear+1) % QUEUE_SIZE;

	return TRUE;
}


BOOL DeQueue(stQueue* q, ElementType* elem)
{
	if(IsQueueEmpty(q))
		return FALSE;

	*elem = q->data[q->front];
	q->front = (q->front+1)%QUEUE_SIZE;

	return TRUE;
}

