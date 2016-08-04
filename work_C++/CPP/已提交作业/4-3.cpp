// 1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int fun(int x);
	int a;
	cout << "Please enter positive integer which is lager than 2" << endl;
	while(1)
	{
	    cin >> a;
	    if(a<2)
		{
		    cin.clear();
  		    cout << "input error, enter again" << endl;
		    continue;
		}
	    else if(a==2 || a==3)
	    	cout << a << " " << "is a prime." << endl;
	    else
	    	fun(a);
	    break;
	}
	return 0;
}

int fun(int x)
{
	bool prime=true;
	int k;
	k=int(sqrt(x));
	for(int i=2; i<=k; i++)
	{
		if(x%i==0)
		{
			prime=false;
			cout << x << " " << "is not a prime." << endl;
			break;
		}
	}
	if(prime)
		cout << x << " " << "is a prime." << endl;
	return 0;
}




