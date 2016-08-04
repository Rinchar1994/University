#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define SUM 20;

//定义单链表,循环链表结点内容
typedef struct Lnode{
	int data;/*存放链表元素	*/
	struct Lnode *next;
} Lnode;

//定义双向链表结点内容
typedef struct BothLnode{
	struct BothLnode *prior;
	int data;
	struct BothLnode *next;
}BothLnode;

//创建一个有头指针且元素随机的单链表
void Create( Lnode &L, int num ){
	Lnode *p, *h = &L;
	h->next= NULL;//建立一个带头结点的单链表
	for( int i = num; i>0; i-- ){//生成新结点
		p = ( Lnode* )malloc( sizeof(Lnode));
		p->data = 1+rand()%100;//生成新元素
		p->next = h->next;
		h->next = p;//插入到表头
	}
}

//创建一个元素随机的循环链表
void CreateCir( Lnode &L, int num ){
	Lnode *p, *h = &L;
	h->next= h;//建立一个空的循环链表
	for( int i = num; i>0; i-- ){//生成新结点
		p = ( Lnode* )malloc( sizeof(Lnode));
		p->data = 1+rand()%100;//生成新元素
		p->next = h->next;
		h->next = p;//插入到表头
	}
}

//创建一个元素随机的双向链表
void CreateBoth( BothLnode &L, int num ){
	BothLnode *p, *h = &L;
	h->next = NULL;
	h->prior = NULL;//建立一个带头结点的单链表
	for( int i = num; i>0; i-- ){//生成新结点
		p = ( BothLnode* )malloc( sizeof(BothLnode));
		p->data = 1+rand()%100;//生成新元素
		p->next = h->next;
		h->next = p;//插入到表头
		p->prior = h;
	}
}

//建立一个有序数字恒定链表
void CreateOrder( Lnode &L ){
	Lnode *p, *h = &L;
	int q = 100, i = SUM;
	h->next= NULL;//建立一个带头指针的单链表
	while( i ){//生成新结点
		p = ( Lnode* )malloc( sizeof(Lnode));
		p->data = q - rand()%5;//生成大于前一个元素的数
		q = p->data;
		p->next = h->next;
		h->next = p;//插入到表头
		i--;
	}
}

//在第i个位置之前插入元素e(单、循链表）
int Insert( Lnode &L, int i, int e ){
	Lnode *p = &L, *s;
	int j = 0;
	while( p && j < i-1 ){
		p = p->next;
		++j;
	}//有头指针，寻找第i-1个结点
	if( !p || j > i-1 )
		return 0;//i小于1或者大于表长加1
	s = ( Lnode* )malloc( sizeof(Lnode) );//生成新结点
	s->data = e;
	s->next = p->next;
	p->next = s;//插入L中
	return 0;
}


//在第i个位置之前插入元素e（双向链表）
int InsertBoth( BothLnode &L, int i, int e ){
	BothLnode *p = &L, *s;
	int j = 0;
	while( p && j < i-1 ){
		p = p->next;
		++j;
	}//有头指针，寻找第i-1个结点
	if( !p || j > i-1 )
		return 0;//i小于1或者大于表长加1
	s = ( BothLnode* )malloc( sizeof(BothLnode) );//生成新结点
	s->data = e;
	s->next = p->next;
	p->next = s;//插入L中
	s->prior = p;
	return 0;
}
//删除第i个元素,并返回e的值(单、循链表）
int Delete( Lnode &L, int i, int &e ){
	Lnode *p = &L ,*q;
	int j = 0;
	while( p->next && j < i-1 ){
		p = p->next;
		++j;
	}//寻找第i个结点，并令p指向其前趋
	if( !( p->next ) || j > i-1)
		return 0;//删除不合理位置
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return 0;
}

//删除第i个元素,并返回e的值(双向链表）
int DeleteBoth( BothLnode &L, int i, int &e ){
	BothLnode *p = &L ,*q;
	int j = 0;
	while( p->next && j < i-1 ){
		p = p->next;
		++j;
	}//寻找第i个结点，并令p指向其前趋
	if( !( p->next ) || j > i-1)
		return 0;//删除不合理位置
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	e = q->data;
	free(q);
	return 0;
}
//在单链表中找到第一个值为e的元素，并显示是第几个位置
void Getelem( Lnode &L, int e ){
	Lnode *p = &L;
	int j = 0;
	while( p->next ){//p是链表尾端是截止
		j++;//计数
		if( p->data == e ){
			cout << "第" << j << "个位置" << endl << endl;
			break;
		}
		p = p->next;
	}
	if( !( p->next ) ){//考虑链表尾端的各种情况
		if( p->data == e)
			cout << "第" << ++j << "个位置" << endl << endl;
		else
			cout << "没有这个元素" << endl << endl;
	}
}

