//1252366 蒋凌超 电子一班
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double x=1.0,y,a;
	cout<<"输入一个正数a"<<endl;
	cin>>a;
	
	while(1)
	{
		y=0.5*(x+a/x)-x;
		x=0.5*(x+a/x);
		if((fabs(y))>=1e-5)
			continue;
		cout<<"a的平方根为"<<setiosflags(ios::fixed)<<setprecision(6)<<x<<endl;
	    break;
	}
	return 0;
}




