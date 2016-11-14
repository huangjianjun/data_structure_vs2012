//����ջ�Լ�ģ��ջ�ĸ��ֲ���
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
//��̬ջ������Ϊ�ں˴洢�ṹ
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
		cout<<"�½ڵ��ڴ����ʧ�ܣ�";
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
		cout<<"�½ڵ��ڴ����ʧ�ܣ�";
		system("pause");
	}

	pnew->data = val;
	pnew->pnext = pst->ptop;
	pst->ptop = pnew;
}
//ÿ�ν�ջ��Ԫ�س�ջ����ջԪ�ص�ֵ��������value
bool pop(PSTACK pst, char value)
{
	if (is_empty_stack(pst))
	{
		cout<<"ջΪ�գ���ջ����ʧ�ܣ�\n";
		return false;
	}
	else
	{
		PNODE r = pst->ptop;
		value = r->data;
		pst->ptop = r->pnext;
		free(r);
		cout<<"��ջ�ɹ�����ջ��Ԫ�أ�"<<value<<endl;
		return true;
	}
}


typedef struct bnode
{
	char data;
	struct bnode *plchild;
	struct bnode *prchild;
}BNODE , * PBNODE;
//����һ���ڵ�ָ��root����������������ĸ��ڵ㡣
typedef struct btree
{
	struct bnode * root;//root���ָ�������ڵ�ĵ�ַ��
}BTree;


PBNODE newnode()
{
	PBNODE pnew = (PBNODE)malloc(sizeof(BNODE));
	if (NULL == pnew)
	{
		cout<<"�½�㴴������̬�ڴ����ʧ�ܣ�";
		system("pause");
		exit(-1);
	}
	return pnew;
}

void create_void_tree(BTree *p)//����һ���յĶ�����
{
	p->root = NULL;
}

void create_tree(BTree * bt ,char x, BTree * lt, BTree * rt)//����һ��������
{
	PBNODE p = newnode();
	p->data = x;
	p->plchild = lt->root;//����ʱlt�����������ĸ��ڵ�ĵ�ַ,lt->root������ڵ�ĵ�ַ��
	p->prchild = rt->root;//����ʱrt�����������ĸ��ڵ�ĵ�ַ,rt->root������ڵ�ĵ�ַ��
	lt->root = rt->root = NULL;
	bt->root = p;
}

//���涨����������ķǵݹ��㷨
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