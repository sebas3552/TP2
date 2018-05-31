#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "Fabrica.h"
#include "Palabra.h"

class FabricaPalabras : public Fabrica
{
	public:
		FabricaPalabras()
		: Fabrica("elemento", "Palabra")
		{
		}
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Elemento *>(new Palabra()));
		}
};
#endif