#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;//������
	struct node *pnext;//ָ����
}NODE,* PNODE;//NODE�ȼ���struct node ����, PNODE�ȼ���struct node *����

PNODE create_list(void)
{
	int val;
	int len ;//����ڵ�ĸ���
	PNODE phead = (PNODE)malloc(sizeof(NODE));//����ͷ��㣬�ý�㲻�洢�κ���Ч����
	if (NULL == phead)
	{
		cout<<"ͷ����ڴ����ʧ�ܣ�������ֹ��";
		exit(-1);
	}
	PNODE ptail = phead;//����һ��ʼ��ָ������ĩβ�Ľ��ָ��ptail
	ptail->pnext = NULL;//���⵱len Ϊ0ʱ��û����Ч������ʱ��ָ�������ա�
	cout<<"����������Ҫ�����ķ�ѭ��������Ľ�������";
	cin>>len;
	for (int i = 0; i < len ; i++)
	{
		cout<<"�������"<<i+1<<"���������ֵ(����)��";
		cin>>val;
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == phead)
		{
			cout<<"����ڴ����ʧ�ܣ�������ֹ��";
			exit(-1);
		}
		else
		{
			pnew->data = val;
			pnew->pnext = NULL;
			ptail->pnext = pnew;
			ptail = pnew;
		}
	}
	return phead;
}
void traverse_list(PNODE phead)
{
	if (phead == NULL)
		return;
	PNODE pindex = phead->pnext;
	while(pindex != NULL)
	{
		cout<<pindex->data<<"\t";
		pindex = pindex->pnext;
	}
	cout<<"\n���������ɣ�\n";
	return ;
}
int main()
{
	PNODE phead = NULL;
	phead = create_list();//����һ��ѭ��������
	traverse_list(phead);
	system("pause");
	return 0;
}