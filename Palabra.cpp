#include "Palabra.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

constexpr char Palabra::caracteres[SIZE];

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
	getIndices();
}

Palabra::Palabra(const char *v)
: indices(nullptr)
{
	palabra = v;
	length = getLength();
	getIndices();
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
		if(i == 0 && v[i] == (char) 32){
			throw new invalid_argument("La palabra no puede empezar con espacios en blanco!");
		}else{
			if(v[i] == (char) 32)
				break;
			else
				i++;
		}
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
		if(caracteres[indice] == c){
			return (indice <= SIZE? indice : -1);
		}else{
			if(indice == SIZE-1)
				throw invalid_argument("Entrada inválida!");
		}
	}
}

void Palabra::getIndices()
{
	const char * tira = palabra.c_str();
	int caracteresRaros = caracteresEspeciales(tira);
	indices = new int[length-caracteresRaros]();
	int charActual = 0;
	for(int i = 0; i < length-caracteresRaros; i++){
		try{
			if((int) tira[charActual] < 0){
				indices[i] = decodificar(determinarCaracter((int) tira[++charActual]));
			}else{
				indices[i] = decodificar(tira[charActual]);
			}
			charActual++;
		}catch(invalid_argument &e){
			cerr << e.what() << endl;
			for(int i = 0; i < length+caracteresRaros; i++)
				cout << (int) tira[i] << " " << endl;
			cerr << "No se pudo agregar la palabra " << "\"" << tira << "\"" <<endl;
			exit(1);
		}
	}
	length -= caracteresRaros;
}

int Palabra::caracteresEspeciales(const char *v) const
{
	int caracteresEspeciales = 0;
	for(int i = 0; v[i]; i++){
		if((int) v[i] < 0){
			caracteresEspeciales++;
			i++; //siempre vienen en parejas
		}
	}
	return caracteresEspeciales;
}

char Palabra::determinarCaracter(int c)
{
	switch(c){
		case -127:
		case -95: 
			return (char) 160;
			break;
		case -119:
		case -87:
			return (char) 130;
			break;
		case -115:
		case -83:
			return (char) 161;
			break;
		case -109:
		case -77:
			return (char) 162;
			break;
		case -102:
		case -70:
			return (char) 163;
			break;
		case -100:
		case -68:
			return (char) 129;
			break;
		case -111:
		case -79:
			return (char) 164;
	}
}
