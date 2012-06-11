#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include<QString>
#include <iostream>
#include<QRegExp>
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
    virtual void afficher(std::ostream& f=std::cout) const = 0  ;
    virtual QString getPropriete()=0;

    // ACCESSEURS

    // DESTRUCTEURS
    virtual ~Expression(){} // ?

};
class Constant:public Expression{
protected:
    QString constant;
public:
    QString getConstant(){return constant;}
    Constant(QString s):constant(s){}
    Constant(){}
    ~Constant(){}
    const Nombre& evaluer()const
    {
        /*Nombre* c= new Complexe(); // ??
        qDebug("valeur de constant ???");
        return *c;*/
        return *this; // ???
    } // ne retourne rien ??? pkoi ???

    void afficher(std::ostream& f=std::cout) const{}
 QString getPropriete() { return constant; }
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
        virtual Nombre& operator+(Nombre const& n) = 0;
        virtual Nombre& operator-(Nombre const& n) = 0;
        virtual Nombre& operator*(Nombre const& n) = 0;
        virtual Nombre& operator/(Nombre const& n) = 0;
        virtual QString getPropriete()=0;

       int match_affiche() const
       {
            if(this->getPartieImaginaire()==0 &&this->getDenominateurReel()==1)
            {
                return 1;
            }
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
        void afficher(std::ostream& f=std::cout) const  ;
        const Nombre& evaluer() const ;

    //ACCESSEURS

    // DESTRUCTEURS

    // OPERATEURS : a t on besoin de surcharger les opérateurs ? peut etre l'operateur d'affichage vu qu'on va afficher les résultats des calculs ?
        Complexe& operator=(const Complexe& c);
        Nombre& operator+(Nombre const& n) ;
        Nombre& operator-(Nombre const& n) ;
        Nombre& operator*(Nombre const& n) ;
        Nombre& operator/(Nombre const& n) ;
        QString getPropriete(){
             QString s;
          s=QString::number(this->getPartieReelle())+"$"+QString::number(this->getPartieImaginaire());
                                return s;}


};
class Reel: public Nombre
{
    public:
    // CONSTRUCTEURS
    Reel(double valeur);
    Reel(): Nombre() {}

    // METHODES CLASSIQUEs

    // METHODES REDEFINIES
        void afficher(std::ostream& f=std::cout) const  ;
        const Reel& evaluer() const ;


    // DESTRUCTEURS

    // OPERATEURS
        Reel& operator=(const Reel& r);
        Nombre& operator+(Nombre const& n);
        Nombre& operator-(Nombre const& n);
        Nombre& operator*(Nombre const& n);
        Nombre& operator/(Nombre const& n);
        QString getPropriete(){
                    QString s;
                s=QString::number(this->getPartieReelle()).replace(".",",");
                                       return s;}

};

class Rationnel: public Nombre
{
    public:
    // CONSTRUCTEURS
    Rationnel(int numerateur, int denominateur);
    Rationnel():Nombre() {}

    // METHODES CLASSIQUEs

    // METHODES REDEFINIES
        void afficher(std::ostream& f=std::cout) const  ;
        const Rationnel& evaluer() const ;
        QString getPropriete(){
            QString s;
            s=QString::number(this->getPartieReelle())+"/"+QString::number(this->getDenominateurReel());
            return s;
            }

    // ACCESSEURS


    // DESTRUCTEURS

    // OPERATEURS
        Rationnel& operator=(const Rationnel& q);
        Nombre& operator+(Nombre const& n);
        Nombre& operator-(Nombre const& n);
        Nombre& operator*(Nombre const& n) ;
        Nombre& operator/(Nombre const& n) ;

};
class Entier: public Nombre
{
    public:
    //constructeurs
    Entier(int valeur);
    Entier(): Nombre() {}
    // METHODES CLASSIQUES

    // METHODES REDEFINIES
        void afficher(std::ostream& f=std::cout) const  ;
        const Entier& evaluer() const ;
        QString getPropriete(){
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


class Operation : public Expression
{
protected:
    int choix;
public:
   // CONSTRUCTEURS
  //  Operation(Expression* x1,Expression* x2,int indice):ex1(x1),ex2(x2),choix(indice){}
  //  Operation(Expression* x1, int indice):ex1(x1), choix(indice), ex2(0){}
 Operation( int indice): choix(indice){}
 int getIndice(){return choix;}
  QString match_indice(int indice);
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
  Expression* evaluer2();
    // METHODES REDEFINIES
    const Nombre& evaluer() const  ; // ?
    void afficher(std::ostream& f=std::cout) const;
    QString getPropriete(){
        return this->match_indice(this->getIndice());
        }
    QString getResult(){return this->evaluer2()->getPropriete();}


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

   //Expression* evaluer()const;// ?
    void afficher(std::ostream& f=std::cout) const ;
    QString getPropriete(){
        return this->match_indice(this->getIndice());
        }
    //QString getResult(){return this->evaluer().getPropriete();}
    //Expression* evaluer() const;
};

#endif // EXPRESSION_H
