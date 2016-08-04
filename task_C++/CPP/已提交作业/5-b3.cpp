//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int item(int x, int y);
	int str[10];
	int n=40;
	for(int i=1; i<11; i++)
	{
		for(int j=1; j<=i ;j++)
		{
			str[j-1]=item(i,j);
			if(j==1)
			{
				n=n-4;
				cout<< setw(n) << str[j-1];
			}
			else
			    cout << setw(8) << str[j-1];
		}
		cout << endl;
	}

	return 0;
}

int item(int x, int y)
{
	int m=1,n=1;
	if(x==1 || y==1 || y==x)
		return 1;
	else if(y<=x/2)
	{
		for(int k=1; k<=(y-1); k++)
		{
			x=x-1;
			n=x*n;
            m=k*m;
		}
		return n/m;
	}
	else if((x+1-y)<=x/2)
		return (item( x, x+1-y));
	else
		return item( x-1, y-1)*2;
}