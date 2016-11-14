#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//����һ��˫������Ľ��
typedef struct Snode
{
	int data;
	struct Snode * previous;
	struct Snode * next;
	int position;
}SNODE,*PSNODE;

PSNODE create_slist_ziji(void)
{
	int len;
	int value;
	int count = 0;
	//���Ƚ���һ��ͷ���
	PSNODE phead = (PSNODE)malloc(sizeof(SNODE));
	if (NULL == phead)
	{
		cout<<"ͷ��㶯̬�ڴ����ʧ�ܣ�������ֹ��";
		exit(-1);
	}
	phead->previous = NULL;
	PSNODE p = phead;
	
	//�����µĽ��ҵ�ͷ�����
	cout<<"�������봴�����ĸ�����";
	cin>>len;
	cout<<"------------------------------\n";
	for (int i = 0;i < len;i ++)
	{
		cout<<"��"<<i+1<<"������ֵ(����ֵ)��";
		cin>>value;
		PSNODE pnew = (PSNODE)malloc(sizeof(SNODE));
		if (NULL == pnew)
		{
			cout<<"�½�㶯̬�ڴ����ʧ�ܣ�������ֹ��";
			exit(-1);
		}
		pnew->next = NULL;//˫�������Ϊ�ڵ��ָ��û��ָ��
		pnew->data = value;
		pnew->position = i + 1;
		p->next = pnew;
		pnew->previous = p;
		p = p->next;
		count++;
	}
	cout<<"��������ĳ���Ϊ��"<<count<<endl<<endl;
	return phead;

}
void traverse_list(PSNODE phead)
{
	PSNODE pindex = phead->next;
	cout<<"���������ʼ......\n";
	while(pindex != NULL)
	{
		cout<<pindex->data<<"\t";
		pindex = pindex->next;
	}
	cout<<"\n���������ɣ�\n";
	return ;
}
int is_length(PSNODE phead)
{
	int len = 0;
	PSNODE p = phead->next;
	while (NULL != p)
	{
		len++;
		p = p ->next;
	}
	return len;
}
//��pos����ϲ���һ���ڵ㣬����������ƶ�
bool insert_list_ziji(PSNODE phead, int pos, int val)
{
	if (pos <= 0 || pos > is_length(phead))
	{
		cout<<"����Ĳ�����λ�ò���Ҫ��,����ʧ�ܣ�\n";
		system("pause");
		return false;
	}
	PSNODE p = phead;
	int i = 0;
	while(NULL != p && i < pos - 1)// ѭ��������Pָ��pos-1���
	{
		p = p->next;
		i ++;
	}
	PSNODE pnew = (PSNODE)malloc(sizeof(SNODE));
	if (NULL == pnew)
	{
		cout<<"�½�㶯̬�ڴ����ʧ�ܣ�������ֹ��";
		return false;
		exit(-1);
		system("pause");
	}
	pnew->data = val;
	pnew->next = p->next;
	p->next->previous = pnew;
	pnew->previous = p;
	p->next = pnew;
	cout<<"�������λ�ã�"<<pos<<"\t"<<"����ֵ��"<<pnew->data<<endl;
	return true;
}


int main()
{
	PSNODE phead;
	phead = create_slist_ziji();
	traverse_list(phead);
//	insert_list_ziji(phead,2,800);
//	traverse_list(phead);
	system("pause");
	return 0;
}
