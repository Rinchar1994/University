//1252366 ����һ�� ���賬
#include <iostream>
#include <iomanip>
#define pi 3.1415926
using namespace std;
int main()
{
	float r=1.5,h=3,L,S1,S2,V1,V2;
	L=2*pi*r;
	S1=pi*r*r;
	S2=4*pi*r*r;
	V1=4*pi*r*r*r/3;
	V2=pi*r*r*h;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Բ�ܳ�L="<<L<<endl;
	cout<<"Բ���S1="<<S1<<endl;
	cout<<"Բ������S2="<<S2<<endl;
	cout<<"Բ�����V1="<<V1<<endl;
	cout<<"Բ�����V2="<<V2<<endl;
	return 0;
}
    
