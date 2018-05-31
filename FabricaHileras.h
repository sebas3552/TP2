#ifndef FABRICA_HILERAS
#define FABRICA_HILERAS
#include "Fabrica.h"
#include "Hilera.h"

class FabricaHileras : public Fabrica
{
	public:
		FabricaHileras()
		: Fabrica("elemento", "hilera")
		{
		}
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Elemento *>(new Hilera()));
		}
};
#endif