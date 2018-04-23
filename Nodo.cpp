#include "Nodo.h"

Nodo::Nodo(){
	v = new Nodo[SIZE];
}

Nodo::~Nodo(){
	if( v ){
		delete [] v;
	}
}
