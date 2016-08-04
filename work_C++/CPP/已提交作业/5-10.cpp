// 1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;

int main()
{
	char passage[3][81];
	int CH=0, ch=0, num=0, spa=0, oth=0, T;
	cout << "Please enter three statements, including blank space, and the the number of characters "; 
	cout <<	"of every statement should be smaller than 81." << endl;
	for(int i=0; i<3; i++)
		gets(passage[i]);
	for(int line=0; line<3; line++)
	{
		oth=0;
		for(int list=0; list<81; list++)
		{
			T=int(passage[line][list]);
			if(T>=65 && T<=90)
				CH=CH+1;
			else if(T>=97 && T<=122)
				ch=ch+1;
			else if(T>=48 && T<=57)
				num=num+1;
			else if(T==32)
				spa=spa+1;
			else if(T!=0)
				oth=oth+1;
			else 
				break;
		}
		cout << "There are " << CH << ' ' << "upper case letters, " << ch << ' ' << "lower case letters, ";
		cout << num << ' ' << "numbers, " << spa << ' ' << "blank spaces, " << oth << ' ' << "other characters ";
		cout << "in the line " << (line+1) << "." << endl;
	}

	return 0;
}
				

