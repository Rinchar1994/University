#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define SUM 20;

//���嵥����,ѭ������������
typedef struct Lnode{
	int data;/*�������Ԫ��	*/
	struct Lnode *next;
} Lnode;

//����˫������������
typedef struct BothLnode{
	struct BothLnode *prior;
	int data;
	struct BothLnode *next;
}BothLnode;

//����һ����ͷָ����Ԫ������ĵ�����
void Create( Lnode &L, int num ){
	Lnode *p, *h = &L;
	h->next= NULL;//����һ����ͷ���ĵ�����
	for( int i = num; i>0; i-- ){//�����½��
		p = ( Lnode* )malloc( sizeof(Lnode));
		p->data = 1+rand()%100;//������Ԫ��
		p->next = h->next;
		h->next = p;//���뵽��ͷ
	}
}

//����һ��Ԫ�������ѭ������
void CreateCir( Lnode &L, int num ){
	Lnode *p, *h = &L;
	h->next= h;//����һ���յ�ѭ������
	for( int i = num; i>0; i-- ){//�����½��
		p = ( Lnode* )malloc( sizeof(Lnode));
		p->data = 1+rand()%100;//������Ԫ��
		p->next = h->next;
		h->next = p;//���뵽��ͷ
	}
}

//����һ��Ԫ�������˫������
void CreateBoth( BothLnode &L, int num ){
	BothLnode *p, *h = &L;
	h->next = NULL;
	h->prior = NULL;//����һ����ͷ���ĵ�����
	for( int i = num; i>0; i-- ){//�����½��
		p = ( BothLnode* )malloc( sizeof(BothLnode));
		p->data = 1+rand()%100;//������Ԫ��
		p->next = h->next;
		h->next = p;//���뵽��ͷ
		p->prior = h;
	}
}

//����һ���������ֺ㶨����
void CreateOrder( Lnode &L ){
	Lnode *p, *h = &L;
	int q = 100, i = SUM;
	h->next= NULL;//����һ����ͷָ��ĵ�����
	while( i ){//�����½��
		p = ( Lnode* )malloc( sizeof(Lnode));
		p->data = q - rand()%5;//���ɴ���ǰһ��Ԫ�ص���
		q = p->data;
		p->next = h->next;
		h->next = p;//���뵽��ͷ
		i--;
	}
}

//�ڵ�i��λ��֮ǰ����Ԫ��e(����ѭ����
int Insert( Lnode &L, int i, int e ){
	Lnode *p = &L, *s;
	int j = 0;
	while( p && j < i-1 ){
		p = p->next;
		++j;
	}//��ͷָ�룬Ѱ�ҵ�i-1�����
	if( !p || j > i-1 )
		return 0;//iС��1���ߴ��ڱ���1
	s = ( Lnode* )malloc( sizeof(Lnode) );//�����½��
	s->data = e;
	s->next = p->next;
	p->next = s;//����L��
	return 0;
}


//�ڵ�i��λ��֮ǰ����Ԫ��e��˫������
int InsertBoth( BothLnode &L, int i, int e ){
	BothLnode *p = &L, *s;
	int j = 0;
	while( p && j < i-1 ){
		p = p->next;
		++j;
	}//��ͷָ�룬Ѱ�ҵ�i-1�����
	if( !p || j > i-1 )
		return 0;//iС��1���ߴ��ڱ���1
	s = ( BothLnode* )malloc( sizeof(BothLnode) );//�����½��
	s->data = e;
	s->next = p->next;
	p->next = s;//����L��
	s->prior = p;
	return 0;
}
//ɾ����i��Ԫ��,������e��ֵ(����ѭ����
int Delete( Lnode &L, int i, int &e ){
	Lnode *p = &L ,*q;
	int j = 0;
	while( p->next && j < i-1 ){
		p = p->next;
		++j;
	}//Ѱ�ҵ�i����㣬����pָ����ǰ��
	if( !( p->next ) || j > i-1)
		return 0;//ɾ��������λ��
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return 0;
}

