#ifndef ELEMENTO_PALABRA
#define ELEMENTO_PALABRA
#include "Elemento.h"
#include <string>
#include <vector>

class Palabra : public Elemento{
    private:
		std::string palabra;
		std::vector<std::string> bigramas;
	protected:
	   virtual ostream & imprimir(ostream &);
	   virtual istream & cargar(istream &);
	
	public:
	   Palabra();
	   virtual Elemento * clonar();	   
 	   virtual double distancia(Elemento *);
	   vector<string> bigramas();
	   int bigramasUnicos();
	   int bigramasComunes(Elemento *);
};
#endif