//1252366 电子一班 蒋凌超
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c,S;
	cout<<"请输入三个实数a,b,c"<<endl;
	cin>>a>>b>>c;
	if(a+b>c && a+c>b && b+c>a)
	{
		S=a*b*sqrt(1-(a*a+b*b-c*c)*(a*a+b*b-c*c)/(4*a*a*b*b))/2;
		cout<<"三角形面积S="<<S<<endl;
	}
	else
		cout<<"输入错误 无法构成三角形"<<endl;

	return 0;
}
