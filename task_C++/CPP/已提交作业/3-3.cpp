//1252366 蒋凌超 电子一班
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float c,F;
	cout<<"输入华氏温度"<<endl;
	cin>>F;
	c=5*(F-32)/9;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"摄氏温度c="<<c<<endl;
	return 0;
}
