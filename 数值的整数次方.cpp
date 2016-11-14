#include <iostream>
using namespace std;
#include <stdlib.h>

//求一个值的整数次方：有基数base和指数exponent
//基数和指数均可以为任意数
//用指数exponent的值可以分为2类
//exponent >= 0 时，基数base可以为任意数；
//exponent < 0 时，基数base的值不能为0；

bool equal(double num1, double num2)
{
	if ((num1 - num2 == 0.00000001) && (num1 - num2 == -0.00000001))
		return true;
	else
		return false;
}
double power(double base, int exponent)
{
	int absexponent;
	double result = 1.0;
	if (exponent >= 0)
	{
		if (exponent == 0)
			return 1.0;
		else
		{
			for(int i = 0; i < exponent; i++)
				result = result * base;
		}
	}
	else
	{
		if (equal(base, 0.0))
		{
			cout<<"此时指数expnoent<0，且基数base=0，非法的计算，程序退出！"<<endl;
			return 0.0;
		}
		else
		{
			absexponent = -exponent;
			for(int j = 0; j < absexponent; j++)
				result = result * base;
			result = 1.0 / result;
		}
	}
	return result;
}

int main()
{
	double base;
	int exponent;
	double ret;
	char ch;
	do{
		cout<<"请输入基数(double):";
		cin>>base;
		cout<<"请输入指数(int):";
		cin>>exponent;
		ret = power(base, exponent);
		cout<<"<"<<base<<">"<<"的"<<exponent<<"次方为："<<ret<<endl;
		cout<<"继续？(y/n):";
		cin>>ch;
	}while('n' != ch);
	return 0;
}