//在循环链表中找到第一个值为e的元素，并显示是第几个位置
void GetelemCir( Lnode &L, int e ){
	Lnode *p = &L;
	int j = 0;
	while( p->next != &L ){//p是头结点前一个时截止
		j++;//计数
		if( p->data == e ){
			cout << "第" << j << "个位置" << endl << endl;
			break;
		}
		p = p->next;
	}
	if(  p->next == &L ){//考虑链表尾端的各种情况
		if( p->data == e)
			cout << "第" << ++j << "个位置" << endl << endl;
		else
			cout << "没有这个元素" << endl << endl;
	}
}

//在双向链表中找到第一个值为e的元素，并显示是第几个位置
void GetelemBoth( BothLnode &L, int e ){
	BothLnode *p = &L;
	int j = 0;
	while( p->next ){//p是链表尾端是截止
		j++;//计数
		if( p->data == e ){
			cout << "第" << j << "个位置" << endl << endl;
			break;
		}
		p = p->next;
	}
	if( !( p->next ) ){//考虑链表尾端的各种情况
		if( p->data == e)
			cout << "第" << ++j << "个位置" << endl << endl;
		else
			cout << "没有这个元素" << endl << endl;
	}
}

//销毁单链表
void Destroy( Lnode &L ){
	Lnode *p = L.next, *q = L.next;
	while( p ){
		q = p->next;
		free( p );
		p = q;
	}
}

//销毁循环链表
void DestroyCir( Lnode &L ){
	Lnode *p = L.next, *q = L.next;
	while( p == &L ){
		q = p->next;
		free( p );
		p = q;
	}
}

