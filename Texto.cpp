#include "Texto.h"
#include <iostream>

using namespace std;

Texto::Texto(){
}


Diccionario &Texto::cargarDiccionario(string nombreDiccionario, Diccionario &diccionario){
	fstream archivoDiccionario(nombreDiccionario);
	if(!archivoDiccionario){
		throw invalid_argument("El archivo indicado no existe!");
	}
	string s;
	int palabrasAgregadas = 0;
	while(getline( archivoDiccionario, s )){
		if(s.length() > 1){
			diccionario += convertirMinusculas(s);
			palabrasAgregadas++;
		}
	}
	archivoDiccionario.close();
	cout << "Se agregaron " << palabrasAgregadas << " palabras al diccionario!" << endl;
	return diccionario;
}

void Texto::separar( string nombreArchivo, Diccionario &diccionario ){
	fstream entrada(nombreArchivo);
	fstream salida("Separados.txt", ios::out);
	if( !entrada ){
		throw invalid_argument( "El archivo indicado no existe!" );
	}
	
	string s;
	while( getline( entrada, s ) ){
		const char * v = s.c_str();
		bool hayEspacios = false;
		bool hayRaros = false;
		
		for( int i = 1; i < s.length(); i++ ){
			if( v[i] == ' ' ){
				hayEspacios = true;
				break;
			}
			
			if( esRaro( (v[i] < 0? Palabra::determinarCaracter(v[i]) : v[i]) ) ){
				hayRaros = true;
				break;
			}
		}
		string tira(convertirMinusculas(s));
		salida.seekp(0);
		if(hayEspacios && hayRaros)
			salida << divPorRaros(tira) << endl;
		else
			if( hayEspacios )
				salida << divPorEspacios(tira) << endl;
			else
				if( hayRaros )
					salida << divPorRaros(tira) << endl;
				else
					cout << "si " << endl;
					salida << divPorDiccionario(tira, diccionario) << endl;
	}
	entrada.close();
	salida.close();
}

string Texto::divPorEspacios( string &aDividir ){
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
			dividido += divisiones[i] + ": ";
		} else {
			dividido += divisiones[i];
		}
	}
	return dividido;
}

string Texto::divPorRaros(string &s)
{
	vector <string> dividido;
	dividido.push_back(s + ": ");
	char v[s.length()];
	int i = 1;
	for(i; i < s.length(); i++){
		if((int)s[i] < 0){
			v[i] = s[i];
		}else{
			v[i] = esRaro(s[i])? ' ' : s[i];
		}
	}
	v[i] = '\0';
	dividido.push_back(v);
	return dividido[0] + dividido[1];
}

string Texto::divPorDiccionario(string &s, const Diccionario &d)
{
	vector <string> dividido;
	dividido.push_back(s + ": ");
	string tira;
	for(int i = 1; i < s.length(); i++){
		tira += s[i];
		if(d[tira]){	//si existe la palabra en el diccionario
			dividido.push_back(tira + " ");
			tira.clear();
		}
	}
	string separadas;
	for(int j = 0; j < dividido.size(); j++)
		separadas += dividido[j];
	return separadas;
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