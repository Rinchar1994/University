/*1252337 ������ ����һ��*/
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
	char s[100];
	gets(s);
	int a[10];int *x=a; //��Ŀ˵����10��
	char *str=s;
	int m=0,sum=0;
	for (int n=0, j=0;*str!=0;str++,j++)
	{
	    //if (*str>=48&&*str<=57) ����ж�������ʹÿ���������ֵ��ַ���ִ��һ�Σ�����1234�ͻ� n++ 4��
		if (*str>=48&&*str<=57&&(*(str-1)<48&&*(str-1)>57||j==0))//�����
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
	//cout<<"the number of integers is :"<<i<<endl;   i���԰�
	cout<<"the number of integers is :"<<n<<endl;
	return 0;

	
}
	

	
	
	

	



		


