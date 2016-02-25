#include <iostream>
#include <iomanip>
using namespace std;

#define NUM_CHECK 9                       //棋盘格子数+1
#define MAXNUM_CHILD 9                     //子节点数目的上限
#define MAX 20                             //极大值
#define MIN -20                            //极小值

typedef struct Node{
	int num_blank;                  //空格数量
	int p;                        //评价函数
	char state_check[NUM_CHECK];		 //棋盘中各个空格的状态
	Node* child[MAXNUM_CHILD];         //每个节点的子节点指针
}*Tic_Tac_Toe;

/*****************************************************************************
                          函数声明
*****************************************************************************/

int value_p( Tic_Tac_Toe &check );                      //评价函数
void initial_check( Tic_Tac_Toe &check );                 //初始化搜索树
void print_check( Tic_Tac_Toe &check );                   //打印棋局
int Computer( Tic_Tac_Toe &check );                      //电脑落子（减值算法的实现）
int Choose_max( Tic_Tac_Toe &check );                    //选择子节点中p最大的
int Choose_min( Tic_Tac_Toe &check );                    //选择子节点中p最小的
void Delete_node( Tic_Tac_Toe &check );                   //释放空间
void Create_node( Tic_Tac_Toe &check, int place, char x );   //增加节点
int Player( Tic_Tac_Toe &check );                        //玩家落子
 
 
/*****************************************************************************
                          主函数部分
*****************************************************************************/
 
void main()
{
	Tic_Tac_Toe CHECK;
	initial_check( CHECK );
	cout << "本游戏只能由电脑先行！" << endl;
	cout << "初始棋盘如下：" << endl;
	print_check( CHECK );
	while( 1 )
	{
		cout << "电脑走：" << endl;
		int ret = Computer( CHECK );
		if( ret == 1 || ret == 0 )
			break;
		else if( Player( CHECK ) == -1 )
			break;
	}
	system("pause");
}
 
/*****************************************************************************
                          函数部分
*****************************************************************************/

int value_p( Tic_Tac_Toe &check )
{
	bool ISMAX, ISMIN;
	int Count_MAX = 0, Count_MIN = 0;
	int count_max, count_min;  //用来计算同一行、列、斜线上是否有3个相同标志
	//计算MAX行value和MIN行value
	for( int i = 0; i < 3; i++ )
	{
		ISMAX = true;
		ISMIN = true;         //这两个bool变量用来显示这行、列、斜线是否为MAX或MINvalue
		count_max = 0;
		count_min = 0;
		for( int j = 0; j < 3; j++ )
		{
			if( check->state_check[i*3+j] == 'b' )
			{
				count_min++;
				ISMAX = false;
			}
			else if( check->state_check[i*3+j] == 'a' )
			{
				count_max++;
				ISMIN = false;
			}
		}
		if( count_max == 3 )  //电脑赢
			return MAX;
		else if( count_min == 3 )   //玩家赢
			return MIN;
		if( ISMAX == true )
			Count_MAX++;
		if( ISMIN == true )
			Count_MIN++;
	}
	//计算MAX列value和MIN列value
	for( int i = 0; i < 3; i++ )
	{
		ISMAX = true;
		ISMIN = true;         //这两个bool变量用来显示这行、列、斜线是否为MAX或MINvalue
		count_max = 0;
	    count_min = 0;
		for( int j = 0; j < 3; j++ )
		{
			if( check->state_check[j*3+i] == 'b' )
			{
				count_min++;
				ISMAX = false;
			}
			else if( check->state_check[j*3+i] == 'a' )
			{
				count_max++;
				ISMIN = false;
			}
		}
		if( count_max == 3 )  //电脑赢
			return MAX;
		else if( count_min == 3 )   //玩家赢
			return MIN;
		if( ISMAX == true )
			Count_MAX++;
		if( ISMIN == true )
			Count_MIN++;
	}
	//计算MAX斜线value和MIN斜线value
	ISMAX = true;
	ISMIN = true;
	count_max = 0;
	count_min = 0;
	for( int i = 0; i < 3; i++ )
	{
		if( check->state_check[3*i+i] == 'b' )
		{
			count_min++;
			ISMAX = false;
		}
		else if( check->state_check[3*i+i] == 'a' )
		{
			count_max++;
			ISMIN = false;
		}
	}
	if( count_max == 3 )  //电脑赢
		return MAX;
	else if( count_min == 3 )   //玩家赢
		return MIN;
	if( ISMAX == true )
		Count_MAX++;
	if( ISMIN == true )
		Count_MIN++;
	 
	ISMAX = true;
	ISMIN = true;
	count_max = 0;
	count_min = 0;
	for( int i = 1; i <= 3; i++ )
	{
		if( check->state_check[3*i-i] == 'b' )
		{
			count_min++;
			ISMAX = false;
		}		
		else if( check->state_check[3*i-i] == 'a' )
		{
			count_max++;
			ISMIN = false;
		}
	}
	if( count_max == 3 )  //电脑赢
		return MAX;
	else if( count_min == 3 )   //玩家赢
		return MIN;
	if( ISMAX == true )
		Count_MAX++;
	if( ISMIN == true )
		Count_MIN++;
	return ( Count_MAX - Count_MIN );
}

