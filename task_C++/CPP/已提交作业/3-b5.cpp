//1252366 ����һ�� ���賬
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c,S;
	cout<<"����������ʵ��a,b,c"<<endl;
	cin>>a>>b>>c;
	if(a+b>c && a+c>b && b+c>a)
	{
		S=a*b*sqrt(1-(a*a+b*b-c*c)*(a*a+b*b-c*c)/(4*a*a*b*b))/2;
		cout<<"���������S="<<S<<endl;
	}
	else
		cout<<"������� �޷�����������"<<endl;

	return 0;
}
