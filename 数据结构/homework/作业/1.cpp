//1252366 蒋凌超 电子一班

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

//建立并初始化顺序表
void Initlist_Sq( Sqlist &L ){
	L.elem = new int[ LIST_INIT_SIZE ];
	if( !L.elem )
		exit( OVERFLOW );
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

//在指定位置插入指定数字
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

//删除顺序表中指定的元素并且将删除的元素赋予整型变量
int Listdelete_Sq( Sqlist &L, int i , int &e ){
	if( i<1 || i>L.length )
		return ERROR;
	e = L.elem[ i-1 ];
	for( int num=i-1; num<=L.length-1; num++ )
		L.elem[ num ] = L.elem[ num+1 ];
	--L.length;
	return OK;
}

//找出数e在顺序表中的所有位置并显示出来
void Locateelem_Sq( Sqlist &L, int e ){
	int t=0;
	for( int i=0; i<L.length; i++ ){
		if( L.elem[ i ] == e ){
			t++;
			cout << "第" << i+1 << "位" << " ";
			if( (i+1)%5 == 0 )
				cout << endl;
		}
	}
	if( t == 0 )
		cout << "顺序表中没有这个数" << endl;
}

//释放申请的空间，毁坏顺序表
void Destroylist_Sq( Sqlist &L ){
	delete []L.elem;
}

//给初始化的数据表输入各个元素的值
void Buildlistlist_Sq( Sqlist &L ){
	cout << "请输入100个整数作为顺序表元素" << endl;
	int e;
	for( int i=0; i<LIST_INIT_SIZE; i++){
		cin >> e;
		Listinsert_Sq( L,  i+1,  e );
	}
	cout << endl << endl;
	 Printlist_Sq( L );
}

//输出顺序表
void Printlist_Sq( Sqlist &L ){
	int num;
	for( num=0; num<L.length; num++ ){
		cout << setw(3) << setiosflags(ios::right) << L.elem[ num ] << ' ';
		 if( (num+1)% 10== 0 )
			cout << endl;
	 }
}

//建立并显示一个随机顺序表
void Buildlist( Sqlist &L ){
	Initlist_Sq( L );
	L.length = LIST_INIT_SIZE;
	for( int k=0; k<LIST_INIT_SIZE; k++){
		cout << setw(3) << setiosflags(ios::right) << (L.elem[k]=rand()%100) << ' ';
		if( (k+1)% 10== 0 )
			cout << endl;
	}
}

//在有序表中插入一个指定的数
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

//合并两个有序顺序表
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

//将无序顺序表转换成有序顺序表
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

//删除顺序表中第一个和e相同的元素
void Deletefirst_Sq( Sqlist &L, int e ){
	for( int m=0; m<L.length; m++ ){
		if( L.elem[ m ] == e ){
			Listdelete_Sq( L, m+1 , e );
			break;
		}
		if( m == L.length-1 && e != L.elem[ L.length -1])
			cout << "顺序表中不存在数值为" << e << "的元素" << endl;
	}
}

//删除顺序表中所有和e相同的元素
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
		cout << "顺序表中不存在数值为" << e << "的元素" << endl;
}

//将顺序表逆置
void Backorder_Sq( Sqlist &L ){
	int p;
	for( int i=0; i<L.length/2; i++ ){
		p = L.elem[ i ];
		L.elem[ i ] = L.elem[ L.length-1-i ];
		L.elem[ L.length-1-i ] = p;
	}
}

//清空顺序表
void Clearlist_Sq( Sqlist &L ){
	int e;
	for( int num=L.length-1; num>=0; num--)
		Listdelete_Sq( L, num+1 , e );
}

//将顺序表中重复的元素剔除
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
	cout << "请建立一个顺序表" << endl;
	//Initlist_Sq( A );
	//Buildlistlist_Sq( A );
	Buildlist( A );
	cout << endl;
	cout << "在第n个元素之前插入一个新元素，请输入n的值" << endl;
	cin >> n;
	cout << "请输入要插入的数值t" << endl;
	cin >> t;
        cout << "新表格为" << endl;
	Listinsert_Sq( A, n, t );
	Printlist_Sq( A );
	cout << endl;
	cout << "删除第n个元素，并将删去的数存入t中，请输入n的值" << endl;
	cin >> n;
	 cout << "新表格为" << endl;
	 Listdelete_Sq( A, n , t );
	 Printlist_Sq( A );
	 cout << endl;
	 cout << "删去的数值为:" << t << endl;
	 cout << endl;
	 cout << "请输入要查找的元素值：" << endl;
	 cin >> t;
	 Locateelem_Sq( A , t );
	 cout << endl << endl;
	 cout << "建立并显示含100个数的顺序表" << endl;
	 Sqlist LA;
	 Buildlist( LA );
	 cout << endl;
	 cout << "将顺序表的元素按从小到大排列" << endl;
	 Changeorder_Sq( LA );
         Printlist_Sq( LA );
	 cout << endl << endl;
	 cout << "将整数t按大小插入顺序表中，请输入t" << endl;
	 cin >> t;
	 cout << "新表格为" << endl;
	 Insertlist( LA , t);
	 Printlist_Sq( LA );
	 cout << endl << endl;
	 cout << "再创建并显示一个新顺序表" << endl;
	 Sqlist LB;
	 Buildlist( LB );
	 cout << endl;
	 cout << "转换成元素按从小到大顺序排列的顺序表" << endl;
	 Changeorder_Sq( LB );
         Printlist_Sq( LB );
	 cout << endl << endl;
	 Sqlist LC;
	 Initlist_Sq( LC );
	 cout << "将顺序表LA,LB合并到LC当中" << endl;
	 Mergelist_Sq( LA, LB, LC );
         Printlist_Sq( LC );
	 cout << endl << endl;
	 cout << "重新建立一个非有序顺序表" << endl;
	 Sqlist B;
	 Buildlist( B );
	 cout << endl;
	 cout << "删去顺序表中第一个与t同值的元素，请输入t的值" << endl;
	 cin >> t;
	 cout << endl;
	 Deletefirst_Sq( B, t );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "删去顺序表中与t同值的所有元素，请输入t的值" << endl;
	 cin >> t;
	 cout << endl;
	 Deleteall_Sq( B, t );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "将顺序表中的元素逆置" << endl;
	 Backorder_Sq( B );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "将顺序表清空" << endl;
	 Clearlist_Sq( B );
	 Printlist_Sq( B );
	 cout << endl << endl;
	 cout << "将顺序表LC中多余的数字删除" << endl;
	 Deletesame_Sq( LC );
	 Printlist_Sq( LC );
	 cout << endl << endl;
	 cout << "演示完毕" << endl;
	 Destroylist_Sq( A );
	 Destroylist_Sq( B );
	 Destroylist_Sq( LA );
	 Destroylist_Sq( LB );
	 Destroylist_Sq( LC );
}