//ɾ����i��Ԫ��,������e��ֵ(˫������
int DeleteBoth( BothLnode &L, int i, int &e ){
	BothLnode *p = &L ,*q;
	int j = 0;
	while( p->next && j < i-1 ){
		p = p->next;
		++j;
	}//Ѱ�ҵ�i����㣬����pָ����ǰ��
	if( !( p->next ) || j > i-1)
		return 0;//ɾ��������λ��
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	e = q->data;
	free(q);
	return 0;
}
//�ڵ��������ҵ���һ��ֵΪe��Ԫ�أ�����ʾ�ǵڼ���λ��
void Getelem( Lnode &L, int e ){
	Lnode *p = &L;
	int j = 0;
	while( p->next ){//p������β���ǽ�ֹ
		j++;//����
		if( p->data == e ){
			cout << "��" << j << "��λ��" << endl << endl;
			break;
		}
		p = p->next;
	}
	if( !( p->next ) ){//��������β�˵ĸ������
		if( p->data == e)
			cout << "��" << ++j << "��λ��" << endl << endl;
		else
			cout << "û�����Ԫ��" << endl << endl;
	}
}

//��ѭ���������ҵ���һ��ֵΪe��Ԫ�أ�����ʾ�ǵڼ���λ��
void GetelemCir( Lnode &L, int e ){
	Lnode *p = &L;
	int j = 0;
	while( p->next != &L ){//p��ͷ���ǰһ��ʱ��ֹ
		j++;//����
		if( p->data == e ){
			cout << "��" << j << "��λ��" << endl << endl;
			break;
		}
		p = p->next;
	}
	if(  p->next == &L ){//��������β�˵ĸ������
		if( p->data == e)
			cout << "��" << ++j << "��λ��" << endl << endl;
		else
			cout << "û�����Ԫ��" << endl << endl;
	}
}

//��˫���������ҵ���һ��ֵΪe��Ԫ�أ�����ʾ�ǵڼ���λ��
void GetelemBoth( BothLnode &L, int e ){
	BothLnode *p = &L;
	int j = 0;
	while( p->next ){//p������β���ǽ�ֹ
		j++;//����
		if( p->data == e ){
			cout << "��" << j << "��λ��" << endl << endl;
			break;
		}
		p = p->next;
	}
	if( !( p->next ) ){//��������β�˵ĸ������
		if( p->data == e)
			cout << "��" << ++j << "��λ��" << endl << endl;
		else
			cout << "û�����Ԫ��" << endl << endl;
	}
}

//���ٵ�����
void Destroy( Lnode &L ){
	Lnode *p = L.next, *q = L.next;
	while( p ){
		q = p->next;
		free( p );
		p = q;
	}
}

//����ѭ������
void DestroyCir( Lnode &L ){
	Lnode *p = L.next, *q = L.next;
	while( p == &L ){
		q = p->next;
		free( p );
		p = q;
	}
}

//����˫������
void DestroyBoth( BothLnode &L ){
	BothLnode *p = L.next, *q = L.next;
	while( p ){
		q = p->next;
		free( p );
		p = q;
	}
}
//�����������в�����
void InsertOrder( Lnode &L, int e ){
	int j = 0;
	Lnode *p = L.next;//������ͷ���
	while( p->next ){//������㵽�����ڶ������
		j++;
		if( p->data >= e ){
			Insert( L, j, e );
			break;
		}
		p = p->next;
	}
	if( p->data < e ){//�������һ�����
		p = p->next;
		j++;
		if( p->data >= e )
			Insert( L, j, e );
		else{
			j++;
			Insert( L, j, e );
		}
	}
}

