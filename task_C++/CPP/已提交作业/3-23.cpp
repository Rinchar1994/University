//1252366 ���賬 ����һ��
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double x=1.0,y,a;
	cout<<"����һ������a"<<endl;
	cin>>a;
	
	while(1)
	{
		y=0.5*(x+a/x)-x;
		x=0.5*(x+a/x);
		if((fabs(y))>=1e-5)
			continue;
		cout<<"a��ƽ����Ϊ"<<setiosflags(ios::fixed)<<setprecision(6)<<x<<endl;
	    break;
	}
	return 0;
}




