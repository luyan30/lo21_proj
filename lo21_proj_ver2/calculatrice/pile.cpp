#include "pile.h"
Pile::Pile(){
m_nombreElement=10;
nombreMaximal=30;
m_constantAssez=true;
result="";
}

Pile::~Pile(){}

void Pile::empiler(Expression * s){

   this->Element.push(s);
}
void Pile::empiler_Aff(QString s)
{this->Afficheur.push(s);}

Expression * Pile::depiler(){
return this->Element.pop();
}

QString Pile::depiler_Aff(){
return this->Afficheur.pop();}

bool Pile::traitement(QString commande){
   if (commande.contains(QRegExp("\'"))){
       Element.append(new Constant(commande));
       Afficheur.append(commande);}
   else
   { QStringList list;
        list = commande.split(QRegExp("\\s+"));
        for (int i=0;i<list.size();i++)
        {  //complexe

        Complexe *c;
        double tmp0;
        double tmp1;
        //QString s;

            if (list[i].contains("$"))
            {
            QStringList str=list[i].split("$");
            //avec rationnel
            if (str[0].contains("/")|| str[1].contains("/"))
            {

                if(str[0].contains("/")){

                    if (str[1].contains("/")){
                    QStringList vration0=str[0].split("/");
                    QStringList vration1=str[1].split("/");
                    tmp0=vration0[0].toDouble()/vration0[1].toInt();
                    tmp1=vration1[0].toDouble()/vration1[1].toInt();
                    }
                    else
                    {QStringList vration0=str[0].split("/");
                    tmp0=vration0[0].toDouble()/vration0[1].toInt();
                    if (str[1].contains(",")){str[1].replace(",",".");}
                    tmp1=str[1].toDouble();
                    }
                    }
                else{

                    QStringList vration1=str[1].split("/");
                    tmp1=vration1[0].toDouble()/vration1[1].toInt();
                    if (str[0].contains(",")){str[0].replace(",",".");}
                    tmp0=str[0].toDouble();
                    }
            }

                //sans rationnel
            else{

                if (str[0].contains(",")){str[0].replace(",",".");}
                if (str[1].contains(",")){str[1].replace(",",".");}
                tmp0=str[0].toDouble();
                tmp1=str[1].toDouble();
                }
            c=new Complexe(tmp0,tmp1);
            Element.append(c);
            Afficheur.append(c->getPropriete());

            }

            else if(list[i].contains("/"))
            {
            QStringList str=list[i].split("/");
            Rationnel *r=new Rationnel(str[0].toInt(),str[1].toInt());
            Element.append(r);
            Afficheur.append(r->getPropriete());
            }
            else if(list[i].contains(",")){
            QString str=list[i].replace(",",".");
            Reel *r=new Reel(str.toDouble());
            Element.append(r);
            Afficheur.append(r->getPropriete());
            }

            else if (list[i].contains(QRegExp("^[0-9]+$")))
          {
                  Entier *e=new Entier(list[i].toInt());
                  Element.append(e);
                  Afficheur.append(e->getPropriete());
          }
            else if(list[i].contains("+"))
                {
                //qDebug()<<QString::number(Afficheur.size(),10);
                OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),1);
                 this->depiler_Aff();
                 this->depiler_Aff();
               // qDebug()<<QString::number(Afficheur.size(),10);
                Element.append( op->evaluer2());
                Afficheur.append(op->getResult());
               // qDebug()<<QString::number(Afficheur.size(),10);
                }
            else if(list[i].contains("-"))
                {
                OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),2);
                Afficheur.pop();
                Afficheur.pop();
                Element.append( op->evaluer2());
                Afficheur.append(op->getResult());
                }
            else if(list[i].contains("*"))
                {
                OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),3);
                Afficheur.pop();
                Afficheur.pop();
                Element.append( op->evaluer2());
                Afficheur.append(op->getResult());
                }
            else if(list[i].contains("/"))
                {
                OperationBinaire *op=new OperationBinaire(Element.pop(),Element.pop(),4);
                Afficheur.pop();
                Afficheur.pop();
                Element.append( op->evaluer2());
                Afficheur.append(op->getResult());

                }
            else {return false;}

        }
   }

   return true;
}


