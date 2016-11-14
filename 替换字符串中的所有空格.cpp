#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

void print(char *p)
{
	if (NULL == p)
	{
		printf("字符串指针为空！\n");
		return ;
	}
	for(int i = 0; i < strlen(p) && p[i] != '\0'; i++)
		printf("%c",p[i]);
	printf("\n");
}

//length 代表字符串的最大容量，ch 为要替换的字符，str为源字符串, s 表示要替换掉ch的字符串
//思路：1、先遍历源字符串找出要替换的字符的个数n，在源字符串后追加n*strlen(s)个字节大小
//		2、定义两个索引，p1指向源字符串的末尾，p2指向追加字节后新的结尾处
//		3、p1索引所指的字符依次拷贝给p2索引所指的字节并向前移动，
//			当遇到ch字符时，p1++, p2索引字节依次赋值为s并向前移动，
//			当p2=p1时，替换结束。
char *replace_char(char *str, int length, char ch, char *s)//替换字符串中的字符，如空格
{
	int len_str = strlen(str);
	int len_s = strlen(s);
	int n = 0;
	for(int i = 0; i < len_str; i++)
	{
		if(str[i] == ch)
			n++;
	}
	int len_newstr = len_str + n*len_s;
	if(len_newstr > length)
		return NULL;
	str[len_newstr] = '\0';
	int p1 = len_str;
	int p2 = len_newstr-2;
	while(p1 >= 0 && p2 > p1)
	{
		if(str[p1] != ch)
		{
			str[p2--] = str[p1--];
		}
		else
		{
			p1--;
			for(int i = len_s-1; i >= 0; i--)
				str[p2--] = s[i];
		}
	}
	return str;
}


#define MAX_SIZE 100
int main()
{
	char str0[MAX_SIZE] = "huang jian jun";
	char ch0 = ' ';
	char *s0 = "%20";
	char *ret = replace_char(str0, MAX_SIZE, ch0, s0);
	print(ret);
	system("pause");
	return 0;
}