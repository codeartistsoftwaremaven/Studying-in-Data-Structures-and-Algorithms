#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE_NUM 10
#define TRUE 1
#define FALSE 0
bool visited[MAX_SIZE_NUM];

typedef struct
{
	int data[MAX_SIZE_NUM];
	int front, rear;
	//int size; 方法1  
	//int tag;  方法2
}Queue;
typedef struct {
	int vertices[MAX_SIZE_NUM]; // 顶点数据
	int numVertices; // 图中顶点的数量
} Graph;

Queue Q;


void BFSTraverse(Graph G)
{
	int i = 0;
	for (i = 0; i < G.numVertices; ++i)
	{
		visited[i] = FALSE;
	}
	for (i = 0; i < G.numVertices; ++i)
	{
		if (!visited[i])
			BFS(G, i);
	}
}

void BFS(Graph G, int v)
{
	visit(v);
	visited[v] = TRUE;
	Enqueue(Q, v);
	while (!isEmpty(Q))
	{
		DeQueue(Q, v);
		for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		{
			if (!visited[w])
			{
				visit(w);
				visited[w] = TRUE;
				EnQueue(Q, w);
			}
		}
	}
}

//深度优先

void DFSTraverse(Graph G)
{
	int i = 0;
	for (i = 0; i < G.numVertices; ++i)
	{
		visited[i] = FALSE;
	}
	for (i = 0; i < G.numVertices; ++i)
	{
		if (!visited[i])
			DFS(G, i);
	}
}

void DFS(Graph G, int v)
{
	visit(v);
	visited[v] = TRUE;
	for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
	{
		if (!visited[w])
		{
			DFS(G, w);
		}
	}
}