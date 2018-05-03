#include "Diccionario.h"
#include <string>
#include <iostream>
using namespace std;

Diccionario::Diccionario()
{
	arbol = new Arbol();
}

Diccionario::~Diccionario()
{
	delete arbol;
}

bool Diccionario::operator[](string &tira) const
{
	Palabra p(tira);
	return arbol->verificar(p);
}

bool Diccionario::operator[](Palabra &palabra) const
{
	return arbol->verificar(palabra);
}

bool Diccionario::operator[](const char *v) const
{
	Palabra p(v);
	return arbol->verificar(p);
}

Diccionario &Diccionario::operator+=(string &tira)
{
	Palabra p(tira);
	arbol->agregar(p); 
	return *this;
}

Diccionario &Diccionario::operator+=(Palabra &palabra)
{
	arbol->agregar(palabra);
	return *this;
}

Diccionario &Diccionario::operator+=(const char *v)
{
	Palabra p(v);
	arbol->agregar(p);
	/*if(v)
		delete [] v;*/
	return *this;
}

void Diccionario::imprimirCamino(Palabra &palabra) const
{
	cout << "Palabra: " << palabra << endl;
	arbol->verCamino(palabra);
}
