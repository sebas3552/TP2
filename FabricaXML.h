#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "Fabrica.h"

class FabricaXML : public Fabrica
{
	public:
		FabricaXML()
		: Fabrica("visualizador", "Visualizador XML")
		{
		}
		virtual Producto *producir()
		{
			return new Producto();
		}
};
#endif