#include "Diccionario.h"
#include "Palabra.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Diccionario d;
	Palabra p("hola");
	cout << p << endl;
	d += p;
	d += "hala";
	d += "hale"; 
	d += "hole";
	d += "hora"; 
	d += "hoyo";
	Palabra r("holi");
	cout << "existe hola? " << boolalpha << d[p] << endl;
	d.imprimirCamino(p);
	d.imprimirCamino(r);
	return 0;
}