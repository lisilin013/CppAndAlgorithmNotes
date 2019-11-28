/*
 ************************************************************************
 *File Name: double_stack.h
 *Author   : 
 *Date     : 2017年04月10日 星期一 02时38分48秒
 *Brief    : 
 ************************************************************************
 */
#ifndef _DOUBLE_STACK_H
#define _DOUBLE_STACK_H

#include "TYPES.h"

#define MAX_SIZE 1024


typedef int ElementType;

typedef struct
{
    ElementType data[MAX_SIZE]; 
    int top1;
    int top2; 

}stDoubleStack;


void InitStack(stDoubleStack* stack);
BOOL IsFullStack(stDoubleStack* stack);
BOOL IsEmptyStack(stDoubleStack* stack);
BOOL Push(stDoubleStack* stack,int stack_num, ElementType elem);
BOOL Pop(stDoubleStack* stack, int stack_num, ElementType *elem);
int GetLength(stDoubleStack* stack);


#endif
