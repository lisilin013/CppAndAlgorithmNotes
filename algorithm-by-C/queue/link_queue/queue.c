/*
 ************************************************************************
 *File Name: queue.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 01时59分59秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//front and rear point to head node
BOOL InitQueue(stLinkQueue* q)
{
	q->front = (stQueueNode*)malloc(sizeof(stQueueNode));//creat head node
	q->front->next = NULL;
	q->rear = q->front;
}

int GetLength(stLinkQueue* q)
{
	int count=0;
	stQueueNode* node;

	node = q->front;//first node
	while(node!=q->rear)
	{
		count++;
		node = node->next;
	}

	return count;
}

BOOL IsQueueEmpty(stLinkQueue* q)
{
	return q->front==q->rear;
}

BOOL EnQueue(stLinkQueue* q, ElementType elem)
{
	stQueueNode* node;

	node = (stQueueNode*)malloc(sizeof(stQueueNode));

	node->data = elem;
	node->next = NULL;
	q->rear->next = node;//key step
	q->rear = node;

	return TRUE;
}

BOOL DeQueue(stLinkQueue* q, ElementType* elem)
{
	stQueueNode* Delnode;

	if(IsQueueEmpty(q))
		return FALSE;

	Delnode = q->front->next;
	*elem = Delnode->data;
	q->front->next = Delnode->next;

	if (Delnode == q->rear)//only left one elem
		q->rear = q->front;

	free(Delnode);

	return TRUE;
}

BOOL DestoryQueue(stLinkQueue* q)
{
	stQueueNode* Delnode;

	while(!IsQueueEmpty(q))
	{
		Delnode = q->front->next;
		q->front->next = Delnode->next;

		if (Delnode == q->rear)//only left one elem
			q->rear = q->front;

		free(Delnode);
	}
	free(q->front);

	return TRUE;
}


