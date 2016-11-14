#include<iostream>
using namespace std;
#include <stdlib.h>
#include <string>

void add(const char* num1, const char* num2)//没有考虑负数的情况。
{
	int num1_length = strlen(num1);
	int num2_length = strlen(num2);
	int length_max ,length_min;
	if(num1_length >= num2_length)
	{
		length_max = num1_length;
		length_min = num2_length;
	}
	else
	{
		length_max = num2_length;
		length_min = num1_length;
	}
	int* result = (int*)malloc(sizeof(int)*(length_max + 1));
	for(int i = 0; i <= length_max; i++)
		result[i] = 0;
	int deter = length_max - length_min;
	if(num1_length >= num2_length)
	{
		for (int j = 0; j < length_max; j++)
			result[ j + 1] = num1[j] - '0';
		for(int i = 0; i < length_min; i++)
			result[i+deter+1] += num2[i] - '0';
	}
	else
	{
		for (int j = 0; j < length_max; j++)
			result[ j + 1] = num2[j] - '0';
		for(int i = 0; i < length_min; i++)
			result[i+deter+1] += num1[i] - '0';
	}

	// 下面对 result进行进位
	for(int i = length_max; i >= 1; i--)
	{
		if (result[i] / 10 != 0)
		{
			result[i-1] += result[i] / 10;
			result[i] = result[i] % 10; 
		}
	}
	//打印result结果
	bool isbegin0 = false;
	for (int i = 0; i <= length_max; i++)
	{
		if(0 != result[i] && !isbegin0)
			isbegin0 = true;
		if(isbegin0)
			cout<<result[i];
	}
	cout<<endl;
	free(result);
}
int main()
{
	string num1,num2;
	char ch;
	do{
		cout<<"input num1:";
		cin>>num1;
		cout<<"input num2:";
		cin>>num2;
		const char *p1 = num1.c_str();
		const char *p2 = num2.c_str();
		cout<<"计算结果：";
		add(p1,p2);
		cout<<"继续？(y/n):";
		cin>>ch;
	}while('n' != ch);	
	system("pause");
	return 0;
}