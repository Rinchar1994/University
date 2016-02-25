#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define OK 1
#define FALSE 0
#define TRUE 1
#define OVERFLOW -1
#define ERROR -1
#define MAXQSIZE 100
typedef int QElemType;

typedef struct
{
   QElemType *base;
   int front;
   int rear;
}SqQueue;

int InitQueue (SqQueue &Q);//新建一个循环队列
int QueueLength(SqQueue Q);//求队列长度
int EnQueue (SqQueue &Q, QElemType e);//入队
int DeQueue(SqQueue &Q, QElemType &e);//出队
int QueueEmpty(SqQueue Q);//判队空
int GetHead(SqQueue Q,QElemType &e);//取队头元素

int InitQueue (SqQueue &Q)
{
	Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return
		(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

int EnQueue (SqQueue &Q, QElemType e)
{
	if ((Q.rear+1) % MAXQSIZE ==Q.front)
        return ERROR;
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return OK;
}

int DeQueue(SqQueue &Q, QElemType &e)
{
	if (Q.rear==Q.front)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}

int QueueEmpty(SqQueue Q)
{
	if (Q.front==Q.rear)
		return TRUE;
	return FALSE;
}

int GetHead(SqQueue Q,QElemType &e)
{
	if(QueueEmpty(Q))
		return ERROR;
	e=Q.base[Q.front];
	return OK;
}


//-----------------------------------------------------------
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

int InitQueue_L (LinkQueue &Q);//初始化
int DestroyQueue_L (LinkQueue &Q);//销毁队列
int EnQueue_L(LinkQueue &Q, QElemType e);//入队
int DeQueue_L(LinkQueue &Q, QElemType &e);//出队
int QueueEmpty_L(LinkQueue Q);//判队空
int GetHead_L(LinkQueue Q,QElemType &e);//取队头元素

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

int GetHead_L(LinkQueue Q,QElemType &e)
{
	if (QueueEmpty_L(Q))
		return ERROR;
	e=Q.front->next->data;
	return OK;
}

int main()
{
	cout << "测试循环队列" << endl;
	SqQueue A;
	cout << "建立一个新的循环队列A" << endl;
	InitQueue (A);
	cout << "请输入要添加的元素个数n(n<100):";
	int n, e;
	cin >> n;
	cout << endl << "请输入每个元素的值e:";
	while( n )
	{
		cin >> e;
		EnQueue (A, e);
		n--;
	}
	cout << "队列长度为：" << QueueLength(A) << endl;
	GetHead(A,e);
	cout << "队首元素：" << e << endl;
	cout << "清空队列,并依此输出队列元素" << endl;
	while( !QueueEmpty(A) )
	{
	    DeQueue(A, e);
		cout << setiosflags(ios::right) << setw(3) << e;
	}
	free(A.base);
	cout << endl << "--------------------------------------------------" << endl;
	cout << "测试链队列" << endl;
	LinkQueue B;
	cout << "建立一个新的链队列B" << endl;
	InitQueue_L (B);
	cout << "请输入要添加的元素个数n:";
	cin >> n;
	cout << endl << "请输入每个元素的值e:";
	while( n )
	{
		cin >> e;
		EnQueue_L (B, e);
		n--;
	}
	GetHead_L(B,e);
	cout << "队首元素：" << e << endl;
	cout << "清空队列,并依此输出队列元素" << endl;
	while( !QueueEmpty_L(B) )
	{
	    DeQueue_L(B, e);
		cout << setiosflags(ios::right) << setw(3) << e;
	}
	DestroyQueue_L (B);
	return 0;
}
