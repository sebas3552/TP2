#include "Arbol.h"
#include <iostream>
using namespace std;
Arbol::Arbol()
{
	raiz =  new Nodo();
}

Arbol::~Arbol()
{
	delete raiz;
}

void Arbol::agregar(Palabra &palabra)
{
	int* indices = palabra.getIndices();
	const int largo = palabra.getLength();
	int caracterActual = 0;
	raiz->crearCamino(*raiz, indices, largo, caracterActual);
}

bool Arbol::verificar(Palabra &palabra) const
{
	int * indices = palabra.getIndices();
	const int largo = palabra.getLength();
	int caracterActual = 0;
	return raiz->recorrerCamino(*raiz, indices, largo, caracterActual);
}

void Arbol::verCamino(Palabra &palabra) const
{
	int * indices = palabra.getIndices();
	const int largo = palabra.getLength();
	int caracterActual = 0;
	if(raiz->recorrerCamino(*raiz, indices, largo, caracterActual))
		raiz->recorrerCamino(*raiz, indices, largo, caracterActual, 1);
	else
		cerr << "La palabra " << "\"" << palabra << "\"" << " no existe en el diccionario!" << endl;
}
