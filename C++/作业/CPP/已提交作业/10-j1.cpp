/* ѧ�� ���� �༶ */

/* ���б�Ҫ��������ͷ�ļ� */
#include <iostream.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
//using namespace std;

/* �˴����� TString ��Ķ�����ʵ�� */

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


/* main�������������κθĶ� */
int main()
{
	if (1) {
		const int MAX_BYTES = 100*1024*1024;
		TString s1;

		int     total, len, i;
		char    temp[65536];
		long    t_start, t_end;
		char   *crc_str;

		cout << "�ڴ��ۼ��������ܲ��ԣ����ڴ�ľ���������100MB�ֽ�Ϊ�������������������ʼ" << endl;
		getch();

		crc_str = new char[MAX_BYTES+65536]; //���루100MB+64KB���ռ�
		*crc_str = 0; //��Ϊ�մ�

		t_start = GetTickCount(); //ȡ��ǰϵͳʱ�䣬��λ����
		srand(time(0));
		total = 0;
		while(1) {
			len = 32768 + rand()%32768;

			cout << "s1���г��ȣ�" << s1.length()/(1024.0*1024) << " MB�ֽڣ��������� " << len << " �ֽ�" << endl;
			for(i=0; i<len; i++)
				temp[i] = ' '+rand()%95;	//����������ַ����
			temp[len] = 0;
			total += len;
			s1 += temp;
			strcat(crc_str, temp);
			if (s1.length()==0 || s1.length() > MAX_BYTES)	//��100MB���ڴ�ľ������
				break;
			}
		t_end = GetTickCount();   //ȡ��ǰϵͳʱ��

		cout << "time=" << (t_end - t_start)/1000.0 << endl; 
		if (s1.length()==0)
			cout << "�ڴ���䵽�� " << total/(1024.0*1024) << " MB�ֽں��ڴ�ľ�" << endl;
		else
			cout << "�ڴ���䵽����100MB�����Խ���" << endl;

		if (s1!=crc_str)
			cout << "s1�ۼ���֤������������ʵ�ֲ���" << endl;
		else
			cout << "    ���β��Ժ�ʱ " << (t_end - t_start)/1000.0 << "��" << endl;

		delete crc_str;

	//	cout << endl << "���������..." << endl;
	//	getch();
		cout << endl;
		}

	system("pause");

	return 0;
}
