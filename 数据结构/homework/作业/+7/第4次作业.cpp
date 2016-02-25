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

typedef  struct QNode //元素结点
{	
   QElemType  data;
   struct  QNode *next;
}QNode, *QueuePtr;

typedef struct  //特殊结点 
{                          
   QueuePtr  front;  	//队头指针
   QueuePtr  rear;	    //队尾指针
}LinkQueue;

#define MAXSIZE 100
typedef struct {
   QElemType  *base;
   int   front;
   int   rear;
  }SqQueue;


Status InitQueue (LinkQueue &Q) //链队列初始化
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) 
		exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}


Status DestroyQueue (LinkQueue &Q)//链队列的销毁
{	
	while (Q.front)
	{  
		Q.rear=Q.front->next;
	    free(Q.front);
        Q.front=Q.rear;
	}
	return OK;
}

Status EnQueue (LinkQueue &Q, QElemType e)//链队列的插入
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

Status DeQueue (LinkQueue &Q, QElemType &e)//链队列的删除
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

Status QueueEmpty(LinkQueue Q)//判断链队列是否为空
{
	if (Q.front==Q.rear) 
		return OK;
	return 0;
}

Status GetHead(LinkQueue Q,QElemType &e)//取链队列的第一个元素//出现随机数？？？
{
	if (QueueEmpty(Q)) 
		return ERROR;
	e=(Q.front)->next->data;
	return OK;
}

void Print_Q(LinkQueue &Q)//链队列的输出
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
Status InitQueue (SqQueue &Q)//循环队列的初始化
{
	Q.base=(QElemType *)malloc(MAXSIZE*sizeof(QElemType));
	if (!Q.base) exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}
int QueueLength(SqQueue Q)//求循环队列长度
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue (SqQueue &Q, QElemType e)//循环队列入队
{
	if ((Q.rear+1) % MAXSIZE ==Q.front) 
    return ERROR;
	Q.base[Q.rear]=e;
	Q.rear = (Q.rear+1)%MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue &Q, QElemType &e)//循环队列出队
{
	if (Q.rear==Q.front) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
Status QueueEmpty(SqQueue Q)//判断循环队列是否为空
{
	if (Q.front==Q.rear) return OK;
	return 0;
}
Status GetHead(SqQueue Q,QElemType &e)//取循环队列队头元素
{
	if (QueueEmpty(Q)) 
		return ERROR;
	e=Q.base[Q.front];
	return OK;
}

void Print_S(SqQueue Q)//循环队列的输出
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
	cout<<"链队列的基本操作"<<endl;
    LinkQueue Q;
	InitQueue (Q);
    cout << "请输入链队列的项数:";
	int num, e;
	cin >> num;
	cout << "请输入链队列各项的元素" << endl;
	while( num )
	{
		cin >> e;
		EnQueue (Q, e);
		num--;
	}
	cout << "链队列Q的内容为（从队头到队尾）：" << endl;
	Print_Q(Q);
	cout<<"请输入链队列要输入的元素e=";
	int e1;
	cin>>e1;
    EnQueue (Q,  e1);
    cout << "插入后链队列Q的内容为（从队头到队尾）：" << endl;
	Print_Q(Q);

	cout<<"链队列的删除操作"<<endl;
	int e2;
	DeQueue (Q, e2);
    cout << "删除后链队列Q的内容为（从队头到队尾）：" << endl;
	Print_Q(Q);
    cout<<"删除的元素为e="<<e2<<endl;

	int e4;
	GetHead(Q,e4);
	cout<<"链队列的第一个元素为："<<e4<<endl;

	DestroyQueue (Q);




	cout<<"循环队列的基本操作"<<endl;
    SqQueue S;
	InitQueue (S);
    cout << "请输入循环队列的项数:";
	int num1, e5;
	cin >> num1;
	cout << "请输入循环队列各项的元素" << endl;
	while( num1 )
	{
		cin >> e5;
		EnQueue (S, e5);
		num1--;
	}
	cout << "循环队列S的内容为（从队头到队尾）：" << endl;
	Print_S(S);
	cout<<"请输入循环队列要输入的元素e=";
	int e6;
	cin>>e6;
    EnQueue (S,  e6);
    cout << "插入后循环队列Q的内容为（从队头到队尾）：" << endl;
	Print_S(S);

	cout<<"循环队列的删除操作"<<endl;
	int e7;
	DeQueue (S, e7);
    cout << "删除后循环队列Q的内容为（从队头到队尾）：" << endl;
	Print_S(S);
    cout<<"删除的元素为e="<<e7<<endl;

	int e8;
	GetHead(S,e8);
	cout<<"循环队列的第一个元素为："<<e8<<endl;

//	DestroyQueue (S);

	return 0;
}
