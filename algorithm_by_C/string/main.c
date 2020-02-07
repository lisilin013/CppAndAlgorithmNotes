/*
 ************************************************************************
 *File Name: main.c
 *Author   : 
 *Date     : 2017年04月15日 星期六 13时06分22秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "string_handle.h"

int main(int argc, char const *argv[])
{
	int index;
	int table[100];
	string s = (string)malloc(sizeof(char)*100);
	string a = (string)malloc(sizeof(char)*100);
	s = "this a string!";
	a = "string";

	if(GetChildInldex_STRING(s,a,4,&index))
//	if(GetChildInldex_KMP(s, a, 4, &index))
		printf("get: %d\n", index);
	else
		printf("get filed!\n");


	printf("the length of string a is %d\n", GetStrLength(s));

	return 0;
}
