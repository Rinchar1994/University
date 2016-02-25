//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;

int fun(int year)
{
	if(year%4==0 && year%100!=0 || year%400==0)
		return 1;
	else
		return 0;
}

int day(int d2, int mon, int date)
{
	int i, Days=0;
	int DAY[11]={31,d2,31,30,31,30,31,31,30,31,30};
	for(i=0; i<(mon-1); i++)
		Days=DAY[i]+Days;
	if(date>DAY[mon-1] || date<1)
		return -1;
	Days=Days+date;
	return Days;
}

int main()
{
	int year, mon, date, Days, d2, leap;
	cout << "Please input the date." << endl;
	while(1)
	{
		cin >> year >> mon >> date;
		if(mon>12 || mon<1)
		{
			cout << "input error, please input again." << endl;
			continue;
		}
        leap=fun(year);
		if(leap==1)
            d2=29;
		else
			d2=28;
	    Days=day(d2, mon, date);
		if(Days<0)
		{
			cout << "input error, please input again." << endl;
			continue;
		}
		else
			break;
	}
	cout << "Today is the " << Days << " day." << endl;

	return 0;
}
