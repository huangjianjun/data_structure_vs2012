#include <iostream>
using namespace std;
#include <stdlib.h>

//��һ��ֵ�������η����л���base��ָ��exponent
//������ָ��������Ϊ������
//��ָ��exponent��ֵ���Է�Ϊ2��
//exponent >= 0 ʱ������base����Ϊ��������
//exponent < 0 ʱ������base��ֵ����Ϊ0��

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
			cout<<"��ʱָ��expnoent<0���һ���base=0���Ƿ��ļ��㣬�����˳���"<<endl;
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
		cout<<"���������(double):";
		cin>>base;
		cout<<"������ָ��(int):";
		cin>>exponent;
		ret = power(base, exponent);
		cout<<"<"<<base<<">"<<"��"<<exponent<<"�η�Ϊ��"<<ret<<endl;
		cout<<"������(y/n):";
		cin>>ch;
	}while('n' != ch);
	return 0;
}