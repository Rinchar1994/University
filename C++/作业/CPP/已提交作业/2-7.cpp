//1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;
int main()
{ int i,j,m,n;
  i=8;
  j=10;
  m=++i+j++;
  n=(++i)+(++j)+m;
  cout<<i<<'\t'<<j<<'\t'<<m<<'\t'<<n<<endl;
  return 0;
}
//将i中的值加1后赋予i，与j相加所得赋予m，然后j加1后赋予j，将i、j分别自加1后赋予
//i、j，再将i、j、m相加所得赋予n，最终输出10      12      19      41