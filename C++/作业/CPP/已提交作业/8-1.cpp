//1252366 ���賬 ����һ��
#include <iostream>
using namespace std;

class Time
{
    public://ԭ��ʡ�Դ˾�
	    void set_time( void );
        void show_time( void );
	private:
	    int hour;
    	int minute;
        int sec;
};

Time t;

int main()
{
	t.set_time();//ԭ��set.time();
	t.show_time();//ԭ��show.time();
	return 0;
}

void Time::set_time( void )//ԭ��int Time::set_time( void )
{
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}

void Time::show_time( void )//ԭ��int Time::show_time( void )
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
