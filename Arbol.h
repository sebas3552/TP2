#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include "Palabra.h"
class Arbol{
	public:
		Arbol();
		~Arbol();
		void crearPalabra(Palabra &);
	private:
		Nodo** raiz; //puntero a un vector de punteros a Nodo
};
#endif
