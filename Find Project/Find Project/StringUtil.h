#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define INPUT_ERROR -1
#define MALLOC_ERROR -2
#define NOT_FIND NULL

#define MAX2MIN 1
#define MIN2MAX 0


typedef struct _StringNode
{
	int length;
	char * pStr;
}StringNode, *pStringNode;

typedef struct _StringArr
{
	StringNode * pHead;
	int length;
	int capacity;
}StringArr, *pStringArr;

int addOne(StringArr * arr, const char * source);

int deleteOne(StringArr * arr, const char * target);

pStringNode searchStr(StringArr * arr, const char * target);

int sortStr(StringArr * arr, int seq);

pStringArr createStrArr();

void destroyStrArr(pStringArr parr);