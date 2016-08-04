#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const char key[17][8] = { "void", "main", "int", "char", "bool", "false", "while", "cin",
	                      "if", "true", "break", "switch", "case", "default", "cout", "endl","float"};

void main()
{
	char line[200];    //ÿ������ַ���
	int id = 0;     //��ʶ����Ŀ
	char letter[20] = {0};  //ÿ�αȽ�ʱ�����ַ����ĵط�
	ifstream fin;
	fin.open( "workable.txt", ios::in );
	if( fin == NULL )
		cout << "failed to open the file!" << endl;
	while(fin.getline(line,200))
	{
		for( int i = 0; i < 200; i++ )
		{
		    if( line[i] == 0 )
		    	break;
		    else if( line[i] == ' ' )
				continue;
	    	else if( line[i]>=97 && line[i]<=122 || line[i]>=65 && line[i]<=90)//û�п��Ǳ�ʶ����_��ͷ���������ʶ���͹ؼ��֣�
		    {
			    int i_1 = 0;//������ʱ�ַ����е��ַ�����
		    	letter[i_1++] = line[i];
		    	while( 1 )
			    {
				    if( line[i+1]>=97 && line[i+1]<=122 || line[i+1]>=65 && line[i+1]<=90 || line[i+1]>='0' && line[i+1]<='9' )
					    letter[i_1++] = line[++i];
				    else  //�����ո�
					    break;
		    	}
			    for( int i_2 = 0; i_2 < 17; i_2++)
			    {
			    	if( strcmp(letter, key[i_2]) == 0 )//��ؼ���ƥ��ɹ�
					{
					    cout << key[i_2] << "(keyword" << i_2+1 << ")" << "  ";
						break;
					}
					if( strcmp(letter, key[i_2]) != 0 && i_2 == 16 )
						cout << letter << "(identifier)   ";
				}
				for( int let = 0; let < 20; let++ )
					letter[let] = 0;
	       	}
			//����
			else if( line[i]>='0' && line[i]<='9' )
			{
				int i_1 = 0; 
				letter[i_1++] = line[i];
				while( 1 )
			    {
					if( line[i+1]>='0' && line[i+1]<='9' )
						letter[i_1++] = line[++i];
					else
						break;
				}
				cout << letter << "(number)    ";
				for( int let = 0; let < 20; let++ )
					letter[let] = 0;
			}
			//����ͽ��
			else if( line[i] == '<' )
			{
				if( line[i+1] != '<' )
					cout << "< (operator1)   ";
				else
				{
					i++;
					cout << "<< (operator2)   ";
				}
			}
			else if( line[i] == '=' )
			{
				if( line[i+1] != '=' )
					cout << "= (operator3)   ";
				else
				{
					i++;
					cout << "== (operator4)   ";
				}
			}
			else if( line[i] == '+' )
			{
				if( line[i+1] != '+' )
					cout << "+ (operator5)   ";
				else
				{
					i++;
					cout << "++ (operator6)   ";
				}
			}
			else if( line[i] == '-' )
			{
				if( line[i+1] != '-' )
					cout << "- (operator7)   ";
				else
				{
					i++;
					cout << "-- (operator8)   ";
				}
			}
			else if( line[i] == '>' )
			{
				if( line[i+1] != '>' )
					cout << "> (operator9)   ";
				else
				{
					i++;
					cout << ">> (operator10)   ";
				}
			}
			else
			{
				switch( line[i] )
				{
				    case '*':
						cout << "* (operator11)   ";
						break;
					case '/':
						cout << "/ (operator12)   ";
						break;
					case ';':
						cout << ": (delimiter1)   ";
						break;
					case ',':
						cout << ", (delimiter2)   ";
						break;
					case '(': 
						cout << "( (delimiter3)   ";
						break;
					case ')':
						cout << ") (delimiter4)   ";
						break;
					case '{':
						cout << "{ (delimiter5)   ";
						break;
					case '}':
						cout << "} (delimiter6)   ";
						break;
					case '\'':
						cout << "' (delimiter7)   ";
						break;
					case ':':
						cout << ": (delimiter8)   ";
						break;
					default:
						break;
				}
			}

		}
		cout << endl << endl << endl;
	}
	fin.close();
	cout << "���ڱ������ܷ����Ĵ���ȫ�����ڲ��Դ����У��ʲ����������Ա�" << endl;
	system("pause");
}


//���ڱ������ܷ����Ĵ���ȫ�����ڲ��Դ����У��ʲ����������Ա�
	