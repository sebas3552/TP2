#ifndef TEXTO_H
#define TEXTO_H
#include <fstream>
#include <string>
#include <locale>
#include "Diccionario.h"

class Texto{
	
	public:
		Texto( const char * );
		~Texto();
		void agregarPalabrasDiccionario( Diccionario & );
		
	private:
		std::fstream diccionario;
		int dimensionDiccionario;
		std::string nombreDiccionario;
		int cantidadPalabras();
		std::string* separarStrings();
		char * convertirMinusculas( std::string );
};
#endif