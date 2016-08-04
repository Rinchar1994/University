#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define MAXNUM 32000  //当结点扩展之后赋值给f，标记该结点
#define CELLNUM 10

//用来显示操作的序列
int count_of_state = 0;
//用来存放临时状态
char now_state[CELLNUM];

typedef struct {
	int f;
	int g;
	char state[CELLNUM];  //八数码问题中的空格用'0'表示，state[9]不存放内容，方便显示
	int stat_of_zero; //用来显示0所在的位置
}_node_state;

typedef struct _State_Node{
	_State_Node* parent;   //指向父结点
	_State_Node* child;   //在链表（根据f值排列的链表）中的后继结点
	_node_state STATE;
}*Linklist;

//用于存放最后的路径
_State_Node table[20000];

//  用于计算当前状态与目标状态中某个编号的距离，以便计算h
int cal_h[9][9] = { { 0, 1, 2, 1, 2, 3, 2, 3, 4 },
                    { 1, 0, 1, 2, 1, 2, 3, 2, 3 },
                    { 2, 1, 0, 3, 2, 1, 4, 3, 2 },
                    { 1, 2, 3, 0, 1, 2, 1, 2, 3 },
                    { 2, 1, 2, 1, 0, 1, 2, 1, 2 },
                    { 3, 2, 1, 2, 1, 0, 3, 2, 1 },
                    { 2, 3, 4, 1, 2, 3, 0, 1, 2 },
                    { 3, 2, 3, 2, 1, 2, 1, 0, 1 },
                    { 4, 3, 2, 3, 2, 1, 2, 1, 0 } }; 


/***************************************************************

    声明部分

****************************************************************/

void create_state_list( Linklist &L, Linklist &L_last, char* ini_state, char* tar_state );  //根结点的建立
int working_select( Linklist &L, Linklist &L_last, char* tar_state ); //选择扩展的结点
int extention_node( Linklist &L, Linklist &L_last, char* tar_state);  //扩展结点
int create_node( Linklist &L, Linklist &L_last, char* tar_state, int mov );  //生成结点
void delete_list( Linklist &L );
void printf_state( Linklist &L );

/****************************************************************

   主函数部分

****************************************************************/
void main()
{
	char ini_state[CELLNUM], tar_state[CELLNUM];
	cout << "请输入初始状态（空格用0表示）：  ";
	cin >> ini_state;
	cout << "请输入目标状态（空格用0表示）：  ";
	cin >> tar_state;
	Linklist List, List_last;  //last用来指向链表尾结点
	create_state_list( List, List_last, ini_state, tar_state );
	cout << "初始状态为：  " << endl;
	cout << setw( 5 ) << List->STATE.state[0] << List->STATE.state[1] << List->STATE.state[2] << endl;
	cout << setw( 5 ) << List->STATE.state[3] << List->STATE.state[4] << List->STATE.state[5] << endl;
	cout << setw( 5 ) << List->STATE.state[6] << List->STATE.state[7] << List->STATE.state[8] << endl;
	while( 1 )
	{
		if( working_select( List, List_last, tar_state ) == 0 )
			break;
	}
	printf_state( List );
	cout << "运行结束！" << endl;
	//释放空间
	//delete_list( List );
	system("pause");
}


/****************************************************************

   函数部分

****************************************************************/

void create_state_list( Linklist &L, Linklist &L_last, char* ini_state, char* tar_state )  //根结点的建立
{
	L = (Linklist)malloc( sizeof( _State_Node ) );
	L->parent = NULL;
	L->child = NULL;
	L->STATE.g = 0;
	int count_1, count_2, h = 0;
	for( count_1 = 0; count_1 < CELLNUM -1; count_1++ )   //计算耗散函数
		for( count_2 = 0; ; count_2++ )
			if( ini_state[count_1] == tar_state[count_2] )
			{
				h += cal_h[count_1][count_2];
				break;
			}
	L->STATE.f = h;
	for( count_1 = 0; count_1 < CELLNUM; count_1++ )
	{
		L->STATE.state[count_1] = ini_state[count_1];
		if( ini_state[count_1] == '0' )
			L->STATE.stat_of_zero = count_1;
	}
	L_last = L;
}

int working_select( Linklist &L, Linklist &L_last, char* tar_state ) //选择扩展的结点
{
	if( L->STATE.f != L->STATE.g )
		return extention_node( L, L_last, tar_state);  //extention_node函数返回值必为1
	else
		return 0;
}

int extention_node( Linklist &L, Linklist &L_last, char* tar_state)  //扩展结点
{
	
	//将已经扩展的结点放到链表末尾
	if( L->child != NULL )
	{
	    Linklist p = L;
	    L = L->child;
	    L_last->child = p;
	    L_last = p;
	    L_last->child = NULL;
	    L_last->STATE.f = MAXNUM;
	}
	else
		L->STATE.f = MAXNUM;
	switch( L_last->STATE.stat_of_zero )
	{
	    case 0:
			create_node( L, L_last, tar_state, 1 );
			create_node( L, L_last, tar_state, 3 );
			break;
		case 1:
			create_node( L, L_last, tar_state, -1 );
			create_node( L, L_last, tar_state, 1 );
			create_node( L, L_last, tar_state, 3 );
			break;
		case 2:
			create_node( L, L_last, tar_state, -1 );
			create_node( L, L_last, tar_state, 3 );

			break;
		case 3:
			create_node( L, L_last, tar_state, -3 );
			create_node( L, L_last, tar_state, 1 );
			create_node( L, L_last, tar_state, 3 );
			break;
		case 4:
			create_node( L, L_last, tar_state, -3 );
			create_node( L, L_last, tar_state, -1 );
			create_node( L, L_last, tar_state, 1 );
			create_node( L, L_last, tar_state, 3 );
			break;
		case 5:
			create_node( L, L_last, tar_state, -3 );
			create_node( L, L_last, tar_state, -1 );
			create_node( L, L_last, tar_state, 3 );
			break;
		case 6:
			create_node( L, L_last, tar_state, -3 );
			create_node( L, L_last, tar_state, 1 );
			break;
		case 7:
			create_node( L, L_last, tar_state, -3 );
			create_node( L, L_last, tar_state, -1 );
			create_node( L, L_last, tar_state, 1 );
			break;
		case 8:
			create_node( L, L_last, tar_state, -3 );
			create_node( L, L_last, tar_state, -1 );
			break;
		default:
			break;
	}
	return 1;
}

