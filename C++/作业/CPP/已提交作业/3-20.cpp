//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;
int main()
{
	int N,n,a;
	for(N=2;N<=1000;N++)
	{
		for(n=1,a=0;n<N;n++)
		{
			if(N%n==0)
			{
				a=a+n;
			}
		}
		if(a==N)
		{
			cout<<N<<",its factors are 1";
			for(n=2;n<N;n++)
			{
				if(N%n==0)
					cout<<","<<n;
			}
			cout<<endl;
		}
	}
	return 0;
}
	
