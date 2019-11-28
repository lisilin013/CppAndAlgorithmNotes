/*
 ************************************************************************
 *File Name: string_handle.h
 *Author   : 
 *Date     : 2017年04月15日 星期六 13时52分55秒
 *Brief    : 
 ************************************************************************
 */
#ifndef _STRING_HANDLE_H
#define _STRING_HANDLE_H

#ifdef __cplusplus
 extern "C" {
#endif





#include "TYPES.h"

typedef char* string;

int GetStrLength(string str);
BOOL IsStrEqual(string s, string t);
BOOL GetStr(string mother, int i, int m, string child);

BOOL GetChildInldex_STRING(string mother, string child, int pos, int* index);
BOOL GetChildIndex_ARRAY(string mother, string child, int pos, int* index);
void GetTable(string s, int *table);
BOOL GetChildInldex_KMP(string mother, string child, int pos, int* index);
void GetTableVal(string s, int *tableval);
BOOL GetChildInldex_KMP_UPGRADE(string mother, string child, int pos, int* index);


#ifdef __cplusplus
}
#endif

#endif
