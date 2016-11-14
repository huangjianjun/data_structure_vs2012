#include <iostream>
using namespace std;
#include<stdlib.h>
#include <string>
//ʵ�ִ�����ˣ�
void multiply(const char *num1, const char *num2)
{
	long int num1_length = strlen(num1);
	long int num2_length = strlen(num2);
	long int *result = (long int *)malloc((num1_length + num2_length) * sizeof(long int));
	for (long int i = 0; i < num1_length + num2_length; i++)//��ʼ���½�����
		result[i] = 0;
//��num1 ��ÿһλ�ֱ���num2��ˣ�����ÿ�μ�������Ӧλֵ���
//����a�е�ÿλ��λ������b��ˣ����ѽ����������c 
//���磬12345*12345��a�е�5��12345��λ��� 
//��������c��*(c+i+j)��i=0,j=0,1,2,3,4ʱ�����5���λ��˵Ľ�� 
//����i=1,j=0,1,2,3,4ʱ������4���λ��˵Ľ���������ۼ����ϴ���˵Ľ��.��һ������Ҫע���!!! 
	for(long int i = 0; i < num1_length; i++)
		for(long int j = 0; j < num2_length; j++)
			result[i + j +1] += (num1[i] - '0') * (num2[j] - '0');
	
	//�����result������ÿһ����ֵ���н�λ����λ����
	for(long int k = num1_length+num2_length-1; k >= 1 ; k--)
	{
		if(result[k] / 10 != 0)
		{
			result[k-1] += result[k] / 10;
			result[k] = result[k] % 10;
		}
	}
	cout<<"������Ϊ��";
	for (int i = 0; i < num1_length + num2_length; i ++)
		cout<<*(result+ i);
	cout<<endl;
	free(result);
}

int main()
{
	string num1,num2;//�����ַ������洢����
	char ch;
	do{
		cout<<"���������num1:";
		cin>>num1;
		cout<<"���������num2��";
		cin>>num2;
		//c_str()����Ϊstring���һ����������string���׵�ַ���أ���������Ϊconst char *
		const char *p1=num1.c_str();    // ��stringתΪ const char *
		const char *p2=num2.c_str();    // ��stringתΪ const char *
		long int num1_length = strlen(p1);
		long int num2_length = strlen(p2);
		multiply(p1, p2);
		cout<<"������(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;

}