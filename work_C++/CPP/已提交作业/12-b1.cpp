//1252366 蒋凌超 电子一班
#include <iostream>
#include <cmath>
using namespace std;

class integral
{
	public:
		virtual double value()
		{
			return 0.0;
		}
};

class integral_sin: public integral
{
	private:
		double a;
		double b;
	public:
		friend istream& operator >> ( istream &input, integral_sin &t )
		{
			input >> t.a >> t.b;
			return input;
		}
		double value()
		{
			double dx=(a-b)/65535.0, S=0;
			for( int i=1; i<65535; i++ )
				S +=  sin(i*dx)*dx;
			return S;
		}
};

class integral_cos: public integral
{
	private:
		double a;
		double b;
	public:
		friend istream& operator >> ( istream &input, integral_cos &t )
		{
			input >> t.a >> t.b;
			return input;
		}
		double value()
		{
			double dx=(a-b)/65535.0, S=0;
			for( int i=1; i<65535; i++ )
				S +=  cos(i*dx)*dx;
			return S;

		}
};

class integral_exp: public integral
{
	private:
		double a;
		double b;
	public:
		friend istream& operator >> ( istream &input, integral_exp &t )
		{
			input >> t.a >> t.b;
			return input;
		}
		double value()
		{
			double dx=(a-b)/65535.0, S=0;
			for( int i=1; i<65535; i++ )
				S +=  exp(i*dx)*dx;
			return S;

		}
};

int main()
{
    integral_sin s1;
    integral_cos s2;
    integral_exp s3;
    integral *p;
    cin >> s1; //输入上下限及x 的值
    p = &s1;
    cout << p->value() << endl; //打印sinxdx 的值
    cin >> s2; //输入上下限及x 的值
    p = &s2;
    cout << p->value() << endl; //打印cosxdx 的值
    cin >> s3; //输入上下限及x 的值
    p = &s3;
    cout << p->value() << endl; //打印expxdx 的值
    return 0;
}