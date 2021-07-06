#pragma once
#include <fstream>
#include <string>
#include "Usuario.h"
#include "Imprimir.h"
#include "Persona.h"
#include "PersonaJuridica.h"
#include "OfertaLaboral.h"
#include "ArregloPersonas.h"
#include "ArregloJuridicas.h"
#include "ArregloOfertas.h"

using namespace std;

void bienvenida();
void despedida();
void proceso();
void menu(int&);
void escribirP();
void escribirJ();
void escribirO();

void leer();

//OPCIONES DE PERSONA
void menuPersona(int);
void registroPersona();
void inicioSesionPersona();
int buscarPersona(string&, string&);
void opcionesPersona();
void modificarDatosPersona();

//OPCIONES DE EMPRESA
void menuEmpresa(int);
void registroEmpresa();
void inicioSesionEmpresa();
int buscarEmpresa(string&, string&);
void opcionesEmpresa();
void modificarDatosEmpresa();
void registroOferta();
void verOfertas();

//OPCIONES DE ADMINISTRADOR
void menuAdministrador(int);
void inicioSesionAdministrador();
void opcionesAdministrador();