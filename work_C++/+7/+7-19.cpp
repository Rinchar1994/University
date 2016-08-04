/* 1252337 ������ ����һ�� */
#include <iostream.h>
#include <string.h>
#include <conio.h>		//getch()����Ҫ������ͷ�ļ�
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//using namespace std;

class TString {
	private:
		char *content;
		int   len;
	public:
		TString(char *str=NULL);	/* ���幹�캯�� */
		~TString();			/* ������������ */
		int length();			/* ����length()���� */
	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
		TString( const TString &a );
		friend ostream &operator <<(ostream&,TString&);
		TString operator = (TString &c2);
		TString operator = (char *str);
		friend istream &operator >>(istream&,TString&);
        friend TString operator +(TString &c1,TString &c2);

};
TString::TString( const TString &a )
{
	if (a.content==NULL || a.content[0]==0) {
		content = NULL;
		len     = 0;
		}
	else {
		len     = strlen(a.content);
		content = new char[len+1];
		if (content)
			strcpy(content, a.content); //��'\0'����
		else {
			/* ���벻���ռ����� */
			content = NULL;
			len     = 0;
			}
		}
}

TString::TString(char *str)		//�������ٴ�ȱʡֵ
{
	// ���ȿ���strΪNULL��strΪ�մ������
	if (str==NULL || str[0]==0) {
		content = NULL;
		len     = 0;
		}
	else {
		len     = strlen(str);
		content = new char[len+1];
		if (content)
			strcpy(content, str); //��'\0'����
		else {
			/* ���벻���ռ����� */
			content = NULL;
			len     = 0;
			}
		}

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


ostream &operator <<(ostream&output,TString&c)
{
    if (c.content==NULL) 
	{
		output<<"<NULL>";
	}
	else 
	{
		output<<c.content;
	//��'\0'����
	}
	return output;
}

istream &operator >>(istream&input,TString&c)
{
	if (c.content)
		delete c.content;
	char *str=new char[1024];
	input>>str;
	c.len     = strlen(str);
	c.content = new char[c.len+1];
	if (c.content)
		strcpy(c.content, str); //��'\0'����
	else {
			/* ���벻���ռ����� */
		c.content = NULL;
		c.len     = 0;
		}
	delete []str;
	return input;
}

TString TString::operator = (TString &c2)
{
	if( content )
		delete content;
	if (c2.content==NULL || c2.content[0]==0) {
		content = NULL;
		len     = 0;
		}
	else {
		len     = c2.len;
		content = new char[c2.len+1];
		if (content)
			strcpy(content, c2.content); //��'\0'����
		else {
			/* ���벻���ռ����� */
		    content = NULL;
			len     = 0;
			}
		}
	return *this;

}

TString TString::operator = (char *str)
{
	if( content )
		delete content;

	if (str==NULL || str[0]==0) {
		content = NULL;
		len     = 0;
		}
	else {
		len     = strlen(str);
		content = new char[len+1];
		if (content)
			strcpy(content, str); //��'\0'����
		else {
			/* ���벻���ռ����� */
			content = NULL;
			len     = 0;
			}
		}
	return *this;
}


//TString operator +(TString &c1,TString &c2)
//{

  
/* ----main������׼��---- */
int main()
{
	if (1) {
		TString s1;                  //s1ΪNULL
		TString s2("teststr2");      //s2Ϊ"teststr2"
		TString s3="teststr3";       //s3Ϊ"teststr3"
		TString s4=NULL;             //s4ΪNULL
		TString s5="";               //s5ΪNULL

		cout << "������󲢳�ʼ������(NULL���ַ���������ʼ��)" << endl;

		cout << "s1Ӧ����<NULL>��  ʵ�������" << s1 << endl;
		cout << "s2Ӧ����teststr2��ʵ�������" << s2 << endl;
		cout << "s3Ӧ����teststr3��ʵ�������" << s3 << endl;
		cout << "s4Ӧ����<NULL>��  ʵ�������" << s4 << endl;
		cout << "s5Ӧ����<NULL>��  ʵ�������" << s5 << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s0   = "teststr1";
		char *str1   = "teststr2";
		char  str2[] = "teststr3";
		char *str3   = NULL;
		char  str4[] = "";
		TString s1=s0, s2=str1, s3=str2, s4=str3, s5=str4;

		cout << "������󲢳�ʼ������(TString�����ַ�ָ�롢�ַ�����)" << endl;

		cout << "s1Ӧ����teststr1��ʵ�������" << s1 << endl;
		cout << "s2Ӧ����teststr2��ʵ�������" << s2 << endl;
		cout << "s3Ӧ����teststr3��ʵ�������" << s3 << endl;
		cout << "s4Ӧ����<NULL>��  ʵ�������" << s4 << endl;
		cout << "s5Ӧ����<NULL>��  ʵ�������" << s5 << endl;
		
		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1;
		
		cout << "����cin����" << endl;
		
		cout << "���ڼ���������Hello" << endl;
		cin >> s1;
		cout << "s1Ӧ����Hello��ʵ�������" << s1 << endl;

		cout << "���ڼ���������Hello 123" << endl;
		cin >> s1;
		cout << "s1Ӧ����Hello��ʵ�������" << s1 << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1("Hello"), s2;
		
		cout << "��ֵ��������" << endl;

		cout << "s1Ӧ����Hello�� ʵ�������" << s1 << endl;
		
		s2=s1;
		cout << "s2Ӧ����Hello�� ʵ�������" << s2 << endl;
		
		s1="Hi";
		cout << "s1Ӧ����Hi��    ʵ�������" << s1 << endl;
		
		s2="";
		cout << "s2Ӧ����<NULL>��ʵ�������" << s2 << endl;

		s1=NULL;
		cout << "s1Ӧ����<NULL>��ʵ�������" << s1 << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

/*	if (1) {
		TString s0, s1("tong"), s2("ji"), s3;

		cout << "����(+)����(����TString��)"<< endl;
		
		s3 = s1+s2;
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;
		
		s3 = s2+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+s0;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = s0+s2;
		cout << "s3ӦΪji��    ʵ�������" << s3 << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

/*	if (1) {
		TString s1("tong"), s3;

		cout << "����(+)����(TString����ַ�������)"<< endl;

		s3 = s1+"ji";
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;
		
		s3 = "ji"+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+"";
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = s1+NULL;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = ""+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = NULL+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1("tong"), s3;
		char *str1="ji", *str2="", *str3=NULL;

		cout << "����(+)����(TString����ַ�ָ��)"<< endl;

		s3 = s1+str1;
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;
		
		s3 = str1+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+str2;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = str2+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = s1+str3;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = str3+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1("tong"), s3;
		char str1[]="ji", str2[]="";

		cout << "����(+)����(TString����ַ�����)"<< endl;

		s3 = s1+str1;
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;
		
		s3 = str1+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+str2;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = str2+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1="house", s2="horse", s3="house", s4="", s5=NULL;

		cout << "�Ƚ��������(����TString��)" << endl;

		cout << "��1=" << s1 << " ��2=" << s2 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != s2) << endl;
		
		cout << "��1=" << s1 << " ��3=" << s3 << " > ���ӦΪ0��ʵ�ʣ�" <<(s1 >  s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << " <=���ӦΪ1��ʵ�ʣ�" <<(s1 <= s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << " ==���ӦΪ1��ʵ�ʣ�" <<(s1 == s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << " !=���ӦΪ0��ʵ�ʣ�" <<(s1 != s3) << endl;

		cout << "��1=" << s1 << " ��4=" << s4 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != s4) << endl;

		cout << "��1=" << s1 << " ��5=" << s5 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != s5) << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1="house";

		cout << "�Ƚ��������(TString����ַ�������)" << endl;

		cout << "��1=" << s1 << " ����=horse" << " > ���ӦΪ1��ʵ�ʣ�" << (s1 >  "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 <  "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != "horse") << endl;

		cout << "��1=" << s1 << " ����=house" << " > ���ӦΪ0��ʵ�ʣ�" << (s1 >  "house") << endl;
		cout << "��1=" << s1 << " ����=house" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "house") << endl;
		cout << "��1=" << s1 << " ����=house" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 <  "house") << endl;
		cout << "��1=" << s1 << " ����=house" << " <=���ӦΪ1��ʵ�ʣ�" << (s1 <= "house") << endl;
		cout << "��1=" << s1 << " ����=house" << " ==���ӦΪ1��ʵ�ʣ�" << (s1 == "house") << endl;
		cout << "��1=" << s1 << " ����=house" << " !=���ӦΪ0��ʵ�ʣ�" << (s1 != "house") << endl;

		cout << "��1=" << s1 << " ����=" << " > ���ӦΪ1��ʵ�ʣ�" << (s1 >  "") << endl;
		cout << "��1=" << s1 << " ����=" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "") << endl;
		cout << "��1=" << s1 << " ����=" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 <  "") << endl;
		cout << "��1=" << s1 << " ����=" << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= "") << endl;
		cout << "��1=" << s1 << " ����=" << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == "") << endl;
		cout << "��1=" << s1 << " ����=" << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != "") << endl;

		cout << "��1=" << s1 << " ����=<NULL>" << " > ���ӦΪ1��ʵ�ʣ�" << (s1 >  NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 <  NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != NULL) << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}
	
	if (1) {
		TString s1="house";
		char *str2="horse", *str3="house", *str4="", *str5=NULL;

		cout << "�Ƚ��������(TString����ַ�ָ��)" << endl;

		cout << "��1=" << s1 << " ��2=" << str2 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str2) << endl;
		
		cout << "��1=" << s1 << " ��3=" << str3 << " > ���ӦΪ0��ʵ�ʣ�" <<(s1 >  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " <=���ӦΪ1��ʵ�ʣ�" <<(s1 <= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " ==���ӦΪ1��ʵ�ʣ�" <<(s1 == str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " !=���ӦΪ0��ʵ�ʣ�" <<(s1 != str3) << endl;

		cout << "��1=" << s1 << " ��4=" << str4 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str4) << endl;

		cout << "��1=" << s1 << " ��5=<NULL>" << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str5) << endl;

		
		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}
	
	if (1) {
		TString s1="house";
		char str2[]="horse", str3[]="house", str4[]="";

		cout << "�Ƚ��������(TString����ַ�ָ��)" << endl;
		
		cout << "��1=" << s1 << " ��2=" << str2 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str2) << endl;
		
		cout << "��1=" << s1 << " ��3=" << str3 << " > ���ӦΪ0��ʵ�ʣ�" <<(s1 >  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " <=���ӦΪ1��ʵ�ʣ�" <<(s1 <= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " ==���ӦΪ1��ʵ�ʣ�" <<(s1 == str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " !=���ӦΪ0��ʵ�ʣ�" <<(s1 != str3) << endl;

		cout << "��1=" << s1 << " ��4=" << str4 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str4) << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}
	
	if (1) {
		TString s1="tong", s2;

		cout << "�󳤶Ȳ���(length()����)" << endl;
		
		cout << "s1Ϊtong��  ����ӦΪ4��ʵ�ʣ�" << s1.length() << endl;
		cout << "s2Ϊ<NULL>������ӦΪ0��ʵ�ʣ�" << s2.length() << endl;
		s2 = s1+"ji";
		cout << "s2Ϊtongji������ӦΪ6��ʵ�ʣ�" << s2.length() << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1="tong", s2;

		cout << "�󳤶Ȳ���(TStringLen()����)" << endl;
		
		cout << "s1Ϊtong��  ����ӦΪ4��ʵ�ʣ�" << TStringLen(s1) << endl;
		cout << "s2Ϊ<NULL>������ӦΪ0��ʵ�ʣ�" << TStringLen(s2) << endl;
		cout << "��Ϊtongji������ӦΪ6��ʵ�ʣ�" << TStringLen(s1+(s2="ji")) << endl;
		cout << "��Ϊtongji������ӦΪ6��ʵ�ʣ�" << TStringLen(s1+"ji") << endl;
		cout << "��Ϊtongji������ӦΪ6��ʵ�ʣ�" << TStringLen(s2=s1+"ji") << endl;
		cout << "��Ϊtong��  ����ӦΪ4��ʵ�ʣ�" << TStringLen(s1+NULL) << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1;
		int     total, len, i;
		char    temp[65536];
		long    t_start, t_end;
		long    teacher_time = 850000;
		char   *crc_str;

		cout << "�ڴ����ܲ���(��Լ��Ҫ12-20����)�����ڴ�ľ���������100MB�ֽ�Ϊ�������������������ʼ" << endl;
		getch();

		crc_str = new char[100*1024*1024+65536]; //���루100MB+64KB���ռ�
		*crc_str = 0; //��Ϊ�մ�

		t_start = GetTickCount(); //ȡ��ǰϵͳʱ�䣬��λ����
		srand(time(0));
		total = 0;
		while(1) {
		    len = 32768 + rand()%32768;

			cout << "s1���г��ȣ�" << (double)total/(1024*1024) << " MB�ֽڣ��������� " << len << " �ֽ�" << endl;
			for(i=0; i<len; i++)
				temp[i] = ' '+rand()%95;	//����������ַ����
			temp[len] = 0;
			total += len;
			s1 = s1 + temp;
			strcat(crc_str, temp);
			if (s1!=crc_str) {
				cout << "s1�ۼ���֤������������ʵ�ֲ���" << endl;
				goto END;
				}
			if (s1.length()==0 || s1.length() > 1024*1024*100)	//��100MB���ڴ�ľ������
				break;
			}
		t_end = GetTickCount();   //ȡ��ǰϵͳʱ��

	    cout << "time=" << (t_end - t_start)/1000.0 << endl; 
		if (s1.length()==0)
		    cout << "�ڴ���䵽�� " << total/(1024*1024) << " MB�ֽں��ڴ�ľ�" << endl;
		else
		    cout << "�ڴ���䵽����100MB�����Խ���" << endl;
		cout << "    ���β��Ժ�ʱ " << (t_end - t_start)/1000.0 << "�룬��Լ����ʦ������" << (100.0*(t_end - t_start)/teacher_time) << "%" << endl;
		cout << "    ��˵������ֻ��VC++6.0����ϵͳ�µ����ݲ��пɱ���" << endl;
		cout << "              ��ʦ�Ļ���ΪIntel(R) Core(TM) i3-2310M CPU @2.10GHz" << endl;
		cout << "              ���ʱ�����̫�󣬳�CPU�����ܲ����⣬���п������㷨����" << endl;

		cout << endl << "���������..." << endl;
		getch();
		cout << endl;
		}
END:
	system("pause");
*/
	return 0;
}
