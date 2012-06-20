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

class Pile: public QObject
{
private:
    QStack <Expression *> Element; // liste de pointeurs d'expression
    //QStack <QString> Element;
    QString result;
    //Expression* tmp;
    //QStack <Expression *> Backup;
    int m_nombreElement; // nombre d'élements
    int nombreMaximal; // nombre maximal d'éléments
    bool m_constantAssez;

public:
    QStack <QString> Afficheur; // pile conteneur de string : attribut publique ???
    QString get_result()
    {
        return result;
    }

    QString set_result(QString s)
    {
        result=s;
    }

    QStack<Expression *> getElement() // retourne la pile de pointeurs sur Expression
    {
        return Element;
    }
    QStack<QString> getAff() // retourne l'afficheur
    {
        return Afficheur;
    }

    bool traitement(QString commande);

    void swap(int x,int y);
    void sum(int x);
    void mean(int x);
    void clear();
    void dup();
    void drop();
    void annuler();
    void retablir();
    void empiler_Aff(QString s); // ??
    void empiler(Expression* s);

    Expression* depiler(); // la methode depiler renvoie un pointeur sur expression
    void afficher();
    QString depiler_Aff();

    Pile();
    ~Pile();
    //Pile& get_pile();
   // Expression* calculer(); // methode calculer ???
   // int mode_resultat(); // ???
    int get_m_nombreElement()const // retourne le nombre d'éléments actuel de la pile
    {
        return m_nombreElement;
    }

};
#endif // PILE_H
