#include <iostream>
using namespace std;
#include<string>

typedef struct node
{
	int val;
	struct node *pnext;
}NODE, *PNODE;

//反转链表：如1 2 3 4 5 6，反转后变为6 5 4 3 2 1
//定义3个指针，分别指向当前访问的结点pnow,访问结点的前一个结点ppre,访问结点的下一个指针pNext.

PNODE reverse_list(PNODE phead)//头结点不存储有效值
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
	preverse_head->pnext = preverse;//为了使反转后的链表满足遍历函数的要求
	preverse_head->val = -1;
	return preverse_head;
}

void treverse(PNODE phead)
{
	PNODE p = phead->pnext;
	if(p == NULL)
	{
		cout<<"链表为空！"<<endl;
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
		cout<<"请输入创建的链表的长度值n:";
		cin>>n;
		PNODE phead = create_list(n);
		cout<<"创建的链表为：";
		treverse(phead);
		PNODE preverse = reverse_list(phead);
		cout<<"反转之后的链表为：";
		treverse(preverse);
		free(phead);
		free(preverse);
		cout<<"继续（y/n）:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;

}