// 1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;

int main()
{
	int Fibonacci(int n);
	int x;
	cout << "Please enter a integer" << " << x << " << "as the sequence of the items. " << endl;
	while(1)
	{
    	cin >> x;
	    if(x>46 || x<1)
		{
	    	cout << "input error,please enter again." << endl;
			continue;
		}
    	cout << "The value of the sequence is:" << Fibonacci(x) << endl;
		break;
	}

	return 0;
}

int Fibonacci(int n)
{
	if(n==1 || n==2)
		return 1;
	else
		return Fibonacci(n-1)+Fibonacci(n-2);
}


	
