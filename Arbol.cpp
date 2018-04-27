#include "Arbol.h"
#include <iostream>
using namespace std;
Arbol::Arbol()
{
	raiz = new Nodo*[Nodo::SIZE];
	for(int i = 0; i < Nodo::SIZE; i++)
		raiz[i] = nullptr;
	raiz2 = new Nodo2();
}

Arbol::~Arbol()
{
	if( raiz ){
		for(int i = 0; i < 1000; i++){
			if(raiz[i])
				delete raiz[i];
			else
				break;
		}
		delete [] raiz;
	}
}

void Arbol::crearPalabra(Palabra &palabra)
{
	int* indices = palabra.getIndices();
	const int largo = palabra.getLength();
	int caracterActual = 0;
	Nodo::crearCamino(raiz, indices, largo, caracterActual);
}

bool Arbol::verificarPalabra(Palabra &palabra) const
{
	int * indices = palabra.getIndices();
	const int largo = palabra.getLength();
	int caracterActual = 0;
	return Nodo::reconstruirCamino(raiz[indices[caracterActual]], indices, largo, caracterActual);
}

void Arbol::crearPalabra2(Palabra &palabra)
{
	int* indices = palabra.getIndices();
	const int largo = palabra.getLength();
	int caracterActual = 0;
	raiz2->crearCamino(*raiz2, indices, largo, caracterActual);
}

void Arbol::verificarPalabra2(Palabra &palabra)
{
	int * indices = palabra.getIndices();
	const int largo = palabra.getLength();
	int caracterActual = 0;
	raiz2->reconstruirCamino(*raiz2, indices, largo, caracterActual);
}
