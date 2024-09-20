#pragma once
#include "CuentaBancaria.h"
#include <string>
#include <iostream>

const int MAX_CUENTAS = 5;

class Cliente {
public:
	Cliente(std::string n = "", int s = 0) : NIF(n), cuentasBancarias(), saldoTotal(s), numCuentas(0)  {	}
	~Cliente() {
		for (int i = 0; i < numCuentas; i++) {
			delete cuentasBancarias[i];
		}
	}
	int actualizarSaldoTotal();
	void cargar_cuenta();
	void mostrar_cliente();
	std::string nif() { return NIF; }
	int num_cuentas() { return numCuentas; }
	int saldo(int pos) { return cuentasBancarias[pos]->saldo(); }
	bool buscar_cuenta(int numC, int& pos);
	void realizar_ingreso(int pos, int cantidad) {
		cuentasBancarias[pos]->pon_saldo(cuentasBancarias[pos]->saldo() + cantidad);
	}
	void realizar_reintegro(int pos, int cantidad) {
		cuentasBancarias[pos]->pon_saldo(cuentasBancarias[pos]->saldo() - cantidad);
		if (cuentasBancarias[pos]->saldo() <= 0) {
			eliminar_cuenta(pos);
		}
	}
	void nueva_cuenta(int nc, int saldo);
	void eliminar_cuenta(int pos);
	void insertar(CuentaBancaria* cN);

private:
	void desplazarDerecha(int pos);
	std::string NIF;
	CuentaBancaria* cuentasBancarias[MAX_CUENTAS];
	int saldoTotal;
	int numCuentas;
};

