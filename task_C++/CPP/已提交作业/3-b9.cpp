//1252366 ���賬 ����һ��
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double x,n=0,t=1,S=0;
	cout<<"��������ʵ��x"<<endl;
	cin>>x;
	while(fabs(t)>=1e-6)
	{
		S=S+t;
		n++;
		t=t*x/n;
	}
	cout<<"e��x�η��Ľ���ֵΪ��"<<setiosflags(ios::fixed)<<setprecision(6)<<S<<endl;
	return 0;
}

		
