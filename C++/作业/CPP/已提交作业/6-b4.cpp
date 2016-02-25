//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
using namespace std;

void join( char *b1, char *b2, char *b3)
{
	*b3=(*b1<*b2)?*b1:*b2;
	b3++;
	if( *b1==*b2)
	{
		b1++;
		b2++;
	}
	else if( *b1>*b2)
		b2++;
	else
		b1++;
	while(*b1!=0 || *b2!=0)
	{
		if(*b1!=0 && *b2!=0)
		{
		 	if( *b1==*b2 && *b2==*(b3-1))
			{
		    	b1++;
		    	b2++;
			}
		    else if( *b1==*b2 && *b2!=*(b3-1) )
			{
		    	*b3=*b1;
		    	b3++;
		    	b1++;
		    	b2++;
			}
			else if( *(b3-1)==*b1 || *(b3-1)==*b2)
			{
		    	if(*b1<*b2)
		    		b1++;
		    	else
		    		b2++;
			}
	    	else
			{
	    		*b3=(*b1<*b2)?*b1:*b2;
		    	if(*b1<*b2)
		    		b1++;
	    		else
		    		b2++;
		    	b3++;
			}
		}
		else if(*b1==0)
		{
			if(*b2==*(b3-1))
				b2++;
			else
			{
				*b3=*b2;
				b2++;
				b3++;
			}
		}
		else
        {
			if(*b1==*(b3-1))
				b1++;
			else
			{
				*b3=*b1;
				b1++;
				b3++;
			}
		}
	}
	*b3=0;
}


int main()
{
	char a1[20]="!#$$%%1223", a2[20]="!**ABBcce", a3[40];
	join( a1, a2, a3);
	cout << a3 << endl;
	return 0;
}