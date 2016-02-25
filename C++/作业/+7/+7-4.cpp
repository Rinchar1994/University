/* 1252337 王佳琪 电子一班 */
#include <iostream>
using namespace std;

/* 函数的原型定义不准变 */
int   tj_strlen(const char *str);
char *tj_strcat(char *s1, const char *s2);
char *tj_strcpy(char *s1, const char *s2);
char *tj_strncpy(char *s1, const char *s2, const int len);
int   tj_strcmp(const char *s1, const char *s2);
int   tj_strcasecmp(const char *s1, const char *s2);
int   tj_strncmp(const char *s1, const char *s2, const int len);
int   tj_strcasencmp(const char *s1, const char *s2, const int len);
char *tj_strupr(char *str);
char *tj_strlwr(char *str);
int   tj_strchr(const char *str, const char ch);
int   tj_strstr(const char *str, const char *substr);
int   tj_strrchr(const char *str, const char ch);
int   tj_strrstr(const char *str, const char *substr);
char *tj_strrev(char *str);

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */
int tj_strlen(const char *str)
{
    int n=0;
	for(;*str!=0;str++)
		n=n+1;
	return n;

}

char *tj_strcat(char *s1, const char *s2)
{
	char *x=s1;
    for(;;s1++)
	{ 
		if(*s1!=0)
			*s1=*s1;
		else break;
	}
	for(;;s1++,s2++)
	{
		*s1=*s2;
	    if(*s2==0)
			break;
				
	}
	s1=x;
    return s1;
}
	

char *tj_strcpy(char *s1, const char *s2)
{
	char *x=s1;
	for(;;s1++,s2++)
	{
		*s1=*s2;
	    if(*s2==0)
		    break;
	}
	s1=x;
    return s1;
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
	char *x=s1;
	for(;;s1++,s2++)
	{
		if (*s2==0)
			break;
		*s1=*s2;
	}
	s1=x;
    return s1;
}

int tj_strcmp(const char *s1, const char *s2)
{
	for(;;s1++,s2++)
	{
		if(*s1!=*s2||*s1==0||*s2==0)
			break;
	}
	int m=*s1-*s2;

    return m;
}

int tj_strcasecmp(const char *s1, const char *s2)
{
	int x,y;
	for(;;s1++,s2++)
	{
		
		if(*s1>=65&&*s1<=90)
			x=*s1+32;
		else x=*s1;
		if(*s2>=65&&*s2<=90)
		     y=*s2+32;
		else y=*s2;
		if(x!=y||x==0||y==0)
			break;
	}
	int m=x-y;

    return m;
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
	int sum=0;
	for(;;s1++,s2++)
	{
		sum++;
		if(*s1!=*s2||*s1==0||*s2==0||sum==len)
			break;
	}
	int m=*s1-*s2;

    return m;
    
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
	int x,y,sum=0;
	for(;;s1++,s2++)
	{
		sum++;
		
		if(*s1>=65&&*s1<=90)
			x=*s1+32;
		else x=*s1;
		if(*s2>=65&&*s2<=90)
		     y=*s2+32;
		else y=*s2;
		if(x!=y||x==0||y==0||sum==len)
			break;
	}
	int m=x-y;

    return m;
}

char *tj_strupr(char *str)
{
	char *x=str;
	for(;;str++)
	{
		if(*str>=97&&*str<=122)
			*str=*str-32;
		else if(*str!=0)
			*str=*str;
		else break;
	}
	str=x;
    return str;
}

char *tj_strlwr(char *str)
{
    char *x=str;
	for(;;str++)
	{
		if(*str>=65&&*str<=90)
			*str=*str+32;
		else if(*str!=0)
			*str=*str;
		else break;
	}
	str=x;
    return str;
}

int tj_strchr(const char *str, const char ch)
{
	int n=0;
	for(;;str++)
	{
		if (*str!=ch&&*str!=0)
			n--;
		else if (*str==ch)
			break;
		else if (*str==0)
		{
			n=1;
			break;
		}
	}

    return 1-n;
}

