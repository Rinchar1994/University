#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAXNUM_KEY 10
#define NUM_KEY 13
#define NUM_LINE 80
#define NUM_NUMBER 14
#define NUM_OPERA 16
#define MAXNUM_OPERA 3
#define NUM_SYM 11
#define MAXNUM_NODE 20
#define MAXNUM 30000
#define MAXQSIZE 1000

char line[NUM_LINE];   //line存放一行字符串
char id[MAXNUM_KEY] = { 0 };  //临时存放字符串
char num[NUM_NUMBER] = { 0 }; //临时存放数字
char sym[NUM_SYM] = {0};   //用来存放单词
char sym_s[2] = { 0 };
int CC;       //用来存放当前字母在行中的位置

typedef struct NODE{
	char str[NUM_SYM];   //存放文法符号
	NODE *child[MAXNUM_NODE];   //指向子树的指针,子树的数量有限制！
	int layer;  //用来显示结点所在的层数
} *syntax_analyse;

typedef NODE *QElemType;
typedef struct
{
	QElemType *base;
	int front, rear;
}SqQueue;


char KEYWORD[NUM_KEY][MAXNUM_KEY] = { "CONST", "VAR", "PROCEDURE", "CALL", "BEGIN", "END", "IF", "THEN", "WHILE", "DO", "READ", "WRITE", "ODD" };
char OPERATOR[NUM_OPERA][MAXNUM_OPERA] = { ":=", "<=", "<", ">=", ">", "=", "+", "-", "*", "/", "#", ".", ",", ";", "(", ")" };

/*   声明部分       */

int word_analyse( ofstream &file );                           //读取源文件中的字符并将单词存到空白文件中(同时也放在一个字符数组中）
int getsym( ifstream &fsym );                                 //读取词法分析之后单词存放的文件中的单词
void initial_tree( syntax_analyse &L );                       //初始化语法树
void create( syntax_analyse &q, syntax_analyse &p );          //创建结点
int block( ifstream &fsym, syntax_analyse &L );               //分程序
int const_def( ifstream &fsym, syntax_analyse &p );           //常量定义
int var_def( ifstream &fsym, syntax_analyse &p );             //变量定义
int state( ifstream &fsym, syntax_analyse &p );               //语句部分
int condition( ifstream &fsym, syntax_analyse &p );           //条件
int express( ifstream &fsym, syntax_analyse &p );             //表达式部分
int term( ifstream &fsym, syntax_analyse &p );                //项
int factor( ifstream &fsym, syntax_analyse &p );              //因子
void error( int i );                                          //错误原因
void print_child( ofstream &ftree, syntax_analyse &L );       //输出语法树某结点的所有子节点
void print( ofstream &ftree, syntax_analyse &L );             //输出语法树
void delete_tree( syntax_analyse &L );                        //释放树
int InitQueue (SqQueue &Q);                                   //链队列初始化
void LevelOrderTraverse(ofstream &ftree, syntax_analyse T);   //层次遍历二叉树的算法


/*   主函数部分    */
void main()
{
	//workable.txt中放着带编译的源代码
    ifstream fin, fsym;
    fin.open( "source2.txt", ios::in );
    if( !fin )
	   	cout << "failed to open the file!" << endl;
	ofstream file, ftree;
	file.open( "word.txt", ios::out );
	if( !file  )
	    cout << "failed to open the file!" << endl;
    //将源文件做词法分析之后输入指定文件
    while(fin.getline(line,80))
	{
	    CC = 0;
		if( word_analyse( file ) == -1 )
		    break;
	}
	fin.close();
	file.close();
	fsym.open( "word.txt",ios::in );
	if( !fsym )
		cout << "failed to open the file!" << endl;
	
	syntax_analyse _main, p;
	initial_tree( _main );
	block( fsym, _main );
	//处理"."问题！！！！！！！
	if( strcmp( sym, "." ) == 0 )
	{
		create( _main, p ); 
		strcpy_s( p->str, "." );
	}
	else
	{
		error(16);
	}
	fsym.close();
    ftree.open( "tree.txt", ios::out );
	if( !ftree)
		cout << "failed to open the file!" << endl;
	
	LevelOrderTraverse( ftree, _main);
	delete_tree( _main );
	ftree.close();
    system("pause");
}

