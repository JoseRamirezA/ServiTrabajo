#include "menuGeneral.h"
#include <fstream>
#include <string>

//Variables Generales
int opcion = 0, nPersona = 0, nEmpresa = 0, nOfertas = 0;
bool flag1, flag2, flag3, flag4, flag5, flag6;

string ussernamePersonaMenu, passwordPersonaMenu, nombrePersonaMenu, apellidoPersonaMenu, dniPersonaMenu, nivelEstudioPersonaMenu, profesionPersonaMenu, ultimoTrabajoPersonaMenu;
int fechaNacimientoPersonaMenu, telefonoPersonaMenu;

string ussernameJuridicaMenu, passwordJuridicaMenu, nombreJuridicaMenu, direccionJuridicaMenu, rucJuridicaMenu;
int  telefonoJuridicaMenu;

string tituloOferta, descripcionOferta;
int salarioOferta = 0;
int pos=0;

string clave;

ArregloPersonas* P = new ArregloPersonas();
Persona* personaTemporal;

ArregloJuridicas* J = new ArregloJuridicas();
PersonaJuridica* juridicaTemporal;

ArregloOfertas* O = new ArregloOfertas();
OfertaLaboral* ofertaTemporal;


void leer()
{
	string linea;
	ifstream listaP("persona.txt");
	ifstream listaJ("empresa.txt");
	ifstream listaO("oferta.txt");
	int contador = 0;

	while (getline(listaP, linea))
	{
		switch (contador)
		{
		case 0: ussernamePersonaMenu = linea; break;
		case 1: passwordPersonaMenu = linea; break;
		case 2: nombrePersonaMenu = linea; break;
		case 3: apellidoPersonaMenu = linea; break;
		case 4: dniPersonaMenu = linea; break;
		case 5: fechaNacimientoPersonaMenu = atoi(linea.c_str()); break;
		case 6: telefonoPersonaMenu = atoi(linea.c_str()); break;
		case 7: nivelEstudioPersonaMenu = linea; break;
		case 8: profesionPersonaMenu = linea; break;
		case 9:	ultimoTrabajoPersonaMenu = linea;
			P->agregarPersonas(new Persona(ussernamePersonaMenu, passwordPersonaMenu, nombrePersonaMenu, apellidoPersonaMenu, dniPersonaMenu, fechaNacimientoPersonaMenu, telefonoPersonaMenu, nivelEstudioPersonaMenu, profesionPersonaMenu, ultimoTrabajoPersonaMenu));
			break;
		}
		contador++;
		if (contador > 9)
		{
			contador = 0;
		}
	}
	
	while (getline(listaJ, linea))
	{
		switch (contador)
		{
		case 0: ussernameJuridicaMenu = linea; break;
		case 1: passwordJuridicaMenu = linea; break;
		case 2: rucJuridicaMenu = linea; break;
		case 3: nombreJuridicaMenu = linea; break;
		case 4: telefonoJuridicaMenu = atoi(linea.c_str()); break;
		case 5: direccionJuridicaMenu = linea;
			J->agregarJuridicas(new PersonaJuridica(ussernameJuridicaMenu, passwordJuridicaMenu, rucJuridicaMenu, nombreJuridicaMenu, telefonoJuridicaMenu, direccionJuridicaMenu));
			break;
		}
		contador++;
		if (contador > 5)
		{
			contador = 0;
		}
	}
	
	while (getline(listaO, linea))
	{
		switch (contador)
		{
		case 0: rucJuridicaMenu = linea; break;
		case 1: tituloOferta = linea; break;
		case 2: descripcionOferta = linea; break;
		case 3: salarioOferta = atoi(linea.c_str());
			O->agregarOfertas(new OfertaLaboral(tituloOferta, descripcionOferta, salarioOferta, rucJuridicaMenu));
			break;
		}
		contador++;
		if (contador > 3)
		{
			contador = 0;
		}
	}

	listaP.close();
	listaJ.close();
	listaO.close();
}

void escribirP()
{
	ofstream listaP("persona.txt");
	int a = P->tamanio();
	for (int i = 0; i < a; i++)
	{
		personaTemporal = P->getArregloPersonas(i);
		listaP << personaTemporal->getUsername() << endl;
		listaP << personaTemporal->getPassword() << endl;
		listaP << personaTemporal->getNombre() << endl;
		listaP << personaTemporal->getApellido() << endl;
		listaP << personaTemporal->getDni() << endl;
		listaP << personaTemporal->getFechaNacimiento() << endl;
		listaP << personaTemporal->getTelefono() << endl;
		listaP << personaTemporal->getNivelEstudio() << endl;
		listaP << personaTemporal->getProfesion() << endl;
		listaP << personaTemporal->getUltimoTrabajo();
		listaP << "\n";
	}
	listaP.close();
}

