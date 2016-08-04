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

#define MAX_VERTEX_NUM 20 //最大顶点数
typedef struct
{
	char  vexs[MAX_VERTEX_NUM];     //顶点表
	int  arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵
	int   vexnum,arcnum;                  //图的顶点数和弧数
}  MGraph;

int LocateVex(MGraph G,char u);//寻找特定顶点（数组型）
void CreateMGraph(MGraph &G);//建立无向图邻接矩阵（数组型）
void PrintMGraph(MGraph G);//打印无向图邻接矩阵（数组型）

int LocateVex(MGraph G,char u)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if (u == G.vexs[i])
			return i;
	}
	if (i== G.vexnum)
	{
		printf("Error u!\n");
		exit(1);
	}
	return 0;
}

void CreateMGraph(MGraph &G)
{
	int i,j,k,w;
    char v1,v2;
	cout << "Input vexnum & arcnum:";
	cin >> G.vexnum >> G.arcnum;
	cout << "Input Vertices:";
	cin >> G.vexs;
	for (i=0;i<G.vexnum;i++)
		for (j=0;j<G.vexnum;j++)
			G.arcs[i][j]=0;
	for (k=0;k<G.arcnum;k++)
	{
		cout << "Input Arcs(v1,v2 & w):" << endl;
		cin >> v1 >> v2;
		cin >> w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=w;
		G.arcs[j][i]=w;
	}
}

void PrintMGraph(MGraph G)
{
	int i,j;
	printf("Output Vertices:");
	printf("%s",G.vexs);
	printf("\n");
	printf("Output AdjMatrix:\n");
	for (i=0;i<G.vexnum;i++)
	{
		for (j=0;j<G.vexnum;j++)
			printf("%4d",G.arcs[i][j]);
		printf("\n");
	}
}

//--------------------------------------------------------------------------

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode;  //边结点类型
typedef struct VNode
{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;  //邻接表
	int vexnum,arcnum;
}ALGraph;

int LocateVex(ALGraph G,char u);//寻找特定顶点（链表型）
void CreateALGraph_adjlist(ALGraph &G);//建立无向图邻接表
void PrintALGraph(ALGraph G);//打印无向图邻接表
void DestroyALGraph(ALGraph &G);//销毁无向图（链表型）

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
	}
    for (k=0;k<G.arcnum;k++)
	{
		cout << "Input Arcs(v1,v2 & w):" << endl;
		cin >> v1 >> v2;
		cin >> w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j+1;
		p->info = w;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=i+1;
		p->info = w;
		p->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p;
	}
}

