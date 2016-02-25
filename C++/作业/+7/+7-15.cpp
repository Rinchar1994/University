/* 1252337 ������ ����һ�� */
#include <iostream>
#include <ctime>

using namespace std;

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;	//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */

/* ����ϵͳ��ת����������ʾ����������ֵת��Ϊ�뱾�����ƵĽṹ�岢��� */
void system_time_output(int input_time)
{
    struct tm *tt;	//struct tm Ϊϵͳ����Ľṹ��

    tt = localtime((long *)&input_time);	//localtimeΪϵͳ����

    /* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
    cout << tt->tm_year+1900 << '-' << tt->tm_mon + 1 << '-' << tt->tm_mday << ' ' << tt->tm_hour << ':' << tt->tm_min << ':' << tt->tm_sec << endl;

    return;
}

/* ������� */
void tj_time_output(struct tj_time *tp)
{
    /* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
    cout << tp->tj_year << '-' << tp->tj_month << '-' << tp->tj_day << ' ' << tp->tj_hour << ':' << tp->tj_minute << ':' << tp->tj_second << endl;
}

int is_leap_year(int year)
{
	return ((year%4==0) && (year%100!=0)) || (year%400==0);
}

struct tj_time *tj_time_convert(int input_time)
{
    static struct tj_time result;	//���徲̬�ֲ���������׼��

    /* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
	input_time=input_time+28800;
    int d=input_time/86400+1;
	result.tj_hour=input_time/3600%24;
	result.tj_minute=input_time/60%60;
	result.tj_second=input_time%60;
	int year=1970;
	int a[4]={365,365,366,365};
	int i, j;
	int is_leap_year(int year);
	for ( i=0;d>a[i];i++)
	{
		d-=a[i];
		if(i==3)
			i-=1;
		year++;
	}
	result.tj_year=year;
	int b[12]={31, 28+is_leap_year( result.tj_year ), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for( j=1; d>b[j-1]; j++)
		d-=b[j-1];
	result.tj_month=j;
	result.tj_day=d;


    /* ʵ�ֹ��̽��� */

    return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
}

int main()
{
	int test_time[] = {1, 123456789, 349823021, 987654321, 1202990407, 1216468807, 1250312143, 1272636353, 1326193524, 1336549496, 1392837128, 1625675376, 2052743737};
	int i;
	struct tj_time *tp;

	for (i=0; i<sizeof(test_time)/sizeof(int); i++) {
		cout << "��ʱ����        ��" << test_time[i] << endl;
		cout << "ϵͳת���Ľ��  ��";
		system_time_output(test_time[i]);
	
		cout << "�Զ���ת���Ľ����";
		tp = tj_time_convert(test_time[i]);
		tj_time_output(tp);

		cout << endl << "���س�������" << endl;
		getchar();
		}

	if (1) {
		struct tj_time *tp;
		int t=time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		cout << "ϵͳת���ĵ�ǰϵͳʱ�䣺";
		system_time_output(t);
	
		cout << "�Զ���ת����ǰϵͳʱ�䣺";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		cout << endl << "���س�������" << endl;
		getchar();
		}

	return 0;
}