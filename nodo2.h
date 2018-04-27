#ifndef NODO2_h
#define NODO2_h

class Nodo2
{
	public:
		Nodo2();
		~Nodo2();
		void crearCamino(Nodo2 &, int *, const int, int);
		void recorrerCamino(Nodo2 &);
		void reconstruirCamino(Nodo2 &, int *, const int, int);
		static const int SIZE = 27;
		
	private:
		void init();
		Nodo2** punteros;
};

#endif