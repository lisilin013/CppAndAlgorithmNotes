/*
 ************************************************************************
 *File Name: double_stack.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 02时38分43秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "double_stack.h"

void InitStack(stDoubleStack* stack)
{
	stack->top1 = -1;
	stack->top2 = MAX_SIZE;
}

BOOL IsFullStack(stDoubleStack* stack)
{
	return (stack->top1+1 == stack->top2);
}

BOOL IsEmptyStack(stDoubleStack* stack)
{
	return (stack->top1==-1 && stack->top2==MAX_SIZE);
}

BOOL Push(stDoubleStack* stack,int stack_num, ElementType elem)
{
	if(IsFullStack(stack))
		return FALSE;

	if(stack_num==1)
	{
		stack->data[++stack->top1] = elem;
		return TRUE;
	}
	else if(stack_num==2)
	{
		stack->data[--stack->top2] = elem;
		return TRUE;
	}
	else
		return FALSE;
}

BOOL Pop(stDoubleStack* stack, int stack_num, ElementType *elem)
{
	if(stack_num==1)
	{
		if(stack->top1==-1)
			return FALSE;

		*elem = stack->data[stack->top1--];
		return TRUE;
	}
	else if(stack_num==2)
	{
		if(stack->top2==1024)
			return FALSE;

		*elem = stack->data[stack->top2++];
		return TRUE;
	}
	else
		return FALSE;
}
int GetLength(stDoubleStack* stack)
{
	return stack->top1+1 + 1024-stack->top2;
}









