//1252366 蒋凌超 电子一班

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int shudu[9][9];
	ifstream infile;
	infile.open("shudu.txt",ios::in);
	if(infile==NULL)
	{
		cout << "打开文件夹失败" << endl;
		return -1;
	}

	int i, j, G=0;//G用来表示含有9个不同数字的次数
	for( i=0; i<9; i++)
		for( j=0; j<9; j++)
			infile >> shudu[i][j];

	bool _1, _2, _3, _4, _5, _6, _7, _8, _9;
	int item;
    while(1)
	{
	    for( i=0; i<9; i++)
		{
	    	_1=_2=_3=_4=_5=_6=_7=_8=_9=0;
	    	for( j=0; j<9; j++)
			{
		    	item=shudu[i][j];
	    		switch(item%10)
				{
			        case 1:
					    _1=1;
	    		    	break;
		    		case 2:
			    		_2=1;
			        	break;
	    			case 3:
		    	 		_3=1;
			        	break;
			    	case 4:
	    		 		_4=1;
    			    	break;
	    			case 5:
	    				_5=1;
		    	    	break;
	    			case 6:
			    		_6=1;
				        break;
    				case 7:
	    				_7=1;
		    	    	break;
			    	case 8:
				    	_8=1;
			    	    break;
    				case 9:
	    				_9=1;
		    		    break;
			    	default:
				    	break;
				}
			}
		    if(_1 && _2 && _3 && _4 && _5 && _6 && _7 && _8 && _9)
			{
			    G++;
			    continue;
			}
    		else
			{
			    cout << "该矩阵不满足数独的解" << endl;
			    break;
			}
		}
		if(G!=9)
			break;
    	for( j=0; j<9; j++)
		{
		    _1=_2=_3=_4=_5=_6=_7=_8=_9=0;
		    for( i=0; i<9; i++)
			{
			    item=shudu[i][j];
			    switch(item%10)
				{
			        case 1:
					    _1=1;
	    		    	break;
		    		case 2:
			    		_2=1;
			        	break;
	    			case 3:
		    	 		_3=1;
			        	break;
			    	case 4:
	    		 		_4=1;
    			    	break;
	    			case 5:
	    				_5=1;
		    	    	break;
	    			case 6:
			    		_6=1;
				        break;
    				case 7:
	    				_7=1;
		    	    	break;
			    	case 8:
				    	_8=1;
			    	    break;
    				case 9:
	    				_9=1;
		    		    break;
			    	default:
				    	break;
				}
			}
		    if(_1 && _2 && _3 && _4 && _5 && _6 && _7 && _8 && _9)
			{
			    G++;
			    continue;
			}
    		else
			{
			    cout << "该矩阵不满足数独的解" << endl;
			    break;
			}
		}
		if(G!=18)
			break;

    	int shudu_2[9][9], line, list, x=0, y=0;
    	for( line=0; line<9; line++)
    		for( list=0; list<=2; list++)
			{
		    	shudu_2[x][y]=shudu[line][list];
	    		y++;
		    	if(y==9)
				{
				    y=0;
		    		x++;
				}
			}
    	for( line=0; line<9; line++)
	    	for( list=3; list<=5; list++)
			{
			    shudu_2[x][y]=shudu[line][list];
			    y++;
			    if(y==9)
				{
				    y=0;
				    x++;
				}
			}
	    for( line=0; line<9; line++)
		    for( list=6; list<=8; list++)
			{
			    shudu_2[x][y]=shudu[line][list];
			    y++;
			    if(y==9)
				{
				    y=0;
				    x++;
				}
			}

	    for( i=0; i<9; i++)
		{
		    _1=_2=_3=_4=_5=_6=_7=_8=_9=0;
		    for( j=0; j<9; j++)
			{
			    item=shudu[i][j];
			    switch(item%10)
				{
			        case 1:
					    _1=1;
	    		    	break;
		    		case 2:
			    		_2=1;
			        	break;
	    			case 3:
		    	 		_3=1;
			        	break;
			    	case 4:
	    		 		_4=1;
    			    	break;
	    			case 5:
	    				_5=1;
		    	    	break;
	    			case 6:
			    		_6=1;
				        break;
    				case 7:
	    				_7=1;
		    	    	break;
			    	case 8:
				    	_8=1;
			    	    break;
    				case 9:
	    				_9=1;
		    		    break;
			    	default:
				    	break;
				}
			}
		    if(_1 && _2 && _3 && _4 && _5 && _6 && _7 && _8 && _9)
			{
			    G++;
			    continue;
			}
    		else
			{
			    cout << "该矩阵不满足数独的解" << endl;
			    break;
			}
		}
	    if(G==27)
	    	cout << "该矩阵满足数独的解" << endl;
	}
  
	infile.close();

	return 0;
}
	






