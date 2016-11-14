#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

//������
typedef struct binnode 
{
	char data;
	struct binnode *plchild;
	struct binnode *prchild;
}BNODE, * PBNODE;

PBNODE create_bnode()
{
	//��̬����һ��������
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
//�ݹ�ĵ��÷���
void pretraverse(PBNODE pt)
{
	/* �������α�㷨
	�ȷ��ʸ�����ֵ
	���������������
	���������������
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
/*  �������α�㷨
	���������������
	���ʸ����
	���������������
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
/*  �������α�㷨
	�Ⱥ������������	
	�ٺ������������
	���ʸ����
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
	cout<<"���������";
	pretraverse(pt);
	cout<<endl;
	cout<<"���������";
	intraverse(pt);
	cout<<endl;
	cout<<"���������";
	posttraverse(pt);
	cout<<endl;
	system("pause");
	return 0;
}
