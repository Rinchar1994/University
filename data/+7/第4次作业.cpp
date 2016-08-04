#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define OK 1
#define OVERFLOW -1
#define ERROR -1
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
typedef int QElemType;
typedef int Status;

typedef  struct QNode //Ԫ�ؽ��
{	
   QElemType  data;
   struct  QNode *next;
}QNode, *QueuePtr;

typedef struct  //������ 
{                          
   QueuePtr  front;  	//��ͷָ��
   QueuePtr  rear;	    //��βָ��
}LinkQueue;

#define MAXSIZE 100
typedef struct {
   QElemType  *base;
   int   front;
   int   rear;
  }SqQueue;


Status InitQueue (LinkQueue &Q) //�����г�ʼ��
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) 
		exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}


Status DestroyQueue (LinkQueue &Q)//�����е�����
{	
	while (Q.front)
	{  
		Q.rear=Q.front->next;
	    free(Q.front);
        Q.front=Q.rear;
	}
	return OK;
}

Status EnQueue (LinkQueue &Q, QElemType e)//�����еĲ���
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

Status DeQueue (LinkQueue &Q, QElemType &e)//�����е�ɾ��
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

Status QueueEmpty(LinkQueue Q)//�ж��������Ƿ�Ϊ��
{
	if (Q.front==Q.rear) 
		return OK;
	return 0;
}

Status GetHead(LinkQueue Q,QElemType &e)//ȡ�����еĵ�һ��Ԫ��//���������������
{
	if (QueueEmpty(Q)) 
		return ERROR;
	e=(Q.front)->next->data;
	return OK;
}

void Print_Q(LinkQueue &Q)//�����е����
{
	QueuePtr p;
	p=Q.front;
	p=p->next;
	while(p!=Q.rear)
	{
		cout << setiosflags(ios::right) << setw(3) << p->data;
		p=p->next;
	}
	cout << setiosflags(ios::right) << setw(3) << p->data<<endl;

}
Status InitQueue (SqQueue &Q)//ѭ�����еĳ�ʼ��
{
	Q.base=(QElemType *)malloc(MAXSIZE*sizeof(QElemType));
	if (!Q.base) exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}
int QueueLength(SqQueue Q)//��ѭ�����г���
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue (SqQueue &Q, QElemType e)//ѭ���������
{
	if ((Q.rear+1) % MAXSIZE ==Q.front) 
    return ERROR;
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue &Q, QElemType &e)//ѭ�����г���
{
	if (Q.rear==Q.front) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
Status QueueEmpty(SqQueue Q)//�ж�ѭ�������Ƿ�Ϊ��
{
	if (Q.front==Q.rear) return OK;
	return 0;
}
Status GetHead(SqQueue Q,QElemType &e)//ȡѭ�����ж�ͷԪ��
{
	if (QueueEmpty(Q)) 
		return ERROR;
	e=Q.base[Q.front];
	return OK;
}

void Print_S(SqQueue Q)//ѭ�����е����
{
	for(int i=0;i<QueueLength(Q)+1;i++)
	{
		cout<<setiosflags(ios::right) << setw(3) << Q.base[Q.front]<<endl;
		Q.front=(Q.front+1)%MAXSIZE;
	}
	cout<<setiosflags(ios::right) << setw(3) << Q.base[Q.front%MAXSIZE]<<endl;
}

int main()
{
	cout<<"�����еĻ�������"<<endl;
    LinkQueue Q;
	InitQueue (Q);
    cout << "�����������е�����:";
	int num, e;
	cin >> num;
	cout << "�����������и����Ԫ��" << endl;
	while( num )
	{
		cin >> e;
		EnQueue (Q, e);
		num--;
	}
	cout << "������Q������Ϊ���Ӷ�ͷ����β����" << endl;
	Print_Q(Q);
	cout<<"������������Ҫ�����Ԫ��e=";
	int e1;
	cin>>e1;
    EnQueue (Q,  e1);
    cout << "�����������Q������Ϊ���Ӷ�ͷ����β����" << endl;
	Print_Q(Q);

	cout<<"�����е�ɾ������"<<endl;
	int e2;
	DeQueue (Q, e2);
    cout << "ɾ����������Q������Ϊ���Ӷ�ͷ����β����" << endl;
	Print_Q(Q);
    cout<<"ɾ����Ԫ��Ϊe="<<e2<<endl;

	int e4;
	GetHead(Q,e4);
	cout<<"�����еĵ�һ��Ԫ��Ϊ��"<<e4<<endl;

	DestroyQueue (Q);




	cout<<"ѭ�����еĻ�������"<<endl;
    SqQueue S;
	InitQueue (S);
    cout << "������ѭ�����е�����:";
	int num1, e5;
	cin >> num1;
	cout << "������ѭ�����и����Ԫ��" << endl;
	while( num1 )
	{
		cin >> e5;
		EnQueue (S, e5);
		num1--;
	}
	cout << "ѭ������S������Ϊ���Ӷ�ͷ����β����" << endl;
	Print_S(S);
	cout<<"������ѭ������Ҫ�����Ԫ��e=";
	int e6;
	cin>>e6;
    EnQueue (S,  e6);
    cout << "�����ѭ������Q������Ϊ���Ӷ�ͷ����β����" << endl;
	Print_S(S);

	cout<<"ѭ�����е�ɾ������"<<endl;
	int e7;
	DeQueue (S, e7);
    cout << "ɾ����ѭ������Q������Ϊ���Ӷ�ͷ����β����" << endl;
	Print_S(S);
    cout<<"ɾ����Ԫ��Ϊe="<<e7<<endl;

	int e8;
	GetHead(S,e8);
	cout<<"ѭ�����еĵ�һ��Ԫ��Ϊ��"<<e8<<endl;

//	DestroyQueue (S);

	return 0;
}
