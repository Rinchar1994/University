//1252366 ���賬 ����һ��
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float c,F;
	cout<<"���뻪���¶�"<<endl;
	cin>>F;
	c=5*(F-32)/9;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"�����¶�c="<<c<<endl;
	return 0;
}
