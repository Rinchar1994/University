
//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[3][31],tem[31];
	cout << "Please input three strings: ";
	cin >> str[0] >> str[1] >> str[2];
	if(strcmp( str[1], str[2])>0)
	{
		for(int i=0; i<31; i++)
			tem[i]=str[1][i];
		for(int j=0; j<31; j++)
			str[1][j]=str[2][j];
		for(int k=0; k<31; k++)
			str[2][k]=tem[k];
	}
	if(strcmp( str[0], str[1])<=0)
		cout << str[0] << ' ' << str[1] << ' ' << str[2] << endl;
	else if(strcmp( str[0], str[2])<=0)
		cout << str[1] << ' ' << str[0] << ' ' << str[2] << endl;
	else
		cout << str[1] << ' ' << str[2] << ' ' << str[0] << endl;

	return 0;
}
