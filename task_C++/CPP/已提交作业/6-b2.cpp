//1252366 ½¯Áè³¬ µç×ÓÒ»°à

#include <iostream>
#include <cstring>
using namespace std;

void fun( char *b)
{
	int n;
	char c[1000];
	n=strlen(b);
	for(int i=0; i<n; i++)
		c[i]=*(b+n-1-i);
	c[n]=0;
	if(n==0 || n==1)
		cout << "Yes" << endl;
	else if( strcmp( b, c)==0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main()
{
	char a[1000], *array=a;
	cout << "Please input an array" << endl;
	gets(a);
	fun(array);
	return 0;
}
