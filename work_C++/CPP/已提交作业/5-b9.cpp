// 1252366 蒋凌超 电子一班

#include <iostream>
#include <cstring>
using namespace std;

char chistr[]="零\0壹\0贰\0叁\0肆\0伍\0陆\0柒\0捌\0玖";
char money[]="拾\0佰\0仟\0万\0亿\0圆\0角\0分\0整";
char result[256];
int i=0;

void daxie(int num, int flag_of_zero, char a[], char b[])//这个不算后面的指针吧
{
	switch(num) {
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

int main()
{
	double s;
	int t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
	cout << "Please enter a float number" << " << 's' << " << "between 0.01 and 100 hundred million as the price" << endl;
   	while(1)
	{
		cin.clear();
		cin >> s;
		if(s<1e10 && s>=0)
		{
			break;
		}
		else
			cout << "Input error,enter again" << endl;
	}
	
	t1=s/1e9;
	t2=s/1e8-t1*10;
	t3=s/1e7-t1*100-t2*10;
	t4=s/1e6-t1*1000-t2*100-t3*10;
	t5=s/1e5-t1*1e4-t2*1e3-t3*100-t4*10;
	t6=s/1e4-t1*1e5-t2*1e4-t3*1e3-t4*100-t5*10;
	t7=s/1e3-t1*1e6-t2*1e5-t3*1e4-t4*1e3-t5*1e2-t6*10;
	t8=s/100-t1*1e7-t2*1e6-t3*1e5-t4*1e4-t5*1e3-t6*1e2-t7*10;
	t9=s/10-t1*1e8-t2*1e7-t3*1e6-t4*1e5-t5*1e4-t6*1e3-t7*1e2-t8*10;
	t10=s-t1*1e9-t2*1e8-t3*1e7-t4*1e6-t5*1e5-t6*1e4-t7*1e3-t8*1e2-t9*10;
	t12=(s*10-int(s*10)+0.0005)*10;
    t11=((s-int(s)+0.0005)*100-t12)/10;

	daxie( t1, 0, result, chistr);
	if(t1!=0)
		strcat( result, money);

	daxie( t2, 0, result, chistr);
	if(t1!=0 || t2!=0)
		strcat( result, &money[12]);

	if(t1==0 && t2==0 && (t4!=0 || t5!=0 || t6!=0))
	{
		daxie( t3, 0, result, chistr);
		if(t3!=0)
			strcat( result, &money[6]);
	}
	else if(t4==0 && t5==0 && t6==0)
	{
		daxie( t3, 0, result, chistr);
		if(t3!=0)
		{
			strcat( result, &money[6]);
			strcat( result, &money[9]);
		}
	}
	else
	{
		daxie( t3, 1, result, chistr);
		if(t3!=0)
			strcat( result, &money[6]);
	}

	if(t3==0 && (t5!=0 || t6!=0))
    {
		daxie( t4, 0, result, chistr);
		if(t4!=0)
			strcat( result, &money[3]);
	}
	else if(t5==0 && t6==0)
	{
		daxie( t4, 0, result, chistr);
		if(t4!=0)
		{
			strcat( result, &money[3]);
			strcat( result, &money[9]);
		}
	}
	else
	{
		daxie( t4, 1, result, chistr);
		if(t4!=0)
			strcat( result, &money[3]);
	}

	if(t4==0 && t6!=0)
	{
		daxie( t5, 0, result, chistr);
		if(t5!=0)
			strcat( result, money);
	}
	else if(t6==0)
	{
		daxie( t5, 0, result, chistr);
		if(t5!=0)
		{
			strcat( result, money);
			strcat( result, &money[9]);
		}
	}
	else
	{
		daxie( t5, 1, result, chistr);
		if(t5!=0)
			strcat( result, money);
	}

	daxie( t6, 0, result, chistr);
	if(t6!=0)
		strcat( result, &money[9]);

	if(t8==0 && t9==0 && t10==0 || t1==0 && t2==0 && t3==0 && t4==0 && t5==0 && t6==0)
	{
		daxie( t7, 0, result, chistr);
		if(t7!=0)
			strcat( result, &money[6]);
	}
	else
	{
		daxie( t7, 1, result, chistr);
		if(t7!=0)
			strcat( result, &money[6]);
	}

	if(t7==0)
	{
		daxie( t8, 0, result, chistr);
		if(t8!=0)
			strcat( result, &money[3]);
	}
	else
	{
		daxie( t8, 1, result, chistr);
		if(t8!=0)
			strcat( result, &money[3]);
	}

	if(t8==0 && t10!=0 || t10==0)
	{
		daxie( t9, 0, result, chistr);
		if(t9!=0)
			strcat( result, money);
	}
	else
	{
		daxie( t9, 1, result, chistr);
		if(t9!=0)
			strcat( result, money);
	}

	daxie( t10, 0, result, chistr);

	if(t11==0 && t12==0)
	{
		strcat( result, &money[15]);
		strcat( result, &money[24]);
	}
	else if(int(s)==0)
	{
		daxie( t11, 0, result, chistr);
		if(t11!=0)
			strcat( result, &money[18]);
	}
	else
	{
		strcat( result, &money[15]);
		daxie( t11, 1, result, chistr);
		if(t11!=0)
			strcat( result, &money[18]);
	}

	daxie( t12, 0, result, chistr);
	if(t12!=0)
	    strcat( result, &money[21]);
	cout << result << endl;

	return 0;
}
