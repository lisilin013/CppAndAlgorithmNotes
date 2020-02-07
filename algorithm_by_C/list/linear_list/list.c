/*
 ************************************************************************
 *File Name: list.c
 *Author   : 
 *Date     : 2017年04月07日 星期五 11时22分48秒
 *Brief    : static linear list using array to store data
 ************************************************************************
 */
#include "list.h"
#include <stdio.h>
/*
* implementation
*/

void InitList(list_t *list)
{
    list->length = -1;
}
 
Status IsListEmpty(list_t *list)
{
    if (list->length == -1)
        return TRUE;
    else
        return FALSE;
}

Status IsListFull(list_t* list)
{
    if(list->length == MAX_SIZE-1)
        return TRUE;
    else
        return FALSE;
}

void ClearList(list_t* list)
{
    list->length = -1;
}


Status GetElem(list_t* list, int index, ElementType * elem)
{
    if(IsListEmpty(list) || index <0 || index>list->length)
        return FALSE;

    *elem = list->data[index];
    
    return TRUE;
}

Status GetIndex(list_t* list, ElementType elem, int* index)
{
    int i = 0;

    while(i <= list->length)
    {
        if(list->data[i] == elem)
        {
            *index = i;

            return TRUE;
        }

        i++;
    }

    return FALSE;
}

void GetLength(list_t* list, int* len)
{
    *len = list->length+1;
}


// put the elme at the index
Status InsertElem(list_t* list, int index, ElementType elem)
{
    int i=0;

    if(IsListFull(list) || index<0 || index>list->length+1)// list is full or index is elligal
        return FALSE;

    // insert not at length+1, move firstly
    if(index <= list->length) 
    {
        for(i=list->length+1; i>index; i--)
            list->data[i] = list->data[i-1];
    }

    // insert 
    list->data[index] = elem;
    list->length++;

    return TRUE;
}

Status PushElem(list_t* list, ElementType elem)
{
    return InsertElem(list, list->length+1, elem);
}

Status DeletElem(list_t* list, int index)
{
    int i=0;

    if(IsListEmpty(list) || index<0 || index>list->length)
        return FALSE;

    //delet not at length, move firstly
    if(index < list->length)
    {        
        for(i=index; i<list->length; i++)
            list->data[index] = list->data[index+1];
    }

    list->length--;

    return TRUE;
}

Status PopElem(list_t* list)
{
    return DeletElem(list,list->length);
}


Status CopyList(list_t* from, list_t* to)
{
    int i,len;

    InitList(to);
    GetLength(from, &len);

    for(i=0; i<len; i++)
        PushElem(to, from->data[i]);

    return TRUE;
}


Status AppendList(list_t* la, list_t* list)
{   
    int i,la_len,len;

    GetLength(la, &la_len);    
    GetLength(list, &len);

    if(la_len+len > MAX_SIZE)
        return FALSE;

    for(i=0; i<len; i++)
        PushElem(list, la->data[i]);

    return TRUE;
}

// la+lb: put lb behind la
Status AddList(list_t* la, list_t* lb, list_t* list)
{
    int i,la_len,lb_len;

    GetLength(la, &la_len);
    GetLength(lb, &lb_len);

    if(la_len+lb_len > MAX_SIZE)
        return FALSE;

    CopyList(la, list);

    for(i=0; i<lb_len; i++)
        PushElem(list, lb->data[i]);

    return TRUE;
}


void PrintList(list_t* list)
{
    int i, len;

    GetLength(list, &len);

    for(i=0; i<len; i++)
        printf("%d\n", list->data[i]);
}



