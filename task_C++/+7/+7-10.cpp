/*1252337 ����һ�� ������ */
#include <iostream>
#include <cstdlib>
#include <string>
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
	student *head, *p, *q; int i;
    ifstream infile; //fin Ϊ������
        infile.open("list.txt",ios::in);//���ļ�
        if (infile==NULL) 
		{
            cout << "���ļ�ʧ��" << endl;
            return -1;
		}
		p->no=3;
	for(i=0; p->no !=9999999; i++) 
	{
		if (i>0)
            q=p;
        p = new student;
        if (p==NULL)
			return -1;
		if (i==0)
			head = p; //headָ���1�����
		else
			q->next = p;
		infile>> p->no >> p->name>> p->score; 
		p->next = NULL;
	}
	p=head; //p��λ��ָ���1�����
	while(p->no!=9999999)
	{ //ѭ���������
		cout << p->no << " " << p->name << " " << p->score<< endl;
		p=p->next;
	}
	p=head; //p��λ��ָ���1�����
	while(p->no!=9999999) 
	{ //ѭ�����и�����ͷ�
		q = p->next;
		delete p;
		p = q;
	}
	infile.close();
	return 0;
}
