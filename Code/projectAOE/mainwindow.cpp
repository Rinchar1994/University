#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMovie *movie =new QMovie("AOE.png");
    ui->label->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

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
                qDebug() << "error!" << endl;
                exit(1);
        }
        return 0;
}

void CreateALGraph_adjlist(ALGraph &G)
{
        int i,j,k;
        ArcNode *p;
        G.vexnum=10;
        G.arcnum=14;
        for (i=0;i<G.vexnum;i++)
        {
            if(i==G.vexnum-1)
                G.vertices[i].data='0';
            else
                G.vertices[i].data=i+1+'0';

                G.vertices[i].firstarc=NULL;
                G.vertices[i].indegree=0;
        }
        char v1[15]="11233444557689", v2[15]="23445567789090";
        int w[14]={5,6,3,6,3,3,4,4,1,4,5,4,2,2};
    for (k=0;k<G.arcnum;k++)
        {
                i=LocateVex(G,v1[k]);
                j=LocateVex(G,v2[k]);
                p=(ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex=j;
                p->info = w[k];
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
        ++count;
        for (p=G.vertices[i].firstarc;p;p=p->nextarc)
        {//扫描该顶点的出边表
                        k=p->adjvex; //边的另一顶点
            G.vertices[k].indegree--; //顶点入度减
            if (G.vertices[k].indegree==0)
            {
                                G.vertices[k].indegree=top;
                    top=k;
                        }//入度为入栈
                }
    }
        if (count<G.vexnum)
        {
                return 0;//有向环，工程不可行
        }
        else
                return 1;//工程可行
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

void CriticalPath (ALGraph G, int *Ve, int *Vl)
{
        int i, k;
        ArcNode *p;
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
                {
                        k = p->adjvex;
            if ( Vl[k] - p->info < Vl[i])
                    Vl[i] = Vl[k] - p->info;
                p = p->nextarc;
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    switch(drawWhat)
    {
        case IFOK:
            drawifWorkable(&painter);
            break;
        case TIME:
            drawTime(&painter);
            break;
        case LOCAL:
            drawLocal(&painter);
            break;
        default:
            break;
    }
    workable=false;
    time=false;
    local=false;
}
void MainWindow::drawifWorkable(QPainter *painter)
{
    if(workable)
        painter->drawText(200,250,"Workable");
    else
        painter->drawText(200,250,"unWorkable");
    workable=false;
}


void MainWindow::drawTime(QPainter *painter)
{
    int i, k, e, l;
    ArcNode *p;
    if(time)
    {
        QLocale nameshow;
        QString name;
        int y=200;
        for ( i = 0; i < G.vexnum; i++ )
        {
                p = G.vertices[i].firstarc;
                while ( p != NULL ) {
                    k = p->adjvex;
                    e = Ve[i];  l = Vl[k] - p->info;
                    painter->drawText(20,y,"(");
                    name=nameshow.toString(G.vertices[i].data-'0');
                    painter->drawText(30,y,name);
                    painter->drawText(40,y,",");
                    name=nameshow.toString(G.vertices[k].data-'0');
                    painter->drawText(50,y,name);
                    painter->drawText(60,y,"), e=");
                    name=nameshow.toString(e);
                    painter->drawText(100,y,name);
                    painter->drawText(110,y," , l=");
                    name=nameshow.toString(l);
                    painter->drawText(150,y,name);
                    painter->drawText(160,y," ,");
                    y+=10;
                    p = p->nextarc;
                    }
        }
        painter->drawText(20,y,"finishi time=");
        name=nameshow.toString(Ve[G.vexnum]);
        painter->drawText(100,y,name);
    }
    time=false;
}

void MainWindow::drawLocal(QPainter *painter)
{
    if(local)
    {
    QLocale nameshow;
    QString name;
    ArcNode *p;
    int i=0, k, e, l;
    int x_1=30;
    while(1)
    {
        p = G.vertices[i].firstarc;
        while ( p != NULL )
        {
            k = p->adjvex;
            e = Ve[i];  l = Vl[k] - p->info;
            if(e==l)
            {
                name=nameshow.toString(G.vertices[i].data-'0');
                painter->drawText(x_1,300,name);
                x_1+=5;
                painter->drawLine(x_1,295,x_1+20,295);
                x_1+=25;
                break;
            }
            p=p->nextarc;
        }
        i=k;
        if(k==G.vexnum-1)
            break;
    }
    name=nameshow.toString(G.vertices[k].data-'0');
    painter->drawText(x_1,300,name);
    x_1=30;
    int y=200;
    for ( i = 0; i < G.vexnum; i++ )
    {
            p = G.vertices[i].firstarc;
            while ( p != NULL )
            {
                k = p->adjvex;
                e = Ve[i];  l = Vl[k] - p->info;
                if(e==l)
                {
                    painter->drawText(20,y,"(");
                    name=nameshow.toString(G.vertices[i].data-'0');
                    painter->drawText(30,y,name);
                    painter->drawText(40,y,",");
                    name=nameshow.toString(G.vertices[k].data-'0');
                    painter->drawText(50,y,name);
                    painter->drawText(60,y,")");
                    y+=10;
                }
                p=p->nextarc;
            }
    }
    local=false;
}
}

void MainWindow::on_ifOK_clicked()
{
    CreateALGraph_adjlist(G);
    workable=ToplogicalSort(G);
    drawWhat=IFOK;
    this->repaint();
    DestroyALGraph(G);
}

void MainWindow::on_time_clicked()
{
    CreateALGraph_adjlist(G);
    CriticalPath (G,Ve,Vl);
    time=true;
    drawWhat=TIME;
    this->repaint();
    DestroyALGraph(G);

}

void MainWindow::on_path_clicked()
{
    CreateALGraph_adjlist(G);
    CriticalPath (G,Ve,Vl);
    local=true;
    drawWhat=LOCAL;
    this->repaint();
    DestroyALGraph(G);
}

void MainWindow::on_exit_clicked()
{
    QApplication::exit();
}
