//1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;
int main()
{
	int n,a,s=1,t=0,Sn=0;
	cout<<"输入a,n"<<endl;
	cin>>a>>n;
	while(s<=n)
	{
		t=(t*10)+a;
		Sn=Sn+t;
		s+=1;

	}
	cout<<"Sn="<<Sn<<endl;
	return 0;
}


