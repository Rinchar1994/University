//1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;
int main()
{
	double x;
	int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0,n;
	cout<<"输入消费金额（100以内）x"<<endl;
	cin>>x;
	for(;x>=50;n1++)
		x=x-50;
	for(;x>=20 && x<50;n2++)
		x=x-20;
	for(;x>=10 && x<20;n3++)
		x=x-10;
	for(;x>=5 && x<10;n4++)
		x=x-5;
	for(;x>=1 && x<5;n5++)
		x=x-1;
	for(;x>=0.5 && x<1;n6++)
		x=x-0.5;
	for(;x>=0.1 && x<0.5;n7++)
		x=x-0.1;
	for(;x>=0.05 && x<0.1;n8++)
		x=x-0.05;
	for(;x>=0.02 && x<0.05;n9++)
		x=x-0.02;
	for(;x>=0.01 && x<0.05;n10++)
		x=x-0.01;
	n=n1+n2+n3+n4+n5+n6+n7+n8+n9+n10;
	cout<<"总数量为"<<n<<",具体为 ";
	if(n1==0)
		cout<<"";
	else
	    cout<<"50 元x"<<n1<<" ";
	if(n2==0)
		cout<<"";
	else
	    cout<<"20 元x"<<n2<<" ";
	if(n3==0)
		cout<<"";
	else
    	cout<<"10 元x"<<n3<<" ";
	if(n4==0)
		cout<<"";
	else
	    cout<<"5 元x"<<n4<<" ";
	if(n5==0)
		cout<<"";
	else
    	cout<<"1 元x"<<n5<<" ";
	if(n6==0)
		cout<<"";
	else
    	cout<<"5 角x"<<n6<<" ";
	if(n7==0)
		cout<<"";
	else
    	cout<<"1 角x"<<n7<<" ";
	if(n8==0)
		cout<<"";
	else
	    cout<<"5 分x"<<n8<<" ";
	if(n9==0)
		cout<<"";
	else
    	cout<<"2 分x"<<n9<<" ";
	if(n10==0)
		cout<<""<<endl;
	else
    	cout<<"1 分x"<<n10<<" "<<endl;
	return 0;
}






