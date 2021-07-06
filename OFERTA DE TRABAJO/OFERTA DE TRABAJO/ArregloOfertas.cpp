#include "ArregloOfertas.h"

ArregloOfertas::ArregloOfertas()
{
	arregloOfertas = nullptr;
	cantOfertas = 0;
}

ArregloOfertas::~ArregloOfertas()
{
	for (int i = 0; i < cantOfertas; i++)
	{
		delete arregloOfertas[i];
	}
	if (arregloOfertas != nullptr)
	{
		delete[] arregloOfertas;
	}
}

void ArregloOfertas::agregarOfertas(OfertaLaboral* nuevaOferta)
{
	OfertaLaboral** aux = new OfertaLaboral * [cantOfertas + 1];
	for (int i = 0; i < cantOfertas; i++)
	{
		aux[i] = arregloOfertas[i];
	}
	aux[cantOfertas] = nuevaOferta;
	if (arregloOfertas != nullptr)
	{
		delete[] arregloOfertas;
	}
	arregloOfertas = aux;
	cantOfertas++;
}

void ArregloOfertas::eliminarOfertas(int posicion)
{
	OfertaLaboral** aux = new OfertaLaboral * [cantOfertas - 1];
	for (int i = 0; i < posicion; i++)
	{
		aux[i] = arregloOfertas[i];
	}
	for (int i = posicion; i < cantOfertas - 1; i++)
	{
		aux[i] = arregloOfertas[i + 1];
	}
	delete arregloOfertas[posicion];
	if (arregloOfertas != nullptr)
	{
		delete[] arregloOfertas;
	}
	arregloOfertas = aux;
	cantOfertas--;
}

OfertaLaboral* ArregloOfertas::getArregloOfertas(int posicion)
{
	return arregloOfertas[posicion];
}

void ArregloOfertas::mostrar()
{
	for (int i = 0; i < cantOfertas; i++)
	{
		cout <<"\tOFERTA Nro. "<< (i + 1) << endl;
		arregloOfertas[i]->mostrar();
		cout << "\n";
	}
}

int ArregloOfertas::tamanio()
{
	return cantOfertas;
}

void ArregloOfertas::mostrar(int posicion)
{
	cout << "\tOFERTA:" << endl;
	arregloOfertas[posicion]->mostrar();
	cout << "\n";
}



void ArregloOfertas::mostrar(string a)
{
	for (int i = 0; i < cantOfertas; i++)
	{
		cout << "\tOFERTA Nro. " << (i + 1) << endl;
		arregloOfertas[i]->mostrar(a);
		cout << "\n";
	}
}