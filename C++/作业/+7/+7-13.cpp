/* 学号 姓名 班级 */
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

/* 可以在此定义其它需要的函数 */

/* 查找函数，定义不要动，实现即可 */
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
		
	/* 查找匹配项并打印 */

	return sum;	//返回为匹配的项数，如果一个人有三项匹配，算3（目前为0，可改）
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
