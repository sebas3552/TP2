#ifndef NODO_H
#define NODO_H
#include "Palabra.h"
#include <iostream>
class Nodo{
	public: 
		Nodo();
		static void crearCamino(Nodo**, int *, const int, int);
		static void recorrerCamino(Nodo**) const;
		static void reconstruirCamino() const;
		static const int SIZE = 27; //sin caracteres especiales
	private:
		static void init(Nodo** );
		
};
#endif
