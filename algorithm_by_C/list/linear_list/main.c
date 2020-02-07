/*
 ************************************************************************
 *File Name: main.c
 *Author   : 
 *Date     : 2017年04月07日 星期五 16时38分56秒
 *Brief    : 
 ************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main(int argc, char const *argv[])
{
    int i=0;
    int len;
    int index;
 
    list_t list;
    list_t cp_list;
    list_t add_list;
    
    InitList(&list);
    InitList(&cp_list);
    InitList(&add_list);
    
    for (i = 0; i < 10; i++)
    {
        PushElem(&list, i+10);
    }
    
    CopyList(&list, &cp_list);
    AppendList(&list, &cp_list);
    PrintList(&cp_list);

    return 0;
}
