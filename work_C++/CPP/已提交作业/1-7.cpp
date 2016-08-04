/*1252366 蒋凌超 电子一班*/
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
/*程序的运行结果是：
输入10 15 20时输出10
输入10 20 15时输出10
输入15 10 20时输出10
输入15 20 10时输出10
输入20 10 15时输出10
输入20 15 10时输出10
程序的功能是：提取出输入数字中最小值*/
