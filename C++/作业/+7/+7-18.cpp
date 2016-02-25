/* 1252337 王佳琪 电子一班 */
#include <iostream.h>
#include <conio.h>
//using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;
	public:
	/* 根据需要定义所需的成员函数、友元函数等 */
		Date (){year=2000;month=1;day=1;}
		Date (int y,int m,int d);
		void show();
		void set(int y,int m,int d);
    	void set(int y,int m);
		void set(int y);
		void get(int &y,int &m,int &d);
		Date (int sum);
		operator int ();
		friend ostream&operator <<(ostream&,Date&);
		friend istream&operator >>(istream&,Date&);
		friend int operator - (Date &c1,Date &c2);
        friend Date operator - (Date &c1,int c2);
		friend Date operator + (Date &c1,int c2);
		friend Date operator + (int c2,Date &c1);
        friend Date operator ++ (Date &c1);
		friend Date operator ++ (Date &c1,int);
		friend Date operator -- (Date &c1);
		friend Date operator -- (Date &c1,int);
		friend bool operator >(Date &c1,Date &c2);
		friend bool operator >=(Date &c1,Date &c2);	
		friend bool operator <(Date &c1,Date &c2);
		friend bool operator <=(Date &c1,Date &c2);
		friend bool operator !=(Date &c1,Date &c2);
		friend bool operator ==(Date &c1,Date &c2);
	
		
};

/* 定义的成员函数、友元函数的实现部分 */
Date::Date(int y,int m,int d)
{
	if (y>=1900&&y<=2099)
		year=y;
	else if (year!=0)
	    year=2000;
	int mon[13]={0,31,28+((year%4==0&&year%100!=0)||(year%400==0)),31,30,31,30,31,31,30,31,30,31};
	if (m<=12&&m>=1)
		month=m;
	else if (m!=0)
		month=1;
	int D;
	D=mon[month];
	if(d>=1&&d<=D)
		day=d;
	else if(d!=0)
		day=1;
}

void Date::show()
{
	cout<<year<<"."<<month<<"."<<day<<"."<<endl;
}

void Date::set(int y,int m,int d)
{
	if (y>=1900&&y<=2099)
		year=y;
	else if (y!=0)
	    year=2000;
	
	int mon[13]={0,31,28+((year%4==0&&year%100!=0)||(year%400==0)),31,30,31,30,31,31,30,31,30,31};
	if (m<=12&&m>=1)
		month=m;
	else if (m!=0)
		month=1;
	int D;
	D=mon[month];
	if(d>=1&&d<=D)
		day=d;
	else if(d!=0)
		day=1;
}

void Date::set(int y,int m)
{
	day=1;
	if (y>=1900&&y<=2099)
		year=y;
	else if (year!=0)
	    year=2000;
	int mon[13]={0,31,28+((year%4==0&&year%100!=0)||(year%400==0)),31,30,31,30,31,31,30,31,30,31};
	if (m<=12&&m>=1)
		month=m;
	else if (m!=0)
		month=1;
}

void Date::set(int y)
{
	month=1;
	day=1;
	if (y>=1900&&y<=2099)
		year=y;
	else if (year!=0)
	    year=2000;
	
}

void Date ::get(int &y,int &m,int &d)
{
	y=year;
	m=month;
	d=day;
}

Date::Date(int sum)
{
	year=1900;
	month=1;
	day=1;
	if (sum<=1)
	{
		year =1900;
		month =1;
		day =1;
	}
	else if(sum>=73094)
	{
		year=2099;
		month=12;
		day=31;
	}
	else 
	{
		
		for (;(sum-365-((year%4==0&&year%100!=0)||(year%400==0)))>0;)
		{
		    year+=1;
			sum=sum-365-((year%4==0&&year%100!=0)||(year%400==0));
			
		}
		int mon[13]={0,31,28+((year%4==0&&year%100!=0)||(year%400==0)),31,30,31,30,31,31,30,31,30,31};
		
		for (;sum-mon[month]>0;)
		{
			
			sum=sum-mon[month];
			month+=1;
			if (month>12)
			{

				year+=1;
				month-=12;
			}
		}
		day=sum;
	}
	if (year>2099)
	{
		year =2099;
		month =12;
		day =31;
	}
	if (year <1900)
	{
		year =1900;
		month =1;
		day=1;
	}
}

Date ::operator int ()
{

	int sum=0;
	int mon[13]={0,31,28+((year%4==0&&year%100!=0)||(year%400==0)),31,30,31,30,31,31,30,31,30,31};
	for(int i=1;i<month;i++)
		sum=sum+mon[i];
	sum+=day;
	for(i=1900;i<year;i++)
		sum+=365+((i%4==0&&i%100!=0)||(i%400==0));
	return sum;
}



