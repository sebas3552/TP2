#include "Diccionario.h"
#include "Palabra.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "Texto.h"

using namespace std;

int main()
{
	Texto texto;
	Diccionario *d = new Diccionario();
	texto.cargarDiccionario("DiccionarioGwande.txt", *d);
	cout << "está inútil?: " << boolalpha << d->operator[]("inútil") << endl;
	delete d;
	return 0;
}