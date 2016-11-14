#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>

#define initvalue 1000
#define N 50
#define length 100

typedef struct 
{
	int parent;
	int cleft;
	int cright;
	int value;
}hmtree;

typedef struct  
{
	int bit[100];//存储编好的哈夫曼编码
	int end;//标记每个字符的哈夫曼编码在bit数组中的结束位置
}hmcode;

void hmtree_init(hmtree huffnode[], int n)
{
	int val;
	int i;
	int j;
	//根据二叉树的性质可知，具有n个叶子结点的哈夫曼树共有 2n-1 个结点
	//对开辟的2n-1个结点进行初始化，要编码的n结点存储到数组的前n个位置
	for( i = 0; i < n; i++)
	{
		printf("input node_value:");
		scanf("%d\n", &val);
		huffnode[i].value = val;
		huffnode[i].cleft = -1;
		huffnode[i].cright = -1;
		huffnode[i].parent = -1;
	}
	for(; i < 2*n-1; i++)
	{
		huffnode[i].value = 0;
		huffnode[i].cleft = -1;
		huffnode[i].cright = -1;
		huffnode[i].parent = -1;
	}

	//构造哈夫曼树，每次从有效的结点中找出权值最小的两个结点
	/* 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树 */
	int m1 , m2;
	int x1, x2;
	for( i = 0; i < n; i++)
	{
		m1 = m2 = initvalue;
		x1 = x2 = 0;
		for( j = 0; j < n+i; j++)
		{
			if (huffnode[i].value < m1 && huffnode[i].parent == -1)
			{
				m2 = m1;//若找到比m1小的值，则将m1的值赋值给m2，这是m2是第二小。
				x2 = x1;
				m1 = huffnode[i].value;
				x1 = j;
			}
			else if (huffnode[i].value < m2 && huffnode[i].parent == -1)
			{
				m2 = huffnode[i].value;
				x2 = j;
			}
		}
		//将找到的两个权值最小的两个结点进行合并
		huffnode[x1].parent = n + i;
		huffnode[x2].parent = n + i;
		huffnode[n+i].value = huffnode[x1].value + huffnode[x2].value;
		huffnode[n+i].cleft = x1;
		huffnode[n+i].cright = x2;

		//打印每次找的两个结点的权值
		printf("node[%d] = %d   node[%d] = %d\n", x1, huffnode[x1].value, x2, huffnode[x2].value);
	}		
}

int main()
{
	hmtree huffnode[N];
	hmcode huffcode[length];//存放最后的输出编码信息
	hmcode code; //定义一个临时变量来存放求解编码时的信息 
	int n;
	int i;
	int j;
	int child_index, parent_index;
	int count = 0;
	printf("please input node_number:");
	scanf("%d\n", &n);
	hmtree_init(huffnode, n);

	/*编码过程：该过程实质上就是在已建立的哈夫曼树中，从叶结点开始，沿结点的双亲链域回退到根结点，
	每回退一步，就走过了哈夫曼树的一个分支，从而得到一位哈夫曼码值。由于一个字符的哈夫曼编码是从
	根结点到相应叶结点所经过的路径上各分支所组成的 0、1 序列，因此先得到的分支代码为所求编码的低位，
	后得到的分支代码为所求编码的高位码。我们可以设置一个结构数组 HuffCode 用来存放各字符的哈夫曼编码信息，
	数组元素的结构中有两个域：bit 和 start。其中，域 bit 为一维数组，用来保存字符的哈夫曼编码， 
	start 表示该编码在数组 bit 中的开始位置。
	所以，对于第 i 个字符，它的哈夫曼编码存放在 HuffCode[i].bit 中的从 HuffCode[i].start 到 n 的 bit 位中。*/
	
	for (i = 0; i < n; i++)
	{
		child_index = i;
		parent_index = huffnode[i].parent;
		while(parent_index != -1)  /* 父结点存在 */
		{
			if (huffnode[parent_index].cleft == child_index)
				code.bit[count] = 0;
			else
				code.bit[count] = 1;
			count++;
			//设置下一次循环条件
			child_index = parent_index;
			parent_index = huffnode[parent_index].parent;
		}

		for(int k = 0; k < count; k++)
			huffcode[i].bit[k] = code.bit[k];
		huffcode[i].end = count;
	}

	//输出已保存好的所有存在编码的哈夫曼编码 
	for( i = 0; i < n; i++)
	{
		printf("%d huffman code is:\n", huffnode[i]);
		for(j = 0; j <= huffcode[i].end; j++)
		{
			printf("%d", huffcode[i].bit[j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}