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

int Huffmancoding (HuffmanTree &HT,HuffmanCode &HC,int *w, int n);//�����������
int Huffmandecoding( HuffmanTree &HT, char* w);//���������벢��ӡ

int Huffmancoding (HuffmanTree &HT,HuffmanCode &HC,int *w, int n)
{//w���n���ַ���Ȩֵ�������������HT�������n���ַ��Ĺ���������HC��
        if(n<=1)
			return ERROR;
		int m, i;
        int k,s1,s2;
		int min1,min2;
		HuffmanTree p;
        m=2*n-1;
        HT=(HuffmanTree) malloc((m+1)*sizeof(HTNode));//0�ŵ�Ԫδ��
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
					if (HT[k].weight <= min1)//����С��ȨֵСʱ���ѱ�����
			        { 
						min2=min1;
						s2=s1;
		                min1=HT[k].weight;
						s1=k;
					}
			        else if(HT[k].weight<min2)//������СȨֵ��С�ڵڶ�СȨֵ���ѱ�����
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
       HC=(HuffmanCode) malloc ((n+1)*sizeof(char *));//����n���ַ������ͷָ������
       char* cd;
       cd=(char*)malloc(n*sizeof(char));//���������Ĺ����ռ�
       cd[n-1]='\0';//���������
       int start;
       unsigned int c, f;
	   for (i=1;  i<=n;  ++i)  //����ַ������������
	   {
            start=n-1;//���������λ��
            for(c=i, f=HT[i].parent; f!=0; c=f, f=HT[f].parent)//��Ҷ�ӵ������������
                if  (HT[f].lchild==c)
					cd[--start]='0';
                else
					cd[--start]='1';
            HC[i]=(char *)malloc ((n-start)*sizeof(char));//Ϊ��i���ַ��������ռ�
            strcpy(HC[i], &cd[start]); //��cd���Ʊ��뵽HC
       }
       free(cd);//�ͷŹ����ռ�
	   return OK;
}

int Huffmandecoding( HuffmanTree &HT, char* w)
{
	HuffmanTree p = &HT[1];
	int i, j;//j��������ѭ����ʾ���ӽ���λ��
	for( i=1; HT[i].parent != 0; i++ )
	{
	}//i��HT�Ľ�����
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
	cout << "�������������" << endl;
	cout << "�������ַ�����n����ͬ���ͣ�" << endl;
	cin >> n;
	p = (int *)malloc(n*sizeof( int ));
	cout << "����������ַ���Ȩֵ" << endl;
	for( i = 0; i < n; i++ )
		cin >> p[i];
	HuffmanTree HT;
	HuffmanCode HC;
	Huffmancoding (HT,HC,p,n);
	cout << "����������Ϊ��" << endl;
	for( i = 1; i <= n; i++ )
		cout << HC[i] << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "������������̣�����ͬ�ϣ�" << endl;
	char *q;
	while(1)
	{
		cout << endl << endl;
		cout << "*******************************************" << endl;
		cout << "*   1.����                                *" << endl;
		cout << "*   2.�˳�                                *" << endl;
		cout << "*******************************************" << endl;
		int z;
		cin >> z;
		switch( z )
		{
		    case 1:
	            cout << "���������������" << endl;
	            q = (char*)malloc(100*sizeof(char));
	            cin >> q;
				cout << "����������Ϊ��";
	            Huffmandecoding( HT, q);
				free( q );
				break;
			case 2:
				break;
			default:
				cout << "û�и�ѡ��" << endl;
				break;
	    }
		if( z == 2 )
			break;
	}
	cout << endl << "ʵ�����" << endl;
	return 0;
}
