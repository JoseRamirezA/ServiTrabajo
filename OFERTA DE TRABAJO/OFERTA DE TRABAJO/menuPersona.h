#pragma once
#include <string>
#include "Usuario.h"
#include "Imprimir.h"
#include "Persona.h"
#include "PersonaJuridica.h"
#include "OfertaLaboral.h"
#include "ArregloPersonas.h"
#include "ArregloJuridicas.h"

using namespace std;

void menuPersona(int);
void registroPersona();
void inicioSesionPersona();
int buscarPersona(string&, string&);
void opcionesPersona();
void modificarDatosPersona();