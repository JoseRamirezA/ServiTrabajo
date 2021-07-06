#include "OfertaLaboral.h"

OfertaLaboral::OfertaLaboral(){}

OfertaLaboral::OfertaLaboral(const string& tituloOferta, const string& descripcionOferta, int salarioOferta, const PersonaJuridica& personaJuridica) : personaJuridicaOferta(personaJuridica)
{
	this->tituloOferta = tituloOferta;
	this->descripcionOferta = descripcionOferta;
	this->salarioOferta = salarioOferta;
}

OfertaLaboral::~OfertaLaboral(){}

void OfertaLaboral::setTituloOferta(const string& tituloOferta)
{
	this->tituloOferta = tituloOferta;
}
void OfertaLaboral::setDescripcionOferta(const string& descripcionOferta)
{
	this->descripcionOferta = descripcionOferta;
}
void OfertaLaboral::setSalarioOferta(int salarioOferta)
{
	this->salarioOferta = salarioOferta;
}

string OfertaLaboral::getTituloOferta()
{
	return tituloOferta;
}
string OfertaLaboral::getDescripcionOferta()
{
	return descripcionOferta;
}
int OfertaLaboral::getSalarioOferta()
{
	return salarioOferta;
}
string OfertaLaboral::getRucOferta()
{
	return personaJuridicaOferta.getRucPersonaJuridica();
}

void OfertaLaboral::mostrar()
{
	cout << "\t" << tituloOferta << endl;
	cout << "\t" << descripcionOferta << endl;
	cout << "\tSalario: S/." << salarioOferta <<".00\n" << endl;
}

void OfertaLaboral::mostrar(string a)
{
	cout << "\tTitulo: " << tituloOferta << endl;
}