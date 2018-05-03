#include "Nodo.h"
#include <iostream>
#include <iomanip>
using namespace std;

Nodo::Nodo()
: siguiente(nullptr), indice(0)
{
	vector = new Nodo*[SIZE];
	for(int i = 0; i < SIZE; i++)
		vector[i] = nullptr;
}

Nodo::~Nodo()
{
	if(siguiente)
		delete siguiente;
	if(vector){
		for(int i = 0; i < SIZE-1; i++){
			if(vector[i])
				delete vector[i];
		}
		delete [] vector;
	}
}

void Nodo::crearCamino(Nodo &raiz, int* indices, const int largo, int caracterActual)
{	try{
		if(caracterActual < largo-1){
			if(!raiz.vector[indices[caracterActual]]){ //el Nodo raiz tiene un vector que adentro tiene nodos
				raiz.vector[indices[caracterActual]] = new Nodo();	//si no existe el nodo dentro del vector, creo uno
				raiz.vector[indices[caracterActual]]->indice = indices[caracterActual];	//le asigno el indice correspondiente
			}
			Nodo* siguiente;
			/* Si el nodo en el vector del Nodo raiz no apunta a un siguiente, hago un nuevo Nodo siguiente y 
			* creo un nuevo Nodo en el vector del Nodo nuevo en el subindice especificado por el índice del caracter.
			* Luego, el nodo dentro del Nodo raiz apunta ahora al nuevo nodo que acabo de crear dentro del siguiente.
			* Ahora tomo al Nodo siguiente como la nueva raíz para dar el paso recursivo, mientras el indice del 
			* caracter actual sea menor que el largo de la palabra -1, para crear al final el nodo que apunta a sí mismo.
			*/
			if(!raiz.vector[indices[caracterActual]]->siguiente){ 
				siguiente = new Nodo();	
				siguiente->vector[indices[++caracterActual]] = new Nodo();	
				raiz.vector[indices[caracterActual-1]]->siguiente = siguiente->vector[indices[caracterActual]]; 
				raiz.vector[indices[caracterActual-1]]->siguiente->indice = indices[caracterActual]; 
				crearCamino(*raiz.vector[indices[caracterActual-1]]->siguiente, indices, largo, caracterActual);
			}
			else{
			/* Si el nodo en el vector del Nodo raiz ya apunta a un siguiente (ya existe otra palabra en ese camino),
			* tomo ese Nodo al que apunta como el nuevo Nodo raíz para dar el paso recursivo cuantas veces sea 
			* necesario, hasta que el nodo dentro del vector en el campo especificado no apunte a un siguiente.
			* Si la palabra que se está creando forma parte de otra palabra, en donde termine la palabra más 
			* pequeña se agrega el nodo de confirmación de fin de palabra, es decir, el puntero en la posición de $, 
			* con lo que se sabe que ahí existe una palabra, aunque esté dentro del camino de otra.
			*/
				siguiente = raiz.vector[indices[caracterActual]]->siguiente; 
				crearCamino(*siguiente, indices, largo, ++caracterActual);
			}
		}
		else{
			if(!raiz.vector[indices[caracterActual]])
				raiz.vector[indices[caracterActual]] = new Nodo();
			raiz.vector[indices[caracterActual]]->indice = indices[caracterActual];
			raiz.vector[SIZE-1] = new Nodo();	 //crea un nuevo nodo en la ultima posicion y
			raiz.vector[SIZE-1]->siguiente = raiz.vector[SIZE-1]; //apunta a si mismo	
			raiz.vector[SIZE-1]->indice = SIZE-1;
		}
    }catch(bad_alloc &e){
		throw e;
	}
}

bool Nodo::recorrerCamino(Nodo& primero, int* indices, const int largo, int caracterActual, int verCamino) const
{	
	if(primero.vector[indices[caracterActual]] && primero.vector[indices[caracterActual]]->siguiente && primero.vector[indices[caracterActual]]->indice == indices[caracterActual] && caracterActual < largo){
		if(primero.vector[SIZE-1] && caracterActual == largo-1 && primero.vector[indices[caracterActual]]->indice == indices[caracterActual]){ //si la palabra forma parte de otra palabra
			if(verCamino)
				expandirCamino(primero, indices, caracterActual);
			return true;
		}else{	//sino, sigue recorriendo el camino
			Nodo* siguiente = primero.vector[indices[caracterActual]]->siguiente;
			if(verCamino)
				expandirCamino(primero, indices, caracterActual);
			recorrerCamino(*siguiente, indices, largo, ++caracterActual, verCamino);
		}
	}else{
		/*Para confirmar que el camino recorrido es el de la palabra que se está buscando, se debe cumplir que: 
		* El número de caracter actual sea el del último caracter de la palabra.
		* Que exista el nodo en el vector en la posición correspondiente a su caracter.
		* Que exista el nodo que apunta a sí mismo en la última posición del vector de punteros a nodos ($).
		* Que el índice (número de caracter) del nodo sea igual al último caracter de la palabra que se está buscando.
		*/
		if(verCamino)
			expandirCamino(primero, indices, caracterActual);
		return (caracterActual == largo-1 && primero.vector[indices[caracterActual]] && primero.vector[SIZE-1] && primero.vector[indices[caracterActual]]->indice == indices[caracterActual]? true : false );
	}
}

void Nodo::expandirCamino(Nodo &nodo, int * indices, int caracterActual) const
{
	cout << endl;
	char caracter;
	for(int i = 0; i < SIZE; i++){
		/*Si existe un nodo*/
		if(nodo.vector[i]){
		/*Si el nodo es parte de la palabra que estoy buscando*/
		caracter = (nodo.vector[i]->indice == indices[caracterActual]? 'X' : 'x');
		cout << setw(2) << i << " -> " << caracter << endl;
		}else{
			caracter = 'o';
			cout << setw(2) << i << " -> " << caracter << endl;
		}
	}
	cout << endl;
}
