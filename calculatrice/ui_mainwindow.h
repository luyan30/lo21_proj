/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 30 09:28:30 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actionOuvrir_la_source;
    QAction *actionQuit;
    QWidget *centralWidget;
    QLineEdit *line_command;
    QGroupBox *pile;
    QGroupBox *fonction_pile;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *clear;
    QPushButton *dup;
    QPushButton *swap;
    QPushButton *mean;
    QLineEdit *Result;
    QLabel *result;
    QGroupBox *keyboard;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *num0;
    QPushButton *num6;
    QPushButton *num8;
    QPushButton *num7;
    QPushButton *num9;
    QPushButton *plus;
    QPushButton *minus;
    QPushButton *multi;
    QPushButton *slash;
    QPushButton *POW;
    QPushButton *SIGN;
    QPushButton *MOD;
    QPushButton *dollar;
    QPushButton *guillemet;
    QPushButton *eval_2;
    QPushButton *comma;
    QPushButton *del;
    QPushButton *annuler;
    QPushButton *retablir;
    QGroupBox *Fonction_unaire;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QPushButton *SIN;
    QPushButton *COS;
    QPushButton *TAN;
    QPushButton *SIHN;
    QPushButton *LN;
    QPushButton *INV;
    QPushButton *SQRT;
    QPushButton *SQR;
    QPushButton *TANH;
    QPushButton *COSH;
    QPushButton *LOG;
    QPushButton *CUBE;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(809, 434);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionOuvrir_la_source = new QAction(MainWindow);
        actionOuvrir_la_source->setObjectName(QString::fromUtf8("actionOuvrir_la_source"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        line_command = new QLineEdit(centralWidget);
        line_command->setObjectName(QString::fromUtf8("line_command"));
        line_command->setGeometry(QRect(50, 20, 301, 21));
        line_command->setReadOnly(true);
        pile = new QGroupBox(centralWidget);
        pile->setObjectName(QString::fromUtf8("pile"));
        pile->setGeometry(QRect(660, 70, 121, 191));
        fonction_pile = new QGroupBox(centralWidget);
        fonction_pile->setObjectName(QString::fromUtf8("fonction_pile"));
        fonction_pile->setGeometry(QRect(450, 280, 351, 71));
        horizontalLayoutWidget = new QWidget(fonction_pile);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 320, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        clear = new QPushButton(horizontalLayoutWidget);
        clear->setObjectName(QString::fromUtf8("clear"));

        horizontalLayout_3->addWidget(clear);

        dup = new QPushButton(horizontalLayoutWidget);
        dup->setObjectName(QString::fromUtf8("dup"));

        horizontalLayout_3->addWidget(dup);

        swap = new QPushButton(horizontalLayoutWidget);
        swap->setObjectName(QString::fromUtf8("swap"));

        horizontalLayout_3->addWidget(swap);

        mean = new QPushButton(horizontalLayoutWidget);
        mean->setObjectName(QString::fromUtf8("mean"));

        horizontalLayout_3->addWidget(mean);

        Result = new QLineEdit(centralWidget);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setGeometry(QRect(540, 20, 113, 20));
        Result->setReadOnly(true);
        result = new QLabel(centralWidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(490, 20, 41, 21));
        keyboard = new QGroupBox(centralWidget);
        keyboard->setObjectName(QString::fromUtf8("keyboard"));
        keyboard->setGeometry(QRect(20, 60, 371, 271));
        gridLayoutWidget = new QWidget(keyboard);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 323, 181));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        gridLayout_2->setHorizontalSpacing(7);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        num4 = new QPushButton(gridLayoutWidget);
        num4->setObjectName(QString::fromUtf8("num4"));

        gridLayout_2->addWidget(num4, 2, 0, 1, 1);

        num5 = new QPushButton(gridLayoutWidget);
        num5->setObjectName(QString::fromUtf8("num5"));

        gridLayout_2->addWidget(num5, 2, 1, 1, 1);

        num1 = new QPushButton(gridLayoutWidget);
        num1->setObjectName(QString::fromUtf8("num1"));

        gridLayout_2->addWidget(num1, 3, 0, 1, 1);

        num2 = new QPushButton(gridLayoutWidget);
        num2->setObjectName(QString::fromUtf8("num2"));

        gridLayout_2->addWidget(num2, 3, 1, 1, 1);

        num3 = new QPushButton(gridLayoutWidget);
        num3->setObjectName(QString::fromUtf8("num3"));

        gridLayout_2->addWidget(num3, 3, 2, 1, 1);

        num0 = new QPushButton(gridLayoutWidget);
        num0->setObjectName(QString::fromUtf8("num0"));

        gridLayout_2->addWidget(num0, 4, 0, 1, 1);

        num6 = new QPushButton(gridLayoutWidget);
        num6->setObjectName(QString::fromUtf8("num6"));

        gridLayout_2->addWidget(num6, 2, 2, 1, 1);

        num8 = new QPushButton(gridLayoutWidget);
        num8->setObjectName(QString::fromUtf8("num8"));

        gridLayout_2->addWidget(num8, 1, 1, 1, 1);

        num7 = new QPushButton(gridLayoutWidget);
        num7->setObjectName(QString::fromUtf8("num7"));

        gridLayout_2->addWidget(num7, 1, 0, 1, 1);

        num9 = new QPushButton(gridLayoutWidget);
        num9->setObjectName(QString::fromUtf8("num9"));

        gridLayout_2->addWidget(num9, 1, 2, 1, 1);

        plus = new QPushButton(gridLayoutWidget);
        plus->setObjectName(QString::fromUtf8("plus"));

        gridLayout_2->addWidget(plus, 1, 3, 1, 1);

        minus = new QPushButton(gridLayoutWidget);
        minus->setObjectName(QString::fromUtf8("minus"));

        gridLayout_2->addWidget(minus, 2, 3, 1, 1);

        multi = new QPushButton(gridLayoutWidget);
        multi->setObjectName(QString::fromUtf8("multi"));

        gridLayout_2->addWidget(multi, 3, 3, 1, 1);

        slash = new QPushButton(gridLayoutWidget);
        slash->setObjectName(QString::fromUtf8("slash"));

        gridLayout_2->addWidget(slash, 4, 3, 1, 1);

        POW = new QPushButton(gridLayoutWidget);
        POW->setObjectName(QString::fromUtf8("POW"));

        gridLayout_2->addWidget(POW, 5, 0, 1, 1);

        SIGN = new QPushButton(gridLayoutWidget);
        SIGN->setObjectName(QString::fromUtf8("SIGN"));

        gridLayout_2->addWidget(SIGN, 5, 1, 1, 1);

        MOD = new QPushButton(gridLayoutWidget);
        MOD->setObjectName(QString::fromUtf8("MOD"));

        gridLayout_2->addWidget(MOD, 5, 2, 1, 1);

        dollar = new QPushButton(gridLayoutWidget);
        dollar->setObjectName(QString::fromUtf8("dollar"));

        gridLayout_2->addWidget(dollar, 4, 2, 1, 1);

        guillemet = new QPushButton(gridLayoutWidget);
        guillemet->setObjectName(QString::fromUtf8("guillemet"));

        gridLayout_2->addWidget(guillemet, 4, 1, 1, 1);

        eval_2 = new QPushButton(gridLayoutWidget);
        eval_2->setObjectName(QString::fromUtf8("eval_2"));

        gridLayout_2->addWidget(eval_2, 6, 3, 1, 1);

        comma = new QPushButton(gridLayoutWidget);
        comma->setObjectName(QString::fromUtf8("comma"));

        gridLayout_2->addWidget(comma, 5, 3, 1, 1);

        del = new QPushButton(gridLayoutWidget);
        del->setObjectName(QString::fromUtf8("del"));

        gridLayout_2->addWidget(del, 6, 2, 1, 1);

        annuler = new QPushButton(keyboard);
        annuler->setObjectName(QString::fromUtf8("annuler"));
        annuler->setGeometry(QRect(130, 220, 75, 23));
        retablir = new QPushButton(keyboard);
        retablir->setObjectName(QString::fromUtf8("retablir"));
        retablir->setGeometry(QRect(30, 220, 75, 23));
        Fonction_unaire = new QGroupBox(centralWidget);
        Fonction_unaire->setObjectName(QString::fromUtf8("Fonction_unaire"));
        Fonction_unaire->setGeometry(QRect(450, 60, 181, 201));
        gridLayoutWidget_2 = new QWidget(Fonction_unaire);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 158, 170));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        SIN = new QPushButton(gridLayoutWidget_2);
        SIN->setObjectName(QString::fromUtf8("SIN"));

        gridLayout_3->addWidget(SIN, 0, 0, 1, 1);

        COS = new QPushButton(gridLayoutWidget_2);
        COS->setObjectName(QString::fromUtf8("COS"));

        gridLayout_3->addWidget(COS, 0, 1, 1, 1);

        TAN = new QPushButton(gridLayoutWidget_2);
        TAN->setObjectName(QString::fromUtf8("TAN"));

        gridLayout_3->addWidget(TAN, 1, 0, 1, 1);

        SIHN = new QPushButton(gridLayoutWidget_2);
        SIHN->setObjectName(QString::fromUtf8("SIHN"));

        gridLayout_3->addWidget(SIHN, 1, 1, 1, 1);

        LN = new QPushButton(gridLayoutWidget_2);
        LN->setObjectName(QString::fromUtf8("LN"));

        gridLayout_3->addWidget(LN, 3, 0, 1, 1);

        INV = new QPushButton(gridLayoutWidget_2);
        INV->setObjectName(QString::fromUtf8("INV"));

        gridLayout_3->addWidget(INV, 4, 0, 1, 1);

        SQRT = new QPushButton(gridLayoutWidget_2);
        SQRT->setObjectName(QString::fromUtf8("SQRT"));

        gridLayout_3->addWidget(SQRT, 4, 1, 1, 1);

        SQR = new QPushButton(gridLayoutWidget_2);
        SQR->setObjectName(QString::fromUtf8("SQR"));

        gridLayout_3->addWidget(SQR, 5, 0, 1, 1);

        TANH = new QPushButton(gridLayoutWidget_2);
        TANH->setObjectName(QString::fromUtf8("TANH"));

        gridLayout_3->addWidget(TANH, 2, 1, 1, 1);

        COSH = new QPushButton(gridLayoutWidget_2);
        COSH->setObjectName(QString::fromUtf8("COSH"));

        gridLayout_3->addWidget(COSH, 2, 0, 1, 1);

        LOG = new QPushButton(gridLayoutWidget_2);
        LOG->setObjectName(QString::fromUtf8("LOG"));

        gridLayout_3->addWidget(LOG, 3, 1, 1, 1);

        CUBE = new QPushButton(gridLayoutWidget_2);
        CUBE->setObjectName(QString::fromUtf8("CUBE"));

        gridLayout_3->addWidget(CUBE, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 809, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOuvrir_la_source);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(action);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(del, SIGNAL(clicked()), line_command, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        actionOuvrir_la_source->setText(QApplication::translate("MainWindow", "Ouvrir la source", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        pile->setTitle(QApplication::translate("MainWindow", "Pile", 0, QApplication::UnicodeUTF8));
        fonction_pile->setTitle(QApplication::translate("MainWindow", "Fonction pour Pile", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("MainWindow", "clear", 0, QApplication::UnicodeUTF8));
        dup->setText(QApplication::translate("MainWindow", "dup", 0, QApplication::UnicodeUTF8));
        swap->setText(QApplication::translate("MainWindow", "swap", 0, QApplication::UnicodeUTF8));
        mean->setText(QApplication::translate("MainWindow", "mean", 0, QApplication::UnicodeUTF8));
        result->setText(QApplication::translate("MainWindow", "Result\357\274\232", 0, QApplication::UnicodeUTF8));
        keyboard->setTitle(QString());
        num4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        minus->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        multi->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        slash->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        POW->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        SIGN->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        MOD->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        dollar->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        guillemet->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        eval_2->setText(QApplication::translate("MainWindow", "Eval", 0, QApplication::UnicodeUTF8));
        comma->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        del->setText(QApplication::translate("MainWindow", "del", 0, QApplication::UnicodeUTF8));
        annuler->setText(QApplication::translate("MainWindow", "annuler", 0, QApplication::UnicodeUTF8));
        retablir->setText(QApplication::translate("MainWindow", "retablir", 0, QApplication::UnicodeUTF8));
        Fonction_unaire->setTitle(QString());
        SIN->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        COS->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        TAN->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        SIHN->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        LN->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        INV->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        SQRT->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        SQR->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        TANH->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        COSH->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        LOG->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        CUBE->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H