//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;

int main()
{
	int t, i, j, n;
	int grade[50]={34,23,54,34,65,45,65,75,34,54,
		           12,35,76,87,98,28,84,27,13,99,
				   54,86,83,26,75,24,36,86,4,94,
				   51,100,56,75,86,24,46,78,93,24,
				   37,75,85,56,43,56,86,87,13,46};
	for(i=1; i<=49; i++)
		for(j=1; j<=50-i; j++)
			if(grade[j-1]<grade[j])
			{
				t=grade[j-1];
				grade[j-1]=grade[j];
				grade[j]=t;
			}
	for(int k=0; k<50; k++)
	{
		if(k>0 && grade[k-1]==grade[k])
		{
			cout << grade[k] << ' ' << n << endl;
			continue;
		}
        n=k+1;
		cout << grade[k] << ' ' << n << endl;
	}

	return 0;
}
		

