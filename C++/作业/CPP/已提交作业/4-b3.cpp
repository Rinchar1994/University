// 1252366 蒋凌超 电子一班
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c;
int main()
{
	double f1(double , double , double );
	double f2(double , double , double );
	double f3(double , double , double );
	double f4(double , double , double );

	cout << "输入实数a,b,c" << endl;
	while(1)
	{
    	cin >> a >> b >> c;
	    if(a==0)
		{
 	    	if(b==0 && c!=0)
			{
		    	cout << "方程无解,请重新输入" << endl;
		    	continue;
			}
		    else if(b==0 && c==0)
		    	cout << "方程有无数解" << endl;
	    	else
		    	f1( a, b, c);
			break;
		}
    	else if(b*b-4*a*c>0)
    		f2( a, b, c);
		else if(b*b-4*a*c==0)
	    	f3( a, b, c);
    	else
	    	f4( a, b, c);
		break;
	}

	return 0;
}

double f1(double , double , double )
{
	double x;
	x=c/b;
	cout << "x=" << x << endl;
	return 0;
}

double f2(double , double , double )
{
	double x1, x2;
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
	return 0;
}

double f3(double , double , double )
{
	double x;
	x=(-b)/(2*a);
	cout << "x=" << x << endl;
	return 0;
}

double f4(double , double , double )
{
	double x, y;
	x=(-b)/(2*a);
	y=sqrt(4*a*c-b*b)/(2*a);
	cout << "x1=" << x << '+' << y << 'i' << endl;
	cout << "x2=" << x << '-' << y << 'i' << endl;
	return 0;
}
