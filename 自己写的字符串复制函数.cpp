#include <iostream>
using namespace std;
#include <stdlib.h>

char* my_strcpy(char *des, char* res)
{
	char * buff = des;
	char ch;
	if(NULL == des || NULL == res)
		return NULL;
	while((ch = *res++) != '\0')
	{
		*(des++) = ch;
	}
	*des = '\0';
	return buff;
}

void func()
{
	char s[] = "123456789";
	char des[10] = "1234";
	char *addr = my_strcpy(des,s);
	cout<<"des:"<<des<<endl;
	cout<<"  s:"<<s<<endl;
}

//下面是拷贝函数的完整的标准写法
char* strcpy_stand(char *to, char *from)
{
	char *temp = to;
	if(NULL == to || NULL == from) return NULL;
	while( *from != '\0')
	{
		*to++ = *from++;
	}
	*to = '\0';
	return temp;
}
int main()
{
	char s[10] = "hello";
	char *d = (char *)malloc(50*sizeof(char));
	d = my_strcpy(d,s);
	cout<<d<<endl;
	func();
	cout<<"\n----- 对strcpy_stand()的测试--------"<<endl;
	char *f = (char *)malloc(50*sizeof(char));
	char *t = (char *)malloc(50*sizeof(char));
	d = strcpy_stand(f,"huang jian jun");
	d = strcpy_stand(t,"liu jing");
	cout<<"f:"<<f<<" ->"<<strlen(f)<<endl;
	cout<<"t:"<<t<<" ->"<<strlen(t)<<endl;
	cout<<"d:"<<d<<" ->"<<strlen(d)<<endl;
	d = strcpy_stand(t,f);
	cout<<"f:"<<f<<" ->"<<strlen(f)<<endl;
	cout<<"t:"<<t<<" ->"<<strlen(t)<<endl;
	cout<<"d:"<<d<<" ->"<<strlen(d)<<endl;
	system("pause");
	return 0;

}