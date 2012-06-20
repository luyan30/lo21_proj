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
    simplifier(*this); // pour simplifier le numérateur et le dénominateur
}

Entier::Entier(int valeur):Nombre(valeur)
{
}


// Méthodes la variable Complexe
/*void Complexe::afficher(std::ostream& f) const
{
    if ((this->m_denominateurReel==1)&&(this->m_denominateurReel==1))
        f<<"("<<this->m_partieReelle << ")$(" << this->m_partieImaginaire ;
    else
        f<<"("<<this->m_partieReelle<<"/"<<this->m_denominateurReel << ")$(" << this->m_partieImaginaire << "/" << this->m_denominateurImaginaire << ")" ;
}*/

const Complexe &Complexe::evaluer() const
{
    return *this;
}

/*void Reel::afficher(std::ostream& f) const
{
    f<<this->m_partieReelle ;
}*/

const Reel &Reel::evaluer() const
{
    return *this;
}

/*void Rationnel::afficher(std::ostream& f) const
{
    f<<this->m_partieReelle<<"/"<<this->m_denominateurReel ;
}*/

 const Rationnel& Rationnel::evaluer() const
{
    return *this;
}

/*void Entier::afficher(std::ostream& f) const
{
    f<<this->m_partieReelle ;
}*/

 const Entier& Entier::evaluer() const
{
    return *this;
}



Complexe& Complexe::operator=(const Complexe& c)
{
    if (this!=&c)
    {
        this->setDenominateurImaginaire(c.getDenominateurImaginaire());
        this->setDenominateurReel(c.getDenominateurReel());
        this->setPartieReelle(c.getPartieReelle());
        this->setPartieImaginaire(c.getPartieImaginaire());
        this->setMode(c.getMode()); // cette methode est privée
    }
    return *this;
}

Reel& Reel::operator=(const Reel& r)
{
    if (this!=&r)
    {
        //this->setDenominateurImaginaire(c.getDenominateurImaginaire());
        //this->setDenominateurReel(c.getDenominateurReel());
        this->setPartieReelle(r.getPartieReelle());
        //this->setPartieImaginaire(c.getPartieImaginaire());
        this->setMode(r.getMode()); // cette methode est privée
    }
    return *this;
}

Rationnel& Rationnel::operator=(const Rationnel& q)
{
    if (this!=&q)
    {
        this->setDenominateurImaginaire(q.getDenominateurImaginaire());
        this->setDenominateurReel(q.getDenominateurReel());
        this->setPartieReelle(q.getPartieReelle());
        this->setPartieImaginaire(q.getPartieImaginaire());
        this->setMode(q.getMode()); // cette methode est privée
    }
    return *this;
}

Entier& Entier::operator=(const Entier& e)
{
    if (this!=&e)
    {
        this->setDenominateurImaginaire(e.getDenominateurImaginaire());
        this->setDenominateurReel(e.getDenominateurReel());
        this->setPartieReelle(e.getPartieReelle());
        this->setPartieImaginaire(e.getPartieImaginaire());
        this->setMode(e.getMode()); // cette methode est privée
    }
    return *this;
}


Nombre& Complexe::operator+(const Nombre& n) // on est en mode complexe  : Ok !
{
    if (n.getMode() == "complexe") // addition de deux nombres complexes
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
        this->m_partieImaginaire = this->m_partieImaginaire + n.getPartieImaginaire();

    }


    if (n.getMode() == "reel") // addition d'un nombre complexe et d'un reel
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();

    }

    if (n.getMode() == "rationnel") // addition d'un nombre complexe et d'un rationnel, on convertit le rationnel en reel avant de l'ajouter au complexe
    {
        double* temp = new double(0);
        *temp = (double) (n.getPartieReelle() / n.getDenominateurReel());
        this->m_partieReelle += (*temp);
        delete temp;
    }

    if (n.getMode() == "entier") // addition d'un nombre complexe et d'un entier
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();
    }
    return *this;
}

