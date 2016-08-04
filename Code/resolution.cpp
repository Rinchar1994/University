#include <iostream>
#include <fstream>
using namespace std;

#define NUM_FIRSTORDERLOGIC 100              //һ���߼�������ĸ����
#define NUM_CNF 100                           //֪ʶ�������һ���߼�ʽ������
#define NUM_VAR 25                           //��������������
#define LEN_PRE 10                           //ν�ʵĳ�������
#define NUM_PRE 25                           //ν�ʵ���������
// ���������ڷ��ű��е�λ��
#define VAR 1
#define PREDICATE 2     //ν��
#define ANY 3
#define NOT 4
#define EXIST 5
#define CONTAIN 6
#define OR 7
#define AND 8
#define LEFT 9
#define RIGHT 10
#define COMMA 11
#define SPACE 12

int sym[NUM_FIRSTORDERLOGIC];       //sym������ŵ����ڷ��ű��е����
char var[NUM_VAR];                //var������ű���
char predicate[NUM_PRE][LEN_PRE];    //predicate�������ν��   
/***************************************************************
	����������
***************************************************************/

void main()
{
	cout << "�����Ǳ�ʵ��˵����������������" << endl;
	cout << "����ʵ��ĸ������ű�ʾ��" << endl;
	cout << "���ڣ���@���� ���⣺��$���� �񣺡�~���� �̺�����=���� ������|���� ������&��" <<endl;
	cout << "�����õ���Сд��ĸ��ʾ��ν��Ϊ����ĸ��д�ĵ��ʣ������ǵ�����ĸ��" << endl;
	cout << "����ʵ����û�е�ʽ��" << endl;
	char CNF[NUM_CNF][NUM_FIRSTORDERLOGIC];
	Initial_CNF( CNF );
	cout << "������֪ʶ��" << endl;
	int no = 0;          //�������һ���߼�ʽ�ӵ����
	//��ÿһ�������һ���߼����ʽת����CNF
	while( 1 )
	{
		if( no == NUM_CNF )
			break;
		cin >> CNF[no];
		if( strcmp( CNF[no], "finish" ) == 0 )
		{
			for( int t = 0; t < 7; t++ )
				CNF[no][t] = NULL;
			break;
		}
		//�������ʱ�Ĵ���
		while( 1 )
		{
			int tem = word_analyse( CNF[no] );
			if( tem != -1 )
			    break;
			else
			{
			    for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
				    CNF[no][i] = NULL;
		    	cin >> CNF[no];
			}
		}
		//����ƥ��
		while( 1 )
		{
			int tem = match_brackets();
			if( tem != -1 )
			    break;
			else
			{
			    for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
				    CNF[no][i] = NULL;
		    	cin >> CNF[no];
			}
		}
		transform_CNF( CNF[no] );
		no++;
	}
	system("pause");
}

/***************************************************************
	�������岿��
***************************************************************/

void Initial_CNF( char**  &CNF )                             //��ʼ��֪ʶ��
{
	int i, j;
	for( i = 0; i < NUM_CNF; i++ )
		for( j = 0; j < NUM_FIRSTORDERLOGIC; j++ )
		    CNF[i][j] = NULL;
}

void Initial_Table()                                //sym��������ν�ʱ�
{
	for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
		sym[i] = 0;
	for( int i = 0; i < NUM_VAR; i++ )
		var[i] = NULL;
	for( int i = 0; i < NUM_PRE; i++ )
		for( int j = 0; j < LEN_PRE; j++ )
		    predicate[i][j] = NULL;
}

int word_analyse( char* &CNF )              //�ʷ�����
{
	Initial_Table();
	int i = 0, s = 0;    //i��ʾCNF[no]�е�Ԫ����ţ�s��ʾsym��Ԫ�����
	int v = 0, p = 0;    //v��ʾvar��Ԫ�ص���ţ�p��ʾpredicate��Ԫ�����
	while( 1 )
	{
		if( CNF[i] >= 'a' && CNF[i] <= 'z' )
		{
			if( CNF[i+1] != ' ' && CNF[i+1] != ')' CNF[i+1] != ',' )
			{
				error(1);
				return -1;
			}
			else
			{
				sym[s++] = VAR;
				var[v++] = CNF[i];
				i++;
			}
		}
		else if( CNF[i] >= 'A' && CNF[i] <= 'Z' )
		{
			char pre[LEN_PRE] = {0};   ������ʱ����ַ���  
			int no_pre = 0;
			pre[no_pre++] = CNF[i];
			while( 1 )
			{
				if( CNF[i+1] >= 'a' && CNF[i+1] <= 'z' )
					pre[no_pre++] = CNF[++i];
				else
					break;	
			}
			sym[s++] = PREDICATE;
			strcpy( predicate[p++], pre );
			i++;
		}
		else
		{
			switch( CNF[i] )
			{
				case '$':
					sym[s++] = ANY;
					break;
				case '~':
					sym[s++] = NOT;
					break;
				case '@':
					sym[s++] = EXIST;
					break;
				case '=':
					sym[s++] = CONTAIN;
					break;
				case '|':
					sym[s++] = OR;
					break;
				case '&':
					sym[s++] = AND;
					break;
				case '(':
					sym[s++] = LEFT;
					break;
				case ')':
					sym[s++] = RIGHT;
					break;
				case ',':
					sym[s++] = COMMA;
					break;
				case ' ':
					sym[s++] = SPACE;
					break;
				default:
					error(1);
					return -1;
			}
		}
	}
	return 0;
}

