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
	string ruta;
	bool hayProblemas = false;
	do{
		try{
			cout << "Ingrese el nombre del archivo o ruta del diccionario: ";
			cin >> ruta;
			texto.cargarDiccionario(ruta, *d);
			hayProblemas = false;
		}catch(invalid_argument &e){
			cerr << "Error! " << e.what() << endl;
			hayProblemas = true;
		}
	}while(hayProblemas);
	cout << "está África?: " << boolalpha << d->operator[]("África") << endl;
	cout << "está a?: " << boolalpha << d->operator[]("a") << endl;
	delete d;
	
	return 0;
}