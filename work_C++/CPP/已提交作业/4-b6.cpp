/* 1252366 ���賬 ����һ�� */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/* ������Ա��������κ��޸�
   ���������⣬�������κκ�����������㡱-������!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch(num) {
		case 0:
			if (flag_of_zero)
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
		}
}

/* �ɸ�����Ҫ�Զ����������� */


/* ������Ҫ���main���� */
main()
{
	void daxie(int num, int flag_of_zero);
	double s;
	int t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
	cout << "Please enter a float number" << " << 's' << " << "between 0.01 and 100 hundred million as the price" << endl;
	cin >> s;
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
	
	daxie( t1, 0);
	if(t1!=0)
		cout << "ʰ";

	daxie( t2, 0);
	if(t1==0 && t2==0)
		cout << "";
	else
		cout << "��";

	if(t1==0 && t2==0 && (t4!=0 || t5!=0 || t6!=0))
	{
		daxie( t3, 0);
		if(t3!=0)
			cout << "Ǫ";
	}
	else if(t4==0 && t5==0 && t6==0)
	{
		daxie( t3, 0);
		if(t3!=0)
			cout << "Ǫ��";
	}
	else
	{
		daxie( t3, 1);
		if(t3!=0)
			cout << "Ǫ";
	}

	if(t3==0 && (t5!=0 || t6!=0))
    {
		daxie( t4, 0);
		if(t4!=0)
			cout << "��";
	}
	else if(t5==0 && t6==0)
	{
		daxie( t4, 0);
		if(t4!=0)
			cout << "����";
	}
	else
	{
		daxie( t4, 1);
		if(t4!=0)
			cout << "��";
	}

	if(t4==0 && t6!=0)
	{
		daxie( t5, 0);
		if(t5!=0)
			cout << "ʰ";
	}
	else if(t6==0)
	{
		daxie( t5, 0);
		if(t5!=0)
			cout << "ʰ��";
	}
	else
	{
		daxie( t5, 1);
		if(t5!=0)
			cout << "ʰ";
	}

	daxie( t6, 0);
	if(t6!=0)
		cout << "��";

	if(t8==0 && t9==0 && t10==0 || t1==0 && t2==0 && t3==0 && t4==0 && t5==0 && t6==0)
	{
		daxie( t7, 0);
		if(t7!=0)
			cout << "Ǫ";
	}
	else
	{
		daxie( t7, 1);
		if(t7!=0)
			cout << "Ǫ";
	}

	if(t7==0)
	{
		daxie( t8, 0);
		if(t8!=0)
			cout << "��";
	}
	else
	{
		daxie( t8, 1);
		if(t8!=0)
			cout << "��";
	}

	if(t8==0 && t10!=0 || t10==0)
	{
		daxie( t9, 0);
		if(t9!=0)
			cout << "ʰ";
	}
	else
	{
		daxie( t9, 1);
		if(t9!=0)
			cout << "ʰ";
	}

	daxie( t10, 0);

	if(t11==0 && t12==0)
		cout<<"Բ��";
	else if(int(s)==0)
	{
		daxie( t11, 0);
		if(t11!=0)
			cout << "��";
	}
	else
	{
		cout << "Բ";
		daxie( t11, 1);
		if(t11!=0)
			cout << "��";
	}

	daxie( t12, 0);
	if(t12!=0)
	    cout << "��";

	return 0;
}
