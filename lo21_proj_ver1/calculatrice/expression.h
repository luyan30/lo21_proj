#ifndef EXPRESSION_H
#define EXPRESSION_H
#include<QString>
class Nombre;
class Expression {

    public:
    virtual Nombre evaluer()const=0;
    virtual void afficher()const{}
    virtual ~Expression(){}

};

class Operation:public Expression{
int choix;
public:
Operation(int indice):choix(indice){}
//Nombre evaluer(Nombre n1, Nombre n2) const;
~Operation(){}
};

class operationUnitaire:public Operation{
    Expression *ex;
    public:
    operationUnitaire(Expression *x,int indice):Operation(indice),ex(x){}
    ~operationUnitaire(){}
};
class operationBinaire:public Operation{
    Expression *ex1;
    Expression *ex2;
    public:
    operationBinaire(Expression *x1,Expression *x2,int indice):Operation(indice),ex1(x1),ex2(x2){}
    ~operationBinaire(){}
};
class Constant:public Expression
{
protected:
    QString constantExp;
public:
    Constant(QString s):constantExp(s){}
    void afficher();
    //Nombre evaluer(Nombre n1, Nombre n2) const;
    ~Constant(){}
};
class Nombre:public Expression
{
    protected:
        float m_partieReelle;
        float m_partieImaginaire;
        int m_denominateurReel;
        int m_denominateurImaginaire;
        int m_mode;
    public:
        Nombre(float partieReelle=0, int denominateurReel=0, float partieImaginaire=1, int denominateurImaginaire=0, int mode=0);
        Nombre();
        void afficher() ;
        Nombre evaluer()const{return Nombre(*this);}
        ~Nombre(){}

        // ACCESSEURS
            float getPartieReelle() const { return m_partieReelle; }
            float getPartieImaginaire() const { return m_partieImaginaire; }
            int getDenominateurReel() const { return m_denominateurReel; }
            int getDenominateurImaginaire() const { return m_denominateurImaginaire;}
            int getMode() const { return m_mode; }

        // SETTEURS (MODIFICATEURS)
            void setPartieReelle(float nombreReel) { m_partieReelle = nombreReel; }
            void setPartieImaginaire(float nombreImaginaire) { m_partieImaginaire = nombreImaginaire; }
            void setDenominateurReel(int denominateur) { this->m_denominateurReel = denominateur ; }
            void setDenominateurImaginaire(int denominateur) { this->m_denominateurImaginaire = denominateur ; }
};
/*
class Complexe: public Nombre
{
    public:

    const Complexe& Get_complexe() const;

};

class Rationnel: public Nombre
{
    public:

    const Complexe& Get_complexe() const;


};

class Reel: public Nombre
{
    public:

    const Reel& Get_reel() const;


};

class Entier: public Nombre
{
    public:
    const Entier& Get_entier() const;


};

class Degre: public Nombre
{
    public:

    const Complexe& Get_complexe() const;

};

class Radian: public Nombre
{
    public:
    const Complexe& Get_complexe() const;

};*/
#endif // EXPRESSION_H
