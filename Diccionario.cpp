#include "Diccionario.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Diccionario::Diccionario()
: arbol(nullptr)
{
	
}

Diccionario::Diccionario(std::fstream &)
: arbol(nullptr)
{
	//TO-DO
}

Diccionario::~Diccionario()
{
	if(arbol)
		delete arbol;
	if(indices)
		delete [] indices;
}

string Diccionario::operator[](string &palabra)
{
	//TO-DO
}

string operator+=(string &palabra, Diccionario &)
{
	//TO-DO
}

void Diccionario::buscar(string &palabra)
{
	if(indices)
		delete[] indices;
	int length = palabra.size();
	indices = new int[length];
	const char * tira = palabra.c_str();
	for(int i = 0; i < length; i++){
		indices[i] = getIndice(tira[i]);
	}
	
	for(int j = 0; j < length; j++)
		cout << indices[j] << endl;
}

int Diccionario::getIndice(char c) const
{
	int indice = 0;
	for(indice; indice < SIZE; indice++){
		if(caracteres[indice] == c){
			return indice;
		}
	}
}