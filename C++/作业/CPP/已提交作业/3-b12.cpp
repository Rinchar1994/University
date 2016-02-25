//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;
int main()
{
	int s,n=0,c;
	bool a1,a2,a3,a4,a5,a6,a7,a8,a9;
	for(int a=123;a<988;a++)
	{
		for(int b=a+1;(b<988 && b>a);b++)
		{
			c=1953-a-b;
			a1=a2=a3=a4=a5=a6=a7=a8=a9=0;
			s=a*1e6+b*1e3+c;
			for(int i=1;i<10;i++)
			{
				switch(s%10)
				{
				    case 1:
						a1=1;
						break;
					case 2:
						a2=1;
						break;
					case 3:
						a3=1;
						break;
					case 4:
						a4=1;
						break;
					case 5:
						a5=1;
						break;
					case 6:
						a6=1;
						break;
					case 7:
						a7=1;
						break;
					case 8:
						a8=1;
						break;
					case 9:
						a9=1;
						break;
					default:
						break;
				}
				s=s/10;
			}
			if(a1 && a2 && a3 && a4 && a5 && a6 && a7 && a8 && a9 && c>b && c<988)
			{
				n++;
				cout<<a<<" "<<b<<" "<<c<<endl;
			}
			else
				cout<<"";
		}
	}
	cout << n << endl;
	return 0;
}