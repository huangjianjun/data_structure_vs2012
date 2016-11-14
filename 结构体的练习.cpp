#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int sid;
	char name[100];
	int age;
}; //分号不能少！！！

int main()
{
	struct student st = {20,"huang",25};
	cout<<"输入姓名:";
	cin>>st.name;
	printf("输入学生信息如下：\n");
	printf("姓名：%s\n",st.name);
	printf("学号：%d\n",st.sid);
	printf("年龄：%d\n",st.age);
	system("pause");
	return 0;
}
