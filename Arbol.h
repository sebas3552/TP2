#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include "nodo2.h"
#include "Palabra.h"
class Arbol{
	public:
		Arbol();
		~Arbol();
		void crearPalabra(Palabra &);
		void crearPalabra2(Palabra &);
		bool verificarPalabra(Palabra &) const;
		void verificarPalabra2(Palabra &);
	private:
		Nodo** raiz; //puntero a un vector de punteros a Nodo
		Nodo2* raiz2; 
};
#endif
