/*
 ************************************************************************
 *File Name: main_stack.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 01时58分05秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "link_stack.h"

int main(int argc, char const *argv[])
{
	int i,len;
	stLinkStack stack;

	InitStack(&stack);


	for (i = 0; i < 10; ++i)
	{
		Push(&stack, i);
		printf("push elem %d\n", i);
	}


	printf("len is %d\n\n", GetLength(&stack));

	for (i = 0; i < 4; ++i)
	{
		ElementType elem;
		Pop(&stack, &elem);
		printf("pop elem %d\n", elem);
	}

	printf("len is %d\n", GetLength(&stack));
	
	ClearStack(&stack);
	return 0;
}