//1252366 ���賬 ����һ��

#include <iostream>
using namespace std;

class Time
{
    private:
		int hour;
		int minute;
		int sec;
	public:
		void input();
		void output();
};

void Time::input()
{
	cin >> hour;
	cin >> minute;
	cin >> sec;
}

void Time::output()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main()
{
	Time t1;
	t1.input();
	t1.output();
	return 0;
}
