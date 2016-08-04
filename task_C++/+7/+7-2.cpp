/*1252337 电子一班 王佳琪*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[3][30],t[30];
	cin >> a[0] >> a[1] >> a[2];//这个我解释过了，应该是比较清楚的，个人认为
	//这里你用了p,q,m来代替strcmp，老师说不痛编译器中比较之后的值不确定，如果把比较结果赋值给int型变量
	//假设结果是0.1，它也是0了，所以我直接将strcmp拿去比较
    if(strcmp( a[2], a[1])<0)
	{
        for(int i=0; i<30; i++)
			t[i]=a[2][i];
		for(int j=0; j<30; j++)
			a[2][j]=a[1][j];
		for(int k=0; k<30; k++)// 这个步骤是令a[2]>a[1],减少后面讨论次数
			a[1][k]=t[k];// 欲哭无泪了、、、、我竟然把k,j都写成了i 0.0
	}
	if(strcmp( a[1], a[0])>=0)
	    cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
	else if(strcmp(a[0],a[2])>=0)
		cout << a[1] << ' ' << a[2] << ' ' << a[0] << endl;
	else
	    cout << a[1] << ' ' << a[0] << ' ' << a[2] << endl;
	return 0;
}//==、 错了这么多次 真不好意思。

