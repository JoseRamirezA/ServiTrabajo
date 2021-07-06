#ifndef ARREGLOPERSONAS_H
#define ARREGLOPERSONAS_H

#include <iostream>
#include <string>
#include "Persona.h"
#include "Imprimir.h"

using namespace std;

class ArregloPersonas : public Imprimir
{
protected:
	Persona** arregloPersonas;
	int cantPersonas;
public:
	ArregloPersonas();
	~ArregloPersonas();
	void agregarPersonas(Persona*);
	void eliminarPersonas(int);
	Persona* getArregloPersonas(int);
	void mostrar();
	int tamanio();
	void mostrar(int);
	void mostrar(string);
};

#endif // ARREGLOPERSONAS_H