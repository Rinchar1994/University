//1252366 ���賬 ����һ��

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
			cout << "�������ϲ�����ѧ��" << *(b+i) << ' ';
			cout << "���ſγɼ�Ϊ�� ";
			for( j=0; j<5; j++)
			{
				cout << *(*(a+i)+j) << ' ';
				s+=*(*(a+i)+j);
			}
			s/=5.0;
			cout << "���ſ�ƽ���ɼ�Ϊ��" << s << endl;
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
			cout << "�ɼ�������ѧ��Ϊ��" << *(b+i) << endl;
	}
}


int main()
{
	int grade[4][5];
	double average;
	char num[4][20];
	cout << "�������ĸ�ѧ����ѧ��" << endl;
	int i, j;
	for(i=0; i<4; i++)
		cin >> num[i];
	cout << "��������ѧ������˳���Ӧ�����ſγɼ�(������һ���˵ĳɼ�������һ��)" << endl;
	for(i=0; i<4; i++)
		for(j=0; j<5; j++)
			cin >> grade[i][j];
	average=AV( grade );
	cout << "��һ�ſε�ƽ���ɼ�Ϊ��" << average << endl;
	cout << endl;
	find1( grade, num);
	cout << endl;
	find2( grade, num);
	return 0;
}




