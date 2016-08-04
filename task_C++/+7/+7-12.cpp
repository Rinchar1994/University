/*1252337 电子一班 王佳琪 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student
{
	int num;
	char name[8];
	int score;
	int o;
};
int main()
{
	int  n,m;
    ifstream infile; //fin 为变量名
    infile.open("student.txt",ios::in);//打开文件
    if (infile==NULL) 
	{
        cout << "打开文件失败" << endl;
        return -1;
	}
    infile>>n;
	Student *p=new Student[n];
	Student max;
	for(int i=0;i<n;i++)
		infile>>p[i].num>>p[i].name>>p[i].score;

    infile.close(); //关闭文件

	for (i=0;i<n-1;i++)
	{
		
		for(int j=i+1;j<n;j++)
		{
			if (p[j].score >p[i].score)
			{
				m=j;
			    max=p[m];
		        p[j]=p[i];
		        p[i]=max;
			}
		}
	}


    int k=1,x=1;
	for(i=1,p[0].o=1;i<n;i++)
	{
	    if (p[i].score!=p[i-1].score)
		{
			if(x!=1)
				k+=x;
			else 
				k++;
			x=1;
		    p[i].o=k;
		    
		}
		else if (p[i].score==p[i-1].score)
		{
			p[i].o=k;
			x++;
		}
	}
    Student min;
	for (i=0;i<n-1;i++)
	{

		int m=i;
		for(int j=i+1;j<n;j++)
		{
			if (p[j].num<p[i].num&&p[j].o==p[i].o)
			{
				m=j;
		        min=p[m];
		        p[j]=p[i];
		        p[i]=min;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		cout<<setw(8)<<p[i].num<<' '<<setw(6)<<p[i].name<<' '<<setw(4)<<p[i].score<<' '<<setw(3)<<p[i].o<<endl;
	}
	delete p; 
	return 0;
}








