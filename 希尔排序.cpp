#include<iostream>
using namespace std;
#include<stdlib.h>
#include <time.h>

int shell_sort(int *a, int n)
{
	int d ;
	int k;
	int temp;
	for(d = n/2; d > 0; d /= 2)  //确定希尔排序的步长（增量）值
	{
		for(int i = 0; i < d; i++) //根据步长值进行分组
		{
			for(int j = i + d; j < n; j += d)//每相隔 d 个距离取一个元素组成一组，如{a[0],a[0+d],a[2d]...}
			{
				if(a[j] < a[j-d])//每个组内进行插入排序,寻找要插入的值a[j]
				{
					temp = a[j];//记录当前找到的要插入的值（默认升序排列）
					for( k = j; a[k-d] > temp && k >= 0; k -= d)//
					{
						a[k] = a[k-d];
					}
					a[k] = temp;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int num = 0;
	int a[8] = {0};
	cout<<"<对数组元素进行赋值初始化>\n";
	for (int i = 0;i < 8; i++)
	{
		int temp;
		cout<<"a["<<i<<"]"<<" :";
		cin>>temp;
		a[i] = temp;
	}
	cout<<"---------------------------------\n";
	cout<<"排序前:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	time_t start = clock();
	shell_sort(a,8);
	time_t end = clock();
	cout<<"排序后:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	printf("the 希尔排序 running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}