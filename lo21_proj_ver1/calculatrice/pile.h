#ifndef PILE_H
#define PILE_H
#include<QStack>
#include<QString>
#include <QChar>
#include <QObject>
#include <QDebug>
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
QStack<Expression *> getElement(){return Element;}
QStack<QString> getAff(){return Afficheur;}
bool traitement(QString commande);
void swap(int x,int y);
void sum(int x);
Expression* mean(int x);
void clear();
void dup();
void drop();
void annuler();
void retablir();
void empiler_Aff(QString s);
void empiler(Expression* s);
void depiler();
void afficher();
//bool expressionDetect(const QChar c);
Pile();
~Pile();
Pile& get_pile();
Expression * calculer();
int mode_resultat();

};
#endif // PILE_H
