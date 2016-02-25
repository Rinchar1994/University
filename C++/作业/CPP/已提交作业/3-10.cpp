//1252366 µç×ÓÒ»°à ½¯Áè³¬
#include <iostream>
using namespace std;
int main()
{
	double x,y;
	cout<<"please enter x:";
	cin>>x;
	if(x<1)
		y=x;
	else if(x>=1 && x<10)
		y=2*x-1;
	else
		y=3*x-11;
	cout<<"y="<<y<<endl;

	return 0;
}