#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // MainWindow est un objet
    QApplication a(argc, argv);
    MainWindow w;

   /* MainWindow onglet;
    w.setWindowTitle("Calculatrice 1");*/

    w.show();

  /*  MainWindow second;

    if (true)
    {
       onglet.show();
    }

    second.show();*/

    return a.exec();
}
