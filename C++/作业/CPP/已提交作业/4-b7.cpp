// 1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;

int main()
{
	int max(int a, int b,int n);
	int max(int a, int b, int c,int n);
	int max(int a, int b, int c, int d, int n);
	int n;
	cout << "请输入要比较大小的数的个数n（n=2,3,4），以及要比较的正整数" << endl;
	while(1)
	{
	    cin >> n;
	    if(n!=2 && n!=3 && n!=4)
			{
				cout << "输入错误，请重新输入" << endl;
				cin.ignore(1000,'\n');
				continue;
			}
		else
			break;
	}
	while(1)
	{
		if(n==2)
		{
		    int i1, i2;
		    cin  >> i1 >> i2;
			if(i1>0 && i2>0)
			{
	            cout << "max_2=" << max(i1, i2, n) <<endl;
			    break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				continue;
			}
		}
	    else if(n==3)
		{
	    	int j1, j2, j3;
	        cin >> j1 >> j2 >> j3;
			if(j1>0 && j2>0 && j3>0)
			{
	            cout << "max_3=" << max(j1, j2, j3, n) << endl;
	        	break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				continue;
			}

		}
     	else if(n==4)
		{
			int k1, k2, k3 ,k4;
	        cin >> k1 >> k2 >> k3 >> k4;
			if(k1>0 && k2>0 && k3>0 && k4>0)
			{
	            cout << "max_4=" << max(k1, k2, k3, k4, n) << endl;
			    break;
			}
		}
	}

	return 0;
}

int max(int a, int b,int n)
{
	if(a<b)
		a=b;
		return a;
}

int max(int a, int b, int c,int n)
{
	if(a<b)
		a=b;
	if(a<c)
		a=c;
	return a;
}

int max(int a, int b, int c, int d,int n)
{
	if(a<b)
		a=b;
	if(c<d)
		c=d;
	if(a<c)
		a=c;
	return a;
}
// 没有解决当n与正整数个数不对应时不输出错误的问题。


	