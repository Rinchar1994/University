/*1252337 电子一班 王佳琪 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
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
	student *head, *p, *q; int i;
    ifstream infile; //fin 为变量名
        infile.open("list.txt",ios::in);//打开文件
        if (infile==NULL) 
		{
            cout << "打开文件失败" << endl;
            return -1;
		}
	for(i=0; ; i++) 
	{
		if (i>0)
            q=p;
        p = ( student*)malloc(sizeof(student));
        if (p==NULL)
			return -1;
		if (i==0)
			head = p; //head指向第1个结点
		else
			q->next = p;
		p->no=(int*)malloc(sizeof(int));
		if (p->no==NULL)
			return -1;
		//infile>> p->no;
		infile>> *p->no;
		
		char xx[20];
		int m=0;
		infile>>xx;
		for (i=0;xx[i]!=0;i++)
			m++;
		//p->score=(int*)malloc((m+1)*sizeof(char));
		p->name=(char*)malloc((m+1)*sizeof(char));
		if (p->name==NULL)
			return -1;
		//p->name=xx;
		strcpy( p->name, xx);
        
		p->score=(int*)malloc(sizeof(int));
		if (p->score==NULL)
			return -1;
		//infile>>p->score;
		infile>>*p->score;
		p->next = NULL;
		//if (p->no==9999999)
		if (*p->no==9999999)
			break;
		
	}
	p=head; //p复位，指向第1个结点
	//while(p->no!=9999999)
	while(*p->no!=9999999)
	{ //循环进行输出
		//cout << setw(8)<<p->no << " " <<setw(8)<< p->name << " " << setw(3)<<p->score<< endl;
		cout << setw(8)<<*p->no << " " <<setw(8)<< p->name << " " << setw(3)<<*p->score<< endl;
		p=p->next;
	}
	p=head; //p复位，指向第1个结点
	
	
	while(p) 
	{ //循环进行各结点释放
		q = p->next;
		//free(p->next);
		free(p->no);
		free(p->name);
		free(p->score);
	    free(p);
		p = q;
	}
	//
	infile.close();
	return 0;
}
