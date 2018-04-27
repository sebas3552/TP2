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

string Diccionario::operator[](Palabra palabra&)
{
	
}

string operator+=(string &palabra, Diccionario diccionario&)
{
	//TO-DO
}

string operator+=(Palabra palabra&, Diccionario diccionario&)
{
	
}
