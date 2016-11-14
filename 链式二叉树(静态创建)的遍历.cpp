#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

//定义结点
typedef struct binnode 
{
	char data;
	struct binnode *plchild;
	struct binnode *prchild;
}BNODE, * PBNODE;

PBNODE create_bnode()
{
	//静态创建一个二叉树
	PBNODE pA = (PBNODE)malloc(sizeof(BNODE)); pA->data = 'A';
	PBNODE pB = (PBNODE)malloc(sizeof(BNODE)); pB->data = 'B';
	PBNODE pC = (PBNODE)malloc(sizeof(BNODE)); pC->data = 'C';
	PBNODE pD = (PBNODE)malloc(sizeof(BNODE)); pD->data = 'D';
	PBNODE pF = (PBNODE)malloc(sizeof(BNODE)); pF->data = 'F';
	PBNODE pL = (PBNODE)malloc(sizeof(BNODE)); pL->data = 'L';
	PBNODE pM = (PBNODE)malloc(sizeof(BNODE)); pM->data = 'M';
	PBNODE pN = (PBNODE)malloc(sizeof(BNODE)); pN->data = 'N';
	pA->plchild = pB;    pA->prchild = pD;
	pB->plchild = NULL;  pB->prchild = pF;
	pF->plchild = NULL;  pF->prchild = NULL;
	pD->plchild = pC;    pD->prchild = pL;
	pC->plchild = NULL;  pC->prchild = NULL;
	pL->plchild = NULL;  pL->prchild = pM;
	pM->plchild = pN;    pM->prchild = NULL;
	pN->plchild = NULL;  pN->prchild = NULL;
	return pA;
}
//递归的调用访问
void pretraverse(PBNODE pt)
{
	/* 先序遍历伪算法
	先访问根结点的值
	再先序遍历左子树
	再先序遍历右子树
	*/
	if (pt != NULL)
	{
		cout<<pt->data<<"  ";
		pretraverse(pt->plchild);
		pretraverse(pt->prchild);
	}
}

void intraverse(PBNODE pt)
{
/*  中序遍历伪算法
	先中序遍历左子树
	访问根结点
	再中序遍历右子树
*/
	if (pt != NULL)
	{
		intraverse(pt->plchild);
		cout<<pt->data<<"  ";
		intraverse(pt->prchild);
	}
}

void posttraverse(PBNODE pt)
{
/*  后序遍历伪算法
	先后序遍历左子树	
	再后序遍历右子树
	访问根结点
*/
	if(pt != NULL)
	{
		posttraverse(pt->plchild);
		posttraverse(pt->prchild);
		cout<<pt->data<<"  ";
	}
}

int main()
{
	PBNODE pt;
	pt = create_bnode();
	cout<<"先序遍历：";
	pretraverse(pt);
	cout<<endl;
	cout<<"中序遍历：";
	intraverse(pt);
	cout<<endl;
	cout<<"后序遍历：";
	posttraverse(pt);
	cout<<endl;
	system("pause");
	return 0;
}
