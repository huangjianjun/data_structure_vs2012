#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stack>
/*����˼�룺���Ÿ����ĳ�ջ����������ѹջ������Ѱ����Ӧ��Ԫ�أ������յ�Ԫ�ز���ջ��Ԫ�أ�����ѹջ�����в��ң������ֲ��ҹ�������Ԫ��ѹջ��������Ԫ�أ������ҵ����򽫸�Ԫ�س�ջ����־λflag = ture����û����ֱ�ӽ������أ���־λflag = false;����һ��Ҫ�ҵ�Ԫ�ظպ���ջ�����򵯳���Ԫ�أ�����һ��Ҫ�ҵ�Ԫ�ز���ջ��Ԫ�أ�����ʣ���δѹջ��Ԫ�����ң��ҵ��󽫴��ֲ��ҹ�������Ԫ��ѹջ��������Ԫ�أ�����ѹջ���б����궼û���ҵ���Ԫ�أ�����������*/
stack<int> m_data;
bool is_pop_order(int *order_push, int *order_pop, int length, int count)
{
	bool flag = false;
	int defaultval = -100;
	m_data.push(defaultval);//��ջ��ʼ��һ��Ĭ��ֵ����ֹ����ȡջ��Ԫ��ʱ����
	for( int i = 0; i < length; i++)
	{
		if(count == length && order_pop[i] != m_data.top())
		{
			flag = false;
			return flag;
		}
		if(order_pop[i] != m_data.top() && count != length)
		{
			for(int j = count; j < length; j++)
			{
				if(order_pop[i] == order_push[j])
				{
					flag = true;
					for(int k = count; k <= j; k++)//��order_push[j]֮ǰ��Ԫ��ѹջ
					{
						m_data.push(order_push[k]);
						count++;
					}
					m_data.pop();
					break;
				}
				else
					flag = false;
			}
		}
		else
		{
			m_data.pop();
			flag = true;
		}
	}
	return flag;
}
void stack_clear(stack<int> m)
{
	while(m.size() != 0)
		m.pop();
}
void traverse(int * a, int length)
{
	cout<<"���У�{";
	for(int i = 0; i < length; i++)
		cout<<a[i]<<"  ";
	cout<<"}";
}
void test(int *order_push, int *order_pop, int length, int count, stack<int> m)
{
	bool ret;
	count = 0;
	stack_clear(m);
	ret = is_pop_order(order_push, order_pop, length,count);
	if(1 == ret)
	{
		traverse(order_pop,length);
		cout<<"<��>";
		traverse(order_push,length);
		cout<<" �ĳ�ջ���У�"<<endl;
	}
	else
	{
		traverse(order_pop,length);
		cout<<"<����>";
		traverse(order_push,length);
		cout<<" �ĳ�ջ���У�"<<endl;
	}
	return ;
}
int main()
{
	int count = 0;
	int order_push[5] = {1,2,3,4,5};
	int order_pop1[5] = {4,3,5,1,2};//false
	int order_pop2[5] = {4,3,2,1,5};//true
	int order_pop3[5] = {4,5,3,2,1};//true
	int order_pop4[5] = {1,5,4,3,2};//true
	test(order_push, order_pop1, 5, count, m_data);
	test(order_push, order_pop2, 5, count, m_data);
	test(order_push, order_pop3, 5, count, m_data);
	test(order_push, order_pop4, 5, count, m_data);
	system("pause");
	return 0;
}