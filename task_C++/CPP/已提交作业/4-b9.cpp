/* 1252366 蒋凌超 电子一班 */
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X=69;
const int MAX_Y=17;

/* 将光标移动到指定位置 */
void move(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout,coord);	
}

/* 在指定位置处打印一个指定的字符 */
void show(HANDLE hout, int X, int Y, char ch)
{
	move(hout, X, Y);
	putchar(ch);
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int    i;

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(time(0));

	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数*/
	for (i=0; i<20; i++)
		show(hout, rand()%MAX_X+1, rand()%MAX_Y+1, 'A'+rand()%26);

	/* 在此处添加需要的代码-begin */
	move(hout, MAX_X/2, MAX_Y/2);
	int x=MAX_X/2, y=MAX_Y/2;
	while(1)
	{
		char c;
		c=getch();
		if(c==76 || c==108)
		{
			x=x+1;
			if(x>69)
			{
				x=x-1;
				continue;
			}
			move(hout, x, y);
			continue;
		}
		else if(c==75 || c==107)
		{
			y=y+1;
			if(y>17)
			{
				y=y-1;
				continue;
			}
			move(hout, x, y);
			continue;
		}
		else if(c==74 || c==106)
		{
			x=x-1;
			if(x<1)
			{
				x=x=1;
				continue;
			}
			move(hout, x, y);
			continue;
		}
		else if(c==73 || c==105)
		{
			y=y-1;
			if(y<1)
			{
				y=y+1;
				continue;
			}
			move(hout, x, y);
			continue;
		}
		else if(c==81 || c==113)
		{
            move(hout, 0, 22);
			break;
		}
		else if(c==32)
		{
			show(hout, x, y, 32);
			continue;
		}
		else
			continue;
	}
	cout << "游戏结束，按任意键退出." << endl;
	getchar();
	return 0;
}
