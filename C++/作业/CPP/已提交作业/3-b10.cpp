//1252366 ���賬 ����һ��
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double a,b,t,y;
	for(a=0,b=1.0;fabs(y)>=1e-5;)
	{
		t=(a+b)/2;
		y=2*t*t*t-9*t*t+12*t-3;
		if(y<0)
			a=t;
		else
			b=t;
	}
	cout<<"���̵ĸ�Ϊ��"<<setiosflags(ios::fixed)<<setprecision(6)<<t<<endl;
	return 0;
}
