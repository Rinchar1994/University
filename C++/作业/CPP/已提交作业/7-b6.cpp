//1252366 蒋凌超 电子一班

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct student 
{
    int no; 
    char *name;
    char *school;
};

int main()
{
	student *p;
	int sum, sub;
	char name_1[12], school_1[10]; 
	ifstream fin;
	ofstream fout;
	fin.open("student.txt", ios::in);
	fout.open("result.txt", ios::out);
	if (fin==NULL)
	{
        cout << "打开输入文件失败" << endl;
        return -1;
	}
    if (fout==NULL) 
	{
        cout << "打开输出文件失败" << endl;
        fin.close();
        return -1;
	}
	fin >> sub >> sum;
	p = new student[ sum ];
	if(p==NULL)
		return -1;
	int i;
	for( i=0; i<sum; i++)
	{
		fin >> p[i].no >>  name_1 >> school_1;
		p[i].name = new char[strlen( name_1 )+1];
		if(p[i].name==NULL)
			return -1;
		p[i].school = new char[strlen( school_1 )+1];
		if(p[i].school==NULL)
			return -1;
		strcpy( p[i].name, name_1);
		strcpy( p[i].school, school_1);
	}
	int *m;
	m = new int[ sub ];
	if(m==NULL)
		return -1;
	for( i=0; i<sub; i++)
	{
		m[i] = rand()%sum;
		for( int j=0; j<i; j++)
			if( m[i]==m[j] )
			{
				i--;
				break;
			}
	}
	for( i=0; i<sub; i++)
		fout << p[ *(m+i) ].no << setw(13) << p[ *(m+i) ].name << setw(13) << p[ *(m+i) ].school << endl;
	for( i=0; i<sum; i++)
	{
		delete []p[i].name;
		delete []p[i].school;
	}
	delete []p;
	delete []m;
	fin.close();
	fout.close();
	cout << "已生成文件" << endl;
	return 0;
}

