/* 学号 姓名 班级 */

/* 如有必要，可增减头文件 */
#include <iostream.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
//using namespace std;

/* 此处给出 TString 类的定义与实现 */

class TString {
	private:
		char *content;
		int   len;
	public:
		TString();	
		~TString();	
		int length();	
		TString& operator += ( char *str);
		bool operator != ( char *b );

};

bool TString::operator != ( char *b )
{
	if ( len!=strlen(b) )
		return 1;
	else
		return 0;
}

TString& TString::operator += ( char *str)
{
	len = len + strlen( str );
	delete content;
	content = new char[len+1];
	return *this;
}

TString::TString()
{
	content = NULL;
	len     = 0;
}

TString::~TString()
{
	if (content)
		delete content;
}

int TString::length()
{
	return len;
}


/* main函数不允许有任何改动 */
int main()
{
	if (1) {
		const int MAX_BYTES = 100*1024*1024;
		TString s1;

		int     total, len, i;
		char    temp[65536];
		long    t_start, t_end;
		char   *crc_str;

		cout << "内存累加申请性能测试，以内存耗尽或申请满100MB字节为结束条件，按任意键开始" << endl;
		getch();

		crc_str = new char[MAX_BYTES+65536]; //申请（100MB+64KB）空间
		*crc_str = 0; //置为空串

		t_start = GetTickCount(); //取当前系统时间，单位毫秒
		srand(time(0));
		total = 0;
		while(1) {
			len = 32768 + rand()%32768;

			cout << "s1已有长度：" << s1.length()/(1024.0*1024) << " MB字节，本次增加 " << len << " 字节" << endl;
			for(i=0; i<len; i++)
				temp[i] = ' '+rand()%95;	//数组用随机字符填充
			temp[len] = 0;
			total += len;
			s1 += temp;
			strcat(crc_str, temp);
			if (s1.length()==0 || s1.length() > MAX_BYTES)	//满100MB或内存耗尽则结束
				break;
			}
		t_end = GetTickCount();   //取当前系统时间

		cout << "time=" << (t_end - t_start)/1000.0 << endl; 
		if (s1.length()==0)
			cout << "内存分配到达 " << total/(1024.0*1024) << " MB字节后，内存耗尽" << endl;
		else
			cout << "内存分配到达满100MB，测试结束" << endl;

		if (s1!=crc_str)
			cout << "s1累加验证出错，请检查程序的实现部分" << endl;
		else
			cout << "    本次测试耗时 " << (t_end - t_start)/1000.0 << "秒" << endl;

		delete crc_str;

	//	cout << endl << "任意键继续..." << endl;
	//	getch();
		cout << endl;
		}

	system("pause");

	return 0;
}
