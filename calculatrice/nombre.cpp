#include "nombre.h"

/*construction d'un complexe*/

Nombre::Nombre(double partieReelle, double partieImaginaire): m_mode("complexe"),m_partieReelle(partieReelle),m_partieImaginaire (partieImaginaire),m_denominateurReel(1), m_denominateurImaginaire(1)
{
}

/*construction d'un réel*/
Nombre::Nombre(double valeur)
{
    m_mode = "reel";
    m_partieReelle =valeur;
    m_partieImaginaire=0;
    m_denominateurReel = 1;
    this->m_denominateurImaginaire= 1;
}

/*construction d'un rationnel*/
Nombre::Nombre(int numerateur, int denominateur)
{
    m_mode = "rationnel";
    m_partieReelle =(double)numerateur;
    if(denominateur==0) {m_denominateurReel=1; }
    else m_denominateurReel= denominateur;
    m_partieImaginaire=0;
    this->m_denominateurImaginaire = 1;
}

/*construction d'un entier*/
Nombre::Nombre(int valeur)
{
    m_mode = "entier";
    m_partieReelle =(int)valeur;
    m_partieImaginaire=0;
    m_denominateurReel = 1;
    this->m_denominateurImaginaire = 1;
}

/*construction d'un nombre sans arguments*/
Nombre::Nombre():m_partieReelle(0), m_partieImaginaire(0), m_denominateurReel(1), m_denominateurImaginaire(1),m_mode("complexe")
{
}


Complexe::Complexe(double partieReelle, double partieImaginaire):Nombre(partieReelle, partieImaginaire)
{
}

Complexe::Complexe(Reel& r1, Reel& r2) // construction d'un complexe avec deux objets de la classe Reel
{
    this->m_partieReelle = r1.getPartieReelle();
    this->m_partieImaginaire = r2.getPartieReelle();
    this->m_denominateurImaginaire = 1;
    this->m_denominateurReel = 1;
}

Complexe::Complexe(Rationnel& q1, Rationnel& q2) // construction d'un complexe avec deux objets de la classe rationnel
{
    this->m_partieReelle = q1.getPartieReelle();
    this->m_denominateurReel = q1.getDenominateurReel();
    this->m_partieImaginaire = q1.getPartieImaginaire();
    this->m_denominateurImaginaire = q1.getDenominateurImaginaire();
}


Complexe::Complexe(Entier& e1, Entier& e2) // construction d'un complexe avec deux objets de la classe entier
{
    this->m_partieReelle = e1.getPartieReelle();
    this->m_partieImaginaire = e2.getPartieReelle();
    this->m_denominateurImaginaire = 1;
    this->m_denominateurReel = 1;
}

Complexe::Complexe(): Nombre()
{
}

Reel::Reel(double valeur): Nombre(valeur)
{
}

Rationnel::Rationnel(int numerateur, int denominateur): Nombre(numerateur, denominateur)
{
}

Entier::Entier(int valeur):Nombre(valeur)
{
}


// Méthodes la variable Complexe
void Complexe::afficher(std::ostream& f) const	/*affichage d'un complexe*/
{
    if ((this->m_denominateurReel==1)&&(this->m_denominateurReel==1))
        f<<"("<<this->m_partieReelle << ")$(" << this->m_partieImaginaire ;
    else
        f<<"("<<this->m_partieReelle<<"/"<<this->m_denominateurReel << ")$(" << this->m_partieImaginaire << "/" << this->m_denominateurImaginaire << ")" ;
}

const Nombre& Complexe::evaluer() const
{
    return *this;
}

void Reel::afficher(std::ostream& f) const	/*affichage d'un réel*/
{
    f<<this->m_partieReelle ;
}

const Reel& Reel::evaluer() const
{
    return *this;
}

void Rationnel::afficher(std::ostream& f) const	/*affichage d'un rationnel*/
{
    f<<this->m_partieReelle<<"/"<<this->m_denominateurReel ;
}

const Rationnel& Rationnel::evaluer() const
{
    return *this;
}

void Entier::afficher(std::ostream& f) const
{
    f<<this->m_partieReelle ;
}

const Entier& Entier::evaluer() const
{
    return *this;
}



Nombre& Complexe::operator+=(Nombre const& n) // on est en mode complexe
{
    /*if (n.getMode() == "complexe")
    {*/
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
        this->m_partieImaginaire = this->m_partieImaginaire + n.getPartieImaginaire();
        return *this;
    //}
}

Nombre& Reel::operator+=(Nombre const& n) // on est en mode reel
{
    this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
    return *this;
}

Nombre& Rationnel::operator+=(Nombre const& n) // on est en mode rationnel
{
    this->m_partieReelle = (this->m_partieReelle*n.getDenominateurReel()  + n.getPartieReelle()*this->getDenominateurReel());
    this->m_denominateurReel = this->m_denominateurReel*n.getDenominateurReel();
    return *this;
}

Nombre& Entier::operator+=(Nombre const& n) // on est en mode entier
{
    this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
    return *this;
}

Nombre& Complexe::operator-=(Nombre const& n) // on est en mode complexe
{
    /*if (n.getMode() == "complexe")
    {*/
        this->m_partieReelle = this->m_partieReelle - n.getPartieReelle();
        this->m_partieImaginaire = this->m_partieImaginaire - n.getPartieImaginaire();
        return *this;
    //}
}

Nombre& Reel::operator-=(Nombre const& n) // on est en mode reel
{
    this->m_partieReelle = this->m_partieReelle - n.getPartieReelle();
    return *this;
}

Nombre& Rationnel::operator-=(Nombre const& n) // on est en mode rationnel
{
    this->m_partieReelle = (this->m_partieReelle*n.getDenominateurReel()  - n.getPartieReelle()*this->getDenominateurReel());
    this->m_denominateurReel = this->m_denominateurReel*n.getDenominateurReel();
    return *this;
}

Nombre& Entier::operator-=(Nombre const& n) // on est en mode entier
{
    this->m_partieReelle = this->m_partieReelle - n.getPartieReelle();
    return *this;
}