ostream&operator <<(ostream&output,Date&c)
{
	output<<c.year<<"."<<c.month<<"."<<c.day<<endl;
	return output;
}
istream&operator >>(istream&input,Date&c)
{
	
	input>>c.year>>c.month>>c.day;
    if (c.year>=1900&&c.year<=2099)
		c.year=c.year;
	else c.year=2000;
	int mon[13]={0,31,28+((c.year%4==0&&c.year%100!=0)||(c.year%400==0)),31,30,31,30,31,31,30,31,30,31};
	if (c.month<=12&&c.month>=1)
		c.month=c.month;
	else c.month=1;
	int D;
	D=mon[c.month];
	if(c.day>=1&&c.day<=D)
		c.day=c.day;
	else c.day=1;
	return input;
}

int  operator - (Date &c1,Date &c2)
{
	int a=int (c1);
	int b=int (c2);
	return a-b;
}

			
Date operator - (Date &c1,int c2)
{
	int a=int(c1);
    int b=a-c2;
	return Date(b);
}

Date operator + (Date &c1,int c2)
{
	int a=int(c1);
	int b=a+c2;
	return Date(b);
}

Date operator + (int c2,Date &c1)
{
	int a=int(c1);
	int b=a+c2;
	return Date(b);
}

Date operator ++ (Date&c1)
{
    int a=int(c1);
    a++;
	c1=Date(a);
    return c1;
}
Date operator ++ (Date&c1,int)
{
    Date b(c1);
    int a= c1.operator int();
    a=a+1;
	c1=Date(a);
    return b;
}
Date operator -- (Date&c1)
{
    int a=int(c1);
    a=a-1;
	c1=Date (a);
    return c1;
}
Date operator -- (Date&c1,int )
{
	Date b(c1);
    int a= c1.operator int();
	a--;
    c1=Date(a);
    return b;
}


bool operator >(Date &c1,Date &c2)
{
	int a=int(c1);
	int b=int(c2);
	if (a>b)
		return true;
	else return false;
}
bool operator >=(Date &c1,Date &c2)	
{
	int a=int(c1);
	int b=int(c2);
	if (a>=b)
		return true;
	else return false;
}
bool operator <(Date &c1,Date &c2)
{
	int a=int(c1);
	int b=int(c2);
	if (a<b)
		return true;
	else return false;
}
bool operator <=(Date &c1,Date &c2)
{
	int a=int(c1);
	int b=int(c2);
	if (a<=b)
		return true;
	else return false;
}
bool operator !=(Date &c1,Date &c2)
{
	int a=int(c1);
	int b=int(c2);
	if (a!=b)
		return true;
	else return false;
}
bool operator ==(Date &c1,Date &c2)
{
	int a=int(c1);
	int b=int(c2);
	if (a==b)
		return true;
	else return false;
}


