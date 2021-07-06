#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include "Usuario.h"
#include "Imprimir.h"

using namespace std;

class Persona : public Usuario , public Imprimir
{
protected:
	string nombre;
	string apellido;
	string dni;
	int fechaNacimiento;
	int telefono;
	string nivelEstudio;
	string profesion;
	string ultimoTrabajo;
public:
	Persona();
	Persona(const string&, const string&, const string&, const string&, const string&, int, int, const string&, const string&, const string&);
	~Persona();

	void setNombre(const string&);
	void setApellido(const string&);
	void setDni(const string&);
	void setFechaNacimiento(int);
	void setTelefono(int);
	void setNivelEstudio(const string&);
	void setProfesion(const string&);
	void setUltimoTrabajo(const string&);

	string getNombre();
	string getApellido();
	string getDni();
	int getFechaNacimiento();
	int getTelefono();
	string getNivelEstudio();
	string getProfesion();
	string getUltimoTrabajo();

	void mostrar();
	void mostrar(string);
};

#endif // PERSONA_H