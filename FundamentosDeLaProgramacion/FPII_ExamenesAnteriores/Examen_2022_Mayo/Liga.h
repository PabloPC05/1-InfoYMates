#pragma once
#include "Equipo.h"
#include "Jugadoras.h"
#include <fstream>

class Liga {
public:
	Liga(int nE = 0) : numEquipos(nE), listaEquipos(), campeonLiga() {}
	~Liga() {
		for (int i = 0; i < numEquipos; i++) {
			delete listaEquipos[i];
		}
		delete campeonLiga;
	}
	void aumentar_presupuesto(std::string& team);
	int buscarEquipo(std::string& nombre);
	Equipo* campeon_liga(std::istream& entrada);
	void cargar(std::istream& entrada);
	void mostrar(std::ostream& salida, Jugadoras& jugadoras);
	bool insertar(std::string nombreEquipo, int idJugadora);
	void descenso_equipo(std::string nombreEquipo, Jugadoras& jugadoras);
 
private:
	int buscarMaximoEquipo();
	void desplazarDerecha(int pos);
	static const int MAX_EQUIPOS = 10;
	Equipo* listaEquipos[MAX_EQUIPOS];
	int numEquipos;
	Equipo* campeonLiga;
};

