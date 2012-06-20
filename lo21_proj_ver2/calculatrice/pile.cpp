#include "pile.h"
#include <QLabel>

/*constructeur de Pile*/
Pile::Pile()
{
    m_nombreElement=10;
    nombreMaximal=20;
    m_constantAssez=true;
    result="";
}

/*destructeur de Pile*/
Pile::~Pile(){}
void Pile::dup()
{    Expression* ex1=this->getElement().top(); // top : retourne le sommet de la pile
     this->empiler(ex1); // ??
     QString s=this->getAff().top(); // ??
     this->empiler_Aff(s); // ??
}

/* méthodes de Pile */
void Pile::drop()
{
    this->depiler();
    this->depiler_Aff();
}


void Pile::empiler(Expression* s)
{
   this->Element.push(s); // push: ajoute un element au sommet de la pile de pointeurs d'expressions
}

void Pile::empiler_Aff(QString s)
{
    this->Afficheur.push(s); // push: ajoute un element au sommet de la pile d'affichage ?
}

Expression* Pile::depiler()
{
    return this->Element.pop(); // pop: pour dépiler un élément
}

QString Pile::depiler_Aff()
{
    return this->Afficheur.pop();
}

bool Pile::traitement(QString commande) // algo la plus difficile !
{
   if (commande.contains(QRegExp("\'")))// si on a une expression avec << ' >>
   {
       Element.push(new Constant(commande));// insere une valeur au sommet de la pile ???
       Afficheur.push(commande);

   }

   else
   {
       QStringList list; // list est une liste de strings
        list = commande.split(QRegExp("\\s+")); // formation d'une liste de chaines separees par un espace
        for (int i=0;i<list.size();i++) // list.size() donne le nombre de strings de notre commande
        {  //complexe

        Complexe* c;
        double tmp0;
        double tmp1;
        //QString s;

          if (list[i].contains("$"))
          {
             QStringList str=list[i].split("$"); // liste des chaines qui composent un complexe
             //le complexe contient des rationnels
              if (str[0].contains("/")|| str[1].contains("/"))
              {
                  if(str[0].contains("/"))
                  {
                      if (str[1].contains("/")) // str[0] et str[0] contiennent '/'
                      {
                          QStringList vration0=str[0].split("/");
                          QStringList vration1=str[1].split("/");
                          tmp0=((vration0[0].toDouble())/(vration0[1].toInt()));
                          tmp1=((vration1[0].toDouble())/(vration1[1].toInt()));
                      }

                      else // str[1] ne contient pas '/'
                      {
                          QStringList vration0=str[0].split("/");
                          tmp0=((vration0[0].toDouble())/(vration0[1].toInt()));
                          if (str[1].contains(","))
                          {
                              str[1].replace(",",".");
                          }
                          tmp1 = str[1].toDouble();
                      }
                  }

                  else
                  {
                      QStringList vration1=str[1].split("/");
                      tmp1=((vration1[0].toDouble())/(vration1[1].toInt()));
                      if (str[0].contains(","))
                      {
                          str[0].replace(",",".");
                      }
                      tmp0=str[0].toDouble();
                  }
              }

                //sans rationnel
              else
              {
                  if (str[0].contains(","))
                  {
                      str[0].replace(",",".");
                  }
                  if (str[1].contains(","))
                  {
                      str[1].replace(",",".");
                  }
                  tmp0=str[0].toDouble();
                  tmp1=str[1].toDouble();
              }

              c = new Complexe(tmp0,tmp1);
              Element.push(c); //
              Afficheur.push(c->getPropriete());
          }

          else if(list[i].contains("/"))
          {
              QStringList str=list[i].split("/"); // str est
              Rationnel* r=new Rationnel(str[0].toInt(),str[1].toInt());
              Element.push(r);
              Afficheur.push(r->getPropriete());
          }

          else if(list[i].contains(","))
          {
              QString str=list[i].replace(",",".");
              Reel *r=new Reel(str.toDouble());
              Element.push(r);
              Afficheur.push(r->getPropriete());
          }

          else if (list[i].contains(QRegExp("^[0-9]+$")))
          {
              Entier* e=new Entier(list[i].toInt());
              Element.push(e); // insere une valeur a la fin du <vector>
              Afficheur.push(e->getPropriete());
          }

          else if(list[i].contains("+"))
          {

              OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),1);
              this->depiler_Aff();
              this->depiler_Aff();

              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());

          }

          else if(list[i].contains("-"))
          {
              OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),2);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());
          }

          else if(list[i].contains("*"))
          {
              OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),3);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());
          }

          else if(list[i].contains("/"))
          {
              OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),4);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());
          }
          else if(list[i].contains(QRegExp("(POW)")))
          {
              Expression* ex1 = Element.pop(); // 1ere expression depilee
              Expression* ex2 = Element.pop(); // 2eme expression depilee
              OperationBinaire* op=new OperationBinaire(ex1,ex2,5);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
             // QString s=op->evaluer2();
              Afficheur.push(op->getResult());
              /* *op=new OperationBinaire(Element.pop(),Element.pop(),5);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());*/
             // delete op;
            //  delete ex1;
            //  delete ex2;
          }

          else if(list[i] =="POW")
          {
              Expression* ex1 = Element.pop(); // 1ere expression depilee
              Expression* ex2 = Element.pop(); // 2eme expression depilee
              OperationBinaire* op=new OperationBinaire(ex1,ex2,5);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());
              delete op;
              delete ex1;
              delete ex2;
          }

          /*else if(list[i].contains(QRegExp("(MOD)")))
          {
              OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),6);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());
          }
          */
          else if(list[i].contains(QRegExp("(MOD)")))
          {
              OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),6);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());
          }

          else if(list[i] =="MOD")
          {
              OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),6);
              Afficheur.pop();
              Afficheur.pop();
              Element.push( op->evaluer2());
              Afficheur.push(op->getResult());
          }

         else
          {
              QLabel msg;
              msg.setText("Erreur inconnue");
              msg.show();
              //qDebug() << QString(" Erreur : on a une erreur dans l'algorithme")  ;
              //throw("erreur: le traitement n'a pas marché");
              return false;
          }

      }// fin pour
   } // fin si

   return true;
}

