#include <iostream>
#include <fstream>
#include "Banco.h"

#ifndef DOMJUDGE
#include "memoryleaks.h"
#endif

using namespace std;

void ingresar_dinero(Banco& banco, string const& nif, int cuenta, int cantidad);
void sacar_dinero(Banco& banco, string const& nif, int cuenta, int cantidad);

int main() {
// Si estás ejecutando el programa en tu ordenador, las siguientes líneas
// redirigirán cualquier lectura de cin al fichero 'entrada.txt'. Esto es
// útil para no tener que teclear los casos de prueba por teclado cada vez
// que ejecutas el programa.
//
// Si prefieres teclear la entrada por teclado en tu ordenador,
// comenta las líneas comprendidas entre los #ifndef y #endif
#ifndef DOMJUDGE
	std::ifstream in("entrada.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

#ifndef DOMJUDGE
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	Banco banco; // invoca a la constructora por defecto

	banco.cargar_clientes();

	string operacion;
	cin >> operacion;
	while (operacion != "SALIR") {
		if (operacion == "INGRESAR") {
			string NIF; int cuenta, cantidad;
			cin >> NIF >> cuenta >> cantidad;
			ingresar_dinero(banco, NIF, cuenta, cantidad);
		}
		else if (operacion == "SACAR") {
			string NIF; int cuenta, cantidad;
			cin >> NIF >> cuenta >> cantidad;
			sacar_dinero(banco, NIF, cuenta, cantidad);
		}
		else { // operacion == MOSTRAR_CLIENTES
			banco.mostrar_clientes();
		}
		cin >> operacion;
	}
	return 0;
}


void ingresar_dinero(Banco& banco, string const& nif, int cuenta, int cantidad) {
	//Si el NIF esta en el banco
	int pos;
	if (banco.buscar_cliente(nif, pos)) {
		int posCuenta;
		//Si el NIF esta en el banco y tiene una cuenta
		if (banco.cliente(pos)->buscar_cuenta(cuenta, posCuenta)) {
			banco.cliente(pos)->realizar_ingreso(posCuenta, cantidad);
		}
		//Si el NIF esta en el banco pero no existe una cuenta con ese identificador
		else {
			banco.cliente(pos)->nueva_cuenta(cuenta, cantidad);
		}
	}
	//Si el NIF no esta en el banco y por tanto tampoco tiene ninguna cuenta
	else{
		banco.insertar_cliente(nif, pos);
		banco.cliente(pos)->nueva_cuenta(cuenta, cantidad);
	}
}

void sacar_dinero(Banco& banco, string const& nif, int cuenta, int cantidad) {
	int pos;
	//Si el NIF esta en el banco
	if (banco.buscar_cliente(nif, pos)) {
		int posCuenta;
		//Si el NIF esta en el banco y tiene una cuenta
		if (banco.cliente(pos)->buscar_cuenta(cuenta, posCuenta)) {
			banco.cliente(pos)->realizar_reintegro(posCuenta, cantidad);
			if (banco.cliente(pos)->num_cuentas() <= 0) banco.eliminar_cliente(pos);
		}
		//Si el NIF esta en el banco y no tiene una cuenta con ese identificador
		else {
			cout << "ERROR: EL CLIENTE " << nif << " NO TIENE UNA CUENTA " << cuenta << '\n';
		}
	}
	//Si el NIF no esta en el banco
	else {
		cout << "ERROR: NO EXISTE EL CLIENTE " << nif << '\n';
	}
}