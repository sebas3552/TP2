#include "Diccionario.h"
#include "Palabra.h"
#include <iostream>
#include <string>
#include "Texto.h"

using namespace std;

int main()
{
	Diccionario d;
	Texto texto("dic.txt");
	texto.agregarPalabrasDiccionario(d);
	return 0;
}