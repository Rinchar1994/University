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

int LinkLength_L (LinkList L);//��������
Status ListInsert_L(LinkList &L,int i,ElemType e);//����Ԫ��
void DestroyList_L1(LinkList &L);//����ѭ������
Status ListDelete_L(LinkList &L, int i, ElemType &e);////ɾ��ĳλ��Ԫ�أ�����ɾȥλ�õ���һ�����Ϊͷ���
void PrintList_L1(LinkList L);//ѭ���������ʾ���
void CreateList_L1(LinkList &L,int n);//����ѭ������



void CreateList_L1(LinkList &L,int n)//����ѭ������
{
	LinkList p, q;
	q = L= (LinkList)malloc(sizeof(LNode));
    L ->next=L;
	int t = 0;
	for(int i=n;i>0;i--)
	{
        p=(LinkList)malloc(sizeof(LNode));
		p->data = ++t;//Ԫ��Ϊ���
		p->next = L;
        q->next = p;//ʹ�������ܴ�С����
		q = p;
	}
}

void PrintList_L1(LinkList L)//ѭ���������ʾ���
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

Status ListDelete_L(LinkList &L, int i, ElemType &e)//ɾ��ĳλ��Ԫ�أ�����ɾȥλ�õ���һ�����Ϊͷ���
{
	LinkList p,q,s;
	p = L;
	s = L;
	int l = LinkLength_L (L);
	int j=0;
	i=i%l;
	if( i == 0 )
		i = l;//���������һ��λ��ǰ����Ԫ�ص����
	while (j<i-1 )
	{
		p=p->next;
		++j;
	}
	while( s->next != L )
		s = s->next;
	if( p == L )//����ɾ��Ԫ���ǵ�һ������ʱ��
	{
		q=p->next;
		L->next = q->next;
	}
	else if( p->next == s )//����ɾ��Ԫ�������һ������ʱ��
	{
		q=p->next;
	    p->next = L;
	}
	else
	{
	    s->next = L->next;//��ԭ��ͷ��㴦��������
	    q=p->next;
	    p->next = L;
	    L->next = q->next;//��L����ɾ��Ԫ�ش�
	}
	e=q->data;
	free(q);
	return OK;
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

Status ListInsert_L(LinkList &L,int i,ElemType e)//����Ԫ��
{
	LinkList p,s;
	p=L;
	int j = 0;
	while (j<i-1)//�ڱ����в����λ��ֻ����������ж�������΢�Ķ�
	{
		p=p->next;
		++j;
	}
	s = (LinkList) malloc( sizeof (LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;//ʹ����Ԫ�ذ������Ⱥ�����
	return OK;
}

int LinkLength_L (LinkList L)//��������
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
	cout << "����Josephus����Ĳ���" << endl;
	cout << "������������n, n=";
	cin >> n;
	cout << "�����뿪ʼ������λ��s, s=";
	cin >> s;
	cout << "������ÿ����������m, m=";
	cin >> m;
	LinkList A;
	CreateList_L1( A, n );
	PrintList_L1( A );
	cout << "--------------------------------------" << endl;
	cout << "�㷨ʵ�ֲ���" << endl;
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
	cout << "������ϯ�����Ϊ��" << endl;
	PrintList_L1(B);
	DestroyList_L1(A);
	DestroyList_L1(B);
	return 0;
}
