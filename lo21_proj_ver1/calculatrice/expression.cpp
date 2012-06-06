#include "expression.h"
Nombre::Nombre()
{
    //std::cout << "nombre construit! avec premier constructeur" << std::endl;
    m_partieReelle=0;
    m_partieImaginaire=0;
    m_denominateurReel=0;
    m_denominateurImaginaire=0;
    m_mode=0;
}

Nombre::Nombre(float partieReelle, int denominateurReel, float partieImaginaire, int denominateurImaginaire, int mode):
m_partieReelle(partieReelle), m_partieImaginaire(partieImaginaire),m_denominateurReel(denominateurReel),m_denominateurImaginaire(denominateurImaginaire),m_mode(mode)
{
   // std::cout << "nombre construit! avec deuxieme constructeur" << std::endl;

}

void Nombre::afficher()
{
}

/*
Nombre Operation::evaluer()const {

    if (choix==1)//multiplication
    {//ex1->evaluer()*ex2->evaluer()
        return new Nombre(0,0,0,0,0);}

}*/
