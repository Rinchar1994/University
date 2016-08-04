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

int CreateBiTree(BiTree &T);//建立二叉树
void PreOrderTraverse(BiTree T);//先序遍历二叉树的递归算法
void InOrderTraverse(BiTree T);//中序遍历二叉树的递归算法
void PostOrderTraverse(BiTree T);//后序遍历二叉树的递归算法
int InitQueue (SqQueue &Q);//链队列初始化
void LevelOrderTraverse(BiTree T);//层次遍历二叉树的算法
void PrintBiTree(BiTree T,int n);//二叉树的显示输出
int Depth(BiTree T);//利用二叉树后序遍历计算二叉树的深度
int Size(BiTree T);//求二叉树结点个数
int LeafSize(BiTree T);//求叶子结点数
void CopyTree(BiTree T,BiTree &T1);//复制二叉树
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
	    while (Q.front !=Q.rear)      //判队空
		{
			p=Q.base[Q.front];   //取队头元素
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
	cout << "先序建立一个新的二叉树，空格代表该结点不存在，结点内容为字母型" << endl;
	BiTree A;
	CreateBiTree(A);
	while(1){
	int i;
	cout << "***************************************" << endl;
	cout << "*请输入要选择的操作项目代号:           " << endl;
	cout << "* 1、基本操作                          " << endl;
	cout << "* 2、选做操作                          " << endl;
	cout << "* 3、退出                              " << endl;
	cout << "***************************************" << endl;
	cout << endl;
	cin >> i;
	switch( i )
	{
	    case 1:
			while(1){
			cout << "***************************************" << endl;
			cout << "*请输入要选择的基本操作代号:           " << endl;
			cout << "* 1、先序遍历                          " << endl;
			cout << "* 2、中序遍历                          " << endl;
			cout << "* 3、后序遍历                          " << endl;
			cout << "* 4、层次遍历                          " << endl;
			cout << "* 5、二叉树显示                        " << endl;
			cout << "* 6、退出                              " << endl;
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
					cout << "没有该选项" << endl;
			}
			cout << endl;
			if( j == 6 )
				break;
			}
			break;
		case 2:
			while(1){
			cout << "***************************************" << endl;
			cout << "*请输入要选择的选做操作代号:           " << endl;
			cout << "* 1、求二叉树的深度                    " << endl;
			cout << "* 2、总结点数                          " << endl;
			cout << "* 3、叶子结点数                        " << endl;
			cout << "* 4、二叉树的复制                      " << endl;
			cout << "* 5、退出                              " << endl;
			cout << "***************************************" << endl;
			cout << endl;
			int k;
			cin >> k;
			switch( k )
			{
			    case 1:
					cout << "二叉树A的深度为：" << Depth(A);
					break;
				case 2:
					cout << "二叉树A的总结点数为：" << Size(A);
					break;
				case 3:
					cout << "二叉树A的叶子结点数为：" << LeafSize(A);
					break;
				case 4:
					BiTree B;
					CopyTree(A,B);
					cout << "复制生成的二叉树B为：" << endl;
					PrintBiTree(B,1);
					break;
				case 5:
					break;
				default:
					cout << "没有该选项" << endl;
			}
			cout << endl;
			if( k == 5 )
				break;
			}
			break;
	    case 3:
			break;
		default:
			cout << "没有该选项" << endl;
	}
	if( i == 3 )
		break;
	}
	return 0;
}
