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

void CreateList_L(LinkList &L, int n)//�����������Ա�
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
void DestroyList_L(LinkList &L)//���ٵ�����������
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


void DestroyList_L1(LinkList &L)//����ѭ������
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


void DestroyList_DuL(DuLinkList &L)//����˫������
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



int LinkLength_L (LinkList L)//��������
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

void PrtList_DuL(LinkList L)//��ʾ���
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

Status GetElem_L(LinkList L,int i,ElemType &e)//ȡ��i��Ԫ��(���������ѭ��������)
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

Status GetElem_DuL(DuLinkList L,int i,ElemType &e)//ȡ��i��Ԫ�أ�˫������
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

Status ListInsert_L(LinkList &L,int i,ElemType e)//����Ԫ��(���������ѭ��������)
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

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e)//����Ԫ��(˫������)
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

Status ListDelete_L(LinkList &L, int i, ElemType &e)//ɾ��Ԫ��(���������ѭ��������)
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

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e)//ɾ��Ԫ��(˫������)
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

void UnionList_L(LinkList &La,LinkList Lb)//������������ĺϲ���A=A��B
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

void UnionList_L1(LinkList &La,LinkList Lb)//����ѭ������ĺϲ���A=A��B
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


void UnionList_DuL(DuLinkList &La,DuLinkList Lb)//����˫������ĺϲ���A=A��B
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


void CreateList_L1(LinkList &L,int n)//����ѭ������
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

void PrintList_L1(LinkList L)//ѭ���������ʾ���
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


void CrtList_DuL(DuLinkList &L,int n)//����˫������
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

void PrtList_DuL(DuLinkList L)//˫���������ʾ���
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

void inverse (LinkList &L)  //����������
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
	cout<<"��������Ļ�������"<<endl;
    LinkList L;
	int n;
	cout<<"������������n=";
	cin>>n;
    CreateList_L(L, n);
	cout<<"����L��"<<endl;
    PrtList_DuL(L);
	
	cout<<"���ҵ�i��Ԫ�أ�������i=";
    int i1;
	cin>>i1;
	int e;
	GetElem_L (L,i1,e);
	cout<<"��"<<i1<<"��Ԫ��Ϊ��"<<e<<endl;

	cout<<"������Ҫ�����λ�õ�i���Լ������Ԫ��e"<<'\n'<<"i=";
	int i2,e2;
	cin>>i2;
	cout<<"e=";
	cin>>e2;
    ListInsert_L(L, i2, e2);
	cout<<"������Ϊ��"<<'\n';
	PrtList_DuL(L);

	cout<<"������Ҫɾ����Ԫ��λ�ã�i=";
	int i3,e3;
	cin>>i3;
	ListDelete_L(L, i3, e3);
	cout<<"������Ϊ:"<<endl;
	PrtList_DuL(L);
	cout<<"ɾ����Ԫ��Ϊ��"<<e3<<endl;

    LinkList La;
	int n1;
	cout<<"������������n=";
	cin>>n1;
    CreateList_L(La, n1);
	cout<<"����La��"<<endl;
    PrtList_DuL(La);
	
	LinkList Lb;
	int n2;
	cout<<"������������n=";
	cin>>n2;
    CreateList_L(Lb, n2);
	cout<<"����Lb��"<<endl;
    PrtList_DuL(Lb);
	
    UnionList_L(La,Lb);
	cout<<"�ϲ��������Ϊ��"<<endl;
	PrtList_DuL(La);
    cout<<"����Ϊ��"<<LinkLength_L ( La)<<endl;


	cout<<"���������ú�Ϊ��"<<endl;
	inverse (La);
	PrtList_DuL(La);

	cout<<"ɾ�������������ж����Ԫ�غ������Ϊ"<<endl;
	DeleteExtra(La);
	PrtList_DuL(La);
    DestroyList_L(L);
	DestroyList_L(La);


	
	cout<<"ѭ������Ļ�������"<<endl;

    LinkList Lc ;
	int n3;
	cout<<"������ѭ��������n=";
	cin>>n3;
    CreateList_L1(Lc,n3);
	PrintList_L1(Lc);
	cout<<"���ҵ�i��Ԫ�أ�������i=";
    int i4;
	cin>>i4;
	int e4;
	GetElem_L (Lc,i4,e4);
	cout<<"��"<<i4<<"��Ԫ��Ϊ��"<<e4<<endl;


    cout<<"������Ҫ�����λ�õ�i���Լ������Ԫ��e"<<'\n'<<"i=";
	int i5,e5;
	cin>>i5;
	cout<<"e=";
	cin>>e5;
    ListInsert_L(Lc, i5, e5);
	cout<<"������Ϊ��"<<'\n';
	PrintList_L1(Lc);

	cout<<"������Ҫɾ����Ԫ��λ�ã�i=";
	int i6,e6;
	cin>>i6;
	ListDelete_L(Lc, i6, e6);
	cout<<"������Ϊ:"<<endl;
	PrintList_L1(Lc);
	cout<<"ɾ����Ԫ��Ϊ��"<<e6<<endl;

	LinkList Ld ;
	int n7;
	cout<<"������ѭ������Ld����n=";
	cin>>n7;
    CreateList_L1(Ld,n7);
	PrintList_L1(Ld);

	LinkList Le ;
	int n8;
	cout<<"������ѭ������Le����n=";
	cin>>n8;
    CreateList_L1(Le,n8);
	PrintList_L1(Le);

	UnionList_L1(Ld,Le);
	cout<<"�ϲ��������Ϊ:";
	PrintList_L1(Ld);
   
	DestroyList_L1(Lc);
	DestroyList_L1(Ld);




	cout<<"˫������Ļ�������"<<endl;


	DuLinkList Lf;
	int n9;
	cout<<"������˫��ѭ������Lf����n=";
	cin>>n9;
    CrtList_DuL(Lf,n9);
	PrtList_DuL(Lf);

	cout<<"���ҵ�i��Ԫ�أ�������i=";
    int i10;
	cin>>i10;
	int e10;
	GetElem_DuL(Lf,i10,e10);
	cout<<"��"<<i10<<"��Ԫ��Ϊ��"<<e10<<endl;

	cout<<"������Ҫ�����λ�õ�i���Լ������Ԫ��e"<<'\n'<<"i=";
	int i11,e11;
	cin>>i11;
	cout<<"e=";
	cin>>e11;
    ListInsert_DuL(Lf, i11, e11);
	cout<<"������Ϊ��"<<'\n';
	PrtList_DuL(Lf);

	cout<<"������Ҫɾ����Ԫ��λ�ã�i=";
	int i12,e12;
	cin>>i12;
	ListDelete_DuL(Lf, i12, e12);
	cout<<"������Ϊ:"<<endl;
	PrtList_DuL(Lf);
	cout<<"ɾ����Ԫ��Ϊ��"<<e12<<endl;

    DuLinkList Lg ;
	int n13;
	cout<<"������˫������Ld����n=";
	cin>>n13;
    CrtList_DuL(Lg,n13);
	PrtList_DuL(Lg);


	DuLinkList Lh ;
	int n14;
	cout<<"������˫������Ld����n=";
	cin>>n14;
    CrtList_DuL(Lh,n14);
	PrtList_DuL(Lh);

	UnionList_DuL(Lg,Lh);
	cout<<"�ϲ��������Ϊ:";
	PrtList_DuL(Lg);

    DestroyList_DuL(Lf);
	DestroyList_DuL(Lg);

	return 0;
}

