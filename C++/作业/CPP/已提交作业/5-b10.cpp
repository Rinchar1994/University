//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

const int MAX_X=52;
const int MAX_Y=10;
char symbol[]={'0','1','2','3','4','5','6','7','8','*'};

void move(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout,coord);	
}

void show(HANDLE hout, int X, int Y, char ch)
{
	move(hout, X, Y);
	putchar(ch);
}

int main()
{
	char a[MAX_X][MAX_Y]={'\0'};
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, m, n, num=0;
	srand(time(0));
	for (i=0; i<50; i++)
	{
		m=(rand()%(MAX_X/2))*2+1;
		n=rand()%MAX_Y+1;
		if(a[m-1][n-1]==symbol[9])
			i--;
		show(hout, m, n, symbol[9]);
		show(hout, m+1, n, 0);
		a[m-1][n-1]=symbol[9];
	}
	for(i=0; i<26; i++)
		for(j=0; j<10 ; j++)
		{
			if((int)a[2*i][j]==(int)symbol[9])
				continue;
			else if(i==0 && j==0)
			{
				if((int)a[0][1]==(int)symbol[9])
					num++;
				if((int)a[2][1]==(int)symbol[9])
					num++;
				if((int)a[2][0]==(int)symbol[9])
					num++;
				show(hout, i+1, j+1, symbol[num]);
				show(hout, i+2, j+1, 0);
				num=0;
			}
			else if(i==25 && j==0)
			{
				if((int)a[50][1]==(int)symbol[9])
					num++;
				if((int)a[48][1]==(int)symbol[9])
					num++;
				if((int)a[48][0]==(int)symbol[9])
					num++;
				show(hout, 2*i+1, j+1, symbol[num]);
				show(hout, 2*i+2, j+1, 0);
				num=0;
			}
			else if(i==25 && j==9)
			{
				if((int)a[50][8]==(int)symbol[9])
					num++;
				if((int)a[48][9]==(int)symbol[9])
					num++;
				if((int)a[48][8]==(int)symbol[9])		
					num++;
				show(hout, 2*i+1, j+1, symbol[num]);
				show(hout, 2*i+2, j+1, 0);
				num=0;
			}
			else if(i==0 && j==9)
			{
				if((int)a[0][8]==(int)symbol[9])
					num++;
				if((int)a[2][9]==(int)symbol[9])
					num++;
				if((int)a[2][8]==(int)symbol[9])
					num++;
				show(hout, i+1, j+1, symbol[num]);
				show(hout, i+2, j+1, 0);
				num=0;
			}
			else if(i==0)
			{
				if((int)a[0][j-1]==(int)symbol[9])
					num++;
				if((int)a[0][j+1]==(int)symbol[9])
					num++;
				if((int)a[2][j]==(int)symbol[9])
					num++;
				if((int)a[2][j-1]==(int)symbol[9])
					num++;
				if((int)a[2][j+1]==(int)symbol[9])
					num++;
				show(hout, i+1, j+1, symbol[num]);
				show(hout, i+2, j+1, 0);
				num=0;
			}
			else if(i==25)
			{
				if((int)a[50][j-1]==(int)symbol[9])
					num++;
				if((int)a[50][j+1]==(int)symbol[9])
					num++;
				if((int)a[48][j]==(int)symbol[9])
					num++;
				if((int)a[48][j-1]==(int)symbol[9])
					num++;
				if((int)a[48][j+1]==(int)symbol[9])
					num++;
				show(hout, 2*i+1, j+1, symbol[num]);
				show(hout, 2*i+2, j+1, 0);
				num=0;
			}
			else if(j==0)
			{
				if((int)a[2*i-2][0]==(int)symbol[9])
					num++;
				if((int)a[2*i+2][0]==(int)symbol[9])
					num++;
				if((int)a[2*i][1]==(int)symbol[9])
					num++;
				if((int)a[2*i+2][1]==(int)symbol[9])
					num++;
				if((int)a[2*i-2][1]==(int)symbol[9])
					num++;
				show(hout, 2*i+1, j+1, symbol[num]);
				show(hout, 2*i+2, j+1, 0);
				num=0;
			}
			else if(j==9)
			{
				if((int)a[2*i-2][9]==(int)symbol[9])
					num++;
				if((int)a[2*i+2][9]==(int)symbol[9])
					num++;
				if((int)a[2*i][8]==(int)symbol[9])
					num++;
				if((int)a[2*i+2][8]==(int)symbol[9])
					num++;
				if((int)a[2*i-2][8]==(int)symbol[9])
					num++;
				show(hout, 2*i+1, j+1, symbol[num]);
				show(hout, 2*i+2, j+1, 0);
				num=0;
			}
			else
			{
				if((int)a[2*i-2][j]==(int)symbol[9])
					num++;
				if((int)a[2*i+2][j]==(int)symbol[9])
					num++;
				if((int)a[2*i][j-1]==(int)symbol[9])
					num++;
				if((int)a[2*i][j+1]==(int)symbol[9])
					num++;
				if((int)a[i*2-2][j-1]==(int)symbol[9])
					num++;
				if((int)a[i*2-2][j+1]==(int)symbol[9])
					num++;
				if((int)a[i*2+2][j-1]==(int)symbol[9])
					num++;
				if((int)a[i*2+2][j+1]==(int)symbol[9])
					num++;
				show(hout, 2*i+1, j+1, symbol[num]);
				show(hout, 2*i+2, j+1, 0);
				num=0;
			}
		}
		move( hout, 0, 15);

	return 0;
}

