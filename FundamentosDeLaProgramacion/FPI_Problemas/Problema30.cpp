// Problema 30: Dentro o fuera

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void calculo() {
	int nummuestrasluz, limiteinferior, limitesuperior;
	cin >> nummuestrasluz >> limiteinferior >> limitesuperior;
	for (int i = 0; nummuestrasluz > i; i++) {
		int muestraluz; 
		cin >> muestraluz;
		if (limiteinferior <= muestraluz && muestraluz <= limitesuperior) cout << "EN EL INTERVALO\n";
		else if (muestraluz < limiteinferior) cout << "DISTANCIA: " << limiteinferior - muestraluz << "\n";
		else cout << "DISTANCIA: " << muestraluz - limitesuperior << "\n";
	}
	cout << "---\n";
}


int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}