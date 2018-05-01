#include "Texto.h"
#include <iostream>

using namespace std;

Texto::Texto(){
}

Texto::~Texto(){

}

Diccionario &Texto::cargarDiccionario(string nombreDiccionario, Diccionario &diccionario){
	fstream archivoDiccionario(nombreDiccionario);
	if(!archivoDiccionario){
		throw invalid_argument("El archivo indicado no existe!");
	}
	string s;
	int palabrasAgregadas = 0;
	while(getline( archivoDiccionario, s )){
		diccionario += convertirMinusculas(s);
		palabrasAgregadas++;
	}
	archivoDiccionario.close();
	cout << "Se agregaron " << palabrasAgregadas << " palabras al diccionario!" << endl;
	return diccionario;
}

char * Texto::convertirMinusculas( string aConvertir ){
	const char * cadena = aConvertir.c_str();
	int longitudPalabra = 0;
	while( cadena[ longitudPalabra ] ){
		++longitudPalabra;
	}
	
	char * v = new char[ longitudPalabra ];
	
	int i = 0;
	while( cadena[i] ){
		char c = tolower( cadena[i] );
		v[i] = c;
		++i;
	}
	
	v[i] = '\0';
	
	return v;
}