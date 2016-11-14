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
		cout<<"��̬�����ռ�ʧ�ܣ�"<<endl;
		exit(-1);
		system("pause");
	}
	phead->data = -100;
	printf("�����봴������ĳ��ȣ�");
	cin>>num;
	PNODE p = phead;
	for(int i = 0; i<num; i++)
	{
		PNODE pnew = (PNODE)malloc(sizeof(NODE));
		p->next = pnew;
		cout<<"�������������ֵ��";
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
	cout<<"����ĳ���Ϊ��"<<n<<endl;
	return n;
}
void insert(PNODE phead)//����pos��λ��ǰ�������ֵval
{
	int pos,val;
	int n = 1;
	PNODE p1 = phead; 
	PNODE p = phead->next;
	cout<<"�����������Ľ��λ�ã�";
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
	cout<<"�����������Ľ���ֵ��";
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
	cout<<"�����������β������ֵ��";
	cin>>val;
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->data = val;
	p->next = pnew;
	pnew->next = NULL;
}
PNODE del(PNODE phead)
{
	int val;
	cout<<"��������Ҫɾ���Ľڵ�ֵ��";
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
	cout<<"�������б�";
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
	phead->next->next = NULL;//phead ��ֵ��ѭ����û�б䣬�൱��ԭ����һ��������һ������ÿա�
	PNODE pnew = (PNODE)malloc(sizeof(NODE));//������ù���������ͷ���
	pnew->data = -200;
	pnew->next = ppre;
	phead = pnew;
	return phead;
}
//��֪��������Ľ����N������һ�ε������ҳ��м�ڵ�ֵ��
//������������ָ��p,q,ʹqÿ���ƶ�����λ�ã�pÿ���ƶ�һ��λ�ã�������q��β��ʱ��p�պ��ߵ��м�λ�ã���Ȼ����������Ϊ��ż������������ǡ�
void find_mid_val(PNODE phead)
{
	int flag = 0; //��־λ�����ֽ����Ϊ��ż���������
	PNODE temp = NULL ; //ż��ʱ�������p��ǰһ����㡣
	PNODE p = phead->next;
	PNODE q = phead->next;
	if(NULL == phead || NULL == phead->next)
	{
		cout<<"�����������"<<endl;
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
			if(NULL == q ) //�ڵ�Ϊż��������ж�
			{
				flag = 1;
			}
		}
	}
	if(flag == 1 )
	{
		cout<<"��������Ϊż����"<<leng(phead)<<endl;
		cout<<"�м�ڵ�ֵΪ��"<<temp->data<<","<<p->data<<endl;
	}
	else
		cout<<"��������Ϊ������"<<leng(phead)<<", �м�ڵ�ֵΪ��"<<p->data<<endl;

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
//	cout<<"���ú�����Ϊ��";
//	head = reverse(head);
//	print(head);
//	head = list_sort(head);
	find_mid_val(head);
	system("pause");
	return 0;
}