/*   函数定义部分   */
int word_analyse(ofstream &file)
{
	for (; CC < 80; CC++)
	{
		if (line[CC] == 0)
			break;
		else if (line[CC] == ' ')
			continue;
		//考虑标识符和关键字
		else if (line[CC] <= 'z' && line[CC] >= 'a' || line[CC] <= 'Z' && line[CC] >= 'A')
		{
			int i_1 = 0;
			id[i_1++] = line[CC];
			while (1)
			{
				if (line[CC + 1] >= 97 && line[CC + 1] <= 122 || line[CC + 1] >= 65 && line[CC + 1] <= 90 || line[CC + 1] >= '0' && line[CC + 1] <= '9')
					id[i_1++] = line[++CC];
				else  //包含空格
					break;
			}
			for (int i_2 = 0; i_2 < NUM_KEY; i_2++)
			{
				if (strcmp(id, KEYWORD[i_2]) == 0)//与关键字匹配成功
				{
					file << id << "  " << "$  ";   //$表示保留字
					break;
				}
				else if (i_2 == NUM_KEY - 1)
					file << id << "  %  ";          //%表示自定义变量
			}
			for (int let = 0; let < MAXNUM_KEY; let++)
				id[let] = 0;
		}
		// 数字
		else if (line[CC] >= '0' && line[CC] <= '9')
		{
			int i_1 = 0;
			num[i_1++] = line[CC];
			while (1)
			{
				if (line[CC + 1] >= '0' && line[CC + 1] <= '9')
					num[i_1++] = line[++CC];
				else
					break;
			}
			file << num << "  ^  ";   //^表示数字
			for (int let = 0; let < NUM_NUMBER; let++)
				num[let] = 0;
		}
		//符号
		else if (line[CC] == ':')
		{
			if (line[CC + 1] == '=')
			{
				CC++;
				file << ":=  " << "$  ";
			}
		}
		else if (line[CC] == '< ')
		{
			if (line[CC + 1] == '=')
			{
				CC++;
				file << "<=  " << "$  ";
			}
			else
				file << "<  " << "$  ";
		}
		else if (line[CC] == '>')
		{
			if (line[CC + 1] == '=')
			{
				CC++;
				file << ">=  " << "$  ";
			}
			else
				file << ">  " << "$  ";
		}
		else if (line[CC] == '=')
			file << "=  " << "$  ";
		else if (line[CC] == '+')
			file << "+  " << "$  ";
		else if (line[CC] == '-')
			file << "-  " << "$  ";
		else if (line[CC] == '*')
			file << "*  " << "$  ";
		else if (line[CC] == '/')
			file << "/  " << "$  ";
		else if (line[CC] == '#')
			file << "#  " << "$  ";
		else if (line[CC] == '.')
			file << ".  " << "$  ";
		else if (line[CC] == ',')
			file << ",  " << "$  ";
		else if (line[CC] == ';')
			file << ";  " << "$  ";
		else if (line[CC] == '(')
			file << "(  " << "$  ";
		else if (line[CC] == ')')
			file << ")  " << "$  ";
		else
		{
			file << "error";
			error(1);
			return -1;
		}
	}
	file << endl;
	return 0;
}

int getsym(ifstream &fsym)
{
	int i;
	char ch;
	for (i = 0; i < NUM_SYM; i++)
		sym[i] = 0;
	i = 0;
	while (1)
	{
		if (fsym.get(ch))
		{
			if (ch == ' ')
				break;
			else if (ch == '\n')
				continue;
			else
				sym[i++] = ch;
		}
		else
			return 0;
	}
	//将两个空格读掉！
	fsym.get(ch);
	fsym.get(ch);
	//获得属性
	sym_s[0] = ch;
	fsym.get(ch);
	fsym.get(ch);
	return 1;
}
void initial_tree( syntax_analyse &L )
{
	L = (syntax_analyse)malloc(sizeof(NODE));
	syntax_analyse body = (syntax_analyse)malloc(sizeof(NODE));  //分程序的结点
	int i;
	strcpy_s( L->str, "main" );
	L->child[0] = body;
    for( i = 1; i < MAXNUM_NODE; i++ )
		L->child[i] = NULL;
	L->layer = 0;
    strcpy_s( body->str, "block" );
	for( i = 0; i < MAXNUM_NODE; i++ )
		body->child[i] = NULL;
	body->layer = 1;
}

