//1252366 电子一班 蒋凌超
#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,A,B,C,D;
	cout<<"输入四个整数";
	cin>>a>>b>>c>>d;
	if(a>=b)
	{
		A=a;
		B=b;
	}
	else
	{
		A=b;
		B=a;
	}
	if(c>=d)
	{
		C=c;
		D=d;
	}
	else
	{
		C=d;
		D=c;
	}
	if(B>=C)
		cout<<D<<" "<<C<<" "<<B<<" "<<A<<endl;
	else if(B>=D && A>=C)
		cout<<D<<" "<<B<<" "<<C<<" "<<A<<endl;
	else if(A>=C && B<=D)
		cout<<B<<" "<<D<<" "<<C<<" "<<A<<endl;
	else if(D>=A)
		cout<<B<<" "<<A<<" "<<D<<" "<<C<<endl;
	else if(C>=A && B>=D)
		cout<<D<<" "<<B<<" "<<A<<" "<<C<<endl;
	else if(C>=A && B<=D)
		cout<<B<<" "<<D<<" "<<A<<" "<<C<<endl;

	return 0;
}




