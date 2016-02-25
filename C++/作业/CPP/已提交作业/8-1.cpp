//1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;

class Time
{
    public://原：省略此句
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
	t.set_time();//原：set.time();
	t.show_time();//原：show.time();
	return 0;
}

void Time::set_time( void )//原：int Time::set_time( void )
{
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}

void Time::show_time( void )//原：int Time::show_time( void )
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