void create( syntax_analyse &q, syntax_analyse &p )  //q为父亲结点
{
	p = (syntax_analyse)malloc(sizeof(NODE));
	int i = 0;
	while( 1 )
	{
		if( q->child[i++] == NULL )
		{
			q->child[--i] = p;
			break;
		}
		else if( i == MAXNUM_NODE )
		{
			error(2);
			break;
		}
	}
	p->layer = q->layer + 1;
	for( i = 0; i < MAXNUM_NODE; i++ )
		p->child[i] = NULL;
}

int block( ifstream &fsym, syntax_analyse &L )
{
	syntax_analyse p, q, r;
	q = L->child[0];
	while( getsym( fsym ) )
	{
		//常量说明
	    if( strcmp( sym, "CONST" ) == 0 )
	    {
		    create( q, p );
		    strcpy_s( p->str, "const_exp" );
		    create( p, r );
	    	strcpy_s( r->str, "CONST" );
			getsym( fsym );
			if( strcmp(sym_s,"%") != 0 )
			{
				error(3);
				return -1;
			}
			else
			{
				if( const_def( fsym, p ) == -1 )
					return -1;
				create( p, r );
				strcpy_s( r->str, ";" );
			}
		}
		//变量说明
		else if( strcmp( sym, "VAR" ) == 0 )
		{
			create( q, p );
			strcpy_s( p->str, "var_exp" );
			create( p, r );
			strcpy_s( r->str, "VAR" );
			getsym( fsym );
			if( strcmp(sym_s,"%") != 0 )
			{
				error(5);
				return -1;
			}
			else
			{
				if( var_def( fsym, p ) == -1 )
					return -1;
				create( p, r );
				strcpy_s( r->str, ";" );
			} 
		}
		//分程序递归
		else if( strcmp( sym, "PROCEDURE" ) == 0 )
		{
			create( q, p );
			strcpy_s( p->str, "block_def" );
			create( p, r );
			strcpy_s( r->str, "PROCEDURE" );
			getsym( fsym );
			if( strcmp( sym_s, "%" ) != 0 )
			{
				error(6);
				cout << "nimei" << endl;
				return -1;
			}
			else
			{
				create( p, r );
				strcpy_s( r->str, sym );
				getsym( fsym );
				if( strcmp( sym, ";" ) != 0 )
				{
					error(6);
					return -1;
				}
				else
				{
					create( p, r );
					strcpy_s( r->str, ";" );
					create( p, r );
					strcpy_s( r->str, "block" );
					int ret_1 = block( fsym, p );
					if( ret_1 == -1 )
						return -1;
					else if( ret_1 == 1 )
						return 1;
					else if( ret_1 == 2 )
					{
						create( p, r ); 
			            strcpy_s( r->str, ";" );
					}
				}
			} 
		}
		//语句部分
		else
		{
			int ret_1 = state( fsym, q );
			if( ret_1 == -1 )
				return -1;
			else if( ret_1 == 1 )
				return 1;
			else if( ret_1 == 2 )
				return 2;
		}
	}
	return 0;
}

int const_def( ifstream &fsym, syntax_analyse &p )
{
	syntax_analyse r = p, r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, "const_def" );
	r = r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, sym );
	getsym( fsym );
	if( strcmp( sym, "=" ) != 0 ) 
	{
		error(4);
		return -1;
	}
	else
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "=" );
	    getsym( fsym );
		if( strcmp(sym_s,"^") !=0 )
	    {
    		error(4);
			return -1;
		}
		else
		{
			create( r, r_1 );
			strcpy_s( r_1->str, "num" );
			getsym( fsym );
			if( strcmp( sym, "," ) == 0 )
			{
				create( r, r_1 );
				strcpy_s( r_1->str, "," );
				getsym( fsym );
				if( strcmp(sym_s,"%") != 0 )
				{
					error(3);
					return -1;
				}
				else
				{
				    if( const_def( fsym, r ) == -1 )
					    return -1;
				}
			}
			else if( strcmp( sym, ";" )  != 0 )
			{
				error(4);
				return -1;
			}
		}
	}
	return 0;
}

int var_def( ifstream &fsym, syntax_analyse &p )
{
	syntax_analyse r = p, r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, "var_def" );
	r = r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, sym );
	getsym( fsym );
	if( strcmp( sym, "," ) == 0 ) 
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "," );
		getsym( fsym );
		if( strcmp(sym_s,"%") != 0 )
		{
			error(5);
			return -1;
		}
		else
		{
			if( var_def( fsym, r ) == -1 )
			    return -1;
		}
	}
	else if( strcmp( sym, ";" ) != 0 )
	{
		error(5);
		return -1;
	}
	return 0;
}

