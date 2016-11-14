#include <iostream>
using namespace std;
#include<stdlib.h>
#include <string>
//实现大数相乘！
void multiply(const char *num1, const char *num2)
{
	long int num1_length = strlen(num1);
	long int num2_length = strlen(num2);
	long int *result = (long int *)malloc((num1_length + num2_length) * sizeof(long int));
	for (long int i = 0; i < num1_length + num2_length; i++)//初始化新建数组
		result[i] = 0;
//将num1 的每一位分别与num2相乘，并且每次计算结果对应位值相加
//数组a中的每位逐位与数组b相乘，并把结果存入数组c 
//比如，12345*12345，a中的5与12345逐位相乘 
//对于数组c：*(c+i+j)在i=0,j=0,1,2,3,4时存的是5与各位相乘的结果 
//而在i=1,j=0,1,2,3,4时不光会存4与各位相乘的结果，还会累加上上次相乘的结果.这一点是需要注意的!!! 
	for(long int i = 0; i < num1_length; i++)
		for(long int j = 0; j < num2_length; j++)
			result[i + j +1] += (num1[i] - '0') * (num2[j] - '0');
	
	//下面对result数组中每一项储存的值进行进位，移位操作
	for(long int k = num1_length+num2_length-1; k >= 1 ; k--)
	{
		if(result[k] / 10 != 0)
		{
			result[k-1] += result[k] / 10;
			result[k] = result[k] % 10;
		}
	}
	cout<<"计算结果为：";
	for (int i = 0; i < num1_length + num2_length; i ++)
		cout<<*(result+ i);
	cout<<endl;
	free(result);
}

int main()
{
	string num1,num2;//采用字符串来存储大数
	char ch;
	do{
		cout<<"请输入大数num1:";
		cin>>num1;
		cout<<"请输入大数num2：";
		cin>>num2;
		//c_str()函数为string类的一个方法，将string的首地址返回，返回类型为const char *
		const char *p1=num1.c_str();    // 将string转为 const char *
		const char *p2=num2.c_str();    // 将string转为 const char *
		long int num1_length = strlen(p1);
		long int num2_length = strlen(p2);
		multiply(p1, p2);
		cout<<"继续？(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;

}