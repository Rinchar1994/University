//1252366 ���賬 ����һ��
#include <iostream>
using namespace std;
int main()
{
	int S,a,b,c,d,e;
	cout<<"����1-30000�е�һ������"<<endl;
	cin>>S;
    a=S/10000;
	b=S/1000-a*10;
	c=S/100-a*100-b*10;
	d=S/10-a*1000-b*100-c*10;
	e=S-a*10000-b*1000-c*100-10*d;
	cout<<"��λ��"<<a<<endl;
    cout<<"ǧλ��"<<b<<endl;
	cout<<"��λ��"<<c<<endl;
	cout<<"ʮλ��"<<d<<endl;
	cout<<"��λ��"<<e<<endl;
	return 0;
}