// 1252366 ����һ�� ���賬
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x1,x2,x3,y1,y2,y3,a,b,c,p,S;
	cout<<"���������������(x1,y1)��(x2,y2)��(x3,y3)"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;

	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	if(a+b>c && a+c>b && b+c>a)
	{
		p=(a+b+c)/2;
		S=sqrt(p*(p-a)*(p-b)*(p-c))/2;
		cout<<"���������S="<<S<<endl;
	}
	else
		cout<<"������� ���ܹ���������"<<endl;

	return 0;
}


