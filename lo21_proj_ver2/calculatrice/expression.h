#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include<QString>
#include <iostream>
#include<QRegExp>
#include<Qdebug>
#include <math.h> // bibliotheque mathematique
class Nombre;
class Complexe;
class Reel;
class Rationnel;
class Entier;

class Expression
{
private:

public:

    // CONSTRUCTEURS

    // METHODES CLASSIQUES
    virtual const Nombre& evaluer() const = 0 ; // ?
    //virtual void afficher(std::ostream& f=std::cout) const = 0  ;
    virtual QString getPropriete()=0;

    // ACCESSEURS

    // DESTRUCTEURS
    virtual ~Expression(){} // ?

};


class Nombre: public Expression
{

    protected: // pour que les methodes des classes filles puissent y accer

    // ATTRIBUTS
        double m_partieReelle;
        double m_partieImaginaire;
        int m_denominateurReel;
        int m_denominateurImaginaire;
        std::string m_mode;

    // METHODE PRIVEE / PROTEGEE
        void setMode(std::string mode) { m_mode = mode ; } // pour qu'un utilisateur ne puisse jamais changer la nature d'un nombre

    public:

    // CONSTRUCTEURS

    //Nombre(double partieReelle=0, int denominateurReel=0, double partieImaginaire=1, int denominateurImaginaire=0, std::string mode="complexe"); // construction de n'importe quel nombre ?

    /*construction d'un complexe*/
    Nombre(double partieReelle, double partieImaginaire);

    /*construction d'un réel*/
    Nombre(double valeur);

    /*construction d'un rationnel*/
    Nombre(int numerateur, int denominateur);

    /*construction d'un entier*/
    Nombre(int valeur);

    /*construction d'un nombre par defaut*/
    Nombre();

    /*construction par recopie*/
     /*Nombre(const Nombre& n): m_partieReelle(n.getPartieReelle()),
            m_partieImaginaire(n.getPartieImaginaire()),
            m_denominateurReel(n.getDenominateurReel()),
            m_denominateurImaginaire(n.getDenominateurImaginaire()){} // et l'initialisation de m_mode ??? peut on laisser ça comme ça ?*/

    // METHODES CLASSIQUES


    // ACCESSEURS
        double getPartieReelle() const { return m_partieReelle; }
        double getPartieImaginaire() const { return m_partieImaginaire; }
        int getDenominateurReel() const { return m_denominateurReel; }
        int getDenominateurImaginaire() const { return m_denominateurImaginaire;}
        std::string getMode() const { return m_mode; }

    // SETTEURS (MODIFICATEURS)
        void setPartieReelle(double nombreReel) { m_partieReelle = nombreReel; }
        void setPartieImaginaire(double nombreImaginaire) { m_partieImaginaire = nombreImaginaire; }
        void setDenominateurReel(int denominateur) { this->m_denominateurReel = denominateur ; }
        void setDenominateurImaginaire(int denominateur) { this->m_denominateurImaginaire = denominateur ; }
        //void setMode(std::string mode) ;

    // DESTRUCTEURS

    // OPERATEURS : a t on besoin de surcharger les opérateurs ? peut etre l'operateur d'affichage vu qu'on va afficher les résultats des calculs ?
        virtual Nombre& operator+(const Nombre& n) = 0;
        virtual Nombre& operator-(const Nombre& n) = 0;
        virtual Nombre& operator*(const Nombre& n) = 0;
        virtual Nombre& operator/(const Nombre& n) = 0;
       // virtual QString getPropriete()=0; // convertit le nombre en string en respectant l'affichage correct

       int match_affiche() const // pour quoi faire ?
       {
            if(this->getPartieImaginaire()==0 &&this->getDenominateurReel()==1)
            {
                return 1;
            } // et sinon ???
       }
};
class Constant:public Expression // pour les expressions constantes
{
    protected:
       QString constant;
    public:
       QString getConstant()
       {
           return constant;
       }
        Constant(QString s):constant(s)
       {
       }

