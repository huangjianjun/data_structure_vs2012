#include<stdio.h>
#include<iostream>
using namespace std;
#include<stack>
#include<string>

int main()
{
	int i;
	int num ;
	stack<string> mystack;
	char *str[10] = {"huang","jian","jun","stack","exceise"};
	cout<<strlen(*(str))<<endl;
	for(i = 0; i < strlen(*str); i++)
	{
		mystack.push(*(str+i));
	}
	cout<<"对栈进行遍历：\n";
	num = mystack.size();
	for(i = 0; i < num; i++)
	{
		cout<<mystack.top()<<"\t";
		mystack.pop();
	}
	cout<<endl;
	system("pause");
	return 0;
}