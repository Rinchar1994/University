/*1252337 王佳琪 电子一班*/
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
    void display ();
	Teacher(string n,int a ,string s,string ad,string te,string ti);
protected:
	string name;
	int age;
	string sex;
	string addr;
	string tele;
	string title;
};

class Cadre
{
public :
    Cadre(string n,int a ,string s ,string ad,string te,string po);
protected:
	string name;
	int age;
	string sex;
	string addr;
	string tele;
	string post;
};

class Teacher_Cadre:public Teacher,public Cadre
{
public:
    Teacher_Cadre(string n,int a  ,string s,string ad,string te,string ti,string po,float w):Teacher(n, a , s, ad, te, ti),Cadre( n, a , s ,ad, te, po),wages(w){}

    void show();
protected:
	float wages;
};


Teacher::Teacher(string n,int a,string s, string ad,string te,string ti)
{
	name=n;
	age=a;
	sex=s;
	addr=ad;
	tele=te;
	title=ti;
}

Cadre::Cadre(string n,int a ,string s,string ad,string te,string po)
{
	name=n;
	age=a;
	sex=s;
	addr=ad;
	tele=te;
	post=po;
}


void Teacher::display()
{
	cout<<"name:"<<name<<'\n'<<"age:"<<age<<'\n'<<"sex:"<<sex<<'\n'<<"title:"<<title<<'\n'<<"address:"<<addr<<'\n'<<"tele:"<<tele;
}

void Teacher_Cadre::show()
{
	Teacher::display();
	cout<<"post:"<<Cadre::post<<'\n'<<"wages:"<<wages<<endl;
}


int main()
{
	Teacher_Cadre X("Li_qiang",18,"m","Shang hai","20001","engineer","manager",6000.8);
	X.show();
	return 0;
}


