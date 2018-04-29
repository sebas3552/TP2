#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <string>
#include "Arbol.h"
/**@class Diccionario
* Mediante esta clase se modela un Diccionario de palabras, que será utilizado con el diccionario 
* del Español proporcionado para los efectos de esta tarea.
* El diccionario tiene un puntero a un Arbol que es la entidad que almacena las palabras en un Nodo 
* raíz, la cual a su vez es la que crea cada palabra mediante un camino de punteros entre vectores de 
* punteros a Nodo.
* Esta clase contiene las funciones sobrecargadas correspondientes para buscar y añadir palabras al 
* diccionario de manera sencilla y eficaz.
*/
class Diccionario
{
	public:
		/**Constructor por omisión.*/
		Diccionario();
		/**Destructor personalizado.*/
		~Diccionario();
		/**Operador [] sobrecargado, para buscar una Palabra en el diccionario mediante un string.
		* @param tira String con el que se busca una Palabra en el diccionario.
		* @return true si la Palabra está, false en caso contrario.
		*/
		bool operator[](std::string &tira) const;
		/**Operador [] sobrecargado, para buscar una Palabra directamente en el diccionario.
		* @param palabra Palabra a buscar en el diccionario.
		* @return true si la Palabra está, false en caso contrario.
		*/
		bool operator[](Palabra &palabra) const;
		/**Operador [] sobrecargado, para buscar una Palabra en el diccionario mediante una cadena de caracteres.
		* @param v Cadena de caracteres con la que se busca una Palabra en el diccionario.
		* @return true si la Palabra está, false en caso contrario.
		*/
		bool operator[](const char *v) const;
		/**Operador += sobrecargado para añadir palabras al diccionario.
		* @param tira Palabra que se desea añadir al diccionario, mediante un string.
		* @return El diccionario modificado, útil para invocar funciones en cascada.
		*/
		Diccionario& operator+=(std::string &tira); 
		/**Operador += sobrecargado para añadir palabras al diccionario.
		* @param palabra Palabra que se desea añadir directamente al diccionario.
		* @return El diccionario modificado, útil para invocar funciones en cascada.
		*/
		Diccionario& operator+=(Palabra &palabra);
		/**Operador += sobrecargado para añadir palabras al diccionario.
		* @param v Palabra que se desea añadir al diccionario, mediante una cadena de caracteres.
		* @return El diccionario modificado, útil para invocar funciones en cascada.
		*/
		Diccionario& operator+=(const char *v);
		/**Función utilitaria para imprimir el camino de vectores de punteros a Nodo a través del cual se forma una palabra, si existe en el diccionario.
		* @param palabra Palabra para la que se quiere imprimir el camino de punteros a Nodo.
		*/
		void imprimirCamino(Palabra &palabra) const;
	
	private:
		/**Puntero a un objeto Arbol, que a su vez tiene un Nodo.*/
		Arbol * arbol;
};
#endif