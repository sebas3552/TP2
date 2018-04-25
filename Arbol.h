#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
class Arbol{
	public:
		Arbol();
		~Arbol();
		void crearPalabra(int *);
	private:
		Nodo* raiz;
};
#endif
