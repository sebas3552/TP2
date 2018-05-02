#ifndef PALABRA_H
#define PALABRA_H
#include <string>
/**@class Palabra 
* Se encarga de la creación, concatenación, comparación de igualdad y otras utilidades que debe 
* tener una Palabra para estos efectos.
*/
class Palabra
{
	/**Función friend sobrecargada para imprimir una Palabra.*/
	friend std::ostream &operator<<(std::ostream &, Palabra &);
	
	public:
		/**Constructor por omisión. Crea una palabra vacía.*/
		Palabra();
		/**Constructor que recibe como parámetro un string, para almacenarlo dentro de la Palabra.
		* @param tira String con el que se inicializa la Palabra.
		*/
		Palabra(const std::string &tira);
		/**Constructor que recibe como parámetro una cadena de caracteres.
		* @param v Vector de caracteres con el que se inicializa la Palabra.
		*/
		Palabra(const char *v);
		/**Constructor de copia para Palabra. Necesario porque una Palabra tiene punteros a objetos almacenados en memoria.
		* @param otra Palabra a copiar.
		*/
		Palabra(Palabra &otra);
		/**Destructor personalizado.*/
		~Palabra();
		/**Operador == sobrecargado, para comparar una Palabra con un string.
		* @param tira String con el que se va a comparar la Palabra.
		* @return true si son iguales, false en caso contrario.
		*/
		bool operator==(const std::string &tira) const;
		/**Operador == sobrecargado, para comparar una Palabra con otra Palabra.
		* @param otra Palabra con la que se va a comparar la otra Palabra.
		* @return true si son iguales, false en caso contrario.
		*/
		bool operator==(const Palabra &otra) const;
		/**Operador == sobrecargado, para comparar una Palabra con una cadena de caracteres.
		* @param v Cadena de caracteres con la que se va a comparar la Palabra.
		* @return true si son iguales, false en caso contrario.
		*/
		bool operator==(const char *v) const;
		/** Operador = sobrecargado, para asignar una Palabra a otra Palabra.
		* @param otra Otra Palabra que se asigna a la Palabra.
		* @return la misma Palabra modificada.
		*/
		Palabra &operator=(Palabra &otra);
		/** Operador = sobrecargado, para asignar un string a una Palabra.
		* @param tira String que se asigna a la Palabra.
		* @return la misma Palabra modificada.
		*/
		Palabra &operator=(const std::string &tira);
		/** Operador = sobrecargado, para asignar una cadena de caracteres a una Palabra.
		* @param v Cadena de caracteres que se asigna a la Palabra.
		* @return la misma Palabra modificada.
		*/
		Palabra &operator=(const char *v);
		/** Operador += sobrecargado, para concatenar un string a una Palabra.
		* @param tira String que se concatena a la Palabra.
		* @return la misma Palabra modificada.
		*/
		Palabra &operator+=(const std::string &tira);
		/** Operador += sobrecargado, para concatenar una Palabra a otra Palabra.
		* @param otra Otra Palabra que se concatena a la Palabra.
		* @return la misma Palabra modificada.
		*/
		Palabra &operator+=(const Palabra &otra);
		/** Operador += sobrecargado, para concatenar una cadena de caracteres a una Palabra.
		* @param v Cadena de caracteres que se concatena a la Palabra.
		* @return la misma Palabra modificada.
		*/
		Palabra &operator+=(const char *v);
		/**
		* Función utilitaria que cuenta los caracteres de un string cualquiera.
		* @param tira String a la que se contarán los caracteres.
		* @return Cantidad de caracteres del string (largo).
		*/
		int getLength(const std::string &tira) const;
		/**Vector de índices, según el número correspondiente a cada caracter.*/
		int * indices;
		/**Largo de la Palabra.*/
		int length;
		
	private:
		/**Constante que representa el largo del vector de caracteres.*/
		static const int SIZE = 34;
		/**String que representa el contenido de la Palabra.*/
		std::string palabra;
		/**Vector constante de caracteres, según lo especificado en el enunciado.*/
		const char caracteres[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z', (char) 160, (char) 130, (char) 161, (char) 162, (char) 163, (char) 129, (char) 164, '$'}; 
		/**Función que devuelve el número asociado al caracter que recibe como parámetro.*/
		int decodificar(char c) const;	
		/** Función utilitaria que cuenta los caracteres de la Palabra sobre la que se invoca.
		* @return Cantidad de caracteres de la Palabra (largo). 
		*/
		int getLength();
		/**	Función que crea un vector con tantas celdas como caracteres tenga la Palabra, 
		* que contiene los índices de los caracteres según el número que corresponde a cada 
		* caracter, de acuerdo con la ilustración del enunciado.
		* @return Puntero a un vector de indices, útil para trazar el camino de los vectores de punteros.
		*/
		void getIndices();
		/**Función utilitaria que analiza cada Palabra en búsqueda de caracteres especiales (tildes, ñ,û) para contabilizarlos.
		* @param v Cadena de caracteres a la que cuenta las incidencias de caracteres especiales.
		* @return Cantidad de caracteres especiales encontrados en la cadena de caracteres, o cero si no encontró ninguno.
		*/
		int caracteresEspeciales(const char *v) const;
		/** Función que traduce manualmente cada caracter especial a su respectivo código de ASCII, para que la función decodificar pueda interpretarlos correctamente.
		*@param c Número que identifica el caracter especial sin "traducir".
		*@return El número que ingresó como argumento convertido a su respectivo código en ASCII.
		*/
		char determinarCaracter(int c) const;
		
};
#endif