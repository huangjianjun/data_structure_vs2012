#include <iostream>
using namespace std;
#include <stdlib.h>

//������������Ը�����������������������䷶Χ 0-99��
//���и���������±�������䣬����ֵ�����������Դ���������г��ֵĴ���

void age_sort(int *ages , int length)
{
	int oldest = 99;
//	int index = 0;
	int age;
	int times_age[100];
	for(int i = 0; i <= oldest; i++)
	{
		times_age[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		age = ages[i];
		times_age[age] += 1;
	}
	for(int i = 0; i < oldest; i++)
	{
		if (times_age[i] != 0)
		{
			for (int j = 0; j < times_age[i]; j++)
			{
				cout<<i<<" ";
			}
		}
	}
	cout<<endl;
}

int main()
{
	int ages[13] = {80,91,45,36,69,78,23,48,29,68,36,15,18};
	cout<<"����ǰ�����䣺"<<endl;
	for(int i = 0; i < 13; i++)
		cout<<ages[i]<<" ";
	cout<<endl;
	cout<<"���������Ľ�����£�"<<endl;;
	age_sort(ages,13);
	system("pause");
	return 0;
}