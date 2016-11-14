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
	cout<<"����������Ҫ����������Ľ�������";
	cin>>len;
	for (int i = 0; i < len ; i++)
	{
		cout<<"�������"<<i+1<<"���������ֵ(����)��";
		cin>>val;
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pnew)
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

PNODE creat_newnode_copy(PNODE p, PNODE pnode)
{
	PNODE ptail = p;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->pnext = NULL;
	pnew->data = pnode->data;
	ptail->pnext = pnew;
	ptail = pnew;
	return ptail;
}

PNODE merge(PNODE phead1, PNODE phead2,PNODE pmerge_head)//�ϲ��������������
{
	PNODE p1 = phead1->pnext;
	PNODE p2 = phead2->pnext;
	PNODE ptail = pmerge_head;
	ptail->pnext = NULL;
	if(p1 == NULL && p2 == NULL) return NULL;//ֻ�Ƿ��ز�����ڵ�ֵ��ͷָ�롣
	if(p1 == NULL) return phead2;
	if(p2 == NULL) return phead1;
	while(p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			ptail = creat_newnode_copy(ptail, p1);
			p1 = p1->pnext;	
		}
		else
		{
			ptail = creat_newnode_copy(ptail, p2);
			p2 = p2->pnext;
		}	
	}
	if (p1 == NULL)  //����whileѭ���˳�������ʣ������
	{
		while(p2 != NULL)
		{
			ptail = creat_newnode_copy(ptail, p2);
			p2 = p2->pnext;
		}
	}
	if (p2 == NULL)
	{
		while(p1 != NULL)
		{
			ptail = creat_newnode_copy(ptail, p1);
			p1 = p1->pnext;
		}
	}
	if(p1 == NULL && p2 == NULL)
		return pmerge_head;
	return pmerge_head;
}
void traverse_list(PNODE phead)
{
	if(phead == NULL)
	{
		cout<<"����Ϊ�գ�"<<endl;
		return ;
	}
	if(phead->pnext == NULL)
	{
		cout<<"����Ϊ�գ�"<<endl;
		return ;
	}
	PNODE pindex = phead->pnext;
	while(pindex != NULL)
	{
		cout<<pindex->data<<"  ";
		pindex = pindex->pnext;
	}
	cout<<endl;
}
int main()
{
	char ch;
	do{
		PNODE pmerge_head = (PNODE)malloc(sizeof(NODE));
		pmerge_head->pnext = NULL;
		pmerge_head->data = -1;
		PNODE phead1 = create_list();
		cout<<"�����ĵ�һ����������";
		traverse_list(phead1);
		PNODE phead2 = create_list();
		cout<<"�����ĵڶ�����������";
		traverse_list(phead2);
		PNODE phead = merge(phead1, phead2, pmerge_head);
		cout<<"�ϲ�֮�����������";
		traverse_list(phead);
		free(phead);
		cout<<"��������y/n��:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}
//�ܽ᣺������������ϲ������÷ֱ�ȡ��������Ľڵ�ֵ���бȽϣ������н��ڵ�ֵС�����ӵ��½��������У��Դ����ƣ�
//��ĳһ��������������һ����������ʣ�࣬��ʣ��Ľ��ֱֵ�ӿ������ϲ������β������Ϊ��ǰ�������Ǹ���������н��ֵ���Ѿ���û�н������Ǹ�������Ѿ��������Ľ��ֵ�����˱Ƚϣ���Ϊ��Ϊ������������ʣ��ڵ�ֵ����ֱ�ӿ������ϲ������β����
//��ĳһ������Ϊ�գ���ֱ�ӷ�����һ������