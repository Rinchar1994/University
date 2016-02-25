//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
#include <cstring>
using namespace std;

struct student 
{
	char num[10];
	char name[10];
	int score[3];
};
 
void input( student *s )
{
	for( int i=0; i<10; i++)
	{
		cin >> s[i].num >> s[i].name;
		cin >> s[i].score[0] >> s[i].score[1] >> s[i].score[2];
	}
}

void average( student *t )
{
	double a;
	cout << "The average score is:" << endl;
	for( int i=0; i<10; i++)
	{
		a=(t[i].score[0]+t[i].score[1]+t[i].score[2])/3.0;
		cout << t[i].num << ' ' << a << endl;
	}
}

void max( student *m )
{
	double a[10], b[10];
	int k;
	for( int i=0; i<10; i++)
		a[i]=m[i].score[0]+m[i].score[1]+m[i].score[2];
	for( int j=0; j<10; j++)
		b[j]=a[j];
	for( k=1; k<10; k++)
		a[k]=(a[k-1]>a[k])?a[k-1]:a[k];
	cout << "The best students are:" << endl;
	for( k=0; k<10; k++)
		if(b[k]==a[9])
		{
			cout << m[k].num << ' ' << m[k].name << ' ';
			cout << m[k].score[0] << ' ' << m[k].score[1] << ' ' << m[k].score[2] << ' ';
			cout << "the average score is " << b[k]/3.0 << endl;
		}
}

int main()
{
	cout << "Please input the numbers, names and three subjects' scores of the 10 student." << endl;
	student stu[10];
	input( stu );
	cout << endl;
	average( stu );
	cout << endl;
	max( stu );
	return 0;
}
