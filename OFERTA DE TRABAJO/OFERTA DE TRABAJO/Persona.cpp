#include "Persona.h"

Persona::Persona() {}

Persona::Persona(const string& username, const string& password, const string& nombre, const string& apellido, const string& dni, int fechaNacimiento, int telefono, const string& nivelEstudio, const string& profesion, const string& ultimoTrabajo) : Usuario(username, password)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->dni = dni;
	this->fechaNacimiento = fechaNacimiento;
	this->telefono = telefono;
	this->nivelEstudio = nivelEstudio;
	this->profesion = profesion;
	this->ultimoTrabajo = ultimoTrabajo;
}

Persona::~Persona() {}

void Persona::setNombre(const string& nombre)
{
	this->nombre = nombre;
}

void Persona::setApellido(const string& apellido)
{
	this->apellido = apellido;
}

void Persona::setDni(const string& dni)
{
	this->dni = dni;
}

void Persona::setFechaNacimiento(int fechaNacimiento)
{
	this->fechaNacimiento = fechaNacimiento;
}

void Persona::setTelefono(int telefono)
{
	this->telefono = telefono;
}

void Persona::setNivelEstudio(const string& nivelEstudio)
{
	this->nivelEstudio = nivelEstudio;
}

void Persona::setProfesion(const string& profesion)
{
	this->profesion = profesion;
}

void Persona::setUltimoTrabajo(const string& ultimoTrabajo)
{
	this->ultimoTrabajo = ultimoTrabajo;
}


string Persona::getNombre()
{
	return nombre;
}

string Persona::getApellido()
{
	return apellido;
}

string Persona::getDni()
{
	return dni;
}

int Persona::getFechaNacimiento()
{
	return fechaNacimiento;
}

int Persona::getTelefono()
{
	return telefono;
}

string Persona::getNivelEstudio()
{
	return nivelEstudio;
}

string Persona::getProfesion()
{
	return profesion;
}

string Persona::getUltimoTrabajo()
{
	return ultimoTrabajo;
}

void Persona::mostrar()
{
	cout << "\tNombres: \t\t" << nombre << endl;
	cout << "\n\tApellidos: \t\t" << apellido << endl;
	cout << "\n\tDNI: \t\t\t" << dni << endl;
	cout << "\n\tFecha de Nacimiento: \t" << (fechaNacimiento / 1000000) << " / " << ((fechaNacimiento % 1000000) / 10000) << " / " << (fechaNacimiento % 10000) << endl;
	cout << "\n\tTelefono: \t\t" << telefono << endl;
	cout << "\n\tNivel de Estudios: \t" << nivelEstudio << endl;
	cout << "\n\tProfesion: \t\t" << profesion << endl;
	cout << "\n\tUltimo Trabajo: \t" << ultimoTrabajo << endl;
	cout << "\n\n\n\n\n";
}

void Persona::mostrar(string a)
{
	cout << "\tNombres: " << nombre << endl;
}