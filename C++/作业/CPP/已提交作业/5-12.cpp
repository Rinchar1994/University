//1252366 蒋凌超 电子一班
#include <iostream>
using namespace std;

int main()
{
	char pcd[]="akdfDFA./.DFAaihdajai";
	char orig[22];
	int T;
	for(int i=0; i<22; i++)
	{
		T=int(pcd[i]);
		if(T>=65 && T<=90)
			orig[i]=155-T;
		else if(T>=97 && T<=122)
			orig[i]=219-T;
		else
			orig[i]=pcd[i];
	}
	cout << "The passcode is: " << pcd << endl;
	cout << "The original statement is: " << orig << endl;

	return 0;
}
//密码是初始化输入的
		
