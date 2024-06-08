#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectSort(int A[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[min])
				min = j;
		}
		if (min != i)
			Swap(&A[i], &A[min]);
	}
}

void BuildMaxHeap(int A[], int len)
{
	for (int i = len / 2; i > 0; i--)
		HeapAdjust(A, i, len);
}

void HeapAdjust(int A[], int k, int len)
{
	A[0] = A[k];
	for (int i = k * 2; i < len; i *= 2)
	{
		if (i < len && A[i] < A[i + 1])
			i++;
		if (A[0] >= A[i])
			break;
		else
			A[k] = A[i];
		k = i;
	}
	A[k] = A[0];
}

void HeapSort(int A[], int len)
{
	BuildMaxHeap(A, len);
	for (int i = len; i > 1; i--)
	{
		Swap(&A[i], &A[1]);
		HeapAdjust(A, 1, i - 1);
	}
}