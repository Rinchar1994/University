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
#define MAXQSIZE 100
typedef int TElemType;


typedef enum
{
	Link,Thread
}PointerTag;
//Link==0��ָ�룬ָ���ӽ��
//Thread==1��������ָ��ǰ�����̽��

typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild;
	PointerTag LTag,RTag;
}BiThrNode, *BiThrTree;

typedef struct TriThrNode{
	TElemType data;
	struct TriThrNode *lchild,*rchild,*parent;
	PointerTag LTag,RTag;
}TriThrNode, *TriThrTree;

typedef TriThrNode *QElemType;
typedef struct
{
	QElemType *base;
	int front, rear;
}SqQueue;

int CreateBiThrTree(BiThrTree &T);//����������
int CreateTriThrTree(TriThrTree &T);//������˫�׽��Ķ�����
int InOrderThreading(BiThrTree &Thrt, BiThrTree T);//�������ͷ��㣬ʹpreʼ��ָ��ǰ�����
int PreOrderThreading(BiThrTree &Thrt, BiThrTree T);//�������ͷ��㣬ʹpreʼ��ָ��ǰ�����
int PostOrderThreading(TriThrTree &Thrt, TriThrTree T);//�������ͷ��㣬ʹpreʼ��ָ��ǰ�����
void InThreading (BiThrTree P, BiThrTree &pre);//����������
void PreThreading(BiThrTree P, BiThrTree &pre);//����������
void PostThreading(TriThrTree P, TriThrTree &pre);//����������
void inorder_Thr(BiThrTree T);//�����������������������
void preorder_Thr(BiThrTree T);//�����������������������
void postorder_Thr(TriThrTree T);//�����������������������
void Destroy_in( BiThrTree &T );//������������������
void Destroy_pre( BiThrTree &T );//������������������
void Destroy_post( TriThrTree &T );//���ٺ�������������
int InitQueue (SqQueue &Q);//�����г�ʼ��
void LevelOrderTraverse(TriThrTree T);//ʹparentָ��ָ��˫�׽��

int CreateBiThrTree(BiThrTree &T)
 {
	 char ch;
	 ch = getchar();
     if (ch==' ')
		 T=NULL;
     else
	 {
		 if (!(T=(BiThrNode*)malloc(sizeof(BiThrNode))))
			 exit(OVERFLOW);
		 T->data = ch;
		 T->LTag = Link;
		 T->RTag = Link;
		 CreateBiThrTree(T->lchild);
		 CreateBiThrTree(T->rchild);
	}
	return OK; 
}

int CreateTriThrTree(TriThrTree &T)
{
	 char ch;
	 ch = getchar();
     if (ch==' ')
		 T=NULL;
     else
	 {
		 if (!(T=(TriThrNode*)malloc(sizeof(TriThrNode))))
			 exit(OVERFLOW);
		 T->data = ch;
		 T->LTag = Link;
		 T->RTag = Link;
		 CreateTriThrTree(T->lchild);
		 CreateTriThrTree(T->rchild);
	}
	return OK; 
}
int InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	BiThrTree pre;
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) 
		exit(OVERFLOW);
	Thrt->LTag = Link;	
	Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	if (!T) Thrt->lchild = Thrt;
	else {
		Thrt->lchild=T;	
		pre=Thrt;
		InThreading(T, pre);
	}
	return OK;
}

int PreOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	BiThrTree pre;
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) 
		exit(OVERFLOW);
	Thrt->LTag = Link;	
	Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	if (!T) Thrt->lchild = Thrt;
	else {
		Thrt->lchild=T;	
		pre=Thrt;
		PreThreading(T, pre);
	}
	return OK;
}

