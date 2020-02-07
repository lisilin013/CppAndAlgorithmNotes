/*
 ************************************************************************
 *File Name: stack.h
 *Author   : 
 *Date     : 2017年04月10日 星期一 01时58分22秒
 *Brief    : 
 ************************************************************************
 */
#ifndef _STACK_H
#define _STACK_H

#include "TYPES.h"



typedef int ElementType;

typedef struct stStackNode
{
	ElementType data;
	struct stStackNode* next;
}stStackNode;

typedef struct
{
    stStackNode* top; 
    int length;
}stLinkStack;


void InitStack(stLinkStack* stack);
BOOL IsFullStack(stLinkStack* stack);
BOOL IsEmptyStack(stLinkStack* stack);
BOOL Push(stLinkStack* stack, ElementType elem);
BOOL Pop(stLinkStack* stack, ElementType *elem);
int GetLength(stLinkStack* stack);
void ClearStack(stLinkStack* stack);


#endif
