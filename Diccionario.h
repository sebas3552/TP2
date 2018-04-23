#ifndef DICCIONARIO
#define DICCIONARIO
#include <string>
class Diccionario
{

	public:
		Diccionario();
		Diccionario(std::fstream &);
		~Diccionario();
		
	
	private:
		const char caracteres[33] = {};
	
};
#endif