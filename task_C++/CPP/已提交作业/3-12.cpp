// 1252366 ����һ�� ���賬
#include <iostream>
using namespace std;
int main()
{
	int s,a,b,c,d,e,f;
	cout<<"�����벻����5λ�������� s:";
	cin>>s;
    a=s/10000;
	b=s/1000-a*10;
	c=s/100-a*100-b*10;
	d=s/10-a*1000-b*100-c*10;
	e=s-a*10000-b*1000-c*100-d*10;
	cout<<a<<" "<<b<<"��"<<c<<" "<<d<<" "<<e<<endl;


	if(s/10==0)
	{
		f=e;
		cout<<"s��1λ��"<<endl;
	    cout<<f<<endl;
	}
	else if(s/100==0)
	{
		f=e*10+d;
		cout<<"s��2λ��"<<endl;
		cout<<f<<endl;
	}
	else if(s/1000==0)
	{
		f=e*100+d*10+c;
		cout<<"s��3λ��"<<endl;
		cout<<f<<endl;
	}
	else if(s/10000==0)
	{
		f=e*1000+d*100+c*10+b;
		cout<<"s��4λ��"<<endl;
		cout<<f<<endl;
	}
	else if(s/100000==0)
	{
        f=e*10000+d*1000+c*100+b*10+a;
		cout<<"s��5λ��"<<endl;
		cout<<f<<endl;
	}
	else
		cout<<"�������"<<endl;


	return 0;
}
	

