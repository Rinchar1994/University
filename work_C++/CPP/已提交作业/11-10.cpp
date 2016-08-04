//1252366 ���賬 ����һ��

#include <iostream>
#include <cstring>
using namespace std;

class Teacher
{
    public:
		Teacher( int a, char* b, char c )
		{
			num = a;
			strcpy( name, b );
			sex = c;
		}
		void show_1()
		{
			cout << " ���ţ�" << num << endl;
			cout << " ������" << name << endl;
			cout << " �Ա�" << sex << endl;
		}
    private:
		int num;
		char name[10];
		char sex;
};

class BirthDate 
{
    public:
		void set(int a, int b, int c)
		{
			year = a;
			month = b;
			day = c;
		}
		BirthDate( int a, int b, int c )
		{
			year = a;
			month = b;
			day = c;
		}
		void show_2()
		{
			cout << "birthday:" << year << ' '<< month << ' ' << day << endl;
		}
    private:
		int year;
		int month;
		int day;
};

class Proffessor: public Teacher
{
    public:
		void set_birthday(int a, int b, int c)
		{
			birthday.set( a, b, c );
		}
		Proffessor( int a, char* b, char c, int d, int e, int f ): Teacher( a, b, c ), birthday( d, e, f )
		{
		}
		void show()
		{
			show_1();
			birthday.show_2();
		}
    private:
		BirthDate birthday;
};

void main()
{
	Proffessor a( 213, "���", 'm', 2013, 6, 11 );
	a.set_birthday( 2014, 1, 1 );
	a.show();
}
//213, "���", 'm', 2013, 6, 11