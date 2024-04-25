#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*Bitree;

void visit(Bitree T)
{
	// 对节点进行访问操作
	printf("%d ", T->data); // 例如，打印节点的数据值
}

void PreOrder(Bitree T)
{
	if (T != NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(Bitree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(Bitree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

int treeDepth(Bitree T)
{
	if (T == NULL)
		return 0;
	else
	{
		int l = treeDepth(T->lchild);
		int r = treeDepth(T->rchild);
		return l > r ? l + 1 : r + 1;
	}
}

//层次遍历

typedef struct LinkNode
{
	BiTNode* data;
	struct LinkNode* next;
}LinkNode;

typedef struct
{
	LinkNode* front, * rear;
}LinkQueue;

void LevelOrder(Bitree T)
{
	LinkQueue Q;
	InitQueue(Q);
	Bitree p;
	EnQueue(Q, T);
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}
