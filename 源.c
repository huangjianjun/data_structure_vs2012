#include <stdio.h>
#include<stdlib.h>

int main()
{
	int b = 3;
	int a[] = {6,7,8,9,10};
	int *ptr = a;
	*(ptr++) += 123;
	printf("%d , %d\n", *(ptr++), *(++ptr));
	system("pause");
	return 0;
}