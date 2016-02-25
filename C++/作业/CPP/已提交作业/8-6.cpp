//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
using namespace std;

class Rec
{
	double length;
	double width;
	double height;
    public:
		void input();
		double volume();
		void output();
};

void Rec::input()
{
	cin >> length >> width >> height;
}

double Rec::volume()
{
	return length*width*height;
}

void Rec::output()
{
	cout << "The volume of the rectangular prism is : " << volume() << endl;
}

void main()
{
	Rec a[3];
	for( int i=0; i<3; i++)
	{
		a[i].input();
		a[i].volume();
		a[i].output();
	}
}

		


