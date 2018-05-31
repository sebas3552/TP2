#ifndef VECTOR_H
#define VECTOR_H
#include "Elemento.h"
/**@class Vector Clase para modelar objetos tipo Vector, cuya información se almacena en un vector del 
* tipo fundamental numérico double, para almacenar números reales. 
*/
class Vector : public Elemento
{
	public:
		/**Constructor por omisión. El contenido del vector se carga con
		* el operador sobrecargado de inserción de flujo desde Elemento.
		*/
		Vector();
		/**Constructor por copia.*/
		Vector(const Vector &);
		/**Destructor virtual.*/
		virtual ~Vector();
		/**Función para calcular la distancia entre vectores del mismo tamaño.
		* Note que, por definición algebráica, la distancia solo se puede calcular 
		* entre vectores del mismo tamaño.
		* @param Elemento Elemento cuya naturaleza subyacente es un vector, contra el
		* que se calculará la distancia entre el vector sobre el que se invoca la función.
		* @return la distancia como un número real, entendida como la norma del vector 
		* diferencia.
		*/
		virtual double distancia(Elemento *) override;
		/**Función para clonar un Vector.
		* @param Elemento Puntero al elemento (vector) que se quiere clonar.
		* @return Puntero a una copia del elemento que se ingresó como argumento.
		*/
		virtual Elemento *clonar() override;
		/**Función utilizada al cargar un vector, para determinar la cantidad de elementos.*/
		static int contarEspacios(const char *);
		/**Función para determinar el tamaño (cantidad de elementos) de un vector.
		* @return Largo del vector.
		*/
		int length() const;
		/** Vector de tipo fundamental double que almacena los valores del objeto Vector.*/
		double *vector;
	protected:
		virtual std::istream &cargar(std::istream &entrada) override;
		virtual std::ostream &imprimir(std::ostream &salida) override;
	private:
		/**Entero que guarda el largo del vector.*/
		int size;
		/**Constante para simbolizar el límite de elementos de un vector.*/
		const int LIMIT = 256;	
		/**Función utilizada por cargar para rellenar el vector double con los valores apropiados.*/
		void rellenar(double *, int, char *);
		/**Sobrecarga del operador - para restar un vector elemento por elemento.*/
		Vector &operator-(const Vector *);
		/**Determina la norma del vector, entendida como la raíz cuadrada de la suma de cada término al cuadrado.*/
		double norma(Vector &) const;		
};
#endif