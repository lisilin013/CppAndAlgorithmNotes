#include "TYPES.h"
#include <stdio.h>


typedef  int ElementType;

typedef struct node
{
	struct node* next;
	ElementType data;
}node;

typedef struct
{
	node right;
	node left;
}ST_BiTree;

