#include <iostream>
using namespace std;
#include <stdlib.h>
#define  max 255 
int main()
{
	char p[max+1];
	unsigned char ch;//��ΧΪ0-255,��char ��ΧΪ-127 ~ 128��
	for(ch = 0; ch < max; ch++)// 0��ASCIIֵΪ48����ʱch����Ϊ48.
	{
		p[ch] = ch; //��ֵ��ch����p[]������Ϊchar�͵ģ�����ϵͳ�Զ�ת�����ַ� 0.
	}
	p[ch] = '\0';
	cout<<(p+48)<<endl;
	system("pause");
	return 0;
}