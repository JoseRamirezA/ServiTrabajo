#include "ArregloJuridicas.h"

ArregloJuridicas::ArregloJuridicas()
{
	arregloJuridicas = nullptr;
	cantJuridicas = 0;
}

ArregloJuridicas::~ArregloJuridicas()
{
	for (int i = 0; i < cantJuridicas; i++)
	{
		delete arregloJuridicas[i];
	}
	if (arregloJuridicas != nullptr)
	{
		delete[] arregloJuridicas;
	}
}

void ArregloJuridicas::agregarJuridicas(PersonaJuridica* nuevaPersona)
{
	PersonaJuridica** aux = new PersonaJuridica * [cantJuridicas + 1];
	for (int i = 0; i < cantJuridicas; i++)
	{
		aux[i] = arregloJuridicas[i];
	}
	aux[cantJuridicas] = nuevaPersona;
	if (arregloJuridicas!= nullptr)
	{
		delete[] arregloJuridicas;
	}
	arregloJuridicas = aux;
	cantJuridicas++;
}

void ArregloJuridicas::eliminarJuridicas(int posicion)
{
	PersonaJuridica** aux = new PersonaJuridica * [cantJuridicas - 1];
	for (int i = 0; i < posicion; i++)
	{
		aux[i] = arregloJuridicas[i];
	}
	for (int i = posicion; i < cantJuridicas - 1; i++)
	{
		aux[i] = arregloJuridicas[i + 1];
	}
	delete arregloJuridicas[posicion];
	if (arregloJuridicas!= nullptr)
	{
		delete[] arregloJuridicas;
	}
	arregloJuridicas = aux;
	cantJuridicas--;
}

PersonaJuridica* ArregloJuridicas::getArregloJuridicas(int posicion)
{
	return arregloJuridicas[posicion];
}

void ArregloJuridicas::mostrar()
{
	for (int i = 0; i < cantJuridicas; i++)
	{
		cout << "\tEmpresa Nro " << (i + 1) << endl;
		cout << "\n";
		arregloJuridicas[i]->mostrar();
		cout << "\n";
	}
}

int ArregloJuridicas::tamanio()
{
	return cantJuridicas;
}

void ArregloJuridicas::mostrar(int posicion)
{
	arregloJuridicas[posicion]->mostrar();
	system("pause");
	cout << "\n";
}

void ArregloJuridicas::mostrar(string a)
{
	for (int i = 0; i < cantJuridicas; i++)
	{
		cout << "\tEMPRESA NRO " << (i + 1) << endl;
		arregloJuridicas[i]->mostrar(a);
		cout << "\n";
	}
}