int match_brackets()                     //����ƥ��
{
	int num_left = 0, num_right = 0;
	for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
	{
		if( sym[i] == 0 )
			break;
		else if( sym[i] == LEFT )
		{
			num_left++;
		}
		else if( sym[i] == RIGHT )
		{
			num_right++;
			if( num_left < num_right )
			{
				error(2);
				return -1;
			}
		}
	}
	return 0;
}

void transform_CNF( char* &CNF )
{
	del_contain();
	neg_remove();
	stand_var();
	remove_measure();
	del_exist();
	del_any();
	skolem();
}

void del_contain()
{
	int cont;
	for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
	{
		if( sym[i] == CONTAIN )
		{
			int t = 1;
			//��һ���߼��бض�Ϊ���������ڱ�ʵ��Ķ����У�
			for( int j = i - 2; j >= 0; j-- )
			{
				if( sym[j] == RIGHT )
					t++;
				else if( sym[j] == LEFT )
					t--;
				if( t == 0 )
				{
					if( sym[j-1] == SPACE )
						cont = j + 1;
					else if( sym[j-1] == PREDICATE )
						cont = j - 1;
					break;
				}
			}
			sym[i] = OR;
			for( int j = NUM_FIRSTORDERLOGIC; j > cont; j-- )
				sym[j] = sym[j-1];
			sym[cont] = NOT;
			i++;
		}
	}
}

void neg_remove()              //ֻ����3�����
{
	for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
	{
		int count = 0;
		if( sym[i] == NOT )
			if( sym[i+1] == PREDICATE );
			else if( sym[i+1] == NOT )
			{
				for( int j = i; j < NUM_FIRSTORDERLOGIC - 2; j++ )
					sym[j] = sym[j+2];
				sym[NUM_FIRSTORDERLOGIC-2] = 0;
				sym[NUM_FIRSTORDERLOGIC-1] = 0;
			}
			else if( sym[i+1] == ANY  || sym[i+1] == EXIST )   //������ŵ������
			{
				if( sym[i+1] == ANY )
					sym[i+1] = EXIST;
				else
					sym[i+1] = ANY;
				for( int j = i + 2; j < NUM_FIRSTORDERLOGIC; j++ )
				{
					//�ж�����Ƿ����
					if( sym[j] == LEFT )
						count++;
					else if( sym[j] == RIGHT )
					{
						count--;
						if( count < 0 )
							break;
					}
					else if( sym[j] == 0 )
						break;
					//ν�ʵķ�
					else if( sym[j] == PREDICATE )
					{
						int count_sym, count_brak = 1;          //�϶�ν�ʺ���ض�����һ��������
						for( count_sym = j+2; count_sym < NUM_FIRSTORDERLOGIC; count_sym++ )
						{
							if( sym[count_sym] == LEFT )
								count_brak++;
							else if( sym[count_sym] == RIGHT )
							{
								count_brak--;
								if( count_brak == 0 )
									break;
							}
						}
						for( int p = NUM_FIRSTORDERLOGIC-1; p > j; p-- )
							sym[p] = sym[p-1];
						sym[j] = NOT;
						j = count_sym + 1;
					}
					//����ķ�
					else
					{
					    switch( sym[j] )
					    {
						    case ANY:
							    sym[j] = EXIST;
							    break;
						    case EXIST:
						    	sym[j] = ANY;
						    	break;
						    case OR:
							    sym[j] = AND;
							    break;
						    case AND:
							    sym[j] = OR;
							    break;
					    	case NOT:
							    for( int k = j; k < NUM_FIRSTORDERLOGIC-2; k++ )
							    	sym[k] = sym[k+2];
							    sym[NUM_FIRSTORDERLOGIC-2] = 0;
						    	sym[NUM_FIRSTORDERLOGIC-1] = 0;
							    break;
						    default:
								break;
					    }
					}
				}
				for( int t = i; t < NUM_FIRSTORDERLOGIC-1; t++ )
					sym[i] = sym[i+1];
				sym[NUM_FIRSTORDERLOGIC-1] = 0;
			}
	}
}

void stand_var()              //�Ա�Ԫ��׼�����ĵ�֮��ı�����ASCII��ԭ����10��������������������
{
	char var_temp[NUM_VAR] = {0};
	int v = -1;
	for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
	{
		if( sym[i] == VAR )
			v++;
		else if( sym[i] == ANY || sym[i] == EXIST )
		{
			int j = 0;
			while( 1 )
			{
				if( var[v+1] == var_temp[j] )
				{
					for( int k = v+1; k < NUM_VAR; k++ )
					{
						if( var[k] == var_temp[j] )
							var[k] = 'z';            //������3����ͬ����  
					}
					break;
				}
				else if( var_temp[j] == NULL )
				{
					var_temp[j] = var[v+1];
					break;
				}
				j++;
			}
		}
	}
}

