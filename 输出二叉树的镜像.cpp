#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

//二叉树的镜像就是镜子效果，除根节点外所有结点左右交换位置。剑指offer 第126页

typedef struct bintree
{
	int val;
	bintree *pleft;
	bintree *pright;
}BTREE, *PTREE;

void mirror_bintree(PTREE pnode)
{
	if(pnode == NULL)
		return ;
	if(pnode->pleft == NULL && pnode->pright == NULL)
		return ;
	PTREE ptemp = pnode->pleft;
	pnode->pleft = pnode->pright;
	pnode->pright = ptemp;
	if(pnode->pleft != NULL)
		mirror_bintree(pnode->pleft);
	if(pnode->pright != NULL)
		mirror_bintree(pnode->pright);
}

PTREE create_breenode_left(PTREE pnode, int value)
{
	PTREE pnewnode = (PTREE)malloc(sizeof(BTREE));
	pnewnode->val = value;
	pnewnode->pleft = NULL;
	pnewnode->pright = NULL;
	pnode->pleft = pnewnode;
	return pnewnode;
}

PTREE create_breenode_right(PTREE pnode, int value)
{
	PTREE pnewnode = (PTREE)malloc(sizeof(BTREE));
	pnewnode->val = value;
	pnewnode->pleft = NULL;
	pnewnode->pright = NULL;
	pnode->pright = pnewnode;
	return pnewnode;
}
PTREE creat_bintree()
{
	PTREE proot = (PTREE)malloc(sizeof(BTREE));
	proot->pleft = NULL;
	proot->pright = NULL;
	proot->val = 8;
	PTREE p1 = create_breenode_left(proot, 6);
	PTREE p2 = create_breenode_right(proot, 10);
	PTREE p3 = create_breenode_left(p1, 5);
	PTREE p4 = create_breenode_right(p1, 7);
	PTREE p5 = create_breenode_left(p2, 9);
	PTREE p6 = create_breenode_right(p2, 11);
//	PTREE p7 = create_breenode_right(p3, 4);
	return proot;
}

void pretraverse(PTREE pt)
{
	if (pt != NULL)
	{
		cout<<pt->val<<"  ";
		pretraverse(pt->pleft);
		pretraverse(pt->pright);
	}
}

int main()
{
	PTREE root = creat_bintree();
	cout<<"树的先序遍历为：";
	pretraverse(root);
	cout<<endl;
	mirror_bintree(root);
	cout<<"镜像二叉树的先序遍历为：";
	pretraverse(root);
	cout<<endl;
	system("pause");
	return 0;
}
