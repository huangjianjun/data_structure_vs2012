#include<iostream>
using namespace std;
#include <stdlib.h>

//쳲��������еķǵݹ�ʵ�֣����ô������ϼ����˳�������ϵ��¼����е��ظ�����

long long fei_squeue(int n)
{
	if(n == 0 || n == 1)
		return n;
	long long one = 0;
	long long two = 1;
	long long mN = 0;
	for (int i = 2; i <= n; i++)
	{
		mN = one + two;
		one = two;
		two = mN;
	}
	return mN;
}

int main()
{
	char ch;
	int n;
	long long result = 0;
	do{
		cout<<"������쳲��������е�n:";
		cin>>n;
		result = fei_squeue(n);
		cout<<"���Ϊ��"<<result<<endl;
		cout<<"������y/n��:";
		cin>>ch;
	}while('n' != ch);
	system("pause");
	return 0;
}