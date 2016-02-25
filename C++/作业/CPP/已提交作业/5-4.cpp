//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;

int main()
{
	double str1[]={0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	double str2[11];
	double a;
	int i,j;
	cout << "Plese enter a number,and place into the aray in the specific raw." << endl;
	cin >> a;
	for(i=0; i<10; i++)
	{
		for(j=0; j<i; j++)
			str2[j]=str1[j];
		if(str1[i]>=a)
		{
			j=i;
			str2[j]=a;
			for(int j=i+1; j<11; j++)
				str2[j]=str1[j-1];
			break;
		}
		if(i==9)
		{
			str2[9]=str1[9];
			str2[10]=a;
		}
	}
	for(int k=0; k<10; k++)
		cout << str2[k] << ' ';
	cout << str2[10] << endl;
	return 0;
}

				




    
