#include "nombre.h"
#include <iostream>
#include <math.h>
#include "expression.h"

using namespace std;
//pour initialiser un float, mettre un point "."
int main ()
{
	float b(5);
	float c(6);
	//c=(float)b/10;
	Complexe n1;
	Complexe n2;
	n1.afficher();
	cout << endl;
	n2.afficher();
	cout << endl;
	(n1+n2).afficher();
	cout << endl ;

	/*float a(10.10);
	a/=0.5;
	/*a = a / 5;
	int b(5);
	a = b + a;
	cout << a << endl; */

	return 0;
}