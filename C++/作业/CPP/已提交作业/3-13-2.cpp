//1252366 ���賬 ����һ��
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i,c;
	float w;
	cout<<"������������i:";
	cin>>i;
	if(i>1e6)
		c=10;
	else
		c=i/1e5;
	switch (c)
	{
	case 0:
		w=i*10/100;
	break;
	case 1:
		w=1e4+(i-1e5)*7.5/100;
	break;
	case 2:
	case 3:
		w=17500+(i-2e5)*5/100;
	break;
	case 4:
	case 5:
		w=27500+(i-4e5)*3/100;
	break;
	case 6:
	case 7:
	case 8:
	case 9:
		w=33500+(i-6e5)*1.5/100;
	break;
	case 10:
		w=39500+(i-1e6)*1/100;
	}
	cout<<"����������"<<setiosflags(ios::fixed)<<setprecision(2)<<w<<endl;

	return 0;
}


