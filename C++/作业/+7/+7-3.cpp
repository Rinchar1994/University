/*1252337 电子一班 王佳琪*/
#include <iostream>
//#include <iomanip>
//#include <cstring>这几个头文件不用的
using namespace std;
int main()
{
	char a[200];
	cout<<"please input sentence :";
	for(int q=0; q<200; q++)
	{
		a[q]=getchar();
		if(a[q]=='\n')
		{
			for( ; q<200; q++)/* 我错了 不能用cin 因为cin 不能输入空格，误导你了，还是用你的getchar，不过这个得
							  一个一个赋值，回车表示输入结束，但是如果你没有这个for循环的话，你会被烫死的，因为是随机
							  赋值了之后。其实呢老师上课还讲了gets(a);，这个更方便，你可以试一下*/
		    	a[q]=0; 
		       
			break;
		}
	}
	for (int i=0;i<200;i++)
	{
		if (a[0]>=97 && a[0]<=122)
			a[0]=a[0]-32;        //考虑第一个字符为小写字母的情况
		if (a[i]==32&&a[i+1]!=32)
		{
			if(a[i+1]>=97&&a[i+1]<=122)
				a[i+1]=a[i+1]-32;
			/*for(int m=i-1;m>=0;m=m-1)我解释下这里的错误：
			{
				if (a[m]==32)                 假设现在输入 Wang jia qi is a student.我们现在做到了g后面的空格了
					break;                    然后你开始吧前面的大写字母都变成了小写字母，这个循环之后就成了
			    else if(a[m]>=65&&a[m]<=90)   wang Jia qi is a student. 而之后继续运行下去，w不会再变大。
					a[m]=a[m]+32;
			}*/
		}
		if (a[i]!=32 && a[i+1]<=90 && a[i+1]>=65)
			a[i+1]=a[i+1]+32;   //考虑在不是首字母的时候出现大写字母的情况
	}
	cout << a << endl;//这里我改成这样更简单些
	//for (int p=0; p<200; p++)
		//cout << a[p];如果是这样的话，你最后输出会有很多'\0'出现，这个时候再此循环后加个cout << endl;即可
	return 0;
}



