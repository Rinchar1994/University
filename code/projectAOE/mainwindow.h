#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>
#include <QDebug>

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
}VNode,AdjList[100];
typedef struct
{
        AdjList vertices;
        int vexnum,arcnum;
        int kind;
}ALGraph;

enum DRAWWHAT {IFOK,TIME,LOCAL};

int LocateVex(ALGraph G,char u);//Ѱ���ض�����
void CreateALGraph_adjlist(ALGraph &G);//��������ͼ
int ToplogicalSort(ALGraph G);//��������
void DestroyALGraph(ALGraph &G);//��������ͼ
void CriticalPath (ALGraph G, int *Ve, int *Vl);//�ؼ�·��

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