int state( ifstream &fsym, syntax_analyse &p )
{
	syntax_analyse r = p, r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, "state_def" );
	r = r_1;
	if( strcmp(sym_s,"%") == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "assign" );
		r = r_1;
		create( r, r_1 );
		strcpy_s( r_1->str, sym );
		getsym( fsym );
        if( strcmp( sym, ":=" ) != 0 )
		{
			error(7);
			return -1;
		}
		else
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, ":=" );
		    getsym( fsym );
			if( express( fsym, r ) == -1 )
				return -1;
		}
	}
	else if( strcmp( sym, "CALL" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "call_order" );
		r = r_1;
		create( r, r_1 );
		strcpy_s( r_1->str, "CALL" );
		getsym( fsym );
		if( strcmp(sym_s,"%") != 0 )
		{
			error(10);
			return -1;
		}
		else
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, sym );
		    getsym( fsym );
		}
	}
	else if( strcmp( sym, "BEGIN" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "mul_state" );
		r = r_1;
		create( r, r_1 );
		strcpy_s( r_1->str, "BEGIN" );
		getsym( fsym );
		if( state( fsym, r ) == -1 )
			return -1;
		if( strcmp( sym, ";" ) != 0 )
		{
			error(11);
			return -1;
		}
		else
		{
			create( r, r_1 );
			strcpy_s( r_1->str, ";" );
			getsym( fsym );
		}
		while( 1 )
		{
			 if( strcmp( sym, "END" ) == 0 )
			{
				create( r, r_1 );
				strcpy_s( r_1->str, "END" );
				getsym( fsym );
				break;
			}
			 else
			{
				if( state( fsym, r ) == -1 )
					return -1;
				if( strcmp( sym, ";" ) != 0 )
		        {
			         error(11);
		        	return -1;
	        	}
		        else
		        {
		        	create( r, r_1 );
		        	strcpy_s( r_1->str, ";" );
		        	getsym( fsym );
	        	}
			}
		}
	}
	else if( strcmp( sym, "IF" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "condition" );
		r = r_1;
		create( r, r_1 );
		strcpy_s( r_1->str, "IF" );
		getsym( fsym );
		if( condition( fsym, r ) == -1 )
			return -1;
		if( strcmp( sym, "THEN" ) != 0 )
		{
			error(15);
			return -1;
		}
		else
		{
			create( r, r_1 );
			strcpy_s( r_1->str, "THEN" );
			getsym( fsym );
			if( state( fsym, r ) == -1 )
			    return -1;
		}
	}
	else if( strcmp( sym, "WHILE" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "circle" );
		r = r_1;
		create( r, r_1 );
		strcpy_s( r_1->str, "WHILE" );
		getsym( fsym );
		if( condition( fsym, r ) == -1 )
			return -1;
		if( strcmp( sym, "DO" ) != 0 )
		{
			error(12);
			return -1;
		}
		else
		{
			create( r, r_1 );
			strcpy_s( r_1->str, "DO" );
			getsym( fsym );
			if( state( fsym, r ) == -1 )
			    return -1;
		}
	}
	else if( strcmp( sym, "READ" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "read" );
		r = r_1;
		create( r, r_1 );
		strcpy_s( r_1->str, "READ" );
		getsym( fsym );
		if( strcmp( sym, "(" ) != 0 )
		{
			error(13);
			return -1;
		}
		else
		{
			create( r, r_1 );
			strcpy_s( r_1->str, "(" );
			getsym( fsym );
		    if( strcmp(sym_s,"%") != 0 )
			{
				error(13);
				return -1;
			}
			else
			{
				create( r, r_1 );
			    strcpy_s( r_1->str, sym );
			    getsym( fsym );
				while( 1 )
				{
					if( strcmp( sym, ")" ) == 0 )
					{
						create( r, r_1 );
			            strcpy_s( r_1->str, ")" );
			            getsym( fsym );
						break;
					}
					else if( strcmp( sym, "," ) == 0 )
					{
						create( r, r_1 );
			            strcpy_s( r_1->str, "," );
			            getsym( fsym );
						if( strcmp(sym_s,"%") == 0 )
						{
							create( r, r_1 );
			                strcpy_s( r_1->str, sym );
			                getsym( fsym );
						}
						else
						{
							error(13);
							return -1;
						}
					}
					else
					{
						error(13);
						return -1;
					}
				}
			}
		} 
	}
	else if( strcmp( sym, "WRITE" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "write" );
		r = r_1;
		create( r, r_1 );
		strcpy_s( r_1->str, "WRITE" );
		getsym( fsym );
		if( strcmp( sym, "(" ) != 0 )
		{
			error(14);
			return -1;
		}
		else
		{
			create( r, r_1 );
			strcpy_s( r_1->str, "(" );
			getsym( fsym );
		    if( express( fsym, r ) == -1 )
			    return -1;
			while( 1 )
			{
				if( strcmp( sym, ")" ) == 0 )
				{
					create( r, r_1 );
			        strcpy_s( r_1->str, ")" );
			        getsym( fsym );
					break;
				}
				else if( strcmp( sym, "," ) == 0 )
				{
					create( r, r_1 );
		            strcpy_s( r_1->str, "," );
		            getsym( fsym );
					if( express( fsym, r ) == -1 )
						return -1;
				}
				else
				{
					error(14);
					return -1;
				}
			}
		}
	}
	else
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "blank" );
	}
	if( strcmp( sym, "." ) == 0 )
		return 1;
	else if( strcmp( sym, ";" ) == 0 )
		return 2;
	return 0;
}

