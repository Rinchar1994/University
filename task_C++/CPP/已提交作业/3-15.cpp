//1252366 电子一班 蒋凌超
#include <iostream>
using namespace std;
int main()
{
	int m,n,a,b;
	cout<<"输入两个正整数m,n"<<endl;
	cin>>m>>n;
	if(m>n)
		a=n;
	else
		a=m;
	while(1)
	{
		if((m%a==0) && (n%a==0))
		{
			cout<<"最大公约数a="<<a<<endl;
			break;
		}
		a=a-1;
	}
	if(m>n)
		b=m;
	else
		b=n;
	while(1)
	{
		if((b%m==0) && (b%n==0))
		{
			cout<<"最小公倍数b="<<b<<endl;
			break;
		}
		b=b+1;
	}

	return 0;
}


