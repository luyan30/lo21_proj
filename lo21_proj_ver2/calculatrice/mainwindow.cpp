#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

void MainWindow::retablir(){


QString s=historique->depiler_Aff();

if (s.contains(QRegExp("^[0-9]+$"))||s.contains(QRegExp("\'"))){


    ui->line_command->setText(s);

    tempo->depiler();

    tempo->depiler_Aff();

  }

else if (s.contains("+")||s.contains("*")||s.contains("-")){


    ui->line_command->setText(s);

    tempo->depiler();

    tempo->depiler_Aff();

    QString s1=historique->depiler_Aff();


    qDebug()<<s1;

    QString s2=historique->depiler_Aff();


    qDebug()<<s2;

    tempo->traitement(s1);

    tempo->traitement(s2);

}//ajouter d'autre operations binaire avec || dans le else if condition


else if (s.contains("TAN")){


    ui->line_command->setText(s);

    tempo->depiler();

    tempo->depiler_Aff();

    QString s1=historique->depiler_Aff();


    qDebug()<<s1;

    tempo->traitement(s1);

}//ajouter d'autre operations unaire avec || dans le else if condition


MisePile();

}

void MainWindow::traitment()
{
    QString tmp=ui->line_command->text();
    historique->empiler_Aff(tmp);
    if (tempo->traitement(tmp))
    {
         annuler();
         MisePile();
    }
    else
        throw ("le traitement n'a pas pu marcher");
}

void MainWindow::backspaceClicked()
{
    if (waitingForOperand)
      return; // on ne retourne rien ?
    QString tmp=ui->line_command->text();
     tmp.chop(1);
    if (tmp.isEmpty()) {
        tmp = "0";
        waitingForOperand = true;
    }
    ui->line_command->setText(tmp);
}
void MainWindow::digitClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton *>(sender()); // casting ?
    int digitValue = clickedButton->text().toInt();
    if (ui->line_command->text() == "0" && digitValue == 0.0)
    {
        return;
    }
    if (waitingForOperand)
    {
        ui->line_command->clear();
        waitingForOperand = false;
    }
    ui->line_command->setText(ui->line_command->text()+QString::number(digitValue));
}

void MainWindow::operatorClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton *>(sender());// sender retourne un pointeur de l'objet ayant envoyé le signal
    QString operValue = clickedButton->text();
    if (operValue=="Space")
    {
        operValue=' ';
    }
    //if (operValue="POW")
    if (waitingForOperand)
    {
        ui->line_command->clear();
        waitingForOperand = false;
    }
    ui->line_command->setText(ui->line_command->text()+operValue); //line_command = ligne de commande
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) // constructeur de mainwindow
{
    tempo=new Pile(); // initialisation de tempo
    historique=new Pile();
    ui->setupUi(this); // initialisation de ui
    connection(); // initialisation des connections signaux - slots
    ui->line_command->setText("0"); // initialisation de la ligne de commande
    waitingForOperand=true; // ??attente d'operateur ?
    for (int i=0;i<10;i++)
    {
        ui->listWidget->insertItem(1,"");
    }
}

void MainWindow::MisePile()
{

    for(int i =0;i<tempo->get_m_nombreElement();i++) // vide la pile ?
    {
        ui->listWidget->item(i)->setText("");
    }
    if(tempo->getElement().size()==0)
    {
        ui->Result->setText("");
    }

    else
    {
        for(int i=0;i<tempo->getAff().count(); i++)
        {
            ui->listWidget->item(i)->setText(tempo->getAff().value(i));
        }
    ui->Result->setText(tempo->getElement().last()->getPropriete());
    }
}

void MainWindow::evaluation() // fonction pour evaluer une expression
{
    Expression* ex=tempo->depiler(); // on depile le sommet de la pile que l'on met dans ex
    tempo->depiler_Aff();// on depile le sommet de l'afficheur
    MisePile(); // vide la pile apres l'evaluation ???
    QString nouveau=ex->getPropriete();
    qDebug()<<nouveau;
    QRegExp rx("^'(.*)'$");
    rx.indexIn(nouveau);
    ui->line_command->setText(rx.cap(1));

}

void MainWindow::afficherResult()
{
    ui->Result->setText(tempo->get_result());
}

MainWindow::~MainWindow() // destructeur de mainWindow
{
    delete ui;
}

void MainWindow::pileCLear() // depile tous les elements de la pile avant de la vider
{

    int nb=tempo->getAff().size();
    for(int i=0;i<nb;i++)
    {
        tempo->depiler();
        tempo->depiler_Aff();
    }

    MisePile();
}

void MainWindow::pileDup()
{
    tempo->dup();
    MisePile();
}

void MainWindow::pileDrop()
{
    tempo->drop();
    MisePile();
}

void MainWindow::pileFonc() //enfin n'utilise pas pour le moment
{
    QString s=ui->line_command->text();
    qDebug()<<s;
    QRegExp rxad("^+(.*)$");
    QRegExp rxme("^/(.*)$");
    rxad.indexIn(s);
    rxme.indexIn(s);
    if(s.contains("/")){tempo->mean(rxme.cap(1).toInt());qDebug("dd");}
    else if (s.contains("+")){tempo->sum(rxad.cap(1).toInt());}
    MisePile();qDebug("sd");
}

void MainWindow::pileSum()
{
   // ui->line_command->setText("combien de elements: entrer par +");
    tempo->sum(2);
    MisePile();
}
void MainWindow::pileMean()
{
   // ui->line_command->setText("combien de elements:entrer par /");
    tempo->mean(2);
    MisePile();
}
void MainWindow::pileSwap()
{
    tempo->swap(0,1);
    MisePile();
}

void MainWindow::annuler()
{
    if (waitingForOperand)
        return;

    ui->line_command->setText("0");
    waitingForOperand = true;
}
//void MainWindow::ddd()
//{// mettre ici tout ce qu'il faut pour la commande, fonction
//}

void MainWindow::connection()
{
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

    for (int i = 0; i < 10;i++)
    {
        connect(digitButtons[i],SIGNAL(clicked()),this,SLOT(digitClicked()));
    }
    connect(ui->multi, SIGNAL(clicked()),this,SLOT(operatorClicked())); // multiplication
    connect(ui->comma,SIGNAL(clicked()),this,SLOT(operatorClicked()));
    connect(ui->espace,SIGNAL(clicked()),this,SLOT(operatorClicked())); // espace
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
    connect(ui->div,SIGNAL(clicked()),this,SLOT(operatorClicked()));
    connect(ui->eval,SIGNAL(clicked()),this,SLOT(evaluation()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(pileCLear()));
    connect(ui->dup,SIGNAL(clicked()),this,SLOT(pileDup()));
    connect(ui->drop,SIGNAL(clicked()),this,SLOT(pileDrop()));
    connect(ui->sum,SIGNAL(clicked()),this,SLOT(pileSum()));
    connect(ui->mean,SIGNAL(clicked()),this,SLOT(pileMean()));
    connect(ui->swap,SIGNAL(clicked()),this,SLOT(pileSwap()));
    connect(ui->confirmer,SIGNAL(clicked()),this,SLOT(pileFonc()));
    connect(ui->fact,SIGNAL(clicked()),this,SLOT(operatorClicked()));

    connect(ui->del,SIGNAL(clicked()),this,SLOT(backspaceClicked())); // ???
    connect(ui->retablir,SIGNAL(clicked()),this,SLOT(retablir()));//nouveau
}


