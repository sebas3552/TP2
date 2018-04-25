#ifndef NODO_H
#define NODO_H
#include "Palabra.h"
#include <iostream>
class Nodo{
	public:
		Nodo();
		~Nodo();
		void crearCamino(Nodo *, int *, int, int);
		void imprimirCamino(Nodo &);
		
	private:
		static const int SIZE = 27;
		//Nodo* nodosPtr; //puntero a vector de punteros a nodos
		Nodo* siguiente;
		int elemento;
};
#endif
