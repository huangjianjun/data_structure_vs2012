#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>//window ��sleep()������ͷ�ļ���ʹ��ʱsleep()������sҪ��дS����ʱ��λΪ���롣
#define  MAXNUM  8 //���ƶ��еĳ��� 
#define N 5 // ����ģ���ʱ�䳤�ȣ��룩

//������ʽ���еĽ��ṹ
typedef struct node 
{
	int number;
//	char name[MAXSIZE];
	struct node *next;
}NODE, *PNODE;

typedef struct linkqueue
{
	PNODE front;
	PNODE rear;
}QUEUE, *PQUEUE;

PQUEUE init_queue( PQUEUE q)
{
	q->front = (PNODE)malloc(sizeof(NODE));
	if (NULL == q->front)
	{
		cout<<"(��ʼ��)��̬�����б�ʧ�ܣ�\n";
		exit(-1);
	}
	q->front->next = NULL;
	q->rear = q->front;
	q->front->number = 0;//��ʼ��ֵΪ0
	return q;
}

void in_queue( PQUEUE q, int val)
{
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	pnew->next = NULL;
	pnew->number = val;
	q->rear->next = pnew;
	q->rear = pnew;
}
bool is_empty_queue(PQUEUE q)
{
	if (q->front == q->rear) return true;
	else return false;
}
int out_queue( PQUEUE q)
{
	int out;
	PNODE temp = NULL;
	if(is_empty_queue(q))
	{
		cout<<"�˿�ԤԼ����Ϊ��!\n";
		return -1;
	}
	else
	{
		out = q->front->next->number;
		temp = q->front;
		q->front = q->front->next;
		free(temp);
		return out;
	}
}
int get_first_val( PQUEUE q)
{
	int ret = q->front->next->number;
	return ret;

}

void traverse(PQUEUE q)
{
	PNODE p = q->front->next;
	if(is_empty_queue(q))
	{
		cout<<"ϵͳ�й˿�ԤԼ����Ϊ��!\n";
	}
	else
	{
		while( NULL != p)
		{
			cout<<p->number<<"\t";
			p = p->next;
		}
		cout<<"\n";
	}
}

int length_queue( PQUEUE q)
{
	int len = 0;
	PNODE p = q->front->next;
	while( NULL != p)
	{
		len++;
		p = p->next;
	}
//	cout<<"��ʱ���г��ȣ�"<<len<<endl;
	return len;
}
void delay(int s)//��ʱ��λΪ��
{
	Sleep(s * 1000);//Sleep()�ĵ�λΪ����
}

void guahao(PQUEUE q, int num)
{
	if(length_queue(q) == MAXNUM)
	{
		cout<<"�Բ��𣬽���ϵͳ��Ԥ���������Ѵ����ޣ��������������Һ�ԤԼ��\n";
		cout<<"������ϵͳ�еĹ˿ͱ�ţ�";
		traverse(q);
		return;
	}
	else
	{
//		num++;
		in_queue(q, num);
		cout<<"���Ϊ��"<<num<<" �Ĺ˿��Ѿ�ԤԼ�ɹ��������ĵȴ���\n";
		delay(1);
	}
}

int simulation(PQUEUE q,int n)
{
	int n1,n2,out;
	n1 = get_first_val(q);
	cout<<"-----------------------------------------------------------------\n";
	cout<<"����Ϊ��"<<n1<<" �Ĺ˿͵�ǰ̨����ҵ��!\n";
	out = out_queue(q);
	if( n1 != n)
	{
		n2 = get_first_val(q);
		cout<<"����Ϊ��"<<n2<<" �Ĺ˿�����׼����\n";
	}
	cout<<"�˿ͱ��Ϊ��"<<out<<" ��ҵ�����ڰ���"<<endl;
	cout<<"ģ��ҵ��Ա����ҵ��......\n";
	for(int i = 0;i < N; i++)
	{
		cout<<N-i<<"\n";
		delay(1);
	}
//	cout<<"\n";
	cout<<"ģ��ҵ��Ա����ҵ�������\n";
	cout<<"-----------------------------------------------\n";
	return n1;
}
int main()
{
	int n,k,m;
	char s;
	PQUEUE q = (PQUEUE)malloc(sizeof(QUEUE));
	q = init_queue(q);
	cout<<"<��ӭ��ʹ�ùҺ�ϵͳ>\n";
	do
	{
		int num = 0; //�������ڱ���˿͵����
		cout<<"�������뽫Ҫģ��Ĺ˿�������";
		cin>>k;
		for(int i = 0; i<k; i++)
		{
			num++;
			guahao(q,num);
		}
		cout<<"-----------------------------------------------------------------\n";
		cout<<"�˿ͱ�ţ�";
		traverse(q);
		n = length_queue(q);
		while(1)
		{
			m = simulation(q,n);
			cout<<"�˿ͱ�ţ�";
			traverse(q);
			if( m == n)  break;
		}
		cout<<"�Ƿ��������ģ��?(y/n):";
		cin>>s;
	}while( s != 'n');
	
	system("pause");
	return 0;
}
