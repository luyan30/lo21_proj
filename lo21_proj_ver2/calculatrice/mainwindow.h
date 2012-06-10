#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include "pile.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Pile* tempo;
    Pile* historique;
    
private:
    Ui::MainWindow *ui;
    QPushButton *digitButtons[10];
    bool waitingForOperand;
    void clear();
    void connection();
private slots:
    void digitClicked();
    void operatorClicked();
    void traitment();
    void afficherResult();
    void MisePile();
    void annuler();
    void evaluation();
    void pileCLear();
    void pileDup();
    void pileDrop();
    void pileSum();
    void pileMean();
    void pileSwap();
    void pileFonc();}
   /*
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();

    void clearAll();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();*/
;

#endif // MAINWINDOW_H
