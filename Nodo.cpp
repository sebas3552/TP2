#include "Nodo.h"
#include <iostream>
#include <iomanip>
using namespace std;

Nodo::Nodo()
: siguiente(nullptr), indice(0)
{
}

void Nodo::crearCamino(Nodo** raiz, int* indices, const int largo, int caracterActual)
{	
	cout << "Caracteractual: " << caracterActual << endl;
	cout << "indices[i]: " << indices[caracterActual] << endl;
	if(caracterActual < largo-1){
		if(!raiz[indices[caracterActual]]){
			raiz[indices[caracterActual]] = new Nodo();
			raiz[indices[caracterActual]]->indice = indices[caracterActual];
		}
		if(!raiz[indices[caracterActual]->siguiente]){
			Nodo** siguiente = new Nodo*[SIZE];	
			Nodo::init(siguiente);	
		}
		siguiente[indices[++caracterActual]] = new Nodo();
		raiz[indices[caracterActual-1]]->siguiente = siguiente[indices[caracterActual]]; 
		siguiente[indices[caracterActual]]->indice = indices[caracterActual];
		recorrerCamino(raiz);
		cout << "Nodo actual: " << siguiente[indices[caracterActual]] << endl;
		crearCamino(siguiente, indices, largo, caracterActual);
	}
	else{
		raiz[indices[caracterActual]]->indice = indices[caracterActual];
		raiz[SIZE-1] = new Nodo();	 //crea un nuevo nodo en la ultima posicion y
		raiz[SIZE-1]->siguiente = raiz[SIZE-1]; //apunta a si mismo	
		raiz[SIZE-1]->indice = SIZE-1;
		recorrerCamino(raiz);
		cout << "La palabra se agrego correctamente!" << endl;
	}
	
}

void Nodo::recorrerCamino(Nodo** raiz)
{ 
	for(int i = 0; i < SIZE; i++){
		cout << "i = " << setw(2) << i << " -> " << (raiz[i]? raiz[i]->siguiente : 0) << endl;
	}
}

bool Nodo::reconstruirCamino(Nodo* primero, int* indices, const int largo, int caracterActual)
{	
	//cout << caracterActual << endl;
	//cout << "indices caracterActual: " << indices[caracterActual] << endl;
	if(primero && primero->indice == indices[caracterActual] && caracterActual < largo && primero->siguiente){
		Nodo* siguiente = primero->siguiente;
		//cout << "Mi indice: " << primero->indice << endl;
		//cout << "Yo le apunto a: " << primero->siguiente << endl;
		reconstruirCamino(siguiente, indices, largo, ++caracterActual);
	}else{
		return (caracterActual == largo-1 && primero->indice == indices[caracterActual]? true : false );
	}
}

void Nodo::init(Nodo** v)
{
	for(int i = 0; i < SIZE; i++)
		v[i] = nullptr;
}