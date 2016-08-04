#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>
#include <QDebug>

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
}VNode,AdjList[100];
typedef struct
{
        AdjList vertices;
        int vexnum,arcnum;
        int kind;
}ALGraph;

enum DRAWWHAT {IFOK,TIME,LOCAL};

int LocateVex(ALGraph G,char u);//寻找特定顶点
void CreateALGraph_adjlist(ALGraph &G);//建立有向图
int ToplogicalSort(ALGraph G);//拓扑排序
void DestroyALGraph(ALGraph &G);//销毁有向图
void CriticalPath (ALGraph G, int *Ve, int *Vl);//关键路径

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void drawifWorkable(QPainter *painter);
    void drawTime(QPainter *painter);
    void drawLocal(QPainter *painter);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    DRAWWHAT drawWhat;
    bool workable;
    bool time;
    bool local;
    ALGraph G;
    int Ve[10], Vl[10];

private slots:
    void on_exit_clicked();
    void on_path_clicked();
    void on_time_clicked();
    void on_ifOK_clicked();
};

#endif // MAINWINDOW_H
