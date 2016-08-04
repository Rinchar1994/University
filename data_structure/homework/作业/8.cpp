#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
using namespace std;
typedef int TelemType;
#define MAXQSIZE 100
#define OK 1
#define OVERFLOW 0
typedef struct BiTNode
{
  TelemType data;
  BiTNode *lchild;
  BiTNode *rchild;
} BiTNode,*BiTree;

typedef BiTNode *QElemType;
typedef struct
{
	QElemType *base;
	int front, rear;
}SqQueue;

int CreateBiTree(BiTree &T);//����������
void PreOrderTraverse(BiTree T);//��������������ĵݹ��㷨
void InOrderTraverse(BiTree T);//��������������ĵݹ��㷨
void PostOrderTraverse(BiTree T);//��������������ĵݹ��㷨
int InitQueue (SqQueue &Q);//�����г�ʼ��
void LevelOrderTraverse(BiTree T);//��α������������㷨
void PrintBiTree(BiTree T,int n);//����������ʾ���
int Depth(BiTree T);//���ö��������������������������
int Size(BiTree T);//�������������
int LeafSize(BiTree T);//��Ҷ�ӽ����
void CopyTree(BiTree T,BiTree &T1);//���ƶ�����
//-----------------------------------------------------------------------
int CreateBiTree(BiTree &T)
 {
	 char ch;
	 ch = getchar();
     if (ch==' ')
		 T=NULL;
     else
	 {
		 if (!(T=(BiTNode*)malloc(sizeof(BiTNode))))
			 exit(OVERFLOW);
		 T->data = ch;
		 CreateBiTree(T->lchild);
		 CreateBiTree(T->rchild);
	}
	return OK; 
}

void PreOrderTraverse(BiTree T)
{
	if (T)
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
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

void LevelOrderTraverse(BiTree T)
{
	BiTree p;
	SqQueue Q;
	InitQueue(Q);
    if (T)
	{
		Q.base[Q.rear]=T;
		Q.rear=(Q.rear+1)%MAXQSIZE;
	    while (Q.front !=Q.rear)      //�жӿ�
		{
			p=Q.base[Q.front];   //ȡ��ͷԪ��
			printf("%c",p->data);
			Q.front=(Q.front+1)%MAXQSIZE;
			if (p->lchild)
			{
				Q.base[Q.rear]=p->lchild;
			    Q.rear=(Q.rear+1)%MAXQSIZE;
			}
		    if (p->rchild)
			{
				Q.base[Q.rear]=p->rchild;
				Q.rear=(Q.rear+1)%MAXQSIZE;
			}
		}
	}
}

void PrintBiTree(BiTree T,int n)
{
	int i;
	char ch=' ';
	if (T)
	{
		PrintBiTree(T->rchild,n+1);
		for (i=1;i<=n;++i) {printf("%5c",ch);}
		printf("%c\n", T->data);
		PrintBiTree(T->lchild,n+1);
	}
}

int Depth(BiTree T)
{
	int depl,depr;
	if (T)
	{
		depl=Depth(T->lchild);
		depr=Depth(T->rchild);
		if (depl>=depr)
			return (depl+1);
		else
			return (depr+1);
	}
	return 0;
}

int Size(BiTree T)
{
    if (T==NULL)
		return 0;
   else
	   return 1 + Size (T->lchild ) + Size ( T->rchild);
}

int LeafSize(BiTree T)
{
	if( T == NULL )
		return 0;
	else if( !(T->lchild) && !(T->rchild) )
		return 1 + LeafSize(T->lchild ) + LeafSize(T->rchild);
	else
		return 0 + LeafSize(T->lchild ) + LeafSize(T->rchild);
}

void CopyTree(BiTree T,BiTree &T1)
{
	if (T)
	{
		T1=(BiTree)malloc(sizeof(BiTNode));
		if (!T1)
		{
			printf("Overflow\n");
			exit(1);
		}
		T1->data=T->data;
		T1->lchild=T1->rchild=NULL;
		CopyTree(T->lchild,T1->lchild);
		CopyTree(T->rchild,T1->rchild);
	}
}

//-------------------------------------------------------
int main()
{
	cout << "������һ���µĶ��������ո����ý�㲻���ڣ��������Ϊ��ĸ��" << endl;
	BiTree A;
	CreateBiTree(A);
	while(1){
	int i;
	cout << "***************************************" << endl;
	cout << "*������Ҫѡ��Ĳ�����Ŀ����:           " << endl;
	cout << "* 1����������                          " << endl;
	cout << "* 2��ѡ������                          " << endl;
	cout << "* 3���˳�                              " << endl;
	cout << "***************************************" << endl;
	cout << endl;
	cin >> i;
	switch( i )
	{
	    case 1:
			while(1){
			cout << "***************************************" << endl;
			cout << "*������Ҫѡ��Ļ�����������:           " << endl;
			cout << "* 1���������                          " << endl;
			cout << "* 2���������                          " << endl;
			cout << "* 3���������                          " << endl;
			cout << "* 4����α���                          " << endl;
			cout << "* 5����������ʾ                        " << endl;
			cout << "* 6���˳�                              " << endl;
			cout << "***************************************" << endl;
			cout << endl;
			int j;
			cin >> j;
			switch( j )
			{
			    case 1:
					PreOrderTraverse(A);
					break;
				case 2:
					InOrderTraverse(A);
					break;
				case 3:
					PostOrderTraverse(A);
					break;
				case 4:
					LevelOrderTraverse(A);
					break;
				case 5:
					PrintBiTree(A,1);
					break;
				case 6:
					break;
				default:
					cout << "û�и�ѡ��" << endl;
			}
			cout << endl;
			if( j == 6 )
				break;
			}
			break;
		case 2:
			while(1){
			cout << "***************************************" << endl;
			cout << "*������Ҫѡ���ѡ����������:           " << endl;
			cout << "* 1��������������                    " << endl;
			cout << "* 2���ܽ����                          " << endl;
			cout << "* 3��Ҷ�ӽ����                        " << endl;
			cout << "* 4���������ĸ���                      " << endl;
			cout << "* 5���˳�                              " << endl;
			cout << "***************************************" << endl;
			cout << endl;
			int k;
			cin >> k;
			switch( k )
			{
			    case 1:
					cout << "������A�����Ϊ��" << Depth(A);
					break;
				case 2:
					cout << "������A���ܽ����Ϊ��" << Size(A);
					break;
				case 3:
					cout << "������A��Ҷ�ӽ����Ϊ��" << LeafSize(A);
					break;
				case 4:
					BiTree B;
					CopyTree(A,B);
					cout << "�������ɵĶ�����BΪ��" << endl;
					PrintBiTree(B,1);
					break;
				case 5:
					break;
				default:
					cout << "û�и�ѡ��" << endl;
			}
			cout << endl;
			if( k == 5 )
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