Nombre& Reel::operator+(const Nombre& n) // on est en mode reel : Ok !
{
    if (n.getMode() == "complexe") // addition d'un reel et d'un complexe
    {
        Nombre* c = new Complexe();
        (*c)=(*c) + n;      // ne pas mettre "*c+=n" : ajouter des parentheses
        (*c)= (*c)+(*this);
        // upcasting de reel en complexe ???
        //*this = *c;
        //delete c;
        return *c;
    }

    if (n.getMode() == "reel") // addition de deux nombres reels
    {
        this->m_partieReelle = this->m_partieReelle + n.getPartieReelle();

    }

    if (n.getMode() == "rationnel") // addition d'un nombre reel et d'un rationnel
    {
        /*Nombre* temp = new Complexe(*this);
        *temp+=n;
        *this=*temp;
        return *this;

        */
        double* temp = new double(0);
        (*temp) = (double) (n.getPartieReelle() / n.getDenominateurReel());
        this->m_partieReelle += (*temp);
        delete temp;
    }

    if (n.getMode() == "entier") // addition d'un nombre reel et d'un entier
    {
        this->m_partieReelle += n.getPartieReelle();
    }
    return *this;
}

Nombre& Rationnel::operator+(const Nombre& n) // on est en mode rationnel : Ok !
{
    if (n.getMode() == "complexe") // addition d'un nombre rationnel et d'un complexe:
    {
        Nombre* c = new Complexe(0,0);
        //(*c).afficher();
        (*c)= (*c)+(n); // addition de complexes
        //(*c).afficher();
        (*c) = (*c) + (*this); // addition de complexe et rationnel
        return *c;
    }

    if (n.getMode() == "reel") // addition d'un nombre rationnel et d'un reel
    {
        Nombre* r = new Reel();
        (*r)=(*r)+n;
        (*r)=(*r)+(*this);
        //dynamic casting de reel en rationnel ???
        return *r;
    }

    if (n.getMode() == "rationnel") // addition de deux nombres rationnels
    {
        this->m_partieReelle = (this->m_partieReelle*n.getDenominateurReel()  + n.getPartieReelle()*this->getDenominateurReel());
        this->m_denominateurReel = this->m_denominateurReel*n.getDenominateurReel();
        //simplifier apres addition de deux rationnels: implementer la fonction simplifier à inclure/utiliser dans le constructeur de rationnel
    }

    if (n.getMode() == "entier") // addition d'un nombre rationnel et d'un entier
    {
        this->m_partieReelle = this->m_partieReelle + (this->m_denominateurReel*n.getPartieReelle());
        // simplifier rationnel
    }

    return *this;
}

Nombre& Entier::operator+(const Nombre& n) // on est en mode entier
{
    if (n.getMode() == "complexe") // addtion d'un entier avec un complexe
    {
        Nombre* c = new Complexe();
        (*c)=(*c)+n;
        (*c)=(*c)+(*this);
        //dynamic casting de reel en rationnel ???
        return *c;
    }

    if (n.getMode() == "reel") // addition d'un entier avec un reel
    {
        this->m_partieReelle +=n.getPartieReelle();
    }
    if (n.getMode() == "rationnel") // addition d'un entier avec un rationnel
    {
        Nombre* q = new Rationnel();
        (*q)=n; // q = n
        (*q)=(*q)+(*this); // addition d'un rationnel et d'un entier
        return *q;
    }

    if (n.getMode() == "entier") // // addition d'un entier avec un entier
    {
        this->m_partieReelle +=n.getPartieReelle();
    }

    return *this;
}

Nombre& Complexe::operator-(const Nombre& n) // on est en mode complexe : Ok !
{
    if (n.getMode() == "complexe") // soustraction de deux nombres complexes
    {
        this->m_partieReelle = this->m_partieReelle - n.getPartieReelle();
        this->m_partieImaginaire = this->m_partieImaginaire - n.getPartieImaginaire();
    }

    if (n.getMode() == "reel") // soustraction d'un nombre complexe et d'un reel
    {
        this->m_partieReelle = this->m_partieReelle - n.getPartieReelle();
    }

    if (n.getMode() == "rationnel") // soustraction d'un nombre complexe et d'un rationnel, on convertit le rationnel en reel avant de l'ajouter au complexe
    {
        double* temp = new double(0);
        *temp = (double) (n.getPartieReelle() / n.getDenominateurReel());
        this->m_partieReelle -= (*temp);
        delete temp;
    }

    if (n.getMode() == "entier") // addition d'un nombre complexe et d'un entier
    {
        this->m_partieReelle -= n.getPartieReelle();
    }
    return *this;

}

