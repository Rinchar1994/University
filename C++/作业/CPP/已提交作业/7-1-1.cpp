//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
using namespace std;

int main()
{
	struct date {
		int year;
		int month;
		int day;
	};
	struct date a;
	int Days=0;
	int MON[12]={31,0,31,30,31,30,31,31,30,31,30,31};
	cout << "Please input the date you want." << endl;
	while(1)
	{
		cin.clear();
		cin >> a.year >> a.month >> a.day;
		if(a.year%4==0 && a.year%100!=0 || a.year%400==0)
		    MON[1]=29;
    	else
	    	MON[1]=28;
		if( a.month<1 || a.month>12 )
		{
			cout << "input error, please input again." << endl;
			continue;
		}
		else if( a.day<1 || a.day>MON[a.month-1] )
		{
			cout << "input error, please input again." << endl;
			continue;
		}
		else
			break;
	}
	for(int i=0; i<(a.month-1); i++)
    	Days=MON[i]+Days;
	Days=Days+a.day;
	cout << "The day is the " << Days << ' ' << "day." << endl;
	return 0;
}