/* ----main函数不准动---- */
int main()
{
	/*if (1) {
		Date d1;             //2000.1.1
		Date d2(2013,5,29);  //2013.5.29
		
		cout << "测试初始化，完全正确的赋值" << endl;

		cout << "d1应该是2000.1.1， 实际为：";
		d1.show();
		cout << "d2应该是2013.5.29，实际为：";
		d2.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1870,3,15);  //2000.3.15
		Date d2(2112,3,4);   //2000.3.4
		Date d3(2005,13,15); //2005.1.15
		Date d4(2008,5,32);  //2008.5.1
		
		cout << "测试初始化，年、月、日非法" << endl;

		cout << "d1应该是2000.3.15，实际为：";
		d1.show();
		cout << "d2应该是2000.3.4， 实际为：";
		d2.show();
		cout << "d3应该是2005.1.15，实际为：";
		d3.show();
		cout << "d4应该是2008.5.1， 实际为：";
		d4.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
	    Date d1(2011,2,29);   //2011.2.1
	    Date d2(2012,2,29);   //2012.2.29

		cout << "测试初始化，闰年" << endl;

		cout << "d1应该是2011.2.1， 实际为：";
		d1.show();
		cout << "d2应该是2012.2.29，实际为：";
		d2.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1, d2, d3; //都是2000.1.1

		cout << "测试set，带缺省值" << endl;
		d1.set(2013,5,29);	//2013.5.29
		d2.set(2013,5);		//2013.5.1
		d3.set(2013);		//2013.1.1

		cout << "d1应该是2013.5.29，实际为：";
		d1.show();
		cout << "d2应该是2013.5.1， 实际为：";
		d2.show();
		cout << "d3应该是2013.1.1， 实际为：";
		d3.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2(2013,5,29);
		Date d3(2013,5,29);

		cout << "测试set，部分不变" << endl;

		d1.set(2007,0,0);   //2007.5.29
		d2.set(0, 3, 18);   //2013.3.18
		d3.set(0, 0, 18);   //2013.5.18

		cout << "d1应该是2007.5.29，实际为：";
		d1.show();
		cout << "d2应该是2013.3.18，实际为：";
		d2.show();
		cout << "d3应该是2013.5.18，实际为：";
		d3.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2(2007,5,29);
		Date d3(2013,5,29);
		Date d4(2013,5,29);

		cout << "测试set，年、月、日非法" << endl;

		d1.set(2112,1,0);     //2000.1.29
		d2.set(0, 2, 29);     //2007.2.1
		d3.set(2011, 5, 32);  //2011.5.1
		d4.set(2011, 13, 12); //2011.1.12

		cout << "d1应该是2000.1.29，实际为：";
		d1.show();
		cout << "d2应该是2007.2.1， 实际为：";
		d2.show();
		cout << "d3应该是2011.5.1， 实际为：";
		d3.show();
		cout << "d4应该是2011.1.12，实际为：";
		d4.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		int y,m,d;

		cout << "测试get" << endl;
		d1.get(y, m, d);
		
		cout << "应该y=2013,m=5,d=29，实际为：";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2;

		cout << "测试cout" << endl;
		cout << "d1应该是2013.5.29，实际为："<< d1 << endl;
		cout << "d2应该是2000.1.1， 实际为："<< d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

/*	if (1) {
		Date d1;

		cout << "测试cin/cout" << endl;

		cout << "请输入2013 5 29" << endl;
		cin  >> d1;
		cout << "d1应该是2013.5.29，实际为："<< d1 << endl;

		cout << "请输入2012 2 29" << endl;
		cin  >> d1;
		cout << "d1应该是2012.2.29，实际为："<< d1 << endl;

		cout << "请输入2011 2 29" << endl;
		cin  >> d1;
		cout << "d1应该是2011.2.1，实际为："<< d1 << endl;

		cout << "请输入1899 4 10" << endl;
		cin  >> d1;
		cout << "d1应该是2000.4.10，实际为："<< d1 << endl;

		cout << "请输入2012 13 10" << endl;
		cin  >> d1;
		cout << "d1应该是2012.1.10，实际为："<< d1 << endl;

		cout << "请输入2012 4 31" << endl;
		cin  >> d1;
		cout << "d1应该是2012.4.1，实际为："<< d1 << endl;

		cout << "请输入2112 15 34" << endl;
		cin  >> d1;
		cout << "d1应该是2000.1.1，实际为："<< d1 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		
		cout << "转换构造函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1900.1.1，  实际为：";
		d1.show();
		cout << "d2应该是2099.12.31，实际为：";
		d2.show();
		cout << "d3应该是1900.1.1，  实际为：";
		d3.show();
		cout << "d4应该是2099.12.31，实际为：";
		d4.show();

		d1 = 30000;
		cout << "d1应该是1982.2.19， 实际为：";
		d1.show();

		d2 = 41422;
		cout << "d2应该是2013.5.29， 实际为：";
		d2.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1900,1,1);
		Date d2(2099,12,31);
		Date d3(1982,2,19);
		Date d4(2013,5,29);
		
		cout << "类型转换函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1，     实际为：" << int(d1) << endl;
		cout << "d2应该是73049， 实际为：" << int(d2) << endl;
		cout << "d3应该是30000， 实际为：" << int(d3) << endl;
		cout << "d4应该是41422， 实际为：" << int(d4) << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}


	if (1) {
		Date d1(2013, 5, 1);
		Date d2;

		cout << "测试+/- n" << endl;
	
		d2 = d1+38;
		cout << "d2应该是2013.6.8，  实际为："<< d2 << endl;
	
		d2 = 38+d1;
		cout << "d2应该是2013.6.8，  实际为："<< d2 << endl;
	
		d2 = d1-7;
		cout << "d2应该是2013.4.24， 实际为："<< d2 << endl;

		d1.set(2012,2,28);
		d2 = d1+3;
		cout << "d2应该是2012.3.2，  实际为："<< d2 << endl;

		d1.set(2011,2,28);
		d2 = d1+3;
		cout << "d2应该是2011.3.3，  实际为："<< d2 << endl;

		d1.set(2010,12,28);
		d2 = d1+5;
		cout << "d2应该是2011.1.2，  实际为："<< d2 << endl;

		d1.set(2011,1,1);
		d2 = d1-5;
		cout << "d2应该是2010.12.27，实际为："<< d2 << endl;

		d1.set(2009,12,31);
		d2 = d1+366;
		cout << "d2应该是2011.1.1，  实际为："<< d2 << endl;

		d1.set(2009,1,1);
		d2 = d1-367;
		cout << "d2应该是2007.12.31，实际为："<< d2 << endl;

		d1.set(1900,1,2);
		d2 = d1-10;
		cout << "d2应该是1900.1.1，  实际为："<< d2 << endl;

		d1.set(2099,12,30);
		d2 = d1+5;
		cout << "d2应该是2099.12.31，实际为："<< d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2012,5,1);
		Date d2(2012,3,11);

		cout << "测试-date" << endl;
		cout << "日期差值应为51， 实际为：" << d1-d2 << endl;

		d2.set(2012, 5, 23);
		cout << "日期差值应为-22，实际为：" << d1-d2 << endl;

		d1.set(2012, 3, 2);
		d2.set(2012, 2, 27);
		cout << "日期差值应为4，  实际为：" << d1-d2 << endl;

		d1.set(2011, 3, 2);
		d2.set(2011, 2, 27);
		cout << "日期差值应为3，  实际为：" << d1-d2 << endl;

		d1.set(2011, 1, 2);
		d2.set(2010, 12, 27);
		cout << "日期差值应为6，  实际为：" << d1-d2 << endl;

		d1.set(2011, 1, 1);
		d2.set(2009, 12, 31);
		cout << "日期差值应为366，实际为：" << d1-d2 << endl;

		d1.set(2009, 1, 1);
		d2.set(2007, 12, 31);
		cout << "日期差值应为367，实际为：" << d1-d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}*/

	if (1) {
		Date d1, d2;

		cout << "测试++/--" << endl;

		d1.set(2012,5,1);
		d2 = d1++;
		cout << "d1应该是2012.5.2，  实际为：" << d1 << endl;
		cout << "d2应该是2012.5.1，  实际为：" << d2 << endl;

		d1.set(2012,5,1);
		d2 = ++d1;
		cout << "d1应该是2012.5.2，  实际为：" << d1 << endl;
		cout << "d2应该是2012.5.2，  实际为：" << d2 << endl;

		d1.set(2012,5,1);
		d2 = d1--;
		cout << "d1应该是2012.4.30， 实际为：" << d1 << endl;
		cout << "d2应该是2012.5.1，  实际为：" << d2 << endl;

		d1.set(2012,5,1);
		d2 = --d1;
		cout << "d1应该是2012.4.30， 实际为：" << d1 << endl;
		cout << "d2应该是2012.4.30， 实际为：" << d2 << endl;

		d1.set(2008,12,31);
		d2 = d1++;
		cout << "d1应该是2009.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是2008.12.31，实际为：" << d2 << endl;

		d1.set(2011,1,1);
		d2 = d1--;
		cout << "d1应该是2010.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2011.1.1，  实际为：" << d2 << endl;

		d1.set(2012,2,28);
		d2 = d1++;
		cout << "d1应该是2012.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2012.2.28， 实际为：" << d2 << endl;

		d1.set(2011,2,28);
		d2 = d1++;
		cout << "d1应该是2011.3.1，  实际为：" << d1 << endl;
		cout << "d2应该是2011.2.28， 实际为：" << d2 << endl;

		d1.set(2012,3,1);
		d2 = d1--;
		cout << "d1应该是2012.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2012.3.1，  实际为：" << d2 << endl;

		d1.set(2011,3,1);
		d2 = d1--;
		cout << "d1应该是2011.2.28， 实际为：" << d1 << endl;
		cout << "d2应该是2011.3.1，  实际为：" << d2 << endl;

		d1.set(2099,12,31);
		d2 = d1++;
		cout << "d1应该是2099.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2099.12.31，实际为：" << d2 << endl;

		d1.set(1900,1,1);
		d2 = d1--;
		cout << "d1应该是1900.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是1900.1.1，  实际为：" << d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}


	if (1) {
		/* 测试比较运算符 */
		Date d1(2013,5,29);
		Date d2(2013,5,29);
		Date d3(2013,4,27);

		cout << "测试比较运算符" << endl;

		cout << "比较结果应为0，实际为：" << (d1 >  d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <  d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 <= d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 == d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 != d2) << endl;

		cout << "比较结果应为1，实际为：" << (d1 >  d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <  d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 == d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 != d3) << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	return 0;
}