int PostOrderThreading(TriThrTree &Thrt, TriThrTree T)
{
	TriThrTree pre;
	if (!(Thrt = (TriThrTree)malloc(sizeof(TriThrNode)))) 
		exit(OVERFLOW);
	Thrt->LTag = Link;	
	Thrt->RTag=Thread;
	Thrt->rchild=Thrt;
	Thrt->parent=Thrt;
	if (!T) Thrt->lchild = Thrt;
	else {
		Thrt->lchild=T;	
		pre=Thrt;
		PostThreading(T, pre);
	}
	return OK;
}
void InThreading (BiThrTree P, BiThrTree &pre)
{
	if (P)
	{
		InThreading (P->lchild, pre);
		if (!P->lchild)
		{
			P->LTag=Thread; 
			P->lchild=pre;
		}
		if (!P->rchild) 
			P->RTag=Thread;
		if (pre && pre->RTag==Thread)
		{ 
			pre->rchild = P;
		}
		pre = P;
		InThreading (P->rchild, pre);
	}
}

void PreThreading(BiThrTree P, BiThrTree &pre)
{  
	if (P)
    {  
		if (!P->lchild)
        { 
			P->LTag=Thread;
			P->lchild=pre;
		}
	    if (!P->rchild) 
			P->RTag=Thread;
        if (pre && pre->RTag==Thread) 
			pre->rchild=P;
	    pre=P;
	    if (P->LTag==Link)
		    PreThreading(P->lchild, pre);
	    if (P->RTag==Link)
		    PreThreading(P->rchild, pre);
	 }
}

void PostThreading(TriThrTree P, TriThrTree &pre)
{ 
	if (P)
	{ 
		PostThreading(P->lchild, pre);
	    PostThreading(P->rchild, pre);
	    if (!P->lchild)
		{  
			P->LTag=Thread;   
			P->lchild=pre;
		}
        if (!P->rchild) 
			P->RTag=Thread;
	    if (pre && pre->RTag==Thread) 
			pre->rchild=P;
	    pre=P;
	 }
}

void inorder_Thr(BiThrTree T)
{ 
	BiThrTree p=T;
	while (p->LTag==Link) 
		p=p->lchild;
	printf("%c",p->data);
	while (p->rchild)
    {
		if (p->RTag==Link)
		{ 
			p=p->rchild;
			while(p->LTag==Link) 
				p=p->lchild;
		}
		else 
			p=p->rchild;
		printf("%c",p->data);
	}
}

void preorder_Thr(BiThrTree T)
{ 
	BiThrTree p=T;
	printf("%c",p->data);
    while (p->rchild)
	{   
		if (p->LTag==Link)
			p=p->lchild;
		else 
			p=p->rchild;
		printf("%c",p->data);
	}
}

void postorder_Thr(TriThrTree T)
{  
	TriThrTree f,p=T;
    do 
	{
		while (p->LTag==Link) 
			p=p->lchild;
		if (p->RTag==Link) p=p->rchild;
	}  
	while (p->LTag!=Thread||p->RTag!=Thread);
	printf("%c",p->data);
	while (p!=T)
    {  
		if (p->RTag==Link)
        {
			f=p->parent;
	        if (f->RTag==Thread || p==f->rchild) 
				p=f;
	        else  
			{ 
				p=f->rchild;
		        do
				{
					while(p->LTag==Link) 
						p=p->lchild;
			    if (p->RTag==Link) 
					p=p->rchild;
		        }while (p->LTag!=Thread || p->RTag!=Thread);
			}
		}
		else p=p->rchild;
        printf("%c",p->data);
	}
}

void Destroy_in( BiThrTree &T )
{ 
	BiThrTree p=T, q;
	while (p->LTag==Link) 
		p=p->lchild;
	while (p->rchild)
    {
		q = p;
		if (p->RTag==Link)
		{ 
			p=p->rchild;
			while(p->LTag==Link) 
				p=p->lchild;
		}
		else 
			p=p->rchild;
		free( q );
	}
}

void Destroy_pre( BiThrTree &T )
{ 
	BiThrTree p=T, q;
    while (p->rchild)
	{   
		q = p;
		if (p->LTag==Link)
			p=p->lchild;
		else 
			p=p->rchild;
		free(q);
	}
}

