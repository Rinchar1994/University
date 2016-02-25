#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType  data;
    struct LNode *next;
} LNode, *LinkList;

#define OK 1
#define OVERFLOW -1
#define ERROR -1

int LinkLength_L (LinkList L);//求链表长度
Status ListInsert_L(LinkList &L,int i,ElemType e);//插入元素
void DestroyList_L1(LinkList &L);//销毁循环链表
Status ListDelete_L(LinkList &L, int i, ElemType &e);////删除某位置元素，并以删去位置的下一个结点为头结点
void PrintList_L1(LinkList L);//循环链表的显示输出
void CreateList_L1(LinkList &L,int n);//建立循环链表



void CreateList_L1(LinkList &L,int n)//建立循环链表
{
	LinkList p, q;
	q = L= (LinkList)malloc(sizeof(LNode));
    L ->next=L;
	int t = 0;
	for(int i=n;i>0;i--)
	{
        p=(LinkList)malloc(sizeof(LNode));
		p->data = ++t;//元素为编号
		p->next = L;
        q->next = p;//使插入编号能从小到大
		q = p;
	}
}

void PrintList_L1(LinkList L)//循环链表的显示输出
 {
	LinkList p;
	p=L->next;
	cout << "L->";
	while (p!=L)
	{
		cout << p->data << "->";
		p=p->next;
	}
  	cout << "L" << endl;
 }

Status ListDelete_L(LinkList &L, int i, ElemType &e)//删除某位置元素，并以删去位置的下一个结点为头结点
{
	LinkList p,q,s;
	p = L;
	s = L;
	int l = LinkLength_L (L);
	int j=0;
	i=i%l;
	if( i == 0 )
		i = l;//考虑在最后一个位置前插入元素的情况
	while (j<i-1 )
	{
		p=p->next;
		++j;
	}
	while( s->next != L )
		s = s->next;
	if( p == L )//考虑删除元素是第一个结点的时候
	{
		q=p->next;
		L->next = q->next;
	}
	else if( p->next == s )//考虑删除元素是最后一个结点的时候
	{
		q=p->next;
	    p->next = L;
	}
	else
	{
	    s->next = L->next;//将原来头结点处连接起来
	    q=p->next;
	    p->next = L;
	    L->next = q->next;//将L插入删除元素处
	}
	e=q->data;
	free(q);
	return OK;
}

void DestroyList_L1(LinkList &L)//销毁循环链表
{
	LinkList p,q,r;
	p=L;
	r=L;
	while(r->next!=L)
		r=r->next;
	while (p!=r)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
}

Status ListInsert_L(LinkList &L,int i,ElemType e)//插入元素
{
	LinkList p,s;
	p=L;
	int j = 0;
	while (j<i-1)//在本例中插入的位置只在最后，所以判断条件稍微改动
	{
		p=p->next;
		++j;
	}
	s = (LinkList) malloc( sizeof (LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;//使插入元素按插入先后排列
	return OK;
}

int LinkLength_L (LinkList L)//求链表长度
{
	int j;
	LinkList p;
    p=L->next;
	j=0;
	while (p != L)
	{
		p=p->next;
		j++;
	}
    return(j);
}
int main()
{
	int n, s, m;
	cout << "关于Josephus问题的测试" << endl;
	cout << "请输入总人数n, n=";
	cin >> n;
	cout << "请输入开始计数的位置s, s=";
	cin >> s;
	cout << "请输入每次数的人数m, m=";
	cin >> m;
	LinkList A;
	CreateList_L1( A, n );
	PrintList_L1( A );
	cout << "--------------------------------------" << endl;
	cout << "算法实现部分" << endl;
	LinkList B;
	CreateList_L1( B, 0 );
	int e, i = 1, t = s+m-1;
	ListDelete_L(A, t, e);
	ListInsert_L(B, i, e);
	i++;
	while( n-2 != 0 )
	{
		ListDelete_L(A, m, e);
		ListInsert_L(B, i, e);
		i++;
		n--;
	}
	ListInsert_L(B, i, A->next->data);
	cout << "依次离席的序号为：" << endl;
	PrintList_L1(B);
	DestroyList_L1(A);
	DestroyList_L1(B);
	return 0;
}
