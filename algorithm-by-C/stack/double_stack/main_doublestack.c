/*
 ************************************************************************
 *File Name: main_doublestack.c
 *Author   : 
 *Date     : 2017年04月10日 星期一 02时38分21秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include "double_stack.h"

int main(int argc, char const *argv[])
{
	int i;
	stDoubleStack stack;

	InitStack(&stack);
	printf("len %d\n", GetLength(&stack));

	for(i=0;i<4;i++)
	{
		Push(&stack, 1, i);
		Push(&stack, 2, i+10);
		printf("push stack1 elem %d\n", i);
		printf("push stack2 elem %d\n", i+10);
	}

	printf("len %d\n", GetLength(&stack));

	for (i = 0; i < 4; ++i)
	{
		ElementType elem;

		Pop(&stack, 1, &elem);
		printf("pop stack1 elem %d\n", elem);
		Pop(&stack, 2, &elem);
		printf("pop stack2 elem %d\n", elem);
	}

	printf("len %d\n", GetLength(&stack));

	return 0;
}