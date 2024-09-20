#include "Equipo.h"
#include <cassert>
#include <iostream>
#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
using namespace std;


int Equipo::buscar(int id) {
	int i = -1, fin = num_jugadoras;
	while (i + 1 < fin) {
		int mitad = (i + fin) / 2;
		if (jugadoras[mitad] < id) i = mitad;
		else fin = mitad;
	}
	return fin;
}

void Equipo::cargar(istream& entrada) {
	for (int i = 0; i < num_jugadoras; i++) {
		entrada >> jugadoras[i];
	}
}

void Equipo::redimensionar(size_t nuevaCap) {
	int* aux = new int[nuevaCap];
	for (int i = 0; i < num_jugadoras; i++) {
		aux[i] = jugadoras[i];
	}
	delete[] jugadoras;
	jugadoras = aux;
}

void Equipo::desplazarDerecha(int pos) {
	for (int i = pos; i < num_jugadoras; i++) {
		jugadoras[i] = jugadoras[i - 1];
	}
}

void Equipo::insertar(int nuevaJugadora) {
	jugadoras[num_jugadoras] = nuevaJugadora;
	num_jugadoras++;
}

void Equipo::actualizarPuntos(int p) {
	Puntos = Puntos + p;
}

void Equipo::eliminar_jugadoras(Jugadoras& Jugadoras) {
	for (int i = 0; i < num_jugadoras; i++) {
		Jugadoras.borrar_jugadora(jugadoras[i]);
	}
}

void Equipo::mostrar(ostream& salida, Jugadoras& Jugadoras) {
	salida << "Nombre: " << nombre() << ", Presupuesto: " << presupuesto;
	salida << " Puntos: " << puntos() << ", # jugadoras: " << num_jugadoras << '\n';
	if (num_jugadoras > 0) {
		cout << "Plantilla:";
		for (int i = 0; i < num_jugadoras; ++i) {
			int pos = Jugadoras.buscar(jugadoras[i]);
			salida << ' ' << Jugadoras.jugadora(pos)->apellido();
		}
		salida << '\n';
	}
}