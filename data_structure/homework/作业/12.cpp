#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define MAX_VERTEX_NUM 20 //��󶥵���
#define OK 1
#define ERROR -1
#define OVERFLOW -1

typedef struct ArcNode//ͼ���ڽӱ�Ķ���
{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode;
typedef struct VNode
{
	char data;
	int indegree;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;
	int kind;
}ALGraph;

int LocateVex(ALGraph G,char u);//Ѱ���ض�����
void CreateALGraph_adjlist(ALGraph &G);//��������ͼ
int ToplogicalSort(ALGraph G);//��������
void DestroyALGraph(ALGraph &G);//��������ͼ
void CriticalPath (ALGraph G);//�ؼ�·��

int LocateVex(ALGraph G,char u)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if(u==G.vertices[i].data)
			return i;
	}
	if (i==G.vexnum)
	{
		printf("Error u!\n");
		exit(1);
	}
	return 0;
}

void CreateALGraph_adjlist(ALGraph &G)
{
	int i,j,k,w;
	char v1,v2;
	ArcNode *p;
	cout << "Input vexnum & arcnum:";
	cin >> G.vexnum >> G.arcnum;
	cout << "Input Vertices:";
	for (i=0;i<G.vexnum;i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
		G.vertices[i].indegree=0;
	}
    for (k=0;k<G.arcnum;k++)
	{
		cout << "Input Arcs(v1,v2 & w):" << endl;
		cin >> v1 >> v2;
		cin >> w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->info = w;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;
		G.vertices[j].indegree++;
	}
}

int ToplogicalSort(ALGraph G)
{
	ArcNode *p;
	int k, i;
	int top=-1; //���Ϊ��Ķ���ջ��ʼ��
	for ( i=0;i<G.vexnum;++i)
		if (G.vertices[i].indegree==0)
		{
			G.vertices[i].indegree=top;
			top=i; //���Ϊ�㶥���ջ
		}
	int count=0;
    while (top+1)
    {
		i=top;
		top=G.vertices[top].indegree;
        cout << G.vertices[i].data << "  ";
        ++count;
        for (p=G.vertices[i].firstarc;p;p=p->nextarc)
        {//ɨ��ö���ĳ��߱�
			k=p->adjvex; //�ߵ���һ����
            G.vertices[k].indegree--; //������ȼ�1
            if (G.vertices[k].indegree==0)
            {
				G.vertices[k].indegree=top;
	            top=k;
			}//���Ϊ0��ջ
		}
    }
	if (count<G.vexnum)
	{
		cout << "��������ͼ" << endl;
		return ERROR;//����
	}
	else 
		return OK;
}

void DestroyALGraph(ALGraph &G)
{
	int i;
	ArcNode *p;
	for( i = 0; i<G.vexnum; i++ )
	{
		p = G.vertices[i].firstarc;
		while( p )
		{
			G.vertices[i].firstarc = p->nextarc;
			free(p);
			p = G.vertices[i].firstarc;
		}
	}
}

void CriticalPath (ALGraph G) {	
        int i, k, e, l;	
	int *Ve,*Vl;		
        ArcNode *p;   
        Ve = new int[G.vexnum];
  	Vl = new int[G.vexnum];
        for ( i = 0; i < G.vexnum; i++ ) 	
	Ve[i] = 0;   
        for ( i = 0; i < G.vexnum; i++ ) 	
        {       
             p = G.vertices[i].firstarc;       
             while ( p != NULL )		
            {					
	         k = p->adjvex;		   
                 if (Ve[i] + p->info > Ve[k])		
        	 Ve[k] = Ve[i] + p->info; 	 
                 p = p->nextarc;   
             }  
        }  
        for ( i = 0; i < G.vexnum; i++ ) 	
            Vl[i] = Ve[G.vexnum-1];   
        for ( i = G.vexnum-2; i; i-- )
	{	 
             p = G.vertices[i].firstarc;   
             while ( p != NULL ) 	
            {			k = p->adjvex;            if ( Vl[k] - p->info < Vl[i])	            Vl[i] = Vl[k] - p->info;	        p = p->nextarc;        }    }        for ( i = 0; i < G.vexnum; i++ )	{		p = G.vertices[i].firstarc;			    	while ( p != NULL ) {	    	k = p->adjvex;						    	e = Ve[i];  l = Vl[k] - p->info;	    	char tag= (e == l) ? '*' : ' ';	        printf("(%c,%c),e=%d,l=%d,%c\n",G.vertices[i].data,G.vertices[k].data,e,l,tag);	        p = p->nextarc;       		}    }	delete Ve;	delete Vl;}
int main()
{
	while(1){
	int i;
	cout << "********************************************" << endl;
	cout << "*    ������Ҫѡ��Ĳ�����Ŀ����:           *" << endl;
	cout << "*     1����������                          *" << endl;
	cout << "*     2���ؼ�·��                          *" << endl;
	cout << "*     3���˳�                              *" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cin >> i;
	switch( i )
	{
	    case 1:
			ALGraph A;
			cout << "���������ͼ" << endl;
	        CreateALGraph_adjlist(A);
	        ToplogicalSort(A);
			cout << endl << endl;
			DestroyALGraph(A);
			break;
		case 2:
			ALGraph B;
			cout << "���������ͼ" << endl;
			CreateALGraph_adjlist(B);
			CriticalPath (B);
			cout << endl << endl;
			DestroyALGraph(B);
			break;
	    case 3:
			break;
		default:
			cout << "û�и�ѡ��" << endl;
	}
	if( i == 3 )
		break;
	}
	return 0;
}
