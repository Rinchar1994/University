// 1252366 ���賬 ����һ��
#include <iostream>
using namespace std;
int main()
{
	double x,y;
	cout<<"�������������꣨x,y��"<<endl;
	cin>>x>>y;
	if(x>0 && y>0 && y+x-3<=0)
		cout<<"�����߶�h=1m"<<endl;
	else if(x>0 && y<0 && y-x+3>=0)
		cout<<"�����߶�h=2m"<<endl;
	else if(x<0 && y<0 && y+x+3>=0)
		cout<<"�����߶�h=3m"<<endl;
	else if(x<0 && y>0 && y-x-3<=0)
		cout<<"�����߶�h=4m"<<endl;
	else if(x==0 || y==0)
		cout<<"�����紦"<<endl;
	else
		cout<<"�����߶�h=0m"<<endl;

	return 0;
}