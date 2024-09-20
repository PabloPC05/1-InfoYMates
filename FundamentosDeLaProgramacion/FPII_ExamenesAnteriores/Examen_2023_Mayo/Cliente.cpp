#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
#include "Cliente.h"
#include <iomanip>
#include <iostream>
using namespace std;

void Cliente::mostrar() const {
    std::cout << "NIF: " << std::setw(4) << nifn << "   Precio Anual: " << std::setw(7) << precio << "   Numero de Partes: " << std::setw(2) << numPartes << '\n';
}

