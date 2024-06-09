#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main()
{
	return 0;
}

void Merge(int A[], int low, int mid, int high)
{
	int n = 10;
	int* B = (int*)malloc(n * sizeof(int));
	//代码必须放这，伪代码需放外面
	int i = 0, j = 0, k = 0;
	for (k = low; k <= high ; k++)
	{
		B[k] = A[k];
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if (B[i] <= B[j])
			A[k++] = B[i++];
		else
			A[k++] = B[j++];
	}
	while (i <= mid)
		A[k++] = B[k++];
	while (j <= high)
		A[k++] = B[k++];
}

void MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}