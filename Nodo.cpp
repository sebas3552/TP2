#include "Nodo.h"

Nodo::Nodo(){
	size = 27;
	Nodo * v[size];
}

Nodo::~Nodo(){
	if( v ){
		delete [] v;
	}
}
