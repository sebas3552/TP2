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
	int caracterActual = 0;
	raiz->crearCamino(*raiz, palabra.indices, palabra.length, caracterActual);
}

bool Arbol::verificar(Palabra &palabra) const
{
	int caracterActual = 0;
	return raiz->recorrerCamino(*raiz, palabra.indices, palabra.length, caracterActual);
}

void Arbol::verCamino(Palabra &palabra) const
{
	int caracterActual = 0;
	if(raiz->recorrerCamino(*raiz, palabra.indices, palabra.length, caracterActual))
		raiz->recorrerCamino(*raiz, palabra.indices, palabra.length, caracterActual, 1);
	else
		cerr << "La palabra " << "\"" << palabra << "\"" << " no existe en el diccionario!" << endl;
}
