#define CRT_SECURE_NO_WARNI
#include<stdio.h>
#include<stdbool.h>

#define MaxVertexNum 100

typedef struct
{
	char Ver[MaxVertexNum];
	int  Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}MGraph;

//邻接矩阵法存储带权图

#define INFINITY
typedef char VerterType;
typedef int  Edgetype;
typedef struct
{
	VerterType Vex[MaxVertexNum];
	Edgetype Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
};

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* next;//指向下一条弧的指针
	//InfoType info;
}ArcNode;

typedef struct VNode
{
	VerterType data;
	ArcNode* first;
}VNode,AdjList[MaxVertexNum];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;