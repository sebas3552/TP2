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
	string otratira = "sdsadsada";
	Palabra o(otratira);
	Arbol arbol;
	arbol.crearPalabra(p);
	arbol.verificarPalabra(p);
	//arbol.verificarPalabra(o);
	//arbol.verificarPalabra(p);
	
	return 0;
}