/*1252337 ������ ����һ��*/
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
    	case 1:cout<<"Ҽʰ";break;
		case 2:cout<<"��ʰ";break;
		case 3:cout<<"��ʰ";break;
		case 4:cout<<"��ʰ";break;
		case 5:cout<<"��ʰ";break;
		case 6:cout<<"½ʰ";break;
		case 7:cout<<"��ʰ";break;
		case 8:cout<<"��ʰ";break;
	    case 9:cout<<"��ʰ";break;
	}
	switch (x9)
	{
	    case 0:
			if (x10==0)
				cout<<"";
			else cout<<"��";
			break;
	    case 1:cout<<"Ҽ��";break;
		case 2:cout<<"����";break;
		case 3:cout<<"����";break;
		case 4:cout<<"����";break;
		case 5:cout<<"����";break;
		case 6:cout<<"½��";break;
		case 7:cout<<"����";break;
		case 8:cout<<"����";break;
		case 9:cout<<"����";break;
	}
	switch (x8)
	{
	    case 0:
			if (x10==0&&x9==0)
				cout<<"";
			else if (x7==0&&x6==0&&x5==0)
				cout<<"";
			else cout<<"��";
			break;
		case 1:cout<<"ҼǪ";break;
		case 2:cout<<"��Ǫ";break;
		case 3:cout<<"��Ǫ";break;
		case 4:cout<<"��Ǫ";break;
		case 5:cout<<"��Ǫ";break;
		case 6:cout<<"½Ǫ";break;
		case 7:cout<<"��Ǫ";break;
		case 8:cout<<"��Ǫ";break;
		case 9:cout<<"��Ǫ";break;
	}
	switch (x7)
	{
	    case 0:
			if (x8==0)
				cout<<"";
			else cout<<"��";
			break;
		case 1:cout<<"Ҽ��";break;
		case 2:cout<<"����";break;
		case 3:cout<<"����";break;
		case 4:cout<<"����";break;
		case 5:cout<<"���";break;
		case 6:cout<<"½��";break;
		case 7:cout<<"���";break;
		case 8:cout<<"�ư�";break;
		case 9:cout<<"����";break;
	}
	switch (x6)
	{
	    case 0:
			if (x7==0)
				cout<<"";
			else if (x5==0)
				cout<<"";
			else cout<<"��";
			break;
		case 1:cout<<"Ҽʰ";break;
		case 2:cout<<"��ʰ";break;
		case 3:cout<<"��ʰ";break;
		case 4:cout<<"��ʰ";break;
		case 5:cout<<"��ʰ";break;
		case 6:cout<<"½ʰ";break;
		case 7:cout<<"��ʰ";break;
		case 8:cout<<"��ʰ";break;
		case 9:cout<<"��ʰ";break;
	}
	switch (x5)
	{
	    case 0:
			cout<<"";
			break;
		case 1:cout<<"Ҽ";break;
		case 2:cout<<"��";break;
		case 3:cout<<"��";break;
		case 4:cout<<"��";break;
		case 5:cout<<"��";break;
		case 6:cout<<"½";break;
		case 7:cout<<"��";break;
		case 8:cout<<"��";break;
		case 9:cout<<"��";break;
	}
	if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0)
		cout<<"";
	else if ((x10!=0||x9!=0)&&x8==0&&x7==0&&x6==0&&x5==0)
		cout<<"";
	else cout<<"��";
	switch (x4)
	{
	    case 0:
			if (x3==0&&x2==0&&x1==0)
				cout<<"";
			else if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0)
				cout<<"";
			else cout<<"��";
		    break;		
		case 1:cout<<"ҼǪ";break;
		case 2:cout<<"��Ǫ";break;
		case 3:cout<<"��Ǫ";break;
		case 4:cout<<"��Ǫ";break;
		case 5:cout<<"��Ǫ";break;
		case 6:cout<<"½Ǫ";break;
		case 7:cout<<"��Ǫ";break;
		case 8:cout<<"��Ǫ";break;
		case 9:cout<<"��Ǫ";break;
	}
	switch (x3)
	{
	    case 0:
			if (x4==0||(x2==0&&x1==0))
				cout<<"";
			else cout<<"��";
		    break;	
		case 1:cout<<"Ҽ��";break;
		case 2:cout<<"����";break;
		case 3:cout<<"����";break;
		case 4:cout<<"����";break;
		case 5:cout<<"���";break;
		case 6:cout<<"½��";break;
		case 7:cout<<"���";break;
		case 8:cout<<"�ư�";break;
		case 9:cout<<"����";break;
	}
	switch (x2)
	{
	    case 0:
			if (x3==0||x1==0)
				cout<<"";
			else cout<<"��";
		    break;		
		case 1:cout<<"Ҽʰ";break;
		case 2:cout<<"��ʰ";break;
		case 3:cout<<"��ʰ";break;
		case 4:cout<<"��ʰ";break;
		case 5:cout<<"��ʰ";break;
		case 6:cout<<"½ʰ";break;
		case 7:cout<<"��ʰ";break;
		case 8:cout<<"��ʰ";break;
		case 9:cout<<"��ʰ";break;
	}
	switch (x1)
	{
	    case 0:
			cout<<"";
			break;
		case 1:cout<<"Ҽ";break;
		case 2:cout<<"��";break;
		case 3:cout<<"��";break;
		case 4:cout<<"��";break;
		case 5:cout<<"��";break;
		case 6:cout<<"½";break;
		case 7:cout<<"��";break;
		case 8:cout<<"��";break;
		case 9:cout<<"��";break;
	}
	if (x0==0&&x==0)
		cout<<"��";
	else if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0&&x4==0&&x3==0&&x2==0&&x1==0)
		cout<<"";
	else cout<<"Բ";
	switch (x0)
	{
		case 0:
			if (x10==0&&x9==0&&x8==0&&x7==0&&x6==0&&x5==0&&x4==0&&x3==0&&x2==0&&x1==0)
				cout<<"";
			else if (x!=0)
				cout<<"��";
			else cout<<"";
		    break;		
		case 1:cout<<"Ҽ��";break;
		case 2:cout<<"����";break;
		case 3:cout<<"����";break;
		case 4:cout<<"����";break;
		case 5:cout<<"���";break;
		case 6:cout<<"½��";break;
		case 7:cout<<"���";break;
		case 8:cout<<"�ƽ�";break;
		case 9:cout<<"����";break;
	}
	switch (x)
	{
		case 0:
			if (x0!=0)
				cout<<"��";
			else cout<<"";
		    break;		
		case 1:cout<<"Ҽ��";break;
		case 2:cout<<"����";break;
		case 3:cout<<"����";break;
		case 4:cout<<"����";break;
		case 5:cout<<"���";break;
		case 6:cout<<"½��";break;
		case 7:cout<<"���";break;
		case 8:cout<<"�Ʒ�";break;
		case 9:cout<<"����";break;
	}
    return 0;

}