Nombre& Reel::operator-(const Nombre& n) // on est en mode reel
{
    if (n.getMode() == "complexe") // soustraction d'un reel et d'un complexe
    {
        Nombre* c = new Complexe(m_partieReelle-n.getPartieReelle(), n.getPartieImaginaire());
        //Nombre* r = new Reel(m_partieReelle);
        //(*c)=(*c) + n;      // ne pas mettre "*c+=n" : ajouter des parentheses
        //(*c)= (*c)+(*r);
        // upcasting de reel en complexe ???
        //*this = *c;
        //delete c;
        //delete r;
        return *c;
    }

    if (n.getMode() == "reel") // addition de deux nombres reels
    {
        this->m_partieReelle = this->m_partieReelle - n.getPartieReelle();

    }

    if (n.getMode() == "rationnel") // addition d'un nombre reel et d'un rationnel
    {
        /*Nombre* temp = new Complexe(*this);
        *temp+=n;
        *this=*temp;
        return *this;

        */
        double* temp = new double(0);
        (*temp) = (double) (n.getPartieReelle() / n.getDenominateurReel());
        this->m_partieReelle -= (*temp);
        delete temp;
    }

    if (n.getMode() == "entier") // addition d'un nombre reel et d'un entier
    {
        this->m_partieReelle -= n.getPartieReelle();
    }
    return *this;
}

Nombre& Rationnel::operator-(const Nombre& n) // on est en mode rationnel : Ok !
{
    if (n.getMode() == "complexe") // addition d'un nombre rationnel et d'un complexe:
    {
        Nombre* c = new Complexe(-n.getPartieReelle(), -n.getPartieImaginaire());
        (*c) = (*c) + (*this);
        //double* temp = new double(0);
        //*temp = (double) (m_partieReelle / m_partieImaginaire);
        //(*c).afficher();
        //(*c)= (*c)+(n); // addition de complexes
        //(*c).afficher();
        //(*c) = (*c) + (*temp); // addition de complexe et rationnel
        //delete temp;
        return *c;
    }

    if (n.getMode() == "reel") // addition d'un nombre rationnel et d'un reel
    {
        Nombre* r = new Reel(-n.getPartieReelle());
        //(*r)=(*r)+n;
        (*r)=(*r)+(*this);
        //dynamic casting de reel en rationnel ???
        return *r;
    }

    if (n.getMode() == "rationnel") // addition de deux nombres rationnels
    {
        Nombre* q= new Rationnel();
        q->setPartieReelle((this->m_partieReelle*n.getDenominateurReel()  - n.getPartieReelle()*this->getDenominateurReel()));
        q->setDenominateurReel(this->m_denominateurReel*n.getDenominateurReel());
        //simplifier apres addition de deux rationnels: implementer la fonction simplifier à inclure/utiliser dans le constructeur de rationnel
        return *q;
    }

    if (n.getMode() == "entier") // addition d'un nombre rationnel et d'un entier
    {
        Nombre* q = new Rationnel();
        q->setPartieReelle(this->m_partieReelle + (this->m_denominateurReel*n.getPartieReelle()));
        return *q;
        // simplifier rationnel
    }
    //return *this;
}

Nombre& Entier::operator-(const Nombre& n) // on est en mode entier
{
    if (n.getMode() == "complexe") // addtion d'un entier avec un complexe
    {
        Nombre* c = new Complexe(-n.getPartieReelle(), -n.getPartieImaginaire()); // ???
        //(*c)=(*c)+n;
        (*c)=(*c)+(*this);
        //dynamic casting de reel en rationnel ???
        return *c;
    }

    if (n.getMode() == "reel") // addition d'un entier avec un reel
    {
        Nombre* r = new Reel(-n.getPartieReelle());
        (*r)=(*r)+(*this);
        return *r ;
    }

    if (n.getMode() == "rationnel") // addition d'un entier avec un rationnel
    {
        Nombre* q = new Rationnel(-n.getPartieReelle(),n.getDenominateurReel());
        //(*q)=n; // q = n
        (*q)=(*q)+(*this); // addition d'un rationnel et d'un entier
        return *q;

    }

    if (n.getMode() == "entier") // // addition d'un entier avec un entier
    {
        Nombre* e= new Entier(this->m_partieReelle - n.getPartieReelle());
        return *e;

    }

    return *this;
}

