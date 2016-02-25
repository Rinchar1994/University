#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
using namespace std;
#define OK 1
#define FALSE 0
#define TRUE 1
#define OVERFLOW -1
#define ERROR -1
typedef int QElemType;

typedef  struct QNode //元素结点
{
   QElemType data;
   struct QNode *next;
}QNode, *QueuePtr;

typedef struct//特殊结点
{
   QueuePtr  front;  	//队头指针
   QueuePtr  rear;	//队尾指针
}LinkQueue;

int InitQueue_L (LinkQueue &Q);//链队列初始化
int DestroyQueue_L (LinkQueue &Q);//销毁队列
int EnQueue_L(LinkQueue &Q, QElemType e);//入队
int DeQueue_L(LinkQueue &Q, QElemType &e);//出队
int QueueEmpty_L(LinkQueue Q);//判队空
void QueuePrint_L(LinkQueue Q);//打印队列

int InitQueue_L (LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

int DestroyQueue_L (LinkQueue &Q)
{
	while (Q.front)
    {
		Q.rear=Q.front->next;
	    free(Q.front);
        Q.front=Q.rear;
	}
	return OK;
}

int EnQueue_L (LinkQueue &Q, QElemType e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

int DeQueue_L (LinkQueue &Q, QElemType &e)
{
	QueuePtr p;
	if (Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if (Q.rear == p)
		Q.rear=Q.front;
	free(p);
	return OK;
}

int QueueEmpty_L(LinkQueue Q)
{
	if (Q.front==Q.rear)
		return TRUE;
	return FALSE;
}

void QueuePrint_L(LinkQueue Q)
{
	QueuePtr p = Q.front->next;
	while( p )
	{
		cout << setiosflags(ios::right) << setw(2) << char(p->data);
		p = p->next;
	}
}

//---------------------------------------
int InitStack_L (QueuePtr &s);//链栈的初始化操作
int  Push_L (QueuePtr &s, QElemType e);//链栈进栈操作
int  Pop_L (QueuePtr &s, QElemType &e);//链栈退栈操作
void Print_L( QueuePtr &s );//链栈内容打印
int GetTOp_L(QueuePtr &s);//返回栈顶元素值
void Destroy_L(QueuePtr &s);//栈的销毁

int InitStack_L (QueuePtr &s)//链栈的初始化操作
{
	 s=(QueuePtr)malloc(sizeof(QNode));
	 if (!s)
		 return (OVERFLOW);
	 s->next = NULL;
	 return OK;
}
int  Push_L (QueuePtr &s, QElemType e)//链栈进栈操作
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = s;
	s=p;
	return OK;
}

int  Pop_L (QueuePtr &s, QElemType &e)//链栈退栈操作
{
	QueuePtr p;
	if (!s)
		return  ERROR;
	e=s->data;
	p=s;
	s=s->next;
	free(p);
	return OK;
}

void Print_L( QueuePtr &s )
{
	QueuePtr p;
	p = s;
	while( p->next )
	{
		cout << setiosflags(ios::right) << setw(3) << p->data;
		p = p->next;
	}
}

int GetTOp_L(QueuePtr &s)
{
	if( s->next != NULL )
	    return s->data;
	else
		return ERROR;
}

void Destroy_L(QueuePtr &s)
{
	QueuePtr p = s;
	while( s )
	{
		s = s->next;
		free( p );
		p = s;
	}
}
//------------------------------------------------------
void match();//括弧的匹配
char Precede(char a,char b);//比较运算符的优先级
int EvaluateExpression();//表达式求值,可以大于9,假设输入都正确
int Operate( int a, int b, int c );//运算符运算方式
void Change_L(QueuePtr &A);//将中缀表达式转换成后缀表达式(小于等于9）

void match()
{
	QueuePtr A;
	InitStack_L (A);
	int x;
	char ch;
	ch = getchar();
	while( ch != '#')
	{
		if( ch == '[' || ch == '{' || ch == '(' )
		{
			Push_L (A, int(ch) );
			ch = getchar();
		}
		else if( ch == ']' || ch == '}' || ch == ')' )
		{
			switch( ch )
			{
			    case ']':
					if( char(A->data) == '[' )
					{
						Pop_L( A, x);
					    ch = getchar();
					}
					else
						cout << "匹配不成功" << endl;
					break;
				case ')':
					if( char(A->data) == '(' )
					{
						Pop_L( A, x);
					    ch = getchar();
					}
					else
						cout << "匹配不成功" << endl;
					break;
				case '}':
					if( char(A->data) == '{' )
					{
						Pop_L( A, x);
					    ch = getchar();
					}
					else
						cout << "匹配不成功" << endl;
					break;
			}
		}
	}
	if( !(A->next) )
		cout << "匹配成功" << endl;
	if( A->next && A->data != '#' && A->data != ']' && A->data != '}' && A->data != ')' )
		cout << "匹配不成功" << endl;
}

char Precede(char a,char b)
{
	switch( a )
	{
	    case '+':
			switch( b )
			{
			    case '+':
				case '-':
				case ')':
				case '#':
					return '>';
				default:
					return '<';
			}
			break;
		case '-':
			switch( b )
			{
			    case '+':
				case '-':
				case ')':
				case '#':
					return '>';
				default:
					return '<';
			}
			break;
		case '*':
			switch( b )
			{
			    case '+':
				case '-':
				case ')':
				case '#':
				case '*':
				case '/':
					return '>';
				default:
					return '<';
			}
			break;
		case '/':
			switch( b )
			{
			    case '+':
				case '-':
				case ')':
				case '#':
				case '*':
				case '/':
					return '>';
				default:
					return '<';
			}
			break;
		case '(':
			switch( b )
			{
			    case '+':
				case '-':
				case '*':
				case '/':
				case '(':
					return '<';
				case ')':
					return '=';
			}
			break;
		case ')':
			switch( b )
			{
			    case '+':
				case '-':
				case '*':
				case '/':
				case ')':
				case '#':
					return '>';
			}
			break;
		case '#':
			switch( b )
			{
			    case '+':
				case '-':
				case '*':
				case '/':
				case '(':
					return '<';
				case '#':
					return '=';
			}
			break;
	}
}

int EvaluateExpression()
{
	char c;
	int a, x, theta, e, d;
	QueuePtr OPTR;
	QueuePtr OPND;
    InitStack_L(OPTR);
	Push_L(OPTR,'#');
	InitStack_L(OPND);
	c = getchar();
	while( c != '#' || GetTOp_L( OPTR ) != '#' )
	{
		if( c >= '0' && c <= '9' )
		{
			a = c - '0';
			c = getchar();
			while( c >= '0' && c <= '9' )
			{
				a = a * 10 + c - '0';
				c = getchar();
			}
			Push_L(OPND, a);
		}
		else
			switch( Precede( char( GetTOp_L( OPTR ) ), c ) )
		    {
			    case '<':
					Push_L(OPTR,int(c));
					c = getchar();
					break;
				case '=':
					Pop_L (OPTR, x);
					c = getchar();
					break;
				case '>':
					Pop_L (OPTR, theta);
					Pop_L(OPND, e);
					Pop_L(OPND, d);
					Push_L(OPND, Operate( d, theta, e ) );
					break;
		    }
	}
	return GetTOp_L( OPND );
}

int Operate( int a, int b, int c )
{
	switch( b )
	{
	    case '+':
			return a + c;
		case '-':
			return a - c;
		case '*':
			return a * c;
		case '/':
			return a / c;
	}
}
void Change_L(QueuePtr &A)
{
	int c, x, theta;
	QueuePtr OPTR;
	LinkQueue OPND;
    InitStack_L(OPTR);
	Push_L(OPTR,'#');
	InitQueue_L(OPND);
	c=getchar();
	while ( c!='#' || (OPTR->data) != '#' )
	{
		if (c>='0' && c<='9')
		{
			EnQueue_L(OPND,c);
			c=getchar();
		}
        else
			switch (Precede(char(GetTOp_L(OPTR)),char(c)))
		    {
			    case '<' :
					Push_L(OPTR,c);
					c=getchar();
					break;
				case '=' :
					Pop_L(OPTR,x);
					c=getchar();
					break;
				case '>' :
				    Pop_L(OPTR,theta);
					EnQueue_L(OPND,theta);
				    break;
            }
	}
	if( c=='#' )
	{
		while( OPTR->data != '#' )
		{
			Pop_L(OPTR,theta);
			EnQueue_L(OPND,theta);
		}
		Pop_L(OPTR,theta);
		Pop_L(OPTR,theta);
		free( OPTR );
	}
	cout << "后缀表达式为：";
	QueuePrint_L(OPND);
	int d, e;
	while( OPND.front != OPND.rear )
	{
		DeQueue_L(OPND, x);
		if( x <= '9' && x >= '0' )
			Push_L( A, x-48 );
		else
		{
			Pop_L(A, d);
			Pop_L(A, e);
			Push_L( A, Operate( e, x, d) );
		}
	}
}

int main()
{
	char ch;
	int i;
	while(1)
	{
		cout << "    ************************************************************" << endl;
		cout << "    *                                                          *" << endl;
		cout << "    *   1、括弧的匹配                                          *" << endl;
		cout << "    *   2、表达式的求值                                        *" << endl;
		cout << "    *   3、把中缀表达式转换成后缀表达式，实现表达式的求值      *" << endl;
		cout << "    *   4、退出                                                *" << endl;
		cout << "    *                                                          *" << endl;
		cout << "    ************************************************************" << endl;
		cin >> i;
		switch( i )
		{
		    case 1:
			    cout << "输入#表示表达式输入结束" << endl;
				cout << "请输入表达式：";
				ch = getchar();
				match();
				cout << endl;
				break;
			case 2:
				cout << "输入#表示表达式输入结束" << endl;
				cout << "请输入表达式：";
				ch = getchar();
				cout << "结果为" << EvaluateExpression() << endl << endl;
				break;
			case 3:
				cout << "输入#表示表达式输入结束" << endl;
				cout << "请输入表达式(9以内运算）：";
				QueuePtr A;
	            InitStack_L (A);
				ch = getchar();
				Change_L(A);
				cout << "结果为" << GetTOp_L(A) << endl << endl;
				Destroy_L(A);
				break;
			case 4:
				break;
			default:
				cout << "无对应选项" << endl;
		}
		if( i == 4 )
			break;
	}
	return 0;
}