//销毁双向链表
void DestroyBoth( BothLnode &L ){
	BothLnode *p = L.next, *q = L.next;
	while( p ){
		q = p->next;
		free( p );
		p = q;
	}
}
//在有序链表中插入结点
void InsertOrder( Lnode &L, int e ){
	int j = 0;
	Lnode *p = L.next;//不考虑头结点
	while( p->next ){//最多运算到倒数第二个结点
		j++;
		if( p->data >= e ){
			Insert( L, j, e );
			break;
		}
		p = p->next;
	}
	if( p->data < e ){//考虑最后一个结点
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

//合并两个有序链表La,Lb到Lc中
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
	pc->next = pa?pa:pb;//插入剩余段
}

//合并两个循环链表
void MergeCir( Lnode &La, Lnode &Lb, Lnode &Lc ){
	Lnode *pa = La.next, *pb = Lb.next;
	Lc.next = pa;
	while( pa->next != &La )
		pa = pa->next;//找到尾结点
	while( pb->next != &Lb )
		pb = pb->next;
	pa->next = Lb.next;//La的尾结点指向Lb的头结点
	pb->next = &Lc;//Lb的尾结点指向Lc
}
//合并两个双向链表La,Lb到Lc中（非有序）
void MergeBoth( BothLnode &La, BothLnode &Lb, BothLnode &Lc ){
	BothLnode *pa = La.next, *pb = pa;
	while( pa->next )
		pa = pa->next;
	pa->next = Lb.next;
	Lb.next->prior = pa;
	Lc.next = pb;
	pb->prior = &Lc;
}

//输出单链表中的各个元素
void Print( Lnode &L ){
	Lnode *p = L.next;
	int i=0;
	while( p ){
		i++;
		cout << setw(3) << setiosflags(ios::right) << p->data << " " ;
		if( i%10 == 0 )//10个一行
			cout << endl;
		p = p->next;
	}
}

//输出循环链表中的各个元素
void PrintCir( Lnode &L ){
	Lnode *p = L.next;
	int i=0;
	while( p != &L ){
		i++;
		cout << setw(3) << setiosflags(ios::right) << p->data << " " ;
		if( i%10 == 0 )//10个一行
			cout << endl;
		p = p->next;
	}
}

//输出双向链表中的各个元素
void PrintBoth( BothLnode &L ){
	BothLnode *p = L.next;
	int i=0;
	while( p ){
		i++;
		cout << setw(3) << setiosflags(ios::right) << p->data << " " ;
		if( i%10 == 0 )//10个一行
			cout << endl;
		p = p->next;
	}
}
//逆置链表
void Backorder( Lnode &L ){
	if( L.next ){
	    Lnode *p = L.next;
	    Lnode *q = L.next->next;
	    L.next = NULL;//断开头指针
	    while( p->next ){//只能停在倒数第二个结点
		    p->next = L.next;
		    L.next = p;
		    p = q;
		    q = q->next;
	    }
		p->next = L.next;//考虑最后一项
		L.next = p;
	}
}

//删除链表中重复的元素
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



//判断一个链表是否为循环链表
void JudgeCir( Lnode &L ){
	Lnode *p = &L;
	while( 1 ){
		if( !( p->next ) ){
			cout << "这个链表不是循环链表" << endl;
			break;
		}
		if( p->next == &L ){
			cout << "这个链表是循环链表" << endl;
			break;
		}
		p = p->next;
	}
}

int main(){
	Lnode A;
	Create( A, 20 );
	cout << "建立一个新链表A并且依次显示所有元素" << endl;
	Print( A );
	cout << endl << endl << "在第i个结点之前插入一个新结点" << endl;
	cout << "请输入要插入的位置i和数值e" << endl;
	int i, e;
	cin >> i;
	cin >> e;
	Insert( A, i, e );
	cout << "新链表A的个结点内容为：" << endl;
	Print( A );
	cout << endl << endl << "删除第i个结点" << endl;
	cout << "请输入要删除的结点编号" << endl;
	cin >> i;
	Delete( A, i, e );
	cout << "新链表A的个结点内容为：" << endl;
	Print( A );
	cout << endl << endl << "查找与结点元素与e相等的结点，并输出位置，请输入要查找的e" << endl;
	cin >> e;
	Getelem( A, e );
	cout << endl << endl << "生成一个有序链表B" << endl;
	Lnode B;
	CreateOrder( B );
	Print( B );
	cout << endl << endl << "按大小插入一个数值e，请输入e的值" << endl;
	cin >> e;
	InsertOrder( B, e );
	cout << "新链表B的个结点内容为：" << endl;
	Print( B );
	Lnode C, D;
	Create( D, 0 );
	cout << endl << endl << "生成一个有序链表C" << endl;
	CreateOrder( C );
	Print( C );
	cout << endl << endl << "合并两个有序链表B,C得到D" << endl;
	Merge( B, C, D );
	cout << "新链表D的个结点内容为：" << endl;
	Print( D );
	cout << endl << endl << "新建有序链表E" << endl;
	Lnode E;
	CreateOrder( E );
	//Create( E, 0 );
	Print( E );
	cout << endl << endl << "逆置有序表E" << endl;
	Backorder( E );
	cout << "新链表E的个结点内容为：" << endl;
    Print( E );
	cout << endl << endl << "新建有序链表F" << endl;
	Lnode F;
	Create( F, 20 );
	cout << "新链表F的个结点内容为：" << endl;
    Print( F );
	cout << endl << endl << "删除重复的元素，用链表F来检验" << endl;
	Deleteextra( F );
	cout << "新链表F的个结点内容为：" << endl;
    Print( F );
	cout << endl << endl << "建立循环链表G并打印出来" << endl;
	Lnode G;
	CreateCir( G, 20 );
	PrintCir( G );
	cout << endl << endl << "无序循环链表插入、删除与单链表相同，这里不做演示" << endl;
	cout << endl << endl << "查找第一个元素与t相同的结点，请输入t" << endl;
	int t;
	cin >> t;
	GetelemCir( G, t );
	cout << endl << endl << "新建一个循环链表H，并且打印出来" << endl;
	Lnode H, I;
	CreateCir( H, 20 );
	PrintCir( H );
	cout << endl << endl << "合并G、H,新表I为" << endl;
	MergeCir( G, H, I );
	PrintCir( I );
	cout << endl << endl << "建立一个双向链表J，并且打印出来" << endl;
	BothLnode J;
	CreateBoth( J, 20 );
	PrintBoth( J );
	cout << endl << endl << "在第h个位置前插入一个结点，其元素为s并输入其值" << endl;
	int h, s;
	cin >> h;
	cin >> s;
	InsertBoth( J, h, s );
	cout << "新链表J的个结点内容为：" << endl;
    PrintBoth( J );
	cout << endl << endl << "删除第h个位置结点,请输入h的值,其返回值是s" << endl;
	cin >> h;
	DeleteBoth( J, h, s );
	cout << "新链表J的个结点内容为：" << endl;
    PrintBoth( J );
	cout << endl << "返回值s为：" << s;
	cout << endl << endl << "查找元素与s相同的结点位置，请输入s的值" << endl;
	cin >> s;
	GetelemBoth( J, s );
	cout << endl << endl << "生成一个新的双向链表K，L，并且将K打印出来" << endl;
	BothLnode K, L;
	CreateBoth( K, 20 );
	CreateBoth( L, 0 );
	PrintBoth( K );
	cout << endl << endl << "合并K、J,并打印出来" << endl;
	MergeBoth( J, K, L );
	cout << "新链表L的个结点内容为：" << endl;
    PrintBoth( L );
	cout << endl << endl << "判断一个链表是否为循环链表" << endl;

	//由于双向链表的判断和单链表的判断类似，用算法写感觉太麻烦，直接用一个函数来测试单链表和循环链表

	cout << endl << endl << "生成一个单链表M，一个循环链表N" << endl;
	Lnode M;
	Create( M, 20 );
	cout << endl << "单链表M为" << endl;
	Print( M );
	Lnode N;
	CreateCir( N, 20 );
	cout << endl << endl << "循环链表N为" << endl;
	PrintCir( N );
	cout << endl << endl << "将单链表M带入检验" << endl;
	JudgeCir( M );
	cout << endl << endl << "将双链表N带入检验" << endl;
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











