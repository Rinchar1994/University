/* 1252337 王佳琪 电子一班 */
#include <iostream>
using namespace std;
int tj_strlen(const char *str)
{
    int n=0;
	for(;*str!=0;str++)
		n=n+1;
	return n;

}
char *tj_strrev(char *str)
{
	
	int m;
	m=tj_strlen(str);
	char y[20];
	char *z=y+m;
	*z--=0;
	for(;*str!=0;str++,z--)
	{
		*z=*str;
	}
	str-=m;
	for(int i=0;i<m;i++)
		str[i]=y[i];
	return str;
}

int main()
{
	int tj_strlen(const char *str);
	
	char *tj_strrev(char *str);
	char a[20],b[20];
	gets(a);
	for(int i=0;i<20;i++)
		b[i]=a[i];
	int m=tj_strlen(b);
    char *c=b;
	int sum=0;
	char *d=tj_strrev(a);
	for( i=0;a[i]!=0;c++,d++)
	{
		if (*d==*c)
			sum++;
		i++;
	}
	if(sum==i)
		cout<<"yes";
	else if(m==0||(b[0]==' '&&m==1))
		cout<<"yes";
	else cout<<"no";
    return 0;
}

