#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <string>
#include <fstream>
#include "Arbol.h"
class Diccionario
{

	 
	friend std::string operator+=(std::string &, Diccionario &); //agregar palabras
	friend std::string operator+=(Palabra &, Diccionario &);
	public:
		Diccionario();
		Diccionario(std::fstream &);
		~Diccionario();
		std::string operator[](std::string &); //buscar palabras
		std::string operator[](Palabra &);
	
	private:
		Arbol * arbol; //-wno-multichar
		int * indices;
};
#endif