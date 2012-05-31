#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

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
    ui->setupUi(this);
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
    ui->line_command->setText("0");
    waitingForOperand=true;

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*void MainWindow::clear()
{
    if (waitingForOperand)
        return;

    ui->line_command->setText("0");
    waitingForOperand = true;
}*/
