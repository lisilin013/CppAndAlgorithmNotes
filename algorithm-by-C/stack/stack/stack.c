/*
 ************************************************************************
 *File Name: stack.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 01时58分16秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "stack.h"



void InitStack(stStack* stack)
{
	stack->top = -1;
}


BOOL IsFullStack(stStack* stack)
{
	return (stack->top == MAX_SIZE-1);
}

BOOL IsEmptyStack(stStack* stack)
{
	return (stack->top == -1);
}

BOOL Push(stStack* stack, ElementType elem)
{
	if((IsFullStack(stack)))
		return FALSE;

	stack->data[++stack->top] = elem;

	return TRUE;
}


BOOL Pop(stStack* stack, ElementType *elem)
{
	if(IsEmptyStack(stack))
		return FALSE;

	*elem = stack->data[stack->top--];
	return TRUE;
}

int GetLength(stStack* stack)
{
	return stack->top+1;
}


