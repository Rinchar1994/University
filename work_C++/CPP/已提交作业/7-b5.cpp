/* 1252366 蒋凌超 电子一班 */
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

/* 可以在此定义其它需要的函数 */
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


/* 查找函数，定义不要动，实现即可 */
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

	return number;	//返回为匹配的项数，如果一个人有三项匹配，算3（目前为0，可改）
}

/* 主函数，不准动 */
int main()
{
	/* 初始数组的数量随时可能发生变化，因此程序的实现中不能直接用10来表示数组有10个元素!!! */
	struct address_list list[] = {
		{"张三",   "13912345678", "18887654321", "021-65980000",  "021-69584321", "1023123",    "73636276",    "zhangsan@163.com",     "san.zhang@126.com"},
		{"李四",   "13901201234", "18601035283", "010-53629873",  NULL,           "102312301",  "6353292732",  "lisi@hotmail.com",     "lisi@gmain.com"},
		{"王五",   NULL,          "13482330973", "021-64372987",  "025-84436251", "82837323",   NULL,          "wangwu@126.com",       NULL},
		{"赵六",   "13764212387", NULL,          "0571-85239889", NULL,           "1505210003", NULL,          "zhaoliu@sohu.com",     NULL},
		{"猫三",   "13301138263", "13901037653", "0593-8152353",  "0552-7363928", "1023123",    "10293838792", "maosan@tongji.edu.cn", "maosan@qq.com"},
		{"狗四",   NULL,          NULL,          NULL,            NULL,           "2738471827", "827361523",   "gousi@sina.com.cn",    "gousi@vip.sohu.com"},
		{"牛七",   "15002220808", NULL,          "0755-62538792", NULL,           "3527374672", NULL,          "niuqi@sina.com",       "3527374642@qq.com"},
		{"马八",   "18932147635", "18887154321", "0371-27363623", "0372-7263523", "226383726",  NULL,          "maba@163.com",         NULL},
		{"张三丰", "13587126834", NULL,          "028-287362373", "028-76365253", "1029383423", NULL,          "zhangsanfeng@163.com", "sanfeng.zhang@gmail.com"},
		{NULL,     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
		};
	char input_str[1024];
	int  match;

	if (1) {
		cout << "请从键盘输入 三 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
	}

	if (1) {
		cout << "请从键盘输入 张三 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 123 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 126 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 126.com : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 792 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 1023 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 27384 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 71 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 037 : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 sina : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 sina.com : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 san : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 li : ";
		cin >> input_str;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	return 0;
}
