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
   if (commande.contains(QRegExp("\'"))){
       Element.append(new Constant(commande));
       Afficheur.append(commande);}
   else
   { QStringList list;
        list = commande.split(QRegExp("\\s+"));      
        for (int i=0;i<list.size();i++)
        {
          if (list[i].compare("6"))
          {
              Element.append(new Entier(list[i].toInt()));
              Afficheur.append(list[i]);
          }
        }
   }
   return true;
}


