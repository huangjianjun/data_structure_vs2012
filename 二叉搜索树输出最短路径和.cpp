#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

typedef struct node {
	int val;
	struct node *pleft;
	struct node *pright;
}TREE, *PTREE;

PTREE create_tree_node(int value)
{
	PTREE pnew = (PTREE)malloc(sizeof(TREE));
	pnew->val = value;
	pnew->pleft = NULL;
	pnew->pright = NULL;
	return pnew;
}

void create_subtree(PTREE p, PTREE pleft, PTREE pright)
{
	if(NULL == p)
		return ;
	else
	{
		p->pleft = pleft;
		p->pright = pright;
	}
}

PTREE create_tree()
{
	PTREE proot = create_tree_node(12);
	PTREE p2 = create_tree_node(8);
	PTREE p3 = create_tree_node(13);
	PTREE p4 = create_tree_node(6);
	PTREE p5 = create_tree_node(9);
	PTREE p6 = create_tree_node(4);
	PTREE p7 = create_tree_node(7);
	PTREE p8 = create_tree_node(2);
	PTREE p9 = create_tree_node(3);
	PTREE p10 = create_tree_node(5);
	create_subtree(p6, p9, p10);
	create_subtree(p4, p6, p7);
	create_subtree(p5, p8, NULL);
	create_subtree(p2, p4, p5);
	create_subtree(proot, p2, p3);
	return proot;
}

void intraverse(PTREE pt)
{
	if (pt != NULL)
	{
		intraverse(pt->pleft);
		cout<<pt->val<<"  ";
		intraverse(pt->pright);
	}
	else
		return;
}


void digui(PTREE p, int sum, vector<int> &vec)
{
	if(p != NULL) 
		sum += p->val;
	else return;
	if(p->pleft == NULL && p->pright == NULL)
		vec.push_back(sum);
	else
	{
		digui(p->pleft, sum, vec);
		digui(p->pright, sum, vec);
	}
}

int main()
{
	PTREE proot = create_tree();
	vector<int> vec;
	int sum  = 0;
	intraverse(proot);
	cout<<endl;
	digui(proot, sum, vec);
	for(int i = 0; i < vec.size(); i++)
		cout<<vec[i]<<"\t";
	cout<<endl;
	system("pause");
	return 0;
}