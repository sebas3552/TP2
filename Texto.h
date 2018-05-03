#ifndef TEXTO_H
#define TEXTO_H
#include <fstream>
#include <string>
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
		/**Función que toma un Diccionario por referencia y le carga las palabras del diccionario.txt.
		*@param nombreDiccionario String con el nombre del archivo de texto que contiene el diccionario.
		*@param diccionario Diccionario que se pasa por referencia para ser llenado con las palabras del archivo de texto.
		*@return el Diccionario que se pasó como argumento, con las palabras del archivo de texto incorporadas en su estructura de árbol.
		*/
		Diccionario &cargarDiccionario(std::string nombreDiccionario, Diccionario &diccionario);
		/**Función primaria de todo el programa, la cual consiste en decidir el modo en el que dividirá los comentarios, y en seguida 
		* crea un nuevo archivo con los comentarios separados, según el diccionario y los comentarios que se le hayan proporcionado.
		* @param nombreArchivo Nombre o ruta del archivo donde se encuentran los comentarios de opinión a separar.
		* @param diccionario Diccionario cargado necesario para buscar las palabras existentes y dividirlas bajo ese criterio, cuando la situación lo amerite.
		*/
		void separar( std::string nombreArchivo, Diccionario &diccionario );
		
	private:
		/**Función utilitaria que convierte a minúsculas el string que recibe como argumento, para evitar conflictos en la clase Palabra.
		*@param aConvertir String que será convertido a letras minúsculas, si las tiene.
		*@return Cadena de caracteres con el valor del String que recibe como parámetro pero compuesto únicamente de letras minúsculas.
		*/
		char * convertirMinusculas(std::string aConvertir);
		/**Función que divide los comentarios basándose en la aparición de "tokens" que no corresponden a caracteres admitidos en un comentario.
		*@param aDividir String individual que se pasa para que la función realice su respectiva separación.
		*@return El string que ingresó como argumento separado por los tokens que se hayan encontrado.
		*/
		std::string divPorRaros(std::string &aDividir);
		/**Función que divide los comentarios basándose en la existencia de palabras en el diccionario, para lo cual crea Strings caracter por caracter que simultáneamente 
		* busca en el diccionario, hasta que encuentra alguna palabra que efectivamente existe, y la separa como tal, repitiendo el proceso hasta acabar con el string.
		*@param s String que representa el comentario a dividir.
		*@param d Diccionario por referencia para que la función pueda consultar las palabras existentes.
		*@return El string que ingresó como argumento separado según las palabras válidas que lo conformen.
		*/
		std::string divPorDiccionario(std::string &s, const Diccionario &d);
		/**Función que divide un hashtag por espacios.
		*@param s String al que se dividirá por espacios.
		*@return Un string con el hashtag que se recibió como parámetro, y además, todas sus divisiones correspondientes.
		*/
		std::string divPorEspacios(std::string& aDividir);
		/**Función que informa de la presencia de un caracter en el vector de caracteres brindado en el enunciado.
		*@param c Char que se buscará en el vector de caracteres.
		*@return true si no está, false en caso contrario.
		*/
		bool esRaro( char c );
};
#endif