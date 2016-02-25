#include <iostream>
using namespace std;

class Shape
{
    public:
		virtual double area()
		{
			return 0.0;
		}
};

class Circle: public Shape
{
	private:
		double r;
	public:
		double area()
		{
			return 3.14159*r*r;
		}
		Circle()
		{
			r = 0;
		}
		friend istream& operator >> ( istream& infile, Circle& b )
		{
			infile>>b.r;
			return infile;
		}
};

class Square: public Shape
{
	private:
		double a;
	public:
		double area()
		{
			return a*a;
		}
		Square()
		{
			a = 0;
		}
		friend istream& operator >> ( istream& infile, Square& b )
		{
			infile>>b.a;
			return infile;
		}
};

class Rectangle: public Shape
{
	private:
		double a;
		double b;
	public:
		double area()
		{
			return a*b;
		}
		Rectangle()
		{
			a=0;
			b=0;
		}
		friend istream& operator >> ( istream& infile, Rectangle& s )
		{
			infile>>s.a>>s.b;
			return infile;
		}
};

class Trapezoid: public Shape
{
	private:
		double a;
		double b;
		double h;
	public:
		double area()
		{
			return (a+b)*h/2;
		}
		Trapezoid()
		{
			a=0;
			b=0;
			h=0;
		}
		friend istream& operator >> ( istream& infile, Trapezoid& s )
		{
			infile>>s.a>>s.b>>s.h;
			return infile;
		}
};

class Triangle: public Shape
{
	private:
		double a;
		double h;
	public:
		double area()
		{
			return a*h/2;
		}
		Triangle()
		{
			a=0;
			h=0;
		}
		friend istream& operator >> ( istream& infile, Triangle& s )
		{
			infile>>s.a>>s.h;
			return infile;
		}
};

int main()
{
	Circle c1;
	cin >> c1;
	Square s1;
	cin >> s1;
	Rectangle r1;
	cin >> r1;
	Trapezoid t1;
	cin >> t1;
	Triangle t2;
	cin >> t2;
	Shape *s[5]={ &c1, &s1, &r1, &t1, &t2 };

	int i;
	double S=0.0;
	for( i=0; i<5; i++)
	{
		cout << s[i]->area() << ' ';
		S += s[i]->area();
	}
	cout << endl;
	cout << S << endl;

	return 0;
}
