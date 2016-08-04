#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType  data;
    struct LNode   *next;
} LNode, *LinkList;


typedef struct DuLNode
{
    ElemType   data;
    struct DuLNode   *prior;
    struct DuLNode   *next;
}DuLNode, *DuLinkList;

#define OK 1
#define OVERFLOW -1
#define ERROR -1

void CreateList_L(LinkList &L, int n)//建立单链线性表
{ 
	LinkList p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i=n;i>0;i--) 
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->data=rand()%100;
		p->next = L->next; 
		L->next=p;
	}
  }
void DestroyList_L(LinkList &L)//销毁单链线性链表
{
	LinkList p,q;
	p=L;
	while (p->next!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
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


void DestroyList_DuL(DuLinkList &L)//销毁双向链表
{
	DuLinkList p,q,r;
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



int LinkLength_L (LinkList L)//求链表长度
{  
	int j; 
	LinkList p;
    p=L->next;  
	j=0;
    while (p) 
	{
		p=p->next;j++;
	}
    return(j);
}

void PrtList_DuL(LinkList L)//显示输出
{	
	LinkList p;
	p=L->next;
	while(p!=NULL)
	{
		cout<<setw(4)<<p->data;
		p=p->next;
	}
	cout<<'\n';
}

Status GetElem_L(LinkList L,int i,ElemType &e)//取第i个元素(线性链表和循环链表共用)
{ 
	
	LinkList p;
	p=L->next;  int j=1;
	while (p && j<i) 
	{ 
		p=p->next; 
		++j; 
	}
	if (!p || j>i) 
		return ERROR;
	e=p->data;
	return OK;
}

Status GetElem_DuL(DuLinkList L,int i,ElemType &e)//取第i个元素（双向链表）
{ 
	
	DuLinkList p;
	p=L->next;  int j=1;
	while (p && j<i) 
	{ 
		p=p->next; 
		++j; 
	}
	if (!p || j>i) 
		return ERROR;
	e=p->data;
	return OK;
}

Status ListInsert_L(LinkList &L,int i,ElemType e)//插入元素(线性链表和循环链表共用)
{ 
	
	LinkList p,s;
	p=L;   int j=0;
	while (p && j<i-1) 
	{ 
		p=p->next; 
		++j;
	}
	if (!p || j> i-1) 
		return ERROR;
	s = (LinkList) malloc( sizeof (LNode));
	s->data = e; 
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e)//插入元素(双向链表)
{ 
	
	DuLinkList p,s;
	p=L;   int j=0;
	while (p && j<i-1) 
	{ 
		p=p->next; 
		++j;
	}
	if (!p || j> i-1) 
		return ERROR;
	s = (DuLinkList) malloc( sizeof (DuLNode));
	s->data = e; 
	s->prior = p;
	s->next=p->next;
	s->next->prior=s;
	p->next = s;
	return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e)//删除元素(线性链表和循环链表共用)
{ 
	LinkList p,q;
	p=L;   
	int j=0;
	while ( p->next && j<i-1 ) 
	{ 
		p=p->next; 
		++j;
	}
	if (!(p->next) || j> i-1) 
		return ERROR;
	q=p->next;	
	p->next = q->next; 
	e=q->data;	
	free(q);
	return OK;
}

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e)//删除元素(双向链表)
{ 
	DuLinkList p,q;
	p=L;   
	int j=0;
	while ( p->next && j<i-1 ) 
	{ 
		p=p->next; 
		++j;
	}
	if (!(p->next) || j> i-1) 
		return ERROR;
	q=p->next;	
	p->next = q->next; 
	p->next->prior=q->prior;
	e=q->data;	
	free(q);
	return OK;
}

void UnionList_L(LinkList &La,LinkList Lb)//两个线性链表的合并，A=A∪B
{   
	LinkList  p,q,first;  
	int x;
    first = La->next; 
	p=Lb->next;
    while (p)
	{
         x=p->data;  
		 p=p->next;  
		 q=first;
         while (q && q->data !=x)  
			 q=q->next;
         if (!q) 
		 {  
			 q=(LinkList)malloc(sizeof(LNode));
             q->data = x;  q->next = La->next;
             La->next = q; 
		 }  
	}
}

void UnionList_L1(LinkList &La,LinkList Lb)//两个循环链表的合并，A=A∪B
{
	LinkList p; 
	p=La;
	while (p->next!=La)  p=p->next;
    p->next=Lb->next;
	p=p->next;
    while (p->next!=Lb) p=p->next;
    p->next=La; 
	free(Lb);
}


void UnionList_DuL(DuLinkList &La,DuLinkList Lb)//两个双向链表的合并，A=A∪B
{
	DuLinkList p; 
	p=La;
	while (p->next!=La)  p=p->next;
    p->next=Lb->next;
	p->next->prior=p;
    p=p->next;
    while (p->next!=Lb) p=p->next;
    p->next=La; 
	p->next->prior=p;
    free(Lb);
}


void CreateList_L1(LinkList &L,int n)//建立循环链表
{  
	LinkList p;  
	L= (LinkList)malloc(sizeof(LNode));
    L ->next=L;
	for(int i=n;i>0;i--)
	{ 
        p=(LinkList)malloc(sizeof(LNode));
		p->data=rand ()%100; 
		p->next = L->next;
        L->next = p;
	}
}

void PrintList_L1(LinkList L)//循环链表的显示输出
 { 
	LinkList p;
	p=L->next;  
	printf("L->");
	while (p!=L) 
	{
		printf("%d->",p->data);
		p=p->next;  
	}
  	printf("L\n");
 }


void CrtList_DuL(DuLinkList &L,int n)//建立双向链表
{	
	DuLinkList p;   
	L=p=(DuLinkList)malloc(sizeof(DuLNode));
    L ->next=L;  
	L->prior =L;
	for (int i=n;i>0;i--)
	{
		p->next=(DuLinkList)malloc(sizeof(DuLNode));
		p->next->prior =p;    
		p=p->next;
		p->data=rand()%100;
    }
	p->next=L;
	L->prior =p;
}

void PrtList_DuL(DuLinkList L)//双向链表的显示输出
{	
	DuLinkList p;  
	p=L->next;	printf("L<->");
	while (p!=L)
	{
		printf("%d<->",p->data);
		p=p->next;
    }
	printf("L\n");
}

void inverse (LinkList &L)  //单链表逆置
{
	LinkList p,q,r;
	p=L->next;
	r=L->next;
	while (p->next!=NULL)
		p=p->next;
	L->next=p;
	for(;;)
	{
		q=r;
		while(q->next!=p)
		    q=q->next;
    	p->next=q;
		p=p->next;
		if (p==r)
			break;

	}
	p->next=NULL;
}

void DeleteExtra(LinkList &L)
{
	LinkList p,q,r;
	p=L->next;
	int i=1;
	int g=1;
	for(;p->next!=NULL;p=p->next,g++)
	{	
	
	    q=p->next;
		i=g+1;
		for (;q!=NULL;i++)
		{
			
		    if (p->data==q->data)
			{
				int e;
				r=q->next;
				ListDelete_L(L,  i, e);
				i--;
				q=r;
				continue;
			}
			q=q->next;
		}
		
	}
}


int main()
{
	cout<<"线性链表的基本操作"<<endl;
    LinkList L;
	int n;
	cout<<"请输入链表长度n=";
	cin>>n;
    CreateList_L(L, n);
	cout<<"链表L："<<endl;
    PrtList_DuL(L);
	
	cout<<"查找第i个元素，请输入i=";
    int i1;
	cin>>i1;
	int e;
	GetElem_L (L,i1,e);
	cout<<"第"<<i1<<"个元素为："<<e<<endl;

	cout<<"请输入要插入的位置第i个以及插入的元素e"<<'\n'<<"i=";
	int i2,e2;
	cin>>i2;
	cout<<"e=";
	cin>>e2;
    ListInsert_L(L, i2, e2);
	cout<<"新链表为："<<'\n';
	PrtList_DuL(L);

	cout<<"请输入要删除的元素位置，i=";
	int i3,e3;
	cin>>i3;
	ListDelete_L(L, i3, e3);
	cout<<"新链表为:"<<endl;
	PrtList_DuL(L);
	cout<<"删除的元素为："<<e3<<endl;

    LinkList La;
	int n1;
	cout<<"请输入链表长度n=";
	cin>>n1;
    CreateList_L(La, n1);
	cout<<"链表La："<<endl;
    PrtList_DuL(La);
	
	LinkList Lb;
	int n2;
	cout<<"请输入链表长度n=";
	cin>>n2;
    CreateList_L(Lb, n2);
	cout<<"链表Lb："<<endl;
    PrtList_DuL(Lb);
	
    UnionList_L(La,Lb);
	cout<<"合并后的链表为："<<endl;
	PrtList_DuL(La);
    cout<<"长度为："<<LinkLength_L ( La)<<endl;


	cout<<"单链表逆置后为："<<endl;
	inverse (La);
	PrtList_DuL(La);

	cout<<"删除单链表中所有多余的元素后的链表为"<<endl;
	DeleteExtra(La);
	PrtList_DuL(La);
    DestroyList_L(L);
	DestroyList_L(La);


	
	cout<<"循环链表的基本操作"<<endl;

    LinkList Lc ;
	int n3;
	cout<<"请输入循环链表长度n=";
	cin>>n3;
    CreateList_L1(Lc,n3);
	PrintList_L1(Lc);
	cout<<"查找第i个元素，请输入i=";
    int i4;
	cin>>i4;
	int e4;
	GetElem_L (Lc,i4,e4);
	cout<<"第"<<i4<<"个元素为："<<e4<<endl;


    cout<<"请输入要插入的位置第i个以及插入的元素e"<<'\n'<<"i=";
	int i5,e5;
	cin>>i5;
	cout<<"e=";
	cin>>e5;
    ListInsert_L(Lc, i5, e5);
	cout<<"新链表为："<<'\n';
	PrintList_L1(Lc);

	cout<<"请输入要删除的元素位置，i=";
	int i6,e6;
	cin>>i6;
	ListDelete_L(Lc, i6, e6);
	cout<<"新链表为:"<<endl;
	PrintList_L1(Lc);
	cout<<"删除的元素为："<<e6<<endl;

	LinkList Ld ;
	int n7;
	cout<<"请输入循环链表Ld长度n=";
	cin>>n7;
    CreateList_L1(Ld,n7);
	PrintList_L1(Ld);

	LinkList Le ;
	int n8;
	cout<<"请输入循环链表Le长度n=";
	cin>>n8;
    CreateList_L1(Le,n8);
	PrintList_L1(Le);

	UnionList_L1(Ld,Le);
	cout<<"合并后的链表为:";
	PrintList_L1(Ld);
   
	DestroyList_L1(Lc);
	DestroyList_L1(Ld);




	cout<<"双向链表的基本操作"<<endl;


	DuLinkList Lf;
	int n9;
	cout<<"请输入双向循环链表Lf长度n=";
	cin>>n9;
    CrtList_DuL(Lf,n9);
	PrtList_DuL(Lf);

	cout<<"查找第i个元素，请输入i=";
    int i10;
	cin>>i10;
	int e10;
	GetElem_DuL(Lf,i10,e10);
	cout<<"第"<<i10<<"个元素为："<<e10<<endl;

	cout<<"请输入要插入的位置第i个以及插入的元素e"<<'\n'<<"i=";
	int i11,e11;
	cin>>i11;
	cout<<"e=";
	cin>>e11;
    ListInsert_DuL(Lf, i11, e11);
	cout<<"新链表为："<<'\n';
	PrtList_DuL(Lf);

	cout<<"请输入要删除的元素位置，i=";
	int i12,e12;
	cin>>i12;
	ListDelete_DuL(Lf, i12, e12);
	cout<<"新链表为:"<<endl;
	PrtList_DuL(Lf);
	cout<<"删除的元素为："<<e12<<endl;

    DuLinkList Lg ;
	int n13;
	cout<<"请输入双向链表Ld长度n=";
	cin>>n13;
    CrtList_DuL(Lg,n13);
	PrtList_DuL(Lg);


	DuLinkList Lh ;
	int n14;
	cout<<"请输入双向链表Ld长度n=";
	cin>>n14;
    CrtList_DuL(Lh,n14);
	PrtList_DuL(Lh);

	UnionList_DuL(Lg,Lh);
	cout<<"合并后的链表为:";
	PrtList_DuL(Lg);

    DestroyList_DuL(Lf);
	DestroyList_DuL(Lg);

	return 0;
}

