// 1252366 电子一班 蒋凌超
#include <iostream>
using namespace std;
int main()
{
	int s,a,b,c,d,e,f;
	cout<<"请输入不多于5位的正整数 s:";
	cin>>s;
    a=s/10000;
	b=s/1000-a*10;
	c=s/100-a*100-b*10;
	d=s/10-a*1000-b*100-c*10;
	e=s-a*10000-b*1000-c*100-d*10;
	cout<<a<<" "<<b<<"　"<<c<<" "<<d<<" "<<e<<endl;


	if(s/10==0)
	{
		f=e;
		cout<<"s是1位数"<<endl;
	    cout<<f<<endl;
	}
	else if(s/100==0)
	{
		f=e*10+d;
		cout<<"s是2位数"<<endl;
		cout<<f<<endl;
	}
	else if(s/1000==0)
	{
		f=e*100+d*10+c;
		cout<<"s是3位数"<<endl;
		cout<<f<<endl;
	}
	else if(s/10000==0)
	{
		f=e*1000+d*100+c*10+b;
		cout<<"s是4位数"<<endl;
		cout<<f<<endl;
	}
	else if(s/100000==0)
	{
        f=e*10000+d*1000+c*100+b*10+a;
		cout<<"s是5位数"<<endl;
		cout<<f<<endl;
	}
	else
		cout<<"输入错误"<<endl;


	return 0;
}
	

