/* ѧ�� ���� �༶ */
#include <iostream>
using namespace std;

struct address_list {
	char *name;
	char *mobilephone1;
	char *mobilephone2;
	char *phone_1;
	char *phone_2;
	char *qq_1;
	char *qq_2;
	char *email_1;
	char *email_2;
};

/* �����ڴ˶���������Ҫ�ĺ��� */

/* ���Һ��������岻Ҫ����ʵ�ּ��� */
int search_list(struct address_list *list, char *item)
{
	int m=0,sum=0, s=0;
	char *a=item;
	for( ; *item!=0; item++)
		m++;
	item-=m;
	
	for (int n=0;list[n].name!=NULL;n++)
	{   
		char *name=list[n].name;
		for(;*(list[n].name)!=0;list[n].name++)
		{
			if (*(list[n].name)==*item)
			{
				for (;;item++,list[n].name++)
				{
					if (*item==0||*(list[n].name)==0)
						break;
					else if (*(list[n].name)==*item)
						s++;
				}
		
				if(s==m)
				{
					sum++;
					item-=m;
					list[n].name-=m;
					s=0;
					break;
				}
			    list[n].name-=item-a;
			    item=a;
			    s=0;
			}
		}
		list[n].name=name;


		char *mobilephonel1=list[n].mobilephone1;
		if(list[n].mobilephone1!=NULL)
		{for(;*(list[n].mobilephone1)!=0;list[n].mobilephone1++)
		{
			if (*(list[n].mobilephone1)==*item)
			{
				for (;;item++,list[n].mobilephone1++)
				{
					if (*item==0||*(list[n].mobilephone1)==0)
						break;
					else if (*(list[n].mobilephone1)==*item)
						s++;
				}
				if(s==m)
				{
					sum++;
					item-=m;
					list[n].mobilephone1-=m;
					s=0;
					break;
				}
			    list[n].mobilephone1-=item-a;
			    item=a;
			    s=0;
			}
		}
		}
		list[n].mobilephone1=mobilephonel1;


		char *mobilephonel2=list[n].mobilephone2;
		if(list[n].mobilephone2!=NULL)
		{for(;*(list[n].mobilephone2)!=0;list[n].mobilephone2++)
		{
			if (*(list[n].mobilephone2)==*item)
			{
				for (;;item++,list[n].mobilephone2++)
				{
					if (*item==0||*(list[n].mobilephone2)==0)
						break;
					else if (*(list[n].mobilephone2)==*item)
						s++;
				}
			    if(s==m)
				{
					sum++;
					item-=m;
					list[n].mobilephone2-=m;
					s=0;
					break;
				}
		      	list[n].mobilephone2-=item-a;
		    	item=a;
		    	s=0;
			}
		}
		}
		list[n].mobilephone2=mobilephonel2;



		char *phone_1=list[n].phone_1;
		if(list[n].phone_1!=NULL)
		{for(;*(list[n].phone_1)!=0;list[n].phone_1++)
		{
			if (*(list[n].phone_1)==*item)
			{
				for (;;item++,list[n].phone_1++)
				{
					if (*item==0||*(list[n].phone_1)==0)
						break;
					else if (*(list[n].phone_1)==*item)
						s++;
				}
			    if(s==m)
				{
					sum++;
					item-=m;
					list[n].phone_1-=m;
					s=0;
					break;
				}
		      	list[n].phone_1-=item-a;
		    	item=a;
		    	s=0;
			}
		}
		}
		list[n].phone_1=phone_1;


		char *phone_2=list[n].phone_2;
		if(list[n].phone_2!=NULL)
		{for(;*(list[n].phone_2)!=0;list[n].phone_2++)
		{
			if (*(list[n].phone_2)==*item)
			{
				for (;;item++,list[n].phone_2++)
				{
					if (*item==0||*(list[n].phone_2)==0)
						break;
					else if (*(list[n].phone_2)==*item)
						s++;
				}
			    if(s==m)
				{
					sum++;
					item-=m;
					list[n].phone_2-=m;
					s=0;
					break;
				}
		    	list[n].phone_2-=item-a;
		    	item=a;
		    	s=0;
			}
		}
		}
		list[n].phone_2=phone_2;


		char *qq_1=list[n].qq_1;
		if(list[n].qq_1!=NULL)
		{for(;*(list[n].qq_1)!=0;list[n].qq_1++)
		{
			if (*(list[n].qq_1)==*item)
			{
				for (;;item++,list[n].qq_1++)
				{
					if (*item==0||*(list[n].qq_1)==0)
						break;
					else if (*(list[n].qq_1)==*item)
						s++;
				}
		    	if(s==m)
				{
					sum++;
					item-=m;
					list[n].qq_1-=m;
					s=0;
					break;
				}
		    	list[n].qq_1-=item-a;
		    	item=a;
	 	    	s=0;
			}
		}
		}
		list[n].qq_1=qq_1;


		char *qq_2=list[n].qq_2;
		if(list[n].qq_2!=NULL)
		{for(;*(list[n].qq_2)!=0;list[n].qq_2++)
		{
			if (*(list[n].qq_2)==*item)
			{
				for (;;item++,list[n].qq_2++)
				{
					if (*item==0||*(list[n].qq_2)==0)
						break;
					else if (*(list[n].qq_2)==*item)
						s++;
				}
		    	if(s==m)
				{
					sum++;
					item-=m;
					list[n].qq_2-=m;
					s=0;
					break;
				}
		    	list[n].qq_2-=item-a;
		    	item=a;
		    	s=0;
			}
		}
		}
		list[n].qq_2=qq_2;



		char *email_1=list[n].email_1;
		if(list[n].email_1!=NULL)
		{for(;*(list[n].email_1)!=0;list[n].email_1++)
		{
			if (*(list[n].email_1)==*item)
			{
				for (;;item++,list[n].email_1++)
				{
					if (*item==0||*(list[n].email_1)==0)
						break;
					else if (*(list[n].email_1)==*item)
						s++;
				}
		      	if(s==m)
				{
					sum++;
					item-=m;
					list[n].email_1-=m;
					s=0;
					break;
				}
			    list[n].email_1-=item-a;
			    item=a;
			    s=0;
			}
		}
		}
		list[n].email_1=email_1;



		char *email_2=list[n].email_2;
		if(list[n].email_2!=NULL)
		{for(;*(list[n].email_2)!=0;list[n].email_2++)
		{
			if (*(list[n].email_2)==*item)
			{
				for (;;item++,list[n].email_2++)
				{
					if (*item==0||*(list[n].email_2)==0)
						break;
					else if (*(list[n].email_2)==*item)
						s++;
				}
			    if(s==m)
				{
					sum++;
					item-=m;
					list[n].email_2-=m;
					s=0;
					break;
				}
			    list[n].email_2-=item-a;
			    item=a;
			    s=0;
			}
		}
		}
		list[n].email_2=email_2;
	}
		
	/* ����ƥ�����ӡ */

	return sum;	//����Ϊƥ������������һ����������ƥ�䣬��3��ĿǰΪ0���ɸģ�
}

