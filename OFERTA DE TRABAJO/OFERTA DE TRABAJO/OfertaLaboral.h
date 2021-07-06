#ifndef OFERTALABORAL_H
#define OFERTALABORAL_H

#include <iostream>
#include <string>
#include "PersonaJuridica.h"
#include "Imprimir.h"

using namespace std;

class OfertaLaboral : public Imprimir
{
protected:
	string tituloOferta;
	string descripcionOferta;
	int salarioOferta;
	PersonaJuridica personaJuridicaOferta;
public:
	OfertaLaboral();
	OfertaLaboral(const string&, const string&, int, const PersonaJuridica&);
	~OfertaLaboral();

	void setTituloOferta(const string&);
	void setDescripcionOferta(const string&);
	void setSalarioOferta(int);

	string getTituloOferta();
	string getDescripcionOferta();
	int getSalarioOferta();
	string getRucOferta();

	void mostrar();
	void mostrar(string);

};

#endif // OFERTALABORAL_H