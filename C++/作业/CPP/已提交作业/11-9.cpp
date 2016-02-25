//1252366 蒋凌超 电子一班

#include <iostream> 
#include <string>
using namespace std;

class TC
{
    protected:
		char name[10];
		int age;
		char sex;
		char address[20];
		char phone[20];
	public:
		TC( char *a, int b, char c, char *d, char *e );
};

TC::TC( char *a, int b, char c, char *d, char *e )
{
	strcpy( name, a );
	age = b;
	sex = c;
	strcpy( address, d );
	strcpy( phone, e );
}

class Teacher: virtual public TC
{
    protected:
		char title[15];
	public:
		void display();
		Teacher( char *a, int b, char c, char *d, char *e, char* f );
};

Teacher::Teacher( char *a, int b, char c, char *d, char *e, char* f ): TC( a, b, c, d, e)
{
	strcpy( title, f);
}

class Cadre: virtual public TC
{
    protected:
		char post[15];
	public:
		Cadre( char *a, int b, char c, char *d, char *e, char* f );
};

Cadre::Cadre( char *a, int b, char c, char *d, char *e, char* f ): TC( a, b, c, d, e)
{
	strcpy( post, f );
}

class Teacher_Cadre: public Teacher, public Cadre
{
    private:
		int wages;
	public:
		void show();
		Teacher_Cadre(char *a, int b, char c, char *d, char *e, char* f, char* g, int h );
};
Teacher_Cadre::Teacher_Cadre(char *a, int b, char c, char *d, char *e, char* f, char* g, int h ): TC( a, b, c, d, e ), Teacher( a, b, c, d, e, f ), Cadre( a, b, c, d, e, g )
{ 
	wages = h;
}

void Teacher::display()
{
	cout << " name: " << name << endl;
	cout << " age: " << age << endl;
	cout << " sex: " << sex << endl;
	cout << " title: " << title << endl;
	cout << " address: " << address << endl;
	cout << " phone: " << phone << endl;
}

void Teacher_Cadre::show()
{
	display();
	cout << " post: " << post << endl;
	cout << " wages: " << wages << endl;
}

void main()
{
	Teacher_Cadre a( "沈坚", 3, 'm', "讲师", "...", "***", "老大", -100);
	a.show();
}
//"沈坚", 3, 'm', "讲师", "...", "***", "老大", -100