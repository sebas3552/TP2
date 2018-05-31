#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "Fabrica.h"

class FabricaJSON : public Fabrica
{
	public:
		FabricaJSON()
		: Fabrica("visualizador", "Visualizador JSON")
		{
		}
		virtual Producto *producir()
		{
			return new Producto();
		}
};
#endif