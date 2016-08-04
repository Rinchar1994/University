//1252366 ½¯Áè³¬ µç×ÓÒ»°à
#include <iostream>
using namespace std;
int main()
{
	int y,m,n,d,D1,D;
	bool leap;
	cout<<"ÊäÈëÄê£¬ÔÂ£¬	ÈÕ:";
	cin>>y>>m>>d;
	if(y%4==0 && y%100!=0 || y%400==0)
		leap=true;
	else
		leap=false;
	if(leap)
	{
		if(m<1 || m>12)
			cout<<"ÊäÈë´íÎó"<<endl;
		else
		{
			for(n=1,D=0;n<m;n++)
			{
		        if(n==1 || n==3 || n==5 || n==7 || n==8 || n==10)
			        D1=31;
	        	else if(n==2)
			        D1=29;
			    else
			       	D1=30;
			    D=D+D1;
			}
			if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			{
				if(d>31)
					cout<<"ÊäÈë´íÎó"<<endl;
				else
				{
	                D=D+d;
					cout<<D<<endl;
				}
			}
	       	else if(m==2)
			{
				if(d>29)
					cout<<"ÊäÈë´íÎó"<<endl;
				else
			    {
			        D=D+d;
			    	cout<<D<<endl;
				}
			}
		    else
			{
				if(d>30)
					cout<<"ÊäÈë´íÎó"<<endl;
				else
			   	{
		            D=D+d;
					cout<<D<<endl;
				}
			}
		}
	}
	else
	{
		if(m<1 || m>12)
			cout<<"ÊäÈë´íÎó"<<endl;
		else
		{
			for(n=1,D=0;n<m;n++)
			{
		        if(n==1 || n==3 || n==5 || n==7 || n==8 || n==10)
			        D1=31;
	        	else if(n==2)
			        D1=28;
			    else
			       	D1=30;
			    D=D+D1;
			}
			if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			{
				if(d>31)
					cout<<"ÊäÈë´íÎó"<<endl;
				else
				{
	                D=D+d;
					cout<<D<<endl;
				}
			}
	       	else if(m==2)
			{
				if(d>28)
					cout<<"ÊäÈë´íÎó"<<endl;
				else
			    {
			        D=D+d;
			    	cout<<D<<endl;
				}
			}
		    else
			{
				if(d>30)
					cout<<"ÊäÈë´íÎó"<<endl;
				else
			   	{
		            D=D+d;
					cout<<D<<endl;
				}
			}
		}
	}
	return 0;
}
			

		




		

