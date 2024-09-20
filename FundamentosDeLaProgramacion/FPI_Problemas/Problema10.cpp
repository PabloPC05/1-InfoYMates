// Problema 10: Tabla de multiplicar

// IMPORTANTE
// Pablo Pardo Cotos
// FP1-DG25

#include <iostream>
using namespace std;

/*
* En la funcion calculo se declaran las variables del numero a introducir, el multiplicador y el resultado,
* se realiza el calculo del resultado y se muestra en pantalla hasta que se complete la tabla (llegar al numero 10)
*/
void calculo() {
	int numero, n = 1;
	cin >> numero;
	for (int i = 0; i < 10; i++, n++) {
		int resultado = numero * n;
		cout << numero << ' ' << '*' << ' ' << n << ' ' << '=' << ' ' << resultado << "\n";
	}
	cout << "---" << "\n";
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		calculo();
	}
	return 0;
}