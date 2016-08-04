//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
using namespace std;

struct date {
		int year;
		int month;
		int day;
		int d2;
};

int days(struct date s)
{
	int i, Days=0;
	int DAY[11]={31,0,31,30,31,30,31,31,30,31,30};
	DAY[1]=s.d2;
	for(i=0; i<(s.month-1); i++)
		Days=DAY[i]+Days;
	Days=Days+s.day;
	return Days;
}

int main()
{
	struct date a;
	int Days=0;
	int MON[12]={31,0,31,30,31,30,31,31,30,31,30,31};
	cout << "Please input the date you want." << endl;
	while(1)
	{
		cin.clear();
		cin >> a.year >> a.month >> a.day;
		if(a.year%4==0 && a.year%100!=0 || a.year%400==0)
		    a.d2=MON[1]=29;
    	else
	    	a.d2=MON[1]=28;
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
	Days=days( a );
	cout << "The day is the " << Days << ' ' << "day." << endl;
	return 0;
}