#include <iostream>
using namespace std;
#include <stdlib.h>

//�ж�һ�����Ƿ�Ϊ2�������η�
//��������Ϊ2�������η�����������������ҽ���һλ��1��

bool is_2_n_cifang(long int number)
{
	int flag = 0;
	int count = 0;
	while(number)
	{
		count++;
		flag = 1;
		number = number&(number - 1);
	}
	if ((flag == 1) && (count == 1) )
		return true;
	else
		return false;
}

//��������m,n ����Ҫ�ı�m�Ķ����Ʊ�ʾ�еĶ���λ���ܵõ�n
//���������Ƚ�m,n��������򣨶����Ʊ�ʾ�в�ͬ��λ����Ϊ1�������ͳ��������е�1�ĸ�������ΪҪ�ı��λ��
int num_of_change(long int m, long int n)
{
	long int temp ;
	int count = 0;
	temp = m^n;
	while(temp)
	{
		count++;
		temp = temp&(temp-1);
	}
	return count;
}

int main()
{
	long int m,n;
	char ch;
	do{
		int k;
		cout<<"����������(long int):\n";
		cout<<"m = ";
		cin>>m;
		cout<<"n = ";
		cin>>n;
		if(is_2_n_cifang(m))
			cout<<"m = "<<m<<" ��2�������η�"<<endl;
		else
			cout<<"m = "<<m<<" ����2�������η�"<<endl;
		if(is_2_n_cifang(n))
			cout<<"n = "<<n<<" ��2�������η�"<<endl;
		else
			cout<<"n = "<<n<<" ����2�������η�"<<endl;
		k = num_of_change(m,n);
		cout<<"�����Ʊ�ʾ�� m->n ��Ҫ�ı��λ����"<<k<<endl;
		cout<<"����?(y/n):";
		cin>>ch;

	}while('n' != ch);
	return 0;
}