/*1252366 ���賬 ����һ��*/
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
/*ǰ������������֮����Ļ�Ͼ�����3��6��10�Ľ����˵�����Ǹ���С�����������򣬵�������������֮��
����˵�����������в��ܼ��ӷ��ţ����ӷ��Ż�ʹ�������������в���Ԥ����ֵ*/