
#include <iostream>
#include <fstream>
#include <string>
#include "Usuario.h"
#include "Imprimir.h"
#include "Persona.h"
#include "PersonaJuridica.h"
#include "OfertaLaboral.h"
#include "menuGeneral.h"
#include "ArregloPersonas.h"
#include "ArregloJuridicas.h"
#include "ArregloOfertas.h"

using namespace std;
int main()
{
    leer();
    bienvenida();
    proceso();
    despedida();
    return 0;
}
