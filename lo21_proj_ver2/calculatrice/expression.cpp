#include "expression.h"
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
    if (n.getMode() == "complexe") // addition de deux nombres complexes
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
        this->m_partieImaginaire = this->m_partieImaginaire + n.getPartieImaginaire();
        return *this;
    }


    if (n.getMode() == "reel") // addition d'un nombre complexe et d'un reel
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
        return *this;
    }

    if (n.getMode() == "rationnel") // addition d'un nombre complexe et d'un rationnel
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
        return *this;
    }

    if (n.getMode() == "rationnel") // addition d'un nombre complexe et d'un rationnel, on convertit le rationnel en reel avant de l'ajouter au complexe
    {
        double* temp = new double(0);
        *temp = (double) (n.getPartieReelle() / n.getDenominateurReel());
        this->m_partieReelle = this->m_partieReelle + (*temp);
        delete temp;
        return *this;
    }

    if (n.getMode() == "entier") // addition d'un nombre complexe et d'un entier
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
        return *this;
    }

else return *this;
}

Nombre& Reel::operator+=(Nombre const& n) // on est en mode reel
{
    if (n.getMode() == "complexe") // addition d'un reel et d'un complexe
    {
        Nombre* c = new Complexe();
      //  *c+=n;
        //*c+=(*this);
        // upcasting de reel en complexe ???
        c->setPartieReelle(n.getPartieReelle()+(*this).getPartieReelle());
        c->setPartieImaginaire(n.getPartieImaginaire());
        //delete c;
        return *c;
    }

    if (n.getMode() == "reel") // addition de deux nombres reels
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
        return *this;
    }

    if (n.getMode() == "rationnel") // addition d'un nombre reel et d'un rationnel
    {
        /*Nombre* temp = new Complexe(*this);
        *temp+=n;
        *this=*temp;
        return *this;

        */
        double* temp = new double(0);
        *temp = (double) (n.getPartieReelle() / n.getDenominateurReel());
        this->m_partieReelle = this->m_partieReelle + (*temp);
        delete temp;
        return *this;
    }

    if (n.getMode() == "entier") // addition d'un nombre reel et d'un entier
    {
        this->m_partieReelle += n.getPartieReelle();
        return *this;
    }
else return *this;
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

Nombre& Complexe::operator*=(Nombre const& n)
{
    double* temp1= new double(0);
    double* temp2= new double(0);

    *temp1=(this->m_partieReelle*n.getPartieReelle())-(this->m_partieImaginaire*n.getPartieImaginaire());
    *temp2=(this->m_partieReelle*n.getPartieImaginaire())+(this->m_partieImaginaire*n.getPartieReelle());
    this->m_partieReelle=*temp1;
    this->m_partieImaginaire=*temp2;
    delete temp1;
    delete temp2; // pour libérer l'espace mémoire allou?
    return *this;
}

Nombre& Reel::operator*=(Nombre const& n) // on est en mode reel
{
    this->m_partieReelle *= n.getPartieReelle();
    return *this;
}

Nombre& Rationnel::operator*=(Nombre const& n) // on est en mode rationnel
{
    this->m_partieReelle *=n.getPartieReelle();
    this->m_denominateurReel *=n.getDenominateurReel();
    return *this;
}

Nombre& Entier::operator*=(Nombre const& n) // on est en mode entier
{
    this->m_partieReelle *=n.getPartieReelle();
    return *this;
}

Nombre& Complexe::operator/=(Nombre const& n)
{
    double* temp1= new double(0);
    double* temp2= new double(0);

    *temp1=(this->m_partieReelle*n.getPartieReelle())-(this->m_partieImaginaire*n.getPartieImaginaire());
    *temp2=(this->m_partieReelle*n.getPartieImaginaire())+(this->m_partieImaginaire*n.getPartieReelle());
    this->m_partieReelle=*temp1;
    this->m_partieImaginaire=*temp2;

    delete temp1;
    delete temp2;
    return *this;
}

Nombre& Reel::operator/=(Nombre const& n) // on est en mode reel
{
    this->m_partieReelle /= n.getPartieReelle();
    return *this;
}

Nombre& Rationnel::operator/=(Nombre const& n) // on est en mode rationnel
{
    this->m_partieReelle *=n.getDenominateurReel();
    this->m_denominateurReel *=n.getPartieReelle();
    return *this;
}

Nombre& Entier::operator/=(Nombre const& n) // on est en mode entier ???
{
    this->m_partieReelle /=n.getPartieReelle(); /// ??? division de deux entiers doit donner quoi ???
    return *this;
}

const Nombre& OperationBinaire::evaluer() const
{	Nombre* c= new Complexe(); // pointeur sur nombre qui sera initialis?par le constructeur sans argument

    if (this->choix ==1) // on a choisi l'addition
    {
        *c+= ex1->evaluer();
        *c+= ex2->evaluer();
    }

    if (this->choix ==2) // on a choisi la soustraction
    {
        *c+= ex1->evaluer();
        *c-= ex2->evaluer();
    }

    if (this->choix ==3) // on a choisi la multiplication
    {
        *c+= ex1->evaluer();
        *c*= ex2->evaluer();
    }

    if (this->choix ==4) // on a choisi la division
    {
        *c+= ex1->evaluer();
        *c/= ex2->evaluer();
    }
    return *c;
}

const Nombre& OperationUnaire::evaluer() const
{
    Nombre* c=new Complexe();
    return *c;
}

void OperationUnaire::afficher(std::ostream& f) const
{
    f<< "Operation Unaire " << std::endl ;

}

void OperationBinaire::afficher(std::ostream& f) const
{
    f<< "Operation Binaire " << std::endl ;

}
