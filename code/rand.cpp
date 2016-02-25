#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

void main()
{
	int M,N;
	cout << "please input M and N" << endl;
	cin >> M;
	cin >> N;
	srand((unsigned)time(NULL));
	if( M+1<N || N<(M/2+M%2-1) )
		cout << "there is no valid char string!" << endl;
	else if( N==0 )
	{
		for( int i=0; i<M; i++)
			cout << 1;
		cout << endl;
	}
	else if( N==1 )
	{
		vector<string> bit(3);
		vector<int> num(2,0);
		int pos;
		for(int i=0; i<M; i++)
		{
			while(1)
			{
				pos = rand()%2;
				if(num[pos]<2)
				{
					num[pos]++;
					break;
				}
			}
		}
		for( int i=0; i<int(bit.size()); i++)
		{
			if(i==0)
			{
				switch(num[0])
				{
					case 0: bit[i]=""; break;
					case 1: bit[i]="1"; break;
					case 2: bit[i]="11"; break;
					default: break;
				}
			}
			else if(i==bit.size()-1)
			{
				switch(num[1])
				{
					case 0: bit[i]=""; break;
					case 1: bit[i]="1"; break;
					case 2: bit[i]="11"; break;
					default: break;
				}
			}
			else
				bit[i]="0";
		}
		for(int i=0; i<int(bit.size()); i++)
			cout << bit[i];
		cout << endl;
	}
	else
	{
		//initial 0101010101.....010
		vector<string> bit;
		for( int i=0; i<2*N-1; i++ )
		{
			if(i%2==0)
				bit.push_back("0");
			else
				bit.push_back("1");
		}

		//calculate the number of '1' to insert in every pos
		//initial the number of '1' in every pos whitch can be inserted
		vector<int> add(N+1,1);
		add[0] = 0;
		add[N] = 0;

		int pos;//random pos

		for(int j=0; j<M-N+1; j++)
		{
			while(1)
			{
				pos = rand()%(add.size());
				if(add[pos]<2)
				{
					add[pos]++;
					break;
				}
			}
		}
		
		//generate final char string
	    for( int i=0; i<int(bit.size()); i++)
		{
			if(i==0)
			{
				switch(add[i])
				{
				    case 0: bit[i]="0"; break;
					case 1: bit[i]="10"; break;
					case 2: bit[i]="110"; break;
					default: break;
				}
			}
			else if(i==(bit.size()-1))
			{
				switch(add[add.size()-1])
				{
				    case 0: bit[i]="0"; break;
					case 1: bit[i]="01"; break;
					case 2: bit[i]="011"; break;
					default: break;
				}
			}
			else if(bit[i]=="1")
			{
				switch(add[(i+1)/2])
				{
					case 1: bit[i]="1"; break;
					case 2: bit[i]="11"; break;
					default: break;
				}
			}
		}
		for(int i=0; i<int(bit.size()); i++)
			cout << bit[i];
		cout << endl;

	}
	system("pause");
	
}