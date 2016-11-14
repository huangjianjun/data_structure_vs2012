#include <iostream>
#include <stdio.h>
using namespace std;
/*汉诺（Hanoi）塔问题：古代有一个梵塔，塔内有三个座A、B、C，A座上有64个盘子，盘子大小不等，大的在下，小的在上（如图）。有一个和尚想把这64个盘子从A座移到B座，但每次只能允许移动一个盘子，并且在移动过程中，3个座上的盘子始终保持大盘在下，小盘在上。在移动过程中可以利用B座，要求打印移动的步骤。如果只有一个盘子，则不需要利用B座，直接将盘子从A移动到C。
如果有2个盘子，可以先将盘子1上的盘子2移动到B；将盘子1移动到c；将盘子2移动到c。这说明了：可以借助B将2个盘子从A移动到C，当然，也可以借助C将2个盘子从A移动到B。
如果有3个盘子，那么根据2个盘子的结论，可以借助c将盘子1上的两个盘子从A移动到B；将盘子1从A移动到C，A变成空座；借助A座，将B上的两个盘子移动到C。这说明：可以借助一个空座，将3个盘子从一个座移动到另一个。
如果有4个盘子，那么首先借助空座C，将盘子1上的三个盘子从A移动到B；将盘子1移动到C，A变成空座；借助空座A，将B座上的三个盘子移动到C。

汉诺塔的时间复杂度为2的n次方减1*/
static int step = 0;
void move ( int n, char sour, char dest )
{
    printf ( "move %d from %c to %c \n", sour, n, dest );
}

void hanoi ( int n, char sour, char temp, char dest )
{
    if ( n == 1 )
    {
        move (sour, n, dest );
        ++step;
    }
    else
    {
        hanoi ( n-1, sour, dest, temp );
        move (sour,  n, dest );
        ++step;
        hanoi ( n-1, temp, sour, dest );
    }
}
int main ( int argc, char **argv )
{
    int n ;
	char s;
	do{
		cout<<"请输入盘子总数：";
		cin>>n;
		cout<<"这里1代表最小的盘子，以此类推...\n";
		hanoi ( n, 'A', 'B', 'C' );
		printf ( "Total steps is %d\n", step );
		cout<<"是否继续运行程序?(y/n) : ";
		cin>>s;
		}while(s != 'n');
	system("pause");
    return 0;
}