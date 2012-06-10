#ifndef PILE_H
#define PILE_H
#include<QStack>
#include<QString>
#include<QStringList>
#include <QChar>
#include <QObject>
#include <QDebug>
#include <QRegExp>
#include"expression.h"
//class Expression;
//class Nombre;
class Pile:public QObject{
private:
QStack <Expression *> Element;
//QStack <QString> Element;
QString result;
//Expression* tmp;
//QStack <Expression *> Backup;
int m_nombreElement;
int nombreMaximal;
bool m_constantAssez;

public:
QStack <QString> Afficheur;
QString get_result(){return result;}
QString set_result(QString s){result=s;}
QStack<Expression *> getElement(){return Element;}
QStack<QString> getAff(){return Afficheur;}
bool traitement(QString commande);
void swap(int x,int y);
void sum(int x);
void mean(int x);
void clear();
void dup();
void drop();
void annuler();
void retablir();
void empiler_Aff(QString s);
void empiler(Expression* s);
Expression * depiler();
void afficher();
QString depiler_Aff();
Pile();
~Pile();
Pile& get_pile();
Expression * calculer();
int mode_resultat();
int get_m_nombreElement(){return m_nombreElement;}

};
#endif // PILE_H
