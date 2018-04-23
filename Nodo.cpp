#include "Nodo.h"

Nodo::Nodo(){
	size = 34;
	Nodo * v[size];
}

Nodo::~Nodo(){
	if( v ){
		delete [] v;
	}
}