        //Constant(){} // ??
      // ~Constant(){}
    const Nombre& evaluer() const ;// convertir un QString en Nombre&, n'est ce pas possible ?

   // void afficher(std::ostream& f=std::cout) const{}
    QString getPropriete()// pareil que getContant() ici !
    {
         return constant;
    }
};

class Complexe: public Nombre
{
    public:
        // CONSTRUCTEURS
    //Nombre(double partieReelle=0, int denominateurReel=0, double partieImaginaire=1, int denominateurImaginaire=0, std::string mode="complexe"); // construction de n'importe quel nombre ?

    /*construction d'un complexe*/
    Complexe(double partieReelle, double partieImaginaire); // construction d'un complexe avec deux nombres réels simples(float, double...)
    Complexe(Reel& r1, Reel& r2); // construction d'un complexe avec deux objets de la classe Reel
    Complexe(Rationnel& q1, Rationnel& q2); // construction d'un complexe avec deux objets de la classe rationnel
    Complexe(Entier& e1, Entier& q2); // construction d'un complexe avec deux objets de la classe rationnel
    Complexe();


    // METHODES REDEFINIES
       // void afficher(std::ostream& f=std::cout) const  ;
        const Complexe& evaluer() const ;
        QString getPropriete()
        {
            QString s;
            s=(QString::number(this->getPartieReelle())+"$"+QString::number(this->getPartieImaginaire()));
            return s;
        }

    //ACCESSEURS

    // DESTRUCTEURS

    // OPERATEURS : a t on besoin de surcharger les opérateurs ? peut etre l'operateur d'affichage vu qu'on va afficher les résultats des calculs ?
        Complexe& operator=(const Complexe& c);
        Nombre& operator+(const Nombre& n) ;
        Nombre& operator-(const Nombre& n) ;
        Nombre& operator*(const Nombre& n) ;
        Nombre& operator/(const Nombre& n) ;



};

class Reel: public Nombre
{
    public:
    // CONSTRUCTEURS
    Reel(double valeur);
    Reel(): Nombre() {}

    // METHODES CLASSIQUEs

    // METHODES REDEFINIES
     //   void afficher(std::ostream& f=std::cout) const  ;
        const Reel& evaluer() const ;
        QString getPropriete()
        {
            QString s;
            s=QString::number(this->getPartieReelle()).replace(".",","); // remplace le point par une virgule !
            return s;
        }


    // DESTRUCTEURS

    // OPERATEURS
        Reel& operator=(const Reel& r);
        Nombre& operator+(const Nombre& n);
        Nombre& operator-(const Nombre& n);
        Nombre& operator*(const Nombre& n);
        Nombre& operator/(const Nombre& n);


};

class Rationnel: public Nombre
{
    public:
    // CONSTRUCTEURS
    Rationnel(int numerateur, int denominateur);
    Rationnel():Nombre() {}

    // METHODES CLASSIQUEs

    // METHODES REDEFINIES
    //    void afficher(std::ostream& f=std::cout) const  ;
        const Rationnel& evaluer() const ;
        QString getPropriete()
        {
            QString s;
            s=QString::number(this->getPartieReelle())+"/"+QString::number(this->getDenominateurReel());
            return s;
        }

    // ACCESSEURS


    // DESTRUCTEURS

    // OPERATEURS
        Rationnel& operator=(const Rationnel& q);
        Nombre& operator+(const Nombre& n);
        Nombre& operator-(const Nombre& n);
        Nombre& operator*(const Nombre& n) ;
        Nombre& operator/(const Nombre& n) ;

};

class Entier: public Nombre
{
    public:
    //constructeurs
    Entier(int valeur);
    Entier(): Nombre() {}
    // METHODES CLASSIQUES

    // METHODES REDEFINIES
     //   void afficher(std::ostream& f=std::cout) const  ;
        const Entier& evaluer() const ;
        QString getPropriete()
        {
              return QString::number(this->getPartieReelle());
        }

    // ACCESSEURS


    // DESTRUCTEURS

