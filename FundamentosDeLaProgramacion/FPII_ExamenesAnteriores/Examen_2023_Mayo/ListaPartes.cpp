#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif
#include "ListaPartes.h"
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

ListaPartes::ListaPartes() : cont(0), capacidad(2), lista(new string*[2]) {}

ListaPartes::~ListaPartes() {
    for (int i = 0; i < cont; ++i) {
        delete lista[i];
    }
    delete[] lista;
}

void ListaPartes::cargar() {
   string nif; cin >> nif;
   while (nif != "XX") {
      if (cont == capacidad)
         redimensionar();
      lista[cont] = new string(nif);
      ++cont;
      cin >> nif;
   }
}

int ListaPartes::num_partes() const {
   return cont;
}

std::string const& ListaPartes::parte(int i) const {
   assert(0 <= i && i < cont);
   return *lista[i];
}

void ListaPartes::redimensionar() {
   string** viejo = lista;
   capacidad *= 2;
   lista = new string*[capacidad];
   for (int i = 0; i < cont; ++i)
      lista[i] = viejo[i];
   delete[] viejo;
}
