/*
 ************************************************************************
 *File Name: stack.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 01时58分16秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"


void InitStack(stLinkStack* stack)
{
	//stack->top = (stStackNode*)malloc(sizeof(stStackNode));
	stack->length = 0;
	stack->top->next = NULL;
}


BOOL IsEmptyStack(stLinkStack* stack)
{
	return !stack->length;
}

BOOL Push(stLinkStack* stack, ElementType elem)
{
	stStackNode* node = (stStackNode*)malloc(sizeof(stStackNode));
	node->next = stack->top;
	node->data = elem;

	stack->top = node;
	stack->length++;

	return TRUE;
}

BOOL Pop(stLinkStack* stack, ElementType *elem)
{
	stStackNode* delNode;

	if(IsEmptyStack(stack))
		return FALSE;

	delNode = stack->top;
	*elem = delNode->data;
	stack->top = delNode->next;


	free(delNode);
	stack->length--;

	return TRUE;
}
int GetLength(stLinkStack* stack)
{
	return stack->length;
}

void ClearStack(stLinkStack* stack)
{
	stStackNode* delNode;

	while(!IsEmptyStack(stack))
	{
		delNode = stack->top;
		stack->top = delNode->next;

		free(delNode);
		stack->length--;
	}
}