void Destroy_post( TriThrTree &T )
{  
	TriThrTree f,p=T,q;
    do 
	{
		while (p->LTag==Link) 
			p=p->lchild;
		if (p->RTag==Link)
			p=p->rchild;
	}  
	while (p->LTag!=Thread||p->RTag!=Thread);
	while (p!=T)
    {  
		q=p;
		if (p->RTag==Link)
        {
			f=p->parent;
	        if (f->RTag==Thread || p==f->rchild) 
				p=f;
	        else  
			{ 
				p=f->rchild;
		        do
				{
					while(p->LTag==Link) 
						p=p->lchild;
			        if (p->RTag==Link)
				    {
					    free(q);
					    q=p;
					    p=p->rchild;
					}
		        }while (p->LTag!=Thread || p->RTag!=Thread);
			}
		}
		else p=p->rchild;
        free(q);
	}
}
int InitQueue (SqQueue &Q)
{
	Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}
void LevelOrderTraverse(TriThrTree T)
{
	TriThrTree p;
	SqQueue Q;
	InitQueue(Q);
    if (T)
	{
		Q.base[Q.rear]=T;
		Q.rear=(Q.rear+1)%MAXQSIZE;
	    while (Q.front !=Q.rear)      //�жӿ�
		{
			p=Q.base[Q.front];   //ȡ��ͷԪ��
			Q.front=(Q.front+1)%MAXQSIZE;
			if (p->lchild)
			{
				Q.base[Q.rear]=p->lchild;
			    Q.rear=(Q.rear+1)%MAXQSIZE;
				p->lchild->parent=p;
			}
		    if (p->rchild)
			{
				Q.base[Q.rear]=p->rchild;
				Q.rear=(Q.rear+1)%MAXQSIZE;
				p->rchild->parent=p;
			}
		}
	}
}

int main()
{
	BiThrTree A;
	BiThrTree Thrt;
	TriThrTree B;
	TriThrTree Thrt2;
	while(1){
	int i;
	cout << "********************************************" << endl;
	cout << "*    ������Ҫѡ��Ĳ�����Ŀ����:           *" << endl;
	cout << "*     1����������                          *" << endl;
	cout << "*     2��ѡ������                          *" << endl;
	cout << "*     3���˳�                              *" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cin >> i;
	fflush(stdin);
	switch( i )
	{
	    case 1:
			while(1){
			cout << "********************************************" << endl;
			cout << "*    ������Ҫѡ��Ļ�����������:           *" << endl;
			cout << "*     1������������������                  *" << endl;
			cout << "*     2������������������                  *" << endl;
			cout << "*     3���˳�                              *" << endl;
			cout << "********************************************" << endl;
			cout << endl;
			int j;
			cin >> j;
			fflush(stdin);
			switch( j )
			{
			    case 1:
					cout << "������������A" << endl;
					CreateBiThrTree(A);
                    fflush(stdin);//�������
	                PreOrderThreading(Thrt, A);
					preorder_Thr(A);
					Destroy_pre( A );
					break;
				case 2:
					cout << "������������A" << endl;
	                CreateBiThrTree(A);
	                fflush(stdin);
	                InOrderThreading(Thrt, A);
					inorder_Thr(A);
					Destroy_in( A );
					break;
			    case 3:
					break;
				default:
					cout << "û�и�ѡ��" << endl;
			}
			cout << endl;
			if( j == 3 )
				break;
			}
			break;
		case 2:
			while(1){
			cout << "*******************************************" << endl;
			cout << "*    ������Ҫѡ���ѡ����������:           *" << endl;
			cout << "*     1������������������                  *" << endl;
			cout << "*     2���˳�                              *" << endl;
			cout << "*******************************************" << endl;
			cout << endl;
			int k;
			cin >> k;
			fflush(stdin);
			switch( k )
			{
			    case 1:
					cout << "������������B" << endl;
					CreateTriThrTree(B);
	                fflush(stdin);
					LevelOrderTraverse(B);
	                PostOrderThreading(Thrt2, B);
					postorder_Thr(B);
					Destroy_post( B );
					break;
				case 2:
					break;
				default:
					cout << "û�и�ѡ��" << endl;
			}
			cout << endl;
			if( k == 2 )
				break;
			}
			break;
	    case 3:
			break;
		default:
			cout << "û�и�ѡ��" << endl;
	}
	if( i == 3 )
		break;
	}
	return 0;
}
