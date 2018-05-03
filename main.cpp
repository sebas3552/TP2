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
	Diccionario *diccionario = new Diccionario();
	string ruta;
	int opcion = 0;
	bool hayProblemas = false;
	cout << "Bienvenido!" << endl << endl;
	do{
		try{
			cout << "Seleccione una opcion del menu: " << endl;
			cout << "1: Cargar diccionario" << endl;
			cout << "2: Cargar documento para extraer hashtags" << endl;
			cout << "3: Guardar los hashtags" << endl;
			cout << "4: Ver el camino de una palabra" << endl;
			cout << "5: Salir" << endl;
			cin >> opcion;
			if(opcion < 0 || opcion > 5)
				throw invalid_argument("Seleccione una opcion");
			switch(opcion){
				case 1:
				cout << "Ingrese el nombre del archivo o ruta del diccionario: " << endl;
				cin >> ruta;
				texto.cargarDiccionario(ruta, *diccionario);
				break;
				case 2: 
				cout << "Ingrese el nombre del archivo o ruta del archivo: " << endl;
				cin >> ruta;
				break;
				case 3:
				texto.separar(ruta, *diccionario);
				cout << "Los hashtags se separaron correctamente!" << endl;
				break;
				case 4: {
				string palabra;
				cout << "Ingrese una palabra para ver su camino: " << endl;
				cin >> palabra;
				Palabra p(palabra);
				diccionario->imprimirCamino(p);
				}
				break;
				case 5: 
				cout << endl;
				exit(0);
			}
			hayProblemas = false;
		}catch(invalid_argument &e){
			cerr << "Error! " << e.what() << endl;
			hayProblemas = true;
		}
	}while(hayProblemas || opcion != 5);
	
	delete diccionario; 
	
	return 0;
}