//1252366 ���賬 ����һ��

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct student 
{
    int *no; 
    char *name;
    int *score;
    struct student *next;
};

int main()
{
	student *p=NULL, *q, *head;
	int i;
	char Name[9];
	ifstream infile;
	infile.open("list.txt",ios::in);
	if(infile==NULL)
	{
		cout << "���ļ���ʧ��" << endl;
		return -1;
	}
	for(i=0; ; i++)
	{
		if(i>0)
	    	q=p;
    	p= new student;
		if(p==NULL)
		    return -1;
		if(i==0)
			head=p;
		else
			q->next=p;
		p->no= new int;
		if(p->no==NULL)
			return -1;
		infile >> *p->no >> Name;
		p->name= new char[strlen(Name)+1];
		if(p->name==NULL)
			return -1;
		strcpy( p->name, Name);
		p->score= new int;
		if(p->score==NULL)
			return -1;
		infile >> *p->score;
		p->next=NULL;
		if( *p->no==9999999)
			break;
	}
	p=head;
	while(1)
	{
		if(*p->no==9999999)
			break;
		cout << *p->no << setw(9) << p->name << setw(4) << *p->score << endl;
		p=p->next;
	}
	p=head;
	while(1)
	{
		q=p->next;
		delete p->score;
		delete []p->name;
		delete p->no;
		delete p;
		p=q;
		if(p==NULL)
			break;
	}
	infile.close();
	return 0;
}