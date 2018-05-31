#include "Lista.h"
#include "Elemento.h"

using namespace std;
// CELDA
// En la lista al agregar elementos son clonados... Hay que destruirlos
Lista::Celda::Celda( Elemento * elemento){
	if(elemento!=0){
  	   this->elemento = elemento->clonar();
	}
	else {
	   this->elemento = 0;
	}
}


Lista::Celda::~Celda(){ 
// SOLO DESTRUYE EL ELEMENTO DE LA CELDA
	delete elemento;
}			


ostream & Lista::imprimir(ostream & salida){

	if(primera!=0){
	   salida << "{ ";	
  	   Iterator elFinal = this->end();
	   Lista::Iterator i = this->begin();
	   salida << *i;
	   ++i;
	   while(i != elFinal){
		   salida << " , "<< *i;
		   ++i;
	   }
	   salida << " }";
	}
	else {
	   salida << "LISTA_VACIA";	
	}
	return salida;
}

istream & Lista::cargar(istream & entrada){
	if(primera!=0){
  	   Lista::Iterator elFinal = this->end();
	   for(Lista::Iterator i = this->begin() ; i != elFinal ; ++i){
		   entrada >> *i;
	   }
	}
	return entrada;	
}

Lista::Iterator::Iterator(){
	actual = 0;
}		      

Lista::Iterator::Iterator( Celda * actual)
: actual(0)
{
	this->actual = actual;	
}

Elemento * Lista::Iterator::operator*(){
   Elemento * resp = 0;
   if(actual!=0){
	   resp = actual->elemento;
   }   
   return resp;			  
}
          
Lista::Iterator & Lista::Iterator::operator++(){
	if(actual!=0){
  	   actual =  actual->siguiente;
	}
	return *this;
}

Lista::Iterator &Lista::Iterator::operator--(){
	if(actual!=0){
  	   actual =  actual->anterior;
	}
	return *this;
}

Lista::Iterator Lista::Iterator::operator++(int noSeUsa){
   Iterator copia(actual);
   ++(*this);
   return copia;
}
			  
Lista::Iterator Lista::Iterator::operator--(int noSeUsa){
   Iterator copia(actual);
   --(*this);
   return copia;	
}

int Lista::Iterator::operator==(const Iterator & otro){
	return this->actual == otro.actual;
}

Lista::Iterator Lista::begin(){

   Lista::Iterator elPrimero( primera );
   return elPrimero;
}
	   
Lista::Iterator Lista::end(){
   Lista::Iterator elFinal; // El final es una posición después del último que siempre es nula
   return elFinal;
}

Lista::Lista(){
   primera = 0;
   ultima = 0;   
}


Lista::Lista( Elemento * elemento, istream &entrada, int n)
: primera(0), ultima(0)
{
   for(int i=0; i<n; ++i){
      entrada >> elemento;
	  (*this)+= elemento;
   }
} // Carga elementos desde el flujo y rellena la lista

void  Lista::destruir(){
		Celda * actual;
		Celda * victima;
		for( actual = primera; actual!=0; actual=actual->siguiente){
			victima = actual->anterior;
			if(victima!=0){
				delete victima;
			}
		} 
		if(ultima!=0){
			delete ultima;
		}
		primera=0;
		ultima=0;
}
Lista & Lista::operator=( Elemento & otra){
	Lista * lista2 = dynamic_cast< Lista * >( &otra );
    if(lista2!=0){
		this->destruir();
        Iterator elFinal = lista2->end();
		for(Iterator i = lista2->begin(); i!=elFinal; ++i){
			*this += (*i);
		} 
	}
	return *this;
}

Lista::~Lista(){
   destruir();
}

Lista * Lista::clonar(){
   Lista * nueva = new Lista();
   *nueva = *this;
   return nueva;
}	   

double Lista::distancia(Elemento *){
  // :)   Don't worry be happy...
}

Lista & Lista::operator+=(Elemento *elemento){
	Celda *nueva = new Celda(elemento);
	if(!primera){
		primera = ultima = nueva;
		primera->anterior = 0;
		primera->siguiente = 0;
	}else{
		ultima->siguiente = nueva;
		nueva->anterior = ultima;
		nueva->siguiente = 0;
		ultima = nueva;
	}
}  // Es un push_back que agrega al final de la lista 
	   
Lista & Lista::insertar(Lista::Iterator& i, Elemento * elemento){

} // inserta una copia del elemento
	   
	   
Lista & Lista::borrar(Lista::Iterator&){
	
}

Lista & Lista::push_front(Elemento *){

}

Elemento * Lista::pop_front(){
	
}

Elemento * Lista::pop_back(){
	
} // Retorna el último 	   
