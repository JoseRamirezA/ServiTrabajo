#ifndef ARREGLOJURIDICAS_H
#define ARREGLOJURIDICAS_H

#include <iostream>
#include <string>
#include "PersonaJuridica.h"
#include "Imprimir.h"

using namespace std;

class ArregloJuridicas : public Imprimir
{
protected:
	PersonaJuridica** arregloJuridicas;
	int cantJuridicas;
public:
	ArregloJuridicas();
	~ArregloJuridicas();
	void agregarJuridicas(PersonaJuridica*);
	void eliminarJuridicas(int);
	PersonaJuridica* getArregloJuridicas(int);
	void mostrar();
	int tamanio();
	void mostrar(int);
	void mostrar(string);
};

#endif // ARREGLOJURIDICAS_H