int create_node( Linklist &L, Linklist &L_last, char* tar_state, int mov )  //生成结点
{
	char ch; //用于临时存放编号
	int f = L_last->STATE.g + 1; //临时存放耗散函数的值
	int state_0;  //用来临时存放‘0’的格子编号
	Linklist p, q, r; //用来访问链表中的结点
	int count_1, count_2;
	//将last中的状态，即父结点的状态复制到数组中
	for( count_1 = 0; count_1 < CELLNUM; count_1++ )
		now_state[count_1] = L_last->STATE.state[count_1];
	//cout << now_state << endl;

	switch( mov )
	{
	    case 1:
			//完成移动
			ch = now_state[L_last->STATE.stat_of_zero];
			now_state[L_last->STATE.stat_of_zero] = now_state[L_last->STATE.stat_of_zero+1];
			now_state[L_last->STATE.stat_of_zero+1] = ch;

			state_0 = L_last->STATE.stat_of_zero+1;
			break;

		case -1:
			//完成移动
			ch = now_state[L_last->STATE.stat_of_zero];
			now_state[L_last->STATE.stat_of_zero] = now_state[L_last->STATE.stat_of_zero-1];
			now_state[L_last->STATE.stat_of_zero-1] = ch;

			state_0 = L_last->STATE.stat_of_zero-1;
			break;  //创建成功

		case 3:
			//完成移动
			ch = now_state[L_last->STATE.stat_of_zero];
			now_state[L_last->STATE.stat_of_zero] = now_state[L_last->STATE.stat_of_zero+3];
			now_state[L_last->STATE.stat_of_zero+3] = ch;

			state_0 = L_last->STATE.stat_of_zero+3;
			break;  //创建成功

		case -3:
			//完成移动
			ch = now_state[L_last->STATE.stat_of_zero];
			now_state[L_last->STATE.stat_of_zero] = now_state[L_last->STATE.stat_of_zero-3];
			now_state[L_last->STATE.stat_of_zero-3] = ch;

			state_0 = L_last->STATE.stat_of_zero-3;
			break;  //创建成功

		default:
			break;
	}

	        //计算f值
			for( count_1 = 0; count_1 < CELLNUM -1; count_1++ )   //计算耗散函数
	        	for( count_2 = 0; ; count_2++ )
			        if( now_state[count_1] == tar_state[count_2] )
			        {
				        f += cal_h[count_1][count_2];
				        break;
			        }


			p = r = L;
			q = NULL;
			while( r != L_last->child )
			{
				if( strcmp( r->STATE.state, now_state ) == 0 )
				{
					return 0;  //状态重复，没有生成该结点
				}
				r = r->child;
				//确定插入结点位置
				if( p->STATE.f <= f )
				{
					q = p;
				    p = p->child;
				}
			}

			//插入结点
			if( q != NULL )
			{
		    	r = (Linklist)malloc(sizeof( _State_Node ) );
			    q->child = r;
			    r->child = p;
			}
			else
			{
				r = (Linklist)malloc(sizeof( _State_Node ) );
				r->child = L;
				L = r;
			}

			//为结点赋值
			r->parent = L_last;
			r->STATE.f = f;
			r->STATE.g = L_last->STATE.g + 1;
			r->STATE.stat_of_zero = state_0;
			for( count_1 = 0; count_1 < CELLNUM; count_1++ )
		        r->STATE.state[count_1] = now_state[count_1];
			//cout << now_state << endl;
	return 1;
}

void printf_state( Linklist &L )
{
	Linklist p = L;
	int i = 0;
	while( p->parent != NULL )
	{
		for( int count = 0; count < CELLNUM; count ++ )
			table[i].STATE.state[count] = p->STATE.state[count];
		i++;
		p = p->parent;
	}
	for( --i; i >= 0; i-- )
	{
		cout << "第" << ++count_of_state << "步：  " << endl;
		cout << setw( 5 ) << table[i].STATE.state[0] << table[i].STATE.state[1] << table[i].STATE.state[2] << endl;
		cout << setw( 5 ) << table[i].STATE.state[3] << table[i].STATE.state[4] << table[i].STATE.state[5] << endl;
		cout << setw( 5 ) << table[i].STATE.state[6] << table[i].STATE.state[7] << table[i].STATE.state[8] << endl;
	}
}

void delete_list( Linklist &L )
{
	Linklist p = L;
	while( L != NULL )
	{
		L = L->child;
		free(p);
		p = L;
	}
}