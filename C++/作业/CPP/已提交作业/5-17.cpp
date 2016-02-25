//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;

const int N=10;
char name[N][20],num[N][8],grade[N][4];

void input_data()
{
	int i;
	for( i=0; i<N; i++)
	{
		cout << "Please input name: ";
		gets(name[i]);
		cout << "   NO.: ";
		gets(num[i]);
		cout << "   grade: ";
		gets(grade[i]);
		cout << endl;
	}
}

int main()
{
	int n=0;
	input_data();
	for(int j=0; j<N; j++)
	{
		if((int)grade[j][2]==0 && (int)grade[j][0]<54)
		{
			cout << name[j] << ' ' << "did not pass the test, his number is " << num[j] << ", ";
			cout << "his grade is " << grade[j] << endl;
			n=n+1;
		}
	}
	if(n==0)
		cout << "All the students pass the test." << endl;

	return 0;
}




	


