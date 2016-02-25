//1252366 蒋凌超 电子一班

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct KFC
{
    char no;
    char *name;
    float price;
	int num;
};

struct SPECIAL
{
    char *item;
    char *prompt;
    float price;
};

int main()
{
	struct KFC n_menu[] = { 
		{'A', "香辣鸡腿堡", 15.0},
		{'B', "劲脆鸡腿堡", 15.0},
		{'C', "新奥尔良烤鸡腿堡", 15.5},
		{'D', "老北京鸡肉卷", 14.0},
		{'E', "川香嫩牛卷", 15.0},
		{'F', "吮指原味鸡", 9.0},
		{'G', "新奥尔良烤翅", 9.5},
		{'H', "香辣鸡翅", 8.5},
		{'I', "劲脆鸡米花", 10.0},
		{'J', "上校鸡块", 8.0},
		{'K', "薯条(小)", 7.0},
		{'L', "薯条(中)", 8.5},
		{'M', "薯条(大)", 10.0},
		{'N', "芙蓉鲜蔬汤", 6.0},
		{'O', "香甜粟米棒", 6.5},
		{'P', "土豆泥", 4.5},
		{'Q', "脆皮甜筒", 3.0},
		{'R', "百事可乐(小)", 6.0},
		{'S', "百事可乐(中)", 7.5},
		{'T', "百事可乐(大)", 9.0},
		{'U', "九珍", 9.5},
		{'V', "雪顶爱尔兰咖啡", 10.0},
		{'\0', NULL, 0}
	};

    struct SPECIAL s_menu[]={
		{"AKR", "香辣汉堡超值套餐", 25},
		{"FHFFHFGTFGOTT", "超值全家桶", 84},
		{"QQ", "脆皮甜筒第2 件半价", 4.5},
		{"LLL", "中薯买2 送1", 17},
		{NULL, NULL, 0}
	};
	int m=0, i;
	for( i=0; n_menu[i].no!=0; i++)
	{
		cout << setw(2) << n_menu[i].no << ' ' << setiosflags(ios::left) << setw(20) << n_menu[i].name << setw(10) << n_menu[i].price;
		m++;
        if( m%2==1 )
			cout << "|     ";
		else
			cout << endl;
	}
	cout << endl;
	cout << "【优惠信息】：" << endl;
	cout << s_menu[0].prompt << "=香辣鸡腿堡+薯条(小)+百事可乐(小)=25" << endl;
    cout << s_menu[1].prompt << "=吮指原味鸡*5+新奥尔良烤翅*2+香辣鸡翅*2+香甜粟米棒+百事可乐(大)*3=84" << endl;
	cout << s_menu[2].prompt << "=脆皮甜筒*2=4.5" << endl;
	cout << s_menu[3].prompt << "=薯条(中)*3=17" << endl;
	cout << endl;
	cout << "【输入规则说明】" << endl;
	cout << "AkR=香辣鸡腿堡+薯条(小)+百事可乐(小) / ahaah=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl;
	char list[1000];
	while(1)
	{
		cout << "请点单：";
		gets(list);

		if(list==NULL)
			continue;
	    for( i=0; i<strlen(list); i++)
		{
		    if( list[i]=='0' )
		    	return 0;
			else if( !( list[i]>='A' && list[i]<='V' || list[i]>='a' && list[i]<='v'))
			{
				cout << "输入错误，请重新输入" << endl;
				break;
			}
	    	else
		        for( int j=0; ; j++)
			        if( list[i]==n_menu[j].no || list[i]==n_menu[j].no+32 )
					{
			    	    n_menu[j].num++;
			    		break;
					}
		}
		if( i<strlen(list) || strlen(list)==0 )
			continue;
    	cout << "您的点餐=";
    	int h=0;
    	float sum=0;
    	for(  i=0; n_menu[i].no!=0; i++)
		{
		    if( n_menu[i].num!=0 )
			{
	    		h++;
	    		if( h>1 )
	    			cout << '+';
			}
	    	if( n_menu[i].num==1 )
			{
	    		cout << n_menu[i].name;
	    		sum += n_menu[i].price;
			}
	    	else if( n_menu[i].num!=0 )
			{
	    		cout << n_menu[i].name << '*' << n_menu[i].num;
        		sum += n_menu[i].price*n_menu[i].num;
			}
		}
    	int min;
     	min=( n_menu[0].num < n_menu[10].num)?n_menu[0].num:n_menu[10].num;
    	min=( min < n_menu[17].num)?min:n_menu[17].num;
    	sum -= min*(n_menu[0].price+n_menu[10].price+n_menu[17].price);
    	sum += min*25;
    	min=( n_menu[5].num/5 < n_menu[6].num/2)?n_menu[5].num/5:n_menu[6].num/2;
        min=( min < n_menu[7].num/2)?min:n_menu[7].num/2;
    	min=( min < n_menu[14].num)?min:n_menu[14].num;
    	min=( min < n_menu[19].num/3)?min:n_menu[19].num/3;
    	sum -= min*(n_menu[5].price*5+n_menu[6].price*2+n_menu[7].price*2+n_menu[14].price+n_menu[19].price*3);
    	sum += min*84;
    	sum -= n_menu[16].num/2*n_menu[16].price;
    	sum += n_menu[16].num/2*4.5;
    	sum -= n_menu[11].num/3*n_menu[11].price;
    	cout << endl;
    	cout << "共计：" << sum << "元" << endl;
		for(  i=0; n_menu[i].no!=0; i++)
			n_menu[i].num=0;
    	cout << "点单完成，请按任意键继续" << endl;
		cout << endl;
	}

	return 0;
}
