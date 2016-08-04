//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;

int main()
{
	cout << "Please enter 16 different numbers." << endl;
	double a[4][4];
	double max;
	for(int k=0; k<4; k++)
		for (int m=0; m<4; m++)
			cin >> a[k][m];
	for (int i=0; i<4; i++)
	{
		int s;
		max=a[i][0];
		for (int j=0; j<4; j++)
		{
			if(j>=1 && a[i][j]>a[i][j-1])
			{
				max=a[i][j];
				s=j;
			}
		}
		if(max<=a[0][s] && max<=a[1][s] && max<=a[2][s] && max<=a[3][s])
		{
			cout << "The saddle point is " << max << endl;
			break;
		}
		else if(i==3)
			cout << "There is no saddle point in the array." << endl; 
	}

	return 0;
}



