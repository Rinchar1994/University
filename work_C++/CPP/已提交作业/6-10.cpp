//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
#include <iomanip>
using namespace std;

void fun( double *a)
{
	int k;
	double  t;
	for( k=0; k<24; k++)
		if(*(a+k)>*(a+k+1))
		{
		    t=*(a+k);
			*(a+k)=*(a+k+1);
			*(a+k+1)=t;
		}
	for( int s=0; s<4; s++)
		for( k=0; k<23-s; k++)
			if(*(a+k)<*(a+k+1))
			{
				t=*(a+k);
				*(a+k)=*(a+k+1);
				*(a+k+1)=t;
			}
	t=*(a+24);
	*(a+24)=*(a+12);
	*(a+12)=t;
	t=*(a+23);
	*(a+23)=*a;
	*a=t;
	t=*(a+22);
	*(a+22)=*(a+4);
	*(a+4)=t;
	t=*(a+24);
	*(a+24)=*(a+20);
	*(a+20)=t;
	t=*(a+21);
	*(a+21)=*(a+20);
	*(a+20)=t;
}
	
int main()
{
	cout << "Please input 25 different numbers." << endl;
	double num[5][5], *p=num[0];
	int i, n=0;
	for( i=0; i<25; i++)
		cin >> *(p+i);
	fun( p );
	for( i=0; i<25; i++)
		{
		    cout << setw(4) <<  *(p+i);
		    n++;
		    if(n%5==0)
			    cout << endl;
	}
	return 0;
}
