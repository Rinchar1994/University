//1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;

class Days {
	private:
		int year;
		int month;
		int day;
		int is_leap_year();  //判断是否闰年，是：返回1  /   否：返回0
	public:
		int calc_days();     //计算是当年的第几天
		/* 下面可以补充其它需要的类成员函数的定义，数量不限 */
		int days( int );
		Days( int, int, int);
};

/* 此处给出类成员函数的体外实现 */
Days::Days( int y, int m, int d):year(y), month(m), day(d)
{
}

int Days::is_leap_year()
{
	return ((year%4==0) && (year%100!=0)) || (year%400==0);
}

int Days::calc_days()
{
	int d2;
	if(month>12 || month<1 || day<0)
		return -1;
    d2=28+is_leap_year();
	return days( d2 );
}

int Days::days( int d2)
{
	int i, Days=0;
	int DAY[11]={31,d2,31,30,31,30,31,31,30,31,30};
	for(i=0; i<(month-1); i++)
		Days=DAY[i]+Days;
	if(day>DAY[month-1] || day<1)
		return -1;
	Days=Days+day;
	return Days;
}
/* main函数不准动 */
int main()
{
	if (1) {
		Days d1(2012,3,18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
		}

	if (1) {
		Days d1(2011,12,31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
		}
	
	if (1) {
		Days d1(2012,12,31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
		}
		
	if (1) {
		Days d1(2011,2,29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
		}

	return 0;
}
