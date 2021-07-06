#include "PersonaJuridica.h"

PersonaJuridica::PersonaJuridica(){}

PersonaJuridica::PersonaJuridica(const string& username, const string& password, const string& rucPersonaJuridica, const string& nombrePersonaJuridica, int telefonoPersonaJuridica, const string& direccionPersonaJuridica) : Usuario(username, password)
{
	this->rucPersonaJuridica = rucPersonaJuridica;
	this->nombrePersonaJuridica = nombrePersonaJuridica;
	this->telefonoPersonaJuridica = telefonoPersonaJuridica;
	this->direccionPersonaJuridica = direccionPersonaJuridica;
}

PersonaJuridica::PersonaJuridica(const string& rucPersonaJuridica) {
	this->rucPersonaJuridica = rucPersonaJuridica;
}

PersonaJuridica::~PersonaJuridica() {}

void PersonaJuridica::setRucPersonaJuridica(const string& rucPersonaJuridica)
{
	this->rucPersonaJuridica = rucPersonaJuridica;
}

void PersonaJuridica::setNombrePersonaJuridica(const string& nombrePersonaJuridica)
{
	this->nombrePersonaJuridica = nombrePersonaJuridica;
}

void PersonaJuridica::setTelefonoPersonaJuridica(int telefonoPersonaJuridica)
{
	this->telefonoPersonaJuridica = telefonoPersonaJuridica;
}

void PersonaJuridica::setDireccionPersonaJuridica(const string& direccionPersonaJuridica)
{
	this->direccionPersonaJuridica = direccionPersonaJuridica;
}

string PersonaJuridica::getRucPersonaJuridica()
{
	return rucPersonaJuridica;
}
string PersonaJuridica::getNombrePersonaJuridica()
{
	return nombrePersonaJuridica;
}
string PersonaJuridica::getDireccionPersonaJuridica()
{
	return direccionPersonaJuridica;
}
int PersonaJuridica::getTelefonoPersonaJuridica()
{
	return telefonoPersonaJuridica;
}

void PersonaJuridica::mostrar()
{
	cout << "\tNombres Empresa: \t" << nombrePersonaJuridica << endl;
	cout << "\n\tRUC Empresa: \t\t" << rucPersonaJuridica << endl;
	cout << "\n\tTelefono Empresa: \t" << telefonoPersonaJuridica << endl;
	cout << "\n\tDireccion Empresa: \t" << direccionPersonaJuridica << endl;
	cout << "\n\n\n\n\n";
}

void PersonaJuridica::mostrar(int a)
{
	cout << "El RUC de la empresa es: " <<rucPersonaJuridica<< endl;
}

void PersonaJuridica::mostrar(string a)
{
	cout << "\tNombres: " << nombrePersonaJuridica << endl;
}