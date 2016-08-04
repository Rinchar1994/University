// 1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int gotbaha(int x);
	int a;
	cout << "Please enter a even number which is lager 6" << endl;
	while(1)
	{
	    cin >> a;
    	if(a%2!=0 || a<6)
		{
			cin.clear();
	    	cout << "input error, enter again" << endl;
			continue;
		}
    	else
	    	gotbaha(a);
		break;
	}

	return 0;
}

int gotbaha(int x)
{
	int prime(int y);
	bool PRIME=true;
	int k,j;
	k=x/2;
	for(int i=2; i<=k; i++)
	{
		PRIME=prime(i);
		if(PRIME==false)
			continue;
		else
		{
			j=x-i;
			PRIME=prime(j);
			if(PRIME==false)
				continue;
			else
				cout << x << "=" << i << "+" << j << endl;
		}
	}
	
	return 0;
}

int prime(int y)
{
	bool PRIME=true;
	int k;
	k=int(sqrt(y));
	for(int i=2; i<=k; i++)
	{
		if(y%i==0)
		{
			PRIME=false;
			break;
		}
	}
	
	return PRIME;
}




