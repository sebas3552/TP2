#include "Palabra.h"
#include "Elemento.h"
using namespace std;

virtual ostream & Palabra::imprimir(ostream & salida){
	salida << palabra;
	return salida;
}

virtual istream & Palabra::cargar(istream & entrada){
	entrada >> palabra;
	return entrada;
}

Palabra::Palabra(const Palabra & otra){
	this->palabra = otra.palabra;
}

virtual Elemento * Palabra::clonar(){
	return new Elemento( *this );
}

virtual double Palabra::distancia(Elemento * otro){
	double distancia;
	distancia = (2 * bigramasComunes(otro))/
		(bigramasUnicos() + otro->bigramasUnicos());
	return distancia;
}

vector<string> Palabra::bigramas(){
	vector<string> bigramas;
	const char * cadenaPalabra = palabra.c_str();
	
	for( int i = 0; i < palabra.length()-1; i++ )
		bigramas.push_back( cadenaPalabra[i] + cadenaPalabra[i+1] );
	
	return bigramas;
}

int Palabra::bigramasUnicos(){
	int unicos = bigramas.size();
	int noUnicos = 0;
	
	for( int i = 0; i < bigramas.size(); i++ ){
		for( int j = i+1; j < bigramas.size(); j++ ){
			if( bigramas[i] == bigramas[j] )
				noUnicos++;
		}
	}
	
	unicos -= noUnicos;
	return unicos;
}

int Palabra::bigramasComunes(Elemento * otro){
	
}