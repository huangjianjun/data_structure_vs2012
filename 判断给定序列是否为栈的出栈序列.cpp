#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stack>
/*基本思想：按着给定的出栈序列依次在压栈序列中寻找相应的元素，若参照的元素不是栈顶元素，则在压栈序列中查找，将此轮查找过的所有元素压栈（包括该元素），若找到，则将该元素出栈，标志位flag = ture，若没有则直接结束返回，标志位flag = false;若下一个要找的元素刚好在栈顶，则弹出该元素；若下一个要找的元素不是栈顶元素，则在剩余的未压栈的元素中找，找到后将此轮查找过的所有元素压栈（包括该元素），若压栈序列遍历完都没有找到该元素，则程序结束。*/
stack<int> m_data;
bool is_pop_order(int *order_push, int *order_pop, int length, int count)
{
	bool flag = false;
	int defaultval = -100;
	m_data.push(defaultval);//给栈初始化一个默认值，防止初次取栈顶元素时出错。
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
					for(int k = count; k <= j; k++)//将order_push[j]之前的元素压栈
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
	cout<<"序列：{";
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
		cout<<"<是>";
		traverse(order_push,length);
		cout<<" 的出栈序列！"<<endl;
	}
	else
	{
		traverse(order_pop,length);
		cout<<"<不是>";
		traverse(order_push,length);
		cout<<" 的出栈序列！"<<endl;
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