#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
void MainWindow::traitment(){
QString tmp=ui->line_command->text();
if (tempo->traitement(tmp)){
annuler();
MisePile();}
}


void MainWindow::digitClicked()
{//qDebug("tester");
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();
    if (ui->line_command->text() == "0" && digitValue == 0.0)
    {
        return;
}
   if (waitingForOperand) {
        ui->line_command->clear();
    waitingForOperand = false;
    }
    ui->line_command->setText(ui->line_command->text()+QString::number(digitValue));
}

void MainWindow::operatorClicked(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString operValue = clickedButton->text();
    if (operValue=="Space"){operValue=' ';}
    if (waitingForOperand) {
         ui->line_command->clear();
     waitingForOperand = false;
     }
     ui->line_command->setText(ui->line_command->text()+operValue);
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tempo=new Pile();
    ui->setupUi(this);
    connection();
    ui->line_command->setText("0");
    waitingForOperand=true;
    for (int i=0;i<10;i++)
       { ui->listWidget->insertItem(1,"");}


}

void MainWindow::MisePile(){
    for(int i =0;i<tempo->get_m_nombreElement();i++)
    {ui->listWidget->item(i)->setText("");
    }

    for(int i=0;i<tempo->getAff().count(); i++)
    {
       ui->listWidget->item(i)->setText(tempo->getAff().value(i));
    }
    ui->Result->setText(tempo->getElement().last()->getPropriete());
    }



void MainWindow::evaluation(){
Expression *ex=tempo->depiler();
tempo->depiler_Aff();
MisePile();
QString nouveau=ex->getPropriete();
QRegExp rx("^'(.*)'$");
rx.indexIn(nouveau);
qDebug()<<rx.cap(1);
ui->line_command->setText(rx.cap(1));

}

void MainWindow::afficherResult(){
    ui->Result->setText(tempo->get_result());
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pileCLear(){}
void MainWindow::pileDup(){}
void MainWindow::pileDrop(){}
void MainWindow::pileSum(){}
void MainWindow::pileMean(){}
void MainWindow::pileSwap(){}

void MainWindow::annuler()
{
    if (waitingForOperand)
        return;

    ui->line_command->setText("0");
    waitingForOperand = true;
}

void MainWindow::connection(){
    digitButtons[0]=ui->num0;
    digitButtons[1]=ui->num1;
    digitButtons[2]=ui->num2;
    digitButtons[3]=ui->num3;
    digitButtons[4]=ui->num4;
    digitButtons[5]=ui->num5;
    digitButtons[6]=ui->num6;
    digitButtons[7]=ui->num7;
    digitButtons[8]=ui->num8;
    digitButtons[9]=ui->num9;

    for (int i = 0; i < 10;i++) {
        connect(digitButtons[i],SIGNAL(clicked()),this,SLOT(digitClicked()));
    }
connect(ui->multi, SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->comma,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->espace,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->guillemet,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->point,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->entrer,SIGNAL(clicked()),this,SLOT(traitment()));
connect(ui->dollar,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->minus,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->plus,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->annuler,SIGNAL(clicked()),this,SLOT(annuler()));
connect(ui->slash,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->POW,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->SIGN,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->COS,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->TAN,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->TANH,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->COSH,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->CUBE,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->SQRT,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->SQR,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->SIHN,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->SIN,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->MOD,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->INV,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->LN,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->LOG,SIGNAL(clicked()),this,SLOT(operatorClicked()));
connect(ui->eval,SIGNAL(clicked()),this,SLOT(evaluation()));
connect(ui->clear,SIGNAL(clicked()),this,SLOT(pileCLear()));
 connect(ui->dup,SIGNAL(clicked()),this,SLOT(pileDup()));
  connect(ui->drop,SIGNAL(clicked()),this,SLOT(pileDrop()));
  connect(ui->sum,SIGNAL(clicked()),this,SLOT(pileSum()));
  connect(ui->mean,SIGNAL(clicked()),this,SLOT(pileMean()));
  connect(ui->swap,SIGNAL(clicked()),this,SLOT(pileSwap()));}

