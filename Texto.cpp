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

void Texto::metodoDivision( string nombreArchivo ){
	fstream archivo( nombreArchivo );
	
	if( !archivo ){
		throw invalid_argument( "El archivo indicado no existe!" );
	}
	
	string s;
	while( getline( archivo, s ) ){
		const char * v = s.c_str();
		bool hayEspacios = false;
		bool hayRaros = false;
		
		for( int i = 1; i < s.length(); i++ ){
			if( v[i] == ' ' ){
				hayEspacios = true;
			}
			
			if( esRaro( (v[i] < 0? Palabra::determinarCaracter(v[i]) : v[i]) ) ){
				hayRaros = true;
			}
		}
		
		if( hayEspacios ){
			//divPorEspacios( s, cantEspacios );
			cout << "tiene espacios, entonces se debe llamar al metodo que divida por espacios" << endl;
		} else if( hayRaros ){
			//divPorRaros( s );
			cout << "tiene raros y no espacios, entonces se llama al metodo que divide por raros" << endl;
		} else {
			//divPorDiccionario( s );
			cout << "no tiene ni espacios ni raros" << endl;
		}
	}
}

string Texto::divPorEspacios( string aDividir ){
	vector <string> divisiones;
	divisiones.push_back( aDividir );
	
	char * v = convertirMinusculas( aDividir );
	
	int i = 0;
	int actual = 0;
	int dimension = 0;
	int temp = 0;
	while( i < aDividir.length() ){
		dimension = 0;
		while( (v[actual] != ' ') && (v[actual] != '\0') ){
			dimension++;
			actual++;
		}
		
		char aGuardar[ dimension+1 ];
		
		temp = i;
		for( int j = 0; j < dimension; j++ ){
			aGuardar[j] = v[temp];
			temp++;
		}
		
		aGuardar[ dimension ] = '\0';
		divisiones.push_back( aGuardar );
		
		i = ++actual;
	}
	delete [] v;
	
	string dividido;
	for( int i = 0; i < divisiones.size(); i++ ){
		if( !i ){
			dividido += divisiones[i] + ":";
		} else {
			dividido += " " + divisiones[i];
		}
	}
	
	return dividido;
}

bool Texto::esRaro( char c ){
	bool esRaro = true;
	
	for( int i = 0; i < Palabra::SIZE-1; i++ ){
		if( c == Palabra::caracteres[i] )
			esRaro = false;
	}
	
	return esRaro;
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
