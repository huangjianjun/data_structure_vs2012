#include<iostream>
using namespace std;
#include<stdlib.h>
#include <time.h>

//插入排序的基本思想：通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应的位置并插入。
//插入排序非常类似于整扑克牌,在开始摸牌时，左手是空的，牌面朝下放在桌上。接着，一次从桌上摸起一张牌，并将它插入到左手一把牌中的正确位置上。为了找到这张牌的正确位置，要将它与手中已有的牌从右到左地进行比较。无论什么时候，左手中的牌都是排好序的。

int charu_sort(int *a ,int n)
{
	int j;
	int temp;//临时存储a[i]的值。
	//将a[0]自动看做有序序列，循环从1到n-1，将剩下的n-1个数依次插入到前面的有序序列a[0]到a[i-1]中
	for(int i = 1; i < n; i++)
	{
		temp = a[i];
		for(j = i; j >=0 && a[j-1] > temp; j--) //将标号i的元素算到组内即a[0]到a[i]进行插入排序。
		{
			a[j] = a[j-1];
		}
		a[j] = temp;
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
	charu_sort(a,8);
	time_t end = clock();
	cout<<"排序后:";
	for (int i=0; i<8; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	printf("the charusort running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}