//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int fun(int a);
	int n;
	cout << "Please enter a integer which belongs to [-1000000~+1000000]" << endl;
	while(1)
	{
	    cin >> n;
	    if(n>1e6 || n<-1e6)
		{
			cin.clear();
		    cout << "input error,enter again" << endl;
		    continue;
		}
    	else
		{
	    	fun(n);
			cout << endl;
		}
		break;
	}

	return 0;
}

int fun(int a)
{
	int f;
	if(a>=10 || a<=-10)
	{
		cout << fabs(a%10);
		fun(int(a/10));
	}
	else
	{
		f=fabs(a);
		cout << f;
		if(a<0)
			cout << "-";
	}
	return 0;
}