#pragma once
#include <iostream>

class CuentaBancaria {
private:
	int numCuenta;
	int Saldo;
public:
	CuentaBancaria(int s = 0, int nC = 0) : numCuenta(nC), Saldo(s) {}
	~CuentaBancaria(){}
	void cargar_cuenta() {
		std::cin >> numCuenta >> Saldo;
	}
	void mostrar_cuenta() {
		std::cout << "Numero de cuenta: " << numCuenta << '\t' << "Saldo: " << Saldo << '\n';
	}
	int num_Cuenta() { return numCuenta; }
	int saldo() { return Saldo; }
	void pon_saldo(int s) { Saldo = s; }
};

