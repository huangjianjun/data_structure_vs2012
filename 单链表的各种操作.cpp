#include<iostream>
using namespace std;
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}NODE,*PNODE;

PNODE creat()
{
	int num,val;
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	if (NULL == phead)
	{
		cout<<"动态创建空间失败！"<<endl;
		exit(-1);
		system("pause");
	}
	phead->data = -100;
	printf("请输入创建链表的长度：");
	cin>>num;
	PNODE p = phead;
	for(int i = 0; i<num; i++)
	{
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		p->next = pnew;
		cout<<"请输入链表结点的值：";
		cin>>val;
		pnew->data = val;
		pnew->next = NULL;
		p = pnew;
	}
	return phead;
}

void print(PNODE phead)
{
	PNODE p = phead->next;
	while(NULL != p)
	{
		cout<<p->data<<"	";
		p = p->next;
	}
	cout<<endl;
}
int leng(PNODE phead)
{
	int n = 0;
	PNODE p = phead->next;
	while(NULL != p)
	{
		n++;
		p = p->next;
	}
	cout<<"链表的长度为："<<n<<endl;
	return n;
}
void insert(PNODE phead)//插入pos的位置前，插入的值val
{
	int pos,val;
	int n = 1;
	PNODE p1 = phead; 
	PNODE p = phead->next;
	cout<<"请您输入插入的结点位置：";
	cin>>pos;
	while(NULL != p)
	{
		if(n == pos -1)
		{
			p1 = p;
		}
		n++;
		p = p->next;
	}
	cout<<"请您输入插入的结点的值：";
	cin>>val;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->data = val;
	pnew->next = p1->next;
	p1->next = pnew;
}
void add_tail(PNODE phead)
{
	int val;
	PNODE p = phead->next;
	while(NULL != p->next)
	{
		p = p->next;
	}
	cout<<"请您输入插入尾部结点的值：";
	cin>>val;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->data = val;
	p->next = pnew;
	pnew->next = NULL;
}
PNODE del(PNODE phead)
{
	int val;
	cout<<"请您输入要删除的节点值：";
	cin>>val;
	PNODE p = phead->next;
	PNODE p1= NULL;
	PNODE p2 = NULL;
	while(val != p->data && p->next != NULL)
	{
		p2 = p;
		p = p->next;
	}
	p = phead->next;
	while(NULL != p)
	{
		if (val == p->data)
		{
			p1 = p;
		}
		p = p->next;
	}
	if (p1 == phead->next)
	{
		phead->next = p1->next;
		free(p1);
	}
	else
	{
		p2->next = p1->next;
		free(p1);
	}
	return phead;
}
PNODE list_sort(PNODE phead)
{
	int temp;
	PNODE p = phead->next;
	int n = leng(phead);
	for(int i = 1;i < n; i++)
	{
		p = phead->next;
		for (int j = 0; j < n - i; j++)
		{
			if (p->data > p->next->data)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
	cout<<"排序后的列表：";
	print(phead);
	return phead;
}
PNODE reverse(PNODE phead)
{
	PNODE ppre = phead;
	PNODE pcur = ppre->next;
	PNODE pnext = NULL;
	if (phead->next == NULL && phead->next->next == NULL) return phead;
	while(NULL != pcur)
	{
		pnext = pcur->next;
		pcur->next = ppre;
		ppre = pcur;
		pcur = pnext;
	}
	phead->next->next = NULL;//phead 的值在循环中没有变，相当于原来第一个结点的下一个结点置空。
	PNODE pnew = (PNODE)malloc(sizeof(NODE));//添加逆置过后的链表的头结点
	pnew->data = -200;
	pnew->next = ppre;
	phead = pnew;
	return phead;
}
//不知道单链表的结点数N，遍历一次单链表，找出中间节点值。
//设立两个辅助指针p,q,使q每次移动两个位置，p每次移动一个位置，这样当q到尾部时，p刚好走到中间位置，当然链表结点数分为奇偶两种情况来考虑。
void find_mid_val(PNODE phead)
{
	int flag = 0; //标志位来区分结点数为奇偶数的情况。
	PNODE temp = NULL ; //偶数时用来标记p的前一个结点。
	PNODE p = phead->next;
	PNODE q = phead->next;
	if(NULL == phead || NULL == phead->next)
	{
		cout<<"有情况！！！"<<endl;
		system("pause");
		return ;
	}
	while(NULL != q)
	{
		q = q->next;
		if(NULL != q)
		{
			q = q->next;
			temp = p;
			p = p->next;
			if(NULL == q ) //节点为偶数的情况判断
			{
				flag = 1;
			}
		}
	}
	if(flag == 1 )
	{
		cout<<"链表结点数为偶数："<<leng(phead)<<endl;
		cout<<"中间节点值为："<<temp->data<<","<<p->data<<endl;
	}
	else
		cout<<"链表结点数为奇数："<<leng(phead)<<", 中间节点值为："<<p->data<<endl;

}
int main()
{
	int length;
	PNODE head = NULL;
	head = creat();
	length = leng(head);
	print(head);
//	insert(head);
//	length = leng(head);
//	print(head);
//	add_tail(head);
//	length = leng(head);
//	print(head);
//	head = del(head);
//	length = leng(head);
//	print(head);
//	head = list_sort(head);
//	cout<<"逆置后链表为：";
//	head = reverse(head);
//	print(head);
//	head = list_sort(head);
	find_mid_val(head);
	system("pause");
	return 0;
}
