/*1252337 电子一班 王佳琪*/

#include <iostream>
#include <cstring>
using namespace std;
char chistr[]="零\0壹\0贰\0叁\0肆\0伍\0陆\0柒\0捌\0玖";
char m[]="圆\0角\0分\0整\0拾\0佰\0仟\0万\0亿";
char result[256];
int i=0;
int main()
{
	void daxie(int n, int flag_of_zero, char a[], char b[]);
	long double a;
	cout<<"请输入数字[0,100亿)，保留小数点后两位"<<endl; 
   	while(1)
	{
		cin >> a;
		if(a<1e10&&a>=0)
			break;
		else
			cout<<"输入错误，重新输入"<<endl;
	}
	
	int x10=(int)(a/1000000000);
	int x9=(int)((a-((int)(a/1000000000))*(long double)1000000000)/100000000);
	int x8=(int)((a-((int)(a/100000000))*(long double)100000000)/10000000);
	int x7=(int)((a-((int)(a/10000000))*(long double)10000000)/1000000);
	int x6=(int)((a-((int)(a/1000000))*(long double)1000000)/100000);
	int x5=(int)((a-((int)(a/100000))*(long double)100000)/10000);
	int x4=(int)((a-((int)(a/10000))*(long double)10000)/1000);
	int x3=(int)((a-((int)(a/1000))*(long double)1000)/100);
	int x2=(int)((a-((int)(a/100))*(long double)100)/10);
    int x1=(int)((a-((int)(a/10))*(long double)10)/1);
	int x0=(int)(((a-(long int)a)+0.00001)*10);
	int x=(int)((a+0.000001-(long int)a)*100)-(int)(((a-(long int)a)+0.00001)*10)*10;
    daxie( x10, 0, result, chistr);
	if(x10!=0)
		strcat( result, "拾");

	daxie( x9, 0, result, chistr);
	if(x10!=0 || x9!=0)
		strcat( result, "亿");

	if(x10==0 && x9==0 && (x7!=0 || x6!=0 || x5!=0))
	{
		daxie( x8, 0, result, chistr);
		if(x8!=0)
			strcat( result, "仟");
	}
	else if(x7==0 && x6==0 && x5==0)
	{
		daxie( x8, 0, result, chistr);
		if(x8!=0)
		{
			strcat( result, "仟");
			strcat( result, "万");
		}
	}
	else
	{
		daxie( x8, 1, result, chistr);
		if(x8!=0)
			strcat( result, "仟");
	}

	if(x8==0 && (x6!=0 || x5!=0))
    {
		daxie( x7, 0, result, chistr);
		if(x7!=0)
			strcat( result, "佰");
	}
	else if(x6==0 && x5==0)
	{
		daxie( x7, 0, result, chistr);
		if(x7!=0)
		{
			strcat( result, "佰");
			strcat( result, "万");
		}
	}
	else
	{
		daxie( x7, 1, result, chistr);
		if(x7!=0)
			strcat( result, "佰");
	}

	if(x7==0 && x5!=0)
	{
		daxie( x6, 0, result, chistr);
		if(x6!=0)
			strcat( result, "拾");
	}
	else if(x5==0)
	{
		daxie( x6, 0, result, chistr);
		if(x6!=0)
		{
			strcat( result, "拾");
			strcat( result, "万");
		}
	}
	else
	{
		daxie( x6, 1, result, chistr);
		if(x6!=0)
			strcat( result, "拾");
	}

	daxie( x5, 0, result, chistr);
	if(x5!=0)
		strcat( result, "万");

	if(x3==0 && x2==0 && x1==0 || x10==0 && x9==0 && x8==0 && x7==0 && x6==0 && x5==0)
	{
		daxie( x4, 0, result, chistr);
		if(x4!=0)
			strcat( result, "仟");
	}
	else
	{
		daxie( x4, 1, result, chistr);
		if(x4!=0)
			strcat( result, "仟");
	}

	if(x4==0)
	{
		daxie( x3, 0, result, chistr);
		if(x3!=0)
			strcat( result, "佰");
	}
	else
	{
		daxie( x3, 1, result, chistr);
		if(x3!=0)
			strcat( result, "佰");
	}

	if(x3==0 && x1!=0 || x1==0)
	{
		daxie( x2, 0, result, chistr);
		if(x2!=0)
			strcat( result,"拾");
	}
	else
	{
		daxie( x2, 1, result, chistr);
		if(x2!=0)
			strcat( result, "拾");
	}

	daxie( x1, 0, result, chistr);

	if(x0==0 && x==0)
	{
		strcat( result, "圆");
		strcat( result, "整");
	}
	else if(int(a)==0)
	{
		daxie( x0, 0, result, chistr);
		if(x0!=0)
			strcat( result, "角");
	}
	else
	{
		strcat( result, "圆");
		daxie( x0, 1, result, chistr);
		if(x0!=0)
			strcat( result, "角");
	}

	daxie( x, 0, result, chistr);
	if(x!=0)
	    strcat( result, "分");
	cout << result << endl;
	return 0;
}

void daxie(int n, int flag_of_zero, char a[], char b[])
{
	switch(n) {
		case 0:
			if (flag_of_zero)
				strcat(a, b);
			break;
		case 1:
			strcat(a, &b[3]);
			break;
		case 2:
			strcat(a, &b[6]);
			break;
		case 3:
			strcat(a, &b[9]);
			break;
		case 4:
			strcat(a, &b[12]);
			break;
		case 5:
			strcat(a, &b[15]);
			break;
		case 6:
			strcat(a, &b[18]);
			break;
		case 7:
			strcat(a, &b[21]);
			break;
		case 8:
			strcat(a, &b[24]);
			break;
		case 9:
			strcat(a, &b[27]);
			break;
		default:
			cout << "error";
			break;
		}
}
