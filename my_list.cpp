#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;//������
	struct node *pnext;//ָ����
}NODE,* PNODE;//NODE�ȼ���struct node ����, PNODE�ȼ���struct node *����
//����������
void traverse_list(PNODE phead);
PNODE create_list(void);
bool is_empty_list(PNODE phead);
int find_list(PNODE phead, int x);
bool delete_list_ziji(PNODE phead, int pos, int *remove);
bool insert_list_ziji(PNODE phead, int pos, int value);//�� pos�ڵ�ǰ����һ���µĽ��
bool insert_list_shipin(PNODE phead, int pos, int value);//�� pos�ڵ�ǰ����һ���µĽ��
int length(PNODE phead);
void sort_list(PNODE phead);

bool is_empty_list(PNODE phead)
{
	if (NULL == phead->pnext)
	{
		cout<<"������Ϊ������"<<endl;
		return true;
	}
	else
		return false;
}
int length(PNODE phead)
{
	int count = 0;
	PNODE p = phead;
	while(p->pnext != NULL)
	{
		count++;
		p = p->pnext;
	}
	return count;
}
bool insert_list_ziji(PNODE phead, int pos, int value)
{
	cout<<"����insert_list_ziji������������������"<<endl;
	if (length(phead) < pos)//�ж������������λ�õĹ�ϵ
	{
		cout<<"�����λ�ô�������ĳ��ȣ��޷����룡"<<endl;
		return false;
	}
	if (pos < 1)//�ж��������λ��pos��ֵ������ڵ���1
	{
		cout<<"pos ��ֵ������ڵ���1��"<<endl;
		return false;
	}
		
	else
	{
		int count = 0;
		PNODE p = phead;
		PNODE p1 = phead;//��¼����λ�õ�ǰһ�����λ��
		PNODE p2 = phead;//��¼����λ�õĺ�һ�����λ��
		if (pos < 1)
		{
			cout<<"pos ��ֵ���Ĳ���ȷ,������ֹ��";
			system("pause");
			exit(-1);

		}
		while(count != pos && pos >=1)
		{
			if (count == pos-1)
			{
				p1 = p;
			}
			p = p->pnext;
			count++;
		}
		p2 = p;
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pnew)
		{
			cout<<"����������ڴ�ʱ����������ֹ��";
			exit(-1);
		}
		pnew->data = value;
		//���Ĳ������
		pnew->pnext =  p2;
		p1->pnext = pnew;
		cout<<"����Ľ�㣺"<<pos<<"\t"<<"�����ֵΪ��"<<value<<endl;
		return true;
	}
	
}
bool insert_list_shipin(PNODE phead, int pos, int value)
{
	cout<<"����insert_list_shipin������������������"<<endl;
	int i = 0 ;
	PNODE p = phead;
	if (i > pos - 1 || NULL == p)
		return false;
	while(NULL != p && i < pos - 1)
	{
		p = p -> pnext;
		i ++;
	}
	//ѭ��������Pָ��pos-1��㣬��������½ڵ�Ĳ���
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pnew)
	{
		cout<<"�½ڵ㶯̬�ڴ����ʧ�ܣ�������ֹ��";
		exit(-1);
	}
	pnew->data = value;
	pnew->pnext = p->pnext;
	p->pnext = pnew;
	cout<<"����Ľ��λ�ã�"<<pos<<"\t"<<"�����ֵΪ��"<<value<<endl;
	return true;

}
bool delete_list_ziji(PNODE phead, int pos, int *remove)
{
	if (length(phead) < pos)//�ж���������ɾ��λ�õĹ�ϵ
	{
		cout<<"ɾ����λ�ô�������ĳ��ȣ��޷�ɾ����";
		return false;
	}
		
	else
	{
		int count = 0;//��ʼֵ��ͬ��Ҫ��������ѭ��������
		PNODE p = phead->pnext;
		PNODE p3 = phead;//��¼pos����λ��
		PNODE p1 = phead;//��¼����λ�õ�ǰһ�����λ��
		PNODE p2 = phead;//��¼����λ�õĺ�һ�����λ��
		//while(count != pos + 1 )
		while(count < pos )
		{
			if (count == pos-2)
			{
				p1 = p;
			}
			if (count == pos-1)
			{
				p3 = p;
			}
			p = p->pnext;
			count++;
		}
		p2 = p;
		PNODE r = p3;
		p1->pnext = p3->pnext;
		remove = (int *)p3;
		cout<<"ɾ���Ľ��Ϊ��"<<pos<<endl;
		cout<<"ɾ������ϴ����ֵΪ��"<<p3->data<<endl;
		free(r);
		return true;
	}
}
void sort_list(PNODE phead)
{
	PNODE p = phead->pnext;
	int len = length(phead);
	int a[100] = {0};
	int temp;
	
	for (int i = 0; i < len; i ++)
	{
		if (NULL != p)
		{
			a[i] = p->data;
		}
		p = p->pnext;
	}
	
	//��������дӴ�С����
	for (int j = 0; j < len; j ++)
	{
		for (int k = j + 1; k < len; k ++)
		{
			if (a[j] <= a[k])
			{
				temp = a[j];
				a[j] = a[k];
				a[k] = temp;
			}
		}
	}
	cout<<"����Ӵ�С������˳��Ϊ(�ܳ���Ϊ��"<<len<<")"<<endl;
	for (int i = 0; i < len; i++ )
		cout<<a[i]<<"\t";
	cout<<"\n";
	return ;

}
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
void traverse_list(PNODE phead)
{
	PNODE pindex = phead->pnext;
	cout<<"���������ʼ......\n";
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
	int *val = NULL;
	phead = create_list();//����һ����ѭ��������
	if (is_empty_list(phead))
	{
		cout<<"�б�Ϊ�գ�";
	}
	traverse_list(phead);

	delete_list_ziji(phead, 3, val);
	traverse_list(phead);
	insert_list_shipin(phead, 2, 800);
	traverse_list(phead);
	insert_list_ziji(phead, 4, 700);
	traverse_list(phead);
	sort_list(phead);
	system("pause");
	return 0;
}