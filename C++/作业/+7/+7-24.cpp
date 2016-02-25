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
	void show()
	{
		cout << setw(20) << setiosflags(ios::right) << "1玩家昵称：" << name << endl;
	    cout << setw(20) << setiosflags(ios::right) << "B生命值：" << hp << endl;
	    cout << setw(20) << setiosflags(ios::right) << "C力量值：" << strength << endl;
	    cout << setw(20) << setiosflags(ios::right) << "D体质值：" <<  tizhi << endl;
    	cout << setw(20) << setiosflags(ios::right) << "E灵巧值：" << lingqiao << endl;
    	cout << setw(20) << setiosflags(ios::right) << "F金钱值：" << mon << endl;
    	cout << setw(20) << setiosflags(ios::right) << "G名声值：" << fame << endl;
    	cout << setw(20) << setiosflags(ios::right) << "H魅力值：" << meili << endl;
    	cout << setw(20) << setiosflags(ios::right) << "I移动速度值：" << short(m_speed) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "J攻击速度值：" << short(h_speed) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "K攻击范围值：" << short(h_extent) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "L攻击力值：" << h_strength << endl;
    	cout << setw(20) << setiosflags(ios::right) << "M防御力值：" << f_strength << endl;
    	cout << setw(20) << setiosflags(ios::right) << "N敏捷度值：" << short(minjie) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "O智力值：" << short(intellege) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "P经验值：" << short(experience) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "Q等级值：" << short(state) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "R魔法值：" << mofa << endl;
    	cout << setw(20) << setiosflags(ios::right) << "S消耗魔法值：" << short(haomo) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "T魔法伤害力值：" << short(moshang) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "U命中率值：" << short(mingzhong) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "V魔法防御力值：" << short(mofang) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "W暴击率值：" << short(baoji) << endl;
    	cout << setw(20) << setiosflags(ios::right) << "X耐力值：" << short(naili) << endl;
	}
};

void change( char a, game &b )
{
	if( a == 'A' )
	{
		char t1[16];
	    cin >> t1;
	    if ( strlen(t1)>15 || strlen(t1)==0 )
	    	cout << "error name!!" << endl;
	    else
	    	strcpy( b.name, t1 );
	}
	if( a == 'B' )
	{
		short t2;
	    cin >> t2;
	    if ( t2<0 || t2 >10000 )
	    	cout << "error hp!!" << endl;
	    else
	    	b.hp=t2;
	}
	if( a == 'C' )
	{
		short t3;
	    cin >> t3;
	    if ( t3<0 || t3 >10000 )
	    	cout << "error strength!!" << endl;
	    else
	    	b.strength=t3;
	}
	if( a == 'D' )
	{
		short t4;
	    cin >> t4;
	    if ( t4<0 || t4 >8192 )
	    	cout << "error tizhi!!" << endl;
	    else
	    	b.tizhi=t4;
	}
	if( a == 'E' )
	{
		short t5;
	    cin >> t5;
	    if ( t5<0 || t5 >1024 )
	    	cout << "error lingqiao!!" << endl;
	    else
	    	b.lingqiao=t5;
	}
    if( a == 'F' )
	{
		int t6;
	    cin >> t6;
	    if ( t6<0 || t6 >100000000 )
	    	cout << "error mon!!" << endl;
		else
	    	b.mon=t6;
	}
	if( a == 'G' )
	{
		int t7;
	    cin >> t7;
		if ( t7<0 || t7 >1000000 )
	    	cout << "error fame!!" << endl;
	    else
			b.fame=t7;
	}
	if( a == 'H' )
	{
		int t8;
	    cin >> t8;
	    if ( t8<0 || t8 >1000000 )
			cout << "error meili!!" << endl;
		else
			b.meili=t8;
	}
	if( a == 'I' )
	{
		char t9;
		cin >> t9;
	    if ( t9<0 || t9 >100 )
	    	cout << "error m_speed!!" << endl;
		else
	    	b.m_speed=t9;
	}
	if( a == 'J' )
	{
		char t10;
		cin >> t10;
		if ( t10<0 || t10 >100 )
	    	cout << "error h_speed!!" << endl;
	    else
			b.h_speed=t10;
	}
	if( a == 'K' )
	{
		char t11;
	    cin >> t11;
		if ( t11<0 || t11 >100 )
	    	cout << "error h_extent!!" << endl;
	    else
			b.h_extent=t11;
	}
	if( a == 'L' )
	{
		short t12;
	    cin >> t12;
		if ( t12<0 || t12 >2000 )
	    	cout << "error h_strength!!" << endl;
	    else
			b.h_strength=t12;
	}
	if( a == 'M' )
	{
		short t13;
	    cin >> t13;
		if ( t13<0 || t13 >2000 )
	    	cout << "error f_strength!!" << endl;
	    else
			b.f_strength=t13;
	}
	if( a == 'N' )
	{
		char t14;
		cin >> t14;
		if ( t14<0 || t14 >100 )
	    	cout << "error minjie!!" << endl;
		else
	    	b.minjie=t14;
	}
	if( a == 'O' )
	{
		char t15;
		cin >> t15;
	    if ( t15<0 || t15 >100 )
	    	cout << "error intellege!!" << endl;
		else
	    	b.intellege=t15;
	}
	if( a == 'P' )
	{
		char t16;
	    cin >> t16;
		if ( t16<0 || t16 >100 )
	    	cout << "error experience!!" << endl;
	    else
			b.experience=t16;
	}
	if( a == 'Q' )
	{
		char t17;
	    cin >> t17;
		if ( t17<0 || t17 >100 )
		   	cout << "error state!!" << endl;
	    else
	    	b.state=t17;
	}
	if( a == 'R' )
	{
		short t18;
		cin >> t18;
	    if ( t18<0 || t18 >10000 )
	    	cout << "error mofa!!" << endl;
		else
	    	b.mofa=t18;
	}
	if( a == 'S' )
	{
		char t19;
	    cin >> t19;
	    if ( t19<0 || t19 >100 )
			cout << "error haomo!!" << endl;
		else
	    	b.haomo=t19;
	}
	if( a == 'T' )
	{
		char t20;
	    cin >> t20;
	    if ( t20<0 || t20 >100 )
		   	cout << "error moshang!!" << endl;
		else
	    	b.moshang=t20;
	}
	if( a == 'U' )
	{
		char t21;
	    cin >> t21;
	    if ( t21<0 || t21 >100 )
	    	cout << "error mingzhong!!" << endl;
	    else
	    	b.mingzhong=t21;
	}
	if( a == 'V' )
	{
		char t22;
        cin >> t22;
        if ( t22<0 || t22 >100 )
		    cout << "error mofang!!" << endl;
		else
		    b.mofang=t22;
	}
	if( a == 'W' )
	{
		char t23;
        cin >> t23;
	    if ( t23<0 || t23 >100 )
		    cout << "error baoji!!" << endl;
	    else
		   	b.baoji=t23;
	}
	if( a == 'X' )
	{
		char t24;
		cin >> t24;
		if ( t24<0 || t24 >100 )
			cout << "error naili!!" << endl;
		else
		   	b.naili=t24;
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
	s1.show();
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

	s1.show();	

	jlb.close();
 	return 0;
}