#include <iostream>
#include <iomanip>
using namespace std;

#define NUM_CHECK 9                       //���̸�����+1
#define MAXNUM_CHILD 9                     //�ӽڵ���Ŀ������
#define MAX 20                             //����ֵ
#define MIN -20                            //��Сֵ

typedef struct Node{
	int num_blank;                  //�ո�����
	int p;                        //���ۺ���
	char state_check[NUM_CHECK];		 //�����и����ո��״̬
	Node* child[MAXNUM_CHILD];         //ÿ���ڵ���ӽڵ�ָ��
}*Tic_Tac_Toe;

/*****************************************************************************
                          ��������
*****************************************************************************/

int value_p( Tic_Tac_Toe &check );                      //���ۺ���
void initial_check( Tic_Tac_Toe &check );                 //��ʼ��������
void print_check( Tic_Tac_Toe &check );                   //��ӡ���
int Computer( Tic_Tac_Toe &check );                      //�������ӣ���ֵ�㷨��ʵ�֣�
int Choose_max( Tic_Tac_Toe &check );                    //ѡ���ӽڵ���p����
int Choose_min( Tic_Tac_Toe &check );                    //ѡ���ӽڵ���p��С��
void Delete_node( Tic_Tac_Toe &check );                   //�ͷſռ�
void Create_node( Tic_Tac_Toe &check, int place, char x );   //���ӽڵ�
int Player( Tic_Tac_Toe &check );                        //�������
 
 
/*****************************************************************************
                          ����������
*****************************************************************************/
 
void main()
{
	Tic_Tac_Toe CHECK;
	initial_check( CHECK );
	cout << "����Ϸֻ���ɵ������У�" << endl;
	cout << "��ʼ�������£�" << endl;
	print_check( CHECK );
	while( 1 )
	{
		cout << "�����ߣ�" << endl;
		int ret = Computer( CHECK );
		if( ret == 1 || ret == 0 )
			break;
		else if( Player( CHECK ) == -1 )
			break;
	}
	system("pause");
}
 
/*****************************************************************************
                          ��������
*****************************************************************************/

int value_p( Tic_Tac_Toe &check )
{
	bool ISMAX, ISMIN;
	int Count_MAX = 0, Count_MIN = 0;
	int count_max, count_min;  //��������ͬһ�С��С�б�����Ƿ���3����ͬ��־
	//����MAX��value��MIN��value
	for( int i = 0; i < 3; i++ )
	{
		ISMAX = true;
		ISMIN = true;         //������bool����������ʾ���С��С�б���Ƿ�ΪMAX��MINvalue
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
		if( count_max == 3 )  //����Ӯ
			return MAX;
		else if( count_min == 3 )   //���Ӯ
			return MIN;
		if( ISMAX == true )
			Count_MAX++;
		if( ISMIN == true )
			Count_MIN++;
	}
	//����MAX��value��MIN��value
	for( int i = 0; i < 3; i++ )
	{
		ISMAX = true;
		ISMIN = true;         //������bool����������ʾ���С��С�б���Ƿ�ΪMAX��MINvalue
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
		if( count_max == 3 )  //����Ӯ
			return MAX;
		else if( count_min == 3 )   //���Ӯ
			return MIN;
		if( ISMAX == true )
			Count_MAX++;
		if( ISMIN == true )
			Count_MIN++;
	}
	//����MAXб��value��MINб��value
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
	if( count_max == 3 )  //����Ӯ
		return MAX;
	else if( count_min == 3 )   //���Ӯ
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
	if( count_max == 3 )  //����Ӯ
		return MAX;
	else if( count_min == 3 )   //���Ӯ
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
		if( check->state_check[i] == '_' )          //�������ӣ�MAX��
		{
			Create_node( check, i, 'a' );
			if( check->child[i]->p == MAX )
			{
				print_check( check->child[i] );
				cout << "���Ի�ʤ��" << endl;
				Delete_node( check );
				return 1;
			}
			else if( check->child[i]->num_blank == 0 )
			{
				print_check( check->child[i] );
				cout << "ƽ�֣�" << endl;
				Delete_node( check );
				return 0;
			}
			for( int j = 0; j < MAXNUM_CHILD; j++ )    //��ҿ������ӣ�MIN��
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
	//�����µĳ�ʼ״̬
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
		cout << "���������Ҫ���ӵ�λ�ã���0~8��ʾ����";
	    cin >> place;
	    if( check->state_check[place] == '_' )
		{
		    check->state_check[place] = 'b';
			break;
		}
	    else
		    cout << "�ø��Ӳ������ӣ��뻻�����ӣ�" << endl; 
	}
	print_check( check );
	if( value_p( check ) == MIN )
	{
		cout << "��һ�ʤ��" << endl;
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

