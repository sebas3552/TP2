#include "Vector.h"
#include <iomanip>
#include <stdexcept>
#include <cmath>
using namespace std;

Vector::Vector()
: vector(nullptr)
{
}

double Vector::distancia(Elemento *otro)
{
	Vector *v = dynamic_cast<Vector *>(otro);
	/*La distancia entre dos vectores es la norma del vector diferencia.*/
	double distancia = norma(*v-this);
	return distancia;
}

Vector::Vector(const Vector &otro) 
: vector(nullptr)
{
	size = otro.size;
	vector = new double[size];
	if(vector){
		for(int i = 0; i < size; i++)
			vector[i] = otro.vector[i];
	}
}

Vector::~Vector()
{
	if(vector)
		delete vector;
}
Elemento *Vector::clonar()
{
	return new Vector(*this);
}

int Vector::length() const
{
	return size;
}

istream &Vector::cargar(istream &entrada)
{
	char buffer[LIMIT];
	entrada.getline(buffer, LIMIT);
	size = 1 + contarEspacios(buffer);
	if(vector)
		delete [] vector;
	vector = new double[size];
	rellenar(vector, size, buffer);
	return entrada;
}

ostream &Vector::imprimir(ostream &salida)
{
	salida << "[ ";
	cout << fixed << setprecision(2);
	for(int i = 0; i < size; i++){
		if(i < size-1)
			salida << vector[i] << ", ";
		else
			salida << vector[i];
	}
	salida << " ]";
	return salida;
}

int Vector::contarEspacios(const char *tira){
	const char BLANCO = ' ';
	int blancos = 0;
	for(int i = 0; tira[i]; i++){
		blancos += (tira[i] == BLANCO? 1 : 0);
	}
	return blancos;
}

void Vector::rellenar(double *vector, int largo, char* buffer){
	int leidos = 0;
	const char BLANCO = ' ';
	string numero = "";
	for(int i = 0; leidos < largo && i < LIMIT; i++){
		if(buffer[i] != BLANCO && buffer[i]){
			numero += buffer[i];
		}else{
			if(numero != ""){
				vector[leidos] = stod(numero);
				numero = "";
			}
			leidos++;
		}
	}
}

Vector &Vector::operator-(const Vector *otro)
{	/*No se pueden restar vectores de diferente largo.*/
	Vector *copia = dynamic_cast<Vector *>(this->clonar());
	if(size != otro->size)
		throw invalid_argument("Error! Los vectores difieren en cantidad de elementos!");
	for(int i = 0; i < size; i++){
		copia->vector[i] -= otro->vector[i];
	}
	return *copia;
}

double Vector::norma(Vector &v) const
{
	double raiz = 0;
	for(int i = 0; i < size; i++){
		raiz += pow(v.vector[i], 2);
	}
	return sqrt(raiz);
}