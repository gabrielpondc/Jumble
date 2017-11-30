#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "StringUtil.h"
#define NULL 0
int addOne(StringArr * arr, const char * source)
{
	if (arr == NULL || source == NULL)
		return INPUT_ERROR;

	// alloc memory
	if (arr->capacity <= arr->length)
	{
		if (arr->pHead == NULL)
		{
			// alloc space when phead == NULL
			pStringNode pNode = (pStringNode)malloc(sizeof(StringNode));
			if (pNode == NULL)
				return MALLOC_ERROR;

			arr->pHead = pNode;
			arr->capacity += 1;
		}
		else
		{
			// realloc space
			pStringNode pNode = (pStringNode)realloc(arr->pHead, sizeof(StringNode) * 2 * arr->capacity);
			if (pNode == NULL)
				return MALLOC_ERROR;

			arr->pHead = pNode;
			arr->capacity = 2 * arr->capacity;
		}
	}

	int source_len = strlen(source);
	char * tmp = (char *)malloc(sizeof(char)* (source_len + 1));
	if (tmp == NULL)
		return MALLOC_ERROR;

	//pStringNode pNode = arr->pHead + arr->length;             //  c2275 C不允许在中途声明变量
	//StringNode * pNode = &(arr->pHead)[arr->length];
	arr->pHead[arr->length].length = source_len + 1;
	arr->pHead[arr->length].pStr = tmp;

	strcpy(arr->pHead[arr->length].pStr, source);
	arr->length += 1;
	return SUCCESS;
}

int deleteOne(StringArr * arr, const char * target)
{
	pStringNode pres = (pStringNode)NOT_FIND;

	if (arr == NULL || target == NULL)
		return INPUT_ERROR;

	pres = searchStr(arr, target);
	if (pres == (pStringNode)NOT_FIND)
		return (int)NOT_FIND;

	free(pres->pStr);

	for (; pres != arr->pHead + arr->length - 1; pres++)
		*pres = *(pres + 1);
	pres->length = 0;
	pres->pStr = NULL;

	arr->length -= 1;

	return SUCCESS;
}

pStringNode searchStr(StringArr * arr, const char * target)
{
	pStringNode pres = (pStringNode)NOT_FIND;

	if (arr == NULL || target == NULL)
		return (pStringNode)INPUT_ERROR;

	//pStringNode pres = NOT_FIND;
	for (int i = 0; i != arr->length; i++)
	{
		if (strcmp(target, arr->pHead[i].pStr) == 0)
		{
			pres = &arr->pHead[i];
			break;
		}
	}

	return pres;
}


int sortStr(StringArr * arr, int seq)
{
	StringNode tmp;

	if (arr == NULL)
		return INPUT_ERROR;

	if (arr->pHead == NULL || arr->length == 1)
		return SUCCESS;



	seq = (seq > 0) ? MAX2MIN : MIN2MAX;

	if (seq == MIN2MAX)
	{
		// 使用冒泡法排序
		for (int i = 0; i != arr->length - 1; i++)
		{
			for (int j = 0; j != arr->length - 1 - i; j++)
			{
				if (strcmp(arr->pHead[j].pStr, arr->pHead[j + 1].pStr) > 0)
				{
					tmp = arr->pHead[j + 1];
					arr->pHead[j + 1] = arr->pHead[j];
					arr->pHead[j] = tmp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i != arr->length - 1; i++)
		{
			for (int j = 0; j != arr->length - 1 - i; j++)
			{
				if (strcmp(arr->pHead[j].pStr, arr->pHead[j + 1].pStr) < 0)
				{
					tmp = arr->pHead[j + 1];
					arr->pHead[j + 1] = arr->pHead[j];
					arr->pHead[j] = tmp;
				}
			}
		}
	}

	return SUCCESS;
}

pStringArr createStrArr()
{
	pStringArr parr = (pStringArr)malloc(sizeof(StringArr));
	if (parr == NULL)
		return parr;

	parr->capacity = 0;
	parr->length = 0;
	parr->pHead = NULL;
	return parr;
}

void destroyStrArr(pStringArr parr)
{
	if (parr == NULL)
		return;

	while (parr->length != 0)
	{
		if (parr->pHead[parr->length - 1].pStr != NULL)
		{
			free(parr->pHead[parr->length - 1].pStr);
			parr->pHead[parr->length - 1].length = 0;
			parr->length--;
		}
	}
	if (parr->pHead != NULL)
		free(parr->pHead);

	free(parr);
}