    // OPERATEURS
        Entier& operator=(const Entier& e);
        Nombre& operator+(const Nombre& n);
        Nombre& operator-(const Nombre& n);
        Nombre& operator*(const Nombre& n);
        Nombre& operator/(const Nombre& n);

};

/*class Degre: public Nombre
{
    public:
    //constructeurs

    //méthodes classiques

    //accesseurs
    const Complexe& Get_complexe() const;

    //destructeurs

};

class Radian: public Nombre
{
    public:
    //constructeurs

    //méthodes classiques

    //accesseurs
    const Complexe& Get_complexe() const;

    //destructeurs

};    */



int pgcd (int a, int b);
void simplifier (Rationnel& r);
Nombre&/*double*/ power( const Nombre& n, const Nombre& e); // ok en theorie mais provoque une erreur: probleme dans traitment ...
Nombre&/*int*/ modulo(const Nombre& e1, const Nombre& e2); // ok en theorie mais provoque une erreur au bout d'un certain temps ...
Nombre& inversionSigne(const Nombre& n); // ok !
Nombre& sinus(const Nombre& n) ; // fait    ok
Nombre& cosinus(const Nombre& n) ; // fait ok
Nombre& tangente(const Nombre& n) ; // fait ok
Nombre& sinusHyperbolique(const Nombre& n) ; // fait ok
Nombre& cosinusHyperbolique(const Nombre& n) ; // fait ok
Nombre& tangenteHyperbolique(const Nombre& n) ; // fait ok
Nombre& logarithme(const Nombre& n)  ; // fait ok
Nombre& inverse(const Nombre& n) ; // fait ok
Nombre& racineCarree(const Nombre& n) ; // fait
Nombre& fonctionCarree(const Nombre& n) ; // fait ok
Nombre& logarithme10(const Nombre& n) ;// fait ok
Nombre& fonctionCube(const Nombre& n) ; //fait : à tester ok
Nombre& factoriel(const Nombre& n)  ; // fait : ok
// reste: exceptions , diagramme de sequence, rapport, integrer retablir et annuler, fonction traitement et eval ?




class Operation : public Expression
{
protected:
    int choix;
public:
   // CONSTRUCTEURS
     Operation( int indice): choix(indice){}

  //  Operation(Expression* x1,Expression* x2,int indice):ex1(x1),ex2(x2),choix(indice){}
  //  Operation(Expression* x1, int indice):ex1(x1), choix(indice), ex2(0){}

 int getIndice() const { return choix; }
  QString match_indice(int indice); // ???
    //Expression* evaluer() const;
};

class OperationBinaire : public Operation // classe concrete
{
private:
    Expression* ex1;
    Expression* ex2;

public:

    // CONSTRUCTEURS
    OperationBinaire(Expression* x1,Expression* x2,int indice):Operation(indice),ex1(x1),ex2(x2){} // une operation binaire contient deux "expressions"


    // METHODES REDEFINIES
    const Nombre& evaluer() const  ; // ?
    //void afficher(std::ostream& f=std::cout) const;
    QString getPropriete() // va renvoyer un nombre ???
    {
        return this->match_indice(this->getIndice());
    }

    //METHODES CLASSIQUES
    QString getResult()  { return this->evaluer2()->getPropriete(); } // retourne le resultat de l'operation sous forme de string ???
    Expression* evaluer2();

    //Expression* evaluer() const;
};

class OperationUnaire : public Operation // classe concrete
{
private:
    Expression* ex1;

public:

    // CONSTRUCTEURS
    OperationUnaire(Expression* x1,int indice):Operation(indice),ex1(x1){} // une operation unaire contient deux "expressions"

    // METHODES REDEFINIES
    const Nombre& evaluer() const ;
    Expression* evaluer2() ;
     QString getResult()  { return this->evaluer2()->getPropriete(); }
    QString getPropriete() // va renvoyer un nombre ???
    {
        return this->evaluer2()->getPropriete();
    }


   //Expression* evaluer()const;// ?
    //void afficher(std::ostream& f=std::cout) const ;

    //QString getResult(){return this->evaluer().getPropriete();}
    //Expression* evaluer() const;
};

#endif // EXPRESSION_H
