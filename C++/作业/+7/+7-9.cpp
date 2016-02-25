/*1252337 王佳琪 电子一班*/
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
	char s[100];
	gets(s);
	int a[10];int *x=a; //题目说最多出10个
	char *str=s;
	int m=0,sum=0;
	for (int n=0, j=0;*str!=0;str++,j++)
	{
	    //if (*str>=48&&*str<=57) 这个判断条件会使每个代表数字的字符都执行一次，比如1234就会 n++ 4次
		if (*str>=48&&*str<=57&&(*(str-1)<48&&*(str-1)>57||j==0))//理解下
			n++;
	    else if(*(str-1)>=48&&*(str-1)<=57&&n!=0)
		{
			for(int i=0;i<n;i++,str--)
			{
				sum=sum+((*str)-48)*pow(10,i);
			}
			a[m]=sum;
			m++;
			str=str+n;
		}
	}
	a[m]=0;
	
	for(int i=0;i<m-1;i++)
	{
		cout<<a[i]<<' ';
	}
	//cout<<"the number of integers is :"<<i<<endl;   i不对吧
	cout<<"the number of integers is :"<<n<<endl;
	return 0;

	
}
	

	
	
	

	



		


