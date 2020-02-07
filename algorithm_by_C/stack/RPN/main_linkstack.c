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

void test();

int main(int argc, char const *argv[])
{
	int i,len;
	stLinkStack stack;

	InitStack(&stack);


	test();
	
	ClearStack(&stack);
	return 0;
}