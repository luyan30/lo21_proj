#ifndef NOMBRE_H
#define NOMBRE_H
#include <string>
#include <iostream>
#include "expression.h"
class Nombre:public Expression
{
    //Expression* result;

    protected:
        float m_partieReelle;
        float m_partieImaginaire;
        int m_denominateurReel;
        int m_denominateurImaginaire;
        std::string m_mode;
    public:
    Nombre(float partieReelle=0, int denominateurReel=0, float partieImaginaire=1, int denominateurImaginaire=0, std::string mode="complexe");


        //méthodes classiques
        //bool pReelIntPas();
        //bool pImagIntNul();
        //bool denominateurLPas();
        void afficher() ; // doit etre une methode virtuelle pure pour rendre la classe abstraite
        //void setMode(std::string mode) ;

        float getPartieReelle() const { return m_partieReelle;}
        float getPartieImaginaire() const { return m_partieImaginaire; }
        int getDenominateurReel() const { return m_denominateurReel; }
        int getDenominateurImaginaire() const { return m_denominateurImaginaire;}
        std::string getMode() const { return m_mode; }
        //Expression* evaluer()const{return result;}
};

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

};

#endif // NOMBRE_H
