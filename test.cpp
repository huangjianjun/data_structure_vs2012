#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//快速排序 。。。。。 升序排列
int findpos(int *a, int low, int high)
{
	int val = a[low];
	while(low < high)//low与high相等的话就停止
	{
		while(low < high && a[high] >= val)  //low与high相等的话就停止，防止数组下标越界。
			high--;
		a[low++] = a[high];//此时的a[high]相当于小于val，所以复制给a[low]的话就不必进行小于val的判断了
		while(low < high && a[low] <= val) //low与high相等的话就停止，防止数组下标越界。
			low++;
		a[high--] = a[low];//与上面的++是同理的。
	}
	a[low] = val;  //此时，low 和 high 标号相等，且为val在排序后的确切标号。
	return low; //之后序列以val所对应的位置分为两个子序列，利用递归对子序列进行排序。
}

void quitesort(int *a, int low, int high)
	//low 表示数组的首元素下标，high表示数组的尾元素下标
{
	int pos;
	if( NULL == a || low > high)
	{
		cout<<"所给参数不符合要求，程序退出！"<<endl;
		return ;
	}
	if (low < high)//仅当区间长度大于1时才需要排序
	{
		pos = findpos(a,low,high);
		cout<<"pos = "<<pos<<endl;
		quitesort(a,low,pos-1);
		quitesort(a,pos+1,high);
	}
}



int main()
{
	int a[5] = {0};
	cout<<"<对数组元素进行赋值初始化>\n";
	for (int i = 0;i < 5; i++)
	{
		int temp;
		cout<<"a["<<i<<"]"<<" :";
		cin>>temp;
		a[i] = temp;
	}
	cout<<"---------------------------------\n";
	cout<<"排序前:";
	for (int i=0; i<5; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	time_t start = clock();
	quitesort(a,0,4);
	time_t end = clock();
	cout<<"排序后:";
	for (int i=0; i<5; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	printf("the quicksort running time is : %f\n", double(end -start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
