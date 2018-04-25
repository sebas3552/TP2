#include <string>
#include <iostream>
#include "Palabra.h"

using namespace std;

ostream &operator<<(ostream &salida, Palabra &tira)
{
	salida << tira.palabra << endl;
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
	return this->palabra == tira;
}

bool Palabra::operator==(const Palabra &otra) const
{
	return this->palabra == otra.palabra;
}

Palabra &Palabra::operator=(Palabra &otra)
{
	this->palabra = otra.palabra;
	this->length = otra.length;
	return *this;
}

Palabra &Palabra::operator=(const string &tira)
{
	this->palabra = tira;
	this->length += getLength(tira);
	return *this;
}

Palabra &Palabra::operator=(const char *v)
{
	this->palabra = v;
	this->length = getLength();
	return *this;
}

Palabra &Palabra::operator+=(const string &tira)
{
	this->palabra += tira;
	length += getLength(tira);
}

Palabra &Palabra::operator+=(const Palabra &otra)
{
	this->palabra += otra.palabra;
	this->length += otra.length;
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
const char * Palabra::getCaracteres()
{
	const char *v = palabra.c_str();
	return v;
}

int Palabra::decodificar(char c) const
{
	int indice = 0;
	for(indice; indice < SIZE; indice++){
		if(caracteres[indice] == c){
			return (indice <= SIZE? indice : -1);
		}
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
