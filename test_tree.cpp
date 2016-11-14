#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct node
{
	int val;
	struct node *pleft;
	struct node *pright;
}NODE, *PNODE;

void create_btree(PNODE proot)
{
	int m;
	cout<<"please input int:";
	cin>>m;
	if(m == -1)
		proot = NULL;
	else
	{
		PNODE proot = (PNODE)malloc(sizeof(NODE));
		proot->val = m;
		create_btree(proot->pleft);
		create_btree(proot->pright);
	}
}

void preorder(PNODE p)
{
	if(p == NULL)
		return ;
	else
	{
		cout<<p->val<<"\t";
		preorder(p->pleft);
		preorder(p->pright);
	}
}
int main()
{
	PNODE pt = (PNODE)malloc(sizeof(NODE));
	create_btree(pt);
	preorder(pt);
	system("pause");
	return 0;
}
