/* 1252366 ���賬 ����һ�� */
#include <iostream>
#include <cstring>
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
int tj_strstr(const char *str, const char *substr, int a)
{
	for( ; *str!=0; str++)
	{
		if(strncmp(str, substr, a)==0)
			return 1;
	}
	return 0;
}

int tj_strstr2(const char *str, const char *substr, int a)
{
	for( ; *str!=0; str+=2)
	{
		if(strncmp(str, substr, a)==0)
			return 1;
	}
	return 0;
}


/* ���Һ��������岻Ҫ����ʵ�ּ��� */
int search_list(struct address_list *list, char *item)
{
	int number=0, a;
	a=strlen( item );
	for( int i=0; list[i].name!=NULL; i++)
	{
		if(tj_strstr2( list[i].name,  item, a)==1)
		{
			cout << list[i].name << endl;
		    number+=1;
		}
		if(list[i].mobilephone1!=NULL)
			if(tj_strstr( list[i].mobilephone1,  item, a)==1)
			{
				cout << list[i].mobilephone1 << endl;
		        number+=1;
			}
		if(list[i].mobilephone2!=NULL)
			if(tj_strstr( list[i].mobilephone2,  item, a)==1)
			{
				cout << list[i].mobilephone2 << endl;
		        number+=1;
			}
		if(list[i].phone_1!=NULL)
			if(tj_strstr( list[i].phone_1,  item, a)==1)
			{
				cout << list[i].phone_1 << endl;
		        number+=1;
			}
		if(list[i].phone_2!=NULL)
		    if(tj_strstr( list[i].phone_2,  item, a)==1)
			{
				cout << list[i].phone_2 << endl;
		        number+=1;
			}
		if(list[i].qq_1!=NULL)
	    	if(tj_strstr( list[i].qq_1,  item, a)==1)
			{
				cout << list[i].qq_1 << endl;
		        number+=1;
			}
		if(list[i].qq_2!=NULL)
	    	if(tj_strstr( list[i].qq_2, item, a)==1)
			{
				cout << list[i].qq_2 << endl;
		        number+=1;
			}
		if(list[i].email_1!=NULL)
	    	if(tj_strstr( list[i].email_1,  item, a)==1)
			{
				cout << list[i].email_1 << endl;
		        number+=1;
			}
		if(list[i].email_2!=NULL)
		    if(tj_strstr( list[i].email_2,  item, a)==1)
			{
				cout << list[i].email_2 << endl;
		        number+=1;
			}
	}

	return number;	//����Ϊƥ������������һ����������ƥ�䣬��3��ĿǰΪ0���ɸģ�
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
