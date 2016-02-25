//1252366 ���賬 ����һ��
#include <iostream>
using namespace std;

class Days {
	private:
		int year;
		int month;
		int day;
		int is_leap_year();  //�ж��Ƿ����꣬�ǣ�����1  /   �񣺷���0
	public:
		int calc_days();     //�����ǵ���ĵڼ���
		/* ������Բ���������Ҫ�����Ա�����Ķ��壬�������� */
		int days( int );
		Days( int, int, int);
};

/* �˴��������Ա����������ʵ�� */
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
/* main������׼�� */
int main()
{
	if (1) {
		Days d1(2012,3,18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
		}

	if (1) {
		Days d1(2011,12,31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
		}
	
	if (1) {
		Days d1(2012,12,31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
		}
		
	if (1) {
		Days d1(2011,2,29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
		}

	return 0;
}
