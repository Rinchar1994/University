#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;
#define OK 1
#define FALSE 0
#define TRUE 1
#define OVERFLOW -1
#define ERROR -1

typedef  struct
{
	 int  weight;
     int  parent,  lchild,  rchild;
} HTNode,  *HuffmanTree;

typedef  char  **HuffmanCode;

int Huffmancoding (HuffmanTree &HT,HuffmanCode &HC,int *w, int n);//求哈夫曼编码
int Huffmandecoding( HuffmanTree &HT, char* w);//哈夫曼译码并打印

int Huffmancoding (HuffmanTree &HT,HuffmanCode &HC,int *w, int n)
{//w存放n个字符的权值，构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC。
        if(n<=1)
			return ERROR;
		int m, i;
        int k,s1,s2;
		int min1,min2;
		HuffmanTree p;
        m=2*n-1;
        HT=(HuffmanTree) malloc((m+1)*sizeof(HTNode));//0号单元未用
        for(p=HT+1, i=1;  i<=n; ++i,  ++p,  ++w)
		{
			p->weight=*w;
			p->parent=0;
			p->lchild=0;
			p->rchild=0;
		}
        for(;  i<=m;  ++i,  ++p)
		{
			p->weight=0;
			p->parent=0;
			p->lchild=0;
			p->rchild=0;
		}
		for(i=n+1;i<=m;i++)
		{ 
			min1=min2=32767;
		    s1=s2=0;
		    for(k=1;k<=i-1;k++)
			    if(HT[k].parent==0)
			    {
					if (HT[k].weight <= min1)//比最小的权值小时（已遍历）
			        { 
						min2=min1;
						s2=s1;
		                min1=HT[k].weight;
						s1=k;
					}
			        else if(HT[k].weight<min2)//大于最小权值但小于第二小权值（已遍历）
			        {
						min2=HT[k].weight;
				        s2=k;
			        }
				}
				int j;
				if( s1>s2 )
				{
					j=s1;
					s1=s2;
					s2=j;
				}
				HT[s1].parent=i;
				HT[s2].parent=i;
			    HT[i].lchild=s1;
				HT[i].rchild=s2;
                HT[i].weight=HT[s1].weight+HT[s2].weight;
		}
       HC=(HuffmanCode) malloc ((n+1)*sizeof(char *));//分配n个字符编码的头指针向量
       char* cd;
       cd=(char*)malloc(n*sizeof(char));//分配求编码的工作空间
       cd[n-1]='\0';//编码结束符
       int start;
       unsigned int c, f;
	   for (i=1;  i<=n;  ++i)  //逐个字符求哈夫曼编码
	   {
            start=n-1;//编码结束符位置
            for(c=i, f=HT[i].parent; f!=0; c=f, f=HT[f].parent)//从叶子到根逆向求编码
                if  (HT[f].lchild==c)
					cd[--start]='0';
                else
					cd[--start]='1';
            HC[i]=(char *)malloc ((n-start)*sizeof(char));//为第i个字符编码分配空间
            strcpy(HC[i], &cd[start]); //从cd复制编码到HC
       }
       free(cd);//释放工作空间
	   return OK;
}

int Huffmandecoding( HuffmanTree &HT, char* w)
{
	HuffmanTree p = &HT[1];
	int i, j;//j用于下面循环表示孩子结点的位置
	for( i=1; HT[i].parent != 0; i++ )
	{
	}//i是HT的结点个数
	while( *w=='0' || *w=='1' )
	{
		p = &HT[i];
		while( p->lchild != 0 )
		{
			switch( *w )
			{
			    case '0':
					j = p->lchild;
					p = &HT[p->lchild];
					break;
				case '1':
					j = p->rchild;
					p = &HT[p->rchild];
					break;
				default:
					return ERROR;
			}
			w++;
		}
		cout << j;
	}
	return OK;
}

int main()
{
	int *p, n, i;
	cout << "哈夫曼编码过程" << endl;
	cout << "请输入字符个数n（不同类型）" << endl;
	cin >> n;
	p = (int *)malloc(n*sizeof( int ));
	cout << "请输入各个字符的权值" << endl;
	for( i = 0; i < n; i++ )
		cin >> p[i];
	HuffmanTree HT;
	HuffmanCode HC;
	Huffmancoding (HT,HC,p,n);
	cout << "哈夫曼编码为：" << endl;
	for( i = 1; i <= n; i++ )
		cout << HC[i] << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "哈夫曼解码过程（编码同上）" << endl;
	char *q;
	while(1)
	{
		cout << endl << endl;
		cout << "*******************************************" << endl;
		cout << "*   1.译码                                *" << endl;
		cout << "*   2.退出                                *" << endl;
		cout << "*******************************************" << endl;
		int z;
		cin >> z;
		switch( z )
		{
		    case 1:
	            cout << "请输入哈夫曼编码" << endl;
	            q = (char*)malloc(100*sizeof(char));
	            cin >> q;
				cout << "哈夫曼译码为：";
	            Huffmandecoding( HT, q);
				free( q );
				break;
			case 2:
				break;
			default:
				cout << "没有该选项" << endl;
				break;
	    }
		if( z == 2 )
			break;
	}
	cout << endl << "实验结束" << endl;
	return 0;
}
