//1252366 ���賬 ����һ��
#include <iostream>
using namespace std;
int main()
{
	double S,k,l;
	int a,b,c,d,e,f,g,h,i,j;
	cout<<"����0.01-1000000000"<<endl;
	cin>>S;
	a=S/1.0e9;
	b=S/1.0e8-a*10;
	c=S/1.0e7-a*100-b*10;
	d=S/1.0e6-a*1000-b*100-c*10;
	e=S/1.0e5-a*10000-b*1000-c*100-d*10;
	f=S/1.0e4-a*1.0e5-b*10000-c*1000-d*100-e*10;
	g=S/1000-a*1.0e6-b*1.0e5-c*10000-d*1000-e*100-f*10;
	h=S/100-a*1.0e7-b*1.0e6-c*1.0e5-d*10000-e*1000-f*100-g*10;
	i=S/10-a*1.0e8-b*1.0e7-c*1.0e6-d*1.0e5-e*10000-f*1000-g*100-h*10;
	j=S-a*1.0e9-b*1.0e8-c*1.0e7-d*1.0e6-e*1.0e5-f*10000-g*1000-h*100-i*10;
	k=S-a*1.0e9-b*1.0e8-c*1.0e7-d*1.0e6-e*1.0e5-f*10000-g*1000-h*100-i*10-j;
	k=int(k*10+0.00005);
	l=(S-a*1.0e9-b*1.0e8-c*1.0e7-d*1.0e6-e*1.0e5-f*10000-g*1000-h*100-i*10-j)*10-k;
	l=int(l*10+0.00005);
	cout<<"ʮ��λ��"<<a<<endl;
	cout<<"��λ��"<<b<<endl;
	cout<<"ǧ��λ��"<<c<<endl;
	cout<<"����λ��"<<d<<endl;
	cout<<"ʮ��λ��"<<e<<endl;
	cout<<"��λ��"<<f<<endl;
	cout<<"ǧλ��"<<g<<endl;
    cout<<"��λ��"<<h<<endl;
	cout<<"ʮλ��"<<i<<endl;
	cout<<"��λ��"<<j<<endl;
	cout<<"ʮ��λ��"<<k<<endl;
	cout<<"�ٷ�λ��"<<l<<endl;
	return 0;
}

