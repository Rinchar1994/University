#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

#define MAX 12
#define OPENNUM 50000  //open表容量
#define CLOSENUM 5000  //close表容量
#define MAXNUM 32200 //一个极大值

typedef struct _Node {      //结点定义
	int parent;
	char position[MAX];
	int f;  //耗散，f(n) = g( n ) + h( n )
	int g; //即树的深度
}_State;

typedef struct Node {
	char position[MAX];
}Drop_state;

_State OPEN[OPENNUM];
Drop_state CLOSE[CLOSENUM];
int NUM_OF_STEP = 1;

/* -----------------------------------------------------------------------
  函数声明
  ------------------------------------------------------------------------*/

void initial_open( int num_of_disk );   //为open表初始化
void initial_close();  //为close表初始化
int select_emptyopen();               //寻找空的OPEN表结点存放扩展结点
int select_emptyclose();               //寻找空的CLOSE表结点存放扩展结点
int match_plan( char ch_1, char ch_2 );   //为6种转换方式ch_1 -> ch_2返回不同的值作为操作号
void reset_tree( int child_num ); //以该节点为起始节点
int create_node( int child_num , int parent_num, int plan, int change_num, int num_of_disk );   // 扩展结点,包含了f( n ) 的计算，chang_num表示移动的盘子编号
int extention_node( int parent_num, int num_of_disk );  //参数为父节点在open表中的序号，从0开始,并将扩展过的点存入close表中
int select_node( int num_of_disk );  //选择最佳节点

/* ------------------------------------------------------------------------
  主函数
  -------------------------------------------------------------------------*/

void main()
{
	int num_of_disk;
	cout << "柱子名字分别为A,B,C！" << endl;
	cout << "下面请输入盘子的数量num_of_disk = ";
	cin >> num_of_disk;
	cout << endl;
	initial_open( num_of_disk );
	initial_close();
	cout << "初始状态为：  " << OPEN[0].position << endl;
	while( 1 )
	{
		if( select_node( num_of_disk ) == 1 )
			break;
	}
	cout << "运行结束" << endl;
	system("pause");
}

/* ------------------------------------------------------------------------
   函数
   ------------------------------------------------------------------------*/

void initial_open( int num_of_disk )   //为open表初始化
{
	OPEN[0].parent = -2;  //根节点的父节点
	OPEN[0].f = int(pow( 2.0, num_of_disk )) - 1;
	OPEN[0].g = 0;
	for( int i = 0; i < MAX; i++)   //为根节点设置状态，即初始状态
	{
		if( i < num_of_disk )
		    OPEN[0].position[i] = 'A';
		else
			OPEN[0].position[i] = 0;
	}
	int count = 1;
	for( ; count < OPENNUM; count++ )
	{
		OPEN[count].parent = -1;  //parent=-1表示该结点为空
		OPEN[count].f = -1;
		OPEN[count].g = -1;
		for( int i = 0; i < MAX; i++ )
			OPEN[count].position[i] = 0;
	}
}

void initial_close()  //为close表初始化
{
	for( int count = 0; count < CLOSENUM; count++ )
	{
		for( int i = 0; i < MAX; i++ )
		    CLOSE[count].position[i] = 0;
	}
}

int select_emptyopen()               //寻找空的OPEN表结点存放扩展结点
{
	for( int i = 0; i < OPENNUM; i++ )
	{
		if( OPEN[i].parent == -1 )
			return i;
	}
	return -1;
}

int select_emptyclose()               //寻找空的CLOSE表结点存放扩展结点
{
	for( int i = 0; i < CLOSENUM; i++ )
	{
		if( CLOSE[i].position[0] != 0 )
			return i;
	}
	return -1;
}

int match_plan( char ch_1, char ch_2 )   //为6种转换方式ch_1 -> ch_2返回不同的值作为操作号
{
	if( ch_1 == 'A' && ch_2 == 'B' )
		return 1;
	else if( ch_1 == 'A' && ch_2 == 'C' )
		return 2;
	else if( ch_1 == 'B' && ch_2 == 'A' )
		return 3;
	else if( ch_1 == 'B' && ch_2 == 'C' )
		return 4;
	else if( ch_1 == 'C' && ch_2 == 'A' )
		return 5;
	else if( ch_1 == 'C' && ch_2 == 'B' )
		return 6;
	else
		return 0;
}

void reset_tree( int child_num ) //以该节点为起始节点
{
	initial_close();
	OPEN[0].parent = -2;  //根节点的父节点
	OPEN[0].f = OPEN[child_num].f - OPEN[child_num].g;;
	OPEN[0].g = 0;
	for( int i = 0; i < MAX; i++)   //为根节点设置状态，即初始状态
		OPEN[0].position[i] = OPEN[child_num].position[i];
	int count = 1;
	for( ; count < OPENNUM; count++ )
	{
		OPEN[count].parent = -1;  //parent=-1表示该结点为空
		OPEN[count].f = -1;
		OPEN[count].g = -1;
		for( int i = 0; i < MAX; i++ )
			OPEN[count].position[i] = 0;
	}
}