int condition( ifstream &fsym, syntax_analyse &p )
{
	syntax_analyse r = p, r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, "condition" );
	r = r_1;
	if( strcmp( sym, "ODD" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "ODD" );
		getsym( fsym );
		if( express( fsym, r ) == -1 )
			return -1;
	}
	else
	{
		if( express( fsym, r ) == -1 )
			return -1;
		if( strcmp( sym, "=" ) == 0 ) 
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, "=" );
		    getsym( fsym );
		}
		else if( strcmp( sym, "#" ) == 0 ) 
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, "#" );
		    getsym( fsym );
		}
		else if( strcmp( sym, "<" ) == 0 ) 
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, "<" );
		    getsym( fsym );
		}
		else if( strcmp( sym, "<=" ) == 0 ) 
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, "<=" );
		    getsym( fsym );
		}
		else if( strcmp( sym, ">" ) == 0 ) 
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, ">" );
		    getsym( fsym );
		}
		else if( strcmp( sym, ">=" ) == 0 ) 
		{
			create( r, r_1 );
		    strcpy_s( r_1->str, ">=" );
		    getsym( fsym );
		}
		else
		{
			error(9);
			return -1;
		}
		if( express( fsym, r ) == -1 )
			return -1;
	}
	return 0;
}

int express( ifstream &fsym, syntax_analyse &p )
{
	syntax_analyse r = p, r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, "express" );
	r = r_1;
	if( strcmp( sym, "+" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "+" );
		getsym( fsym );
		if( term( fsym, r ) == -1 )
			return -1;
	}
	else if( strcmp( sym, "-" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "-" );
		getsym( fsym );
		if( term( fsym, r ) == -1 )
			return -1;
	}
	else
		if( term( fsym, r ) == -1 )
			return -1;
	while( 1 )
	{
		if( strcmp( sym, "+" ) == 0 )
	    {
		    create( r, r_1 );
		    strcpy_s( r_1->str, "+" );
		    getsym( fsym );
		    if( term( fsym, r ) == -1 )
		        return -1;
	    }
		else if( strcmp( sym, "-" ) == 0 )
	    {
		    create( r, r_1 );
		    strcpy_s( r_1->str, "-" );
		    getsym( fsym );
		    if( term( fsym, r ) == -1 )
		        return -1;
	    }
		else
			break; 
	}
	return 0;	
}

int term( ifstream &fsym, syntax_analyse &p )
{
	syntax_analyse r = p, r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, "term" );
	r = r_1;
	if( factor( fsym, r ) == -1 )
		return -1;
	while( 1 )
	{
		if( strcmp( sym, "*" ) == 0 )
	    {
		    create( r, r_1 );
		    strcpy_s( r_1->str, "*" );
		    getsym( fsym );
		    if( factor( fsym, r ) == -1 )
		        return -1;
	    }
		else if( strcmp( sym, "/" ) == 0 )
	    {
		    create( r, r_1 );
		    strcpy_s( r_1->str, "/" );
		    getsym( fsym );
		    if( factor( fsym, r ) == -1 )
		        return -1;
	    }
		else
			break;
	}
	return 0;
}

