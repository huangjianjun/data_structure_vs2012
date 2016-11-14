#include<iostream>
using namespace std;
#include <stdlib.h>
char * Cstr(void)
{
	char b[10] = "like";
	printf("%p\n", b);
	return b;	//返回局部变量b,子函数运行结束后盖b变量的空间被释放，
}

int main(void) 
{ 
	char *a=Cstr();//指针a的值为b的一个副本值，此时的b已经无效了，所以用a来访问这块被释放的空间是非法的，该块内存已经被操作系统标记为未使用，可以被其他程序使用，但是未被其他程序占用前，上面的数据任然是b数组的值。
	printf("%p\n", a);
	printf("%c\n",*(a+1));
	printf("%c\n",*(a+2));
	system("pause");
	return 0; 
} 
