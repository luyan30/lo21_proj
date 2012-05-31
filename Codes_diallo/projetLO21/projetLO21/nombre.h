#include <string>
#include <iostream>
class Nombre
{
	
	protected: // pour que les méthodes des classes filles puissent y accéder

		//attributs
		float m_partieReelle;
		float m_partieImaginaire;
		int m_denominateurReel;
		int m_denominateurImaginaire;
		std::string m_mode;
		

	public:

	//constructeurs
	Nombre(float partieReelle=0, int denominateurReel=0, float partieImaginaire=1, int denominateurImaginaire=0, std::string mode="complexe");
	/*Nombre();*/


	//méthodes classiques
		//bool pReelIntPas();
		//bool pImagIntNul();
		//bool denominateurLPas();
		void afficher() ; // doit etre une methode virtuelle pure pour rendre la classe abstraite
		//void setMode(std::string mode) ;
	
	//accesseurs
		float getPartieReelle() const { return m_partieReelle;} 
		float getPartieImaginaire() const { return m_partieImaginaire; }
		int getDenominateurReel() const { return m_denominateurReel; }
		int getDenominateurImaginaire() const { return m_denominateurImaginaire;}
		std::string getMode() const { return m_mode; }
	
	//destructeurs
	
	//opérateurs : a t on besoin de surcharger les opérateurs ? peut etre l'operateur d'affichage vu qu'on va afficher les résultats des calculs ? 
};
/*
class Complexe: public Nombre
{
	public:
	//constructeurs
	//Complexe(
	//méthodes classiques
	
	//accesseurs
	const Complexe& Get_complexe() const;
	
	//destructeurs
	
};    

class Rationnel: public Nombre
{
	public:
	//constructeurs
	
	//méthodes classiques
	
	//accesseurs
	const Complexe& Get_complexe() const;  
	
	//destructeurs                   
	
};  

class Reel: public Nombre
{
	public:
	//constructeurs
	
	//méthodes classiques
	
	//accesseurs
	const Reel& Get_reel() const;
	
	//destructeurs
	
};      

class Entier: public Nombre     
{
	public:
	//constructeurs
	
	//méthodes classiques
	
	//accesseurs
	const Entier& Get_entier() const;
	
	//destructeurs
	
};    

class Degre: public Nombre
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