int factor( ifstream &fsym, syntax_analyse &p )
{
	syntax_analyse r = p, r_1;
	create( r, r_1 );
	strcpy_s( r_1->str, "factor" );
	r = r_1;
	if( strcmp(sym_s,"%") == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, sym );
		getsym( fsym );
	}
	else if( strcmp(sym_s,"^") == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "num" );
		getsym( fsym );
	}
	else if( strcmp( sym, "(" ) == 0 )
	{
		create( r, r_1 );
		strcpy_s( r_1->str, "(" );
		getsym( fsym );
		if( express( fsym, r ) == -1 )
			return -1;
		create( r, r_1 );
		strcpy_s( r_1->str, ")" );
		getsym( fsym );
	}
	else
	{
		error(8);
		return -1;
	}
	return 0;
}

void error( int i )
{
	switch( i )
	{
		case 1:
			cout << "error: not exist!" << endl;
			break;
		case 2:
			cout << "error: number of child-tree is too much!" << endl;
			break;
		case 3:
			cout << "error: const statement is wrong!" << endl;
			break;
		case 4:
			cout << "error: define of const statement is wrong!" << endl;
			break;
		case 5:
			cout << "error: var statement is wrong!" << endl;
			break;
		case 6:
			cout << "error: procedure statement is wrong!" << endl;
			break;
		case 7:
			cout << "error: define of assign statement is wrong!" << endl;
			break;
		case 8:
			cout << "error: factor is wrong!" << endl;
			break;
		case 9:
			cout << "error: condition is wrong!" << endl;
			break;
		case 10:
			cout << "error: define of call statement is wrong!" << endl;
			break;
		case 11:
			cout << "error: define of mul_statement is wrong!" << endl;
			break;
		case 12:
			cout << "error: define of circle statement is wrong!" << endl;
			break;
		case 13:
			cout << "error: define of read statement is wrong!" << endl;
			break;
		case 14:
			cout << "error: define of write statement is wrong!" << endl;
			break;
		case 15:
			cout << "error: define of condition statement is wrong!" << endl;
			break;
		case 16:
			cout << "error: '.' is wrong!" << endl;
		default:
			break;
	}
}

void print_child( ofstream &ftree, syntax_analyse &L )
{
	syntax_analyse p = L;
	if( p->child[0] != NULL )
	{
		ftree << "(  ";
	    for( int i= 0; ; i++ )
	    {
	    	if( p->child[i] == NULL )
			    break;
		    else if( p->child[i+1] == NULL )
			    ftree << p->child[i]->str << "  )  ";
		    else
	  	    	ftree << p->child[i]->str << "  ";
	    }
	}
}

int InitQueue (SqQueue &Q)
{
	Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));   //队列大小有限
	if (!Q.base)
		return -1;
	Q.front=Q.rear=0;
	return 0;
}

void LevelOrderTraverse(ofstream &ftree, syntax_analyse T)
{
	syntax_analyse p;
	SqQueue Q;
	InitQueue(Q);
	int num_level = 1;
    if (T)
	{
		ftree << "(  " << T->str << "  )  " << endl;     //输出根结点
		Q.base[Q.rear]=T;
		Q.rear=(Q.rear+1)%MAXQSIZE;
	    while (Q.front%MAXQSIZE != Q.rear%MAXQSIZE)      //判队空
		{
			p=Q.base[Q.front];   //取队头元素
			if( num_level-1 != p->layer )
			{
				num_level++;
				ftree << endl;
			}
			print_child( ftree, p );
			Q.front=(Q.front+1)%MAXQSIZE;
			for( int i = 0; ; i++ )
			{
				if( p->child[i] )
				{
					Q.base[Q.rear] = p->child[i];
					Q.rear=(Q.rear+1)%MAXQSIZE;
				}
				else
					break;
			}
		}
	}
}

void delete_tree( syntax_analyse &L )
{
	syntax_analyse p = L;
	int i = 0;
	while( p->child[i] )
	{
		delete_tree( p->child[i] );
		i++;
		if( i == MAXNUM_NODE )
			break;
	}
	free(p);
}