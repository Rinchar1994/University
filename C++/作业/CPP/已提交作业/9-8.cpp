//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream.h>

class Student
{
    public:
		Student( int n, float s):num(n), score(s)
		{
		}
		void change( int n, float s)
		{
			num=n;
			score=s;
		}
		void display()
		{
			cout << num << " " << score << endl;
		}
	private:
		int num;
		float score;
};

void fun( Student &t)
{
	t.display();
	t.change(101, 80.5);
	t.display();
}

int main()
{
	Student stud( 101, 78.5 );
	fun( stud );
	return 0;
}