void remove_measure()          //������
{
	int t;
	for( int i = NUM_FIRSTORDERLOGIC-1; i >= 0; i-- )
	{
		if( sym[i] == ANY || sym[i] == EXIST )
		{
			t = sym[i];
			for( int j = i + 1; j >= 2; j-- )
				sym[j] = sym[j-2];
			sym[1] = VAR;
			sym[0] = t;	
		}
	}
	char var_temp[NUM_VAR] = {0};
	var_temp[0] = var[0];
	for( int i = 1; i < NUM_VAR; i++ )
	{
		for( int j = 0; j < NUM_VAR; j++ )
		{
			if( var_temp[j] == var[i] )
				break;
			else if( var_temp[j] == NULL )
			{
				t = var[i];
				for( int k = i; k > j; k-- )
					var[k] = var[k-1];
				var[j] = t;
				break;
			}
		}
	}
}

void del_exist()              //��ȥ��������
{
	int num_any = 0;
	char ch_any, ch_exist;
	for( int i = 0; i < NUM_FIRSTORDERLOGIC/2; i++ )
	{
		if( sym(i*2) == EXIST )
		{
			if( num_any == 0 )
			{
				for( int k = 0; k < NUM_FIRSTORDERLOGIC-2; k++ )
					sym[k] = sym[k+2];
				sym[NUM_FIRSTORDERLOGIC-1] = 0;
				sym[NUM_FIRSTORDERLOGIC-2] = 0;
				for( int k = 0; k < NUM_VAR-1; k++ )
					var[k] = var[k+1];
				var[NUM_VAR-1] = NULL;
				i--;
			}
			else                 //�������ʱ�ɺ���
			{
				int count_var = -1, count_predicate = -1;
				ch_exist = var[i];
				for( int k = i*2; k < NUM_FIRSTORDERLOGIC-2; k++ )
					sym[k] = sym[k+2];
				sym[NUM_FIRSTORDERLOGIC-1] = 0;
				sym[NUM_FIRSTORDERLOGIC-2] = 0;
				for( int k = 0; k < NUM_FIRSTORDERLOGIC; k++ )
				{
					if( sym[k] == VAR )
					{
						count_var++;
						if( var[count_var] == ch_exist )
						{
							var[count_var] = ch_any;
							for( int t = NUM_FIRSTORDERLOGIC-1; t > k+3; t-- )
								sym[t] = sym[t-3];
							sym[k] = PREDICATE;
							sym[k+1] = LEFT;
							sym[k+2] = VAR;
							sym[k+3] = RIGHT;
							for( int t = NUM_PRE-1; t > count_predicate+1; t-- )
								strcpy( predicate[t], predicate[t-1] );
							predicate[count_predicate+1][0] = ch_any - 'a' + 'A';
							for( int t = 1; t < NUM_PRE; t++ )
								predicate[t] = NULL;
							count_var--;      //ת��֮�����δ����ȡ��
						}
					}
					else if( sym[k] == PREDICATE )
						count_predicate++;
				}
			}
		}
		else if( sym(i*2) == ANY )           //�������ֻ��һ������
		{
			num_any++;
			ch_any = var[i];
		}
		else
			break;
	}
}

void del_any()                //��ȥ��������
{
	for( int i = 0; i < NUM_FIRSTORDERLOGIC/2; i++ )
	{
		if( sym[i*2] == ANY )
		{
			for( int j = 0; j < NUM_FIRSTORDERLOGIC-2; j++ )
			    sym[j] = sym[j+2];
			sym[NUM_FIRSTORDERLOGIC-1] = 0;
			sym[NUM_FIRSTORDERLOGIC-2] = 0;
			for( int j = 0; j < NUM_VAR-1; j++ )
				var[i] = var[i+1];
			var[NUM_VAR-1] = NULL;
		}
	}
}

void skolem()                 //skolem��׼��
{
	int sym_temp[NUM_FIRSTORDERLOGIC];
	int* p = sym_temp;
	for( int i = 0; i < NUM_FIRSTORDERLOGIC; i++ )
	{
		*p++ = sym[i];
		if( *(p-1) == RIGHT )
		{
			int count_brak = 0;
			if( sym[i+1] == AND || sym[i+1] = RIGHT );
			else if( sym[i+1] == OR )
			{
				int *q = p - 1;
				while(1)
				{
					if( *q == RIGHT )
						count_brak++;
					else if( *q == LEFT )
						count_brak--;
					else if( *q == AND && count_brak == 1 )
						break;
					q -= 1;
				}
			}
		}
	}
}
	
void error( int i )
{
	switch( i )
	{
		case 1: 
		    cout << "���Ŵ������������룡" << endl;
			break;
		case 2:
			cout << "����ƥ��������������룡" << endl;
			break;
		default:
			break;
	}
}