// A partir d'ici jusqu'en bas , c'est bon. EN haut faut juste modifier les operateurs pour qu'ils ne changent pas les deux classes en parametre mais en renvoie une nouvelle allouee dynamiquement
//
//
Nombre& Complexe::operator*(const Nombre& n) // on est en mode complexe : Ok !
{
    if (n.getMode() =="complexe" )
    {
        Nombre* c = new Complexe();
        c->setPartieReelle(n.getPartieReelle()*m_partieReelle - n.getPartieImaginaire()*m_partieImaginaire );
        c->setPartieImaginaire(n.getPartieReelle()*m_partieImaginaire + n.getPartieImaginaire()*m_partieReelle);
        return *c;
    }

    if (n.getMode() == "reel" )
    {
        Nombre* c = new Complexe(m_partieReelle*n.getPartieReelle(), m_partieImaginaire*n.getPartieReelle());
        return *c;
    }

    if (n.getMode() == "rationnel" )
    {
        Nombre* c = new Complexe();
        double* temp = new double(0);
        *temp = (double) (n.getPartieReelle() / n.getDenominateurReel() );
        c->setPartieReelle( (*temp)*(m_partieReelle));
        c->setPartieImaginaire((*temp)*(m_partieImaginaire));
        return *c;
    }

    if (n.getMode() == "entier" )
    {
        Nombre* c = new Complexe(m_partieReelle*n.getPartieReelle(), m_partieImaginaire*n.getPartieReelle());
        return *c;

    }

}

Nombre& Reel::operator*(const Nombre& n) // on est en mode reel : Ok !
{
    if (n.getMode() =="complexe" )
    {
        Nombre* c = new Complexe();
        *c = n;
        (*c) = (*c)*(*this);
        //c->setPartieReelle(n.getPartieReelle()*m_partieReelle - n.getPartieImaginaire()*m_partieImaginaire );
        //c->setPartieImaginaire(n.getPartieReelle()*m_partieImaginaire + n.getPartieImaginaire()*m_partieReelle);
        return *c;
    }

    if (n.getMode() == "reel" )
    {
        Nombre* c = new Reel(m_partieReelle*n.getPartieReelle());
        return *c;
    }

    if (n.getMode() == "rationnel" ) // ??? et si le reel est un entier ? faut juste multiplier le reel et le numerateur
    {
        Nombre* c = new Reel();
        double* temp = new double(0);
        *temp = (double) (n.getPartieReelle() / n.getDenominateurReel() );
        c->setPartieReelle( (*temp)*(m_partieReelle));

        return *c;
    }

    if (n.getMode() == "entier" )
    {
        Nombre* c = new Reel(m_partieReelle*n.getPartieReelle());
        return *c;

    }
}

Nombre& Rationnel::operator*(const Nombre& n) // on est en mode rationnel
{
    if (n.getMode() =="complexe" )
    {
        Nombre* c = new Complexe();
        (*c) = n ;
        (*c) = (*c) * (*this);
        return *c;
    }

    if (n.getMode() == "reel" )
    {
        Nombre* r = new Reel();
        (*r) = n;
        (*r) = (*r) * (*this);
        return *r;
    }

    if (n.getMode() == "rationnel" )
    {
        Nombre* q = new Rationnel();
        (*q) = n ;
        q->setPartieReelle(q->getPartieReelle() * this->getPartieReelle());
        q->setDenominateurReel(q->getDenominateurReel() * this->getDenominateurReel());
        return *q;
    }

    if (n.getMode() == "entier" )
    {
        Nombre* c = new Rationnel();
        (*c) = (*this);
        c->setPartieReelle(n.getPartieReelle()*(this->getPartieReelle()));
        return *c;
    }
}

Nombre& Entier::operator*(const Nombre& n) // on est en mode entier : Ok !
{
    if (n.getMode() =="complexe" )
    {
        Nombre* c = new Complexe();
        c->setPartieReelle(this->getPartieReelle()*n.getPartieReelle());
        c->setPartieImaginaire(this->getPartieReelle()*n.getPartieImaginaire());
        return *c;
    }

    if (n.getMode() =="reel" )
    {
        Nombre* r = new Reel();
        (*r) = n ;
        (*r) = (*r) * (*this);
        return *r;
    }

    if (n.getMode() =="rationnel" )
    {
        Nombre* q = new Rationnel();
        (*q) = n ;
        (*q) = (*q) * (*this);
        return *q;
    }

    if (n.getMode() =="entier" )
    {
        Nombre* e = new Entier();
        e->setPartieReelle(n.getPartieReelle()*this->getPartieReelle());
        return *e;
    }
}

