#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "nombre.h"

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
#endif // EXPRESSION_H
