//1252366 蒋凌超 电子一班

#include <iostream>
#include <cstring>
using namespace std;

unsigned trans(char *t)
{	
	char c[32];
	unsigned s=0;
	int i, n, q, num[32]={1};
	n=strlen(t);
	for( i=0; i<n; i++)
		c[i]=*(t+n-1-i);
	c[n]=0;
	for(i=0; i<31; i++)
		num[i+1]=num[i]*2;
	for(i=0; i<n; i++)
	{
		switch(int(*(c+i)))
		{
		    case 48:
				q=0;
				break;
			case 49:
				q=1;
				break;
			default:
				break;
		}
		s=s+*(num+i)*q;
	}
	return s;
}

int main()
{
	cout << "请输入不超过32位的一个二进制数" << endl;
	char binary[32], *b=binary;
	cin >> b;
	unsigned Dec;
	Dec=trans(b);
	cout << Dec << endl;
	return 0;
}
