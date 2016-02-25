//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
using namespace std;

void fun( int *a, int *b, int x, int y)
{
	for( int j=0; j<x-y; j++)
		*(a+j+y)=*(b+j);
	for( int k=0; k<y; k++)
		*(a+k)=*(b+x-y+k);
}

int main()
{
	cout << "Please inupt integer n, m(m<n and n<=20)" << endl;
	int m, n, num[21], a[21];
	while(1)
	{
		cin >> n >> m;
		if(n>20 || n<m)
		{
			cout << "Please input error, enter again." << endl;
			continue;
		}
		else
			break;
	}
	cout << "Please input integers you want." << endl;
	int *p=num, *tem=a, i;
	for( i=0; i<n; i++)
	{
		cin >> *(p+i);
		*(tem+i)=*(p+i);
	}
	fun( p, tem, n, m);
	for( i=0; i<n; i++)
		cout << *(p+i) << ' ';
	return 0;
}




	

	