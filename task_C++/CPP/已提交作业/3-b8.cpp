// 1252366 µç×ÓÒ»°à ½¯Áè³¬
#include <iostream>
using namespace std;
int main()
{
	double s;
	int t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
	cout<<"ÊäÈëÒ»¸ö0.01-100ÒÚÖ®¼äµÄÊý"<<endl;
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
			cout<<"Ò¼Ê°";
		break;
		case 2:
			cout<<"·¡Ê°";
		break;
		case 3:
			cout<<"ÈþÊ°";
		break;
		case 4:
			cout<<"ËÁÊ°";
		break;
		case 5:
			cout<<"ÎéÊ°";
		break;
		case 6:
			cout<<"Â½Ê°";
		break;
		case 7:
			cout<<"ÆâÊ°";
		break;
		case 8:
			cout<<"°ÆÊ°";
		break;
		case 9:
			cout<<"¾ÁÊ°";
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
		        cout<<"Ò¼ÒÚ";
 	        break;
	    	case 2:
		        cout<<"·¡ÒÚ";
	        break;
	    	case 3:
		        cout<<"ÈþÒÚ";
	        break;
	    	case 4:
	    	    cout<<"ËÁÒÚ";
	        break;
	    	case 5:
		        cout<<"ÎéÒÚ";
            break;
	    	case 6:
	    	    cout<<"Â½ÒÚ";
	        break;
	    	case 7:
		        cout<<"ÆâÒÚ";
    	    break;
	    	case 8:
		        cout<<"°ÆÒÚ";
    	    break;
	    	case 9:
		        cout<<"¾ÁÒÚ";
    	    break;
		}
	}	
	else
	{
		switch(t2)
		{
		    case 0:
				cout<<"ÒÚ";
			break;
	    	case 1:
		        cout<<"Ò¼ÒÚ";
 	        break;
	    	case 2:
		        cout<<"·¡ÒÚ";
	        break;
	    	case 3:
		        cout<<"ÈþÒÚ";
	        break;
	    	case 4:
	    	    cout<<"ËÁÒÚ";
	        break;
	    	case 5:
		        cout<<"ÎéÒÚ";
            break;
	    	case 6:
	    	    cout<<"Â½ÒÚ";
	        break;
	    	case 7:
		        cout<<"ÆâÒÚ";
    	    break;
	    	case 8:
		        cout<<"°ÆÒÚ";
    	    break;
	    	case 9:
		        cout<<"¾ÁÒÚ";
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
		        cout<<"Ò¼Çª";
 	        break;
	    	case 2:
		        cout<<"·¡Çª";
	        break;
	    	case 3:
		        cout<<"ÈþÇª";
	        break;
	    	case 4:
	    	    cout<<"ËÁÇª";
	        break;
	    	case 5:
		        cout<<"ÎéÇª";
            break;
	    	case 6:
	    	    cout<<"Â½Çª";
	        break;
	    	case 7:
		        cout<<"ÆâÇª";
    	    break;
	    	case 8:
		        cout<<"°ÆÇª";
    	    break;
	    	case 9:
		        cout<<"¾ÁÇª";
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
		        cout<<"Ò¼ÇªÍò";
 	        break;
	    	case 2:
		        cout<<"·¡ÇªÍò";
	        break;
	    	case 3:
		        cout<<"ÈþÇªÍò";
	        break;
	    	case 4:
	    	    cout<<"ËÁÇªÍò";
	        break;
	    	case 5:
		        cout<<"ÎéÇªÍò";
            break;
	    	case 6:
	    	    cout<<"Â½ÇªÍò";
			break;
	    	case 7:
		        cout<<"ÆâÇªÍò";
    	    break;
	    	case 8:
		        cout<<"°ÆÇªÍò";
    	    break;
	    	case 9:
		        cout<<"¾ÁÇªÍò";
    	    break;
		}
	}
	else
	{
		switch(t3)
		{
		    case 0:
				cout<<"Áã";
			break;
	    	case 1:
		        cout<<"Ò¼Çª";
 	        break;
	    	case 2:
		        cout<<"·¡Çª";
	        break;
	    	case 3:
		        cout<<"ÈþÇª";
	        break;
	    	case 4:
	    	    cout<<"ËÁÇª";
	        break;
	    	case 5:
		        cout<<"ÎéÇª";
            break;
	    	case 6:
	    	    cout<<"Â½Çª";
			break;
	    	case 7:
		        cout<<"ÆâÇª";
    	    break;
	    	case 8:
		        cout<<"°ÆÇª";
    	    break;
	    	case 9:
		        cout<<"¾ÁÇª";
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
		        cout<<"Ò¼°Û";
 	        break;
	    	case 2:
		        cout<<"·¡°Û";
	        break;
	    	case 3:
		        cout<<"Èþ°Û";
	        break;
	    	case 4:
	    	    cout<<"ËÁ°Û";
	        break;
	    	case 5:
		        cout<<"Îé°Û";
            break;
	    	case 6:
	    	    cout<<"Â½°Û";
	        break;
	    	case 7:
		        cout<<"Æâ°Û";
    	    break;
	    	case 8:
		        cout<<"°Æ°Û";
    	    break;
	    	case 9:
		        cout<<"¾Á°Û";
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
		        cout<<"Ò¼°ÛÍò";
 	        break;
	    	case 2:
		        cout<<"·¡°ÛÍò";
	        break;
	    	case 3:
		        cout<<"Èþ°ÛÍò";
	        break;
	    	case 4:
	    	    cout<<"ËÁ°ÛÍò";
	        break;
	    	case 5:
		        cout<<"Îé°ÛÍò";
            break;
	    	case 6:
	    	    cout<<"Â½°ÛÍò";
	        break;
	    	case 7:
		        cout<<"Æâ°ÛÍò";
    	    break;
	    	case 8:
		        cout<<"°Æ°ÛÍò";
    	    break;
	    	case 9:
		        cout<<"¾Á°ÛÍò";
		}
	}
	else
	{
		switch(t4)
		{
		    case 0:
				cout<<"Áã";
			break;
	    	case 1:
		        cout<<"Ò¼°Û";
 	        break;
	    	case 2:
		        cout<<"·¡°Û";
	        break;
	    	case 3:
		        cout<<"Èþ°Û";
	        break;
	    	case 4:
	    	    cout<<"ËÁ°Û";
	        break;
	    	case 5:
		        cout<<"Îé°Û";
            break;
	    	case 6:
	    	    cout<<"Â½°Û";
	        break;
	    	case 7:
		        cout<<"Æâ°Û";
    	    break;
	    	case 8:
		        cout<<"°Æ°Û";
    	    break;
	    	case 9:
		        cout<<"¾Á°Û";
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
		        cout<<"Ò¼Ê°";
 	        break;
	    	case 2:
		        cout<<"·¡Ê°";
	        break;
	    	case 3:
		        cout<<"ÈþÊ°";
	        break;
	    	case 4:
	    	    cout<<"ËÁÊ°";
	        break;
	    	case 5:
		        cout<<"ÎéÊ°";
            break;
	    	case 6:
	    	    cout<<"Â½Ê°";
	        break;
	    	case 7:
		        cout<<"ÆâÊ°";
    	    break;
	    	case 8:
		        cout<<"°ÆÊ°";
    	    break;
	    	case 9:
		        cout<<"¾ÁÊ°";
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
		        cout<<"Ò¼Ê°Íò";
 	        break;
	    	case 2:
		        cout<<"·¡Ê°Íò";
	        break;
	    	case 3:
		        cout<<"ÈþÊ°Íò";
	        break;
	    	case 4:
	    	    cout<<"ËÁÊ°Íò";
	        break;
	    	case 5:
		        cout<<"ÎéÊ°Íò";
            break;
	    	case 6:
	    	    cout<<"Â½Ê°Íò";
	        break;
	    	case 7:
		        cout<<"ÆâÊ°Íò";
    	    break;
	    	case 8:
		        cout<<"°ÆÊ°Íò";
    	    break;
	    	case 9:
		        cout<<"¾ÁÊ°Íò";
    	    break;
		}
	}
	else
	{
		switch(t5)
		{
		    case 0:
				cout<<"Áã";
			break;
	    	case 1:
		        cout<<"Ò¼Ê°";
 	        break;
	    	case 2:
		        cout<<"·¡Ê°";
	        break;
	    	case 3:
		        cout<<"ÈþÊ°";
	        break;
	    	case 4:
	    	    cout<<"ËÁÊ°";
	        break;
	    	case 5:
		        cout<<"ÎéÊ°";
            break;
	    	case 6:
	    	    cout<<"Â½Ê°";
	        break;
	    	case 7:
		        cout<<"ÆâÊ°";
    	    break;
	    	case 8:
		        cout<<"°ÆÊ°";
    	    break;
	    	case 9:
		        cout<<"¾ÁÊ°";
    	    break;
		}
	}

	switch(t6)
	{
	    case 0:
			cout<<"";
		break;
	   	case 1:
	        cout<<"Ò¼Íò";
		break;
	   	case 2:
	        cout<<"·¡Íò";
		break;
	   	case 3:
	        cout<<"ÈþÍò";
		break;
	   	case 4:
	   	    cout<<"ËÁÍò";
        break;
		case 5:
	        cout<<"ÎéÍò";
        break;
		case 6:
	   	    cout<<"Â½Íò";
        break;
		case 7:
	        cout<<"ÆâÍò";
   	    break;
		case 8:
	        cout<<"°ÆÍò";
   	    break;
		case 9:
	        cout<<"¾ÁÍò";
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
		        cout<<"Ò¼Çª";
 	        break;
	    	case 2:
		        cout<<"·¡Çª";
	        break;
	    	case 3:
		        cout<<"ÈþÇª";
	        break;
	    	case 4:
	    	    cout<<"ËÁÇª";
	        break;
	    	case 5:
		        cout<<"ÎéÇª";
            break;
	    	case 6:
	    	    cout<<"Â½Çª";
	        break;
	    	case 7:
		        cout<<"ÆâÇª";
    	    break;
	    	case 8:
		        cout<<"°ÆÇª";
    	    break;
	    	case 9:
		        cout<<"¾ÁÇª";
    	    break;
		}
	}	
	else
	{
		switch(t7)
		{
		    case 0:
				cout<<"Áã";
			break;
	    	case 1:
		        cout<<"Ò¼Çª";
 	        break;
	    	case 2:
		        cout<<"·¡Çª";
	        break;
	    	case 3:
		        cout<<"ÈþÇª";
	        break;
	    	case 4:
	    	    cout<<"ËÁÇª";
	        break;
	    	case 5:
		        cout<<"ÎéÇª";
            break;
	    	case 6:
	    	    cout<<"Â½Çª";
	        break;
	    	case 7:
		        cout<<"ÆâÇª";
    	    break;
	    	case 8:
		        cout<<"°ÆÇª";
    	    break;
	    	case 9:
		        cout<<"¾ÁÇª";
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
		        cout<<"Ò¼°Û";
 	        break;
	    	case 2:
		        cout<<"·¡°Û";
	        break;
	    	case 3:
		        cout<<"Èþ°Û";
	        break;
	    	case 4:
	    	    cout<<"ËÁ°Û";
	        break;
	    	case 5:
		        cout<<"Îé°Û";
            break;
	    	case 6:
	    	    cout<<"Â½°Û";
	        break;
	    	case 7:
		        cout<<"Æâ°Û";
    	    break;
	    	case 8:
		        cout<<"°Æ°Û";
    	    break;
	    	case 9:
		        cout<<"¾Á°Û";
    	    break;
		}
	}	
	else
	{
		switch(t8)
		{
		    case 0:
				cout<<"Áã";
			break;
	    	case 1:
		        cout<<"Ò¼°Û";
 	        break;
	    	case 2:
		        cout<<"·¡°Û";
	        break;
	    	case 3:
		        cout<<"Èþ°Û";
	        break;
	    	case 4:
	    	    cout<<"ËÁ°Û";
	        break;
	    	case 5:
		        cout<<"Îé°Û";
            break;
	    	case 6:
	    	    cout<<"Â½°Û";
	        break;
	    	case 7:
		        cout<<"Æâ°Û";
    	    break;
	    	case 8:
		        cout<<"°Æ°Û";
    	    break;
	    	case 9:
		        cout<<"¾Á°Û";
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
		        cout<<"Ò¼Ê°";
 	        break;
	    	case 2:
		        cout<<"·¡Ê°";
	        break;
	    	case 3:
		        cout<<"ÈþÊ°";
	        break;
	    	case 4:
	    	    cout<<"ËÁÊ°";
	        break;
	    	case 5:
		        cout<<"ÎéÊ°";
            break;
	    	case 6:
	    	    cout<<"Â½Ê°";
	        break;
	    	case 7:
		        cout<<"ÆâÊ°";
    	    break;
	    	case 8:
		        cout<<"°ÆÊ°";
    	    break;
	    	case 9:
		        cout<<"¾ÁÊ°";
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
		        cout<<"Ò¼Ê°";
 	        break;
	    	case 2:
		        cout<<"·¡Ê°";
	        break;
	    	case 3:
		        cout<<"ÈþÊ°";
	        break;
	    	case 4:
	    	    cout<<"ËÁÊ°";
	        break;
	    	case 5:
		        cout<<"ÎéÊ°";
            break;
	    	case 6:
	    	    cout<<"Â½Ê°";
	        break;
	    	case 7:
		        cout<<"ÆâÊ°";
    	    break;
	    	case 8:
		        cout<<"°ÆÊ°";
    	    break;
	    	case 9:
		        cout<<"¾ÁÊ°";
    	    break;
		}
	}
	else
	{
		switch(t9)
		{
		    case 0:
				cout<<"Áã";
			break;
	    	case 1:
		        cout<<"Ò¼Ê°";
 	        break;
	    	case 2:
		        cout<<"·¡Ê°";
	        break;
	    	case 3:
		        cout<<"ÈþÊ°";
	        break;
	    	case 4:
	    	    cout<<"ËÁÊ°";
	        break;
	    	case 5:
		        cout<<"ÎéÊ°";
            break;
	    	case 6:
	    	    cout<<"Â½Ê°";
	        break;
	    	case 7:
		        cout<<"ÆâÊ°";
    	    break;
	    	case 8:
		        cout<<"°ÆÊ°";
    	    break;
	    	case 9:
		        cout<<"¾ÁÊ°";
    	    break;
		}
	}

	switch(t10)
	{
	    case 0:
			cout<<"";
		break;
	    case 1:
			cout<<"Ò¼";
		break;
		case 2:
			cout<<"·¡";
		break;
		case 3:
			cout<<"Èþ";
		break;
		case 4:
			cout<<"ËÁ";
		break;
		case 5:
			cout<<"Îé";
		break;
		case 6:
			cout<<"Â½";
		break;
		case 7:
			cout<<"Æâ";
		break;
		case 8:
			cout<<"°Æ";
		break;
		case 9:
			cout<<"¾Á";
		break;
	}

	if(t11==0 && t12==0)
		cout<<"Ô²Õû";
	else if(int(s)==0)
	{
		switch(t11)
		{
		    case 0:
				cout<<"";
			break;
	    	case 1:
		        cout<<"Ò¼½Ç";
 	        break;
	    	case 2:
		        cout<<"·¡½Ç";
	        break;
	    	case 3:
		        cout<<"Èþ½Ç";
	        break;
	    	case 4:
	    	    cout<<"ËÁ½Ç";
	        break;
	    	case 5:
		        cout<<"Îé½Ç";
            break;
	    	case 6:
	    	    cout<<"Â½½Ç";
	        break;
	    	case 7:
		        cout<<"Æâ½Ç";
    	    break;
	    	case 8:
		        cout<<"°Æ½Ç";
    	    break;
	    	case 9:
		        cout<<"¾Á½Ç";
    	    break;
		}
	}
	else
	{
		switch(t11)
		{
		    case 0:
				cout<<"Ô²Áã";
			break;
	    	case 1:
		        cout<<"Ô²Ò¼½Ç";
 	        break;
	    	case 2:
		        cout<<"Ô²·¡½Ç";
	        break;
	    	case 3:
		        cout<<"Ô²Èþ½Ç";
	        break;
	    	case 4:
	    	    cout<<"Ô²ËÁ½Ç";
	        break;
	    	case 5:
		        cout<<"Ô²Îé½Ç";
            break;
	    	case 6:
	    	    cout<<"Ô²Â½½Ç";
	        break;
	    	case 7:
		        cout<<"Ô²Æâ½Ç";
    	    break;
	    	case 8:
		        cout<<"Ô²°Æ½Ç";
    	    break;
	    	case 9:
		        cout<<"Ô²¾Á½Ç";
    	    break;
		}
	}

	switch(t12)
	{
	    case 0:
			cout<<"";
		break;
	    case 1:
			cout<<"Ò¼·Ö";
		break;
		case 2:
			cout<<"·¡·Ö";
		break;
		case 3:
			cout<<"Èþ·Ö";
		break;
		case 4:
			cout<<"ËÁ·Ö";
		break;
		case 5:
			cout<<"Îé·Ö";
		break;
		case 6:
			cout<<"Â½·Ö";
		break;
		case 7:
			cout<<"Æâ·Ö";
		break;
		case 8:
			cout<<"°Æ·Ö";
		break;
		case 9:
			cout<<"¾Á·Ö";
		break;
	}

	return 0;
}
	
	

	    	



	

			
			
			
			
			
			
			

			
			
			
