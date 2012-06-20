#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include "pile.h"
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT // MACRO Q_OBJECT
    
public:
    explicit MainWindow(QWidget* parent = 0); // pourquoi explicit ?
    ~MainWindow();
    Pile* tempo; // pile temporaire ?
    Pile* historique; // la derniere pile de l'historique ?
    
private:
    Ui::MainWindow* ui;
    QPushButton* digitButtons[10]; // boutons numériques ???
    bool waitingForOperand; // waitingForOperand pour quoi faire?
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
    void pileFonc();
    void backspaceClicked(); // slot espace cliqué
   // void ddd();
};


#endif // MAINWINDOW_H
