#include<iostream>
using namespace std;
#include <stdlib.h>
#include<stack>

long int number_of_1_changgui(long int data)
{
	unsigned int flag = 1;
	int count = 0;
	int n = 0;
	while(flag)
	{
		n++; //��¼whileѭ���Ĵ���
		if(data&flag)//ֻҪ����Ľ����Ϊ0���ʹ������������λ��Ϊ0.
			count++;
		flag = flag << 1;
	}
	cout<<"number_of_1_changgui ��ѭ��������"<<n<<endl;
	return count;
}

long int number_of_1_zuijia(long int data)
{
	int count = 0;
	while(data)
	{
		count++;//�ȱ�ʾ1�ĸ�����Ҳ����whileѭ���Ĵ���
		data = data&(data-1);
	}
	cout<<"number_of_1_changgui ��ѭ��������"<<count<<endl;
	return count;
}
int main()
{
	char ch;
	int remainder;//����
	long int number;
	long int temp1;
	do{
		long int num_of_1;
		cout<<"������ʮ������:";
		cin>>number;
		temp1 = number;
		stack<int> stack1;
		int n = 0;//��¼ת����Ķ���������ʵ��λ��
		int m = 0;//��¼��Ҫ��ǰ����ӵ�0�ĸ���
		int val;
		int num = 0;//��¼�����4��һ�����ĸ���
		while(number != 0)
		{
			remainder = number % 2;
			stack1.push(remainder);
			number = number / 2;
			n += 1;
			if (n % 4 == 0)
				num += 1;
		}
		if ( n % 4 != 0)
		{
			m = 4 - (n - 4 * num);
			for (int i = 0; i < m; i++)
			{
				stack1.push(0);
			}
		}
		cout<<"ת������Ч�Ķ�����λ(�Ӻ�����)��"<<n<<endl;
		cout<<"ʮ��������<"<<temp1<<"> ת����Ķ�����Ϊ��";
		stack<int> temp = stack1;
		n = 0;
		while(!temp.empty())
		{
			val = temp.top();
			cout<<val;
			temp.pop();
			n += 1;
			if (n % 4 == 0)
			{
				cout<<" ";
			}
		}
			cout<<endl;
		cout<<"-------------------------------------------\n";
		num_of_1 = number_of_1_changgui(temp1);
		cout<<"ת����Ķ�������<1>�ĸ���Ϊ��"<<num_of_1<<endl;
		cout<<"-------------------------------------------\n";
		num_of_1 = number_of_1_zuijia(temp1);
		cout<<"ת����Ķ�������<1>�ĸ���Ϊ��"<<num_of_1<<endl;
		cout<<"����?(y/n):";
		cin>>ch;
	}while(ch != 'n');
}