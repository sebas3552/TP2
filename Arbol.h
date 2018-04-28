#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include "Palabra.h"
/**@class Arbol
* Esta clase solicita los servicios de la clase Nodo mediante su puntero a Nodo raiz,
* para agregar Palabras a la estructura de árbol de vectores de punteros a Nodo, y para 
* buscar Palabras mediante la comprobación del camino de punteros para una palabra determinada. 
*/
class Arbol{
	public:
		/**Constructor por omisión.*/
		Arbol();
		/**Destructor personalizado.*/
		~Arbol();
		/**Función para agregar Palabras al diccionario.
		* @param palabra Palabra que se va a agregar al diccionario.
		*/
		void agregar(Palabra &palabra);
		/**Función para determinar si una palabra está o no en el diccionario.
		* @param palabra Palabra que se va a buscar en el diccionario.
		* @return true si la Palabra existe en el diccionario, false en caso contrario.
		*/
		bool verificar(Palabra &palabra) const;
	private:
		/**Puntero a Nodo, que es la raíz del árbol en el que se alojan las palabras.*/
		Nodo* raiz; 
};
#endif