int tj_strstr(const char *str, const char *substr)
{
    int n=0,m,sum=0;
	int tj_strlen(const char *str);
	m=tj_strlen(substr);
	for(;;str++)
	{
		if (*str!=*substr && *str!=0)
			n--;
		else if (*str==*substr)
		{
			for(;;str++,substr++)
				if(*substr==0)
					break;
				else if(*str==*substr)
					sum++;
				n--;
		}
		if (sum==m)
		{
			n++;
			break;
		}
		else if(sum!=0)
		{
			sum=0;
			substr-=m;
			str-=m;
		}
		else if (*str==0)
		{
			n=1;
			break;
		}
    	
	}
    return 1-n;
}

int tj_strrchr(const char *str, const char ch)
{
    int n=0,m,k;
	int tj_strlen(const char *str);
	m=tj_strlen(str);
	for(k=1;k<=m;str++)
	{
		k++;
		if (*str!=ch&&*str!=0)
			n--;
		else if (*str==ch)
			break;
		else if (*str==0)
		{
			n=1;
			break;
		}
	}

    return 1-n;

}

int tj_strrstr(const char *str, const char *substr)
{
    int n=0,m,sum=0,y,k;
	m=tj_strlen(substr);
	y=tj_strlen(str);
	for(k=1,str=str+y-1;k<=y;str--,k++)//判断条件不能是y-m，因为你得判断到头截止
	{ 
		if (*str!=*substr)
			n++;
		else if (*str==*substr)
		{
			for(;;str++,substr++)
				if(*substr==0)
					break;
				else if(*str==*substr)
					sum++;
				n++;
		}
		if (sum==m)
		{
			n--;
			return y-n;//这里用break的话会导致一种情况出现二义性：str=abcde，substr=abcde
		}              //若break，则这里跳出循环，但是n=y-1，这样会在下面返回0，仔细想想
		else if (sum!=0)
		{
			sum=0;
			substr-=m;//小循环中str++,所以这里得减掉。
			str-=m;
		}
	}	
	n=n-y+1;
	if(n==0 )
		n=1;
    return 1-n;
}

char *tj_strrev(char *str)
{
    return str;
}
/* ==The End==(函数实现部分) */

