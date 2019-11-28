/*
 ************************************************************************
 *File Name: list.h
 *Author   : 
 *Date     : 2017年04月07日 星期五 16时30分55秒
 *Brief    : 
 ************************************************************************
 */
#ifndef _LIST_H
#define _LIST_H

#ifdef __cplusplus
 extern "C" {
#endif



#define MAX_SIZE 1024

typedef enum
{
    FALSE = 0,
    TRUE = 1
}Status;

typedef int ElementType;

typedef struct
{
    ElementType data[MAX_SIZE]; 
    int length;// start from 0

}list_t;



void InitList(list_t *list);
Status IsListEmpty(list_t *list);
Status IsListFull(list_t* list);
void ClearList(list_t* list);
Status GetElem(list_t* list, int index, ElementType * elem);
Status GetIndex(list_t* list, ElementType elem, int* index);
void GetLength(list_t* list, int* len);
Status InsertElem(list_t* list, int index, ElementType elem);
Status PushElem(list_t* list, ElementType elem);
Status DeletElem(list_t* list, int index);
Status PopElem(list_t* list);
Status CopyList(list_t* from, list_t* to);
Status AppendList(list_t* la, list_t* list);
Status AddList(list_t* la, list_t* lb, list_t* list);


void PrintList(list_t* list);


#ifdef __cplusplus
}
#endif


#endif
