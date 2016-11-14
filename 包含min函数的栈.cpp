#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stack>

stack <int> m_data;//Ϊ����ջ������������ջ����
stack <int> m_min;//����ջ�����ڼ�¼ѹ�뵽ջ����СԪ��
void stack_with_min_push(int value)
{
	m_data.push(value);
	if(m_min.size() == 0 || value <= m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
	return ;
}
void stack_with_min_pop()
{
	int val, val_min;
	if( m_min.size() > 0 && m_data.size() > 0)
	val = m_data.top();
	val_min = m_min.top();
	m_data.pop();
	m_min.pop();
	cout<<"m_data ջ��ջ��Ԫ��Ϊ�� "<<val<<endl;
	cout<<"m_min ջ��ջ��Ԫ��Ϊ�� "<<val_min<<endl;
	return ;
}

int stack_with_min_min()
{
	int min_val;
	if( m_min.size() > 0)
		min_val = m_min.top();
	return min_val;
}

void display(stack<int> m)
{
	while(m.size() > 0)
	{
		cout<<m.top()<<"  ";
		m.pop();
	}
	cout<<endl;
}
int main()
{
	char ch;
	int minval;
	int n,m;
	int slect = 0;
	cout<<"������Ҫѹջ��Ԫ�ظ���: n = ";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"������ѹջԪ�أ�";
		cin>>m;
		stack_with_min_push(m);
	}
	do
	{
		cout<<"----------------------------------------------\n";
		cout<<"1��ѹջ����  2����ջ���� 3�����ջ����Сֵ\n";
		cout<<"----------------------------------------------\n";
		cout<<"��ʱջ m_data Ϊ��";
		display(m_data);
		cout<<"��ʱջ m_min Ϊ��";
		display(m_min);
		cout<<"��������ѡ��";
		cin>>slect;
		switch(slect)
		{
		case 1:
			{
				cout<<"������ѹջԪ�أ�";
				cin>>m;
				stack_with_min_push(m);
				break;
			}
		case 2:
			{
				stack_with_min_pop();
				break;
			}
		case 3:
			{
				minval = stack_with_min_min();
				cout<<"ջ����СֵΪ�� "<<minval<<endl;
				break;
			}
		default:
			break;
		}
		cout<<"��������y/n��:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}