/*1252366 ���賬 ����һ��*/
#include <iostream>
using namespace std;
int main()
{
	int add(int x,int y);
	int a,b,c;
	cin>>a>>b;
	c=add(a,b);
	cout<<"a+b="<<c<<endl;
	return 0;
}
int add(int x,int y)
{
	int z;
	z=x+y;
	return(z);
}
/*������û�жԵ��ó�������������û�ж���C��û������������û�ж���Z�����ַֺ�ûд*/