void escribirJ()
{
	ofstream listaJ("empresa.txt");
	int b = J->tamanio();
	for (int i = 0; i < b; i++)
	{
		juridicaTemporal = J->getArregloJuridicas(i);
		listaJ << juridicaTemporal->getUsername() << endl;
		listaJ << juridicaTemporal->getPassword() << endl;
		listaJ << juridicaTemporal->getRucPersonaJuridica() << endl;
		listaJ << juridicaTemporal->getNombrePersonaJuridica() << endl;
		listaJ << juridicaTemporal->getTelefonoPersonaJuridica() << endl;
		listaJ << juridicaTemporal->getDireccionPersonaJuridica();
		listaJ << "\n";
	}
	listaJ.close();
}

void escribirO()
{
	ofstream listaO("oferta.txt");
	int c = O->tamanio();
	for (int i = 0; i < c; i++)
	{
		ofertaTemporal = O->getArregloOfertas(i);
		listaO << ofertaTemporal->getRucOferta() << endl;
		listaO << ofertaTemporal->getTituloOferta() << endl;
		listaO << ofertaTemporal->getDescripcionOferta() << endl;
		listaO << ofertaTemporal->getSalarioOferta();
		listaO << "\n";
	}
	listaO.close();
}


void bienvenida()
{
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\t||||||||||||||||||||||||\t||||||||||||||||||||||  \t||||||||||||||||||||||||" << endl;
	cout << "\t||||||||||||||||||||||||\t||||||||         |||||||\t||||||||||||||||||||||||" << endl;
	cout << "\t||||||||||||||||||||||||\t||||||||           |||||\t||||||||||||||||||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||           |||||\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||         |||||||\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||||||||||||||||  \t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\n";
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\t   |||||| |||||   ||||  |||||   ||||  ||||||  ||||       |||||   ||||  |||||   |||| " << endl;
	cout << "\t     ||   ||  || ||  || ||  || ||  ||    ||  ||  ||      ||  || ||  || ||  || ||  ||" << endl;
	cout << "\t     ||   ||||   |||||| |||||  ||||||    ||  ||  ||      |||||  |||||| ||||   ||||||" << endl;
	cout << "\t     ||   || ||  ||  || ||  || ||  || || ||  ||  ||      ||     ||  || || ||  ||  ||" << endl;
	cout << "\t     ||   ||  || ||  || |||||  ||  ||  ||||   ||||       ||     ||  || ||  || ||  ||" << endl;
	cout << "\n";
	cout << "\t\t\t\t    ||||||  ||||  |||||   ||||   |||||" << endl;
	cout << "\t\t\t\t      ||   ||  || ||  || ||  || ||    " << endl;
	cout << "\t\t\t\t      ||   ||  || ||  || ||  ||  |||| " << endl;
	cout << "\t\t\t\t      ||   ||  || ||  || ||  ||     ||" << endl;
	cout << "\t\t\t\t      ||    ||||  |||||   ||||  ||||| \n" << endl;
	system("pause");
	system("cls");
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\t    |||||||  |||| |||||| |||   ||| |||  ||| |||||| |||   ||| |||| |||||||   ||||||||" << endl;
	cout << "\t    |||  ||| |||| |||    ||||  ||| |||  ||| |||    ||||  ||| |||| |||  |||  |||  |||" << endl;
	cout << "\t    |||||||  |||| |||||| ||| | ||| |||  ||| |||||| ||| | ||| |||| |||   ||| |||  |||" << endl;
	cout << "\t    |||  ||| |||| |||    |||  ||||  ||||||  |||    |||  |||| |||| |||  |||  |||  |||" << endl;
	cout << "\t    |||||||  |||| |||||| |||   |||   ||||   |||||| |||   ||| |||| |||||||   ||||||||" << endl;
	cout << "\n";
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n\n\n\n\n";
	system("pause");
	system("cls");
}
void despedida()
{
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\t    ||  ||  ||||   ||||| ||||||   ||||            ||     ||  || ||||||  |||||  |||| " << endl;
	cout << "\t    ||  || ||  || ||       ||    ||  ||           ||     ||  || ||     ||     ||  ||" << endl;
	cout << "\t    |||||| ||||||  ||||    ||    ||||||           ||     ||  || |||||| || ||| ||  ||" << endl;
	cout << "\t    ||  || ||  ||     ||   ||    ||  ||           ||     ||  || ||     ||  || ||  ||" << endl;
	cout << "\t    ||  || ||  || |||||    ||    ||  ||           |||||| |||||| ||||||  ||||   |||| " << endl;
	cout << "\n";
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n\n\n\n\n";
	system("pause");
	system("cls");
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\t||||||||||||||||||||||||\t||||||||||||||||||||||  \t||||||||||||||||||||||||" << endl;
	cout << "\t||||||||||||||||||||||||\t||||||||         |||||||\t||||||||||||||||||||||||" << endl;
	cout << "\t||||||||||||||||||||||||\t||||||||           |||||\t||||||||||||||||||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||           |||||\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||         |||||||\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||||||||||||||||  \t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\t\t||||||||\t\t||||||||\t\t\t\t||||||||" << endl;
	cout << "\n";
	cout << "\t----------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\t   |||||| |||||   ||||  |||||   ||||  ||||||  ||||       |||||   ||||  |||||   |||| " << endl;
	cout << "\t     ||   ||  || ||  || ||  || ||  ||    ||  ||  ||      ||  || ||  || ||  || ||  ||" << endl;
	cout << "\t     ||   ||||   |||||| |||||  ||||||    ||  ||  ||      |||||  |||||| ||||   ||||||" << endl;
	cout << "\t     ||   || ||  ||  || ||  || ||  || || ||  ||  ||      ||     ||  || || ||  ||  ||" << endl;
	cout << "\t     ||   ||  || ||  || |||||  ||  ||  ||||   ||||       ||     ||  || ||  || ||  ||" << endl;
	cout << "\n";
	cout << "\t\t\t\t    ||||||  ||||  |||||   ||||   |||||" << endl;
	cout << "\t\t\t\t      ||   ||  || ||  || ||  || ||    " << endl;
	cout << "\t\t\t\t      ||   ||  || ||  || ||  ||  |||| " << endl;
	cout << "\t\t\t\t      ||   ||  || ||  || ||  ||     ||" << endl;
	cout << "\t\t\t\t      ||    ||||  |||||   ||||  ||||| " << endl;
	system("pause");
	system("cls");
}
void proceso()
{
	flag1 = true;
	while (flag1 == true)
	{
		menu(opcion);
		switch (opcion)
		{
		case 1:
			flag2 = true;
			while (flag2==true)
			{
				menuPersona(opcion);
			}
			break;
		case 2:
			flag2 = true;
			while (flag2 == true)
			{
				menuEmpresa(opcion);
			}
			break;
		case 3:
			flag2 = true;
			while (flag2 == true)
			{
				menuAdministrador(opcion);
			}
			break;
		case 4:
			flag1 = false;
			delete P;
			delete J;
			delete O;
			delete personaTemporal;
			delete juridicaTemporal;
			delete ofertaTemporal;
			break;
		}
	}
}
void menu(int& opcion)
{
	do {
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t1. Persona" << endl;
		cout << "\t2. Persona Juridica (Empresa)" << endl;
		cout << "\t3. Administrador" << endl;
		cout << "\t4. Salir" << endl;
		cout << "\n\tIngrese la opcion deseada: ";
		cin >> opcion;
		if (opcion < 1 || opcion>4)
		{
			system("cls");
			cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\t    DEBE INGRESAR UNA OPCION VALIDA\n\n\n\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
		}
	} while (opcion < 1 || opcion>4);
	system("cls");
}


