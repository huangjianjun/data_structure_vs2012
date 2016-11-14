#include<stdio.h>
int f1(int * p)//将变量地址传给形参
{
	*p = 100;
	return 0;
}
int f2(int p)
{
	p = 100;
	return 0;
}
int main()
{
	int i = 99;
	f2(i);//修改失败，因为i为局部变量。
	//f1(&i);//修改成功，地址标号在内存中唯一。
	printf("i = %d\n",i);
	getchar();

}