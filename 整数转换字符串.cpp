#include <iostream>
using namespace std;
#include <stdlib.h>

char exchange(int m)//��1��9������ת���ɶ�Ӧ���ַ��͡�1������9��
{
	char ch;
	ch = m + '0'; //"0"��ASCIIֵΪ48.
	return ch;
}

int main()
{
	char ch;
	int num,temp,k;
	int i = 10;
	while(i >= 0)
	{
		int j = 0;
		cout<<"����������(5λ)��";
		cin>>num;
		temp = num;
		char result[5] = {'0','0','0','0','0'};
		while(num)
		{
			k = num % 10;
			ch = exchange(k);
			result[j] = ch;
			num = num / 10;
			j++;
		}
		cout<<"����"<<temp<<"ת������ַ���Ϊ��";
		for(int m = 4; m >= 0; m--)
		{
			cout<<result[m]<<" ";
		}
		i--;
		cout<<endl;
	}
	system("pause");
	return 0;
}