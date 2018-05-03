#ifndef TEXTO_H
#define TEXTO_H
#include <fstream>
#include <string>
#include <locale>
#include <vector>
#include "Palabra.h"
#include "Diccionario.h"

/** Esta clase se encarga de obtener los archivos de texto que se utilizarán como diccionario y como comentarios de opinión para dividir (hashtags).
* Asímismo, cuenta con algunas funciones privadas para cargar las palabras del archivo de texto del diccionario en la estructura de árbol de un 
* objeto Diccionario. También, divide las palabras en los comentarios de opinión y genera nuevos archivos de texto con los comentarios separados.
*/
class Texto{
	
	public:
		/**Constructor por omisión.*/
		Texto();
		/**Destructor personalizado.*/
		~Texto();
		/**Función que toma un Diccionario por referencia y le carga las palabras del diccionario.txt.
		*@param nombreDiccionario String con el nombre del archivo de texto que contiene el diccionario.
		*@param diccionario Diccionario que se pasa por referencia para ser llenado con las palabras del archivo de texto.
		*@return el Diccionario que se pasó como argumento, con las palabras del archivo de texto incorporadas en su estructura de árbol.
		*/
		Diccionario &cargarDiccionario(std::string nombreDiccionario, Diccionario &diccionario);
		void metodoDivision( std::string nombreArchivo );
		/**Función que divide un hashtag por espacios.
		*@param s String al que se dividirá por espacios.
		*@return Un string con el hashtag que se recibió como parámetro, y además, todas sus divisiones correspondientes.
		*/
		std::string divPorEspacios( std::string s );
		/**Función que informa de la presencia de un caracter en el vector de caracteres brindado en el enunciado.
		*@param c Char que se buscará en el vector de caracteres.
		*@return true si no está, false en caso contrario.
		*/
		bool esRaro( char c );
		
	private:
		/**Función utilitaria que convierte a minúsculas el string que recibe como argumento, para evitar conflictos en la clase Palabra.
		*@param aConvertir String que será convertido a letras minúsculas, si las tiene.
		*@return Cadena de caracteres con el valor del String que recibe como parámetro pero compuesto únicamente de letras minúsculas.
		*/
		char * convertirMinusculas(std::string aConvertir);
};
#endif
