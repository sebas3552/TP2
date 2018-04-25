#include "Arbol.h"
#include <iostream>
Arbol::Arbol()
{
	raiz = new Nodo*[Nodo::SIZE];
	for(int i = 0; i < Nodo::SIZE-1; i++)
		raiz[i] = nullptr;
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
