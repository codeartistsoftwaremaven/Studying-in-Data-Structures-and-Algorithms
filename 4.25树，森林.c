#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_TREE_SIZE 100

//˫�ױ�ʾ��
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

//���ӱ�ʾ��
struct CTNode
{
	int child; //���ӽ���������е�λ��
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
	int n, r;//�������n������λ��r
}CTree;

//�����ֵܱ�ʾ��
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
//		while (R����һ������T)
//			PreOrder(T);
//	}
//}

//void PostOrder(TreeNode* R)
//{
//	if (R != NULL)
//	{
//		while (R����һ������T)
//			PostOrder(T);
//		 visit(R);
// 
//	}
//}