int main()
{
    if (1) {
        char s1[]="abcdefghijklmnopqrstuvwxyz";
        char s2[]="abcdefghijklmnopqrstuvwxyz\0UVWXYZ";
        char s3[]="";

        cout << "tj_strlen()测试部分：" << endl;
        cout << "1.s1     的长度应该是26，实际是：" << tj_strlen(s1)      << endl;
        cout << "2.s2     的长度应该是26，实际是：" << tj_strlen(s2)      << endl;
        cout << "3.&s2[27]的长度应该是6， 实际是：" << tj_strlen(&s2[27]) << endl;
        cout << "4.s3     的长度应该是0， 实际是：" << tj_strlen(s3)      << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
        }

    if (1) {
        char s1[80]="abcdefghij";
        char s2[]="abcde";
        char s3[]="hello\0UVWXYZ";

        cout << "tj_strcat()测试部分：" << endl;
        cout << "1.s1的输出应该是abcdefghij，                实际是：" << s1 << endl;
        cout << "  s1的长度应该是10，                        实际是：" << tj_strlen(s1) << endl;

        cout << "2.s1的输出应该是abcdefghijabcde，           实际是：" << tj_strcat(s1, s2) << endl;
        cout << "  s1的长度应该是15，                        实际是：" << tj_strlen(s1)     << endl;

        cout << "3.s1的输出应该是abcdefghijabcdehello，      实际是：" << tj_strcat(s1, s3) << endl;
        cout << "  s1的长度应该是20，                        实际是：" << tj_strlen(s1)     << endl;

        cout << "4.s1的输出应该是abcdefghijabcdehelloUVWXYZ，实际是：" << tj_strcat(s1, &s3[6]) << endl;
        cout << "  s1的长度应该是26，                        实际是：" << tj_strlen(s1)         << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

    if (1) {
        char s1[80]="abcdefghijklm";
        char s2[]="abcde";
        char s3[]="hello\0UVWXYZ";
        char s4[80];

        cout << "tj_strcpy()测试部分：" << endl;
        cout << "1.s1的输出应该是abcdefghijklm，   实际是：" << s1            << endl;
        cout << "  s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        cout << "2.s1的输出应该是abcde，           实际是：" << tj_strcpy(s1, s2) << endl;
        cout << "  s1的长度应该是5，               实际是：" << tj_strlen(s1)     << endl;

        cout << "3.s1的输出应该是UVWXYZ，          实际是：" << tj_strcpy(s1, &s3[6]) << endl;
        cout << "  s1的长度应该是6，               实际是：" << tj_strlen(s1)         << endl;

        cout << "4.s1的输出应该是hello，           实际是：" << tj_strcpy(s1, s3) << endl;
        cout << "  s1的长度应该是5，               实际是：" << tj_strlen(s1)     << endl;

        tj_strcpy(s4, s2);
        tj_strcat(s4, s3);
        cout << "5.s4的输出应该是abcdehelloUVWXYZ，实际是：" << tj_strcat(s4, &s3[6]) << endl;
        cout << "  s4的长度应该是16，              实际是：" << tj_strlen(s4)         << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

    if (1) {
        char s1[80]="abcdefghijklm";
        char s2[]="abcde";
        char s3[]="hello\0UVWXYZ";
        char s4[80];

        cout << "tj_strncpy()测试部分：" << endl;
        cout << " 1.s1的输出应该是abcdefghijklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        cout << " 2.s1的输出应该是hellofghijklm，   实际是：" << tj_strncpy(s1, s3, 10) << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1)          << endl;

        tj_strcpy(s1, "abcdefghijklm");
        cout << " 3.s1的输出应该是hellofghijklm，   实际是：" << tj_strncpy(s1, s3, 5) << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1)         << endl;

        tj_strcpy(s1, "abcdefghijklm");
        cout << " 4.s1的输出应该是heldefghijklm，   实际是：" << tj_strncpy(s1, s3, 3) << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1)         << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 10);
        cout << " 5.s1的输出应该是abcdhellojklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 5);
        cout << " 6.s1的输出应该是abcdhellojklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], s3, 3);
        cout << " 7.s1的输出应该是abcdhelhijklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
       tj_strncpy(&s1[4], &s3[6], 10);
        cout << " 8.s1的输出应该是abcdUVWXYZklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
		tj_strncpy(&s1[4], &s3[6], 6);
        cout << " 9.s1的输出应该是abcdUVWXYZklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strcpy(s1, "abcdefghijklm");
        tj_strncpy(&s1[4], &s3[6], 3);
        cout << "10.s1的输出应该是abcdUVWhijklm，   实际是：" << s1            << endl;
        cout << "   s1的长度应该是13，              实际是：" << tj_strlen(s1) << endl;

        tj_strncpy(s4, s2, tj_strlen(s2));
        s4[tj_strlen(s2)] = 0;
        cout << "11.s4的输出应该是abcde，           实际是：" << s4            << endl;
        cout << "   s4的长度应该是5，               实际是：" << tj_strlen(s4) << endl;

        cout << "12.s4的输出应该是abcdehello，      实际是：" << tj_strcat(s4, s3) << endl;
        cout << "   s4的长度应该是10，              实际是：" << tj_strlen(s4)     << endl;
        
        int old_len = tj_strlen(s4);
        tj_strncpy(&s4[10], &s3[6], tj_strlen(&s3[6]));
        s4[old_len + tj_strlen(&s3[6]) ] = 0;
        cout << "13.s4的输出应该是abcdehelloUVWXYZ，实际是：" << s4            << endl;
        cout << "   s4的长度应该是16，              实际是：" << tj_strlen(s4) << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";

        cout << "tj_strcmp()测试部分：" << endl;
        cout << "1.s1 和s2 的输出应该是-3，  实际是：" << tj_strcmp(s1,  s2)  << endl;
        cout << "2.s3 和s4 的输出应该是-111，实际是：" << tj_strcmp(s3,  s4)  << endl;
        cout << "3.s5 和s6 的输出应该是111， 实际是：" << tj_strcmp(s5,  s6)  << endl;
        cout << "4.s7 和s8 的输出应该是0，   实际是：" << tj_strcmp(s7,  s8)  << endl;
        cout << "5.s9 和s10的输出应该是0，   实际是：" << tj_strcmp(s9,  s10) << endl;
        cout << "6.s11和s12的输出应该是-32， 实际是：" << tj_strcmp(s11, s12) << endl;
        cout << "7.s13和s14的输出应该是-32， 实际是：" << tj_strcmp(s13, s14) << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";

        cout << "tj_strcasecmp()测试部分：" << endl;
        cout << "1.s1 和s2 的输出应该是-3，  实际是：" << tj_strcasecmp(s1,  s2)  << endl;
        cout << "2.s3 和s4 的输出应该是-111，实际是：" << tj_strcasecmp(s3,  s4)  << endl;
        cout << "3.s5 和s6 的输出应该是111， 实际是：" << tj_strcasecmp(s5,  s6)  << endl;
        cout << "4.s7 和s8 的输出应该是0，   实际是：" << tj_strcasecmp(s7,  s8)  << endl;
        cout << "5.s9 和s10的输出应该是0，   实际是：" << tj_strcasecmp(s9,  s10) << endl;
        cout << "6.s11和s12的输出应该是0，   实际是：" << tj_strcasecmp(s11, s12) << endl;
        cout << "7.s13和s14的输出应该是0，   实际是：" << tj_strcasecmp(s13, s14) << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";

        cout << "tj_strncmp()测试部分：" << endl;
        cout << "1.s1 和s2 比较前10个字符的输出应该是-3，  实际是：" << tj_strncmp(s1,  s2,  10) << endl;
        cout << "  s1 和s2 比较前5 个字符的输出应该是-3，  实际是：" << tj_strncmp(s1,  s2,  5)  << endl;
        cout << "  s1 和s2 比较前3 个字符的输出应该是-3，  实际是：" << tj_strncmp(s1,  s2,  3)  << endl;
        cout << "  s1 和s2 比较前2 个字符的输出应该是0，   实际是：" << tj_strncmp(s1,  s2,  2)  << endl;
        cout << "2.s3 和s4 比较前10个字符的输出应该是-111，实际是：" << tj_strncmp(s3,  s4,  10) << endl;
        cout << "  s3 和s4 比较前5 个字符的输出应该是-111，实际是：" << tj_strncmp(s3,  s4,  5)  << endl;
        cout << "  s3 和s4 比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s3,  s4,  4)  << endl;
        cout << "3.s5 和s6 比较前10个字符的输出应该是111 ，实际是：" << tj_strncmp(s5,  s6,  10) << endl;
        cout << "  s5 和s6 比较前5 个字符的输出应该是111， 实际是：" << tj_strncmp(s5,  s6,  5)  << endl;
        cout << "  s5 和s6 比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s5,  s6,  4)  << endl;
        cout << "4.s7 和s8 比较前10个字符的输出应该是0 ，  实际是：" << tj_strncmp(s7,  s8,  10) << endl;
        cout << "  s7 和s8 比较前5 个字符的输出应该是0，   实际是：" << tj_strncmp(s7,  s8,  5)  << endl;
        cout << "  s7 和s8 比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s7,  s8,  4)  << endl;
        cout << "5.s9 和s10比较前10个字符的输出应该是0 ，  实际是：" << tj_strncmp(s9,  s10, 10) << endl;
        cout << "  s9 和s10比较前5 个字符的输出应该是0，   实际是：" << tj_strncmp(s9,  s10, 5)  << endl;
        cout << "  s9 和s10比较前4 个字符的输出应该是0，   实际是：" << tj_strncmp(s9,  s10, 4)  << endl;
        cout << "6.s11和s12比较前10个字符的输出应该是-32， 实际是：" << tj_strncmp(s11, s12, 10) << endl;
        cout << "  s11和s12比较前5 个字符的输出应该是-32， 实际是：" << tj_strncmp(s11, s12, 5)  << endl;
        cout << "  s11和s12比较前2 个字符的输出应该是-32， 实际是：" << tj_strncmp(s11, s12, 2)  << endl;
        cout << "7.s13和s14比较前10个字符的输出应该是-32， 实际是：" << tj_strncmp(s13, s14, 10) << endl;
        cout << "  s13和s14比较前5 个字符的输出应该是-32， 实际是：" << tj_strncmp(s13, s14, 5)  << endl;
        cout << "  s13和s14比较前2 个字符的输出应该是-32， 实际是：" << tj_strncmp(s13, s14, 2)  << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

    if (1) {
        char s1[]="horse";
        char s2[]="house";
        char s3[]="hell";
        char s4[]="hello";
        char s5[]="hello";
        char s6[]="hell";
        char s7[]="hello";
        char s8[]="hello";
        char s9[]="hello";
        char s10[]="hello\0UVWXYZ";
        char s11[]="HELLO";
        char s12[]="hello";
        char s13[]="HeLlO";
        char s14[]="hElLo";

        cout << "tj_strcasencmp()测试部分：" << endl;
        cout << "1.s1 和s2 比较前10个字符的输出应该是-3，  实际是：" << tj_strcasencmp(s1,  s2,  10) << endl;
        cout << "  s1 和s2 比较前5 个字符的输出应该是-3，  实际是：" << tj_strcasencmp(s1,  s2,  5)  << endl;
        cout << "  s1 和s2 比较前3 个字符的输出应该是-3，  实际是：" << tj_strcasencmp(s1,  s2,  3)  << endl;
        cout << "  s1 和s2 比较前2 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s1,  s2,  2)  << endl;
        cout << "2.s3 和s4 比较前10个字符的输出应该是-111，实际是：" << tj_strcasencmp(s3,  s4,  10) << endl;
        cout << "  s3 和s4 比较前5 个字符的输出应该是-111，实际是：" << tj_strcasencmp(s3,  s4,  5)  << endl;
        cout << "  s3 和s4 比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s3,  s4,  4)  << endl;
        cout << "3.s5 和s6 比较前10个字符的输出应该是111 ，实际是：" << tj_strcasencmp(s5,  s6,  10) << endl;
        cout << "  s5 和s6 比较前5 个字符的输出应该是111， 实际是：" << tj_strcasencmp(s5,  s6,  5)  << endl;
        cout << "  s5 和s6 比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s5,  s6,  4)  << endl;
        cout << "4.s7 和s8 比较前10个字符的输出应该是0 ，  实际是：" << tj_strcasencmp(s7,  s8,  10) << endl;
        cout << "  s7 和s8 比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s7,  s8,  5)  << endl;
        cout << "  s7 和s8 比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s7,  s8,  4)  << endl;
        cout << "5.s9 和s10比较前10个字符的输出应该是0 ，  实际是：" << tj_strcasencmp(s9,  s10, 10) << endl;
        cout << "  s9 和s10比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s9,  s10, 5)  << endl;
        cout << "  s9 和s10比较前4 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s9,  s10, 4)  << endl;
        cout << "6.s11和s12比较前10个字符的输出应该是0，   实际是：" << tj_strcasencmp(s11, s12, 10) << endl;
        cout << "  s11和s12比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s11, s12, 5)  << endl;
        cout << "  s11和s12比较前2 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s11, s12, 2)  << endl;
        cout << "7.s13和s14比较前10个字符的输出应该是0，   实际是：" << tj_strcasencmp(s13, s14, 10) << endl;
        cout << "  s13和s14比较前5 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s13, s14, 5)  << endl;
        cout << "  s13和s14比较前2 个字符的输出应该是0，   实际是：" << tj_strcasencmp(s13, s14, 2)  << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

     if (1) {
        char s1[]="123horseHELLO*#@";
        char s2[]="1A2b3C*d#E@f";

        cout << "tj_strupr()测试部分：" << endl;
        cout << "1.s1 的输出应该是123HORSEHELLO*#@，实际是：" << tj_strupr(s1) << endl;
        cout << "2.s2 的输出应该是1A2B3C*D#E@F，    实际是：" << tj_strupr(s2) << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

     if (1) {
        char s1[]="123horseHELLO*#@";
        char s2[]="1A2b3C*d#E@f";

        cout << "tj_strlwr()测试部分：" << endl;
        cout << "1.s1 的输出应该是123horsehello*#@，实际是：" << tj_strlwr(s1) << endl;
        cout << "2.s2 的输出应该是1a2b3c*d#e@f，    实际是：" << tj_strlwr(s2) << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

     if (1) {
        char s1[]="This is a pencil.";

        cout << "tj_strchr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1，实际是：" << tj_strchr(s1, 'T') << endl;
        cout << "2.s1 的输出应该是3，实际是：" << tj_strchr(s1, 'i') << endl;
        cout << "3.s1 的输出应该是5，实际是：" << tj_strchr(s1, ' ') << endl;
        cout << "4.s1 的输出应该是0，实际是：" << tj_strchr(s1, 'x') << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

     if (1) {
        char s1[]="This is a pencil.";
        char s2[]="aabbbceddbbbceeeff";
        char s3[]="abcde";

        cout << "tj_strstr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1， 实际是：" << tj_strstr(s1, "T")      << endl;
        cout << "  s1 的输出应该是3， 实际是：" << tj_strstr(s1, "is")     << endl;
        cout << "  s1 的输出应该是11，实际是：" << tj_strstr(s1, "pencil") << endl;
        cout << "  s1 的输出应该是0， 实际是：" << tj_strstr(s1, "Pencil") << endl;
        cout << "2.s2 的输出应该是3， 实际是：" << tj_strstr(s2, "bb")     << endl;
        cout << "  s2 的输出应该是3， 实际是：" << tj_strstr(s2, "bbb")    << endl;
        cout << "  s2 的输出应该是4， 实际是：" << tj_strstr(s2, "bbc")    << endl;
        cout << "  s2 的输出应该是0， 实际是：" << tj_strstr(s2, "bbbb")   << endl;
        cout << "  s2 的输出应该是6， 实际是：" << tj_strstr(s2, "ce")     << endl;
        cout << "  s2 的输出应该是13，实际是：" << tj_strstr(s2, "cee")    << endl;
        cout << "3.s3 的输出应该是1， 实际是：" << tj_strstr(s3, "abcde")  << endl;
        cout << "  s3 的输出应该是0， 实际是：" << tj_strstr(s3, "abcdef") << endl;


        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}
	
     if (1) {
        char s1[]="This is a pencil.";

        cout << "tj_strrchr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1， 实际是：" << tj_strrchr(s1, 'T') << endl;
        cout << "2.s1 的输出应该是15，实际是：" << tj_strrchr(s1, 'i') << endl;
        cout << "3.s1 的输出应该是10，实际是：" << tj_strrchr(s1, ' ') << endl;
        cout << "4.s1 的输出应该是0， 实际是：" << tj_strrchr(s1, 'x') << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
	}

     if (1) {
        char s1[]="This is a pencil.";
        char s2[]="aabbbceddbbbceeeff";
        char s3[]="abcde";

        cout << "tj_strrstr()测试部分：" << endl;
        cout << "1.s1 的输出应该是1， 实际是：" << tj_strrstr(s1, "T")      << endl;
        cout << "  s1 的输出应该是6， 实际是：" << tj_strrstr(s1, "is")     << endl;
        cout << "  s1 的输出应该是11，实际是：" << tj_strrstr(s1, "pencil") << endl;
        cout << "  s1 的输出应该是0， 实际是：" << tj_strrstr(s1, "Pencil") << endl;
        cout << "2.s2 的输出应该是11，实际是：" << tj_strrstr(s2, "bb")     << endl;
        cout << "  s2 的输出应该是10，实际是：" << tj_strrstr(s2, "bbb")    << endl;
        cout << "  s2 的输出应该是11，实际是：" << tj_strrstr(s2, "bbc")    << endl;
        cout << "  s2 的输出应该是0， 实际是：" << tj_strrstr(s2, "bbbb")   << endl;
        cout << "  s2 的输出应该是13，实际是：" << tj_strrstr(s2, "ce")     << endl;
        cout << "  s2 的输出应该是13，实际是：" << tj_strrstr(s2, "cee")    << endl;
        cout << "3.s3 的输出应该是1， 实际是：" << tj_strrstr(s3, "abcde")  << endl;
        cout << "  s3 的输出应该是0， 实际是：" << tj_strrstr(s3, "abcdef") << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
        }
	
     if (1) {
        char s1[]="This is a pencil.";
        char s2[]="aabbbceddbbbceeeff";
        char s3[]="";

        cout << "tj_strrev()测试部分：" << endl;
        cout << "1.s1 的输出应该是This is a pencil.，  实际是：" << s1 << endl;
        cout << "  s1 的输出应该是.licnep a si sihT，  实际是：" << tj_strrev(s1) << endl;

        cout << "2.s2 的输出应该是aabbbceddbbbceeeff， 实际是：" << s2 << endl;
        cout << "  s2 的输出应该是ffeeecbbbddecbbbaa， 实际是：" << tj_strrev(s2) << endl;

        cout << "3.s3 的输出应该是--， 实际是：-" << s3            << "-" << endl;
        cout << "  s3 的输出应该是--， 实际是：-" << tj_strrev(s3) << "-" << endl;

        cout << endl << "按回车键继续" <<endl << endl;
        getchar();
        }
	

    return 0;
}
