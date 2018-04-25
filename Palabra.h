#ifndef PALABRA_H
#define PALABRA_H
#include <string>
#include <iostream>
#include <fstream>

class Palabra
{
	friend std::ostream &operator<<(std::ostream &, Palabra &);
	
	public:
	
		Palabra();
		Palabra(const std::string &);
		Palabra(const char *);
		Palabra(Palabra &);
		~Palabra();
		bool operator==(const std::string &) const;
		bool operator==(const Palabra &) const;
		Palabra &operator=(Palabra &);
		Palabra &operator=(const std::string &);
		Palabra &operator=(const char *);
		Palabra &operator+=(const std::string &);
		Palabra &operator+=(const Palabra &);
		int getLength();
		int getLength(const std::string &) const;
		const char * getCaracteres();
		int * getIndices();
		int length;
	private:
	
		static const int SIZE = 27;
		std::string palabra;
		int * indices;
		const char caracteres[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '$'}; 
		int decodificar(char) const;
		
};
#endif