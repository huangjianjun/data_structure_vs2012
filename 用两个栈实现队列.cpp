#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stack>

stack<char> stack1;
stack<char> stack2;

void appendTail(char value)
{
	stack1.push(value);
}
char deleteHead()
{
	char data;
	char head;
	if(stack2.size() <= 0)
	{
		while(stack1.size() > 0)
		{
			data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
		cout<<"此时队列为空！"<<endl;
	head = stack2.top();
	stack2.pop();
	return head;
}

void traverse(stack<char> st)
{
	stack<char> temp = st;
	char ch;
	while(!temp.empty())
	{
		ch = temp.top();
		cout<<ch<<"    ";
		temp.pop();
	}
	cout<<endl;
}

int main()
{
	int n;
	char m,ret;
	cout<<"请输入模仿的队列的长度：";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"请输入值(char):";
		cin>>m;
		appendTail(m);
	}
	cout<<"出列前 stack1: ";
	traverse(stack1);
	cout<<"出列前 stack2: ";
	traverse(stack2);
	ret = deleteHead();
	cout<<"出列的元素： "<<ret<<endl;
	cout<<"出列后 stack2: ";
	traverse(stack2);
	system("pause");
	return 0;
}