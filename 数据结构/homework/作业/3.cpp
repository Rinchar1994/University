#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef struct ElemType{
     float coef;//ϵ��
     int expn;	//ָ��
}ElemType;// ElemTypeΪLinkList�����ݶ�����

typedef struct LNode{
    ElemType  data;
    struct LNode *next;
} LNode, *polynomail;

int CreatPolyn( polynomail &P, int m);
//����m���ϵ����ָ����������ʾһԪ����ʽ����������P
void CopyPolyn( polynomail &Pa, polynomail &Pb, int m );
//����һԪ����ʽ
void DestroyPolyn( polynomail &P );
//����һԪ����ʽP
void PrintPolyn( polynomail P );
//��ӡ���һԪ����ʽP
int PolynLength( polynomail P );
//����һԪ����ʽP�е���
void AddPolyn( polynomail &Pa, polynomail &Pb);
//��ɶ���ʽ������㣬����Pa = Pa + Pb,������һԪ����ʽPb
void SubtractPolyn( polynomail &Pa, polynomail &Pb);
//��ɶ���ʽ������㣬����Pa = Pa - Pb,������һԪ����ʽPb
void MultiplyPolyn( polynomail &Pa, polynomail &Pb);
//��ɶ���ʽ������㣬����Pa = Pa * Pb,������һԪ����ʽPb
void CalculatorPolyn( polynomail &Pa, int x , int &SUM);
//����x�����ж���ʽ�����㣬����SUM

int CreatPolyn( polynomail &P, int m)
{
    if( m == 0 )
    return 0;
	polynomail p, q;
	q=P=(polynomail)malloc(sizeof(LNode));
	P->next = NULL;
	for (int i=m;i>0;--i) {
		p=(polynomail)malloc(sizeof(LNode));
		cin >> p->data.coef >> p->data.expn;
		p->next = NULL;
		q->next=p;
		q=q->next;
	}
}


void CopyPolyn( polynomail &Pa, polynomail &Pb, int m )
{
	polynomail pb, pa = Pa->next;
	Pb = (polynomail)malloc(sizeof(LNode));
	Pb->next = NULL;
	for ( ; m>0; --m)
	{
		pb=(polynomail)malloc(sizeof(LNode));
		pb->data.coef = pa->data.coef;
		pb->data.expn = pa->data.expn;
		pb->next = Pb->next;
		Pb->next=pb;
		pa = pa->next;
	}
}
void DestroyPolyn( polynomail &P )
{
	polynomail p = P, q = P;
	while( p ){
		q = p->next;
		free( p );
		p = q;
	}
}

void PrintPolyn( polynomail P )
{
	polynomail p;
	p=P->next;
	if( !p )
	{
		cout << '0';
	}
	else
	{
	    while(p->next)
	    {
		    cout << "(" << p->data.coef << ")" << "*x^" << p->data.expn << "+";
		    p=p->next;
	    }
	    cout << "(" << p->data.coef << ")" << "*x^" << p->data.expn;
	}
}

int PolynLength( polynomail P )
{
	int j;
	polynomail p;
    p=P->next;
	j=0;
    while (p)
	{
		p=p->next;
		j++;
	}
    return(j);
}

void AddPolyn( polynomail &Pa, polynomail &Pb )
{
	polynomail pa = Pa->next, pb = Pb->next ,pc = Pa, pd, pe;
	while( pa && pb )
	{
		if( pa->data.expn < pb->data.expn )
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if( pa->data.expn > pb->data.expn )
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pa->data.coef += pb->data.coef;
			if( pa->data.coef == 0 )
			{
				pc->next = pa->next;
				pe = pa;
				pd = pb;
				pb = pb->next;
			    pa = pa->next;
			    free( pd );
				free( pe );
			}
			else
			{
				pc->next = pa;
			    pd = pb;
			    pb = pb->next;
			    pc = pa;
			    pa = pa->next;
			    free( pd );
			}
		}
	}
	pc->next = pa?pa:pb;//����ʣ���
	free( Pb );
}

