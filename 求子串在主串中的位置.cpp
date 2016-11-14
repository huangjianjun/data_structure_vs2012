#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int substr_index(char *str, char *sub)
{
	int strlength = strlen(str);
	int sublen = strlen(sub);
	int m = 0;
	int count = 0;
	int flag = 0;
	if(NULL == str || NULL == sub || strlen(sub) > strlen(str))
		return -1;
	for(int j = 0; j <= strlength - sublen; j++)
	{
		if(sub[m] == str[j])
		{
			for(int k = j+1; k <= j + sublen && j + sublen <= strlength; k++)
			{
				if(str[k] == sub[++m])
				{
					count++;
				}
				if(count == sublen-1)
				{
					flag = 1;
					return j;
				}
			}
			count = 0;
			m = 0;
		}
	}
	if (flag == 0)
		return -1;
}

int main()
{
	char *str = "abcdefgh";
	char *sub = "chd";
	int ret = substr_index(str, sub);
	cout<<"ret = "<<ret<<endl;
	system("pause");
	return 0;
}
