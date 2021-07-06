#include "ArregloPersonas.h"

ArregloPersonas::ArregloPersonas()
{
	arregloPersonas = nullptr;
	cantPersonas = 0;
}

ArregloPersonas::~ArregloPersonas()
{
	for (int i = 0; i < cantPersonas; i++)
	{
		delete arregloPersonas[i];
	}
	if (arregloPersonas != nullptr)
	{
		delete[] arregloPersonas;
	}
}

void ArregloPersonas::agregarPersonas(Persona* nuevaPersona)
{
	Persona** aux = new Persona * [cantPersonas + 1];
	for (int i = 0; i < cantPersonas; i++)
	{
		aux[i] = arregloPersonas[i];
	}
	aux[cantPersonas] = nuevaPersona;
	if (arregloPersonas != nullptr)
	{
		delete[] arregloPersonas;
	}
	arregloPersonas = aux;
	cantPersonas++;
}

void ArregloPersonas::eliminarPersonas(int posicion)
{
	Persona** aux = new Persona * [cantPersonas - 1];
	for (int i = 0; i < posicion; i++)
	{
		aux[i] = arregloPersonas[i];
	}
	for (int i = posicion; i < cantPersonas - 1; i++)
	{
		aux[i] = arregloPersonas[i + 1];
	}
	delete arregloPersonas[posicion];
	if (arregloPersonas != nullptr)
	{
		delete[] arregloPersonas;
	}
	arregloPersonas = aux;
	cantPersonas--;
}

Persona* ArregloPersonas::getArregloPersonas(int posicion)
{
	return arregloPersonas[posicion];
}

void ArregloPersonas::mostrar()
{
	for (int i = 0; i < cantPersonas; i++)
	{
		cout <<"\tPersona Nro " << (i + 1) << endl;
		cout << "\n";
		arregloPersonas[i]->mostrar();
		cout << "\n";
	}
}

int ArregloPersonas::tamanio()
{
	return cantPersonas;
}

void ArregloPersonas::mostrar(int posicion)
{
	arregloPersonas[posicion]->mostrar();
	system("pause");
	cout << "\n";
}

void ArregloPersonas::mostrar(string a)
{
	for (int i = 0; i < cantPersonas; i++)
	{
		cout << "\tPERSONA NRO " << (i + 1) << endl;
		arregloPersonas[i]->mostrar(a);
		cout << "\n";
	}
}