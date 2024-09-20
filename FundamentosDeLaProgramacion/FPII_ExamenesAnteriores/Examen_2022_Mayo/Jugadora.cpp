#include "Jugadora.h"
#include <iostream>
using namespace std;

void Jugadora::cargar(istream& entrada) {
	entrada >> id >> nombre >> Apellido >> goles;
}

void Jugadora::mostrar(ostream& salida) {
	salida << "Nombre: " << nombre << ' ' << Apellido << ", Goles: " << goles << '\n';
}