//1252366 蒋凌超 电子一班

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
		cout << "打开文件夹失败" << endl;
		return -1;
	}
	for(i=0; ; i++)
	{
		if(i>0)
	    	q=p;
    	p=( student * )malloc( sizeof( student ));
		if(p==NULL)
		    return -1;
		if(i==0)
			head=p;
		else
			q->next=p;
		p->no=( int * )malloc( sizeof( int ));
		if(p->no==NULL)
			return -1;
		infile >> *p->no >> Name;
		p->name=( char * )malloc((1+strlen(Name))*sizeof( char ));
		if(p->name==NULL)
			return -1;
		strcpy( p->name, Name);
		p->score=( int * )malloc( sizeof( int ));
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
		free(p->score);
		free(p->name);
		free(p->no);
		free(p);
		p=q;
		if(p==NULL)
			break;
	}
	infile.close();
	return 0;
}