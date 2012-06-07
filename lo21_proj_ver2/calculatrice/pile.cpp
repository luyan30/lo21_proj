#include "pile.h"
Pile::Pile(){
m_nombreElement=10;
nombreMaximal=30;
m_constantAssez=true;
result="";
}

Pile::~Pile(){}

/*bool Pile::expressionDetect(const QChar c)
{
        bool res = false;
        if(c=="'")
                res = true;

        return res;
}*/
void Pile::empiler(Expression * s){

   this->Element.push(s);
}
void Pile::empiler_Aff(QString s)
{this->Afficheur.push(s);}

void Pile::depiler(){
this->Element.pop();
}


bool Pile::traitement(QString commande){
//for (int i=0;i<commande.size();i++)
//{
    QStringList list;
        list = commande.split(QRegExp("\\s+"));
        qDebug()<<list[1];
    //if (commande[i]=="'"){return 0}
    //if (commande[i].isDigit())
   // {Element.append(new Nombre(commande.at(i).digitValue(),0,0,0,0));
   // Afficheur.append((QString)commande[i]);}
  // qDebug()<<QString::number(getElement()[i]->evaluer().getPartieReelle());

return true;
}

//}
