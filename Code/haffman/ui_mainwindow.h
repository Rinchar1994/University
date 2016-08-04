/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Aug 26 18:12:29 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pattern1;
    QPushButton *pattern2;
    QPushButton *pattern3;
    QPushButton *finish;
    QPushButton *exit;
    QPushButton *refresh;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(579, 438);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pattern1 = new QPushButton(centralWidget);
        pattern1->setObjectName(QString::fromUtf8("pattern1"));
        pattern1->setGeometry(QRect(460, 50, 75, 23));
        pattern2 = new QPushButton(centralWidget);
        pattern2->setObjectName(QString::fromUtf8("pattern2"));
        pattern2->setGeometry(QRect(460, 120, 75, 23));
        pattern3 = new QPushButton(centralWidget);
        pattern3->setObjectName(QString::fromUtf8("pattern3"));
        pattern3->setGeometry(QRect(460, 190, 75, 23));
        finish = new QPushButton(centralWidget);
        finish->setObjectName(QString::fromUtf8("finish"));
        finish->setGeometry(QRect(90, 350, 141, 21));
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(460, 350, 75, 23));
        refresh = new QPushButton(centralWidget);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(290, 350, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 579, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pattern1->setText(QApplication::translate("MainWindow", "\347\273\231\345\256\232\345\205\263\345\201\245\345\200\274", 0, QApplication::UnicodeUTF8));
        pattern2->setText(QApplication::translate("MainWindow", "\347\273\231\345\256\232\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        pattern3->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272\346\226\207\346\234\254", 0, QApplication::UnicodeUTF8));
        finish->setText(QApplication::translate("MainWindow", "\347\273\230\345\207\272\345\223\210\345\244\253\346\233\274\346\240\221\345\271\266\347\273\231\345\207\272\347\274\226\347\240\201", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        refresh->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
