#ifndef NODO_H
#define NODO_H
/** @class Nodo 
* Se encarga de crear la estructura de palabras en forma de Nodos con vectores de punteros a Nodos.
* Al crear una palabra, se crea un nuevo Nodo en el vector de punteros a Nodos que tiene el Nodo raiz,
* en el subíndice especificado por el número correspondiente al primer caracter. Luego, se crea un nuevo 
* Nodo en cuyo vector de punteros a Nodos se crea otro nuevo Nodo en el subíndice especificado por el 
* número de caracter correspondiente a la siguiente letra de la palabra (si tiene más de una letra).
* Posteriormente, se enlaza el Nodo creado en el vector del Nodo raíz y el Nodo creado en el vector del 
* Nodo siguiente, mediante el puntero al siguiente que tiene el Nodo en el vector del Nodo raíz.
* Mientras no se haya llegado al final de la palabra, se toma al nuevo Nodo como raíz, y se invoca de 
* nuevo a la función con esa "raíz".
* Cuando se llega al penúltimo caracter de la palabra, se crea un nuevo Nodo cuyo puntero al siguiente es vacío, 
* con el Nodo correspondiente al último caracter de la palabra en el subíndice correspondiente del vector, y en 
* ese mismo vector se crea en el último espacio (33) un nuevo Nodo y se establece su puntero al siguiente a sí 
* mismo, para indicar el final de la palabra.
*/
class Nodo{
	public:
		/**Constructor por omisión.*/
		Nodo();
		/**Destructor personalizado.*/
		~Nodo();
		/**Función recursiva para crear el camino de vectores de punteros a Nodo según 
		* la posición de cada caracter.
		* @param raiz Nodo raiz que se toma por referencia.
		* @param indices Vector de índices que corresponden a cada caracter de la palabra.
		* @param largo Largo del vector de índices.
		* @param caracterActual Número de caracter por el que se va creando el camino de vectores de punteros.
		*/
		void crearCamino(Nodo &raiz, int *indices, const int largo, int caracterActual);
		/**Función recursiva para tratar de recorrer el camino de vectores de punteros, para determinar si una palabra existe.
		* @param raiz Nodo raiz que se toma por referencia.
		* @param indices Vector de índices que corresponden a cada caracter de la palabra.
		* @param largo Largo del vector de índices.
		* @param caracterActual Número de caracter por el que se va creando el camino de vectores de punteros.
		* @return true si la palabra existe, falso en caso contrario.
		*/
		bool recorrerCamino(Nodo&raiz, int*indices, const int largo, int caracterActual) const;
		/**Tamaño de los vectores de punteros.*/
		static const int SIZE = 34;
		
	private:
		/**Puntero a un vector de punteros a Nodos.*/
		Nodo** vector;
		/**Puntero al Nodo siguiente, para poder enlazar los vectores.*/
		Nodo* siguiente;
		/**Entero que almacena el subíndice del vector donde se encuentra, para efectos de comprobación de palabra.*/
		int indice;
};
#endif
