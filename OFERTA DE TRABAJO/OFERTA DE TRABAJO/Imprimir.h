#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include <iostream>
#include <string>
using namespace std;

class Imprimir
{
public:
	virtual void mostrar()
	{
		cout << "Soy la funcion padre mostrar"<<endl;
	}
	~Imprimir(){}
};

#endif // IMPRIMIR_H