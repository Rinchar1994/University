/*1252337 电子一班 王佳琪*/
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;
const int MAX_X=26;
const int MAX_Y=10;
int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	void move(HANDLE hout, int X, int Y);
	void show(HANDLE hout, int X, int Y, char ch);
	char position[MAX_X][MAX_Y]={0};
	char lei[]={'0','1','2','3','4','5','6','7','8','9'};
	int i, j, n=0, x, y;
	srand(time(0));
	for (i=0; i<50; i++)
	{
		x=rand()%MAX_X+1;
		y=rand()%MAX_Y+1;
		if(position[x-1][y-1]==lei[9])
			i--;
		position[x-1][y-1]=lei[9];
	}
	move( hout, 0, 12);
	for(i=0; i<26; i++)
		for(j=0; j<10 ; j++)
		{
			if((int)position[i][j]==lei[9])
				continue;
			else if(i==0 && j==0)
			{
				if((int)position[i][j+1]==(int)lei[9])
					n++;
				if((int)position[i+1][j+1]==(int)lei[9])
					n++;
				if((int)position[i+1][j]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else if(i==25 && j==0)
			{
				if((int)position[i][j+1]==(int)lei[9])
					n++;
				if((int)position[i-1][j]==(int)lei[9])
					n++;
				if((int)position[i-1][j+1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else if(i==0 && j==9)
			{
				if((int)position[i][j-1]==(int)lei[9])
					n++;
				if((int)position[i+1][j]==(int)lei[9])
					n++;
				if((int)position[i+1][j-1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else if(i==25 && j==9)
			{
				if((int)position[i][j-1]==(int)lei[9])
					n++;
				if((int)position[i-1][j]==(int)lei[9])
					n++;
				if((int)position[i-1][j-1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else if(i==0)
			{
				if((int)position[i][j-1]==(int)lei[9])
					n++;
				if((int)position[i][j+1]==(int)lei[9])
					n++;
				if((int)position[i+1][j]==(int)lei[9])
					n++;
				if((int)position[i+1][j-1]==(int)lei[9])
					n++;
				if((int)position[i+1][j+1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else if(j==0)
			{
				if((int)position[i-1][j]==(int)lei[9])
					n++;
				if((int)position[i+1][j]==(int)lei[9])
					n++;
				if((int)position[i][j+1]==(int)lei[9])
					n++;
				if((int)position[i+1][j+1]==(int)lei[9])
					n++;
				if((int)position[i-1][j+1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else if(i==25)
			{
				if((int)position[i][j-1]==(int)lei[9])
					n++;
				if((int)position[i][j+1]==(int)lei[9])
					n++;
				if((int)position[i-1][j]==(int)lei[9])
					n++;
				if((int)position[i-1][j-1]==(int)lei[9])
					n++;
				if((int)position[i-1][j+1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else if(j==9)
			{
				if((int)position[i-1][j]==(int)lei[9])
					n++;
				if((int)position[i+1][j]==(int)lei[9])
					n++;
				if((int)position[i][j-1]==(int)lei[9])
					n++;
				if((int)position[i+1][j-1]==(int)lei[9])
					n++;
				if((int)position[i-1][j-1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
			else
			{
				if((int)position[i-1][j]==(int)lei[9])
					n++;
				if((int)position[i+1][j]==(int)lei[9])
					n++;
				if((int)position[i][j-1]==(int)lei[9])
					n++;
				if((int)position[i][j+1]==(int)lei[9])
					n++;
				if((int)position[i-1][j-1]==(int)lei[9])
					n++;
				if((int)position[i-1][j+1]==(int)lei[9])
					n++;
				if((int)position[i+1][j-1]==(int)lei[9])
					n++;
				if((int)position[i+1][j+1]==(int)lei[9])
					n++;
				position[i][j]=n+48;
				n=0;
			}
		}
	for( i=0; i<MAX_X; i++)
		for( j=0; j<MAX_Y; j++)
			show( hout, i+1, j+1, position[i][j]);

	return 0;
}
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