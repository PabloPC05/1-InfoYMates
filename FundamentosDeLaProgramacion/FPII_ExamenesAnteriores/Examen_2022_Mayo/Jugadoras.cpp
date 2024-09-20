#include "Jugadoras.h"
#include <iostream>
#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
using namespace std;

void Jugadoras::cargar(istream& entrada) {
	entrada >> numJugadoras;
	for (int i = 0; i < numJugadoras; i++) {
		Jugadora* jugadora = new Jugadora;
		jugadora->cargar(entrada);
		listaJugadoras[i] = jugadora;
	}
}

void Jugadoras::mostrar(ostream& salida) {
	salida << "- - - - -\n"; 
	salida << "JUGADORAS\n- - - - -\n"; 
	for (int i = 0; i < numJugadoras; i++) {
		listaJugadoras[i]->mostrar(salida);
	}
}

int Jugadoras::buscar(int id) {
	int i = -1, fin = numJugadoras;
	while (i + 1 < fin) {
		int mitad = (i + fin) / 2;
		if (listaJugadoras[mitad]->getId() < id) i = mitad;
		else fin = mitad;
	}
	return fin;
}

void Jugadoras::insertar(Jugadora* nuevaJugadora) {
	listaJugadoras[numJugadoras] = nuevaJugadora;
	numJugadoras++;
}

void Jugadoras::borrar_jugadora(int id) {
	int pos = buscar(id);
	delete listaJugadoras[pos];
	for (int i = pos; i < numJugadoras - 1; i++) {
		listaJugadoras[i] = listaJugadoras[i + 1];
	}
	numJugadoras--;
}