Nombre& Complexe::operator/(const Nombre& n)
{
    if (n.getMode()=="complexe")
    {
        Nombre* c = new Complexe();
        double* denominateur= new double(0);
        *denominateur = ((n.getPartieReelle()*n.getPartieReelle()) + (n.getPartieImaginaire()*n.getPartieImaginaire())); // denominateur de notre nouveau complexe

        c->setPartieReelle((this->m_partieReelle*n.getPartieReelle())+(this->m_partieImaginaire*n.getPartieImaginaire()));
        c->setPartieImaginaire((this->m_partieImaginaire*n.getPartieReelle())-(this->m_partieReelle*n.getPartieImaginaire()));

        c->setPartieReelle((c->getPartieReelle()) / (*denominateur));
        c->setPartieImaginaire((c->getPartieImaginaire()) / (*denominateur));
        delete denominateur ;
        return *c;
    }

    if(n.getMode() =="reel")
    {
        Nombre* c = new Complexe();
        Nombre* r = new Reel(1/n.getPartieReelle());
        //(*r) = n;
        (*c) = (*this);
        //double temp = n.getPartieReelle();
        //temp = (double)(1/(temp));
        //r->setPartieReelle(temp);
        (*c) = (*c) * (*r);
        delete r;
        //delete temp;
        return *c;
    }

    if(n.getMode() =="rationnel")
    {
        Nombre* c = new Complexe();
        (*c) = (*this);
        Nombre* q = new Rationnel(n.getDenominateurReel(),n.getPartieReelle() );
        //q->setPartieReelle(n.getDenominateurReel());
        //q->setDenominateurReel(n.getPartieReelle());
        (*c) = (*c) * (*q);
        delete q;
        return *c;
    }

    if(n.getMode() =="entier")
    {
        Nombre* c = new Complexe();
        (*c) = (*this);
        Nombre* q = new Rationnel(1,n.getPartieReelle());
        (*c) = (*c) * (*q);
        delete q;
        return *c;
    }
}

Nombre& Reel::operator/(const Nombre& n) // on est en mode reel : ok!
{
    if (n.getMode() =="complexe")
    {
        Nombre* c = new Complexe(n.getPartieReelle(),-n.getPartieImaginaire());
        double* denominateur= new double(0);
        *denominateur = ((n.getPartieReelle()*n.getPartieReelle()) + (n.getPartieImaginaire()*n.getPartieImaginaire())); // denominateur de notre nouveau complexe
        (*c) = (*c) * (*this);
        (*c).setPartieReelle(c->getPartieReelle()/(*denominateur));
        (*c).setPartieImaginaire(c->getPartieImaginaire()/(*denominateur));
        delete denominateur ;

        return *c;
    }

    if(n.getMode()=="reel")
    {
        Nombre* r = new Reel(1/n.getPartieReelle());
        (*r) = (*r) * (*this);
        return *r;
    }

    if (n.getMode() == "rationnel")
    {
        Nombre* q = new Rationnel(n.getDenominateurReel(), n.getPartieReelle());
        Nombre* r = new Reel ();

        (*r) = (*q) * (*this);
        delete q ;
        return *r;
    }

    if(n.getMode() =="entier")
    {
        Nombre* q = new Rationnel(1, n.getPartieReelle());
        Nombre* r = new Reel();

        (*r) = (*q) * (*this);
        delete q;
        return *r;
    }
}

Nombre& Rationnel::operator/(const Nombre& n) // on est en mode rationnel
{	if (n.getMode() =="complexe")
    {
        Nombre* c = new Complexe(n.getPartieReelle(),-n.getPartieImaginaire());
        double* denominateur= new double(0);
        Nombre* temp = new Reel(m_partieReelle / m_denominateurReel);
        *denominateur = ((n.getPartieReelle()*n.getPartieReelle()) + (n.getPartieImaginaire()*n.getPartieImaginaire())); // denominateur de notre nouveau complexe
        (*c) = (*c) * (*temp);
        (*c).setPartieReelle(c->getPartieReelle()/(*denominateur));
        (*c).setPartieImaginaire(c->getPartieImaginaire()/(*denominateur));
        delete denominateur ;
        delete temp;

        return *c;
    }

    if(n.getMode()=="reel")
    {
        Nombre* r = new Reel(1/n.getPartieReelle());
        Nombre* q= new Rationnel(m_partieReelle, m_denominateurReel);
        (*r) = (*r) * (*q);
        delete q ;
        return *r;
    }

    if (n.getMode() == "rationnel")
    {
        Nombre* q = new Rationnel(n.getDenominateurReel(), n.getPartieReelle());
        (*q) = (*q) * (*this);
        return *q;
    }

    if(n.getMode() =="entier")
    {
        Nombre* q = new Rationnel (1, n.getPartieReelle());
        (*q) = (*q) * (*this);
        return *q;
    }

}

