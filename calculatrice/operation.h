#ifndef OPERATION_H
#define OPERATION_H
#include "nombre.h"
class Operation:public Expression{
Expression *ex1;
Expression *ex2;
int choix;
public:
Operation(Expression *x1,Expression *x2,int indice):ex1(x1),ex2(x2),choix(indice){}
//Expression* evaluer() const;
};
#endif // OPERATION_H
