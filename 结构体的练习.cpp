#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int sid;
	char name[100];
	int age;
}; //�ֺŲ����٣�����

int main()
{
	struct student st = {20,"huang",25};
	cout<<"��������:";
	cin>>st.name;
	printf("����ѧ����Ϣ���£�\n");
	printf("������%s\n",st.name);
	printf("ѧ�ţ�%d\n",st.sid);
	printf("���䣺%d\n",st.age);
	system("pause");
	return 0;
}
