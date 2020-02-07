/*
 ************************************************************************
 *File Name: string_handle.c
 *Author   :
 *Date     : 2017年04月15日 星期六 13时52分50秒
 *Brief    :
 ************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "string_handle.h"



int GetStrLength(string str)
{
	int count = 0;

	while (*str)
	{
		str++;
		count++;
	}

	return count;
}


BOOL IsStrEqual(string s, string t)
{
	while (*s == *t && *s && *t)
	{
		s++;
		t++;
	}

	if (*s || *t)
		return FALSE;

	return TRUE;
}

/*
* 0<=i<=strlen(mother)-1
* m>=1
* include index i
*/
BOOL GetStr(string mother, int i, int m, string child)
{
	int count = 0;

	if (i < 0 || m < 1)
		return FALSE;

	while (mother[i] && count < m)
	{
		*child++ = mother[i++];

		count++;
	}

	if (count == m)
		return TRUE;
	else
		return FALSE;
}



/*
*----------------------------------------------------
* usual char model match using str implementation
*----------------------------------------------------
* brief : get the index of child in str after pos for the first time
* return: index of child in mother for the first time
*/
BOOL GetChildInldex_STRING(string mother, string child, int pos, int* index)
{
	int m_len, c_len, i;
	string str;

	m_len = GetStrLength(mother);
	c_len = GetStrLength(child);
	i = pos;
	str = (string)malloc(sizeof(char) * c_len);

	if (pos < 0)
		return FALSE;

	while (i <= m_len - c_len) //rest of mother len>=c_len
	{
		if (GetStr(mother, i, c_len, str))
		{
			if (IsStrEqual(str, child))
			{
				*index = i;
				return TRUE;
			}
			else
				i++;
		}

	}

	return FALSE;
}


/*
*----------------------------------------------------
* usual char model match using array implementation
*----------------------------------------------------
* brief : get the index of child in str after pos(include pos index) for the first time
* return: pos of child in mother for the first time
*/
BOOL GetChildIndex_ARRAY(string mother, string child, int pos, int* index)
{
	int i = pos;
	int j = 0;

	while (mother[i] && child[j])
	{
		if (mother[i] == child[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (!child[j])
	{
		*index = i - j;
		return TRUE;
	}
	else
		return FALSE;
}

/*
**************************************************************************
*                             KMP algorithm
* -----------------------------------------------------------------------
* brief    : index start from 0
* Reference: http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
*		     http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
**************************************************************************
*/
void GetTable(string s, int *table)
{
	int i, j;

	table[0] = 0;//first char's
	i = 0;
	j = 1;//from the second char

	while (s[j])
	{
		if (s[i] == s[j])
		{
			i++;
			table[j] = i;
			j++;
		}
		else
		{
			table[j] = 0;
			i = 0;
			j++;
		}
	}
}

/*
* Brief: pos>=0 index>=0
* a little complex
*
*/
BOOL GetChildInldex_KMP(string mother, string child, int pos, int* index)
{
	int i = pos;
	int j = 0;
	int match_len = 0;
	int table[255];

	GetTable(child, table);
	while (child[j] && mother[i])
	{
		if (mother[i] == child[j])
		{
			i++;
			j++;
		}
		else
		{
			match_len = j - 1;
			if (match_len >= 1)
			{
				i = i - j + match_len - table[match_len - 1];
				j = 0;
			}
			else
			{
				j = 0;
				i++;
			}

		}
	}

	if (!child[j])
	{
		*index = i - j;
		return TRUE;
	}
	else
		return FALSE;
}

/*
**************************************************************************
*   KMP UPGRADE algorithm
**************************************************************************
*/
void GetTableVal(string s, int *tableval)
{
	int i, j;
	i = 1;
	j = 0;
	tableval[1] = 0;

	while (s[i])
	{
		if (j == 0 || s[i] == s[j])
		{
			i++; j++;
			if (s[i] != s[j])
				tableval[i] = j;
			else
				tableval[i] = tableval[j];
		}
		else
			j = tableval[j];
	}
}

BOOL GetChildInldex_KMP_UPGRADE(string mother, string child, int pos, int* index)
{
	int i = pos;
	int j = 0;
	int match_len = 0;
	int table[255];

	GetTableVal(child, table);
	while (child[j] && mother[i])
	{
		if (mother[i] == child[j])
		{
			i++;
			j++;
		}
		else
		{
			match_len = j - 1;
			if (match_len >= 1)
			{
				i = i - j + match_len - table[match_len - 1];
				j = 0;
			}
			else
			{
				j = 0;
				i++;
			}

		}
	}

	if (!child[j])
	{
		*index = i - j;
		return TRUE;
	}
	else
		return FALSE;
}


