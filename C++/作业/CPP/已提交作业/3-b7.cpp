// 1252366 电子一班 蒋凌超
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c,d,h,x1,x2;
	cout<<"输入实数a,b,c"<<endl;
	cin>>a>>b>>c;
	h=b*b-4*a*c;
	if(fabs(a-0)<1e-6)
	{
		x1=-c/b;
	    cout<<"x1="<<x1<<endl;
	}
	else if(h>0)
	{
		x1=(-b+sqrt(h))/(2*a);
		x2=(-b-sqrt(h))/(2*a);
		cout<<"x1="<<x1<<endl;
		cout<<"x2="<<x2<<endl;
	}
	else if(fabs(h-0)<1e-6)
	{
		x1=-b/(2*a);
		cout<<"x1="<<x1<<endl;
	}
	else if(h<0)
	{
		x1=-b/(2*a);
		x2=-b/(2*a);
        d=sqrt(-h)/(2*a);
		cout<<"x1="<<x1<<"+"<<d<<'i'<<endl;
		cout<<"x2="<<x2<<"-"<<d<<'i'<<endl;
	}

	return 0;
}
		
