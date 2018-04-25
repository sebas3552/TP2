#ifndef DICCIONARIO_H
#define DICCIONARIO_H
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
		Arbol * arbol; //-wno-multichar
		int * indices;
};
#endif