//PERSONA

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
		cout << "\n\tIngrese la opcion deseada: ";
		cin >> opcion;
		if (opcion < 1 || opcion>4)
		{
			system("cls");
			cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\t    DEBE INGRESAR UNA OPCION VALIDA\n\n\n\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (opcion < 1 || opcion>4);


	switch (opcion)
	{
	case 1: inicioSesionPersona(); break;
	case 2:	registroPersona(); break;
	case 3: flag2=false; break;
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
	cout << "\n\tIngrese su Contraseña: ";
	cin >> passwordPersonaMenu;
	system("cls");
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      PERSONA       --------\n" << endl;
	cout << "\t--------      REGISTRO      --------\n" << endl;
	cout << "\n";
	cout << "\tIngrese sus Nombres: ";
	cin.ignore();
	getline(cin, nombrePersonaMenu);
	cout << "\n\tIngrese sus Apellidos: ";
	getline(cin, apellidoPersonaMenu);
	cout << "\n\tIngrese su DNI: ";
	cin>>dniPersonaMenu;
	cout << "\n\tIngrese su Fecha de Nacimiento: ";
	cin>>fechaNacimientoPersonaMenu;
	cout << "\n\tIngrese su telefono: ";
	cin>>telefonoPersonaMenu;
	cin.ignore();
	cout << "\n\tIngrese su nivel de Estudio: ";
	getline(cin, nivelEstudioPersonaMenu);
	cout << "\n\tIngrese su Profesion: ";
	getline(cin, profesionPersonaMenu);
	cout << "\n\tIngrese su Ultimo puesto de trabajo: ";
	getline(cin, ultimoTrabajoPersonaMenu);
	system("cls");
	P->agregarPersonas(new Persona(ussernamePersonaMenu,passwordPersonaMenu,nombrePersonaMenu,apellidoPersonaMenu,dniPersonaMenu,fechaNacimientoPersonaMenu,telefonoPersonaMenu,nivelEstudioPersonaMenu,profesionPersonaMenu,ultimoTrabajoPersonaMenu));
	cout << "\n\n\n\t-------------- FELICIDADES ----------------\n\n" << endl;
	cout << "\n\t\tREGISTRADO CORRECTAMENTE\n\n\n\n\n\n";
	escribirP();
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
	cout << "\n\tIngrese su Contrasena: ";
	cin >> passwordPersonaMenu;
	nPersona=buscarPersona(ussernamePersonaMenu, passwordPersonaMenu);
	if (nPersona>=0)
	{
		system("cls");
		cout << "\n\n\n\t--------------- BIENVENIDO ---------------\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
		flag3 = true;
		while (flag3==true)
		{
			opcionesPersona();
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
		cout << "\n\t    USUARIO O CONTRASENA INCORRECTO\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
	}
}

int buscarPersona(string& ussername,string& password)
{
	int a = P->tamanio();
	for (int i = 0; i < a; i++)
	{
		personaTemporal = P->getArregloPersonas(i);
		if (personaTemporal->getUsername() == ussername && personaTemporal->getPassword() == password)
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
		cout << "\t3. Mostrar Ofertas de Trabajo: " << endl;
		cout << "\t4. Eliminar mi cuenta" << endl;
		cout << "\t5. Salir de mi cuenta" << endl;
		cout << "\n\tIngrese la opcion deseada: ";
		cin >> opcion;
		if (opcion < 1 || opcion>5)
		{
			system("cls");
			cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\t    DEBE INGRESAR UNA OPCION VALIDA\n\n\n\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
		system("cls");
	} while (opcion < 1 || opcion>5);


	switch (opcion)
	{
	case 1:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------      PERSONA       --------\n" << endl;
		cout << "\t--------  DATOS PERSONALES  --------\n" << endl;
		cout << "\n";
		P->mostrar(nPersona);
		cout << "\n\n\n\n";
		system("cls");
		break;
	case 2:	
		modificarDatosPersona();
		escribirP();
		break;
	case 3:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------      PERSONA       --------\n" << endl;
		cout << "\t--------  OFERTAS LABORALES --------\n" << endl;
		cout << "\n";
		O->mostrar();
		system("pause");
		system("cls");
		break;
	case 4:
		P->eliminarPersonas(nPersona);
		cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
		cout << "\n\t     CUENTA ELIMINADA CORRECTAMENTE\n" << endl;
		cout << "\n\t  USTED A NO SE ENCUENTRA EN NUESTRO SISTEMA\n" << endl;
		cout << "\n\t DEBE VOLVER A REGISTRARSE PARA TENER ACCESO\n\n\n\n\n\n\n\n\n" << endl;
		escribirP();
		flag3 = false;
		system("pause");
		system("cls");
		break;
	case 5: flag3 = false; break;
	}
}

void modificarDatosPersona()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      PERSONA       --------\n" << endl;
	cout << "\t--------  CAMBIO DE DATOS   --------\n\n" << endl;
	personaTemporal = P->getArregloPersonas(nPersona);
	cout << "\tIngrese sus Nombres: ";
	cin.ignore();
	getline(cin, nombrePersonaMenu);
	cout << "\n\tIngrese sus Apellidos: ";
	getline(cin, apellidoPersonaMenu);
	cout << "\n\tIngrese su DNI: ";
	cin >> dniPersonaMenu;
	cout << "\n\tIngrese su Fecha de Nacimiento (20051980): ";
	cin >> fechaNacimientoPersonaMenu;
	cout << "\n\tIngrese su telefono: ";
	cin >> telefonoPersonaMenu;
	cin.ignore();
	cout << "\n\tIngrese su nivel de Estudio: ";
	getline(cin, nivelEstudioPersonaMenu);
	cout << "\n\tIngrese su Profesion: ";
	getline(cin, profesionPersonaMenu);
	cout << "\n\tIngrese su Ultimo puesto de trabajo: ";
	getline(cin, ultimoTrabajoPersonaMenu);
	personaTemporal->setNombre(nombrePersonaMenu);
	personaTemporal->setApellido(apellidoPersonaMenu);
	personaTemporal->setDni(dniPersonaMenu);
	personaTemporal->setFechaNacimiento(fechaNacimientoPersonaMenu);
	personaTemporal->setTelefono(telefonoPersonaMenu);
	personaTemporal->setNivelEstudio(nivelEstudioPersonaMenu);
	personaTemporal->setProfesion(profesionPersonaMenu);
	personaTemporal->setUltimoTrabajo(ultimoTrabajoPersonaMenu);
	system("cls");
	cout << "\n\n\n\t----- CAMBIO REALIZADO CORRECTAMENTE -----\n" << endl;
	cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
	system("pause");
	system("cls");
}


//PERSONA JURIDICA - EMPRESA

void menuEmpresa(int opcion)
{
	do {
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------      EMPRESA       --------\n" << endl;
		cout << "\t1. Iniciar Sesion" << endl;
		cout << "\t2. Registro" << endl;
		cout << "\t3. Volver" << endl;
		cout << "\t4. Salir" << endl;
		cout << "\n\tIngrese la opcion deseada: ";
		cin >> opcion;
		if (opcion < 1 || opcion>4)
		{
			system("cls");
			cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\t    DEBE INGRESAR UNA OPCION VALIDA\n\n\n\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (opcion < 1 || opcion>4);


	switch (opcion)
	{
	case 1: inicioSesionEmpresa(); break;
	case 2:	
		registroEmpresa();
		escribirJ();
		; break;
	case 3: flag2 = false; break;
	case 4:	flag1 = false; flag2 = false; break;
	}
}

void registroEmpresa()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      EMPRESA       --------\n" << endl;
	cout << "\t--------      REGISTRO      --------\n" << endl;
	cout << "\n";
	cout << "\tIngrese su Usuario: ";
	cin >> ussernameJuridicaMenu;
	cout << "\n\tIngrese su Contraseña: ";
	cin >> passwordJuridicaMenu;
	system("cls");
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      EMPRESA       --------\n" << endl;
	cout << "\t--------      REGISTRO      --------\n" << endl;
	cout << "\n";
	cout << "\tIngrese su RUC: ";
	cin>>rucJuridicaMenu;
	cout << "\n\tIngrese nombre de la Empresa: ";
	cin.ignore();
	getline(cin, nombreJuridicaMenu);
	cout << "\n\tIngrese su Telefono: ";
	cin>>telefonoJuridicaMenu;
	cout << "\n\tIngrese su Direccion: ";
	cin.ignore();
	getline(cin, direccionJuridicaMenu);
	system("cls");
	J->agregarJuridicas(new PersonaJuridica(ussernameJuridicaMenu,passwordJuridicaMenu,rucJuridicaMenu,nombreJuridicaMenu,telefonoJuridicaMenu,direccionJuridicaMenu));
	cout << "\n\n\n\t-------------- FELICIDADES ----------------\n\n" << endl;
	cout << "\n\t\tREGISTRADO CORRECTAMENTE\n\n\n\n\n\n";
	system("pause");
	system("cls");
}

void inicioSesionEmpresa()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      PERSONA       --------\n" << endl;
	cout << "\t--------   INICIO SESION    --------\n" << endl;
	cout << "\n";
	cout << "\tIngrese su Usuario: ";
	cin >> ussernameJuridicaMenu;
	cout << "\n\tIngrese su Contraseña: ";
	cin >> passwordJuridicaMenu;
	nEmpresa = buscarEmpresa(ussernameJuridicaMenu, passwordJuridicaMenu);
	if (nEmpresa >= 0)
	{
		system("cls");
		cout << "\n\n\n\t--------------- BIENVENIDO ---------------\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
		flag3 = true;
		while (flag3 == true)
		{
			opcionesEmpresa();
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
		cout << "\n\t    USUARIO O CONTRASENA INCORRECTO\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
	}
}

int buscarEmpresa(string& ussername, string& password)
{
	int b = J->tamanio();
	for (int i = 0; i < b; i++)
	{
		juridicaTemporal = J->getArregloJuridicas(i);
		if (juridicaTemporal->getUsername() == ussername && juridicaTemporal->getPassword() == password)
		{
			return i;
		}
	}
	return -1;
}

void opcionesEmpresa()
{
	do {
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------      EMPRESA       --------\n" << endl;
		cout << "\n";
		cout << "\t1. Ver mis Datos" << endl;
		cout << "\t2. Modificar mis datos" << endl;
		cout << "\t3. Registrar ofertas de Trabajo" << endl;
		cout << "\t4. Ver mis ofertas de Trabajo" << endl;
		cout << "\t5. Eliminar mi cuenta" << endl;
		cout << "\t6. Salir" << endl;
		cout << "\n\tIngrese la opcion deseada: ";
		cin >> opcion;
		if (opcion < 1 || opcion>6)
		{
			system("cls");
			cout << "\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\tDEBE INGRESAR UNA OPCION VALIDA\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (opcion < 1 || opcion>6);

	
	switch(opcion)
	{
		case 1:
			cout << "\n";
			cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
			cout << "\t--------      EMPRESA       --------\n" << endl;
			cout << "\t--------   DATOS EMPRESA    --------\n" << endl;
			cout << "\n";
			J->mostrar(nEmpresa);
			cout << "\n\n\n\n";
			system("cls");
			break;
		case 2:
			modificarDatosEmpresa();
			escribirJ();
			break;
		case 3: 
			registroOferta();
			escribirO();
			; break;
		case 4:	verOfertas(); break;
		case 5:
			J->eliminarJuridicas(nEmpresa);
			cout << "\n\n\n\t------------------ ALERTA ------------------\n" << endl;
			cout << "\n\t     CUENTA ELIMINADA CORRECTAMENTE\n" << endl;
			cout << "\n\t  USTED A NO SE ENCUENTRA EN NUESTRO SISTEMA\n" << endl;
			cout << "\n\t DEBE VOLVER A REGISTRARSE PARA TENER ACCESO\n\n\n\n\n\n\n\n\n" << endl;
			escribirJ();
			flag3 = false;
			system("pause");
			system("cls");

			break;
		case 6:
			flag3 = false; break;
	}
}

void modificarDatosEmpresa()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      EMPRESA       --------\n" << endl;
	cout << "\t--------  CAMBIO DE DATOS   --------\n\n" << endl;
	juridicaTemporal = J->getArregloJuridicas(nEmpresa);
	cout << "\tIngrese su RUC: ";
	cin >> rucJuridicaMenu;
	cout << "\n\tIngrese nombre de la Empresa: ";
	cin.ignore();
	getline(cin, nombreJuridicaMenu);
	cout << "\n\tIngrese su Telefono: ";
	cin >> telefonoJuridicaMenu;
	cout << "\n\tIngrese su Direccion: ";
	cin.ignore();
	getline(cin, direccionJuridicaMenu);
	juridicaTemporal->setRucPersonaJuridica(rucJuridicaMenu);
	juridicaTemporal->setNombrePersonaJuridica(nombreJuridicaMenu);
	juridicaTemporal->setTelefonoPersonaJuridica(telefonoJuridicaMenu);
	juridicaTemporal->setDireccionPersonaJuridica(direccionJuridicaMenu);
	system("cls");
	cout << "\n\n\n\t----- CAMBIO REALIZADO CORRECTAMENTE -----\n" << endl;
	cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
	system("pause");
	system("cls");
}

void registroOferta()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      EMPRESA       --------\n" << endl;
	cout << "\t------REGISTRO OFERTA LABORAL-------\n\n" << endl;
	cout << "\tIngrese el Titulo de la Oferta: \n\t";
	cin.ignore();
	getline(cin, tituloOferta);
	cout << "\n\tIngrese la descripcion de la Oferta: \n\t";
	getline(cin, descripcionOferta);
	cout << "\n\tIngrese el Salario: \n\t";
	cin >> salarioOferta;
	system("cls");
	O->agregarOfertas(new OfertaLaboral(tituloOferta,descripcionOferta,salarioOferta,juridicaTemporal->getRucPersonaJuridica()));
	cout << "\n\n\n\t-------------- FELICIDADES ----------------\n\n" << endl;
	cout << "\n\t     OFERTA REGISTRADA CORRECTAMENTE\n\n\n\n\n\n";
	system("pause");
	system("cls");
}

void verOfertas()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------      EMPRESA       --------\n" << endl;
	cout << "\t-------- OFERTAS DE EMPRESA --------\n" << endl;
	cout << "\n";
	int c = O->tamanio();
	for (int i = 0; i < c; i++)
	{
		ofertaTemporal = O->getArregloOfertas(i);
		if (ofertaTemporal->getRucOferta() == juridicaTemporal->getRucPersonaJuridica())
		{
				O->mostrar(i);
		}
	}

	system("pause");
	system("cls");
}

//ADMINISTRADOR

void menuAdministrador(int opcion)
{
	do {
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------    ADMINISTRADOR   --------\n" << endl;
		cout << "\t1. Iniciar Sesion" << endl;
		cout << "\t2. Volver" << endl;
		cout << "\t3. Salir" << endl;
		cout << "\n\tIngrese la opcion deseada: ";
		cin >> opcion;
		if (opcion < 1 || opcion>3)
		{
			system("cls");
			cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\t    DEBE INGRESAR UNA OPCION VALIDA\n\n\n\n\n\n\n\n\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (opcion < 1 || opcion>3);


	switch (opcion)
	{
	case 1: inicioSesionAdministrador(); break;
	case 2: flag2 = false; break;
	case 3:	flag1 = false; flag2 = false; break;
	}
}

void inicioSesionAdministrador()
{
	cout << "\n";
	cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
	cout << "\t--------    ADMINISTRADOR   --------\n" << endl;
	cout << "\t--------   INICIO SESION    --------\n" << endl;
	cout << "\tINGRESE CLAVE SECRETA (1234): ";
	cin>>clave;
	if (clave == "1234")
	{

		system("cls");
		cout << "\n\n\n\t--------------- BIENVENIDO ---------------\n" << endl;
		cout << "\n\t\t USTED ES ADMINISTRADOR\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
		flag3 = true;
		while (flag3 == true)
		{
			opcionesAdministrador();
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\n\t---------------- ALERTA ----------------\n" << endl;
		cout << "\n\t\tUSTED NO ES ADMINISTRADOR\n\n\n" << endl;
		cout << "\n\t\     O LA CONTRASEÑA ES INCORRECTA\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
	}
}

void opcionesAdministrador()
{
	do {
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\n";
		cout << "\t1. Ver las Personas registradas" << endl;
		cout << "\t2. Modificar Personas registradas" << endl;
		cout << "\t3. Eliminar Personas registradas" << endl;
		cout << "\t4. Ver las Personas Juridicas registradas (Empresas)" << endl;
		cout << "\t5. Modificar Personas Juridicas registradas(Empresas)" << endl;
		cout << "\t6. Eliminar Personas Juridicas registradas (Empresas)" << endl;
		cout << "\t7. Ver las Ofertas Laborales registradas" << endl;
		cout << "\t8. Modificar las Ofertas Laborales registradas" << endl;
		cout << "\t9. Eliminar las Ofertas Laborales registradas" << endl;
		cout << "\t10. Salir" << endl;
		cout << "\n\tIngrese la opcion deseada: ";
		cin >> opcion;
		if (opcion < 1 || opcion>10)
		{
			system("cls");
			cout << "\n\t---------------- ALERTA ----------------\n" << endl;
			cout << "\n\tDEBE INGRESAR UNA OPCION VALIDA\n" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (opcion < 1 || opcion>10);


	switch (opcion)
	{
	case 1:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t--------PERSONAS REGISTRADAS--------\n" << endl;
		cout << "\n";
		P->mostrar();
		system("pause");
		system("cls");
		break;
	case 2:	
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t-------- MODIFICAR PERSONAS --------\n" << endl;
		cout << "\n";
		P->mostrar("a");
		cout << "\tIngrese la posicion a modificar: ";
		cin >> pos;
		personaTemporal = P->getArregloPersonas(pos-1);
		system("cls");
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t-------- MODIFICAR PERSONAS --------\n" << endl;
		cout << "\t--------  PERSONA NRO " << pos << "  --------\n" << endl;
		cout << "\n";
		cout << "\tIngrese sus Nombres: ";
		cin.ignore();
		getline(cin, nombrePersonaMenu);
		cout << "\n\tIngrese sus Apellidos: ";
		getline(cin, apellidoPersonaMenu);
		cout << "\n\tIngrese su DNI: ";
		cin >> dniPersonaMenu;
		cout << "\n\tIngrese su Fecha de Nacimiento (20051980): ";
		cin >> fechaNacimientoPersonaMenu;
		cout << "\n\tIngrese su telefono: ";
		cin >> telefonoPersonaMenu;
		cout << "\n\tIngrese su nivel de Estudio: ";
		cin.ignore();
		getline(cin, nivelEstudioPersonaMenu);
		cout << "\n\tIngrese su Profesion: ";
		getline(cin, profesionPersonaMenu);
		cout << "\n\tIngrese su Ultimo puesto de trabajo: ";
		getline(cin, ultimoTrabajoPersonaMenu);
		personaTemporal->setNombre(nombrePersonaMenu);
		personaTemporal->setApellido(apellidoPersonaMenu);
		personaTemporal->setDni(dniPersonaMenu);
		personaTemporal->setFechaNacimiento(fechaNacimientoPersonaMenu);
		personaTemporal->setTelefono(telefonoPersonaMenu);
		personaTemporal->setNivelEstudio(nivelEstudioPersonaMenu);
		personaTemporal->setProfesion(profesionPersonaMenu);
		personaTemporal->setUltimoTrabajo(ultimoTrabajoPersonaMenu);
		system("cls");
		cout << "\n\n\n\t----- CAMBIO REALIZADO CORRECTAMENTE -----\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		escribirP();
		system("pause");
		system("cls");
		break;
	case 3:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t--------  ELIMINAR PERSONAS --------\n" << endl;
		cout << "\n";
		P->mostrar("a");
		cout << "\n\tIngrese la posicion a eliminar: ";
		cin >> pos;
		P->eliminarPersonas(pos - 1);
		escribirP();
		system("cls");
		cout << "\n\n\n\t----- PERSONA ELIMINADA CORRECTAMENTE -----\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
		break;
	case 4:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t--------EMPRESAS REGISTRADAS--------\n" << endl;
		cout << "\n";
		J->mostrar();
		system("pause");
		system("cls");
		break;
	case 5:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t-------- MODIFICAR EMPRESAS --------\n" << endl;
		cout << "\n";
		J->mostrar("a");
		cout << "\tIngrese la posicion a modificar: ";
		cin >> pos;
		juridicaTemporal = J->getArregloJuridicas(pos - 1);
		system("cls");
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t-------- MODIFICAR EMPRESAS --------\n" << endl;
		cout << "\t--------     EMPRESA " << pos << "     --------\n" << endl;
		cout << "\n";
		cout << "\tIngrese su RUC: ";
		cin >> rucJuridicaMenu;
		cout << "\n\tIngrese nombre de la Empresa: ";
		cin.ignore();
		getline(cin, nombreJuridicaMenu);
		cout << "\n\tIngrese su Telefono: ";
		cin >> telefonoJuridicaMenu;
		cout << "\n\tIngrese su Direccion: ";
		cin.ignore();
		getline(cin, direccionJuridicaMenu);
		juridicaTemporal->setNombrePersonaJuridica(nombreJuridicaMenu);
		juridicaTemporal->setRucPersonaJuridica(rucJuridicaMenu);
		juridicaTemporal->setTelefonoPersonaJuridica(telefonoJuridicaMenu);
		juridicaTemporal->setDireccionPersonaJuridica(direccionJuridicaMenu);
		system("cls");
		cout << "\n\n\n\t----- CAMBIO REALIZADO CORRECTAMENTE -----\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		escribirJ();
		system("pause");
		system("cls");
		break;
	case 6: 
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t--------  ELIMINAR EMPRESAS --------\n" << endl;
		cout << "\n";
		J->mostrar("a");
		cout << "\n\tIngrese la posicion a eliminar: ";
		cin >> pos;
		J->eliminarJuridicas(pos - 1);
		escribirJ();
		system("cls");
		cout << "\n\n\n\t----- EMPRESA ELIMINADA CORRECTAMENTE -----\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
		break;
	case 7:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t--------OFERTAS REGISTRADAS--------\n" << endl;
		cout << "\n";
		O->mostrar();
		system("pause");
		system("cls");
		break;
	case 8:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t-------- MODIFICAR OFERTAS  --------\n" << endl;
		cout << "\n";
		O->mostrar("a");
		cout << "\tIngrese la posicion a modificar: ";
		cin >> pos;
		ofertaTemporal = O->getArregloOfertas(pos - 1);
		system("cls");
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t-------- MODIFICAR OFERTAS  --------\n" << endl;
		cout << "\t--------      OFERTA " << pos << "      --------\n" << endl;
		cout << "\n";
		cout << "\tIngrese el Titulo de la Oferta: \n\t";
		cin.ignore();
		getline(cin, tituloOferta);
		cout << "\n\tIngrese la descripcion de la Oferta: \n\t";
		getline(cin, descripcionOferta);
		cout << "\n\tIngrese el Salario: \n\t";
		cin >> salarioOferta;
		ofertaTemporal->setTituloOferta(tituloOferta);
		ofertaTemporal->setDescripcionOferta(descripcionOferta);
		ofertaTemporal->setSalarioOferta(salarioOferta);
		system("cls");
		cout << "\n\n\n\t----- CAMBIO REALIZADO CORRECTAMENTE -----\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		escribirO();
		system("pause");
		system("cls");
		break;
	case 9:
		cout << "\n";
		cout << "\t-------- TRABAJO PARA TODOS --------\n" << endl;
		cout << "\t--------   ADMINISTRADOR    --------\n" << endl;
		cout << "\t--------  ELIMINAR OFERTAS  --------\n" << endl;
		cout << "\n";
		O->mostrar("a");
		cout << "\tIngrese la posicion a eliminar: ";
		cin >> pos;
		O->eliminarOfertas(pos - 1);
		escribirO();
		system("cls");
		cout << "\n\n\n\t----- EMPRESA ELIMINADA CORRECTAMENTE -----\n" << endl;
		cout << "\n\t\tDESEAMOS QUE ESTES BIEN\n\n\n\n\n\n\n\n\n" << endl;
		system("pause");
		system("cls");
		break;
	case 10: flag3 = false; break;
	}
}