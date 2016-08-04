//1252366 蒋凌超 电子一班

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct student
{
    int no;
    char name[8];
    int score;
    struct student *next;
};

int main()
{
	student *p, *q, *head;
	int i;
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
    	p=new student;
		if(p==NULL)
		    return -1;
		if(i==0)
			head=p;
		else
			q->next=p;
		infile >> p->no >> p->name >> p->score;
		p->next=NULL;
		if( p->no==9999999)
			break;
	}
	p=head;
	while(1)
	{
		cout << p->no << setw(9) << p->name << setw(4) << p->score << endl;
		p=p->next;
		if( p->no==9999999)
			break;
	}
	p=head;
	while(1)
	{
		q=p->next;
		delete p;
		p=q;
		if( p->no==9999999)
			break;
	}
	infile.close();
	return 0;
}


	

