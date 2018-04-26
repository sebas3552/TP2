#include "Nodo.h"
#include <iostream>
#include <iomanip>
using namespace std;

Nodo::Nodo()
{
}

void Nodo::crearCamino(Nodo** raiz, int* indices, const int largo, int caracterActual)
{	
	cout << "Caracteractual: " << caracterActual << endl;
	cout << "indices[i]: " << indices[caracterActual] << endl;
	if(caracterActual < largo-1){
		Nodo** siguiente = new Nodo*[SIZE];		//crea un nuevo vector de punteros 
		Nodo::init(siguiente);					//elimina la basura
		siguiente[indices[++caracterActual]] = new Nodo();	//crea un nodo en la posición del caracter correspondiente del nuevo vector
		raiz[indices[caracterActual-1]] = siguiente[indices[caracterActual]];  //establece el puntero del vector anterior hacia el nuevo
		recorrerCamino(raiz); //prueba la creacion de los vectores de punteros
		cout << "Nodo actual: " << raiz[indices[caracterActual-1]] << endl;
		crearCamino(siguiente, indices, largo, caracterActual);	//repite el proceso con el nuevo vector como raiz hasta que se alcance el final de la palabra
	}
	else{
		cout << "Raiz ultimo: " << raiz[SIZE-1] << endl;
		raiz[SIZE-1] = new Nodo();	 //crea un nuevo nodo en la ultima posicion y
		raiz[SIZE-1] = raiz[SIZE-1]; //apunta a si mismo	
		recorrerCamino(raiz);
		cout << "La palabra se agrego correctamente!" << endl;
	}
	
}

void Nodo::recorrerCamino(Nodo** raiz)
{ 
	for(int i = 0; i < SIZE; i++){
		cout << "i = " << setw(2) << i << " -> " << raiz[i] << endl;
	}
}

void Nodo::reconstruirCamino(Nodo** raiz, int * indices, const int largo, int caracterActual)
{	//NO FUNCIONA
	cout << "caracterActual: " << caracterActual << endl;
	cout << "condicion?: " << boolalpha << raiz[SIZE-1] << endl;
	if(raiz[indices[caracterActual]]){
		if(!raiz[SIZE-1] && caracterActual < largo-1){
			Nodo** siguiente = new Nodo*[SIZE];
			init(siguiente);
			siguiente[indices[++caracterActual]] = raiz[indices[caracterActual-1]];
			cout << "Nodo actual: " << siguiente[indices[caracterActual]] << endl;
			reconstruirCamino(siguiente, indices, largo, caracterActual);
		}else{
			cout << "La palabra existe!" << endl;
		}
	}else{
		cout << "La palabra no existe!" << endl;
	}
}

void Nodo::init(Nodo** v)
{
	for(int i = 0; i < SIZE; i++)
		v[i] = nullptr;
}