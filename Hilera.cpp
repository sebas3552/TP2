#include "Hilera.h"
using namespace std;

Hilera::Hilera()
: tira("")
{
}
	   
Hilera::Hilera(const Hilera &otra)
{
	tira = otra.tira;
}
ostream & Hilera::imprimir(ostream & salida)
{
	salida << tira;
	return salida;
}

istream & Hilera::cargar(istream & entrada)
{
	getline(entrada, tira);
	return entrada;
}	   

Elemento *Hilera::clonar()
{
	Hilera *otra = new Hilera(*this);
	return dynamic_cast<Elemento *>(otra);
}

double Hilera::distancia(Elemento *elemento)
{
	Hilera *otra = dynamic_cast<Hilera *>(elemento);
	string otraTira = otra->tira;
	int largoTira = Vector::contarEspacios(tira.c_str());
	int largoOtraTira = Vector::contarEspacios(otraTira.c_str());
	
	int u[largoTira];
	int v[largoOtraTira];
	u = calcularFrecuencia(tira, u, tira.length(), largoTira);
	v = calcularFrecuencia(otraTira, v, otraTira.length(), largoOtraTira);
	for(int i = 0; i < largoTira; i++)
		cout << u[i] << " ";
	cout << endl;
	for(int j = 0; j < largoOtraTira; j++)
		cout << v[j] << " ";
}

int []Hilera::calcularFrecuencia(string &tira, int v[], int largo, int cantPalabras)
{
	const char BLANCO = ' ';
	String buffer = "";
	vector<string> container;
	int pos = 0;
	for(int i = 0; i < largo; i++){
		if(tira[i] != BLANCO){
			buffer += tira[i];
		}else{
			container.push_back(buffer);
			tira = "";
		}
	}
	for(int j = 0; j < cantPalabras; j++){
		for(int l = 0; l < container.size(); l++){
			pos = tira.find(container[l]);
			if(pos != string::npos){
				v[j]++;
			}
		}
	}
	return v;
}