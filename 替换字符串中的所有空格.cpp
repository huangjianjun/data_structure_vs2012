#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

void print(char *p)
{
	if (NULL == p)
	{
		printf("�ַ���ָ��Ϊ�գ�\n");
		return ;
	}
	for(int i = 0; i < strlen(p) && p[i] != '\0'; i++)
		printf("%c",p[i]);
	printf("\n");
}

//length �����ַ��������������ch ΪҪ�滻���ַ���strΪԴ�ַ���, s ��ʾҪ�滻��ch���ַ���
//˼·��1���ȱ���Դ�ַ����ҳ�Ҫ�滻���ַ��ĸ���n����Դ�ַ�����׷��n*strlen(s)���ֽڴ�С
//		2����������������p1ָ��Դ�ַ�����ĩβ��p2ָ��׷���ֽں��µĽ�β��
//		3��p1������ָ���ַ����ο�����p2������ָ���ֽڲ���ǰ�ƶ���
//			������ch�ַ�ʱ��p1++, p2�����ֽ����θ�ֵΪs����ǰ�ƶ���
//			��p2=p1ʱ���滻������
char *replace_char(char *str, int length, char ch, char *s)//�滻�ַ����е��ַ�����ո�
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