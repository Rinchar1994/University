/*1252337 Íõ¼Ñç÷ µç×ÓÒ»°à*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long double a;
	cin>>a;
	cout<<setiosflags(ios::fixed)<<setprecision(10);
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
	switch (x10)
	{
	    case 0:break;
    	case 1:cout<<"Ò¼Ê°";break;
		case 2:cout<<"·¡Ê°";break;
		case 3:cout<<"ÈşÊ°";break;
		case 4:cout<<"ËÁÊ°";break;
		case 5:cout<<"ÎéÊ°";break;
		case 6:cout<<"Â½Ê°";break;
		case 7:cout<<"ÆâÊ°";break;
		case 8:cout<<"°ÆÊ°";break;
	    case 9:cout<<"¾ÁÊ°";break;
	}
	switch (x9)
	{
	    case 0:
			if (x10==0)
				cout<<"";
			else cout<<"ÒÚ";
			break;
	    case 1:cout<<"Ò¼ÒÚ";break;
		case 2:cout<<"·¡ÒÚ";break;
		case 3:cout<<"ÈşÒÚ";break;
		case 4:cout<<"ËÁÒÚ";break;
		case 5:cout<<"ÎéÒÚ";break;
		case 6:cout<<"Â½ÒÚ";break;
		case 7:cout<<"ÆâÒÚ";break;
		case 8:cout<<"°ÆÒÚ";break;
		case 9:cout<<"¾ÁÒÚ";break;
	}
	switch (x8)
	{
	    case 0:
			if (x10==0&&x9==0)
				cout<<"";
			else if (x7==0&&x6==0&&x5==0)
				cout<<"";
			else cout<<"Áã";
			break;
		case 1:cout<<"Ò¼Çª";break;
		case 2:cout<<"·¡Çª";break;
		case 3:cout<<"ÈşÇª";break;
		case 4:cout<<"ËÁÇª";break;
		case 5:cout<<"ÎéÇª";break;
		case 6:cout<<"Â½Çª";break;
		case 7:cout<<"ÆâÇª";break;
		case 8:cout<<"°ÆÇª";break;
		case 9:cout<<"¾ÁÇª";break;
	}
	switch (x7)
	{
	    case 0:
			if (x8==0)
				cout<<"";
			else cout<<"Áã";
			break;
		case 1:cout<<"Ò¼°Û";break;
		case 2:cout<<"·¡°Û";break;
		case 3:cout<<"Èş°Û";break;
		case 4:cout<<"ËÁ°Û";break;
		case 5:cout<<"Îé°Û";break;
		case 6:cout<<"Â½°Û";break;
		case 7:cout<<"Æâ°Û";break;
		case 8:cout<<"°Æ°Û";break;
		case 9:cout<<"¾Á°Û";break;
	}
	switch (x6)
	{
	    case 0:
			if (x7==0)
				cout<<"";
			else if (x5==0)
				cout<<"";
			else cout<<"Áã";
			break;
		case 1:cout<<"Ò¼Ê°";break;
		case 2:cout<<"·¡Ê°";break;
		case 3:cout<<"ÈşÊ°";break;
		case 4:cout<<"ËÁÊ°";break;
		case 5:cout<<"ÎéÊ°";break;
		case 6:cout<<"Â½Ê°";break;
		case 7:cout<<"ÆâÊ°";break;
		case 8:cout<<"°ÆÊ°";break;
		case 9:cout<<"¾ÁÊ°";break;
	}
	switch (x5)
	{
	    case 0:
			cout<<"";
			break;
		case 1:cout<<"Ò¼";break;
		case 2:cout<<"·¡";break;
		case 3:cout<<"Èş";break;
		case 4:cout<<"ËÁ";break;
		case 5:cout<<"Îé";break;
		case 6:cout<<"Â½";break;
		case 7:cout<<"Æâ";break;
		case 8:cout<<"°Æ";break;
		case 9:cout<<"¾Á";break;
	}
	if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0)
		cout<<"";
	else if ((x10!=0||x9!=0)&&x8==0&&x7==0&&x6==0&&x5==0)
		cout<<"";
	else cout<<"Íò";
	switch (x4)
	{
	    case 0:
			if (x3==0&&x2==0&&x1==0)
				cout<<"";
			else if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0)
				cout<<"";
			else cout<<"Áã";
		    break;		
		case 1:cout<<"Ò¼Çª";break;
		case 2:cout<<"·¡Çª";break;
		case 3:cout<<"ÈşÇª";break;
		case 4:cout<<"ËÁÇª";break;
		case 5:cout<<"ÎéÇª";break;
		case 6:cout<<"Â½Çª";break;
		case 7:cout<<"ÆâÇª";break;
		case 8:cout<<"°ÆÇª";break;
		case 9:cout<<"¾ÁÇª";break;
	}
	switch (x3)
	{
	    case 0:
			if (x4==0||(x2==0&&x1==0))
				cout<<"";
			else cout<<"Áã";
		    break;	
		case 1:cout<<"Ò¼°Û";break;
		case 2:cout<<"·¡°Û";break;
		case 3:cout<<"Èş°Û";break;
		case 4:cout<<"ËÁ°Û";break;
		case 5:cout<<"Îé°Û";break;
		case 6:cout<<"Â½°Û";break;
		case 7:cout<<"Æâ°Û";break;
		case 8:cout<<"°Æ°Û";break;
		case 9:cout<<"¾Á°Û";break;
	}
	switch (x2)
	{
	    case 0:
			if (x3==0||x1==0)
				cout<<"";
			else cout<<"Áã";
		    break;		
		case 1:cout<<"Ò¼Ê°";break;
		case 2:cout<<"·¡Ê°";break;
		case 3:cout<<"ÈşÊ°";break;
		case 4:cout<<"ËÁÊ°";break;
		case 5:cout<<"ÎéÊ°";break;
		case 6:cout<<"Â½Ê°";break;
		case 7:cout<<"ÆâÊ°";break;
		case 8:cout<<"°ÆÊ°";break;
		case 9:cout<<"¾ÁÊ°";break;
	}
	switch (x1)
	{
	    case 0:
			cout<<"";
			break;
		case 1:cout<<"Ò¼";break;
		case 2:cout<<"·¡";break;
		case 3:cout<<"Èş";break;
		case 4:cout<<"ËÁ";break;
		case 5:cout<<"Îé";break;
		case 6:cout<<"Â½";break;
		case 7:cout<<"Æâ";break;
		case 8:cout<<"°Æ";break;
		case 9:cout<<"¾Á";break;
	}
	if (x0==0&&x==0)
		cout<<"Õû";
	else if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0&&x4==0&&x3==0&&x2==0&&x1==0)
		cout<<"";
	else cout<<"Ô²";
	switch (x0)
	{
		case 0:
			if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0&&x4==0&&x3==0&&x2==0&&x1==0)
				cout<<"";
			else if (x!=0)
				cout<<"Áã";
			else cout<<"";
		    break;		
		case 1:cout<<"Ò¼½Ç";break;
		case 2:cout<<"·¡½Ç";break;
		case 3:cout<<"Èş½Ç";break;
		case 4:cout<<"ËÁ½Ç";break;
		case 5:cout<<"Îé½Ç";break;
		case 6:cout<<"Â½½Ç";break;
		case 7:cout<<"Æâ½Ç";break;
		case 8:cout<<"°Æ½Ç";break;
		case 9:cout<<"¾Á½Ç";break;
	}
	switch (x)
	{
		case 0:
			if (x0!=0)
				cout<<"Õû";
			else cout<<"";
		    break;		
		case 1:cout<<"Ò¼·Ö";break;
		case 2:cout<<"·¡·Ö";break;
		case 3:cout<<"Èş·Ö";break;
		case 4:cout<<"ËÁ·Ö";break;
		case 5:cout<<"Îé·Ö";break;
		case 6:cout<<"Â½·Ö";break;
		case 7:cout<<"Æâ·Ö";break;
		case 8:cout<<"°Æ·Ö";break;
		case 9:cout<<"¾Á·Ö";break;
	}
    return 0;

}

