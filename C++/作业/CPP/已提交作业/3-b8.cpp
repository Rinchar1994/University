// 1252366 ����һ�� ���賬
#include <iostream>
using namespace std;
int main()
{
	double s;
	int t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
	cout<<"����һ��0.01-100��֮�����"<<endl;
	cin>>s;

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

	switch(t1)
	{
	    case 0:
			cout<<"";
		break;
	    case 1:
			cout<<"Ҽʰ";
		break;
		case 2:
			cout<<"��ʰ";
		break;
		case 3:
			cout<<"��ʰ";
		break;
		case 4:
			cout<<"��ʰ";
		break;
		case 5:
			cout<<"��ʰ";
		break;
		case 6:
			cout<<"½ʰ";
		break;
		case 7:
			cout<<"��ʰ";
		break;
		case 8:
			cout<<"��ʰ";
		break;
		case 9:
			cout<<"��ʰ";
		break;
	}

    if(t1==0)
	{
		switch(t2)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽ��";
 	        break;
	    	case 2:
		        cout<<"����";
	        break;
	    	case 3:
		        cout<<"����";
	        break;
	    	case 4:
	    	    cout<<"����";
	        break;
	    	case 5:
		        cout<<"����";
            break;
	    	case 6:
	    	    cout<<"½��";
	        break;
	    	case 7:
		        cout<<"����";
    	    break;
	    	case 8:
		        cout<<"����";
    	    break;
	    	case 9:
		        cout<<"����";
    	    break;
		}
	}	
	else
	{
		switch(t2)
		{
		    case 0:
				cout<<"��";
			break;
	    	case 1:
		        cout<<"Ҽ��";
 	        break;
	    	case 2:
		        cout<<"����";
	        break;
	    	case 3:
		        cout<<"����";
	        break;
	    	case 4:
	    	    cout<<"����";
	        break;
	    	case 5:
		        cout<<"����";
            break;
	    	case 6:
	    	    cout<<"½��";
	        break;
	    	case 7:
		        cout<<"����";
    	    break;
	    	case 8:
		        cout<<"����";
    	    break;
	    	case 9:
		        cout<<"����";
    	    break;
		}
	}

	if(t1==0 && t2==0 && (t4!=0 || t5!=0 || t6!=0))
	{
		switch(t3)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"ҼǪ";
 	        break;
	    	case 2:
		        cout<<"��Ǫ";
	        break;
	    	case 3:
		        cout<<"��Ǫ";
	        break;
	    	case 4:
	    	    cout<<"��Ǫ";
	        break;
	    	case 5:
		        cout<<"��Ǫ";
            break;
	    	case 6:
	    	    cout<<"½Ǫ";
	        break;
	    	case 7:
		        cout<<"��Ǫ";
    	    break;
	    	case 8:
		        cout<<"��Ǫ";
    	    break;
	    	case 9:
		        cout<<"��Ǫ";
    	    break;
		}
	}	
	else if(t4==0 && t5==0 && t6==0)
	{
		switch(t3)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"ҼǪ��";
 	        break;
	    	case 2:
		        cout<<"��Ǫ��";
	        break;
	    	case 3:
		        cout<<"��Ǫ��";
	        break;
	    	case 4:
	    	    cout<<"��Ǫ��";
	        break;
	    	case 5:
		        cout<<"��Ǫ��";
            break;
	    	case 6:
	    	    cout<<"½Ǫ��";
			break;
	    	case 7:
		        cout<<"��Ǫ��";
    	    break;
	    	case 8:
		        cout<<"��Ǫ��";
    	    break;
	    	case 9:
		        cout<<"��Ǫ��";
    	    break;
		}
	}
	else
	{
		switch(t3)
		{
		    case 0:
				cout<<"��";
			break;
	    	case 1:
		        cout<<"ҼǪ";
 	        break;
	    	case 2:
		        cout<<"��Ǫ";
	        break;
	    	case 3:
		        cout<<"��Ǫ";
	        break;
	    	case 4:
	    	    cout<<"��Ǫ";
	        break;
	    	case 5:
		        cout<<"��Ǫ";
            break;
	    	case 6:
	    	    cout<<"½Ǫ";
			break;
	    	case 7:
		        cout<<"��Ǫ";
    	    break;
	    	case 8:
		        cout<<"��Ǫ";
    	    break;
	    	case 9:
		        cout<<"��Ǫ";
    	    break;
		}
	}

	if(t3==0 && (t5!=0 || t6!=0))
	{
		switch(t4)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽ��";
 	        break;
	    	case 2:
		        cout<<"����";
	        break;
	    	case 3:
		        cout<<"����";
	        break;
	    	case 4:
	    	    cout<<"����";
	        break;
	    	case 5:
		        cout<<"���";
            break;
	    	case 6:
	    	    cout<<"½��";
	        break;
	    	case 7:
		        cout<<"���";
    	    break;
	    	case 8:
		        cout<<"�ư�";
    	    break;
	    	case 9:
		        cout<<"����";
    	    break;
		}
	}	
	else if(t5==0 && t6==0)
	{
		switch(t4)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽ����";
 	        break;
	    	case 2:
		        cout<<"������";
	        break;
	    	case 3:
		        cout<<"������";
	        break;
	    	case 4:
	    	    cout<<"������";
	        break;
	    	case 5:
		        cout<<"�����";
            break;
	    	case 6:
	    	    cout<<"½����";
	        break;
	    	case 7:
		        cout<<"�����";
    	    break;
	    	case 8:
		        cout<<"�ư���";
    	    break;
	    	case 9:
		        cout<<"������";
		}
	}
	else
	{
		switch(t4)
		{
		    case 0:
				cout<<"��";
			break;
	    	case 1:
		        cout<<"Ҽ��";
 	        break;
	    	case 2:
		        cout<<"����";
	        break;
	    	case 3:
		        cout<<"����";
	        break;
	    	case 4:
	    	    cout<<"����";
	        break;
	    	case 5:
		        cout<<"���";
            break;
	    	case 6:
	    	    cout<<"½��";
	        break;
	    	case 7:
		        cout<<"���";
    	    break;
	    	case 8:
		        cout<<"�ư�";
    	    break;
	    	case 9:
		        cout<<"����";
		}
	}

	if(t4==0 && t6!=0)
	{
		switch(t5)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽʰ";
 	        break;
	    	case 2:
		        cout<<"��ʰ";
	        break;
	    	case 3:
		        cout<<"��ʰ";
	        break;
	    	case 4:
	    	    cout<<"��ʰ";
	        break;
	    	case 5:
		        cout<<"��ʰ";
            break;
	    	case 6:
	    	    cout<<"½ʰ";
	        break;
	    	case 7:
		        cout<<"��ʰ";
    	    break;
	    	case 8:
		        cout<<"��ʰ";
    	    break;
	    	case 9:
		        cout<<"��ʰ";
    	    break;
		}
	}	
	else if(t6==0)
	{
		switch(t5)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽʰ��";
 	        break;
	    	case 2:
		        cout<<"��ʰ��";
	        break;
	    	case 3:
		        cout<<"��ʰ��";
	        break;
	    	case 4:
	    	    cout<<"��ʰ��";
	        break;
	    	case 5:
		        cout<<"��ʰ��";
            break;
	    	case 6:
	    	    cout<<"½ʰ��";
	        break;
	    	case 7:
		        cout<<"��ʰ��";
    	    break;
	    	case 8:
		        cout<<"��ʰ��";
    	    break;
	    	case 9:
		        cout<<"��ʰ��";
    	    break;
		}
	}
	else
	{
		switch(t5)
		{
		    case 0:
				cout<<"��";
			break;
	    	case 1:
		        cout<<"Ҽʰ";
 	        break;
	    	case 2:
		        cout<<"��ʰ";
	        break;
	    	case 3:
		        cout<<"��ʰ";
	        break;
	    	case 4:
	    	    cout<<"��ʰ";
	        break;
	    	case 5:
		        cout<<"��ʰ";
            break;
	    	case 6:
	    	    cout<<"½ʰ";
	        break;
	    	case 7:
		        cout<<"��ʰ";
    	    break;
	    	case 8:
		        cout<<"��ʰ";
    	    break;
	    	case 9:
		        cout<<"��ʰ";
    	    break;
		}
	}

	switch(t6)
	{
	    case 0:
			cout<<"";
		break;
	   	case 1:
	        cout<<"Ҽ��";
		break;
	   	case 2:
	        cout<<"����";
		break;
	   	case 3:
	        cout<<"����";
		break;
	   	case 4:
	   	    cout<<"����";
        break;
		case 5:
	        cout<<"����";
        break;
		case 6:
	   	    cout<<"½��";
        break;
		case 7:
	        cout<<"����";
   	    break;
		case 8:
	        cout<<"����";
   	    break;
		case 9:
	        cout<<"����";
   	    break;
	}

	if(t8==0 && t9==0 && t10==0 || t1==0 && t2==0 && t3==0 && t4==0 && t5==0 && t6==0)
	{
		switch(t7)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"ҼǪ";
 	        break;
	    	case 2:
		        cout<<"��Ǫ";
	        break;
	    	case 3:
		        cout<<"��Ǫ";
	        break;
	    	case 4:
	    	    cout<<"��Ǫ";
	        break;
	    	case 5:
		        cout<<"��Ǫ";
            break;
	    	case 6:
	    	    cout<<"½Ǫ";
	        break;
	    	case 7:
		        cout<<"��Ǫ";
    	    break;
	    	case 8:
		        cout<<"��Ǫ";
    	    break;
	    	case 9:
		        cout<<"��Ǫ";
    	    break;
		}
	}	
	else
	{
		switch(t7)
		{
		    case 0:
				cout<<"��";
			break;
	    	case 1:
		        cout<<"ҼǪ";
 	        break;
	    	case 2:
		        cout<<"��Ǫ";
	        break;
	    	case 3:
		        cout<<"��Ǫ";
	        break;
	    	case 4:
	    	    cout<<"��Ǫ";
	        break;
	    	case 5:
		        cout<<"��Ǫ";
            break;
	    	case 6:
	    	    cout<<"½Ǫ";
	        break;
	    	case 7:
		        cout<<"��Ǫ";
    	    break;
	    	case 8:
		        cout<<"��Ǫ";
    	    break;
	    	case 9:
		        cout<<"��Ǫ";
    	    break;
		}
	}

	if(t7==0)
	{
		switch(t8)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽ��";
 	        break;
	    	case 2:
		        cout<<"����";
	        break;
	    	case 3:
		        cout<<"����";
	        break;
	    	case 4:
	    	    cout<<"����";
	        break;
	    	case 5:
		        cout<<"���";
            break;
	    	case 6:
	    	    cout<<"½��";
	        break;
	    	case 7:
		        cout<<"���";
    	    break;
	    	case 8:
		        cout<<"�ư�";
    	    break;
	    	case 9:
		        cout<<"����";
    	    break;
		}
	}	
	else
	{
		switch(t8)
		{
		    case 0:
				cout<<"��";
			break;
	    	case 1:
		        cout<<"Ҽ��";
 	        break;
	    	case 2:
		        cout<<"����";
	        break;
	    	case 3:
		        cout<<"����";
	        break;
	    	case 4:
	    	    cout<<"����";
	        break;
	    	case 5:
		        cout<<"���";
            break;
	    	case 6:
	    	    cout<<"½��";
	        break;
	    	case 7:
		        cout<<"���";
    	    break;
	    	case 8:
		        cout<<"�ư�";
    	    break;
	    	case 9:
		        cout<<"����";
    	    break;
		}
	}

	if(t8==0 && t10!=0)
	{
		switch(t9)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽʰ";
 	        break;
	    	case 2:
		        cout<<"��ʰ";
	        break;
	    	case 3:
		        cout<<"��ʰ";
	        break;
	    	case 4:
	    	    cout<<"��ʰ";
	        break;
	    	case 5:
		        cout<<"��ʰ";
            break;
	    	case 6:
	    	    cout<<"½ʰ";
	        break;
	    	case 7:
		        cout<<"��ʰ";
    	    break;
	    	case 8:
		        cout<<"��ʰ";
    	    break;
	    	case 9:
		        cout<<"��ʰ";
    	    break;
		}
	}	
	else if(t10==0)
	{
		switch(t9)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽʰ";
 	        break;
	    	case 2:
		        cout<<"��ʰ";
	        break;
	    	case 3:
		        cout<<"��ʰ";
	        break;
	    	case 4:
	    	    cout<<"��ʰ";
	        break;
	    	case 5:
		        cout<<"��ʰ";
            break;
	    	case 6:
	    	    cout<<"½ʰ";
	        break;
	    	case 7:
		        cout<<"��ʰ";
    	    break;
	    	case 8:
		        cout<<"��ʰ";
    	    break;
	    	case 9:
		        cout<<"��ʰ";
    	    break;
		}
	}
	else
	{
		switch(t9)
		{
		    case 0:
				cout<<"��";
			break;
	    	case 1:
		        cout<<"Ҽʰ";
 	        break;
	    	case 2:
		        cout<<"��ʰ";
	        break;
	    	case 3:
		        cout<<"��ʰ";
	        break;
	    	case 4:
	    	    cout<<"��ʰ";
	        break;
	    	case 5:
		        cout<<"��ʰ";
            break;
	    	case 6:
	    	    cout<<"½ʰ";
	        break;
	    	case 7:
		        cout<<"��ʰ";
    	    break;
	    	case 8:
		        cout<<"��ʰ";
    	    break;
	    	case 9:
		        cout<<"��ʰ";
    	    break;
		}
	}

	switch(t10)
	{
	    case 0:
			cout<<"";
		break;
	    case 1:
			cout<<"Ҽ";
		break;
		case 2:
			cout<<"��";
		break;
		case 3:
			cout<<"��";
		break;
		case 4:
			cout<<"��";
		break;
		case 5:
			cout<<"��";
		break;
		case 6:
			cout<<"½";
		break;
		case 7:
			cout<<"��";
		break;
		case 8:
			cout<<"��";
		break;
		case 9:
			cout<<"��";
		break;
	}

	if(t11==0 && t12==0)
		cout<<"Բ��";
	else if(int(s)==0)
	{
		switch(t11)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ҽ��";
 	        break;
	    	case 2:
		        cout<<"����";
	        break;
	    	case 3:
		        cout<<"����";
	        break;
	    	case 4:
	    	    cout<<"����";
	        break;
	    	case 5:
		        cout<<"���";
            break;
	    	case 6:
	    	    cout<<"½��";
	        break;
	    	case 7:
		        cout<<"���";
    	    break;
	    	case 8:
		        cout<<"�ƽ�";
    	    break;
	    	case 9:
		        cout<<"����";
    	    break;
		}
	}
	else
	{
		switch(t11)
		{
		    case 0:
				cout<<"Բ��";
			break;
	    	case 1:
		        cout<<"ԲҼ��";
 	        break;
	    	case 2:
		        cout<<"Բ����";
	        break;
	    	case 3:
		        cout<<"Բ����";
	        break;
	    	case 4:
	    	    cout<<"Բ����";
	        break;
	    	case 5:
		        cout<<"Բ���";
            break;
	    	case 6:
	    	    cout<<"Բ½��";
	        break;
	    	case 7:
		        cout<<"Բ���";
    	    break;
	    	case 8:
		        cout<<"Բ�ƽ�";
    	    break;
	    	case 9:
		        cout<<"Բ����";
    	    break;
		}
	}

	switch(t12)
	{
	    case 0:
			cout<<"";
		break;
	    case 1:
			cout<<"Ҽ��";
		break;
		case 2:
			cout<<"����";
		break;
		case 3:
			cout<<"����";
		break;
		case 4:
			cout<<"����";
		break;
		case 5:
			cout<<"���";
		break;
		case 6:
			cout<<"½��";
		break;
		case 7:
			cout<<"���";
		break;
		case 8:
			cout<<"�Ʒ�";
		break;
		case 9:
			cout<<"����";
		break;
	}

	return 0;
}
	
	

	    	



	

			
			
			
			
			
			
			

			
			
			
