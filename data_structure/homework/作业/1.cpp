//1252366 ���賬 ����һ��

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -2

typedef struct{
	int *elem;
	int length;
	int listsize;
}Sqlist;

//��������ʼ��˳���
void Initlist_Sq( Sqlist &L ){
	L.elem = new int[ LIST_INIT_SIZE ];
	if( !L.elem )
		exit( OVERFLOW );
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

//��ָ��λ�ò���ָ������
int Listinsert_Sq( Sqlist &L, int i, int e ){
	if( i>L.length+1 || i<1 )
		return ERROR;
	if( L.length >= L.listsize ){
		int *newbase = new  int[ L.listsize  + LISTINCREMENT ];
		if( !newbase )
			exit( OVERFLOW );
		for( int num=0; num<L.length; num++)
	    	        newbase[ num ] = L.elem[ num ];
		delete []L.elem;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	for( int s=L.length-1; s>=i-1; s-- )
		L.elem[ s+1 ] = L.elem[ s ];
	L.elem[ i-1 ] = e;
	++L.length;
	return OK;
}

//ɾ��˳�����ָ����Ԫ�ز��ҽ�ɾ����Ԫ�ظ������ͱ���
int Listdelete_Sq( Sqlist &L, int i , int &e ){
	if( i<1 || i>L.length )
		return ERROR;
	e = L.elem[ i-1 ];
	for( int num=i-1; num<=L.length-1; num++ )
		L.elem[ num ] = L.elem[ num+1 ];
	--L.length;
	return OK;
}

//�ҳ���e��˳����е�����λ�ò���ʾ����
void Locateelem_Sq( Sqlist &L, int e ){
	int t=0;
	for( int i=0; i<L.length; i++ ){
		if( L.elem[ i ] == e ){
			t++;
			cout << "��" << i+1 << "λ" << " ";
			if( (i+1)%5 == 0 )
				cout << endl;
		}
	}
	if( t == 0 )
		cout << "˳�����û�������" << endl;
}

//�ͷ�����Ŀռ䣬�ٻ�˳���
void Destroylist_Sq( Sqlist &L ){
	delete []L.elem;
}

//����ʼ�������ݱ��������Ԫ�ص�ֵ
void Buildlistlist_Sq( Sqlist &L ){
	cout << "������100��������Ϊ˳���Ԫ��" << endl;
	int e;
	for( int i=0; i<LIST_INIT_SIZE; i++){
		cin >> e;
		Listinsert_Sq( L,  i+1,  e );
	}
	cout << endl << endl;
	 Printlist_Sq( L );
}

//���˳���
void Printlist_Sq( Sqlist &L ){
	int num;
	for( num=0; num<L.length; num++ ){
		cout << setw(3) << setiosflags(ios::right) << L.elem[ num ] << ' ';
		 if( (num+1)% 10== 0 )
			cout << endl;
	 }
}

//��������ʾһ�����˳���
void Buildlist( Sqlist &L ){
	Initlist_Sq( L );
	L.length = LIST_INIT_SIZE;
	for( int k=0; k<LIST_INIT_SIZE; k++){
		cout << setw(3) << setiosflags(ios::right) << (L.elem[k]=rand()%100) << ' ';
		if( (k+1)% 10== 0 )
			cout << endl;
	}
}

//��������в���һ��ָ������
void Insertlist( Sqlist &L , int e){
	if( e > L.elem[ L.length-1 ] )
		Listinsert_Sq( L, L.length+1, e );
	else
	        for( int num=0; num<L.length-1; num++){
		        if( L.elem[ num ] <= e && L.elem[ num+1 ] >= e ){
			        Listinsert_Sq( L, num+2, e );
			        break;
				}
			}
}

//�ϲ���������˳���
void Mergelist_Sq( Sqlist La, Sqlist Lb, Sqlist &Lc ){
	Lc.listsize = Lc.length = La.length + Lb.length;
	int *pc = Lc.elem = new int[ Lc.listsize];
	if( !Lc.elem )
		exit( OVERFLOW );
	int *pa = La.elem; int *pb = Lb.elem;
	int *pa_last = La.elem + La.length -1;
	int *pb_last = Lb.elem + Lb.length -1;
	while( pa <= pa_last && pb <= pb_last ){
		if ( *pa <= *pb )
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while ( pa<= pa_last )
		*pc++ = *pa++;
	while ( pb<= pb_last )
		*pc++ = *pb++;
}

//������˳���ת��������˳���
void Changeorder_Sq( Sqlist &L ){
	int p;
	for( int m=0; m<L.length-1; m++ )
		for( int n=L.length-1 ; n>m; n-- )
			if( L.elem[ n-1 ] > L.elem[ n ] ){
				p = L.elem[ n-1 ];
				L.elem [ n-1 ] = L.elem[ n ];
				L.elem[ n ] = p;
			}
}

//ɾ��˳����е�һ����e��ͬ��Ԫ��
void Deletefirst_Sq( Sqlist &L, int e ){
	for( int m=0; m<L.length; m++ ){
		if( L.elem[ m ] == e ){
			Listdelete_Sq( L, m+1 , e );
			break;
		}
		if( m == L.length-1 && e != L.elem[ L.length -1])
			cout << "˳����в�������ֵΪ" << e << "��Ԫ��" << endl;
	}
}

//ɾ��˳��������к�e��ͬ��Ԫ��
void Deleteall_Sq( Sqlist &L, int &e ){
	int num=0;
	for( int m=0; m<L.length; m++ ){
		if( L.elem[ m ] == e ){
			Listdelete_Sq( L, m+1 , e );
			num++;
			m--;
		}
	}
	if( num == 0 )
		cout << "˳����в�������ֵΪ" << e << "��Ԫ��" << endl;
}

//��˳�������
void Backorder_Sq( Sqlist &L ){
	int p;
	for( int i=0; i<L.length/2; i++ ){
		p = L.elem[ i ];
		L.elem[ i ] = L.elem[ L.length-1-i ];
		L.elem[ L.length-1-i ] = p;
	}
}

//���˳���
void Clearlist_Sq( Sqlist &L ){
	int e;
	for( int num=L.length-1; num>=0; num--)
		Listdelete_Sq( L, num+1 , e );
}

//��˳������ظ���Ԫ���޳�
void Deletesame_Sq( Sqlist &L ){
	int e;
	for( int num=0; num<L.length-1; num++)
		for( int s=L.length-1; s>num; s--)
			if( L.elem[ num ] == L.elem[ s ] )
				Listdelete_Sq( L, s , e );
}

void main(){
	int  t, n;
	Sqlist A ;
	cout << "�뽨��һ��˳���" << endl;
	//Initlist_Sq( A );
	//Buildlistlist_Sq( A );
	Buildlist( A );
	cout << endl;
	cout << "�ڵ�n��Ԫ��֮ǰ����һ����Ԫ�أ�������n��ֵ" << endl;
	cin >> n;
	cout << "������Ҫ�������ֵt" << endl;
	cin >> t;
        cout << "�±��Ϊ" << endl;
	Listinsert_Sq( A, n, t );
	Printlist_Sq( A );
	cout << endl;
	cout << "ɾ����n��Ԫ�أ�����ɾȥ��������t�У�������n��ֵ" << endl;
	cin >> n;
	 cout << "�±��Ϊ" << endl;
	 Listdelete_Sq( A, n , t );
	 Printlist_Sq( A );
	 cout << endl;
	 cout << "ɾȥ����ֵΪ:" << t << endl;
	 cout << endl;
	 cout << "������Ҫ���ҵ�Ԫ��ֵ��" << endl;
	 cin >> t;
	 Locateelem_Sq( A , t );
	 cout << endl << endl;
	 cout << "��������ʾ��100������˳���" << endl;
	 Sqlist LA;
	 Buildlist( LA );
	 cout << endl;
	 cout << "��˳����Ԫ�ذ���С��������" << endl;
	 Changeorder_Sq( LA );
         Printlist_Sq( LA );
	 cout << endl << endl;
	 cout << "������t����С����˳����У�������t" << endl;
	 cin >> t;
	 cout << "�±��Ϊ" << endl;
	 Insertlist( LA , t);
	 Printlist_Sq( LA );
	 cout << endl << endl;
	 cout << "�ٴ�������ʾһ����˳���" << endl;
	 Sqlist LB;
	 Buildlist( LB );
	 cout << endl;
	 cout << "ת����Ԫ�ذ���С����˳�����е�˳���" << endl;
	 Changeorder_Sq( LB );
         Printlist_Sq( LB );
	 cout << endl << endl;
	 Sqlist LC;
	 Initlist_Sq( LC );
	 cout << "��˳���LA,LB�ϲ���LC����" << endl;
	 Mergelist_Sq( LA, LB, LC );
         Printlist_Sq( LC );
	 cout << endl << endl;
	 cout << "���½���һ��������˳���" << endl;
	 Sqlist B;
	 Buildlist( B );
	 cout << endl;
	 cout << "ɾȥ˳����е�һ����tֵͬ��Ԫ�أ�������t��ֵ" << endl;
	 cin >> t;
	 cout << endl;
	 Deletefirst_Sq( B, t );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "ɾȥ˳�������tֵͬ������Ԫ�أ�������t��ֵ" << endl;
	 cin >> t;
	 cout << endl;
	 Deleteall_Sq( B, t );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "��˳����е�Ԫ������" << endl;
	 Backorder_Sq( B );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "��˳������" << endl;
	 Clearlist_Sq( B );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "��˳���LC�ж��������ɾ��" << endl;
	 Deletesame_Sq( LC );
	 Printlist_Sq( LC );
	 cout << endl << endl;
	 cout << "��ʾ���" << endl;
	 Destroylist_Sq( A );
	 Destroylist_Sq( B );
	 Destroylist_Sq( LA );
	 Destroylist_Sq( LB );
	 Destroylist_Sq( LC );
}










