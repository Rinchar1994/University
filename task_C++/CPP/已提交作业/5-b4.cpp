//1252366 ���賬 ����һ��
#include <iostream>
using namespace std;

int main()
{
	cout << "������һ��Ӣ�����(��Сд���ӣ����ո񣬿ո���Ϊ���ʵķָ�)" << endl;
	char state[200];
	int T;
    gets(state);
	for(int i=0; i<200; i++)
	{
		T=int(state[i]);
		if((i==0 || int(state[i-1])==32) && T>=97 && T<=122)
			state[i]=char(T-32);
		else if( i!=0 && int(state[i-1])!=32 && T>=65 && T<=90)
			state[i]=char(T+32);
	}
	cout << state << endl;

	return 0;
}