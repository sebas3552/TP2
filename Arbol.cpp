#include "Arbol.h"

Arbol::Arbol(){
	ptrNodo = new Nodo();
}

Arbol::~Arbol(){
	if( ptrNodo ){
		delete ptrNodo;
	}
}