/* ����������׼�� */
int main()
{
	/* ��ʼ�����������ʱ���ܷ����仯����˳����ʵ���в���ֱ����10����ʾ������10��Ԫ��!!! */
	struct address_list list[] = {
		{"����",   "13912345678", "18887654321", "021-65980000",  "021-69584321", "1023123",    "73636276",    "zhangsan@163.com",     "san.zhang@126.com"},
		{"����",   "13901201234", "18601035283", "010-53629873",  NULL,           "102312301",  "6353292732",  "lisi@hotmail.com",     "lisi@gmain.com"},
		{"����",   NULL,          "13482330973", "021-64372987",  "025-84436251", "82837323",   NULL,          "wangwu@126.com",       NULL},
		{"����",   "13764212387", NULL,          "0571-85239889", NULL,           "1505210003", NULL,          "zhaoliu@sohu.com",     NULL},
		{"è��",   "13301138263", "13901037653", "0593-8152353",  "0552-7363928", "1023123",    "10293838792", "maosan@tongji.edu.cn", "maosan@qq.com"},
		{"����",   NULL,          NULL,          NULL,            NULL,           "2738471827", "827361523",   "gousi@sina.com.cn",    "gousi@vip.sohu.com"},
		{"ţ��",   "15002220808", NULL,          "0755-62538792", NULL,           "3527374672", NULL,          "niuqi@sina.com",       "3527374642@qq.com"},
		{"���",   "18932147635", "18887154321", "0371-27363623", "0372-7263523", "226383726",  NULL,          "maba@163.com",         NULL},
		{"������", "13587126834", NULL,          "028-287362373", "028-76365253", "1029383423", NULL,          "zhangsanfeng@163.com", "sanfeng.zhang@gmail.com"},
		{NULL,     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
		};
	char input_str[1024];
	int  match;

	if (1) {
		cout << "��Ӽ������� �� : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� ���� : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 123 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 126 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 126.com : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 792 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 1023 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 27384 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 71 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� 037 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� sina : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� sina.com : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� san : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	if (1) {
		cout << "��Ӽ������� li : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "ƥ�������Ϊ" << match << endl;
		cout << endl << "�����������" << endl;
		getchar();
		}

	return 0;
}
