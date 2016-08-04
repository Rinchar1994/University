#include <iostream>
#include <cstring>
using namespace std;

class Teacher
{
    public:
		void show_1()
		{
			cout << " 工号：" << num << endl;
			cout << " 姓名：" << name << endl;
			cout << " 性别：" << sex << endl;
		}
		Teacher( int a, char* b, char c )
		{
			num = a;
			strcpy( name, b );
			sex = c;
		}
    private:
		int num;
		char name[10];
		char sex;
};

class BirthDate 
{
    public:
		void show_2()
		{
			cout << "birthday:" << year << ' '<< month << ' ' << day << endl;
		}
		BirthDate( int a, int b, int c )
		{
			year = a;
			month = b;
			day = c;
		}
		void set(int a, int b, int c)
		{
			year = a;
			month = b;
			day = c;
		}
    private:
		int year;
		int month;
		int day;
};

class Proffessor: public Teacher
{
    public:
	    void show()
		{
			show_1();
			birthday.show_2();
		}
		Proffessor( int a, char* b, char c, int d, int e, int f ): Teacher( a, b, c ), birthday( d, e, f )
		{
		}
		void set_birthday(int a, int b, int c)
		{
			birthday.set( a, b, c );
		}
    private:
		BirthDate birthday;
};

int main()
{
	Proffessor a( 213, "沈坚", 'm', 2013, 6, 11 );
	a.set_birthday( 2014, 1, 1 );
	a.show();
	return 0;
}
