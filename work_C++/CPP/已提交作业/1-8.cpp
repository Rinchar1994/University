/*1252366 蒋凌超 电子一斑*/
#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	cout<<"a+b="<<a+b;
	return 0;
}
/*缺失预处理指令，第三行多了“；”C值没有定义，缺少输入流对象，运行结束时操作系统没有返回零值*/
