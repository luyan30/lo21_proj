#include <string>
#include <iostream>
#include <math.h> // pour faciliter les calculs et permettre l'utilisation de fonctions mathématiques compliquées

class Nombre ; // si on l'enleve, la méthode evaluer() dans Nombre va présenter un problème de covariance. Pourquoi ?
class Expression 
{
private:

public:

	// CONSTRUCTEURS

	// METHODES CLASSIQUES
	virtual const Nombre& evaluer() const = 0 ; // ?
	virtual void afficher(std::ostream& f=std::cout) const = 0  ;

	// ACCESSEURS

	// DESTRUCTEURS
	virtual ~Expression(){} // ?
}; 

class Nombre: public Expression
{
	
	protected: // pour que les méthodes des classes filles puissent y accéder

	// ATTRIBUTS 
		double m_partieReelle;
		double m_partieImaginaire;
		int m_denominateurReel;
		int m_denominateurImaginaire;
		std::string m_mode;
		

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
	
	// METHODES CLASSIQUES
		//bool pReelIntPas();
		//bool pImagIntNul();
		//bool denominateurLPas();
	
		//optionnel virtual void afficher(std::ostream& f=std::cout) const = 0  ; // doit etre une methode virtuelle pure pour rendre la classe abstraite
		//*optionnel virtual const Nombre& evaluer() const = 0; /*{ return *this; }*/  // méthode virtuelle de Expression . On a 2 const car passage par référence + méthode const
	
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
		
};

class Complexe: public Nombre
{
	public:
		// CONSTRUCTEURS
	//Nombre(double partieReelle=0, int denominateurReel=0, double partieImaginaire=1, int denominateurImaginaire=0, std::string mode="complexe"); // construction de n'importe quel nombre ?

	/*construction d'un complexe*/ 
	Complexe(double partieReelle, double partieImaginaire);
	Complexe();
	

	// METHODES REDEFINIES
		void afficher(std::ostream& f=std::cout) const  ; 
		const Nombre& evaluer() const ;
	
	//ACCESSEURS
		
	// DESTRUCTEURS
	
	// OPERATEURS : a t on besoin de surcharger les opérateurs ? peut etre l'operateur d'affichage vu qu'on va afficher les résultats des calculs ? 
	
	
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
	
	// ACCESSEURS
	  
	
	// DESTRUCTEURS                  
	
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

	// ACCESSEURS
	
	
	// DESTRUCTEURS
	
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





class Addition : public Expression
{
private: 
	Expression* ex1;
	Expression* ex2;
	
public:
	Addition(Expression* x1, Expression* x2): ex1(x1), ex2(x2) {}
	const Nombre& evaluer() const ; // l'evaluation d'une operation retourne un nombre, si ca marche
};

class Soustraction : public Expression
{
private: 
	Expression* ex1;
	Expression* ex2;
	
public:
	Soustraction(Expression* x1, Expression* x2): ex1(x1), ex2(x2) {}
	const Nombre& evaluer() const ; // l'evaluation d'une operation retourne un nombre, si ca marche
};
	
//OPERATEURS : a t on besoin de surcharger les opérateurs ? peut etre l'operateur d'affichage vu qu'on va afficher les résultats des calculs ? 
Nombre& operator+(Nombre const& n1, Nombre const& n2); // 'Nombre const&' equivalent à 'const Nombre&'
Nombre& operator-(Nombre const& n1, Nombre const& n2);
//Nombre& operator*(Nombre const& n1, Nombre const& c2);
//Nombre& operator/(Nombre const& n1, Nombre const& c2);

/*Complexe operator+(Complexe const& c1, Complexe const& c2);
Complexe operator-(Complexe const& c1, Complexe const& c2);
Complexe operator*(Complexe const& c1, Complexe const& c2);
Complexe operator/(Complexe const& c1, Complexe const& c2);

opérateurs pour reels
Complexe operator+(Complexe const& c1, Complexe const& c2);
Complexe operator-(Complexe const& c1, Complexe const& c2);
Complexe operator*(Complexe const& c1, Complexe const& c2);
Complexe operator/(Complexe const& c1, Complexe const& c2);

operateurs pour rationnels
Complexe operator+(Complexe const& c1, Complexe const& c2);
Complexe operator-(Complexe const& c1, Complexe const& c2);
Complexe operator*(Complexe const& c1, Complexe const& c2);
Complexe operator/(Complexe const& c1, Complexe const& c2);

operateurs pour entiers
Complexe operator+(Complexe const& c1, Complexe const& c2);
Complexe operator-(Complexe const& c1, Complexe const& c2);
Complexe operator*(Complexe const& c1, Complexe const& c2);
Complexe operator/(Complexe const& c1, Complexe const& c2);*/