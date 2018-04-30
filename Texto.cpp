#include "Texto.h"
#include <iostream>

using namespace std;

Texto::Texto( const char * nombreDiccionario ){
	this->nombreDiccionario = nombreDiccionario;
	dimensionDiccionario = cantidadPalabras();
}

Texto::~Texto(){

}

std::string* Texto::separarStrings(){
	diccionario.open( nombreDiccionario );
	string *vectorString = new string[ dimensionDiccionario ];
	for( int i = 0; i < dimensionDiccionario; i++ ){
		string s;
		getline( diccionario, s );
		vectorString[i] = s;
	}
	
	diccionario.close();
	return vectorString;
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

void Texto::agregarPalabrasDiccionario( Diccionario & diccionario ){
	string* vectorString = separarStrings();
	
	for( int i = 0; i < dimensionDiccionario; i++  ){
		diccionario += convertirMinusculas( vectorString[i] );
		cout << "Se agrego " << convertirMinusculas(vectorString[i]) << " al diccionario!" << endl; 
	}
	delete [] vectorString;
}

int Texto::cantidadPalabras(){
	diccionario.open( nombreDiccionario );
	int palabras = 0;
	string s;
 	
	while( getline( diccionario, s ) )
		++palabras;
	
	diccionario.close();
	return palabras;
}