#include "nodo2.h"
#include <iostream>
#include <iomanip>

using namespace std;

Nodo2::Nodo2()
{
	punteros = new Nodo2*[SIZE];
	init();
}

Nodo2::~Nodo2()
{
	if(punteros){
		for(int i = 0; i < SIZE; i++)
			delete punteros[i];
		delete [] punteros;
	}
}

void Nodo2::init()
{
	for(int i = 0; i < SIZE; i++)
		punteros[i] = nullptr;
}

void Nodo2::crearCamino(Nodo2 &raiz, int * indices, const int largo, int caracterActual)
{
	cout << "Caracter actual: " << caracterActual << endl;
	cout << "Indice: " << indices[caracterActual] << endl;
	if(caracterActual < largo-1){
		cout << "condicion? :" << boolalpha << !raiz.punteros[indices[caracterActual]] << endl;
		//if(!raiz.punteros[indices[caracterActual]]){
			Nodo2* nuevo = new Nodo2();
			nuevo->punteros[indices[++caracterActual]] = new Nodo2();
			raiz.punteros[indices[caracterActual-1]] = nuevo->punteros[indices[caracterActual]];
			recorrerCamino(raiz);
			crearCamino(*nuevo, indices, largo, caracterActual);
		/*}
		else{
			Nodo2 nuevo = *raiz.punteros[indices[caracterActual]];
			raiz.recorrerCamino(raiz);
			crearCamino(nuevo, indices, largo, ++caracterActual);
		}*/
	}
	else{
		Nodo2* ultimo = new Nodo2();
		raiz.punteros[SIZE-1] = ultimo;
		raiz.punteros[SIZE-1] = raiz.punteros[SIZE-1];
		raiz.recorrerCamino(raiz);
		cout << "La palabra ha sido creada!" << endl;
	}
}

void Nodo2::recorrerCamino(Nodo2 &raiz)
{ 
	for(int i = 0; i < SIZE; i++){
		cout << "i = " << setw(2) << i << " -> " << raiz.punteros[i] << endl;
	}
}

void Nodo2::reconstruirCamino(Nodo2 &raiz, int *indices, const int largo, int caracterActual)
{
	cout << "Direccion actual: " << raiz.punteros[indices[caracterActual]] << endl;
	if(raiz.punteros[indices[caracterActual]]){
		if(!raiz.punteros[SIZE-1] && caracterActual < largo-1){
			Nodo2 *siguiente = raiz.punteros[indices[caracterActual]];
			cout << "Direccion siguiente: " << siguiente << endl;
			reconstruirCamino(*siguiente, indices, largo, ++caracterActual);
		}
		else{
			cout << "la palabra existe!" << endl;
		}
		
	}else{
		cout << "la palabra no existe" << endl;
	}
}