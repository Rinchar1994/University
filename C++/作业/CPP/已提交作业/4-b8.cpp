// 1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;
#define max 2147483647

int main()
{
	int min(int a,int b,int c=max,int d=max);
	int n, a, b, c, d;
	cout << "请输入要比较大小的数的个数n(n=2,3,4)，以及要比较的正整数" << endl;
	while(1)
	{
		cin >> n;
		if(n==2 || n==3 || n==4)
			break;
		else
		{
			cout << "输入错误，请重新输入" << endl;
			cin.ignore(1000,'\n');
			continue;
		}
	}
	while(1)
	{
		if(n==2)
		{
			cin >> a >> b;
			if(a>0 && b>0)
			{
			    cout << "min_2=" << min(a, b) << endl;
				break;
			}
			else
			{
				cout << "输入错误，重新输入" << endl;
				continue;
			}
		}
		if(n==3)
		{
			cin >> a >> b >> c;
			if(a>0 && b>0 && c>0)
			{
				cout << "min_3=" << min(a, b, c) << endl;
				break;
			}
			else
			{
				cout << "输入错误，重新输入" << endl;
				continue;
			}
		}
		if(n==4)
		{
			cin >> a >> b >> c >> d;
			if(a>0 && b>0 && c>0 && d>0)
			{
				cout << "min_4=" << min(a, b, c, d) << endl;
				break;
			}
			else
			{
				cout << "输入错误，重新输入" << endl;
				continue;
			}
		}
	}

	return 0;
}

int min(int a,int b,int c,int d)
{
	if(a>b)
		a=b;
	if(a>c)
		a=c;
	if(a>d)
		a=d;
	return a;
}

		
