#include "Nodo.h"
#include <iostream>
#include <iomanip>
using namespace std;

Nodo::Nodo()
{
}

void Nodo::crearCamino(Nodo** raiz, int* indices, const int largo, int caracterActual)
{	
	if(caracterActual < largo){
		Nodo** siguiente = new Nodo*[SIZE];
		Nodo::init(siguiente);
		siguiente[indices[++caracterActual]] = new Nodo();
		raiz[indices[caracterActual-1]] = siguiente[indices[caracterActual]];
		recorrerCamino(raiz); //prueba la creacion de los vectores de punteros
		cout << "Nodo actual: " << raiz[indices[caracterActual-1]] << endl;
		crearCamino(siguiente, indices, largo, caracterActual);
	}
	else{
		raiz[SIZE-1] = new Nodo();	 //crea un nuevo nodo en la ultima posicion y
		raiz[SIZE-1] = raiz[SIZE-1]; //apunta a si mismo
		cout << "La palabra se agregó correctamente!" << endl;
		recorrerCamino(raiz);
	}
	
}

void Nodo::recorrerCamino(Nodo** raiz) const
{ 
	for(int i = 0; i < SIZE; i++){
		cout << "i = " << setw(2) << i << " -> " << raiz[i] << endl;
	}
}

void Nodo::reconstruirCamino(Nodo** raiz

void Nodo::init(Nodo** v)
{
	for(int i = 0; i < SIZE; i++)
		v[i] = nullptr;
}