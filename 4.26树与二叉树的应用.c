#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_TREE_SIZE 100
typedef struct
{
	int data;
	int parent;
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int n;
}PTree;

//���鼯
#define SIZE 13
int UFSets[SIZE];

void Initial(int S[])
{
	for (int i = 0; i < SIZE; i++)
	{
		S[i] = -1;
	}
}

int Find(int S[], int x)
{
	while (S[x] > 0)
		x = S[x];
	return x;
}

void Union(int S[], int Root1, int Root2)
{
	if (Root1 == Root2)
		return;
	if (S[Root2] > S[Root1])
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
	else
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}

int SuperFind(int S[], int x)
{
	int root = x;
	while (S[root] >= 0)
		root = S[x];
	while (x != root)
	{
		int t = S[x];
		S[x] = root;
		x = t;
	}
	return root;
}