Nombre& Entier::operator/(const Nombre& n) // on est en mode entier
{
    if (n.getMode() =="complexe")
    {
        Nombre* c = new Complexe(n.getPartieReelle(),-n.getPartieImaginaire());
        double* denominateur= new double(0);
        *denominateur = ((n.getPartieReelle()*n.getPartieReelle()) + (n.getPartieImaginaire()*n.getPartieImaginaire())); // denominateur de notre nouveau complexe
        (*c) = (*c) * (*this);
        (*c).setPartieReelle(c->getPartieReelle()/(*denominateur));
        (*c).setPartieImaginaire(c->getPartieImaginaire()/(*denominateur));
        delete denominateur ;

        return *c;
    }

    if(n.getMode()=="reel")
    {
        Nombre* r = new Reel(1/n.getPartieReelle());
        (*r) = (*r) * (*this);
        return *r;
    }

    if (n.getMode() == "rationnel")
    {
        Nombre* q = new Rationnel(n.getDenominateurReel(), n.getPartieReelle());
        (*q) = (*q) * (*this);
        return *q;
    }

    if(n.getMode() =="entier")
    {
        Nombre* r = new Reel(m_partieReelle / n.getPartieReelle());
        return *r;
    }
}

Nombre& power ( const Nombre& n, const Nombre& e) // Ok !
{
    if (e.getMode() == "entier")
        {
            if (n.getMode()=="reel")
            {
                Nombre* r = new Reel();
                double p = pow(n.getPartieReelle(),e.getPartieReelle());
                r->setPartieReelle(p);
                return *r;
            }
            else if (n.getMode()=="rationnel")
            {
                Nombre* r = new Reel();
                double temp = (double)(n.getPartieReelle()/n.getDenominateurReel());
                r->setPartieReelle(pow(temp, e.getPartieReelle()));
                return *r;
            }
            else if (n.getMode()=="entier")
            {
                 Nombre* r = new Reel();
                 r->setPartieReelle(pow(n.getPartieReelle(), e.getPartieReelle()));
                 return *r;
            }
            else
                throw( "operation non valide" ) ;

        }
        else
            throw( "operation non valide" ) ;// on n'autorise pas les puissances reelles
}

Nombre& modulo (const Nombre& e1, const Nombre& e2) // retourne le reste de la division euclidienne
{
    if ((e1.getMode() =="entier") && (e2.getMode() == "entier"))
    {
        Nombre* e = new Reel() ;
        e->setPartieReelle((int)(e1.getPartieReelle())%((int)(e2.getPartieReelle())));
        return *e;
    }
    else
        throw ("erreur: on ne peut effectuer d'operation sur les nombres entres en argument") ;
}

