#include "menuPersona.h"

//PERSONA

string ussernamePersonaMenu, passwordPersonaMenu, nombrePersonaMenu, apellidoPersonaMenu, dniPersonaMenu, nivelEstudioPersonaMenu, profesionPersonaMenu, ultimoTrabajoPersonaMenu;
int fechaNacimientoPersonaMenu, telefonoPersonaMenu;

int verificar = 0, opcion = 0;

ArregloPersonas* P = new ArregloPersonas();
Persona* personaTemporal;

void menuPersona(int opcion)
{
	do {
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------      PERSONA       --------\n" << endl;
		cout << "\t1. Iniciar Sesion" << endl;
		cout << "\t2. Registro" << endl;
		cout << "\t3. Volver" << endl;
		cout << "\t4. Salir" << endl;
		cout << "\n\tIngrese la opcion deseada:";
		cin >> opcion;
		if (opcion < 1 || opcion>4)
		{
			system("cls");
			cout << "\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\tDEBE INGRESAR UNA OPCION VALIDA\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (opcion < 1 || opcion>4);


	switch (opcion)
	{
	case 1: inicioSesionPersona(); break;
	case 2:	registroPersona(); break;
	case 3: flag2 = false; break;
	case 4:	flag1 = false; flag2 = false; break;
	}
}

void registroPersona()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      PERSONA       --------\n" << endl;
	cout << "\t--------      REGISTRO      --------\n" << endl;
	cout << "\n";
	cout << "\tIngrese su Usuario: ";
	cin >> ussernamePersonaMenu;
	cout << "\tIngrese su Contraseña: ";
	cin >> passwordPersonaMenu;
	cout << "\tIngrese sus Nombres: ";
	cin >> nombrePersonaMenu;
	cout << "\tIngrese sus Apellidos: ";
	cin >> apellidoPersonaMenu;
	cout << "\tIngrese su DNI: ";
	cin >> dniPersonaMenu;
	cout << "\tIngrese su Fecha de Nacimiento (20051980): ";
	cin >> fechaNacimientoPersonaMenu;
	cout << "\tIngrese su telefono: ";
	cin >> telefonoPersonaMenu;
	cout << "\tIngrese su nivel de Estudio";
	cin >> nivelEstudioPersonaMenu;
	cout << "\tIngrese su Profesion: ";
	cin >> profesionPersonaMenu;
	cout << "\tIngrese su Ultimo puesto de trabajo: ";
	cin >> ultimoTrabajoPersonaMenu;
	system("cls");
	P->agregarPersonas(new Persona(ussernamePersonaMenu, passwordPersonaMenu, nombrePersonaMenu, apellidoPersonaMenu, dniPersonaMenu, fechaNacimientoPersonaMenu, telefonoPersonaMenu, nivelEstudioPersonaMenu, profesionPersonaMenu, ultimoTrabajoPersonaMenu));
	cout << "\n\n\tREGISTRADO CORRECTAMENTE!!!!!!!!";
	system("pause");
	system("cls");
}

void inicioSesionPersona()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      PERSONA       --------\n" << endl;
	cout << "\t--------   INICIO SESION    --------\n" << endl;
	cout << "\tIngrese su Usuario: ";
	cin >> ussernamePersonaMenu;
	cout << "\tIngrese su Contraseña: ";
	cin >> passwordPersonaMenu;
	verificar = buscarPersona(passwordPersonaMenu, passwordPersonaMenu);
	if (verificar >= 0)
	{
		system("cls");
		cout << "\tBIENVENIDO DE NUEVO" << endl;
		system("pause");
		system("cls");
		flag3 = true;
		while (flag3 == true)
		{
			opcionesPersona();
		}
	}
	else
	{
		cout << "Usuario o Contraseña Incorrecto" << endl;
	}
	system("pause");
	system("cls");
}

int buscarPersona(string& ussername, string& password)
{
	int a = P->tamanio();
	for (int i = 0; i < a; i++)
	{
		personaTemporal = P->getArregloPersonas(i);
		if (personaTemporal->getUsername() == ussernamePersonaMenu && personaTemporal->getPassword() == passwordPersonaMenu)
		{
			return i;
		}
	}
	return -1;
}

void opcionesPersona()
{
	do {
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------      PERSONA       --------\n" << endl;
		cout << "\n";
		cout << "\t1. Ver mis Datos: " << endl;
		cout << "\t2. Modificar mis datos: " << endl;
		cout << "\t3. Buscar Ofertas de Trabajo: " << endl;
		cout << "\t4. Eliminar mi cuenta" << endl;
		cout << "\t5. Salir de mi cuenta" << endl;
		cout << "\n\tIngrese la opcion deseada:";
		cin >> opcion;
		if (opcion < 1 || opcion>5)
		{
			system("cls");
			cout << "\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\tDEBE INGRESAR UNA OPCION VALIDA\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (opcion < 1 || opcion>5);


	switch (opcion)
	{
	case 1:
		P->mostrar(verificar);
		break;
	case 2:	modificarDatosPersona(); break;
	case 3: //proceso();break;
	case 4:
		P->eliminarPersonas(verificar);
		cout << "Cuenta eliminada correctamente" << endl;
		cout << "Ya no se encuentra en nuestro sistema" << endl;
		cout << "Debe volver a registrar para tener acceso" << endl;
		flag3 = false;
		system("pause");
		system("cls");
		break;
	case 5: flag3 = false; break;
	}
}

void modificarDatosPersona()
{
	cout << "\n\n\tPROCEDEREMOS A CAMBIAR SUS DATOS" << endl;
	personaTemporal = P->getArregloPersonas(verificar);
	cout << "\tIngrese sus Nombres: ";
	cin >> nombrePersonaMenu;
	cout << "\tIngrese sus Apellidos: ";
	cin >> apellidoPersonaMenu;
	cout << "\tIngrese su DNI: ";
	cin >> dniPersonaMenu;
	cout << "\tIngrese su Fecha de Nacimiento (20051980): ";
	cin >> fechaNacimientoPersonaMenu;
	cout << "\tIngrese su telefono: ";
	cin >> telefonoPersonaMenu;
	cout << "\tIngrese su nivel de Estudio: ";
	cin >> nivelEstudioPersonaMenu;
	cout << "\tIngrese su Profesion: ";
	cin >> profesionPersonaMenu;
	cout << "\tIngrese su Ultimo puesto de trabajo: ";
	cin >> ultimoTrabajoPersonaMenu;
	personaTemporal->setNombre(nombrePersonaMenu);
	personaTemporal->setApellido(apellidoPersonaMenu);
	personaTemporal->setDni(dniPersonaMenu);
	personaTemporal->setFechaNacimiento(fechaNacimientoPersonaMenu);
	personaTemporal->setTelefono(telefonoPersonaMenu);
	personaTemporal->setNivelEstudio(nivelEstudioPersonaMenu);
	personaTemporal->setProfesion(profesionPersonaMenu);
	personaTemporal->setUltimoTrabajo(ultimoTrabajoPersonaMenu);
}
