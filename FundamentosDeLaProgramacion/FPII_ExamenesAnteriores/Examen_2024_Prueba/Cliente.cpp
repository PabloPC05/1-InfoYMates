#include "Cliente.h"
#include <iostream>


#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif

using namespace std;

void Cliente::mostrar_cliente() {
	saldoTotal = actualizarSaldoTotal();
	cout << "NIF del cliente: " << NIF << '\n';
	cout << "Saldo total del cliente: " << saldoTotal << '\n';
	cout << "  Relacion de cuentas: \n";
	for (int i = 0; i < numCuentas; i++) {
		cout << "\t ";
		cuentasBancarias[i]->mostrar_cuenta();
	}
	cout << '\n';
}

int Cliente::actualizarSaldoTotal() {
	int returnValue = 0;
	for (int i = 0; i < numCuentas; i++) {
		returnValue = returnValue + cuentasBancarias[i]->saldo();
	}
	return returnValue;
}

bool Cliente::buscar_cuenta(int numC, int& pos) {
	int i = -1, fin = numCuentas;
	while (i + 1 < fin) {
		int mitad = (i + fin) / 2;
		if (cuentasBancarias[mitad]->num_Cuenta() < numC) i = mitad;
		else fin = mitad;
	}
	pos = fin; 
	return pos < numCuentas && !(numC < cuentasBancarias[fin]->num_Cuenta());
}

void Cliente::nueva_cuenta(int nC, int saldo) {
	CuentaBancaria* cuenta = new CuentaBancaria(saldo, nC);
	insertar(cuenta);
}

void Cliente::insertar(CuentaBancaria* cN) {
	int pos; 
	buscar_cuenta(cN->num_Cuenta(), pos); 
	desplazarDerecha(pos);
	cuentasBancarias[pos] = cN;
}

void Cliente::desplazarDerecha(int pos) {
	for (int i = numCuentas; i > pos; i--) {
		cuentasBancarias[i] = cuentasBancarias[i - 1];
	}
	numCuentas++;
}

void Cliente::eliminar_cuenta(int pos) {
	delete cuentasBancarias[pos];
	cuentasBancarias[pos] = nullptr;
	for (int i = pos; i < numCuentas - 1; i++) {
		cuentasBancarias[i] = cuentasBancarias[i + 1];
	}
	numCuentas--;
}

void Cliente::cargar_cuenta() {
	CuentaBancaria* cuenta = new CuentaBancaria();
	cuenta->cargar_cuenta();
	insertar(cuenta);
}