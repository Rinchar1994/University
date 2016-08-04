//1252366 蒋凌超 电子一班

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct student
{
    int num;
 	char name[8];
	int score;
	int NO;
};

int main()
{
	int n, i, j, x;
	student *p, s;
	ifstream infile;
	infile.open("student.txt", ios::in);
	if(infile==NULL)
	{
		cout << "文件打开失败" << endl;
		return -1;
	}
	infile >> n;
	p=new student[n];
	if(p==NULL)
		return -1;
	for( i=0; i<n; i++)
		infile >> p[i].num >> p[i].name >> p[i].score;
	for(i=1; i<=n-1; i++)
		for(j=1; j<=n-i; j++)
			if(p[j-1].score<p[j].score)
			{
				s=p[j-1];
				p[j-1]=p[j];
				p[j]=s;
			}
	for(int k=0; k<n; k++)
	{
		if(k>0 && p[k-1].score==p[k].score)
		{
			p[k].NO=x;
			continue;
		}
        x=k+1;
		p[k].NO=x;
	}
	for(i=1; i<=n-1; i++)
		for(j=1; j<=n-i; j++)
			if(p[j-1].num>p[j].num)
			{
				s=p[j-1];
				p[j-1]=p[j];
				p[j]=s;
			}
	for( i=0; i<n; i++)
		cout << p[i].num << setw(9) << p[i].name << setw(4) << p[i].score << setw(4) << p[i].NO << endl;

	infile.close();
	delete p;
	return 0;
}
	


