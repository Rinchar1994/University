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

typedef  struct QNode //Ԫ�ؽ��
{
   QElemType data;
   struct QNode *next;
}QNode, *QueuePtr;

typedef struct//������
{
   QueuePtr  front;  	//��ͷָ��
   QueuePtr  rear;	//��βָ��
}LinkQueue;

int InitQueue_L (LinkQueue &Q);//�����г�ʼ��
int DestroyQueue_L (LinkQueue &Q);//���ٶ���
int EnQueue_L(LinkQueue &Q, QElemType e);//���
int DeQueue_L(LinkQueue &Q, QElemType &e);//����
int QueueEmpty_L(LinkQueue Q);//�жӿ�
void QueuePrint_L(LinkQueue Q);//��ӡ����

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
int InitStack_L (QueuePtr &s);//��ջ�ĳ�ʼ������
int  Push_L (QueuePtr &s, QElemType e);//��ջ��ջ����
int  Pop_L (QueuePtr &s, QElemType &e);//��ջ��ջ����
void Print_L( QueuePtr &s );//��ջ���ݴ�ӡ
int GetTOp_L(QueuePtr &s);//����ջ��Ԫ��ֵ
void Destroy_L(QueuePtr &s);//ջ������

int InitStack_L (QueuePtr &s)//��ջ�ĳ�ʼ������
{
	 s=(QueuePtr)malloc(sizeof(QNode));
	 if (!s)
		 return (OVERFLOW);
	 s->next = NULL;
	 return OK;
}
int  Push_L (QueuePtr &s, QElemType e)//��ջ��ջ����
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

int  Pop_L (QueuePtr &s, QElemType &e)//��ջ��ջ����
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
void match();//������ƥ��
char Precede(char a,char b);//�Ƚ�����������ȼ�
int EvaluateExpression();//���ʽ��ֵ,���Դ���9,�������붼��ȷ
int Operate( int a, int b, int c );//��������㷽ʽ
void Change_L(QueuePtr &A);//����׺���ʽת���ɺ�׺���ʽ(С�ڵ���9��

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
						cout << "ƥ�䲻�ɹ�" << endl;
					break;
				case ')':
					if( char(A->data) == '(' )
					{
						Pop_L( A, x);
					    ch = getchar();
					}
					else
						cout << "ƥ�䲻�ɹ�" << endl;
					break;
				case '}':
					if( char(A->data) == '{' )
					{
						Pop_L( A, x);
					    ch = getchar();
					}
					else
						cout << "ƥ�䲻�ɹ�" << endl;
					break;
			}
		}
	}
	if( !(A->next) )
		cout << "ƥ��ɹ�" << endl;
	if( A->next && A->data != '#' && A->data != ']' && A->data != '}' && A->data != ')' )
		cout << "ƥ�䲻�ɹ�" << endl;
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
	cout << "��׺���ʽΪ��";
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
		cout << "    *   1��������ƥ��                                          *" << endl;
		cout << "    *   2�����ʽ����ֵ                                        *" << endl;
		cout << "    *   3������׺���ʽת���ɺ�׺���ʽ��ʵ�ֱ��ʽ����ֵ      *" << endl;
		cout << "    *   4���˳�                                                *" << endl;
		cout << "    *                                                          *" << endl;
		cout << "    ************************************************************" << endl;
		cin >> i;
		switch( i )
		{
		    case 1:
			    cout << "����#��ʾ���ʽ�������" << endl;
				cout << "��������ʽ��";
				ch = getchar();
				match();
				cout << endl;
				break;
			case 2:
				cout << "����#��ʾ���ʽ�������" << endl;
				cout << "��������ʽ��";
				ch = getchar();
				cout << "���Ϊ" << EvaluateExpression() << endl << endl;
				break;
			case 3:
				cout << "����#��ʾ���ʽ�������" << endl;
				cout << "��������ʽ(9�������㣩��";
				QueuePtr A;
	            InitStack_L (A);
				ch = getchar();
				Change_L(A);
				cout << "���Ϊ" << GetTOp_L(A) << endl << endl;
				Destroy_L(A);
				break;
			case 4:
				break;
			default:
				cout << "�޶�Ӧѡ��" << endl;
		}
		if( i == 4 )
			break;
	}
	return 0;
}
