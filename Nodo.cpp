#include "Nodo.h"
#include <iostream>
using namespace std;

Nodo::Nodo()
: elemento(0)
{
}

Nodo::~Nodo(){
	if( siguiente ){
		delete [] siguiente;
	}
}

void Nodo::crearCamino(Nodo *raiz, int* indices, int largo, int nodoActual)
{	
	cout << raiz->elemento << endl;
	if(nodoActual == 0){
		raiz->elemento = indices[nodoActual];
		raiz[indices[nodoActual++]].siguiente = new Nodo[SIZE];
		crearCamino(raiz[indices[nodoActual-1]].siguiente, indices, largo, nodoActual);
	}
	else{
		if(nodoActual < largo){
			raiz[indices[nodoActual++]].siguiente = new Nodo[SIZE];
			raiz->elemento = indices[nodoActual];
			crearCamino(raiz[indices[nodoActual-1]].siguiente, indices, largo, nodoActual);
		}
		else{
			raiz[nodoActual].siguiente = raiz[nodoActual].siguiente; 
		}
	}
	
}