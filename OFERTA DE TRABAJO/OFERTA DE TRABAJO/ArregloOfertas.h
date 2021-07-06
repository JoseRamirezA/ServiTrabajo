#ifndef ARREGLOOFERTAS_H
#define ARREGLOOFERTAS_H

#include <iostream>
#include <string>
#include "OfertaLaboral.h"
#include "Imprimir.h"

using namespace std;

class ArregloOfertas : public Imprimir
{
protected:
	OfertaLaboral** arregloOfertas;
	int cantOfertas;
public:
	ArregloOfertas();
	~ArregloOfertas();
	void agregarOfertas(OfertaLaboral*);
	void eliminarOfertas(int);
	OfertaLaboral* getArregloOfertas(int);
	void mostrar();
	int tamanio();
	void mostrar(int);
	void mostrar(string);
};

#endif // ARREGLOOFERTAS_H