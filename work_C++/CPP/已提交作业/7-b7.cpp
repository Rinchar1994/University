//1252366 ���賬 ����һ��

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
		{'A', "�������ȱ�", 15.0},
		{'B', "���༦�ȱ�", 15.0},
		{'C', "�°¶��������ȱ�", 15.5},
		{'D', "�ϱ��������", 14.0},
		{'E', "������ţ��", 15.0},
		{'F', "˱ָԭζ��", 9.0},
		{'G', "�°¶�������", 9.5},
		{'H', "��������", 8.5},
		{'I', "���༦�׻�", 10.0},
		{'J', "��У����", 8.0},
		{'K', "����(С)", 7.0},
		{'L', "����(��)", 8.5},
		{'M', "����(��)", 10.0},
		{'N', "ܽ��������", 6.0},
		{'O', "�������װ�", 6.5},
		{'P', "������", 4.5},
		{'Q', "��Ƥ��Ͳ", 3.0},
		{'R', "���¿���(С)", 6.0},
		{'S', "���¿���(��)", 7.5},
		{'T', "���¿���(��)", 9.0},
		{'U', "����", 9.5},
		{'V', "ѩ������������", 10.0},
		{'\0', NULL, 0}
	};

    struct SPECIAL s_menu[]={
		{"AKR", "����������ֵ�ײ�", 25},
		{"FHFFHFGTFGOTT", "��ֵȫ��Ͱ", 84},
		{"QQ", "��Ƥ��Ͳ��2 �����", 4.5},
		{"LLL", "������2 ��1", 17},
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
	cout << "���Ż���Ϣ����" << endl;
	cout << s_menu[0].prompt << "=�������ȱ�+����(С)+���¿���(С)=25" << endl;
    cout << s_menu[1].prompt << "=˱ָԭζ��*5+�°¶�������*2+��������*2+�������װ�+���¿���(��)*3=84" << endl;
	cout << s_menu[2].prompt << "=��Ƥ��Ͳ*2=4.5" << endl;
	cout << s_menu[3].prompt << "=����(��)*3=17" << endl;
	cout << endl;
	cout << "���������˵����" << endl;
	cout << "AkR=�������ȱ�+����(С)+���¿���(С) / ahaah=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl;
	char list[1000];
	while(1)
	{
		cout << "��㵥��";
		gets(list);

		if(list==NULL)
			continue;
	    for( i=0; i<strlen(list); i++)
		{
		    if( list[i]=='0' )
		    	return 0;
			else if( !( list[i]>='A' && list[i]<='V' || list[i]>='a' && list[i]<='v'))
			{
				cout << "�����������������" << endl;
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
    	cout << "���ĵ��=";
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
    	cout << "���ƣ�" << sum << "Ԫ" << endl;
		for(  i=0; n_menu[i].no!=0; i++)
			n_menu[i].num=0;
    	cout << "�㵥��ɣ��밴���������" << endl;
		cout << endl;
	}

	return 0;
}
