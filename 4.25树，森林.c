#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_TREE_SIZE 100

//双亲表示法
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

//孩子表示法
struct CTNode
{
	int child; //孩子结点在数组中的位置
	struct CTNode* next;
};

typedef struct
{
	int data;
	struct STNode* firstChild;
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//结点总数n，根的位置r
}CTree;

//孩子兄弟表示法
typedef struct CSNode
{
	int data;
	struct CSNode* firstChild, * nextsibling;
}CSNode, * CSTree;

#define MaxSize 100

typedef struct TreeNode
{
	int value;
	bool isEmpty;
}TreeNode;

struct ElemType
{
	int value;
};

typedef struct BiTNode
{
	struct ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * Bitree;

//void PreOrder(TreeNode* R)
//{
//	if (R != NULL)
//	{
//		visit(R);
//		while (R的下一个子树T)
//			PreOrder(T);
//	}
//}

//void PostOrder(TreeNode* R)
//{
//	if (R != NULL)
//	{
//		while (R的下一个子树T)
//			PostOrder(T);
//		 visit(R);
// 
//	}
//}