#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define MAX_VERTEX_NUM 20 //最大顶点数
#define OK 1
#define ERROR -1
#define OVERFLOW -1

typedef struct ArcNode//图的邻接表的定义
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

int LocateVex(ALGraph G,char u);//寻找特定顶点
void CreateALGraph_adjlist(ALGraph &G);//建立有向图
int ToplogicalSort(ALGraph G);//拓扑排序
void DestroyALGraph(ALGraph &G);//销毁有向图
void CriticalPath (ALGraph G);//关键路径

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
	int top=-1; //入度为零的顶点栈初始化
	for ( i=0;i<G.vexnum;++i)
		if (G.vertices[i].indegree==0)
		{
			G.vertices[i].indegree=top;
			top=i; //入度为零顶点进栈
		}
	int count=0;
    while (top+1)
    {
		i=top;
		top=G.vertices[top].indegree;
        cout << G.vertices[i].data << "  ";
        ++count;
        for (p=G.vertices[i].firstarc;p;p=p->nextarc)
        {//扫描该顶点的出边表
			k=p->adjvex; //边的另一顶点
            G.vertices[k].indegree--; //顶点入度减1
            if (G.vertices[k].indegree==0)
            {
				G.vertices[k].indegree=top;
	            top=k;
			}//入度为0入栈
		}
    }
	if (count<G.vexnum)
	{
		cout << "带环有向图" << endl;
		return ERROR;//有向环
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
	cout << "*    请输入要选择的操作项目代号:           *" << endl;
	cout << "*     1、拓扑排序                          *" << endl;
	cout << "*     2、关键路径                          *" << endl;
	cout << "*     3、退出                              *" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cin >> i;
	switch( i )
	{
	    case 1:
			ALGraph A;
			cout << "建立所需的图" << endl;
	        CreateALGraph_adjlist(A);
	        ToplogicalSort(A);
			cout << endl << endl;
			DestroyALGraph(A);
			break;
		case 2:
			ALGraph B;
			cout << "建立所需的图" << endl;
			CreateALGraph_adjlist(B);
			CriticalPath (B);
			cout << endl << endl;
			DestroyALGraph(B);
			break;
	    case 3:
			break;
		default:
			cout << "没有该选项" << endl;
	}
	if( i == 3 )
		break;
	}
	return 0;
}
