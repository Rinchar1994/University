//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int c;
	for(int b=1;b<=9;b++)
	{
		for(int a=1;a<=b;a++)
		{
			c=a*b;
			printf("%dx%d=%-3d",a,b,c);
		}
		cout<<endl;
	}
	return 0;
}