void initial_check( Tic_Tac_Toe &check )
{
	check = (Tic_Tac_Toe)malloc( sizeof(Node) );
	check->num_blank = MAXNUM_CHILD;
	check->p = 0;
	for( int i = 0; i < MAXNUM_CHILD; i++ )
	{
		check->state_check[i] = '_';
		check->child[i] = NULL;
	}
}

void print_check( Tic_Tac_Toe &check )
{
	for( int i = 0; i < 3; i++ )
		cout << setw(2) << check->state_check[i*3+0] << setw(2) << check->state_check[i*3+1] << setw(2) << check->state_check[i*3+2] << endl;
	cout << endl;
}

int Computer( Tic_Tac_Toe &check )
{
	int max = MIN;
	for( int i = 0; i < MAXNUM_CHILD; i++ )
	{
		if( check->state_check[i] == '_' )          //电脑落子（MAX）
		{
			Create_node( check, i, 'a' );
			if( check->child[i]->p == MAX )
			{
				print_check( check->child[i] );
				cout << "电脑获胜！" << endl;
				Delete_node( check );
				return 1;
			}
			else if( check->child[i]->num_blank == 0 )
			{
				print_check( check->child[i] );
				cout << "平局！" << endl;
				Delete_node( check );
				return 0;
			}
			for( int j = 0; j < MAXNUM_CHILD; j++ )    //玩家可能落子（MIN）
			{
				if( check->child[i]->state_check[j] == '_' )
				{
					Create_node( check->child[i], j, 'b' );
					if( check->child[i]->child[j]->p < max )
						break;
				}
			}
			check->child[i]->p = Choose_min( check->child[i] );
	    	if( check->child[i]->p > max )
		    	max = check->child[i]->p;
		}
	}
	int k = Choose_max(check);
	print_check( check->child[k] );
	Tic_Tac_Toe p = check, q = (Tic_Tac_Toe)malloc( sizeof( Node ));
	//建立新的初始状态
	for( int t = 0; t < MAXNUM_CHILD; t++ )
	{
		q->state_check[t] = check->child[k]->state_check[t];
		q->child[t] = NULL;
	}
	q->num_blank = check->child[k]->num_blank;
	q->p = check->child[k]->p;
	check = q;
	Delete_node( p );
	return 2;
}

int Choose_max( Tic_Tac_Toe &check )
{
	int value[MAXNUM_CHILD];
	for( int i = 0; i < MAXNUM_CHILD; i++ )
	{
		if( check->child[i] == NULL )
			value[i] = MIN;
		else
			value[i] = check->child[i]->p;
	}
	int k = 0;
	for( int i = 1; i < MAXNUM_CHILD; i++ )
	{
		if( value[k] < value[i] )
			k = i;
	}
	return k;
}

int Choose_min( Tic_Tac_Toe &check )
{
	int value[MAXNUM_CHILD];
	for( int i = 0; i < MAXNUM_CHILD; i++ )
	{
		if( check->child[i] == NULL )
			value[i] = MAX;
		else
			value[i] = check->child[i]->p;
	}
	int k = 0;
	for( int i = 1; i < MAXNUM_CHILD; i++ )
	{
		if( value[k] > value[i] )
			k = i;
	}
	return value[k];
}

void Delete_node( Tic_Tac_Toe &check )
{
	Tic_Tac_Toe p = check;
	int i = 0;
	while( p->child[i] )
	{
		Delete_node( p->child[i] );
		i++;
		if( i == MAXNUM_CHILD )
			break;
	}
	free(p);
}

void Create_node( Tic_Tac_Toe &check, int place, char x )
{
	Tic_Tac_Toe child = (Tic_Tac_Toe)malloc( sizeof(Node) );
	for( int i = 0; i < MAXNUM_CHILD; i++ )
	{
		child->state_check[i] = check->state_check[i];
		child->child[i] = NULL;
	}
	check->child[place] = child;
	child->num_blank = check->num_blank - 1;
	child->state_check[place] = x;
	child->p = value_p( child );
}

int Player( Tic_Tac_Toe &check )
{
	int place;
	while( 1 )
	{
		cout << "请玩家输入要落子的位置（用0~8表示）：";
	    cin >> place;
	    if( check->state_check[place] == '_' )
		{
		    check->state_check[place] = 'b';
			break;
		}
	    else
		    cout << "该格子不能落子，请换个格子！" << endl; 
	}
	print_check( check );
	if( value_p( check ) == MIN )
	{
		cout << "玩家获胜！" << endl;
		Delete_node( check );
		return -1;
	}
	else
	{
		check->num_blank--;
		check->p = value_p( check );
		for( int i = 0; i < MAXNUM_CHILD; i++ )
			check->child[i] = NULL;
	}
	return 2;
}

