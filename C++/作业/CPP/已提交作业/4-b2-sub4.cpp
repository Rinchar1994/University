#include <iostream>
#include <cmath>
using namespace std;

double f4(double a, double b, double c)
{
	double x, y;
	x=(-b)/(2*a);
	y=sqrt(4*a*c-b*b)/(2*a);
	cout << "x1=" << x << '+' << y << 'i' << endl;
	cout << "x2=" << x << '-' << y << 'i' << endl;
	return 0;
}