void SubtractPolyn( polynomail &Pa, polynomail &Pb )
{
	polynomail pa = Pa->next, pb = Pb->next ,pc = Pa, pd, pe;
	while( pa && pb )
	{
		if( pa->data.expn < pb->data.expn )
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if( pa->data.expn > pb->data.expn )
		{
			pc->next = pb;
			pc = pb;
			pb->data.coef = 0 - pb->data.coef;
			pb = pb->next;
		}
		else
		{
			pa->data.coef -= pb->data.coef;
			if( pa->data.coef == 0 )
			{
				pc->next = pa->next;
				pe = pa;
				pd = pb;
				pb = pb->next;
			    pa = pa->next;
			    free( pd );
				free( pe );
			}
			else
			{
				pc->next = pa;
			    pd = pb;
			    pb = pb->next;
			    pa = pa->next;
			    free( pd );
			}
		}
	}
	pc->next = pa?pa:pb;//����ʣ���
	free( Pb );
}


void MultiplyPolyn( polynomail &Pa, polynomail &Pb)
{
	polynomail pa = Pa->next, pb = Pb->next, Pc, pc;
	int i = PolynLength( Pa );
	pa->data.expn += pb->data.expn;
	pa->data.coef *= pb->data.coef;
	pa = pa->next;
	pa = Pa->next;
	pb = pb->next;
	while( pb )
	{
		CopyPolyn( Pa, Pc, i );
		pc = Pc->next;
		while( pc )
		{
			pc->data.expn += pb->data.expn;
			pc->data.coef *= pb->data.coef;
			pc = pc->next;
		}
		AddPolyn( Pa, Pc );
		pb = pb->next;
	}
	free( Pb );
}

void CalculatorPolyn( polynomail &Pa, int x , int &SUM)
{
	polynomail pa = Pa->next;
	int i, ery = 1;
	SUM = 0;
	while( pa )
	{
		i = pa->data.expn;
		while( i )
		{
			ery *= x;
			i--;
		}
		SUM += (pa->data.coef * ery);
		pa = pa->next;
	}
}

int main()
{
    cout << "����Ķ���ʽ�������������0" << endl;
	cout << "�������ʽ����ӣ��ȴ���2���¶���ʽ�����������ʽA������" << endl;
	polynomail A, B;
	int m;
	cin >> m;
	cout << "������A�����ϵ����ָ��" << endl;
	CreatPolyn( A, m );
	cout << "������B������" << endl;
	cin >> m;
	cout << "������B�����ϵ����ָ��" << endl;
	CreatPolyn( B, m );
	AddPolyn( A, B );
	cout << "��Ӻ�Ķ���ʽAΪ��" << endl << endl;
	PrintPolyn( A );
	cout << endl;
	DestroyPolyn( A );
	cout << "----------------------------------------------------------------" << endl;
	cout << "�������ʽ��������ȴ���2���¶���ʽ�����������ʽA������" << endl;
	cin >> m;
	cout << "������A�����ϵ����ָ��" << endl;
	CreatPolyn( A, m );
	cout << "������B������" << endl;
	cin >> m;
	cout << "������B�����ϵ����ָ��" << endl;
	CreatPolyn( B, m );
	SubtractPolyn( A, B );
	cout << "�����Ķ���ʽAΪ��" << endl << endl;
	PrintPolyn( A );
	cout << endl;
	DestroyPolyn( A );
	cout << "----------------------------------------------------------------" << endl;
	cout << "�������ʽ����ˣ��ȴ���2���¶���ʽ�����������ʽA������" << endl;
	cin >> m;
	cout << "������A�����ϵ����ָ��" << endl;
	CreatPolyn( A, m );
	cout << "������B������" << endl;
	cin >> m;
	cout << "������B�����ϵ����ָ��" << endl;
	CreatPolyn( B, m );
	MultiplyPolyn( A, B );
	cout << "�����Ķ���ʽAΪ��" << endl << endl;
	PrintPolyn( A );
	cout << endl;
	DestroyPolyn( A );
	cout << "----------------------------------------------------------------" << endl;
	int SUM;
	cout << "�������ʽ�����㣬�ȴ���1���¶���ʽ�����������ʽA������" << endl;
	cin >> m;
	cout << "������A�����ϵ����ָ��" << endl;
	CreatPolyn( A, m );
	cout << "������δ֪����ֵ" << endl;
	cin >> m;
	CalculatorPolyn( A, m, SUM);
	cout << "����֮�����ֵΪ��" << endl << endl;
	cout << SUM;
	cout << endl;
	DestroyPolyn( A );
	return 0;
}
