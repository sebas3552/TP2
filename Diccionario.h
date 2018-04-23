#ifndef DICCIONARIO
#define DICCIONARIO
#include <string>
#include "Arbol.h"
class Diccionario
{

	public:
		Diccionario();
		Diccionario(std::fstream &);
		~Diccionario();
		
	
	private:
		const char caracteres[33] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r',
					    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'á', 'é', 'í', 'ó', 'ú', 'ü', 'ñ', '$'};
	
};
#endif