int create_node( int child_num , int parent_num, int plan, int change_num, int num_of_disk )   // 扩展结点,包含了f( n ) 的计算，chang_num表示移动的盘子编号
{
	int i;
	for( i = 0; i < MAX ; i++ )   //将父节点的状态复制到子节点,在change_num处发生变换
	{
		if( i == change_num )
		{
			switch( plan )
			{
			    case 1:
					OPEN[child_num].position[i] = OPEN[parent_num].position[i] + 1;
					break;
				case 2:
					OPEN[child_num].position[i] = OPEN[parent_num].position[i] + 2;
					break;
				case 3:
					OPEN[child_num].position[i] = OPEN[parent_num].position[i] - 1;
					break;
				case 4:
					OPEN[child_num].position[i] = OPEN[parent_num].position[i] + 1;
					break;
				case 5:
					OPEN[child_num].position[i] = OPEN[parent_num].position[i] - 2;
					break;
				case 6:
					OPEN[child_num].position[i] = OPEN[parent_num].position[i] - 1;
				default:
					break;
			}
		}
		else
		    OPEN[child_num].position[i] = OPEN[parent_num].position[i];
	}
	for( int t = 0; t < OPENNUM; t++ )   //若已存在该状态，则删除该结点
	{
		if( strcmp( OPEN[t].position , OPEN[child_num].position ) == 0 && t != child_num )
		{
			for( int k = 0; k < MAX; k++ )
				OPEN[child_num].position[k] = 0;
			return -1;
		}
	}
	int count[4] = { 0, 0, 0, 0 };  //用于存放A、B柱子中的盘子数和之后仍会取出的C盘子数,放入C柱子之后不会取出的盘子
	int cnt[4] = { 0, 0, 0, 0 };
	for( --i; i >= 0; i-- )        //判定是否删枝
	{
		if( OPEN[child_num].position[i] == 'A' )
			count[0]++;
		else if( OPEN[child_num].position[i] == 'B' )
			count[1]++;
		else if( OPEN[child_num].position[i] == 'C' && ( count[0] != 0 || count[1] != 0 ) )
			count[2]++;
		else
			count[3]++;
		if( OPEN[parent_num].position[i] == 'A' )
			cnt[0]++;
		else if( OPEN[parent_num].position[i] == 'B' )
			cnt[1]++;
		else if( OPEN[parent_num].position[i] == 'C' && ( count[0] != 0 || count[1] != 0 ) )
			cnt[2]++;
		else
			cnt[3]++;
	}
	/*-------------------------test--------------------------
	 *  设置前驱并计算F
	 *------------------------------------------------------*/
	 OPEN[child_num].parent = parent_num;
	 //OPEN[child_num].g = int(pow(2.0,count[3]));
	 OPEN[child_num].g = OPEN[parent_num].g + 1;
	 OPEN[child_num].f = OPEN[child_num].g + int( pow( 2.0, count[0] ) ) - 1;

	if( count[3] > cnt[3] )
	{
		int child_num_1 = child_num, close_num = 0;//close_num用来存储close表中的节点数
		while( child_num_1 != 0 )    //将截断节点至根节点之间的节点（包含截断节点，不包含根节点）复制到close表中
		{
			for( int counter = 0; counter < MAX ; counter++ )
			{
				CLOSE[close_num].position[counter] = OPEN[child_num_1].position[counter];
			}
			close_num++;
			child_num_1 = OPEN[child_num_1].parent;
		}
		for( --close_num; close_num >= 0; close_num-- )     //将截断之前的路径打印出来
			cout << NUM_OF_STEP++ << ": 此时状态为：   " << CLOSE[close_num].position << endl;
		reset_tree( child_num );
	}
	return 0;
}

