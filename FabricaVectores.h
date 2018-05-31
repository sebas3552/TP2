#ifndef FABRICA_VECTORES
#define FABRICA_VECTORES
#include "Fabrica.h"
#include "Vector.h"

class FabricaVectores: public Fabrica
{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
			*/
		FabricaVectores()
		: Fabrica("elemento", "vector")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de Vector 
		* en un puntero a Elemento, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Elemento Vector.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Elemento *>(new Vector()));
		}
};
#endif