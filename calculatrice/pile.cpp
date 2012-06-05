#include "pile.h"
Pile::Pile(){
m_nombreElement=10;
nombreMaximal=30;
m_constantAssez=true;
//Element={};
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
void Pile::empiler(QString s){

   this->Element.push(s);
     //QString tmp=Element.value(1);
  //  qDebug() << "Types:" << QString(tmp);
  //



}

//void Pile::PileActive(){ }
void Pile::depiler(){
this->Element.pop();
}
