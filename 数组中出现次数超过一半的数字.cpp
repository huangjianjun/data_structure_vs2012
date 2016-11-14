#include<iostream>
using namespace std;
#include<stdlib.h>

//����˼�룺һ�����ĳ��ִ������������鳤�ȵ�һ�룬Ҳ����˵�����ֵĴ����������������ֳ��ִ������ܺͻ�Ҫ�࣬
//��ˣ����Ǳ��������ʱ�򱣴�����ֵ��1��������ֵ 2��times��������
//���ȣ��涨result = a[0];, times = 0; ����forѭ��i = 0��ʼ�������飬
//����������ֵ����һ��������ͬ����times++; ����������ֵ����һ�����ֲ�ͬ����timrs--;
//�������times����0ʱ�����ǽ��¸�������ֵa[i]��ֵ��result,�ҽ�times��ֵ����Ϊ1��
//��������Ҫ�ҵ����ֳ��ֵĴ����������������ֳ��ֵĴ���֮�ͻ�Ҫ�࣬
//��ô����Ҫ�ҵ����ֿ϶��������һ�ν�times����Ϊ1 ����Ӧ������.

bool check_more_half(int *array, int length, int result)
{
	bool flag = false;
	int sum = length / 2;
	int count = 0;
	for(int i = 0; i < length; i++)
	{
		if( array[i] == result)
			count++;
	}
	if(count > sum)
		flag = true;
	return flag;
}

int more_than_half_array(int *array, int length)
{
	if(array == NULL || length <= 0)
		return -1;
	int times = 0;
	int result = array[0];
	for(int i = 0; i < length; i++)
	{
		if(times == 0)
		{
			result = array[i];
			times = 1;
			continue;
		}
		if(array[i] == result)
			times++;
		else
			times--;
	}
	if(!check_more_half(array, length, result))
		return -2;
	return result;
}
void display(int *array, int length)
{
	if(array == NULL || length <= 0)
	{
		cout<<"����������󣬳��������"<<endl;
		return ;
	}
	for(int i = 0; i < length; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
}
void test(int *array, int length)
{
	cout<<"���������Ϊ�� ";
	display(array,length);
	int ret = more_than_half_array(array, length);
	cout<<"���ԵĽ��ֵ�� "<<ret<<endl;
}

int main()
{
	int a[11] = {1,2,3,2,2,4,5,2,2,6,2};// 2 ���ֵĴ����������鳤�ȵ�һ��
	int b[3] = {5,5,6};
	int c[18] = {8,8,8,8,8,8,8,8,5,5,5,5,5,5,5,5,5,5};
	int d[10] = {11,3,5,9,5,4,5,5,8,6};// 5 ���ֵĴ���С�����鳤�ȵ�һ��
	cout<<"----------<��������г��ִ����������鳤��һ���Ԫ��>----------\n\n";
	test(a,11);
	cout<<"\n-----------------------------------------------------\n";
	test(b,3);
	cout<<"\n-----------------------------------------------------\n";
	test(c,18);
	cout<<"\n-----------------------------------------------------\n";
	test(d,10);
	cout<<"\n-----------------------------------------------------\n";
	test(NULL, 3);
	cout<<"\n-----------------------------------------------------\n";
	system("pause");
	return 0;
}