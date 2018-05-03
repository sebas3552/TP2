#include "Texto.h"
#include <iostream>
#include <new>

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
	Palabra p;                                //para acceder al vector de caracteres validos
	
	if( !archivo ){
		throw invalid_argument( "El archivo indicado no existe!" );
	}
	
	string s;
	while( getline( archivo, s ) ){
		const char * v = s.c_str();
		bool hayEspacios = false;
		int cantEspacios = 0;
		bool hayRaros = false;
		
		for( int i = 0; i < s.length(); i++ ){
			if( v[i] == ' ' ){
				hayEspacios = true;
				cantEspacios++;
			}
			
			if( esRaro( v[i] ) ){
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

void Texto::divPorEspacios( string aDividir ){
	vector <string> divisiones;
	divisiones.push_back( aDividir );
	
	char * v = convertirMinusculas( aDividir );
	
	int i = 0;
	while( v[i] ){
		int dimension = 0;
		int actual = i;
		while( (v[actual] != ' ') && (v[actual] != '\0') ){
			dimension++;
			actual++;
		}
		
		char * aGuardar = new char[ dimension ];
		
		for( int j = i; j < i+dimension; j++ )
			aGuardar[j] = v[j];
		
		string a = aGuardar;
		divisiones.push_back( a );
		
		i = ++actual;
	}
	
	cout << divisiones[1];
	
	//return divisiones;
}

bool Texto::esRaro( char c ){
	Palabra p;
	bool esRaro = true;
	
	for( int i = 0; i < p.SIZE-1; i++ ){
		if( c == p.caracteres[i] )
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