#pragma once
#include "Jugadora.h"

class Jugadoras {
public:
	Jugadoras(int nJ = 0) : numJugadoras(nJ), listaJugadoras() {}
	~Jugadoras() { 
		for (int i = 0; i < numJugadoras; i++) {
			delete listaJugadoras[i];
		}
	}
	void cargar(std::istream& entrada);
	void mostrar(std::ostream& salida);
	void insertar(Jugadora* nuevaJugadora); 
	int buscar(int id);
	void borrar_jugadora(int id);
	Jugadora* jugadora(int i) { return listaJugadoras[i]; }

private:
	static const int MAX_JUGADORAS = 100;
	int numJugadoras;
	Jugadora* listaJugadoras [MAX_JUGADORAS];
};

