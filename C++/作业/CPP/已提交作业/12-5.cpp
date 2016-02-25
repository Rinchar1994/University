//1252366 ½¯Áè³¬ µç×ÓÒ»°à

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
		Circle( double a )
		{
			r = a;
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
		Square( double t )
		{
			a = t;
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
		Rectangle( double t1, double t2 ): a(t1), b(t2)
		{
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
		Trapezoid( double t1, double t2, double t3 ): a(t1), b(t2), h(t3)
		{
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
		Triangle( double t1, double t2 ): a(t1), h(t2)
		{
		}
};

int main()
{
	Circle c1(1.0);
	Square s1(1.0);
	Rectangle r1(1.0, 2.0);
	Trapezoid t1(1.0, 2.0, 3.0);
	Triangle t2(1.0, 2.0);
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
