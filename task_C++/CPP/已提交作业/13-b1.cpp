//1252366 蒋凌超 电子一班
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct game
{
	char name[16];
	short hp;
	short strength;
	short tizhi;
	short lingqiao;
	int mon;
	int fame;
	int meili;
	char prestay_1[8];
	char m_speed;
	char h_speed;
	char h_extent;
	char prestay_2;
	short h_strength;
	short f_strength;
	char minjie;
	char intellege;
	char experience;
	char state;
	short mofa;
	char haomo;
	char moshang;
	char mingzhong;
	char mofang;
	char baoji;
	char naili;
};

void change( char a, game &b )
{
	if( a == 'A' )
	{
		char t1[16];
		while(1)
		{
		    cin >> t1;
		    if ( strlen(t1)>15 || strlen(t1)==0 )
			{
		    	cout << "error name!!" << endl;
				continue;
			}
		    else
			{
		    	strcpy( b.name, t1 );
				break;
			}
		}
	}
	if( a == 'B' )
	{
		short t2;
		while(1)
		{
		    cin >> t2;
		    if ( t2<0 || t2 >10000 )
			{
		    	cout << "error hp!!" << endl;
				continue;
			}
		    else
			{
		    	b.hp=t2;
				break;
			}
		}
	}
	if( a == 'C' )
	{
		short t3;
		while(1)
		{
		    cin >> t3;
		    if ( t3<0 || t3 >10000 )
			{
		    	cout << "error strength!!" << endl;
				continue;
			}
		    else
			{
		    	b.strength=t3;
				break;
			}
		}
	}
	if( a == 'D' )
	{
		short t4;
		while(1)
		{
		    cin >> t4;
		    if ( t4<0 || t4 >8192 )
			{
		    	cout << "error tizhi!!" << endl;
				continue;
			}
		    else
			{
		    	b.tizhi=t4;
				break;
			}
		}
	}
	if( a == 'E' )
	{
		short t5;
		while(1)
		{
		    cin >> t5;
		    if ( t5<0 || t5 >1024 )
			{
		    	cout << "error lingqiao!!" << endl;
				continue;
			}
		    else
			{
		    	b.lingqiao=t5;
				break;
			}
		}
	}
    if( a == 'F' )
	{
		int t6;
		while(1)
		{
		    cin >> t6;
		    if ( t6<0 || t6 >100000000 )
			{
		    	cout << "error mon!!" << endl;
				continue;
			}
		    else
			{
		    	b.mon=t6;
				break;
			}
		}
	}
	if( a == 'G' )
	{
		int t7;
		while(1)
		{
		    cin >> t7;
		    if ( t7<0 || t7 >1000000 )
			{
		    	cout << "error fame!!" << endl;
				continue;
			}
		    else
			{
		    	b.fame=t7;
				break;
			}
		}
	}
	if( a == 'H' )
	{
		int t8;
		while(1)
		{
		    cin >> t8;
		    if ( t8<0 || t8 >1000000 )
			{
		    	cout << "error meili!!" << endl;
				continue;
			}
		    else
			{
		    	b.meili=t8;
				break;
			}
		}
	}
	if( a == 'I' )
	{
		char t9;
		while(1)
		{
		    cin >> t9;
		    if ( t9<0 || t9 >100 )
			{
		    	cout << "error m_speed!!" << endl;
				continue;
			}
		    else
			{
		    	b.m_speed=t9;
				break;
			}
		}
	}
	if( a == 'J' )
	{
		char t10;
		while(1)
		{
		    cin >> t10;
		    if ( t10<0 || t10 >100 )
			{
		    	cout << "error h_speed!!" << endl;
				continue;
			}
		    else
			{
		    	b.h_speed=t10;
				break;
			}
		}
	}
	if( a == 'K' )
	{
		char t11;
		while(1)
		{
		    cin >> t11;
		    if ( t11<0 || t11 >100 )
			{
		    	cout << "error h_extent!!" << endl;
				continue;
			}
		    else
			{
		    	b.h_extent=t11;
				break;
			}
		}
	}
	if( a == 'L' )
	{
		short t12;
		while(1)
		{
		    cin >> t12;
		    if ( t12<0 || t12 >2000 )
			{
		    	cout << "error h_strength!!" << endl;
				continue;
			}
		    else
			{
		    	b.h_strength=t12;
				break;
			}
		}
	}
	if( a == 'M' )
	{
		short t13;
		while(1)
		{
		    cin >> t13;
		    if ( t13<0 || t13 >2000 )
			{
		    	cout << "error f_strength!!" << endl;
				continue;
			}
		    else
			{
		    	b.f_strength=t13;
				break;
			}
		}
	}
	if( a == 'N' )
	{
		char t14;
		while(1)
		{
		    cin >> t14;
		    if ( t14<0 || t14 >100 )
			{
		    	cout << "error minjie!!" << endl;
				continue;
			}
		    else
			{
		    	b.minjie=t14;
				break;
			}
		}
	}
	if( a == 'O' )
	{
		char t15;
		while(1)
		{
		    cin >> t15;
		    if ( t15<0 || t15 >100 )
			{
		    	cout << "error intellege!!" << endl;
				continue;
			}
		    else
			{
		    	b.intellege=t15;
				break;
			}
		}
	}
	if( a == 'P' )
	{
		char t16;
		while(1)
		{
		    cin >> t16;
		    if ( t16<0 || t16 >100 )
			{
		    	cout << "error experience!!" << endl;
				continue;
			}
		    else
			{
		    	b.experience=t16;
				break;
			}
		}
	}
	if( a == 'Q' )
	{
		char t17;
		while(1)
		{
		    cin >> t17;
		    if ( t17<0 || t17 >100 )
			{
		    	cout << "error state!!" << endl;
				continue;
			}
		    else
			{
		    	b.state=t17;
				break;
			}
		}
	}
	if( a == 'R' )
	{
		short t18;
		while(1)
		{
		    cin >> t18;
		    if ( t18<0 || t18 >10000 )
			{
		    	cout << "error mofa!!" << endl;
				continue;
			}
		    else
			{
		    	b.mofa=t18;
				break;
			}
		}
	}
	if( a == 'S' )
	{
		char t19;
		while(1)
		{
		    cin >> t19;
		    if ( t19<0 || t19 >100 )
			{
		    	cout << "error haomo!!" << endl;
				continue;
			}
		    else
			{
		    	b.haomo=t19;
				break;
			}
		}
	}
	if( a == 'T' )
	{
		char t20;
		while(1)
		{
		    cin >> t20;
		    if ( t20<0 || t20 >100 )
			{
		    	cout << "error moshang!!" << endl;
				continue;
			}
		    else
			{
		    	b.moshang=t20;
				break;
			}
		}
	}
	if( a == 'U' )
	{
		char t21;
		while(1)
		{
		    cin >> t21;
		    if ( t21<0 || t21 >100 )
			{
		    	cout << "error mingzhong!!" << endl;
				continue;
			}
		    else
			{
		    	b.mingzhong=t21;
				break;
			}
		}
	}
	if( a == 'V' )
	{
		char t22;
		while(1)
		{
		    cin >> t22;
		    if ( t22<0 || t22 >100 )
			{
		    	cout << "error mofang!!" << endl;
				continue;
			}
		    else
			{
		    	b.mofang=t22;
				break;
			}
		}
	}
	if( a == 'W' )
	{
		char t23;
		while(1)
		{
		    cin >> t23;
		    if ( t23<0 || t23 >100 )
			{
		    	cout << "error baoji!!" << endl;
				continue;
			}
		    else
			{
		    	b.baoji=t23;
				break;
			}
		}
	}
	if( a == 'X' )
	{
		char t24;
		while(1)
		{
		    cin >> t24;
		    if ( t24<0 || t24 >100 )
			{
		    	cout << "error naili!!" << endl;
				continue;
			}
		    else
			{
		    	b.naili=t24;
				break;
			}
		}
	}

}
int main()
{
	game s1;
	fstream jlc( "game.dat", ios::in | ios::binary);
	if(!jlc)
	{
		cerr << "open error!" << endl;
		abort();
	}
	jlc.read( (char *) &s1, sizeof( s1 ) );
	jlc.close();
	cout << setw(20) << setiosflags(ios::right) << "A玩家昵称：" << s1.name << endl;
	cout << setw(20) << setiosflags(ios::right) << "B生命值：" << s1.hp << endl;
	cout << setw(20) << setiosflags(ios::right) << "C力量值：" << s1.strength << endl;
	cout << setw(20) << setiosflags(ios::right) << "D体质值：" <<  s1.tizhi << endl;
	cout << setw(20) << setiosflags(ios::right) << "E灵巧值：" << s1.lingqiao << endl;
	cout << setw(20) << setiosflags(ios::right) << "F金钱值：" << s1.mon << endl;
	cout << setw(20) << setiosflags(ios::right) << "G名声值：" << s1.fame << endl;
	cout << setw(20) << setiosflags(ios::right) << "H魅力值：" << s1.meili << endl;
	cout << setw(20) << setiosflags(ios::right) << "I移动速度值：" << short(s1.m_speed) << endl;
	cout << setw(20) << setiosflags(ios::right) << "J攻击速度值：" << short(s1.h_speed) << endl;
	cout << setw(20) << setiosflags(ios::right) << "K攻击范围值：" << short(s1.h_extent) << endl;
	cout << setw(20) << setiosflags(ios::right) << "L攻击力值：" << s1.h_strength << endl;
	cout << setw(20) << setiosflags(ios::right) << "M防御力值：" << s1.f_strength << endl;
	cout << setw(20) << setiosflags(ios::right) << "N敏捷度值：" << short(s1.minjie) << endl;
	cout << setw(20) << setiosflags(ios::right) << "O智力值：" << short(s1.intellege) << endl;
	cout << setw(20) << setiosflags(ios::right) << "P经验值：" << short(s1.experience) << endl;
	cout << setw(20) << setiosflags(ios::right) << "Q等级值：" << short(s1.state) << endl;
	cout << setw(20) << setiosflags(ios::right) << "R魔法值：" << s1.mofa << endl;
	cout << setw(20) << setiosflags(ios::right) << "S消耗魔法值：" << short(s1.haomo) << endl;
	cout << setw(20) << setiosflags(ios::right) << "T魔法伤害力值：" << short(s1.moshang) << endl;
	cout << setw(20) << setiosflags(ios::right) << "U命中率值：" << short(s1.mingzhong) << endl;
	cout << setw(20) << setiosflags(ios::right) << "V魔法防御力值：" << short(s1.mofang) << endl;
	cout << setw(20) << setiosflags(ios::right) << "W暴击率值：" << short(s1.baoji) << endl;
	cout << setw(20) << setiosflags(ios::right) << "X耐力值：" << short(s1.naili) << endl;
	while( 1 )
	{
		cout << "请输入要转换的选项的代号(0表示选择结束）：";
		char ch;
		cin >> ch;
		if( ch == '0' )
			break;
		cout << "请输入替换的数据" << endl;
		change( ch, s1 );
	}
	fstream jlb( "game.dat", ios::out | ios::binary);
	jlb.write( (char *) &s1, 64);

	cout << setw(20) << setiosflags(ios::right) << "A玩家昵称：" << s1.name << endl;
	cout << setw(20) << setiosflags(ios::right) << "B生命值：" << s1.hp << endl;
	cout << setw(20) << setiosflags(ios::right) << "C力量值：" << s1.strength << endl;
	cout << setw(20) << setiosflags(ios::right) << "D体质值：" <<  s1.tizhi << endl;
	cout << setw(20) << setiosflags(ios::right) << "E灵巧值：" << s1.lingqiao << endl;
	cout << setw(20) << setiosflags(ios::right) << "F金钱值：" << s1.mon << endl;
	cout << setw(20) << setiosflags(ios::right) << "G名声值：" << s1.fame << endl;
	cout << setw(20) << setiosflags(ios::right) << "H魅力值：" << s1.meili << endl;
	cout << setw(20) << setiosflags(ios::right) << "I移动速度值：" << short(s1.m_speed) << endl;
	cout << setw(20) << setiosflags(ios::right) << "J攻击速度值：" << short(s1.h_speed) << endl;
	cout << setw(20) << setiosflags(ios::right) << "K攻击范围值：" << short(s1.h_extent) << endl;
	cout << setw(20) << setiosflags(ios::right) << "L攻击力值：" << s1.h_strength << endl;
	cout << setw(20) << setiosflags(ios::right) << "M防御力值：" << s1.f_strength << endl;
	cout << setw(20) << setiosflags(ios::right) << "N敏捷度值：" << short(s1.minjie) << endl;
	cout << setw(20) << setiosflags(ios::right) << "O智力值：" << short(s1.intellege) << endl;
	cout << setw(20) << setiosflags(ios::right) << "P经验值：" << short(s1.experience) << endl;
	cout << setw(20) << setiosflags(ios::right) << "Q等级值：" << short(s1.state) << endl;
	cout << setw(20) << setiosflags(ios::right) << "R魔法值：" << s1.mofa << endl;
	cout << setw(20) << setiosflags(ios::right) << "S消耗魔法值：" << short(s1.haomo) << endl;
	cout << setw(20) << setiosflags(ios::right) << "T魔法伤害力值：" << short(s1.moshang) << endl;
	cout << setw(20) << setiosflags(ios::right) << "U命中率值：" << short(s1.mingzhong) << endl;
	cout << setw(20) << setiosflags(ios::right) << "V魔法防御力值：" << short(s1.mofang) << endl;
	cout << setw(20) << setiosflags(ios::right) << "W暴击率值：" << short(s1.baoji) << endl;
	cout << setw(20) << setiosflags(ios::right) << "X耐力值：" << short(s1.naili) << endl;	

	jlb.close();
 	return 0;
}