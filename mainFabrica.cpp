#include <fstream>
#include "Fabrica.h"
#include "Vector.h"
#include "Producto.h"
#include "FabricaVectores.h"
#include "Elemento.h"
#include <iostream>
#include "Lista.h"
#include <string>
using namespace std;
int main(){/*
	Fabrica* fabricaVectores = new FabricaVectores();
	Elemento *elemento = dynamic_cast<Elemento *>(fabricaVectores->producir());
	fstream archivo("file.txt");
	Lista *lista = new Lista(elemento, archivo, 2);
	cout << lista << endl;*/
	string str1 = "Esto es una hilera";
	cout << str1.find("hilera")  << endl;
	string str2 = "Hola hola adios hola adios adios";
	cout << str2.find("hola");
	return 0;
}