//�ϲ�������������La,Lb��Lc��
void Merge( Lnode &La, Lnode &Lb, Lnode &Lc ){
	Lnode *pa = La.next, *pb = Lb.next, *pc = &Lc;
	while( pa && pb ){
		if( pa->data <= pb->data ){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;//����ʣ���
}

//�ϲ�����ѭ������
void MergeCir( Lnode &La, Lnode &Lb, Lnode &Lc ){
	Lnode *pa = La.next, *pb = Lb.next;
	Lc.next = pa;
	while( pa->next != &La )
		pa = pa->next;//�ҵ�β���
	while( pb->next != &Lb )
		pb = pb->next;
	pa->next = Lb.next;//La��β���ָ��Lb��ͷ���
	pb->next = &Lc;//Lb��β���ָ��Lc
}
//�ϲ�����˫������La,Lb��Lc�У�������
void MergeBoth( BothLnode &La, BothLnode &Lb, BothLnode &Lc ){
	BothLnode *pa = La.next, *pb = pa;
	while( pa->next )
		pa = pa->next;
	pa->next = Lb.next;
	Lb.next->prior = pa;
	Lc.next = pb;
	pb->prior = &Lc;
}

//����������еĸ���Ԫ��
void Print( Lnode &L ){
	Lnode *p = L.next;
	int i=0;
	while( p ){
		i++;
		cout << setw(3) << setiosflags(ios::right) << p->data << " " ;
		if( i%10 == 0 )//10��һ��
			cout << endl;
		p = p->next;
	}
}

//���ѭ�������еĸ���Ԫ��
void PrintCir( Lnode &L ){
	Lnode *p = L.next;
	int i=0;
	while( p != &L ){
		i++;
		cout << setw(3) << setiosflags(ios::right) << p->data << " " ;
		if( i%10 == 0 )//10��һ��
			cout << endl;
		p = p->next;
	}
}

//���˫�������еĸ���Ԫ��
void PrintBoth( BothLnode &L ){
	BothLnode *p = L.next;
	int i=0;
	while( p ){
		i++;
		cout << setw(3) << setiosflags(ios::right) << p->data << " " ;
		if( i%10 == 0 )//10��һ��
			cout << endl;
		p = p->next;
	}
}
//��������
void Backorder( Lnode &L ){
	if( L.next ){
	    Lnode *p = L.next;
	    Lnode *q = L.next->next;
	    L.next = NULL;//�Ͽ�ͷָ��
	    while( p->next ){//ֻ��ͣ�ڵ����ڶ������
		    p->next = L.next;
		    L.next = p;
		    p = q;
		    q = q->next;
	    }
		p->next = L.next;//�������һ��
		L.next = p;
	}
}

//ɾ���������ظ���Ԫ��
void Deleteextra( Lnode &L ){
	Lnode *p = L.next, *q, *s;
	int i, x=1, e;
	while( p->next ){
		i = x;
		q = p->next;
		while( q ){
			i++;
		    if( p->data == q->data ){
				s = q->next;
			    Delete( L, i, e );
				i--;
				q = s;
				continue;
			}
			q = q->next;
		}
		p = p->next;
		x++;
	}
}



//�ж�һ�������Ƿ�Ϊѭ������
void JudgeCir( Lnode &L ){
	Lnode *p = &L;
	while( 1 ){
		if( !( p->next ) ){
			cout << "���������ѭ������" << endl;
			break;
		}
		if( p->next == &L ){
			cout << "���������ѭ������" << endl;
			break;
		}
		p = p->next;
	}
}

int main(){
	Lnode A;
	Create( A, 20 );
	cout << "����һ��������A����������ʾ����Ԫ��" << endl;
	Print( A );
	cout << endl << endl << "�ڵ�i�����֮ǰ����һ���½��" << endl;
	cout << "������Ҫ�����λ��i����ֵe" << endl;
	int i, e;
	cin >> i;
	cin >> e;
	Insert( A, i, e );
	cout << "������A�ĸ��������Ϊ��" << endl;
	Print( A );
	cout << endl << endl << "ɾ����i�����" << endl;
	cout << "������Ҫɾ���Ľ����" << endl;
	cin >> i;
	Delete( A, i, e );
	cout << "������A�ĸ��������Ϊ��" << endl;
	Print( A );
	cout << endl << endl << "��������Ԫ����e��ȵĽ�㣬�����λ�ã�������Ҫ���ҵ�e" << endl;
	cin >> e;
	Getelem( A, e );
	cout << endl << endl << "����һ����������B" << endl;
	Lnode B;
	CreateOrder( B );
	Print( B );
	cout << endl << endl << "����С����һ����ֵe��������e��ֵ" << endl;
	cin >> e;
	InsertOrder( B, e );
	cout << "������B�ĸ��������Ϊ��" << endl;
	Print( B );
	Lnode C, D;
	Create( D, 0 );
	cout << endl << endl << "����һ����������C" << endl;
	CreateOrder( C );
	Print( C );
	cout << endl << endl << "�ϲ�������������B,C�õ�D" << endl;
	Merge( B, C, D );
	cout << "������D�ĸ��������Ϊ��" << endl;
	Print( D );
	cout << endl << endl << "�½���������E" << endl;
	Lnode E;
	CreateOrder( E );
	//Create( E, 0 );
	Print( E );
	cout << endl << endl << "���������E" << endl;
	Backorder( E );
	cout << "������E�ĸ��������Ϊ��" << endl;
    Print( E );
	cout << endl << endl << "�½���������F" << endl;
	Lnode F;
	Create( F, 20 );
	cout << "������F�ĸ��������Ϊ��" << endl;
    Print( F );
	cout << endl << endl << "ɾ���ظ���Ԫ�أ�������F������" << endl;
	Deleteextra( F );
	cout << "������F�ĸ��������Ϊ��" << endl;
    Print( F );
	cout << endl << endl << "����ѭ������G����ӡ����" << endl;
	Lnode G;
	CreateCir( G, 20 );
	PrintCir( G );
	cout << endl << endl << "����ѭ��������롢ɾ���뵥������ͬ�����ﲻ����ʾ" << endl;
	cout << endl << endl << "���ҵ�һ��Ԫ����t��ͬ�Ľ�㣬������t" << endl;
	int t;
	cin >> t;
	GetelemCir( G, t );
	cout << endl << endl << "�½�һ��ѭ������H�����Ҵ�ӡ����" << endl;
	Lnode H, I;
	CreateCir( H, 20 );
	PrintCir( H );
	cout << endl << endl << "�ϲ�G��H,�±�IΪ" << endl;
	MergeCir( G, H, I );
	PrintCir( I );
	cout << endl << endl << "����һ��˫������J�����Ҵ�ӡ����" << endl;
	BothLnode J;
	CreateBoth( J, 20 );
	PrintBoth( J );
	cout << endl << endl << "�ڵ�h��λ��ǰ����һ����㣬��Ԫ��Ϊs��������ֵ" << endl;
	int h, s;
	cin >> h;
	cin >> s;
	InsertBoth( J, h, s );
	cout << "������J�ĸ��������Ϊ��" << endl;
    PrintBoth( J );
	cout << endl << endl << "ɾ����h��λ�ý��,������h��ֵ,�䷵��ֵ��s" << endl;
	cin >> h;
	DeleteBoth( J, h, s );
	cout << "������J�ĸ��������Ϊ��" << endl;
    PrintBoth( J );
	cout << endl << "����ֵsΪ��" << s;
	cout << endl << endl << "����Ԫ����s��ͬ�Ľ��λ�ã�������s��ֵ" << endl;
	cin >> s;
	GetelemBoth( J, s );
	cout << endl << endl << "����һ���µ�˫������K��L�����ҽ�K��ӡ����" << endl;
	BothLnode K, L;
	CreateBoth( K, 20 );
	CreateBoth( L, 0 );
	PrintBoth( K );
	cout << endl << endl << "�ϲ�K��J,����ӡ����" << endl;
	MergeBoth( J, K, L );
	cout << "������L�ĸ��������Ϊ��" << endl;
    PrintBoth( L );
	cout << endl << endl << "�ж�һ�������Ƿ�Ϊѭ������" << endl;

	//����˫��������жϺ͵�������ж����ƣ����㷨д�о�̫�鷳��ֱ����һ�����������Ե������ѭ������

	cout << endl << endl << "����һ��������M��һ��ѭ������N" << endl;
	Lnode M;
	Create( M, 20 );
	cout << endl << "������MΪ" << endl;
	Print( M );
	Lnode N;
	CreateCir( N, 20 );
	cout << endl << endl << "ѭ������NΪ" << endl;
	PrintCir( N );
	cout << endl << endl << "��������M�������" << endl;
	JudgeCir( M );
	cout << endl << endl << "��˫����N�������" << endl;
	JudgeCir( N );
	Destroy( A );
	Destroy( D );
	Destroy( E );
	Destroy( F );
	DestroyCir( I );
	DestroyBoth( L );
	Destroy( M );
	DestroyCir( N );
	return 0;
}











