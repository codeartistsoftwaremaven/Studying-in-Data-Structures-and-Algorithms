#define _CRT_SECURE_NO_WARNINi
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct
{
	int* elem;
	int TableLen;
}SSTable;

int Search_Seq(SSTable ST, int key)
{
	int i = 0;
	for (i = 0; i < ST.TableLen && ST.elem[i] != key; ++i)
		;
	return i == ST.TableLen ? -1 : i;
}

int Search_Seq_scout(SSTable ST, int key)
{
	ST.elem[0] = key;
	int i = 0;
	for (i = ST.TableLen; ST.elem[i] != key; --i)
		;
	return i;
}

int Binary_Search(SSTable L, int key)
{
	int low = 0;
	int high = L.TableLen - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L.elem[mid] == key)
			return mid;
		else
		{
			if (L.elem[mid] > key)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;
}

typedef struct
{
	int maxValue;
	int low, high;
}Index;

int List[100];