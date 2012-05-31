#include "nombre.h"



/*Nombre::Nombre()
{
	std::cout << "nombre construit! avec premier constructeur" << std::endl;
}*/

Nombre::Nombre(float partieReelle, int denominateurReel, float partieImaginaire, int denominateurImaginaire, std::string mode):
m_partieReelle(partieReelle), m_partieImaginaire(partieImaginaire),m_denominateurReel(denominateurReel),
m_denominateurImaginaire(denominateurImaginaire),m_mode(mode)
{
	std::cout << "nombre construit! avec deuxieme constructeur" << std::endl;

}

void Nombre::afficher()
{
	std::cout << "partie reelle : "; // sans le denominateur
	std::cout << this->m_partieReelle<< std::endl;
	std::cout << "partie imaginaire : ";
	std::cout << this->m_partieImaginaire<< std::endl;
}