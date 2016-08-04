//1252366 蒋凌超 电子一班

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	int grade[1001];
	ifstream data;
	data.open( "score.dat", ios::in);
	if(data==NULL)
	{
		cout << "打开文件夹失败" << endl;
		return -1;
	}

	int num, i;
    for( i=0; i<1001; i++)
	{
		data >> grade[i];
		if(grade[i]==-1)
		{
			for(int k=i; k<1001; k++)
				grade[k]=0;
			num=i;
			break;
		}
		if(i==1000 && grade[i]!=-1)
			num=1000;
	}
	int m, n, t;
	for( m=1; m<num; m++)
		for( n=1; n<=num-m; n++)
			if(grade[n-1]<grade[n])
			{
				t=grade[n-1];
				grade[n-1]=grade[n];
				grade[n]=t;
			}
    
	int x;
	for(int j=0; j<num; j++)
	{
		if(j>0 && grade[j]==grade[j-1])
		{
			cout << setw(4) << grade[j] << ' ' << setw(4) << x << ' ';
			if((j+1)%5==0)
				cout << endl;
			continue;
		}
		x=j+1;
		cout << setw(4) << grade[j] << ' ' << setw(4) << x << ' ';
		if((j+1)%5==0)
			cout << endl;
	}
	cout << endl;

	data.close();
	return 0;
}
/*因为是一列的话显示不完整，所以我弄成了5个一行*/
