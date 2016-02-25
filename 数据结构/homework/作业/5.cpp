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


int InitStack (SqStack &S);//顺序栈的初始化操作
int GetTop(SqStack S, SElemType  &e);//取顺序栈顶元素
int  Push(SqStack  &S, SElemType  e);//顺序栈进栈操作
int Pop(SqStack &S, SElemType  &e);//顺序栈退栈操作
void Print( SqStack &S );//顺序栈内容打印
int InitStack_L (LinkStack &s);//链栈的初始化操作
int  Push_L (LinkStack &s, SElemType e);//链栈进栈操作
int  Pop_L (LinkStack &s, SElemType &e);//链栈退栈操作
void Print_L( LinkStack &s );//链栈内容打印
void Conversion();//要求：输入一个非负十进制整数，输出任意进制数

int InitStack (SqStack &S)//顺序栈的初始化操作
{
	 S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	 if (!S.base)
		 return (OVERFLOW);
	 S.top=S.base;
	 S.stacksize = STACK_INIT_SIZE;
	 return OK;
}

int GetTop(SqStack S, SElemType  &e)//取顺序栈顶元素
{
	if (S.top == S.base)
		return ERROR;
	e = *(S.top-1);
	return OK;
}

int  Push(SqStack  &S, SElemType  e)//顺序栈进栈操作
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

int Pop(SqStack &S, SElemType  &e)//顺序栈退栈操作
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
		cout << "此栈为空栈" << endl;
	while( p != S.top )
	{
		cout << setiosflags(ios::right) << setw(3) << *p;
		p++;
	}
}

int InitStack_L (LinkStack &s)//链栈的初始化操作
{
	 s=(LinkStack)malloc(sizeof(SNode));
	 if (!s)
		 return (OVERFLOW);
	 s->next = NULL;
	 return OK;
}
int  Push_L (LinkStack &s, SElemType e)//链栈进栈操作
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

int  Pop_L (LinkStack &s, SElemType &e)//链栈退栈操作
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

void Conversion()//要求：输入一个非负十进制整数，输出任意进制数
{
	SqStack s;
	InitStack(s);
	int N, base, N1, e;
	cout << "请输入非负十进制整数";
	cin >> N;
	cout << "请输入要转换成的进制数";
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
	cout << "顺序栈的基本操作" << endl;
	cout << "建立一个新栈A" << endl;
	SqStack A;
	InitStack (A);
	cout << "请输入栈的项数:";
	int num, e;
	cin >> num;
	cout << "请输入栈各项的元素" << endl;
	while( num )
	{
		cin >> e;
		Push(A, e);
		num--;
	}
	cout << "栈A的内容为（最开始的先输出）：" << endl;
	Print( A );
	cout << endl << "栈顶的内容为:";
	GetTop(A, e);
	cout << e << endl;
	cout << "退栈" << endl;
	while( A.base != A.top )
	    Pop(A, e);
    free(A.base);

	cout << "------------------------------------------------------" << endl;
	cout << "链栈的基本操作" << endl;
	cout << "建立一个新栈B" << endl;
	LinkStack B;
	InitStack_L (B);
	cout << "请输入栈的项数:";
	cin >> num;
	cout << "请输入栈各项的元素" << endl;
	while( num )
	{
		cin >> e;
		Push_L(B, e);
		num--;
	}
	cout << "栈B的内容为（最开始的最后输出）：" << endl;
	Print_L( B );
	cout << endl << "退栈" << endl;
	while( B->next )
	    Pop_L(B, e);
    free(B);
    cout << "------------------------------------------------------" << endl;
	cout << "进制转换" << endl;
    Conversion();
	return 0;
}
