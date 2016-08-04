#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

#define MAX 12
#define OPENNUM 50000  //open������
#define CLOSENUM 5000  //close������
#define MAXNUM 32200 //һ������ֵ

typedef struct _Node {      //��㶨��
	int parent;
	char position[MAX];
	int f;  //��ɢ��f(n) = g( n ) + h( n )
	int g; //���������
}_State;

typedef struct Node {
	char position[MAX];
}Drop_state;

_State OPEN[OPENNUM];
Drop_state CLOSE[CLOSENUM];
int NUM_OF_STEP = 1;

/* -----------------------------------------------------------------------
  ��������
  ------------------------------------------------------------------------*/

void initial_open( int num_of_disk );   //Ϊopen���ʼ��
void initial_close();  //Ϊclose���ʼ��
int select_emptyopen();               //Ѱ�ҿյ�OPEN��������չ���
int select_emptyclose();               //Ѱ�ҿյ�CLOSE��������չ���
int match_plan( char ch_1, char ch_2 );   //Ϊ6��ת����ʽch_1 -> ch_2���ز�ͬ��ֵ��Ϊ������
void reset_tree( int child_num ); //�Ըýڵ�Ϊ��ʼ�ڵ�
int create_node( int child_num , int parent_num, int plan, int change_num, int num_of_disk );   // ��չ���,������f( n ) �ļ��㣬chang_num��ʾ�ƶ������ӱ��
int extention_node( int parent_num, int num_of_disk );  //����Ϊ���ڵ���open���е���ţ���0��ʼ,������չ���ĵ����close����
int select_node( int num_of_disk );  //ѡ����ѽڵ�

/* ------------------------------------------------------------------------
  ������
  -------------------------------------------------------------------------*/

void main()
{
	int num_of_disk;
	cout << "�������ֱַ�ΪA,B,C��" << endl;
	cout << "�������������ӵ�����num_of_disk = ";
	cin >> num_of_disk;
	cout << endl;
	initial_open( num_of_disk );
	initial_close();
	cout << "��ʼ״̬Ϊ��  " << OPEN[0].position << endl;
	while( 1 )
	{
		if( select_node( num_of_disk ) == 1 )
			break;
	}
	cout << "���н���" << endl;
	system("pause");
}

/* ------------------------------------------------------------------------
   ����
   ------------------------------------------------------------------------*/

void initial_open( int num_of_disk )   //Ϊopen���ʼ��
{
	OPEN[0].parent = -2;  //���ڵ�ĸ��ڵ�
	OPEN[0].f = int(pow( 2.0, num_of_disk )) - 1;
	OPEN[0].g = 0;
	for( int i = 0; i < MAX; i++)   //Ϊ���ڵ�����״̬������ʼ״̬
	{
		if( i < num_of_disk )
		    OPEN[0].position[i] = 'A';
		else
			OPEN[0].position[i] = 0;
	}
	int count = 1;
	for( ; count < OPENNUM; count++ )
	{
		OPEN[count].parent = -1;  //parent=-1��ʾ�ý��Ϊ��
		OPEN[count].f = -1;
		OPEN[count].g = -1;
		for( int i = 0; i < MAX; i++ )
			OPEN[count].position[i] = 0;
	}
}

void initial_close()  //Ϊclose���ʼ��
{
	for( int count = 0; count < CLOSENUM; count++ )
	{
		for( int i = 0; i < MAX; i++ )
		    CLOSE[count].position[i] = 0;
	}
}

int select_emptyopen()               //Ѱ�ҿյ�OPEN��������չ���
{
	for( int i = 0; i < OPENNUM; i++ )
	{
		if( OPEN[i].parent == -1 )
			return i;
	}
	return -1;
}

int select_emptyclose()               //Ѱ�ҿյ�CLOSE��������չ���
{
	for( int i = 0; i < CLOSENUM; i++ )
	{
		if( CLOSE[i].position[0] != 0 )
			return i;
	}
	return -1;
}

int match_plan( char ch_1, char ch_2 )   //Ϊ6��ת����ʽch_1 -> ch_2���ز�ͬ��ֵ��Ϊ������
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

void reset_tree( int child_num ) //�Ըýڵ�Ϊ��ʼ�ڵ�
{
	initial_close();
	OPEN[0].parent = -2;  //���ڵ�ĸ��ڵ�
	OPEN[0].f = OPEN[child_num].f - OPEN[child_num].g;;
	OPEN[0].g = 0;
	for( int i = 0; i < MAX; i++)   //Ϊ���ڵ�����״̬������ʼ״̬
		OPEN[0].position[i] = OPEN[child_num].position[i];
	int count = 1;
	for( ; count < OPENNUM; count++ )
	{
		OPEN[count].parent = -1;  //parent=-1��ʾ�ý��Ϊ��
		OPEN[count].f = -1;
		OPEN[count].g = -1;
		for( int i = 0; i < MAX; i++ )
			OPEN[count].position[i] = 0;
	}
}

