// 1252366 ���賬 ����һ��
#include <iostream>
#include <cmath>
#include "4-b2.h"
using namespace std;

int main()
{
	double a, b, c;
	cout << "����ʵ��a,b,c" << endl;
	while(1)
	{
    	cin >> a >> b >> c;
	    if(a==0)
		{
 	    	if(b==0 && c!=0)
			{
		    	cout << "�����޽�,����������" << endl;
		    	continue;
			}
		    else if(b==0 && c==0)
		    	cout << "������������" << endl;
	    	else
		    	f1( a, b, c);
			break;
		}
    	else if(b*b-4*a*c>0)
    		f2( a, b, c);
		else if(b*b-4*a*c==0)
	    	f3( a, b, c);
    	else
	    	f4( a, b, c);
		break;
	}

	return 0;
}