/*bool Pile::traitement(QString commande)
{
    if ((commande[0] == "'")&&(commande[commande.size()-1]== "'"))
        {
            Constant c(commande);
            this->empiler(c);
        }
    else if ((commande[0] != "'")&&(commande[commande.size()-1]!= "'"))
    {
        //l'expression n'est pas entourée de << ' >> on fait le traitement
    }
    else
        throw (" erreur : l'expression n'est pas bonne");

}*/

void Pile::mean(int x)
{
   sum(x);
   Expression* ex1=this->depiler();
   this->depiler_Aff();
   double s= ex1->getPropriete().toDouble()/2; // constante sous forme de chaine
   Reel* resultEx=new Reel(s);
   Element.push(resultEx);
   Afficheur.push(QString::number(s));
}

  /*  sum(x);
   double re= this->get_result().toDouble()/x;
   Reel * resultEx=new Reel(re);
   result=resultEx->getPropriete();
   this->depiler();
   this->depiler_Aff();
   Element.push(resultEx);
   Afficheur.push(result);

}*/

void Pile::swap(int x,int y)//pour le moment , je juste fait les deux premiers elements
{
    // algo juste pour les deux premiers elements : voir algo de fac de limoges
    Expression* ex1=this->depiler();

    QString s1=this->depiler_Aff();
    Expression* ex2=this->depiler(); // on depile deux expressions
    QString s2=this->depiler_Aff();
    qDebug()<<s1; // qDebug() pour afficher ?
    qDebug()<<s2; // qDebug() pour afficher ?
    this->empiler(ex1);
    this->empiler(ex2);
    this->empiler_Aff(s1);
    this->empiler_Aff(s2);
}

void Pile::sum(int x) // utilisation de x ???
{
    Expression* ex1= this->depiler();
     Expression* ex2=this->depiler();
     OperationBinaire* op=new OperationBinaire(ex1,ex2,1); // 1 ==> addition des expressions
     Element.push( op->evaluer2());
     this->depiler_Aff();
     this->depiler_Aff();
     Afficheur.push(op->getResult());
}
    /*
   OperationBinaire *op;
   Expression* ex1;
   Expression* ex2;
    for (int i=0;i<x;i++)
    {

         ex1= this->depiler();
         ex2=this->depiler();

        if(ex1->getPropriete().contains("'")||ex1->getPropriete().contains("'"))
        {Element.push(ex2);
            Element.push(ex1);
        }
        else{
            op=new OperationBinaire(ex1,ex2,1);
            this->depiler_Aff();
           this->depiler_Aff();
        Element.push( op->evaluer2());
        Afficheur.push(op->getResult());}

}
    this->set_result(Afficheur.top());
}*/


