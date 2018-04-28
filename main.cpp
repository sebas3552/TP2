#include "Diccionario.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Diccionario d;
	d += "hola";
	Palabra p("halucinogeno");
	cout << "Existe holi?: " <<boolalpha << d["holi"] << endl;
	cout << "Existe hola?: " << boolalpha << d["hola"] << endl;
	cout << "Existe " << p << "?: " << boolalpha << d[p] << endl;
	d += p;
	cout << "Existe " << p << "?: " << boolalpha << d[p] << endl;
	cout << "Existe hola?: " << boolalpha << d["hola"] << endl;
	return 0;
}