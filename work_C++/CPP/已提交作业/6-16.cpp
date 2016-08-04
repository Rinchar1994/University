//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
using namespace std;

int main()
{
	cout << "Please input an array of characters." << endl;
	char  *ch[10], s[100000], tem[100000];
	int n=0, m=0, h=0, f;
	gets(s);
	for( int i=0; *(s+i)!=0; i++)
	{
		if( (*(s+i-1)<48 || *(s+i-1)>57 || i==0) && *(s+i)>=48 && *(s+i)<=57)
		{
			n++;
		    m=1;
		}
		if(*(s+i-1)>=48 && *(s+i-1)<=57 && *(s+i)>=48 && *(s+i)<=57)
			m++;
		if( *(s+i-1)>=48 && *(s+i-1)<=57 && (*(s+i)<48 || *(s+i)>57))
		{
			f=h;
			for( int k=i-m; k<i; k++)
			{
				*(tem+h)=*(s+k);
				h++;
			}
			*(tem+h)='\0';
			h++;
			ch[n-1]=tem+f;
		}
		if(*(s+i+1)=='\0' && *(s+i)<=57 && *(s+i)>=48)
		{
			f=h;
			for( int k=i-m+1; k<=i; k++)
			{
				*(tem+h)=*(s+k);
				h++;
			}
			*(tem+h)='\0';
			h++;
			ch[n-1]=tem+f;
		}
	}
	cout << "There are " << n << ' ' << "integers." << endl;
	for( int t=0; t<n; t++)
	{
		int z=0;
		for( i=0; *(ch[t]+i)!=0; i++)
		{
			if(i==0 && *(ch[t]+i)==48)
			{
				ch[t]++;
				i--;
				if(*(ch[t]+i+1)==48 && z==0)
				{
					*ch[t]=48;
					*(ch[t]+1)=0;
					break;
				}
				continue;
			}
			else if(*(ch[t]+i-1)!=48 || *(ch[t]+i)!=48)
				z++;
		}
	}
	for( i=0; i<n; i++)
		cout << ch[i] << ' ';
	cout << endl;
	return 0;
}
