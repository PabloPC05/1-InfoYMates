#pragma once
#include <string>
#include <fstream>

class Jugadora {
public:
	Jugadora(int i = 0, std::string n = "", std::string a = "", int g = 0) : id(i), nombre(n), Apellido(a), goles(g) {}
	void cargar(std::istream& entrada);
	void mostrar(std::ostream& salida);
	int getId() const { return id; }
	std::string apellido() { return Apellido; }


private:
	int id;
	std::string nombre;
	std::string Apellido;
	int goles;
};