#ifndef DICCIONARIO
#define DICCIONARIO
#include <string>
#include <fstream>
#include "Arbol.h"
class Diccionario
{

	 
	friend std::string operator+=(std::string &, Diccionario &);
	public:
		Diccionario();
		Diccionario(std::fstream &);
		~Diccionario();
		std::string operator[](std::string &);
		void buscar(std::string &);
	
	private:
		static const int SIZE = 27;
		const char caracteres[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
					    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '$'};
		Arbol * arbol;
		
		int getIndice(char) const;
		int * indices;
		std::string decodificar(int *) const;
};
#endif