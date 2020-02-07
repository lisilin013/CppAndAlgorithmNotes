/*
 ************************************************************************
 *File Name: queue.h
 *Author   : 
 *Date     : 2017年04月10日 星期一 02时00分03秒
 *Brief    : 
 ************************************************************************
 */
#ifndef _QUEUE_H
#define _QUEUE_H
#include "TYPES.h"


typedef int ElementType;

/*
*rear point to empty positon
*front point to first positon
*   
* head_node  + + + + + + +
*   ^                    ^
*   |                    |
*  front                rear
*/
typedef struct stQueueNode
{
	ElementType data;
	struct stQueueNode* next;	
}stQueueNode;

typedef struct 
{
	stQueueNode* front;
	stQueueNode* rear;
}stLinkQueue;

BOOL InitQueue(stLinkQueue* q);
int GetLength(stLinkQueue* q);
BOOL IsQueueFull(stLinkQueue* q);
BOOL IsQueueEmpty(stLinkQueue* q);
BOOL EnQueue(stLinkQueue* q, ElementType elem);
BOOL DeQueue(stLinkQueue* q, ElementType* elem);
BOOL DestoryQueue(stLinkQueue* q);

#endif