int extention_node( int parent_num, int num_of_disk )  //参数为父节点在open表中的序号，从0开始,并将扩展过的点存入close表中
{
	if( parent_num == 0)  //根节点中前面可以移动的盘子数为奇数则第一步移动编号最小的盘子至C柱子，反之则移到另一个空柱子
	{
		int count_c[4] = { 0, 0, 0, 0 };
		for( int count_i = num_of_disk - 1; count_i >= 0; count_i-- )
		{
			if( OPEN[parent_num].position[count_i] == 'A' )
			    count_c[0]++;
		    else if( OPEN[parent_num].position[count_i] == 'B' )
		    	count_c[1]++;
		    else if( OPEN[parent_num].position[count_i] == 'C' && ( count_c[0] != 0 || count_c[1] != 0 ) )
		    	count_c[2]++;
		    else
			    count_c[3]++;
		}
		if( count_c[3] == num_of_disk )
	    	return 1;   //已达到目的
		int plan, child_num;
		if( ( num_of_disk - count_c[3] ) % 2 == 1 )
		{
			plan = match_plan( OPEN[parent_num].position[0], 'C' );
		    if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		        child_num = select_emptyopen();
	        else
	    	    cout << "OPEN表已满" << endl;
		    create_node( child_num, parent_num, plan, 0, num_of_disk );
		}
		else
		{
			char ch;
			plan = match_plan( OPEN[parent_num].position[0], 'C' );  //为求得第一个盘子放在A.B哪个柱子中
			switch( plan )
			{
			    case 2:
					ch = 'B';
					break;
				case 4:
					ch = 'A';
					break;
				default:
					break;
			}
			plan = match_plan( OPEN[parent_num].position[0], ch );
		    if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		        child_num = select_emptyopen();
	        else
	    	    cout << "OPEN表已满" << endl;
		    create_node( child_num, parent_num, plan, 0, num_of_disk );
		}
	}
	else  //其余节点的扩展扩展
	{int j = 1, i;
	int count[4] = { 0, 0, 0, 0 };
	for( i = num_of_disk - 1; i >= 0; i-- )
	{
		if( OPEN[parent_num].position[i] == 'A' )
			count[0]++;
		else if( OPEN[parent_num].position[i] == 'B' )
			count[1]++;
		else if( OPEN[parent_num].position[i] == 'C' && ( count[0] != 0 || count[1] != 0 ) )
			count[2]++;
		else
			count[3]++;
	}
	int no[3] = { 0, 0, 0 };    //存放各个柱子顶端放着的盘子的序号
	char ch[3] = { 0 };
	ch[0] = OPEN[parent_num].position[0];
	for( i = 0 ; i < num_of_disk - count[3] -1; i++ ) //取出不固定的各柱子顶端盘子
	{
		if( OPEN[parent_num].position[i] != OPEN[parent_num].position[i+1] )
		{
			for( int num_no = 0; num_no < j; num_no++ )
			{
				if( OPEN[parent_num].position[i+1] == ch[num_no] )
				{
					j--;
					break;
				}
			}
			if( no[j] == 0 ) 
			{
				ch[j] = OPEN[parent_num].position[i+1];
			    no[j++] = i + 1;
			}
			else
				j++;
		}
		if( j == 3 )
			break;
	}
	int child_num, plan;
	if( j == 3 )   //3根柱子上都有不固定的盘子的时候
	{
		plan = match_plan( OPEN[parent_num].position[no[0]], OPEN[parent_num].position[no[1]] );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[0]], OPEN[parent_num].position[no[2]] );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[1]], OPEN[parent_num].position[no[2]] );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[1], num_of_disk );
	}
	else if( j == 2 )
	{
		char ch;  // 用于临时存放柱子编号
		plan = match_plan( OPEN[parent_num].position[no[0]], OPEN[parent_num].position[no[1]] );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		switch( plan )
		{
		    case 1:
				ch = 'C';
				break;
			case 2:
				ch = 'B';
				break;
			case 3:
				ch = 'C';
				break;
			case 4:
				ch = 'A';
				break;
			case 5:
				ch = 'B';
				break;
			case 6:
				ch = 'A';
				break;
			default:
				break;
		}
		plan = match_plan( OPEN[parent_num].position[no[0]], ch );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[1]], ch );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[1], num_of_disk );
	}
	else
	{
		char ch_1, ch_2;
		switch( OPEN[parent_num].position[no[0]] )
		{
		    case 'A':
				ch_1 = 'B';
				ch_2 = 'C';
				break;
			case 'B':
				ch_1 = 'A';
				ch_2 = 'C';
				break;
			case 'C':
				ch_1 = 'A';
				ch_2 = 'B';
				break;
			default:
				break;
		}
		plan = match_plan( OPEN[parent_num].position[no[0]], ch_1 );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[0]], ch_2 );
		if( select_emptyopen() != -1 )    //若返回不为1，则存在空结点
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN表已满" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
	}
	}
	OPEN[parent_num].f = MAXNUM;  //标记已经扩展的节点
	return 0;
}

int select_node( int num_of_disk )  //选择最佳节点
{
	int i = 0, fn = OPEN[0].f, num = 0;
	while( 1 )
	{
		i++;
		if( OPEN[i].f < fn && OPEN[i].f > 0 )
		{
			fn = OPEN[i].f;
			num = i;
		}
		if( OPEN[i].f == -1 )
			break;
	}
	return extention_node( num, num_of_disk );
}