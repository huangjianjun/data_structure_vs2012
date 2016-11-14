//定义栈以及模仿栈的各种操作
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
//动态栈以链表为内核存储结构
typedef struct node
{
	char data;
	struct node *pnext;
}NODE,* PNODE;

typedef struct stack
{
	PNODE ptop;
	PNODE pbottom;
}STACK, * PSTACK;

void init(PSTACK pst)
{
	pst->ptop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pst->ptop)
	{
		cout<<"新节点内存分配失败！";
		system("pause");
	}
	pst->pbottom = pst->ptop;
	pst->ptop->pnext = NULL;
}

bool is_empty_stack(PSTACK pst)
{
	if (pst->ptop == pst->pbottom)
		return true;
	else
		return false;
}

void push(PSTACK pst, char val)
{
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pnew)
	{
		cout<<"新节点内存分配失败！";
		system("pause");
	}

	pnew->data = val;
	pnew->pnext = pst->ptop;
	pst->ptop = pnew;
}
//每次将栈顶元素出栈，出栈元素的值赋给变量value
bool pop(PSTACK pst, char value)
{
	if (is_empty_stack(pst))
	{
		cout<<"栈为空，出栈操作失败！\n";
		return false;
	}
	else
	{
		PNODE r = pst->ptop;
		value = r->data;
		pst->ptop = r->pnext;
		free(r);
		cout<<"出栈成功，出栈的元素："<<value<<endl;
		return true;
	}
}


typedef struct bnode
{
	char data;
	struct bnode *plchild;
	struct bnode *prchild;
}BNODE , * PBNODE;
//定义一个节点指针root，另它代表二叉树的根节点。
typedef struct btree
{
	struct bnode * root;//root结点指针代表根节点的地址，
}BTree;


PBNODE newnode()
{
	PBNODE pnew = (PBNODE)malloc(sizeof(BNODE));
	if (NULL == pnew)
	{
		cout<<"新结点创建，动态内存分配失败！";
		system("pause");
		exit(-1);
	}
	return pnew;
}

void create_void_tree(BTree *p)//创建一个空的二叉树
{
	p->root = NULL;
}

void create_tree(BTree * bt ,char x, BTree * lt, BTree * rt)//创建一个二叉树
{
	PBNODE p = newnode();
	p->data = x;
	p->plchild = lt->root;//传参时lt代表左子树的根节点的地址,lt->root代表根节点的地址。
	p->prchild = rt->root;//传参时rt代表左子树的根节点的地址,rt->root代表根节点的地址。
	lt->root = rt->root = NULL;
	bt->root = p;
}

//下面定义先序遍历的非递归算法
/**/
void intraverse_feidigui(BTree *bt)
{
	char s = ' ';
	PSTACK pst = (PSTACK)malloc(sizeof(STACK));
	init(pst);
	PBNODE p = bt->root;
	while(p || pst->ptop != pst->pbottom)
	{
		if(p)
		{
			push(pst, p->data);
			p = p->plchild;
		}
		else
		{
			pop(pst, s);
			//cout<<"huang :"<<s<<"\t";
			p = p->prchild;
		}
	}
	return;

}
int main()
{
	BTree A,B,C,D,E,F,L,N,M;
	create_void_tree(&A);
	create_void_tree(&B);
	create_void_tree(&C);
	create_void_tree(&D);
	create_void_tree(&E);
	create_void_tree(&F);
	create_void_tree(&L);
	create_void_tree(&M);
	create_void_tree(&N);
	create_tree(&L,'L',&A,&A);
	create_tree(&M,'M',&A,&A);
	create_tree(&F,'F',&L,&M);
	create_tree(&N,'N',&A,&A);
	create_tree(&D,'D',&A,&A);
	create_tree(&E,'E',&N,&A);
	create_tree(&C,'C',&D,&E);
	create_tree(&B,'B',&F,&A);
	create_tree(&A,'A',&B,&C);
	intraverse_feidigui((&A));
	system("pause");
	return 0;
}