#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stack>

stack <int> m_data;//为数据栈，用于正常的栈操作
stack <int> m_min;//辅助栈，用于记录压入到栈的最小元素
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
	cout<<"m_data 栈出栈的元素为： "<<val<<endl;
	cout<<"m_min 栈出栈的元素为： "<<val_min<<endl;
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
	cout<<"请输入要压栈的元素个数: n = ";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"请输入压栈元素：";
		cin>>m;
		stack_with_min_push(m);
	}
	do
	{
		cout<<"----------------------------------------------\n";
		cout<<"1、压栈操作  2、出栈操作 3、输出栈中最小值\n";
		cout<<"----------------------------------------------\n";
		cout<<"此时栈 m_data 为：";
		display(m_data);
		cout<<"此时栈 m_min 为：";
		display(m_min);
		cout<<"请您按键选择：";
		cin>>slect;
		switch(slect)
		{
		case 1:
			{
				cout<<"请输入压栈元素：";
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
				cout<<"栈中最小值为： "<<minval<<endl;
				break;
			}
		default:
			break;
		}
		cout<<"继续？（y/n）:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}