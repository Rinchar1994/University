/*1252366 蒋凌超 电子一班*/
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
/*主函数没有对调用程序做出声明，没有定义C，没有输入流对象，没有定义Z，部分分号没写*/