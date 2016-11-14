#include <iostream>
using namespace std;
#include<string>

typedef struct node
{
	int val;
	struct node *pnext;
}NODE, *PNODE;

//��ת������1 2 3 4 5 6����ת���Ϊ6 5 4 3 2 1
//����3��ָ�룬�ֱ�ָ��ǰ���ʵĽ��pnow,���ʽ���ǰһ�����ppre,���ʽ�����һ��ָ��pNext.

PNODE reverse_list(PNODE phead)//ͷ��㲻�洢��Чֵ
{
	PNODE pnow = phead->pnext;
	PNODE ppre = NULL;
	PNODE preverse = NULL;
	while(pnow != NULL)
	{
		PNODE pNext = pnow->pnext;
		if(pNext == NULL)
			preverse = pnow;
		pnow->pnext = ppre;
		ppre = pnow;
		pnow = pNext; 
	}
	PNODE preverse_head = (PNODE)malloc(sizeof(NODE));
	preverse_head->pnext = preverse;//Ϊ��ʹ��ת��������������������Ҫ��
	preverse_head->val = -1;
	return preverse_head;
}

void treverse(PNODE phead)
{
	PNODE p = phead->pnext;
	if(p == NULL)
	{
		cout<<"����Ϊ�գ�"<<endl;
		return;
	}
	while(NULL != p)
	{
		cout<<p->val<<"  ";
		p = p->pnext;
	}
	cout<<endl;
}

PNODE create_list(int n)
{
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	phead->pnext = NULL;
	phead->val = -1;
	PNODE ptail = phead;
	ptail->pnext = NULL;
	for(int i = 0; i < n; i++)
	{
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		pnew->val = i + 1;
		pnew->pnext = NULL;
		ptail->pnext = pnew;
		ptail = pnew;
	}
	return phead;
}
int main()
{
	int n;
	char ch;
	do{
		cout<<"�����봴��������ĳ���ֵn:";
		cin>>n;
		PNODE phead = create_list(n);
		cout<<"����������Ϊ��";
		treverse(phead);
		PNODE preverse = reverse_list(phead);
		cout<<"��ת֮�������Ϊ��";
		treverse(preverse);
		free(phead);
		free(preverse);
		cout<<"������y/n��:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;

}