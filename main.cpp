#include "Palabra.h"
#include "Nodo.h"
#include "Arbol.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string tira = "hola";
	Palabra p(tira);
	string otratira = "adios";
	Palabra o(otratira);
	Arbol arbol;
	arbol.crearPalabra(p);
	//arbol.crearPalabra(o);
	return 0;
}