/* 1252366 ���賬 ����һ�� */
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X=69;
const int MAX_Y=17;

/* ������ƶ���ָ��λ�� */
void move(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout,coord);	
}

/* ��ָ��λ�ô���ӡһ��ָ�����ַ� */
void show(HANDLE hout, int X, int Y, char ch)
{
	move(hout, X, Y);
	putchar(ch);
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	int    i;

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������*/
	for (i=0; i<20; i++)
		show(hout, rand()%MAX_X+1, rand()%MAX_Y+1, 'A'+rand()%26);

	/* �ڴ˴������Ҫ�Ĵ���-begin */
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
	cout << "��Ϸ��������������˳�." << endl;
	getchar();
	return 0;
}
