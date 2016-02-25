//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
using namespace std;

int main()
{
	cout << "Please input the month." << endl;
	char *mon[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int n;
	while(1)
	{
		cin >> n;
		if(n<=0 || n>12)
		{
			cout << "Invalid" << endl;
			continue;
		}
		else
			break;
	}
	cout << mon[n-1] << endl;
	return 0;
}