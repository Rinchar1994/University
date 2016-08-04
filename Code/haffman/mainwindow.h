#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QInputDialog>
#include <QTextStream>
#include <QPen>
#include <QPainter>
#include <QDebug>
#define OK 1
#define OVERFLOW -1
#define ERROR -1

const int R=3;

namespace Ui {
    class MainWindow;
}

typedef struct
{
    int x;
    int y;
    int isused;
}position;

typedef  struct
{
     int  weight;
     int  parent,  lchild,  rchild;
} HTNode,  *HuffmanTree;

typedef  char  **HuffmanCode;

int Huffmancoding (HuffmanTree &HT,HuffmanCode &HC,int *w, int n);//Çó¹þ·òÂü±àÂë

enum DRAWWHAT {DRAW};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void draw(QPainter *painter);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    DRAWWHAT drawWhat;
    HuffmanTree HT;
    HuffmanCode HC;
    position POS[32];
    int weight[100];
    int num;
    char *member;
    bool isdraw;

private slots:
    void on_refresh_clicked();
    void on_exit_clicked();
    void on_finish_clicked();
    void on_pattern3_clicked();
    void on_pattern2_clicked();
    void on_pattern1_clicked();
};

#endif // MAINWINDOW_H
