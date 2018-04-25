#include "Palabra.h"
#include "Nodo.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string tira = "holayadios";
	Palabra p(tira);
	int *indices = p.getIndices();
	int largo = p.getLength();
	Nodo *raiz = new Nodo();
	raiz->crearCamino(raiz, indices, largo, 0);
	return 0;
}