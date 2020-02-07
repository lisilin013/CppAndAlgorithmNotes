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


#define QUEUE_SIZE 1024

typedef int ElementType;

/*
*rear point to empty positon
*front point to first positon
* 0 1 2 3 4 5 6 7 8 9.... QUEUE_SIZE-1
*     + + + + + +
*     ^           ^
*     |           |
*    front       rear
*/
typedef struct 
{
	ElementType data[QUEUE_SIZE];
	int front;
	int rear;	
}stQueue;

BOOL InitQueue(stQueue* q);
int GetLength(stQueue* q);
BOOL IsQueueFull(stQueue* q);
BOOL IsQueueEmpty(stQueue* q);
BOOL EnQueue(stQueue* q, ElementType elem);
BOOL DeQueue(stQueue* q, ElementType* elem);


#endif
