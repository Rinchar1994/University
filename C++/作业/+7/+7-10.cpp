/*1252337 电子一班 王佳琪 */
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
    ifstream infile; //fin 为变量名
        infile.open("list.txt",ios::in);//打开文件
        if (infile==NULL) 
		{
            cout << "打开文件失败" << endl;
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
			head = p; //head指向第1个结点
		else
			q->next = p;
		infile>> p->no >> p->name>> p->score; 
		p->next = NULL;
	}
	p=head; //p复位，指向第1个结点
	while(p->no!=9999999)
	{ //循环进行输出
		cout << p->no << " " << p->name << " " << p->score<< endl;
		p=p->next;
	}
	p=head; //p复位，指向第1个结点
	while(p->no!=9999999) 
	{ //循环进行各结点释放
		q = p->next;
		delete p;
		p = q;
	}
	infile.close();
	return 0;
}
