#include "Arbol.h"
#define SIZE 27

Arbol::Arbol()
:raiz(nullptr)
{
}

Arbol::~Arbol(){
	if( raiz ){
		delete raiz;
	}
}

void Arbol::crearPalabra(int *vectorIndices)
{
	raiz = new Nodo [SIZE];
}
