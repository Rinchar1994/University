/*1252337 电子一班 王佳琪*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[5][5];
	cout<<"请输入二维数组5*5（先行后列）"<<endl;
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<5;i++)
	{
		int m,n=0,k,l,z=0,y;
		for(j=0;j<5;j++)
		{
			for(m=0;m<5;m++)
			{
				if(a[i][j]>=a[i][m])
					n++;
				else
					n=0;
			}
			if(n==5)
			{
				k=j;
				break;
			}
		}
		for(l=0;l<5;l++)
		{
			if(a[i][k]<=a[l][k])
				z++;
			else
				z=0;
		}
		if(z==5)
		{
			y=i;
		    cout<<a[y][k]<<endl;
			break;
		}
	}
	if(i==4 && (a[4][j]>a[0][j] || a[4][j]>a[1][j] || a[4][j]>a[2][j] || a[4][j]>a[3][j]))
		cout << "没有鞍点" << endl;
	
	return 0;
}

		
