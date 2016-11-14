#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int *pbase;//ָ�����������ָ��
	int front;//ָ��������±�
	int rear;//ָ��������±�
}QUEUE,* PQUEUE;

int init_queue(PQUEUE queue, int n)//��������ĳ���
{
	cout<<"������Ҫ����ѭ�����е�����ĳ��ȣ�";
	cin>>n;
	queue->pbase = (int *)malloc(sizeof(int) * n);
	queue->front = 0;
	queue->rear = 0;
	return n;
}

bool is_empty_queue(PQUEUE queue)
{
	if (queue->rear == queue->front)
		return true;
	else
		return false;
}
bool is_full_queue(PQUEUE queue, int n)
{
	if ((queue->rear + 1) % n == queue->front)
		return true;
	else
		return false;
}


void in_queue(PQUEUE queue, int value,int n)
{
	cout<<"ִ����Ӳ���,"<<"��ӵ�ֵ��"<<value<<endl;
	if (is_full_queue( queue, n))
	{
		cout<<"��������������ָ����Ӳ���!\n";
	}
	else
	{
		//cout<<"queue->rear :"<<queue->rear<<endl;
		queue->pbase[queue->rear] = value;
		queue->rear = (queue->rear + 1) % n;
	}
}

void out_queue(PQUEUE queue,int n)
{
	int r ;//���ڴ�ų��ӵ�ֵ
	cout<<"ִ�г��Ӳ���,";
	if (is_empty_queue(queue))
		cout<<"����Ϊ�գ�����ִ�г��Ӳ�����\n";
	else
	{	
		r = queue->pbase[queue->front] ;
		queue->front = (queue->front + 1) % n;
		cout<<"���ӵ�Ԫ��ֵ:"<<r<<endl;
	}
	return ;
}

void forced_out_queue(PQUEUE queue,int n)
{
	int r ;//���ڴ�ų��ӵ�ֵ
	cout<<"������ǿ�г��ӵ�ֵ��";
	cin>>r;
	cout<<"ִ��ǿ�г��Ӳ���,";
	if (is_empty_queue(queue))
		cout<<"����Ϊ�գ�����ִ�г��Ӳ�����\n";
	else
	{	
		int i = queue->front;
		while(queue->pbase[i] != r)
		{

			i = (i + 1) % n;
		}
		queue->front = (i + 1) % n;
		
		cout<<"���ӵ�Ԫ��ֵ:"<<r<<endl;
	}
	return ;
}
void traverse_queue(PQUEUE queue,int n)
{
	cout<<"��������:";
	if (is_empty_queue(queue))
	{
		cout<<"����Ϊ��!";
	}

	int i = queue->front;
	while(i != queue->rear)
	{
		//cout<<"queue->front :"<<queue->front<<endl;
		cout<<queue->pbase[i]<<"    ";
		i = (i + 1) % n;
	}
	cout<<"\n";
	return ;
}

int main()
{
	QUEUE queue;
	int n = -1;
	n = init_queue(&queue, n);
	cout<<"n :"<<n<<endl;
	in_queue(&queue,200,n);
	traverse_queue(&queue,n);
	in_queue(&queue,400,n);
	traverse_queue(&queue,n);
	in_queue(&queue,500,n);
	traverse_queue(&queue,n);
	in_queue(&queue,300,n);
	traverse_queue(&queue,n);
	out_queue(&queue, n);
	traverse_queue(&queue,n);
	forced_out_queue(&queue,n);
	traverse_queue(&queue,n);
	system("pause");
	return 0;
}

