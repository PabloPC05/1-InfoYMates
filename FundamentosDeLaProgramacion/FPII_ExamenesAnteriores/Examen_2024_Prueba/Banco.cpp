#include "Banco.h"
#include "Cliente.h"
#include <iostream>

#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif

using namespace std;

void Banco::desplazarDerecha(int pos) {
	for (size_t i = numClientes; i > pos; i--) {
		listaClientes[i] = listaClientes[i - 1];
	}
	numClientes++;
}

void Banco::redimensionar(size_t nuevaCap){
	Cliente** aux = new Cliente*[nuevaCap];
	for(int i = 0; i < numClientes; i++){
		aux[i] = listaClientes[i];
	}
	delete[] listaClientes;
	listaClientes = aux;
	capacidad = nuevaCap;
}

bool Banco::insertar_cliente(string NIF, int& pos) {
	if (!buscar_cliente(NIF, pos)) {
		redimensionar(capacidad+1);
		desplazarDerecha(pos);
		listaClientes[pos] = new Cliente(NIF);
		return true;
	}
	else return false;
}

bool Banco::buscar_cliente(string NIF, int& pos) {
	int i = -1, fin = numClientes;
	while (i + 1 < fin) {
		int mitad = (i + fin) / 2;
		if (listaClientes[mitad]->nif() < NIF) i = mitad;
		else fin = mitad;
	}
	pos = fin;
	return (pos < numClientes) && !(NIF < listaClientes[pos]->nif());
}

void Banco::cargar_clientes() {
	int temp;
	cin >> temp;
	for (int i = 0; i < temp; i++) {
		string nif;
		int numCuenta, pos;
		cin >> nif;
		insertar_cliente(nif, pos);
		listaClientes[pos]->cargar_cuenta();
	}
}