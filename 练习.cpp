#include <iostream>
using namespace std;
#include <stdlib.h>
#define  max 255 
int main()
{
	char p[max+1];
	unsigned char ch;//范围为0-255,若char 范围为-127 ~ 128。
	for(ch = 0; ch < max; ch++)// 0的ASCII值为48，这时ch处置为48.
	{
		p[ch] = ch; //赋值的ch由于p[]的类型为char型的，故由系统自动转换成字符 0.
	}
	p[ch] = '\0';
	cout<<(p+48)<<endl;
	system("pause");
	return 0;
}