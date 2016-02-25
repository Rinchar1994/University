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

int InitQueue (SqQueue &Q);//�½�һ��ѭ������
int QueueLength(SqQueue Q);//����г���
int EnQueue (SqQueue &Q, QElemType e);//���
int DeQueue(SqQueue &Q, QElemType &e);//����
int QueueEmpty(SqQueue Q);//�жӿ�
int GetHead(SqQueue Q,QElemType &e);//ȡ��ͷԪ��

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

int InitQueue_L (LinkQueue &Q);//��ʼ��
int DestroyQueue_L (LinkQueue &Q);//���ٶ���
int EnQueue_L(LinkQueue &Q, QElemType e);//���
int DeQueue_L(LinkQueue &Q, QElemType &e);//����
int QueueEmpty_L(LinkQueue Q);//�жӿ�
int GetHead_L(LinkQueue Q,QElemType &e);//ȡ��ͷԪ��

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
	cout << "����ѭ������" << endl;
	SqQueue A;
	cout << "����һ���µ�ѭ������A" << endl;
	InitQueue (A);
	cout << "������Ҫ��ӵ�Ԫ�ظ���n(n<100):";
	int n, e;
	cin >> n;
	cout << endl << "������ÿ��Ԫ�ص�ֵe:";
	while( n )
	{
		cin >> e;
		EnQueue (A, e);
		n--;
	}
	cout << "���г���Ϊ��" << QueueLength(A) << endl;
	GetHead(A,e);
	cout << "����Ԫ�أ�" << e << endl;
	cout << "��ն���,�������������Ԫ��" << endl;
	while( !QueueEmpty(A) )
	{
	    DeQueue(A, e);
		cout << setiosflags(ios::right) << setw(3) << e;
	}
	free(A.base);
	cout << endl << "--------------------------------------------------" << endl;
	cout << "����������" << endl;
	LinkQueue B;
	cout << "����һ���µ�������B" << endl;
	InitQueue_L (B);
	cout << "������Ҫ��ӵ�Ԫ�ظ���n:";
	cin >> n;
	cout << endl << "������ÿ��Ԫ�ص�ֵe:";
	while( n )
	{
		cin >> e;
		EnQueue_L (B, e);
		n--;
	}
	GetHead_L(B,e);
	cout << "����Ԫ�أ�" << e << endl;
	cout << "��ն���,�������������Ԫ��" << endl;
	while( !QueueEmpty_L(B) )
	{
	    DeQueue_L(B, e);
		cout << setiosflags(ios::right) << setw(3) << e;
	}
	DestroyQueue_L (B);
	return 0;
}
