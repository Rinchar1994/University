//1252366 ���賬 ����һ��
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
//��i�е�ֵ��1����i����j������ø���m��Ȼ��j��1����j����i��j�ֱ��Լ�1����
//i��j���ٽ�i��j��m������ø���n���������10      12      19      41