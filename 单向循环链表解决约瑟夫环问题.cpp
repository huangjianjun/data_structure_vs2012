#include<iostream>
using namespace std;
#include<stdlib.h>
//����������
//��֪N���ˣ��������Ϊ1��2��~~~,N��Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ�������䵽m���Ǹ��˳��У�
//������һ�����д�k��ʼ����������m ���Ǹ����ڳ��У��Դ����ƣ�ֱ��Բ���ϵ���ȫ�����С�
//��������͵Ĳ���ѭ��������ģ���������̡�

typedef struct node
{
	int data;
	struct node *pnext;
}NODE,*PNODE;
//���ȴ���һ��ѭ������
PNODE creat()
{
	int n;
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	phead->pnext = NULL;
	PNODE p = phead;
	phead->data = 1;
	cout<<"���봴����ѭ������ĳ��ȣ�����������";
	cin>>n;
	for(int i = 2; i <= n; i++)
	{
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		pnew->data = i;
		p->pnext = pnew;
		pnew->pnext = NULL;
		p = p->pnext;
	}
	p->pnext = phead;
	return phead;
}

void resule_process(PNODE phead,int k, int m)
{
	PNODE temp = NULL;//����ָ�룬ָ��k��ǰһ�����
	PNODE p = phead;
	while(k != p->data)
	{
		p = p->pnext;
	}
	while(p->pnext != p)//�ж������Ƿ�ֻʣһ���ڵ�����
	{
		for(int i = 0; i < m-1; i++)
		{
			temp = p;
			p = p->pnext;
		}
		cout<<"���е�ֵΪ��"<<p->data<<endl;
		temp->pnext = p->pnext;
		free(p);
		p = temp->pnext;
	}
		
	cout<<"���е�ֵΪ��"<<p->data<<endl;
	free(p);
}


int main()
{
	PNODE phead = creat();
	resule_process(phead,1,2);
	system("pause");
	return 0;
}

