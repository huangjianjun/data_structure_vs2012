#include<stdio.h>
void show_array(int array[] , int n)
{
	printf("\n");
	printf("数组标号形式访问数组：");
	for (int i = 0;i <n;i ++)
	{
		printf("%d\t",array[i]);
	}
}
void show_array_point(int * p , int len)
{
	printf("\n");
	printf("指针形式访问数组：");
	for (int i = 0;i <len;i ++)
	{
		printf("%d\t",*(p + i)); 
	}
}
int main()
{
	int a[5] = {6,2,3,4,5};//数组的内存单元是连续的。
	//a[3] == *(a + 3) a代表第一个元素的地址，a+3 可以看做是3个int偏移量。
	printf("a 的内存地址为：%p\n",a);
	printf("a+1 的内存地址为：%p\n",a+1);
	printf("a+2 的内存地址为：%p\n",a+2);
	printf("a+3 的内存地址为：%p\n",a+3);
	printf("a+4 的内存地址为：%p\n",a+4);
	printf("*(a+3) = %d\n",*(a+3));
	printf("*a +3 = %d\n",*a +3);//等价于a[0] + 3
	show_array(a , 5);
	show_array_point(a,5);
	getchar();
	return 0;
}
//通过函数修改变量的值只能传其地址给该函数！！！