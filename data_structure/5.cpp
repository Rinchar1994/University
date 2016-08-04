#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
using namespace std;
#define OK 1
#define OVERFLOW -1
#define ERROR -1
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
typedef int SElemType;
typedef struct
{
	SElemType   *base;
	SElemType   *top;
    int   stacksize;
} SqStack;

typedef struct SNode
{
	SElemType  data;
	struct SNode  *next;
}SNode, *LinkStack;


int InitStack (SqStack &S);//˳��ջ�ĳ�ʼ������
int GetTop(SqStack S, SElemType  &e);//ȡ˳��ջ��Ԫ��
int  Push(SqStack  &S, SElemType  e);//˳��ջ��ջ����
int Pop(SqStack &S, SElemType  &e);//˳��ջ��ջ����
void Print( SqStack &S );//˳��ջ���ݴ�ӡ
int InitStack_L (LinkStack &s);//��ջ�ĳ�ʼ������
int  Push_L (LinkStack &s, SElemType e);//��ջ��ջ����
int  Pop_L (LinkStack &s, SElemType &e);//��ջ��ջ����
void Print_L( LinkStack &s );//��ջ���ݴ�ӡ
void Conversion();//Ҫ������һ���Ǹ�ʮ����������������������

int InitStack (SqStack &S)//˳��ջ�ĳ�ʼ������
{
	 S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	 if (!S.base)
		 return (OVERFLOW);
	 S.top=S.base;
	 S.stacksize = STACK_INIT_SIZE;
	 return OK;
}

int GetTop(SqStack S, SElemType  &e)//ȡ˳��ջ��Ԫ��
{
	if (S.top == S.base)
		return ERROR;
	e = *(S.top-1);
	return OK;
}

int  Push(SqStack  &S, SElemType  e)//˳��ջ��ջ����
{
	if (S.top-S.base>=S.stacksize)
    {
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if (!S.base)
			return (OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
   *S.top++ = e;
   return OK;
}

int Pop(SqStack &S, SElemType  &e)//˳��ջ��ջ����
{
	if (S.top == S.base)
		return ERROR;
	e=*--S.top;
	return OK;
}

void Print( SqStack &S )
{
	SElemType *p = S.base;
	if( S.base == S.top )
		cout << "��ջΪ��ջ" << endl;
	while( p != S.top )
	{
		cout << setiosflags(ios::right) << setw(3) << *p;
		p++;
	}
}

int InitStack_L (LinkStack &s)//��ջ�ĳ�ʼ������
{
	 s=(LinkStack)malloc(sizeof(SNode));
	 if (!s)
		 return (OVERFLOW);
	 s->next = NULL;
	 return OK;
}
int  Push_L (LinkStack &s, SElemType e)//��ջ��ջ����
{
	LinkStack p;
	p=(LinkStack)malloc(sizeof(SNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = s;
	s=p;
	return OK;
}

int  Pop_L (LinkStack &s, SElemType &e)//��ջ��ջ����
{
	LinkStack p;
	if (!s)
		return  ERROR;
	e=s->data;
	p=s;
	s=s->next;
	free(p);
	return OK;
}

void Print_L( LinkStack &s )
{
	LinkStack p;
	p = s;
	while( p->next )
	{
		cout << setiosflags(ios::right) << setw(3) << p->data;
		p = p->next;
	}
}

void Conversion()//Ҫ������һ���Ǹ�ʮ����������������������
{
	SqStack s;
	InitStack(s);
	int N, base, N1, e;
	cout << "������Ǹ�ʮ��������";
	cin >> N;
	cout << "������Ҫת���ɵĽ�����";
	cin >> base;
    N1=N;
    while (N1)
    {
		Push(s,N1%base);
        N1 = N1/base;
	}
    while (s.top != s.base)
	{
		Pop(s,e);
        if (e>9)
			putchar(e+55);
        else
			putchar(e+48);
	}
    cout << endl;
}

int main()
{
	cout << "˳��ջ�Ļ�������" << endl;
	cout << "����һ����ջA" << endl;
	SqStack A;
	InitStack (A);
	cout << "������ջ������:";
	int num, e;
	cin >> num;
	cout << "������ջ�����Ԫ��" << endl;
	while( num )
	{
		cin >> e;
		Push(A, e);
		num--;
	}
	cout << "ջA������Ϊ���ʼ�����������" << endl;
	Print( A );
	cout << endl << "ջ��������Ϊ:";
	GetTop(A, e);
	cout << e << endl;
	cout << "��ջ" << endl;
	while( A.base != A.top )
	    Pop(A, e);
    free(A.base);

	cout << "------------------------------------------------------" << endl;
	cout << "��ջ�Ļ�������" << endl;
	cout << "����һ����ջB" << endl;
	LinkStack B;
	InitStack_L (B);
	cout << "������ջ������:";
	cin >> num;
	cout << "������ջ�����Ԫ��" << endl;
	while( num )
	{
		cin >> e;
		Push_L(B, e);
		num--;
	}
	cout << "ջB������Ϊ���ʼ������������" << endl;
	Print_L( B );
	cout << endl << "��ջ" << endl;
	while( B->next )
	    Pop_L(B, e);
    free(B);
    cout << "------------------------------------------------------" << endl;
	cout << "����ת��" << endl;
    Conversion();
	return 0;
}
