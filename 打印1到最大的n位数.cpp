#include <iostream>
using namespace std;
#include<stdlib.h>
#include <string>
#include <time.h>
//��ָoffer 94ҳ��
char * create_number(int n)//n��ʾ�������λ����
{
	char *number = (char *)malloc(sizeof(char) * (n + 1));
	for(int i = 0; i < n; i++)
		number[i] = '0';
	number[n] = '\0';
	return number;
}
bool increase_number( char *number)
{
	int length  = strlen(number);
	int takeover = 0;
	bool isoverflow = false;
	for (int i = length-1; i >= 0; i--)
	{
		int num = number[i] - '0' + takeover;
		if ( i == length-1)
			num++;
		if( num >= 10)
		{
			if( 0 == i)
				isoverflow = true;
			else
			{
				num -= 10;
				number[i] = '0' + num;
				takeover = 1;
			}
		}
		else
		{
			number[i] = num + '0';
			break;
		}
	}
	return isoverflow;
}

void print_number(char *number)
{
	int n = strlen(number);
	bool isbegin_0 = false;
	for(int i = 0; i< n; i++)
	{
		if ((!isbegin_0) && (number[i] != '0'))
			isbegin_0 = true;
		if (isbegin_0)
		{
			cout<<number[i];
		}		    
	}
	cout<<"\t";
}

int main()
{
	int n = 0;
	char ch;
	do{
		int count = 0;
		cout<<"-------<���Դ�ӡ1������nλ��>---------------\n";
		cout<<"������N��ֵ��";
		cin>>n;
		while( n <= 0)
		{
			cout<<"�����n��ֵ����"<<endl;
			cout<<"������N��ֵ��";
			cin>>n;
		}
		char* number = create_number(n);
		cout<<"��ӡ������£�\n";
		clock_t start_time=clock();
		while(!increase_number(number))
		{
			print_number(number);
			count++;
			if( count % 10 == 0)
				cout<<endl;
		}
		cout<<endl;
		clock_t end_time=clock();
		//�������ʱ��
		cout<< "��������ʱ��: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<" ms"<<"\t"<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC<<" s"<<endl;
		free(number);
		cout<<"������(y/n):";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}
//�漰���������⣬����һ������ַ����������������
//�������ǰ��ַ����е�ÿһ���ַ���ʼ��Ϊ��0����Ȼ��ÿһ��Ϊ�ַ�����ʾ�����ּ�1���ٴ�ӡ����������ֻ��Ҫ�������£�
//һ:���ַ�����ʾ��������ģ��ӷ���
//�������ַ����������ִ�ӡ������