Nombre& inversionSigne(const Nombre& n) //
{
    if (n.getMode()=="complexe")
    {
        Nombre* c = new Complexe(-(n.getPartieReelle()),-(n.getPartieImaginaire()));
        return *c;
    }
    else if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(-(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        Nombre* q = new Rationnel(-(n.getPartieReelle()),(n.getDenominateurReel()));
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(-(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& tangenteHyperbolique(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(tanh(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(tanh(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(tanh(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& cosinus(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(cos(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(cos(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(cos(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& sinus(const Nombre& n) // par defaut les angles sont en radian
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(sin(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(sin(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(sin(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& cosinusHyperbolique(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(cosh(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(cosh(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(cosh(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& sinusHyperbolique(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(sinh(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(sinh(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(sinh(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& tangente(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(tan(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(tan(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(tan(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& logarithme(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(log(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(log(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(log(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& inverse(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel((double)1/n.getPartieReelle());
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        Nombre* q = new Rationnel(n.getDenominateurReel(),n.getPartieReelle());
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Rationnel(1,n.getPartieReelle());
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& racineCarree(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(sqrt(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(sqrt(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Reel(sqrt(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& fonctionCarree(const Nombre& n)
{
    if (n.getMode()=="complexe")
    {
        Nombre* r = new Complexe();
        (*r) = n;
        (*r) = (*r) * (*r);
        //(*r) = dynamic_cast<Nombre&> n * n;
        return *r;
    }

    else if (n.getMode()=="reel")
    {
        Nombre* r = new Reel();
        //(*r) = n * n;
        (*r) = n;
        (*r) = (*r) * (*r);
        return *r;
    }

    else if (n.getMode()=="rationnel")
    {
        Nombre* r = new Rationnel();
        //(*r) = n * n;
        (*r) = n;
        (*r) = (*r) * (*r);
        return *r;

    }
    else if (n.getMode()=="entier")
    {
        Nombre* r = new Entier();
        //(*r) = n * n;
        (*r) = n;
        (*r) = (*r) * (*r);
        return *r;
    }
    else
        throw("operation non valide");
}

Nombre& fonctionCube(const Nombre& n)
{
    if (n.getMode()=="complexe")
    {
        Nombre* r = new Complexe();
        (*r) = n;
        (*r) = (*r) * (*r) * (*r);
        //(*r) = dynamic_cast<Nombre&> n * n;
        return *r;
    }

    else if (n.getMode()=="reel")
    {
        Nombre* r = new Reel();
        //(*r) = n * n;
        (*r) = n;
        (*r) = (*r) * (*r) * (*r);
        return *r;
    }

    else if (n.getMode()=="rationnel")
    {
        Nombre* r = new Rationnel();
        //(*r) = n * n;
        (*r) = n;
        (*r) = (*r) * (*r) * (*r);
        return *r;

    }
    else if (n.getMode()=="entier")
    {
        Nombre* r = new Entier();
        //(*r) = n * n;
        (*r) = n;
        (*r) = (*r) * (*r) * (*r);
        return *r;
    }
    else
        throw("operation non valide");
}

Nombre& logarithme10(const Nombre& n)
{
    if (n.getMode()=="reel")
    {
        Nombre* r = new Reel(log10(n.getPartieReelle()));
        return *r;
    }
    else if (n.getMode()=="rationnel")
    {
        double* temp = new double(n.getPartieReelle()/n.getDenominateurReel());
        Nombre* q = new Reel(log10(*temp));
        delete temp ;
        return *q;
    }
    else if (n.getMode()=="entier")
    {
        Nombre* e = new Entier(log10(n.getPartieReelle()));
        return *e;
    }
    else
        throw("operation non valide");
}

Nombre& factoriel(const Nombre&/*entier*/ n)
{
    if (n.getMode()=="entier")
    {
        int fact(1);
        int i(0);
        for (int i = 1; i<n.getPartieReelle()+1;i++)
        {
            fact *= i;
        }
        Nombre* e = new Entier(fact);
        return *e;
    }
    else
        throw("operation non valide");
}

int pgcd (int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

void simplifier (Rationnel& r)
{
    int p(0);
    p = pgcd (r.getPartieReelle(), r.getDenominateurReel());
    r.setPartieReelle(r.getPartieReelle()/p);
    r.setDenominateurReel(r.getDenominateurReel()/p);
}

QString Operation::match_indice(int indice)
{
    switch(indice)
    {
        case 1: return "+";
        case 2: return "-";
        case 3: return "*";
        case 4: return "/";
        default: return "Inconnu";
    };

}

const Nombre& OperationBinaire::evaluer() const
{	Nombre* c= new Complexe(); // pointeur sur nombre qui sera initialis?par le constructeur sans argument

    if (this->choix ==1) // on a choisi l'addition
        {
            (*c)= ex1->evaluer();
            (*c)= (*c) + (ex2->evaluer());
        }

    if (this->choix ==2) // on a choisi la soustraction
        {
            (*c)= ex1->evaluer();
            (*c)= (*c) - (ex2->evaluer());
        }

    if (this->choix ==3) // on a choisi la multiplication
        {
            (*c)= ex1->evaluer();
            (*c)= (*c) * (ex2->evaluer());
        }

    if (this->choix ==4) // on a choisi la division
        {
            (*c)= ex1->evaluer();
            (*c)= (*c) / (ex2->evaluer());
        }
    if (this->choix ==5) // on a choisi pow
        {
            /*Nombre* r= new Reel();
            (*r)= ex1->evaluer();
            (*r)= power(*c, (ex2->evaluer()));*/
             Nombre* e = new Reel();

             (*e)= (power(ex1->evaluer(), ex2->evaluer()));
             return *e;
        }
    if (this->choix ==6) // on a choisi mod
        {
            Nombre* e = new Entier();
            (*e) = (modulo(ex1->evaluer(), ex2->evaluer()));
            return *e;
        }

    return *c;
}

Expression* OperationBinaire::evaluer2() // à tester et à vérifier pour tous les cas
 {	if (this->ex1->getPropriete().contains("'")||this->ex2->getPropriete().contains("'")) // si les expressions sont de type constantes i.e si elles contiennent << ' >>
     {
         QString s1;
         QString s2;
         QRegExp rx("^'(.*)'$");

         //expression 1
         if( this->ex1->getPropriete().contains("'")) // tests sur la premiere expression de l'operation
         {
             rx.indexIn(this->ex1->getPropriete()); // ???
             s1=rx.cap(1);
         }
         else
         {
             s1=ex1->getPropriete();
         }

         //expression 2
         if (this->ex2->getPropriete().contains("'")) // tests sur la deuxiemee expression de l'operation
         {
             rx.indexIn(this->ex2->getPropriete());
             s2=rx.cap(1);
         }
         else
         {
             s2=ex2->getPropriete();
         }

         int indice=this->choix;
         QString s=this->match_indice(indice);

         return new Constant("'"+s1+" "+s2+" "+s+"'");
     }

     Nombre* c= new Complexe(); // pointeur sur nombre qui sera initialise par le constructeur sans argument

     if (this->choix ==1) // on a choisi l'addition
         {
         (*c)= ex1->evaluer();
         (*c)= (*c) + (ex2->evaluer());
         }
    // else throw ("operation non valide");

     if (this->choix ==2) // on a choisi la soustraction
         {
             (*c)= ex1->evaluer();
             (*c)= (*c) - (ex2->evaluer());
         }

     if (this->choix ==3) // on a choisi la multiplication
         {
             (*c)= ex1->evaluer();
             (*c)= (*c) * (ex2->evaluer());
         }

     if (this->choix ==4) // on a choisi la division
         {
             (*c)= ex1->evaluer();
             (*c)= (*c) / (ex2->evaluer());
         }
     if (this->choix ==5) // on a choisi pow
         {
             Nombre* r= new Reel();
             (*r)= ex1->evaluer();
             (*r)= power(*c, (ex2->evaluer()));
              Nombre* e =&(power(ex1->evaluer(), ex2->evaluer()));
              *c = *e ;


             // return e;
         }
     if (this->choix ==6) // on a choisi mod
         {
             Nombre* e = new Entier();
             (*e) = (modulo(ex1->evaluer(), ex2->evaluer()));
             return e;
         }

     if (c->match_affiche()==1) // ???
     {
        return new Reel(c->getPartieReelle());
     }
    else
        return c;
 }


const Nombre& OperationUnaire::evaluer() const
{
    if (this->choix ==7) // on a choisi inversion signe
            {
                //Nombre* e = new Complexe();// ???
                Nombre* e = &(inversionSigne(ex1->evaluer())); // on initialise le pointeur avec l'adresse d'un nombre
                return *e;
            }
         else if (this->choix ==8) // on a choisi sinus
            {
                // e = new Reel();// ???
                Nombre* e = &(sinus(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==9) // on a choisi cosinus
            {
                Nombre* e = &(cosinus(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==10) // on a choisi tangente
            {
                Nombre* e =&(tangente(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==11) // on a choisi sinusHyperbolique
            {
                Nombre* e = &(sinusHyperbolique(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==12) // on a choisi cosinusHyperbolique
            {
                Nombre* e = &(cosinusHyperbolique(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==13) // on a choisi tangenteHyperbolique
            {
                Nombre* e = &(tangenteHyperbolique(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==14) // on a choisi logarithme népérien (log)
            {
                Nombre* e = &(logarithme(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==15) // on a choisi logarithme décimal (log à base 10)
            {
                Nombre* e = &(logarithme10(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==16) // on a choisi inverse
            {
                Nombre* e = &(inverse(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==17) // on a choisi racineCarree
            {
                Nombre* e = &(racineCarree(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==18) // on a choisi fonctionCarree
            {
                Nombre* e = &(fonctionCarree(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==19) // on a choisi fonctionCube
            {
                Nombre* e = &(fonctionCube(ex1->evaluer()));
                return *e;
            }
         else if (this->choix ==20) // on a choisi factoriel
            {
                Nombre* e = &(factoriel(ex1->evaluer()));
                return *e;
            }
         else throw("operation non geree" ) ;
}

/*void OperationUnaire::afficher(std::ostream& f) const
{
    f<< "Operation Unaire " << std::endl ;
}*/

/*void OperationBinaire::afficher(std::ostream& f) const
{
    f<< "Operation Binaire " << std::endl ;

}*/

const Nombre& Constant::evaluer() const // a revoir
{
    Nombre* c = new Complexe();
    return *c;
}
