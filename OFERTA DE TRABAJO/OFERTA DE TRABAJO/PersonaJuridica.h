#ifndef PERSONAJURIDICA_H
#define PERSONAJURIDICA_H

#include <iostream>
#include <string>
#include "Usuario.h"
#include "Imprimir.h"

using namespace std;

class PersonaJuridica : public Usuario, public Imprimir
{
protected:
	string rucPersonaJuridica;
	string nombrePersonaJuridica;
	int telefonoPersonaJuridica;
	string direccionPersonaJuridica;
public:
	PersonaJuridica();
	PersonaJuridica(const string&, const string&, const string&, const string&, int, const string&);
	PersonaJuridica(const string&);
	~PersonaJuridica();
	void setRucPersonaJuridica(const string&);
	void setNombrePersonaJuridica(const string&);
	void setTelefonoPersonaJuridica(int);
	void setDireccionPersonaJuridica(const string&);
	
	string getRucPersonaJuridica();
	string getNombrePersonaJuridica();
	string getDireccionPersonaJuridica();
	int getTelefonoPersonaJuridica();
	
	void mostrar();
	void mostrar(int);
	void mostrar(string);
};

#endif // PERSONAJURIDICA_H