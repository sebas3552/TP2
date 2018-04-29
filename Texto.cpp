#include "Texto.h"

using namespace std;

Texto::Texto( const char * nombreDiccionario ){
	this->nombreDiccionario = nombreDiccionario;
	dimensionDiccionario = cantidadPalabras();
}

Texto::~Texto(){
	if( vectorString )
		delete [] vectorString;
}

void Texto::separarStrings(){
	diccionario.open( nombreDiccionario );
	
	vectorString = new string[ dimensionDiccionario ];
	
	for( int i = 0; i < dimensionDiccionario; i++ ){
		string s;
		getline( diccionario, s );
		vectorString[i] = s;
	}
	
	diccionario.close();
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
	separarStrings();
	
	for( int i = 0; i < dimensionDiccionario; i++  )
		diccionario += convertirMinusculas( vectorString[i] );
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