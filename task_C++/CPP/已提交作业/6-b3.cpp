//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
#include <cstring>
using namespace std;

void join( char *b1, char *b2, char *b3)
{
	while( *b1!=0 || *b2!=0)
	{
		if( *b1!=0 && *b2!=0)
		{
			*b3=(*b1<*b2)?*b1:*b2;
			if(*b1<*b2)
				b1++;
			else
				b2++;
			b3++;
		}
		else if( *b1==0)
		{
			*b3=*b2;
			b2++;
			b3++;
		}
		else if( *b2==0)
		{
			*b3=*b1;
			b1++;
			b3++;
		}
	}
	*b3=0;
}


int main()
{
	char a1[20]="!#&157AMOavz", a2[20]="$%()+369BNQbew", a3[40];
	join( a1, a2, a3 );
	cout << a3 << endl;
	return 0;
}