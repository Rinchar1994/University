#include <iostream.h>
#include <cmath>

double N=100000.0;
class integral
{
	public:
		 double virtual value()
		{
			return 0.0;
		}
};

class integral_sin: public integral
{
	double a;
	double b;
	public:
		double value();
		friend istream& operator >> ( istream &input, integral_sin &t );
};

double integral_sin::value()
{
		double dx=(a-b)/N, S=0;
		for( int i=1; i<=N; i++ )
			S +=  sin(i*dx)*dx;
		return S;
}

istream& operator >> ( istream &input, integral_sin &t )
{
	input>>t.a>>t.b;
	return input;
}

class integral_cos: public integral
{
	double a;
	double b;
	public:
		double value();
		friend istream& operator >> ( istream &input, integral_cos &t );
};

double integral_cos::value()
{
	double dx=(a-b)/N, S=0;
	for( int i=1; i<=N; i++ )
	    S +=  cos(i*dx)*dx;
    return S;
}

istream& operator >> ( istream &input, integral_cos &t )
{
	input >> t.a >> t.b;
    return input;
}

class integral_exp: public integral
{
	double a;
	double b;
	public:
		double value();
		friend istream& operator >> ( istream &input, integral_exp &t );
};

double integral_exp::value()
{
	double dx=(a-b)/N, S=0;
	for( int i=1; i<=N; i++ )
		S +=  exp(i*dx)*dx;
	return S;
}

istream& operator >> ( istream &input, integral_exp &t )
{
	input >> t.a >> t.b;
	return input;
}

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