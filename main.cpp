#include "Palabra.h"
#include "Nodo.h"
#include "nodo2.h"
#include "Arbol.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string tira = "hola";
	Palabra p(tira);
	string otratira = "holi";
	Palabra o(otratira);
	Arbol arbol;
	//arbol.crearPalabra2(o);
	arbol.crearPalabra(p);
	cout << "Existe " << p << "?: " << boolalpha << arbol.verificarPalabra(p) << endl;
	cout << "Existe " << o << "?: " << boolalpha << arbol.verificarPalabra(o) << endl;
	arbol.crearPalabra(o);
	cout << "Existe " << p << "?: " << boolalpha << arbol.verificarPalabra(p) << endl;
	cout << "Existe " << o << "?: " << boolalpha << arbol.verificarPalabra(o) << endl;
	//arbol.verificarPalabra(o);
	//arbol.verificarPalabra(p);
	
	return 0;
}