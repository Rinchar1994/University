/*1252366 ���賬 ����һ��*/
#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    int f(int x,int y,int z);
    cin>>a>>b>>c;
    c=f(a,b,c);
    cout<<c<<endl;
    return 0;
}
int f(int x,int y,int z)
{
    int m;
    if(x<y) m=x;
    else m=y;
    if(z<m) m=z;
    return(m);
}
/*��������н���ǣ�
����10 15 20ʱ���10
����10 20 15ʱ���10
����15 10 20ʱ���10
����15 20 10ʱ���10
����20 10 15ʱ���10
����20 15 10ʱ���10
����Ĺ����ǣ���ȡ��������������Сֵ*/
