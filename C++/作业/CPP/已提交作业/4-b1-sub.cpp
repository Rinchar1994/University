#include <iostream>
#include <cmath>
using namespace std;

double f1(double a, double b, double c)
{
	double x;
	x=c/b;
	cout << "x=" << x << endl;
	return 0;
}

double f2(double a, double b, double c)
{
	double x1, x2;
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
	return 0;
}

double f3(double a, double b, double c)
{
	double x;
	x=(-b)/(2*a);
	cout << "x=" << x << endl;
	return 0;
}

double f4(double a, double b, double c)
{
	double x, y;
	x=(-b)/(2*a);
	y=sqrt(4*a*c-b*b)/(2*a);
	cout << "x1=" << x << '+' << y << 'i' << endl;
	cout << "x2=" << x << '-' << y << 'i' << endl;
	return 0;
}