int create_node( int child_num , int parent_num, int plan, int change_num, int num_of_disk )   // ��չ���,������f( n ) �ļ��㣬chang_num��ʾ�ƶ������ӱ��
{
	int i;
	for( i = 0; i < MAX ; i++ )   //�����ڵ��״̬���Ƶ��ӽڵ�,��change_num�������任
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
	for( int t = 0; t < OPENNUM; t++ )   //���Ѵ��ڸ�״̬����ɾ���ý��
	{
		if( strcmp( OPEN[t].position , OPEN[child_num].position ) == 0 && t != child_num )
		{
			for( int k = 0; k < MAX; k++ )
				OPEN[child_num].position[k] = 0;
			return -1;
		}
	}
	int count[4] = { 0, 0, 0, 0 };  //���ڴ��A��B�����е���������֮���Ի�ȡ����C������,����C����֮�󲻻�ȡ��������
	int cnt[4] = { 0, 0, 0, 0 };
	for( --i; i >= 0; i-- )        //�ж��Ƿ�ɾ֦
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
	 *  ����ǰ��������F
	 *------------------------------------------------------*/
	 OPEN[child_num].parent = parent_num;
	 //OPEN[child_num].g = int(pow(2.0,count[3]));
	 OPEN[child_num].g = OPEN[parent_num].g + 1;
	 OPEN[child_num].f = OPEN[child_num].g + int( pow( 2.0, count[0] ) ) - 1;

	if( count[3] > cnt[3] )
	{
		int child_num_1 = child_num, close_num = 0;//close_num�����洢close���еĽڵ���
		while( child_num_1 != 0 )    //���ضϽڵ������ڵ�֮��Ľڵ㣨�����ضϽڵ㣬���������ڵ㣩���Ƶ�close����
		{
			for( int counter = 0; counter < MAX ; counter++ )
			{
				CLOSE[close_num].position[counter] = OPEN[child_num_1].position[counter];
			}
			close_num++;
			child_num_1 = OPEN[child_num_1].parent;
		}
		for( --close_num; close_num >= 0; close_num-- )     //���ض�֮ǰ��·����ӡ����
			cout << NUM_OF_STEP++ << ": ��ʱ״̬Ϊ��   " << CLOSE[close_num].position << endl;
		reset_tree( child_num );
	}
	return 0;
}

int extention_node( int parent_num, int num_of_disk )  //����Ϊ���ڵ���open���е���ţ���0��ʼ,������չ���ĵ����close����
{
	if( parent_num == 0)  //���ڵ���ǰ������ƶ���������Ϊ�������һ���ƶ������С��������C���ӣ���֮���Ƶ���һ��������
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
	    	return 1;   //�ѴﵽĿ��
		int plan, child_num;
		if( ( num_of_disk - count_c[3] ) % 2 == 1 )
		{
			plan = match_plan( OPEN[parent_num].position[0], 'C' );
		    if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		        child_num = select_emptyopen();
	        else
	    	    cout << "OPEN������" << endl;
		    create_node( child_num, parent_num, plan, 0, num_of_disk );
		}
		else
		{
			char ch;
			plan = match_plan( OPEN[parent_num].position[0], 'C' );  //Ϊ��õ�һ�����ӷ���A.B�ĸ�������
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
		    if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		        child_num = select_emptyopen();
	        else
	    	    cout << "OPEN������" << endl;
		    create_node( child_num, parent_num, plan, 0, num_of_disk );
		}
	}
	else  //����ڵ����չ��չ
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
	int no[3] = { 0, 0, 0 };    //��Ÿ������Ӷ��˷��ŵ����ӵ����
	char ch[3] = { 0 };
	ch[0] = OPEN[parent_num].position[0];
	for( i = 0 ; i < num_of_disk - count[3] -1; i++ ) //ȡ�����̶��ĸ����Ӷ�������
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
	if( j == 3 )   //3�������϶��в��̶������ӵ�ʱ��
	{
		plan = match_plan( OPEN[parent_num].position[no[0]], OPEN[parent_num].position[no[1]] );
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[0]], OPEN[parent_num].position[no[2]] );
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[1]], OPEN[parent_num].position[no[2]] );
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
		create_node( child_num, parent_num, plan, no[1], num_of_disk );
	}
	else if( j == 2 )
	{
		char ch;  // ������ʱ������ӱ��
		plan = match_plan( OPEN[parent_num].position[no[0]], OPEN[parent_num].position[no[1]] );
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
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
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[1]], ch );
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
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
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
		plan = match_plan( OPEN[parent_num].position[no[0]], ch_2 );
		if( select_emptyopen() != -1 )    //�����ز�Ϊ1������ڿս��
		    child_num = select_emptyopen();
	    else
		    cout << "OPEN������" << endl;
		create_node( child_num, parent_num, plan, no[0], num_of_disk );
	}
	}
	OPEN[parent_num].f = MAXNUM;  //����Ѿ���չ�Ľڵ�
	return 0;
}

int select_node( int num_of_disk )  //ѡ����ѽڵ�
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