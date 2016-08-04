// 1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;
int main()
{
	double x,y;
	cout<<"请输入任意坐标（x,y）"<<endl;
	cin>>x>>y;
	if(x>0 && y>0 && y+x-3<=0)
		cout<<"建筑高度h=1m"<<endl;
	else if(x>0 && y<0 && y-x+3>=0)
		cout<<"建筑高度h=2m"<<endl;
	else if(x<0 && y<0 && y+x+3>=0)
		cout<<"建筑高度h=3m"<<endl;
	else if(x<0 && y>0 && y-x-3<=0)
		cout<<"建筑高度h=4m"<<endl;
	else if(x==0 || y==0)
		cout<<"塔交界处"<<endl;
	else
		cout<<"建筑高度h=0m"<<endl;

	return 0;
}