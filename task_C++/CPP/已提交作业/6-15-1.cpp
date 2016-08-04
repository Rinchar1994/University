//1252366 蒋凌超 电子一班

#include <iostream>
using namespace std;

double AV( int (*a)[5])
{
	double s=0;
	for( int i=0; i<4; i++)
		s=s+**(a+i);
	s/=4.0;
	return s;
}

void find1( int (*a)[5], char (*b)[20])
{
	int i, j, n;
	double s;
	for( i=0; i<4; i++)
	{
		n=0;
		s=0;
		for( j=0; j<5; j++)
			if(*(*(a+i)+j)<60)
				n++;
		if(n>2)
		{
			cout << "两门以上不及格学生" << *(b+i) << ' ';
			cout << "各门课成绩为： ";
			for( j=0; j<5; j++)
			{
				cout << *(*(a+i)+j) << ' ';
				s+=*(*(a+i)+j);
			}
			s/=5.0;
			cout << "五门课平均成绩为：" << s << endl;
		}
	}
}

void find2(int (*a)[5], char (*b)[20])
{
	int i, j, n;
	double s;
	for( i=0; i<4; i++)
	{
		n=0;
		s=0;
		for( j=0; j<5; j++)
		{
			s+=*(*(a+i)+j);
			if( *(*(a+i)+j)>85)
				n++;
		}
		if( n==5 || s/5.0>90)
			cout << "成绩优异者学号为：" << *(b+i) << endl;
	}
}


int main()
{
	int grade[4][5];
	double average;
	char num[4][20];
	cout << "请输入四个学生的学号" << endl;
	int i, j;
	for(i=0; i<4; i++)
		cin >> num[i];
	cout << "请输入与学号输入顺序对应的五门课成绩(先输入一个人的成绩再输下一个)" << endl;
	for(i=0; i<4; i++)
		for(j=0; j<5; j++)
			cin >> grade[i][j];
	average=AV( grade );
	cout << "第一门课的平均成绩为：" << average << endl;
	cout << endl;
	find1( grade, num);
	cout << endl;
	find2( grade, num);
	return 0;
}




