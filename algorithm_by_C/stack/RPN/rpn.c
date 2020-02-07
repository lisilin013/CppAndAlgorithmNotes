/*
 ************************************************************************
 *File Name: rpn.c
 *Author   : 
 *Date     : 2017年04月14日 星期五 21时56分36秒
 *Brief    : Reverse Polish Notation
 ************************************************************************
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "link_stack.h"



char* rpn = "9 3 1 - 3 * + 10 2 / +";

void TraversalString(char* str)
{
	while(*str)
		printf("%c", *str++);

	printf("\n");
}
BOOL IsLeftBracket(char* str)
{
	if(*str == '(')
		return TRUE;
	return FALSE;
}
BOOL IsRightBracket(char* str)
{
	if(*str == ')')
		return TRUE;
	return FALSE;
}

BOOL IsOperator(char* str)
{
	if(*str == "+" ||*str == "-" || *str == "*" || *str == "/")
		return TRUE;
	return FALSE;
}
void PushRPN(stLinkStack* stack, char* rpn)
{
	while(*str)
	{
		while(isdigit(*str))
		{
			char* cnum;
			int num;

			
			Push(stack, )
		}
		if(is)


		str++;
	}
}

void test()
{
	TraversalString(rpn);
}