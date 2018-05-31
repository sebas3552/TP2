#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	string palabra = "perro";
	vector<string> bigramas;
	
	const char * primeraCadena = palabra.c_str();
	//char cadenaPalabra[100];
	//stpcpy( cadenaPalabra, primeraCadena );
	for( int i = 0; i < palabra.length()-1; i++ ){
		//string s = cadenaPalabra[i];
		bigramas.push_back( primeraCadena[i] + primeraCadena[i+1] );
	}
	
	for( int i = 0; i < bigramas.size(); i++ ){
		cout << bigramas[i] << endl;
	}
	
	// vector<int> my;
	// for( int i = 0; i < 10; i++ )
		// my.push_back(i);
	// for( int j = 8; j < 12; j++ )
		// my.push_back(j);
	// cout << "tamano = " << my.size() << endl;
	
	// int unicos = my.size();
	// int noUnicos = 0;
	// for( int i = 0; i < my.size(); i++ ){
		// for( int j = i+1; j < my.size(); j++ ){
			// if( my[i] == my[j] )
				// noUnicos++;
		// }
	// }
	// unicos -= noUnicos;
	
	// cout << unicos;
	return 0;
}