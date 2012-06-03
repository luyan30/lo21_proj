#include "expression.h"



//OPERATIONS
const Nombre& Addition::evaluer() const 
{
	return ex1->evaluer() + ex2->evaluer();
}

const Nombre& Soustraction::evaluer() const
{
	return ex1->evaluer() - ex2->evaluer();
}

