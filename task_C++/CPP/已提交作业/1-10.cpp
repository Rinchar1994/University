/*1252366 蒋凌超 电子一斑*/
#include <iostream>
using namespace std;
int main()
{
	void sort(int x,int y,int z);
	int x,y,z;
	cin>>x>>y>>z;
	sort(x,y,z);
	return 0;
}
void sort(int x,int y,int z)
{
	int temp;
	if (x>y) {temp=x;x=y;y=temp;}
	if (z<x)  cout<<z<<','<<x<<','<<y<<endl;
	  else if (z<y) cout<<x<<','<<z<<','<<y<<endl;
	    else cout<<x<<','<<y<<','<<z<<endl;
}
/*前三组数据运行之后屏幕上均出现3，6，10的结果，说明这是个从小到大的排序程序，第四组数据运行之后
出错，说明输入数据中不能夹杂符号，夹杂符号会使后面两个变量有不可预见的值*/