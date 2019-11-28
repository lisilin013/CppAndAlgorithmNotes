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

#define MAX_SIZE 1024


typedef int ElementType;

typedef struct
{
    ElementType data[MAX_SIZE]; 
    int top; 

}stStack;


void InitStack(stStack* stack);
BOOL IsFullStack(stStack* stack);
BOOL IsEmptyStack(stStack* stack);
BOOL Push(stStack* stack, ElementType elem);
BOOL Pop(stStack* stack, ElementType *elem);
int GetLength(stStack* stack);



#endif
