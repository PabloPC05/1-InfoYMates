#pragma once
#include <string>
#include <fstream>
#include "Jugadoras.h"

class Equipo {
public:
	//Constructor y destructr
	Equipo(std::string n = "", int p = 0, size_t nJ = 0) : Nombre(n), presupuesto(p), num_jugadoras(nJ), Puntos(0), capacidad(presupuesto * 3 / 1000), jugadoras(new int[presupuesto*3/1000]) {}
	~Equipo() { delete[] jugadoras; }


	void cargar(std::istream& entrada);
	void mostrar(std::ostream& salida, Jugadoras& Jugadoras);
	void redimensionar(size_t nuevaCap);
	void insertar(int nuevaJugadora);
	int buscar(int id);
	void desplazarDerecha(int pos);
	void eliminar_jugadoras(Jugadoras& jugadoras);


	//Getters y setters de los atributos
	int getNumJugadoras() const { return num_jugadoras; }
	int getNumJugadorasMax() const { return(presupuesto * 3) / 1000; }
	int getPresupuesto() const { return presupuesto; }
	void setPresupuesto(int p) { presupuesto = p; }
	std::string nombre() const { return Nombre; }
	int puntos() const { return Puntos; }
	void actualizarPuntos(int p);

private:
	std::string Nombre;
	int presupuesto;
	size_t num_jugadoras;
	int Puntos;
	size_t capacidad;
	int *jugadoras;
};