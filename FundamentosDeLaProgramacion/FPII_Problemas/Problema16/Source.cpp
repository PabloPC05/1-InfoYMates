#pragma once
#include "inventario.h"
#include <string>
using namespace std;

bool leer_caso(inventario& inv) {
	int a,e,c;
	cin >> a; if (a == 0) return false;
	for (int i = 0; i < a; i++) {
		cin >> e>>c;
		inv.nuevo_id(e, c);
	}
	return true;
}
bool ejecutar() {
	int a,id,cant;
	inventario inv;
	if (!(leer_caso(inv))) return false;
	string op;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> op;
		if (op == "vender") {
			cin >> id;
			inv.vender(id);
		}
		else if (op == "comprar") {
			cin >> id>>cant;
			inv.comprar_id(id,cant);
		}
		else {
			cin >> id >> cant;
			inv.nuevo_id(id, cant);
		}
	}
	inv.mostrar();
	return true;
}

int main() {
	while (ejecutar());
}
