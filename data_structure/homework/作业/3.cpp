#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef struct ElemType{
     float coef;//系数
     int expn;	//指数
}ElemType;// ElemType为LinkList的数据对象名

typedef struct LNode{
    ElemType  data;
    struct LNode *next;
} LNode, *polynomail;

int CreatPolyn( polynomail &P, int m);
//输入m项的系数和指数，建立表示一元多项式的有序链表P
void CopyPolyn( polynomail &Pa, polynomail &Pb, int m );
//复制一元多项式
void DestroyPolyn( polynomail &P );
//销毁一元多项式P
void PrintPolyn( polynomail P );
//打印输出一元多项式P
int PolynLength( polynomail P );
//返回一元多项式P中的项
void AddPolyn( polynomail &Pa, polynomail &Pb);
//完成多项式相加运算，即：Pa = Pa + Pb,并销毁一元多项式Pb
void SubtractPolyn( polynomail &Pa, polynomail &Pb);
//完成多项式相减运算，即：Pa = Pa - Pb,并销毁一元多项式Pb
void MultiplyPolyn( polynomail &Pa, polynomail &Pb);
//完成多项式相乘运算，即：Pa = Pa * Pb,并销毁一元多项式Pb
void CalculatorPolyn( polynomail &Pa, int x , int &SUM);
//输入x，进行多项式的运算，返回SUM

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
	pc->next = pa?pa:pb;//插入剩余段
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
	pc->next = pa?pa:pb;//插入剩余段
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
    cout << "输入的多项式的项数必须大于0" << endl;
	cout << "检验多项式的相加，先创建2个新多项式，请输入多项式A的项数" << endl;
	polynomail A, B;
	int m;
	cin >> m;
	cout << "请输入A各项的系数和指数" << endl;
	CreatPolyn( A, m );
	cout << "请输入B的项数" << endl;
	cin >> m;
	cout << "请输入B各项的系数和指数" << endl;
	CreatPolyn( B, m );
	AddPolyn( A, B );
	cout << "相加后的多项式A为：" << endl << endl;
	PrintPolyn( A );
	cout << endl;
	DestroyPolyn( A );
	cout << "----------------------------------------------------------------" << endl;
	cout << "检验多项式的相减，先创建2个新多项式，请输入多项式A的项数" << endl;
	cin >> m;
	cout << "请输入A各项的系数和指数" << endl;
	CreatPolyn( A, m );
	cout << "请输入B的项数" << endl;
	cin >> m;
	cout << "请输入B各项的系数和指数" << endl;
	CreatPolyn( B, m );
	SubtractPolyn( A, B );
	cout << "相减后的多项式A为：" << endl << endl;
	PrintPolyn( A );
	cout << endl;
	DestroyPolyn( A );
	cout << "----------------------------------------------------------------" << endl;
	cout << "检验多项式的相乘，先创建2个新多项式，请输入多项式A的项数" << endl;
	cin >> m;
	cout << "请输入A各项的系数和指数" << endl;
	CreatPolyn( A, m );
	cout << "请输入B的项数" << endl;
	cin >> m;
	cout << "请输入B各项的系数和指数" << endl;
	CreatPolyn( B, m );
	MultiplyPolyn( A, B );
	cout << "相减后的多项式A为：" << endl << endl;
	PrintPolyn( A );
	cout << endl;
	DestroyPolyn( A );
	cout << "----------------------------------------------------------------" << endl;
	int SUM;
	cout << "检验多项式的运算，先创建1个新多项式，请输入多项式A的项数" << endl;
	cin >> m;
	cout << "请输入A各项的系数和指数" << endl;
	CreatPolyn( A, m );
	cout << "请输入未知数的值" << endl;
	cin >> m;
	CalculatorPolyn( A, m, SUM);
	cout << "运算之后的数值为：" << endl << endl;
	cout << SUM;
	cout << endl;
	DestroyPolyn( A );
	return 0;
}
