/* 1252337 ������ ����һ�� */
#include <iostream.h>
#include <conio.h>
//using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;
	public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
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

/* ����ĳ�Ա��������Ԫ������ʵ�ֲ��� */
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


/* ----main������׼��---- */
int main()
{
	/*if (1) {
		Date d1;             //2000.1.1
		Date d2(2013,5,29);  //2013.5.29
		
		cout << "���Գ�ʼ������ȫ��ȷ�ĸ�ֵ" << endl;

		cout << "d1Ӧ����2000.1.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2013.5.29��ʵ��Ϊ��";
		d2.show();

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1870,3,15);  //2000.3.15
		Date d2(2112,3,4);   //2000.3.4
		Date d3(2005,13,15); //2005.1.15
		Date d4(2008,5,32);  //2008.5.1
		
		cout << "���Գ�ʼ�����ꡢ�¡��շǷ�" << endl;

		cout << "d1Ӧ����2000.3.15��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2000.3.4�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2005.1.15��ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2008.5.1�� ʵ��Ϊ��";
		d4.show();

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
	    Date d1(2011,2,29);   //2011.2.1
	    Date d2(2012,2,29);   //2012.2.29

		cout << "���Գ�ʼ��������" << endl;

		cout << "d1Ӧ����2011.2.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2012.2.29��ʵ��Ϊ��";
		d2.show();

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1, d2, d3; //����2000.1.1

		cout << "����set����ȱʡֵ" << endl;
		d1.set(2013,5,29);	//2013.5.29
		d2.set(2013,5);		//2013.5.1
		d3.set(2013);		//2013.1.1

		cout << "d1Ӧ����2013.5.29��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2013.5.1�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2013.1.1�� ʵ��Ϊ��";
		d3.show();

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2(2013,5,29);
		Date d3(2013,5,29);

		cout << "����set�����ֲ���" << endl;

		d1.set(2007,0,0);   //2007.5.29
		d2.set(0, 3, 18);   //2013.3.18
		d3.set(0, 0, 18);   //2013.5.18

		cout << "d1Ӧ����2007.5.29��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2013.3.18��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2013.5.18��ʵ��Ϊ��";
		d3.show();

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2(2007,5,29);
		Date d3(2013,5,29);
		Date d4(2013,5,29);

		cout << "����set���ꡢ�¡��շǷ�" << endl;

		d1.set(2112,1,0);     //2000.1.29
		d2.set(0, 2, 29);     //2007.2.1
		d3.set(2011, 5, 32);  //2011.5.1
		d4.set(2011, 13, 12); //2011.1.12

		cout << "d1Ӧ����2000.1.29��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2007.2.1�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2011.5.1�� ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2011.1.12��ʵ��Ϊ��";
		d4.show();

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		int y,m,d;

		cout << "����get" << endl;
		d1.get(y, m, d);
		
		cout << "Ӧ��y=2013,m=5,d=29��ʵ��Ϊ��";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2;

		cout << "����cout" << endl;
		cout << "d1Ӧ����2013.5.29��ʵ��Ϊ��"<< d1 << endl;
		cout << "d2Ӧ����2000.1.1�� ʵ��Ϊ��"<< d2 << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

/*	if (1) {
		Date d1;

		cout << "����cin/cout" << endl;

		cout << "������2013 5 29" << endl;
		cin  >> d1;
		cout << "d1Ӧ����2013.5.29��ʵ��Ϊ��"<< d1 << endl;

		cout << "������2012 2 29" << endl;
		cin  >> d1;
		cout << "d1Ӧ����2012.2.29��ʵ��Ϊ��"<< d1 << endl;

		cout << "������2011 2 29" << endl;
		cin  >> d1;
		cout << "d1Ӧ����2011.2.1��ʵ��Ϊ��"<< d1 << endl;

		cout << "������1899 4 10" << endl;
		cin  >> d1;
		cout << "d1Ӧ����2000.4.10��ʵ��Ϊ��"<< d1 << endl;

		cout << "������2012 13 10" << endl;
		cin  >> d1;
		cout << "d1Ӧ����2012.1.10��ʵ��Ϊ��"<< d1 << endl;

		cout << "������2012 4 31" << endl;
		cin  >> d1;
		cout << "d1Ӧ����2012.4.1��ʵ��Ϊ��"<< d1 << endl;

		cout << "������2112 15 34" << endl;
		cin  >> d1;
		cout << "d1Ӧ����2000.1.1��ʵ��Ϊ��"<< d1 << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		
		cout << "ת�����캯�����ԣ������Ϸ����Ƿ�ֵ" << endl;

		cout << "d1Ӧ����1900.1.1��  ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����1900.1.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2099.12.31��ʵ��Ϊ��";
		d4.show();

		d1 = 30000;
		cout << "d1Ӧ����1982.2.19�� ʵ��Ϊ��";
		d1.show();

		d2 = 41422;
		cout << "d2Ӧ����2013.5.29�� ʵ��Ϊ��";
		d2.show();

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1900,1,1);
		Date d2(2099,12,31);
		Date d3(1982,2,19);
		Date d4(2013,5,29);
		
		cout << "����ת���������ԣ������Ϸ����Ƿ�ֵ" << endl;

		cout << "d1Ӧ����1��     ʵ��Ϊ��" << int(d1) << endl;
		cout << "d2Ӧ����73049�� ʵ��Ϊ��" << int(d2) << endl;
		cout << "d3Ӧ����30000�� ʵ��Ϊ��" << int(d3) << endl;
		cout << "d4Ӧ����41422�� ʵ��Ϊ��" << int(d4) << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}


	if (1) {
		Date d1(2013, 5, 1);
		Date d2;

		cout << "����+/- n" << endl;
	
		d2 = d1+38;
		cout << "d2Ӧ����2013.6.8��  ʵ��Ϊ��"<< d2 << endl;
	
		d2 = 38+d1;
		cout << "d2Ӧ����2013.6.8��  ʵ��Ϊ��"<< d2 << endl;
	
		d2 = d1-7;
		cout << "d2Ӧ����2013.4.24�� ʵ��Ϊ��"<< d2 << endl;

		d1.set(2012,2,28);
		d2 = d1+3;
		cout << "d2Ӧ����2012.3.2��  ʵ��Ϊ��"<< d2 << endl;

		d1.set(2011,2,28);
		d2 = d1+3;
		cout << "d2Ӧ����2011.3.3��  ʵ��Ϊ��"<< d2 << endl;

		d1.set(2010,12,28);
		d2 = d1+5;
		cout << "d2Ӧ����2011.1.2��  ʵ��Ϊ��"<< d2 << endl;

		d1.set(2011,1,1);
		d2 = d1-5;
		cout << "d2Ӧ����2010.12.27��ʵ��Ϊ��"<< d2 << endl;

		d1.set(2009,12,31);
		d2 = d1+366;
		cout << "d2Ӧ����2011.1.1��  ʵ��Ϊ��"<< d2 << endl;

		d1.set(2009,1,1);
		d2 = d1-367;
		cout << "d2Ӧ����2007.12.31��ʵ��Ϊ��"<< d2 << endl;

		d1.set(1900,1,2);
		d2 = d1-10;
		cout << "d2Ӧ����1900.1.1��  ʵ��Ϊ��"<< d2 << endl;

		d1.set(2099,12,30);
		d2 = d1+5;
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��"<< d2 << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2012,5,1);
		Date d2(2012,3,11);

		cout << "����-date" << endl;
		cout << "���ڲ�ֵӦΪ51�� ʵ��Ϊ��" << d1-d2 << endl;

		d2.set(2012, 5, 23);
		cout << "���ڲ�ֵӦΪ-22��ʵ��Ϊ��" << d1-d2 << endl;

		d1.set(2012, 3, 2);
		d2.set(2012, 2, 27);
		cout << "���ڲ�ֵӦΪ4��  ʵ��Ϊ��" << d1-d2 << endl;

		d1.set(2011, 3, 2);
		d2.set(2011, 2, 27);
		cout << "���ڲ�ֵӦΪ3��  ʵ��Ϊ��" << d1-d2 << endl;

		d1.set(2011, 1, 2);
		d2.set(2010, 12, 27);
		cout << "���ڲ�ֵӦΪ6��  ʵ��Ϊ��" << d1-d2 << endl;

		d1.set(2011, 1, 1);
		d2.set(2009, 12, 31);
		cout << "���ڲ�ֵӦΪ366��ʵ��Ϊ��" << d1-d2 << endl;

		d1.set(2009, 1, 1);
		d2.set(2007, 12, 31);
		cout << "���ڲ�ֵӦΪ367��ʵ��Ϊ��" << d1-d2 << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}*/

	if (1) {
		Date d1, d2;

		cout << "����++/--" << endl;

		d1.set(2012,5,1);
		d2 = d1++;
		cout << "d1Ӧ����2012.5.2��  ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2012.5.1��  ʵ��Ϊ��" << d2 << endl;

		d1.set(2012,5,1);
		d2 = ++d1;
		cout << "d1Ӧ����2012.5.2��  ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2012.5.2��  ʵ��Ϊ��" << d2 << endl;

		d1.set(2012,5,1);
		d2 = d1--;
		cout << "d1Ӧ����2012.4.30�� ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2012.5.1��  ʵ��Ϊ��" << d2 << endl;

		d1.set(2012,5,1);
		d2 = --d1;
		cout << "d1Ӧ����2012.4.30�� ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2012.4.30�� ʵ��Ϊ��" << d2 << endl;

		d1.set(2008,12,31);
		d2 = d1++;
		cout << "d1Ӧ����2009.1.1��  ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2008.12.31��ʵ��Ϊ��" << d2 << endl;

		d1.set(2011,1,1);
		d2 = d1--;
		cout << "d1Ӧ����2010.12.31��ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2011.1.1��  ʵ��Ϊ��" << d2 << endl;

		d1.set(2012,2,28);
		d2 = d1++;
		cout << "d1Ӧ����2012.2.29�� ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2012.2.28�� ʵ��Ϊ��" << d2 << endl;

		d1.set(2011,2,28);
		d2 = d1++;
		cout << "d1Ӧ����2011.3.1��  ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2011.2.28�� ʵ��Ϊ��" << d2 << endl;

		d1.set(2012,3,1);
		d2 = d1--;
		cout << "d1Ӧ����2012.2.29�� ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2012.3.1��  ʵ��Ϊ��" << d2 << endl;

		d1.set(2011,3,1);
		d2 = d1--;
		cout << "d1Ӧ����2011.2.28�� ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2011.3.1��  ʵ��Ϊ��" << d2 << endl;

		d1.set(2099,12,31);
		d2 = d1++;
		cout << "d1Ӧ����2099.12.31��ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��" << d2 << endl;

		d1.set(1900,1,1);
		d2 = d1--;
		cout << "d1Ӧ����1900.1.1��  ʵ��Ϊ��" << d1 << endl;
		cout << "d2Ӧ����1900.1.1��  ʵ��Ϊ��" << d2 << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}


	if (1) {
		/* ���ԱȽ������ */
		Date d1(2013,5,29);
		Date d2(2013,5,29);
		Date d3(2013,4,27);

		cout << "���ԱȽ������" << endl;

		cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 >  d2) << endl;
		cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d2) << endl;
		cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 <  d2) << endl;
		cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 <= d2) << endl;
		cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 == d2) << endl;
		cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 != d2) << endl;

		cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >  d3) << endl;
		cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 >= d3) << endl;
		cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 <  d3) << endl;
		cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 <= d3) << endl;
		cout << "�ȽϽ��ӦΪ0��ʵ��Ϊ��" << (d1 == d3) << endl;
		cout << "�ȽϽ��ӦΪ1��ʵ��Ϊ��" << (d1 != d3) << endl;

		cout << "���������..." << endl;
		getch();
		cout << endl;
		}

	return 0;
}
