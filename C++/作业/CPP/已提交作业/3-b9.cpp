//1252366 蒋凌超 电子一班
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double x,n=0,t=1,S=0;
	cout<<"输入任意实数x"<<endl;
	cin>>x;
	while(fabs(t)>=1e-6)
	{
		S=S+t;
		n++;
		t=t*x/n;
	}
	cout<<"e的x次方的近似值为："<<setiosflags(ios::fixed)<<setprecision(6)<<S<<endl;
	return 0;
}

		
