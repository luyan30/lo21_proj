#include "expression.h"

/*Nombre::Nombre()
{
	std::cout << "nombre construit! avec premier constructeur" << std::endl;
}*/

/*Nombre::Nombre(float partieReelle, int denominateurReel, float partieImaginaire, int denominateurImaginaire, std::string mode):
m_partieReelle(partieReelle), m_partieImaginaire(partieImaginaire),m_denominateurReel(denominateurReel),
m_denominateurImaginaire(denominateurImaginaire),m_mode(mode)
{
	if(mode=="complexe") 
		std::cout << "on est en mode complexe " << std::endl;

	if(mode=="reel") 
		std::cout << "on est en mode reel " << std::endl;

	if(mode=="rationnel") 
		std::cout << "on est en mode rationnel " << std::endl;

	if(mode=="entier") 
		std::cout << "on est en mode entier " << std::endl;
	
	std::cout << "entrer un mode valide" << std::endl;

}*/

/*construction d'un complexe*/ 

Nombre::Nombre(float partieReelle, float partieImaginaire)
{
	m_mode="complexe" ; //on entre en mode complexe
	m_partieReelle = partieReelle ;
	m_partieImaginaire = partieImaginaire;
}

/*construction d'un réel*/ 
Nombre::Nombre(float valeur)
{
	m_mode = "reel";
	m_partieReelle =valeur;
	m_partieImaginaire=0;
}

/*construction d'un rationnel*/
Nombre::Nombre(int numerateur, int denominateur)
{
	m_mode = "rationnel";
	m_partieReelle =(float)numerateur;
	if(denominateur==0) {m_partieImaginaire=1; }
	else m_partieImaginaire=(float)denominateur;	
	
}

/*construction d'un entier*/
Nombre::Nombre(int valeur)
{
	m_mode = "entier";
	m_partieReelle =(int)valeur;
	m_partieImaginaire=0;
}

/*construction d'un nombre par defaut*/
Nombre::Nombre():m_partieReelle(0), m_partieImaginaire(0), m_denominateurReel(1), m_denominateurImaginaire(1),m_mode("complexe")
{
}


Complexe::Complexe(float partieReelle, float partieImaginaire):Nombre(partieReelle, partieImaginaire)
{
}

Reel::Reel(float valeur): Nombre(valeur)
{
}

Rationnel::Rationnel(int numerateur, int denominateur): Nombre(numerateur, denominateur)
{
}

Entier::Entier(int valeur):Nombre(valeur) 
{
}

// OPERATEURS en fonction du MODE
Nombre& operator+(Nombre const& n1, Nombre const& n2)
{
	//if ((n1.getMode()=="complexe")&&(n2.getMode()=="complexe"))
	//{
		Complexe copie(0,0) ;
		copie.setPartieImaginaire(n1.getPartieImaginaire() + n2.getPartieImaginaire());
		copie.setPartieReelle(n1.getPartieReelle() + n2.getPartieReelle());
		return copie ; // pas besoin de mettre & ou * car reference se comporte comme une variable normale
	//}
}

Nombre& operator-(Nombre const& n1, Nombre const& n2)
{
	//if ((n1.getMode()=="complexe")&&(n2.getMode()=="complexe"))
	//{
		Complexe copie(0,0) ;
		copie.setPartieImaginaire(n1.getPartieImaginaire() - n2.getPartieImaginaire());
		copie.setPartieReelle(n1.getPartieReelle() - n2.getPartieReelle());
		return copie ;
	//}
}
/*
Nombre operator*(Nombre const& n1, Nombre const& n2)
{
	Nombre copie(0,0) ;
	copie.setPartieImaginaire((n1.getPartieImaginaire()*n2.getPartieReelle()) + (n2.getPartieImaginaire()*n1.getPartieReelle()));
	copie.setPartieReelle((n1.getPartieReelle()*n2.getPartieReelle()) - (n2.getPartieImaginaire()*n1.getPartieImaginaire()));
	return copie ;
}
Nombre operator/(Nombre const& n1, Nombre const& n2)
{
	Nombre copie(0,0);
	float A(0);
	A = n2.getPartieReelle();
}

Nombre& Nombre::evaluer() { return *this; } ; // méthode virtuelle de Expression */

// Méthodes la variable Complexe
void Complexe::afficher(std::ostream& f) const	/*affichage d'un complexe*/
{
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

/*Complexe operator+(Complexe const& c1, Complexe const& c2)
{
	Complexe copie(0,0) ;
	copie.setPartieImaginaire(n1.getPartieImaginaire() + n2.getPartieImaginaire());
	copie.setPartieReelle(n1.getPartieReelle() + n2.getPartieReelle());
	return copie ;
}

Complexe operator-(Nombre const& n1, Nombre const& n2)
{
	Complexe copie(0,0) ;
	copie.setPartieImaginaire(n1.getPartieImaginaire() - n2.getPartieImaginaire());
	copie.setPartieReelle(n1.getPartieReelle() - n2.getPartieReelle());
	return copie ;
}*/