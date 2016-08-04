//1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;
int main()
{
	int S,a,b,c,d,e;
	cout<<"输入1-30000中的一个整数"<<endl;
	cin>>S;
    a=S/10000;
	b=S/1000-a*10;
	c=S/100-a*100-b*10;
	d=S/10-a*1000-b*100-c*10;
	e=S-a*10000-b*1000-c*100-10*d;
	cout<<"万位："<<a<<endl;
    cout<<"千位："<<b<<endl;
	cout<<"百位："<<c<<endl;
	cout<<"十位："<<d<<endl;
	cout<<"个位："<<e<<endl;
	return 0;
}