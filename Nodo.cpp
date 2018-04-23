#include "Nodo.h"

Nodo::Nodo(){
	tamaño = 34;
	Nodo v[tamaño];
}

Nodo::~Nodo(){
	if( v ){
		delete [] v;
	}
}
