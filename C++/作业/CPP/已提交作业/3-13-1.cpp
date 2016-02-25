//1252366 电子一班 蒋凌超
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double i,w;
	cout<<"please enter i:";
	cin>>i;
	if(i<=0)
	{
		cout<<"输入错误"<<endl;
	}
	if(i<=1e5 && i>0)
	{
		w=0.1*i;
	}
	if(i<=2e5 && i>1e5)
	{
		w=1e4+(i-1e5)*0.075;
	}
	if(i<=4e5 && i>2e5)
	{
		w=17500+(i-2e5)*0.05;
	}
	if(i<=6e5 && i>4e5)
	{
		w=27500+(i-4e5)*0.03;
	}
	if(i<=1e6 && i>6e5)
	{
		w=33500+(i-6e5)*0.015;
	}
	if(i>1e6)
	{
		w=39500+(i-1e6)*0.01;
	}
	cout<<"总奖金数为："<<setiosflags(ios::fixed)<<setprecision(2)<<w<<endl;

	return 0;
}
