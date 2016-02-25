#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        for(p=HT+1, i=1;  i<=n; ++i,  ++p, ++w)
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


void MainWindow::on_pattern1_clicked()
{
    num = 6;
    weight[0] = 1, member[0] = '1';
    weight[1] = 2, member[1] = '2';
    weight[2] = 3, member[2] = '3';
    weight[3] = 4, member[3] = '4';
    weight[4] = 5, member[4] = '5';
    weight[5] = 6, member[5] = '6';
}

void MainWindow::on_pattern2_clicked()
{
    QFile file("2.txt");
    QString text;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Can't open the file!"<<endl;
    while(!file.atEnd())
    {
        QByteArray line=file.readLine();
        QString str(line);
        text=str;
    }
    file.close();
    num = 0;
    int k = 0, i;
    char* ch;
    QByteArray ba = text.toLatin1();
    ch=ba.data();
    while(1)
    {
        if(ch[k] == '\0')
            break;
        for(i=0; i<num; i++)
        {
            if(member[i]==ch[k])
            {
                weight[i]++;
                break;
            }
        }
        if(i==num)
        {
            member[num]=ch[k];
            weight[num]=1;
            num++;
        }
        k++;
    }
}

void MainWindow::on_pattern3_clicked()
{
    bool isOK;
    QString text = QInputDialog::getText(NULL,
                                         "Input Dialog",
                                         "Please input your comment",
                                         QLineEdit::Normal,
                                         "your comment",
                                         &isOK);
    if(isOK) {
           QMessageBox::information(NULL, "Information",
                                               "Your comment is: <b>" + text + "</b>",
                                               QMessageBox::Yes | QMessageBox::No,
                                               QMessageBox::Yes);
    }
    num = 0;
    int k = 0, i;
    char* ch;
    QByteArray ba = text.toLatin1();
    ch=ba.data();
    while(1)
    {
        if(ch[k] == '\0')
            break;
        for(i=0; i<num; i++)
        {
            if(member[i]==ch[k])
            {
                weight[i]++;
                break;
            }
        }
        if(i==num)
        {
            member[num]=ch[k];
            weight[num]=1;
            num++;
        }
        k++;
    }
}

void MainWindow::draw(QPainter *painter)
{
    if(isdraw)
    {
    int i, j, x_1, cal[100][100], spos[5]={0,1,3,7,15};
    POS[0].x=222, POS[0].y=5, POS[0].isused=0;
    POS[1].x=114, POS[1].y=85, POS[1].isused=0;
    POS[2].x=330, POS[2].y=85, POS[2].isused=0;
    x_1=60-108;
    for(i=3;i<7;i++)
    {
        x_1+=108;
        POS[i].x=x_1, POS[i].y=165, POS[i].isused=0;
    }
    x_1=33-54;
    for(i=7;i<15;i++)
    {
        x_1+=54;
        POS[i].x=x_1, POS[i].y=245, POS[i].isused=0;
    }
    x_1=20-27;
    for(i=15;i<31;i++)
    {
        x_1+=27;
        POS[i].x=x_1, POS[i].y=325, POS[i].isused=0;
    }
    POS[0].isused=1;
    for(i=1;i<=num;i++)
    {
        cal[i][0]=HC[i][0]-'0';
        POS[cal[i][0]+1].isused=1;
        for(j=1;;j++)
        {
            if(HC[i][j]==NULL)
                break;
            cal[i][j]=cal[i][j-1]*2+(HC[i][j]-'0');
            POS[spos[j+1]+cal[i][j]].isused=1;
        }
    }
    for(i=0;i<31;i++)
    {
        if(POS[i].isused==1)
        {
            painter->drawEllipse(POS[i].x,POS[i].y,R,R);
        }
    }
    for(i=0;i<15;i++)
    {
        if(POS[i].isused==1 && POS[i*2+1].isused==1)
        {
            painter->drawLine(POS[i].x,POS[i].y,POS[i*2+1].x,POS[i*2+1].y);
        }
        if(POS[i].isused==1 && POS[i*2+2].isused==1)
        {
            painter->drawLine(POS[i].x,POS[i].y,POS[i*2+2].x,POS[i*2+2].y);
        }
    }
    x_1=10;
    QLocale nameshow;
    QString name;
    for(i=1;i<=num;i++)
    {
        name=nameshow.toString(member[i-1]-'0');//只能以int值为参数
        painter->drawText(x_1,320,name);
        x_1+=20;
        painter->drawText(x_1,340,HC[i]);
        x_1+=50;
    }
}
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    switch(drawWhat)
    {
        case DRAW:
            draw(&painter);
            break;
        default:
            break;
    }
    isdraw=false;
}

void MainWindow::on_finish_clicked()
{
    Huffmancoding (HT,HC,weight,num);
    isdraw=true;
    drawWhat=DRAW;
    this->repaint();
}

void MainWindow::on_exit_clicked()
{
    QApplication::exit();
}

void MainWindow::on_refresh_clicked()
{
    for(int i=0; i<num; i++)
    {
        member[i]='\0';
        weight[i]=0;
        HC[i]='\0';
    }
    num=0;
    delete HT;

}