void PrintALGraph(ALGraph G)
{
	int i;
	ArcNode *p;
	for( i = 0; i<G.vexnum; i++ )
	{
		cout << G.vertices[i].data << "->";
		p = G.vertices[i].firstarc;
		while( p )
		{
			cout << p->adjvex << "->";
			p = p->nextarc;
		}
		cout << "^" << endl;
	}
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
//--------------------------------------------------------------------------

int visited[MAX_VERTEX_NUM];
void DFSTraverse(ALGraph G);//图的深度优先遍历
void DFS(ALGraph G, int v);

void DFS(ALGraph G, int v)
{
	ArcNode *p;
	cout << G.vertices[v].data;
    visited[v]=1;
    p=G.vertices[v].firstarc;
    while (p)
	{
		if (!visited[p->adjvex-1])
			DFS(G,p->adjvex-1);
	    p=p->nextarc;
	}
}//从第v个顶点出发DFS

void DFSTraverse(ALGraph G)
{
    int v;
	for (v=0;v<G.vexnum;++v)
		visited[v]=0;
	for (v=0;v<G.vexnum;++v)
		if (!visited[v])
			DFS(G,v);
}

//-------------------------------------------------------------------------

typedef int QElemType;
typedef struct
{
   QElemType *base;
   int front;
   int rear;
}SqQueue;

int InitQueue (SqQueue &Q);//新建一个循环队列
void BFSTraverse(ALGraph G);//图的广度优先遍历
void BFS(ALGraph G,int v);

int InitQueue (SqQueue &Q)
{
	Q.base=(QElemType *)malloc(MAX_VERTEX_NUM*sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

void BFSTraverse(ALGraph G)
{
	int v;
	for (v=0;v<G.vexnum;++v)
		visited[v]=0;
	for (v=0;v<G.vexnum;++v)
		if (!visited[v])
			BFS(G,v);
}

 void BFS(ALGraph G,int v)
 {
	 ArcNode *p;
	 SqQueue Q;
     InitQueue(Q);
     printf("%c",G.vertices[v].data);
     visited[v]=1;
     Q.base[Q.rear]=v;
     Q.rear=(Q.rear+1)%MAX_VERTEX_NUM;
     while (Q.front!=Q.rear)
     {
		 v=Q.base[Q.front];
         Q.front=(Q.front+1)%MAX_VERTEX_NUM;
     	 p=G.vertices[v].firstarc;
         while (p)
         {
			 if (!visited[p->adjvex-1])
             {
				 printf("%c",G.vertices[p->adjvex-1].data);
	             visited[p->adjvex-1]=1;
	             Q.base[Q.rear]=p->adjvex-1;
	             Q.rear=(Q.rear+1)%MAX_VERTEX_NUM;
	         }
             p=p->nextarc;
         }
	 }
}

//-------------------------------------------------------------------------------------------------------

typedef int VRType;
struct Closedge
{
	char adjvex;
	VRType lowcost;
}closedge[MAX_VERTEX_NUM];

void MiniSpanTree_PRIM(MGraph G,char u);//最小生成树（普里姆算法)

void MiniSpanTree_PRIM(MGraph G,char u)
{
	int k,j,i,minCost;
	k=LocateVex(G,u);
	for (j=0;j<G.vexnum;++j)
		if (j!=k)
		{
			closedge[j].adjvex=u;
			closedge[j].lowcost=G.arcs[k][j];
			G.arcs[j][k] = 0;
		}
	closedge[k].lowcost=0;
	for (i=1;i<G.vexnum;++i)
	{
		//k=minimum(closedge, G.vexnum);
		minCost = 65535;
		for (j=0;j<G.vexnum;++j)
		{
			if (closedge[j].lowcost <minCost && closedge[j].lowcost!=0)
			{
				minCost=closedge[j].lowcost;
				k=j;
			}
		}
		printf("(%c,%c)\n",closedge[k].adjvex,G.vexs[k]);
		closedge[k].lowcost=0;
		for (j=0;j<G.vexnum;++j)
			if ((G.arcs[k][j]<closedge[j].lowcost || closedge[j].lowcost ==0 )&& G.arcs[k][j] != 0  )
			{
				closedge[j].adjvex=G.vexs[k];
				closedge[j].lowcost=G.arcs[k][j];
				G.arcs[j][k] = 0;
			}
	}
	for (j=0;j<G.vexnum;++j)
		for (i=0;i<G.vexnum;++i)
			if(G.arcs[j][i] != 0 )
				G.arcs[i][j] = G.arcs[j][i];
}

//------------------------------------------------------------------------------------------------

int main()
{
	MGraph A;
	ALGraph B;
	while(1){
	int i;
	cout << "****************************************" << endl;
	cout << "*请输入要选择的操作项目代号:           *" << endl;
	cout << "* 1、基本操作                          *" << endl;
	cout << "* 2、选做操作                          *" << endl;
	cout << "* 3、退出                              *" << endl;
	cout << "****************************************" << endl;
	cout << endl;
	cin >> i;
	switch( i )
	{
	    case 1:
			while(1){
			cout << "***************************************" << endl;
			cout << "*请输入要选择的基本操作代号:           *" << endl;
			cout << "* 1、建立并显示图的邻接矩阵            *" << endl;
			cout << "* 2、建立并显示图的邻接表              *" << endl;
			cout << "* 3、实现图的深度优先遍历和广度优先    *" << endl;
			cout << "* 4、退出                              *" << endl;
			cout << "***************************************" << endl;
			cout << endl;
			int j;
			cin >> j;
			switch( j )
			{
			    case 1:
					CreateMGraph(A);
	                PrintMGraph(A);
					break;
				case 2:
					CreateALGraph_adjlist(B);
					PrintALGraph(B);
					DestroyALGraph(B);
					break;
				case 3:
					cout << "先建立图的邻接表" << endl;
					CreateALGraph_adjlist(B);
					while(1)
					{
						int z;
						cout << "****************************************" << endl;
			            cout << "*请输入要选择的选做操作代号:           *" << endl;
			            cout << "* 1、实现图的深度优先遍历              *" << endl;
						cout << "* 2、实现图的广度优先遍历              *" << endl;
			            cout << "* 3、退出                              *" << endl;
			            cout << "****************************************" << endl;
						cin >> z;
						switch( z )
						{
						    case 1:
								DFSTraverse(B);
								cout << endl;
								break;
							case 2:
								BFSTraverse(B);
								cout << endl;
								break;
							case 3:
								DestroyALGraph(B);
								break;
							default:
								cout << "没有该选项" << endl;
						}
						cout << endl;
						if( z == 3 )
							break;
					}
					break;
				case 4:
					break;
				default:
					cout << "没有该选项" << endl;
			}
			cout << endl;
			if( j == 4 )
				break;
			}
			break;
		case 2:
			while(1){
			cout << "****************************************" << endl;
			cout << "*请输入要选择的选做操作代号:           *" << endl;
			cout << "* 1、实现最小生成树的算法              *" << endl;
			cout << "* 2、退出                              *" << endl;
			cout << "****************************************" << endl;
			cout << endl;
			int k;
			cin >> k;
			switch( k )
			{
			    case 1:
					cout << "先建立图的邻接矩阵" << endl;
					CreateMGraph(A);
					cout << "请输入根节点u" << endl;
					char u;
					cin >> u;
					MiniSpanTree_PRIM(A, u);
					break;
				case 2:
					break;
				default:
					cout << "没有该选项" << endl;
			}
			cout << endl;
			if( k == 2 )
				break;
			}
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
