#include "Liga.h"
#include <string>
#include <iostream>
#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
using namespace std;

int Liga::buscarEquipo(string& nombre) {
	int i = -1, fin = numEquipos;
	while (i + 1 < fin) {
		int mitad = (i + fin) / 2;
		if (listaEquipos[mitad]->nombre() < nombre) i = mitad;
		else fin = mitad;
	}
	return fin;
}

void Liga::mostrar(ostream& salida, Jugadoras& jugadoras) {
	salida << "- - - -\n";
	salida << "EQUIPOS\n";
	salida << "- - - -\n";
	for (int i = 0; i < numEquipos; ++i) {
		listaEquipos[i]->mostrar(salida, jugadoras);
	}
}

void Liga::desplazarDerecha(int pos) {
	for (int i = numEquipos; i > pos; i--) {
		listaEquipos[i] = listaEquipos[i-1];
	}
}

void Liga::cargar(istream& entrada) {
	int cont;
	entrada >> cont;
	for (int i = 0; i < cont; i++) {
		string nombre;
		int presupuesto, numJugadoras;
		entrada >> nombre >> presupuesto >> numJugadoras;
		Equipo* equipo = new Equipo(nombre, presupuesto, numJugadoras);
		int pos = buscarEquipo(nombre);
		desplazarDerecha(pos);
		listaEquipos[pos] = equipo;
		equipo->cargar(entrada);
		numEquipos++;
	}
}

void Liga::aumentar_presupuesto(string& team) {
	Equipo* equipo = listaEquipos[buscarEquipo(team)];
	equipo->setPresupuesto(equipo->getPresupuesto() + 1000);
	equipo->redimensionar((equipo->getPresupuesto() * 3) / 1000);
}


bool Liga::insertar(string nombreEquipo, int idJugadora) {
	int pos = buscarEquipo(nombreEquipo);
	if (listaEquipos[pos]->getNumJugadorasMax() < listaEquipos[pos]->getNumJugadoras() + 1) return false;
	else {
		listaEquipos[pos]->insertar(idJugadora);
	}
	return true;
}

int Liga::buscarMaximoEquipo() {
	int indiceMax = 0;
	for (int i = 0; i < numEquipos; i++) {
		if (listaEquipos[indiceMax]->puntos() < listaEquipos[i]->puntos()) indiceMax = i;
	}
	return indiceMax;
}


Equipo* Liga::campeon_liga(istream& entrada) {
	int numPartidos;
	entrada >> numPartidos;
	for (int i = 0; i < numPartidos; i++) {
		string equipo1, equipo2;
		int goles1, goles2;
		entrada >> equipo1 >> goles1 >> equipo2 >> goles2;
		if (goles1 > goles2) {
			listaEquipos[buscarEquipo(equipo1)]->actualizarPuntos(3);
		}
		else if (goles2 > goles1) {
			listaEquipos[buscarEquipo(equipo2)]->actualizarPuntos(3);
		}
		else {
			listaEquipos[buscarEquipo(equipo1)]->actualizarPuntos(1);
			listaEquipos[buscarEquipo(equipo2)]->actualizarPuntos(1);
		}
	}
	return listaEquipos[buscarMaximoEquipo()];

}

void Liga::descenso_equipo(string nombreEquipo, Jugadoras& jugadoras) {
	int pos = buscarEquipo(nombreEquipo);
	listaEquipos[pos]->eliminar_jugadoras(jugadoras);
	delete listaEquipos[pos];
	for (int i = pos; i < numEquipos; i++) {
		listaEquipos[i] = listaEquipos[i + 1];
	}
	numEquipos--;
}