#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct BSTnode
{
	int key;
	struct BSTnode* lchild, * rchild;
}BSTnode,*BSTree;

BSTnode* BST_Search(BSTree T, int key)
{
	while (T != NULL && key != T->key)
	{
		if (key < T->key)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}

BSTnode* BST_Search2(BSTree T, int key)
{
	if (T == NULL)
		return NULL;
	if (key == T->key)
		return T;
	else if (key < T->key)
		return BST_Search2(T->lchild, key);
	else
		return BST_Search2(T->rchild, key);
}

int BST_Insert(BSTree* T, int key)
{
	if (T == NULL)
	{
		(*T) = (BSTree)malloc(sizeof(BSTnode));
		(*T)->key = key;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		return 1;
	}
	else if (key == (*T)->key)
		return 0;
	else if (key < ((*T)->key))
		return BST_Insert((*T)->lchild, key);
	else
		return BST_Insert((*T)->rchild, key);
}

void Creat_BST(BSTree* T, int str[], int n)
{
	(*T) = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);
		i++;
	}
}

typedef struct AVLNode
{
	int key;
	int balance;
	struct AVLNode* lchild, * rchild;
}AVLNode,*AVLTree;

//f->lchild = p->rchild;
//p->rchild = f;
//gf->lchild / right = p;

//f->rchild = p->lchild;
//p->lchild = f;
//gf->rchild / lchild = p;