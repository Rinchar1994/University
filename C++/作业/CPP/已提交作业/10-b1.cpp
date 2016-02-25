/* 1252366 ���賬 ����һ�� */
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
		Date( int a, int b, int c );
		Date();
		void set( int i=0, int j=0, int k=0 );
		void get( int &a, int &b, int &c );
		void show();
		Date( int d );
		operator int();
		friend istream& operator >> ( istream &in, Date &a );
		friend ostream& operator << ( ostream &out, Date &a );
		friend Date operator + ( Date &a, const int &b );
		friend Date operator - ( Date &a, const int &b );
		friend int operator - ( Date &a, Date &b );
		Date& operator ++ ();
		Date operator ++ ( int );
		Date& operator -- ();
		Date operator -- ( int );
		friend bool operator > ( Date &a, Date &b );
		friend bool operator >= ( Date &a, Date &b );
		friend bool operator < ( Date &a, Date &b );
		friend bool operator <= ( Date &a, Date &b );
		friend bool operator == ( Date &a, Date &b );
		friend bool operator != ( Date &a, Date &b );
};

/* ����ĳ�Ա��������Ԫ������ʵ�ֲ��� */
bool operator > ( Date &a, Date &b )
{
	return a.operator int()>b.operator int();
}

bool operator >= ( Date &a, Date &b )
{
	return a.operator int()>=b.operator int();
}
bool operator < ( Date &a, Date &b )
{
	return a.operator int()<b.operator int();
}
bool operator <= ( Date &a, Date &b )
{
	return a.operator int()<=b.operator int();
}
bool operator == ( Date &a, Date &b )
{
	return a.operator int()==b.operator int();
}
bool operator != ( Date &a, Date &b )
{
	return a.operator int()!=b.operator int();
}

Date& Date::operator -- ()
{
	int a=operator int();
	a--;
	*this = Date(a);
	return *this;
}

Date Date::operator -- ( int )
{
	Date c( *this );
	int a=operator int();
	a--;
	*this = Date(a);
	return c;
}

Date Date::operator ++ ( int )
{
	Date c( *this );
	int a=operator int();
	a++;
	*this = Date(a);
	return c;
}

Date& Date::operator ++()
{
	int a=operator int();
	a++;
	*this = Date(a);
	return *this;
}
int operator-( Date &a, Date &b )
{
	int e;
	e = int(a) - int(b);
	return e;
}

Date operator-( Date &a, const int &b )
{
	Date e;
	e = int(a) - b;
	return e;
}

Date operator+( Date &a, const int &b )
{
	Date e;
	e = int(a) + b;
	return e;
}
istream& operator >> ( istream &in, Date &a )
{
	in >> a.year >> a.month >> a.day;
	return in;
}

ostream& operator << ( ostream &out, Date &a )
{
	int c;
	c = int(a);
	a = Date(c);
	out << a.year << "��" << a.month << "��" << a.day << "��" << endl;
	return out;
}

Date::operator int()
{
	int d = 0;
	if( year>2099 || year<1900 )
		year = 2000;
	if( month>12 || month<1 )
		month = 1;
	int b[12]={31, 28+(year%4==0 && year%100!=0 || year%400==0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if( day>b[month-1] || day<1 )
		day = 1;
	if( (year-1900)/4!=0 )
	{
		d += (year-1900)/4*(366+365*3)-1;
	    if( (year-1900)%4!=0 )
		    d += (year-1900)%4*365+1;
	}
	else if( (year-1900)%4!=0 )
		d += (year-1900)%4*365;
	for( int i=0; i<month-1; i++ )
		d += b[i];
	d += day;
	return d;
}

Date::Date( int d )
{
	int a[4]={365, 365, 365, 366};
	year = 1900;
	month = 1;
	day = 1;
	if( d>=73049 )
	{
		year = 2099;
		month = 12;
		day = 31;
	}
	else if( d>=1 )
	{
		if( d>365 )
		{
			d -= 365;
			year++;
		}
        for( int i=0; d>a[i]; i=(i+1)%4)
		{
			year++;
			d -= a[i];
		}
		int b[12]={31, 28+(year%4==0 && year%100!=0 || year%400==0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		for( int j=0; d>b[j]; j++ )
		{
			month++;
			d -= b[j];
		}
		day=d;
	}
}
void Date::show()
{
	cout << year << "��" << month << "��" << day << "��" << endl;
}

void Date::get( int &a, int &b, int &c )
{
	a=year;
	b=month;
	c=day;
}

void Date::set( int i, int j, int k )
{
	if( i!=0 && i<1900 || i>2099 )
		year = 2000;
	else if( i!=0 )
		year = i;
	if( j<0 || j>12 )
		month = 1;
	else if( j!=0 )
		month = j;
	int b[12]={31, 28+(year%4==0 && year%100!=0 || year%400==0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if( k<0 || k>b[month-1] )
		day = 1;
	else if( k!=0 )
		day=k;
}

Date::Date( int a, int b, int c )
{
	if( a<1900 || a>2099 )
		year = 2000;
	else
	    year = a;
	if( b<1 || b>12 )
		month = 1;
	else
	    month = b;
	int e[12]={31, 28+(year%4==0 && year%100!=0 || year%400==0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if( c>e[month-1] || c<1 )
		day = 1;
	else
	    day = c;
}

Date::Date()
{
	year=2000;
	month=1;
	day=1;
}
/* ----main������׼��---- */
int main()
{
	if (1) {
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

    if (1) {
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
d1.show();
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
		}

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
