#include <iostream>
using namespace std;
#include <stdlib.h>

//借助辅助数组对给定的年龄数组进行排序（年龄范围 0-99）
//其中辅助数组的下标代表年龄，数组值代表该年龄在源年龄数组中出现的次数

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
	cout<<"排序前的年龄："<<endl;
	for(int i = 0; i < 13; i++)
		cout<<ages[i]<<" ";
	cout<<endl;
	cout<<"年龄排序后的结果如下："<<endl;;
	age_sort(ages,13);
	system("pause");
	return 0;
}