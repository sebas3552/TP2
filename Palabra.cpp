#include <string>
#include "Palabra.h"

using namespace std;

ostream &operator<<(ostream &salida, Palabra &tira)
{
	salida << tira.palabra;
	return salida;
}

Palabra::Palabra()
: palabra(""), length(0), indices(nullptr)
{
}

Palabra::Palabra(const string &tira)
: palabra(tira), indices(nullptr)
{
	length = getLength(tira);
}

Palabra::Palabra(const char *v)
: indices(nullptr)
{
	palabra = v;
	length = getLength();
}

Palabra::Palabra(Palabra &otra)
{
	palabra = otra.palabra;
	length = otra.length;
	if(otra.indices){
		indices = new int[length];
		for(int i = 0; i < length; i++){
			indices[i] = otra.indices[i];
		}
	}
}

Palabra::~Palabra()
{
	if(indices)
		delete [] indices;
}

bool Palabra::operator==(const string &tira) const
{
	return palabra == tira;
}

bool Palabra::operator==(const Palabra &otra) const
{
	return palabra == otra.palabra;
}

bool Palabra::operator==(const char *v) const
{
	string tira = v;
	return palabra == tira;
}

Palabra &Palabra::operator=(Palabra &otra)
{
	palabra = otra.palabra;
	length = otra.length;
	return *this;
}

Palabra &Palabra::operator=(const string &tira)
{
	palabra = tira;
	length += getLength(tira);
	return *this;
}

Palabra &Palabra::operator=(const char *v)
{
	palabra = v;
	length = getLength();
	return *this;
}

Palabra &Palabra::operator+=(const string &tira)
{
	palabra += tira;
	length += getLength(tira);
}

Palabra &Palabra::operator+=(const Palabra &otra)
{
	palabra += otra.palabra;
	length += otra.length;
}

Palabra &Palabra::operator+=(const char *v)
{
	string tira = v;
	palabra += tira;
}

int Palabra::getLength()
{
	const char *v = palabra.c_str();
	int i = 0;
	while(v[i]){
		i++;
	}
	return i;
}

int Palabra::getLength(const string &tira)const
{
	const char *v = tira.c_str();
	int i = 0;
	while(v[i])
		i++;
	return i;
}


int Palabra::decodificar(char c) const
{
	int indice = 0;
	for(indice; indice < SIZE; indice++){
		if(caracteres[indice] == c)
			return (indice <= SIZE? indice : -1);
		}
}

int * Palabra::getIndices()
{
	if(indices)
		delete[] indices;
	indices = new int[length]();
	const char * tira = palabra.c_str();
	for(int i = 0; i < length; i++){
		indices[i] = decodificar(tira[i]);
	}
	return indices;
}
