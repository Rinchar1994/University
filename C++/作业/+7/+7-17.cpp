/*1252337 ������ ����һ��*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h> 
#include <time.h> 
#include <string>
using namespace std;
class student
{
public:
	char *num;
	char *name;
	char *school;
};

int main()
{
	int N, M;
	student *p;
    ifstream fin; //fin Ϊ������
    ofstream fout; //fout Ϊ������
    fin.open("student.txt", ios::in);//�������ļ�
    fout.open("result.txt",ios::out);//������ļ�
    if (fin==NULL) 
	{
        cout << "�������ļ�ʧ��" << endl;
        return -1;
	}
    if (fout==NULL) 
	{
		cout << "������ļ�ʧ��" << endl;
		fin.close(); //�ر������ļ�
		return -1;
	}
	fin>>N;
	fin>>M;
	char num1[20];
	char name1[20];
	char school1[20];
	p=new student[M];
    for (int i=0;i<M;i++)
	{
		
		//char num1[20];
		int m=0;
		fin>>num1;
		for(int j=0;num1[j]!=0;j++)
			m++;
		p[i].num=new char[m+1];
		strcpy(p[i].num,num1);

		//char name1[20];
		m=0;
		fin>>name1;
		for(int k=0;name1[k]!=0;k++)
			m++;
		p[i].name=new char[m+1];
		strcpy(p[i].name,name1);

		//char school1[20];
	    m=0;
		fin>>school1;
		for(int l=0;school1[l]!=0;l++)
			m++;
		p[i].school=new char[m+1];
		strcpy(p[i].school,school1);
	}
    

	int *a;
	a=new int[N];
	for (i=0;i<N;i++)
	{
		a[i]=rand()%M;
		for( int j=0; j<i; j++)
		{
			if( a[j]==a[i] )
			{
				i--;
				break;
			}
	    	fout<<p[a[i]].num<<p[a[i]].name<<p[a[i]].school<<endl;
		}
	}
	for (i=0;i<M;i++)
	{
		delete p[i].num;
		delete p[i].name;
		delete p[i].school;
	}
	delete []p;
	fin.close();
	fout.close();
	return 0;
}




